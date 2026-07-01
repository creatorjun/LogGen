GET

POST

PUT

  DELETE

GET

PUT

  DELETE

POST

GET

PUT

PUT

SSL VPN > 외부 LDAP 연동 REST API 문서

https://{url}/api/vp

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/vp

외부 LDAP 연동

/sslvpn/ext-ldaps

/sslvpn/ext-ldaps/{pk}

/sslvpn/ext-ldaps/{pk}/test/user

/sslvpn/ext-ldaps/{pk}/test/server

외부 LDAP 연동 적용/취소

/command/sslvpn-ext-ldaps/apply

/command/sslvpn-ext-ldaps/cancel

외부 LDAP 연동

GET

/sslvpn/ext-ldaps

외부 LDAP 목록을 조회한다.

Request

Headers

Authorization: required (string)
Authorization
API Token
로그인 후 응답에 포함된  api_token 을 설정

Example:
Example

fd9b3a9e18ac461cb036a8ea9053985e

Accept
Accept: required (string)
응답 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Content-Type
Content-Type: required (string)
요청 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Accept-Language
Accept-Language: (one of ko, en, ja - default: ko)
언어 설정

필수가 아니며 요청 시 설정되지 않으면 로그인 시 사용된 언어로 설정됩니다.
한국어:	ko,	영어:	en,	일어:	ja

Example:
Example

ko

User-Agent
User-Agent: required (string)
User-Agent  HTTP 헤더
웹 브라우저에서는 자동으로 설정되지만 서버 프로그램에서는 필수로 입력되어야 한다.
인증 후 사용되는 모든 REST API를 호출할 때 필수 입력 사항이다.

Example:
Example

Mozilla/5.0	(Windows	NT	10.0;	Win64;	x64)	AppleWebKit/537.36	(KHTML,	like	Gecko)	Chrome/84.0.4147.105	Safari/537.36

Response

HTTP status code 200

외부 LDAP 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result
result: required (array of ResSslvpnExtLdap)
결과 데이터

Items: ResSslvpnExtLdap
Items

authsvr_ldap_id
authsvr_ldap_id: required (integer)
인증서버 외부 LDAP 아이디

useuse: required (one of 0, 1 - default: 1)
인증서버 사용 여부
사용안함:	0,	사용함:	1

search_base_dn
search_base_dn: required (string)
검색 Base DN

search_bind_dn
search_bind_dn: required (string)
검색 Bind DN

search_usr_id
search_usr_id: required (string)
검색 정보
UID,	CN

grp_info_type
grp_info_type: required (one of 0, 1)
그룹 지정 방법
0:	지정	속성	사용,	1:	첫번째	OU	값	사용

grp_filter
grp_filter: required (string - maxLength: 30)
그룹 필터
grp_info_type  속성값이 0일 때 필수

auto_grp_use
auto_grp_use: required (one of 0, 1 - default: 1)
그룹 자동 변경
사용안함:	0,	사용함:	1

descdesc: required (string)
비고

group_list
group_list: required (array of items)
Items: items
Items

sslvpn_grp_id
sslvpn_grp_id: required (integer - default: 1)
SSLVPN 그룹의 고유한 아이디

grp_code
grp_code: required (string)
그룹 코드

name
name: required (string)
그룹 이름

name
name: required (string)
인증서버 LDAP 이름

base_dn: required (string)
base_dn
Base DN

bind_dn
bind_dn: required (string)
Bind DN

conn_type
conn_type: required (one of 0, 1, 2 - default: 0)
보안 연결 유형
NONE:	0,	LDAPS:	1,	Start	TLS:	2

tm_limit
tm_limit: required (integer - default: 30 - minimum: 1 - maximum: 30)
검색 시간 제한

bind_tm_limit
bind_tm_limit: required (integer - default: 30 - minimum: 1 - maximum: 30)
Bind 시간 제한

retry_intval
retry_intval: required (integer - default: 300 - minimum: 1 - maximum: 3600)
재시도 간격

auth_only
auth_only: required (one of 0, 1 - default: 0)
관리자 인증 전용
사용안함:	0,	사용함:	1

ldap_svr_list
ldap_svr_list: required (array of items)
Items: items
Items

ldap_svr_id
ldap_svr_id: required (integer)
외부 LDAP 아이디

ipip: required (string)
서버 주소

portport: required (integer - default: 3600)
서버 포트

cfg_adm_id
cfg_adm_id: required (integer)
등록자 ID

cfg_adm
cfg_adm: required (string)
등록자

