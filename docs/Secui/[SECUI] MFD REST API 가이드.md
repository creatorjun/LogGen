MFD REST API  가이드

서울특별시  중구  소공로  48(회현동  2가  10-1)  남산센트럴타워  5~7F  ㈜시큐아이

Tel: 02-3783-6500(기술문의)

www.secui.com

Copyright©  2019. SECUI. All rights reserved.

문서  개정  이력

문서버전

작성자

날짜

설명

V 2.0.0

기반기술팀

이만영

문서  최초  작성

2020-08-03

인증,로그인,시스템  정보,IPv4  ACL  설정,  보호  도메인

V 2.0.1

이만영

2021-04-06

설정,  차단  목록  설정

API Token  발급  패스워드  파라미터  수정

-

-

2.1.2    API Token  발급

2.1.3    API Token  조회

목  차

1. REST API  설정 ..................................................................... 1

1.1 관리자 IP 설정 ......................................................................... 1

1.2 HTTP PUT/DELETE Method 제한 .............................................. 1

1.3 HTTP Status Code ..................................................................... 2

2. REST API  인증 ..................................................................... 3

2.1 REST API Token 관리 ................................................................ 3

2.1.1 GUI Token  발급................................................................................ 3

2.1.2 API Token  발급 ................................................................................ 4

2.1.3 API Token  조회 ................................................................................ 5

3.  로그인/로그아웃 .................................................................. 7

3.1 로그인 ....................................................................................... 7

3.2 로그아웃 ................................................................................... 8

4. System ............................................................................... 10

4.1 시스템 정보 ............................................................................ 10

4.1.1  시스템  정보  조회 .......................................................................... 10

4.2  라이선스  정보......................................................................... 11

4.2.1  라이선스  정보  조회 ...................................................................... 11

4.3 IPv4 ACL  설정 ......................................................................... 12

4.3.1 ACL  목록  조회 ............................................................................... 12

4.3.2 ACL  추가 ........................................................................................ 14

4.3.3 ACL  수정 ........................................................................................ 16

4.3.4 ACL  삭제 ........................................................................................ 17

4.3.5 ACL  적용 ........................................................................................ 18

4.3.6 ACL  취소 ........................................................................................ 19

5. Policy ................................................................................. 20

5.1  보호  도메인  설정 ................................................................... 20

5.1.1  세그먼트  후보  목록  조회 ............................................................. 20

5.1.2  보호  도메인  설정  목록  조회 ........................................................ 21

5.1.3  보호  도메인  설정  추가 ................................................................. 22

5.1.4  보호  도메인  설정  수정 ................................................................. 24

5.1.5  보호  도메인  설정  삭제 ................................................................. 26

5.1.6  보호  도메인  설정  적용/취소 ........................................................ 27

5.2 차단 목록 설정 ....................................................................... 28

5.2.1  사용자  정의  차단  목록  조회 ........................................................ 29

5.2.2  사용자  정의  차단  추가 ................................................................. 31

5.2.3  사용자  정의  차단  삭제 ................................................................. 32

5.2.4  사용자  정의  차단  목록  적용/취소................................................ 34

REST API  설정

1.  REST API  설정

1.1  관리자  IP  설정

연동  장비에서  MFD  REST  API  접근이  가능하도록  관리자  >  관리  접속  IP에  연동  장비  IP를

등록한다.

1.2  HTTP PUT/DELETE Method  제한

PUT/DELETE Method는  보안에  취약하기  때문에  사용을  제한한다.

대신  POST  Method와

“X-HTTP-Method-Override”  해더값에  PUT,DELETE  Method를

사용한다.

$.ajax({

    url: “https://192.168.100.101/mfd/api/firewall/object/hosts/test_object”,

    type: “POST”,

    data: {},

    headers: {

            “Content-Type”: “application/json”,

            “X-HTTP-Method-Override”: “PUT” },

})

