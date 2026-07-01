MF2 REST API  가이드

Copyright©  2019. SECUI. All rights reserved.

문서  개정  이력

문서버전

날짜

설명

V 4.3.2_81633

2016-03-29

문서  최초  작성

인증,로그인,Firewall,NAT

사용자  지원  태그  확장

NAT  범위  객체  지원

V 4.3.3_82315

2017-02-07

1:1  단방향  동시변환  지원

1:1  단방향  확장변환  지원

IPv6객체, IPv6  방화벽  정책

블랙리스트,  방화벽  정책  임시  저장

V 4.3.9_86822

2020-05-29

IPv4/IPv6  정책  내용  검색  옵션(관련  정보(객체)포함)  추가

목  차

1. REST API  설정 ..................................................................... 1

1.1 관리자 IP 설정 ......................................................................... 1

1.2 HTTP PUT/DELETE Method 제한 .............................................. 1

1.3 HTTP Status Code ..................................................................... 2

2. REST API  인증 ..................................................................... 3

2.1 REST API Token 관리 ................................................................ 3

2.1.1 GUI Token  발급................................................................................ 3

2.1.2 API Token  발급 ................................................................................ 4

2.1.3 API Token  조회 ................................................................................ 4

3.  로그인/로그아웃 .................................................................. 6

3.1 로그인 ....................................................................................... 6

3.2 로그아웃 ................................................................................... 7

4. Firewall ................................................................................ 9

4.1 객체 설정 .................................................................................. 9

4.1.1  서비스  객체 ..................................................................................... 9

4.1.2  서비스  그룹  객체 .......................................................................... 16

4.1.3  시간  객체 ...................................................................................... 22

4.1.4  호스트  객체 ................................................................................... 29

4.1.5  네트워크  객체 ............................................................................... 33

4.1.6  도메인  객체 ................................................................................... 38

4.1.7  그룹  객체 ...................................................................................... 43

4.1.8 IPv6  호스트  객체 ........................................................................... 48

4.1.9 IPv6  네트워크  객체 ....................................................................... 53

4.1.10 IPv6  그룹  객체 ............................................................................ 58

4.1.11  객체  적용/취소 ............................................................................ 63

4.2 방화벽 정책 ............................................................................ 65

4.2.1  방화벽  정책  목록  조회 ................................................................. 65

4.2.2  방화벽  정책  조회 .......................................................................... 66

4.2.3  방화벽  정책  추가 .......................................................................... 68

4.2.4  방화벽  정책  수정 .......................................................................... 69

4.2.5  방화벽  정책  삭제 .......................................................................... 71

4.2.6  방화벽  정책  이동-최상위로 .......................................................... 72

4.2.7  방화벽  정책  이동-최하위로 .......................................................... 72

4.2.8  방화벽  정책  이동-위로 ................................................................. 73

4.2.9  방화벽  정책  이동-아래로 .............................................................. 74

4.2.10  방화벽  정책  내용  검색 ............................................................... 75

4.2.11  방화벽  Shadow  정책  검색 .......................................................... 79

4.2.12  방화벽  시간만료  정책  검색 ........................................................ 80

4.2.13  방화벽  미참조  정책  검색 ........................................................... 81

4.2.14  방화벽  미참조  객체  검색 ........................................................... 82

4.2.15  방화벽  적용  정책  검색 ............................................................... 83

4.2.16  방화벽  정책그룹  목록  조회 ........................................................ 85

4.2.17  방화벽  정책그룹  추가 ................................................................. 86

4.2.18  방화벽  정책그룹  삭제 ................................................................. 87

4.2.19  방화벽  정책  임시  저장  조회 ...................................................... 87

4.2.20  방화벽  정책  임시  저장 ............................................................... 88

4.2.21  방화벽  정책  임시  저장  파일  삭제 ............................................. 89

4.2.22  방화벽  정책  임시  저장  파일  적용 ............................................. 90

4.2.23  방화벽  정책  적용 ........................................................................ 90

4.2.24  방화벽  정책  취소 ........................................................................ 91

4.3 IPv6 방화벽 정책 .................................................................... 92

4.3.1 IPv6  방화벽  정책  목록  조회 ......................................................... 92

4.3.2 IPv6  방화벽  정책  조회 .................................................................. 93

4.3.3 IPv6  방화벽  정책  추가 .................................................................. 95

4.3.4 IPv6  방화벽  정책  수정 .................................................................. 97

4.3.5 IPv6  방화벽  정책  삭제 .................................................................. 98

4.3.6 IPv6  방화벽  정책  이동-최상위로 .................................................. 99

4.3.7 IPv6  방화벽  정책  이동-최하위로 ................................................ 100

4.3.8 IPv6  방화벽  정책  이동-위로 ....................................................... 100

4.3.9 IPv6  방화벽  정책  이동-아래로 .................................................... 101

4.3.10 IPv6  방화벽  정책  내용  검색 ..................................................... 102

4.3.11 IPv6  방화벽  Shadow  정책  검색 ................................................ 106

4.3.12 IPv6  방화벽  시간만료  정책  검색 .............................................. 107

4.3.13 IPv6  방화벽  미참조  정책  검색 ................................................. 108

4.3.14 IPv6  방화벽  미참조  객체  검색 ................................................. 109

4.3.15 IPv6  방화벽  적용  정책  검색 ...................................................... 111

4.3.16 IPv6  방화벽  정책그룹  목록  조회 .............................................. 112

4.3.17 IPv6  방화벽  정책그룹  추가 ....................................................... 113

4.3.18 IPv6  방화벽  정책그룹  삭제 ....................................................... 114

4.3.19 IPv6  방화벽  정책  적용 .............................................................. 115

4.3.20 IPv6  방화벽  정책  취소 .............................................................. 115

4.4 NAT 정책 설정 ...................................................................... 116

4.4.1 NAT  정책  목록  조회.................................................................... 117

4.4.2 NAT  정책  조회 ............................................................................ 118

4.4.3 NAT  정책  사용  조회.................................................................... 120

4.4.4 NAT  정책  사용  수정.................................................................... 121

4.4.5 NAT  정책  추가 ............................................................................ 122

4.4.6 NAT  정책  수정 ............................................................................ 123

4.4.7 NAT  정책  삭제 ............................................................................ 125

4.4.8 NAT  정책그룹  목록  조회 ............................................................ 125

4.4.9 NAT  정책그룹  추가 ..................................................................... 126

4.4.10 NAT  정책그룹  삭제 ................................................................... 127

4.4.11 NAT  정책  적용 ........................................................................... 128

4.4.12 NAT  정책  취소 .......................................................................... 129

4.5 IPv4 블랙리스트 .................................................................... 129

4.5.1  블랙리스트  목록  조회 ................................................................. 130

4.5.2  블랙리스트  추가 .......................................................................... 132

4.5.3  블랙리스트  삭제 .......................................................................... 134

4.5.4  만료된  블랙리스트  삭제 ............................................................. 135

4.5.5  블랙리스트  적용 .......................................................................... 136

4.5.6  블랙리스트  취소 .......................................................................... 136

5.  부록 .................................................................................. 138

5.1 주소 객체 .............................................................................. 138

5.2 IPv6 주소 객체 ...................................................................... 138

5.3 주소 객체(NAT 정책) ............................................................ 138

5.4 서비스 객체 .......................................................................... 139

5.5 서비스 유형 .......................................................................... 139

5.6 사용자 ................................................................................... 139

5.7 시간 객체 .............................................................................. 140

5.8 로그인 동작 방식 ................................................................. 140

REST API  설정

1.  REST API  설정

1.1  관리자  IP  설정

연동  장비에서  MF2 REST API  접근이  가능하도록  관리자  IP에  연동  장비  IP를  등록한다.

1.2  HTTP PUT/DELETE Method  제한

PUT/DELETE Method는  보안에  취약하기  때문에  사용을  제한한다.

대신  POST  Method와

“X-HTTP-Method-Override”  해더값에  PUT,DELETE  Method를

사용한다.

$.ajax({

    url: “https://192.168.100.101/ mf2/api/v1/firewall/object/hosts/test_object”,

    type: “POST”,

    data: {},

    headers: {

            “Content-Type”: “application/json”,

            “X-HTTP-Method-Override”: “PUT” },

})

$.ajax({

    url: “https://192.168.100.101/ mf2/api/v1/firewall/object/hosts/test_object”,

    type: “POST”,

    data: {},

    headers: {

            “Content-Type”: “application/json”,

            “X-HTTP-Method-Override”: “DELETE” },

})

Copyright©  2016. SECUI. All rights reserved.

1

HTTP Status Code

1.3  HTTP Status Code

REST API  호출시  응답할  수  있는  상태  코드  중  주요  코드에  대한  설명이다.

Code

200

401

404

405

Status

OK

Description

서버가  요청을  제대로  처리했다는  뜻이다.

Unauthorized

이  요청은  인증이  필요하다.

Not Found

요청한  페이지를  찾을  수  없다.

Method

Allowed

Not

요청에  지정된  Method는  사용할  수  없다.

2

Copyright©  2016. SECUI. All rights reserved.

REST API  인증

2.  REST API  인증

2.1  REST API Token  관리

2.1.1  GUI Token  발급

System  >  관리자  메뉴에서  REST  API  계정으로  사용될  관리자를  편집하여  REST  API  토큰을

발급한다.

변경된  관리자  정보는  적용  버튼을  클릭하여  장비에  적용된다.

발급된  토큰  값은  HTTP(S)  프로토콜을  사용하여  REST  API  호출시  “Authorization”

해더값으로  전달  한다.

Copyright©  2016. SECUI. All rights reserved.

3

REST API Token  관리

2.1.2  API Token  발급

API를  사용하여  관리자의  Token을  발급한다.

API  호출시  Authorization Header는  필요  없다.

2.1.2.1  URL

POST http(s)://[serverip]/mf2/api/v1/token

2.1.2.2  Path parameters

None

2.1.2.3  Query parameters

이름

id

pwd

Type

설명

String(required)

관리자  ID

String(required)

관리자  비밀번호(Base64)

2.1.2.4  Body

None

2.1.2.5  Returns

application/json

{

“code”:”OK”, // OK or FAIL

“result”:

{

            “token”: “e2e5090141984d8e9285037a8765eaae”

},

“message”:”“

}

2.1.3  API Token  조회

관리자의  Token을  조회  한다.

API  호출시  Authorization Header는  필요  없다.

2.1.3.1  URL

GET http(s)://[serverip]/mf2/api/v1/token

4

Copyright©  2016. SECUI. All rights reserved.

REST API  인증

2.1.3.2  Path parameters

None

2.1.3.3  Query parameters

이름

id

pwd

Type

설명

String(required)

관리자  ID

String(required)

관리자  비밀번호(Base64)

2.1.3.4  Body

None

2.1.3.5  Returns

application/json

{

“code”:”OK”, // OK or FAIL

“result”:

{

            “token”: “e2e5090141984d8e9285037a8765eaae”

},

“message”:”“

}

Copyright©  2016. SECUI. All rights reserved.

5

로그인

3.  로그인/로그아웃

3.1  로그인

쓰기  권한을  획득하기  위해  로그인  한다.

로그인되면  GUI는  쓰기  권한으로  접속이  불가능  하다.

로그인  이후  timeout  시간내에  REST  API  Request가  발생하면  Request  시점마다  timeout

시간이  갱신된다. timeout  시간내에  아무런  Request가  없다면  자동  로그아웃  된다.

GET  Method를  제외한  나머지  Method(POST,PUT,DELETE)로  정의된  REST  API는  로그인된

관리자만  접근이  가능하다.

POST/PUT/DELETE Method로  정의된  REST API를  호출하기  위해서는

“X-API-SESSION” Header에  로그인  세션값을  설정해야  한다.

$.ajax({

…

type: “POST”,

headers: {

            …,

            “Authorization” : “e2e5090141984d8e9285037a8765eaae”,

            “X-API-SESSION”: “291b3f8d7ba319f363c4f2b0ece7bed8c1f4a36f” },

})

로그인  세션값이  timeout되기  이전에  동일한  token값으로  재로그인할  경우  이전  세션값은

expired되고  새로운  로그인  세션값이  발급된다.

※  재로그인하면  이전  세션에서  적용하지  않은  편집한  설정들은  전부  rollback  된다.

3.1.1.1  URL

POST http(s)://[serverip]/mf2/api/v1/login

3.1.1.2  Path parameters

None

3.1.1.3  Query parameters

None

6

Copyright©  2016. SECUI. All rights reserved.

로그인/로그아웃

설명

인증  세션이  유지되는  시간,1~1440(분)

default : 10

3.1.1.4  Body

이름

timeout

Type

int

application/json

{

    "timeout": "10"

}

{

3.1.1.5  Returns

application/json

    "code": "OK", // OK or FAIL

    "result": {

        "session": "adfab56sdfsadfsa12amn232wfklop"

    },

    "message": ""

}

3.2  로그아웃

로그아웃  한다.

로그아웃  이후  MF2  장비에  다른  관리자가  쓰기  권한으로  로그인이  가능한  상태가  된다.

로그아웃은  로그인에서  발급된  “X-API-SESSION”: “[세션값]” Header  정보가  필요하다.

3.2.1.1  URL

POST http(s)://[serverip]/mf2/api/v1/logout

3.2.1.2  Path parameters

None

3.2.1.3  Query parameters

None

Copyright©  2016. SECUI. All rights reserved.

7

로그아웃

3.2.1.4  Body

None

3.2.1.5  Returns

application/json

{

    "code": "OK",// OK or FAIL

    "message": ""

}

8

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.  Firewall

4.1  객체  설정

4.1.1  서비스  객체

4.1.1.1  서비스  객체  목록  조회

서비스  객체  목록을  조회한다.

URL

GET http(s)://[serverip]/mf2/api/v1/firewall/object/services

Path parameters

None

Query parameters

None

Body

None

Returns

이름

name

tag

description

adminID

Type

string

string

string

string

lastModified

string

svcObjType

string

svcObjProtocol

string

svcObjSrcPort

string

설명

객체  이름

객체  종류

설명

관리자  ID

최종  수정일

서비스  유형

프로토콜  이름

출발지  포트

svcObjPort

string

서비스  포트

*  또는  0-65535,0-255(ICMP인  경우)

단일) *  또는  0-65535,0-255(프로토콜이  ICMP일  경우)

범위)  단일값-단일값

혼합)  최대  10개의  단일값,  범위값을  콤마(,)로  구분

svcObjLifetime

int

Lifetime(초)

Copyright©  2016. SECUI. All rights reserved.

9

객체  설정

svcObjPriority

int

1-604800

우선순위

svcObjSysflag

boolean

내장객체(true)

application/json

{

    "code": "OK",

    "result": [

        {

            "name": "UDP객체",

            "tag": "SO",

            "description ": "",

            "adminID": "admin",

            "lastModified": "2016-05-11 14:08:06",

            "svcObjType ": "NONE",

            "svcObjProtocol ": "UDP",

            "svcObjSrcPort ": "*",

            "svcObjPort ": "6626",

            "svcObjLifetime ": "20",

            "svcObjPriority ": "5",

            "svcObjSysflag ": "false"

        }

    ],

    "message": ""

}

4.1.1.2  프로토콜  목록  조회

서비스  객체  프로토콜에  사용되는  프로토콜  목록을  조회  한다.

URL

GET http(s)://[serverip]/mf2/api/v1/firewall/object/protocols

Path parameters

None

10

Copyright©  2016. SECUI. All rights reserved.

Firewall

Query parameters

None

Body

None

Returns

이름

name

Type

string

protocolNum

int

설명

프로토콜  이름

프로토콜

protocolSysFlag  boolean

내장  객체(true)

description

string

설명

application/json

{

    "code": "OK",

    "result": [

        {

            "name": " L2TP",

            "protocolNum": "115",

            "protocolSysFlag": "true",

            "description": "Layer Two Tunneling Protocol"

        }

    ],

    "message": ""

}

4.1.1.3  서비스  객체  조회

서비스  객체를  조회한다.

URL

GET http(s)://[serverip]/mf2/api/v1/firewall/object/services/{name}

Path parameters

이름

name

Type

설명

string(required)  객체  이름

Copyright©  2016. SECUI. All rights reserved.

11

객체  설정

Query parameters

None

Body

None

Returns

이름

name

tag

description

adminID

Type

string

string

string

string

lastModified

string

svcObjType

string

svcObjProtocol

string

svcObjSrcPort

string

설명

객체  이름

객체  종류

설명

관리자  ID

최종  수정일

서비스  유형

프로토콜  이름

출발지  포트

svcObjPort

string

서비스  포트

*  또는  0-65535,0-255(ICMP인  경우)

단일) *  또는  0-65535,0-255(프로토콜이  ICMP일  경우)

범위)  단일값-단일값

혼합)  최대  10개의  단일값,  범위값을  콤마(,)로  구분

svcObjLifetime

int

svcObjPriority

int

Lifetime(초)

1-604800

우선순위

svcObjSysflag

boolean

내장객체(true)

application/json

{

    "code": "OK",

    "result": {

        "name": "UDP객체",

        "tag": "SO",

        "description ": "",

        "adminID": "admin",

        "lastModified": "2016-05-11 14:08:06",

        "svcObjType": "NONE",

        "svcObjProtocol": "UDP",

        "svcObjSrcPort": "*",

12

Copyright©  2016. SECUI. All rights reserved.

Firewall

        "svcObjPort": "6626",

        "svcObjLifetime": "20",

        "svcObjPriority": "5",

        "svcObjSysflag": "false"

    },

    "message": ""

}