cfg_dt
cfg_dt: required (string)
최근 수정일

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"authsvr_ldap_id":	1,
				"use":	1,
				"search_base_dn":	"base_dn",
				"search_bind_dn":	null,
				"search_usr_id":	"UID",
				"grp_info_type":	0,
				"grp_filter":	"a001",
				"auto_grp_use":	1,
				"name":	"외부	LDAP	이름",
				"base_dn":	"dc=tn,dc=firewall2008,dc=fwad,dc=com",
				"bind_dn":	"cn=administrator,cn=users,dc=tn,dc=firewall2008,dc=fwad,dc=com",
				"conn_type":	0,
				"tm_limit":	30,
				"bind_tm_limit":	30,
				"retry_intval":	300,
				"auth_only":	0,
				"desc":	"비고",
				"ldap_svr_list":	[{
						"ldap_svr_id":	1,
						"ip":	"1.1.1.1",
						"port":	3600
				}],
				"group_list":	[{
						"sslvpn_grp_id":	1,
						"grp_code":	"a001",
						"name":	"기본	그룹"
				}],
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2017-10-10	15:36:45"
		}]
}

HTTP status code 401

인증 또는 인가되지 않음 (UNAUTHORIZED)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

message
message: required (string)
결과 메시지

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"94011",
		"dev_t":	"Authentication	Error"
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"dev_t":	"Authentication	Error",
		"message":	"인가되지	않은	API	요청입니다."
}

POST

/sslvpn/ext-ldaps

외부 LDAP를 추가한다.

Request

Headers

Authorization
Authorization: required (string)
API Token
로그인 후 응답에 포함된  api_token 을 설정

Example:
Example

fd9b3a9e18ac461cb036a8ea9053985e

Accept
Accept: required (string)
응답 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Content-Type
Content-Type: required (string)
요청 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Accept-Language
Accept-Language: (one of ko, en, ja - default: ko)
언어 설정

필수가 아니며 요청 시 설정되지 않으면 로그인 시 사용된 언어로 설정됩니다.
한국어:	ko,	영어:	en,	일어:	ja

Example:
Example

ko

User-Agent
User-Agent: required (string)
User-Agent  HTTP 헤더
웹 브라우저에서는 자동으로 설정되지만 서버 프로그램에서는 필수로 입력되어야 한다.
인증 후 사용되는 모든 REST API를 호출할 때 필수 입력 사항이다.

Example:
Example

Mozilla/5.0	(Windows	NT	10.0;	Win64;	x64)	AppleWebKit/537.36	(KHTML,	like	Gecko)	Chrome/84.0.4147.105	Safari/537.36

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties

authsvr_ldap_id: required (integer)
authsvr_ldap_id
인증서버 외부 LDAP 아이디

useuse: required (one of 0, 1 - default: 1)
인증서버 사용 여부
사용안함:	0,	사용함:	1

search_base_dn: required (string)
search_base_dn
검색 Base DN

search_bind_dn
search_bind_dn: required (string)
검색 Bind DN

search_usr_id: required (string)
search_usr_id
검색 정보
UID,	CN

grp_info_type
grp_info_type: required (one of 0, 1)
그룹 지정 방법
0:	지정	속성	사용,	1:	첫번째	OU	값	사용

grp_filter
grp_filter: required (string - maxLength: 30)
그룹 필터
grp_info_type  속성값이 0일 때 필수

auto_grp_use
auto_grp_use: required (one of 0, 1 - default: 1)
그룹 자동 변경
사용안함:	0,	사용함:	1

descdesc: required (string)
비고

group_list
group_list: required (array of items)
Items: items
Items

sslvpn_grp_id
sslvpn_grp_id: required (integer - default: 1)
SSLVPN 그룹의 고유한 아이디

grp_code
grp_code: required (string)
그룹 코드

name: required (string)
name
그룹 이름

Example:
Example

{
		"authsvr_ldap_id":	1,
		"use":	1,
		"search_base_dn":	"base_dn",
		"search_bind_dn":	null,
		"search_usr_id":	"UID",
		"grp_info_type":	0,
		"grp_filter":	"a001",
		"auto_grp_use":	1,
		"desc":	"비고",
		"group_list":	[{
				"sslvpn_grp_id":	1,
				"grp_code":	"a001",
				"name":	"기본	그룹"
		}]
}

Response

HTTP status code 200

외부 LDAP 추가 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result
result: required (object)
결과 데이터

authsvr_ldap_id
authsvr_ldap_id: required (integer)
인증서버 외부 LDAP 아이디

useuse: required (one of 0, 1 - default: 1)
인증서버 사용 여부
사용안함:	0,	사용함:	1

search_base_dn
search_base_dn: required (string)
검색 Base DN

search_bind_dn
search_bind_dn: required (string)
검색 Bind DN

search_usr_id
search_usr_id: required (string)
검색 정보
UID,	CN

grp_info_type
grp_info_type: required (one of 0, 1)
그룹 지정 방법
0:	지정	속성	사용,	1:	첫번째	OU	값	사용

grp_filter
grp_filter: required (string - maxLength: 30)
그룹 필터
grp_info_type  속성값이 0일 때 필수

auto_grp_use
auto_grp_use: required (one of 0, 1 - default: 1)
그룹 자동 변경
사용안함:	0,	사용함:	1

