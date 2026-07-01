// src/engine/TICategoryMapper.cpp
#include "TICategoryMapper.h"
#include <algorithm>
#include <cctype>

namespace {

std::string toLower(const std::string& s) {
    std::string r = s;
    std::transform(r.begin(), r.end(), r.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return r;
}

bool contains(const std::string& hay, const std::string& needle) {
    return hay.find(needle) != std::string::npos;
}

} // namespace

TICategoryContext TICategoryMapper::map(const std::string& category,
                                        const std::string& tiSeverity)
{
    const std::string cat = toLower(category);
    const std::string sev = toLower(tiSeverity);

    const bool highSeverity = (sev == "high" || sev == "critical");
    const std::string denyAction  = "DENY";
    const std::string alertAction = highSeverity ? "DENY" : "ALERT";

    if (contains(cat, "ssh") && contains(cat, "brute"))
        return { "22",   "TCP", denyAction };

    if (contains(cat, "rdp"))
        return { "3389", "TCP", denyAction };

    if (contains(cat, "ftp") && contains(cat, "brute"))
        return { "21",   "TCP", denyAction };

    if (contains(cat, "smb") || contains(cat, "netbios"))
        return { "445",  "TCP", denyAction };

    if (contains(cat, "telnet"))
        return { "23",   "TCP", denyAction };

    if (contains(cat, "smtp") || contains(cat, "mail"))
        return { "25",   "TCP", alertAction };

    if (contains(cat, "dns"))
        return { "53",   "UDP", alertAction };

    if (contains(cat, "ddos") || contains(cat, "dos")) {
        const std::string proto = contains(cat, "udp") ? "UDP" : "TCP";
        return { "80",   proto, denyAction };
    }

    if (contains(cat, "port scan") || contains(cat, "portscan") || contains(cat, "scan"))
        return { "0",    "TCP", alertAction };

    if (contains(cat, "sql"))
        return { "3306", "TCP", denyAction };

    if (contains(cat, "xss") || contains(cat, "cross-site"))
        return { "443",  "TCP", alertAction };

    if (contains(cat, "lfi") || contains(cat, "rfi") || contains(cat, "path traversal"))
        return { "80",   "TCP", denyAction };

    if (contains(cat, "command injection") || contains(cat, "rce") || contains(cat, "remote code"))
        return { "80",   "TCP", denyAction };

    if (contains(cat, "c2") || contains(cat, "c&c") || contains(cat, "command and control"))
        return { "4444", "TCP", denyAction };

    if (contains(cat, "ransomware"))
        return { "445",  "TCP", denyAction };

    if (contains(cat, "malware") || contains(cat, "trojan") || contains(cat, "rat"))
        return { "8080", "TCP", denyAction };

    if (contains(cat, "phishing"))
        return { "443",  "TCP", alertAction };

    if (contains(cat, "botnet"))
        return { "6667", "TCP", denyAction };

    if (contains(cat, "exploit"))
        return { "443",  "TCP", denyAction };

    if (contains(cat, "http") || contains(cat, "web"))
        return { "80",   "TCP", alertAction };

    if (contains(cat, "https") || contains(cat, "ssl") || contains(cat, "tls"))
        return { "443",  "TCP", alertAction };

    if (contains(cat, "icmp") || contains(cat, "ping"))
        return { "0",    "ICMP", alertAction };

    return { "80", "TCP", alertAction };
}
