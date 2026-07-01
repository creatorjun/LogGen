AhnLab TrusGuard Open API 가이드

일러두기

© 2020 AhnLab, Inc. All rights reserved.

Open API 가이드의 내용은 저작권법과 컴퓨터프로그램보호법에 의해서 보호 받고 있습니다.

AhnLab TrusGuard 의 Open API를 사용하기 위한 설명을 합니다.

법적 고지사항

안랩, AhnLab 로고, AhnLab TrusGuard는 안랩의 등록상표입니다. 그 외 다른 제품 또는 회사 이름은 해 당 소유자의 상표 또는 등록 상표일 수 있습니다.

본 문서의 어떤 부분도 안랩의 서면 동의 없이 복제, 복사, 검색 시스템으로 저장 또는 전송할 수 없습니다.
Open API 가이드의 내용은 현재 제품을 기준으로 작성되었습니다.

㈜안랩은 지금도 새로운 기능을 추가 보 완하고 있으며 향후에도 지속적으로 새로운 기술을 적용할 것입니다.

제품의 모든 기능은 보안, 버그 수정 등의 이유로 사전 통보 없이 변경될 수 있으며, Open API가이드 설명 내용과 일부 다른 부분이 있을 수 있습니다.

대상 독자

이 문서는 AhnLab TrusGuard를 구매하고 Open API를 통해 연동 개발을 하는 사용자에게  API에 대한 이해를 돕기 위해 작성되었습니다.

문서 버전

2020-08-001

© AhnLab, Inc. All rights reserved.

Page 1 of 92

차례

일러두기

법적 고지사항
대상 독자
문서 버전

차례
공통 설정

REST API Status Code
REST API 동작 방식
Token 발급
사용자 인증

객체

IPv4 주소 객체
IPv4 주소 그룹 객체
FQDN 주소 객체
FQDN 주소 그룹 객체
서비스 객체
서비스 그룹 객체
사용자 주소 객체
사용자 주소 그룹 객체
일정 객체
QoS 객체

정책

IPv4 정책
인터페이스 기반 NAT
정책 기반 NAT
IPv4 정책 예외
IPv4 차단 대상
세션 조회

기타

장비 조회
미사용 객체 조회
정책 적용

© AhnLab, Inc. All rights reserved.

Page 2 of 92

공통 설정

REST API Status Code

1.

REST API Status Code

Code

Status

설명

200

OK

서버가 요청을 제대로 처리했다는 뜻입니다.

401

Unauthorized

인증이 필요한 페이지 입니다.

404

Page Not Found

요청한 페이지를 찾을 수 없습니다.

423

Locked

접근하려는 리소스가 잠겨있습니다.

500

Internal Server error 서버에 오류가 발생하여 요청을 처리할 수 없습니다.

101

RET_INVAL

입력 인자 오류입니다.
ex. IP 범위를 벗어난 경우

102

RET_NOENT

대상이 존재하지 않움에 대한 오류 입니다.
ex. 입력받은 객체명이 존재하지 않는 경우

103

RET_EXIST

대상이 이미 존재함 오류 입니다.
ex. 추가하려는 대상이 이미 존재하는 경우

104

RET_NOSPC

최대 개수 초과의 오류 입니다.
ex. 객체 추가 시 최대 개수를 초과하여 추가가 불가한 경우

105

RET_PERM

허용되지 않는 동작(동작 수행 불가 및 권한없음)의 오류 입니다.
ex. tms에서 사용중인 객체 정보를 변경하려고 하는 경우

106

RET_ACCES

허용되지 않는 대상(접근대상 권한없음)의 오류 입니다.
ex. 사용하고자 하는 nif의 모드가 해당 기능에서 사용 불가능한 경우

107

RET_NOMEM

메모리 부족 오류 입니다.
ex. 메모리가 부족하여 Allocation 할 수 없는 경우

108

RET_IO

입출력 오류(IO Error)입니다.
ex. 내부 모듈 간 통신 중 에러 발생한 경우

109

110

RET_NOSYS

존재하지 않는 명령입니다.

RET_UNKNOWN

알 수 없는 오류입니다.

REST API 동작 방식

해당 페이지는 TG 2.7.4H14에 추가되는 Login/Logout 기능을 반영한 문서입니다.

인증

TG REST API 기능은 OAuth2 인증을 기반으로 동작합니다.
제공되는 모든 REST API는 인증 토큰이 필요하며 해당 내용은 공통 설정 > Token 발급 항목을 참조하시기 바랍니다.
인증 토큰의 만료 시간은 10분으로 로그인 중이라도 인증 토큰 시간이 만료되면 토큰을 재발급 받으셔야 합니다.

로그인 동작 방식

REST API 사용자는 인증된 토큰으로 로그인을 할 수 있습니다.
REST API 사용자가 로그인 되어 있는 동안 다른 쓰기 관리자가 접속할 수 없습니다.
마찬가지로 다른 쓰기 관리자가 장비에 접속 중(WebUI)인 경우에는 REST API 사용자가 로그인 할 수 없습니다.
로그인 유지 시간은 관리자 웹 화면 세션 타임아웃시간과 같습니다. (System 메뉴의 접속 관리에서 확인 가능)

REST API 사용시 유의사항

REST API의 단일 객체 조회, 수정, 삭제 시 PATH에 한글 및 특수 문자가 들어갈 경우 URI_ENCODING이 필요합니다.
다만 이름에 '/'가 들어간 객체의 경우 보안상의 이유로 URI_ENCODING 을 지원하지 않기 때문에 조회, 수정, 삭제를 하실 수 없습니다.
조회시 offset과 limit 값에 올바르지 않은 숫자가 입력되지 않을 경우 기본값으로 대체됩니다.

본 REST API를 사용하기 위해서는 TrusGuard 제품의 관리자 동시 접속 정책 설정(admuser_restrict_write)이 "2"로  되어 있어야 합니다.

© AhnLab, Inc. All rights reserved.

Page 3 of 92

Token 발급

1) Token 발급
2) REST API 공통

1) Token 발급

Request URL: https://<TG_IP>:50005/restapi/accessToken
Method: POST
Path parameter

None
Query parameters
None

Header

Basic 인증 방식으로 Client ID와 Secret Key 필요
Authorization 필드에 Basic base64encode(clientId:secretKey)
content-type: application/json

name

Header

value

name

description

value

clientId

제품 번호

제품번호 (dash로 이어진 16자리 숫자)

System > 라이선스 탭에서 확인

secretKey 장비 아이디 장비 아이디 (6자리 alphnumeric)

System > 라이선스 탭에서 확인

-
Request

name

body

value

name

type

require

description

validation

grant_type string

username

string

password

string

Y

Y

Y

인증 방식

"password" 고정

사용자 ID

관리자 계정

IP 주소 타입

관리자 패스워드

-
Response

하위 예시 참조

예시

요청 Header 예시

Content-Type:"application/json"
Authorization:"Basic NDc1NDAwMzAtNDA1NjIwODI6NjEzYzlm"

요청 예시

{
        "grant_type":"password",
        "username":"testuser",
        "password":"xxxxx"
}

인증 성공시 응답 예시

{
        "access_token": "9ab8c75be576c1664c3a11060e33bd3a575c7614",
    "expires_in": 600,
    "token_type": "Bearer",
    "scope": null,
    "refresh_token": "ff2bffcb696352b0885685b18595cf6253c7e80d""
}

© AhnLab, Inc. All rights reserved.

Page 4 of 92

계정 조회 실패 시 응답 예시

{
        "code":401,
        "message":"ID   ."
}

인증 실패시 응답 예시

{
        "error": "invalid_client",
    "error_description": "The client credentials are invalid"
}

2) REST API 공통

REST API 호출 시 발급된 Token을 Header에 넣어 주어야 합니다.
Header

value

name

value

description

Authorization "Bearer 발급된 accessToken"

Bearer와 발급된 access  Token사이 공백

name

Header

-
예시

요청 Header 예시

Authorization:"Bearer 3103e5970f9345d45c6de4ab1e0485a2641f5dc3"

사용자 인증

1)Token 발급
2) REST API 공통
3) 로그인
4) 로그아웃

해당 페이지는 TG 2.7.4H14에 추가되는 Login/Logout 기능을 반영한 문서입니다.

1)Token 발급

Request URL: https://<TG_IP>:50005/restapi/accessToken
Method  : POST
Path parameter

None
Query parameters
None

Header

Basic 인증 방식으로 Client ID와 Secret Key 필요
Authorization 필드에 Basic base64encode(clientId:secretKey)
content-type: application/json

name

Header

value

name

value

description

clientId

제품 번호

제품번호 (dash로 이어진 16자리 숫자)

System > 라이선스 탭에서 확인

secretKey 장비 아이디 장비 아이디 (6자리 alphnumeric)

System > 라이선스 탭에서 확인

© AhnLab, Inc. All rights reserved.

Page 5 of 92

-
Request

name

body

value

name

type

require

description

validation

grant_type string

username

string

password

string

Y

Y

Y

인증 방식

"password" 고정

사용자 ID

관리자 계정

IP 주소 타입

관리자 패스워드

-
Response

하위 예시 참조

예시

요청 Header 예시

Content-Type:"application/json"
Authorization:"Basic NDc1NDAwMzAtNDA1NjIwODI6NjEzYzlm"

요청 예시

{
        "grant_type":"password",
        "username":"testuser",
        "password":"xxxxx"
}

인증 성공시 응답 예시

{
        "access_token": "9ab8c75be576c1664c3a11060e33bd3a575c7614",
    "expires_in": 600,
    "token_type": "Bearer",
    "scope": null,
    "refresh_token": "ff2bffcb696352b0885685b18595cf6253c7e80d""
}

계정 조회 실패 시 응답 예시

{
        "code":401,
        "message":"ID   ."
}

인증 실패시 응답 예시

{
        "error": "invalid_client",
    "error_description": "The client credentials are invalid"
}

2) REST API 공통

REST API 호출 시 발급된 Token을 Header에 넣어 주어야 합니다.
Header

name

Header

value

name

value

description

Authorization "Bearer 발급된 accessToken"

Bearer와 발급된 access  Token사이 공백

© AhnLab, Inc. All rights reserved.

Page 6 of 92

-
예시

요청 Header 예시

Authorization:"Bearer 3103e5970f9345d45c6de4ab1e0485a2641f5dc3"

3) 로그인

Request URL: https://<TG_IP>:50005/restapi/login
Method  : GET
Path parameter

None
Query parameters
None

Header

Authorization 필드에 Bearer 발급된 accessToken

value

name

value

description

Authorization "Bearer 발급된 accessToken"

Bearer와 발급된 access  Token사이 공백

name

Header

Request

None

Response

name

value

 description

Status Code

실패 시 에러 메시지

code

integer

message

string

예시

로그인 성공 시 응답

{
        "code":200,
        "message":" ."
}

로그인 실패 시 응답

{
        "code":401,
        "message":" ."
}

4) 로그아웃

Request URL: https://<TG_IP>:50005/restapi/logout
Method  : GET
Path parameter

None
Query parameters
None

Header

Authorization 필드에 Bearer 발급된 accessToken

value

name

value

description

Authorization "Bearer 발급된 accessToken"

Bearer와 발급된 access  Token사이 공백

name

Header

Request

None

© AhnLab, Inc. All rights reserved.

Page 7 of 92

Response

name

value

 description

Status Code

실패 시 에러 메시지

code

integer

message

string

예시

인증 성공시 응답 예시

{
        "code":200,
        "message":" ."

}

객체

IPv4 주소 객체

1) IPv4 주소 객체 목록 조회
2) IPv4 주소 객체 조회
3) IPv4 주소 객체 추가
4) IPv4 주소 객체 수정
5) IPv4 주소 객체 삭제

1) IPv4 주소 객체 목록 조회

Request URL : https://<TG_IP>:50005/restapi/object/address/ipv4
Method : GET
Path parameter

None
Query parameters
offset/limit

name

value

description

offset

integer

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대값 : 2000

예시 : https://<TG_IP>:50005/restapi/object/address/ipv4?offset=10&limit=20

Request

None

Response

name

value

description

code

integer

total

integer

Status Code

조회 결과 총 갯수

© AhnLab, Inc. All rights reserved.

Page 8 of 92

objects

name

value

description

name

type

ip

mask

nif

desc

zone

객체 이름

IPv4 형식

0 : Host
1 : Network
2 : Range

IP

mask

인터페이스

설명

internal
external
dmz
ha
all (default)

message

string

실패 시 에러 메시지

-
예시

{
        "code":200,
        "total":13,
        "objects":[
                {
                "name":"addr_",
                        "type":"0",
                 "ip":"10.10.1.1",
                        "mask":"32",
                        "nif":"eth0",
                        "desc":"",
                        "zone":"external"
        },
                ....
        ],
        "message":""
}

2) IPv4 주소 객체 조회

Request URL:  https://<TG_IP>:50005/restapi/object/address/ipv4/{name}
Method : GET
Path parameter

name

type

require

description

name

string

Y

검색할 객체 이름

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

© AhnLab, Inc. All rights reserved.

Page 9 of 92

object

name

value

description

name

type

ip

mask

nif

desc

zone

객체 이름

IPv4 형식

0 : Host
1 : Network
2 : Range

IP

mask

인터페이스

설명

internal
external
dmz
ha
all (default)

message

string

실패 시 에러 메시지

-
예시

{
        "code" : 200,
        "objects" :  [
                {
                "name": "addr_",
                        "type": "0",
                 "ip": "10.10.1.1",
                        "mask" : "32",
                        "nif" : "eth0",
                        "desc" : "",
                        "zone": "external"
        }
        ],
        "message" : ""
}

3) IPv4 주소 객체 추가

Request URL:  https://<TG_IP>:50005/restapi/object/address/ipv4
Method : POST
Path parameter

None
Query parameters
None

Request

name

body

value

name

type

require

description

validation

name