descdesc: required (string)
비고

group_list
group_list: required (array of items)
Items: items
Items

sslvpn_grp_id
sslvpn_grp_id: required (integer - default: 1)
SSLVPN 그룹의 고유한 아이디

grp_code
grp_code: required (string)
그룹 코드

name
name: required (string)
그룹 이름

name
name: required (string)
인증서버 LDAP 이름

base_dn
base_dn: required (string)
Base DN

bind_dn: required (string)
bind_dn
Bind DN

conn_type
conn_type: required (one of 0, 1, 2 - default: 0)
보안 연결 유형
NONE:	0,	LDAPS:	1,	Start	TLS:	2

tm_limit: required (integer - default: 30 - minimum: 1 - maximum: 30)
tm_limit
검색 시간 제한

bind_tm_limit
bind_tm_limit: required (integer - default: 30 - minimum: 1 - maximum: 30)
Bind 시간 제한

retry_intval: required (integer - default: 300 - minimum: 1 - maximum: 3600)
retry_intval
재시도 간격

auth_only
auth_only: required (one of 0, 1 - default: 0)
관리자 인증 전용
사용안함:	0,	사용함:	1

ldap_svr_list: required (array of items)
ldap_svr_list
Items: items
Items

ldap_svr_id
ldap_svr_id: required (integer)
외부 LDAP 아이디

ipip: required (string)
서버 주소

portport: required (integer - default: 3600)
서버 포트

cfg_adm_id
cfg_adm_id: required (integer)
등록자 ID

cfg_adm
cfg_adm: required (string)
등록자

cfg_dt
cfg_dt: required (string)
최근 수정일

Example:
Example

{
		"code":	"ok",
		"result":	{
				"authsvr_ldap_id":	1,
				"use":	1,
				"search_base_dn":	"base_dn",
				"search_bind_dn":	null,
				"search_usr_id":	"UID",
				"grp_info_type":	0,
				"grp_filter":	"a001",
				"auto_grp_use":	1,
				"name":	"외부	LDAP	이름",
				"base_dn":	"dc=tn,dc=firewall2008,dc=fwad,dc=com",
				"bind_dn":	"cn=administrator,cn=users,dc=tn,dc=firewall2008,dc=fwad,dc=com",
				"conn_type":	0,
				"tm_limit":	30,
				"bind_tm_limit":	30,
				"retry_intval":	300,
				"auth_only":	0,
				"desc":	"비고",
				"ldap_svr_list":	[{
						"ldap_svr_id":	1,
						"ip":	"1.1.1.1",
						"port":	3600
				}],
				"group_list":	[{
						"sslvpn_grp_id":	1,
						"grp_code":	"a001",
						"name":	"기본	그룹"
				}],
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2017-10-10	15:36:45"
		}
}

HTTP status code 400

잘못된 요청 (BAD	REQUEST)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

message
message: required (string)
결과 메시지

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"11000",
		"message":	"중복되는	항목이	존재합니다."
}

HTTP status code 401

인증 또는 인가되지 않음 (UNAUTHORIZED)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

message: required (string)
message
결과 메시지

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

PUT

/sslvpn/ext-ldaps

외부 LDAP 목록을 (일괄)수정한다.

Request

Headers

Authorization
Authorization: required (string)
API Token
로그인 후 응답에 포함된  api_token 을 설정

Example:
Example

fd9b3a9e18ac461cb036a8ea9053985e

Accept: required (string)
Accept
응답 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Content-Type: required (string)
Content-Type
요청 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Accept-Language
Accept-Language: (one of ko, en, ja - default: ko)
언어 설정

필수가 아니며 요청 시 설정되지 않으면 로그인 시 사용된 언어로 설정됩니다.
한국어:	ko,	영어:	en,	일어:	ja

Example:
Example

ko

User-Agent
User-Agent: required (string)
User-Agent  HTTP 헤더
웹 브라우저에서는 자동으로 설정되지만 서버 프로그램에서는 필수로 입력되어야 한다.
인증 후 사용되는 모든 REST API를 호출할 때 필수 입력 사항이다.

Example:
Example

Mozilla/5.0	(Windows	NT	10.0;	Win64;	x64)	AppleWebKit/537.36	(KHTML,	like	Gecko)	Chrome/84.0.4147.105	Safari/537.36

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
items
items: required (array of ReqSslvpnExtLdapList)
수정 아이템 목록

Items: ReqSslvpnExtLdapList
Items

authsvr_ldap_id
authsvr_ldap_id: required (integer)
인증서버 외부 LDAP 아이디

useuse: required (one of 0, 1 - default: 1)
인증서버 사용 여부
사용안함:	0,	사용함:	1

Example:
Example

{
		"items":	[
				{"authsvr_ldap_id":	1,	"use":	0}
		]
}

Response

HTTP status code 200

