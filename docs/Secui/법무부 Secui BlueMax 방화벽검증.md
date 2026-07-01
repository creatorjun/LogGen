<!-- Slide number: 1 -->
# 법무부 Secui BlueMax 방화벽 검증

<!-- Slide number: 2 -->
# SOAR > 보안장비연계관리

![내용 개체 틀 6](내용개체틀6.jpg)

1. 사용유무 체크
fullMsg.add("=================================");
fullMsg.add(" - 장비OFF, 관리자의 승인이 필요합니다.");
fullMsg.add("=================================");
미연동시 Playbook Message 위 로그 발생

<!-- Slide number: 3 -->
# SOAR > 보안장비연계관리

![내용 개체 틀 4](내용개체틀4.jpg)
BlueMax API연계를 위한 정보 연동
장비IP
URL : {ip} 는 장비모델명 적용됨
적용예) https://{ip}:1113/api/secu...
Key : Client Key
ID : Client ID

* 위항목은 출장시 세팅 후 차단테스트 완료된 상태이기 때문에 기 적용된 설정이 있다면 그대로 유지되어야 합니다.

<!-- Slide number: 4 -->
# 플레이북 관리(컴포넌트 세팅)

![내용 개체 틀 4](내용개체틀4.jpg)

<!-- Slide number: 5 -->
# 검증 절차
내.외부망 Proxy 모듈 상태 체크
요청순서 : Web -> 내부망Proxy -> 외부망Proxy -> Secui BlueMax
모듈 정상 동작시 Playbook 테스트(조회컴포넌트 활용)
조회 결과 확인(Playbook 결과창)
아래 로그가 출력된다면 정상
fullMsg.add("["+(cnt+1)+"# Input Parameter]");
fullMsg.add(" - 블랙리스트IP(조회) : " + block_ip);
fullMsg.add("["+(cnt+1)+"# Result]");
fullMsg.add(" - 요청 장비주소 : " + eqp_ip);
fullMsg.add("["+(cnt+1)+"# Origin Result]");
fullMsg.add(" - 조회결과(true/false) : " + blockStatus);
fullMsg.add(" - 응답(전체) : " + resObj);
위 설정대로 완료 후 Playbook 재생시 오류 -> 로그 전송
Tomcat log
내부망Proxy log
외부망Proxy log