string

type

string

ip

string

mask

string

nif

string

desc

string

zone

string

Y

Y

Y

N

N

N

N

객체 이름

IP 주소 타입

IP 주소

CIDR

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

0 : Host(IPv4)
1 : Network(IPv4/CIDR)
2 : Range(1stIP-LastIP)

IPv4 형식,1stIP-LastIP

0 ~ 32
Host IP일 경우 32(기본값)
Range IP는 무의미

인터페이스

빈값일 경우 all로 설정

설명

Zone

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

internal
external
dmz
ha
all (default)

-

© AhnLab, Inc. All rights reserved.

Page 10 of 92

Response

name

value

 description

code

integer

message

string

Status Code

실패 시 에러 메시지

-
예시

요청 예시

{
        "name": "addr_",
        "type": "0",
        "ip": "10.10.1.1",
        "mask": "32",
        "nif" : "eth0",
    "desc": "",
        "zone": "external"
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

4) IPv4 주소 객체 수정

Request URL:  https://<TG_IP>:50005/restapi/object/address/ipv4/{orgName}
Method : PUT
Path parameter

name

orgName

type

string

require

description

Y

변경전 객체 이름

-
Query parameters
None

Request

name

body

value

name

type

description

validation

name

string

객체 이름

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

type

string

IP 주소 타입

0 : Host(IPv4)
1 : Network(IPv4/CIDR)
2 : Range(1stIP-LastIP)

ip

string

IP 주소

IPv4 형식,1stIP-LastIP

mask

string

CIDR

0 ~ 32
Host IP일 경우 32(기본값)
Range IP는 무의미

nif

string

인터페이스

빈값일 경우 all로 설정

desc

string

설명

zone

string

Zone

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

internal
external
dmz
ha
all (default)

-
Response

name

value

description

code

integer

Status Code

© AhnLab, Inc. All rights reserved.

Page 11 of 92

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
        "name": "addr_",
        "type" : "2",
        "ip": "10.10.1.1-10.10.1.10",
        "mask": "",
        "nif" : "eth1",
    "zone": "internal",
    "desc": ""
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

5) IPv4 주소 객체 삭제

Request URL:  https://<TG_IP>:50005/restapi/object/address/ipv4/{name}
Method : DELETE
Path parameter

type

string

require

description

Y

삭제할 객체 이름

name

name

Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

IPv4 주소 그룹 객체

1) IPv4 주소 그룹 객체 목록 조회
2) IPv4 주소 그룹 객체 조회
3) IPv4 주소 그룹 객체 추가
4) IPv4 주소 그룹 객체 수정
5) IPv4 주소 그룹 객체 삭제

1) IPv4 주소 그룹 객체 목록 조회

Request URL: https://<TG_IP>:50005/restapi/object/address/ipv4Group
Method : GET
Path parameter

None
Query parameters

offset/limit

name

value

description

© AhnLab, Inc. All rights reserved.

Page 12 of 92

offset

integer

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대값 : 2000

예시 : https://<TG_IP>:50005/restapi/object/address/ipv4Group?offset=10&limit=20

Request

None

Response

name

value

code

integer

total

integer

objects

name

type

value

description

description

Status Code

조회 결과 건수

name

그룹 객체 이름

members

array(object)

 IPv4 주소 객체 이름 목록

desc

설명

message string

실패 시 에러 메시지

-
예시

{
        "code" : 200,
        "total" : 5,
        "objects" :  [
                {
                "name": "tg_agrp1",
            "members": [
                                "10.10.10.x",
                "20.20.20.x"
                        ]
        },
                ....
        ],
        "message" : ""
}

2) IPv4 주소 그룹 객체 조회

Request URL:  https://<TG_IP>:50005/restapi/object/address/ipv4Group/{name}
Method : GET
Path parameter

name

type

require

description

name

string

Y

검색할 객체 이름

-
Query parameters
None

Request

None

Response

name

value

code

integer

object

name

type

value

description

description

Status Code

name

그룹 객체 이름

members

array(object)

 IPv4 주소 객체 이름 목록

desc

설명

message string

실패 시 에러 메시지

© AhnLab, Inc. All rights reserved.

Page 13 of 92

-
예시

{
        "code" : 200,
        "objects" :  [
                {
                "name": "tg_agrp1",
            "members": [
                                "10.10.10.x",
                "20.20.20.x"
                        ]
        }
        ],
        "message" : ""
}

3) IPv4 주소 그룹 객체 추가

Request URL: https://<TG_IP>:50005/restapi/object/address/ipv4Group
Method : POST
Path parameter

None
Query parameters
None

Request

value

name

type

require

description

validation

name

string

members array(object)

desc

string

Y

Y

N

객체 이름

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

IPv4 주소 객체 이름 목록

최대 500개

설명

최대 길이: 255bytes

name

body

-
Response

name

value

description

code

integer

message

string

Status Code

실패 시 에러 메시지

-
예시

요청 예시

{
        "name": "address_group",
    "members": [
            "1",
        "2"
        ],
    "desc" : "rest call"
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

4) IPv4 주소 그룹 객체 수정

Request URL:  https://<TG_IP>:50005/restapi/object/address/ipv4Group/{orgName}

© AhnLab, Inc. All rights reserved.

Page 14 of 92

Method : PUT
Path parameter

name

orgName

type

string

require

description

Y

변경전 객체 이름

-
Query parameters
None

Request

value

name

type

description

validation

name

string

객체 이름

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

members array(object)

IPv4 주소 객체 이름 목록

최대 500개

desc

string

설명

최대 길이: 255bytes

name

body

-
Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
        "name": "address_group",
    "members": [
            "2",
        "4"
        ],
    "desc" : "rest call "
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

5) IPv4 주소 그룹 객체 삭제

Request URL:  https://<TG_IP>:50005/restapi/object/address/ipv4Group/{name}
Method : DELETE
Path parameter

name

name

type

string

require

description

Y

삭제할 객체 이름

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

© AhnLab, Inc. All rights reserved.

Page 15 of 92

message

string

실패 시 에러 메시지

FQDN 주소 객체

1) FQDN 주소 객체 목록 조회
2) FQDN 주소 객체 조회
3) FQDN 주소 객체 추가
4) FQDN 주소 객체 수정
5) FQDN 주소 객체 삭제

1) FQDN 주소 객체 목록 조회

Request URL: https://<TG_IP>:50005/restapi/object/fqdn/fqdn
Method : GET
Path parameter

None
Query parameters
offset/limit

name

value

description

offset

integer

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대값 : 2000

예시 : https://<TG_IP>:50005/restapi/object/fqdn/fqdn?offset=10&limit=20

Request

None

Response

name

value

code

integer

count

integer

description

Status Code

조회 결과 건수

objects

name

value

description

name

fqdn

subDomain

zone

객체 이름

도메인 주소

서브도메인 지원
true : 사용
false : 사용안함

internal
external
dmz
ha
all (default)

nif

인터페이스

autoCollection

IP 자동 수집

true : 사용
false : 사용안함

desc

설명

message

string

실패 시 에러 메시지

-
예시

© AhnLab, Inc. All rights reserved.

Page 16 of 92

{
        "code" : 200,
        "count" : 4
        "objects" :  [
                {
                        "name": "_01",
                        "fqdn": "www.xxx.com",
            "subDomain": true,
                        "zone" : "external",
                        "nif" : "eth0",
            "autoCollection": true,
                        "desc" : ""
        },
                ....
        ],
        "message" : ""
}

2) FQDN 주소 객체 조회

Request URL:  https://<TG_IP>:50005/restapi/object/fqdn/fqdn/{name}
Method : GET
Path parameter

name

type

require

description

name

string

Y

검색할 객체 이름

-
Query parameters
None

Request

None

Response

name

value

code

integer

description

Status Code

object

name

value

description

name

fqdn

subDomain

zone

객체 이름

도메인 주소

서브도메인 지원
true : 사용
false : 사용안함

internal
external
dmz
ha
all (default)

nif

인터페이스

autoCollection

IP 자동 수집

true : 사용
false : 사용안함

desc

설명

message

string

실패 시 에러 메시지

-
예시

© AhnLab, Inc. All rights reserved.

Page 17 of 92

{
        "code" : 200,
        "objects" :  [
                {
                "name": "_01",
                        "fqdn": "www.xxx.com",
            "subDomain": true,
                        "zone" : "external",
                        "nif" : "eth0",
            "autoCollection": true,
                        "desc" : ""
        }
        ],
        "message" : ""
}

3) FQDN 주소 객체 추가

Request URL:  https://<TG_IP>:50005/restapi/object/fqdn/fqdn
Method : POST
Path parameter

None
Query parameters
None

Request

name

body

value

name

type

require

description

validation

name

string

fqdn

string

subDomain

boolean

 zone

string

nif

string

autoCollection boolean

desc

string

Y

Y

N

N

N

N

N

객체 이름

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

도메인 주소

URL

www로 시작하는 URL 주소

최대 길이: 127bytes

서브도메인 지원

true : 사용
false : 사용안함(기본값)

Zone

internal
external
dmz
ha
all (default)

인터페이스

빈값일 경우 all로 설정

IP 자동 수집

true : 사용(기본값)
false : 사용안함

설명

최대 길이: 255bytes

-
Response

name

value

description

code

integer

message

string

Status Code

실패 시 에러 메시지

-
예시

요청 예시

{
        "name": "_01",
    "fqdn": "www.xxx.com",
    "subDomain": true,
        "zone" : "external",
        "nif" : "eth0",
    "autoCollection": true,
    "desc": "rest call"
}

© AhnLab, Inc. All rights reserved.

Page 18 of 92

응답 예시

{
        "code" : 200,
        "message" : ""
}

4) FQDN 주소 객체 수정

Request URL :  https://<TG_IP>:50005/restapi/object/fqdn/fqdn/{orgName}
Method : PUT
Path parameter

name

orgName

type

string

require

description

Y

변경전 객체 이름

-
Query parameters
None

Request

name

body

value

name

type

description

validation

name

string

객체 이름

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

fqdn

string

도메인 주소

URL

subDomain

boolean 서브도메인 지원

 zone

string

Zone

www로 시작하는 URL 주소

최대 길이: 127bytes

true : 사용
false : 사용안함(기본값)

internal
external
dmz
ha
all (default)

nif

string

인터페이스

빈값일 경우 all로 설정

autoCollection boolean IP 자동 수집

true : 사용(기본값)
false : 사용안함

desc

string

설명

최대 길이: 255bytes

-
Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
        "name": "_01_",
    "fqdn": "www.test001.com",
    "subDomain": false,
        "zone" : "internal",
        "nif" : "eth1",
    "autoCollection": false,
    "desc": "rest call "
}

© AhnLab, Inc. All rights reserved.

Page 19 of 92

응답 예시

{
        "code" : 200,
        "message" : ""
}

5) FQDN 주소 객체 삭제

Request URL :  https://<TG_IP>:50005/restapi/object/fqdn/fqdn/{name}
Method : DELETE
Path parameter

name

name

type

string

require

description

Y

삭제할 객체 이름

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

FQDN 주소 그룹 객체

1) FQDN 주소 그룹 객체 목록 조회
2) FQDN 주소 그룹 객체 조회
3) FQDN 주소 그룹 객체 추가
4) FQDN 주소 그룹 객체 수정
5) FQDN 주소 그룹 객체 삭제

1) FQDN 주소 그룹 객체 목록 조회

Request URL: https://<TG_IP>:50005/restapi/object/fqdn/fqdnGroup
Method : GET
Path parameter

None
Query parameters
offset/limit

name

value

description

offset

integer

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대값 : 2000

예시 : https://<TG_IP>:50005/restapi/object/fqdn/fqdnGroup?offset=10&limit=20

Request

None

Response

name

value

code

integer

description

Status Code

© AhnLab, Inc. All rights reserved.

Page 20 of 92

count

integer

objects

name

type

value

description

조회 결과 건수

name

그룹 객체 이름

members

array(object)

도메인주소 객체 이름 목록

desc

설명

message string

실패 시 에러 메시지

-
예시

{
        "code" : 200,
        "count" 2,
        "objects" :  [
                {
                        "name": "",
            "members": [
                    "_01",
                "_02"
                        ],
                        "desc": ""
        },
                ....
        ],
        "message" : ""
}

2) FQDN 주소 그룹 객체 조회

Request URL:  https://<TG_IP>:50005/restapi/object/fqdn/fqdnGroup/{name}
Method : GET
Path parameter

name

type

require

description

name

string

Y

검색할 객체 이름

-
Query parameters
None

Request

None

Response

name

value

code

integer

object

name

type

value

description

description

Status Code

name

그룹 객체 이름

members

array(object)

도메인주소 객체 이름 목록

desc

설명

message string

실패 시 에러 메시지

-
예시

© AhnLab, Inc. All rights reserved.

Page 21 of 92

{
        "code" : 200,
        "objects" :  [
                {
                "name": "",
            "members": [
                    "_01",
                "_02"
                        ],
                        "desc": ""
        }
        ],
        "message" : ""
}

3) FQDN 주소 그룹 객체 추가

Request URL:  https://<TG_IP>:50005/restapi/object/fqdn/fqdnGroup
Method : POST
Path parameter

None
Query parameters
None

Request

value

name

type

require

description

validation

name

string

members array(object)

desc

string

Y

Y

N

객체 이름

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

도메인주소 객체 이름 목록

최대 500개

설명

최대 길이: 255bytes

name

body

-
Response

name

value

description

code

integer

message

string

Status Code

실패 시 에러 메시지

-
예시

요청 예시

{
        "name": "_01",
        "members": [
            "_01",
        "_02"
        ],
    "desc" : "rest call"
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

4) FQDN 주소 그룹 객체 수정

Request URL:  https://<TG_IP>:50005/restapi/object/fqdn/fqdnGroup/{orgName}
Method : PUT

© AhnLab, Inc. All rights reserved.