외부 LDAP 목록 수정 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (one of ok, pok, nok)
결과 코드

result
result: required (object)
결과 데이터

errors
errors: required (array of object)
수정 실패 시 에러 목록

Example:
Example

{
		"code":	"ok",
		"result":	{
				"errors":	[]
		}
}

HTTP status code 401

인증 또는 인가되지 않음 (UNAUTHORIZED)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

message
message: required (string)
결과 메시지

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

DELETE

/sslvpn/ext-ldaps

외부 LDAP 목록을 (일괄)삭제한다.

Request

Headers

Authorization
Authorization: required (string)
API Token
로그인 후 응답에 포함된  api_token 을 설정

Example:
Example

fd9b3a9e18ac461cb036a8ea9053985e

Accept
Accept: required (string)
응답 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Content-Type
Content-Type: required (string)
요청 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Accept-Language
Accept-Language: (one of ko, en, ja - default: ko)
언어 설정

필수가 아니며 요청 시 설정되지 않으면 로그인 시 사용된 언어로 설정됩니다.
한국어:	ko,	영어:	en,	일어:	ja

Example:
Example

ko

User-Agent: required (string)
User-Agent
User-Agent  HTTP 헤더
웹 브라우저에서는 자동으로 설정되지만 서버 프로그램에서는 필수로 입력되어야 한다.
인증 후 사용되는 모든 REST API를 호출할 때 필수 입력 사항이다.

Example:
Example

Mozilla/5.0	(Windows	NT	10.0;	Win64;	x64)	AppleWebKit/537.36	(KHTML,	like	Gecko)	Chrome/84.0.4147.105	Safari/537.36

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
items
items: required (array of object)
삭제 아이템 목록

Example:
Example

{
		"items":	[
				{"authsvr_ldap_id":	1},
				{"authsvr_ldap_id":	2}
		]
}

Response

HTTP status code 200

외부 LDAP 목록 삭제 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (one of ok, pok, nok)
결과 코드

result
result: required (object)
결과 데이터

errors
errors: required (array of object)
삭제 실패 시 에러 목록

Example:
Example

{
		"code":	"ok",
		"result":	{
				"errors":	[]
		}
}

HTTP status code 401

인증 또는 인가되지 않음 (UNAUTHORIZED)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (string)
code
결과 코드

message
message: required (string)
결과 메시지

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

GET

/sslvpn/ext-ldaps/{pk}

외부 LDAP을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
인증서버 외부 LDAP 아이디 ( authsvr_ldap_id )

Headers

Authorization
Authorization: required (string)
API Token
로그인 후 응답에 포함된  api_token 을 설정

Example:
Example

fd9b3a9e18ac461cb036a8ea9053985e

Accept
Accept: required (string)
응답 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Content-Type: required (string)
Content-Type
요청 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Accept-Language
Accept-Language: (one of ko, en, ja - default: ko)
언어 설정

필수가 아니며 요청 시 설정되지 않으면 로그인 시 사용된 언어로 설정됩니다.
한국어:	ko,	영어:	en,	일어:	ja

Example:
Example

ko

User-Agent
User-Agent: required (string)
User-Agent  HTTP 헤더
웹 브라우저에서는 자동으로 설정되지만 서버 프로그램에서는 필수로 입력되어야 한다.
인증 후 사용되는 모든 REST API를 호출할 때 필수 입력 사항이다.

Example:
Example

Mozilla/5.0	(Windows	NT	10.0;	Win64;	x64)	AppleWebKit/537.36	(KHTML,	like	Gecko)	Chrome/84.0.4147.105	Safari/537.36

Response

HTTP status code 200

외부 LDAP 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result
result: required (object)
결과 데이터

authsvr_ldap_id: required (integer)
authsvr_ldap_id
인증서버 외부 LDAP 아이디

useuse: required (one of 0, 1 - default: 1)
인증서버 사용 여부
사용안함:	0,	사용함:	1

search_base_dn: required (string)
search_base_dn
검색 Base DN

search_bind_dn
search_bind_dn: required (string)
검색 Bind DN

search_usr_id
search_usr_id: required (string)
검색 정보
UID,	CN

grp_info_type
grp_info_type: required (one of 0, 1)
그룹 지정 방법
0:	지정	속성	사용,	1:	첫번째	OU	값	사용

grp_filter: required (string - maxLength: 30)
grp_filter
그룹 필터
grp_info_type  속성값이 0일 때 필수

auto_grp_use
auto_grp_use: required (one of 0, 1 - default: 1)
그룹 자동 변경
사용안함:	0,	사용함:	1

descdesc: required (string)
비고

group_list
group_list: required (array of items)
Items: items
Items

sslvpn_grp_id
sslvpn_grp_id: required (integer - default: 1)
SSLVPN 그룹의 고유한 아이디

grp_code
grp_code: required (string)
그룹 코드

name
name: required (string)
그룹 이름

name
name: required (string)
인증서버 LDAP 이름

