REST API Guide

제품 버전: 2.0.11

문서  버전: 2024.07.26

일러두기

© 2024 AhnLab, Inc. All rights reserved.

AhnLab DPX REST API Guide 문서의 내용과 프로그램은 저작권법에 의해서 보호받고 있습니다. 이 문서에 표기

된 제품명은 각 사의 등록상표입니다.

문서 버전: 2024.07.26 / 제품 버전: 2.0.11

면책 조항

제조자, 수입자, 대리점은 상해를 포함하는 우발적인 손상 또는 본 제품의 부적절한 사용과 조작으로 인한 기타

손상에 대해 책임을 지지 않습니다. 이 문서의 내용은 현재 제품을 기준으로 작성되었습니다. (주)안랩은 지금도

새로운 기능을 추가 보완하고 있으며 향후에도 지속적으로 새로운 기술을 적용할 것입니다. 제품의 모든 기능은

제품 구입자 또는 제품 구입 기업에게 사전 통보없이 변경될 수 있으며 이 문서의 내용과 차이가 있을 수 있습니

다.

표기 규칙

문서에서 사용하는 기본적인 표기 규칙은 다음과 같습니다.

표기 규칙

내용

굵은 글꼴

제품에서 사용하는 버튼 이름이나 메시지를 나타냅니다. 예) 추가

<창 이름>

웹 브라우저에 표시되는 창의 이름을 나타냅니다. 예) <사용자 정보>

메뉴 1 > 메뉴 2

메뉴 실행 순서를 나타냅니다. 예) 시작 > 프로그램

참고

주의

권장 사항이나 예외 사항과 같은 추가적인 정보를 제공하기 위해 사용합니다.

시스템이나 데이터에 손상을 일으킬 수 있는 중요 정보를 제공하기 위해 사용합니다.

2

AhnLab DPX REST API Guide

약어

문서에서 사용하는 기본적인 약어는 다음과 같습니다.

약어

DPX

Guard

내용

디도스 공격을 방어하는 장비인 AhnLab DPX를 DPX로 표기합니다.

Out of Path 환경에서 디도스 공격을 방어하는 라이선스로 AhnLab DPX Guard를 Guard

로 표기합니다.

Detector

Detector로 표기합니다.

Out  of  Path  환경에서  디도스  공격을  탐지하는  라이선스로  AhnLab  DPX  Detector를

고객 지원

제품 사용 및 기술 지원과 관련한 문의처는 다음과 같습니다.

  홈페이지: https://www.ahnlab.com

  고객지원 통합센터: https://ask.ahnlab.com/hc/ko

  온라인 고객지원: 홈페이지 > 고객지원 > 온라인 고객지원 > 1:1 상담

  기업고객 기술지원: 1577-9431(평일 오전 9시~오후 8시, 토/공휴일 제외)

  주소: (우)13493 경기도 성남시 분당구 판교역로 220

  팩스: 031-722-8901

문서 이력

날짜

제품 버전

내용

2023.08.02

2.0.7

REST API 최초 작성

2023.12.15

2.0.8

[수정] 3.2.6 정책/설정 동기화

[추가] 3.2.7 Zone Protection

2024.07/26

2.0/11

[추가] 3.4 System

3

목 차

 Chapter 1 REST API 이해하기 .................................................................................. 5

1.1 REST API 동작 방식 ................................................................................................................. 6

1.2 REST API 요청 ........................................................................................................................ 9

1.3 REST API 응답 ...................................................................................................................... 11

 Chapter 2 REST API 목록 ...................................................................................... 15

2.1 REST API 목록 ...................................................................................................................... 16

 Chapter 3 REST API 기능 명세 ............................................................................... 18

3.1 인증 .................................................................................................................................... 19

3.1.1 토큰(Token) 발급 ....................................................................................................................................................... 19

3.1.2 토큰(Token) 갱신 ....................................................................................................................................................... 22

3.1.3 로그인 ............................................................................................................................................................................ 25

3.1.4 로그아웃 ....................................................................................................................................................................... 27

3.2 Zone ................................................................................................................................... 29

3.2.1 IPv4 Zone 관리 .......................................................................................................................................................... 29

3.2.2 IPv4 정책 예외 ........................................................................................................................................................... 32

3.2.3 IPv4 접근 차단 ........................................................................................................................................................... 46

3.2.4 IPv4 라우팅 우회 규칙 ............................................................................................................................................ 60

3.2.5 IPv4 시스템 격리 ....................................................................................................................................................... 73

3.2.6 정책/설정 동기화 ...................................................................................................................................................... 82

3.2.7 Zone Protection ........................................................................................................................................................ 96

3.3 Global ............................................................................................................................... 102

3.3.1 IPv4 정책 예외 ........................................................................................................................................................ 102

3.3.2 IPv4 접근 차단 ........................................................................................................................................................ 116

3.3.3 IPv4 라우팅 우회 규칙 ......................................................................................................................................... 130

3.3.4 IPv4 시스템 격리 .................................................................................................................................................... 142

3.3.5 패킷 자동 수집 다운로드 ................................................................................................................................... 150

3.4 System .............................................................................................................................. 152

3.4.1 IPv4 필터 로그 ........................................................................................................................................................ 152

 Chapter 4 법적 고지사항 ..................................................................................... 160

4.1 고지사항 ............................................................................................................................ 161

4

Chapter 1 REST API 이해하기

REST API(Representational State Transfer API)는 서로 다른 두 시스템 간에 통신망을 통해 정보를 안전하게 주고

받기 위해 사용하는 인터페이스 중 하나입니다. URL을 통해 서비스를 제공하고, 서비스 이용을 위해 필요한 주요

행동은 HTTP Method(GET, POST, PUT, DELETE)로 이뤄집니다. REST API 이해하기 챕터에서는 REST API 동작 방

식, URL 구조, HTTP 상태 코드에 대해 알아보겠습니다.







1.1 REST API 동작 방식

1.2 REST API 요청

1.3 REST API 응답

5

Chapter 1 REST API 이해하기

1.1 REST API 동작 방식

DPX의 REST API는 요청(Request)과 그에 대한 응답(Response)을 하는 요청/응답 모델을 사용합니다. 클라이언트

(사용자)는 리소스가 필요할 때 정해진 API를 사용해 서버에 요청하고, 서버는 사용자 인증을 통과한 요청에 대해

리소스를 조회하고 결과를 응답으로 반환합니다.

DPX REST API는 JWT 인증 프로토콜을 사용합니다. 클라이언트는 관리자 계정 정보로 JWT 토큰을 요청한 후 발

급받은 토큰을 서버로 전송해 로그인을 시도합니다. 토큰이 유효하면 서버가 로그인 성공에 대한 응답을 클라이

언트로 전송합니다. 클라이언트는 로그인 이후부터 API를 호출할 수 있습니다.

DPX REST API를 사용하기 위한 단계별 예는 아래와 같습니다.

Step 1. 토큰 발급

REST API를 사용하기 위해선 토큰을 발급받아야 합니다. 토큰은 발급받은 시점부터 24시간동안 사용할 수 있습

니다. 토큰 발급 요청 시 다음과 같은 정보를 서버로 전송합니다.



URL: https://<DPX IP>:50005/restapi/v1/auth/access_token

  Method: POST

HTTP Request Body

"grant_type":"password",

"username":"admin",

"password":"qwe123!@#"



{

}

6

AhnLab DPX REST API Guide

Step 2. 로그인

발급받은 토큰을 서버로 전송하여 로그인을 수행합니다.



URL: https://<DPX IP>:50005/restapi/v1/auth/login

  Method: Get



HTTP Request Header



Authorization: 발급받은 토근

Step 3. API 호출(IPv4 Zone조회)

로그인 후 API를 호출하는 방법은 다음과 같습니다. IPv4 Zone을 조회하는 예 입니다.

IPv4 Zone조회



URL: https://<DPX IP>:50005/restapi/v1/zone/zone-mgmt/ipv4

  Method: GET



HTTP Request Header



Authorization: 발급받은 토큰



HTTP Response Body

{

    "code" : 0,

    "total" : 13,

    "objects" : [

        {

            "zone_id":0,

            "zone_priority":1,

            "enable":1,

            "sync_enable":0,

            "zone_name":"zone_name",

            "target_count":1,

            "targert_name":"Default",

            "desc":"description",

            "auto_protection":0,

            "diversion_type":0,

            "diversion_auto_expire":0,

            "attack_expire_time":120,

            "auto_diversion":0,

            "dpx_ip":"Default"

        }

        ...

7

Chapter 1 REST API 이해하기

    ],

    "message" : ""

}

Step 4. 로그아웃

발급받은 토큰은 로그아웃에도 사용됩니다. 로그아웃 요청 시 다음과 같은 정보를 서버로 전송합니다.



URL: https://<DPX IP>:50005/restapi/v1/auth/logout

  Method: GET



HTTP Request Header



Authorization: 발급받은 토큰

8

AhnLab DPX REST API Guide

1.2 REST API 요청

REST API에서 Request(요청)시 공통으로 사용하는 HTTP 구조를 알아봅니다.

HTTP Method

Request(요청)시 사용하는 HTTP Mothod(GET, POST, PUT, DELETE)입니다.

GET /restapi/items HTTP/1.1 HTTP/1.1

GET /restapi/items /100 HTTP/1.1 HTTP/1.1

POST /restapi/items HTTP/1.1 HTTP/1.1

PUT /restapi/items/100 HTTP/1.1 HTTP/1.1

DELETE /restapi/items/100 HTTP/1.1 HTTP/1.1

리소스

GET

POST

PUT

DELETE

/items

전체 리소스 조회

리소스 생성

일부 리소스 수정

일부 리소스 삭제

/items/{id}

ID에 해당하는

리소스 조회

(지원 안 함)

ID에 해당하는

ID에 해당하는

리소스 수정

리소스 삭제

HTTP GET Paging

GET 으로 목록 리소스를 요청할 경우, 다음을 이용하여 지정한 크기로 데이터를 나누어 요청할 수 있습니다.

GET /restapi/items?offset=10&limit=10 HTTP 1.1

항목

내용

offset

조회할 리소스의 시작 위치를 지정합니다. 지정하지 않을 경우, API별 기본값을 적용합니다.

조회할 리소스의 개수를 지정합니다. limit으로 설정할 수 있는 개수는 API에 정의된 최대값

으로 제한하며, 지정하지 않을 경우 API별 기본값을 적용합니다.

limit

9

Chapter 1 REST API 이해하기

 참고

리소스의 최대 개수가 limit의 최대값을 초과하는 경우, 데이터 셋을 나누어 조회할 수 있습니다.

예) 최대 개수가 400개의 목록을 출력할 경우

    - ?offset=0&limit=200

    - ?offset=199&limit=200

HTTP URL

https://  [IP address]  :  [Port]  / restapi / v1 / [Path]

항목

설명

https

REST API는 https 프로토콜만 지원합니다.

IP address

REST API를 이용해 리소스를 요청할 DPX의 IPv4 주소를 입력합니다.

DPX 접속 시 사용하는 포트 번호입니다(기본값: 50005, 입력 범위: 50005 또는

Port

30000~39999).

restapi

DPX에서 사용하는 REST API입니다.

v1

DPX에서 사용하는 REST API 버전입니다.

빗금(/)을 구분자로 요청할 리소스 위치를 지정합니다. 예를 들어 IPv4 Zone에 대한 리소스

Path

위치는 웹 화면 위치와 동일하게 ‘/zone/zone-mgmt/ipv4'입니다. 정확한 리소스 위치는 기

능 명세에서 확인할 수 있습니다.

10

AhnLab DPX REST API Guide

1.3 REST API 응답

REST API에서 Response(응답)시 공통으로 사용하는 HTTP 상태, 오류 코드를 알아봅니다. HTTP 상태/오류 코드

표에 포함되지 않은 응답 코드를 받은 경우에는 먼저 REST API 요청을 전송한 서버가 맞는지 확인해 주십시오. 올

바른 서버에서 상태 코드에도 없는 이상 코드가 반환되거나 그 외 이상 현상이 발견된다면 담당 엔지니어에게 문

의해 주십시오.

HTTP 상태 코드

Response(응답)에 포함된 상태 코드 및 설명입니다. 서버는 클라이언트에게 요청받은 응답에 대해 응답 코드와

설명 값을 반환합니다. 클라이언트(사용자)는 상태 코드 정보를 통해 요청에 대한 올바른 처리가 되었는지를 확인

할 수 있습니다.

응답 코드

설명

200(OK)

우입니다.

정상 호출입니다. 수행한 API 가 정상적으로 정책을 적용하거나 가져오기 한 경

400(Bad Request)

생합니다.

기능 호출에 필요한 값이 포함되지 않았거나, 정상적으로 전달되지 못한 경우 발

401(Unauthorized)

결과를 요청하는 경우 등에 발생합니다.

인증 실패입니다. 계정 아이디 및 비밀번호가 틀린경우, 로그인하지 않은 상태로

403(Forbidden)

기능 호출에 필요한 권한이 없는 경우 발생합니다.

429(Too Many Request)  주어진 시간 동안 기능 호출을 너무 많이 했을 경우 발생합니다.

500(Internal Server Error)

됩니다. 서버 상태를 확인하고 변수에 대해 확인합니다.

서버 오류입니다. 서버가 응답 하지 않거나 필수 요청 변수가 잘못된 경우 발생

502(Bad Gateway)

생됩니다. 클라이언트가 잘못된 요청을 한것인지 확인합니다.

서버 오류입니다. 서버가 클라이언트로부터 올바른 요청을 받지 못했을 경우 발

503(Service Unavailable)  서버 오류입니다. 서비스를 사용할 수 없는 상태입니다.

11

Chapter 1 REST API 이해하기

HTTP 오류 코드

Response(응답)에 포함된 오류 코드 및 설명입니다. 서버는 클라이언트에게 요청받은 응답에 대해 응답 코드와

설명 값을 반환합니다. 클라이언트(사용자)는 오류 코드 정보를 통해 요청 사항을 다시 한번 확인할 수 있습니다.

응답 코드

설명

101

입력한 값에 대한 유효성 검사 오류입니다. IP 주소에 300.300.300.300과 같이

(REST_ERROR_INVAL)

IP 주소 범위를 벗어나거나 허용하지 않는 특수 문자를 입력한 경우와 같이 값

유효성 검사에서 실패한 경우 발생합니다.

102

대상이 존재하지 않는 경우 발생하는 오류입니다. 수정을 요청한 대상 객체가

(REST_ERROR_NOENT)

없는 경우 발생합니다.

103

대상이 이미 존재하는 경우 발생하는 오류입니다. 일반적으로 이름은 정책/객체

(REST_ERROR_EXIST)

를 식별하는 유일한 속성입니다. 동일한 이름으로 추가할 수 없으므로 이름을

변경하여 다시 시도해 주십시오.

104

최대 개수 초과 오류입니다. 각 기능별 추가할 수 있는 최대 개수를 확인해 주십

(REST_ERROR_NOSPC)

시오.

105

허용되지 않는 작업이 요청된 경우 발생되는 오류입니다. TMS에서 사용중인 객

(REST_ERROR_PERM)

체 정보를 변경하려는 경우와 같이 동작 수행을 할 수 없는 경우 발생합니다.

106

허용되지 않는 대상이 접근하는 경우 발생하는 오류입니다. 해당 작업을 위한

(REST_ERROR_ACCES)

권한이 없는 경우나 작동 모드가 요청한 작업과 매칭되지 않는 경우 등에 발생

합니다.

107

메모리 부족 오류입니다. 메모리가 부족하여 작업을 위한 메모리 할당이 할 수

(REST_ERROR_NOMEM)

없어 작업을 수행할 수 없는 경우에 발생합니다. 장비의 상태를 확인해 주십시

오.

108

입출력 오류가 발생했습니다. 내부 모듈 간 통신 중 에러가 발생했거나 읽기/쓰

(REST_ERROR_IO)

기할 설정 파일이 존재하지 않는 경우 등에 발생합니다.

109

(REST_ERROR_UNKNOWN)

110

(REST_ERROR_INTERNAL)

존재하지 않는 명령입니다. 명령어를 다시 확인해 주십시오.

알 수 없는 오류입니다. 정의되지 않는 이유로 오류가 발생한 경우입니다.

12

AhnLab DPX REST API Guide

111

인증 오류입니다. 관리자를 인증하지 못해 오류가 발생한 경우입니다. 아이디

(REST_ERROR_FAIL_AUTH)

정보가 같이 제공됩니다.

112

(REST_ERROR_FAIL

_ACCESS_TOKEN)

113

(REST_ERROR_NOT

인증 오류입니다. 관리자의 토큰을 인증하지 못해 오류가 발생한 경우입니다.

아이디 정보가 같이 제공됩니다.

세션 오류입니다. 관리자 로그인 시 세션 정보를 찾을 수 없어 오류가 발생한

_FOUND_LOGIN_SESSION)

경우입니다. 다시 로그인이 필요합니다.

114

(REST_ERROR_NOT

지원하지 않는 URI를 요청한 경우 발생하는 오류입니다.

_SUPPORT_URI)

115

(REST_ERROR_NOT

지원하지 않는 메소드를 요청한 경우 발생하는 오류입니다.

_ALLOW_METHOD)

116

(REST_ERROR_BAD

잘못된 요청을 한 경우 발생하는 오류입니다.

_REQUEST)

117

(REST_ERROR_

적용할 변경 사항이 없는 경우 발생하는 오류입니다.

NOTHING_TO_APPLY)

HTTP 응답 성공/실패

요청에 대한 처리를 성공 또는 실패했을 때, 제공되는 응답 구조는 다음과 같습니다.

항목

code

내용

요청 결과에 따라 상태 코드, 오류 코드에 정의된 응답 코드가 표시됩니다.

message

요청 결과에 따라 응답 코드와 매핑된 메시지가 표시됩니다.

13

Chapter 1 REST API 이해하기

  성공 HTTP Response Body

{

    "code": 0,

    "message": ""

}

  실패 HTTP Response Body

{

    "code": 101,

    "message": "로그인하지 못했습니다."

}

14

Chapter 2 REST API 목록

DPX에서 제공하는 REST API를 간략하게 확인할 수 있는 표를 제공합니다.



2.1 REST API 목록

15

Chapter 2 REST API 목록

2.1 REST API 목록

DPX에서 제공하는 로그 정보를 표로 간략하게 알아봅니다. 로그 종류, 플래그, 로그 포맷뿐만 아니라 로그를 확인