Page 22 of 92

Path parameter

name

orgName

type

string

require

description

Y

변경전 객체 이름

-
Query parameters
None

Request

value

name

type

description

validation

name

string

객체 이름

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

members array(object) 도메인주소 객체 이름 목록

최대 500개

desc

string

설명

최대 길이: 255bytes

name

body

-
Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
        "name": "",
        "members": [
            "_01",
        "_02"
        ],
    "desc" : ""
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

5) FQDN 주소 그룹 객체 삭제

Request URL:  https://<TG_IP>:50005/restapi/object/fqdn/fqdnGroup/{name}
Method : DELETE
Path parameter

name

name

type

string

require

description

Y

삭제할 객체 이름

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

© AhnLab, Inc. All rights reserved.

Page 23 of 92

message

string

실패 시 에러 메시지

서비스 객체

1) 서비스 객체 목록 조회
2) 서비스 객체 조회
3) 서비스 객체 추가
4) 서비스 객체 수정
5) 서비스 객체 삭제

1) 서비스 객체 목록 조회

Request URL : https://<TG_IP>:50005/restapi/object/service/service
Method : GET
Path parameter

None
Query parameters
offset/limit

name

value

description

offset

integer

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대값 : 2000

예시 : https://<TG_IP>:50005/restapi/object/service/service?offset=10&limit=20

Request

None

Response

name

code

integer

count

integer

value

description

Status Code

조회 결과 건수

objects

name

value

description

name

protocol

객체 이름

프로토콜

protonum

프로토콜 번호

프로토콜이 IP일 경우 표시

sport

출발지 포트

프로토콜이 TCP나 UDP일 때 표시

dport

목적지 포트

프로토콜이 TCP나 UDP일 때 표시

type

code

timeout

desc

타입

코드

프로토콜이 ICMP나 ICMPv6일 때 표시

프로토콜이 ICMP나 ICMPv6일 때 표시

타임아웃

설명

message

string

실패 시 에러 메시지

© AhnLab, Inc. All rights reserved.

Page 24 of 92

-
예시

{
        "code" : 200,
        "count: 3,
        "objects" :  [
                 {
                        "name": "svc_01",
                        "protocol": "ip",
            "protonum": "22",
            "timeout": "300"
                },
        {
                "name": "svc_02",
            "protocol": "icmp",
                        "type": "123",
            "code": "215"
                },
        {
                "name": "svc_03",
                        "protocol": "tcp",
            "sport": "1-1,2-2",
            "dport": "20-30",
            "timeout": "1800"
                }
        ],
        "message" : ""
}

2) 서비스 객체 조회

Request URL :  https://<TG_IP>:50005/restapi/object/service/service/{name}
Method : GET
Path parameter

name

type

require

description

name

string

Y

검색할 객체 이름

-
Query parameters
None

Request

None

Response

name

code

integer

value

description

Status Code

© AhnLab, Inc. All rights reserved.

Page 25 of 92

object

name

value

description

name

protocol

객체 이름

프로토콜

protonum

프로토콜 번호

프로토콜이 IP일 경우 표시

sport

출발지 포트

프로토콜이 TCP나 UDP일 때 표시

dport

목적지 포트

프로토콜이 TCP나 UDP일 때 표시

type

code

timeout

desc

타입

코드

프로토콜이 ICMP나 ICMPv6일 때 표시

프로토콜이 ICMP나 ICMPv6일 때 표시

타임아웃

설명

message

string

-
예시

{
        "code" : 200,
        "objects" :  [
                {
                "name": "svc_03",
                        "protocol": "tcp",
            "sport": "1-1,2-2",
            "dport": "20-30",
            "timeout": "1800"
        }
        ],
        "message" : ""
}

3) 서비스 객체 추가

Request URL :  https://<TG_IP>:50005/restapi/object/service/service
Method : POST
Path parameter

None
Query parameters
None

Request

name

value

실패 시 에러 메시지

© AhnLab, Inc. All rights reserved.

Page 26 of 92

body

name

type

require

description

validation

name

string

protocol

string

protonum string

sport

string

dport

string

type

string

code

string

timeout

string

Y

Y

N

N

N

N

N

Y

객체 이름

프로토콜 종류

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

tcp : TCP
udp : UDP
icmp : ICMP
icmpv6 : ICMPV6
ip : IP

프로토콜 번호

프로토콜이 IP일 때 필수 값
0 ~ 255 문자

출발지 포트

목적지 포트

타입

코드

타임아웃

프로토콜이 TCP, UDP 일 때 필수 값
1~65535 범위 형태
ex) 1-20

프로토콜이 TCP, UDP 일 때 필수 값
1~65535 범위 형태
ex) 1-20

프로토콜이 ICMP, ICMPv6 일 때 필수 값
0~255 문자열

프로토콜이 ICMP, ICMPv6 일 때 필수 값
0~255 문자열

TCP : 240 ~ 999999
UDP : 1 ~ 99999
ICMP, ICMPv6 : 1 ~ 99
IP : 1 ~ 99999

desc

string

N

설명

-
Response

name

value

description

code

integer

message

string

Status Code

실패 시 에러 메시지

-
예시

요청 예시

{
        "name": "svc_01",
    "protocol": "tcp",
    "sport": "1-2",
    "dport": "20-30",
    "timeout": 1800,
    "desc" : "TCP "
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

4) 서비스 객체 수정

Request URL :  https://<TG_IP>:50005/restapi/object/service/service/{orgName}
Method : PUT
Path parameter

name

orgName

type

string

require

description

Y

변경전 객체 이름

-
Query parameters
None

Request

© AhnLab, Inc. All rights reserved.

Page 27 of 92

name

body

value

name

type

description

validation

name

string

객체 이름

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

protocol

string

프로토콜 종류

protonum string

프로토콜 번호

sport

string

출발지 포트

dport

string

목적지 포트

type

string

타입

code

string

코드

timeout

string

타임아웃

desc

string

설명

tcp : TCP
udp : UDP
icmp : ICMP
icmpv6 : ICMPV6
ip : IP

프로토콜이 IP일 때 필수 값
0 ~ 255 문자

프로토콜이 TCP, UDP 일 때 필수 값
1~65535 값
범위 형태 가능
최대 16개 (구분자 : ,)
포트 범위 검사

프로토콜이 TCP, UDP 일 때 필수 값
1~65535 값
범위 형태 가능
최대 16개 (구분자 : ,)
포트 범위 검사

프로토콜이 ICMP, ICMPv6 일 때 필수 값
0~255 문자열

프로토콜이 ICMP, ICMPv6 일 때 필수 값
0~255 문자열

TCP : 240 ~ 999999
UDP : 1 ~ 99999
ICMP, ICMPv6 : 1 ~ 99
IP : 1 ~ 99999

-
Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
        "name": "svc_01_m",
    "protocol": "ip",
        "protonum" : "22",
        "timeout": 300,
    "desc" : ""
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

5) 서비스 객체 삭제

Request URL :  https://<TG_IP>:50005/restapi/object/service/service/{name}
Method : DELETE
Path parameter

name

name

type

string

require

description

Y

삭제할 객체 이름

-
Query parameters

© AhnLab, Inc. All rights reserved.

Page 28 of 92

None

Request

None

Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

서비스 그룹 객체

1) 서비스 그룹 객체 목록 조회
2) 서비스 그룹 객체 조회
3) 서비스 그룹 객체 추가
4) 서비스 그룹 객체 수정
5) 서비스 그룹 객체 삭제

1) 서비스 그룹 객체 목록 조회

Request URL: https://<TG_IP>:50005/restapi/object/service/serviceGroup
Method : GET
Path parameter

None
Query parameters
offset/limit

name

value

description

offset

integer

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대값 : 2000

예시 : https://<TG_IP>:50005/restapi/object/service/serviceGroup?offset=10&limit=20

Request

None

Response

name

value

code

integer

count

integer

objects

name

type

value

description

name

그룹 객체 이름

members

array(object)

서비스 객체 이름 목록

desc

설명

description

Status Code

조회 결과 건수

message string

실패 시 에러 메시지

-
예시

© AhnLab, Inc. All rights reserved.

Page 29 of 92

{
        "code" : 200,
        "count" : 15,
        "objects" :  [
                {
                "name": "",
                        "members": [
                    "_01",
                "_02"
                        ],
                        "desc" : ""
        },
                ....
        ],
        "message" : ""
}

2) 서비스 그룹 객체 조회

Request URL:  https://<TG_IP>:50005/restapi/object/service/serviceGroup/{name}
Method : GET
Path parameter

name

type

require

description

name

string

Y

검색할 객체 이름

-
Query parameters
None

Request

None

Response

name

value

code

integer

object

name

type

value

description

description

Status Code

name

그룹 객체 이름

members

array(object)

서비스 객체 이름 목록

desc

설명

message string

실패 시 에러 메시지

-
예시

{
        "code" : 200,
        "objects" :  [
                {
                "name": "",
                        "members": [
                    "_01",
                "_02"
                        ],
                        "desc" : ""
        }
        ],
        "message" : ""
}

3) 서비스 그룹 객체 추가

Request URL:  https://<TG_IP>:50005/restapi/object/service/serviceGroup
Method : POST
Path parameter

None
Query parameters
None

© AhnLab, Inc. All rights reserved.

Page 30 of 92

value

name

type

require

description

validation

name

string

members array(object)

desc

string

Y

Y

N

객체 이름

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

서비스 객체 이름 목록

최대 500개

설명

최대 길이: 255bytes

Request

name

body

-
Response

name

value

description

code

integer

message

string

Status Code

실패 시 에러 메시지

-
예시

요청 예시

{
        "name": "_01",
        "members": [
            "_01",
        "_02"
        ],
    "desc" : "  rest call"
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

4) 서비스 그룹 객체 수정

Request URL:  https://<TG_IP>:50005/restapi/object/service/serviceGroup/{orgName}
Method : PUT
Path parameter

name

orgName

Query parameters
None

Request

type

string

require

description

Y

변경전 객체 이름

value

name

type

description

validation

name

string

객체 이름

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

members array(object) 서비스 객체 이름 목록

최대 500개

desc

string

설명

최대 길이: 255bytes

name

body

-
Response

name

value

description

code

integer

Status Code

© AhnLab, Inc. All rights reserved.

Page 31 of 92

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
        "uuid": "b46a8b1f-6dd2-41b0-8264-3b7e63d6c841",
        "name": "",
        "members": [
            "_01",
        "_02"
        ],
    "desc" : ""
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

5) 서비스 그룹 객체 삭제

Request URL:  https://<TG_IP>:50005/restapi/object/service/serviceGroup/{name}
Method : DELETE
Path parameter

type

string

require

description

Y

삭제할 객체 이름

name

name

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

사용자 주소 객체

1) 사용자 주소 객체 목록 조회
2) 사용자 주소 객체 조회
3) 사용자 주소객체 추가
4) 사용자 주소객체 수정
5) 사용자 주소객체 삭제

1) 사용자 주소 객체 목록 조회

Request URL: https://<TG_IP>:50005/restapi/object/userId/userId
Method : GET
Path parameter

None
Query parameters
offset/limit

name

value

description

© AhnLab, Inc. All rights reserved.

Page 32 of 92

offset

integer

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대값 : 2000

예시 : https://<TG_IP>:50005/restapi/object/userId/userId?offset=10&limit=20

Request

None

Response

name

value

code

integer

count

integer

objects

name

value

description

description

Status Code

조회 결과 건수

name

uid

nif

zone

ip

객체 이름

아이디

인터페이스

internal
external
dmz
ha
all (default)

IPv4 주소 목록
format: array(object)

username

사용자 이름

team

desc

부서

설명

message

string

실패 시 에러 메시지

-
예시

{
        "code" : 200,
        "count: 13,
        "objects" :  [
                {
                        "name": "hkd2020",
            "uid": "2020_k",
                        "nif" : "eth1"
                        "zone": "internal",
            "ip": [
                    "172.20.1.1",
                "192.168.100.1"
                        ],
            "username": "",
            "team": "",
                        "desc" : ""
                },
                ....
        ],
        "message" : ""
}

2) 사용자 주소 객체 조회

Request URL :  https://<TG_IP>:50005/restapi/object/userId/userId/{name}
Method : GET
Path parameter

© AhnLab, Inc. All rights reserved.

Page 33 of 92

name

type

require

description

name

string

Y

검색할 객체 이름

-
Query parameters
None

Request

None

Response

name

value

code

integer

description

Status Code

object

name

value

description

name

uid

nif

zone

ip

객체 이름

아이디

인터페이스

internal
external
dmz
ha
all (default)

IPv4 주소 목록
format: array(object)

username

사용자 이름

team

desc

부서

설명

message

string

실패 시 에러 메시지

-
예시

{
        "code" : 200,
        "objects" :  [
                {
                "name": "hkd2020",
            "uid": "2020_k",
                        "nif" : "eth1"
                        "zone": "internal",
            "ip": [
                    "172.20.1.1",
                "192.168.100.1"
                        ],
            "username": "",
            "team": "",
                        "desc" : ""
        }
        ],
        "message" : ""
}

3) 사용자 주소객체 추가

Request URL :  https://<TG_IP>:50005/restapi/object/userId/userId
Method : POST
Path parameter

None
Query parameters
None

Request

name

value

© AhnLab, Inc. All rights reserved.

Page 34 of 92

body

name

type

require

description

validation

name

string

uid

ip

string

array(object)

nif

zone

string

string

username string

team

desc

string

string

Y

Y

Y

N

N

N

N

N

객체 이름

아이디

IP 주소

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 63bytes

단일 IP
최소 갯수 1개
최대 갯수 10개

인터페이스

빈값일 경우 all로 설정

Zone

internal
external
dmz
ha
all (default)

사용자 이름

최대 길이: 15bytes

부서

설명

최대 길이: 31bytes

최대 길이: 255bytes

-
Response

name

value

description

code

integer

message

string