base_dn
base_dn: required (string)
Base DN

bind_dn
bind_dn: required (string)
Bind DN

conn_type: required (one of 0, 1, 2 - default: 0)
conn_type

보안 연결 유형
NONE:	0,	LDAPS:	1,	Start	TLS:	2

tm_limit
tm_limit: required (integer - default: 30 - minimum: 1 - maximum: 30)
검색 시간 제한

bind_tm_limit
bind_tm_limit: required (integer - default: 30 - minimum: 1 - maximum: 30)
Bind 시간 제한

retry_intval
retry_intval: required (integer - default: 300 - minimum: 1 - maximum: 3600)
재시도 간격

auth_only
auth_only: required (one of 0, 1 - default: 0)
관리자 인증 전용
사용안함:	0,	사용함:	1

ldap_svr_list
ldap_svr_list: required (array of items)
Items: items
Items

ldap_svr_id
ldap_svr_id: required (integer)
외부 LDAP 아이디

ipip: required (string)
서버 주소

portport: required (integer - default: 3600)
서버 포트

cfg_adm_id
cfg_adm_id: required (integer)
등록자 ID

cfg_adm: required (string)
cfg_adm
등록자

cfg_dt
cfg_dt: required (string)
최근 수정일

Example:
Example

{
		"code":	"ok",
		"result":	{
				"authsvr_ldap_id":	1,
				"use":	1,
				"search_base_dn":	"base_dn",
				"search_bind_dn":	null,
				"search_usr_id":	"UID",
				"grp_info_type":	0,
				"grp_filter":	"a001",
				"auto_grp_use":	1,
				"name":	"외부	LDAP	이름",
				"base_dn":	"dc=tn,dc=firewall2008,dc=fwad,dc=com",
				"bind_dn":	"cn=administrator,cn=users,dc=tn,dc=firewall2008,dc=fwad,dc=com",
				"conn_type":	0,
				"tm_limit":	30,
				"bind_tm_limit":	30,
				"retry_intval":	300,
				"auth_only":	0,
				"desc":	"비고",
				"ldap_svr_list":	[{
						"ldap_svr_id":	1,
						"ip":	"1.1.1.1",
						"port":	3600
				}],
				"group_list":	[{
						"sslvpn_grp_id":	1,
						"grp_code":	"a001",
						"name":	"기본	그룹"
				}],
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2017-10-10	15:36:45"
		}
}

HTTP status code 401

인증 또는 인가되지 않음 (UNAUTHORIZED)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (string)
code
결과 코드

message
message: required (string)
결과 메시지

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

HTTP status code 404

리소스를 찾을 수 없음 (NOT	FOUND)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (string)
code
결과 코드

message
message: required (string)
결과 메시지

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"12001",
		"message":	"존재하지	않는	항목입니다."
}

PUT

/sslvpn/ext-ldaps/{pk}

외부 LDAP을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
인증서버 외부 LDAP 아이디 ( authsvr_ldap_id )

Headers

Authorization
Authorization: required (string)
API Token
로그인 후 응답에 포함된  api_token 을 설정

Example:
Example

fd9b3a9e18ac461cb036a8ea9053985e

Accept
Accept: required (string)
응답 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Content-Type
Content-Type: required (string)
요청 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Accept-Language
Accept-Language: (one of ko, en, ja - default: ko)
언어 설정

필수가 아니며 요청 시 설정되지 않으면 로그인 시 사용된 언어로 설정됩니다.
한국어:	ko,	영어:	en,	일어:	ja

Example:
Example

ko

User-Agent
User-Agent: required (string)
User-Agent  HTTP 헤더
웹 브라우저에서는 자동으로 설정되지만 서버 프로그램에서는 필수로 입력되어야 한다.
인증 후 사용되는 모든 REST API를 호출할 때 필수 입력 사항이다.

Example:
Example

Mozilla/5.0	(Windows	NT	10.0;	Win64;	x64)	AppleWebKit/537.36	(KHTML,	like	Gecko)	Chrome/84.0.4147.105	Safari/537.36

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties

authsvr_ldap_id: required (integer)
authsvr_ldap_id

인증서버 외부 LDAP 아이디

useuse: required (one of 0, 1 - default: 1)
인증서버 사용 여부
사용안함:	0,	사용함:	1

search_base_dn
search_base_dn: required (string)
검색 Base DN

search_bind_dn
search_bind_dn: required (string)
검색 Bind DN

search_usr_id
search_usr_id: required (string)
검색 정보
UID,	CN

grp_info_type
grp_info_type: required (one of 0, 1)
그룹 지정 방법
0:	지정	속성	사용,	1:	첫번째	OU	값	사용

grp_filter
grp_filter: required (string - maxLength: 30)
그룹 필터
grp_info_type  속성값이 0일 때 필수

auto_grp_use
auto_grp_use: required (one of 0, 1 - default: 1)
그룹 자동 변경
사용안함:	0,	사용함:	1

