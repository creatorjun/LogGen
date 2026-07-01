WebKeeper 정책 연동 모듈

WebKeeperPolicy
 1. DLPCenter에서 보여주는 정책 리스트를 Web 화면에 보여줌과 동시에 해당 정책에
설정된 부서, 사용자 정보를 화면에 보여줍니다.
 2. 해당 정책에 사용자를 추가할 수 있으며 정책설정완료후 NetworkAgent에게 정책 적용을
할수 가 있습니다.
 3.  화면에서는 정책에 설정된 부서, 사용자를 보여줄뿐, 부서추가는 안되고 정책에 해당하는
사용자 정보만 추가할 수 있습니다.

설치및 서버 재기동시 실행될수 있도록 Script를 모두 작성하였습니다.
---------------------------------------------------------------------------------------------------------------------------

1. 패키지 내용

      WebKeeperPolicy패키지 압축을 풀면 아래와 같은 파일 리스트가 나옵니다.

 해당 파일의 설명은 아래와 같습니다.
   Linux

-  WKPolicy
   : 서비스 등록 스크립트(/etc/init.d에 저장)
- WebKeeperPolicy
   : WebKeeper 정책 연동 모듈( 실행파일)
 -  checkpolicy.sh
   : WebKeeperPolicy 모듈 Alive 체크 스크립트
 -  install.sh
   :  WebKeeperPolicy 모듈 설치 스크립트

             - config.json
               : WebKeeperPolicy 에 필요한 설정파일
  Windows

- WindowsService.exe

: 서비스 등록 프로그램

- WindowsService.json

: 서비스 등록을 위한 설정파일

 config.json 파일의 내용은 아래와 같습니다.
{
    "ip": "192.168.0.100",                   : 해당 서버 IP
    "httpport": "10001",                       : WebKeeperPolicy Web Port( http )
    "webkeeperversion":8,                 : 웹키퍼 버전( 8, 10 )
    "dbip": "10.106.13.242",               : DB IP( postgres )
    "dbport": "5432",                          : DB PORT
    "dbid": "postgres",                        : DB ID
    "dbpasswd": "",                            : DB Password
    "database": "somansa",               : DB database
    "tablename":"custompolicylist",    : 사용자 설정 정책리스트 테이블명
    "isdeleteip": true,                          : 사용자 ip 추가시 기존ip삭제여부
}

   ​ 2. 설치 사용법
    2.1 Linux
        해당 패키지를 푼상태에서 ./install.sh 하면 설치 방법이 설명됨

        2.1.1 설치
         : ./install.sh `pwd` 하면 /somansa/webkeeper/policyapply 폴더에 설치됨( ​변경 불가​ )

        2.1.2 서비스 등록 여부
        서비스 이름은 ​WKPolicy​( WebKeeperPolicy 줄임말)
        ( runLevel 3,4,5 일경우 서버 기동시 시작하도록 되어있음 )

 2.2  Windows
     해당 패키지를 압축 풀어서 ​CMD 창에서  WindowsService.exe  파일 실행( 관리자모드)
       해당 프로그램의 실행 옵션을 추가할 수 있습니다.

WindowsService.exe -service=[install, uninstall, start, stop, restart ]
   install : 서비스 등록
   uninstall:  서비스 삭제
   start:   서비스 시작
    stop:  서비스 종료
    restart:  서비스 재시작

설정파일 설정

          {

   "Name": "WebKeeperPolicy",                     서비스 이름
               "DisplayName": "WebKeeperPolicy",         서비스 이름

   "Description": "WebKeeperPolicy Service",  서비스 이름
   "Dir": "C:\\WebKeeperPolicy",                        패키지가 압축 풀린 절대경로
   "Exec": "C:\\WebKeeperPolicy\\WebKeeperPolicy.exe",  실행파일 절대경로
   "Args": [],
   "Env": [
   ],
   "Stderr": "C:\\WebKeeperPolicy\\log\\ServerErr.log",  프로그램 로그 위치
   "Stdout": "C:\\WebKeeperPolicy\\log\\ServerErr.log"   프로그래 로그 위치

        }

       ​  수정사항​은 [ ​DIR, Exec​ ] 두개 부분만 패키지가 설치된 위치만 변경해주시면됩니다.

     2.2.1 설치

1. 서비스 등록

: WindowsService.exe -service=install 명령어로 서비스등록

< 설치된 모습 >

  3. 사용법
   ​ 3.1 Linux
          WebKeeperPolicy 를 실행방법은 2가지가 있다
          서비스로 시작, Command로 실행하는 방법
     3.1.1 ) 서비스 명령어
        : service WKPolicy { start | stop | restart} 명령으로 서비스 시작 , 중지 할수 있음

     3.1.2 ) 서비스 시작
       : service WKPolicy start

   윈도우 실행

3.2 Windows
3.2.1)  서비스 실행

              : windowsService.exe -service=start 명령어로 서비스 실행
               -> windowsservice.exe 가 WebKeeperPolicy.exe를 실행하는형태

3.3) 프로세스 확인
    ​3.3.1 LINUX
        기본적으로 2개의 프로세스를 확인해야함

1. ps -ef | grep checkpolicy | grep -v grep

         : WebKeeperPolicy 모듈을 주기적으로 체크하는 스크립트
           ( 서비스실행시 checkpolicy.sh 스크립트를 실행함 )

      2.  ps -ef | grep WebKeeperPolicy | grep -v grep
         : WebkeeperPolicy 모듈 실행

 ​ 3.3.2 Windows
      서비스 프로그램, WebKeeperPolicy 2개의 프로세스가 실행된 모습

   < 실행된 모습 >

 4) 실행화면( 정상적인 화면 )
   http://serverip:serverport

< 에러가 발생했을 때 >

위 화면과 같이 정책 리스트가 나오지 않을경우 웹 브라우저의 개발자 도구(console)를
확인하시거나 해당 모듈의 로그를 확인하시면 됩니다

 4.1 ) 정책 검색
      : 최소 2자 이상 입력해야함( 정책리스트에서 필터링해서 보여줌 )
      : 새로운 정책 추가시 새로고침해줘야함

 4.2 ) 정책 적용대상 화면( 정책 리스트에서 적용대상 클릭시 )
     : 해당 정책( test나 ) 에 대한 사용자 및 부서 정보

   4.3 ) 정책 선택시 사용자 정의 Table에 저장하기
     : 정책 리스트에서 선택 여부를 선택 하면 사용자가 지정한(config.json파일의
customname) 테이블에 저장됨
     : 선택 해제시 사용자가 지정한(config.json파일의 customname )테이블에서 삭제됨

     DB 테이블 정보
     : 증권허용, 가상화페차단, 페이스북차단 정책정보가 사용자가 지정한 테이블에 저장됨

  4.4 ) 설정정보 확인
   : http://서버ip:10001/config
   : config.json 파일의 정보를 화면에 보여줌

4.5 ) WebKeeperPolicy API설명
   :​ http://서버ip:10001/restapi
   : 아래와 같이 해당 url에 대한 설명이 나와 있다
   : 자세한 설명은 아래와 같다

http://서버ip:10001/help( http body내용 자세히 설명)