Status Code

실패 시 에러 메시지

-
예시

요청 예시

{
        "name": "hkd001",
        "uid": "hkd001",
           "ip": [
            "1.1.1.1",
        "2.2.2.2"
    ],
        "nif" : "eth1",
        "zone": "dmz",
    "username": "",
    "team": "",
    "desc": "desc"
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

4) 사용자 주소객체 수정

Request URL:  https://<TG_IP>:50005/restapi/object/userId/userId/{orgName}
Method : PUT
Path parameter

name

orgName

type

string

require

description

Y

변경전 객체 이름

-
Query parameters
None

Request

name

value

© AhnLab, Inc. All rights reserved.

Page 35 of 92

body

name

type

description

validation

uid

ip

string

아이디

array(object)

IP 주소

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 63bytes

단일 IP
최소 갯수 1개
최대 갯수 10개

nif

zone

string

string

인터페이스

빈값일 경우 all로 설정

Zone

internal
external
dmz
ha
all

username string

사용자 이름

최대 길이: 15bytes

team

desc

string

string

부서

설명

최대 길이: 31bytes

최대 길이: 255bytes

-
Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
        "uid": "2020_k",
    "ip": [
            "172.20.1.1",
        "192.168.100.1"
        ],
        "nif" : "eth1",
    "zone": "internal",
    "username": "",
    "team": ""
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

5) 사용자 주소객체 삭제

Request URL:  https://<TG_IP>:50005/restapi/object/userId/userId/{name}
Method : DELETE
Path parameter

name

name

type

string

require

description

Y

삭제할 객체 이름

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

© AhnLab, Inc. All rights reserved.

Page 36 of 92

message

string

실패 시 에러 메시지

사용자 주소 그룹 객체

1) 사용자 주소 그룹 객체 목록 조회
2) 사용자 주소 그룹 객체 조회
3) 사용자 주소 그룹 객체 추가
4) 사용자 주소 그룹 객체 수정
5) 사용자 주소 그룹 객체 삭제

1) 사용자 주소 그룹 객체 목록 조회

Request URL: https://<TG_IP>:50005/restapi/object/userId/userIdGroup
Method : GET
Path parameter

None
Query parameters
offset/limit

name

value

description

offset

integer

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대값 : 2000

예시 : https://<TG_IP>:50005/restapi/object/userId/userIdGroup?offset=10&limit=20

Request

None

Response

name

value

code

integer

count

integer

objects

name

type

value

description

description

Status Code

조회 결과 건수

name

그룹 객체 이름

members

array(object)

사용자 주소 객체 이름 목록

desc

설명

message string

실패 시 에러 메시지

-
예시

{
        "code" : 200,
        "count" : 5,
        "objects" :  [
                {
                "name": "_01",
                        "members": [
                    "uid_01",
                "uid_02"
                        ],
                        "desc" : ""
        },
                ....
        ],
        "message" : ""
}

© AhnLab, Inc. All rights reserved.

Page 37 of 92

2) 사용자 주소 그룹 객체 조회

Request URL:  https://<TG_IP>:50005/restapi/object/userId/userIdGroup/{name}
Method : GET
Path parameter

name

type

require

description

name

string

Y

검색할 객체 이름

-
Query parameters
None

Request

None

Response

name

value

code

integer

object

name

type

value

description

description

Status Code

name

그룹 객체 이름

members

array(object)

 사용자 주소 객체 이름 목록

desc

설명

message string

실패 시 에러 메시지

-
예시

{
        "code" : 200,
        "objects" :  [
                {
                "name": "_01",
                        "members": [
                    "uid_01",
                "uid_02"
                        ],
                        "desc" : ""
        }
        ],
        "message" : ""
}

3) 사용자 주소 그룹 객체 추가

Request URL: https://<TG_IP>:50005/restapi/object/userId/userIdGroup
Method : POST
Path parameter

None
Query parameters
None

Request

value

name

type

require

description

validation

name

string

members array(object)

desc

string

Y

Y

N

객체 이름

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

사용자 주소 객체 이름 목록

최대 500개

설명

최대 길이: 255bytes

name

body

-
Response

name

value

description

code

integer

Status Code

© AhnLab, Inc. All rights reserved.

Page 38 of 92

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
        "name": "Custom_",
    "members": [
            "uid_01",
        "uid_02_m",
        ""
        ],
    "desc" : "rest call test"
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

4) 사용자 주소 그룹 객체 수정

Request URL :  https://<TG_IP>:50005/restapi/object/userId/userIdGroup/{orgName}
Method : PUT
Path parameter

name

orgName

type

string

require

description

Y

변경전 객체 이름

-
Query parameters
None

Request

value

name

type

description

validation

members array(object) 사용자 주소 객체 이름 목록

최대 500개

desc

string

설명

최대 길이: 255bytes

name

body

-
Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
        "members": [
                ""
        ],
    "desc" : "rest call modify"
}

© AhnLab, Inc. All rights reserved.

Page 39 of 92

응답 예시

{
        "code" : 200,
        "message" : ""
}

5) 사용자 주소 그룹 객체 삭제

Request URL :  https://<TG_IP>:50005/restapi/object/userId/userIdGroup/{name}
Method : DELETE
Path parameter

name

name

type

string

require

description

Y

삭제할 객체 이름

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

일정 객체

1) 일정 객체 목록 조회
2) 일정 객체 조회
3) 일정 객체 추가
4) 일정 객체 수정
5) 일정 객체 삭제

1) 일정 객체 목록 조회

Request URL : https://<TG_IP>:50005/restapi/object/schedule/schedule
Method : GET
Path parameter

None
Query parameters
offset/limit

name

value

description

offset

integer

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대값 : 2000

예시 : https://<TG_IP>:50005/restapi/object/schedule/schedule?offset=10&limit=20

Request

None

Response

name

code

integer

value

description

Status Code

© AhnLab, Inc. All rights reserved.

Page 40 of 92

count

integer

조회 결과 건수

objects

name

value

description

name

type

hour_list

sun_hour_list

mon_hour_list

tue_hour_list

wed_hour_list

thr_hour_list

fri_hour_list

sat_hour_list

day_list

month_list

year

begin_date

end_date

객체 이름

1: daily
2: weekly
3: monthly
4: yealy
5: once
6: period

type : daily, monthly, yealy, once의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 일요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 월요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 화요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 수요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 목요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 금요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 토요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : montyly, yealy, once의 일 표시
DD or DD-DD (1-31)
format: array(object)

type : yealy, once의  달 표시
MM or MM-MM (1-12)
format: array(object)

type : once의  년 표시
2000-9999

type : period의 시작 년월일 표시
YYYY-MM-DD

type : period의 종료 년월일 표시
YYYY-MM-DD

schedule_list

type : period의

실행할 일정

 표시

desc

설명

message

string

-
예시

실패 시 에러 메시지

{
        "code" : 200,
        "count: 6,
        "objects" :  [
                {
                        "name": "",
            "type": "1",
                        "hour_list" : [
                                "12:00-13:00", "13:05-14:00","14:05-15:00"
            ],
                        "desc":""
                },
        {

© AhnLab, Inc. All rights reserved.

Page 41 of 92

                        "name": "",
            "type": "2",
                        "sun_hour_list" : [
                                "12:00-13:00","13:05-14:00"
            ],
                        "mon_hour_list" : [
                                "00:00-24:00"
            ],
                        "tue_hour_list" : [
                                "00:00-24:00"
            ],
                        "web_hour_list" : [
                                "12:00-24:00"
            ],
                        "desc":""
                },
                {
                        "name": "",
            "type": "3",
                        "day_list" : [
                                 "1", "3", "4", "5"
                        ],
                        "hour_list": [
                    "12:00-13:00","14:00-15:00"
            ],
                        "desc":""
                },
                {
                "name": "",
            "type": "4",
                        "month_list" : [
                                "1", "4"
                        ],
                        "day_list" : [
                                "24","25","26","27"
                        ],
                        "hour_list": [
                     "12:00-13:00","14:00-15:00"
            ],
                        "desc":""
                },
                {
                        "name": "",
            "type": "5",
                        "year": "2020",
                        "month_list" : [
                                "1-3"
                        ],
                        "day_list" : [
                                "1", "2", "3","4", "9", "10", "11"
                        ],
                        "hour_list": [
                     "12:00-13:00","14:00-15:00"
            ],
                        "desc":""
                },
        {
                "name": "",
            "type": "6",
            "begin_date": "2020-02-28",
            "end_date": "2020-03-06",
            "schedule_list": "",
                        "desc":""
        }
        ],
        "message" : ""
}

2) 일정 객체 조회

Request URL:  https://<TG_IP>:50005/restapi/object/schedule/schedule/{name}
Method : GET
Path parameter

name

type

require

description

name

string

Y

검색할 객체 이름

© AhnLab, Inc. All rights reserved.

Page 42 of 92

-
Query parameters
None

Request

None

Response

name

code

integer

value

description

Status Code

object

name

value

description

name

type

hour_list

sun_hour_list

mon_hour_list

tue_hour_list

wed_hour_list

thr_hour_list

fri_hour_list

sat_hour_list

day_list

month_list

year

begin_date

end_date

객체 이름

1: daily
2: weekly
3: monthly
4: yealy
5: once
6: period

type : daily, monthly, yealy, once의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 일요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 월요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 화요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 수요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 목요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 금요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 토요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : montyly, yealy, once의 일 표시
DD or DD-DD (1-31)

type : yealy, once의  달 표시
MM or MM-MM (1-12)

type : once의  년 표시
2000-9999

type : period의 시작 년월일 표시
YYYY-MM-DD

type : period의 종료 년월일 표시
YYYY-MM-DD

schedule_list

type : period의

실행할 일정

 표시

desc

설명

message

string

-
예시

실패 시 에러 메시지

© AhnLab, Inc. All rights reserved.

Page 43 of 92

{
        "code" : 200,
        "objects" :  [
                {
                        "name": "",
            "type": "5",
                        "year": "2020",
                        "month_list" : [
                                "1-3"
                        ],
                        "day_list" : [
                                "1","2","3","4","9","10","11"
                        ],
                        "hour_list": [
                     "12:00-13:00","14:00-15:00"
            ],
                        "desc":""
        }
        ],
        "message" : ""
}

3) 일정 객체 추가

Request URL:  https://<TG_IP>:50005/restapi/object/schedule/schedule
Method : POST
Path parameter

None
Query parameters
None

Request

name

value

© AhnLab, Inc. All rights reserved.

Page 44 of 92

body

name

type

require

description

validation

name

string

type

string

hour_list

array(object)

sun_hour_list

array(object)

mon_hour_list

array(object)

tue_hour_list

array(object)

wed_hour_list

array(object)

thr_hour_list

array(object)

fri_hour_list

array(object)

sat_hour_list

array(object)

day_list

array(object)

month_list

array(object)

year

string

begin_date

string

end_date

string

schedule_list

array(string)

desc

string

Y

Y

Y

N

N

N

N

N

N

N

N

N

N

N

N

N

N

객체 이름

일정 타입

시간

일요일 시간

월요일 시간

화요일 시간

수요일 시간

목요일 시간

금요일 시간

토요일 시간

일

월

년

시작년월일

종료년월일

일정

설명

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 15bytes

1: daily
2: weekly
3: monthly
4: yealy
5: once
6: period

type : daily, monthly, yealy, once의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 일요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 월요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 화요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 수요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 목요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 금요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 토요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : montyly, yealy, once의 일 표시
DD or DD-DD (1-31)
format: array(object)

type : yealy, once의  달 표시
MM or MM-MM (1-12)
format: array(object)

type : once의  년 표시
2000-9999

type : period의 시작 년월일 표시
YYYY-MM-DD

type : period의 종료 년월일 표시
YYYY-MM-DD

type : period의
format: array(object)

실행할 일정

 표시

-
Response

name

value

description

code

integer

message

string

Status Code

실패 시 에러 메시지

-
예시

요청 예시

{
        "name": "",
    "type": "6",
    "begin_date": "2020-02-28",
    "end_date": "2020-03-06",
    "schedule_list": ["","once"],
        "desc":""
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

© AhnLab, Inc. All rights reserved.

Page 45 of 92

4) 일정 객체 수정

Request URL:  https://<TG_IP>:50005/restapi/object/schedule/schedule/{orgName}
Method : PUT
Path parameter

name

orgName

type

string

require

description

Y

변경전 객체 이름

-
Query parameters
None

Request

name

body

value

name

type

description

validation

name

string

객체 이름

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 15bytes

type

string

일정 타입

1: daily
2: weekly
3: monthly
4: yealy
5: once
6: period

hour_list

array(object) 시간

type : daily, monthly, yealy, once의 시간 표시
HH:MM-HH:MM
format: array(object)

sun_hour_list

array(object) 일요일 시간

mon_hour_list array(object) 월요일 시간

tue_hour_list

array(object) 화요일 시간

wed_hour_list

array(object) 수요일 시간

thr_hour_list

array(object) 목요일 시간

fri_hour_list

array(object) 금요일 시간

sat_hour_list

array(object) 토요일 시간

day_list

array(object) 일

month_list

array(object) 월

year

string

년

begin_date

string

시작년월일

end_date

string

종료년월일

schedule_list

array(string) 일정

desc

string

설명

type : weekly일 때 일요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 월요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 화요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 수요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 목요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 금요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : weekly일 때 토요일의 시간 표시
HH:MM-HH:MM
format: array(object)

type : montyly, yealy, once의 일 표시
DD or DD-DD (1-31)

type : yealy, once의  달 표시
MM or MM-MM (1-12)

type : once의  년 표시
2000-9999

type : period의 시작 년월일 표시
YYYY-MM-DD

type : period의 종료 년월일 표시
YYYY-MM-DD

type : period의
array(string)

실행할 일정

 표시

-
Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

-
예시

© AhnLab, Inc. All rights reserved.

Page 46 of 92

요청 예시