descdesc: required (string)
비고

group_list
group_list: required (array of items)
Items: items
Items

sslvpn_grp_id
sslvpn_grp_id: required (integer - default: 1)
SSLVPN 그룹의 고유한 아이디

grp_code
grp_code: required (string)
그룹 코드

name
name: required (string)
그룹 이름

Example:
Example

{
		"use":	0,
		"search_base_dn":	"base_dn",
		"search_bind_dn":	null,
		"search_usr_id":	"CN",
		"grp_info_type":	1,
		"grp_filter":	"a001,a002",
		"auto_grp_use":	0,
		"desc":	"비고2",
		"group_list":	[{
				"sslvpn_grp_id":	1,
				"grp_code":	"a001,a002",
				"name":	"기본	그룹"
		}]
}

Response

HTTP status code 200

외부 LDAP 수정 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (object)
result
결과 데이터

authsvr_ldap_id
authsvr_ldap_id: required (integer)
인증서버 외부 LDAP 아이디

useuse: required (one of 0, 1 - default: 1)
인증서버 사용 여부
사용안함:	0,	사용함:	1

search_base_dn
search_base_dn: required (string)
검색 Base DN

search_bind_dn
search_bind_dn: required (string)
검색 Bind DN

search_usr_id
search_usr_id: required (string)
검색 정보
UID,	CN

grp_info_type
grp_info_type: required (one of 0, 1)
그룹 지정 방법
0:	지정	속성	사용,	1:	첫번째	OU	값	사용

grp_filter
grp_filter: required (string - maxLength: 30)
그룹 필터
grp_info_type  속성값이 0일 때 필수

auto_grp_use
auto_grp_use: required (one of 0, 1 - default: 1)
그룹 자동 변경
사용안함:	0,	사용함:	1

descdesc: required (string)
비고

group_list
group_list: required (array of items)
Items: items
Items

sslvpn_grp_id
sslvpn_grp_id: required (integer - default: 1)
SSLVPN 그룹의 고유한 아이디

grp_code
grp_code: required (string)
그룹 코드

name
name: required (string)
그룹 이름

name
name: required (string)
인증서버 LDAP 이름

base_dn
base_dn: required (string)
Base DN

bind_dn
bind_dn: required (string)
Bind DN

conn_type
conn_type: required (one of 0, 1, 2 - default: 0)
보안 연결 유형
NONE:	0,	LDAPS:	1,	Start	TLS:	2

tm_limit
tm_limit: required (integer - default: 30 - minimum: 1 - maximum: 30)
검색 시간 제한

bind_tm_limit
bind_tm_limit: required (integer - default: 30 - minimum: 1 - maximum: 30)
Bind 시간 제한

retry_intval: required (integer - default: 300 - minimum: 1 - maximum: 3600)
retry_intval
재시도 간격

auth_only
auth_only: required (one of 0, 1 - default: 0)
관리자 인증 전용
사용안함:	0,	사용함:	1

ldap_svr_list: required (array of items)
ldap_svr_list
Items: items
Items

ldap_svr_id
ldap_svr_id: required (integer)
외부 LDAP 아이디

ipip: required (string)
서버 주소

portport: required (integer - default: 3600)
서버 포트

cfg_adm_id
cfg_adm_id: required (integer)
등록자 ID

cfg_adm
cfg_adm: required (string)
등록자

cfg_dt
cfg_dt: required (string)
최근 수정일

Example:
Example

{
		"code":	"ok",
		"result":	{
				"authsvr_ldap_id":	1,
				"use":	0,
				"search_base_dn":	"base_dn",
				"search_bind_dn":	null,
				"search_usr_id":	"CN",
				"grp_info_type":	1,
				"grp_filter":	"a001,a002",
				"auto_grp_use":	0,
				"name":	"외부	LDAP	이름	2",
				"base_dn":	"dc=tn,dc=firewall2008,dc=fwad,dc=com2",
				"bind_dn":	"cn=administrator,cn=users,dc=tn,dc=firewall2008,dc=fwad,dc=com2",
				"conn_type":	1,
				"tm_limit":	30,
				"bind_tm_limit":	30,
				"retry_intval":	300,
				"auth_only":	1,
				"desc":	"비고2",
				"ldap_svr_list":	[{
						"ldap_svr_id":	1,
						"ip":	"1.1.1.2",
						"port":	9000
				}],
				"group_list":	[{
						"sslvpn_grp_id":	1,
						"grp_code":	"a001,a002",
						"name":	"기본	그룹"
				}],
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-10-10	15:36:45"
		}
}

HTTP status code 400

잘못된 요청 (BAD	REQUEST)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

message
message: required (string)
결과 메시지

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"12001",
		"message":	"잘못된	값이	입력되었습니다."
}

HTTP status code 401

인증 또는 인가되지 않음 (UNAUTHORIZED)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (string)
code
결과 코드