$.ajax({

    url: “https://192.168.100.101/mfd/api/firewall/object/hosts/test_object”,

    type: “POST”,

    data: {},

    headers: {

            “Content-Type”: “application/json”,

Copyright©  2016. SECUI. All rights reserved.

1

HTTP Status Code

            “X-HTTP-Method-Override”: “DELETE” },

})

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

Copyright©  2016. SECUI. All rights reserved.

3

REST API Token  관리

변경된  관리자  정보는  적용  버튼을  클릭하여  장비에  적용된다.

발급된  토큰  값은  HTTP(S)  프로토콜을  사용하여  REST  API  호출시  “Authorization”

해더값으로  전달  한다.

GET /mfd/api/system/4/acls HTTP/1.1

Host: 192.168.10.10

Authorization: 4c4eddf7def041de9880eda8cce4e1b4

Content-Type: application/json

Cache-Control: no-cache

2.1.2  API Token  발급

API를  사용하여  관리자의  Token을  발급한다.

API  호출시  Authorization Header는  필요  없다.

2.1.2.1  URL

POST http(s)://[serverip]/mfd/api/token

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

관리자  비밀번호(SHA256)

※  평문  비밀번호  암호화  순서  ①  →  ②

①  평문  : vkfksgksmf1!

②  SHA256 : cee70223a11c0609ab3243229e74a0c79374cd54394793f5d444f6ed39ee4686

2.1.2.4  Body

None

4

Copyright©  2016. SECUI. All rights reserved.

REST API  인증

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

GET http(s)://[serverip]/mfd/api/token

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

관리자  비밀번호(SHA256)

※  평문  비밀번호  암호화  순서  ①  →  ②

①  평문  : vkfksgksmf1!

②  SHA256 : cee70223a11c0609ab3243229e74a0c79374cd54394793f5d444f6ed39ee4686

2.1.3.4  Body

None

2.1.3.5  Returns

application/json

{

“code”:”OK”, // OK or FAIL

Copyright©  2016. SECUI. All rights reserved.

5

REST API Token  관리

“result”:

{

            “token”: “e2e5090141984d8e9285037a8765eaae”

},

“message”:”“

}

6

Copyright©  2016. SECUI. All rights reserved.

로그인/로그아웃

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

※  재로그인하면  이전  세션에서  적용하지  않은  편집  설정들은  전부  rollback  된다.

3.1.1.1  URL

POST http(s)://[serverip]/mfd/api/login

3.1.1.2  Path parameters

None

3.1.1.3  Query parameters

None

Copyright©  2016. SECUI. All rights reserved.

7

설명

인증  세션이  유지되는  시간,10~1440(분)

default : 10

로그아웃

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

로그아웃  이후  MFD  장비에  다른  관리자가  쓰기  권한으로  로그인이  가능한  상태가  된다.

로그아웃은  로그인에서  발급된  “X-API-SESSION”: “[세션값]” Header  정보가  필요하다.

3.2.1.1  URL

POST http(s)://[serverip]/mfd/api/logout

3.2.1.2  Path parameters

None

3.2.1.3  Query parameters

None

8

Copyright©  2016. SECUI. All rights reserved.

로그인/로그아웃

3.2.1.4  Body

None

3.2.1.5  Returns

application/json

{

    "code": "OK",// OK or FAIL

    "message": ""

}

Copyright©  2016. SECUI. All rights reserved.

9

시스템  정보

4.  System

4.1  시스템  정보

4.1.1  시스템  정보  조회

시스템  운영  정보를  조회한다.

URL

GET http(s)://[serverip]/mfd/api/sytem/info

Path parameters

None

Query parameters

None

Body

None

Returns

이름

productName

modelName

firmware

patchDate

runTime

haMode

licenseFrom

licenseTo

hwSerial

Type

string

string

string

string

string

string

string

string

string

설명

제품  이름(productname)

모델  이름(modelname)

펌웨어  버전(system-info)

패치  일자(system-info)

시스템  동작  시간(system-info)

HA  모드(system-info)

라이선스  기간  시작일(system-info)

라이선스  기간  종료일(system-info)

H/W  시리얼  번호(system-info)