할 수 있는 DPX 메뉴, 로그가 생성되는 주기, 로그 서버(예: TMS)로 전송 시 부합되는 설정 이름 정보를 확인할 수

있습니다.

카테고리  기능

API

URL

사용 라이선스

관리자 인증

토큰 발급

토큰 갱신

인증

로그인

로그인

로그아웃

로그아웃

IPv4 Zone 관리

https://<DPX_IP>:50005/restapi/v1/

auth/access_token

https://<DPX_IP>:50005/restapi/v1/

auth/refresh_token

https://<DPX_IP>:50005/restapi/v1/

All

auth/login

https://<DPX_IP>:50005/restapi/v1/

auth/logout

https://<DPX_IP>:50005/restapi/v1/

zone/zone-mgmt/ipv4

https://<DPX_IP>:50005/restapi/v1/

IPv4 정책 예외

zone/zone-mgmt/ipv4/{zone-

id}/policy/whitelist

Inline/Guard/Detector

Zone 관리

https://<DPX_IP>:50005/restapi/v1/

IPv4 접근 차단

zone/zone-mgmt/ipv4/{zone-

Zone

IPv4  라우팅  우회

규칙

id}/policy/blacklist

https://<DPX_IP>:50005/restapi/v1/

zone/zone-mgmt/ipv4/{zone-

id}/policy/diversion

https://<DPX_IP>:50005/restapi/v1/

Add: Guard/Detector

Del/List/Search: Guard

시스템 격리

IPv4 시스템 격리

zone/zone-mgmt/ipv4/{zone-

Inline/Guard

Zone 동기화

Zone 동기화

정책 예외

IPv4 정책 예외

Global

접근 차단

IPv4 접근 차단

id}/policy/quarantine

https://<DPX_IP>:50005/restapi/v1/

zone/zone-sync/list/{zone-id}

https://<DPX_IP>:50005/restapi/v1/

zone/zone-sync/conf

https://<DPX_IP>:50005/restapi/v1/

global/whitelist/ipv4

https://<DPX_IP>:50005/restapi/v1/

global/blacklist/ipv4

Inline/Guard/Detector

Inline/Guard/Detector

16

AhnLab DPX REST API Guide

카테고리  기능

API

URL

사용 라이선스

패킷 캡처

Out-of-Path

패킷 자동 수집 다

https://<DPX_IP>:50005/restapi/v1/

운로드

global/packet-capture/download

IPv4  라우팅  우회

https://<DPX_IP>:50005/restapi/v1/

Add: Guard/Detector

규칙

global/oop/diversion/ipv4

Del/List/Search: Guard

시스템 격리

IPv4 시스템 격리

https://<DPX_IP>:50005/restapi/v1/

global/quarantine/ipv4

Inline/Guard

System  필터 로그

적용

적용

IPv4 필터 로그 조

https://<DPX_IP>:50005/restapi/v1/

회

system/log-mgmt/filterlog/ipv4

Inline/Guard/Detector

IPv4 필터 로그 저

https://<DPX_IP>:50005/restapi/v1/

장

적용

system/log-mgmt/filterlog/ipv4

https://<DPX_IP>:50005/restapi/v1/

apply

Inline/Guard/Detector

All

17

Chapter 3 REST API 기능 명세

DPX에서 제공하는 로그의 상세 정보를 알아봅니다.







3.1 인증

3.2 Zone

3.3 Global

18

AhnLab DPX REST API Guide

3.1 인증

DPX에 접속하려는 관리자를 인증하고 로그인/로그아웃 할 수 있는 API를 제공합니다.

3.1.1 토큰(Token) 발급

관리자를 인증하기 위해 토큰(Token)을 발급하는 API입니다.

요청(Request)

관리자를 인증하기 위한 토큰(Token) 발급 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/auth/access_token

Method

POST

Header

이름

유형

내용

Authorization

string

토큰을 발급받기 위한 인증 정보입니다.

  인증 종류로 Basic 을 사용하며 Basic 과 Base64 로

인코드(encode)된 제품 번호와 장비 ID 정보가 표시됩니다.



Basic 과 {Base64_Encode(제품 번호:장비 ID)} 사이에 공백이

입력되어야 합니다. 예) “Basic {Basic64_Encode(제품 번호:장비

ID)}”

Content-Type

string

application/json 정보입니다.

 참고

DPX에 적용된 인증 프로세스에 따라 제품 번호는 다음 정보로 제공되어야 합니다.

- 제품 인증(1.0): 제품 번호

- 제품 인증(2.0): 인증 번호

19

Chapter 3 REST API 기능 명세

Path Parameters

없음

Query Parameters

없음

Request Body

이름

유형

내용

grant_type

string

필수 포함 항목으로 인증 방식에 대한 정보입니다. password (비밀번호

입력 방식)만 입력할 수 있습니다.

username

string

필수 포함 항목으로 관리자 계정 ID 정보입니다.

password

string

필수 포함 항목으로 관리자 계정 Password 정보입니다.

{

}

"grant_type":"password",

"username":"admin",

“password":"*********"

응답(Response)

관리자 인증을 위한 토큰(Token) 발급 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

성공 시

이름

유형

내용

access_token

string

요청 성공시 제공하는 정보로 Access Token(64bytes) 정보가

제공됩니다.

expires_in

integer

요청 성공시 제공하는 정보로 Access Token 만료 시간(86400sec) 정보가

제공됩니다.

refresh_token

string

요청 성공시 제공하는 정보로 토큰 갱신시 필요한 Refresh Token(64bytes)

정보가 제공됩니다.

Token_type

string

요청 성공시 제공하는 정보로 토큰 인증 방식(Bearer) 정보가 제공됩니다.

토큰 인증 방식은 Bearer만 제공합니다.

20

AhnLab DPX REST API Guide

{

}

"access_token": "3w4yQM/T6lu5dLH726TOQjQULZgMydI4XHsHkTmzR28bLjWCzbSnfHqsnIF0OG/Y",

"expires_in": 86400,

"refresh_token": "w87eP3iAClVjl+F63/jGfveBBRFxS8Onr65ENdd+wLjLXw02wcQ5Bsf4aeaTqxeG",

"token_type": "Bearer

실패 시

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

“code”: 0,

“message”: “”

}

21

Chapter 3 REST API 기능 명세

3.1.2 토큰(Token) 갱신

만료된 토큰(Token)을 갱신하는 API입니다.

요청(Request)

만료된 토큰(Token)에 대한 갱신 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/auth/refresh_token

Method

POST

Header

이름

유형

내용

Authorization

string

인코드(encode)된 제품 번호와 장비 ID 정보가 표시됩니다.

토큰을 갱신하기 위한 인증 정보입니다.

  인증 종류로 Basic 을 사용하며 Basic 과 Base64 로



Basic 과 {Base64_Encode(제품 번호: 장비 ID)} 사이에 공백이

입력되야 합니다. 예) “Basic {Basic64_Encode(제품 번호:장비 ID)}”

Content-Type

string

application/json 정보입니다.

Path Parameters

없음

Query Parameters

없음

Request Body

이름

유형

내용

grant_type

string

필수 포함 항목으로 인증 방식에 대한 정보입니다. refresh_token 만

입력할 수 있습니다.

22

AhnLab DPX REST API Guide

refresh_token

string

갱신할 Access Token과 함께 발급된 refresh token 정보입니다.

{

}

"grant_type":"refresh_token",

"refresh_token":"w87eP3iAClVjl+F63/jGfveBBRFxS8Onr65ENdd+wLjLXw02wcQ5Bsf4aeaTqxeG"

응답(Response)

관리자 인증을 위한 토큰(Token) 발급 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

성공 시

이름

유형

내용

access_token

string

요청 성공시 제공하는 정보로 갱신된 Access Token(64bytes) 정보가

제공됩니다.

expires_in

integer

요청 성공시 제공하는 정보로 갱신된 Access Token의 만료 시간

(86400sec) 정보가 제공됩니다.

refresh_token

string

요청 성공시 제공하는 정보로 토큰 갱신시 필요한 Refresh Token(64bytes)

정보가 제공됩니다.

Token_type

string

요청 성공시 제공하는 정보로 토큰 인증 방식(Bearer) 정보가 제공됩니다.

토큰 인증 방식은 Bearer만 제공합니다.

"access_token": "3w4yQM/T6lu5dLH726TOQjQULZgMydI4XHsHkTmzR28bLjWCzbSnfHqsnIF0OG/Y",

"expires_in": 86400,

"refresh_token": "w87eP3iAClVjl+F63/jGfveBBRFxS8Onr65ENdd+wLjLXw02wcQ5Bsf4aeaTqxeG",

"token_type": "Bearer"

{

}

23

Chapter 3 REST API 기능 명세

실패 시

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

24

AhnLab DPX REST API Guide

3.1.3 로그인

발급받은 토큰(Tocken)으로 인증받은 관리자가 DPX에 로그인하기 위한 API입니다.

요청(Request)

관리자가 DPX에 로그인하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/auth/login

Method

GET

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

없음

Query Parameters

없음

Request Body

없음

25

Chapter 3 REST API 기능 명세

응답(Response)

관리자의 로그인 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

26

AhnLab DPX REST API Guide

3.1.4 로그아웃

발급받은 토큰(Tocken)으로 인증받은 관리자가 DPX에 로그아웃하기 위한 API입니다.

요청(Request)

관리자가 DPX에 로그아웃하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/auth/logout

Method

GET

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

없음

Query Parameters

없음

Request Body

없음

27

Chapter 3 REST API 기능 명세

응답(Response)

관리자의 로그아웃 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

28

AhnLab DPX REST API Guide

3.2 Zone

DPX의 Zone을 관리할 수 있는 API를 제공합니다.

3.2.1 IPv4 Zone 관리

DPX에 구성된 IPv4 Zone을 조회하기 위한 API입니다.

요청(Request)

IPv4 Zone을 조회하기 위한 요청(Request)는 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4

Method

GET

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Path Parameters

없음

Query Parameters

이름

유형

내용

offset

integer

조회할 IPv4 Zone 목록의 시작 위치를 지정합니다. 지정하지 않을 경우,

기본값(0)을 적용합니다.

limit

integer

개수는 API에 정의된 최대값(200)으로 제한하며, 지정하지 않을 경우 기

조회할 IPv4 Zone 목록의 개수를 지정합니다. limit으로 설정할 수 있는

본값(50)을 적용합니다.

29

Chapter 3 REST API 기능 명세

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4?offset=1&limit=20

Request Body

없음

응답(Response)

IPv4 Zone 조회 요청에 대한 응답(Response)은 다음과 같습니다

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 IPv4 Zone의 총 개수를 제공합니다.

조회된 IPv4 Zone의 다음 정보를 제공합니다.







zone_id (integer): Zone 을 식별할 ID 정보를 제공합니다.

zone_priority (integer): Zone 의 우선순위 정보를 제공합니다.

enable  (integer):  Zone 의  사용  여부(0:  사용  안  함,  1:  사용)를

제공합니다.



sync_enable (integer): Zone 의  데이터  동기화  사용  여부(0:  사용

안 함, 1: 사용)를 제공합니다.

zone_name (string): Zone 이름을 제공합니다.

target_cnt  (int):  Zone 에  구성된  보호  대상  개수(1~128 개)를





object

-

제공합니다.



target_name  (string):  Zone 에  구성된  보호  대상  이름을

제공합니다. 구분자(;)를 이용하여 최대 8320 bytes 까지 제공할 수





있습니다. 예)target1;target2

desc (string): Zone 에 대한 설명을 제공합니다.

auto_protection  (int):  DDoS  공격  방어를  위한  protection

활성화(0: 공격 탐지 시, 1: 라우팅 우회 시) 정보를 제공합니다.



diversion_type (int): DDoS 공격 시, 라우팅 우회 대상(0: Zone 전체,

1: 보호 대상 IP 주소) 정보를 제공합니다.



diversion_auto_expire (int): DDoS 공격 종료 시, 라우팅 우회 자동

해제에 대한 사용 여부(0: 사용 안 함, 1: 사용)를 제공합니다.

30

AhnLab DPX REST API Guide



attack_expire_time (int): DDoS 공격에 대한 방어 종료 시간(기본값:

120 초, 60~86400 초)을 제공합니다.



auto_diversion (int):  자동  라우팅  우회  사용  여부(0:  개별  규칙에

따름, 1: 모두 사용, 2: 모두 사용 안 함)를 제공합니다.



dpx_ip  (string):  Zone 에  구성된  보호  장비  이름을  제공합니다.

구분자(;)를  이용하여  최대  1200  bytes 까지  제공할  수  있습니다.

예)dpxip1;dpxip2

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

"code" : 0,

    "total" : 13,

    "objects" : [

        {

            "zone_id":0,

            "zone_priority":1,

            "enable":1,

            "sync_enable":0,

            "zone_name":"zone_name",

            "target_count":1,

            "targert_name":"Default",

            "desc":"description",

            "auto_protection":0,

            "diversion_type":0,

            "diversion_auto_expire":0,

            "attack_expire_time":120,

            "auto_diversion":0,

            "dpx_ip":"Default"

        }

        ...

    ],

    "message" : ""

}

31

Chapter 3 REST API 기능 명세

3.2.2 IPv4 정책 예외

DPX의 정책 예외를 조회하고 추가/수정/삭제하기 위한 API입니다.

3.2.2.1 IPv4 정책 예외 목록 조회

요청(Request)

IPv4 정책 예외 목록을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone ID}/policy/whitelist

Method

GET

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

이름

유형

내용

zone-id

string

필수 포함 항목으로 조회할 Zone 의 ID 정보입니다.

Query Parameters

이름

유형

내용

offset

integer

조회할 IPv4 정책 예외 목록의 시작 위치를 지정합니다. 지정하지 않을

경우, 기본값(0)을 적용합니다.

limit

integer

있는 개수는 API에 정의된 최대값(200)으로 제한하며, 지정하지 않을 경

조회할 IPv4 정책 예외 목록의 개수를 지정합니다. limit으로 설정할 수

우 기본값(50)을 적용합니다.

32

AhnLab DPX REST API Guide

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/0/whitelist?offset=1&limit=20

Request Body

없음

응답(Response)

IPv4 정책 예외 목록의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

code

integer

  성공: 0

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 IPv4 정책 예외 목록의 총 개수를 제공합니다.

조회된 IPv4 정책 예외 목록의 다음 정보를 제공합니다.





prioriy: IPv4 정책 예외의 우선순위 정보를 제공합니다.

enable: IPv4 정책 예외에 대한 사용 여부(0: 사용 안 함, 1: 사용)를

제공합니다.



protocol:  IPv4  정책  예외로  예외  처리할  프로토콜(all,  udp,  tcp,

icmp) 정보를 제공합니다.









sip: IPv4 정책 예외로 예외 처리할 출발지 IPv4 주소룰 제공합니다.

sip_mask:  IPv4  정책  예외로  예외  처리할  출발지  IPv4  주소의

넷마스크 정보를 제공합니다.

dip: IPv4 정책 예외로 예외 처리할 목적지 IPv4 주소를 제공합니다.

dip_mask:  IPv4  정책  예외로  예외  처리할  목적지  IPv4  주소의

넷마스크 정보를 제공합니다.



sport:  IPv4  정책  예외로  예외  처리할  출발지  포트  번호를

제공합니다.



dport:  IPv4  정책  예외로  예외  처리할  목적지  포트  번호를

제공합니다.



filter: IPv4 정책 예외로 예외할 정책 필터 정보를 제공합니다.











1: 접근 차단 (0x0001)

2: 시스템 격리 (0x0002)

4: anti-spoofing (0x0004)

8: HTTP 인증 (0x0008)

16 : SEG protection (0x0010)

object

-

33

Chapter 3 REST API 기능 명세





















32: 비 인증 IP  (0x0020)

64: 행위 규칙 (0x0040)

128: 시그니처 (0x0080)

256: 사용량 제한 (0x0100)

512: Global 접근 차단 (0x0200)

1024: Stateful 검사 (0x0400)

2048: Global 시스템 격리 (0x0800)

4096: Global 국가 기반 차단 (0x1000)

8192: 국가 기반 차단 (0x2000)

16384: Global 프로토콜 이상 (0x4000)





name: IPv4 정책 예외의 이름을 제공합니다.

desc: IPv4 정책 예외에 대한 설명을 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

    "code" : 0,

    "total" : 13,

    "objects" : [

        {

            "enable":1,

            "protocol":"tcp",

            "sip":"1.1.1.1",

            "sip_mask":"32",

            "dip":"2.1.1.1",

            "dip_mask":"32",

            "sport":"0",

            "dport":"0",

            "filter":8,

            "name":"whiltelist_0",

            "desc":"description"

        }

        ...

    ],

    "message" : ""

}

34

AhnLab DPX REST API Guide

3.2.2.2 IPv4 정책 예외 조회

요청(Request)

IPv4 정책 예외를 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

ID}/policy/whitelist/{priority}

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone

Method

GET

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

이름

유형

내용

zone-id

priority

string

필수 포함 항목으로 조회할 Zone 의 ID 정보입니다.

String

필수 포함 항목으로 조회할 Zone 의 우선순위 정보입니다.

Query Parameters

없음

Request Body

없음

35

Chapter 3 REST API 기능 명세

응답(Response)

IPv4 정책 예외의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 IPv4 정책 예외의 총 개수를 제공합니다.

조회된 IPv4 정책 예외의 다음 정보를 제공합니다.





prioriy: IPv4 정책 예외의 우선순위 정보를 제공합니다.

enable: IPv4 정책 예외에 대한 사용 여부(0: 사용 안 함, 1: 사용)를

제공합니다.



protocol:  IPv4  정책  예외로  예외  처리할  프로토콜(all,  udp,  tcp,

icmp) 정보를 제공합니다.









sip: IPv4 정책 예외로 예외 처리할 출발지 IPv4 주소룰 제공합니다.

sip_mask:  IPv4  정책  예외로  예외  처리할  출발지  IPv4  주소의

넷마스크 정보를 제공합니다.

dip: IPv4 정책 예외로 예외 처리할 목적지 IPv4 주소를 제공합니다.

dip_mask:  IPv4  정책  예외로  예외  처리할  목적지  IPv4  주소의

넷마스크 정보를 제공합니다.

object

-



sport:  IPv4  정책  예외로  예외  처리할  출발지  포트  번호를

제공합니다.



dport:  IPv4  정책  예외로  예외  처리할  목적지  포트  번호를

제공합니다.



filter: IPv4 정책 예외로 예외할 정책 필터 정보를 제공합니다.





