{
        "name": "",
    "type": "3",
        "day_list" : [
                 "1", "3", "4", "5"
        ],
        "hour_list": [
               "12:00-13:00","14:00-15:00"
    ],
        "desc":""
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

5) 일정 객체 삭제

Request URL:  https://<TG_IP>:50005/restapi/object/schedule/schedule/{name}
Method : DELETE
Path parameter

name

name

type

string

require

description

Y

삭제할 객체 이름

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

QoS 객체

1) QoS 객체 목록 조회
2) QoS 객체 조회
3) QoS 객체 추가
4) QoS 객체 수정
5) QoS 객체 삭제

1) QoS 객체 목록 조회

Request URL : https://<TG_IP>:50005/restapi/object/qos/qos
Method : GET
Path parameter

None
Query parameters

offset/limit

name

value

description

© AhnLab, Inc. All rights reserved.

Page 47 of 92

offset

integer

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대 2000

예시 : https://<TG_IP>:50005/restapi/object/qos/qos?offset=1&limit=20

Request

None

Response

name

value

code

integer

total

integer

objects

name

value

description

description

Status Code

조회 결과 총 갯수

name

객체 이름

minBandwidth

최소 대역폭(kbps)

maxBandwidth

최대 대역폭(kbps)

priority

우선순위

1: 가장높음(HIGHEST)
2: 매우 높음(HIGHER)
3: 높음(HIGH)
4 : 보통(NORMAL)
5: 낮음(LOW)
6: 매우 낮음(LOWER)
7: 가장 낮음(LOWEST)

method

작동 방식

0: 정책 공유
1:개별 할당

desc

설명

message

string

실패 시 에러 메시지

-
예시

{
        "code" : 200,
        "total: 13,
        "objects" :  [
                {
                        "name":"qos_test",
                        "minBandwidth":"123456",
                        "maxBandwidth":"654321",
                        "priority":"2",
                        "desc":"rest test",
                        "method":"1"
        },
                ....
        ],
        "message" : ""
}

2) QoS 객체 조회

Request URL:  https://<TG_IP>:50005/restapi/object/qos/qos/{name}
Method : GET
Path parameter

name

type

require

description

name

string

Y

검색할 객체 이름

© AhnLab, Inc. All rights reserved.

Page 48 of 92

-
Query parameters
None

Request

None

Response

name

value

code

integer

description

Status Code

object

name

value

description

name

객체 이름

minBandwidth

최소 대역폭(kbps)

maxBandwidth

최대 대역폭(kbps)

priority

우선순위

1: 가장높음(HIGHEST)
2: 매우 높음(HIGHER)
3: 높음(HIGH)
4 : 보통(NORMAL)
5: 낮음(LOW)
6: 매우 낮음(LOWER)
7: 가장 낮음(LOWEST)

method

작동 방식

0: 정책 공유
1:개별 할당

desc

설명

message

string

실패 시 에러 메시지

-
예시

{
        "code" : 200,
        "objects" :  [
                {
                "name":"qos_test",
                        "minBandwidth":"123456",
                        "maxBandwidth":"654321",
                        "priority":"2",
                        "desc":"rest test",
                        "method":"1"
        }
        ],
        "message" : ""
}

3) QoS 객체 추가

Request URL:  https://<TG_IP>:50005/restapi/object/qos/qos
Method : POST
Path parameter

None
Query parameters
None

Request

name

value

© AhnLab, Inc. All rights reserved.

Page 49 of 92

body

name

type

require

description

validation

name

string

minBandwidth

string

maxBandwidth string

Y

Y

Y

객체 이름

최소 대역폭

최대 대역폭

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

단위 kbps
최소값 : 1
최대값: 10000000

단위 kbps
최소값 : 1
최대값 : 10000000

priority

string

N

우선순위

우선순위

1: 가장높음(HIGHEST)
2: 매우 높음(HIGHER)
3: 높음(HIGH)
4 : 보통(NORMAL, 기본값)
5: 낮음(LOW)
6: 매우 낮음(LOWER)
7: 가장 낮음(LOWEST)

method

string

N

작동 방식

작동 방식

desc

string

N

설명

0: 정책 공유 (기본값)
1:개별 할당

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

-
Response

name

value

description

code

integer

message

string

Status Code

실패 시 에러 메시지

-
예시

요청 예시

{
        "name" : "internal_qos",
        "minBandwidth" : "123",
        "maxBandwidth" : "567",
        "priority" : "7",
        "desc":"rest test",
        "method":"0"
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

4) QoS 객체 수정

Request URL:  https://<TG_IP>:50005/restapi/object/qos/qos/{orgName}
Method : PUT
Path parameter

name

orgName

type

string

require

description

Y

변경전 객체 이름

-
Query parameters
None

Request

name

value

© AhnLab, Inc. All rights reserved.

Page 50 of 92

body

name

type

description

validation

name

string

객체 이름

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

minBandwidth

string

최소 대역폭

maxBandwidth string

최대 대역폭

단위 kbps
최소값 : 1
최대값: 10000000

단위 kbps
최소값 : 1
최대값 : 10000000

priority

string

우선순위

우선순위

1: 가장높음(HIGHEST)
2: 매우 높음(HIGHER)
3: 높음(HIGH)
4 : 보통(NORMAL, 기본값)
5: 낮음(LOW)
6: 매우 낮음(LOWER)
7: 가장 낮음(LOWEST)

desc

string

설명

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

-
Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
        "name" : "external_qos",
        "minBandwidth" : "567891",
        "maxBandwidth" : "1000000",
        "priority" : "2",
        "desc":"rest test modify"
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

5) QoS 객체 삭제

Request URL:  https://<TG_IP>:50005/restapi/object/qos/qos/{name}
Method : DELETE
Path parameter

name

name

type

string

require

description

Y

삭제할 객체 이름

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

© AhnLab, Inc. All rights reserved.

Page 51 of 92

정책

IPv4 정책

정책 추가 성공시 정책 ID Response는 TG 2.7.4. H15에 반영이 되었습니다.

1) IPv4 정책목록 조회
2) IPv4 정책조회
3) IPv4 정책추가
4) IPv4 정책수정
5) IPv4 정책삭제
6) 우선순위 제어

1) IPv4 정책목록 조회

Request URL : https://<TG_IP>:50005/restapi/firewall/firewall/ipv4
Method : GET
Path parameter

None
Query parameters
offset/limit

name

offset

value

integer

description

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대값 : 2000

expireRule

boolean

만료 정책 검색

true : 일정 만료 정책 검색
false : 전체 검색(기본값)
최대값 : 2000

예시 : https://<TG_IP>:50005/restapi/firewall/firewall/ipv4?offset=10&limit=20&expireRule=false

Request

None

Response

name

value

code

integer

count

integer

description

Status Code

조회 결과 건수

© AhnLab, Inc. All rights reserved.

Page 52 of 92

objects

name

value

description

policyId

priority

sip

dip

svc

정책 ID

우선순위

출발지 주소

format: array(object)

목적지 주소

format: array(object)

서비스

format: array(object)

schedule

enable

일정

사용 여부

true : 사용
false : 미사용

reverse

양방향 정책

true : 사용
false : 미사용

action

처리 방법

1 : 차단
2 : 허용
3 : 보안등급
6 : IPSec VPN

format: 0/0/0/0/0
1번 째 인자 : 1일
2번 째 인자 : 7일
3번 째 인자 : 30일
4번 째 인자 : 60일
5번 째 인자 : 90일

hitcount

desc

설명

message

string

실패 시 에러 메시지

-
예시

{
        "code" : 200,
        "count": 13,
        "objects" :  [
                {
                        "policyId": "7",
                        "priority": 5,
            "sip": [
                "1.1.1.1",
                "10.10.10.1"
            ],
            "dip": [
                "10.10.20.1",
                "111.111.111.111"
            ],
            "svc": [
                "AOL",
                "DNS"
            ],
            "schedule": "once",
            "enable": true,
            "reverse": true,
            "action": "2",
            "hitcount" : "0/0/0/0/0",
            "desc": " "
        },
                ....
        ],
        "message" : ""
}

© AhnLab, Inc. All rights reserved.

Page 53 of 92

2) IPv4 정책조회

Request URL :  https://<TG_IP>:50005/restapi/firewall/firewall/ipv4/{policyId}
Method : GET
Path parameter

name

type

require

description

policyId

string

Y

검색할 정책 ID

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

object

name

value

description

policyId

priority

sip

dip

svc

정책 ID

우선순위

출발지 주소

format: array(object)

목적지 주소

format: array(object)

서비스

format: array(object)

schedule

enable

일정

사용 여부

true : 사용
false : 미사용

reverse

양방향 정책

true : 사용
false : 미사용

action

처리 방법

1 : 차단
2 : 허용
3 : 보안등급
6 : IPSec VPN

format: 0/0/0/0/0
1번 째 인자 : 1일
2번 째 인자 : 7일
3번 째 인자 : 30일
4번 째 인자 : 60일
5번 째 인자 : 90일

hitcount

desc

설명

message

string

실패 시 에러 메시지

-
예시

© AhnLab, Inc. All rights reserved.

Page 54 of 92

{
        "code" : 200,
        "objects" :  [
                {
                "policyId": "7",
                        "priority": 5,
            "sip": [
                "1.1.1.1",
                "10.10.10.1"
            ],
            "dip": [
                "10.10.20.1",
                "111.111.111.111"
            ],
            "svc": [
                "AOL",
                "DNS"
            ],
            "schedule": "once",
            "enable": true,
            "reverse": false,
            "action": "2",
            "hitcount" : "0/0/0/0/0",
            "desc": " "
        }
        ],
        "message" : ""
}

3) IPv4 정책추가

Request URL :  https://<TG_IP>:50005/restapi/firewall/firewall/ipv4
Method : POST
Path parameter

None
Query parameters
None

Request

name

body

name

type

require

description

validation

value

priority

integer

sip

dip

svc

array(json)

array(json)

array(json)

schedule

string

enable

boolean

reverse

boolean

action

string

qos

string

desc

string

N

Y

Y

Y

N

N

N

N

N

N

우선순위

출발지

목적지

서비스

일정

사용 여부

양방향 정책

허용/차단/보안등급/IPSec VPN

QoS

설명

빈값일 경우 최우선 순위

IPv4 주소 / IPv4 주소 그룹 이름
사용자 주소 / 사용자 주소 그룹 이름

IPv4 주소 / IPv4 주소 그룹 이름
도메인 주소/ 도메인 주소 그룹 이름

서비스 / 서비스 그룹 이름

일정 이름
기본값 : always

true : 사용(기본값)
false : 미사용

true : 양방향 정책 사용
false : 양방향 정책 미사용(기본값)

1 : 차단
2 : 허용(기본값)
3 : 보안등급
6 : IPSec VPN

Qos객체 이름

기본값 : 빈값

최대 길이: 255bytes

-
Response

name

value

description

code

integer

message

policyId

string

string

Status Code

실패 시 에러 메시지

정책 ID

© AhnLab, Inc. All rights reserved.

Page 55 of 92

-
예시

요청 예시

{
        "priority": 1,
        "sip": [
                "addr1", "addr2", ""
        ],
    "dip": [
                "dst1", "addr5", "addr6", "2"
        ],
    "svc": [
                "svc_group1", "svc1"
        ],
    "schedule": "always",
        "enable" : true,
        "reverse": false,
    "action": "2",
    "desc": " "
}

응답 예시

{
        "code" : 200,
        "message" : "",
        "policyId" : "28"
}

4) IPv4 정책수정

Request URL :  https://<TG_IP>:50005/restapi/firewall/firewall/ipv4/{policyId}
Method : PUT
Path parameter

type

string

require

description

Y

정책 ID

name

policyId

-
Query parameters
None

Request

name

body

value

name

type

description

validation

sip

dip

svc

array(json) 출발지

array(json) 목적지

IPv4 주소 / IPv4 주소 그룹 이름
사용자 주소 / 사용자 주소 그룹 이름

IPv4 주소 / IPv4 주소 그룹 이름
도메인 주소/ 도메인 주소 그룹 이름

array(json) 서비스

서비스 / 서비스 그룹 이름

schedule

string

일정

enable

string

사용 여부

reverse

string

양방향 정책

action

string

허용/차단/보안등급/IPSec VPN

qos

desc

string

string

QoS

설명

일정 이름

0 : 미사용
1: 사용

0 : 양방향 정책 미사용
1 : 양방향 정책 사용

1 : 차단
2 : 허용
3 : 보안등급
6 : IPSec VPN

Qos객체 이름

최대 길이: 255bytes

-
Response

© AhnLab, Inc. All rights reserved.

Page 56 of 92

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
        "sip": [
                "addr3","addr4", "2"
        ],
    "dip": [
                "addr7", "addr8", "_1"
        ],
        "svc": [
                "svc3", "svc2"
        ],
    "schedule": "once",
        "enable" : false,
        "reverse": false,
        "action": "1",
        "desc": ""
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

5) IPv4 정책삭제

Request URL:  https://<TG_IP>:50005/restapi/firewall/firewall/ipv4/{policyId}
Method : DELETE
Path parameter

name

policyId

type

string

require

description

Y

정책 ID

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

6) 우선순위 제어

Request URL:  https://<TG_IP>:50005/restapi/firewall/firewall/ipv4Action
Method : Get
Path parameter

None
Query parameters

name

policyId

type

type

string

string

require

Y

Y

정책 ID

priority

description

© AhnLab, Inc. All rights reserved.

Page 57 of 92

position

string

Y

top : 최 우선순위
bottom : 최하위 순위
숫자: 해당 우선순위

-
Request

None

Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

인터페이스 기반 NAT

1) 인터페이스 기반 NAT 목록 조회
2) 인터페이스 기반 NAT 조회
3) 인터페이스 기반 NAT 추가
4) 인터페이스 기반 NAT 수정
5) 인터페이스 기반 NAT 삭제
6) 우선순위 제어