10

Copyright©  2016. SECUI. All rights reserved.

packetProcessDrv

string

패킷  처리  방식(packet_process)

System

application/json

{

    "code": "OK",

    "result": {

            "productName": "SECUI MFD V4.0",

            "modelName": "SECUI MFD 4100(R3) V4.0",

            "firmware": "4.0.7",

            "patchDate": "2019-03-13",

            "runTime": "42 days, 3:05",

            "haMode": "N",

            "licenseFrom": "2019/01/01",

            "licenseTo": "2030/12/31",

            "hwSerial": "No serial number",

            "packetProcessDrv": "DPDK Driver Mode"

    },

    "message": ""

}

4.2  라이선스  정보

4.2.1  라이선스  정보  조회

URL

GET http(s)://[serverip]/mfd/api/sytem/license

Path parameters

None

Query parameters

None

Body

None

Copyright©  2016. SECUI. All rights reserved.

11

IPv4 ACL  설정

Returns

이름

swSerial

featureCode

termFrom

termTo

lkey

misckey

clientcode

issuedate

Type

string

string

string

string

string

string

string

string

application/json

{

    "code": "OK",

    "result": {

        "swSerial": "SWSERIAL",

설명

일련  번호

피처  코드

라이선스  기간  시작일

라이선스  기간  종료일

라이선스  Key

Misc. Key

Client Code

라이선스  발급일

        "featureCode": "00008000080000000000000080088000",

        "termFrom": "2019/01/01",

"termTo": "2021/12/31",

"lkey": "no_license_key",

"misckey": "",

"clientcode": "",

"issuedate": "2019/07/09"

},

    "message": ""

}

4.3  IPv4 ACL  설정

4.3.1  ACL  목록  조회

ACL  목록을  조회한다.

URL

12

Copyright©  2016. SECUI. All rights reserved.

System

GET http(s)://[serverip]/mfd/api/system/4/acls

Path parameters

None

Query parameters

이름

srcIP

srcPort

dstIP

dstPort

protocol

Type

string

string

string

string

string

설명

출발지  네트워크  주소(CIDR  포멧)

ex)10.10.10.0/24

출발지  포트

목적지  네트워크  주소(CIDR  포멧)

ex)10.10.10.0/24

목적지  포트

프로토콜

(ANY: A, TCP: T, UDP: U, ICMP: I)

action

string

동작

(예외: E,  허용: A,  거부: D)

Body

None

Returns

이름

sequence

id

Type

int

int

설명

순번

ID

srcAddr

string

출발지  네트워크  주소(CIDR  포멧)

‘any’  또는  네트워크  주소

0.0.0.0, 127.0.0.1  입력  불가

srcPort

string

출발지  포트

any or 1~65535

targetAddr

string

목적지  네트워크  주소(CIDR  포멧)

‘any’  또는  네트워크  주소

0.0.0.0, 127.0.0.1  입력  불가

dstPort

string

목적지  포트

any or 1~65535

Copyright©  2016. SECUI. All rights reserved.

13

IPv4 ACL  설정

protocol

string

프로토콜

(ANY: any, TCP: T, UDP: U, ICMP: I)

action

string

동작

(ANY: any,  예외: E,  허용: A,  거부: D)

expireDate

string

종료일

년(4)-월(2)-일(2)

2019-10-20

설명(64자)

desc

string

application/json

{

    "code": "OK",

    "result": [

        {

            "sequence": "1",

            "id": "3",

            "srcAddr": "22.22.22.0/24",

            "srcPort": "any",

            "targetAddr": "any",

            "dstPort": "any",

            "protocol": "T",

            "action": "D",

            "expireDate": "2019-08-26",

            "desc": ""

        }

    ],

    "message": ""

}

4.3.2  ACL  추가

ACL을  추가한다.

URL

POST http(s)://[serverip]/mfd/api/system/4/acls

14

Copyright©  2016. SECUI. All rights reserved.

System

Path parameters

None

Query parameters

None

Body

이름

Type

설명