1: 접근 차단 (0x0001)

2: 시스템 격리 (0x0002)

4: anti-spoofing (0x0004)

8: HTTP 인증 (0x0008)

16 : SEG protection (0x0010)

32: 비 인증 IP  (0x0020)

64: 행위 규칙 (0x0040)

128: 시그니처 (0x0080)

256: 사용량 제한 (0x0100)

512: Global 접근 차단 (0x0200)

36

AhnLab DPX REST API Guide











1024: Stateful 검사 (0x0400)

2048: Global 시스템 격리 (0x0800)

4096: Global 국가 기반 차단 (0x1000)

8192: 국가 기반 차단 (0x2000)

16384: Global 프로토콜 이상 (0x4000)





name: IPv4 정책 예외의 이름을 제공합니다.

desc: IPv4 정책 예외에 대한 설명을 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

"code" : 0,

    "total" : 1,

    "objects" : [

        {

            "priority":0,

            "enable":1,

            "protocol":"tcp",

            "sip":"1.1.1.1",

            "sip_mask":"32",

            "dip":"2.1.1.1",

            "dip_mask":"32",

            "sport":"0",

            "dport":"0",

            "filter":8,

            "name":"whiltelist_0",

            "desc":"description"

            }

    ],

    "message" : ""

}

37

Chapter 3 REST API 기능 명세

3.2.2.3 IPv4 정책 예외 추가

요청(Request)

IPv4 정책 예외를 추가하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone ID}/policy/whitelist

Method

POST

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Content-Type

string

application/json 정보입니다.

Path Parameters

이름

유형

내용

zone-id

string

필수 포함 항목으로 추가할 Zone 의 ID 정보 입니다.

Query Parameters

없음

Request Body

이름

유형

내용

priority

integer

필수 포함 항목으로 추가할 IPv4 정책 예외의 우선순위 정보입니다.

enable

integer

필수 포함 항목으로 추가할 IPv4 정책 예외에 대한 사용 여부(0: 사용 안

함, 1: 사용)입니다.

protocol

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 프로토콜(all, udp, tcp, icmp)

정보입니다. 공백을 입력할 경우, all로 동작합니다.

38

AhnLab DPX REST API Guide

sip

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 출발지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

sip_mask

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 출발지 넷마스크 정보입니

다. 공백을 입력할 경우, sip가 all로 동작합니다.

dip

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 목적지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

dip_mask

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 목적지 넷마스크 정보입니

다. 공백을 입력할 경우, dip가 all로 동작합니다.

sport

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 출발지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

dport

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 목적지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

필수 포함 항목으로 추가할 IPv4 정책 예외에서 예외할 필터 정보입니다.

filter

Integer





























1: 접근 차단 (0x0001)

2: 시스템 격리 (0x0002)

4: anti-spoofing (0x0004)

8: HTTP 인증 (0x0008)

16: SEG protection (0x0010)

32: 비 인증 IP  (0x0020)

64: 행위 규칙 (0x0040)

128: 시그니처 (0x0080)

256: 사용량 제한 (0x0100)

512: Global 접근 차단 (0x0200)

1024: Stateful 검사 (0x0400)

2048: Global 시스템 격리 (0x0800)

4096: Global 국가 기반 차단 (0x1000)

8192: 국가 기반 차단 (0x2000)



16384: Global 프로토콜 이상 (0x4000)

name

string

필수 포함 항목으로 추가할 IPv4 정책 예외 이름입니다. 사용할 수 있는

문자는 영문자, 숫자, 특수문자( / - _ ( ) . )입니다.

desc

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 설명입니다.

39

Chapter 3 REST API 기능 명세

{

}

“prioriy”:0,

"enable":1,

"protocol":"tcp",

"sip":"1.1.1.1",

"sip_mask":"32",

"dip":"2.1.1.1",

"dip_mask":"32",

"sport":"0",

"dport":"0",

"filter":8,

"name":"whiltelist_0",

"desc":"description"

응답(Response)

IPv4 정책 예외의 추가 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

40

AhnLab DPX REST API Guide

3.2.2.4 IPv4 정책 예외 수정

요청(Request)

IPv4 정책 예외를 수정하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

ID}/policy/whitelist/{priority}

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone

Method

PUT

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Content-Type

string

application/json 정보입니다.

Path Parameters

이름

유형

내용

zone-id

priority

string

필수 포함 항목으로 수정할 Zone 의 ID 정보 입니다.

String

필수 포함 항목으로 수정할 Zone 의 우선순위 정보입니다.

Query Parameters

없음

41

Chapter 3 REST API 기능 명세

Request Body

이름

유형

내용

enable

integer

필수 포함 항목으로 수정할 IPv4 정책 예외에 대한 사용 여부(0: 사용 안

함, 1: 사용)입니다.

protocol

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 프로토콜(all, udp, tcp, icmp)

정보입니다. 공백을 입력할 경우, all로 동작합니다.

sip

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 출발지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

sip_mask

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 출발지 넷마스크 정보입니

다. 공백을 입력할 경우, sip가 all로 동작합니다.

dip

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 목적지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

dip_mask

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 목적지 넷마스크 정보입니

다. 공백을 입력할 경우, dip가 all로 동작합니다.

sport

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 출발지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

dport

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 목적지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

필수 포함 항목으로 수정할 IPv4 정책 예외에서 예외할 필터 정보입니다.

filter

Integer





























1: 접근 차단 (0x0001)

2: 시스템 격리 (0x0002)

4: anti-spoofing (0x0004)

8: HTTP 인증 (0x0008)

16: SEG protection (0x0010)

32: 비 인증 IP  (0x0020)

64: 행위 규칙 (0x0040)

128: 시그니처 (0x0080)

256: 사용량 제한 (0x0100)

512: Global 접근 차단 (0x0200)

1024: Stateful 검사 (0x0400)

2048: Global 시스템 격리 (0x0800)

4096: Global 국가 기반 차단 (0x1000)

8192: 국가 기반 차단 (0x2000)

42

AhnLab DPX REST API Guide



16384: Global 프로토콜 이상 (0x4000)

name

string

필수 포함 항목으로 수정할 IPv4 정책 예외 이름입니다. 사용할 수 있는

문자는 영문자, 숫자, 특수문자( / - _ ( ) . )입니다.

desc

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 설명입니다.

{

}

"enable":1,

"protocol":"tcp",

"sip":"1.1.1.1",

"sip_mask":"32",

"dip":"2.1.1.1",

"dip_mask":"32",

"sport":"0",

"dport":"0",

"filter":8,

"name":"whiltelist_0",

"desc":"description"

응답(Response)

IPv4 정책 예외의 수정 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

“code”: 0,

“message”: “”

{

}

43

Chapter 3 REST API 기능 명세

3.2.2.5 IPv4 정책 예외 삭제

요청(Request)

IPv4 정책 예외를 삭제하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

ID}/policy/whitelist/{priority}

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone

Method

DELETE

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

이름

유형

내용

zone-id

priority

string

필수 포함 항목으로 삭제할 Zone 의 ID 정보 입니다.

String

필수 포함 항목으로 삭제할 Zone 의 우선순위 정보입니다.

Query Parameters

없음

Request Body

없음

44

AhnLab DPX REST API Guide

응답(Response)

IPv4 정책 예외의 수정 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

45

Chapter 3 REST API 기능 명세

3.2.3 IPv4 접근 차단

DPX의 접근 차단을 조회하고 추가/수정/삭제하기 위한 API입니다.

3.2.3.1 IPv4 접근 차단 목록 조회

요청(Request)

IPv4 접근 차단 목록을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone-id}/policy/blacklist

Method

GET

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Path Parameters

이름

유형

내용

zone-id

string

필수 항목으로 조회할 Zone 의 ID 정보입니다.

Query Parameters

이름

유형

내용

offset

integer

경우, 기본값(0)을 적용합니다.

조회할 IPv4 접근 차단 목록의 시작 위치를 지정합니다. 지정하지 않을

46

AhnLab DPX REST API Guide

limit

integer

있는 개수는 API에 정의된 최대값(200)으로 제한하며, 지정하지 않을 경

조회할 IPv4 접근 차단 목록의 개수를 지정합니다. limit으로 설정할 수

우 기본값(50)을 적용합니다.

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/0/policy/blacklist?offset=1&limit=20

Request Body

없음

응답(Response)

IPv4 접근 차단 목록의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 IPv4 접근 차단 목록의 총 개수를 제공합니다.

조회된 IPv4 접근 차단 목록의 다음 정보를 제공합니다.





prioriy: IPv4 접근 차단의 우선순위 정보를 제공합니다.

enable: IPv4 접근 차단에 대한 사용 여부(0: 사용 안 함, 1: 사용)를

제공합니다.



protocol: IPv4 접근 차단으로 예외 처리할 프로토콜(all, udp, tcp,

icmp) 정보를 제공합니다.



sip:  IPv4  접근  차단으로  예외  처리할  출발지  IPv4  주소룰

object

-

제공합니다.



sip_mask:  IPv4  접근  차단으로  예외  처리할  출발지  IPv4  주소의

넷마스크 정보를 제공합니다.



dip:  IPv4  접근  차단으로  예외  처리할  목적지  IPv4  주소를

제공합니다.



dip_mask:  IPv4  접근  차단으로  예외  처리할  목적지  IPv4  주소의

넷마스크 정보를 제공합니다.



sport:  IPv4  접근  차단으로  예외  처리할  출발지  포트  번호를

제공합니다.

47

Chapter 3 REST API 기능 명세



dport:  IPv4  접근  차단으로  예외  처리할  목적지  포트  번호를

제공합니다.





name: IPv4 접근 차단의 이름을 제공합니다.

desc: IPv4 접근 차단에 대한 설명을 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

"code" : 0,

    "total" : 13,

    "objects" : [

        {

            "priority":0,

            "enable":1,

            "protocol":"tcp",

            "sip":"1.1.1.1",

            "sip_mask":"32",

            "dip":"2.1.1.1",

            "dip_mask":"32",

            "sport":"0",

            "dport":"0",

            "name":"blacklist_0",

            "desc":"description"

        }

        ...

    ],

    "message" : ""

}

48

AhnLab DPX REST API Guide

3.2.3.2 IPv4 접근 차단 조회

요청(Request)

IPv4 접근 차단을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

id}/policy/blacklist/{priority}

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone-

Method

GET

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

이름

유형

내용

zone-id

priority

string

필수 포함 항목으로 조회할 Zone 의 ID 정보입니다.

String

필수 포함 항목으로 조회할 Zone 의 우선순위 정보입니다.

Query Parameters

없음

Request Body

없음

49

Chapter 3 REST API 기능 명세

응답(Response)

IPv4 접근 차단의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 IPv4 접근 차단의 총 개수를 제공합니다.

조회된 IPv4 접근 차단의 다음 정보를 제공합니다.





prioriy: IPv4 접근 차단의 우선순위 정보를 제공합니다.

enable: IPv4 접근 차단에 대한 사용 여부(0: 사용 안 함, 1: 사용)를

제공합니다.



protocol: IPv4 접근 차단으로 예외 처리할 프로토콜(all, udp, tcp,

icmp) 정보를 제공합니다.



sip:  IPv4  접근  차단으로  예외  처리할  출발지  IPv4  주소룰

제공합니다.



sip_mask:  IPv4  접근  차단으로  예외  처리할  출발지  IPv4  주소의

object

-

넷마스크 정보를 제공합니다.



dip:  IPv4  접근  차단으로  예외  처리할  목적지  IPv4  주소를

제공합니다.



dip_mask:  IPv4  접근  차단으로  예외  처리할  목적지  IPv4  주소의

넷마스크 정보를 제공합니다.



sport:  IPv4  접근  차단으로  예외  처리할  출발지  포트  번호를

제공합니다.



dport:  IPv4  접근  차단으로  예외  처리할  목적지  포트  번호를

제공합니다.





name: IPv4 접근 차단의 이름을 제공합니다.

desc: IPv4 접근 차단에 대한 설명을 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

50

AhnLab DPX REST API Guide

{

"code" : 0,

"total" : 1,

"objects" : [

        {

            "priority":0,

            "enable":1,

            "protocol":"tcp",

            "sip":"1.1.1.1",

            "sip_mask":"32",

            "dip":"2.1.1.1",

            "dip_mask":"32",

            "sport":"0",

            "dport":"0",

            "name":"blacklist_0",

            "desc":"description"

            }

    ],

"message" : ""

}

51

Chapter 3 REST API 기능 명세

3.2.3.3 IPv4 접근 차단 추가

요청(Request)

IPv4 접근 차단을 추가하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone-id}/policy/blacklist

Method

POST

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Content-Type

string

application/json 정보입니다.

Path Parameters

이름

유형

내용

zone-id

string

필수 포함 항목으로 추가할 Zone 의 ID 정보 입니다.

Query Parameters

없음

Request Body

이름

유형

내용

priority

integer

필수 포함 항목으로 추가할 IPv4 접근 차단의 우선순위 정보입니다.

enable

integer

필수 포함 항목으로 추가할 IPv4 접근 차단에 대한 사용 여부(0: 사용 안

52

AhnLab DPX REST API Guide

함, 1: 사용)입니다.

protocol

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 프로토콜(all, udp, tcp, icmp)

정보입니다. 공백을 입력할 경우, all로 동작합니다.

sip

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 출발지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

sip_mask

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 출발지 넷마스크 정보입니

다. 공백을 입력할 경우, sip가 all로 동작합니다.

dip

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 목적지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

dip_mask

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 목적지 넷마스크 정보입니

다. 공백을 입력할 경우, dip가 all로 동작합니다.

sport

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 출발지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

dport

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 목적지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

name

string

필수 포함 항목으로 추가할 IPv4 접근 차단 이름입니다. 사용할 수 있는

문자는 영문자, 숫자, 특수문자( / - _ ( ) . )입니다.

desc

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 설명입니다.

"priority":0,

"enable":1,

"protocol":"tcp",

"sip":"1.1.1.1",

"sip_mask":"32",

"dip":"2.1.1.1",

"dip_mask":"32",

"sport":0,

"dport":0,

"name":"blacklist_0",

"desc":"description"

{

}

53

Chapter 3 REST API 기능 명세

응답(Response)

IPv4 접근 차단의 추가 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

54

AhnLab DPX REST API Guide

3.2.3.4 IPv4 접근 차단 수정

요청(Request)

IPv4 접근 차단을 수정하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

id}/policy/blacklist/{priority}

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone-

Method

PUT

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Content-Type

string

application/json 정보입니다.

Path Parameters

이름

유형

내용

zone-id

string

필수 포함 항목으로 수정할 Zone 의 ID 정보 입니다.

priority

String

필수 포함 항목으로 수정할 Zone 의 우선순위 정보입니다.

Query Parameters

없음

Request Body

이름

유형

내용

priority

integer

필수 포함 항목으로 수정할 IPv4 접근 차단의 우선순위 정보입니다.

enable

integer

필수 포함 항목으로 수정할 IPv4 접근 차단에 대한 사용 여부(0: 사용 안

함, 1: 사용)입니다.

55

Chapter 3 REST API 기능 명세

protocol

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 프로토콜(all, udp, tcp, icmp)

정보입니다. 공백을 입력할 경우, all로 동작합니다.

sip

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 출발지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

sip_mask

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 출발지 넷마스크 정보입니

다. 공백을 입력할 경우, sip가 all로 동작합니다.

dip

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 목적지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

dip_mask

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 목적지 넷마스크 정보입니

다. 공백을 입력할 경우, dip가 all로 동작합니다.

sport

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 출발지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

dport

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 목적지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

name

string

필수 포함 항목으로 수정할 IPv4 접근 차단 이름입니다. 사용할 수 있는

문자는 영문자, 숫자, 특수문자( / - _ ( ) . )입니다.

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 설명입니다.

desc

{

"enable":1,

"protocol":"tcp",

"sip":"1.1.1.1",

"sip_mask":"32",

"dip":"2.1.1.1",

"dip_mask":"32",

"sport":"0",

"dport":"0",

"filter":8,

"name":"blacklist01 ",

"desc":"description"

}

56

AhnLab DPX REST API Guide

응답(Response)

IPv4 접근 차단의 수정 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

57

Chapter 3 REST API 기능 명세

3.2.3.5 IPv4 접근 차단 삭제

요청(Request)

IPv4 접근 차단을 삭제하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

id}/policy/blacklist/{priority}

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone-

Method

DELETE

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

이름

유형

내용

zone-id

priority

string

필수 포함 항목으로 차단할 Zone 의 ID 정보 입니다.

string

필수 포함 항목으로 차단할 Zone 의 우선순위 정보입니다.

Query Parameters

없음

Request Body

없음

58

AhnLab DPX REST API Guide

응답(Response)

IPv4 접근 차단의 수정 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

59

Chapter 3 REST API 기능 명세

3.2.4 IPv4 라우팅 우회 규칙

DPX의 라우팅 우회 규칙을 조회하고 추가/삭제하기 위한 API입니다.

3.2.4.1 IPv4 라우팅 우회 규칙 목록 조회

요청(Request)

IPv4 라우팅 우회 규칙 목록을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone-id}/policy/diversion

Method

GET

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Path Parameters

이름

유형

내용

zone-id

string

필수 포함 항목으로 조회할 Zone 의 ID 정보입니다.

Query Parameters

이름

유형

내용

offset

integer

않을 경우, 기본값(0)을 적용합니다.

조회할 IPv4 라우팅 우회 규칙 목록의 시작 위치를 지정합니다. 지정하지

60

AhnLab DPX REST API Guide

limit

integer

할 수 있는 개수는 API에 정의된 최대값(200)으로 제한하며, 지정하지 않

조회할 IPv4 라우팅 우회 규칙 목록의 개수를 지정합니다. limit으로 설정

을 경우 기본값(50)을 적용합니다.

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/0/policy/diversion?offset=1&limit=20

Request Body

없음

응답(Response)

IPv4 라우팅 우회 규칙 목록의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

code

integer

  성공: 0

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 IPv4 라우팅 우회 규칙 목록의 총 개수를 제공합니다.

조회된 IPv4 라우팅 우회 규칙 목록의 다음 정보를 제공합니다.



zone_id(integer): IPv4 라우팅 우회 규칙 목록을 조회할 Zone 의

ID 정보를 제공합니다.



index(integer): IPv4 라우팅 우회 규칙 목록을 조회할

인덱스(index) 정보를 제공합니다.



zone_name(string): IPv4 라우팅 우회 규칙 목록을 조회할 Zone

