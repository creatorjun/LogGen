API  명세서

v1.11

㈜티앤디소프트

문서  이력

버전

v1.0

v1.1

v1.2

v1.3

v1.4

v1.5

v1.6

비고

일자

내용

2021.11.15  초기  명세  작성

2021.11.15  검색  관련  명세  추가

list  응답에  id  필드  추가

mod  및  del  명령시  필드  변경

2021.11.25

api  결과  샘플  추가

2021.12.01

api  결과  샘플  추가

일부  API parameter  조정

2021.12.06  검색  관련  api  명세  추가

2021.12.20

file upload  관련  명세  추가

2021.12.23  삭제  관련  API  변경

국가정보에  위,경도  정보  추가

작성자

김영곤

김영곤

김영곤

김영곤

김영곤

김영곤

김영곤

v1.7

2022.09.22  등록  IP  현황  및  세션  로그  현황

이예진

관련  명세  추가

2023.04.04  최신  API  상태  반영

2023.04.10  일부  누락된  API  수정사항  반영

v1.8

v1.9

v1.10

2023.05.22  Manager  관련  API  수정

김영곤

김영곤

김영곤

유해  IP  상세정보  조회  API  추가

v1.11

2023.07.25  국가별  차단  관련  API  추가

김영곤

Manager  관련  whitestlist API  변경

목차  재조정

1. API  목록

1.1.  개요

본  문서는  ㈜티앤디소프트  제품에서  제공하는  API에  대한  설명을  제공한다.

1.2. API  리스트

제공하는  API  리스트는  아래와  같다.

기능

URL

Method

로그인

비밀번호  변경

사용자  관리

로그아웃

차단  현황

실시간  차단  세션

시스템  상태

시간대별  차단  통계

IP별  차단  통계

등록  IP  현황

세션  로그  현황

통신  인터페이스  설정

관리  인터페이스  설정

라우팅  정보  설정

DNS  정보  설정

/1/apis/login

/1/apis/chpass

/1/apis/user

/1/apis/logout

/1/apis/summary/sums

/1/apis/summary/sums

/1/apis/summary/sums

/1/apis/summary/sums

/1/apis/summary/sums

/1/apis/summary/sums

/1/apis/summary/sums

/1/apis/setting/data_iface

/1/apis/setting/mgmt_iface

/1/apis/setting/mgmt_route

/1/apis/setting/mgmt_dns

국가별  차단  정보  설정

/1/apis/setting/block_country

유해  IP  배포  서버  설정

/1/apis/server/mip_server

Custom  유해  IP  배포  서버  설정

/1/apis/server/cmip_server

로그  서버  설정

유해  IP  관리

/1/apis/server/log_server

/1/apis/server/mip_info

화이트리스트  IP  관리

/1/apis/server/whiteip_info

세션  로그

정책  로그

시스템  로그

세션  통계

포트  정보

업데이트

백업

복구

/1/apis/log/sesslog

/1/apis/log/pollog

/1/apis/log/syslog

/1/apis/log/sessstat

/1/apis/log/portstat

/1/apis/update

/1/apis/backup

/1/apis/restore

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

POST

정책  적용

라이선스  등록

라이선스  검사

About

/1/apis/apply

/1/apis/license

/1/apis/license

/1/apis/about

POST

POST

POST

POST

1.3. Manager  관련  API  리스트

제공하는  Manager  관련  API  리스트는  아래와  같다.

기능

URL

Method

유해  IP  관리

화이트리스트  IP  관리

배포서버별  차단  통계

Manager  관련  설정

1.4. API  요청  및  응답

/1/apis/manager/mip_info

/1/apis/manager/whiteip_info

/1/apis/manager/sums

/1/apis/manager/setting

POST

POST

POST

POST

API  사용을  위해서는  필요한  HTTP header  및  body  정보가  전송되어야  한다.

◼  요청  메시지  Header  포맷

Authorization

Login API를  통해  받은  token  정보

Login API에서는  사용하지  않음

Content-Type

application/json

예)

POST /1/apis/chgpwd HTTP/1.1

User-Agent: python-requests/2.26.0

Accept-Encoding: gzip, deflate