4.1.1.4  서비스  객체  추가

서비스  객체를  추가한다.

URL

POST http(s)://[serverip]/mf2/api/v1/firewall/object/services

Path parameters

None

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

restrict : [한글숫자영문._-:]

description

string

설명(128자)

svcObjType

string(required)

서비스  유형

svcObjProtocol

string(required)

프로토콜  이름

svcObjSrcPort

string(required)

출발지  포트

svcObjPort

string(required)

서비스  포트

*  또는  0-65535

단일) *  또는  0-65535,0-255(프로토콜이  ICMP일  경우)

범위)  단일값-단일값

혼합)  최대  10개의  단일값,  범위값을  콤마(,)로  구분

svcObjLifetime

integer(required)

Lifetime(초)

Copyright©  2016. SECUI. All rights reserved.

13

1-604800

TCP) 1800초

UDP) 20초

etc) 10초

우선순위

객체  설정

svcObjPriority

int

application/json

{

    "name": "TCP_80_객체",

    "description": "",

    "svcObjType": "NONE",

    "svcObjProtocol": "TCP",

    "svcObjSrcPort": "*",

    "svcObjPort": "80",

    "svcObjLifetime": "1800",

    "svcObjPriority": "8"

}

{

Returns

application/json

    "code": "OK",// OK or FAIL

    "message": ""

}

4.1.1.5  서비스  객체  수정

서비스  객체를  수정한다.

URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/object/services/{orgName}

Path parameters

이름

Type

설명

orgName

string(required)  변경전  객체  이름(48자)

14

Copyright©  2016. SECUI. All rights reserved.

Firewall

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

restrict : [한글숫자영문._-:]

description

string

설명(128자)

svcObjType

string(required)

서비스  유형

svcObjProtocol

string(required)

프로토콜  이름

svcObjSrcPort

string(required)

출발지  포트

svcObjPort

string(required)

서비스  포트

*  또는  0-65535

단일) *  또는  0-65535,0-255(프로토콜이  ICMP일  경우)

범위)  단일값-단일값

혼합)  최대  10개의  단일값,  범위값을  콤마(,)로  구분

svcObjLifetime

int(required)

Lifetime(초)

1-604800

TCP) 1800초

UDP) 20초

etc) 10초

우선순위

svcObjPriority

int

application/json

{

    "name": "NEW_TCP_80_객체",

    "description": "",

    "svcObjType": "NONE",

    "svcObjProtocol": "TCP",

    "svcObjSrcPort": "*",

    "svcObjPort": "80",

    "svcObjLifetime": "1800",

    "svcObjPriority": "8"

}

{

Returns

application/json

Copyright©  2016. SECUI. All rights reserved.

15

객체  설정

    "code": "OK",// OK or FAIL

    "message": ""

}

4.1.1.6  서비스  객체  삭제

서비스  객체를  삭제한다.

URL

DELETE http(s)://[serverip]/mf2/api/v1/firewall/object/services/{name}

Path parameters

이름

name

Type

설명

string(required)  객체  이름(48자)

Query parameters

None

Body

None

Returns

application/json

{

    "code": "OK",// OK or FAIL

    "message": ""

}

4.1.2  서비스  그룹  객체

4.1.2.1  서비스  그룹  객체  목록  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewall/object/servicegroups

16

Copyright©  2016. SECUI. All rights reserved.

Firewall

Path parameters

None

Query parameters

None

Body

None

Returns

이름

name

tag

description

Type

string

string

string

설명

객체  이름

객체  종류

설명

svcGroupChildObj  array(object)

서비스  객체  목록

관리자  ID

최종  수정일

adminID

lastModified

string

string

application/json

{

    "code": "OK",

    "result": [

        {

            "name": "Web서버객체",

            "tag": "SG",

            "svcGroupChildObj": [

                {

                    "name": "httpservice",

                    "tag": "SS"

                },

                {

                    "name": "webservice",

                    "tag": "SS"

                }

            ],

            "description": "",

            "adminID": "admin",

            "lastModified": "2016-05-11 14:08:06"

Copyright©  2016. SECUI. All rights reserved.

17

객체  설정

        }

    ],

    "message": ""

}

4.1.2.2  서비스  그룹  객체  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewall/object/servicegroups/{name}

Path parameters

이름

name

Type

설명

string(required)  객체  이름

Query parameters

None

Body

None

Returns

이름

name

tag

description

Type

string

string

string

설명

객체  이름

객체  종류

설명

svcGroupChildObj  array(object)

서비스  객체  목록

관리자  ID

최종  수정일

adminID

lastModified

string

string

application/json

{

    "code": "OK",

    "result": [

        {

            "name": "Web서버객체",

            "tag": "SG",

            "svcGroupChildObj": [

18

Copyright©  2016. SECUI. All rights reserved.

Firewall

                {

                    "name": "httpservice",

                    "tag": "SS"

                },

                {

                    "name": "webservice",

                    "tag": "SS"

                }

            ],

            "description": "",

            "adminID": "admin",

            "lastModified": "2016-05-11 14:08:06"

        }

    ],

    "message": ""

}

4.1.2.3  서비스  그룹  객체  추가

URL

POST http(s)://[serverip]/mf2/api/v1/firewall/object/servicegroups

Path parameters

None

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

description

string

설명(128자)

svcGroupChildObj  array(object)(required)  서비스  객체  목록

restrict : [한글숫자영문._-:]

name,tag  속성을  갖는  서비스  객체의  배열을

입력한다.

Copyright©  2016. SECUI. All rights reserved.

19

객체  설정

application/json

{

    "name": "service_group_object",

    "description": "",

    "svcGroupChildObj": [

        {

            "name": "httpservice",

            "tag": "SS"

        },

        {

            "name": "webservice",

            "tag": "SS"

        }

    ]

}

Returns

application/json

{

    "code": "OK",// OK or FAIL

    "message": ""

}

4.1.2.4  서비스  그룹  객체  수정

URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/object/servicegroups/{orgName}

Path parameters

이름

Type

설명

orgName

string(required)  변경전  객체  이름(48자)

Query parameters

None

20

Copyright©  2016. SECUI. All rights reserved.

Firewall

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

description

string

설명(128자)

svcGroupChildObj  array(object)(required)  서비스  객체  목록

restrict : [한글숫자영문._-:]

name,tag  속성을  갖는  서비스  객체의  배열을

입력한다.

application/json

{

    "name": "service_group_object",

    "description": "",

    "svcGroupChildObj": [

        {

            "name": "httpservice",

            "tag": "SS"

        },

        {

            "name": "webservice",

            "tag": "SS"

        }

    ]

}

{

Returns

application/json

    "code": "OK",// OK or FAIL

    "message": ""

}

4.1.2.5  서비스  그룹  객체  삭제

URL

DELETE http(s)://[serverip]/mf2/api/v1/firewall/object/servicegroups/{name}

Copyright©  2016. SECUI. All rights reserved.

21

객체  설정

Path parameters

이름

name

Type

설명

string(required)  객체  이름(48자)

Query parameters

None

Body

None

Returns

application/json

{

    "code": "OK",// OK or FAIL

    "message": ""

}

4.1.3  시간  객체

4.1.3.1  시간  객체  목록  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewall/object/times

Path parameters

None

Query parameters

None

Body

None

Returns

이름

Type

설명

22

Copyright©  2016. SECUI. All rights reserved.

Firewall

name

tag

description

string

string

string

timeObjDaytime  string

객체  이름

객체  종류

설명

주간

1) ANY/any

2) SUN|MON|TUE|WED|THU|FRI|SAT(hh:mm~hh:mm)

    최대3개의  시간  범위  입력  가능

(ex. SUN(00:00~23:59), MON(00:00~13:59,

14:00~20:59,21:00~23:59),WED(*))

timeObjMonth

string

월간

1) month

(ex. 1D,2D,3D,4D,5D,6D,7D,8D,9D,10D,11D,12D)

timeObjYear

string

2) range of day

  (ex. 01~31)

3) week

  (ex. 1W,2W,3W,4W,5W,6W)

연간

(1~12)M

timeObjInterval

string

기간

  (ex. 1M,2M,3M,4M,5M,6M,7M,8M,9M,10M,11M,12M)

YYYY-MM-DD hh:mm~YYYY-MM-DD hh:mm

  (Maximum Period Counts : 3)

관리자  ID

최종  수정일

adminID

string

lastModified

string

application/json

{

    “code”: “OK”,

    “result”: [

        {

            “name”: “시간객체”,

            “tag”: “TO”,

            “description“: ““,

            “adminID”: “admin”,

            “lastModified”: “2016-05-11 14:08:06”,

            “ timeObjDaytime “: “MON(*),TUE(*),SAT(00:00~18:59,19:00~22:59,23:00~23:59)”,

            “ timeObjMonth “: “1W,2W”,

            “ timeObjYear “: “1M,2M”,

Copyright©  2016. SECUI. All rights reserved.

23

객체  설정

            “  timeObjInterval  “:  “2014-01-01  00:00~2014-05-31  23:59,2014-06-01  00:00~2014-08-31

23:59”

        },

        …

],

“message”:”“

}

4.1.3.2  시간  객체  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewall/object/times/{name}

Path parameters

이름

name

Type

설명

string(required)  객체  이름

Query parameters

None

Body

None

Returns

이름

name

tag

description

Type

string

string

string

timeObjDaytime  string

설명

객체  이름

객체  종류

설명

주간

1) ANY/any

2) SUN|MON|TUE|WED|THU|FRI|SAT(hh:mm~hh:mm)

    최대3개의  시간  범위  입력  가능

(ex. SUN(00:00~23:59), MON(00:00~13:59,

14:00~20:59,21:00~23:59),WED(*))

timeObjMonth

string

월간

1) month

24

Copyright©  2016. SECUI. All rights reserved.

Firewall

(ex. 1D,2D,3D,4D,5D,6D,7D,8D,9D,10D,11D,12D)

2) range of day

  (ex. 01~31)

3) week

  (ex. 1W,2W,3W,4W,5W,6W)

연간

(1~12)M

timeObjYear

string

timeObjInterval

string

기간

  (ex. 1M,2M,3M,4M,5M,6M,7M,8M,9M,10M,11M,12M)

YYYY-MM-DD hh:mm~YYYY-MM-DD hh:mm

  (Maximum Period Counts : 3)

관리자  ID

최종  수정일

adminID

string

lastModified

string

application/json

{

    “code”: “OK”,

    “result”:

        {

            “name”: “시간객체”,

            “tag”: “TO”,

            “ description “: ““,

            “adminID”: “admin”,

            “lastModified”: “2016-05-11 14:08:06”,

            “ timeObjDaytime “: “MON(*),TUE(*),SAT(00:00~18:59,19:00~22:59,23:00~23:59)”,

            “ timeObjMonth “: “1W,2W”,

            “ timeObjYear “: “1M,2M”,

            “  timeObjInterval  “:  “2014-01-01  00:00~2014-05-31  23:59,2014-06-01  00:00~2014-08-31

23:59”

        },

“message”:”“

}

4.1.3.3  시간  객체  추가

URL

POST http(s)://[serverip]/mf2/api/v1/firewall/object/times

Copyright©  2016. SECUI. All rights reserved.

25

객체  설정

Path parameters

None

Query parameters

None

Body

이름

name

Type

설명

string(required)  객체  이름(48자)

timeObjDaytime  string(required)  주간

restrict : [한글숫자영문._-:]

SUN|MON|TUE|WED|THU|FRI|SAT(hh:mm~hh:mm(최대3개구간))

ex)SUN(00:00~23:59),

MON(00:00~13:59,14:00~20:59,21:00~23:59)

ex)SUN(*),WED(*),FRI(09:00~18:00)

timeObjMonth

string

월간

1D,2D,10D

timeObjYear

string

연간

1M,5M,9M

timeObjInterval

string

기간

description

string

설명(128자)

2015-02-27 00:00~2015-03-20 23:59

application/json

{

“ name “: “Time_객체”,

“ timeObjDaytime “: “ MON(*),TUE(*),SAT(00:00~18:59,19:00~22:59,23:00~23:59) “,

    “ timeObjMonth “: ““,

    “ timeObjYear “: “ 1M,2M “,

    “ timeObjInterval “: “2014-01-01 00:00~2014-05-31 23:59 “,

“ description “: “sample”

}

{

Returns

application/json

“code”:”OK”, // OK or FAIL

26

Copyright©  2016. SECUI. All rights reserved.

Firewall

“message”:”“

}

4.1.3.4  시간  객체  수정

URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/object/times/{orgName}

Path parameters

이름

Type

설명

orgName

string(required)  변경전  객체  이름(48자)

Query parameters

None

Body

이름

name

Type

설명

string(required)  객체  이름(48자)

timeObjDaytime  string(required)  주간

restrict : [한글숫자영문._-:]

SUN|MON|TUE|WED|THU|FRI|SAT(hh:mm~hh:mm(최대3개구간))

ex)SUN(00:00~23:59),

MON(00:00~13:59,14:00~20:59,21:00~23:59)

ex)SUN(*),WED(*),FRI(09:00~18:00)

timeObjMonth

string

월간

1D,2D,10D

timeObjYear

string

연간

1M,5M,9M

timeObjInterval

string

기간

description

string

설명(128자)

2015-02-27 00:00~2015-03-20 23:59

application/json

{

“name”: “NEW_Time_객체”,

    “ timeObjDaytime “: “ MON(*),TUE(*),SAT(00:00~18:59,19:00~22:59,23:00~23:59) “,

    “ timeObjMonth “: ““,

Copyright©  2016. SECUI. All rights reserved.

27

객체  설정

    “ timeObjYear “: “ 1M,2M “,

    “ timeObjInterval “: “2014-01-01 00:00~2014-05-31 23:59 “,

“ description “: “sample”

}

{

}

Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

4.1.3.5  시간  객체  삭제

URL

DELETE http(s)://[serverip]/mf2/api/v1/firewall/object/times/{name}

Path parameters

이름

name

Type

설명

string(required)  객체  이름(48자)

Query parameters

None

Body

None

Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

28

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.1.4  호스트  객체

4.1.4.1  호스트  객체  목록  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewall/object/hosts

설명

객체  Zone(internal|external|dmz)

Zone과  일치하는  객체만  조회한다.

설명

객체  이름

객체  종류

IP  주소

설명

관리자  ID

최종  수정일

Path parameters

None

Query parameters

이름

zone

Type

string

Body

None

Returns

이름

name

tag

objIp

Type

string

string

ipv4 address

description

adminID

string

string

lastModified

string

application/json

{

    “code”: “OK”,

    “result”: [

        {

            “name”: “Web서버객체”,

            “tag”: “IH”,

“objIP”: “192.168.120.112”,

            “ description “: ““,

            “adminID”: “admin”,

            “lastModified”: “2016-05-11 14:08:06”

        },

Copyright©  2016. SECUI. All rights reserved.

29

객체  설정

        …

],

“message”:”“

}

4.1.4.2  호스트  객체  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewall/object/hosts/{name}

Path parameters

이름

name

Type

설명

string(required)  객체  이름

Query parameters

None

Body

None

Returns

이름

name

tag

objIp

Type

string

string

ipv4 address

description

adminID

string

string

lastModified

string

application/json

{

    “code”: “OK”,

    “result”:

        {

            “name”: “Web서버객체”,

            “tag”: “IH”,

“objIP”: “192.168.120.112”,

            “ description “: ““,

설명

객체  이름

객체  종류

IP  주소

설명

관리자  ID

최종  수정일

30

Copyright©  2016. SECUI. All rights reserved.

Firewall

            “adminID”: “admin”,

            “lastModified”: “2016-05-11 14:08:06”

        },

“message”:”“

}

4.1.4.3  호스트  객체  추가

URL

POST http(s)://[serverip]/mf2/api/v1/firewall/object/hosts

Path parameters

None

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

tag

string(required)

객체  종류

restrict : [한글숫자영문._-:]

description

string

objIp

ipv4

address(required)

Zone(I|E|D) + Type(H)

설명(128자)

IP  주소

application/json

{

    “name” : “host_object

    “tag”: “IH”,

    “ description “: ““,

    “ objIp “: “11.4.9.100”

}

{

Returns

application/json

Copyright©  2016. SECUI. All rights reserved.

31

객체  설정

“code”:”OK”, // OK or FAIL

“message”:”“

}

4.1.4.4  호스트  객체  수정

URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/object/hosts/{orgName}

Path parameters

이름

Type

설명

orgName

string(required)  변경전  객체  이름(48자)

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

restrict : [한글숫자영문._-:]

tag

string(required)

객체  종류

Zone(I|E|D) + Type(H)

objIp

ipv4

IP  주소

address(required)

description

string

설명(128자)

application/json

{

“name”: “NEW_호스트객체”,

    “ tag “: “IH”,

    “ description “: ““,

    “ objIp “: “11.4.9.100”

}

{

Returns

application/json

“code”:”OK”, // OK or FAIL

32

Copyright©  2016. SECUI. All rights reserved.

Firewall

“message”:”“

}

4.1.4.5  호스트  객체  삭제

URL

DELETE http(s)://[serverip]/mf2/api/v1/firewall/object/hosts/{name}

Path parameters

이름

name

Type

설명

string(required)  객체  이름(48자)

Query parameters

None

Body

None

Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.1.5  네트워크  객체