1) 인터페이스 기반 NAT 목록 조회

Request URL : https://<TG_IP>:50005/restapi/firewall/nat/ib
Method : GET
Path parameter

None
Query parameters
offset/limit

name

value

description

offset

integer

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대값 : 2000

예시 : https://<TG_IP>:50005/restapi/firewall/nat/ib?offset=1&limit=20

Request

None

Response

name

value

description

code

integer

total

integer

objects

2.7.4

Status Code

조회 결과 총 갯수

© AhnLab, Inc. All rights reserved.

Page 58 of 92

name

value

description

priority

natId

우선순위

NAT ID

enable

boolean

사용여부

type

타입

true : 사용
false : 미사용

1: Dynamic NAT
2: Static NAT
3: 변환 안함
4: LS NAT

protocol

프로토콜

1: ALL
2: TCP
3: UDP

사설 IP 주소

내부 포트

privateIp

privatePort

publicIp

array:object NAT 인터페이스

publicPort

외부 포트

dynamicBlist boolean

동적 블랙 리스트

true : 사용
false : 미사용

desc

설명

2.7.5

© AhnLab, Inc. All rights reserved.

Page 59 of 92

name

value

description

priority

natId

enable

우선순위

NAT ID

boolean 사용여부

type

타입

true : 사용
false : 미사용

1: Dynamic NAT
2: Static NAT
3: 변환 안함
4: LS NAT

protocol

프로토콜

1: ALL
2: TCP
3: UDP

receiveInterface

array

수신 인터페이스

beforeSip

beforeDip

변환 전 출발지

변환 전 목적지

beforeSport

변환 전 포트

afterSip

afterDip

변환 후 출발지

변환 후 목적지

afterSport

변환 후 포트

sendInterface

array

송신 인터페이스

dynamicBlist

boolean 동적 블랙 리스트

true : 사용
false : 미사용

reverse

boolean 양방향

true : 사용
false : 미사용

desc

설명

message

string

실패 시 에러 메시지

-
예시

{
        "code" : 200,
        "total": 24,
        "objects" :  [
                {
                        "priority":"0",
                        "natId": "1",
                        "enable":true,
                        "type":"3",
                        "protocol":"1",
                        "privateIp":"10.0.0.1",
                        "privatePort":"1-65535",
                        "publicIp":[
                                "10.0.1.1"
                        ],
                        "publicPort":"1-65535",
                        "dynamicBlist":false,
                        "desc":""
                },
        ....
        ],
        "message" : ""
}

2.7.5

© AhnLab, Inc. All rights reserved.

Page 60 of 92

{
        "code" : 200,
        "total": 24,
        "objects": [
                {
                        "priority": "0",
            "enable": false,
            "type": "2",
            "natId": "3",
            "reverse": true,
            "protocol": "1",
            "receiveInterface": [
                "eth0"
            ],
            "beforeSip": "",
            "afterSip": "",
            "beforeSport": "1-65535",
            "afterSport": "1-65535",
            "beforeDip": "",
            "afterDip": "1.1.1.1z",
            "sendInterface": [
                "all"
            ],
            "desc": "",
            "dynamicBlist": false
                },
                ...
         ],
        "message" : ""
}

2) 인터페이스 기반 NAT 조회

Request URL:  https://<TG_IP>:50005/restapi/firewall/nat/ib/{natId}
Method : GET
Path parameter

name

type

require

description

natId

string

Y

검색할 정책 NAT ID

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

total

integer

objects

2.7.4

Status Code

조회 결과 총 갯수

© AhnLab, Inc. All rights reserved.

Page 61 of 92

name

value

description

priority

natId

우선순위

NAT ID

enable

boolean

사용여부

type

타입

true : 사용
false : 미사용

1: Dynamic NAT
2: Static NAT
3: 변환 안함
4: LS NAT

protocol

프로토콜

1: ALL
2: TCP
3: UDP

사설 IP 주소

내부 포트

privateIp

privatePort

publicIp

array:object NAT 인터페이스

publicPort

외부 포트

dynamicBlist boolean

동적 블랙 리스트

true : 사용
false : 미사용

desc

설명

2.7.5

© AhnLab, Inc. All rights reserved.

Page 62 of 92

name

value

description

priority

natId

enable

우선순위

NAT ID

boolean 사용여부

type

타입

true : 사용
false : 미사용

1: Dynamic NAT
2: Static NAT
3: 변환 안함
4: LS NAT

protocol

프로토콜

1: ALL
2: TCP
3: UDP

receiveInterface

수신 인터페이스

beforeSip

beforeDip

변환 전 출발지

변환 전 목적지

beforeSport

변환 전 포트

afterSip

afterDip

변환 후 출발지

변환 후 목적지

afterSport

변환 후 포트

sendInterface

송신 인터페이스

dynamicBlist

동적 블랙 리스트

true : 사용
false : 미사용

reverse

양방향

true : 사용
false : 미사용

desc

설명

message

string

예시

실패 시 에러 메시지

{
        "code" : 200,
        "objects" :  [
                {
                "priority":"2",
                        "natId": "11",
                        "enable":true,
                        "type":"2",
                        "protocol":"1",
                        "privateIp":"10.0.0.1",
                        "privatePort":"1-65535",
                        "publicIp":["eth0,192.1.1.1"],
                        "publicPort":"1-65535",
                        "dynamicBlist":true,
                        "desc":""
        }
        ],
        "message" : ""
}

2.7.5

© AhnLab, Inc. All rights reserved.

Page 63 of 92

{
    "code": 200,
    "objects": [
        {
            "priority": "0",
            "enable": false,
            "type": "2",
            "natId": "3",
            "reverse": true,
            "protocol": "1",
            "receiveInterface": [
                "eth0"
            ],
            "beforeSip": "",
            "afterSip": "",
            "beforeSport": "1-65535",
            "afterSport": "1-65535",
            "beforeDip": "",
            "afterDip": "1.1.1.1z",
            "sendInterface": [
                "all"
            ],
            "desc": "",
            "dynamicBlist": false
        }
    ],
    "message": ""
}

3) 인터페이스 기반 NAT 추가

Request URL:  https://<TG_IP>:50005/restapi/firewall/nat/ib
Method : POST
Path parameter

None
Query parameters
None

Request

name

body

2.7.4

value

© AhnLab, Inc. All rights reserved.

Page 64 of 92

name

type

require

description

validation

priority

string

enable

boolean

type

string

protocol

string

privateIp

string

privatePort

string

publicIp

array

Y

N

N

N

Y

N

Y

우선 순위

사용여부

유형

프로토콜

기본값 : 0

true : 사용 (기본값)
false : 미사용

1: Dynamic NAT(기본값)
2: Static NAT
3: 변환 안함
4: LS NAT

1: ALL(기본값)
2: TCP
3: UDP

사설 IP 주소

Dynamic NAT, Static NAT, LS NAT

사설 IP 주소 - 단일 IPv4주소/IPv4 주소 그룹

변환 안함

출발지 IP - 단일 IPv4주소/IPv4 주소 그룹

내부 포트

min-max (ex: 1-65535)

NAT 인터페이스

Dynamic NAT

NAT 인터페이스 - 인터페이스,IP주소 형태의 array(max 16개)

Static NAT

NAT 인터페이스 - 인터페이스,IP주소 형태의 문자열

변환 안함

목적지 IP - 단일 IPv4주소/IPv4 주소 그룹

LS NAT

NAT 인터페이스 - 인터페이스,IP주소 형태의 array(max 16개)

publicPort

string

N

외부 포트

형식

dynamicBlist boolean

desc

string

N

N

동적 블랙 리스트 사용

설명

2.7.5

min-max (ex: 1-65535)
기본값 : 1-65535

true : 사용
false : 미사용(기본값)

© AhnLab, Inc. All rights reserved.

Page 65 of 92

name

type

require

description

validation

priority

string

enable

boolean

type

string

protocol

string

beforeIp

string

Y

N

N

N

Y

우선 순위

사용여부

유형

프로토콜

기본값 : 0

true : 사용 (기본값)
false : 미사용

1: Dynamic NAT(기본값)
2: Static NAT
3: 변환 안함
4: LS NAT

1: ALL(기본값)
2: TCP
3: UDP

Dynamic Nat: 변환전 출발지 주소

단일 IPv4주소/IPv4 주소 그룹

Static Nat: 변환 후 목적지 주소

변환 없음: 출발지 IP

Ls Nat: 변환후 목적지 주소

beforePort

string

N

Dynamic Nat: 변환전 포트

min-max (ex: 1-65535)

Static Nat: 변환전 포트

변환 없음: 출발지 포트

Ls Nat: 변환전 포트

afterIp

array

Y

Dynamic Nat: 송신 인터페이스

Dynamic Nat(type: array)

string

Static Nat: 수신 인터페이스,변환전 목적지 주소

인터페이스,IP주소 형태의 array(max 16개)

변환 없음: 목적지 IP

Ls Nat: 수신 인터페이스

Static Nat(type: string)

인터페이스,단일 IPv4 주소
변환전 목적지 주소 생략 할 경우: 인터페이스만 표기

변환 없음(type: string)

단일 IPv4주소/IPv4 주소 그룹

Ls Nat(type: array)

인터페이스,IP주소 형태의 array(max 16개)

afterPort

string

N

Dynamic Nat: 변환 후 포트

min-max (ex: 1-65535)

dynamicBlist boolean

reverse

boolean

N

N

Static Nat: 변환 후 포트

변환 없음: 목적지 포트

Ls Nat: 변환 후 포트

동적 블랙 리스트 사용

true : 사용
false : 미사용(기본값)

양방향 정책

Static NAT

true : 사용
false : 미사용(기본값)

desc

string

N

설명

-
Response

name

value

description

code

integer

message

string

Status Code

실패 시 에러 메시지

-
예시

요청 예시

{
        "priority":"0",
        "enable":true,
        "type":"4",
        "protocol":"1",
        "privateIp":"10.0.102.1",
        "privatePort":"1-65535",
        "publicIp":[
                "eth1,11.11.11.11",
                "eth5,10.1.1.1"
        ],
        "publicPort":"1-65535",
        "desc":"",
        "dynamicBlist":true
}

© AhnLab, Inc. All rights reserved.

Page 66 of 92

2.7.5

// Dynamic Nat
{
    "priority":"0",
    "enable":true,
    "type":"1",
    "protocol":"1",
    "beforeIp":"1.1.1.12",
    "beforePort": "1-65535",
    "afterIp": [
            "eth0,1.1.1.1",
            "eth0,2.2.2.2"
    ],
    "afterPort":"1-65535",
    "desc":"",
    "reverse": false,
    "dynamicBlist":true
}
// Static Nat
{
        "priority":"0",
    "enable":true,
    "type":"2",
    "protocol":"1",
    "beforeIp":"1.1.1.2",
    "beforePort": "1-65535",
    "afterIp": "eth0,1.2.3.4",
    "afterPort":"1-65535",
    "desc":"desc",
    "reverse": true,
    "dynamicBlist":false
}
//
{
        "priority":"0",
    "enable":true,
    "type":"3",
    "protocol":"1",
    "beforeIp":"1.1.1.2",
    "beforePort": "1-65535",
    "afterIp": "1.2.3.4",
    "afterPort":"1-65535",
    "desc":"desc",
    "reverse": true,
    "dynamicBlist":false
}
// LS NAT
{
        "priority":"0",
    "enable":true,
    "type":"4",
    "protocol":"2",
    "beforeIp":"1.1.1.2",
    "beforePort": "66",
    "afterIp": [
            "eth6,2.5.5.5"
    ],
    "afterPort":"1-65535",
    "desc":"desc",
    "reverse": false,
    "dynamicBlist":true
}

1

응답 예시

{
        "code" : 200,
        "message" : ""
}

4) 인터페이스 기반 NAT 수정

© AhnLab, Inc. All rights reserved.

Page 67 of 92

Request URL:  https://<TG_IP>:50005/restapi/firewall/nat/ib/{natId}
Method : PUT
Path parameter

name

natId

type

string

require

description

Y

변경할 정책 NAT ID

-
Query parameters
None

Request

name

body

2.7.4

value

name

type

description

validation

enable

boolean 사용여부

type

string

유형

protocol

string

프로토콜

true : 사용 (기본값)
false : 미사용

1: Dynamic NAT(기본값)
2: Static NAT
3: 변환 안함
4: LS NAT

1: ALL(기본값)
2: TCP
3: UDP

privateIp

string

사설 IP 주소

Dynamic NAT, Static NAT, LS NAT

사설 IP 주소 - 단일 IPv4주소/IPv4 주소 그룹

변환 안함

출발지 IP - 단일 IPv4주소/IPv4 주소 그룹

privatePort

string

내부 포트

형식

publicIp

array

NAT 인터페이스

Dynamic NAT

min-max (ex: 1-65535)

NAT 인터페이스 - 인터페이스,IP주소 형태의 array(max 16개)

Static NAT

NAT 인터페이스 - 인터페이스,IP주소 형태의 문자열

변환 안함

목적지 IP - 단일 IPv4주소/IPv4 주소 그룹

LS NAT

NAT 인터페이스 - 인터페이스,IP주소 형태의 array(max 16개)

publicPort

string

외부 포트

형식

dynamicBlist boolean 동적 블랙 리스트 사용

min-max (ex: 1-65535)

true : 사용
false : 미사용(기본값)

desc

string

설명

2.7.5

© AhnLab, Inc. All rights reserved.

Page 68 of 92

name

type

require

description

validation

enable

boolean

type

string

protocol

string

beforeIp

string

N

N

N

Y

사용여부

유형

프로토콜

true : 사용 (기본값)
false : 미사용

1: Dynamic NAT(기본값)
2: Static NAT
3: 변환 안함
4: LS NAT

1: ALL(기본값)
2: TCP
3: UDP

Dynamic Nat: 변환전 출발지 주소