Accept: */*

Connection: keep-alive

Authorization: ABCD

Content-Type: application/json

Content-Length: 26

◼  요청  메시지  body  포맷

Json  포맷으로  된  parameter  리스트이며  각  API마다  형식이  다름

예)

{'cmd' : 'init', 'id': 'admin', 'old_pwd' : '', 'new_pwd': 'abcdefg'}

◼  응답  메시지  body  포맷

Json  포맷으로  된  parameter  리스트이며  각  API마다  형식이  다름

예)

{'status' : 1, 'code' : 1001}

2.  사용자

2.1.  로그인

관리자  또는  사용자  계정으로  로그인을  시도하고  로그인  결과를  받아온다.

◼  요청  메시지  포맷

URL

Method

/1/apis/login

POST

Content-Type

application/json

body

{'id': 'admin', 'pass': 'abcdefg'}



id :  로그인  계정

  pass :  비밀번호

◼  응답  메시지  포맷

항목

값

설명

0  또는  1(상태  정의  참조)

로그인  성공  여부

문자열

0  또는  1

코드  정의  참조

0  또는  1

문자열

로그인  성공  시  인증  token

사용자  타입

리턴  코드

관리자  초기  접속  여부

사용자  이름

status

token

type

code

init

name











status : 0이면  실패, 1이면  성공

token :  성공일  경우  추가적인  모든  API  사용시  헤더에  추가되어야  함

type : 0이면  일반  사용자, 1이면  관리자

code :  성공  또는  실패에  대한  상세  코드값

init : 0이면  무시, 1이면  관리자  비밀번호  초기  변경  페이지로  전환

  name :  사용자  이름

(성공)

{

        "status": 1,

        "token": "bdf5bf3ed8da736b3ca88037455d5d00",

        "type": 0,

        "code": 1000,

        "init": 0,

        “name”: “user”

}

(실패)

{

        "status": 0,

"code": 1004

}

2.2.  비밀번호  변경

관리자  또는  사용자  계정으로  로그인을  시도하고  로그인  결과를  받아온다.

◼  요청  메시지  포맷

URL

Method

/1/apis/chpass

POST

Authorization

token

Content-Type

application/json

Body

{'cmd' : 'init', 'id': 'admin', 'old_pass' : '', 'new_pass: 'abcdefg'}



cmd  :  로그인  결과  init  값이  1이면  init으로  지정.  나머지는  normal로  지정.  단  관리

자가  사용자  비밀번호를  강제로  변경하고자  할  경우에는  init  값을  1로  지정, old_pass

는  ‘’로  지정, new_pass를  지정하면  됨



id :  로그인  계정

  old_pass :  현재  비밀번호.  단  cmd가  init인  경우  빈문자열  지정

  new_pass :  새  비밀번호

◼  응답  메시지  포맷

항목

값

설명

0  또는  1(상태  정의  참조)

비밀번호  변경  성공  여부

코드  정의  참조

리턴  코드

status

code

(성공)

{

        "status": 1,

        "code": 1000

}

(실패)

{

        "status": 0,

        "code": 1005

}

2.3.  사용자  관리

사용자  관련된  정보를  추가,  수정,  삭제,  조회한다.  주로  설정에서  사용자  정보를  확인하기  위해

사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/user

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’}

{‘cmd’

:

‘add’,

‘uid’:’test01’,

‘name’:’hong’,

‘tel’:’123-1234’,

‘email’:’test@test.com’, ‘type’:0, ‘pass’:’qwe123’}

{‘cmd’

:

‘mod’,

‘uid’:’test01’,

‘oname’:’hong’,

‘otel’:’123-1234’,

‘oemail’:’test@test.com’, ‘otype’:0, ‘opass’:’’, ‘nname’:’kim’, ‘ntel’:’123-

1234’, ‘nemail’:’test@test.com’, ‘ntype’:0, ‘npass’:’’}

{‘cmd’ : ‘del.’, ‘uid’:[’test01’]}

{‘cmd’ : ‘search’, ‘uid’:’test01’, ‘type’:0}



cmd :  사용자에  대한  추가,  수정,  삭제,  리스트를  위한  명령  지정

◼  응답  메시지  포맷(list/search)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

문자열

문자열

문자열

문자열

정수(0/1)

문자열

Info entry  개수

사용자  계정

담당자명

전화번호

이메일  주소

일반사용자  /  관리자

날짜

status

code

users

  num

info

  uid

name

tel

email

type

date

(성공)

{

        "status": 1,

        "code": 1001,

        "users": {

                "num": 6,

                "info": [

                        {

                                "uid": "testuser001",

                                "name": "\uad00\ub9ac\uc7901",

                                "email": "test1@naver.com",

                                "phone": "010-2434-1414",

                                "type": 1,

                                "date": "1970-01-01 00:00:00"

                        },

                        {

                                "uid": "testuser002",

                                "name": "\uad00\ub9ac\uc7902",

                                "email": "test2@naver.com",

                                "phone": "010-2434-1414",

                                "type": 1,

                                "date": "1970-01-01 00:00:00"

                        },

                        {

                                "uid": "testuser003",

                                "name": "\uc77c\ubc18\uc0ac\uc6a9\uc7903",

                                "email": "test3@naver.com",

                                "phone": "010-2434-1414",

                                "type": 0,

                                "date": "1970-01-01 00:00:00"

                        },

                        {

                                "uid": "testuser004",

                                "name": "\uc77c\ubc18\uc0ac\uc6a9\uc7904",

                                "email": "test4@naver.com",

                                "phone": "010-2434-1414",

                                "type": 0,

                                "date": "1970-01-01 00:00:00"

                        },

                        {

                                "uid": "testuser005",

                                "name": "\uc77c\ubc18\uc0ac\uc6a9\uc7905",

                                "email": "test5@naver.com",

                                "phone": "010-2434-1414",

                                "type": 1,

                                "date": "1970-01-01 00:00:00"

                        },

                        {

                                "uid": "testuser100",

                                "name": "tndsoft_user200",

                                "email": "td1@tndsoft.com",

                                "phone": "010-111-2222",

                                "type": 0,

                                "date": "1970-01-01 00:00:00"

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

◼  응답  메시지  포맷(add/mod/del)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

status

code

(성공)

{

        "status": 1,

        "code": 1000

}

(실패)

{

        "status": 0,

        "code": 1004

}

2.4.  로그아웃

로그아웃  기능을  수행한다.

◼  요청  메시지  포맷

URL

Method

/1/apis/logout

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘logout’, ‘token’:token}



cmd : logout  명령  지정

◼  응답  메시지  포맷

항목

값

설명

status

code

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

3.  대시보드

3.1.  차단  현황

국가별  차단현황을  요청하고  결과를  받아온다.  주로  대시보드에서  차단현황을  보여주기  위해  사

용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/summary/sums

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘country_basic’}



cmd  :  차단  현황  유형으로서  대시보드에서는  country_basic을  지정.  차단현황을  상세

하게  볼  때는  country_detail을  지정

◼  응답  메시지  포맷(country_basic)

항목

값

설명

status

code

basic

  num

info

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

Info entry  개수

  country

2자리  영문자

count

latitude

longitude

정수

실수

실수

country_long  문자열

2자리  국가코드

차단  개수

국가  위도  좌표

국가  경도  좌표

국가명

country_code  3자리  영문자

3자리  국가코드

(성공)

{

        "status": 1,

        "code": 1001,

        "basic": {

                "num": 10,

                "info": [

                        {

                                "country": "AB",

                                "count": 65,

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "BC",

                                "count": 66

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "CD",

                                "count": 67

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "DE",

                                "count": 68

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "EF",

                                "count": 69

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "FG",

                                "count": 70

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "GH",

                                "count": 71

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "HI",

                                "count": 72

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "IJ",

                                "count": 73

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "JK",

                                "count": 74

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

◼  응답  메시지  포맷(country_detail)

항목

값

설명

status

code

basic

  num

info

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

Info entry  개수

  country

2자리  영문자

count

latitude

longitude

정수

실수

실수

country_long  문자열

2자리  국가코드

차단  개수

국가  위도  좌표

국가  경도  좌표

국가명

country_code  3자리  영문자

3자리  국가코드

ips

  num

info

ip

정수

문자열

country

2자리  영문자

count

date

detail

정수

문자열

  server

문자열

reg_date  문자열

reg_org

문자열

org

문자열

Info entry  개수

IP  주소

국가코드

차단  개수

최근  차단  날짜

IP  주소

IP  등록  날짜

국가코드

IP  등록  기관

countries

  num

정수

Info entry  개수

info

  country

2자리  영문자

정수

국가코드

차단  개수

실수(소수점  1자리)

비율

count

ratio

(성공)

{

        "status": 1,

        "code": 1001,

        "basic": {

                "num": 10,

                "info": [

                        {

                                "country": "AB",

                                "count": 65

"latitude": 1.23456,

                                “longitude”: -32.11111,

                                “country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "BC",

                                "count": 66

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "CD",

                                "count": 67

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "DE",

                                "count": 68

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "EF",

                                "count": 69

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "FG",

                                "count": 70

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "GH",

                                "count": 71

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "HI",

                                "count": 72

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "IJ",

                                "count": 73

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        },

                        {

                                "country": "JK",

                                "count": 74

"latitude": 1.23456,

                                “longitude”: -32.11111,

“country_long”: “U.S.A”,

                                “country_code”: “USA”

                        }

                ]

        },

        "ips": {

                "num": 10,

                "info": [

                        {

                                "ip": "192.168.100.100",

                                "country": "AB",

                                "count": 65,

                                "date": "2021-11-11 10:00:00",

                                "detail": {

                                        "server": "123.123.123.1",

                                        "reg_date": "2021-10-10 10:00:00",

                                        "reg_org": "US",

                                        “org”: “TAXII”

                                }

                        },

                        {

                                "ip": "192.168.100.100",

                                "country": "BC",

                                "count": 66,

                                "date": "2021-11-11 10:00:00",

                                "detail": {

                                        "server": "123.123.123.1",

                                        "reg_date": "2021-10-10 10:00:00",

"reg_org": "US",

                                        “org”: “TAXII”

                                }

                        },

                        {

                                "ip": "192.168.100.100",

                                "country": "CD",

                                "count": 67,

                                "date": "2021-11-11 10:00:00",

                                "detail": {

                                        "server": "123.123.123.1",

                                        "reg_date": "2021-10-10 10:00:00",

"reg_org": "US",

                                        “org”: “TAXII”

                                }

                        },

                        {

                                "ip": "192.168.100.100",

                                "country": "DE",

                                "count": 68,

                                "date": "2021-11-11 10:00:00",

                                "detail": {

                                        "server": "123.123.123.1",

                                        "reg_date": "2021-10-10 10:00:00",

"reg_org": "US",

                                        “org”: “TAXII”

                                }

                        },

                        {

                                "ip": "192.168.100.100",

                                "country": "EF",

                                "count": 69,

                                "date": "2021-11-11 10:00:00",

                                "detail": {

                                        "server": "123.123.123.1",

                                        "reg_date": "2021-10-10 10:00:00",

"reg_org": "US",

                                        “org”: “TAXII”

                                }

                        },

                        {

                                "ip": "192.168.100.100",

                                "country": "FG",

                                "count": 70,

                                "date": "2021-11-11 10:00:00",

                                "detail": {

                                        "server": "123.123.123.1",

                                        "reg_date": "2021-10-10 10:00:00",

"reg_org": "US",

                                        “org”: “TAXII”

                                }

                        },

                        {

                                "ip": "192.168.100.100",

                                "country": "GH",

                                "count": 71,

                                "date": "2021-11-11 10:00:00",

                                "detail": {

                                        "server": "123.123.123.1",

                                        "reg_date": "2021-10-10 10:00:00",

"reg_org": "US",

                                        “org”: “TAXII”

                                }

                        },

                        {

                                "ip": "192.168.100.100",

                                "country": "HI",

                                "count": 72,

                                "date": "2021-11-11 10:00:00",

                                "detail": {

                                        "server": "123.123.123.1",

                                        "reg_date": "2021-10-10 10:00:00",

"reg_org": "US",

                                        “org”: “TAXII”

                                }

                        },

                        {

                                "ip": "192.168.100.100",

                                "country": "IJ",

                                "count": 73,

                                "date": "2021-11-11 10:00:00",

                                "detail": {

                                        "server": "123.123.123.1",

                                        "reg_date": "2021-10-10 10:00:00",

"reg_org": "US",

                                        “org”: “TAXII”

                                }

                        },

                        {

                                "ip": "192.168.100.100",

                                "country": "JK",

                                "count": 74,

                                "date": "2021-11-11 10:00:00",

                                "detail": {

                                        "server": "123.123.123.1",

                                        "reg_date": "2021-10-10 10:00:00",

"reg_org": "US",

                                        “org”: “TAXII”

                                }

                        }

                ]

        },

        "countries": {

                "num": 10,

                "info": [

                        {

                                "country": "AB",

                                "count": 65,

                                "ratio": 72.2

                        },

                        {

                                "country": "BC",

                                "count": 66,

                                "ratio": 73.3

                        },

                        {

                                "country": "CD",

                                "count": 67,

                                "ratio": 74.4

                        },

                        {

                                "country": "DE",

                                "count": 68,

                                "ratio": 75.6

                        },

                        {

                                "country": "EF",

                                "count": 69,

                                "ratio": 76.7

                        },

                        {

                                "country": "FG",

                                "count": 70,

                                "ratio": 77.8

                        },

                        {

                                "country": "GH",

                                "count": 71,

                                "ratio": 78.9

                        },

                        {

                                "country": "HI",

                                "count": 72,

                                "ratio": 80.0

                        },

                        {

                                "country": "IJ",

                                "count": 73,

                                "ratio": 81.1

                        },

                        {

                                "country": "JK",

                                "count": 74,

                                "ratio": 82.2

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

3.2.  실시간  차단  세션

실시간  차단  세션  현황을  요청하고  결과를  받아온다.  주로  대시보드에서  실시간  차단  세션을  보

여주기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/summary/sums

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘session’, ‘count’ : 50}





cmd :  실시간  차단  세션을  요청을  위해서는  session을  지정

count :  최대  요청하는  실시간  최대  세션  수(10~200, default : 50)

◼  응답  메시지  포맷

항목

값

설명

status

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

문자열

문자열

문자열

문자열

문자열

문자열

Info entry  개수

출발지  IP  주소

출발지  Port

목적지  IP  주소

목적지  Port

프로토콜

차단시간

code

sessions

  num

info

  sip

sport

dip

dport

protocol

date

(성공)

{

        "status": 1,

        "code": 1001,

        "sessions": {

                "num": 10,

                "info": [

                        {

                                "sip": "100.100.100.1",

                                "sport": "1024",

                                "dip": "100.100.100.2",

                                "dport": "8080",

                                "protocol": "tcp",

                                “date”: “2023-04-04 12:01:31”

                        },

                        {

                                "sip": "100.100.100.1",

                                "sport": "1024",

                                "dip": "100.100.100.2",

                                "dport": "8080",

                                "protocol": "tcp",

“date”: “2023-04-04 12:01:31”

                        },

                        {

                                "sip": "100.100.100.1",

                                "sport": "1024",

                                "dip": "100.100.100.2",

                                "dport": "8080",

                                "protocol": "tcp",

“date”: “2023-04-04 12:01:31”

                        },

                        {

                                "sip": "100.100.100.1",

                                "sport": "1024",

                                "dip": "100.100.100.2",

                                "dport": "8080",

                                "protocol": "tcp",

“date”: “2023-04-04 12:01:31”

                        },

                        {

                                "sip": "100.100.100.1",

                                "sport": "1024",

                                "dip": "100.100.100.2",

                                "dport": "8080",

                                "protocol": "tcp",

“date”: “2023-04-04 12:01:31”

                        },

                        {

                                "sip": "100.100.100.1",

                                "sport": "1024",

                                "dip": "100.100.100.2",

                                "dport": "8080",

                                "protocol": "tcp",

“date”: “2023-04-04 12:01:31”

                        },

                        {

                                "sip": "100.100.100.1",

                                "sport": "1024",

                                "dip": "100.100.100.2",

                                "dport": "8080",

                                "protocol": "tcp",

“date”: “2023-04-04 12:01:31”

                        },

                        {

                                "sip": "100.100.100.1",

                                "sport": "1024",

                                "dip": "100.100.100.2",

                                "dport": "8080",

                                "protocol": "tcp",

“date”: “2023-04-04 12:01:31”

                        },

                        {

                                "sip": "100.100.100.1",

                                "sport": "1024",

                                "dip": "100.100.100.2",

                                "dport": "8080",

                                "protocol": "tcp",

“date”: “2023-04-04 12:01:31”

                        },

                        {

                                "sip": "100.100.100.1",

                                "sport": "1024",

                                "dip": "100.100.100.2",

                                "dport": "8080",

                                "protocol": "tcp",

“date”: “2023-04-04 12:01:31”

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

3.3.  시스템  상태

현재  시스템  상태를  요청하고  결과를  받아온다.  주로  대시보드에서  시스템  상태를  보여주기  위해

사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/summary/sums

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘system’ }



cmd :  시스템  상태  요청을  위해서는  system을  지정

◼  응답  메시지  포맷

항목

값

설명

status

code

cpu

memory

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

정수

정수

리턴  코드

CPU  사용율

메모리  사용율

정수

정수

정수

정수

정수

정수

정수

정수

전체  메모리  용량

사용중인  메모리  용량

HDD  디스크  사용율

전체  HDD  디스크  용량

사용중인  HDD  디스크  용량

SSD  디스크  사용율

전체  SSD  디스크  용량

사용중인  SSD  디스크  용량

0  또는  1

0  또는  1

엔진  상태

로그  상태

mtotal

mused

storage

stotal

sused

dom

dtotal

dused

engine

log

(성공)

{

        "status": 1,

        "code": 1001,

        "cpu": 50,

        "memory": 26,

        “mtotal”: 19,

        “mused”: 5,

        "storage": 0,

        “stotal”: 915,

        “sused”: 2,

        “dom”: 23,

        “dtotal”: 113,

        “dused”: 25,

        "engine": 1,

        "log": 1

}

(실패)

{

        "status": 0,

        "code": 1005

}

3.4.  시간대별  차단  통계

시간대별  차단  통계를  요청하고  결과를  받아온다.  주로  대시보드에서  시간대별  차단  통계를  보여

주기  위해  사용된다.

◼  요청  메시지  포맷

URL

/1/apis/summary/sums

Method

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘timestat’ }



cmd :  시간대별  차단통계를  위해서는  timestat을  지정

◼  응답  메시지  포맷

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

문자열

정수

정수

정수

정수

문자열

정수

정수

정수

정수

문자열

정수

정수

정수

Info entry  개수

날짜

출발지  IP  차단  개수

목적지  IP  차단  개수

프로토콜  차단  개수

Info entry  개수

날짜

출발지  IP  차단  개수

목적지  IP  차단  개수

프로토콜  차단  개수

Info entry  개수

날짜

출발지  IP  차단  개수

목적지  IP  차단  개수

프로토콜  차단  개수

status

code

daily

  num

info

  date

sip_cnt

dip_cnt

proto_cnt

weelky

  num

info

  date

sip_cnt

dip_cnt

proto_cnt

monthly

  num

info

  date

sip_cnt

dip_cnt

proto_cnt

(성공)

{

        "status": 1,

        "code": 1001,

        "daily": {

                "num": 5,

                "info": [

                        {

                                "date": "2021-11-1",

                                "sip_cnt": 11,

                                "dip_cnt": 21,

                                "proto_cnt": 31

                        },

                        {

                                "date": "2021-11-2",

                                "sip_cnt": 12,

                                "dip_cnt": 22,

                                "proto_cnt": 32

                        },

                        {

                                "date": "2021-11-3",

                                "sip_cnt": 13,

                                "dip_cnt": 23,

                                "prot_cnt": 33

                        },

                        {

                                "date": "2021-11-4",

                                "sip_cnt": 14,

                                "dip_cnt": 24,

                                "proto_cnt": 34

                        },

                        {

                                "date": "2021-11-5",

                                "sip_cnt": 15,

                                "dip_cnt": 25,

                                "proto_cnt": 35

                        }

                ]

        },

        "weekly": {

                "num": 2,

                "info": [

                        {

                                "date": "2021-11-8",

                                "sip_cnt": 101,

                                "dip_cnt": 201,

                                "protp_cnt": 301

                        },

                        {

                                "date": "2021-11-9",

                                "sip_cnt": 102,

                                "dip_cnt": 202,

                                "proto_cnt": 302

                        }

                ]

        },

        "monthly": {

                "num": 2,

                "info": [

                        {

                                "date": "2021-10",

                                "sip_cnt": 1010,

                                "dip_cnt": 2010,

                                "proto_cnt": 3010

                        },

                        {

                                "date": "2021-11",

                                "sip_cnt": 1011,

                                "dip_cnt": 2011,

                                "proto_cnt": 3011

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

3.5. IP 별  차단  통계

IP별  차단  통계를  요청하고  결과를  받아온다.  주로  대시보드에서  IP별  차단  통계를  보여주기  위해

사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/summary/sums

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘ipstat’ }



cmd :  시간대별  차단통계를  위해서는  ipstat을  지정

◼  응답  메시지  포맷

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

문자열

정수

정수

문자열

정수

Info entry  개수

출발지  IP  주소

차단  개수

Info entry  개수

목적지  IP  주소

차단  개수

status

code

sips

  num

info

ip

count

dips

  num

info

ip

count

(성공)

{

        "status": 1,

        "code": 1001,

        "sips": {

                "num": 12,

                "info": [

                        {

                                "ip": "192.168.100.100",

                                "count": 100

                        },

                        {

                                "ip": "192.168.100.101",

                                "count": 101

                        },

                        {

                                "ip": "192.168.100.102",

                                "count": 102

                        },

                        {

                                "ip": "192.168.100.103",

                                "count": 103

                        },

                        {

                                "ip": "192.168.100.104",

                                "count": 104

                        },

                        {

                                "ip": "192.168.100.105",

                                "count": 105

                        },

                        {

                                "ip": "192.168.100.106",

                                "count": 106

                        },

                        {

                                "ip": "192.168.100.107",

                                "count": 107

                        },

                        {

                                "ip": "192.168.100.108",

                                "count": 108

                        },

                        {

                                "ip": "192.168.100.109",

                                "count": 109

                        },

                        {

                                "ip": "192.168.100.110",

                                "count": 110

                        },

                        {

                                "ip": "192.168.100.111",

                                "count": 111

                        }

                ]

        },

        "dips": {

                "num": 8,

                "info": [

                        {

                                "ip": "192.168.200.200",

                                "count": 220

                        },

                        {

                                "ip": "192.168.200.201",

                                "count": 221

                        },

                        {

                                "ip": "192.168.200.202",

                                "count": 222

                        },

                        {

                                "ip": "192.168.200.203",

                                "count": 223

                        },

                        {

                                "ip": "192.168.200.204",

                                "count": 224

                        },

                        {

                                "ip": "192.168.200.205",

                                "count": 225

                        },

                        {

                                "ip": "192.168.200.206",

                                "count": 226

                        },

                        {

                                "ip": "192.168.200.207",

                                "count": 227

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

3.6.  등록  IP  현황

등록  IP  현황을  요청하고  결과를  가져온다.  주로  대시보드에서  등록된  유해  IP,  화이트  IP,

예외  IP들의  총  개수와  당일  등록  개수를  보여주기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/summary/sums

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘ipcount’ }



cmd :  등록  IP  현황  정보를  가져오기  위해서는  ipcount를  지정

◼  응답  메시지  포맷

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

정수

정수

정수

정수

정수

정수

등록된  유해  IP  총  개수

당일  등록된  유해  IP  개수

등록된  화이트  IP  총  개수

당일  등록된  화이트  IP  개수

등록된  예외  IP  총  개수

당일  등록된  예외  IP  개수

Info entry  개수

정수(0-3)

interface index

문자열(UP / DOWN)

interface  상태

문자열(1G / 10G / 40G)

interface  속도

status

code

btt

btd

wtt

wtd

ett

etd

ports

  num

info

index

status

speed

ports_stat

  num

info

  bs_cnt

ps_cnt

port_stat

  num

info

rx_cnt

rx_byte

tx_cnt

tx_byte

1

정수

정수

8

정수

정수

정수

정수

drop_cnt  정수

drop_byte  정수

create_dat

문자열

(성공)

Info entry  개수

차단  세션수

허용  세션수

Info entry  개수

rx  패킷  개수

rx  바이트  수

tx  패킷  개수

tx  바이트  수

drop  패킷  개수

drop  바이트  수

생성  시간

{

"status": 1,

        "code": 1001,

        "btt": 43821,

        "btd": 0,

        "wtt": 0,

        "wtd": 0,

        "ett": 0,

        "etd": 0,

        "ports": {

                "num": 8,

                "info": [

                        {

                                "index": 0,

                                "status": "UP",

                                "speed": "1G"

                        },

                        {

                                "index": 1,

                                "status": "UP",

                                "speed": "1G"

                        },

                        {

                                "index": 2,

                                "status": "UP",

                                "speed": "1G"

                        },

                        {

                                "index": 3,

                                "status": "UP",

                                "speed": "1G"

                        },

                        {

                                "index": 4,

                                "status": "DOWN",

                                "speed": "0M"

},

                        {

                                "index": 5,

                                "status": "DOWN",

                                "speed": "0M"

                        },

                        {

                                "index": 6,

                                "status": "DOWN",

                                "speed": "0M"

                        },

                        {

                                "index": 7,

                                "status": "DOWN",

                                "speed": "0M"

                        }

                ]

        },

"ports_stat": {

                "num": 1,

                "info": [

                        {

                                "bs_cnt": 0,

                                "ps_cnt": 0,

                                "port_stats": {

                                        "num": 8,

                                        "info": [

                                                {

                                                        "rx_cnt": 115320,

                                                        "rx_byte": 20931407,

                                                        "tx_cnt": 373376,

                                                        "tx_byte": 399101587,

                                                        "drop_cnt": 0,

                                                        "drop_byte": 0

                                                },

                                                {

                                                        "rx_cnt": 373372,

                                                        "rx_byte": 399100266,

                                                        "tx_cnt": 115332,

                                                        "tx_byte": 20932591,

                                                        "drop_cnt": 21,

                                                        "drop_byte": 1260

                                                },

                                                {

                                                        "rx_cnt": 95146,

                                                        "rx_byte": 14426102,

                                                        "tx_cnt": 368883,

                                                        "tx_byte": 420901425,

                                                        "drop_cnt": 0,

                                                        "drop_byte": 0

                                                },

                                                {

                                                        "rx_cnt": 368914,

                                                        "rx_byte": 420907727,

"tx_cnt": 95169,

                                                        "tx_byte": 14426408,

                                                        "drop_cnt": 0,

                                                        "drop_byte": 0

                                                },

                                                {

                                                        "rx_cnt": 0,

                                                        "rx_byte": 0,

                                                        "tx_cnt": 0,

                                                        "tx_byte": 0,

                                                        "drop_cnt": 0,

                                                        "drop_byte": 0

                                                },

                                                {

                                                        "rx_cnt": 0,

                                                        "rx_byte": 0,

                                                        "tx_cnt": 0,

                                                        "tx_byte": 0,

                                                        "drop_cnt": 0,

                                                        "drop_byte": 0

                                                },

                                                {

                                                        "rx_cnt": 0,

                                                        "rx_byte": 0,

                                                        "tx_cnt": 0,

                                                        "tx_byte": 0,

                                                        "drop_cnt": 0,

                                                        "drop_byte": 0

                                                },

                                                {

                                                        "rx_cnt": 0,

                                                        "rx_byte": 0,

                                                        "tx_cnt": 0,

                                                        "tx_byte": 0,

                                                        "drop_cnt": 0,

                                                        "drop_byte": 0

}

                                        ]

                                },

                                "create_date": "2023-04-04 17:25:25"

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

3.7.  세션  로그  현황

세션  로그  현황을  조회한다.  주로  LCD에서  당일  발생한  세션  로그  개수와  3개월  간  발생한  세션

로그  개수를  표시하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/summary/sums

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘sesslog_cnt‘}



cmd : sesslog_cnt  명령  지정

◼  응답  메시지  포맷

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

정수

오늘  차단된  세션의  개수

3개월  동안  차단된  세션의  개수

status

code

today

total

(성공)

{

        "status": 1,

        "code": 1001,

        "today” : 123,

        “total” : 333

}

(실패)

{

        "status": 0,

        "code": 1004

}

4.  설정

4.1.  통신  인터페이스  설정

패킷  처리를  위한  인터페이스를  설정하거나  조회한다.  주로  장비  설정에서  통신  인터페이스를  설

정하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/setting/data_iface

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’ }



cmd :  통신  인터페이스  조회를  위해서는  list를  지정

◼  응답  메시지  포맷

항목

값

설명

status

code

ports

  num

info

index

status

speed

ports_stat

  num

info

  bs_cnt

ps_cnt

port_stat

  num

info

0  또는  1(상태  정의  참조)  성공  여부

코드  정의  참조

리턴  코드

정수

Info entry  개수

정수(0-3)

interface index

문자열(UP / DOWN)

interface  상태

문자열(1G / 10G / 40G)

interface  속도

정수

정수

정수

정수

Info entry  개수

차단  세션수

허용  세션수

Info entry  개수

rx  패킷  개수

rx  바이트  수

tx  패킷  개수

tx  바이트  수

drop  패킷  개수

drop  바이트  수

생성  시간

rx_cnt

rx_byte

tx_cnt

tx_byte

정수

정수

정수

정수

drop_cnt  정수

drop_byte  정수

create_dat

문자열

(성공)

{

        "status": 1,

        "code": 1001,

        "ports": {

                "num": 4,

                "info": [

                        {

                                "index": 0,

                                "status": "UP",

                                "speed": "10G"

                        },

                        {

                                "index": 1,

                                "status": "UP",

                                "speed": "10G"

                        },

                        {

                                "index": 2,

                                "status": "UP",

                                "speed": "10G"

                        },

                        {

                                "index": 3,

                                "status": "UP",

                                "speed": "10G"

                        }

                ]

        },

"ports_stat": {

                "num": 1000,

                "info": [

                        {

                                "bs_cnt": 0,

                                "ps_cnt": 0,

                                "port_stats": {

                                        "num": 8,

                                        "info": [

                                                {

                                                        "rx_cnt": 115320,

                                                        "rx_byte": 20931407,

                                                        "tx_cnt": 373376,

                                                        "tx_byte": 399101587,

                                                        "drop_cnt": 0,

                                                        "drop_byte": 0

                                                },

                                                {

                                                        "rx_cnt": 373372,

                                                        "rx_byte": 399100266,

                                                        "tx_cnt": 115332,

                                                        "tx_byte": 20932591,

                                                        "drop_cnt": 21,

                                                        "drop_byte": 1260

                                                },

                                                {

                                                        "rx_cnt": 95146,

                                                        "rx_byte": 14426102,

                                                        "tx_cnt": 368883,

                                                        "tx_byte": 420901425,

                                                        "drop_cnt": 0,

                                                        "drop_byte": 0

                                                },

                                                {

                                                        "rx_cnt": 368914,

                                                        "rx_byte": 420907727,

"tx_cnt": 95169,

                                                        "tx_byte": 14426408,

                                                        "drop_cnt": 0,

                                                        "drop_byte": 0

                                                },

                                                {

                                                        "rx_cnt": 0,

                                                        "rx_byte": 0,

                                                        "tx_cnt": 0,

                                                        "tx_byte": 0,

                                                        "drop_cnt": 0,

                                                        "drop_byte": 0

                                                },

                                                {

                                                        "rx_cnt": 0,

                                                        "rx_byte": 0,

                                                        "tx_cnt": 0,

                                                        "tx_byte": 0,

                                                        "drop_cnt": 0,

                                                        "drop_byte": 0

                                                },

                                                {

                                                        "rx_cnt": 0,

                                                        "rx_byte": 0,

                                                        "tx_cnt": 0,

                                                        "tx_byte": 0,

                                                        "drop_cnt": 0,

                                                        "drop_byte": 0

                                                },

                                                {

                                                        "rx_cnt": 0,

                                                        "rx_byte": 0,

                                                        "tx_cnt": 0,

                                                        "tx_byte": 0,

                                                        "drop_cnt": 0,

                                                        "drop_byte": 0

}

                                        ]

                                },

                                "create_date": "2023-04-04 17:25:25"

                        },

                        {

                        …

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

4.2.  관리  인터페이스  설정

시스템  관리를  위한  인터페이스를  설정하거나  조회한다.  주로  장비  설정에서  관리  인터페이스를

설정하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/setting/mgmt_iface

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’ }

{‘cmd’ : ‘mod’, ‘iface’:0, ‘ip’:’1.1.1’, ‘nm’:’255.255.255.0’, ‘gw’:’1.1.1.254’,

‘auto’:0, ‘speed’:1, ‘duplex’:1}



cmd :  관리  인터페이스  수정을  위해서는  mod를  지정.  조회를  위해서는  list를  지정

◼  응답  메시지  포맷(list)

항목

값

설명

status

code

ports

  num

info

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

Info entry  개수

interface index

IP  주소

netmask

gateway  주소

자동  설정  사용  여부

interface  속도

full / half duplex  여부

날짜

iface

0

ip

nm

gw

auto

speed

duplex

date

문자열

문자열

문자열

정수

정수

정수

문자열

(성공)

{

        "status": 1,

        "code": 1001,

        "ports": {

                "num": 2,

                "info": [

                        {

                                "iface": 0,

                                "ip": "192.168.1.100",

                                "nm": "255.255.255.0",

                                "gw": "192.168.1.100",

                                "auto": 0,

                                "speed": 0,

                                "dupex": 0,

                                "date": "2021-11-25 06:22:20"

                        },

                        {

                                "iface": 1,

                                "ip": "192.168.1.101",

                                "nm": "255.255.255.0",

                                "gw": "192.168.1.101",

                                "auto": 1,

                                "speed": 1,

                                "dupex": 1,

                                "date": "2021-11-25 06:23:10"

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

◼  응답  메시지  포맷(mod)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

status

code

(성공)

{

        "status": 1,

        "code": 1000

}

(실패)

{

        "status": 0,

        "code": 1004

}

4.3.  라우팅  정보  설정

시스템  관리를  위한  라우팅  정보를  설정하거나  조회한다.  주로  장비  설정에서  라우팅  정보를  설

정하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/setting/mgmt_route

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’ }

{‘cmd’

:

‘add’,

‘iface’:0,

‘nw’:’1.1.1.0’,

‘nm’:’255.255.255.0’,

‘gw’:’1.1.1.254’ }

{‘cmd’  :  ‘mod’,  ‘id’:1,  ‘iface’:0,  ‘onw’:’1.1.1.0’,  ‘onm’:’255.255.255.0’,

‘ogw’:’1.1.1.254’,

‘nnw’:’1.1.1.0’,

‘nnm’:’255.255.255.0’,

‘ogw’:’1.1.1.253’}

{‘cmd’

:

‘del’,

‘iface’:’MGT0’,

‘nw’:’1.1.1.0’,

‘nm’:’255.255.255.0’,

‘gw’:’1.1.1.254’ }

{‘cmd’ : ‘del’, ‘id’:[1,…]}



cmd :  라우팅  정보  추가,  수정,  삭제,  리스트를  위한  명령  지정

◼  응답  메시지  포맷(list)

항목

값

설명

status

code

routings

  num

info

id

iface

nw

nm

gw

date

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

정수

0

문자열

문자열

문자열

문자열

Info entry  개수

index

interface index

network  주소

netmask  정보

gateway  주소

날짜

◼  응답  메시지  포맷(add/mod/del)

항목

값

설명

status

0  또는  1(상태  정의  참조)

성공  여부

code

코드  정의  참조

리턴  코드

4.4. DNS  정보  설정

시스템  관리를  위한  DNS  정보를  설정하거나  조회한다.  주로  장비  설정에서  DNS  정보를  설정하

기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/setting/mgmt._dns

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’ }

{‘cmd’  :  ‘mod’,  ‘opdns’:’8.8.8.8’,  ‘osdns’:’0.0.0.0’,  ‘npdns’:’9.9.9.9’,

‘nsdns’:’8.8.8.8’}



cmd : DNS  정보  수정,  리스트를  위한  명령  지정

◼  응답  메시지  포맷(list)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

문자열

문자열

리턴  코드

primary DNS

secondary DNS

status

code

pdns

sdns

info

(성공)

{

        "status": 1,

        "code": 1001,

        “pdns”: “8.8.8.8”,

        “sdns”: “0.0.0.0”

}

(실패)

{

        "status": 0,

        "code": 1004

}

◼  응답  메시지  포맷(mod)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

status

code

(성공)

{

        "status": 1,

        "code": 1000

}

(실패)

{

        "status": 0,

        "code": 1004

}

4.5.  차단  국가  정보  설정

국가별  차단  정책  설정을  위한  국가  정보를  설정하거나  조회한다.  최대  5개  국가  설정이  가능하

다.

◼  요청  메시지  포맷

URL

Method

/1/apis/setting/block_country

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’ }

{'cmd': ‘mod’, 'bcn_use': 1, 'bcn_cnt': 3, 'info': ['CN', 'US', 'RU']}



cmd :  국가별  차단  정보  수정,  리스트를  위한  명령  지정

◼  응답  메시지  포맷(list)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

0  또는  1

정수(0~5)

리스트

리턴  코드

사용  여부

차단  국가  개수

차단  국가  리스트

status

code

bcn_use

bcn_cnt

info

(성공)

{

        "status": 1,

        "code": 1001,

“bcn_use”: 1,
”bcn_cnt”: 3,
“info”: ['CN', 'US', 'RU']

}

(실패)

{

        "status": 0,

        "code": 1004

}

◼  응답  메시지  포맷(mod)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

status

code

(성공)

{

        "status": 1,

        "code": 1000

}

(실패)

{

        "status": 0,

        "code": 1004

}

5.  서버  설정

5.1.  유해  IP  배포  서버  설정

서버  관리를  위한  유해  IP  배포  서버  정보를  설정하거나  조회한다.  주로  장비  설정에서  유해  IP

배포  서버  정보를  설정하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/server/mip_server

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’}

{‘cmd’

:

‘add’,

‘ip’:’192.168.1.10’,

‘port’:’443’,

‘proto’:’https’,

‘user’:’admin’,  ‘pass’:’qwe123’,  ‘url’:’  /services/poll-a’,  ‘dis_path’:

‘/services/discovery-a’, ‘col_name’:’ collection-a’, ‘use’:1}

{‘cmd’ : ‘mod’, ‘id’:1, ‘oip’:’192.168.1.10’, ‘oport’:’443’, ‘oproto’:’https’,

‘ouser’:’admin’, ‘opass’:’qwe123’,  ‘ourl’:’ /services/poll-a’,  ‘odis_path’:

‘/services/discovery-a’,

‘ocol_name’:’

collection-a’,

‘ouse’:1

‘nip’:’192.168.1.11’,

‘nport’:’443’,

‘nproto’:’https’,

‘nuser’:’admin’,

‘npass’:’qwe123’,

‘nurl’:’

/services/poll-a’,

‘ndis_path’:

‘/services/discovery-a’, ‘ncol_name’:’ collection-a’, ‘nuse’:1}

{‘cmd’

:

‘del’,

‘ip’:’192.168.1.10’,

‘port’:’443’,

‘proto’:’https’,

‘user’:’admin’, ‘pass’:’qwe123’, ‘url’:’mip.test.or.kr/url’, ‘use’:1}

{‘cmd’ : ‘del’, ‘id’:[1]}



cmd :  유해  IP  서버  정보  추가,  수정,  삭제,  리스트를  위한  명령  지정

◼  응답  메시지  포맷(list)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

status

code

servers

  num

info

id

ip

port

proto

user

pass

url

dis_path

정수

정수

문자열

문자열

문자열(http / https  등)

문자열

정수

문자열

문자열

col_name

문자열

use

date

정수(0 / 1)

문자열

(성공)

{

        "status": 1,

        "code": 1001,

Info entry  개수

index

server IP  주소

server port  값

프로토콜

사용자명

사용자  비밀번호  사용  여부

접속  URL

discovery path

collection name

사용  여부

날짜

        "servers": {

                "num": 9,

                "info": [

                        {

                                "id": 1,

                                "ip": "210.95.66.67",

                                "port": "22",

                                "proto": "https",

                                "user": "testUser1",

                                "pass": 0,

                                "url": "/services/poll-a",

                                “dis_path”: “/services/discovery-a”,

“col_name”: “collection-a”,

                                "use": 1,

                                "date": "1970-01-01 00:00:00"

                        },

                        {

                                "id": 2,

                                "ip": "210.95.66.67",

                                "port": "22",

                                "proto": "https",

                                "user": "testUser2",

                                "pass": 0,

"url": "/services/poll-a",

                                “dis_path”: “/services/discovery-a”,

“col_name”: “collection-a”,

                                "use": 1,

                                "date": "1970-01-01 00:00:00"

                        },

                        {

                                "id": 3,

                                "ip": "210.95.66.67",

                                "port": "22",

                                "proto": "https",

                                "user": "testUser3",

                                "pass": 0,

"url": "/services/poll-a",

                                “dis_path”: “/services/discovery-a”,

“col_name”: “collection-a”,

                                "use": 1,

                                "date": "1970-01-01 00:00:00"

                        },

                        {

                                "id": 4,

                                "ip": "210.95.66.67",

                                "port": "22",

                                "proto": "https",

                                "user": "testUser4",

                                "pass": 0,

"url": "/services/poll-a",

                                “dis_path”: “/services/discovery-a”,

“col_name”: “collection-a”,

                                "use": 1,

                                "date": "1970-01-01 00:00:00"

                        },

                        {

                                "id": 5,

                                "ip": "21::dbb:0:fe01:0",

                                "port": "22",

                                "proto": "http",

                                "user": "testUser7",

                                "pass": 0,

"url": "/services/poll-a",

                                “dis_path”: “/services/discovery-a”,

“col_name”: “collection-a”,

                                "use": 1,

                                "date": "2021-10-29 01:39:52"

                        },

                        {

                                "id": 6,

                                "ip": "21::dbb:0:fe01:0",

                                "port": "22",

                                "proto": "http",

                                "user": "test_6",

                                "pass": 0,

"url": "/services/poll-a",

                                “dis_path”: “/services/discovery-a”,

“col_name”: “collection-a”,

                                "use": 1,

                                "date": "2021-10-29 02:40:06"

                        },

                        {

                                "id": 7,

                                "ip": "1.2.3.4",

                                "port": "443",

                                "proto": "https",

                                "user": "",

                                "pass": 1,

"url": "/services/poll-a",

                                “dis_path”: “/services/discovery-a”,

“col_name”: “collection-a”,

                                "use": 1,

                                "date": "2021-11-24 08:37:14"

                        },

                        {

                                "id": 8,

                                "ip": "21::dbb:0:fe01:0",

                                "port": "22",

                                "proto": "http",

                                "user": "testUser7",

                                "pass": 0,

"url": "/services/poll-a",

                                “dis_path”: “/services/discovery-a”,

“col_name”: “collection-a”,

                                "use": 1,

                                "date": "2021-10-29 02:42:51"

                        },

                        {

                                "id": 12,

                                "ip": "0.0.0.1",

                                "port": "442",

                                "proto": "http",

                                "user": "",

                                "pass": 1,

"url": "/services/poll-a",

                                “dis_path”: “/services/discovery-a”,

“col_name”: “collection-a”,

                                "use": 1,

                                "date": "2021-11-15 18:13:20"

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

◼  응답  메시지  포맷(add/mod/del)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

status

code

(성공)

{

        "status": 1,

        "code": 1000

}

(실패)

{

        "status": 0,

        "code": 1004

}

5.2. Custom  유해  IP  배포  서버  설정

서버  관리를  위한  custom  유해  IP  배포  서버  정보를  설정한다.  주로  장비  설정에서  custom  유해

IP  배포  서버  정보를  설정하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/server/cmip_server

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’}

{‘cmd’ : ‘mod’, ‘otnd’:0, ‘octas’:0, ‘olog’:0, ‘ntnd’:1, ‘nctas’:1, ‘nlog’:1}



cmd : custom  유해  IP  정보  수정,  리스트를  위한  명령  지정

nlog  및  olog flag는  세션  로그를  남기지  여부를  지정하는  옵션임

◼  응답  메시지  포맷(list)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

정수

정수

TNDSoft  서버  사용  여부

c-tas  서버  사용  여부

세션  로그  생성  여부

status

code

tnd

ctas

log

(성공)

{

        "status": 1,

        "code": 1001,

        "tnd": 1,

        "ctas": 1,

        “log”: 0

}

(실패)

{

        "status": 0,

        "code": 1004

}

◼  응답  메시지  포맷(mod)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

status

code

(성공)

{

        "status": 1,

        "code": 1000

}

(실패)

{

        "status": 0,

        "code": 1004

}

5.3.  로그  서버  설정

서버  관리를  위한  로그  서버  정보를  설정하거나  조회한다.  주로  장비  설정에서  로그  서버  정보를

설정하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/server/log_server

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’}

{‘cmd’

:

‘add’,

‘ip’:’192.168.1.10’,

‘port’:’443’,

‘proto’:’https’,

‘user’:’admin’,  ‘pass’:’qwe123’,  ‘url’:’  /services/poll-a’,  ‘dis_path’:

‘/services/discovery-a’, ‘col_name’:’ collection-a’, ‘use’:1}

{‘cmd’ : ‘mod’, ‘id’:1, ‘oip’:’192.168.1.10’, ‘oport’:’443’, ‘oproto’:’https’,

‘ouser’:’admin’, ‘opass’:’qwe123’,  ‘ourl’:’ /services/poll-a’,  ‘odis_path’:

‘/services/discovery-a’,

‘ocol_name’:’

collection-a’,

‘ouse’:1

‘nip’:’192.168.1.11’,

‘nport’:’443’,

‘nproto’:’https’,

‘nuser’:’admin’,

‘npass’:’qwe123’,

‘nurl’:’

/services/poll-a’,

‘ndis_path’:

‘/services/discovery-a’, ‘ncol_name’:’ collection-a’, ‘nuse’:1}

{‘cmd’

:

‘del’,

‘ip’:’192.168.1.10’,

‘port’:’443’,

‘proto’:’https’,

‘user’:’admin’, ‘pass’:’qwe123’, ‘url’:’mip.test.or.kr/url’, ‘use’:1}

{‘cmd’ : ‘del’, ‘id’:[1,2]}



cmd :  로그  서버  IP  정보  추가,  수정,  삭제,  리스트를  위한  명령  지정

◼  응답  메시지  포맷(list)

항목

값

설명

status

code

servers

  num

info

id

ip

port

proto

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

정수

문자열

문자열

Info entry  개수

index

server IP  주소

server port  값

문자열(http / https  등)

프로토콜

user

pass

url

dis_path

문자열

정수

문자열

문자열

col_name

문자열

use

date

정수(0 / 1)

문자열

사용자명

사용자  비밀번호  사용  여부

접속  URL

discovery path

collection name

사용  여부

날짜

(성공)

{

        "status": 1,

        "code": 1001,

        "servers": {

                "num": 3,

                "info": [

                        {

                                "id": 1,

                                "ip": "210.95.66.67",

                                "port": "22",

                                "proto": "https",

                                "user": "testUser1",

                                "pass": 1,

"url": "/services/poll-a",

                                “dis_path”: “/services/discovery-a”,

“col_name”: “collection-a”,

                                "use": 1,

                                "date": "2021-10-25 05:48:20"

                        },

                        {

                                "id": 3,

                                "ip": "21::dbb:0:fe01:0",

                                "port": "22",

                                "proto": "https",

                                "user": "testUser1",

                                "pass": 1,

"url": "/services/poll-a",

                                “dis_path”: “/services/discovery-a”,

“col_name”: “collection-a”,

                                "use": 1,

                                "date": "2021-10-29 07:46:53"

                        },

                        {

                                "id": 4,

                                "ip": "21::dbb:0:fe01:0",

                                "port": "22",

                                "proto": "https",

                                "user": "testUser1",

                                "pass": 1,

"url": "/services/poll-a",

                                “dis_path”: “/services/discovery-a”,

“col_name”: “collection-a”,

                                "use": 1,

                                "date": "2021-11-01 02:09:59"

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

◼  응답  메시지  포맷(add/mod/del)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

status

code

(성공)

{

        "status": 1,

        "code": 1000

}

(실패)

{

        "status": 0,

        "code": 1004

}

5.4.  유해  IP  관리

서버  관리를  위한  유해  IP  내역을  조회하거나  사용자  설정을  추가한다.  주로  장비  설정에서  유해

IP  등록  내역을  확인하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/server/mip_info

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’}

{‘cmd’  :  ‘add’,  ‘ip’:’0.0.0.0’,  ‘port’:0’,  ‘proto’:’-’,  ‘url’:’-’,  ‘use’:1,

‘details’:{‘num’:10, ‘info’:[{‘ip’:’1.1.1.1.’, ‘org’:’KR’, ‘except’:1}, …}

{‘cmd’ : ‘mod’, ‘id’:1, ‘ouse’:1 ‘nuse’:0}

{‘cmd’ : ‘detail’, ‘id’:1}

{‘cmd’  :  ‘detailset’,  ‘id’:1,  ‘details’:{‘num’:10,  ‘info’:[{‘ip’:’1.1.1.1’,

‘org’:’KR’,  ‘except’:1,  ‘start_date’:’2023-04-01  12:00:00’,  ‘end_date’:

start_date’:’2023-04-02 12:00:00’}, …}

{‘cmd’ : ‘detailsearch’, ‘ip’:’1.1.1.1’}

{‘cmd’

:

‘search’,

‘ip’:’192.168.1.10’,

‘port’:’443’,

‘url’:’mip.test.or.kr/url’,  ‘sdate’:  1634692033,  ‘edate’:  1634692033,

‘mal_ip’: ‘1.1.1.1’}

{‘cmd’ : ‘new’, ‘id’:1}

{‘cmd’ : ‘detailsearchset’, ‘ip’:’1.1.1.1’}

{‘cmd’ : ‘detailinfo’, ‘ip’:’1.1.1.1’}

{‘cmd’  :  ‘detailadd’,  ‘id’:1,  ‘details’:{‘num’:10,  ‘info’:[{‘ip’:’1.1.1.1’,

‘org’:’KR’, ‘except’:1}, …}

{‘cmd’  :  ‘detailmod’,  ’id’:1,  ‘oip’:’1.1.1.1’,  ‘oorg’:’KR’,  ‘nip’:’1.1.1.2’,

‘norg’:’KR’}

{‘cmd’ : ‘detaildel’, ‘id’:1, ‘ip’:[‘1.1.1.1’, ‘1.1.1.2’]}



cmd  :  유해  IP  관리  내역에  대한  추가,  수정,  삭제,  리스트,  상세정보를  위한  명령  지

정

→ detailsearch  명령은  인자로  주어진  IP가  포함된  유해  IP  관리  리스트  조회

→ new  명령은  인자로  주어진  id  리스트에서  중복  제거된  유해  IP  정보  조회

→  detailsearchset  명령은  인자로  주어진  IP가  포함된  유해  IP  관리  리스트에서  해당

IP  예외  처리

→  detailset  명령  중  start_date  및  end_date  설정은  관리자가  수동으로  등록한  IP에

만  적용해야  함.  나머지  배포서버에서  자동으로  받은  IP에  대해서는  비어있는  값을

설정해야  함.

→  detailset  명령  중  start_date  및  end_date는  시간  단위로  설정해야  함.  즉  분과  초

는  항상  00으로  설정되어야  함

→ detailinfo  명령은  유해  IP에  대한  상세  정보를  요청하는  명령임



search를  사용할  경우  4가지  필드  중  하나  이상을  지정해야  함.  검색  조건이  아닌  경

우  ‘’로  지정(ex. {‘cmd’ : ‘search’, ‘ip’:’192.168.1.10’, ‘port’:’443’, ‘url’:’’, ‘sdate’:0, ‘edate’:0’}





→  이  경우  서버  IP가  192.168.1.10이면서  port가  443인  모든  정보  검색)

search에서  검색  날짜는  utc time  값을  사용하고  시작  시간과  끝  시간을  지정

add의  경우  파일을  읽어  json  형식의  details  정보를  만들어서  전송.  파일  형식은  하

나의  라인에  ip,.  org  형식임.  한  라인씩  읽어  json  형식으로  만들어  전송함.  use는  항

상  1로  지정하고, except는  항상  0으로  지정.

  detailadd / detailmod / detaildel  명령은  관리자가  수동으로  등록한  IP  관리  리스트에

서만  가능함

  detailadd / detailmod / detaildel에서  추가,  변경,  삭제하고자  하는  IP는  현  id  이외의

id에  존재하지  않아야  함

◼  응답  메시지  포맷(list/search/detailsearch)

항목

값

설명

status

code

mips

  num

info

id

ip

port

proto

url

use

date

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

정수

문자열

문자열

문자열(http / https  등)

문자열

정수(0 / 1)

문자열

Info entry  개수

index

server IP  주소

server port  값

프로토콜

접속  URL

사용  여부

날짜

(성공)

{

        "status": 1,

        "code": 1001,

        "mips": {

                "num": 14,

                "info": [

                        {

                                "id": 1,

                                "ip": "210.95.66.67",

                                "port": "22",

                                "url": "https://testUrl1.com",

                                "use": 1,

                                "date": "2021-10-25 05:48:20"

                        },

                        {

                                "id": 2,

                                "ip": "210.95.66.1",

                                "port": "22",

                                "url": "https://testUrl2.com",

                                "use": 1,

                                "date": "2021-11-01 06:54:15"

                        },

                        {

                                "id": 15,

                                "ip": "100.100.100.100",

                                "port": "8888",

                                "url": "/test01/test02/test",

                                "use": 1,

                                "date": "2021-12-02 01:44:27"

                        },

                        {

                                "id": 16,

                                "ip": "192.168.100.5",

                                "port": "9000",

                                "url": "/services/poll-a",

                                "use": 1,

                                "date": "2021-12-02 06:13:17"

                        },

                        {

                                "id": 23,

                                "ip": "192.168.100.5",

                                "port": "9000",

                                "url": "/services/poll-a",

                                "use": 1,

                                "date": "2021-12-02 06:24:05"

                        },

                        {

                                "id": 26,

                                "ip": "192.168.100.100",

                                "port": "8088",

                                "url": "wsis_Intellligency/malicious/ip/filehash",

                                "use": 1,

                                "date": "2021-12-02 06:33:10"

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

◼  응답  메시지  포맷(add/mod/del/detailset/detailsearchset/detailadd/detailmod/detaildel)

항목

값

설명

status

code

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

◼  응답  메시지  포맷(detail)

항목

값

설명

status

code

details

id

num

info

ip

org

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

정수

문자열

문자열

index

Info entry  개수

server IP  주소

server port  값

except

정수(0 / 1 / 2 / …)

예외  여부



except  필드는  0  이상의  정수값을  가지며  0이  아니면  예외  처리된  것으로  간주

(성공)

{

        "status": 1,

        "code": 1001,

        "details": {

                "id": 15,

                "num": 2,

                "info": [

                        {

                                "ip": "1.1.1.1",

                                "org": "CN",

                                "except": 1

                        },

                        {

                                "ip": "1.1.1.2",

                                "org": "US",

                                "except": 1

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

◼  응답  메시지  포맷(new)

항목

값

설명

status

code

details

id

num

info

ip

org

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

정수

문자열

문자열

index

Info entry  개수

server IP  주소

server port  값

except

정수(0 / 1 / 2 / …)

예외  여부

start_date

문자열

날짜

end_date

문자열

날짜



except  필드는  0  이상의  정수값을  가지며  0이  아니면  예외  처리된  것으로  간주

(성공)

{

        "status": 1,

        "code": 1001,

        "details": {

                "id": 15,

                "num": 2,

                "info": [

                        {

                                "ip": "1.1.1.1",

                                "org": "CN",

                                "except": 1,

                                “start_date”: “2023-04-01 13:00:00”,

                                “end_date”: “”

                        },

                        {

                                "ip": "1.1.1.2",

                                "org": "US",

                                "except": 1,

“start_date”: “2023-04-01 13:00:00”,

                                “end_date”: “2023-04-30 23:00:00”

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

◼  응답  메시지  포맷(detailinfo)

항목

값

설명

status

0  또는  1(상태  정의

성공  여부

참조)

코드  정의  참조

리턴  코드

code

info

ipaddr

scores

  score_ain

score_aout

score_b

basic

  basic_a

cn_code

as_name

org_name

city

confirm_date

basic_b

cn_code

domain

public

whitelist

isp

type

last_report

  detect

ids

count

data

classification

url

message

source_system

문자열

정수

정수

정수

정수

문자열

문자열

문자열

문자열

문자열

문자열

문자열

BOOL

BOOL

문자열

문자열

문자열

문자열

정수

문자열

문자열

문자열

문자열

조회할  IP  주소

Info entry  개수

A  서버  inbound  위험도(0~5)

A  서버  outbound  위험도(0~5)

B  서버  위험도(0~5)

국가코드

IP  사용  ISP  이름

IP  사용  기관  이름

도시명

날짜

국가코드

domain  이름

public IP  여부

whitelist IP  여부

IP  사용  ISP  이름

IP  유형

날짜

server IP  주소

데이터  개수

분류명

URL

메시지

탐지  출처

날짜

confirmed_time

문자열

category

count

data

정수

데이터  개수

  detect_source

type

문자열

문자열

confirmed_time

문자열

탐지  출처

타입

날짜

reports

  count

data

reportedAt

comment

categories

reporterId

정수

데이터  개수

문자열

문자열

날짜

설명

정수  LIST

카테고리  리스트

정수

보고자정보

국가코드

국가명

reporterCountryCode  문자열

reporterCountryName  문자열

(성공)

{

“status”: 1,

“code”: 1001,

“info”: {

        "ipaddr": "45.93.16.15",

        "scores": {

                "score_ain": 5,

                "score_aout": 3,

                "score_b": 5

        },

        "basic": {

                "basic_a": {

                        "cn_code": "de",

                        "as_name": "RELIABLESITE",

                        "org_name": "Dedires LLC",

                        "city": "",

                        "confirm_date": "2023-04-03 00:00:00"

                },

                "basic_b": {

                        "cn_code": "US",

                        "cn_name": "United States of America",

                        "domain": "ipv4superhub.com",

                        "public": true,

                        "whitelist": false,

                        "isp": "IPv4 Superhub Limited",

                        "type": "Data Center/Web Hosting/Transit",

                        "last_report": "2023-04-03T08:05:04+00:00"

                }

        },

        "detect": {

                "ids": {

                        "count": 2,

                        "data": [

                                {

                                        "classification": "3coresec",

                                        "url": "blacklist.3coresec.net/lists/et-open.txt",

                                        "message": "ET 3CORESec Poor Reputation IP UDP group 25",

                                        "source_system": "./snort-2.9.0 10282",

                                        "confirmed_time": "2023-04-03 02:13:04"

},

                                {

                                        "classification": "ciarmy",

                                        "url": "www.cinsscore.com",

                                        "message": "ET CINS Active Threat Intelligence Poor Reputation IP

UDP group 45",

                                        "source_system": "./snort-2.9.0 10282",

                                        "confirmed_time": "2023-04-03 07:31:46"

                                }

                        ]

                },

                "category": {

                        "count": 2,

                        "data": [

                                {

                                        "detect_source": "",

                                        "type": "bruteforce (fail2ban)",

                                        "confirmed_time": "2023-04-02 16:20:12"

                                },

                                {

                                        "detect_source": "",

                                        "type": "ddos (apache_report)",

                                        "confirmed_time": "2023-04-02 15:05:36"

                                }

                        ]

                }

        },

        "reports": {

                "count": 10,

                "data": [

                        {

                                "reportedAt": "2023-04-03T08:05:04+00:00",

                                "comment": "Firewall IPS Detection on 03-04-2023 at 10:05:04",

                                "categories": [

                                        14,

                                        20

],

                                "reporterId": 107900,

                                "reporterCountryCode": "AD",

                                "reporterCountryName": "Andorra"

                        },

                        {

                                "reportedAt": "2023-04-03T08:03:13+00:00",

                                "comment": "tcp ports: 5038,80 (136 or more attempts)",

                                "categories": [

                                        14

                                ],

                                "reporterId": 86513,

                                "reporterCountryCode": "US",

                                "reporterCountryName": "United States of America"

                        },

                        {

                                "reportedAt": "2023-04-03T07:38:09+00:00",

                                "comment": "Portscan on 80/TCP blocked by UFW",

                                "categories": [

                                        14

                                ],

                                "reporterId": 71060,

                                "reporterCountryCode": "DE",

                                "reporterCountryName": "Germany"

                        },

                        {

                                "reportedAt": "2023-04-03T07:17:07+00:00",

                                "comment": "Firewall IPS Detection on 03-04-2023 at 09:17:06",

                                "categories": [

                                        14,

                                        20

                                ],

                                "reporterId": 107900,

                                "reporterCountryCode": "AD",

                                "reporterCountryName": "Andorra"

                        },

                        {

                                "reportedAt": "2023-04-03T07:03:08+00:00",

                                "comment": "tcp ports: 5038,80 (198 or more attempts)",

                                "categories": [

                                        14

                                ],

                                "reporterId": 86513,

                                "reporterCountryCode": "US",

                                "reporterCountryName": "United States of America"

                        },

                        {

                                "reportedAt": "2023-04-03T06:11:28+00:00",

                                "comment": "03.04.2023 06:08:02 HTTP access blocked by firewall",

                                "categories": [

                                        14,

                                        21

                                ],

                                "reporterId": 81259,

                                "reporterCountryCode": "DE",

                                "reporterCountryName": "Germany"

                        },

                        {

                                "reportedAt": "2023-04-03T06:06:42+00:00",

                                "comment": "45.93.16.15 was recorded 23 times by 15 hosts attempting

to connect to 1 unique ports. Incident counter (4h, 24h, all-time): 23, 138, 2410",

                                "categories": [

                                        14

                                ],

                                "reporterId": 35293,

                                "reporterCountryCode": "US",

                                "reporterCountryName": "United States of America"

                        },

                        {

                                "reportedAt": "2023-04-03T06:03:12+00:00",

                                "comment": "tcp ports: 5038,80 (185 or more attempts)",

"categories": [

                                        14

                                ],

                                "reporterId": 86513,

                                "reporterCountryCode": "US",

                                "reporterCountryName": "United States of America"

                        },

                        {

                                "reportedAt": "2023-04-03T05:56:04+00:00",

                                "comment": "Firewall IPS Detection on 03-04-2023 at 07:56:04",

                                "categories": [

                                        14,

                                        20

                                ],

                                "reporterId": 107900,

                                "reporterCountryCode": "AD",

                                "reporterCountryName": "Andorra"

                        },

                        {

                                "reportedAt": "2023-04-03T05:44:48+00:00",

                                "comment":  "Port  Scan  2023-04-03T03:29:54.265Z  ->  45.93.16.15

scanned port 5038 on one of our servers",

                                "categories": [

                                        15

                                ],

                                "reporterId": 91757,

                                "reporterCountryCode": "ES",

                                "reporterCountryName": "Spain"

                        }

                ]

        }

    }

}

(실패)

{

        "status": 0,

        "code": 1004

}

5.5.  화이트리스트  IP  관리

서버  관리를  위한  화이트리스트  IP  내역을  조회하거나  추가한다.  주로  장비  설정에서  화이트리스

트  IP  등록  내역을  확인하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/server/whiteip_info

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’}

{‘cmd’ : ‘add’, ‘ip’:’1.1.1.1’, ‘reason’:’test’, ‘use’:1 }

{‘cmd’

:

‘mod’,

‘id’:1,

‘oip’:’1.1.1.1’,

‘oreason’:’test’,

‘ouse’:1,

‘nip’:’1.1.1.1’, ‘nreason’:’test’, ‘nuse’:0}

{‘cmd’ : ‘del’, ‘id’:[1]}

{‘cmd’

:

‘search’,

‘ip’:’1.1.1.1’,

‘sdate’:  1634692033,

‘edate’:

1634692033}



cmd :  화이트리스트  IP  관리  내역에  대한  추가,  수정,  삭제,  리스트를  위한  명령  지정

◼  응답  메시지  포맷(list/search)

항목

값

설명

status

code

whiteips

  num

info

id

ip

reason

use

flag

date

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

정수

문자열

문자열

정수

정수

문자열

Info entry  개수

index

server IP  주소

사유

사용여부

local / exceptip / manager  구분

날짜



flag : 0이면  local whitetip / 1이면  exceptip(예외처리  IP) / 2이면  manger whitetip  임

(성공)

{

        "status": 1,

        "code": 1001,

        "whiteips": {

                "num": 3,

                "info": [

                        {

                                "id": 1,

                                "ip": "210.95.66.67",

                                "reason": "\ud14c\uc2a4\ud2b8",

                                "use": 1,

                                “flag”: 0,

                                "date": "2021-10-25 05:48:20"

                        },

                        {

                                "id": 2,

                                "ip": "210.95.66.1",

                                "reason": "\uc9c4\uc9dc\uc878\ub824",

                                "use": 1,

“flag”: 1,

                                "date": "2021-11-04 07:22:45"

                        },

                        {

                                "id": 4,

                                "ip": "100.100.100.100",

                                "reason": "test100",

                                "use": 1,

“flag”: 0,

                                "date": "2021-11-26 06:36:12"

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

◼  응답  메시지  포맷(add/mod/del)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

status

code

(성공)

{

        "status": 1,

        "code": 1001

}

(실패)

{

        "status": 0,

        "code": 1004

}

6.  로그

6.1.  세션  로그

세션  로그를  조회한다.  주로  로그에서  세션  로그를  확인하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/log/sesslog

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’}

{‘cmd’  :  ‘search’,  ‘itype’:1,  ‘ip’:’1.1.1.10’,  ‘ptype’:  0,  ‘port’:’8080’,

‘proto’:’tcp’, ‘block’:[0,1], ‘sdate’: 1634692033, ‘edate’: 1634692033}





cmd :  세션  로그에  대한  리스트를  위한  명령  지정

search에서  itype/ptype에서  0은  출발지, 1은  목적지임.  또한  block에서  0은  허용, 1은

차단, 2는  종료  세션을  의미함

◼  응답  메시지  포맷(list/search)

항목

값

설명

status

code

logs

  num

info

  sip

sport

dip

dport

proto

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

문자열

문자열

문자열

문자열

문자열

Info entry  개수

출발지  IP  주소

출발지  port

목적지  IP  주소

목적지  port

프로토콜

block

date

리스트(0/1/2/)

문자열

차단여부

날짜

(성공)

{

        "status": 1,

        "code": 1001,

        "logs": {

                "num": 20,

                "info": [

                        {

                                "sip": "210.95.66.67",

                                "sport": "22",

                                "dip": "2.200.168.192",

                                "dport": "246",

                                "proto": "udp",

                                "block": 1,

                                "date": "2021-10-20 01:07:13"

                        },,

                        {

                                "sip": "2001:db8::1428:57ac",

                                "sport": "22",

                                "dip": "199.168.200.8",

                                "dport": "246",

                                "proto": "udp",

                                "block": 1,

                                "date": "2021-10-20 01:07:13"

                        },

                        {

                                "sip": "2001:db8::1428:57ac",

                                "sport": "22",

                                "dip": "9.200.168.199",

                                "dport": "246",

                                "proto": "udp",

                                "block": 1,

                                "date": "2021-10-20 01:07:13"

                        },

                        {

                                "sip": "2001:db8::1428:57ac",

                                "sport": "22",

                                "dip": "11.200.168.201",

                                "dport": "246",

                                "proto": "udp",

                                "block": 1,

                                "date": "2021-10-20 01:07:13"

                        },

                        {

                                "sip": "2001:db8::1428:57ac",

                                "sport": "22",

                                "dip": "202.168.200.11",

                                "dport": "246",

                                "proto": "udp",

                                "block": 1,

                                "date": "2021-10-20 01:07:13"

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

6.2.  정책  로그

정책  로그를  조회한다.  주로  로그에서  정책  로그를  확인하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/log/pollog

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’}

{‘cmd’

:

‘search’,

‘action’:’apply’,

‘object’:’mip_info’,

‘sdate’:

1634692033, ‘edate’: 1634692033, ‘userId’: ‘admin’}



cmd :  정책  로그에  대한  리스트를  위한  명령  지정

◼  응답  메시지  포맷(list/search)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

문자열

문자열

문자열

문자열

문자열

Info entry  개수

로그  발생  모듈

정책  적용  객체

상세  이력

행위

날짜

status

code

logs

  num

info

  module

object

detail

action

date

(성공)

{

        "status": 1,

        "code": 1001,

        "logs": {

                "num": 1,

                "info": [

                        {

                                "module": "gui",

                                "object": "mip_info",

                                "detail": "\ucc28\ub2e8\uc815\ucc45\ucd94\uac00",

                                "action": "detail",

                                "date": "2021-10-20 01:07:13",

                                “userId”: “admin”

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

6.3.  시스템  로그

시스템  로그를  조회한다.  주로  로그에서  시스템  로그를  확인하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/log/syslog

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’}

{‘cmd’ : ‘search’, ‘action’:’success’, ‘object’:’login’, ‘sdate’: 1634692033,

‘edate’: 1634692033, ‘userId’: ‘admin’}



cmd :  시스템  로그에  대한  리스트를  위한  명령  지정

◼  응답  메시지  포맷(list/search)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

문자열

문자열

문자열

문자열

문자열

문자열

Info entry  개수

로그  발생  모듈

정책  적용  객체

상세  이력

행위

날짜

사용자id

status

code

logs

  num

info

  module

object

detail

action

date

userId

(성공)

{

        "status": 1,

        "code": 1001,

        "logs": {

                "num": 13,

                "info": [

                        {

                                "module": "backup",

                                "object": "sys",

                                "detail": "\ubcf5\uad6c\uc2dc\uc791",

                                "action": "fail",

                                "date": "2021-11-30 05:20:44",

                                “userId”: “admin

                        },

                        {

                                "module": "system",

                                "object": "other",

                                "detail": "\ud14c\uc2a4\ud2b8",

                                "action": "start",

                                "date": "2021-10-20 01:07:13",

“userId”: “admin

                        },

                        {

                                "module": "system",

                                "object": "other",

                                "detail": "\ud14c\uc2a4\ud2b82",

                                "action": "start",

                                "date": "2021-11-23 06:19:05",

“userId”: “admin

                        },

                        {

                                "module": "backup",

                                "object": "sys",

                                "detail": "\ubc31\uc5c5\uc2dc\uc791",

                                "action": "finish",

                                "date": "2021-11-29 08:26:21",

“userId”: “admin

                        },

                        …

{

                                "module": "system",

                                "object": "sys",

                                "detail": "\ubcf5\uad6c\uc885\ub8cc",

                                "action": "other",

                                "date": "2021-11-30 05:20:44",

“userId”: “admin

                        },

                        {

                                "module": "other",

                                "object": "sys",

                                "detail": "\ubcf5\uad6c\uc644\ub8cc",

                                "action": "other",

                                "date": "2021-11-30 05:20:44",

“userId”: “admin

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

6.4.  세션  통계

세션  통계를  조회한다.  주로  로그에서  세션  통계를  확인하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/log/sessstat

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’}

{‘cmd’ : ‘search’, ‘date’: 1634692033}



cmd :  세션  통계에  대한  리스트를  위한  명령  지정

◼  응답  메시지  포맷(list/search)

항목

값

설명

status

code

daily

  num

info

  date

count

weelky

  num

info

  date

count

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

문자열

정수

정수

문자열

정수

Info entry  개수

날짜

해당  날짜  차단  수

Info entry  개수

날짜

해당  주  차단  수

monthly

  num

info

  date

count

정수

문자열

정수

6.5.  포트  통계

Info entry  개수

날짜

해당  월  차단  수

포트  통계를  조회한다.  10분  주기로  저장된  포트  통계(차단세션  수,  허용세션  수,  포트별  트래픽

정보  등)를  조회할  수  있다.

◼  요청  메시지  포맷

URL

Method

/1/apis/log/portstat

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’}

{‘cmd’ : ‘search’, ‘sdate’: 1534692033, ‘edate”: 1634692033}



cmd :  포트  통계에  대한  리스트를  위한  명령  지정

◼  응답  메시지  포맷(list/search)

항목

값

설명

0  또는  1(상태  정의  참조)  성공  여부

코드  정의  참조

리턴  코드

status

code

logs

  num

info

  bs_cnt

ps_cnt

port_stat

  num

info

rx_cnt

rx_byte

tx_cnt

tx_byte

정수

정수

정수

정수

정수

정수

정수

정수

drop_cnt  정수

drop_byte  정수

create_dat

문자열

Info entry  개수

차단  세션수

허용  세션수

Info entry  개수

rx  패킷  개수

rx  바이트  수

tx  패킷  개수

tx  바이트  수

drop  패킷  개수

drop  바이트  수

생성  시간

7.  기타

7.1.  업데이트

패키지  업데이트  및  이력을  조회한다.  주로  로그에서  업데이트  이력을  확인하거나  업데이트를  수

행하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/update

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘update’, ‘filename’:filename, …, multipart-contents }

{‘cmd’ : ‘list’}

{‘cmd’

:

‘search’,

‘action’:’success’,

‘module’:’update’,

‘sdate’:

1634692033, ‘edate’: 1634692033}



cmd :  업데이트  및  이력에  대한  명령  지정

◼  응답  메시지  포맷(list/search)

항목

값

설명

status

code

logs

  num

info

  module

detail

action

date

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

문자열

문자열

문자열

문자열

Info entry  개수

로그  발생  모듈

상세  이력

행위

날짜

7.2.  백업  및  복구

백업  및  이력을  조회한다.  주로  로그에서  백업  이력을  확인하거나  백업/복구를  수행하기  위해  사

용된다.  또한  서버에  존재하는  백업  파일을  이용하여  복구를  실행한다.

◼  요청  메시지  포맷

URL

Method

/1/apis/backup

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘backup’, “policy’:1, ‘sesslog’:1, ‘otlog’:1, ‘stat’:1, ‘mip’:1}

{‘cmd’  :  ‘restore’,  ‘policy’:1,  ‘sesslog’:0,  ‘otlog’:0,  ‘stat’:0,  ‘mip’:0,

‘filename’:file}

{‘cmd’ : ‘list’}

{‘cmd’

:

‘search’,

‘action’:’success’,

‘module’:’sesslog’,

‘sdate’:

1634692033, ‘edate’: 1634692033}





cmd :  백업  및  이력에  대한  명령  지정

restore  명령은  서버에  존재하는  백업  파일  경로를  지정함

◼  응답  메시지  포맷

항목

값

설명

status

code

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

filename

문자열

백업  파일  경로

◼  응답  메시지  포맷(list/search)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

status

code

logs

  num

info

  module

detail

action

path

정수

문자열

문자열

문자열

문자열

restore

정수(0/1)

date

문자열

7.3.  복구

Info entry  개수

로그  발생  모듈

상세  이력

행위

백업/복구  경로

restore  버튼  출력  여부

날짜

복구  및  이력을  조회한다.  주로  로그에서  복구  이력을  확인하거나  복구를  수행하기  위해  사용된

다.

◼  요청  메시지  포맷

URL

Method

/1/apis/restore

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’  :  ‘restore’,  “policy’:1,  ‘sesslog’:0,  ‘otlog’:0,  ‘stat’:0,  ‘mip’:0,

‘filename’:filename, …, multipart-contents }

{‘cmd’ : ‘list’}

{‘cmd’

:

‘search’,

‘action’:’success’,

‘module’:’sesslog’,

‘sdate’:

1634692033, ‘edate’: 1634692033}



cmd :  복구  및  이력에  대한  명령  지정

  이  항목에서  restore  기능은  로컬로  백업된  파일을  첨부하여  복구할  때  사용하는  기

능임

◼  응답  메시지  포맷

항목

값

설명

status

code

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

◼  응답  메시지  포맷(list/search)

항목

값

설명

status

code

logs

  num

info

  module

detail

action

path

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

문자열

문자열

문자열

문자열

Info entry  개수

로그  발생  모듈

상세  이력

행위

백업/복구  경로

restore

정수(0/1)

date

문자열

restore  버튼  출력  여부

날짜

7.4.  정책  적용

수정된  정책을  적용한다.

◼  요청  메시지  포맷

URL

Method

/1/apis/apply

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘apply’}



cmd :  정책  적용  명령  지정

◼  응답  메시지  포맷

항목

값

설명

status

code

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

7.5.  라이선스  등록

라이선스를  적용한다.

◼  요청  메시지  포맷

URL

Method

/1/apis/license

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘reg’, ‘license’:lic}



cmd :  라이선스  등록  명령  지정

◼  응답  메시지  포맷

항목

값

설명

status

code

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

7.6.  라이선스  검사

라이선스를  검사한다.

◼  요청  메시지  포맷

URL

Method

/1/apis/license

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘check’ }



cmd :  라이선스  체크  명령  지정

◼  응답  메시지  포맷

항목

값

설명

status

code

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

7.7. About

About  정보를  출력한다.

◼  요청  메시지  포맷

URL

Method

/1/apis/about

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘about’}



cmd : about  명령  지정

◼  응답  메시지  포맷

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

문자열

문자열

문자열

문자열

문자열

문자열

문자열

리턴  코드

제품명

제품버전

라이선스  등록  여부

라이선스  유효  기간

제조사

manual  다운로드  링크

회사  홈페이지  링크

status

code

product

version

license

period

company

manual

homepage

8. Manager  관련

8.1.  유해  IP  관리

Manager에서  유해  IP를  등록하거나  유해  IP  내역을  조회하거나  사용자  설정을  추가한다.

Manager에서  적용한  유해IP  등록  내역을  확인하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/manager/mip_info

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’}

{‘cmd’  :  ‘add’,  ‘category’:1,  ’seq’:1,  ‘use’:1,  ‘details’:{‘num’:10,

‘info’:[{‘ip’:’1.1.1.1’, ‘org’:’KR’, ‘except’:1}, …}

{‘cmd’ : ‘mod’, ‘category’:1, ’seq’:1, ‘ouse’:1 ‘nuse’:0}

{‘cmd’

:

‘detailset’,

‘category’:1,

’seq’:1,

‘details’:{‘num’:10,

‘info’:[{‘ip’:’1.1.1.1’,

‘org’:’KR’,

‘except’:1,

‘start_date’:’2023-04-01

12:00:00’, ‘end_date’: ’2023-04-05 12:00:00’}, …}

{‘cmd’ : ‘detailsearch’, ‘ip’:’1.1.1.1”}

{‘cmd’

:

‘detailadd’,

‘category’:1,

’seq’:1,

‘details’:{‘num’:10,

‘info’:[{‘ip’:’1.1.1.1’, ‘org’:’KR’, ‘except’:1}, …}

{‘cmd’  :  ‘detailmod’,  ‘category’:1,  ’seq’:1,  ‘oip’:’1.1.1.1’,  ‘oorg’:’KR’,

‘nip’:’1.1.1.2’, ‘norg’:’KR’}

{‘cmd’ : ‘detaildel’, ‘category’:1, ’seq’:1, ‘ip’:[‘1.1.1.1’, ‘1.1.1.2’]}



cmd :  유해  IP  관리  내역에  대한  추가,  수정,  리스트,  상세정보를  위한  명령  지정

→ detailsearch  명령은  인자로  주어진  IP가  포함된  유해  IP  관리  리스트  조회

→  detailset  명령  중  start_date  및  end_date  설정은  관리자가  수동으로  등록한  IP에

만  적용해야  함.  나머지  배포서버에서  자동으로  받은  IP에  대해서는  비어있는  값을

설정해야  함.

→  detailset  명령  중  start_date  및  end_date는  시간  단위로  설정해야  함.  즉  분과  초

는  항상  00으로  설정되어야  함





search에서  검색  날짜는  utc time  값을  사용하고  시작  시간과  끝  시간을  지정

add의  경우  파일을  읽어  json  형식의  details  정보를  만들어서  전송  또는  직접  입력

하는  방식을  택할  수  있음.  ip,  org  형식임.  한  라인씩  읽어  json  형식으로  만들어  전

송함. use는  항상  1로  지정하고, except는  항상  0으로  지정.

  detailadd  /  detailmod  /  detaildel  명령은  관리자가  수동으로  등록한  category만  가능

함

  detailadd  /  detailmod  /  detaildel에서  추가,  변경,  삭제하고자  하는  IP는  현  cate  및

seq  이외의  cate  및  seq에  존재하지  않아야  함

◼  응답  메시지  포맷(list)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

정수

정수

정수

정수(0 / 1)

문자열

Info entry  개수

index

유해  IP  배포  정보

category별  고유  id

사용  여부

날짜

status

code

mips

  num

info

id

category

seq

use

date

(성공)

{

        "status": 1,

        "code": 1001,

        "mips": {

                "num": 14,

                "info": [

                        {

                                ‘id’: 1,

"category”: 1,

                                "seq": 1,

"use": 1,

                                "date": "2021-10-25 05:48:20"

                        },

                        {

‘id’: 2

"category”: 1,

                                "seq": 2,

                                "use": 1,

                                "date": "2021-11-01 06:54:15"

                        },

                        {

‘id’: 3

"category”: 1,

                                "seq": 3,

                                "use": 4

                                "date": "2021-12-02 01:44:27"

                        },

                        {

‘id’: 1,

"category”: 1,

                                "seq": 4,

                                "use": 1,

                                "date": "2021-12-02 06:13:17"

                        },

                        {

‘id’: 1,

"category”: 1,

                                "seq": 5,

                                "use": 1,

                                "date": "2021-12-02 06:24:05"

                        },

                        {

‘id’: 1,

"category”: 1,

                                "seq": 6,

                                "use": 1,

                                "date": "2021-12-02 06:33:10"

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

◼  응답  메시지  포맷(detailsearch)

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

문자열

문자열

정수

문자열

문자열

정수

정수

정수

정수(0 / 1)

문자열

Info entry  개수

검색한  IP  주소

2자리  국가코드

예외  처리  여부

유해  IP  적용  시작시간

유해  IP  적용  종료시간

index

유해  IP  배포  정보

category별  고유  id

사용  여부

날짜

status

code

mips

  num

ip

code

except

start_date

end_date

info

id

category

seq

use

date

(성공)

{

        "status": 1,

        "code": 1001,

        "mips": {

                "num": 2,

                "ip": "1.1.1.1",

                "code": "CN",

                "except": 2,

                "start_date": "2023-04-10 12:00:00",

                "end_date": "",

                "info": [

                        {

                                ‘id’: 1,

"category”: 1,

                                "seq": 1,

"use": 1,

                                "date": "2021-10-25 05:48:20"

                        },

                        {

‘id’: 2

"category”: 1,

                                "seq": 2,

                                "use": 1,

                                "date": "2021-11-01 06:54:15"

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

◼  응답  메시지  포맷(add/mod/detailset/detailadd/detailmod/detaildel)

항목

값

설명

status

code

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

8.2.  화이트리스트  IP  관리

Manager에서  설정하고자  하는  화이트리스트  IP  내역을  조회하거나  추가한다.  Manager에서  화이

트리스트  IP  등록  내역을  확인하기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/manager/whiteip_info

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’}

{‘cmd’ : ‘add’, ‘category’:1,’seq’:1’,‘ip’:’1.1.1.1’, ‘reason’:’test’, ‘use’:1 }

{‘cmd’  :  ‘mod’,  ‘category’:1,’seq’:1’,  ‘oip’:’1.1.1.1’,  ‘oreason’:’test’,

‘ouse’:1, ‘nip’:’1.1.1.1’, ‘nreason’:’test’, ‘nuse’:0}

{‘cmd’ : ‘del’, ‘category’:1,’seq’:1’}

{‘cmd’

:

‘search’,

‘ip’:’1.1.1.1’,

‘sdate’:  1634692033,

‘edate’:

1634692033}



cmd :  화이트리스트  IP  관리  내역에  대한  추가,  수정,  삭제,  리스트를  위한  명령  지정

◼  응답  메시지  포맷(list/search)

항목

값

설명

status

code

whiteips

  num

info

id

category

seq

ip

reason

use

flag

date

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

정수

정수

정수

문자열

문자열

정수

정수

문자열

Info entry  개수

index

category

sequence

server IP  주소

사유

사용여부

2

날짜



flag : 2이면  manger whitetip  임

(성공)

{

        "status": 1,

        "code": 1001,

        "whiteips": {

                "num": 3,

                "info": [

                        {

                                "id": 1,

                                "category": 1,

                                "seq": 1,

                                "ip": "210.95.66.67",

                                "reason": "\ud14c\uc2a4\ud2b8",

                                "use": 1,

                                “flag”: 2,

                                "date": "2021-10-25 05:48:20"

                        },

                        {

                                "id": 2,

"category": 1,

                                "seq": 2,

                                "ip": "210.95.66.1",

                                "reason": "\uc9c4\uc9dc\uc878\ub824",

                                "use": 1,

“flag”: 2,

                                "date": "2021-11-04 07:22:45"

                        },

                        {

                                "id": 4,

"category": 2,

                                "seq": 1,

                                "ip": "100.100.100.100",

                                "reason": "test100",

                                "use": 1,

“flag”: 2,

                                "date": "2021-11-26 06:36:12"

                        }

                ]

        }

}

(실패)

{

        "status": 0,

        "code": 1004

}

8.3.  배포서버별  차단  통계

배포서버별  차단  통계를  요청하고  최근  7일간  결과를  받아온다. Manager에서  배포서버별  차단  통

계를  보여주기  위해  사용된다.

◼  요청  메시지  포맷

URL

Method

/1/apis/manager/sums

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘svrstat’ }



cmd :  배포서버별  차단통계를  위해서는  svrstat을  지정

◼  응답  메시지  포맷

항목

값

설명

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

정수

문자열

정수

문자열

정수

Info entry  개수

날짜

배포  서버  개수

배포  서버  id

차단  IP  개수

status

code

daily

  num

info

  date

num

server

sid

cnt

(성공)

{

        "status": 1,

        "code": 1001,

        "daily": {

                "num": 7,

                "info": [

                        {

                                "date": "2021-11-10",

                                “num”: 2,

                                “server” : [

                                    {

                                        "sid": “1”,

                                        "cnt": 100

                                    },

{

                                        "sid": “2”,

                                        "cnt": 80

                                    }

],

{

                                "date": "2021-11-09",

                                “num”: 1,

                                “server” : [

                                    {

                                        "sid": “3”,

                                        "cnt": 120

                                    },

{

                                        "sid": “1”,

                                        "cnt": 100

                                    }

],

                        },

                        …

                  ]

        },

}

(실패)

{

        "status": 0,

        "code": 1004

}

8.4. Manager  관련  설정

Manager  사용시  Manager  및  Log Server  연동  관련  설정을  위해  사용한다.

◼  요청  메시지  포맷

URL

Method

/1/apis/manager/setting

POST

Authorization

token

Content-Type

application/json

Body

{‘cmd’ : ‘list’}

{‘cmd’  : ‘mod’, "omgr_use" : 1, "omgr_ip" : "1.1.1.1",  "omgr_port" :

1234, "omgr_user" : "admin", "omgr_pass" : "admin", "omgr_proto" :

"tcp", "olog_use" : 0,    "olog_ip" : "", "olog_port" : 0, "olog_proto" :

"",  "nmgr_use"  :  1,  "nmgr_ip"  :  "1.1.1.1",  "nmgr_port"  :  1234,

"nmgr_user" : "admin", "nmgr_pass" : "admin", "nmgr_proto" : "tcp",

"nlog_use" : 1,    "nlog_ip" : "1.1.1.2", "nlog_port" : 514, "nlog_proto" :

"udp"}



cmd :  배포서버별  차단통계를  위해서는  svrstat을  지정

◼  응답  메시지  포맷

항목

값

설명

status

code

mgr_use

mgr_ip

mgr_port

mgr_user

mgr_pass

mgr_proto

log_use

log_ip

log_port

log_user

log_pass

log_proto

0  또는  1(상태  정의  참조)

성공  여부

코드  정의  참조

리턴  코드

0  또는  1

Manager  사용  여부

문자열

정수

문자열

문자열

문자열

0  또는  1

문자열

정수

문자열

문자열

문자열

Manager IP

Manager  사용  포트

Manger  연동시  사용  계정

Manger  연동시  사용  비밀번호

Manager  연동  프로토콜

Log Server  사용  여부

Log Server IP

Log Server  사용  포트

Log Server  연동시  사용  계정

Log Server  연동시  사용  비밀번호

Log Server  연동  프로토콜

(성공)

{

        "status": 1,

        "code": 1001,

        "info": {

                        "mgr_use" : 1,

                        "mgr_ip" : "1.1.1.1",

                        "mgr_port" : 1234,

                        "mgr_user" : "admin",

                        "mgr_pass" : "admin",

                        "mgr_proto" : "tcp",

                        "log_use" : 0,

                        "log_ip" : "",

                        "log_port" : 0,

                        "log_proto" : "",

        },

}

(실패)

{

        "status": 0,

        "code": 1004

}

9.  참고

9.1.  응답  status

◼  공통  응답  status

값

설명

기타

0

1

실패

성공

9.2.  응답  code

◼  공통  응답  code

값

설명

기타

1001~1099

성공

2001

2002

2003

2004

token  오류

DB  오류

parameter  오류

지원하지  않는  API

status가  1일  경우  무시

로그인  페이지로  전환

◼  사용자  관련  응답  code

값

설명

기타

3001

3002

3003

로그인  실패

사용할  수  없는  사용자

로그인  시도  횟수  초과

