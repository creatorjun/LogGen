from pathlib import Path
from markitdown import MarkItDown

def convert_docs_to_md(base_folder):
    # MarkItDown 변환기 초기화
    md = MarkItDown()
    target_dir = Path(base_folder)
    
    # 폴더 존재 여부 확인
    if not target_dir.exists() or not target_dir.is_dir():
        print(f"에러: '{target_dir}' 폴더를 찾을 수 없습니다. 경로를 다시 확인해 주세요.")
        return

    # 변환할 대상 확장자 (소문자로 통일)
    target_extensions = {'.pdf', '.pptx'}
    
    # rglob('*')을 통해 하위 폴더를 포함한 모든 파일을 순회
    for file_path in target_dir.rglob('*'):
        # 파일이면서 확장자가 pdf 또는 pptx 인지 확인 (대소문자 무시)
        if file_path.is_file() and file_path.suffix.lower() in target_extensions:
            # 원본 파일명 기반으로 저장할 .md 경로 생성
            md_file_path = file_path.with_suffix('.md')
            
            print(f"변환 중: {file_path.name}")
            try:
                # 파일을 마크다운 형식으로 변환
                result = md.convert(str(file_path))
                
                # 한글 깨짐 방지를 위해 utf-8 인코딩으로 저장
                with open(md_file_path, 'w', encoding='utf-8') as f:
                    f.write(result.text_content)
                    
                print(f"  ✅ 변환 완료 -> {md_file_path}")
                
            except Exception as e:
                print(f"  ❌ 변환 실패 ({file_path.name}): {e}")

if __name__ == "__main__":
    # 대상 폴더 경로 설정 (상황에 맞게 수정하여 사용하세요)
    folder_path = "docs"
    
    print("문서 변환 작업을 시작합니다...\n" + "-"*40)
    convert_docs_to_md(folder_path)
    print("-" * 40 + "\n모든 작업이 종료되었습니다.")