message
message: required (string)
결과 메시지

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

HTTP status code 404

리소스를 찾을 수 없음 (NOT	FOUND)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (string)
code
결과 코드

message
message: required (string)
결과 메시지

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"12001",
		"message":	"존재하지	않는	항목입니다."
}

DELETE

/sslvpn/ext-ldaps/{pk}

외부 LDAP을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
인증서버 외부 LDAP 아이디 ( authsvr_ldap_id )

Headers

Authorization
Authorization: required (string)
API Token
로그인 후 응답에 포함된  api_token 을 설정

Example:
Example

fd9b3a9e18ac461cb036a8ea9053985e

Accept
Accept: required (string)
응답 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Content-Type: required (string)
Content-Type
요청 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Accept-Language: (one of ko, en, ja - default: ko)
Accept-Language
언어 설정

필수가 아니며 요청 시 설정되지 않으면 로그인 시 사용된 언어로 설정됩니다.
한국어:	ko,	영어:	en,	일어:	ja

Example:
Example

ko

User-Agent
User-Agent: required (string)
User-Agent  HTTP 헤더
웹 브라우저에서는 자동으로 설정되지만 서버 프로그램에서는 필수로 입력되어야 한다.
인증 후 사용되는 모든 REST API를 호출할 때 필수 입력 사항이다.

Example:
Example

Mozilla/5.0	(Windows	NT	10.0;	Win64;	x64)	AppleWebKit/537.36	(KHTML,	like	Gecko)	Chrome/84.0.4147.105	Safari/537.36

Response

HTTP status code 200

외부 LDAP 삭제 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (string)
code
결과 코드

result
result: required (object)
결과 데이터

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"ok",
		"result":	{}
}

HTTP status code 400

잘못된 요청 (BAD	REQUEST)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

message
message: required (string)
결과 메시지

dev_t: (string)
dev_t
개발용 메시지

Example:
Example

{
		"code":	"12004",
		"message":	"다른	기능에서	사용	중입니다."
}

HTTP status code 401

인증 또는 인가되지 않음 (UNAUTHORIZED)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

message: required (string)
message
결과 메시지

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

HTTP status code 404

리소스를 찾을 수 없음 (NOT	FOUND)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

message: required (string)
message
결과 메시지

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"12001",
		"message":	"존재하지	않는	항목입니다."
}

POST

/sslvpn/ext-ldaps/{pk}/test/user

외부 LADP 사용자 접속 테스트한다.

Request

URI Parameters

pkpk: required (integer)
인증서버 외부 LDAP 아이디 ( authsvr_ldap_id )

Headers

Authorization
Authorization: required (string)
API Token
로그인 후 응답에 포함된  api_token 을 설정

Example:
Example

fd9b3a9e18ac461cb036a8ea9053985e

Accept
Accept: required (string)
응답 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Content-Type
Content-Type: required (string)
요청 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Accept-Language
Accept-Language: (one of ko, en, ja - default: ko)
언어 설정

필수가 아니며 요청 시 설정되지 않으면 로그인 시 사용된 언어로 설정됩니다.
한국어:	ko,	영어:	en,	일어:	ja

Example:
Example

ko

User-Agent
User-Agent: required (string)
User-Agent  HTTP 헤더
웹 브라우저에서는 자동으로 설정되지만 서버 프로그램에서는 필수로 입력되어야 한다.
인증 후 사용되는 모든 REST API를 호출할 때 필수 입력 사항이다.

Example:
Example

Mozilla/5.0	(Windows	NT	10.0;	Win64;	x64)	AppleWebKit/537.36	(KHTML,	like	Gecko)	Chrome/84.0.4147.105	Safari/537.36

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties

idid: required (string)
사용자 아이디

pwdpwd: required (string)
사용자 패스워드(Base64 인코딩)

Example:
Example

{
		"id":	"usr1",
		"pwd":	"x2xAyWkwMEAh"
}

Response

HTTP status code 200

외부 LADP 사용자 접속 테스트 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (string)
code
결과 코드

result
result: required (object)
결과 데이터

Example:
Example

{
		"code":	"ok",
		"result":	{}
}

HTTP status code 400

외부 LDAP 사용자 접속 테스트 요청 실패

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

message
message: required (string)
결과 메시지

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"11000",
		"message":	"중복되는	항목이	존재합니다."
}

HTTP status code 401

인증 또는 인가되지 않음 (UNAUTHORIZED)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (string)
code
결과 코드

message
message: required (string)
결과 메시지

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

GET

/sslvpn/ext-ldaps/{pk}/test/server

외부 LADP 접속 테스트한다.

Request

URI Parameters

pkpk: required (integer)
인증서버 외부 LDAP 아이디 ( authsvr_ldap_id )

Headers

Authorization
Authorization: required (string)
API Token
로그인 후 응답에 포함된  api_token 을 설정

