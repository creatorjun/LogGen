WEBFRONT-K
PREST API 설명서

등록 상표

PIOLINK 는 ㈜파이오링크의 등록상표 입니다.

일러두기

  이 설명서의 저작권은 ㈜파이오링크에 있습니다. 이 설명서는 저작권법에 의하여 법적으로 보호 받고 있으며,

저작권자의 사전 서면 허가 없이는 어떠한 이유에서든 무단으로 전체 혹은 일부분의 내용을 발췌하거나 어떠한

형태로든 복제할 수 없습니다.

  이 설명서는 제품의 기능 향상과 인쇄상의 오류 수정 등으로 인하여 예고 없이 변경될 수 있습니다.

  이 설명서 및 그 내용에 의해 직접, 간접으로 발생될 수 있는 피해 및 재산상 손해에 대해 ㈜파이오링크에

법적인 책임이 없음을 밝힙니다.

WEBFRONT-K PREST API 설명서

©PIOLINK, Inc. All rights reserved.

전화: 02-2025-6900 Web page: http://www.piolink.com

시작하기 전에

설명서 소개

이 설명서는 WEBFRONT-K 의 PREST API 정보를 소개하는 PREST API 설명서입니다. 이 설명서는 PLOS v2.0.59.0.6

이상의 버전이 설치된 PREST API 를 기준으로 작성되었습니다.

대상 독자

이  설명서는  WEBFRONT-K 와  같은 웹방화벽을  설정하고 관리할  수  있는  숙련된  네트워크  관리자를  대상으로

작성된 설명서입니다.

PLOS 버전

PLOS 는 WEBFRONT-K 에 설치되어 있는 파이오링크 운영 체제를 의미합니다. 이 사용 설명서는 PLOS v2.0.59.0.6

버전이 설치된 WEBFRONT-K 를 기준으로 작성하였습니다. 이전 버전의 PLOS 가 설치되어 있는 경우에는 이 사용

설명서에서 설명하는 기능이 지원되지 않을 수 있고, 설명에 맞게 설정한 경우에도 정상적으로 동작하지 않을 수

있습니다.

설명서의 표기법

다음은 이 설명서에서 사용하는 제품의 이름과 PREST API 정보 설명 형식에 대한 설명입니다.

제품 명칭 표기

이 설명서에서는 제품을 지칭할 때 다음과 같은 명칭을 사용합니다.

  WEBFRONT-K

파이오링크의 웹방화벽 제품군을 지칭하는 공식적인 제품 명으로, 모든 제품에 공통적으로 해당되는 내용을

설명할 때 사용되는 명칭입니다.

참고 및 주의 표기

이  사용  설명서에서  사용자에게  특별히  전달하고자  하는  내용은  다음과  같은  아이콘과  글꼴을  사용하여

표시합니다.

참고: 설명서의 내용과 관련하여 함께 알아두면 유용한 사항이나 제품을 사용하면서 도움이 될 만한 참고 사항과 관련 자료 등을 소개합니다.

주의: 데이터를 손실하거나 혹은 제품이 잘못 동작할 수 있는 상황을 설명하고, 그 상황에 대한 대처 방법을 알려줍니다.

관련 문서

이 설명서와 함께 WEBFRONT-K 에 대한 다음과 같은 문서를 제공합니다.

  WEBFRONT-K 사용 설명서 (User Guide)

WEBFRONT-K 가 제공하는 기능을 소개하고, GUI 를 통해 각 기능을 설정하는 방법을 알려주는 설명서입니다.

  WEBFRONT-K 설치 설명서 (Installation Guide)

WEBFRONT-K 의 앞면, 뒷면, 옆면에 있는 각 부분의 기능을 소개하고, WEBFRONT-K 를 랙에 설치한 후 각

포트에  장비를  연결하는  방법을  알려주는  설명서입니다.  WEBFRONT-K 의  하드웨어  사양과  장비  연결시

사용하는 케이블에 대한 상세한 사양도 이 설명서에서 볼 수 있습니다.

서비스 지원

고객 서비스나 기술 지원, 혹은 기술 교육에 관한 자세한 정보가 필요한 경우에는 다음 연락처로 문의하시면 필요한

도움을 받을 수 있습니다.

 기술지원센터

1544-9890

 E-mail

4

WEBFRONT-K PREST API 설명서

목 차

WEBFRONT-K PREST API 설명서 ..................................................................................... 1

시작하기 전에 ...............................................................................................................................................................3

설명서 소개 3

대상 독자 3

PLOS 버전 3

설명서의 표기법 3

관련 문서 3

서비스 지원 4

목 차오류! 책갈피가 정의되어 있지 않습니다.

제 1 장 사용하기 전에 .......................................................................................................... 7

PEST-API ......................................................................................................................................................................... 8

PREST-API 소개 ...............................................................................................................................................8

리소스 ......................................................................................................................................................8

메소드 ......................................................................................................................................................8

바디 메시지 ...........................................................................................................................................8

PREST-API 인증 방법 .....................................................................................................................................9

Basic Auth ..............................................................................................................................................9

권한 .....................................................................................................................................................................9

제 2 장 System 설정 9

VLAN 설정 10

14

포트 바운더리 설정 16

애플리케이션 추가 삭제 20

시그니처 클래스 별로 설정 변경 22

시그니처 애플리케이션 별로 설정 변경 29

블랙리스트 IP 설정 변경 31

설정 저장 34

사용자 관리 34

라이센스 관리 ............................................................................................................................................................ 47

제 3 장 Application 설정 .................................................................................................. 50

Application 일반설정(IP/PORT 리스트, 도메인 리스트) .......................................................................... 51

Application 일반설정(상태, 일반 설정 정보) ............................................................................................... 56

요청검사 보안기능 활성화/비활성화 설정.................................................................................................... 59

부하분산 - 소스 NAT 설정 .................................................................................................................................... 62

부하분산 – (패턴, 실제서버, 그룹, 규칙, 장애감시) .................................................................................. 67

SSL - 일반설정 ........................................................................................................................................................... 89

SSL - 인증서 관리 .................................................................................................................................................... 97

제 4 장 파일 시스템  ........................................................................................................ 101

파일 업로드 .............................................................................................................................................................. 102

5

제 1 장
사용하기 전에

6

WEBFRONT-K PREST API 설명서

PEST-API

PREST-API 소개

PREST-API 는 PIOLINK 에서 제공하는 REST-API 입니다. 또한, 클라이언트가 웹사이트를 통해서 장비 WEBFRONT-

K 에 직접 설정을 할 수 있도록 제공하는 Web 기반 아키텍쳐 입니다. PREST-API 는 다음과 같이 리소스, 메서드,

메세지 3 가지 요소로 구성됩니다.

리소스

URI 는  슬래시  구분자를  사용하여  계층관계를  나타내도록  합니다.  사용자의  보안을  위하여  반드시  HTTPS

프로토콜을 사용합니다.

예시>

https://{장비 IP:PORT}/api/{버전}/{기능타입}/{기능}

기능타입

설명

conf

PREST-API 에 환경 설정 기능입니다.

statistics

PREST-API 에 통계 기능입니다.

site

app

PREST-API 에 시스템 설정 기능입니다.

PREST-API 에 애플리케이션 설정 기능입니다.

system

PREST-API 에 파일 시스템 설정 기능입니다.

메소드

HTTP 에서 제공하는 많은 메소드 중에서 다음 4 가지만 사용하도록 합니다.

Method

GET

POST

PUT

리소스 상태의 표현을 얻거나 조회할 때 사용합니다.

기능에 새로운 리소스를 만들거나 컨트롤러를 실행할 때 사용하도록 합니다.

기존의 리소스를 변경하는데 사용하도록 합니다.

설명

바디 유무

DELETE

리소스를 제거하는데 사용합니다.

X

O

O

O

주의: 각각의 메소드는 위의 설명에 나온 목적에 따라서 사용하도록 합니다. 위의 목적 반하여 메소드를 사용하지 않도록 합니다.

바디 메시지

실제 명령을 내릴 메시지를 나타냅니다. 기본적으로 JSON 언어를 사용합니다. 헤더는 반드시 Content/Type 을

Application/json 으로 설정합니다.

예시>

{

“port”: {

“name”: “ge1”,

“speed”: 1000,

“duplex”: full

7

}

}

PREST-API 인증 방법

Basic Auth

Basic Auth 방식은 가장 잘 알려진 HTTP 인증 규약입니다. 보안상 비 인가된 사용자의 접근을 막기 위해 이 방식을

사용합니다.  HTTP  프로토콜은  사용자  정보를  전달하기  때문에  보안상으로  안전하지  않습니다.  따라서  반드시

HTTPS  프로토콜을  사용합니다.  ID 와  Password 는  PREST-API 기존에  설정되어있는  값이나,  새로  수정한  값을

입력하도록 합니다.

권한

권한

설명

8

WEBFRONT-K PREST API 설명서

제 2 장
System 명령

9

2-1 VLAN 명령

VLAN 를 생성합니다.

Methods

GET, POST, DELETE

URI

/api/v2/conf/vlan

요청 예시 (VLAN 추가)

Method

POST

URI

설명

/api/v2/conf/vlan