이름을 제공합니다.



trigger(integer): IPv4 라우팅 우회 규칙이 우회된 원인(0: 수동

object

-

추가, 1: Detector 에 의한 자동 추가)을 제공합니다.







time(string): IPv4 라우팅 우회 규칙의 우회 시간을 제공합니다.

desc(string): IPv4 라우팅 우회 규칙의 설명을 제공합니다.

diversion_type(integer): IPv4 라우팅 우회 규칙의 우회 유형(0:

Zone 전체, 1: 보호 대상 IPv4 주소, 2: Zone 관리의 '라우팅 우회

대상'에 따름)을 제공합니다.



ip(string): IPv4 라우팅 우회 규칙으로 우회된 대상 IP 주소를

제공합니다. diversion_type 에 따라 다음과 같이 동작합니다.



0 (Zone 전체): 해당 값은 무시되고 '-'으로 고정

61

Chapter 3 REST API 기능 명세



1 (보호 대상 IPv4 주소): IPv4 주소 형식을 지원하고 공백과

범위는 허용 안됨



2 (Zone 관리 - 라우팅 우회 대상): Zone의 라우팅 우회 대상

설정에 따라 'Zone 전체' 또는 '보호 대상 IPv4 주소'로 동작

  mask(int): IPv4 라우팅 우회 규칙으로 우회된 대상 IP 주소의

넷마스크를 제공합니다. diversion_type 에 따라 다음과 같이

동작합니다.





0 (Zone 전체): 해당 값은 무시되고 '0'으로 고정

1 (보호 대상 IPv4 주소): IPv4 주소 형식의 넷마스크(0~32)를

지원하고, 공백과 범위는 입력할 수 없음



2 (Zone 관리 - 라우팅 우회 대상): Zone의 라우팅 우회 대상

설정에 따라 'Zone 전체' 또는 '보호 대상 IPv4 주소'로 동작



prefix_list(string): IPv4 라우팅 우회 규칙에서 사용하는 중계

스위치의 prefix list 이름을 제공합니다. prefix_list 를 통해 설정한

값과 우회 스위치의 prefix list(prefix_list1~3)와 매칭하여

제공합니다.



tag(string): IPv4 라우팅 우회 규칙에서 사용하는 중계 스위치의

tag 이름을 제공합니다.

  수동 추가: IPv4 라우팅 우회 규칙 추가 시 설정한 tag 정보

제공



Detector에 의한 자동 추가: tag_list에서 설정한 정보(0:

tag_value를 통해 설정한 tag 값(1~4294967295), 1~3:

tag_list를 통해 설정한 값과 우회 스위치의 tag(tag_list1~3)와

매칭하여 제공)에 따라 제공



active_status(integer): IPv4 라우팅 우회 규칙에서 사용하는 중계

스위치의 active switch 상태(-1: 초기 값, 0: 적용 안 됨, 1: 적용, 2:

사용하지 않음)에 따라 제공합니다.



standby_status(integer): IPv4 라우팅 우회 규칙에서 사용하는

중계 스위치의 standby switch 상태(-1: 초기 값, 0: 적용 안 됨, 1:

적용, 2: 사용하지 않음)에 따라 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

62

AhnLab DPX REST API Guide

{

"code" : 0,

"total" : 13,

"objects" : [

{

"zone_priority":0,

"index":0,

"zone_name":"zone_name",

"trigger":0,

"time":"2022-08-02+10:10:14",

"desc":"description",

"diversion_type":1,

"ip":"1.1.1.1",

"mask":32,

"prefix_list":"prefix_0",

"tag":"100",

"active_status":1,

"standby_status":2

}

...

],

"message" : ""

}

63

Chapter 3 REST API 기능 명세

3.2.4.2 IPv4 라우팅 우회 규칙 조회

요청(Request)

IPv4 라우팅 우회 규칙을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

id}/policy/diversion/{index}

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone-

Method

GET

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

이름

유형

내용

zone-id

index

string

필수 포함 항목으로 조회할 Zone 의 ID 정보입니다.

String

필수 포함 항목으로 조회할 IPv4 라우팅 우회 규칙의 인덱스 정보입니다.

Query Parameters

없음

Request Body

없음

64

AhnLab DPX REST API Guide

응답(Response)

IPv4 라우팅 우회 규칙의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

code

integer

  성공: 0

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 IPv4 라우팅 우회 규칙의 총 개수를 제공합니다.

조회된 IPv4 라우팅 우회 규칙의 다음 정보를 제공합니다.



zone_id(integer): IPv4 라우팅 우회 규칙을 조회할 Zone 의

ID 정보를 제공합니다.



index(integer): IPv4 라우팅 우회 규칙을 조회할 인덱스(index)

정보를 제공합니다.



zone_name(string): IPv4 라우팅 우회 규칙을 조회할 Zone 이름을

제공합니다.



trigger(integer): IPv4 라우팅 우회 규칙이 우회된 원인(0: 수동

추가, 1: Detector 에 의한 자동 추가)을 제공합니다.







time(string): IPv4 라우팅 우회 규칙의 우회 시간을 제공합니다.

desc(string): IPv4 라우팅 우회 규칙의 설명을 제공합니다.

diversion_type(integer): IPv4 라우팅 우회 규칙의 우회 유형(0:

Zone 전체, 1: 보호 대상 IPv4 주소, 2: Zone 관리의 '라우팅 우회

object

-

대상'에 따름)을 제공합니다.



ip(string): IPv4 라우팅 우회 규칙으로 우회된 대상 IP 주소를

제공합니다. diversion_type 에 따라 다음과 같이 동작합니다.





0 (Zone 전체): 해당 값은 무시되고 '-'으로 고정

1 (보호 대상 IPv4 주소): IPv4 주소 형식을 지원하고 공백과

범위는 허용 안됨



2 (Zone 관리 - 라우팅 우회 대상): Zone의 라우팅 우회 대상

설정에 따라 'Zone 전체' 또는 '보호 대상 IPv4 주소'로 동작

  mask(int): IPv4 라우팅 우회 규칙으로 우회된 대상 IP 주소의

넷마스크를 제공합니다. diversion_type 에 따라 다음과 같이

동작합니다.





0 (Zone 전체): 해당 값은 무시되고 '0'으로 고정

1 (보호 대상 IPv4 주소): IPv4 주소 형식의 넷마스크(0~32)를

지원하고, 공백과 범위는 입력할 수 없음

65

Chapter 3 REST API 기능 명세



2 (Zone 관리 - 라우팅 우회 대상): Zone의 라우팅 우회 대상

설정에 따라 'Zone 전체' 또는 '보호 대상 IPv4 주소'로 동작



prefix_list(string): IPv4 라우팅 우회 규칙에서 사용하는 중계

스위치의 prefix list 이름을 제공합니다. prefix_list 를 통해 설정한

값과 우회 스위치의 prefix list(prefix_list1~3)와 매칭하여

제공합니다.



tag(string): IPv4 라우팅 우회 규칙에서 사용하는 중계 스위치의

tag 이름을 제공합니다.

  수동 추가: IPv4 라우팅 우회 규칙 추가 시 설정한 tag 정보

제공



Detector에 의한 자동 추가: tag_list에서 설정한 정보(0:

tag_value를 통해 설정한 tag 값(1~4294967295), 1~3:

tag_list를 통해 설정한 값과 우회 스위치의 tag(tag_list1~3)와

매칭하여 제공)에 따라 제공



active_status(integer): IPv4 라우팅 우회 규칙에서 사용하는 중계

스위치의 active switch 상태(-1: 초기 값, 0: 적용 안 됨, 1: 적용, 2:

사용하지 않음)에 따라 제공합니다.



standby_status(integer): IPv4 라우팅 우회 규칙에서 사용하는 중계

스위치의 standby switch 상태(-1: 초기 값, 0: 적용 안 됨, 1: 적용,

2: 사용하지 않음)에 따라 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

"code" : 0,

"total" : 1,

"objects" : [

{

"zone_priority":0,

"index":0,

"zone_name":"zone_name",

"trigger":0,

"time":"2022-08-02+10:10:14",

"desc":"description",

"diversion_type":1,

"ip":"1.1.1.1",

"mask":32,

"prefix_list":"prefix_0",

"tag":"100",

66

AhnLab DPX REST API Guide

"active_status":1,

"standby_status":2

}

...

],

"message" : ""

}

67

Chapter 3 REST API 기능 명세

3.2.4.3 IPv4 라우팅 우회 규칙 추가

요청(Request)

IPv4 라우팅 우회 규칙을 추가하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

Request URL

내용

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone-

id}/policy/diversion

Method

POST

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Content-Type

string

application/json 정보입니다.

Path Parameters

이름

유형

내용

zone-id

string

필수 포함 항목으로 추가할 Zone 의 ID 정보 입니다.

Query Parameters

없음

Request Body

이름

유형

내용

zone_name

string

필수 포함 항목으로 추가할 IPv4 라우팅 우회 규칙의 Zone 이름입니다.

trigger

integer

추가할 IPv4 라우팅 우회 규칙의 우회 원인(0: 수동 추가, 1: Detector에 의

한 자동 추가)입니다.

desc

string

필수 포함 항목으로 추가할 IPv4 라우팅 우회 규칙의 설명입니다.

68

AhnLab DPX REST API Guide

diversion_type

integer

전체, 1: 보호 대상 IPv4 주소, 2: Zone 관리의 '라우팅 우회 대상'에 따름)

필수 포함 항목으로 추가할 IPv4 라우팅 우회 규칙의 우회 유형(0: Zone

입니다.

필수  포함  항목으로  추가할  IPv4  라우팅  우회  규칙의  IP  주소  입니다.

diversion_type에 따라 다음과 같이 동작합니다.

ip

string





0 (Zone 전체): 해당 값은 무시되고 '-'으로 고정

1 (보호 대상 IPv4 주소): IPv4 주소 형식을 지원하고 공백과 범위는

허용 안됨



2 (Zone 관리 - 라우팅 우회 대상): Zone 의 라우팅 우회 대상 설정에

따라 'Zone 전체' 또는 '보호 대상 IPv4 주소'로 동작

필수 포함 항목으로 추가할 IPv4 라우팅 우회 규칙의 IP 주소 넷마스크입

니다. diversion_type에 따라 다음과 같이 동작합니다.





0 (Zone 전체): 해당 값은 무시되고 '0'으로 고정

1  (보호  대상  IPv4  주소):  IPv4  주소  형식의  넷마스크(0~32)를

지원하고, 공백과 범위는 입력할 수 없음



2 (Zone 관리 - 라우팅 우회 대상): Zone 의 라우팅 우회 대상 설정에

따라 'Zone 전체' 또는 '보호 대상 IPv4 주소'로 동작

추가할  IPv4  라우팅  우회  규칙에서  사용하는  중계  스위치의  prefix  list

index(0: 사용 안 함, 1~3: prefix-list 1~3 값 참조) 정보입니다.

추가할 IPv4 라우팅 우회 규칙에서 사용하는 중계 스위치의 tag index(0:

사용 안 함, 1~3: tag-list 1~3 값 참조) 정보입니다.

mask

int

prefix_list

tag_list

int

int

tag_value

int

보입니다. 1~4294967895까지 입력할 수 있으며, tag_list가 0인 경우에만

추가할 IPv4 라우팅 우회 규칙에서 사용하는 중계 스위치의 tag_value 정

사용하는 정보입니다.

"zone_priority":0,

"zone_name":"diversion_0",

"desc":"description",

"diversion_type":1,

"ip":"1.1.1.1",

"mask":32,

"prefix_list":0,

"tag_list":0,

"tag_value":100

{

}

69

Chapter 3 REST API 기능 명세

응답(Response)

IPv4 라우팅 우회 규칙의 추가 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

“code”: 0,

“message”: “”

}

70

AhnLab DPX REST API Guide

3.2.4.4 IPv4 라우팅 우회 규칙 삭제

요청(Request)

IPv4 라우팅 우회 규칙을 삭제하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone-id}/policy/diversion

Method

DELETE

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Content-Type

string

application/json 정보입니다.

Path Parameters

이름

유형

내용

zone_id

string

필수 포함 항목으로 삭제할 Zone 의 ID 정보 입니다.

Query Parameters

없음

Request Body

이름

유형

내용

zone_name

string

필수 포함 항목으로 삭제할 IPv4 라우팅 우회 규칙의 Zone 이름입니다.

diversion_type

integer

필수 포함 항목으로 삭제할 IPv4 라우팅 우회 규칙의 우회 유형(0: Zone

전체, 1: 보호 대상 IPv4 주소)입니다.

71

Chapter 3 REST API 기능 명세

ip

string

diversion_type이  1(보호  대상  IPv4  주소)인  경우,  모두  일치해야  삭제할

필수 포함 항목으로 삭제할 IPv4 라우팅 우회 규칙의 우회 IP 주소입니다.

수 있습니다.

mask

int

넷마스크입니다.  diversion_type 이  1(보호  대상  IPv4  주소)인  경우,  모두

필수  포함  항목으로  삭제할  IPv4  라우팅  우회  규칙의  우회  IP  주소

일치해야 삭제할 수 있습니다.

{

}

"zone_name":"diversion_0",

"diversion_type":1,

"ip":"1.1.1.1",

"mask":32

응답(Response)

IPv4 라우팅 우회 규칙의 수정 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

72

AhnLab DPX REST API Guide

3.2.5 IPv4 시스템 격리

DPX의 시스템 격리를 조회하고 추가/삭제하기 위한 API입니다.

3.2.5.1 IPv4 시스템 격리 목록 조회

요청(Request)

IPv4 시스템 격리 목록을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone-id}/policy/quarantine

Method

GET

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Path Parameters

이름

유형

내용

zone-id

string

필수 항목으로 조회할 Zone 의 ID 정보입니다.

Query Parameters

이름

유형

내용

offset

integer

경우, 기본값(0)을 적용합니다.

조회할 IPv4 시스템 격리 목록의 시작 위치를 지정합니다. 지정하지 않을

limit

integer

조회할 IPv4 시스템 격리 목록의 개수를 지정합니다. limit으로 설정할 수

73

Chapter 3 REST API 기능 명세

있는 개수는 API에 정의된 최대값(200)으로 제한하며, 지정하지 않을 경

우 기본값(50)을 적용합니다.

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone-id}/policy/quarantine?offset=0&limit=20

Request Body

없음

응답(Response)

IPv4 시스템 격리 목록의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 IPv4 시스템 격리 목록의 총 개수를 제공합니다.

조회된 IPv4 시스템 격리 목록의 다음 정보를 제공합니다.







index(integer): IPv4 시스템 격리의 인덱스 정보를 제공합니다.

sip(string): IPv4 시스템 격리의 출발지 IP 정보를 제공합니다.

filter_type(string):  IPv4  시스템  격리의  필터  종류(1001:  시그니처

규칙, 1002: 행위 규칙)을 제공합니다.

object

-



action(string): IPv4 시스템 격리의 처리 방법(3002: 시스템 격리)를

제공합니다.







applied_time(string): IPv4 시스템 격리의 시작 시간을 제공합니다.

expired_time(string): IPv4 시스템 격리의 종료 시간을 제공합니다.

desc(string):  IPv4  시스템  격리를  처리  방법으로  사용하는  규칙

이름을 설명으로 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

74

AhnLab DPX REST API Guide

{

"code": 0,

    "message": "",

    "object": [

        {

            "action": "3002",

            "applied_time": "2023-02-16T10:08:33",

            "desc": "DoS_TCP_Ack_Only",

            "expired_time": "-",

            "filter_type": "1002",

            "index": 0,

            "sip": "193.85.1.3"

        },

        {

            "action": "3002",

            "applied_time": "2023-02-16T10:08:33",

            "desc": "DoS_TCP_Ack_Only",

            "expired_time": "-",

            "filter_type": "1002",

            "index": 1,

            "sip": "192.85.1.3"

        }

    ],

    "total": 2

}

75

Chapter 3 REST API 기능 명세

3.2.5.2 IPv4 시스템 격리 조회

요청(Request)

IPv4 시스템 격리를 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

id}/policy/quarantine/{index}

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone-

Method

GET

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

이름

유형

내용

zone-id

index

string

필수 포함 항목으로 조회할 Zone 의 ID 정보입니다.

string

필수 포함 항목으로 조회할 IPv4 시스템 격리의 인덱스 정보입니다.

Query Parameters

없음

Request Body

없음

76

AhnLab DPX REST API Guide

응답(Response)

IPv4 시스템 격리의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

total

Integer

조회된 IPv4 시스템 격리의 총 개수를 제공합니다.

object

-

조회된 IPv4 시스템 격리의 다음 정보를 제공합니다.















index(integer): IPv4 시스템 격리의 인덱스 정보를 제공합니다.

sip(string): IPv4 시스템 격리의 출발지 IP 정보를 제공합니다.

filter_type(string):  IPv4  시스템  격리의  필터  종류(1001:  시그니처

규칙, 1002: 행위 규칙)을 제공합니다.

action(string): IPv4 시스템 격리의 처리 방법(3002: 시스템 격리)를

제공합니다.

applied_time(string): IPv4 시스템 격리의 시작 시간을 제공합니다.

expired_time(string): IPv4 시스템 격리의 종료 시간을 제공합니다.

desc(string): IPv4 시스템 격리의 설명을 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

"code": 0,

    "message": "",

    "object": [

        {

            "action": "3002",

            "applied_time": "2023-02-16T10:45:45",

            "desc": "DoS_TCP_Ack_Only",

            "expired_time": "2023-02-16T10:55:45",

            "filter_type": "1002",

            "index": 0,

            "sip": "192.85.1.5"

        }

    ],

    "total": 1

}

77

Chapter 3 REST API 기능 명세

3.2.5.3 IPv4 시스템 격리 추가

요청(Request)

IPv4 시스템 격리를 추가하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone-id}/policy/quarantine

Method

POST

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Content-Type

string

application/json 정보입니다.

Path Parameters

이름

유형

내용

zone-id

string

필수 포함 항목으로 추가할 Zone 의 ID 정보 입니다.

Query Parameters

없음

Request Body

이름

유형

내용

sip

string

필수  포함  항목으로  추가할  IPv4  시스템  격리의  출발지  IP  주소

정보입니다.

{

}

"sip”:”1.1.1.1”

78

AhnLab DPX REST API Guide

응답(Response)

IPv4 시스템 격리의 추가 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

79

Chapter 3 REST API 기능 명세

3.2.5.4 IPv4 시스템 격리 삭제