4.1.5.1  네트워크  객체  목록  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewall/object/networks

Path parameters

None

Query parameters

이름

zone

Type

string

설명

객체  Zone(internal|external|dmz)

Copyright©  2016. SECUI. All rights reserved.

33

객체  설정

Zone과  일치하는  객체만  조회한다.

Body

None

Returns

이름

name

tag

objIp

Type

string

string

ipv4 address

description

adminID

string

string

lastModified

string

application/json

{

    “code”: “OK”,

    “result”: [

        {

설명

객체  이름

객체  종류

IP  주소

설명

관리자  ID

최종  수정일

            “name”: “서비스사업부객체”,

            “tag”: “IN”,

            “ objIp “: “11.4.100.0/16”,

            “ description “: ““,

            “adminID”: “admin”,

            “lastModified”: “2016-05-11 14:08:06”

        },

        …

],

“message”:”“

}

4.1.5.2  네트워크  객체  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewall/object/networks/{name}

Path parameters

이름

Type

설명

34

Copyright©  2016. SECUI. All rights reserved.

name

string(required)  객체  이름

Firewall

Query parameters

None

Body

None

Returns

이름

name

tag

objIp

Type

string

string

ipv4 address

description

adminID

string

string

lastModified

string

application/json

{

    “code”: “OK”,

    “result”:

        {

설명

객체  이름

객체  종류

IP  주소

설명

관리자  ID

최종  수정일

            “name”: “서비스사업부객체”,

            “tag”: “IN”,

            “ objIp “: “11.4.100.0/16”,

            “ description “: ““,

            “adminID”: “admin”,

            “lastModified”: “2016-05-11 14:08:06”

        },

“message”:”“

}

4.1.5.3  네트워크  객체  추가

URL

POST http(s)://[serverip]/mf2/api/v1/firewall/object/networks

Copyright©  2016. SECUI. All rights reserved.

35

객체  설정

Path parameters

None

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

restrict : [한글숫자영문._-:]

tag

string(required)

객체  종류

Zone(I|E|D) + Type(N)

description

string

설명(128자)

objIp

ipv4

네트워크  IP  주소(CIDR  또는  IP범위)

address(required)

11.4.9.0/24 or 11.4.9.1~11.4.9.255

application/json

{

    “name”: “네트워크객체”,

    “tag”: “IN”,

    “ description “: ““,

    “ objIp “: “11.4.9.100~11.4.9.200”

}

{

}

Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

4.1.5.4  네트워크  객체  수정

URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/object/networks/{orgName}

36

Copyright©  2016. SECUI. All rights reserved.

Firewall

Path parameters

이름

Type

설명

orgName

string(required)  변경전  객체  이름(48자)

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

restrict : [한글숫자영문._-:]

tag

string(required)

객체  종류

Zone(I|E|D) + Type(N)

objIp

ipv4

네트워크  IP  주소(CIDR  또는  IP범위)

address(required)

11.4.9.0/24 or 11.4.9.1~11.4.9.255

description

string

설명(128자)

application/json

{

“name”: “NEW_네트워크객체”,

    “tag”: “IN”,

    “ description “: ““,

    “ objIp “: “11.4.9.100~11.4.9.200”

}

{

}

Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

4.1.5.5  네트워크  객체  삭제

URL

DELETE http(s)://[serverip]/mf2/api/v1/firewall/object/networks/{name}

Copyright©  2016. SECUI. All rights reserved.

37

객체  설정

Path parameters

이름

name

Type

설명

string(required)  객체  이름

Query parameters

None

Body

None

Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.1.6  도메인  객체

4.1.6.1  도메인  객체  목록  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewall/object/domains

Path parameters

None

Query parameters

이름

zone

Type

string

Body

None

Returns

설명

객체  Zone(internal|external|dmz)

Zone과  일치하는  객체만  조회한다.

이름

Type

설명

38

Copyright©  2016. SECUI. All rights reserved.

Firewall

name

fqdn

tag

description

adminID

string

string

string

string

string

lastModified

string

객체  이름

도메인  네임

객체  종류

설명

관리자  ID

최종  수정일

staticObjIp

string

수동으로  입력된  IP  주소  목록

dynamicObjIp

string

DNS Query를  통한  자동  수집된  IP  주소  목록

staticObjIpv6

string

수동으로  입력된  IPv6  주소  목록

dynamicObjIpv6  string

DNS Query를  통한  자동  수집된  IPv6  주소  목록

application/json

{

    “code”: “OK”,

    “result”: [

        {

            “name”: “도메인객체”,

            “ fqdn “: “www.domain.com”,

            “tag”: “IF”,

“staticObjIp“: “201.100.100.10,201.100.100.11,201.100.100.12”,

“dynamicObjIp”:”125.209.222.141,202.179.177.21”,

“staticObjIpv6“: “2002::1001,2002::1002,2002::1003”,

“dynamicObjIpv6”:”1::2.1::3,1::4”,

            “ description “: ““,

            “adminID”: “admin”,

            “lastModified”: “2016-05-11 14:08:06”

        },

        …

],

“message”:”“

}

4.1.6.2  도메인  객체  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewall/object/domains/{name}

Copyright©  2016. SECUI. All rights reserved.

39

객체  설정

Path parameters

이름

name

Type

설명

string(required)  객체  이름

Query parameters

None

Body

None

Returns

이름

name

fqdn

tag

description

adminID

Type

string

string

string

string

string

lastModified

string

설명

객체  이름

도메인  네임

객체  종류

설명

관리자  ID

최종  수정일

staticObjIp

string

수동으로  입력된  IP  주소  목록

dynamicObjIp

string

DNS Query를  통한  자동  수집된  IP  주소  목록

staticObjIpv6

string

수동으로  입력된  IPv6  주소  목록

dynamicObjIpv6  string

DNS Query를  통한  자동  수집된  IPv6  주소  목록

application/json

{

    “code”: “OK”,

    “result”:

        {

            “name”: “도메인객체”,

            “ fqdn “: “www.domain.com”,

            “tag”: “IF”,

“staticObjIp“: “201.100.100.10,201.100.100.11,201.100.100.12”,

“dynamicObjIp”:”125.209.222.141,202.179.177.21”,

“staticObjIpv6“: “2002::1001,2002::1002,2002::1003”,

“dynamicObjIpv6”:”1::2.1::3,1::4”,

            “ description “: ““,

            “adminID”: “admin”,

            “lastModified”: “2016-05-11 14:08:06”

40

Copyright©  2016. SECUI. All rights reserved.

Firewall

        },

“message”:”“

}

4.1.6.3  도메인  객체  추가

URL

POST http(s)://[serverip]/mf2/api/v1/firewall/object/domains

Path parameters

None

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

restrict : [한글숫자영문._-:]

tag

string(required)

객체  종류

Zone(I|E|D) + Type(F)

fqdn

string(required)

도메인  네임(255자)

description

staticObjIp

string

string

설명(128자)

수동으로  입력된  IP  주소

staticObjIpv6

string

수동으로  입력된  IPv6  주소  목록

application/json

{

    “name”: “secui”,

“tag”: “EF”,

“ fqdn “: “*.secui.com “,

    “ description “: ““,

“ staticObjIp“: “10.10.10.1,10.10.10.2,10.10.10.3”,

“ staticObjIpv6“: “2002::1001,2002::1002,2002::1003”

}

Copyright©  2016. SECUI. All rights reserved.

41

객체  설정

Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

{

}

4.1.6.4  도메인  객체  수정

URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/object/domains/{orgName}

Path parameters

이름

Type

설명

orgName

string(required)  변경전  객체  이름(48자)

Query parameters

None

Body

이름

name

tag

Type

설명

string(required)

객체  이름(48자)

string(required)

객체  종류

Zone(I|E|D) + Type(F)

fqdn

string(required)

도메인  네임(255자)

description

staticObjIp

string

string

설명(128자)

수동으로  입력된  IP  주소

staticObjIpv6

string

수동으로  입력된  IPv6  주소  목록

application/json

{

“name”: “NEW_secui”,

“tag”: “EF”,

“ fqdn “: “*.secui.com”,

    “description “: ““,

“staticObjIp“: “10.10.10.1,10.10.10.2,10.10.10.3”,

“staticObjIpv6“: “2002::1001,2002::1002,2002::1003”

}

42

Copyright©  2016. SECUI. All rights reserved.

Firewall

Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

{

}

4.1.6.5  도메인  객체  삭제

URL

DELETE http(s)://[serverip]/mf2/api/v1/firewall/object/domains/{name}

Path parameters

이름

name

Type

설명

string(required)  객체  이름(48자)

Query parameters

None

Body

None

Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.1.7  그룹  객체

4.1.7.1  그룹  객체  목록  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewall/object/groups

Copyright©  2016. SECUI. All rights reserved.

43

객체  설정

Path parameters

None

Query parameters

이름

zone

Type

string

Body

None

Returns

이름

name

tag

description

Type

string

string

string

설명

객체  Zone(internal|external|dmz)

Zone과  일치하는  객체만  조회한다.

설명

객체  이름

객체  종류

설명

groupChild

array(object)

객체  목록

호스트  객체,네트워크  객체,도메인  객체만

child에

추가될  수  있다.

관리자  ID

최종  수정일

adminID

lastModified

string

string

application/json

{

    “code”: “OK”,

    “result”: [

        {

            “name”: “그룹객체”,

            “tag”: “IG”,

“ groupChild “: [{“name”:”host_object1”,”tag”:”IH”},{“name”:”network_object1”,”tag”:”IN”}],

            “ description “: ““,

            “adminID”: “admin”,

            “lastModified”: “2016-05-11 14:08:06”

        },

        …

],

“message”:”“

44

Copyright©  2016. SECUI. All rights reserved.

Firewall

}

4.1.7.2  그룹  객체  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewall/object/groups/{name}

Path parameters

이름

name

Type

설명

string(required)  객체  이름

Query parameters

None

Body

None

Returns

이름

name

tag

description

Type

string

string

string

설명

객체  이름

객체  종류

설명

groupChild

array(object)

객체  목록

호스트  객체,네트워크  객체,도메인  객체만

child에

추가될  수  있다.

관리자  ID

최종  수정일

adminID

lastModified

string

string

application/json

{

    “code”: “OK”,

    “result”:

        {

            “name”: “그룹객체”,

            “tag”: “IG”,

“ groupChild “: [{“name”:”host_object1”,”tag”:”IH”},{“name”:”network_object1”,”tag”:”IN”}],

            “ description “: ““,

            “adminID”: “admin”,

Copyright©  2016. SECUI. All rights reserved.

45

객체  설정

            “lastModified”: “2016-05-11 14:08:06”

        },

“message”:”“

}

4.1.7.3  그룹  객체  추가

URL

POST http(s)://[serverip]/mf2/api/v1/firewall/object/groups

Path parameters

None

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

restrict : [한글숫자영문._-:]

tag

string(required)

객체  종류

Zone(I|E|D) + Type(G)

description

string

설명(128자)

groupChild

array(object)(required)  객체  목록

호스트  객체,네트워크  객체,도메인  객체만  child에

추가될  수  있다.

name,tag  속성을  갖는  주소객체의  배열을  입력한다.

application/json

{

“name” : “group_object”,

“tag” : “IG”,

“ description “: ““,

    “ groupChild “: [{“name”:”host_object1”,”tag”:”IH”},{“name”:”network_object1”,”tag”:”IN”}]

}

46

Copyright©  2016. SECUI. All rights reserved.

Firewall

Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

{

}

4.1.7.4  그룹  객체  수정

URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/object/groups/{orgName}

Path parameters

이름

Type

설명

orgName

string(required)  변경전  객체  이름(48자)

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

restrict : [한글숫자영문._-:]

tag

string(required)

객체  종류

Zone(I|E|D) + Type(G)

description

string

설명(128자)

groupChild

array(object)(required)  객체  목록

호스트  객체,네트워크  객체,도메인  객체만  child에

추가될  수  있다.

name,tag  속성을  갖는  주소객체의  배열을  입력한다.

application/json

{

“name” : “new_group_object”,

“tag” : “IG”,

“ description “: ““,

    “ groupChild”: [{“name”:”host_object1”,”tag”:”IH”},{“name”:”network_object1”,”tag”:”IN”}]

Copyright©  2016. SECUI. All rights reserved.

47

객체  설정

}

{

}

Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

4.1.7.5  그룹  객체  삭제

URL

DELETE http(s)://[serverip]/mf2/api/v1/firewall/object/groups/{name}

Path parameters

이름

name

Type

설명

string(required)  객체  이름(48자)

Query parameters

None

Body

None

Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.1.8  IPv6  호스트  객체

4.1.8.1  IPv6  호스트  객체  목록  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewallv6/object/hosts

48

Copyright©  2016. SECUI. All rights reserved.

Firewall

Path parameters

None

Query parameters

이름

zone

Type

string

Body

None

Returns

이름

name

tag

objIp

Type

string

string

Ipv6 address

description

adminID

string

string

lastModified

string

application/json

{

    “code”: “OK”,

    “result”: [

        {

설명

객체  Zone(internal|external|dmz)

Zone과  일치하는  객체만  조회한다.

설명

객체  이름

객체  종류

IP  주소

설명

관리자  ID

최종  수정일

            “name”: “IPv6_호스트객체”,

            “tag”: “IH”,

“objIP”: “2002::1001”,

            “ description “: ““,

            “adminID”: “admin”,

            “lastModified”: “2016-05-11 14:08:06”

        },

        …

],

“message”:”“

}

Copyright©  2016. SECUI. All rights reserved.

49

객체  설정

4.1.8.2  IPv6  호스트  객체  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewallv6/object/hosts/{name}

Path parameters

이름

name

Type

설명

string(required)  객체  이름

Query parameters

None

Body

None

Returns

이름

name

tag

objIp

Type

string

string

Ipv6 address

description

adminID

string

string

lastModified

string

application/json

{

    “code”: “OK”,

    “result”:

        {

설명

객체  이름

객체  종류

IP  주소

설명

관리자  ID

최종  수정일

            “name”: “IPv6_호스트객체”,

            “tag”: “IH”,

“objIP”: “2002::1001”,

            “ description “: ““,

            “adminID”: “admin”,

            “lastModified”: “2016-05-11 14:08:06”

        },

“message”:”“

}

50

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.1.8.3  IPv6  호스트  객체  추가

URL

POST http(s)://[serverip]/mf2/api/v1/firewallv6/object/hosts

Path parameters

None

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

tag

string(required)

객체  종류

restrict : [한글숫자영문._-:]

Zone(I|E|D) + Type(H)

설명(128자)

IP  주소

description

string

objIp

Ipv6

address(required)

application/json

{

    “name” : “IPv6_호스트객체

    “tag”: “IH”,

    “ description “: ““,

    “ objIp “: “2002::1002”

}

{

}

Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

Copyright©  2016. SECUI. All rights reserved.

51

객체  설정

4.1.8.4  IPv6  호스트  객체  수정

URL

PUT http(s)://[serverip]/mf2/api/v1/firewallv6/object/hosts/{orgName}

Path parameters

이름

Type

설명

orgName

string(required)  변경전  객체  이름(48자)

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

restrict : [한글숫자영문._-:]

tag

string(required)

객체  종류

Zone(I|E|D) + Type(H)

objIp

Ipv6

IP  주소

address(required)

description

string

설명(128자)

application/json

{

“name”: “NEW_IPv6_호스트객체”,

    “ tag “: “IH”,

    “ description “: ““,

    “ objIp “: “2002::1002”

}

{

}

Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

52

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.1.8.5  IPv6  호스트  객체  삭제

URL

DELETE http(s)://[serverip]/mf2/api/v1/firewallv6/object/hosts/{name}

Path parameters

이름

name

Type

설명

string(required)  객체  이름(48자)

Query parameters

None

Body

None

Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.1.9  IPv6  네트워크  객체

4.1.9.1  IPv6  네트워크  객체  목록  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewallv6/object/networks

Path parameters

None

Query parameters

이름

zone

Type

string

설명

객체  Zone(internal|external|dmz)

Zone과  일치하는  객체만  조회한다.

Copyright©  2016. SECUI. All rights reserved.

53

객체  설정

Body

None

Returns

이름

name

tag

objIp

Type

string

string

Ipv6 address

description

adminID

string

string

lastModified

string

application/json

{

    “code”: “OK”,

    “result”: [

        {

설명

객체  이름

객체  종류

IP  주소

설명

관리자  ID

최종  수정일

            “name”: “IPv6_네트워크객체”,

            “tag”: “IN”,

            “ objIp “: “2002::1001/127”,

            “ description “: ““,

            “adminID”: “admin”,

            “lastModified”: “2016-05-11 14:08:06”

        },

        …

],

“message”:”“

}

4.1.9.2  IPv6  네트워크  객체  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewallv6/object/networks/{name}

Path parameters

이름

name

Type

설명

string(required)  객체  이름

54

Copyright©  2016. SECUI. All rights reserved.

Firewall

Query parameters

None

Body

None

Returns

이름

name

tag

objIp

Type

string

string

Ipv6 address

description

adminID

string

string

lastModified

string

application/json

{

    “code”: “OK”,

    “result”:

        {

설명

객체  이름

객체  종류

IP  주소

설명

관리자  ID

최종  수정일

            “name”: “IPv6_네트워크객체”,

            “tag”: “IN”,

            “ objIp “: “2002::1001/127”,

            “ description “: ““,

            “adminID”: “admin”,

            “lastModified”: “2016-05-11 14:08:06”

        },

“message”:”“

}