WEBFRONT-K 장비에 vlan1 이름의 vid 5 을 설정합니다.

요청 파라미터 예시

항목

name

vid

값

vlan1

5

port: name

ge5

port: type

tagged

요청 바디 메시지

{

    "vlan": {

     "name": "vlan1",

     "vid": 5,

     "port": {

"name": "ge5",

"type": "tagged"

     }

    }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

10

WEBFRONT-K PREST API 설명서

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (해당 vlan 설정 보기)

Method

GET

URI

설명

/api/v2/conf/vlan/vlan1

vlan1 의 설정 정보를 불러옵니다.

응답 메시지

{

    "vlan": {

        "name": "vlan1",

        "vid": "5",

        "port": {

            "type": "tagged",

            "name": "ge5"

        }

    }

}

요청 예시 (vlan 설정 제거)

Method

DELETE

URI

설명

/api/v2/conf/vlan

설정된 vlan1 을 제거합니다.

요청 파라미터 예시

항목

값

vlan: name

vlan1

요청 바디 메시지

{

    "vlan": {

     "name": "vlan1"

11

    }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (VLAN 의 해당하는 포트만 제거)

Method

DELETE

URI

설명

/api/v2/conf/vlan/vlan1

설정된 vlan1 에서 특정 포트만 제거합니다.

요청 파라미터 예시

항목

port: name

값

ge5

요청 바디 메시지

{

     "port": {

"name": "ge5",

"type": "tagged"

     }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

12

WEBFRONT-K PREST API 설명서

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

13

2-2 Interface IP

VLAN 인터페이스의 IP 주소를 지정하는 명령입니다.

Methods

GET, POST, DELETE

URI

/api/v2/conf/interface/[name]

요청 예시 (interface 에 IP 추가)

Method

POST

URI

설명

/api/v2/conf/interface/vlan2

설정되어있는 interface vlan2 에 IP 를 추가하는 예제입니다.

interface 에서 설정되어있는 vlan2 에서 IP 를 추가하기 위해 uri 를 위와 같이 써줘야 합니다.

요청 파라미터 예시

항목

값

broadcast

100.30.10.255

address

100.30.10.10/24

요청 바디 메시지

{

"ip": {

"broadcast": "100.30.10.255",

"address": "100.30.10.10/24"

}

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

14

WEBFRONT-K PREST API 설명서

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (interface IP 설정 보기)

Method

GET

URI

설명

/api/v2/conf/interface/vlan2

interface vlan2 의 설정 정보를 보여줍니다.

응답 메시지

{

    "interface": {

        "status": "up",

        "name": "vlan2",

        "adv-default-lifetime": "1800",

        "adv-cur-hop-limit": "64",

        "mac": "00:06:c4:70:02:7b",

        "adv-send-advert": "enable",

        "mtu": "1500",

        "min-rtr-adv-interval": "198",

        "rpf": "default",

        "adv-reachable-time": "0",

        "max-rtr-adv-interval": "600",

        "adv-retrans-timer": "0",

        "ip": {

            "broadcast": "100.30.10.255",

            "overlapped": null,

            "address": "100.30.10.10/24"

        }

    }

}

요청 예시 (interface IP 제거)

Method

DELETE

URI

설명

/api/v2/conf/interface/vlan2

설정된 vlan2 에서 IP 를 제거합니다.

요청 파라미터 예시

항목

값

15

broadcast

100.30.10.255

address

100.30.10.10/24

요청 바디 메시지

{

"ip": {

"broadcast": "100.30.10.255",

"address": "100.30.10.10/24"

}

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

2-3 포트 바운더리 명령

PREST-API 를 이용하여 포트 바운더리 설정을 합니다.

Methods

GET, POST, DELETE

URI

/prestapi/v2/conf/port-boundary

요청 예시 (포트 바운더리 설정)

Method

POST

URI

16

/api/v2/conf/port-boundary

WEBFRONT-K PREST API 설명서

설명

WEBFRONT-K 로 수신되는 패킷을 스위칭 하기 위해 포트 바운더리를 설정합니다.

요청 파라미터 예시

항목

id

dip

값

2

210.1.1.0/24

dport

8080

include-mac

none

port

ge1, ge3-5

promisc

protocol

on

tcp

sip

sport

status

vid

168.10.0.0/16

80

disable

2

바디 요청 메시지

{

"port-boundary": {

  "id": "2",

  "dip": "210.1.1.0/24",

  "dport": 8080,

  "include-mac": "none",

  "port": [

"ge1",

"ge3",

"ge4",

"ge5"

  ],

  "promisc": "on",

  "protocol": "tcp",

  "sip": "168.10.0.0/16",

  "sport": 80,

  "vid": 2,

  "status": "disable"

}

}

응답 파라미터

isSuccessful

true or false

17

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (해당 포트의 설정 보기)

Method

GET

URI

설명

/prestapi/v2/conf/port-boundary

port-boundary 의 전체 설정을 불러옵니다.

응답 메시지

{

    "port-boundary": [

        {

            "status": "enable",

            "sip": "0.0.0.0/0",

            "protocol": "tcp",

            "vid": "2",

            "id": "1",

            "include-mac": "unicast",

            "promisc": "off",

            "dport": null,

            "boundary": "all",

            "sport": null,

            "dip": "210.1.1.0/24",

            "port": [

                "ge17",

                "ge18"

            ]

        },

        {

            "status": "enable",

            "sip": "210.1.1.0/24",

            "protocol": "tcp",

            "vid": "2",

            "id": "2",

            "include-mac": "unicast",

18

WEBFRONT-K PREST API 설명서

            "promisc": "off",

            "dport": null,

            "boundary": "all",

            "sport": null,

            "dip": "0.0.0.0/0",

            "port": [

                "ge17",

                "ge18"

            ]

        }

    ]

}

요청 예시 (해당 포트의 설정 제거)

Method

DELETE

URI

설명

/api/v2/conf/port-boundary

port-boundary 의 id 2 번의 설정을 제거 합니다.

요청 파라미터 예시

항목

id

값

2

요청 바디 메시지

{

}

"port-boundary": {

"id": "2"

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

19

}

2-4 애플리케이션 추가/조회/삭제

애플리케이션 추가/조회/삭제를 합니다.

Methods

GET, POST, DELETE

URI

/api/v2/site/site-app/app-list

요청 예시 (애플리케이션 추가)

Method

POST

URI

설명

/api/v2/site/site-app/app-list

애플리케이션을 추가 합니다.

요청 파라미터 예시

항목

name

값

app_name

description

application name

요청 바디 메시지

{  "name": {

       "description":  "application name",

       "type": "app_name"

    }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

20

WEBFRONT-K PREST API 설명서

        "isSuccessful": true

    }

}

요청 예시 (전체 애플리케이션 설정 정보 조회)

Method

GET

/api/v2/site/site-app/app-list

애플리케이션의 전체 설정 정보를 불러옵니다.

URI

설명

응답 메시지

{

    "app_list": {

        "app_entry": [

            {

                "app_id": "255",

                "name": "default_app",

                "desc": "",

                "priority": "255"

            },

            {

                "app_id": "1",

                "name": "http",

                "desc": "",

                "priority": "1"

            },

            {

                "app_id": "2",

                "name": "https",

                "desc": "",

                "priority": "2"

            }

        ]

    }

}

요청 예시 (특정 애플리케이션 설정 정보 조회)

Method

GET

URI

설명

/api/v2/site/site-app/app-list/1

“app_id”가 “1”인 애플리케이션 설정 정보를 불러옵니다.

응답 메시지

{

    "app_entry": {

21

        "app_id": "1",

        "name": "http",

        "desc": "",

        "priority": "1"

    }

}

요청 예시 (애플리케이션  제거)

Method

DELETE

URI

설명

/api/v2/site/site-app/app-list/1

설정된 애플리케이션 아이디가 1 의 애플리케이션을 제거합니다.

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

2-5 시그니처 클래스 별로 설정 변경

시그니처를 클래스 별로 설정 변경 합니다.

Methods

GET, POST, PUT, DELETE

Method

GET

POST

PUT

설명

시그니처 클래스 별로 시그니처 전체 정보 조회

시그니처 클래스 별로 사용자 정의 시그니처 추가

일반 시그니처 및 사용자 정의 시그니처 설정 변경

DELETE

사용자 정의 시그니처 삭제

URI

22

/api/v2/site/paf_sig_base/{시그니처 클래스}

WEBFRONT-K PREST API 설명서

시그니처 클래스

설명

허용 Method

sig_id (9 자)

sig_info

sig_req_appac

sig_req_buffer

시그니처 정보

GET

비고

접근제어-차단 URL

GET, POST, PUT, DELETE

1101xxxxx

버퍼오버플로우-

GET, POST, PUT, DELETE

1105

쉘코드검사

sig_req_download

다운로드검사

GET, POST, PUT, DELETE

1112

sig_req_filter

금칙어차단-금지된

GET, POST, PUT, DELETE

2118 (사용자 정의)

단어

sig_req_include

인클루드

인젝션

GET, POST, PUT, DELETE

1114

차단

sig_req_sql

SQL 삽입차단

GET, POST, PUT, DELETE

1106

sig_req_sqllogin

SQL

삽입차단

GET, POST, PUT, DELETE

1117

논리연산차단

sig_req_tool

웹공격프로그램차단  GET, PUT

1115

sig_req_upload

업로드검사-파일내용  GET, POST, PUT, DELETE

1111

sig_req_uploadfile

업로드검사-

파일확장자

GET, PUT

1116

sig_req_url

접근제어-URL

GET, POST, PUT, DELETE

1201

정규식검사

sig_req_xss

스크립트삽입차단

GET, POST, PUT, DELETE

1107

sig_update_history

업데이트된 시그니처  GET

비고

참고: 사용자 정의 시그니처인 경우 “sig_id”가 “2”로 시작합니다. ex) 접근제어-차단 URL  2101xxxxx, 다운로드검사 2112xxxxx

시그니처 클래스 별 사용자 정의 시그니처 허용 시그니처 유형(sig_type)

시그니처 클래스

하용 시그니처 유형(sig_type) ( 0: 문자열, 1: 정규식, 2: URL, 3: PCRE)

sig_req_appac

2

sig_req_buffer

sig_req_download

sig_req_filter

0, 1, 3

0, 1, 3

0, 1, 3

sig_req_include

2

sig_req_sql

sig_req_sqllogin

0, 1, 3

0, 1, 3

sig_req_tool

사용자 정의 시그니처 기능을 지원(X)

sig_req_upload

0, 1, 3

sig_req_uploadfile

사용자 정의 시그니처 기능을 지원(X)

sig_req_url

sig_req_xss

1, 3

0, 1, 3

요청 예시 (접근제어-차단 URL 사용자 정의 시그니처 추가)

Method

POST

URI

/api/v2/site/paf_sig_base/sig_req_appac

23

설명

접근제어-차단 URL 사용자 정으 시그니처를 추가합니다.

요청 파라미터 예시

항목

값

sig_content

/test

sig_status

1 ( 1 : 탐지. 2 : 차단, 3 : 예외)

sig_type

3

sig_ko_desc

test

요청 바디 메시지

{

  "sig_entry":[

    {

      "sig_content":"/test1",

      "sig_status":"1",

      "sig_type":"1",

      "sig_ko_desc":"test1"

    }

    ]

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (접근제어-차단 URL 전체 시그니처 조회)

Method

GET

/api/v2/site/paf_sig_base/sig_req_appac

접근제어-차단 URL 전체 시그니처 정보를 불러옵니다.

URI

설명

24

WEBFRONT-K PREST API 설명서

응답 메시지

{

    "sig_req_appac": {

        "sig_entry": [

            {

                "sig_id": "110100001",

                "sig_content": "VkdTQ2cuNDQ6ZGQ=",

                "sig_status": "1",

                "sig_level": "1",

                "sig_warning": "1",

                "sig_type": "2",

                "sig_expire": "0",

                "sig_staging": "0",

                "sig_update_status": "0",

                "sig_update_type": "0",

                "sig_ko_desc": ".htaccess \uc561\uc138\uc2a4 \uacf5\uaca9",

                "sig_eg_desc": "Attack by .htaccess",

                "sig_jp_desc": "Attack by .htaccess",

                "sig_ch_desc": "\u8bbf\u95ee\u653b\u51fb"

            },

...

요청 예시 (접근제어-차단 URL 사용자 정의 시그니처)

Method

DELETE

URI

설명

/api/v2/site/paf_sig_base/sig_req_appac

접근제어-차단 URL 사용자 정으 시그니처를 추가합니다.

요청 파라미터 예시

항목

sig_id

값

210100001

요청 바디 메시지

{

  "sig_entry":[

    {

      "sig_id":"210100001"

    }

    ]

}

응답 파라미터

25

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (접근제어-차단 URL 일반 시그니처 설정 변경)

Method

PUT

URI

설명

/api/v2/site/paf_sig_base/sig_req_appac

접근제어-차단 URL 일반 시그니처의 설정을 변경합니다.

요청 파라미터 예시

항목

sig_id

값

110100001

sig_status

1

요청 바디 메시지

{

  "sig_entry":[

    {

      "sig_id":"110100001",

      "sig_status":"1"

    }

    ]

}

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

26

WEBFRONT-K PREST API 설명서

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (접근제어-차단 URL 사용자 정의  시그니처 설정 변경)

Method

PUT

URI

설명

/api/v2/site/paf_sig_base/sig_req_appac

접근제어-차단 URL 사용자 정 시그니처의 설정을 변경합니다.

요청 파라미터 예시

항목

sig_id

값

210100001

sig_status

sig_type

1

2

sig_content

/test2

sig_ko_desc

Restapi 시그니처 테스트

요청 바디 메시지

{

  "sig_entry":[

    {

      "sig_id":"210100001",

      "sig_status":"1",

      "sig_type":"2",

      "sig_content":"/test2",

      "sig_ko_desc":"Restapi 시그니처 테스트"

    }

    ]

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

27

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

28

WEBFRONT-K PREST API 설명서

2-6 시그니처 상태 애플리케이션 별로 설정 변경

애플리케이션 별로 시그니처 상태를 변경 합니다.

Methods

GET, PUT

URI

/api/v2/site/paf_sig_settle/{시그니처 클래스}

시그니처 클래스

설명

허용 Method

GET, PUT

sig_req_appac

접근제어-차단 URL

         sig_req_buffer

버퍼오버플로우-쉘코드검사

sig_req_download

다운로드검사

sig_req_filter

sig_req_include

sig_req_sql

sig_req_sqllogin

sig_req_tool

sig_req_upload

금칙어차단-금지된 단어

인클루드 인젝션 차단

SQL 삽입차단

SQL 삽입차단 논리연산차단

웹공격프로그램차단

업로드검사-파일내용

sig_req_uploadfile

업로드검사-파일확장자

sig_req_url

sig_req_xss

접근제어-URL 정규식검사

스크립트삽입차단

요청 예시 (애플리케이션 별로 접근제어-차단 URL 상태를 조회)

Method

GET

/api/v2/site/paf_sig_settle/sig_req_appac

애플리케이션 별로 접근제어-차단 URL 상태 정보를 불러옵니다.

URI

설명

응답 메시지

{

    "sig_req_appac": {

        "sig_entry": {

            "app_id": "1",

            "sig_id": "110100001",

            "sig_status": "2"

        }

    }

}

요청 예시 (애플리케이션 별로 접근제어-차단 URL 상태를 설정(변경))

Method

PUT

29

URI

설명

/api/v2/site/paf_sig_settle/sig_req_appac

애플리케이션 별로 접근제어-차단 URL 상태를 설정(변경)합니다.

요청 파라미터 예시

항목

sig_id

값

110100001

sig_status

app_id

2

1

요청 바디 메시지

{

  "sig_entry":[

    {

      "sig_id":"110100001",

      "sig_status":"2",

      "app_id":"1"

    }

    ]

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

 참고: 사용자 정의 시그니처 또한 애플리케이션 별로 설정이 가능합니다.

30

WEBFRONT-K PREST API 설명서

2-7 블랙리스트 사용자 정의 IP 설정 변경

블랙리스트 고급 설정의 사용자 정의 IP 설정을 변경합니다.

Methods

GET, POST, DELETE

URI

/api/v2/site/paf_site_blacklist/ip_list

요청 예시 (블랙리스트 IP 추가)

Method

POST

URI

설명

/api/v2/site/paf_site_blacklist/ip_list

블랙리스트 IP 를 추가 설정 합니다.

요청 파라미터 예시

항목

값

ipaddr_value

192.168.0.0/32

status

4 (4 : 영구차단, 5 : 허용)

permanent_enabe  0 (0 : 영구 차단 or 영구 허용 비활성화, 1 :  영구 차단 or 영구 허용 활성화)

요청 바디 메시지

{

    "entry":[

    {

        "ipaddr_value":"192.168.0.0/32",

        "status":"4",

        "permanent_enable":"0"

    }

        ]

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

31

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (블랙리스트 IP 조회)

Method

GET

URI

설명

/api/v2/site/paf_site_blacklist/ip_list

불랙리스트 IP 전체 설정 정보를 불러옵니다.

응답 메시지

{

    "ip_list": {

        "entry": [

            {

                "ipaddr_value": "1.1.1.1",

                "ipaddr": "1.1.1.1",

                "maskbits": "99",

                "term_of_validity": "30",

                "unit_time_validity": "1",

                "registration_times": "1522223534",

                "permanent_enable": "1",

                "detected_pos": "0",

                "desc": "",

                "status": "4"

            },

            {

                "ipaddr_value": "2.2.2.2",

                "ipaddr": "2.2.2.2",

                "maskbits": "99",

                "term_of_validity": "30",

                "unit_time_validity": "1",

                "registration_times": "1522223534",

                "permanent_enable": "1",

                "detected_pos": "0",

                "desc": "",

                "status": "5"

            }

        ]

    }

}

요청 예시 (블랙리스트 IP 삭제)

32

WEBFRONT-K PREST API 설명서

Method

DELETE

URI

설명

/api/v2/site/paf_site_blacklist/ip_list

블랙리스트 IP 를 삭제 설정 합니다.

요청 파라미터 예시

항목

값

ipaddr_value

192.168.0.0/32

status

4 (4 : 영구차단, 5 : 허용)

permanent_enabe  0 (0 : 영구 차단 or 영구 허용 비활성화, 1 :  영구 차단 or 영구 허용 활성화)

요청 바디 메시지

{

    "entry":[

    {

        "ipaddr_value":"192.168.0.0/32",

        "status":"4",

        "permanent_enable":"0"

    }

        ]

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

33

2-8 설정 저장

웹방화벽 운영 중인 설정을 저장 합니다.

Methods

POST

URI

api/v2/site/site-boot/save-config

요청 예시 (운영 중인 설정을 저장)

Method

POST

URI

설명

/api/v2/site/site-boot/save-config

현재 운영 중인 설정을 최근 부팅에 사용된 슬롯에 저장 합니다.

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

34

WEBFRONT-K PREST API 설명서

2-9 사용자 관리

사용자 계정을 추가, 변경, 삭제, 조회 합니다.

Methods

GET, POST, PUT, DELETE

URI

api/v2/site/paf_site_user/user_list

요청 예시 (전체 사용자 계정 조회)

Method

GET

URI

설명

api/v2/site/paf_site_user/user_list

현재 설정된 사용자 계정 전체를 조회합니다.

응답 메시지

{

    "user_list": {

        "user_entry": {

            "app_list": null,

            "shortcut_list": null,

            "user_id": "wfadmin",

            "email": "edit_this_email@piolink.com",

            "gui_login_exp": "0",

            "current_login_fail_count": "0",

            "max_login_fail_count": "10",

            "max_login_fail_count_set_time": "0",

            "def_menu": "0",

            "desc": "Default User",

            "user_type": "0",

            "prev_pass2": "",

            "prev_pass3": "",

            "prev_pass4": "",

            "terminal_login_exp": "0"

        }

    }

}

요청 예시 (하나의 사용자 계정 조회)

Method

GET

URI

설명

api/v2/site/paf_site_user/user_list/wfadmin

사용자 아이디가 “wfadmin”인 계정 정보를 조회합니다.

35

응답 메시지

{

    "user_entry": {

        "app_list": null,

        "shortcut_list": null,

        "user_id": "wfadmin",

        "email": "edit_this_email@piolink.com",

        "gui_login_exp": "0",

        "current_login_fail_count": "0",

        "max_login_fail_count": "10",

        "max_login_fail_count_set_time": "0",

        "def_menu": "0",

        "desc": "Default User",

        "user_type": "0",

        "prev_pass2": "",

        "prev_pass3": "",

        "prev_pass4": "",

        "terminal_login_exp": "0"

    }

}

요청 예시 (사용자 계정을 추가)

Method

POST

URI

설명

/api/v2/site/paf_site_user/user_list

사용자 계정을 추가합니다.

요청 파라미터 예시

항목

user_id

값

5 자리 이상의 문자

password

4 자리 이상의 문자, 숫자, 특수문자로 조합된 문자

email

이메일 주소

user_type

0 ~ 3 (0: 통합 관리자, 1: 사이트 관리자,  2: 애플리케이션 관리자, 3: 모니터 관리자)

app_id

애플리케이션 ID (애플리케이션 관리자인 경우 필수 파라미터)

permit_type

0 ~ 1 (0: 관리자, 1: 모니터) (애플리케이션 관리자인 경우 필수 파라미터)

max_login_exp

0 ~ 50 (기본값: 5)

gui_login_exp

0 ~ 1440 (기본값: 5)

terminal_login_exp  0 ~ 65535 (기본값: 5)

def_menu

0 ~ 1 (0: 고급설정모드, 1: 일반모드)

36

WEBFRONT-K PREST API 설명서

desc

설명

요청 바디 메시지(통합 관리자)

{

"user_entry": {

"user_id": "rest_test1",

"email": "a@p.com",

                          "desc": "set by prest",

                          "user_type": "0",

                          "password": "password123!",

                          "max_login_fail_count": "0",

                          "gui_login_exp": "0",

                          "terminal_login_exp": "0",

                          "def_menu": "0"

}

}

요청 바디 메시지(애플리케이션 관리자)

{

"user_entry": {

"app_list": {

"app_entry": {

"app_id": "1",

"permit_type": "0"

}

},

"user_id": "rest_test2",

"email": "a@p.com",

                          "desc": "set by prest",

                          "user_type": "2",

                          "password": "wfadmin123!",

                          "max_login_fail_count": "0",

                          "gui_login_exp": "0",

                          "terminal_login_exp": "0",

                          "def_menu": "0"

}

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

37

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (사용자 계정을 변경)

Method

PUT

URI

설명

/api/v2/site/paf_site_user/user_list

설정된 사용자 계정을 변경합니다.

요청 파라미터 예시

항목

user_id

값

5 자리 이상의 문자

current_login_fail_count  0 ~ 50

email

app_id

이메일 주소

애플리케이션 ID (애플리케이션 관리자인 경우 필수 파라미터)

permit_type

0 ~ 1 (0: 관리자, 1: 모니터) (애플리케이션 관리자인 경우 필수 파라미터)

max_login_exp

0 ~ 50 (기본값: 5)

gui_login_exp

0 ~ 1440 (기본값: 5)

terminal_login_exp

0 ~ 65535 (기본값: 5)

def_menu

0 ~ 1 (0: 고급설정모드, 1: 일반모드)

desc

설명

요청 바디 메시지(통합 관리자)

{

"user_entry": {

"user_id": "rest_test1",

"email": "",

                          "desc": "set by prest",

                          "current_login_fail_count": "0",

                          "max_login_fail_count": "0",

                          "gui_login_exp": "0",

                          "terminal_login_exp": "0",

                          "def_menu": "0"

}

}

38

WEBFRONT-K PREST API 설명서

요청 바디 메시지(애플리케이션 관리자)

{

"user_entry": {

"app_list": {

"app_entry": {

"app_id": "1",

"permit_type": "1"

}

},

"user_id": "rest_test2",

"email": "a@p.com",

                          "desc": "set by prest",

                          "current_login_fail_count": "0",

                          "max_login_fail_count": "0",

                          "gui_login_exp": "0",

                          "terminal_login_exp": "0",

                          "def_menu": "0"

}

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (사용자 계정을 삭제)

Method

DELETE

URI

설명

/api/v2/site/paf_site_user/user_list

설정된 사용자 계정을 삭제합니다.

요청 파라미터 예시

항목

값

39

user_id

5 자리 이상의 문자

요청 바디 메시지

{

}

"user_entry": {

"user_id": "rest_test1"

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

 참고: Default User 는 추가, 변경, 삭제가 불가능 합니다.

 참고: 애플리케이션 관리자의 애플리케이션 설정을 변경할 경우 기존 설정은 제거되고 요청한 설정으로 업데이트 됩니다.

40

WEBFRONT-K PREST API 설명서

2-10 라이센스 관리

유시보수 라이센스 & 성능 라이센스 정보 조회 및 등록합니다.

Methods

GET, POST

URI

/api/v2/amss/license/warranty-license

/api/v2/amss/license/license

요청 예시 (유지보수 라이센스 정보 조회)

Method

GET

URI

설명

/api/v2/amss/license/warranty-license

유지보수 라이센스 정보를 조회합니다.

응답 메시지

{

    "Warranty": "99",

    "Expired date": "UNLIMITED",

    "License status": "UNLIMITED",

    "License type": "SUPER",

    "Regist key": "SUPER_LICENSE",

    "Serial number": "R00000000000000",

    "Issue date": "UNLIMITED"

}

요청 예시 (유지보수 라이센스 등록)

Method

POST

URI

설명

/api/v2/amss/license/warranty-license

유지보수 라이센스를 등록합니다.

요청 파라미터 예시

항목

key

lvc

값

유지보수 라이센스 키

유지보스 라이센스 검증코

요청 바디 메시지

41

{

"key": "FFFFFFFFFFFFFFFFFF",

             “lvc”: “XXXXXX”

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (성능 라이센스 정보 조회)

Method

GET

URI

설명

/api/v2/amss/license/license

성능 라이센스 정보를 조회합니다.

응답 메시지

{

    "SSL ( UNLIMITED TPS )": "2019/09/19",

    "CPS ( 16000 CPS )": "2019/09/19",

    "Throughput ( 1000 MBPS )": "2019/09/19",

    "Serial number": "RFFFFFFFFFFFFFF",

    "Version": "1",

    "Issue date": "2018/09/20",

    "VINSTANCE ( 10 )": "2019/09/19"

}

요청 예시 (성능 라이센스 등록)

Method

POST

URI

42

/api/v2/amss/license/license

WEBFRONT-K PREST API 설명서

설명

성능 라이센스를 등록합니다.

요청 파라미터 예시

항목

key

값

성능 라이센스 키

요청 바디 메시지

{

}

"key": "FFFFFFFFFFFFFFFFFF"

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

43

제 3 장
Application 설정

44

WEBFRONT-K PREST API 설명서

3-1  Application  일반설정(IP/PORT  리스트,  도메인
리스트)

보호대상 웹서버에 대한 일반정보(IP/Port/Domain)에 대한 설정을 합니다.

Methods

GET, POST, DELETE

URI

/api/v2/app/{app_id}/app-gen/ip-list

/api/v2/app/{app_id}/app-gen/domain-list

요청 예시 (app_id 1 번 애플리케이션에 도메인 추가 )

Method

POST

URI

설명

/api/v2/app/1/app-gen/domain-list

app_id 1 번 애플리케이션에 대한 도메인을 추가 합니다.

요청 파라미터 예시

항목

값

domain

your-domain.com

요청 바디 메시지

{

    "domain":"your-domain.com"

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

45

    }

}

요청 예시 (app_id 1 번 애플리케이션에 웹서버 IP / Port 추가 )

Method

POST

URI

설명

/api/v2/app/1/app-gen/ip-list

app_id 1 번 애플리케이션에 대한 도메인을 추가 합니다..

요청 파라미터 예시

항목

Ip

port

값

10.1.1.12

80

요청 바디 메시지

{

    "ip":"10.1.1.12",

    "port":"80"

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (app_id 1 번 애플리케이션에 도메인 리스트 조회)

Method

GET

/api/v2/app/1/app-gen/domain-list

“app_id”가 “1”인 애플리케이션에 도메인 리스트의 설정 정보를 불러옵니다.

URI

설명

46

WEBFRONT-K PREST API 설명서

47

응답 메시지

{

    "domain_list": {

        "domain_entry": [

            {

                "domain": "abcd",

                "status": "1",

                "desc": ""

            },

            {

                "domain": "rest_test",

                "status": "1",

                "desc": "addedbyapi"

            }

        ]

    }

}

요청 예시 (app_id 1 번 애플리케이션에 웹서버 IP/PORT 리스트 조회)

Method

GET

/api/v2/app/1/app-gen/ip-list

“app_id”가 “1”인 애플리케이션에 IP/PORT 리스트의 설정 정보를 불러옵니다.

URI

설명

응답 메시지

{

    "ip_list": {

        "ip_entry": [

            {

                "id": "1",

                "ip": "192.168.216.71",

                "port": "80",

                "type": "0",

                "status": "1",

                "tp": "1",

                "desc": "",

                "version": "4"

            },

            {

                "id": "2",

                "ip": "1.1.1.12",

                "port": "80",

                "type": "0",

                "status": "1",

                "tp": "1",

                "desc": "addedbyapi",

                "version": "4"

            }

48

WEBFRONT-K PREST API 설명서

        ]

    }

}

요청 예시 (app_id 1 번 애플리케이션에 도메인 삭제 )

Method

DELETE

URI

설명

/api/v2/app/1/app-gen/domain-list/your-domain.com

app_id 1 번 애플리케이션의 “your-domain.com” 도메인을 삭제 합니다.

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (app_id 1 번 애플리케이션에 웹서버 IP / Port 삭제 )

Method

DELETE

URI

설명

/api/v2/app/1/app-gen/ip-list/1

app_id 1 번 애플리케이션의 “id”가 “1”인 IP/PORT 를 삭제합니다.

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

49

        "isSuccessful": true

    }

}

50

WEBFRONT-K PREST API 설명서

3-2 Application 일반설정(상태, 일반 설정 정보)

보호대상 웹서버에 대한 일반정보(status/info)에 대한 설정을 합니다.

Methods

GET, PUT

URI

/api/v2/app/{app_id}/app-gen/status

/api/v2/app/{app_id}/app-gen/info

요청 예시 (app_id 1 번 애플리케이션에 상태 조회)

Method

GET

/api/v2/app/1/app-gen/status

“app_id”가 “1”인 애플리케이션에 상태 설정 정보를 불러옵니다.

URI

설명

응답 메시지

{

    "status": {

        "enable": "0",

        "default_url_match": "1"

    }

}

요청 예시 (app_id 1 번 애플리케이션 상태 변경)

Method

PUT

URI

설명

/api/v2/app/1/app-gen/status

app_id 1 번 애플리케이션 상태 설정을 변경 합니다

요청 파라미터 예시

항목

enable

값

(0): 비활성화, (1): 활성화

요청 바디 메시지

{

    "enable":"1"

}

51

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (app_id 1 번 애플리케이션에 일반 설정 정보 조회)

Method

GET

/api/v2/app/1/app-gen/info

“app_id”가 “1”인 애플리케이션에 상태 설정 정보를 불러옵니다.

URI

설명

응답 메시지

{

    "info": {

        "lbmode": "0",

        "ignore_domain": "1",

        "remove_encode": "0",

        "client_side_tcp_mss": "1460",

        "server_side_tcp_mss": "0",

        "max_cps_limit": "0",

        "max_cc_limit": "0",

        "max_bps_limit": "0",

        "max_bps_size": "98",

        "proxy_type": "0"

    }

}

요청 예시 (app_id 1 번 애플리케이션 일반 설정 정보의 도메인 무시 설정 변경)

Method

PUT

/api/v2/app/1/app-gen/info

app_id 1 번 애플리케이션 일반 설정 정보의 도메인 무시 설정을 변경합니다

URI

설명

52

WEBFRONT-K PREST API 설명서

요청 파라미터 예시

항목

값

ignore_domain

(0): 비활성화, (1): 활성화

요청 바디 메시지

{

    "ignore_domain": "1"

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

53

3-3 요청검사 보안기능 활성화/비활성화 설정

요청검사 보안기능에 대한 활성화, 비활성화 설정을 변경합니다..

Methods

GET, PUT

URI

/api/v2/app/{app_id}/{보안기능}/status

보안 기

설명

req-appac  접근제어

req-buffer  버퍼오버플로우차단

req-sql

SQL 삽입차단

Req-tool

웹공격프로그램차단

req-xxs

스크립트삽입차단

요청 예시 (app_id 1 번 애플리케이션에 접근제어 기능 활성화, 차단 기능 활성화, 로그기능 활성화)

Method

PUT

URI

설명

/api/v2/app/{app_id}/req-appac/status

app_id 1 번 애플리케이션에 접근제어 기능 활성화, 차단 기능 활성화, 로그기능 활성화..

요청 파라미터 예시

항목

enable

block

log

값

1 (0 : 비활성화, 1 : 활성화)

1 (0 : 비활성화, 1 : 활성화)

1 (0 : 비활성화, 1 : 활성화)

요청 바디 메시지

{

      "enable":"1",

      "block":"1",

      "log":"1"

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

54

WEBFRONT-K PREST API 설명서

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (app_id 1 번 애플리케이션에 접근제어 상태 정보 조회)

Method

GET

URI

설명

/api/v2/app/{app_id}/req-appac/status

app_id 1 번 애플리케이션에 접근제어 상태정보를 불러옵니다.

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "status": {

        "enable": "1",

        "log": "1",

        "allow_log": "0",

        "alarm": "0",

        "block": "1",

        "learn": "0",

        "start": "0",

        "advanced_ac": "0",

        "access_log": "0",

        "url_regex": "0",

        "blacklist": "0",

        "geoip_status": "0",

        "no_extension_allow": "0"

    }

}

55

3-4 부하분산 - 소스 NAT 설정

부하분산 – 소스 NAT 상태 및 IP 리스트를 설정합니다.

Methods

status: GET, PUT

ip_list: GET, POST, DELETE

URI

api/v2/app/{app_id}/paf_app_src_nat/status

api/v2/app/{app_id}/paf_app_src_nat/ip_list

요청 예시 (부하분산 – 소스 NAT 상태 조회)

Method

GET

api/v2/app/1/paf_app_src_nat/status

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 소스 NAT 상태를 조회합니다.

URI

설명

응답 메시지

{

    "status": {

        "enable": "1"

    }

}

요청 예시 (부하분산 – 소스 NAT 상태 변경)

Method

PUT

URI

설명

/api/v2/app/1/paf_app_src_nat/status

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 소스 NAT 상태를 활성화합니다.

요청 파라미터 예시

항목

enable

값

(0): 비활성화, (1): 활성화

요청 바디 메시지

{

    "status": {

        "enable": "1"

    }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (부하분산 – 소스 NAT IP 리스트 조회)

Method

GET

api/v2/app/1/paf_app_src_nat/ip_list

애플리케이션  ID 가  “1”인  애플리케이션의  부하분산  –  소스 NAT  IP  리스트  정보를

조회합니다.

URI

설명

응답 메시지

{

    "ip_list": {

        "ip_entry": {

            "status": "1",

            "ip": "10.10.10.10",

            "desc": "by rest"

        }

    }

}

요청 예시 (부하분산 – 소스 NAT IP 리스트 추가)

Method

POST

URI

설명

/api/v2/app/1/paf_app_src_nat/ip_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 소스 NAT IP 리스트를 설정합니다.

요청 파라미터 예시

항목

status

Ip

desc

값

(0): 비활성화, (1): 활성화

IP 주소

설정에 대한 설명

요청 바디 메시지

{

    "ip_entry": {

        "status": "1",

        "ip": "10.10.10.10",

        "desc": "by rest"

        }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

 참고: IP 트랜스패런트 모드인 VIP 를 소스 NAT IP 로 설정할 수 없습니다.

요청 예시 ( 부하분산 – 소스 NAT IP 리스트 삭제)

Method

DELETE

URI

설명

/api/v2/app/1/paf_app_src_nat/ip_list

애플리케이션  ID 가  “1”인  애플리케이션의  부하분산  –  소스 NAT  IP  리스트  ID 가  “1”인

리스트를 삭제합니다.

요청 파라미터 예시

항목

Ip

값

삭제할 IP 리스트의 IP

요청 바디 메시지

{

    "ip_entry": {

        "ip": "10.10.10.10"

        }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

3-5 부하분산 – (패턴, 실제서버, 그룹, 규칙, 장애감시)

부하분산 – 패턴, 실제서버, 그룹, 규칙, 장애감시를 설정합니다.

Methods

GET, POST, PUT, DELETE

URI

api/v2/app/{app_id}/paf_lb/{기능}

기능

패턴

pattern_list

실제서버

server_list

그룹

규칙

group_list

rule_list

장애감시

hc_list

요청 예시 (부하분산 – 패턴 리스트 조회)

Method

GET

URI 설정

api/v2/app/1/paf_lb/pattern_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 패턴 리스트를 조회합니다.

URI

설명

응답 메시지

{

    "pattern_list": {

        "pattern_entry": {

            "id": "1",

            "type": "0",

            "method": "1",

            "pattern": "pattern_rest1",

            "ref_cnt": "0",

            "desc": "by rest"

        }

    }

}

요청 예시 ( 부하분산 – 패턴 리스트 추가)

Method

POST

URI

/api/v2/app/1/paf_lb/ip_list

설명

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 패턴 리스트를 추가합니다.

요청 파라미터 예시

항목

Type

Method

Pattern

Desc

값

(0): URI, (1): 호스트, (2): 쿠키, (3): 사용자-에이전트, (4): Accept-Language

(1): Any, (2): 시작, (3): 끝, (4): 정규식

패턴 (범위: 1 ~ 127)

설명

요청 바디 메시지

{

    "pattern_entry": {

        "type": "0",

        "method": "1",

        "pattern": "pattern_rest1",

        "desc": "by rest"

        }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (부하분산 – 패턴 리스트 변경)

Method

PUT

URI

설명

/api/v2/app/1/paf_lb/pattern_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 패턴 리스트를 변경합니다.

요청 파라미터 예시

항목

Id

Type

Method

Pattern

Desc

값

변경할 패턴 리스트 ID

(0): URI, (1): 호스트, (2): 쿠키, (3): 사용자-에이전트, (4): Accept-Language

(1): Any, (2): 시작, (3): 끝, (4): 정규식

패턴 (범위: 1 ~ 127)

설명

요청 바디 메시지

{

    "pattern_entry": {

     "id": "1",

     "type": "4",

     "method": "3",

     "pattern": "pattern_rest4",

     "desc": "by rest"

        }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 ( 부하분산 – 패턴 리스트 삭제)

Method

DELETE

URI

설명

/api/v2/app/1/paf_lb/pattern_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 패턴 리스트 ID 가 “1”인 리스트를

삭제합니다.

요청 파라미터 예시

항목

Id

값

삭제할 패턴 리스트의 ID

요청 바디 메시지

{

    "pattern_entry": {

        "id": "1"

     }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

참고: 삭제할 패턴을 다른곳에서 참조하고 있을 경우 해당 패턴을 삭제할 수 없습니다.

요청 예시 (부하분산 – 실제서버 리스트 조회)

Method

GET

api/v2/app/1/paf_lb/server_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 실제서버 리스트를 조회합니다.

URI

설명

응답 메시지

{

    "server_list": {

        "server_entry": {

            "id": "1",

            "name": "rest_test",

            "ip": "10.10.10.10",

            "port": "80",

            "weight": "1",

            "ref_cnt": "0",

            "enable_snat": "0",

            "backup_server_id": "0",

            "backup_server_name": "-",

            "max_connection": "0",

            "enable": "1",

            "status": "1",

            "desc": "by rest",

            "hc_flag": "0"

        }

    }

}

요청 예시 ( 부하분산 – 실제서버 리스트 추가)

Method

POST

URI

설명

/api/v2/app/1/paf_lb/server_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 실제서버 리스트를 추가합니다.

요청 파라미터 예시

항목

Status

Name

Ip

Port

Weight

desc

값

(0): 비활성화, (1): 활성화

실제서버 이름 (길이: 1 ~ 16)

IP 주소

포트 (범위: 0 ~ 65535)

가중치 (범위: 0 ~ 65535)

설명

요청 바디 메시지

{

    "server_entry":

    {

        "name": "rest_test",

        "ip": "10.10.10.10",

        "port": "80",

        "weight": "1",

        "status": "1",

        "desc": "by rest"

    }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (부하분산 – 실제서버 리스트 변경)

Method

PUT

URI

설명

/api/v2/app/1/paf_lb/server_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 실제서버 리스트를 변경합니다.

요청 파라미터 예시

항목

Name

Status

Ip

Port

Weight

desc

값

변경할 실제서버 이름

(0): 비활성화, (1): 활성화

IP 주소

포트 (범위: 0 ~ 65535)

가중치 (범위: 0 ~ 65535)

설명

요청 바디 메시지

{

    "server_entry":

    {

        "name": "rest_test",

        "ip": "10.10.10.11",

        "port": "443",

        "weight": "1",

        "status": "1",

        "desc": "by rest"

    }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 ( 부하분산 – 실제서버 리스트 삭제)

Method

DELETE

URI

설명

/api/v2/app/1/paf_lb/server_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 실제서버 리스트를 삭제합니다.

요청 파라미터 예시

항목

Name

값

삭제할 실제서버 리스트의 이름

요청 바디 메시지

{

    "server_entry":

    {

        "name": "rest_test"

    }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

참고: 삭제할 실제서버를 다른곳에서 참조하고 있을 경우 해당 실제서버를 삭제할 수 없습니다.

요청 예시 (부하분산 – 그룹 리스트 조회)

Method

GET

api/v2/app/1/paf_lb/group_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 그룹 리스트를 조회합니다.

URI

설명

응답 메시지

{

    "group_list": {

        "group_entry": {

            "status": "1",

            "name": "group1",

            "cookie_name": "cookie_name",

            "max_connection": "0",

            "ref_cnt": "0",

            "real_servers": "1, 2",

            "backup_group_name": "-",

            "persist": "0",

            "backup_group_id": "0",

            "num_real_servers": "2",

            "type": "1",

            "id": "1",

            "desc": "by REST"

        }

    }

}

참고: 실제서버(real_servers)가 2 개 이상일 경우 ","(콤마)로 구분 (ex> "real_servers": "1, 2")

요청 예시 ( 부하분산 – 그룹 리스트 추가)

Method

POST

URI

설명

/api/v2/app/1/paf_lb/group_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 그룹 리스트를 추가합니다.

요청 파라미터 예시

항목

Status

Name

persist

값

(0): 비활성화, (1): 활성화

그룹 이름 (길이: 1 ~ 16)

(0): 아이피, (1): 쿠키

cookie_name

쿠키 Persist 인 경우 쿠키이름 설정 가능

Type

real_servers

desc

(1): 라우드 로빈, (2): 가중치 라운드 로빈, (3): 최소 연결, (4): 가중치 최소 연결, (5): 해싱, (6): URL
해싱, (7): 최대 가중치 (8): 목적지 IP 유지
실제서버 리스트 ID(복수 설정가능) - 2 개 이상의 실제서버 ID 입력(두개이상 입력시 ","(콤마)로
구분
설명

요청 바디 메시지

{

    "group_entry": {

        "name": "group1",

        "type": "1",

        "real_servers": "1, 2",

        "status": "1",

        "persist": "0",

        "desc": "by REST"

        }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (부하분산 – 그룹 리스트 변경)

Method

PUT

URI

설명

/api/v2/app/1/paf_lb/group_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 그룹 리스트를 변경합니다.

요청 파라미터 예시

항목

Name

Status

persist

값

변경할 그룹 이름

(0): 비활성화, (1): 활성화

(0): 아이피, (1): 쿠키

cookie_name

쿠키 Persist 인 경우 쿠키이름 설정 가능

(1): 라우드 로빈, (2): 가중치 라운드 로빈, (3): 최소 연결, (4): 가중치 최소 연결, (5): 해싱, (6): URL
해싱, (7): 최대 가중치 (8): 목적지 IP 유지
실제서버 리스트 ID(복수 설정가능) - 2 개 이상의 실제서버 ID 입력(두개이상 입력시 ","(콤마)로

구분

설명

Type

real_servers

desc

요청 바디 메시지

{

    "group_entry": {

        "name": "group1",

        "type": "1",

        "real_servers": "1",

        "status": "1",

        "persist": "1",

        "cookie_name": "cookie_name",

        "desc": "by REST PUT"

        }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 ( 부하분산 – 그룹 리스트 삭제)

Method

DELETE

URI

설명

/api/v2/app/1/paf_lb/group_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 그룹 리스트를 삭제합니다.

요청 파라미터 예시

항목

Name

값

삭제할 그룹 리스트의 이름

요청 바디 메시지

{

    "group_entry": {

        "name": "group1"

        }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

참고: 삭제할 그룹을 다른곳에서 참조하고 있을 경우 해당 그룹을 삭제할 수 없습니다.

요청 예시 (부하분산 – 규칙 리스트 조회)

Method

GET

api/v2/app/1/paf_lb/rule_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 규칙 리스트를 조회합니다.

URI

설명

응답 메시지

{

    "rule_list": {

        "rule_entry": {

            "id": "1",

            "priority": "100",

            "patternid": "1",

            "patternid2": "2",

            "group_id": "1",

            "group_name": "group1",

            "status": "1",

            "desc": "by rest"

        }

    }

}

요청 예시 ( 부하분산 – 규칙 리스트 추가)

Method

POST

URI

설명

/api/v2/app/1/paf_lb/rule_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 규칙 리스트를 추가합니다.

요청 파라미터 예시

항목

Status

값

(0): 비활성화, (1): 활성화

Priority

우선순위 (범위: 0 ~ 255)

group_name

그룹 이름 설정(하나만 설정가능)

patternid

설정할 패턴 ID 입력

patternid2

설정할 두번째 패턴 ID 입력

desc

설명

요청 바디 메시지

{

    "rule_entry": {

        "priority": "100",

        "patternid": "1",

        "patternid2": "2",

        "group_name": "group1",

        "status": "1",

        "desc": "by rest"

        }

}

참고: 최대 2 개까지 패턴 ID 설정 가능

참고: 두개의 패턴 ID 가 동일할 수 업습니다.

주의: 하나만 설정할 경우 "patternid"만 설정해야하고 2 개를 설정할 경우 "patternid", "patternid2" 두개 모두 작성해야합니다. 즉,

"patternid"설정 없이 "patternid2"만 설정할 경우 패턴이 설정되지 않습니다.

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (부하분산 – 규칙 리스트 변경)

Method

PUT

URI

설명

/api/v2/app/1/paf_lb/rule_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 규칙 리스트를 변경합니다.

요청 파라미터 예시

항목

Id

Status

Priority

값

변경할 규칙 ID

(0): 비활성화, (1): 활성화

우선순위 (범위: 0 ~ 255)

group_name

그룹 이름 설정(하나만 설정가능)

patternid

설정할 패턴 ID 입력

patternid2

설정할 두번째 패턴 ID 입력

desc

설명

요청 바디 메시지

{

    "rule_entry": {

        "id": "1",

        "priority": "50",

        "patternid": "1",

        "group_name": "group1",

        "status": "1",

        "desc": "by rest PUT"

        }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 ( 부하분산 – 규칙 리스트 삭제)

Method

DELETE

URI

설명

/api/v2/app/1/paf_lb/rule_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 규칙 리스트를 삭제합니다.

요청 파라미터 예시

항목

Id

값

삭제할 규칙 리스트의 ID

요청 바디 메시지

{

    "rule_entry": {

        "id": "1",

        }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (부하분산 – 장애감시 리스트 조회)

Method

GET

api/v2/app/1/paf_lb/hc_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 장애감시 리스트를 조회합니다.

URI

설명

응답 메시지

{

    "hc_list": {

        "hc_entry": {

            "script_list": null,

            "id": "1",

            "type": "1",

            "port": "0",

            "timeout": "3",

            "interval": "5",

            "retry": "3",

            "recover": "0",

            "url": "-",

            "domain": "-",

            "enable_passive": "0",

            "increase_icmp_id": "1",

            "enable": "0",

            "status": "1",

            "desc": "by REST"

        }

    }

}

요청 예시 ( 부하분산 – 장애감시 리스트 추가)

Method

POST

URI

설명

/api/v2/app/1/paf_lb/hc_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 장애감시 리스트를 추가합니다.

요청 파라미터 예시

항목

Status

Type

값

(0): 비활성화, (1): 활성화

유형 (1): ICMP, (2): TCP, (3): HTTP, (6): HTTPS

Timeout

제한시간 (범위: 0 ~ 10)

Interval

Retry

Recover

간격 (범위: 1 ~ 60)

재시도 횟수 (범위: 0 ~ 5)

복구 횟수 (범위: 0 ~ 5)

increase_icmp_id

ICMP ID 증가 (0): 비활성화, (1): 활성화 (유형이 "ICMP"일 경우 적용)

Port

Url

Domain

desc

포트 (범위: 0 ~ 65535) (유형이 "TCP, HTTP, HTTPS"일 경우 적용)

URL (유형이 "HTTP, HTTPS"일 경우 적용)

도메인 (유형이 "HTTP, HTTPS"일 경우 적용)

설명

요청 바디 메시지

{

"hc_entry": {

"type": "3",

"port": "80",

"timeout": "3",

"interval": "5",

"retry": "3",

"recover": "0",

"url": "/hc_test",

"domain": "hc_test_d",

"status": "1",

"desc": "by REST"

}

}

참고: 유형에 맞게 필드값 조정 필요합니다.

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (부하분산 – 장애감시 리스트 변경)

Method

PUT

URI

설명

/api/v2/app/1/paf_lb/hc_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 장애감시 리스트를 변경합니다.

요청 파라미터 예시

항목

Id

Status

Type

Timeout

Interval

Retry

값

변경할 장애감시 ID

(0): 비활성화, (1): 활성화

유형 (1): ICMP, (2): TCP, (3): HTTP, (6): HTTPS

제한시간 (범위: 0 ~ 10)

간격 (범위: 1 ~ 60)

재시도 횟수 (범위: 0 ~ 5)

Recover

복구 횟수 (범위: 0 ~ 5)

increase_icmp_id

ICMP ID 증가 (0): 비활성화, (1): 활성화 (유형이 "ICMP"일 경우 적용)

Port

Url

Domain

desc

포트 (범위: 0 ~ 65535) (유형이 "TCP, HTTP, HTTPS"일 경우 적용)

URL (유형이 "HTTP, HTTPS"일 경우 적용)

도메인 (유형이 "HTTP, HTTPS"일 경우 적용)

설명

요청 바디 메시지

{

    "hc_entry": {

        "id": "1",

        "type": "1",

        "timeout": "1",

        "interval": "2",

        "retry": "3",

        "recover": "4",

        "increase_icmp_id": "1",

        "status": "1",

        "desc": "by REST PUT"

    }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 ( 부하분산 – 장애감시 리스트 삭제)

Method

DELETE

URI

설명

/api/v2/app/1/paf_lb/hc_list

애플리케이션 ID 가 “1”인 애플리케이션의 부하분산 – 장애감시 리스트를 삭제합니다.

요청 파라미터 예시

항목

Id

값

삭제할 장애감시 리스트의 ID

요청 바디 메시지

{

    "hc_entry": {

        "id": "1"

    }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

3-6 SSL – 일반설정

SSL 일반설정을 설정합니다.

Methods

GET, PUT

URI

api/v2/app/{app_id}/paf_ssl/{기능}

기능

상태

설정정보

고급설정

status

info

adv_info

SSL 버전별 차단  adv_rsp_info

요청 예시 (SSL - 일반설정 상태 조회)

Method

GET

URI 설정

/api/v2/app/1/paf_ssl/status

애플리케이션 ID 가 “1”인 애플리케이션의 SSL-일반설정의 상태를 조회합니다.

URI

설명

응답 메시지

{

    "status": {

        "enable": "0",

        "backend": "0"

    }

}

요청 예시 ( SSL - 일반설정 상태 변경)

Method

PUT

URI

설명

/api/v2/app/1/paf_ssl/status

애플리케이션 ID 가 “1”인 애플리케이션의 SSL-일반설정의 상태를 변경합니다.

요청 파라미터 예시

항목

enable

값

상태 - (0): 비활성화, (1): 활성화

backend

백엔드 – (0): 비활성화, (1): 활성화

요청 바디 메시지

{

    "status": {

        "enable": "1",

        "backend": "1"

    }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

주의: SSL-일반설정의 상태 변경시 변경할 상태에 따라 애플리케이션의 상태도 변경됩니다. (예> SSL 비활성화 → 애플리케이션 비활성화)

요청 예시 (SSL - 일반설정 설정정보 조회)

Method

GET

/api/v2/app/1/paf_ssl/info

애플리케이션 ID 가 “1”인 애플리케이션의 SSL-일반설정의 설정정보를 조회합니다.

URI

설명

응답 메시지

{

    "info": {

        "http_port": "80",

        "bandwidth_limit_rate": "1048576",

        "session_reuse_cache": "0",

        "tcp_keepalive_interval": "56",

        "reset_error_close": "0",

        "client_body_buffer_size": "1048576",

        "conn_pool": "1",

        "idle_timeout": "60",

        "max_keepalive": "30001",

        "session_resumption": "1",

        "read_timeout": "600",

        "sni_enable": "0"

    }

}

요청 예시 ( SSL - 일반설정 설정정보 변경)

Method

PUT

URI

설명

/api/v2/app/1/paf_ssl/info

애플리케이션 ID 가 “1”인 애플리케이션의 SSL-일반설정의 설정정보를 변경합니다.

요청 파라미터 예시

항목

값

session_resumption

세션 재사용 - (0): 비활성화, (1): 활성화

session_reuse_cache

클라이언트 IP 별 세션 재사용 – (0): 비활성화, (1): 활성화

max_keepalive

최대 세션 개수 – 범위(1 ~ 65535)

read_timeout

웹서버 응답 대기시간 – 범위(30 ~ 600)

client_body_buffer_size

Request Buffer Size – 범위(4096 ~ 104857600)

reset_error_close

에러시 RESET 종료 – (0): 비활성화, (1): 활성화

conn_pool

서버  HTTP  Keepalive  조건  –  (0):  client_ip  +  server_ip  +  server_port,  (1):  server_ip  +

server_port, (2): client_ip + client_port + server_ip + server_port, (3): 비활성화

idle_timeout

서버 HTTP Keepalive 제한 시간 – (0): 비활성화, 범위(1 ~ 86400)

http_port

HTTP 서비스 포트 – 범위(1 ~ 65535)

tcp_keepalive_interval  서버 TCP Keepalive - (0): 비활성화, 범위(1 ~ 32767)

bandwidth_limit_rate

요청 대역폭 제한 - (0): 비활성화, 범위(1048576 ~ 104857600)

sni_enable

Server Name Indication - (0): 비활성화, (1): 활성화

요청 바디 메시지

{

    "info": {

        "http_port": "80",

        "bandwidth_limit_rate": "3145728",

        "session_reuse_cache": "0",

        "client_body_buffer_size": "1048576",

        "reset_error_close": "0",

        "tcp_keepalive_interval": "2",

        "idle_timeout": "35",

        "conn_pool": "0",

        "max_keepalive": "29443",

        "session_resumption": "1",

        "read_timeout": "600",

        "sni_enable": "0"

    }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (SSL - 일반설정 고급설정 조회)

Method

GET

URI

설명

/api/v2/app/1/paf_ssl/adv_info

애플리케이션 ID 가 “1”인 애플리케이션의 SSL-일반설정의 고급설정을 조회합니다.

응답 메시지

{

    "adv_info": {

        "proxy_protocol": "0",

        "server_ssl_protocol": "tlsv1.1, tlsv1, tlsv1.2, sslv3",

        "dhparam_status": "0",

        "cipher_level": "2",

        "client_ssl_ciphers": "AES",

        "user_dhparam_pem": "",

        "server_ssl_ciphers":

"AES128-SHA:AES128-SHA256:AES256-SHA:AES256-

SHA256:ALL:!ADH:!EXPORT",

        "client_ssl_protocol": "tlsv1.1, tlsv1, tlsv1.2"

    }

}

요청 예시 ( SSL - 일반설정 고급설정 변경)

Method

PUT

URI

설명

/api/v2/app/1/paf_ssl/adv_info

애플리케이션 ID 가 “1”인 애플리케이션의 SSL-일반설정의 고급설정을 변경합니다.

요청 파라미터 예시

항목

값

server_ssl_protocol

서버 구간 SSL 프로토콜 – “,” 구분자로 설정가능(ex> “sslv3, tlsv1”)

client_ssl_protocol

클라이언트 구간  SSL  프로토콜  –  “cipher_level”  설정에 따라 설정, 사용자정의인 경우  “,”

server_ssl_ciphers

서버 구간 SSL 알고리즘

구분자로 설정가능(ex> “sslv3, tlsv1”)

client_ssl_ciphers

클라이언트 구간 SSL 알고리즘

dhparam_status

DH 파라미터 – (0): 비활서화, (1): 사용자정의, (2): 1024, (3): 2048, (4): 4096

user_dhparam_pem

PEM 형식 DH 파라미터 – “DH 파라미터”설정이 사용자정의인 경우 설정가능

proxy_protocol

프록시 프로토콜 – (0): 비활성화, (1): 활성화

cipher_level

클라이언트 구간 SSL 보안등급 – (0): B 등급, (1): A 등급, (2): 사용자정의

요청 바디 메시지

{

    "adv_info": {

        "proxy_protocol": "0",

        "server_ssl_protocol": "tlsv1.1, tlsv1, sslv3",

        "dhparam_status": "2",

        "cipher_level": "1",

        "client_ssl_ciphers": "ALL:!ADH:!EXPORT:!RC4:!MD5:!DES:!aNULL:!RSA:!SHA",

        "user_dhparam_pem": "",

        "server_ssl_ciphers": "AES128-SHA:AES128-SHA256:AES256-SHA:AES256-SHA256:ALL:!ADH:!EXPORT",

        "client_ssl_protocol": "tlsv1.2"

    }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

요청 예시 (SSL - 일반설정 고급설정의 SSL 버전별 차단 설정 조회)

Method

GET

/api/v2/app/1/paf_ssl/adv_rsp_info

애플리케이션  ID 가  “1”인  애플리케이션의 SSL-일반설정의  고급설정의  SSL  버전별  차단

설정을 조회합니다.

URI

설명

응답 메시지

{

    "adv_rsp_info": {

        "rsp_code": "0",

        "url": "",

        "log_enable": "0",

        "user_html": "",

        "refuse_protocol": "sslv3",

        "rspset_type": "1"

    }

}

요청 예시 ( SSL - 일반설정 고급설정의 SSL 버전별 차단 설정 변경)

Method

PUT

URI

설명

/api/v2/app/1/paf_ssl/adv_rsp_info

애플리케이션  ID 가  “1”인  애플리케이션의 SSL-일반설정의  고급설정의  SSL  버전별  차단

설정을 변경합니다.

요청 파라미터 예시

항목

값

rspset_type

유형 – (1): 일반, (2): 리다이렉트, (3): 사용자 정의

url

rsp_code

user_html

URL - “유형”이 리다이렉트인 경우 설정가능

응답 코드 - “유형”이 사용자 정의인 경우 설정가능, 범위(100 ~ 599)

“유형”이 사용자 정의인 경우 설정가능

refuse_protocol

차단 SSL 프로토콜 - “,” 구분자로 설정가능(ex> “sslv3, tlsv1”)

log_enable

보안로그 – (0): 비활성화, (1): 활성화

요청 바디 메시지

{

    "adv_rsp_info": {

        "rsp_code": "0",

        "url": "",

        "log_enable": "0",

        "user_html": "",

        "refuse_protocol": "sslv3",

        "rspset_type": "1"

    }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

3-7 SSL – 인증서 관리

SSL 인증서를 관리합니다.

Methods

GET, POST, PUT, DELETE

URI

/api/v2/app/{app_id}/paf_ssl/keycertificate

요청 예시 (SSL 인증 조회)

Method

GET

/api/v2/app/1/paf_ssl/keycertificate

애플리케이션 ID 가 “1”인 애플리케이션의 SSL 인증서를 조회합니다.

URI

설명

응답 메시지

{

    "keycertificate": {

        "cert": "",

        "key": ""

    }

}

요청 예시 ( SSL 인증서 업로드)

Method

POST

URI

설명

/api/v2/app/1/paf_ssl/keycertificate

애플리케이션 ID 가 “1”인 애플리케이션에 SSL 인증서를 업로드합니다.

요청 파라미터 예시

항목

file_name

값

업로드 요청한 후 전달받은 (인증서)파일이름

passphrase

인증 암호

요청 바디 메시지

{

    "keycertificate": {

        "file_name": "pio_xxx",

        "passphrase": ""

    }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

참고: 파일을 업로드(4 장 파일 시스템의 업로드 참조)한 후에 전달받은 파일이름을 요청 바디 메세지에 추가해야합니다.

요청 예시 ( SSL 인증서 업로드)

Method

PUT

URI

설명

/api/v2/app/1/paf_ssl/keycertificate

애플리케이션 ID 가 “1”인 애플리케이션에 SSL 인증서를 업로드합니다.

값

업로드 요청한 후 전달받은 (인증서)파일이름

인증 암호

요청 파라미터 예시

항목

file_name

passphrase

요청 바디 메시지

{

    "keycertificate": {

        "file_name": "pio_xxx",

        "passphrase": ""

    }

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

참고: 파일을 업로드(4 장 파일 시스템의 업로드 참조)한 후에 전달받은 파일이름을 요청 바디 메세지에 추가해야합니다.

요청 예시 ( SSL 인증서 삭제)

Method

DELETE

URI

설명

/api/v2/app/1/paf_ssl/keycertificate

애플리케이션 ID 가 “1”인 애플리케이션에 SSL 인증서를 삭제합니다.

요청 바디 메시지

{

    "keycertificate": {}

}

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "header": {

        "resultCode": 0,

        "resultMessage": "ok",

        "isSuccessful": true

    }

}

제 4 장
파일 시스템 설정

4-1 파일 업로드

파일을 WEBFRONT-k 에 업로드합니다.

Methods

POST

URI

/api/v2/system/upload

요청 예시 (파일 업로드)

Method

POST

URI

설명

/api/v2/system/upload

WEBFRONT-K 장비에 파일을 업로드합니다.

요청 파라미터 예시

바이너리 형태로 파일 데이터를 바디에 추가합니다.

응답 파라미터

isSuccessful

true or false

resultCode

0 or -1

resultMessage  에러 리턴 시, 실패 원인에 대한 설명

응답 메시지

{

    "file_name": "pio_2020-08-18_14-41-40_hJIbNDmF"

}