요청(Request)

IPv4 시스템 격리를 삭제하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-mgmt/ipv4/{zone-id}/policy/quarantine

Method

DELETE

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Content-Type

string

application/json 정보입니다.

Path Parameters

이름

유형

내용

zone_id

string

필수 포함 항목으로 삭제할 Zone 의 ID 정보 입니다.

Query Parameters

없음

Request Body

유형

내용

string

필수  포함  항목으로  삭제할  IPv4  시스템  격리의  출발지  IP  주소

정보입니다.

이름

sip

{

}

"sip”:”1.1.1.1”

80

AhnLab DPX REST API Guide

응답(Response)

IPv4 시스템 격리의 수정 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

81

Chapter 3 REST API 기능 명세

3.2.6 정책/설정 동기화

DPX의 Zone을 동기화하고 설정하기 위한 API입니다.

3.2.6.1 정책/설정 동기화 목록 조회

요청(Request)

정책/설정을 동기화한 목록을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-sync/list

Method

GET

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Path Parameters

없음

Query Parameters

이름

유형

내용

offset

integer

을 경우, 기본값(0)을 적용합니다.

조회할 정책/설정 동기화 목록의 시작 위치를 지정합니다. 지정하지 않

limit

integer

있는 개수는 API에 정의된 최대값(21)으로 제한하며, 지정하지 않을 경우

조회할 정책/설정 동기화 목록의 개수를 지정합니다. limit으로 설정할 수

기본값(21)을 적용합니다.

https://<DPX_IP>:50005/restapi/v1/zone/zone-sync/listt?offset=0&limit=20

82

AhnLab DPX REST API Guide

Request Body

없음

응답(Response)

정책/설정 동기화 목록의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

code

integer

  성공: 0

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 정책/설정 동기화 목록의 총 개수를 제공합니다.

object

-

조회된 정책/설정 동기화 목록의 다음 정보를 제공합니다.



















dpx_name(string): Zone 에 설정된 보호 장비 이름을 제공합니다.

dpx_ip(string): Zone 에 설정된 보호 장비의 IP 정보를 제공합니다.

sync_mode(integer):  Zone 을  동기화한  운영  모드(1:  Main,

2:Secondary)를 제공합니다.

status(integer): Zone 동기화 상태(0: 이상, 1: 정상)를 제공합니다.

last_sync_result(int): Zone 동기화 결과(0: 동기화 필요, 1: 완료, 2:

동기화 진행 중, 3: 동기화 실패)를 제공합니다.

last_sync_time(string):  Zone  동기화를  성공한  가장  최근  시간을

제공합니다.

zone_cnt(integer):  Zone  동기화로  동기화된  IPv4  Zone  개수를

제공합니다.

zone6_cnt(integer):  Zone  동기화로  동기화된  IPv6  Zone  개수를

제공합니다.

zone_whiteip(integer):  IPv4  Zone 에서  인증된  IP  정보를

동기화할지  여부(0:  인증  IP  정보  동기화  OFF,  1:  인증  IP  정보

동기화 ON)를 제공합니다.



zone6_whiteip(integer):  IPv6  Zone 에서  인증된  IP  정보를

동기화할지  여부(0:  인증  IP  정보  동기화  OFF,  1:  인증  IP  정보

동기화 ON)를 제공합니다.



index(integer):  정책/설정  동기화에  대한  인덱스(index)  정보를

제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

83

{

"code": 0,

    "message": "",

    "object": [

        {

            "dpx_ip": "192.168.72.11",

            "dpx_name": "-",

            "index": 0,

            "last_sync_result": 0,

            "last_sync_time": "",

            "status": 1,

            "sync_mode": 1,

            "zone6_cnt": 0,

            "zone6_whiteip": 0,

            "zone_cnt": 2,

            "zone_whiteip": 0

        },

        {

            "dpx_ip": "192.168.72.13",

            "dpx_name": "72_13",

            "index": 1,

            "last_sync_result": 1,

            "last_sync_time": "2023-03-06 14:42:21",

            "status": 1,

            "sync_mode": 2,

            "zone6_cnt": 0,

            "zone6_whiteip": 0,

            "zone_cnt": 2,

            "zone_whiteip": 0

        },

],

"total": 2

}

Chapter 3 REST API 기능 명세

84

AhnLab DPX REST API Guide

3.2.6.2 정책/설정 동기화 조회

요청(Request)

정책/설정 동기화를 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-sync/list/{index}

Method

GET

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

없음

Query Parameters

없음

Request Body

없음

85

Chapter 3 REST API 기능 명세

응답(Response)

정책/설정 동기화의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 정책/설정 동기화의 총 개수를 제공합니다.

조회된 정책/설정 동기화의 다음 정보를 제공합니다.











dpx_name(string): Zone 에 설정된 보호 장비 이름을 제공합니다.

dpx_ip(string): Zone 에 설정된 보호 장비의 IP 정보를 제공합니다.

sync_mode(integer):  Zone 을  동기화한  운영  모드(1:  Main,

2:Secondary)를 제공합니다.

status(integer): Zone 동기화 상태(0: 이상, 1: 정상)를 제공합니다.

last_sync_result(int): Zone 동기화 결과(0: 동기화 필요, 1: 완료, 2:

동기화 진행 중, 3: 동기화 실패)를 제공합니다.



last_sync_time(string):  Zone  동기화를  성공한  가장  최근  시간을

제공합니다.

object

-



zone_cnt(integer):  Zone  동기화로  동기화된  IPv4  Zone  개수를

제공합니다.



zone6_cnt(integer):  Zone  동기화로  동기화된  IPv6  Zone  개수를

제공합니다.



zone_whiteip(integer):  IPv4  Zone 에서  인증된  IP  정보를

동기화할지  여부(0:  인증  IP  정보  동기화  OFF,  1:  인증  IP  정보

동기화 ON)를 제공합니다.



zone6_whiteip(integer):  IPv6  Zone 에서  인증된  IP  정보를

동기화할지  여부(0:  인증  IP  정보  동기화  OFF,  1:  인증  IP  정보

동기화 ON)를 제공합니다.



index(integer):  Zone  동기화에  대한  인덱스(index)  정보를

제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

86

AhnLab DPX REST API Guide

{

"code": 0,

    "message": "",

    "object": [

        {

            "dpx_ip": "192.168.72.13",

            "dpx_name": "72_13",

            "index": 0,

            "last_sync_result": 1,

            "last_sync_time": "2023-03-06 14:42:21",

            "status": 1,

            "sync_mode": 2,

            "zone6_cnt": 0,

            "zone6_whiteip": 0,

            "zone_cnt": 2,

            "zone_whiteip": 0

        }

    ],

    "total": 1

}

87

Chapter 3 REST API 기능 명세

3.2.6.3 Zone 동기화 실행

요청(Request)

정책/설정을 동기화하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-sync/sync-conf

Method

POST

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Content-Type

string

application/json 정보입니다.

Path Parameters

없음

Query Parameters

없음

Request Body

이름

유형

내용

secondary_dpx_list

string

필수  포함  항목으로  Secondary 로  운영되는  보호  장비  정보입니다.

구분자(;)를 이용하여 여러개 입력할 수 있습니다.

{

}

secondary_dpx_list":"72_18;72_13"

88

AhnLab DPX REST API Guide

응답(Response)

정책/설정 동기화에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

89

Chapter 3 REST API 기능 명세

3.2.6.4 Zone 동기화 설정

요청(Request)

정책/설정 동기화를 설정하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-sync/conf

Method

POST

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Content-Type

string

application/json 정보입니다.

Path Parameters

없음

Query Parameters

없음

Request Body

이름

유형

내용

enable

integer

필수 포함 항목으로 Zone 동기화 사용 여부(0: 사용 안 함, 1: 사용)입니다.

sync_mode

integer

필수  포함  항목으로  Zone  동기화시  사용할  운영  모드(1:  Main,  2:

Secondary)입니다.

sync_nif

string

필수 포함 항목으로 Zone 동기화시 사용할 통기화 포트 정보입니다.

90

AhnLab DPX REST API Guide

main_ip

string

필수 포함 항목으로 Zone 동기화시 Main으로 운영할 장비의 IP 주소입니

다.

use_cluster

int

필수 포함 항목으로 Zone 동기화시 정책을 동기화하기 위한 옵션(1: 모든

Zone 및 System 설정, 2: 모든 Zone 설정)입니다.

secondary_zone_

only

필수 포함 항목으로 Zone 동기화시 Secondary를 동기화 하기 위한 옵션

int

(0: Secondary로 등록한 모든 장비들에 동기화, 1: Secondary가 속한 Zone

의 정책만 동기화)입니다.

필수 포함 항목으로 IPv4 Zone에서 수집한 Self-Learn 결과에 대한 사용

여부(0: 사용 안 함, 1: 사용)입니다.

필수 포함 항목으로 IPv6 Zone에서 수집한 Self-Learn 결과에 대한 사용

여부(0: 사용 안 함, 1: 사용)입니다.

필수 포함 항목으로 IPv4 Zone 에서 인증된 IP 정보에 대한 사용 여부(0:

사용 안 함, 1: 사용)입니다.

필수 포함 항목으로 IPv6 Zone에서 인증된 IP 정보에 대한 사용 여부(0:

사용 안 함, 1: 사용)입니다.

zone_sync_sl

int

zone6_sync_sl

int

zone_white_ip

int

Zone6_white_ip

int

{

    "enable":0,

    "sync_mode":2,

    "sync_nif":"eth0",

    "main_ip":"192.168.72.11",

    "use_cluster":2,

    "secondary_zone_only":1,

    "zone_sync_sl":0,

    "zone6_sync_sl":0,

    "zone_whiteip":0,

    "zone6_whiteip":0

}

91

Chapter 3 REST API 기능 명세

응답(Response)

정책/설정 동기화의 설정 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

92

AhnLab DPX REST API Guide

3.2.6.5 Zone 동기화 설정 조회

요청(Request)

정책/설정 동기화 설정을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-sync/conf

Method

GET

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

없음

Query Parameters

없음

Request Body

없음

93

Chapter 3 REST API 기능 명세

응답(Response)

정책/설정 동기화의 설정 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 Zone 동기화 설정의 총 개수를 제공합니다.

object

-

조회된 Zone 동기화 설정의 다음 정보를 제공합니다.



use(integer):  Zone  동기화  사용  여부(0:  사용  안  함,  1:  사용)를

제공합니다.



sync_mode(integer): Zone 동기화시 사용할 운영 모드(1: Main, 2:

Secondary)를 제공합니다.



sync_nif(string):  Zone  동기화시  사용할  통기화  포트  정보를

제공합니다.

  main_ip(string):  Zone  동기화시  Main 으로  운영할  장비의  IP

주소를 제공합니다.



use_cluster(int):  Zone  동기화시  정책을  동기화하기  위한  옵션(1:

모든 Zone 및 System 설정, 2: 모든 Zone 설정) 정보를 제공합니다.



secondary_zone_only(int):  Zone  동기화시  Secondary 를  동기화

하기 위한 옵션(0: Secondary 로 등록한 모든 장비들에 동기화, 1:

Secondary 가 속한 Zone 의 정책만 동기화) 정보를 제공합니다.



zone_sync_sl(int):  IPv4 Zone 에서 수집한 Self-Learn 결과에 대한

사용 여부(0: 사용 안 함, 1: 사용)를 제공합니다.



zone6_sync_sl(int): IPv6 Zone 에서 수집한 Self-Learn 결과에 대한

사용 여부(0: 사용 안 함, 1: 사용)를 제공합니다.



zone_white_ip(int):  IPv4  Zone 에서  인증된  IP  정보에  대한  사용

여부(0: 사용 안 함, 1: 사용)를 제공합니다.



Zone6_white_ip(int): IPv6 Zone 에서 인증된 IP 정보에 대한 사용

여부(0: 사용 안 함, 1: 사용)를 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

94

AhnLab DPX REST API Guide

{

    "code": 0,

    "message": "",

    "object": [

        {

            "enable": 0,

            "main_ip": "192.168.72.11",

            "secondary_zone_only": 1,

            "sync_mode": 2,

            "sync_nif": "eth0",

            "use_cluster": 2,

            "zone6_sync_sl": 0,

            "zone6_whiteip": 0,

            "zone_sync_sl": 0,

            "zone_whiteip": 0

        }

    ],

    "total": 1

}

95

Chapter 3 REST API 기능 명세

3.2.7 Zone Protection

DPX가 관린하는 모든 Zone에 대해 Zone Protection 동작 현황을 확인하고 설정하기 위한 API입니다..

3.2.7.1 Zone Protection 목록 조회

요청(Request)

Zone Protection 목록을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-protection/ipv4

Method

GET

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Path Parameters

없음

Query Parameters

이름

유형

내용

offset

integer

경우, 기본값(0)을 적용합니다.

조회할 Zone Protection 목록의 시작 위치를 지정합니다. 지정하지 않을

limit

integer

있는 개수는 API에 정의된 최대값(50)으로 제한하며, 지정하지 않을 경우

조회할 Zone Protection 목록의 개수를 지정합니다. limit으로 설정할 수

기본값(200)을 적용합니다.

https://<DPX_IP>:50005/restapi/v1/zone/zone-protection/ipv4?offset=0&limit=20

96

AhnLab DPX REST API Guide

Request Body

없음

응답(Response)

Zone Protectoin 목록의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

code

integer

  성공: 0

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 Zone Protection 목록의 총 개수를 제공합니다.

object

-

조회된 Zone Protection 목록의 다음 정보를 제공합니다.









zone_priority(integer): Zone 의 우선 순위 정보를 제공합니다.

zone_id(integer): Zone 을 식별하는 고유 ID 정보를 제공합니다.

zone_name(string): Zone 의 이름을 제공합니다.

zone_protection(integer):  Zone 에  적용된  Protection  활성화

상태(0: 비활성화, 1: 활성화)를 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

"code": 0,

    "message": "",

    "object": [

        {

            "zone_priority": 0,

            "zone_id": 1010,

            "zone_name": “protection zone”,

            "zone_protection": 1

        },

],

"total": 1

}

97

Chapter 3 REST API 기능 명세

3.2.7.2 Zone Protection 조회

요청(Request)

Zone Protection을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-protection/ipv4/{zone-priority}

Method

GET

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

이름

유형

내용

zone-priority

Integer

필수 포함 항목으로 조회할 Zone ID 의 우선순위 정보입니다.

Query Parameters

없음

Request Body

없음

98

AhnLab DPX REST API Guide

응답(Response)

Zone Protectoin 목록의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

code

integer

  성공: 0

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 Zone Protection 목록의 총 개수를 제공합니다.

object

-

조회된 Zone Protection 목록의 다음 정보를 제공합니다.









zone_priority(integer): Zone 의 우선 순위 정보를 제공합니다.

zone_id(integer): Zone 을 식별하는 고유 ID 정보를 제공합니다.

zone_name(string): Zone 의 이름을 제공합니다.

zone_protection(integer):  Zone 에  적용된  Protection  활성화

상태(0: 비활성화, 1: 활성화)를 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

"code": 0,

    "message": "",

    "object": [

        {

            "zone_priority": 0,

            "zone_id": 1010,

            "zone_name": “protection zone”,

            "zone_protection": 1

        },

],

"total": 1

}

99

Chapter 3 REST API 기능 명세

3.2.7.3 Zone Protection 상태 업데이트

요청(Request)

Zone Protection의 상태를 업데이트하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/zone/zone-protection/ipv4

Method

PUT

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Path Parameters

없음

Query Parameters

없음

Request Body

이름

유형

내용

zone_id

integer

zone_protection

Integer

필수 포함 항목으로 Zone Protection 활성화 상태를 확인할 Zone 의 ID

정보입니다.

필수  포함  항목으로  Zone  Protection  활성화  여부(0:  비활성화,  1:

활성화)입니다.

응답(Response)

Zone Protection에 대한 응답(Response)은 다음과 같습니다.

100

AhnLab DPX REST API Guide

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

101

Chapter 3 REST API 기능 명세

3.3 Global

DPX 장비 단위로 정책을 설정하고 관리할 수 있는 API를 제공합니다.

3.3.1 IPv4 정책 예외

DPX의 정책 예외를 조회하고 추가/수정/삭제하기 위한 API입니다.

3.3.1.1 IPv4 정책 예외 목록 조회

요청(Request)

IPv4 정책 예외 목록을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/whitelist/ipv4

Method

GET

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

없음

Query Parameters

이름

유형

내용

offset

integer

조회할 IPv4 정책 예외 목록의 시작 위치를 지정합니다. 지정하지 않을

경우, 기본값(0)을 적용합니다.

102

AhnLab DPX REST API Guide

limit

integer

있는 개수는 API에 정의된 최대값(200)으로 제한하며, 지정하지 않을 경

조회할 IPv4 정책 예외 목록의 개수를 지정합니다. limit으로 설정할 수

우 기본값(50)을 적용합니다.

https://<DPX_IP>:50005/restapi/v1/global/whitelist/ipv4?offset=0&limit=20

Request Body

없음

응답(Response)

IPv4 정책 예외 목록의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

code

integer

  성공: 0

total

Integer

조회된 IPv4 정책 예외 목록의 총 개수를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

조회된 IPv4 정책 예외 목록의 다음 정보를 제공합니다.



















prioriy: IPv4 정책 예외의 우선순위 정보를 제공합니다.

enable: IPv4 정책 예외에 대한 사용 여부(0: 사용 안 함, 1: 사용)를

제공합니다.

protocol:  IPv4  정책  예외로  예외  처리할  프로토콜(all,  udp,  tcp,

icmp) 정보를 제공합니다.

sip: IPv4 정책 예외로 예외 처리할 출발지 IPv4 주소룰 제공합니다.

sip_mask:  IPv4  정책  예외로  예외  처리할  출발지  IPv4  주소의

넷마스크 정보를 제공합니다.

dip: IPv4 정책 예외로 예외 처리할 목적지 IPv4 주소를 제공합니다.

dip_mask:  IPv4  정책  예외로  예외  처리할  목적지  IPv4  주소의

넷마스크 정보를 제공합니다.

sport:  IPv4  정책  예외로  예외  처리할  출발지  포트  번호를

제공합니다.

dport:  IPv4  정책  예외로  예외  처리할  목적지  포트  번호를

제공합니다.



filter: IPv4 정책 예외로 예외할 정책 필터 정보를 제공합니다.







1: 접근 차단 (0x0001)

2: 시스템 격리 (0x0002)