4.1.9.3  IPv6  네트워크  객체  추가

URL

POST http(s)://[serverip]/mf2/api/v1/firewallv6/object/networks

Copyright©  2016. SECUI. All rights reserved.

55

객체  설정

Path parameters

None

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

restrict : [한글숫자영문._-:]

tag

string(required)

객체  종류

Zone(I|E|D) + Type(N)

description

string

설명(128자)

objIp

Ipv6

네트워크  IP  주소(CIDR  또는  IP범위)

address(required)

2002::1001/127 or 2002::1001:1~2002::1001:100

application/json

{

    “name”: “IPv6_네트워크객체”,

    “tag”: “IN”,

    “ description “: ““,

    “ objIp “: “2002::1001:1~2002::1001:100”

}

{

}

Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

4.1.9.4  IPv6  네트워크  객체  수정

URL

PUT http(s)://[serverip]/mf2/api/v1/firewallv6/object/networks/{orgName}

56

Copyright©  2016. SECUI. All rights reserved.

Firewall

Path parameters

이름

Type

설명

orgName

string(required)  변경전  객체  이름(48자)

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

tag

string(required)

객체  종류

Zone(I|E|D) + Type(N)

restrict : [한글숫자영문._-:]

objIp

ipv4

네트워크  IP  주소(CIDR  또는  IP범위)

address(required)

2002::1001/127 or 2002::1001:1~2002::1001:100

description

string

설명(128자)

application/json

{

“name”: “NEW_IPv6_네트워크객체”,

    “tag”: “IN”,

    “ description “: ““,

    “ objIp “: “2002::1001:1~2002::1001:100”

}

{

}

Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

4.1.9.5  IPv6  네트워크  객체  삭제

URL

DELETE http(s)://[serverip]/mf2/api/v1/firewallv6/object/networks/{name}

Copyright©  2016. SECUI. All rights reserved.

57

객체  설정

Path parameters

이름

name

Type

설명

string(required)  객체  이름

Query parameters

None

Body

None

Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.1.10  IPv6  그룹  객체

4.1.10.1  IPv6  그룹  객체  목록  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewallv6/object/groups

Path parameters

None

Query parameters

이름

zone

Type

string

Body

None

설명

객체  Zone(internal|external|dmz)

Zone과  일치하는  객체만  조회한다.

Returns

이름

name

Type

string

설명

객체  이름

58

Copyright©  2016. SECUI. All rights reserved.

tag

description

string

string

객체  종류

설명

groupChild

array(object)

객체  목록

Firewall

IPv6  호스트  객체,  IPv6  네트워크  객체만  child에  추가될

수  있다.

관리자  ID

최종  수정일

adminID

lastModified

string

string

application/json

{

    “code”: “OK”,

    “result”: [

        {

            “name”: “IPv6_그룹객체”,

            “tag”: “IG”,

“

groupChild

“:

[{“name”:”ipv6_host_object1”,”tag”:”IH”},{“name”:”

ipv6_network_object1”,”tag”:”IN”}],

            “ description “: ““,

            “adminID”: “admin”,

            “lastModified”: “2016-05-11 14:08:06”

        },

        …

],

“message”:”“

}

4.1.10.2  IPv6  그룹  객체  조회

URL

GET http(s)://[serverip]/mf2/api/v1/firewallv6/object/groups/{name}

Path parameters

이름

name

Type

설명

string(required)  객체  이름

Query parameters

None

Copyright©  2016. SECUI. All rights reserved.

59

객체  설정

Body

None

Returns

이름

name

tag

description

Type

string

string

string

설명

객체  이름

객체  종류

설명

groupChild

array(object)

객체  목록

IPv6  호스트  객체,  IPv6  네트워크  객체만  child에  추가될

adminID

lastModified

string

string

application/json

{

    “code”: “OK”,

    “result”:

        {

            “name”: “IPv6_그룹객체”,

            “tag”: “IG”,

“

수  있다.

관리자  ID

최종  수정일

groupChild

“:

[{“name”:”ipv6_host_object1”,”tag”:”IH”},{“name”:”ipv6_network_object1”,”tag”:”IN”}],

            “ description “: ““,

            “adminID”: “admin”,

            “lastModified”: “2016-05-11 14:08:06”

        },

“message”:”“

}

4.1.10.3  IPv6  그룹  객체  추가

URL

POST http(s)://[serverip]/mf2/api/v1/firewallv6/object/groups

Path parameters

None

60

Copyright©  2016. SECUI. All rights reserved.

Firewall

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

restrict : [한글숫자영문._-:]

tag

string(required)

객체  종류

Zone(I|E|D) + Type(G)

description

string

설명(128자)

groupChild

array(object)(required)  객체  목록

application/json

{

“name” : “IPv6_그룹객체”,

“tag” : “IG”,

“ description “: ““,

    “

IPv6  호스트  객체,

IPv6  네트워크  객체만  child에

추가될  수  있다.

name,tag  속성을  갖는  주소객체의  배열을  입력한다.

groupChild

“:

[{“name”:”ipv6_host_object1”,”tag”:”IH”},{“name”:”ipv6_network_object1”,”tag”:”IN”}]

}

{

}

Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

4.1.10.4  IPv6  그룹  객체  수정

URL

PUT http(s)://[serverip]/mf2/api/v1/firewallv6/object/groups/{orgName}

Copyright©  2016. SECUI. All rights reserved.

61

객체  설정

Path parameters

이름

Type

설명

orgName

string(required)  변경전  객체  이름(48자)

Query parameters

None

Body

이름

name

Type

설명

string(required)

객체  이름(48자)

restrict : [한글숫자영문._-:]

tag

string(required)

객체  종류

Zone(I|E|D) + Type(G)

description

string

설명(128자)

groupChild

array(object)(required)  객체  목록

IPv6  호스트  객체,

IPv6  네트워크  객체만  child에

추가될  수  있다.

name,tag  속성을  갖는  주소객체의  배열을  입력한다.

application/json

{

“name” : “NEW_IPv6_그룹객체”,

“tag” : “IG”,

“ description “: ““,

    “ groupChild”: [{“name”:”ipv6_host_object1”,”tag”:”IH”},{“name”:”ipv6_network_object1”,”tag”:”IN”}]

}

{

}

Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

62

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.1.10.5  IPv6  그룹  객체  삭제

URL

DELETE http(s)://[serverip]/mf2/api/v1/firewallv6/object/groups/{name}

Path parameters

이름

name

Type

설명

string(required)  객체  이름(48자)

Query parameters

None

Body

None

Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.1.11  객체  적용/취소
4.1.11.1  객체  적용

편집된  모든  객체  내용들을  운영중인  설정  파일에  적용한다.

URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/object/apply

Path parameters

None

Query parameters

None

Copyright©  2016. SECUI. All rights reserved.

63

객체  설정

Body

None

Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.1.11.2  객체  취소

편집된  모든  객체  내용들을  rollback  한다.

URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/object/cancel

Path parameters

None

Query parameters

None

Body

None

Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

64

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.2  방화벽  정책

4.2.1  방화벽  정책  목록  조회

방화벽  정책  목록을  조회  한다.

4.2.1.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewall/rules

4.2.1.2  Path parameters

None

4.2.1.3  Query parameters

None

4.2.1.4  Body

None

4.2.1.5  Returns

이름

Type

설명

ruleEnable

boolean

Rule  활성/비활성

ruleGroup

string

int

int

ruleSeq

ruleId

srcObj

users

dstObj

array(object)

출발지  객체  목록

array(object)

출발지  사용자  목록

array(object)

목적지  객체  목록

그룹  이름

순번

Rule ID

ruleSvcName

array(object)

서비스  객체  목록

ruleTime

ruleAction

ruleDesc

hitRatio

ruleAdminID

object

string

string

string

string

시간  객체

동작

설명

Hit Ratio

관리자  ID

ruleLastModifie

string

최종  수정일

d

{

application/json

Copyright©  2016. SECUI. All rights reserved.

65

방화벽  정책

“code”: “OK”, // OK or FAIL

      “result”: [{

            “ruleEnable”:”true”,

“ruleGroup”: “default”, //그룹  이름

            “ruleSeq”: “12”, //  순번

            “ruleId”: “24”, //Rule ID

            “srcObj”: [{”name”:”ANY”,”tag”:”AA”], //출발지  객체  목록

            “users”:[{”name”:”ANY”,”tag”:”UA”}], //사용자  목록

            “dstObj”: [{”name”:”1.1.1.1_IH”,”tag”:”IH”},{”name”:”2.2.2.2_IH”,”tag”:”IH”}], //목적지  객체  목록

            “ruleSvcName”: [{”name”:”ANY”,”tag”:”SA”], //서비스  객체  목록

            “ruleTime”:{“name”:”ANY”},

            “ruleAction”: “allow”, //동작

            “ruleDesc”: ““, //설명

            “hitRatio”:”10.2%”,

“ruleAdminID”: “admin”, //수정  관리자  ID

            “ruleLastModified”: “2015-10-10 12:12:12” //최종  수정일

},

{…}

],

“message”: ““ //에러  메시지

}

4.2.2  방화벽  정책  조회

하나의  정책을  조회한다.

4.2.2.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewall/rules/{ruleid}

4.2.2.2  Path parameters

이름

ruleid

Type

설명

int(required)

Rule ID

4.2.2.3  Query parameters

None

66

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.2.2.4  Body

None

4.2.2.5  Returns

이름

Type

설명

ruleEnable

boolean

Rule  활성/비활성

ruleGroup

string

int

int

ruleSeq

ruleId

srcObj

users

dstObj

array(object)

출발지  객체  목록

array(object)

출발지  사용자  목록

array(object)

목적지  객체  목록

그룹  이름

순번

Rule ID

ruleSvcName

array(object)

서비스  객체  목록

ruleTime

ruleAction

ruleDesc

hitRatio

ruleAdminID

object

string

string

string

string

시간  객체

동작

설명

Hit Ratio

관리자  ID

ruleLastModifie

string

최종  수정일

d

{

application/json

      “code”: “OK”, // OK or FAIL

      “result”: {

            “ruleEnable”:”true”,

“ruleGroup”: “default”, //그룹  이름

            “ruleSeq”: “12”, //  순번

            “ruleId”: “24”, //Rule ID

            “srcObj”: [{”name”:”ANY”,”tag”:”AA”], //출발지  객체  목록

            “users”:[{”name”:”ANY”,”tag”:”UA”}], //사용자  목록

            “dstObj”: [{”name”:”1.1.1.1_IH”,”tag”:”IH”},{”name”:”2.2.2.2_IH”,”tag”:”IH”}], //목적지  객체  목록

            “ruleSvcName”: [{”name”:”ANY”,”tag”:”SA”], //서비스  객체  목록

            “ruleTime”:{“name”:”ANY”},

            “ruleAction”: “allow”, //동작

            “hitRatio”:”10.2%”,

            “ruleDesc”: ““, //설명

Copyright©  2016. SECUI. All rights reserved.

67

방화벽  정책

“ruleAdminID”: “admin”, //수정  관리자  ID

            “ruleLastModified”: “2015-10-10 12:12:12” //최종  수정일

},

“message”: ““ //에러  메시지

}

4.2.3  방화벽  정책  추가

하나의  정책을  추가한다.

4.2.3.1  URL

POST http(s)://[serverip]/mf2/api/v1/firewall/rules

4.2.3.2  Path parameters

None

4.2.3.3  Query parameters

None

4.2.3.4  Body

이름

Type

설명

ruleGroup

string(required)  그룹  이름

ruleEnable

boolean(required)  사용

ruleSeq

srcObj

int(required)

순번

array(object)

출발지  주소

(required)

objIp  속성  사용시  해당  IP로  객체  생성  후

정책에  자동  추가.

(object1, object 2, object 3 … object 60)

users

dstObj

array(object)

출발지  사용자  목록

array(object)

목적지  주소

(required)

objIp  속성  사용시  해당  IP로  객체  생성  후

정책에  자동  추가.

(object1, object 2, object 3 … object 60)

ruleSvcName

array(object)

서비스  객체

svcObjProtocol, svcObjPort  속성  사용시  해당  정보로  객체

생성  후  정책에  자동  추가

68

Copyright©  2016. SECUI. All rights reserved.

Firewall

ruleTime

object

시간  객체

(object1, object 2, object 3 … object 60)

timeObjInterval  속성  사용시  해당  기간으로  시간객체  생성

후

정책에  자동  추가.

ruleAction

string(required)  동작(allow | deny | reject(icmp) | reject(reset))

ruleDesc

string

설명

application/json

{

}

“ruleGroup”: “default”,

“ruleEnable”:”true”,

“ruleSeq”: “1”,

“srcObj”: [{”name”:”host1”,”tag”:”IH”},{objIp:”1.1.1.2”,”tag”:”IH”},{objIp:”10.10.10.0/24”,”tag”:”IN”}],

“users”:[{”name”:”ANY”,”tag”:”UA”}],

“dstObj”: [{name:”ANY“,”tag”:”AA”}], //ANY

“ruleSvcName”: [{”name”:”tcp_80”},{“svcObjProtocol”:”TCP”, “svcObjPort”:”8443-8449”}],

“ruleTime”:{“name”:”ANY”},

“ruleAction”: “allow”,

“ruleDesc”: ““

설명

Rule ID

4.2.3.5  Returns

이름

ruleId

Type

int

application/json

{

}

“code”:”OK”,

“result”: {

    “ruleId”:123

}

“message”:”“

4.2.4  방화벽  정책  수정

정책을  수정한다.

Copyright©  2016. SECUI. All rights reserved.

69

방화벽  정책

4.2.4.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/rules/{ruleid}

4.2.4.2  Path parameters

이름

ruleid

Type

설명

int(required)

Rule ID

4.2.4.3  Query parameters

None

4.2.4.4  Body

이름

Type

설명

ruleEnable

boolean(required)  사용

srcObj

array(object)

출발지  주소

(required)

objIp  속성  사용시  해당  IP로  객체  생성  후

정책에  자동  추가.

(object1, object 2, object 3 … object 60)

users

dstObj

array(object)

출발지  사용자  목록

array(object)

목적지  주소

(required)

objIp  속성  사용시  해당  IP로  객체  생성  후

정책에  자동  추가.

(object1, object 2, object 3 … object 60)

ruleSvcName

array(object)

서비스  객체

ruleTime

object

시간  객체

svcObjProtocol, svcObjPort  속성  사용시  해당  정보로  객체

(object1, object 2, object 3 … object 60)

timeObjInterval  속성  사용시  해당  기간으로  시간객체  생성

후

정책에  자동  추가.

ruleAction

string(required)  동작(allow | deny | reject(icmp) | reject(reset))

ruleDesc

string

설명

application/json

{

“ruleEnable”:”true”,

“srcObj”: [{objIp:”1.1.1.1”,”tag”:”IH”},{objIp:”1.1.1.2”,”tag”:”IH”},{objIp:”10.10.10.0/24”,”tag”:”IN”}],

70

Copyright©  2016. SECUI. All rights reserved.

Firewall

“users”:[{”name”:”ANY”,”tag”:”UA”}],

“dstObj”: [{name:”ANY“,”tag”:”AA”}], //ANY

“ruleSvcName”: [{”name”:”tcp_80”},{“svcObjProtocol”:”TCP”, “svcObjPort”:”8888”}],

“ruleTime”:{“timeObjInterval”:”2015-02-27 00:00~2015-03-20 23:59”},

“ruleAction”: “allow”,

“ruleDesc”: ““

4.2.4.5  Returns

application/json

“code”:”OK”,

“message”:”“

}

{

}

4.2.5  방화벽  정책  삭제

정책을  삭제한다.

4.2.5.1  URL

DELETE http(s)://[serverip]/mf2/api/v1/firewall/rules/{ruleid}

4.2.5.2  Path parameters

이름

ruleid

Type

설명

int(required)

Rule ID

4.2.5.3  Query parameters

None

4.2.5.4  Body

None

4.2.5.5  Returns

application/json

{

“code”:”OK”,

Copyright©  2016. SECUI. All rights reserved.

71

방화벽  정책

“message”:”“

}

4.2.6  방화벽  정책  이동-최상위로

정책  rule을  최상위  위치로  이동한다.

4.2.6.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/rules/move/top

4.2.6.2  Path parameters

None

4.2.6.3  Query parameters

None

4.2.6.4  Body

이름

ruleid

Type

설명

string(required)

rule ID

application/json

{

}

{

}

“ruleid”: “10”

4.2.6.5  Returns

application/json

“code”:”OK”,

“message”:”“

4.2.7  방화벽  정책  이동-최하위로

정책  rule을  최하위  위치로  이동한다.

72

Copyright©  2016. SECUI. All rights reserved.

4.2.7.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/rules/move/bottom

Firewall

4.2.7.2  Path parameters

None

4.2.7.3  Query parameters

None

4.2.7.4  Body

이름

ruleid

Type

설명

string(required)

rule ID

application/json

{

}

{

}

“ruleid”: “10”

4.2.7.5  Returns

application/json

“code”:”OK”,

“message”:”“

4.2.8  방화벽  정책  이동-위로
정책  rule을  위로  이동한다.

4.2.8.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/rules/move/before

4.2.8.2  Path parameters

None

Copyright©  2016. SECUI. All rights reserved.

73

방화벽  정책

4.2.8.3  Query parameters

None

4.2.8.4  Body

이름

ruleid

Type

설명

string(required)  이동할  정책의  rule ID

baseruleid

string(required)  대상  ruleid  위로  이동

application/json

“ruleid”: “10”,

“baseruleid”: “20”,

4.2.8.5  Returns

application/json

“code”:”OK”,

“message”:”“

{

}

{

}

4.2.9  방화벽  정책  이동-아래로
정책  rule을  아래로  이동한다.

4.2.9.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/rules/move/after

4.2.9.2  Path parameters

None

4.2.9.3  Query parameters

None

4.2.9.4  Body

이름

Type

설명

74

Copyright©  2016. SECUI. All rights reserved.

ruleid

string(required)

rule ID

baseruleid

string(required)  대상  ruleid  아래로  이동

Firewall

application/json

“ruleid”: “10”,

“baseruleid”: “20”,

4.2.9.5  Returns

application/json

“code”:”OK”,

“message”:”“

{

}

{

}

4.2.10  방화벽  정책  내용  검색

검색  조건에  따른  정책  내용을  검색한다.

최소  하나  이상의  조건이  입력되어야  한다.

관련  정보  (객체)포함  옵션에  따라  결과  포맷이  달라질  수  있으므로  4.2.10.5  Returns  항목을

참고  한다.

4.2.10.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewall/rules/search/rule

4.2.10.2  Path parameters

None

4.2.10.3  Query parameters

이름

enable

Type

boolean

설명

사용

srcObj

string

1)출발지  객체  이름

true일  경우  활성화된  rule만  검색

2)상세  검색  옵션  >  객체  내용  검색  옵션이  켜질  경우  객체

이름  대신  IP  정보  입력

단일)1.2.3.4 , CIDR)1.1.1.0/24

