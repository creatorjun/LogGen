// src/engine/MemoryPool.h
#pragma once

#include <vector>
#include <memory>
#include <span>
#include <ranges>
#include <cstddef>
#include <new>
#include "core/Constants.h"

template <typename T, size_t BlockSize = Constants::Memory::kMemoryPoolBlockSize>
class FixedMemoryPool {
public:
    FixedMemoryPool() {
        allocateBlock();
    }

    ~FixedMemoryPool() = default;

    FixedMemoryPool(const FixedMemoryPool&)            = delete;
    FixedMemoryPool& operator=(const FixedMemoryPool&) = delete;

    [[nodiscard]] T* allocate() {
        if (!m_nextFree)
            allocateBlock();
        Node* node = m_nextFree;
        m_nextFree = m_nextFree->next;
        return std::launder(reinterpret_cast<T*>(node->storage.data()));
    }

    void deallocate(T* ptr) {
        if (!ptr) return;
        destroy(ptr);
        Node* node = reinterpret_cast<Node*>(ptr);
        node->next = m_nextFree;
        m_nextFree = node;
    }

    template <typename... Args>
    [[nodiscard]] T* construct(Args&&... args) {
        T* p = allocate();
        return ::new (p) T(std::forward<Args>(args)...);
    }

    void destroy(T* ptr) {
        if (ptr) ptr->~T();
    }

private:
    struct alignas(alignof(T)) Node {
        std::array<std::byte, sizeof(T)> storage;
        Node* next = nullptr;
    };

    static_assert(sizeof(Node) >= sizeof(T),
        "Node storage too small for T");
    static_assert(alignof(Node) >= alignof(T),
        "Node alignment insufficient for T");

    void allocateBlock() {
        auto block = std::make_unique<std::byte[]>(BlockSize * sizeof(Node));
        Node* first = std::launder(reinterpret_cast<Node*>(block.get()));

        std::ranges::for_each(
            std::views::iota(size_t{0}, BlockSize),
            [&](size_t i) {
                first[i].next = (i + 1 < BlockSize) ? &first[i + 1] : m_nextFree;
            });

        m_nextFree = first;
        m_blocks.push_back(std::move(block));
    }

    std::vector<std::unique_ptr<std::byte[]>> m_blocks;
    Node*                                     m_nextFree = nullptr;
};