srcAddr

string(required)

출발지  네트워크  주소(CIDR  포멧)

‘any’  또는  네트워크  주소

0.0.0.0, 127.0.0.1  입력  불가

srcPort

string(required)

출발지  포트

any or 1~65535

targetAddr

string(required)

목적지  네트워크  주소(CIDR  포멧)

‘any’  또는  네트워크  주소

0.0.0.0, 127.0.0.1  입력  불가

dstPort

string(required)

목적지  포트

any or 1~65535

protocol

string(required)

프로토콜

(ANY: A, TCP: T, UDP: U, ICMP: I)

ANY가  설정될  경우  출발지/목적지  포트는  ‘any’로

설정된다.

action

string(required)

동작

(예외: E,  허용: A,  거부: D)

expireDate

string

종료일

desc

string

년(4)-월(2)-일(2)

2019-10-20

설명(64자)

-  출발지  주소(srcAddr),  목적지  주소(targetAddr),  출발지  포트(srcPort),  목록지  포트(dstPort)  중

최소  하나는  ANY가  아닌  값으로  입력해야  한다.

application/json

{

    "srcAddr": "22.22.22.0/24",

    "srcPort": "any",

    "targetAddr": "any",

    "dstPort": "any",

    "protocol": "T",

Copyright©  2016. SECUI. All rights reserved.

15

IPv4 ACL  설정

    "action": "D",

    "expireDate": "2019-08-26",

    "desc": ""

}

{

Returns

application/json

    "code": "OK",// OK or FAIL

    "message": ""

}

4.3.3  ACL  수정

4.3.3.1  URL

PUT http(s)://[serverip]/mfd/api/system/4/acls/{id}

4.3.3.2  Path parameters

이름

id

Type

설명

int(required)

ACL ID

4.3.3.3  Query parameters

None

4.3.3.4  Body

이름

srcAddr

Type

설명

string(required)

출발지  네트워크  주소(CIDR  포멧)

‘any’  또는  네트워크  주소

0.0.0.0, 127.0.0.1  입력  불가

srcPort

string(required)

출발지  포트

any or 1~65535

targetAddr

string(required)

목적지  네트워크  주소(CIDR  포멧)

dstPort

string(required)

목적지  포트

‘any’  또는  네트워크  주소

0.0.0.0, 127.0.0.1  입력  불가

16

Copyright©  2016. SECUI. All rights reserved.

System

protocol

string(required)

프로토콜

any or 1~65535

(ANY: A, TCP: T, UDP: U, ICMP: I)

ANY가  설정될  경우  출발지/목적지  포트는

‘any’로

action

string(required)

동작

설정된다.

expireDate

string

종료일

(예외: E,  허용: A,  거부: D)

desc

string

년(4)-월(2)-일(2)

2019-10-20

설명(64자)

-  출발지  주소(srcAddr),  목적지  주소(targetAddr),  출발지  포트(srcPort),  목록지  포트(dstPort)  중

최소  하나는  ANY가  아닌  값으로  입력해야  한다.

application/json

{

    "srcAddr": "22.22.22.0/24",

    "srcPort": "any",

    "targetAddr": "any",

    "dstPort": "any",

    "protocol": "T",

    "action": "D",

    "expireDate": "2019-08-26",

    "desc": ""

}

{

4.3.3.5  Returns

application/json

    "code": "OK",// OK or FAIL

    "message": ""

}

4.3.4  ACL  삭제

ACL을  삭제한다.

Copyright©  2016. SECUI. All rights reserved.

17

IPv4 ACL  설정

URL

DELETE http(s)://[serverip]/mfd/api/system/4/acls/{id}

Path parameters

이름

id

Type

int(required)

설명

ID

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

4.3.5  ACL  적용

편집된  모든  ACL을  운영중인  설정  파일에  적용한다.

4.3.5.1  URL

PUT http(s)://[serverip]/mfd/api/system/4/acls/apply

4.3.5.2  Path parameters

None

4.3.5.3  Query parameters

None

4.3.5.4  Body