Copyright©  2016. SECUI. All rights reserved.

75

방화벽  정책

객체  이름

name

string

객체  이름

상세  검색  옵션

csensitive

boolean  대소문자  구분(Case Sensitive)

wword

boolean  완전  일치(Whole Word)

cobject

boolean  객체  내용  검색

relation

boolean  관련  정보  (객체)포함

속성  이름과  값은  ‘%3D’문자로  구분하고  파라미터  구분은

‘,’문자를  사용한다.

cobject가  true이면  name은  IP주소  형식만  입력할  수  있다.

srcObj=name%3Dobject

srcObj=name%3Dobject,csensitive%3Dtrue

srcObj=name%3Dobject,csensitive%3Dtrue,wword%3Dtrue

srcObj=name%3D1.1.1.0/24,cobject%3Dtrue

user

userOpt

string

string

도메인\사용자  ID  또는  사용자  ID

사용자  상세  검색  옵션

csensitive

boolean  대소문자  구분(Case Sensitive)

wword

boolean  완전  일치(Whole Word)

relation

boolean  관련  정보  (객체)포함

속성  이름과  값은  ‘%3D’문자로  구분하고  파라미터  구분은

‘,’문자를  사용한다.

userOpt=csensitive%3Dtrue

userOpt=csensitive%3Dtrue,wword%3Dtrue

dstObj

string

1)목적지  객체  이름

2)상세  검색  옵션  >  객체  내용  검색  옵션이  켜질  경우  객체

이름  대신  IP  정보  입력

단일)1.2.3.4 , CIDR)1.1.1.0/24

객체  이름

name

string

객체  이름

상세  검색  옵션

csensitive

boolean  대소문자  구분(Case Sensitive)

wword

boolean  완전  일치(Whole Word)

76

Copyright©  2016. SECUI. All rights reserved.

Firewall

cobject

boolean  객체  내용  검색

relation

boolean  관련  정보  (객체)포함

속성  이름과  값은  ‘%3D’문자로  구분하고  파라미터  구분은

‘,’문자를  사용한다.

cobject가  true이면  name은  IP주소  형식만  입력할  수  있다.

dstObj=name%3Dobject

dstObj=name%3Dobject,csensitive%3Dtrue

dstObj=name%3Dobject,csensitive%3Dtrue,wword%3Dtrue

dstObj=name%3D1.1.1.0/24,cobject%3Dtrue

svcObj

string

1)서비스  객체  이름

2)상세  검색  옵션  >  객체  내용  검색  옵션이  켜질  경우  객체

이름  대신  Protocol:Port  정보  입력

Protocol:Port => TCP:80

객체  이름

name

string

객체  이름

상세  검색  옵션

csensitive

boolean  대소문자  구분(Case Sensitive)

wword

boolean  완전  일치(Whole Word)

cobject

boolean  객체  내용  검색

relation

boolean  관련  정보  (객체)포함

속성  이름과  값은  ‘%3D’문자로  구분하고  파라미터  구분은

‘,’문자를  사용한다.

svcObj=name%3Dobject

svcObj=name%3Dobject,csensitive%3Dtrue

svcObj=name%3Dobject,csensitive%3Dtrue,wword%3Dtrue

svcObj=name%3DTCP:80,cobject%3Dtrue

srcPort

dstPort

action

desc

int

int

string

string

출발지  포트(0~65535)

목적지  포트(0~65535)

동작(allow | deny | reject(icmp) | reject(reset))

설명

Copyright©  2016. SECUI. All rights reserved.

77

방화벽  정책

4.2.10.4  Body

None

4.2.10.5  Returns

관련 정보 (객체)포함 옵션 False 결과 포맷

이름

ruleSeq

ruleId

Type

int

int

application/json

{

    “code”: “OK”, // OK or FAIL

설명

순번

Rule ID

    “result”: [

        {

            “ruleSeq”: 1,

            “ruleId”: 10

},

        {…}

    ],

    “message”: ““

}

관련 정보 (객체)포함 옵션 True 결과 포맷

배열

relations

이름

field

Type

string

설명

검색  항목( src | dst | svc | aut )

src :  출발지, dst :  목적지, svc :  서비스, aut  사용자

name

ruleSeq

ruleId

string

객체  이름

int

int

순번

Rule ID

application/json

rules

{

    “code”: “OK”, // OK or FAIL

    “result”: {

"relations": [

{

    "field":"src",

    "name":"object_name"

}

78

Copyright©  2016. SECUI. All rights reserved.

Firewall

],

"rules": [

{

    "ruleSeq":1,

    "ruleId":10

}

],

"message":""

}

4.2.11  방화벽  Shadow  정책  검색
Shadow된  rule을  검색한다.

4.2.11.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewall/rules/search/shadow

4.2.11.2  Path parameters

None

4.2.11.3  Query parameters

이름

ruleid

Type

int

설명

rule ID (0~99999999)

0 : shadow된  모든  rule

includeDisable  boolean

비활성화된  정책도  포함

4.2.11.4  Body

None

4.2.11.5  Returns

이름

ruleSeq

ruleId

Type

int

int

설명

순번

Rule ID

shadowRuleId

int

상위  정책  ID

desc

string

설명

Copyright©  2016. SECUI. All rights reserved.

79

방화벽  정책

application/json

{

    “code”: “OK”, // OK or FAIL

    “result”: [

        {

            “ruleSeq”: 1,

            “ruleId”: 10,

            “shadowRuleId”:123,

            “desc”:”Partially shadowed”

},

        {…}

    ],

    “message”: ““

}

4.2.12  방화벽  시간만료  정책  검색

시간이  만료된  rule을  검색한다.

4.2.12.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewall/rules/search/expired

4.2.12.2  Path parameters

None

4.2.12.3  Query parameters

이름

limit

Type

int

설명

만료  기한, 0~365(일)

includeDisable  boolean

비활성화된  정책  포함

0 :  현재  기준으로  만료된  정책만  검색

1  이상  :  입력한  기한내에  만료되는  정책까지  포함하여  검색

4.2.12.4  Body

None

4.2.12.5  Returns

80

Copyright©  2016. SECUI. All rights reserved.

Firewall

설명

순번

Rule ID

남은  기간

이름

ruleSeq

ruleId

Type

int

int

remainDay

string

application/json

{

    “code”: “OK”, // OK or FAIL

    “result”: [

        {

            “ruleSeq”: 1,

            “ruleId”: 10,

“remainDay”:”Expired(-133 days 1 hr 17 mins 53 secs)”

},

        {…}

    ],

    “message”: ““

}

4.2.13  방화벽  미참조  정책  검색

적용된  정책에  대한  검색  결과만  제공한다.

편중  중인  정책은  검색  대상에  포함되지  않는다.

상위  정책과  내용이  중복되어  있거나,  중복되어  있지는  않지만  실제  유입된  패킷이  없어서

참조되고  있지  않는  정책에  대한  검색입니다.

4.2.13.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewall/rules/search/nonrule

4.2.13.2  Path parameters

None

4.2.13.3  Query parameters

Type

설명

int(required)

미참조  일,1~365(일)

이름

day

Copyright©  2016. SECUI. All rights reserved.

81

방화벽  정책

4.2.13.4  Body

None

4.2.13.5  Returns

이름

ruleSeq

ruleId

Type

int

int

nonReference

int

설명

순번

Rule ID

미참조  일

ruleCreate

string

정책  생성일

-1 :  현재까지  참조기록  없음

application/json

{

    “code”: “OK”, // OK or FAIL

    “result”: [

        {

            “ruleSeq”: 1,

            “ruleId”: 10,

            “nonReference”:144,

“ruleCreate”:”2016-07-19 11:29:11”

},

        {…}

    ],

    “message”: ““

}

4.2.14  방화벽  미참조  객체  검색

적용된  정책에  대한  검색  결과만  제공한다.

편중  중인  정책은  검색  대상에  포함되지  않는다.

정책에  사용된  주소/서비스  객체의  내용이  다른  객체  내용과  중복  되었거나,  중복되어

있지는  않지만  실제  유입된  패킷이  없어서  참조되지  않는  객체에  대한  검색입니다.

4.2.14.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewall/rules/search/nonobject

82

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.2.14.2  Path parameters

None

4.2.14.3  Query parameters

Type

설명

int(required)

미참조  일,1~365(일)

이름

day

4.2.14.4  Body

None

4.2.14.5  Returns

이름

tag

name

Type

string

string

nonReference

int

설명

객체  종류

객체  이름

미참조  일

historyRuleId

int

참조  이력  정책  ID

-1 :  현재까지  참조기록  없음

-99 :  현재까지  참조된  정책  없음

application/json

{

    “code”: “OK”, // OK or FAIL

    “result”: [

        {

            “tag”: “EH”,

            “name”: “ExternalHost”,

“nonReference”:144,

“historyRuleId”:123

},

        {…}

    ],

    “message”: ““

}

4.2.15  방화벽  적용  정책  검색

적용된  정책에  대한  검색  결과만  제공한다.

Copyright©  2016. SECUI. All rights reserved.

83

방화벽  정책

편중  중인  정책은  검색  대상에  포함되지  않는다.

정책  사용  여부,  시간  객체  설정,  예외  객체  설정  내용을  반영하여,  유입된  패킷이  정확히

어떤  정책으로  필터링  되는지를  확인해  줍니다.

4.2.15.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewall/rules/search/applyrule

4.2.15.2  Path parameters

None

4.2.15.3  Query parameters

Type

설명

string(required)  유입  zone(internal | external | dmz)

이름

zone

protocol

string(required)  프로토콜  이름

ICMP, IPv6-ICMP :  목적지  포트  필수(0~255)

TCP,UDP :  출발지/목적지  포트  필수(0~65535)

나머지  프로토콜은  포트  입력이  불가하다.

srcIp

dstIp

srcPort

dstPort

string(required)  출발지  주소

string(required)  목적지  주소

int

int

출발지  포트

TCP,UDP :  출발지  포트  필수(0~65535)

목적지  포트

ICMP, IPv6-ICMP :  목적지  포트  필수(0~255)

TCP,UDP :  목적지  포트  필수(0~65535)

time

string

유입시간

YYYYMMDDhhmmss

ex)20161010121000

4.2.15.4  Body

None

4.2.15.5  Returns

이름

Type

설명

84

Copyright©  2016. SECUI. All rights reserved.

ruleSeq

ruleId

int

int

순번

Rule ID

ruleAction

string

동작(allow | deny | reject(icmp) | reject(reset))

Firewall

application/json

{

    “code”: “OK”, // OK or FAIL

    “result”: [

        {

            “ruleSeq”: 4,

“ruleId”:17,

“ruleAction”:”allow”

},

        {…}

    ],

    “message”: ““

}

4.2.16  방화벽  정책그룹  목록  조회
정책  그룹  목록을  조회한다.

4.2.16.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewall/rules/groups

4.2.16.2  Path parameters

None

4.2.16.3  Query parameters

None

4.2.16.4  Body

None

4.2.16.5  Returns

이름

id

Type

string

설명

정책  그룹  ID

Copyright©  2016. SECUI. All rights reserved.

85

정책  그룹  이름

정책  그룹  설명

방화벽  정책

name

desc

string

string

application/json

{

    “code”: “OK”, // OK or FAIL

    “result”: [

        {

            “id”: 1,

            “name”: “default”,

            “desc”: “default rule-group”

        },

        {…}

    ],

    “message”: ““

}

4.2.17  방화벽  정책그룹  추가
정책  그룹을  추가한다.

4.2.17.1  URL

POST http(s)://[serverip]/mf2/api/v1/firewall/rules/groups

4.2.17.2  Path parameters

None

4.2.17.3  Query parameters

None

4.2.17.4  Body

이름

name

desc

Type

설명

string(required)  정책  그룹  이름

string

정책  그룹  설명

application/json

{

“name”: ““,

“desc”: ““

86

Copyright©  2016. SECUI. All rights reserved.

Firewall

}

{

}

4.2.17.5  Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

4.2.18  방화벽  정책그룹  삭제
정책  그룹을  삭제한다.

정책  그룹  내에  포함된  정책이  하나도  없을  경우에만  삭제가  가능하다.

4.2.18.1  URL

DELETE http(s)://[serverip]/mf2/api/v1/firewall/rules/groups/{name}

4.2.18.2  Path parameters

이름

name

Type

설명

string(required)  정책  그룹  이름

4.2.18.3  Query parameters

None

4.2.18.4  Body

None

4.2.18.5  Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.2.19  방화벽  정책  임시  저장  조회

임시  저장된  정책  파일이  존재하는지  조회한다.

Copyright©  2016. SECUI. All rights reserved.

87

방화벽  정책

4.2.19.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewall/rules/temp

4.2.19.2  Path parameters

None

4.2.19.3  Query parameters

None

설명

임시  저장  파일  존재  여부

true :  정책  임시  저장  파일  존재

false :  정책  임시  저장  파일  없음

4.2.19.4  Body

None

4.2.19.5  Returns

이름

temp

Type

boolean

application/json

{

    "code": "OK",

    "result": {

        "temp": true

    }

}

4.2.20  방화벽  정책  임시  저장
정책을  임시  저장한다.

4.2.20.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/rules/temp

4.2.20.2  Path parameters

None

88

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.2.20.3  Query parameters

None

4.2.20.4  Body

None

4.2.20.5  Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.2.21  방화벽  정책  임시  저장  파일  삭제
임시  저장한  정책  파일을  삭제한다.

4.2.21.1  URL

DELETE http(s)://[serverip]/mf2/api/v1/firewall/rules/temp

4.2.21.2  Path parameters

None

4.2.21.3  Query parameters

None

4.2.21.4  Body

None

4.2.21.5  Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

Copyright©  2016. SECUI. All rights reserved.

89

방화벽  정책

4.2.22  방화벽  정책  임시  저장  파일  적용

임시  저장된  방화벽  정책을  적용한다.

4.2.22.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/rules/temp-apply

4.2.22.2  Path parameters

None

4.2.22.3  Query parameters

None

4.2.22.4  Body

None

4.2.22.5  Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.2.23  방화벽  정책  적용

편집된  모든  rule  내용들을  운영중인  설정  파일에  적용한다.

4.2.23.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/rules/apply

4.2.23.2  Path parameters

None

90

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.2.23.3  Query parameters

None

4.2.23.4  Body

None

4.2.23.5  Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.2.24  방화벽  정책  취소

편집된  모든  rule  내용들을  rollback  한다.

4.2.24.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewall/rules/cancel

4.2.24.2  Path parameters

None

4.2.24.3  Query parameters

None

4.2.24.4  Body

None

4.2.24.5  Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

Copyright©  2016. SECUI. All rights reserved.

91

IPv6  방화벽  정책

4.3  IPv6  방화벽  정책

4.3.1  IPv6  방화벽  정책  목록  조회

IPv6  방화벽  정책  목록을  조회  한다.

4.3.1.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewallv6/rules

4.3.1.2  Path parameters

None

4.3.1.3  Query parameters

None

4.3.1.4  Body

None

4.3.1.5  Returns

이름

Type

설명

ruleEnable

boolean

Rule  활성/비활성

ruleGroup

string

int

int

ruleSeq

ruleId

srcObj

users

dstObj

array(object)

출발지  객체  목록

array(object)

출발지  사용자  목록

array(object)

목적지  객체  목록

그룹  이름

순번

Rule ID

ruleSvcName

array(object)

서비스  객체  목록

ruleTime

ruleAction

ruleDesc

hitRatio

ruleAdminID

object

string

string

string

string

시간  객체

동작

설명

Hit Ratio

관리자  ID

ruleLastModifie

string

최종  수정일

92

Copyright©  2016. SECUI. All rights reserved.

Firewall

d