4: anti-spoofing (0x0004)

object

-

103

Chapter 3 REST API 기능 명세

























8: HTTP 인증 (0x0008)

16 : SEG protection (0x0010)

32: 비 인증 IP  (0x0020)

64: 행위 규칙 (0x0040)

128: 시그니처 (0x0080)

256: 사용량 제한 (0x0100)

512: Global 접근 차단 (0x0200)

1024: Stateful 검사 (0x0400)

2048: Global 시스템 격리 (0x0800)

4096: Global 국가 기반 차단 (0x1000)

8192: 국가 기반 차단 (0x2000)

16384: Global 프로토콜 이상 (0x4000)





name: IPv4 정책 예외의 이름을 제공합니다.

desc: IPv4 정책 예외에 대한 설명을 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

    "code" : 0,

    "total" : 13,

    "objects" : [

        {

            "priority":0,

            "enable":1,

            "protocol":"tcp",

            "sip":"1.1.1.1",

            "sip_mask":"32",

            "dip":"2.1.1.1",

            "dip_mask":"32",

            "sport":"0",

            "dport":"0",

            "filter":8,

            "name":"whiltelist_0",

            "desc":"description"

        }

        ...

    ],

    "message" : ""

}

104

AhnLab DPX REST API Guide

3.3.1.2 IPv4 정책 예외 조회

요청(Request)

IPv4 정책 예외를 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/whiltelist/ipv4/{priority}

Method

GET

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

이름

유형

내용

priority

String

필수 포함 항목으로 조회할 Zone 의 우선순위 정보입니다.

Query Parameters

없음

Request Body

없음

105

Chapter 3 REST API 기능 명세

응답(Response)

IPv4 정책 예외의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 IPv4 정책 예외의 총 개수를 제공합니다.

object

-

조회된 IPv4 정책 예외의 다음 정보를 제공합니다.



















prioriy: IPv4 정책 예외의 우선순위 정보를 제공합니다.

enable: IPv4 정책 예외에 대한 사용 여부(0: 사용 안 함, 1: 사용)를

제공합니다.

protocol:  IPv4  정책  예외로  예외  처리할  프로토콜(all,  udp,  tcp,

icmp) 정보를 제공합니다.

sip: IPv4 정책 예외로 예외 처리할 출발지 IPv4 주소룰 제공합니다.

sip_mask:  IPv4  정책  예외로  예외  처리할  출발지  IPv4  주소의

넷마스크 정보를 제공합니다.

dip: IPv4 정책 예외로 예외 처리할 목적지 IPv4 주소를 제공합니다.

dip_mask:  IPv4  정책  예외로  예외  처리할  목적지  IPv4  주소의

넷마스크 정보를 제공합니다.

sport:  IPv4  정책  예외로  예외  처리할  출발지  포트  번호를

제공합니다.

dport:  IPv4  정책  예외로  예외  처리할  목적지  포트  번호를

제공합니다.



filter: IPv4 정책 예외로 예외할 정책 필터 정보를 제공합니다.





























1: 접근 차단 (0x0001)

2: 시스템 격리 (0x0002)

4: anti-spoofing (0x0004)

8: HTTP 인증 (0x0008)

16 : SEG protection (0x0010)

32: 비 인증 IP  (0x0020)

64: 행위 규칙 (0x0040)

128: 시그니처 (0x0080)

256: 사용량 제한 (0x0100)

512: Global 접근 차단 (0x0200)

1024: Stateful 검사 (0x0400)

2048: Global 시스템 격리 (0x0800)

4096: Global 국가 기반 차단 (0x1000)

8192: 국가 기반 차단 (0x2000)

106

AhnLab DPX REST API Guide



16384: Global 프로토콜 이상 (0x4000)

name: IPv4 정책 예외의 이름을 제공합니다.

desc: IPv4 정책 예외에 대한 설명을 제공합니다.





처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

    "code" : 0,

    "total" : 1,

    "objects" : [

        {

            "priority":0,

            "enable":1,

            "protocol":"tcp",

            "sip":"1.1.1.1",

            "sip_mask":"32",

            "dip":"2.1.1.1",

            "dip_mask":"32",

            "sport":"0",

            "dport":"0",

            "filter":8,

            "name":"whiltelist_0",

            "desc":"description"

            }

    ],

    "message" : ""

}

107

Chapter 3 REST API 기능 명세

3.3.1.3 IPv4 정책 예외 추가

요청(Request)

IPv4 정책 예외를 추가하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/whiltelist/ipv4

Method

POST

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Content-Type

string

application/json 정보입니다.

Path Parameters

없음

Query Parameters

없음

Request Body

이름

유형

내용

priority

integer

필수 포함 항목으로 추가할 IPv4 정책 예외의 우선순위 정보입니다.

enable

integer

필수 포함 항목으로 추가할 IPv4 정책 예외에 대한 사용 여부(0: 사용 안

함, 1: 사용)입니다.

protocol

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 프로토콜(all, udp, tcp, icmp)

108

AhnLab DPX REST API Guide

정보입니다. 공백을 입력할 경우, all로 동작합니다.

sip

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 출발지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

sip_mask

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 출발지 넷마스크 정보입니

다. 공백을 입력할 경우, sip가 all로 동작합니다.

dip

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 목적지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

dip_mask

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 목적지 넷마스크 정보입니

다. 공백을 입력할 경우, dip가 all로 동작합니다.

sport

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 출발지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

dport

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 목적지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

필수 포함 항목으로 추가할 IPv4 정책 예외에서 예외할 필터 정보입니다.

filter

Integer





























1: 접근 차단 (0x0001)

2: 시스템 격리 (0x0002)

4: anti-spoofing (0x0004)

8: HTTP 인증 (0x0008)

16: SEG protection (0x0010)

32: 비 인증 IP  (0x0020)

64: 행위 규칙 (0x0040)

128: 시그니처 (0x0080)

256: 사용량 제한 (0x0100)

512: Global 접근 차단 (0x0200)

1024: Stateful 검사 (0x0400)

2048: Global 시스템 격리 (0x0800)

4096: Global 국가 기반 차단 (0x1000)

8192: 국가 기반 차단 (0x2000)



16384: Global 프로토콜 이상 (0x4000)

name

string

필수 포함 항목으로 추가할 IPv4 정책 예외 이름입니다. 사용할 수 있는

문자는 영문자, 숫자, 특수문자( / - _ ( ) . )입니다.

desc

string

필수 포함 항목으로 추가할 IPv4 정책 예외의 설명입니다.

109

Chapter 3 REST API 기능 명세

{

    "priority":0,

    "enable":1,

    "protocol":"tcp",

    "sip":"1.1.1.1",

    "sip_mask":"32",

    "dip":"2.1.1.1",

    "dip_mask":"32",

    "sport":"0",

    "dport":"0",

    "filter":8,

    "name":"whiltelist_0",

    "desc":"description"

}

응답(Response)

IPv4 정책 예외의 추가 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

110

AhnLab DPX REST API Guide

3.3.1.4 IPv4 정책 예외 수정

요청(Request)

IPv4 정책 예외를 수정하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/whiltelist/ipv4/{priority}

Method

PUT

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Content-Type

string

application/json 정보입니다.

Path Parameters

이름

유형

내용

priority

String

필수 포함 항목으로 수정할 Zone 의 우선순위 정보입니다.

Query Parameters

없음

Request Body

이름

유형

내용

enable

integer

필수 포함 항목으로 수정할 IPv4 정책 예외에 대한 사용 여부(0: 사용 안

함, 1: 사용)입니다.

protocol

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 프로토콜(all, udp, tcp, icmp)

정보입니다. 공백을 입력할 경우, all로 동작합니다.

111

Chapter 3 REST API 기능 명세

sip

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 출발지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

sip_mask

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 출발지 넷마스크 정보입니

다. 공백을 입력할 경우, sip가 all로 동작합니다.

dip

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 목적지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

dip_mask

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 목적지 넷마스크 정보입니

다. 공백을 입력할 경우, dip가 all로 동작합니다.

sport

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 출발지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

dport

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 목적지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

필수 포함 항목으로 수정할 IPv4 정책 예외에서 예외할 필터 정보입니다.

filter

Integer





























1: 접근 차단 (0x0001)

2: 시스템 격리 (0x0002)

4: anti-spoofing (0x0004)

8: HTTP 인증 (0x0008)

16: SEG protection (0x0010)

32: 비 인증 IP  (0x0020)

64: 행위 규칙 (0x0040)

128: 시그니처 (0x0080)

256: 사용량 제한 (0x0100)

512: Global 접근 차단 (0x0200)

1024: Stateful 검사 (0x0400)

2048: Global 시스템 격리 (0x0800)

4096: Global 국가 기반 차단 (0x1000)

8192: 국가 기반 차단 (0x2000)



16384: Global 프로토콜 이상 (0x4000)

name

string

필수 포함 항목으로 수정할 IPv4 정책 예외 이름입니다. 사용할 수 있는

문자는 영문자, 숫자, 특수문자( / - _ ( ) . )입니다.

desc

string

필수 포함 항목으로 수정할 IPv4 정책 예외의 설명입니다.

112

AhnLab DPX REST API Guide

{

    "enable":1,

    "protocol":"tcp",

    "sip":"1.1.1.1",

    "sip_mask":"32",

    "dip":"2.1.1.1",

    "dip_mask":"32",

    "sport":"0",

    "dport":"0",

    "filter":8,

    "name":"whitelist01",

    "desc":"description"

}

응답(Response)

IPv4 정책 예외의 수정 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

113

Chapter 3 REST API 기능 명세

3.3.1.5 IPv4 정책 예외 삭제

요청(Request)

IPv4 정책 예외를 삭제하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/whiltelist/ipv4/{priority}

Method

DELETE

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Path Parameters

이름

유형

내용

priority

string

필수 포함 항목으로 삭제할 Zone 의 우선순위 정보입니다.

Query Parameters

없음

Request Body

없음

114

AhnLab DPX REST API Guide

응답(Response)

IPv4 정책 예외의 수정 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

115

Chapter 3 REST API 기능 명세

3.3.2 IPv4 접근 차단

DPX의 접근 차단을 조회하고 추가/수정/삭제하기 위한 API입니다.

3.3.2.1 IPv4 접근 차단 목록 조회

요청(Request)

IPv4 접근 차단 목록을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/blacklist/ipv4

Method

GET

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Path Parameters

이름

유형

내용

zone-id

string

필수 항목으로 조회할 Zone 의 ID 정보입니다.

Query Parameters

이름

유형

내용

offset

integer

경우, 기본값(0)을 적용합니다.

조회할 IPv4 접근 차단 목록의 시작 위치를 지정합니다. 지정하지 않을

116

AhnLab DPX REST API Guide

limit

integer

있는 개수는 API에 정의된 최대값(200)으로 제한하며, 지정하지 않을 경

조회할 IPv4 접근 차단 목록의 개수를 지정합니다. limit으로 설정할 수

우 기본값(50)을 적용합니다.

https://<DPX_IP>:50005/restapi/v1/global/blacklist/ipv4?offset=0&limit=20

Request Body

없음

응답(Response)

IPv4 접근 차단 목록의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 IPv4 접근 차단 목록의 총 개수를 제공합니다.

조회된 IPv4 접근 차단 목록의 다음 정보를 제공합니다.





prioriy: IPv4 접근 차단의 우선순위 정보를 제공합니다.

enable: IPv4 접근 차단에 대한 사용 여부(0: 사용 안 함, 1: 사용)를

제공합니다.



protocol: IPv4 접근 차단으로 예외 처리할 프로토콜(all, udp, tcp,

icmp) 정보를 제공합니다.



sip:

IPv4  접근  차단으로  예외  처리할  출발지

IPv4  주소룰

object

-

제공합니다.



sip_mask:  IPv4  접근  차단으로  예외  처리할  출발지  IPv4  주소의

넷마스크 정보를 제공합니다.



dip:  IPv4  접근  차단으로  예외  처리할  목적지

IPv4  주소를

제공합니다.



dip_mask:  IPv4  접근  차단으로  예외  처리할  목적지  IPv4  주소의

넷마스크 정보를 제공합니다.



sport:  IPv4  접근  차단으로  예외  처리할  출발지  포트  번호를

제공합니다.

117

Chapter 3 REST API 기능 명세



dport:  IPv4  접근  차단으로  예외  처리할  목적지  포트  번호를

제공합니다.





name: IPv4 접근 차단의 이름을 제공합니다.

desc: IPv4 접근 차단에 대한 설명을 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

    "code" : 0,

    "total" : 13,

    "objects" : [

        {

            "priority":0,

            "enable":1,

            "protocol":"tcp",

            "sip":"1.1.1.1",

            "sip_mask":"32",

            "dip":"2.1.1.1",

            "dip_mask":"32",

            "sport":"0",

            "dport":"0",

            "name":"blacklist_0",

            "desc":"description"

        }

        ...

    ],

    "message" : ""

}

118

AhnLab DPX REST API Guide

3.3.2.2 IPv4 접근 차단 조회

요청(Request)

IPv4 접근 차단을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/blacklist/ipv4/{priority}

Method

GET

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

이름

유형

내용

priority

String

필수 포함 항목으로 조회할 Zone 의 우선순위 정보입니다.

Query Parameters

없음

Request Body

없음

119

Chapter 3 REST API 기능 명세

응답(Response)

IPv4 접근 차단의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 IPv4 접근 차단의 총 개수를 제공합니다.

조회된 IPv4 접근 차단의 다음 정보를 제공합니다.





prioriy: IPv4 접근 차단의 우선순위 정보를 제공합니다.

enable: IPv4 접근 차단에 대한 사용 여부(0: 사용 안 함, 1: 사용)를

제공합니다.



protocol: IPv4 접근 차단으로 예외 처리할 프로토콜(all, udp, tcp,

icmp) 정보를 제공합니다.



sip:

IPv4  접근  차단으로  예외  처리할  출발지

IPv4  주소룰

제공합니다.



sip_mask:  IPv4  접근  차단으로  예외  처리할  출발지  IPv4  주소의

object

-

넷마스크 정보를 제공합니다.



dip:  IPv4  접근  차단으로  예외  처리할  목적지

IPv4  주소를

제공합니다.



dip_mask:  IPv4  접근  차단으로  예외  처리할  목적지  IPv4  주소의

넷마스크 정보를 제공합니다.



sport:  IPv4  접근  차단으로  예외  처리할  출발지  포트  번호를

제공합니다.



dport:  IPv4  접근  차단으로  예외  처리할  목적지  포트  번호를

제공합니다.





name: IPv4 접근 차단의 이름을 제공합니다.

desc: IPv4 접근 차단에 대한 설명을 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

120

AhnLab DPX REST API Guide

{

    "code" : 0,

    "total" : 1,

    "objects" : [

        {

            "priority":0,

            "enable":1,

            "protocol":"tcp",

            "sip":"1.1.1.1",

            "sip_mask":"32",

            "dip":"2.1.1.1",

            "dip_mask":"32",

            "sport":"0",

            "dport":"0",

            "name":"blacklist_0",

            "desc":"description"

            }

    ],

    "message" : ""

}

121

Chapter 3 REST API 기능 명세

3.3.2.3 IPv4 접근 차단 추가

요청(Request)

IPv4 접근 차단을 추가하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/blacklist/ipv4

Method

POST

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Content-Type

string

application/json 정보입니다.

Path Parameters

없음

Query Parameters

없음

Request Body

이름

유형

내용

priority

integer

필수 포함 항목으로 추가할 IPv4 접근 차단의 우선순위 정보입니다.

enable

integer

필수 포함 항목으로 추가할 IPv4 접근 차단에 대한 사용 여부(0: 사용 안

함, 1: 사용)입니다.

protocol

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 프로토콜(all, udp, tcp, icmp)

정보입니다. 공백을 입력할 경우, all로 동작합니다.

122

AhnLab DPX REST API Guide

sip

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 출발지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

sip_mask

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 출발지 넷마스크 정보입니

다. 공백을 입력할 경우, sip가 all로 동작합니다.

dip

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 목적지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

dip_mask

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 목적지 넷마스크 정보입니

다. 공백을 입력할 경우, dip가 all로 동작합니다.

sport

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 출발지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

dport

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 목적지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

name

string

필수 포함 항목으로 추가할 IPv4 접근 차단 이름입니다. 사용할 수 있는

문자는 영문자, 숫자, 특수문자( / - _ ( ) . )입니다.

string

필수 포함 항목으로 추가할 IPv4 접근 차단의 설명입니다.

desc

{

    "priority":0,

    "enable":1,

    "protocol":"tcp",

    "sip":"1.1.1.1",

    "sip_mask":"32",

    "dip":"2.1.1.1",

    "dip_mask":"32",

    "sport":"0",

    "dport":"0",

    "name":"blacklist_0",

    "desc":"description"

}

123

Chapter 3 REST API 기능 명세

응답(Response)

IPv4 접근 차단의 추가 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

124

AhnLab DPX REST API Guide

3.3.2.4 IPv4 접근 차단 수정

요청(Request)

IPv4 접근 차단을 수정하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/blacklist/ipv4/{priority}

Method

PUT

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Content-Type

string

application/json 정보입니다.

Path Parameters

이름

유형

내용

priority

String

필수 포함 항목으로 수정할 Zone 의 우선순위 정보입니다.

Query Parameters

없음

Request Body

이름

유형

내용

priority

integer

필수 포함 항목으로 수정할 IPv4 접근 차단의 우선순위 정보입니다.

enable

integer

필수 포함 항목으로 수정할 IPv4 접근 차단에 대한 사용 여부(0: 사용 안

함, 1: 사용)입니다.

125

Chapter 3 REST API 기능 명세

protocol

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 프로토콜(all, udp, tcp, icmp)

정보입니다. 공백을 입력할 경우, all로 동작합니다.

sip

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 출발지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

sip_mask

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 출발지 넷마스크 정보입니

다. 공백을 입력할 경우, sip가 all로 동작합니다.

dip

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 목적지 IPv4 주소입니다. 공

백을 입력할 경우, all로 동작합니다.

dip_mask

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 목적지 넷마스크 정보입니

다. 공백을 입력할 경우, dip가 all로 동작합니다.

sport

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 출발지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

dport

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 목적지 포트 번호입니다. 공

백을 입력할 경우, all로 동작합니다.

name

string

필수 포함 항목으로 수정할 IPv4 접근 차단 이름입니다. 사용할 수 있는

문자는 영문자, 숫자, 특수문자( / - _ ( ) . )입니다.