단일 IPv4주소/IPv4 주소 그룹

Static Nat: 변환 후 목적지 주소

변환 없음: 출발지 IP

Ls Nat: 변환후 목적지 주소

beforePort

string

N

Dynamic Nat: 변환전 포트

min-max (ex: 1-65535)

Static Nat: 변환전 포트

변환 없음: 출발지 포트

Ls Nat: 변환전 포트

afterIp

array

Y

Dynamic Nat: 송신 인터페이스

Dynamic Nat

string

Static Nat: 수신 인터페이스,변환전 목적지 주소

인터페이스,IP주소 형태의 array(max 16개)

변환 없음: 목적지 IP

Ls Nat: 수신 인터페이스

Static Nat

인터페이스,단일 IPv4 주소
변환전 목적지 주소 생략 할 경우: 인터페이스만 표기

변환 없음

단일 IPv4주소/IPv4 주소 그룹

Ls Nat

인터페이스,IP주소 형태의 array(max 16개)

afterPort

string

N

Dynamic Nat: 변환 후 포트

min-max (ex: 1-65535)

dynamicBlist boolean

reverse

boolean

N

N

Static Nat: 변환 후 포트

변환 없음: 목적지 포트

Ls Nat: 변환 후 포트

동적 블랙 리스트 사용

true : 사용
false : 미사용(기본값)

양방향 정책

Static NAT

true : 사용
false : 미사용(기본값)

desc

string

N

설명

-
Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
    "enable":false,
        "type":"1",
        "protocol":"1",
        "privateIp":"10.0.0.1",
        "privatePort":"1-65535",
        "publicIp":["eth0,10.0.1.1"],
        "publicPort":"1-65535",
        "dynamicBlist":false,
        "desc":""
}

2.7.5

© AhnLab, Inc. All rights reserved.

Page 69 of 92

/** "priority"  POST   */
{
    "enable":true,
    "type":"1",
    "protocol":"1",
    "beforeIp":"1.1.1.12",
    "beforePort": "1-65535",
    "afterIp": [
        "eth0,1.1.1.1",
        "eth0,2.2.2.2"
    ],
    "afterPort":"1-65535",
    "desc":"",
    "reverse": false,
    "dynamicBlist":true
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

5) 인터페이스 기반 NAT 삭제

Request URL:  https://<TG_IP>:50005/restapi/firewall/nat/ib/{natId}
Method : DELETE
Path parameter

name

natId

type

string

require

description

Y

삭제할 정책 NAT ID

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

6) 우선순위 제어

Request URL:  https://<TG_IP>:50005/restapi/firewall/nat/ibAction
Method : Get
Path parameter

None
Query parameters

type

string

string

string

require

description

Y

Y

Y

NAT ID

priority

top : 최 우선순위
bottom : 최하위 순위
숫자: 해당 우선순위

name

natId

type

position

-
Request

None

Response

name

value

description

code

integer

Status Code

© AhnLab, Inc. All rights reserved.

Page 70 of 92

message

string

실패 시 에러 메시지

정책 기반 NAT

1) 정책 기반 NAT 목록 조회
2) 정책 기반 NAT 조회
3) 정책 기반 NAT 추가
4) 정책 기반 NAT 수정
5) 정책 기반 NAT 삭제
6) 우선순위 제어

1) 정책 기반 NAT 목록 조회

Request URL : https://<TG_IP>:50005/restapi/firewall/nat/pb
Method : GET
Path parameter

None
Query parameters
offset/limit

name

value

description

offset

integer

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대값 : 2000

예시 : https://<TG_IP>:50005/restapi/firewall/nat/pb?offset=1&limit=20

Request

None

Response

name

value

description

code

integer

total

integer

Status Code

조회 결과 총 갯수

objects

name

value

description

priority

우선순위

enable

boolean 사용여부

beforeSip

beforeDip

true : 사용
false : 미사용

변환 전 출발지

변환 전 목적지

beforeService

변환 전 서비스

afterSip

afterDip

변환 후 출발지

변환 후 목적지

afterService

변환 후 서비스

reverse

boolean 양방향 정책

true : 사용
false : 미사용

dynamicBlist

boolean 동적 블랙 리스트

true : 사용
false : 미사용

desc

설명

© AhnLab, Inc. All rights reserved.

Page 71 of 92

message

string

실패 시 에러 메시지

-
예시

{
        "code" : 200,
        "total: 16,
        "objects" :  [
                {
                        "priority":"0",
                        "enable":true,
                        "beforeSip":"10.1.1.1",
                        "beforeDip":"10.1.1.2",
                        "beforeService":"AH",
                        "afterSip":"10.1.1.2",
                        "afterDip":"ipv4address",
                        "afterService":"",
                        "desc":"",
                        "reverse":false,
                        "dynamicBlist":true
                },
        ....
        ],
        "message" : ""
}

2) 정책 기반 NAT 조회

Request URL:  https://<TG_IP>:50005/restapi/firewall/nat/pb/{priority}
Method : GET
Path parameter

name

type

require

description

priority

string

Y

검색할 정책 우선 순위

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

© AhnLab, Inc. All rights reserved.

Page 72 of 92

object

name

value

description

priority

우선순위

enable

boolean 사용여부

beforeSip

beforeDip

true : 사용
false : 미사용

변환 전 출발지

변환 전 목적지

beforeService

변환 전 서비스

afterSip

afterDip

변환 후 출발지

변환 후 목적지

afterService

변환 후 서비스

reverse

boolean 양방향 정책

true : 사용
false : 미사용

dynamicBlist

boolean 동적 블랙 리스트

true : 사용
false : 미사용

desc

설명

message

string

실패 시 에러 메시지

-
예시

{
        "code" : 200,
        "objects" :  [
                {
                "priority":"0",
                        "enable":true,
                        "beforeSip":"10.1.1.1",
                        "beforeDip":"10.1.1.2",
                        "beforeService":"AH",
                        "afterSip":"10.1.1.2",
                        "afterDip":"ipv4address",
                        "afterService":"",
                        "desc":"",
                        "reverse":false,
                        "dynamicBlist":true
        }
        ],
        "message" : ""
}

3) 정책 기반 NAT 추가

Request URL:  https://<TG_IP>:50005/restapi/firewall/nat/pb
Method : POST
Path parameter

None
Query parameters
None

Request

name

value

© AhnLab, Inc. All rights reserved.

Page 73 of 92

body

name

type

require

description

validation

priority

string

enable

boolean

beforeSip

string

beforeDip

string

beforeService string

afterSip

afterDip

string

string

afterService

string

reverse

boolean

dynamicBlist

boolean

desc

string

Y

N

Y

Y

Y

Y

Y

Y

N

N

N

우선 순위

사용여부

기본값 : 0

true : 사용 (기본값)
false : 미사용

변환 전 출발지

IPv4 주소/ IPv4 주소 그룹

변환 전 목적지

IPv4 주소/ IPv4 주소 그룹

변환 전 서비스

서비스 / 서비스 그룹

변환 후 출발지

IPv4 주소/ IPv4 주소 그룹

변환 후 목적지

IPv4 주소/ IPv4 주소 그룹

변환 후 서비스

서비스 / 서비스 그룹

양방향 정책

동적 블랙 리스트 사용

설명

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

-
Response

name

value

description

code

integer

message

string

Status Code

실패 시 에러 메시지

-
예시

요청 예시

{
        "priority":"0",
        "enable":true,
        "beforeSip":"10.0.118.1",
        "beforeDip":"10.0.120.1",
        "beforeService":"all",
        "afterSip":"",
        "afterDip":"10.0.128.1",
        "afterService":"",
        "desc":"",
        "reverse":true,
        "dynamicBlist":true
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

4) 정책 기반 NAT 수정

Request URL:  https://<TG_IP>:50005/restapi/firewall/nat/pb/{priority}
Method : PUT
Path parameter

name

priority

type

string

require

description

Y

변경할 정책 우선순위

-
Query parameters
None

Request

name

value

© AhnLab, Inc. All rights reserved.

Page 74 of 92

body

name

type

description

validation

enable

boolean 사용여부

true : 사용 (기본값)
false : 미사용

beforeSip

string

변환 전 출발지

IPv4 주소/ IPv4 주소 그룹

beforeDip

string

변환 전 목적지

IPv4 주소/ IPv4 주소 그룹

beforeService string

변환 전 서비스

서비스 / 서비스 그룹

afterSip

string

변환 후 출발지

IPv4 주소/ IPv4 주소 그룹

afterDip

string

변환 후 목적지

IPv4 주소/ IPv4 주소 그룹

afterService

string

변환 후 서비스

서비스 / 서비스 그룹

reverse

boolean 양방향 정책

dynamicBlist

boolean 동적 블랙 리스트 사용

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

desc

string

설명

-
Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
    "enable":true,
        "beforeSip":"10.1.1.1",
        "beforeDip":"10.1.1.2",
        "beforeService":"AH",
        "afterSip":"10.1.1.2",
        "afterDip":"ipv4address",
        "afterService":"",
        "desc":"",
        "reverse":false,
        "dynamicBlist":true
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

5) 정책 기반 NAT 삭제

Request URL:  https://<TG_IP>:50005/restapi/firewall/nat/pb/{priority}
Method : DELETE
Path parameter

name

priority

type

string

require

description

Y

삭제할 정책 우선순위

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

© AhnLab, Inc. All rights reserved.

Page 75 of 92

message

string

실패 시 에러 메시지

6) 우선순위 제어

Request URL:  https://<TG_IP>:50005/restapi/firewall/nat/pbAction
Method : Get
Path parameter

None
Query parameters

type

string

string

string

require

description

Y

Y

Y

NAT ID

priority

top : 최 우선순위
bottom : 최하위 순위
숫자: 해당 우선순위

name

natId

type

position

-
Request

None

Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

IPv4 정책 예외

1) IPv4 정책 예외 목록 조회
2) IPv4 정책 예외 조회
3) IPv4 정책 예외 추가
4) IPv4 정책 예외 수정
5) IPv4 정책 예외 삭제

1) IPv4 정책 예외 목록 조회

Request URL : https://<TG_IP>:50005/restapi/firewall/white/ipv4
Method : GET
Path parameter

None
Query parameters
offset/limit

name

value

description

offset

integer

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대값 : 2000

예시 : https://<TG_IP>:50005/restapi/firewall/white/ipv4?offset=1&limit=20

Request

None

Response

name

value

description

code

integer

total

integer

Status Code

조회 결과 총 갯수

© AhnLab, Inc. All rights reserved.

Page 76 of 92

objects

name

value

description

priority

우선순위

enable

boolean 사용여부

sip

dip

svc

iac

true : 사용
false : 미사용

출발지

목적지

서비스

boolean 인터넷 접근 제어

true : 사용
false : 미사용

pf

boolean 기본 정책

true : 사용
false : 미사용

blacklist boolean 접근 차단

true : 사용
false : 미사용

geoip

boolean 지역 기반 차단

true : 사용
false : 미사용

lbqos

boolean 웹 트래픽 제한

ips

boolean IPS

true : 사용
false : 미사용

true : 사용
false : 미사용

appctl

boolean 애플리케이션 제어

true : 사용
false : 미사용

ipsec

boolean IPSec VPN

true : 사용
false : 미사용

af

boolean 프록시

true : 사용
false : 미사용

cnc

boolean C&C 연결 차단

true : 사용
false : 미사용

desc

설명

message

string

실패 시 에러 메시지

-
예시

© AhnLab, Inc. All rights reserved.

Page 77 of 92

{
        "code" : 200,
        "total: 13,
        "objects" :  [
                {
                        "priority":"0",
                        "enable":true,
                        "sip":"ipv4address",
                        "dip":"ipv4address2",
                        "svc":"all",
                        "iac":false,
                        "pf":true,
                        "blacklist":false,
                        "geoip":false,
                        "lbqos":true,
                        "ips":false,
                        "appctl":false,
                        "ipsec":true,
                        "af":false,
                        "cnc":false,
                        "desc":""
                },
        ....
        ],
        "message" : ""
}

2) IPv4 정책 예외 조회

Request URL:  https://<TG_IP>:50005/restapi/firewall/white/ipv4/{priority}
Method : GET
Path parameter

name

type

require

description

priority

string

Y

검색할 정책 우선 순위

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

© AhnLab, Inc. All rights reserved.

Page 78 of 92

object

name

value

description

priority

우선순위

enable

boolean 사용여부

sip

dip

svc

iac

true : 사용
false : 미사용

출발지

목적지

서비스

boolean 인터넷 접근 제어

true : 사용
false : 미사용

pf

boolean 기본 정책

true : 사용
false : 미사용

blacklist boolean 접근 차단

true : 사용
false : 미사용

geoip

boolean 지역 기반 차단

true : 사용
false : 미사용

lbqos

boolean 웹 트래픽 제한

ips

boolean IPS

true : 사용
false : 미사용

true : 사용
false : 미사용

appctl

boolean 애플리케이션 제어

true : 사용
false : 미사용

ipsec

boolean IPSec VPN

true : 사용
false : 미사용

af

boolean 프록시

true : 사용
false : 미사용

cnc

boolean C&C 연결 차단

true : 사용
false : 미사용

desc

설명

message

string

실패 시 에러 메시지

-
예시

© AhnLab, Inc. All rights reserved.

Page 79 of 92

{
        "code" : 200,
        "objects" :  [
                {
                "priority":"0",
                        "enable":true,
                        "sip":"ipv4address",
                        "dip":"ipv4address2",
                        "svc":"all",
                        "iac":false,
                        "pf":true,
                        "blacklist":false,
                        "geoip":false,
                        "lbqos":true,
                        "ips":false,
                        "appctl":false,
                        "ipsec":true,
                        "af":false,
                        "cnc":false,
                        "desc":""
        }
        ],
        "message" : ""
}

3) IPv4 정책 예외 추가