{

application/json

“code”: “OK”, // OK or FAIL

      “result”: [{

            “ruleEnable”:”true”,

“ruleGroup”: “default”, //그룹  이름

            “ruleSeq”: “12”, //  순번

            “ruleId”: “24”, //Rule ID

            “srcObj”: [{”name”:”ANY”,”tag”:”AA”], //출발지  객체  목록

            “users”:[{”name”:”ANY”,”tag”:”UA”}], //사용자  목록

            “dstObj”: [{”name”:”1::1_IH”,”tag”:”IH”},{”name”:”1::2_IH”,”tag”:”IH”}], //목적지  객체  목록

            “ruleSvcName”: [{”name”:”ANY”,”tag”:”SA”], //서비스  객체  목록

            “ruleTime”:{“name”:”ANY”},

            “ruleAction”: “allow”, //동작

            “ruleDesc”: ““, //설명

            “hitRatio”:”10.2%”,

“ruleAdminID”: “admin”, //수정  관리자  ID

            “ruleLastModified”: “2015-10-10 12:12:12” //최종  수정일

},

{…}

],

“message”: ““ //에러  메시지

}

4.3.2  IPv6  방화벽  정책  조회

하나의  정책을  조회한다.

4.3.2.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewallv6/rules/{ruleid}

4.3.2.2  Path parameters

이름

ruleid

Type

설명

int(required)

Rule ID

Copyright©  2016. SECUI. All rights reserved.

93

IPv6  방화벽  정책

4.3.2.3  Query parameters

None

4.3.2.4  Body

None

4.3.2.5  Returns

이름

Type

설명

ruleEnable

boolean

Rule  활성/비활성

ruleGroup

string

int

int

ruleSeq

ruleId

srcObj

users

dstObj

array(object)

출발지  객체  목록

array(object)

출발지  사용자  목록

array(object)

목적지  객체  목록

그룹  이름

순번

Rule ID

ruleSvcName

array(object)

서비스  객체  목록

ruleTime

ruleAction

ruleDesc

hitRatio

ruleAdminID

object

string

string

string

string

시간  객체

동작

설명

Hit Ratio

관리자  ID

ruleLastModifie

string

최종  수정일

d

{

application/json

      “code”: “OK”, // OK or FAIL

      “result”: {

            “ruleEnable”:”true”,

“ruleGroup”: “default”, //그룹  이름

            “ruleSeq”: “12”, //  순번

            “ruleId”: “24”, //Rule ID

            “srcObj”: [{”name”:”ANY”,”tag”:”AA”], //출발지  객체  목록

            “users”:[{”name”:”ANY”,”tag”:”UA”}], //사용자  목록

“dstObj”: [{”name”:”1::1_IH”,”tag”:”IH”},{”name”:”1::2_IH”,”tag”:”IH”}], //목적지  객체  목록

            “ruleSvcName”: [{”name”:”ANY”,”tag”:”SA”], //서비스  객체  목록

            “ruleTime”:{“name”:”ANY”},

94

Copyright©  2016. SECUI. All rights reserved.

Firewall

            “ruleAction”: “allow”, //동작

            “hitRatio”:”10.2%”,

            “ruleDesc”: ““, //설명

“ruleAdminID”: “admin”, //수정  관리자  ID

            “ruleLastModified”: “2015-10-10 12:12:12” //최종  수정일

},

“message”: ““ //에러  메시지

}

4.3.3  IPv6  방화벽  정책  추가

하나의  정책을  추가한다.

4.3.3.1  URL

POST http(s)://[serverip]/mf2/api/v1/firewall6/rules

4.3.3.2  Path parameters

None

4.3.3.3  Query parameters

None

4.3.3.4  Body

이름

Type

설명

ruleGroup

string(required)  그룹  이름

ruleEnable

boolean(required)  사용

ruleSeq

srcObj

int(required)

순번

array(object)

출발지  주소

(required)

objIp  속성  사용시  해당  IP로  객체  생성  후

정책에  자동  추가.

(object1, object 2, object 3 … object 60)

users

dstObj

array(object)

출발지  사용자  목록

array(object)

목적지  주소

(required)

objIp  속성  사용시  해당  IP로  객체  생성  후

정책에  자동  추가.

(object1, object 2, object 3 … object 60)

Copyright©  2016. SECUI. All rights reserved.

95

IPv6  방화벽  정책

ruleSvcName

array(object)

서비스  객체

svcObjProtocol, svcObjPort  속성  사용시  해당  정보로  객체

생성  후  정책에  자동  추가

(object1, object 2, object 3 … object 60)

ruleTime

object

시간  객체

timeObjInterval  속성  사용시  해당  기간으로  시간객체  생성

후

정책에  자동  추가.

ruleAction

string(required)  동작(allow | deny | reject(icmp) | reject(reset))

ruleDesc

string

설명

application/json

{

}

“ruleGroup”: “default”,

“ruleEnable”:”true”,

“ruleSeq”: “1”,

“srcObj”: [{”name”:”host1”,”tag”:”IH”},{objIp:”1::2”,”tag”:”IH”},{objIp:”1::4”,”tag”:”IN”}],

“users”:[{”name”:”ANY”,”tag”:”UA”}],

“dstObj”: [{name:”ANY“,”tag”:”AA”}], //ANY

“ruleSvcName”: [{”name”:”tcp_80”},{“svcObjProtocol”:”TCP”, “svcObjPort”:”8443-8449”}],

“ruleTime”:{“name”:”ANY”},

“ruleAction”: “allow”,

“ruleDesc”: ““

설명

Rule ID

4.3.3.5  Returns

이름

ruleId

Type

int

application/json

{

}

“code”:”OK”,

“result”: {

    “ruleId”:123

}

“message”:”“

96

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.3.4  IPv6  방화벽  정책  수정
정책을  수정한다.

4.3.4.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewallv6/rules/{ruleid}

4.3.4.2  Path parameters

이름

ruleid

Type

설명

int(required)

Rule ID

4.3.4.3  Query parameters

None

4.3.4.4  Body

이름

Type

설명

ruleEnable

boolean(required)  사용

srcObj

array(object)

출발지  주소

(required)

objIp  속성  사용시  해당  IP로  객체  생성  후

정책에  자동  추가.

(object1, object 2, object 3 … object 60)

users

dstObj

array(object)

출발지  사용자  목록

array(object)

목적지  주소

(required)

objIp  속성  사용시  해당  IP로  객체  생성  후

정책에  자동  추가.

(object1, object 2, object 3 … object 60)

ruleSvcName

array(object)

서비스  객체

ruleTime

object

시간  객체

svcObjProtocol, svcObjPort  속성  사용시  해당  정보로  객체

(object1, object 2, object 3 … object 60)

timeObjInterval  속성  사용시  해당  기간으로  시간객체  생성

후

정책에  자동  추가.

ruleAction

string(required)  동작(allow | deny | reject(icmp) | reject(reset))

ruleDesc

string

설명

application/json

Copyright©  2016. SECUI. All rights reserved.

97

IPv6  방화벽  정책

{

}

{

}

“ruleEnable”:”true”,

“srcObj” : [{”name”:”host1”,”tag”:”IH”},{objIp:”1::2”,”tag”:”IH”},{objIp:”1::4”,”tag”:”IN”}],

“users”:[{”name”:”ANY”,”tag”:”UA”}],

“dstObj”: [{name:”ANY“,”tag”:”AA”}], //ANY

“ruleSvcName”: [{”name”:”tcp_80”},{“svcObjProtocol”:”TCP”, “svcObjPort”:”8888”}],

“ruleTime”:{“timeObjInterval”:”2015-02-27 00:00~2015-03-20 23:59”},

“ruleAction”: “allow”,

“ruleDesc”: ““

4.3.4.5  Returns

application/json

“code”:”OK”,

“message”:”“

4.3.5  IPv6  방화벽  정책  삭제
정책을  삭제한다.

4.3.5.1  URL

DELETE http(s)://[serverip]/mf2/api/v1/firewallv6/rules/{ruleid}

4.3.5.2  Path parameters

이름

ruleid

Type

설명

int(required)

Rule ID

4.3.5.3  Query parameters

None

4.3.5.4  Body

None

98

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.3.5.5  Returns

application/json

{

}

“code”:”OK”,

“message”:”“

4.3.6  IPv6  방화벽  정책  이동-최상위로

정책  rule을  최상위  위치로  이동한다.

4.3.6.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewallv6/rules/move/top

4.3.6.2  Path parameters

None

4.3.6.3  Query parameters

None

4.3.6.4  Body

이름

ruleid

Type

설명

string(required)

rule ID

application/json

{

}

{

}

“ruleid”: “10”

4.3.6.5  Returns

application/json

“code”:”OK”,

“message”:”“

Copyright©  2016. SECUI. All rights reserved.

99

IPv6  방화벽  정책

4.3.7  IPv6  방화벽  정책  이동-최하위로

정책  rule을  최하위  위치로  이동한다.

4.3.7.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewallv6/rules/move/bottom

4.3.7.2  Path parameters

None

4.3.7.3  Query parameters

None

4.3.7.4  Body

이름

ruleid

Type

설명

string(required)

rule ID

application/json

{

}

{

}

“ruleid”: “10”

4.3.7.5  Returns

application/json

“code”:”OK”,

“message”:”“

4.3.8  IPv6  방화벽  정책  이동-위로
정책  rule을  위로  이동한다.

4.3.8.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewallv6/rules/move/before

100

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.3.8.2  Path parameters

None

4.3.8.3  Query parameters

None

4.3.8.4  Body

이름

ruleid

Type

설명

string(required)  이동할  정책의  rule ID

baseruleid

string(required)  대상  ruleid  위로  이동

application/json

“ruleid”: “10”,

“baseruleid”: “20”,

4.3.8.5  Returns

application/json

“code”:”OK”,

“message”:”“

{

}

{

}

4.3.9  IPv6  방화벽  정책  이동-아래로
정책  rule을  아래로  이동한다.

4.3.9.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewallv6/rules/move/after

4.3.9.2  Path parameters

None

4.3.9.3  Query parameters

None

Copyright©  2016. SECUI. All rights reserved.

101

IPv6  방화벽  정책

4.3.9.4  Body

이름

ruleid

Type

설명

string(required)

rule ID

baseruleid

string(required)  대상  ruleid  아래로  이동

application/json

“ruleid”: “10”,

“baseruleid”: “20”,

4.3.9.5  Returns

application/json

“code”:”OK”,

“message”:”“

{

}

{

}

4.3.10  IPv6  방화벽  정책  내용  검색

검색  조건에  따른  정책  내용을  검색한다.

최소  하나  이상의  조건이  입력되어야  한다.

관련  정보  (객체)포함  옵션에  따라  결과  포맷이  달라질  수  있으므로  4.3.10.5  Returns  항목을

참고  한다.

4.3.10.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewallv6/rules/search/rule

4.3.10.2  Path parameters

None

4.3.10.3  Query parameters

이름

enable

Type

boolean

설명

사용

srcObj

string

1)출발지  객체  이름

true일  경우  활성화된  rule만  검색

2)상세  검색  옵션  >  객체  내용  검색  옵션이  켜질  경우  객체

102

Copyright©  2016. SECUI. All rights reserved.

Firewall

이름  대신  IP  정보  입력

단일)123::1 , CIDR)123::/64

객체  이름

name

string

객체  이름

상세  검색  옵션

csensitive

boolean  대소문자  구분(Case Sensitive)

wword

boolean  완전  일치(Whole Word)

cobject

boolean  객체  내용  검색

relation

boolean  관련  정보  (객체)포함

속성  이름과  값은  ‘%3D’문자로  구분하고  파라미터  구분은

‘,’문자를  사용한다.

cobject가  true이면  name은  IP주소  형식만  입력할  수  있다.

srcObj=name%3Dobject

srcObj=name%3Dobject,csensitive%3Dtrue

srcObj=name%3Dobject,csensitive%3Dtrue,wword%3Dtrue

srcObj=name%3D123::/64,cobject%3Dtrue

user

userOpt

string

string

도메인\사용자  ID  또는  사용자  ID

사용자  상세  검색  옵션

csensitive

boolean  대소문자  구분(Case Sensitive)

wword

boolean  완전  일치(Whole Word)

relation

boolean  관련  정보  (객체)포함

속성  이름과  값은  ‘%3D’문자로  구분하고  파라미터  구분은

‘,’문자를  사용한다.

userOpt=csensitive%3Dtrue

userOpt=csensitive%3Dtrue,wword%3Dtrue

dstObj

string

1)목적지  객체  이름

2)상세  검색  옵션  >  객체  내용  검색  옵션이  켜질  경우  객체

이름  대신  IP  정보  입력

단일)123::1 , CIDR)123::/64

객체  이름

name

string

객체  이름

Copyright©  2016. SECUI. All rights reserved.

103

IPv6  방화벽  정책

상세  검색  옵션

csensitive

boolean  대소문자  구분(Case Sensitive)

wword

boolean  완전  일치(Whole Word)

cobject

boolean  객체  내용  검색

relation

boolean  관련  정보  (객체)포함

속성  이름과  값은  ‘%3D’문자로  구분하고  파라미터  구분은

‘,’문자를  사용한다.

cobject가  true이면  name은  IP주소  형식만  입력할  수  있다.

dstObj=name%3Dobject

dstObj=name%3Dobject,csensitive%3Dtrue

dstObj=name%3Dobject,csensitive%3Dtrue,wword%3Dtrue

dstObj=name%3D123::/64,cobject%3Dtrue

svcObj

string

1)서비스  객체  이름

2)상세  검색  옵션  >  객체  내용  검색  옵션이  켜질  경우  객체

이름  대신  Protocol:Port  정보  입력

Protocol:Port => TCP:80

객체  이름

name

string

객체  이름

상세  검색  옵션

csensitive

boolean  대소문자  구분(Case Sensitive)

wword

boolean  완전  일치(Whole Word)

cobject

boolean  객체  내용  검색

relation

boolean  관련  정보  (객체)포함

속성  이름과  값은  ‘%3D’문자로  구분하고  파라미터  구분은

‘,’문자를  사용한다.

svcObj=name%3Dobject

svcObj=name%3Dobject,csensitive%3Dtrue

svcObj=name%3Dobject,csensitive%3Dtrue,wword%3Dtrue

svcObj=name%3DTCP:80,cobject%3Dtrue

srcPort

dstPort

action

desc

int

int

string

string

출발지  포트(0~65535)

목적지  포트(0~65535)

동작(allow | deny | reject(icmp) | reject(reset))

설명

104

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.3.10.4  Body

None

4.3.10.5  Returns

관련 정보 (객체)포함 옵션 False 결과 포맷

이름

ruleSeq

ruleId

Type

int

int

application/json

{

    “code”: “OK”, // OK or FAIL

설명

순번

Rule ID

    “result”: [

        {

            “ruleSeq”: 1,

            “ruleId”: 10

},

        {…}

    ],

    “message”: ““

}

관련 정보 (객체)포함 옵션 True 결과 포맷

배열

relations

이름

field

Type

string

설명

검색  항목( src | dst | svc | aut )

src :  출발지, dst :  목적지, svc :  서비스, aut  사용자

name

ruleSeq

ruleId

string

객체  이름

int

int

순번

Rule ID

application/json

rules