desc

string

필수 포함 항목으로 수정할 IPv4 접근 차단의 설명입니다.

{

    "enable":1,

    "protocol":"tcp",

    "sip":"1.1.1.1",

    "sip_mask":"32",

    "dip":"2.1.1.1",

    "dip_mask":"32",

    "sport":"0",

    "dport":"0",

    "name":"blacklist01",

    "desc":"description"

}

126

AhnLab DPX REST API Guide

응답(Response)

IPv4 접근 차단의 수정 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

127

Chapter 3 REST API 기능 명세

3.3.2.5 IPv4 접근 차단 삭제

요청(Request)

IPv4 접근 차단을 삭제하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/blacklist/ipv4/{priority}

Method

DELETE

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Path Parameters

이름

유형

내용

priority

string

필수 포함 항목으로 차단할 Zone 의 우선순위 정보입니다.

Query Parameters

없음

Request Body

없음

128

AhnLab DPX REST API Guide

응답(Response)

IPv4 접근 차단의 수정 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

129

Chapter 3 REST API 기능 명세

3.3.3 IPv4 라우팅 우회 규칙

DPX의 라우팅 우회 규칙을 조회하고 추가/삭제하기 위한 API입니다.

3.3.3.1 IPv4 라우팅 우회 규칙 목록 조회

요청(Request)

IPv4 라우팅 우회 규칙 목록을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/oop/diversion/ipv4

Method

GET

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Path Parameters

없음

Query Parameters

이름

유형

내용

offset

integer

조회할 IPv4 라우팅 우회 규칙 목록의 시작 위치를 지정합니다. 지정하지

않을 경우, 기본값(0)을 적용합니다.

limit

integer

할 수 있는 개수는 API에 정의된 최대값(200)으로 제한하며, 지정하지 않

조회할 IPv4 라우팅 우회 규칙 목록의 개수를 지정합니다. limit으로 설정

을 경우 기본값(50)을 적용합니다.

https://<DPX_IP>:50005/restapi/v1/global/oop/diversion/ipv4?offset=0&limit=20

130

AhnLab DPX REST API Guide

Request Body

없음

응답(Response)

IPv4 라우팅 우회 규칙 목록의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 IPv4 라우팅 우회 규칙 목록의 총 개수를 제공합니다.

조회된 IPv4 라우팅 우회 규칙 목록의 다음 정보를 제공합니다.



zone_id(integer): IPv4 라우팅 우회 규칙 목록을 조회할 Zone 의

ID 정보를 제공합니다.



index(integer): IPv4 라우팅 우회 규칙 목록을 조회할

인덱스(index) 정보를 제공합니다.



zone_name(string): IPv4 라우팅 우회 규칙 목록을 조회할 Zone

이름을 제공합니다.



trigger(integer): IPv4 라우팅 우회 규칙이 우회된 원인(0: 수동

추가, 1: Detector 에 의한 자동 추가)을 제공합니다.







time(string): IPv4 라우팅 우회 규칙의 우회 시간을 제공합니다.

desc(string): IPv4 라우팅 우회 규칙의 설명을 제공합니다.

diversion_type(integer): IPv4 라우팅 우회 규칙의 우회 유형(0:

Zone 전체, 1: 보호 대상 IPv4 주소, 2: Zone 관리의 '라우팅 우회

대상'에 따름)을 제공합니다.



ip(string): IPv4 라우팅 우회 규칙으로 우회된 대상 IP 주소를

제공합니다. diversion_type 에 따라 다음과 같이 동작합니다.





0 (Zone 전체): 해당 값은 무시되고 '-'으로 고정

1 (보호 대상 IPv4 주소): IPv4 주소 형식을 지원하고 공백과 범

위는 허용 안됨



2 (Zone 관리 - 라우팅 우회 대상): Zone의 라우팅 우회 대상

설정에 따라 'Zone 전체' 또는 '보호 대상 IPv4 주소'로 동작

  mask(int): IPv4 라우팅 우회 규칙으로 우회된 대상 IP 주소의

넷마스크를 제공합니다. diversion_type 에 따라 다음과 같이

동작합니다.

object

-

131

Chapter 3 REST API 기능 명세





0 (Zone 전체): 해당 값은 무시되고 '0'으로 고정

1 (보호 대상 IPv4 주소): IPv4 주소 형식의 넷마스크(0~32)를

지원하고, 공백과 범위는 입력할 수 없음



2 (Zone 관리 - 라우팅 우회 대상): Zone의 라우팅 우회 대상

설정에 따라 'Zone 전체' 또는 '보호 대상 IPv4 주소'로 동작



prefix_list(string): IPv4 라우팅 우회 규칙에서 사용하는 중계

스위치의 prefix list 이름을 제공합니다. prefix_list 를 통해 설정한

값과 우회 스위치의 prefix list(prefix_list1~3)와 매칭하여

제공합니다.



tag(string): IPv4 라우팅 우회 규칙에서 사용하는 중계 스위치의

tag 이름을 제공합니다.

  수동 추가: IPv4 라우팅 우회 규칙 추가 시 설정한 tag 정보 제

공



Detector에 의한 자동 추가: tag_list에서 설정한 정보(0:

tag_value를 통해 설정한 tag 값(1~4294967295), 1~3:

tag_list를 통해 설정한 값과 우회 스위치의 tag(tag_list1~3)

와 매칭하여 제공)에 따라 제공



active_status(integer): IPv4 라우팅 우회 규칙에서 사용하는 중계

스위치의 active switch 상태(-1: 초기 값, 0: 적용 안 됨, 1: 적용, 2:

사용하지 않음)에 따라 제공합니다.



standby_status(integer): IPv4 라우팅 우회 규칙에서 사용하는

중계 스위치의 standby switch 상태(-1: 초기 값, 0: 적용 안 됨, 1:

적용, 2: 사용하지 않음)에 따라 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

"code" : 0,

    "code" : 0,

    "total" : 13,

    "objects" : [

        {

            "index" 0,

            "zone_name":"zone_name",

            "trigger":0,

            "time":"2022-08-02+10:10:14",

            "desc":"description",

            "diversion_type":1,

            "ip":"1.1.1.1",

132

AhnLab DPX REST API Guide

            "mask":32,

            "prefix_list":"prefix_0",

            "tag":"100",

            "active_status":1,

            "standby_status":2

        }

        ...

    ],

    "message" : ""

}

133

Chapter 3 REST API 기능 명세

3.3.3.2 IPv4 라우팅 우회 규칙 조회

요청(Request)

IPv4 라우팅 우회 규칙을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/oop/diversion/ipv4/{index}

Method

GET

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Path Parameters

이름

index

유형

내용

string

필수 포함 항목으로 조회할 IPv4 라우팅 우회 규칙의 인덱스 정보입니다.

Query Parameters

없음

Request Body

없음

134

AhnLab DPX REST API Guide

응답(Response)

IPv4 라우팅 우회 규칙의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 IPv4 라우팅 우회 규칙의 총 개수를 제공합니다.

조회된 IPv4 라우팅 우회 규칙의 다음 정보를 제공합니다.



zone_id(integer): IPv4 라우팅 우회 규칙을 조회할 Zone 의













ID 정보를 제공합니다.

index(integer): IPv4 라우팅 우회 규칙을 조회할 인덱스(index)

정보를 제공합니다.

zone_name(string): IPv4 라우팅 우회 규칙을 조회할 Zone 이름을

제공합니다.

trigger(integer): IPv4 라우팅 우회 규칙이 우회된 원인(0: 수동

추가, 1: Detector 에 의한 자동 추가)을 제공합니다.

time(string): IPv4 라우팅 우회 규칙의 우회 시간을 제공합니다.

desc(string): IPv4 라우팅 우회 규칙의 설명을 제공합니다.

diversion_type(integer): IPv4 라우팅 우회 규칙의 우회 유형(0:

Zone 전체, 1: 보호 대상 IPv4 주소, 2: Zone 관리의 '라우팅 우회

대상'에 따름)을 제공합니다.



ip(string): IPv4 라우팅 우회 규칙으로 우회된 대상 IP 주소를

제공합니다. diversion_type 에 따라 다음과 같이 동작합니다.





0 (Zone 전체): 해당 값은 무시되고 '-'으로 고정

1 (보호 대상 IPv4 주소): IPv4 주소 형식을 지원하고 공백과

범위는 허용 안됨



2 (Zone 관리 - 라우팅 우회 대상): Zone의 라우팅 우회 대상

설정에 따라 'Zone 전체' 또는 '보호 대상 IPv4 주소'로 동작

  mask(int): IPv4 라우팅 우회 규칙으로 우회된 대상 IP 주소의

넷마스크를 제공합니다. diversion_type 에 따라 다음과 같이

동작합니다.





0 (Zone 전체): 해당 값은 무시되고 '0'으로 고정

1 (보호 대상 IPv4 주소): IPv4 주소 형식의 넷마스크(0~32)를

지원하고, 공백과 범위는 입력할 수 없음



2 (Zone 관리 - 라우팅 우회 대상): Zone의 라우팅 우회 대상

설정에 따라 'Zone 전체' 또는 '보호 대상 IPv4 주소'로 동작

object

-

135

Chapter 3 REST API 기능 명세



prefix_list(string): IPv4 라우팅 우회 규칙에서 사용하는 중계

스위치의 prefix list 이름을 제공합니다. prefix_list 를 통해 설정한

값과 우회 스위치의 prefix list(prefix_list1~3)와 매칭하여

제공합니다.



tag(string): IPv4 라우팅 우회 규칙에서 사용하는 중계 스위치의

tag 이름을 제공합니다.

  수동 추가: IPv4 라우팅 우회 규칙 추가 시 설정한 tag 정보

제공



Detector에 의한 자동 추가: tag_list에서 설정한 정보(0:

tag_value를 통해 설정한 tag 값(1~4294967295), 1~3:

tag_list를 통해 설정한 값과 우회 스위치의 tag(tag_list1~3)와

매칭하여 제공)에 따라 제공



active_status(integer): IPv4 라우팅 우회 규칙에서 사용하는 중계

스위치의 active switch 상태(-1: 초기 값, 0: 적용 안 됨, 1: 적용, 2:

사용하지 않음)에 따라 제공합니다.



standby_status(integer): IPv4 라우팅 우회 규칙에서 사용하는 중계

스위치의 standby switch 상태(-1: 초기 값, 0: 적용 안 됨, 1: 적용,

2: 사용하지 않음)에 따라 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

    "code" : 0,

    "total" : 1,

    "objects" : [

        {   "index":0,

            "zone_name":"zone_name",

            "trigger":0,

            "time":"2022-08-02+10:10:14",

            "desc":"description",

            "diversion_type":1,

            "ip":"1.1.1.1",

            "mask":32,

            "prefix_list":"prefix_0",

            "tag":"100",

            "active_status":1,

            "standby_status":2    }

    ],

    "message" : ""

}

136

AhnLab DPX REST API Guide

3.3.3.3 IPv4 라우팅 우회 규칙 추가

요청(Request)

IPv4 라우팅 우회 규칙을 추가하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/oop/diversion/ipv4

Method

POST

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Content-Type

string

application/json 정보입니다.

Path Parameters

없음

Query Parameters

없음

Request Body

이름

유형

내용

zone_name

string

필수 포함 항목으로 추가할 IPv4 라우팅 우회 규칙의 Zone 이름입니다.

trigger

integer

추가할 IPv4 라우팅 우회 규칙의 우회 원인(0: 수동 추가, 1: Detector에 의

한 자동 추가)입니다.

desc

string

필수 포함 항목으로 추가할 IPv4 라우팅 우회 규칙의 설명입니다.

137

Chapter 3 REST API 기능 명세

diversion_type

integer

전체, 1: 보호 대상 IPv4 주소, 2: Zone 관리의 '라우팅 우회 대상'에 따름)

필수 포함 항목으로 추가할 IPv4 라우팅 우회 규칙의 우회 유형(0: Zone

입니다.

필수  포함  항목으로  추가할  IPv4  라우팅  우회  규칙의  IP  주소  입니다.

diversion_type에 따라 다음과 같이 동작합니다.

ip

string





0 (Zone 전체): 해당 값은 무시되고 '-'으로 고정

1 (보호 대상 IPv4 주소): IPv4 주소 형식을 지원하고 공백과 범위는

허용 안됨



2  (Zone  관리  -  라우팅  우회  대상):  Zone 의  라우팅  우회  대상

설정에 따라 'Zone 전체' 또는 '보호 대상 IPv4 주소'로 동작

필수 포함 항목으로 추가할 IPv4 라우팅 우회 규칙의 IP 주소 넷마스크입

니다. diversion_type에 따라 다음과 같이 동작합니다.





0 (Zone 전체): 해당 값은 무시되고 '0'으로 고정

1  (보호  대상  IPv4  주소):  IPv4  주소  형식의  넷마스크(0~32)를

지원하고, 공백과 범위는 입력할 수 없음



2  (Zone  관리  -  라우팅  우회  대상):  Zone 의  라우팅  우회  대상

설정에 따라 'Zone 전체' 또는 '보호 대상 IPv4 주소'로 동작

mask

int

prefix_list

int

추가할  IPv4  라우팅  우회  규칙에서  사용하는  중계  스위치의  prefix  list

index(0: 사용 안 함, 1~3: prefix-list 1~3 값 참조) 정보입니다.

tag_list

int

추가할 IPv4 라우팅 우회 규칙에서 사용하는 중계 스위치의 tag index(0:

사용 안 함, 1~3: tag-list 1~3 값 참조) 정보입니다.

tag_value

int

보입니다. 1~4294967895까지 입력할 수 있으며, tag_list가 0인 경우에만

추가할 IPv4 라우팅 우회 규칙에서 사용하는 중계 스위치의 tag_value 정

사용하는 정보입니다.

{

    "zone_name":"diversion_0",

    "desc":"description",

    "diversion_type":1,

    "ip":"1.1.1.1",

    "mask":32,

    "prefix_list":0,

    "tag_list":"0",

    "tag_value":"100"

}

138

AhnLab DPX REST API Guide

응답(Response)

IPv4 라우팅 우회 규칙의 추가 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

139

Chapter 3 REST API 기능 명세

3.3.3.4 IPv4 라우팅 우회 규칙 삭제

요청(Request)

IPv4 라우팅 우회 규칙을 삭제하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/oop/diversion/ipv4

Method

DELETE

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Content-Type

string

application/json 정보입니다.

Path Parameters

없음

Query Parameters

없음

Request Body

이름

유형

내용

zone_name

string

필수 포함 항목으로 삭제할 IPv4 라우팅 우회 규칙의 Zone 이름입니다.

diversion_type

integer

필수 포함 항목으로 삭제할 IPv4 라우팅 우회 규칙의 우회 유형(0: Zone

전체, 1: 보호 대상 IPv4 주소)입니다.

ip

string

diversion_type이  1(보호  대상  IPv4  주소)인  경우,  모두  일치해야  삭제할

필수 포함 항목으로 삭제할 IPv4 라우팅 우회 규칙의 우회 IP 주소입니다.

수 있습니다.

140

AhnLab DPX REST API Guide

mask

int

넷마스크입니다.  diversion_type 이  1(보호  대상  IPv4  주소)인  경우,  모두

필수  포함  항목으로  삭제할  IPv4  라우팅  우회  규칙의  우회  IP  주소

일치해야 삭제할 수 있습니다.

{

}

"zone_name":"diversion_0",

"diversion_type":1,

"ip":"1.1.1.1",

"mask":32

응답(Response)

IPv4 라우팅 우회 규칙의 수정 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

141

Chapter 3 REST API 기능 명세

3.3.4 IPv4 시스템 격리

DPX의 시스템 격리를 조회하고 추가/삭제하기 위한 API입니다.

3.3.4.1 IPv4 시스템 격리 목록 조회

요청(Request)

IPv4 시스템 격리 목록을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/quarantine/ipv4

Method

GET

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

없음

Query Parameters

이름

유형

내용

offset

integer

조회할 IPv4 시스템 격리 목록의 시작 위치를 지정합니다. 지정하지 않을

경우, 기본값(0)을 적용합니다.

limit

integer

있는 개수는 API에 정의된 최대값(200)으로 제한하며, 지정하지 않을 경

조회할 IPv4 시스템 격리 목록의 개수를 지정합니다. limit으로 설정할 수

우 기본값(50)을 적용합니다.

https://<DPX_IP>:50005/restapi/v1/global/quarantine/ipv4?offset=0&limit=20

Request Body

없음

142

AhnLab DPX REST API Guide

응답(Response)

IPv4 시스템 격리 목록의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

code

integer

  성공: 0

total

Integer

조회된 IPv4 시스템 격리 목록의 총 개수를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

object

-

조회된 IPv4 시스템 격리 목록의 다음 정보를 제공합니다.









index(integer): IPv4 시스템 격리의 인덱스 정보를 제공합니다.

sip(string): IPv4 시스템 격리의 출발지 IP 정보를 제공합니다.

applied_time(string): IPv4 시스템 격리의 시작 시간을 제공합니다.

expired_time(string): IPv4 시스템 격리의 종료 시간을 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

"code": 0,

    "message": "",

    "object": [

        {

            "applied_time": "23-02-21T09:00:43",

            "expired_time": "23-02-21T09:17:23",

            "index": 0,

            "sip": "10.10.10.10"

        },

        {

            "applied_time": "23-02-21T09:00:00",

            "expired_time": "23-02-21T09:16:40",

            "index": 1,

            "sip": "1.1.1.1"

        }

    ],

    "total": 2

}

143

Chapter 3 REST API 기능 명세

3.3.4.2 IPv4 시스템 격리 조회

요청(Request)

IPv4 시스템 격리를 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/quarantine/ipv4/{index}

Method

GET

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Path Parameters

이름

index

유형

내용

string

필수 포함 항목으로 조회할 IPv4 시스템 격리의 인덱스 정보입니다.

Query Parameters

없음

Request Body

없음

144

AhnLab DPX REST API Guide

응답(Response)

IPv4 시스템 격리의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

total

Integer

조회된 IPv4 시스템 격리의 총 개수를 제공합니다.

object

-

조회된 IPv4 시스템 격리의 다음 정보를 제공합니다.









index(integer): IPv4 시스템 격리의 인덱스 정보를 제공합니다.

sip(string): IPv4 시스템 격리의 출발지 IP 정보를 제공합니다.

applied_time(string): IPv4 시스템 격리의 시작 시간을 제공합니다.

expired_time(string): IPv4 시스템 격리의 종료 시간을 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