None

18

Copyright©  2016. SECUI. All rights reserved.

System

4.3.5.5  Returns

application/json

“code”:”OK”, // OK or FAIL

“message”:”“

{

}

4.3.6  ACL  취소

편집된  모든  ACL을  rollback  한다.

4.3.6.1  URL

PUT http(s)://[serverip]/mfd/api/system/4/acls/cancel

4.3.6.2  Path parameters

None

4.3.6.3  Query parameters

None

4.3.6.4  Body

None

4.3.6.5  Returns

application/json

{

}

“code”:”OK”, // OK or FAIL

“message”:”“

Copyright©  2016. SECUI. All rights reserved.

19

보호  도메인  설정

5.  Policy

5.1  보호  도메인  설정

5.1.1  세그먼트  후보  목록  조회

보호  대상  세그먼트  후보  목록을  조회  한다.

5.1.1.1  URL

GET http(s)://[serverip]/mfd/api/policy/pdomains/segments

5.1.1.2  Path parameters

None

5.1.1.3  Query parameters

None

5.1.1.4  Body

None

5.1.1.5  Returns

세그먼트  ID  배열

application/json

{

    "code": "OK",

    "result": [

        1,

        2,

        3,

        4,

        5,

        6

20

Copyright©  2016. SECUI. All rights reserved.

Policy

    ],

    "message": ""

}

5.1.2  보호  도메인  설정  목록  조회
보호  도메인  설정  목록을  조회한다.

5.1.2.1  URL

GET http(s)://[serverip]/mfd/api/policy/pdomains

5.1.2.2  Path parameters

None

5.1.2.3  Query parameters

None

5.1.2.4  Body

None

5.1.2.5  Returns

이름

id

type

targetList

ectHostList

name

enable

xHeader

statReportEnable

sslProxyEnable

sslInlineEnable

ipsDdosName

ipsDdosPolicy

Type

int

string

설명

ID

분류

(세그먼트: S, VLAN ID: V, IP:I)

Array(string)

보호  대상  목록

Array(string)

예외  호스트  목록

string

boolean

boolean

boolean

boolean

boolean

string

string

이름

사용

X-Header IP  검사

리포트  생성

SSL Inspection(Proxy)

SSL Inspection(Inline)

IPS/DDoS  프로파일  이름

IPS/DDoS  정책

(탐지: D,  차단: B)

Copyright©  2016. SECUI. All rights reserved.

21

string

설명

보호  도메인  설정

desc

{

application/json

    "code": "OK",

    "result": [

        {

            "id": "0",

            "type": "I",

            "targetList": [

                "2.2.2.0/24",

                "5.5.5.0/24"

            ],

            "ectHostList": [

                "2.2.1.1/24-1.1.1.1/24",

                "A-23.3.3.3/24"

            ],

            "name": "default",

            "enable": true,

            "xHeader": false,

            "statReportEnable": true,

            "sslProxyEnable": false,

            "sslInlineEnable": false,

            "ipsDdosName": "default",

            "ipsDdosPolicy": "D",

            "desc": "default protect domain"

        }

    ],

    "message": ""

}

5.1.3  보호  도메인  설정  추가

보호  도메인  설정  정책을  추가한다.

5.1.3.1  URL

POST http(s)://[serverip]/mfd/api/policy/pdomains

22

Copyright©  2016. SECUI. All rights reserved.

Policy

5.1.3.2  Path parameters

None

5.1.3.3  Query parameters

None

5.1.3.4  Body

이름

type

targetList

ectHostList

name

enable

Type

string(required)

설명

분류

(세그먼트: S, VLAN ID: V, IP:I)

Array(string)(required)

보호  대상  목록

Array(string)

예외  호스트  목록

string(required)

이름(32자)

Boolean

사용

기본값:false

xHeader

Boolean

X-Header IP  검사

statReportEnable

Boolean

기본값:false

리포트  생성

기본값:false

sslProxyEnable

Boolean

SSL Inspection(Proxy)

기본값:false