{

    “code”: “OK”, // OK or FAIL

    “result”: {

"relations": [

{

    "field":"src",

Copyright©  2016. SECUI. All rights reserved.

105

IPv6  방화벽  정책

    "name":"object_name"

}

],

"rules": [

{

    "ruleSeq":1,

    "ruleId":10

}

],

"message":""

}

4.3.11  IPv6  방화벽  Shadow  정책  검색

Shadow된  rule을  검색한다.

4.3.11.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewallv6/rules/search/shadow

4.3.11.2  Path parameters

None

4.3.11.3  Query parameters

이름

ruleid

Type

int

설명

rule ID (0~99999999)

0 : shadow된  모든  rule

includeDisable  boolean

비활성화된  정책도  포함

4.3.11.4  Body

None

4.3.11.5  Returns

이름

ruleSeq

ruleId

Type

int

int

설명

순번

Rule ID

106

Copyright©  2016. SECUI. All rights reserved.

Firewall

shadowRuleId

int

상위  정책  ID

desc

string

설명

application/json

{

    “code”: “OK”, // OK or FAIL

    “result”: [

        {

            “ruleSeq”: 1,

            “ruleId”: 10,

            “shadowRuleId”:123,

            “desc”:”Partially shadowed”

},

        {…}

    ],

    “message”: ““

}

4.3.12  IPv6  방화벽  시간만료  정책  검색
시간이  만료된  rule을  검색한다.

4.3.12.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewallv6/rules/search/expired

4.3.12.2  Path parameters

None

4.3.12.3  Query parameters

이름

limit

Type

int

설명

만료  기한, 0~365(일)

includeDisable  boolean

비활성화된  정책  포함

0 :  현재  기준으로  만료된  정책만  검색

1  이상  :  입력한  기한내에  만료되는  정책까지  포함하여  검색

4.3.12.4  Body

None

Copyright©  2016. SECUI. All rights reserved.

107

IPv6  방화벽  정책

4.3.12.5  Returns

이름

ruleSeq

ruleId

Type

int

int

remainDay

string

application/json

{

    “code”: “OK”, // OK or FAIL

    “result”: [

        {

            “ruleSeq”: 1,

            “ruleId”: 10,

설명

순번

Rule ID

남은  기간

“remainDay”:”Expired(-133 days 1 hr 17 mins 53 secs)”

},

        {…}

    ],

    “message”: ““

}

4.3.13  IPv6  방화벽  미참조  정책  검색

적용된  정책에  대한  검색  결과만  제공한다.

편중  중인  정책은  검색  대상에  포함되지  않는다.

상위  정책과  내용이  중복되어  있거나,  중복되어  있지는  않지만  실제  유입된  패킷이  없어서

참조되고  있지  않는  정책에  대한  검색입니다.

4.3.13.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewallv6/rules/search/nonrule

4.3.13.2  Path parameters

None

4.3.13.3  Query parameters

이름

Type

설명

108

Copyright©  2016. SECUI. All rights reserved.

Firewall

day

int(required)

미참조  일,1~365(일)

4.3.13.4  Body

None

4.3.13.5  Returns

이름

ruleSeq

ruleId

Type

int

int

nonReference

int

설명

순번

Rule ID

미참조  일

ruleCreate

string

정책  생성일

-1 :  현재까지  참조기록  없음

application/json

{

    “code”: “OK”, // OK or FAIL

    “result”: [

        {

            “ruleSeq”: 1,

            “ruleId”: 10,

            “nonReference”:144,

“ruleCreate”:”2016-07-19 11:29:11”

},

        {…}

    ],

    “message”: ““

}

4.3.14  IPv6  방화벽  미참조  객체  검색

적용된  정책에  대한  검색  결과만  제공한다.

편중  중인  정책은  검색  대상에  포함되지  않는다.

정책에  사용된  주소/서비스  객체의  내용이  다른  객체  내용과  중복  되었거나,  중복되어

있지는  않지만  실제  유입된  패킷이  없어서  참조되지  않는  객체에  대한  검색입니다.

4.3.14.1  URL

Copyright©  2016. SECUI. All rights reserved.

109

IPv6  방화벽  정책

GET http(s)://[serverip]/mf2/api/v1/firewallv6/rules/search/nonobject

4.3.14.2  Path parameters

None

4.3.14.3  Query parameters

Type

설명

int(required)

미참조  일,1~365(일)

이름

day

4.3.14.4  Body

None

4.3.14.5  Returns

이름

tag

name

Type

string

string

nonReference

int

설명

객체  종류

객체  이름

미참조  일

historyRuleId

int

참조  이력  정책  ID

-1 :  현재까지  참조기록  없음

-99 :  현재까지  참조된  정책  없음

application/json

{

    “code”: “OK”, // OK or FAIL

    “result”: [

        {

            “tag”: “EH”,

            “name”: “ExternalHost”,

“nonReference”:144,

“historyRuleId”:123

},

        {…}

    ],

    “message”: ““

}

110

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.3.15  IPv6  방화벽  적용  정책  검색

적용된  정책에  대한  검색  결과만  제공한다.

편중  중인  정책은  검색  대상에  포함되지  않는다.

정책  사용  여부,  시간  객체  설정,  예외  객체  설정  내용을  반영하여,  유입된  패킷이  정확히

어떤  정책으로  필터링  되는지를  확인해  줍니다.

4.3.15.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewallv6/rules/search/applyrule

4.3.15.2  Path parameters

None

4.3.15.3  Query parameters

Type

설명

string(required)  유입  zone(internal | external | dmz)

이름

zone

protocol

string(required)  프로토콜  이름

ICMP, IPv6-ICMP :  목적지  포트  필수(0~255)

TCP,UDP :  출발지/목적지  포트  필수(0~65535)

나머지  프로토콜은  포트  입력이  불가하다.

srcIp

dstIp

srcPort

dstPort

string(required)  출발지  주소

string(required)  목적지  주소

int

int

출발지  포트

TCP,UDP :  출발지  포트  필수(0~65535)

목적지  포트

ICMP, IPv6-ICMP :  목적지  포트  필수(0~255)

TCP,UDP :  목적지  포트  필수(0~65535)

time

string

유입시간

YYYYMMDDhhmmss

ex)20161010121000

4.3.15.4  Body

None

Copyright©  2016. SECUI. All rights reserved.

111

IPv6  방화벽  정책

4.3.15.5  Returns

이름

ruleSeq

ruleId

Type

int

int

설명

순번

Rule ID

ruleAction

string

동작(allow | deny | reject(icmp) | reject(reset))

application/json

{

    “code”: “OK”, // OK or FAIL

    “result”: [

        {

            “ruleSeq”: 4,

“ruleId”:17,

“ruleAction”:”allow”

},

        {…}

    ],

    “message”: ““

}

4.3.16  IPv6  방화벽  정책그룹  목록  조회

정책  그룹  목록을  조회한다.

4.3.16.1  URL

GET http(s)://[serverip]/mf2/api/v1/firewallv6/rules/groups

4.3.16.2  Path parameters

None

4.3.16.3  Query parameters

None

4.3.16.4  Body

None

112

Copyright©  2016. SECUI. All rights reserved.

Firewall

설명

정책  그룹  ID

정책  그룹  이름

정책  그룹  설명

4.3.16.5  Returns

이름

id

name

desc

Type

string

string

string

application/json

{

    “code”: “OK”, // OK or FAIL

    “result”: [

        {

            “id”: 1,

            “name”: “default”,

            “desc”: “default rule-group”

        },

        {…}

    ],

    “message”: ““

}

4.3.17  IPv6  방화벽  정책그룹  추가

정책  그룹을  추가한다.

4.3.17.1  URL

POST http(s)://[serverip]/mf2/api/v1/firewallv6/rules/groups

4.3.17.2  Path parameters

None

4.3.17.3  Query parameters

None

4.3.17.4  Body

이름

name

desc

Type

설명

string(required)  정책  그룹  이름

string

정책  그룹  설명

application/json

Copyright©  2016. SECUI. All rights reserved.

113

IPv6  방화벽  정책

{

}

{

}

“name”: ““,

“desc”: ““

4.3.17.5  Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

4.3.18  IPv6  방화벽  정책그룹  삭제

정책  그룹을  삭제한다.

정책  그룹  내에  포함된  정책이  하나도  없을  경우에만  삭제가  가능하다.

4.3.18.1  URL

DELETE http(s)://[serverip]/mf2/api/v1/firewallv6/rules/groups/{name}

4.3.18.2  Path parameters

이름

name

Type

설명

string(required)  정책  그룹  이름

4.3.18.3  Query parameters

None

4.3.18.4  Body

None

4.3.18.5  Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

114

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.3.19  IPv6  방화벽  정책  적용

편집된  모든  rule  내용들을  운영중인  설정  파일에  적용한다.

4.3.19.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewallv6/rules/apply

4.3.19.2  Path parameters

None

4.3.19.3  Query parameters

None

4.3.19.4  Body

None

4.3.19.5  Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.3.20  IPv6  방화벽  정책  취소

편집된  모든  rule  내용들을  rollback  한다.

4.3.20.1  URL

PUT http(s)://[serverip]/mf2/api/v1/firewallv6/rules/cancel

4.3.20.2  Path parameters

None

4.3.20.3  Query parameters

None

Copyright©  2016. SECUI. All rights reserved.

115

NAT  정책  설정

4.3.20.4  Body

None

4.3.20.5  Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.4  NAT  정책  설정

NAT  변환  방식은  매핑  방법과  변환  기준에  따라  다음과  같이  구분될  수  있다.

매핑  방법에  따라  1:1  변환,  N:M  변환,  N:1  변환,  1:N  변환으로  구분되며,  변환  기준에  따라

Source NAT(SNAT), Destination NAT(DNAT)으로  구분된다.

1:1  변환은  Static NAT라고도  하며,  변경  전  주소와  변경  후  주소를  1:1로  연관시켜  변환한다.

N:M  변환은  Dynamic  NAT로도  불리며  변경  전  주소  Pool과  변경  후  주소  Pool을  매핑시킨다.  이

때  변경  전/후의  주소  Pool에서  제공되는  IP  개수가  일치될  필요는  없다.  N:1  변환은  PAT,

NAPT라고도  하며  다수의  변경  전  주소가  하나의  변경  후  주소로  변환된다.  이  때  변경  후

주소의  포트가  동일하여  충돌이  발생할  수  있기  때문에  포트  충돌  시  포트도  변환되어야  한다.

1:N  변환은  LS  NAT라고도  하며,  특정  목적지로  향하는  패킷의  목적지를  설정된  여러  개의  목적지

중  하나로  변환한다.  이  방식은  서버의  부하를  분산시킬  목적으로  사용한다.

SNAT는  패킷의  출발지  주소를  변경하고, DNAT는  패킷의  목적지  주소를  변경하는  변환방식이다.

이러한  NAT  변환  방식을  정리하면  다음과  같다.

변환  기준에  따른

SNAT

1:1  변환, N:M  변환, N:1  변환

구분

1:1  단방향  확장/동시  변환

매핑  방법에  따른  구분

DNAT

1:N  변환

1:1  단방향  확장/동시  변환

※  1:1단방향  확장/동시  변환은  SNAT, DNAT  모두에  사용가능

116

Copyright©  2016. SECUI. All rights reserved.

Firewall

아래  변환  방식만  지원한다.

-

1:1  변환  : 11A

-  N:M  변환-IP Pool : NMA

-  N:M  변환-Port Pool : NMN

-

-

-

1:N  변환  : 1NA

1:1  단방향  확장변환  : 11N

1:1  단방향  동시변환  : 11O

4.4.1  NAT  정책  목록  조회

NAT  정책  목록을  조회  한다.

4.4.1.1  URL

GET http(s)://[serverip]/mf2/api/v1/nat/rules

4.4.1.2  Path parameters

None

4.4.1.3  Query parameters

None

4.4.1.4  Body

None

4.4.1.5  Returns

이름

natGroup

natSeq

natRuleId

Type

string

int

int

설명

그룹  이름

순번

Rule ID

orgSrcObj

array(nobject)

변경전  출발지  객체  목록

orgDstObj

array(nobject)

변경전  목적지  객체  목록

orgSvcObj

array(object)

변경  전  서비스  객체  목록

svcObjProtocol,  svcObjPort  속성  사용시  해당  정보로

객체  생성  후  정책에  자동  추가

natSrcObj

array(nobject)

변경후  출발지  객체  목록

natDstObj

array(nobject)

변경후  목적지  객체  목록

Copyright©  2016. SECUI. All rights reserved.

117

NAT  정책  설정

natSvcObj

array(object)

변경  후  서비스  객체  목록

svcObjProtocol,  svcObjPort  속성  사용시  해당  정보로

객체  생성  후  정책에  자동  추가

natOption

string

변환방식

-

1:1  변환  : 11A

-  N:M  변환-IP Pool : NMA

-  N:M  변환-Port Pool : NMN

-

-

-

1:N  변환  : 1NA

1:1  단방향  확장변환  : 11N

1:1  단방향  동시변환  : 11O

natDesc

string

설명

application/json

{

      “code”: “OK”, // OK or FAIL

      “result”: [{

            “natGroup”: “default”, //그룹  이름

            “natSeq”: “12”, //  순번

            “natRuleId”: “24”, //Rule ID

            “orgSrcObj”: [{”name”:”ANY”,”tag”:”AA”}], //변경전  출발지  객체  목록

            “orgDstObj”: [{”name”:”1.1.1.1_IH”,”tag”:”IH”}], //변경전  목적지  객체  목록

            "orgSvcObj": [{name:"ANY",tag:"SA"}],

            “natSrcObj”: [{”name”:”200.1.1.1_IH”,”tag”:”IH”}], //변경후  출발지  객체  목록

            “natDstObj”: [{”name”:”ORG”,”tag”:”AO”}], //변경후  목적지  객체  목록

"natSvcObj": [{name:"ORG",tag:"SO"}],

            “natOption”: “1NA”, //변환방식

            “natDesc”: ““ //설명

},

{…}

],

“message”: ““ //에러  메시지

}

4.4.2  NAT  정책  조회

하나의  정책을  조회한다.

4.4.2.1  URL

118

Copyright©  2016. SECUI. All rights reserved.

Firewall

GET http(s)://[serverip]/mf2/api/v1/nat/rules/{ruleid}

4.4.2.2  Path parameters

이름

ruleid

Type

설명

int(required)

Rule ID

4.4.2.3  Query parameters

None

4.4.2.4  Body

None

4.4.2.5  Returns

이름

natGroup

natSeq

natRuleId

Type

string

int

int

설명

그룹  이름

순번

Rule ID

orgSrcObj

array(nobject)

변경전  출발지  객체  목록

orgDstObj

array(nobject)

변경전  목적지  객체  목록

orgSvcObj

array(object)

변경  전  서비스  객체  목록

svcObjProtocol,  svcObjPort  속성  사용시  해당  정보로

객체  생성  후  정책에  자동  추가

natSrcObj

array(nobject)

변경후  출발지  객체  목록

natDstObj

array(nobject)

변경후  목적지  객체  목록

natSvcObj

array(object)

변경  후  서비스  객체  목록

natOption

string

변환방식

svcObjProtocol,  svcObjPort  속성  사용시  해당  정보로

객체  생성  후  정책에  자동  추가

-

1:1  변환  : 11A

-  N:M  변환-IP Pool : NMA

-  N:M  변환-Port Pool : NMN

-

-

-

1:N  변환  : 1NA

1:1  단방향  확장변환  : 11N

1:1  단방향  동시변환  : 11O

natDesc

string

설명

application/json

Copyright©  2016. SECUI. All rights reserved.

119

NAT  정책  설정

{

      “code”: “OK”, // OK or FAIL

      “result”: {

            “natGroup”: “default”, //그룹  이름

            “natSeq”: “12”, //  순번

            “natRuleId”: “24”, //Rule ID

            “orgSrcObj”: [{”name”:”ANY”,”tag”:”AA”}], //변경전  출발지  객체  목록

            “orgDstObj”: [{”name”:”1.1.1.1_IH”,”tag”:”IH”}], //변경전  목적지  객체  목록

            "orgSvcObj": [{name:"ANY",tag:"SA"}],

            “natSrcObj”: [{”name”:”200.1.1.1_IH”,”tag”:”IH”}], //변경후  출발지  객체  목록

            “natDstObj”: [{”name”:”ORG”,”tag”:”AO”}], //변경후  목적지  객체  목록

            "natSvcObj": [{name:"ORG",tag:"SO"}],

            “natOption”: “1NA”, //변환방식

            “natDesc”: ““ //설명

},

“message”: ““ //에러  메시지

}

4.4.3  NAT  정책  사용  조회

NAT  정책  설정  활성화  여부를  조회한다.

4.4.3.1  URL

GET http(s)://[serverip]/mf2/api/v1/nat/use

4.4.3.2  Path parameters

None

4.4.3.3  Query parameters

None

4.4.3.4  Body

None

4.4.3.5  Returns

이름

enable

Type

boolean

설명

NAT  정책  설정  활성화  여부

120

Copyright©  2016. SECUI. All rights reserved.

Firewall

application/json

“code”:”OK”,

“result”: {

    “enable”:”true”

}

“message”:”“

{

}

4.4.4  NAT  정책  사용  수정

NAT  정책  설정을  활성화  할지를  변경한다.

디폴트는  미사용으로  설정되어  있다.

4.4.4.1  URL

PUT http(s)://[serverip]/mf2/api/v1/nat/use

4.4.4.2  Path parameters

None

4.4.4.3  Query parameters

None

4.4.4.4  Body

이름

enable

Type

설명

boolean(required)

NAT  정책  설정  활성화  여부

{

}

{

application/json

“enable”: “true”

4.4.4.5  Returns

application/json

“code”:”OK”,

“message”:”“

Copyright©  2016. SECUI. All rights reserved.

121

NAT  정책  설정

}

4.4.5  NAT  정책  추가

하나의  정책을  추가한다.

4.4.5.1  URL

POST http(s)://[serverip]/mf2/api/v1/nat/rules

4.4.5.2  Path parameters

None

4.4.5.3  Query parameters

None

4.4.5.4  Body

이름

Type

설명

natGroup

string(required)

그룹  이름

natSeq

int(required)

순번

주의  :  ruleGroup의  그룹  범위에  포함되는  순번이

입력되어야  한다.

orgSrcObj

array(nobject)(required)  변경전  출발지  객체  목록

orgDstObj

array(nobject)(required)  변경전  목적지  객체  목록

orgSvcObj

array(object)

변경  전  서비스  객체  목록

svcObjProtocol,  svcObjPort  속성  사용시  해당  정보로

객체  생성  후  정책에  자동  추가

natSrcObj

array(nobject)(required)  변경후  출발지  객체  목록

natDstObj

array(nobject)(required)  변경후  목적지  객체  목록

natSvcObj

array(object)

변경  후  서비스  객체  목록

natOption

string(required)

변환방식

svcObjProtocol,  svcObjPort  속성  사용시  해당  정보로

객체  생성  후  정책에  자동  추가

-

1:1  변환  : 11A

-  N:M  변환-IP Pool : NMA

-  N:M  변환-Port Pool : NMN

-

1:N  변환  : 1NA

122

Copyright©  2016. SECUI. All rights reserved.

Firewall

-

-

1:1  단방향  확장변환  : 11N

1:1  단방향  동시변환  : 11O

natDesc

string

설명

application/json

{

“natGroup”: “default”,

“natSeq”: “1”,

        “orgSrcObj”: [{objIp:”1.1.1.2”,”tag”:”IH”}],

        “orgDstObj”: [{objIp:”10.1.1.1”,”tag”:”IH”}],

"orgSvcObj": [{name:"ANY",tag:"SA"}],

“natSrcObj “: [{name:”ORG “,”tag”:”AO”}],

“natDstObj”: [{objIp:”19.1.1.0/24”,”tag”:”IN”}],

"natSvcObj": [{name:"ORG",tag:"SO"}],

“natOption”: “1NA”,

“natDesc”: ““

}