"code": 0,

    "message": "",

    "object": [

        {

            "applied_time": "23-02-21T09:32:01",

            "expired_time": "23-02-21T09:48:41",

            "index": 0,

            "sip": "10.10.10.10"

        }

    ],

    "total": 1

}

145

Chapter 3 REST API 기능 명세

3.3.4.3 IPv4 시스템 격리 추가

요청(Request)

IPv4 시스템 격리를 추가하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/quarantine/ipv4

Method

POST

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Content-Type

string

application/json 정보입니다.

Path Parameters

없음

Query Parameters

없음

Request Body

이름

sip

유형

내용

string

필수 포함 항목으로 추가할 IPv4 시스템 격리의 출발지 IP 주소 정보입니다.

expired_time

integer

필수 포함 항목으로 추가할 IPv4 시스템 격리의 종료 시간 정보입니다.

{

"sip":"1.1.1.1",

    "expired_time": 600

}

146

AhnLab DPX REST API Guide

응답(Response)

IPv4 시스템 격리의 추가 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

147

Chapter 3 REST API 기능 명세

3.3.4.4 IPv4 시스템 격리 삭제

요청(Request)

IPv4 시스템 격리를 삭제하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/quarantine/ipv4

Method

DELETE

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Content-Type

string

application/json 정보입니다.

Path Parameters

없음

Query Parameters

없음

Request Body

유형

내용

string

필수 포함 항목으로 삭제할 IPv4 시스템 격리의 출발지 IP 주소 정보입니다.

이름

sip

{

}

"sip”:”1.1.1.1”

148

AhnLab DPX REST API Guide

응답(Response)

IPv4 시스템 격리의 수정 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

}

“code”: 0,

“message”: “”

149

Chapter 3 REST API 기능 명세

3.3.5 패킷 자동 수집 다운로드

DPX에서 패킷 자동 수집으로 생성된 pcap 파일을 다운로드하기 위한 API입니다.

요청(Request)

패킷 자동 수집으로 생성된 pcap 파일을 다운로드 하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/global/packet-capture/download

Method

POST

Header

이름

유형

내용

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

발급 받은 토큰 정보입니다.

Content-Type

string

application/json 정보입니다.

Path Parameters

없음

Query Parameters

없음

Request Body

이름

유형

내용

detect_time

string

필수 포함 항목으로 패킷 자동 수집이 수행된 시간입니다.

detect_rule

string

필수 포함 항목으로 패킷 자동 수집이 수행된 탐지 규칙 이름입니다.

150

AhnLab DPX REST API Guide

detect_ip

device_id

string

필수 포함 항목으로 패킷 자동 수집이 수행된 탐지 IP 주소입니다.

string

필수 포함 항목으로 패킷 자동 수집이 수행된 장비 ID 입니다.

detect_rule_id

string

필수 포함 항목으로 패킷 자동 수집이 수행된 탐지 규칙 ID 입니다.

{

"detect_time": "20210924120000.000",

    "detect_rule": "DDoS_TCP_Syn_Only",

    "detect_ip": "192.168.0.1",

    "device_id": "9b8edd",

    "detect_rule_id": "92016"

}

응답(Response)

다운로드를 요청한 pcap 파일에 대한 응답(Response)은 다음과 같습니다.

Response Body

패킷 자동 수집으로 생성한 pcap 파일 이름은 장비 ID와 탐지 규칙 ID를 포함하여 표시(예, YYYYMMDDhhmmss

.SSS_deviceid_ruleid.pcap)합니다. Resopnse Body에서는 패킷 자동 수집으로 생성된 pcap 파일의 바이너리 데이

터를 제공합니다.

151

Chapter 3 REST API 기능 명세

3.4 System

DPX 장비 단위로 시스템 설정을 관리할 수 있는 API를 제공합니다.

3.4.1 IPv4 필터 로그

DPX의 필터 로그를 조회하고 설정하기 위한 API입니다.

3.4.1.1 IPv4 필터 로그 설정 조회

요청(Request)

IPv4 필터 로그 설정을 조회하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/system/log-mgmt/filterlog/ipv4

Method

GET

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Path Parameters

없음

Query Parameters

없음

Request Body

없음

152

AhnLab DPX REST API Guide

응답(Response)

IPv4 필터 로그 설정의 조회 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

code

integer

  성공: 0

total

Integer

조회된 IPv4 필터 로그 설정의 총 개수를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

조회된 IPv4 필터 로그 설정의 다음 정보를 제공합니다.



global_white_list: Global 정책 예외 필터 로그에 대한 기록 여부(0:

사용 안 함, 1: 사용)를 제공합니다.



white_list: 정책 예외 필터 로그에 대한 기록 여부(0: 사용 안 함, 1:

사용)를 제공합니다.



global_black_list: Global 접근 차단 필터 로그에 대한 기록 여부(0:

사용 안 함, 1: 사용)를 제공합니다.



black_list: 접근 차단 필터 로그에 대한 기록 여부(0: 사용 안 함, 1:

사용)를 제공합니다.



quarantine:  시스템  격리  필터  로그에  대한  기록  여부(0:  사용  안

함, 1: 사용)를 제공합니다.



antispoof_block:  Anti-Spoofing(TCP)  필터의  차단  로그에  대한

기록 여부(0: 사용 안 함, 1: 사용)를 제공합니다.

object

-



antispoof_authip: Anti-Spoofing(TCP) 필터의 인증 IP 로그에 대한

기록 여부(0: 사용 안 함, 1: 사용)를 제공합니다.



httpauth_block:  HTTP  접속  인증  필터의  차단  로그에  대한  기록

여부(0: 사용 안 함, 1: 사용)를 제공합니다.



httpauth_authip: HTTP 접속 인증 필터의 인증 IP 로그에 대한 기록

여부(0: 사용 안 함, 1: 사용)를 제공합니다.



segment: Segment protection 필터 로그에 대한 기록 여부(0: 사용

안 함, 1: 사용)를 제공합니다.



unauth: 비인증 IP 차단 필터 로그에 대한 기록 여부(0: 사용 안 함,

1: 사용)를 제공합니다.



stateful: Stateful 검사 필터 로그에 대한 기록 여부(0: 사용 안 함,

1: 사용)를 제공합니다.



threshold: 행위 규칙 필터 로그에 대한 기록 여부(0: 사용 안 함, 1:

사용)를 제공합니다.

153

Chapter 3 REST API 기능 명세



qos:  사용량  제한  필터  로그에  대한  기록  여부(0:  사용  안  함,  1:

사용)를 제공합니다.



dnsauth_block:  Anti-Spoofing(DNS)  필터의  차단  로그에  대한

기록 여부(0: 사용 안 함, 1: 사용)를 제공합니다.



dnsauth_authip: Anti-Spoofing(DNS) 필터의 인증 IP 로그에 대한

기록 여부(0: 사용 안 함, 1: 사용)를 제공합니다.



global_quarantine:  Global  시스템  격리  필터  로그에  대한  기록

여부(0: 사용 안 함, 1: 사용)를 제공합니다.



global_geoip:  Global  국가  기반  차단  필터  로그에  대한  기록

여부(0: 사용 안 함, 1: 사용)를 제공합니다.



geoip: 국가 기반 차단 필터 로그에 대한 기록 여부(0: 사용 안 함,

1: 사용)를 제공합니다.



global_protocol_anomaly: Global 프로토콜 이상 필터 로그에 대한

기록 여부(0: 사용 안 함, 1: 사용)를 제공합니다.



dns_nxdomain_block:  Anti-Spoofing(NXDomain)  필터의  차단

로그에 대한 기록 여부(0: 사용 안 함, 1: 사용)를 제공합니다.



dns_nxdomain_allow:  Anti-Spoofing(NXDomain)  필터의  허용

로그에 대한 기록 여부(0: 사용 안 함, 1: 사용)를 제공합니다.



antispoof_udp_block:  Anti-Spoofing(UDP)  필터의  차단  로그에

대한 기록 여부(0: 사용 안 함, 1: 사용)를 제공합니다.



antispoof_udp_allow:  Anti-Spoofing(UDP)  필터의  허용  로그에

대한 기록 여부(0: 사용 안 함, 1: 사용)를 제공합니다.

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

    "code": 0,

    "total": 1,

    "object": [

        {

            "global_white_list": 1,

            "white_list": 1,

            "global_black_list": 1,

            "black_list": 0,

            "quarantine": 1,

            "antispoof_block": 1,

            "antispoof_authip": 0,

            "httpauth_block": 0,

            "httpauth_authip": 0,

154

AhnLab DPX REST API Guide

            "segment": 0,

            "unauth": 0,

            "stateful": 0,

            "threshold": 0,

            "qos": 0,

            "dnsauth_block": 1,

            "dnsauth_authip": 1,

            "global_quarantine": 1,

            "global_geoip": 0,

            "geoip": 0,

            "global_protocol_anomaly": 0,

            "dns_nxdomain_block": 0,

            "dns_nxdomain_allow": 1,

            "antispoof_udp_block": 0,

            "antispoof_udp_allow": 0

        }

    ],

    "message": ""

}

155

Chapter 3 REST API 기능 명세

3.4.1.2 IPv4 필터 로그 설정 저장

요청(Request)

IPv4 필터 로그 설정을 저장하기 위한 요청(Request)은 다음과 같습니다.

공통

항목

내용

Request URL

https://<DPX_IP>:50005/restapi/v1/system/log-mgmt/filterlog/ipv4

Method

POST

Header

이름

유형

내용

발급 받은 토큰 정보입니다.

Authorization

string

  인증 종류로 Bearer 를 사용하며 Bearer 와 {access_token} 사이에

공백이 입력되야 합니다. 예) “Bearer {access_token}”

Content-Type

string

application/json 정보입니다.

Path Parameters

없음

Query Parameters

없음

Request Body

이름

유형

내용

global_white_list

integer

필수 포함 항목으로, Global 정책 예외 필터 로그에 대한 기록 여부(0: 사용

안 함, 1: 사용)를 제공합니다.

white_list

integer

필수 포함 항목으로, 정책 예외 필터 로그에 대한 기록 여부(0: 사용 안 함,

1: 사용)를 제공합니다.

global_black_list

integer

필수 포함 항목으로, Global 접근 차단 필터 로그에 대한 기록 여부(0: 사

용 안 함, 1: 사용)를 제공합니다.

156

AhnLab DPX REST API Guide

black_list

integer

필수 포함 항목으로, 접근 차단 필터 로그에 대한 기록 여부(0: 사용 안 함,

1: 사용)를 제공합니다.

quarantine

integer

필수 포함 항목으로, 시스템 격리 필터 로그에 대한 기록 여부(0: 사용 안

함, 1: 사용)를 제공합니다.

antispoof_block

integer

필수 포함 항목으로,  Anti-Spoofing(TCP) 필터의 차단 로그에 대한 기록

여부(0: 사용 안 함, 1: 사용)를 제공합니다.

antispoof_authip

integer

필수 포함 항목으로, Anti-Spoofing(TCP) 필터의 인증 IP 로그에 대한 기

록 여부(0: 사용 안 함, 1: 사용)를 제공합니다.

httpauth_block

integer

필수 포함 항목으로, HTTP 접속 인증 필터의 차단 로그에 대한 기록 여부

(0: 사용 안 함, 1: 사용)를 제공합니다.

httpauth_authip

integer

필수 포함 항목으로, HTTP 접속 인증 필터의 인증 IP 로그에 대한 기록 여

부(0: 사용 안 함, 1: 사용)를 제공합니다.

segment

Integer

필수 포함 항목으로, Segment protection 필터 로그에 대한 기록 여부(0:

사용 안 함, 1: 사용)를 제공합니다.

unauth

integer

필수 포함 항목으로, 비인증 IP 차단 필터 로그에 대한 기록 여부(0: 사용

안 함, 1: 사용)를 제공합니다.

stateful

integer

필수 포함 항목으로, Stateful 검사 필터 로그에 대한 기록 여부(0: 사용 안

함, 1: 사용)를 제공합니다.

threshold

integer

필수 포함 항목으로, 행위 규칙 필터 로그에 대한 기록 여부(0: 사용 안 함,

1: 사용)를 제공합니다.

qos

integer

필수 포함 항목으로, 사용량 제한 필터 로그에 대한 기록 여부(0: 사용 안

함, 1: 사용)를 제공합니다.

dnsauth_block

integer

필수 포함 항목으로, Anti-Spoofing(DNS) 필터의 차단 로그에 대한 기록

여부(0: 사용 안 함, 1: 사용)를 제공합니다.

dnsauth_authip

integer

필수 포함 항목으로, Anti-Spoofing(DNS) 필터의 인증 IP 로그에 대한 기

록 여부(0: 사용 안 함, 1: 사용)를 제공합니다.

global_quarantine

integer

필수 포함 항목으로, Global 시스템 격리 필터 로그에 대한 기록 여부(0:

사용 안 함, 1: 사용)를 제공합니다.

global_geoip

integer

필수 포함 항목으로, Global 국가 기반 차단 필터 로그에 대한 기록 여부

(0: 사용 안 함, 1: 사용)를 제공합니다.

geoip

integer

필수 포함 항목으로, 국가 기반 차단 필터 로그에 대한 기록 여부(0: 사용

안 함, 1: 사용)를 제공합니다.

157

Chapter 3 REST API 기능 명세

필수 포함 항목으로, Global 프로토콜 이상 필터 로그에 대한 기록 여부(0:

사용 안 함, 1: 사용)를 제공합니다.

필수 포함 항목으로, Anti-Spoofing(NXDomain) 필터의 차단 로그에 대한

기록 여부(0: 사용 안 함, 1: 사용)를 제공합니다.

필수 포함 항목으로, Anti-Spoofing(NXDomain) 필터의 허용 로그에 대한

기록 여부(0: 사용 안 함, 1: 사용)를 제공합니다.

필수 포함 항목으로, Anti-Spoofing(UDP) 필터의 차단 로그에 대한 기록

여부(0: 사용 안 함, 1: 사용)를 제공합니다.

필수 포함 항목으로, Anti-Spoofing(UDP) 필터의 허용 로그에 대한 기록

여부(0: 사용 안 함, 1: 사용)를 제공합니다.

global_protocol_a

nomaly

integer

dns_nxdomain_bl

ock

integer

dns_nxdomain_all

ow

integer

antispoof_udp_bl

ock

integer

antispoof_udp_all

ow

integer

응답(Response)

IPv4 필터 로그 설정의 저장 요청에 대한 응답(Response)은 다음과 같습니다.

Response Body

이름

유형

내용

code

integer

  성공: 0

처리 결과(성공, 실패)에 따라 정의된 응답 코드를 제공합니다.

  실패: 실패 원인에 따른 상태 코드, 오류 코드 제공

처리 결과(성공, 실패)에 따라 정의된 메시지를 제공합니다.

message

string

  성공: “ ”(빈값)

  실패: 실패 원인에 따른 메시지 제공

{

    "global_white_list": 1,

    "white_list": 1,

    "global_black_list": 1,

    "black_list": 0,

    "quarantine": 1,

    "antispoof_block": 1,

    "antispoof_authip": 0,

    "httpauth_block": 0,

    "httpauth_authip": 0,

    "segment": 0,

    "unauth": 0,

158

AhnLab DPX REST API Guide

    "stateful": 0,

    "threshold": 0,

    "qos": 0,

    "dnsauth_block": 1,

    "dnsauth_authip": 1,

    "global_quarantine": 1,

    "global_geoip": 0,

    "geoip": 0,

    "global_protocol_anomaly": 0,

    "dns_nxdomain_block": 0,

    "dns_nxdomain_allow": 1,

    "antispoof_udp_block": 0,

    "antispoof_udp_allow": 0

}

159

Chapter 4 법적 고지사항

제품에 대한 법적인 고지사항을 확인합니다.



4.1 고지사항

160

AhnLab DPX REST API Guide

4.1 고지사항

법적 고지사항

안랩, AhnLab, AhnLab DPX는 안랩의 등록상표입니다. 그 외 다른 제품 또는 회사 이름은 해당 소유자의 상표 또

는 등록상표일 수 있습니다.

본 문서의 어떤 부분도 안랩의 서면 동의 없이 복제, 복사, 검색 시스템으로 저장 또는 전송할 수 없습니다. 본 문

서는 기술적 오류나 오타가 포함되어 있을 수 있습니다. 문서에 사용된 제품 화면은 실물과 다를 수 있습니다. 문

서는 오류 수정 및 개선을 위해 사전 통지 없이 변경될 수 있으며, 변경 사항은 새 문서 버전에 적용됩니다. 본 문

서는 제품이 사용자의 사용 환경에 적합함을 보증하지 않습니다.

안랩은 사전 통지 없이 본 문서에 언급된 제품의 규격 및 외관, 기능을 개선 및 변경할 수 있습니다. 안랩 및 제품

구입처는 본 제품의 부적절한 사용과 조작으로 인한 상해를 포함하여, 우발적인 손상 또는 기타 손상에 대해 책

임을 지지 않습니다.

정보통신기기 인증규칙 준수

방송통신기자재등의 적합성평가(KC)

A급 기기(업무용 방송통신기자재)

이 기기는 업무용(A급) 전자파적합기기로서 판매자 또는 사용자는 이 점을 주의하시기 바라며, 가정외의 지역에

서 사용하는 것을 목적으로 합니다.

미국연방통신위원회 인증규칙 준수(FCC Part 15)

Class A device

This equipment has been tested and found to comply with the limits for a Class A digital device, pursuant to

Part  15  of  the  FCC  Rules.  These  limits  are  designed  to  provide  reasonable  protection  against  harmful

interference when the equipment is operated in a commercial environment. This equipment generates, uses,

and can radiate radio frequency energy, and if it is not installed and used in accordance with the instruction

manual,  it  may  cause  harmful  interference  to  radio  communications.  Operation  of  this  equipment  in  a

residential area is likely to cause harmful interference, in which case the user will be required to correct the

interference at his own expense.

Changes or modifications not expressly approved by the manufacturer responsible for compliance could void

the user’s authority to operate the equipment.

161

㈜안랩

경기도 성남시 분당구 판교역로 220  (우) 13493

대표전화 : 031-722-8000  |  구매문의 : 1588-3096  |  전용 상담전화 : 1577-9431  |  팩스 : 031-722-8901

www.ahnlab.com

© 2024 AhnLab, Inc. All rights reserved.

www.ahnlab.com

www.facebook.com/AhnLabSP

www.youtube.com/user/OfficialAhnLab