sslInlineEnable

Boolean

SSL Inspection(Inline)

기본값:false

ipsDdosName

string

IPS/DDoS  프로파일  이름

기본값: “default”

값이  입력될  경우  프로파일  존재여부  체크

필요

IPS/DDoS  정책

(탐지: D,  차단: B)

기본값:’D’

설명(128자)

ipsDdosPolicy

string

string

application/json

desc

{

    "type": "I",

    "targetList": [

        "2.2.2.0/24",

Copyright©  2016. SECUI. All rights reserved.

23

보호  도메인  설정

        "5.5.5.0/24"

    ],

    "ectHostList": [

        "2.2.1.1/24-1.1.1.1/24",

        "A-23.3.3.3/24"

    ],

    "name": "default",

    "enable": true,

    "xHeader": false,

    "statReportEnable": true,

    "sslProxyEnable": false,

    "sslInlineEnable": false,

    "ipsDdosName": "default",

    "ipsDdosPolicy": "D",

    "desc": "default protect domain"

}

{

5.1.3.5  Returns

application/json

    "code": "OK",// OK or FAIL

    "message": ""

}

5.1.4  보호  도메인  설정  수정

보호  도메인  설정을  수정한다.

5.1.4.1  URL

PUT http(s)://[serverip]/mfd/api/policy/pdomains/{id}

5.1.4.2  Path parameters

이름

id

Type

int(required)

설명

ID

24

Copyright©  2016. SECUI. All rights reserved.

Policy

5.1.4.3  Query parameters

None

5.1.4.4  Body

이름

type

targetList

ectHostList

name

enable

Type

string(required)

설명

분류

(세그먼트: S, VLAN ID: V, IP:I)

Array(string)(required)  보호  대상  목록

Array(string)

예외  호스트  목록

string(required)

이름(32자)

Boolean

사용

기본값:false

xHeader

Boolean

X-Header IP  검사

statReportEnable

Boolean

기본값:false

리포트  생성

기본값:false

sslProxyEnable

Boolean

SSL Inspection(Proxy)

기본값:false

sslInlineEnable

Boolean

SSL Inspection(Inline)

기본값:false

ipsDdosName

string

IPS/DDoS  프로파일  이름

기본값: “default”

값이  입력될  경우  프로파일  존재여부  체크  필요

IPS/DDoS  정책

(탐지: D,  차단: B)

기본값:’D’

설명(128자)

ipsDdosPolicy

string

string

application/json

desc

{

    "type": "I",

    "targetList": [

        "2.2.2.0/24",

        "5.5.5.0/24"

    ],

    "ectHostList": [

        "2.2.1.1/24-1.1.1.1/24",

        "A-23.3.3.3/24"

Copyright©  2016. SECUI. All rights reserved.

25

보호  도메인  설정

    ],

    "name": "default",

    "enable": true,

    "xHeader": false,

    "statReportEnable": true,

    "sslProxyEnable": false,

    "sslInlineEnable": false,

    "ipsDdosName": "default",

    "ipsDdosPolicy": "D",

    "desc": "default protect domain"

}

{

}

5.1.4.5  Returns

application/json

“code”:”OK”,

“message”:”“

5.1.5  보호  도메인  설정  삭제

보호  도메인  설정을  삭제한다.

5.1.5.1  URL

DELETE http(s)://[serverip]/mfd/api/policy/pdomains/{id}

5.1.5.2  Path parameters

이름

id

Type

int(required)

설명

ID

5.1.5.3  Query parameters

None

5.1.5.4  Body

None

26

Copyright©  2016. SECUI. All rights reserved.

Policy

5.1.5.5  Returns

application/json

{

}

“code”:”OK”,

“message”:”“

5.1.6  보호  도메인  설정  적용/취소

5.1.6.1  객체  적용

편집된  보호  도메인  설정  내용들을  운영중인  설정  파일에  적용한다.

URL

PUT http(s)://[serverip]/mfd/api/policy/pdomains/apply

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

5.1.6.2  객체  취소