Request URL:  https://<TG_IP>:50005/restapi/firewall/white/ipv4
Method : POST
Path parameter

None
Query parameters
None

Request

name

body

value

name

type

require

description

validation

enable

boolean

N

사용여부

sip

dip

svc

iac

pf

string

string

string

boolean

boolean

blacklist

boolean

geoip

boolean

lbqos

boolean

ips

boolean

appctl

boolean

ipsec

boolean

af

boolean

cnc

boolean

desc

string

Y

Y

Y

Y

Y

Y

Y

Y

Y

Y

Y

Y

Y

Y

출발지

목적지

서비스

인터넷 접근 제어

기본 정책

접근 차단

지역 기반 차단

웹 트래픽 제한

IPS

애플리케이션 제어

IPSec VPN

프록시

C&C 연결 차단

설명

true : 사용 (기본값)
false : 미사용

IPv4 주소/ IPv4 주소 그룹

IPv4 주소/ IPv4 주소 그룹

서비스 / 서비스 그룹

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

-
Response

name

value

description

code

integer

Status Code

© AhnLab, Inc. All rights reserved.

Page 80 of 92

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
        "enable":true,
        "sip":"10.1.1.1",
        "dip":"10.1.1.2",
        "svc":"BGP",
        "iac":true,
        "pf":true,
        "blacklist":true,
        "geoip":true,
        "lbqos":true,
        "ips":true,
        "appctl":true,
        "ipsec":true,
        "af":true,
        "cnc":true,
        "desc":""
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

4) IPv4 정책 예외 수정

Request URL:  https://<TG_IP>:50005/restapi/firewall/white/ipv4/{priority}
Method : PUT
Path parameter

name

priority

type

string

require

description

Y

변경할 정책 우선순위

-
Query parameters
None

Request

name

value

© AhnLab, Inc. All rights reserved.

Page 81 of 92

body

name

type

description

validation

enable

boolean 사용여부

true : 사용 (기본값)
false : 미사용

string

출발지

IPv4 주소/ IPv4 주소 그룹

string

목적지

IPv4 주소/ IPv4 주소 그룹

string

서비스

서비스 / 서비스 그룹

sip

dip

svc

iac

pf

boolean 인터넷 접근 제어

boolean 기본 정책

blacklist

boolean 접근 차단

geoip

boolean 지역 기반 차단

lbqos

boolean 웹 트래픽 제한

ips

boolean IPS

appctl

boolean 애플리케이션 제어

ipsec

boolean IPSec VPN

af

boolean 프록시

cnc

boolean C&C 연결 차단

desc

string

설명

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

true : 사용
false : 미사용(기본값)

-
Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
    "enable":false,
        "sip":"ipv4address",
        "dip":"ipv4address2",
        "svc":"AH",
        "pf":true,
        "desc":""
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

5) IPv4 정책 예외 삭제

Request URL:  https://<TG_IP>:50005/restapi/firewall/white/ipv4/{priority}
Method : DELETE
Path parameter

name

priority

type

string

require

description

Y

삭제할 정책 우선순위

-
Query parameters

© AhnLab, Inc. All rights reserved.

Page 82 of 92

None

Request

None

Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

IPv4 차단 대상

1) IPv4 차단 대상 목록 조회
2) IPv4 차단 대상 조회
3) IPv4 차단 대상 추가
4) IPv4 차단 대상 수정
5) IPv4 차단 대상 삭제

1) IPv4 차단 대상 목록 조회

Request URL : https://<TG_IP>:50005/restapi/firewall/black/ipv4Black
Method : GET
Path parameter

None
Query parameters
offset/limit

name

value

description

offset

integer

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대값 : 2000

예시 : https://<TG_IP>:50005/restapi/firewall/black/ipv4Black?offset=1&limit=20

Request

None

Response

name

value

description

code

integer

total

integer

Status Code

조회 결과 총 갯수

objects

name

priority

sip

dip

svc

value

description

우선순위

출발지

목적지

서비스

lastUpdateTime

마지막 변경 시간

desc

설명

message

string

실패 시 에러 메시지

-
예시

© AhnLab, Inc. All rights reserved.

Page 83 of 92

{
        "code" : 200,
        "total: 13,
        "objects" :  [
                {
                        "priority":"0",
                        "sip":"10.1.1.2",
                        "dip":"ipv4address",
                        "svc":"BGP",
                        "desc":"",
                        "lastUpdateTime":"2020-05-25 16:08:53"
                },
        ....
        ],
        "message" : ""
}

2) IPv4 차단 대상 조회

Request URL:  https://<TG_IP>:50005/restapi/firewall/black/ipv4Black/{priority}
Method : GET
Path parameter

name

type

require

description

priority

string

Y

검색할 정책 우선 순위

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

object

name

priority

sip

dip

svc

value

description

우선순위

출발지

목적지

서비스

lastUpdateTime

마지막 변경 시간

desc

설명

message

string

실패 시 에러 메시지

-
예시

{
        "code" : 200,
        "objects" :  [
                {
                "priority":"0",
                        "sip":"10.1.1.2",
                        "dip":"ipv4address",
                        "svc":"BGP",
                        "desc":"",
                        "lastUpdateTime":"2020-05-25 16:08:53"
        }
        ],
        "message" : ""
}

3) IPv4 차단 대상 추가

© AhnLab, Inc. All rights reserved.

Page 84 of 92

Request URL:  https://<TG_IP>:50005/restapi/firewall/black/ipv4Black
Method : POST
Path parameter

None
Query parameters
None

Request

value

name

type

require

description

validation

sip

dip

svc

string

string

string

desc

string

Y

Y

Y

N

출발지

목적지

서비스

설명

IPv4 주소/ IPv4 주소 그룹

IPv4 주소/ IPv4 주소 그룹

서비스

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

name

body

-
Response

name

value

description

code

integer

message

string

Status Code

실패 시 에러 메시지

-
예시

요청 예시

{
        "sip": "ipv4address",
    "dip": "ipv4address2",
    "svc": "all",
    "desc": "rest test"
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

4) IPv4 차단 대상 수정

Request URL:  https://<TG_IP>:50005/restapi/firewall/black/ipv4Black/{priority}
Method : PUT
Path parameter

name

priority

type

string

require

description

Y

변경할 정책 우선순위

-
Query parameters
None

Request

name

body

value

name

type

description

validation

sip

dip

svc

string

출발지

IPv4 주소/ IPv4 주소 그룹

string

목적지

IPv4 주소/ IPv4 주소 그룹

string

서비스

서비스

desc

string

설명

한글, 영문, 숫자, 특수문자 / - _ ( ) . :
최대 길이: 255bytes

© AhnLab, Inc. All rights reserved.

Page 85 of 92

-
Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

-
예시

요청 예시

{
    "sip": "ipv4address2",
    "dip": "ipv4address",
    "svc": "all",
    "desc": "rest test modify"
}

응답 예시

{
        "code" : 200,
        "message" : ""
}

5) IPv4 차단 대상 삭제

Request URL:  https://<TG_IP>:50005/restapi/firewall/black/ipv4Black/{priority}
Method : DELETE
Path parameter

name

priority

type

string

require

description

Y

삭제할 정책 우선순위

-
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

message

string

실패 시 에러 메시지

세션 조회

1) 세션 조회

1) 세션 조회

Request URL:  https://<TG_IP>:50005/restapi/monitoring/firewall/sessionv4
Method : Get
Path parameter

None
Query parameters
offset/limit

name

value

description

© AhnLab, Inc. All rights reserved.

Page 86 of 92

offset

integer

조회 결과 항목 시작 위치

기본값 : 1
미지정 시, 기본값 적용

limit

integer

조회 결과 항목 개수

기본값 : 50
미지정 시, 기본값 적용
최대값 : 2000

예시 : https://<TG_IP>:50005/restapi/monitoring/firewall/sessionv4?offset=10&limit=20

Request

None

Response

name

code

integer

value

description

Status Code

objects

name

value

description

time

policyId

logId

sessionId

protocol

sip

dip

svc

tx

rx

시간

정책 ID

로그 ID

세션 ID

프로토콜

출발지 IP : 포트

목적지 IP : 포트

서비스

아웃바운드(bytes/pkts)

인바운드(bytes/pkts)

duration

연결 시간

nat

NAT

vpn

VPN

0 :  사용 안 함
1 : 사용
2 : 인터페이스 기반 NAT
3 : 정책 기반 NAT

0 : 사용 안함
1 : 사용

status

tcpFlag

상태

TCP 플래그

message

string

실패 시 에러 메시지

-
예시

© AhnLab, Inc. All rights reserved.

Page 87 of 92

{
        "code" : 200,
        "count: 100,
        "objects" :  [
                {
                        "time": "2020-05-12 13:33:20",
                        "policyId": "4294967295",
            "logId": "UTM_ADMINHOST",
            "sessionId": "11543526",
            "protocol": "tcp",
            "sip": "192.168.70.42/34310",
            "dip": "192.168.70.113/514",
            "svc": "syslog",
            "tx": "465567407/4626124",
            "rx": "0/0",
            "duration": "1220278",
            "nat": "0",
            "vpn": "0",
            "status": "UNREPLY",
            "tcpFlag": "",
        },
                ....
        ],
        "message" : ""
}

기타

장비 조회

1) 장비 조회

1) 장비 조회

Request URL: https://<TG_IP>:50005/restapi/deviceInfo
Method : GET
Path parameter

None
Query parameters
None

Request

None

Response

name

value

description

code

integer

Status Code

objects

name

value

description

name

uniqueId

productNo

serial

model

firmware

uptime

ha

장비 이름

장비 ID

제품번호

장비 일련 번호

장비 모델

장비 펌웨어 버전

장비 가동 시간

HA 여부

message

string

실패 시 에러 메시지

© AhnLab, Inc. All rights reserved.

Page 88 of 92

-
예시

{
        "code" : 200,
        "objects" :  [
                {
                "name": "TG1000_42",
                        "uniqueId":"613c9f",
                        "productNo":"47540030-40562082",
                 "serial": "1635010700xxx",
                        "model": "TG1000",
                        "firmware" : "2.7.4.61(Build 1026)",
                        "uptime" : "14day 5:02",
                        "ha": "OFF"
        }
        ],
        "message" : ""
}

미사용 객체 조회

TG의 미사용 객체 조회 기능은 요청 시점에 미사용 객체를 계산해 내는 구조임
작업 완료까지의 소요 시간을 보장할 수 없는 작업이기 때문에 관련 CLI가 비동기 방식으로 개발되어져 있음.

TG의 작업이 완료되면 요청 대상에 notification(push)을 보내는 방식을 취하거나
작업 진행 상태를 주기적으로 체크(polling)하는 방식을 취할 수 있는데,
본 문서에서는 polling 방식에 대한 방법을 가이드 함

1) 미사용 객체 조회 시작

Request URL: https://<TG_IP>:50005/restapi/firewall/firewall/unusedObject
Method : GET
Path parameter

None
Query parameters

name

value

description

action

string

start : 미사용 객체 조회 시작
stop : 미사용 객체 조회 종료
status :  미사용 객체 조회 상태
show : 미사용 객체 조회(status가 complete인 경우 사용)

startDate

string 미사용 객체 조회 시작 일

형식: yyyyMMdd
action이 start일 경우일때 필수값

endDate

string 미사용 객체 조회 시작 일

형식: yyyyMMdd
action이 start일 경우일때 필수값

예시 : https://<TG_IP>:50005/restapi/firewall/firewall/unusedObject?action=start&startDate=20200603&endDate=20200610
Request

None

Response (action이 status 일 경우)

name

value

code

integer

description

Status Code

© AhnLab, Inc. All rights reserved.

Page 89 of 92

objects

name

value

description

status

진행 상태

idle : 조회 대기
working : 조회중
completed : 조회 완료
failed : 조회 실패
canceled : 조회 취소

progress

startDate

endDate

진행율

미사용 객체 조회 시작 일

미사용 객체 조회 시작 일

message

string

실패 시 에러 메시지

-
Response (action이 show 일 경우)

name

value

code

integer

objects

name

value

description

objectType

객체 종류

description

Status Code

0 : IPv4
1: IPv4 Group
2: FQDN
3: FQDN Group
4: 사용자 주소
5: 사용자 주소 그룹
6: IPv6
7: IPv6 그룹

name

zone

refCnt

이름

Zone

참조수

refId

array:object 참조 정책 ID

message

string

실패 시 에러 메시지

-
예시

action이 status일 때 응답예시

{
        "code":200,
        "status":"completed",
        "progress":"100%",
        "startDate":"2020-06-03",
        "endDate":"2020-06-10",
        "message":""
}

© AhnLab, Inc. All rights reserved.

Page 90 of 92

action이 status일 때 응답예시

{
        "code":200,
        "objects":[
                {
                        "objType":"0",
                        "zone":"all",
                        "name":"10.1.1.1",
                        "refCnt":"10",
                        "refId":[
                                "40,41,42,43,44,45,46,47,48,49"
                        ]
                },
                ...
        ],
        "message":""
}

정책 적용

1) 정책 적용

1) 정책 적용

Request URL: https://<TG_IP>:50005/restapi/apply
Method : GET
Path parameter

None
Query parameters

sessionClear

name

sessionClear

value

boolean

description

차단으로 변경한 세션 초기화

기본값 : false
미지정 시, 기본값 적용

예시 : https://<TG_IP>:50005/restapi/apply?sessionClear=false

Request

None

Response

name

value

description

code

integer

message

string

Status Code

실패 시 에러 메시지

© AhnLab, Inc. All rights reserved.

Page 91 of 92

AhnLab TrusGuard Open API 가이드

경기도 성남시 분당구 판교역로 220 (우)13493
홈페이지:
http://www.ahnlab.com
대표전화: 031-722-8000 팩스: 031-722-8901
© 2020 AhnLab, Inc. All rights reserved.

© AhnLab, Inc. All rights reserved.

Page 92 of 92