{

}

4.4.5.5  Returns

application/json

“code”:”OK”,

“message”:”“

4.4.6  NAT  정책  수정

정책을  수정한다.

4.4.6.1  URL

PUT http(s)://[serverip]/mf2/api/v1/nat/rules/{ruleid}

4.4.6.2  Path parameters

이름

ruleid

Type

설명

int(required)

Rule ID

Copyright©  2016. SECUI. All rights reserved.

123

NAT  정책  설정

4.4.6.3  Query parameters

None

4.4.6.4  Body

이름

Type

설명

orgSrcObj

array(nobject)(required)  변경전  출발지  객체  목록

orgDstObj

array(nobject)(required)  변경전  목적지  객체  목록

orgSvcObj

array(object)

변경  전  서비스  객체  목록

svcObjProtocol,  svcObjPort  속성  사용시  해당  정보로

객체  생성  후  정책에  자동  추가

natSrcObj

array(nobject)(required)  변경후  출발지  객체  목록

natDstObj

array(nobject)(required)  변경후  목적지  객체  목록

natSvcObj

array(object)

변경  후  서비스  객체  목록

natOption

string(required)

변환방식

svcObjProtocol,  svcObjPort  속성  사용시  해당  정보로

객체  생성  후  정책에  자동  추가

-

1:1  변환  : 11A

-  N:M  변환-IP Pool : NMA

-  N:M  변환-Port Pool : NMN

-

-

-

1:N  변환  : 1NA

1:1  단방향  확장변환  : 11N

1:1  단방향  동시변환  : 11O

natDesc

string

설명

application/json

{

“orgSrcObj”: [{objIp:”1.1.1.2”,”tag”:”IH”}],

        “orgDstObj”: [{objIp:”10.1.1.1”,”tag”:”IH”}],

"orgSvcObj": [{name:"ANY",tag:"SA"}],

“natSrcObj “: [{name:”ORG“,”tag”:”AO”}],

“natDstObj”: [{objIp:”19.1.1.0/24”,”tag”:”IN”}],

"natSvcObj": [{name:"ORG",tag:"SO"}],

“natOption”: “1NA”,

“natDesc”: ““

}

124

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.4.6.5  Returns

application/json

{

}

“code”:”OK”,

“message”:”“

4.4.7  NAT  정책  삭제

정책을  삭제한다.

4.4.7.1  URL

DELETE http(s)://[serverip]/mf2/api/v1/nat/rules/{ruleid}

4.4.7.2  Path parameters

이름

ruleid

Type

설명

int(required)

Rule ID

4.4.7.3  Query parameters

None

4.4.7.4  Body

None

4.4.7.5  Returns

application/json

{

}

“code”:”OK”,

“message”:”“

4.4.8  NAT  정책그룹  목록  조회

정책  그룹  목록을  조회한다.

4.4.8.1  URL

Copyright©  2016. SECUI. All rights reserved.

125

NAT  정책  설정

GET http(s)://[serverip]/mf2/api/v1/nat/rules/groups

4.4.8.2  Path parameters

None

4.4.8.3  Query parameters

None

4.4.8.4  Body

None

4.4.8.5  Returns

이름

id

name

desc

Type

string

string

string

application/json

{

    “code”: “OK”, // OK or FAIL

    “result”: [

        {

설명

정책  그룹  ID

정책  그룹  이름

정책  그룹  설명

            “id”: 1, //그룹  ID

            “name”: “default”, //그룹  이름

            “desc”: “default rule-group” //그룹  설명

        },

        {…}

    ],

    “message”: ““

}

4.4.9  NAT  정책그룹  추가

정책  그룹을  추가한다.

126

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.4.9.1  URL

POST http(s)://[serverip]/mf2/api/v1/nat/rules/groups

4.4.9.2  Path parameters

None

4.4.9.3  Query parameters

None

4.4.9.4  Body

이름

name

desc

Type

설명

string(required)  정책  그룹  이름

string

정책  그룹  설명

application/json

{

    “name”: ““,

“desc”: ““

}

{

}

4.4.9.5  Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

4.4.10  NAT  정책그룹  삭제

정책  그룹을  삭제한다.

정책  그룹  내에  포함된  정책이  하나도  없을  경우에만  삭제가  가능하다.

4.4.10.1  URL

DELETE http(s)://[serverip]/mf2/api/v1/nat/rules/groups/{name}

4.4.10.2  Path parameters

이름

Type

설명

Copyright©  2016. SECUI. All rights reserved.

127

NAT  정책  설정

name

string(required)  정책  그룹  이름

4.4.10.3  Query parameters

None

4.4.10.4  Body

None

4.4.10.5  Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.4.11  NAT  정책  적용

편집된  모든  rule  내용들을  운영중인  설정  파일에  적용한다.

4.4.11.1  URL

PUT http(s)://[serverip]/mf2/api/v1/nat/rules/apply

4.4.11.2  Path parameters

None

4.4.11.3  Query parameters

None

4.4.11.4  Body

None

4.4.11.5  Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

128

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.4.12  NAT  정책  취소

편집된  모든  rule  내용들을  rollback  한다.

4.4.12.1  URL

PUT http(s)://[serverip]/mf2/api/v1/nat/rules/cancel

4.4.12.2  Path parameters

None

4.4.12.3  Query parameters

None

4.4.12.4  Body

None

4.4.12.5  Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.5  IPv4  블랙리스트

시스템  정의  기본  프로토콜  정보

이름

ICMP

IGMP

IPv4

TCP

IGP

번호  설명

1  Internet Control Message Protocol

2  Internet Group Management Protocol

4  IPv4 Encapsulation

6  Transmission Control Protocol

9  Any private interior gateway (Cisco: for IGRP)

Copyright©  2016. SECUI. All rights reserved.

129

IPv4  블랙리스트

UDP

IPv6

17  User Datagram Protocol

41  IPv6 Encapsulation

IPv6-Route

43  Routing Header for IPv6

IPv6-Frag

44  Fragment Header for IPv6

RSVP

GRE

ESP

AH

SKIP

46  Resource Reservation Protocol

47  Generic Routing Encapsulation

50  Encapsulating Security Payload

51  Authentication Header

57  IPSEC use this

IPv6-ICMP

58  ICMP for IPv6

IPv6-NoNxt

59  No Next Header for IPv6

IPv6-Opts

60  Destination Options for IPv6

EIGRP

OSPF

PIM

88  Enhanced Interior Routing Protocol (Cisco)

89  Open Shortest Path First IGP

103  Protocol Independent Multicast

IPComp

108  IP Payload Compression Protocol

VRRP

L2TP

ISIS

SCTP

112  Virtual Router Redundancy Protocol

115  Layer Two Tunneling Protocol

124  ISIS over IPv4

132  Stream Control Transmission Protocol

4.5.1  블랙리스트  목록  조회

블랙리스트  목록을  조회한다.

URL

GET http(s)://[serverip]/mf2/api/v1/blacklist/ips

Path parameters

None

Query parameters

이름

count

Type

int

page

int

설명

페이지당  개수

Default : 30

페이지  번호

130

Copyright©  2016. SECUI. All rights reserved.

Firewall

srcIP

srcPort

dstIP

dstPort

protocol

desc

search

boolean

boolean

boolean

boolean

boolean

boolean

string

Body

None

Returns

이름

srcIP

Type

string

srcPort

int

dstIP

string

dstPort

int

protocol

int

Default : 1

출발지  IP  주소  검색  유무

출발지  포트  검색  유무

목적지  IP  주소  검색  유무

목적지  포트  검색  유무

프로토콜  검색  유무

설명  검색  유무

검색  키워드

설명

출발지  IP  주소

0  또는  IP  주소

0  값은  ‘ANY’값을  의미한다.

출발지  포트

0~65535

0  값은  ‘ANY’값을  의미한다.

목적지  IP  주소

0  또는  IP  주소

0  값은  ‘ANY’값을  의미한다.

목적지  포트

0~65535

0  값은  ‘ANY’값을  의미한다.

프로토콜

0~255

0  값은  ‘ANY’값을  의미한다.

exprtime

string

차단  만료  시간

년(4)-월(2)-일(2)  시(2):분(2):초(2)

2019-10-20 12:10:50

expiration

boolean

만료  여부

desc

user

date

string

string

string

설명

사용자

최종  수정일

Copyright©  2016. SECUI. All rights reserved.

131

IPv4  블랙리스트

application/json

{

    "code": "OK",

    "result": [

        {

            "srcIP": "10.10.10.20",

            "srcPort": 0,

            "dstIP ": "0",

            "dstPort": 0,

            "protocol": 0,

            "exprtime": "2019-10-20 11:20:10",

            "expiration": false,

            "desc": "설명",

            "user": "api_user",

            "date": "2019-09-20 11:20:10"

        }

    ],

    "message": ""

}

4.5.2  블랙리스트  추가

블랙리스트를  추가한다.

URL

POST http(s)://[serverip]/mf2/api/v1/blacklist/ips

Path parameters

None

Query parameters

None

Body

이름

srcIP

Type

설명

string(required)

출발지  IP  주소

132

Copyright©  2016. SECUI. All rights reserved.

Firewall

0  또는  IP  주소

0  값은  ‘ANY’값을  의미한다.

0.0.0.0  주소는  허용하지  않는다.

srcPort

int(required)

출발지  포트

0~65535

0  값은  ‘ANY’값을  의미한다.

dstIP

string(required)

목적지  IP  주소

0  또는  IP  주소

0  값은  ‘ANY’값을  의미한다.

0.0.0.0  주소는  허용하지  않는다.

dstPort

int(required)

목적지  포트

protocol

int(required)

0~65535

0  값은  ‘ANY’값을  의미한다.

프로토콜

0~255

0  값은  ‘ANY’값을  의미한다.

프로토콜  정보는  객체  설정  >  서비스  객체  >  프로토콜

목록  조회를  참고한다.

또는  시스템  정의  기본  프로토콜  정보  참고

exprtime

string(required)

차단  만료  시간

년(4)-월(2)-일(2)  시(2):분(2):초(2)

2019-10-20 12:10:50

desc

string

설명(128자)

-  출발지  주소(srcIP),  목적지  주소(dstIP)  중  최소  하나는  ANY가  아닌  값으로  입력해야  한다.

-  프로토콜(protocol)이  TCP(6)  또는  UDP(17)가  아닌경우  출발지  포트(srcPort),  목적지

포트(dstPort)  번호는  0으로  입력된다.

application/json

{

    "srcIP": "10.10.10.20",

    "srcPort": 0,

    "dstIP ": "0",

    "dstPort": 0,

    "protocol": 0,

    "exprtime": "2019-10-20 11:20:10",

    "desc": "설명",

}

Copyright©  2016. SECUI. All rights reserved.

133

IPv4  블랙리스트

Returns

application/json

{

    "code": "OK",// OK or FAIL

    "message": ""

}

4.5.3  블랙리스트  삭제

블랙리스트를  삭제한다.

URL

DELETE http(s)://[serverip]/mf2/api/v1/blacklist/ips

Path parameters

None

Query parameters

None

Body

이름

srcIP

Type

설명

string(required)

출발지  IP  주소

0  또는  IP  주소

0  값은  ‘ANY’값을  의미한다.

srcPort

int(required)

출발지  포트

0~65535

0  값은  ‘ANY’값을  의미한다.

dstIP

string(required)

목적지  IP  주소

0  또는  IP  주소

0  값은  ‘ANY’값을  의미한다.

dstPort

int(required)

목적지  포트

protocol

int(required)

0~65535

0  값은  ‘ANY’값을  의미한다.

프로토콜

0~255

0  값은  ‘ANY’값을  의미한다.

134

Copyright©  2016. SECUI. All rights reserved.

desc

string

설명

Firewall

application/json

{

    "srcIP": "10.10.10.20",

    "srcPort": 0,

    "dstIP ": "0",

    "dstPort": 0,

    "protocol": 0,

"desc": "설명"

}

{

Returns

application/json

    "code": "OK",// OK or FAIL

    "message": ""

}

4.5.4  만료된  블랙리스트  삭제

만료된  블랙리스트를  모두  삭제한다.

URL

DELETE http(s)://[serverip]/mf2/api/v1/blacklist/ips/expired

Path parameters

None

Query parameters

None

Body

None

Returns

application/json

{

Copyright©  2016. SECUI. All rights reserved.

135

IPv4  블랙리스트

    "code": "OK",// OK or FAIL

    "message": ""

}

4.5.5  블랙리스트  적용

편집된  모든  블랙리스트를  운영중인  설정  파일에  적용한다.

4.5.5.1  URL

PUT http(s)://[serverip]/mf2/api/v1/blacklist/ips/apply

4.5.5.2  Path parameters

None

4.5.5.3  Query parameters

None

4.5.5.4  Body

None

4.5.5.5  Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

4.5.6  블랙리스트  취소

편집된  모든  블랙리스트를  rollback  한다.

4.5.6.1  URL

PUT http(s)://[serverip]/mf2/api/v1/blacklist/ips/cancel

4.5.6.2  Path parameters

None

136

Copyright©  2016. SECUI. All rights reserved.

Firewall

4.5.6.3  Query parameters

None

4.5.6.4  Body

None

4.5.6.5  Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

Copyright©  2016. SECUI. All rights reserved.

137

주소  객체

5.  부록

5.1  주소  객체

이름

name

Type

string

설명

객체  이름

NAT  추가/수정/삭제  name  속성  지원  안함.

objIp

ip address

-

IP Address

ex)10.10.10.10

-  Network Address CIDR Notation

ex)10.10.10.0/24

tag

string

객체  Zone(I|E|D) +  객체  타입(H|N|F|G)

ANY일  경우  tag는  ‘AA’

5.2  IPv6  주소  객체

이름

name

Type

string

설명

객체  이름

objIp

ip address

-

IP Address

NAT  추가/수정/삭제  name  속성  지원  안함.

ex)2001::100:1

-  Network Address CIDR Notation

ex)2001::100/127

tag

string

객체  Zone(I|E|D) +  객체  타입(H|N|F|G)

ANY일  경우  tag는  ‘AA’

5.3  주소  객체(NAT  정책)

이름

name

Type

string

설명

객체  이름

objIp

ip address

-

IP Address

NAT  추가/수정/삭제  name  속성  지원  안함.

ex)10.10.10.10

-  Network Address CIDR Notation

ex)10.10.10.0/24

-  Range Address(1NA,NMA,NMN)

ex)10.10.10.1~10.10.10.254

138

Copyright©  2016. SECUI. All rights reserved.

tag

string

객체  Zone(I|E|D) +  객체  타입(H|N)

부록

ANY일  경우  tag는  ‘AA’

NAT  정책  변경  후  출발지,목적지는

ORG일  경우  tag는  ‘AO’

ORG는  ANY와  동일한  의미이다.

설명

객체  이름

ANY일  경우  tag는  ‘SA’

서비스  객체일  경우  tag는  ‘SS’

5.4  서비스  객체

이름

name

tag

Type

string

string

svcObjProtocol

string

TCP,UDP,ICMP만  지원

svcObjPort

string

서비스  포트

단일) *  또는  0-65535,0-255(프로토콜이  ICMP일  경우)

범위)  단일값-단일값

혼합)  최대  10개의  단일값,  범위값을  콤마(,)로  구분

5.5  서비스  유형

프로토콜  종류별  사용  가능한  서비스  유형  정보

프로토콜

서비스  유형

TCP

UDP

NONE,HTTP,SMTP,POP3,FTP,H.323,SQLNET,HTTPS,SMTPS,POP3S,SSL,RMI,SIP

NONE,SIP,TFTP

나머지

NONE

5.6  사용자

이름

name

Type

string

설명

사용자  이름

tag

string

사용자  종류(L|S|I|A) +  객체  타입(U|G)

Known  사용자일  경우  name은  ‘known_user’

Unkown  사용자일  경우  name은  ‘unknown_user’

-

-

-

LU :  로컬  사용자

LG :  로컬  사용자  그룹

IU : IP  매핑  사용자

Copyright©  2016. SECUI. All rights reserved.

139

시간  객체

-

-

-

IG : IP  매핑  사용자  그룹

SU :  외부  인증  사용자

SG :  외부  인증  사용자  그룹

-  AU : AD  사용자

-  AG : AD  사용자  그룹

Known  사용자일  경우  tag는  ‘KN’

Unknown  사용자일  경우  tag는  ‘UN’

문자열  사용자일  경우  tag는  ‘ST’

ANY일  경우  tag는  ‘UA’

5.7  시간  객체

이름

name

Type

string

설명

시간  객체  이름,

timeObjInterv

string

기간

al

2015-02-27 00:00~2015-03-20 23:59

5.8  로그인  동작  방식

-  로그인/로그아웃

140

Copyright©  2016. SECUI. All rights reserved.

부록

-  REST API/GUI  중복  로그인

REST  API  Write  Mode  로그인  이후  GUI를  통한  Write  Mode  로그인이  시도될  때  API

로그인을  강제로  밀어내고  GUI로  로그인이  가능하다.

※  GUI  접속시  알림창

반대로  GUI에  Write Mode로  접속되어  있고  REST API를  통해  로그인을  시도할  경우는  강제

로그인을  허용하지  않는다.

Copyright©  2016. SECUI. All rights reserved.

141