Example:
Example

fd9b3a9e18ac461cb036a8ea9053985e

Accept
Accept: required (string)
응답 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Content-Type
Content-Type: required (string)
요청 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Accept-Language
Accept-Language: (one of ko, en, ja - default: ko)
언어 설정

필수가 아니며 요청 시 설정되지 않으면 로그인 시 사용된 언어로 설정됩니다.
한국어:	ko,	영어:	en,	일어:	ja

Example:
Example

ko

User-Agent
User-Agent: required (string)
User-Agent  HTTP 헤더
웹 브라우저에서는 자동으로 설정되지만 서버 프로그램에서는 필수로 입력되어야 한다.
인증 후 사용되는 모든 REST API를 호출할 때 필수 입력 사항이다.

Example:
Example

Mozilla/5.0	(Windows	NT	10.0;	Win64;	x64)	AppleWebKit/537.36	(KHTML,	like	Gecko)	Chrome/84.0.4147.105	Safari/537.36

Response

HTTP status code 200

외부 LADP 접속 테스트 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result
result: required (object)
결과 데이터

authsvr_ldap_id
authsvr_ldap_id: required (integer)
인증서버 외부 LDAP 아이디

Example:
Example

{
		"code":	"ok",
		"result":	{
				"authsvr_ldap_id":	1
		}
}

HTTP status code 400

외부 LDAP 접속 테스트 요청 실패

HTTP status code 401

인증 또는 인가되지 않음 (UNAUTHORIZED)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

message
message: required (string)
결과 메시지

dev_t: (string)
dev_t
개발용 메시지

Example:
Example

{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

HTTP status code 404

리소스를 찾을 수 없음 (NOT	FOUND)

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

message
message: required (string)
결과 메시지

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"12001",
		"message":	"존재하지	않는	항목입니다."
}

외부 LDAP 연동 적용/취소

PUT

/command/sslvpn-ext-ldaps/apply

외부 LDAP 연동을 적용합니다.

Request

Headers

Authorization
Authorization: required (string)
API Token
로그인 후 응답에 포함된  api_token 을 설정

Example:
Example

fd9b3a9e18ac461cb036a8ea9053985e

Accept
Accept: required (string)
응답 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Content-Type
Content-Type: required (string)
요청 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Accept-Language
Accept-Language: (one of ko, en, ja - default: ko)
언어 설정

필수가 아니며 요청 시 설정되지 않으면 로그인 시 사용된 언어로 설정됩니다.
한국어:	ko,	영어:	en,	일어:	ja

Example:
Example

ko

User-Agent
User-Agent: required (string)
User-Agent  HTTP 헤더
웹 브라우저에서는 자동으로 설정되지만 서버 프로그램에서는 필수로 입력되어야 한다.
인증 후 사용되는 모든 REST API를 호출할 때 필수 입력 사항이다.

Example:
Example

Mozilla/5.0	(Windows	NT	10.0;	Win64;	x64)	AppleWebKit/537.36	(KHTML,	like	Gecko)	Chrome/84.0.4147.105	Safari/537.36

Body

Media type: application/json
Media type

TypeType: object

Example:
Example

{}

Response

HTTP status code 200

외부 LDAP 연동 적용 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (string)
code
결과 코드

result
result: required (object)
결과 데이터

Example:
Example

{
		"code":	"ok",
		"result":	{}
}

PUT

/command/sslvpn-ext-ldaps/cancel

외부 LDAP 연동을 취소합니다.

Request

Headers

Authorization
Authorization: required (string)
API Token
로그인 후 응답에 포함된  api_token 을 설정

Example:
Example

fd9b3a9e18ac461cb036a8ea9053985e

Accept
Accept: required (string)
응답 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Content-Type
Content-Type: required (string)
요청 시 사용되는 MIME 타입은 JSON 형식이다.

Example:
Example

application/json

Accept-Language: (one of ko, en, ja - default: ko)
Accept-Language

언어 설정

필수가 아니며 요청 시 설정되지 않으면 로그인 시 사용된 언어로 설정됩니다.
한국어:	ko,	영어:	en,	일어:	ja

Example:
Example

ko

User-Agent: required (string)
User-Agent
User-Agent  HTTP 헤더
웹 브라우저에서는 자동으로 설정되지만 서버 프로그램에서는 필수로 입력되어야 한다.
인증 후 사용되는 모든 REST API를 호출할 때 필수 입력 사항이다.

Example:
Example

Mozilla/5.0	(Windows	NT	10.0;	Win64;	x64)	AppleWebKit/537.36	(KHTML,	like	Gecko)	Chrome/84.0.4147.105	Safari/537.36

Body

Media type: application/json
Media type

TypeType: object

Example:
Example

{}

Response

HTTP status code 200

외부 LDAP 연동 취소 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result
result: required (object)
결과 데이터

Example:
Example

{
		"code":	"ok",
		"result":	{}
}