편집된  모든  객체  내용들을  rollback  한다.

Copyright©  2016. SECUI. All rights reserved.

27

차단  목록  설정

URL

PUT http(s)://[serverip]/mfd/api/policy/pdomains/cancel

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

5.2  차단  목록  설정

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

28

Copyright©  2016. SECUI. All rights reserved.

Policy

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

5.2.1  사용자  정의  차단  목록  조회
사용자  정의  차단  목록을  조회한다.

5.2.1.1  URL

GET http(s)://[serverip]/mfd/api/policy/user-black-list

5.2.1.2  Path parameters

None

5.2.1.3  Query parameters

None

5.2.1.4  Body

None

Copyright©  2016. SECUI. All rights reserved.

29

차단  목록  설정

5.2.1.5  Returns

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

0~65535

0  값은  ‘ANY’값을  의미한다.

프로토콜

0~255

0  값은  ‘ANY’값을  의미한다.

설명

종료일

년(4)월(2)일(2)

20191020

protocol

int(required)

desc

expireDate

string

string

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

            "expireDate": "20191020",

            "desc": "설명"

        }

    ],

    "message": ""

30

Copyright©  2016. SECUI. All rights reserved.

Policy

}

5.2.2  사용자  정의  차단  추가

하나의  차단  정책을  추가한다.

5.2.2.1  URL

POST http(s)://[serverip]/mfd/api/policy/user-black-list

5.2.2.2  Path parameters

None

5.2.2.3  Query parameters

None

5.2.2.4  Body

이름

srcIP

Type

설명

string(required)

출발지  IP  주소

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

0~65535

0  값은  ‘ANY’값을  의미한다.

protocol

string(required)

프로토콜

0~255

0  값은  ‘ANY’값을  의미한다.

프로토콜  정보는  객체  설정  >  서비스  객체  >  프로토콜

목록  조회를  참고한다.

Copyright©  2016. SECUI. All rights reserved.

31

차단  목록  설정

또는  시스템  정의  기본  프로토콜  정보  참고

desc

expireDate

string

string

설명(256Bytes)

종료일

년(4)월(2)일(2)

20191020

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

    "expireDate": "20191020",

    "desc": "설명"

}

-

{

5.2.2.5  Returns

application/json

    "code": "OK",// OK or FAIL

    "message": ""

}

5.2.3  사용자  정의  차단  삭제

하나의  차단  정책을  삭제한다.

5.2.3.1  URL

DELETE http(s)://[serverip]/mfd/api/policy/user-black-list

32

Copyright©  2016. SECUI. All rights reserved.

Policy

5.2.3.2  Path parameters

None

5.2.3.3  Query parameters

None

5.2.3.4  Body

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

0~65535

0  값은  ‘ANY’값을  의미한다.

프로토콜

0~255

0  값은  ‘ANY’값을  의미한다.

설명(256Bytes)

종료일

년(4)월(2)일(2)

20191020

protocol

int(required)

desc

expireDate

string

string

application/json

{

    "srcIP": "10.10.10.20",

    "srcPort": 0,

    "dstIP ": "0",

    "dstPort": 0,

    "protocol": 0,

"desc": "설명",

"expireDate": "20191020"

Copyright©  2016. SECUI. All rights reserved.

33

차단  목록  설정

}

{

}

5.2.3.5  Returns

application/json

“code”:”OK”,

“message”:”“

5.2.4  사용자  정의  차단  목록  적용/취소

5.2.4.1  사용자  정의  차단  목록  적용

편집된  모든  객체  내용들을  운영중인  설정  파일에  적용한다.

URL

PUT http(s)://[serverip]/mfd/api/policy/user-black-list/apply

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

5.2.4.2  사용자  정의  차단  목록  취소

편집된  모든  객체  내용들을  rollback  한다.

34

Copyright©  2016. SECUI. All rights reserved.

URL

PUT http(s)://[serverip]/mfd/api/policy/user-black-list/cancel

Policy

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

Copyright©  2016. SECUI. All rights reserved.

35

