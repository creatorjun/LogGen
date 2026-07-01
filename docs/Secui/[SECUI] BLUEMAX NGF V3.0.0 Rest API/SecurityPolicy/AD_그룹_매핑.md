그룹 매핑 연동 REST API 문서

https://{url}/api/po

urlurl: required (string)
장비 IP:Port

하위 DN 목록 조회

/ad-group/search/distinguished/names

POST

GET

POST

PUT

  DELETE

GET

PUT

  DELETE

GET

GET

GET

POST

PUT

PUT

그룹 매핑

/ad-group/servers

/ad-group/servers/{pk}

/ad-group/servers/{pk}/groups

/ad-group/servers/{pk}/groups/{group_name}/filters/{usr_status_filter}/users

매핑 그룹 연동, 사용자 참조 상세 정보

/ad-group/types/{usr_obj_type}/names/{name}/ref

AD 서버 연결 테스트(AD 설정 마법사)

/ad/connect/server

그룹 매핑 연동 적용/취소

/command/ad-group-servers/apply

/command/ad-group-servers/cancel

하위 DN 목록 조회

POST

/ad-group/search/distinguished/names

그룹 매핑를 추가한다.

Request

Annotations

SupportedVersion:
SupportedVersion

"2.1.0"

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

ad_name
ad_name: required (string)
서버 이름(필수)

server_type
server_type: required (one of 1, 2)
서버 타입(필수)
1:	AD
2:	LDAP

group_class
group_class: required (string)
그룹 클래스 값(필수)

target
target: (string)
하위 객체 조회를 위한 타겟 DN

filter
filter: (string)
검색을 위한 필터값

Response

HTTP status code 200

그룹 매핑 추가 성공

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
result: required (array of GetLdap)
결과 데이터

Items: GetLdap
Items

type: required (string)
type
타입

idid: required (string)
ID

dndn: required (string)
DN

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"type":	"container",
				"id":	"Computers",
				"dn":	"CN=Computers\tDC=firewall2008\tDC=fwad\tDC=com"
		},	{
				"type":	"organizationalUnit",
				"id":	"Domain	Controllers",
				"dn":	"OU=Domain	Controllers\tDC=firewall2008\tDC=fwad\tDC=com"
		},	{
				"type":	"container",
				"id":	"ForeignSecurityPrincipals",
				"dn":	"CN=ForeignSecurityPrincipals\tDC=firewall2008\tDC=fwad\tDC=com"
		}]
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

그룹 매핑

GET

/ad-group/servers

그룹 매핑 목록을 조회한다.

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

Response

HTTP status code 200

그룹 매핑 목록 조회 성공

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
result: required (array of GetAdGroupList)
결과 데이터

Items: GetAdGroupList
Items

useuse: required (one of 0, 1)
사용 여부  사용	안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 32)
이름

auth_serv_type: required (one of 1, 2)
auth_serv_type
연동 서버 타입
1:	AD
2:	LDAP

(지원버전:	2.1.0)

auth_serv_id: required (integer)
auth_serv_id
AD 연동 서버 ID

[AD 서버 목록 조회]
GET	{{url}}/api/sm/auth/ad/servers/names

interval: required (integer - minimum: 1 - maximum: 1440)
interval
연동 주기(분)

dmndmn: required (string - maxLength: 32)
도메인
영문,	숫자,	특수	문자('-',	'_')	만	허용,	공백	문자	입력	불가

grp_filter
grp_filter: (string - maxLength: 256)
그룹 객체 필터

grp_obj_class
grp_obj_class: required (string - maxLength: 32)
그룹 객체 클래스

grp_name
grp_name: required (string - maxLength: 32)
그룹 이름

grp_mem: required (string - maxLength: 32)
grp_mem
그룹 멤버

usr_filter
usr_filter: (string - maxLength: 256)
사용자 객체 필터

usr_obj_class
usr_obj_class: required (string - maxLength: 32)
사용자 객체 클래스

usr_name
usr_name: required (string - maxLength: 32)
사용자 이름

usr_status_filter
usr_status_filter: required (one of 0, 1)
사용자 상태 필터
사용안함:	0,	사용:	1

SupportedVersion:	2.0.0

ad_grp_map_id
ad_grp_map_id: required (integer)
그룹 매핑 ID(PK)

auth_serv_name
auth_serv_name: required (string)
연동 서버 이름

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ad_grp_map_id":	1,
				"use":	1,
				"name":	"AD	그룹	이름",
				"auth_serv_type":	1,
				"auth_serv_id":	1,
				"auth_serv_name":	"AD	연동	서버	이름",
				"interval":	1,
				"dmn":	"test@example.com",
				"grp_filter":	"필터	이름",
				"grp_obj_class":	"group",
				"grp_name":	"name",
				"grp_mem":	"member",
				"usr_filter":	"user_filter",
				"usr_obj_class":	"person",
				"usr_name":	"sAMAccountName"
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

/ad-group/servers

그룹 매핑를 추가한다.

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

useuse: required (one of 0, 1)
사용 여부  사용	안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 32)
이름

auth_serv_type
auth_serv_type: required (one of 1, 2)
연동 서버 타입
1:	AD
2:	LDAP

(지원버전:	2.1.0)

auth_serv_id: required (integer)
auth_serv_id

AD 연동 서버 ID

[AD 서버 목록 조회]
GET	{{url}}/api/sm/auth/ad/servers/names

interval
interval: required (integer - minimum: 1 - maximum: 1440)
연동 주기(분)

dmndmn: required (string - maxLength: 32)
도메인
영문,	숫자,	특수	문자('-',	'_')	만	허용,	공백	문자	입력	불가

grp_filter
grp_filter: (string - maxLength: 256)
그룹 객체 필터

grp_obj_class
grp_obj_class: required (string - maxLength: 32)
그룹 객체 클래스

grp_name
grp_name: required (string - maxLength: 32)
그룹 이름

grp_mem
grp_mem: required (string - maxLength: 32)
그룹 멤버

usr_filter: (string - maxLength: 256)
usr_filter
사용자 객체 필터

usr_obj_class
usr_obj_class: required (string - maxLength: 32)
사용자 객체 클래스

usr_name
usr_name: required (string - maxLength: 32)
사용자 이름

usr_status_filter
usr_status_filter: required (one of 0, 1)
사용자 상태 필터
사용안함:	0,	사용:	1

SupportedVersion:	2.0.0

mmbr_obj
mmbr_obj: required (object)
LDAP 정보

group_dn
group_dn: required (string)
타겟 그룹 DN

group_name: required (string)
group_name
타겟 그룹 이름

Example:
Example

{
		"use":	1,
		"name":	"New	AD	그룹	매핑	이름",
		"auth_serv_type":	1,
		"auth_serv_id":	1,
		"interval":	10,
		"dmn":	"test@example.com",
		"grp_filter":	"필터	이름	",
		"grp_obj_class":	"객체	클래스",
		"grp_name":	"그룹	이름",
		"grp_mem":	"그룹	멤버",
		"usr_filter":	"사용자	객체	필터",
		"usr_obj_class":	"사용자	객체	클래스",
		"usr_name":	"사용자	이름",
		"usr_status_filter":	1,
		"mmbr_obj":	[
				{"group_dn":	"dn1",	"group_name":	"그룹명1"},
				{"group_dn":	"dn2",	"group_name":	"그룹명1"}
		]
}

Response

HTTP status code 200

그룹 매핑 추가 성공

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

useuse: required (one of 0, 1)
사용 여부  사용	안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 32)
이름

auth_serv_type
auth_serv_type: required (one of 1, 2)
연동 서버 타입
1:	AD
2:	LDAP

(지원버전:	2.1.0)

auth_serv_id: required (integer)
auth_serv_id

AD 연동 서버 ID

[AD 서버 목록 조회]
GET	{{url}}/api/sm/auth/ad/servers/names

interval
interval: required (integer - minimum: 1 - maximum: 1440)
연동 주기(분)

dmndmn: required (string - maxLength: 32)
도메인
영문,	숫자,	특수	문자('-',	'_')	만	허용,	공백	문자	입력	불가

grp_filter
grp_filter: (string - maxLength: 256)
그룹 객체 필터

grp_obj_class
grp_obj_class: required (string - maxLength: 32)
그룹 객체 클래스

grp_name
grp_name: required (string - maxLength: 32)
그룹 이름

grp_mem
grp_mem: required (string - maxLength: 32)
그룹 멤버

usr_filter: (string - maxLength: 256)
usr_filter
사용자 객체 필터

usr_obj_class
usr_obj_class: required (string - maxLength: 32)
사용자 객체 클래스

usr_name
usr_name: required (string - maxLength: 32)
사용자 이름

usr_status_filter
usr_status_filter: required (one of 0, 1)
사용자 상태 필터
사용안함:	0,	사용:	1

SupportedVersion:	2.0.0

ad_grp_map_id
ad_grp_map_id: required (integer)
그룹 매핑 ID(PK)

auth_serv_name
auth_serv_name: required (string)
연동 서버 이름

target_list: required (object)
target_list
LDAP 정보

group_dn
group_dn: required (string)
타겟 그룹 DN

group_name
group_name: required (string)
타겟 그룹 이름

ad_grp_map_target_id
ad_grp_map_target_id: required (integer)
타겟 ID

ad_grp_map_id
ad_grp_map_id: required (integer)
그룹 매핑 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ad_grp_map_id":	2,
				"use":	1,
				"name":	"New	AD	그룹	이름",
				"auth_serv_type":	1,
				"auth_serv_id":	1,
				"auth_serv_name":	"AD	연동	서버명",
				"interval":	10,
				"dmn":	"test@example.com",
				"grp_filter":	"필터	이름	",
				"grp_obj_class":	"객체	클래스",
				"grp_name":	"그룹	이름",
				"grp_mem":	"그룹	멤버",
				"usr_filter":	"사용자	객체	필터",
				"usr_obj_class":	"사용자	객체	클래스",
				"usr_name":	"사용자	이름",
				"usr_status_filter":	1,
				"mmbr_obj":	[
						{
								"ad_grp_map_target_id":	1,
								"ad_grp_map_id":	2
								"group_dn":	"dn1",
								"group_name":	"그룹명1"
						},
						{
								"ad_grp_map_target_id":	2,
								"ad_grp_map_id":	2
								"group_dn":	"dn2",
								"group_name":	"그룹명2"
						}
				]
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

message: required (string)
message
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

PUT

/ad-group/servers

그룹 매핑 목록을 (일괄)수정한다.

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
items: required (array of object)
items
수정될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"ad_grp_map_id":	1,	"use":	0},
				{"ad_grp_map_id":	2,	"use":	0}
		]
}

Response

HTTP status code 200

그룹 매핑 목록 수정 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (one of ok, pok, nok)
결과 코드

ok:	요청된	모든	항목	정상	처리
pok:	요청	항목	중	일부	항목	오류
nok:	요청된	전체	항목	오류

result: required (object)
result
결과 데이터
code	속성값이	'ok'가	아닐	경우	errors	속성이	포함됨

Example:
Example

{
		"code":	"ok",
		"result":	{
				"errors":	[
				]
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

DELETE

/ad-group/servers

그룹 매핑 목록을 (일괄)삭제한다.

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

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"ad_grp_map_id":	1},
				{"ad_grp_map_id":	2}
		]
}

Response

HTTP status code 200

그룹 매핑 목록 삭제 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (one of ok, pok, nok)
code
결과 코드

ok:	요청된	모든	항목	정상	처리
pok:	요청	항목	중	일부	항목	오류
nok:	요청된	전체	항목	오류

result
result: required (object)
결과 데이터
code	속성값이	'ok'가	아닐	경우	errors	속성이	포함됨

Example:
Example

{
		"code":	"ok",
		"result":	{
				"errors":	[
				]
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

GET

/ad-group/servers/{pk}

그룹 매핑을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
그룹 매핑 ID (ad_grp_map_id)

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

그룹 매핑 조회 성공

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

useuse: required (one of 0, 1)
사용 여부  사용	안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 32)
이름

auth_serv_type
auth_serv_type: required (one of 1, 2)
연동 서버 타입
1:	AD
2:	LDAP

(지원버전:	2.1.0)

auth_serv_id
auth_serv_id: required (integer)
AD 연동 서버 ID

[AD 서버 목록 조회]
GET	{{url}}/api/sm/auth/ad/servers/names

interval
interval: required (integer - minimum: 1 - maximum: 1440)
연동 주기(분)

dmndmn: required (string - maxLength: 32)
도메인
영문,	숫자,	특수	문자('-',	'_')	만	허용,	공백	문자	입력	불가

grp_filter
grp_filter: (string - maxLength: 256)
그룹 객체 필터

grp_obj_class
grp_obj_class: required (string - maxLength: 32)
그룹 객체 클래스

grp_name
grp_name: required (string - maxLength: 32)
그룹 이름

grp_mem
grp_mem: required (string - maxLength: 32)
그룹 멤버

usr_filter: (string - maxLength: 256)
usr_filter
사용자 객체 필터

usr_obj_class
usr_obj_class: required (string - maxLength: 32)
사용자 객체 클래스

usr_name: required (string - maxLength: 32)
usr_name
사용자 이름

usr_status_filter
usr_status_filter: required (one of 0, 1)
사용자 상태 필터
사용안함:	0,	사용:	1

SupportedVersion:	2.0.0

ad_grp_map_id
ad_grp_map_id: required (integer)
그룹 매핑 ID(PK)

auth_serv_name
auth_serv_name: required (string)
연동 서버 이름

target_list
target_list: required (object)
LDAP 정보

group_dn
group_dn: required (string)
타겟 그룹 DN

group_name: required (string)
group_name
타겟 그룹 이름

ad_grp_map_target_id
ad_grp_map_target_id: required (integer)
타겟 ID

ad_grp_map_id
ad_grp_map_id: required (integer)
그룹 매핑 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ad_grp_map_id":	1,
				"use":	1,
				"name":	"AD	그룹	매핑	이름",
				"auth_serv_type":	1,
				"auth_serv_id":	1,
				"auth_serv_name":	"AD	연동	서버	이름",
				"interval":	1,
				"dmn":	"example_com",
				"grp_filter":	"test",
				"grp_obj_class":	"group",
				"grp_name":	"name",
				"grp_mem":	"member",
				"usr_filter":	"test",
				"usr_obj_class":	"person",
				"usr_name":	"sAMAccountName",
				"usr_status_filter":	1,
				"mmbr_obj":	[{
						"ad_grp_map_target_id":	1,
						"ad_grp_map_id":	1,
						"group_dn":	"CN=QA_Group_5,OU=qatest,DC=firewall2008,DC=fwad,DC=com",
						"group_name":	"Group_5"
				},	{
						"ad_grp_map_target_id":	2,
						"ad_grp_map_id":	1,
						"group_dn":	"CN=QA_Group_6,OU=qatest,DC=firewall2008,DC=fwad,DC=com",
						"group_name":	"Group_6"
				}]
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

dev_t: (string)
dev_t
개발용 메시지

Example:
Example

{
		"code":	"12001",
		"message":	"존재하지	않는	항목입니다."
}

PUT

/ad-group/servers/{pk}

그룹 매핑을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
그룹 매핑 ID (ad_grp_map_id)

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

useuse: required (one of 0, 1)
사용 여부  사용	안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 32)
이름

auth_serv_type
auth_serv_type: required (one of 1, 2)
연동 서버 타입
1:	AD
2:	LDAP

(지원버전:	2.1.0)

auth_serv_id
auth_serv_id: required (integer)
AD 연동 서버 ID

[AD 서버 목록 조회]
GET	{{url}}/api/sm/auth/ad/servers/names

interval
interval: required (integer - minimum: 1 - maximum: 1440)
연동 주기(분)

dmndmn: required (string - maxLength: 32)
도메인
영문,	숫자,	특수	문자('-',	'_')	만	허용,	공백	문자	입력	불가

grp_filter
grp_filter: (string - maxLength: 256)
그룹 객체 필터

grp_obj_class
grp_obj_class: required (string - maxLength: 32)
그룹 객체 클래스

grp_name
grp_name: required (string - maxLength: 32)
그룹 이름

grp_mem
grp_mem: required (string - maxLength: 32)
그룹 멤버

usr_filter
usr_filter: (string - maxLength: 256)
사용자 객체 필터

usr_obj_class
usr_obj_class: required (string - maxLength: 32)
사용자 객체 클래스

usr_name: required (string - maxLength: 32)
usr_name
사용자 이름

usr_status_filter
usr_status_filter: required (one of 0, 1)
사용자 상태 필터
사용안함:	0,	사용:	1

SupportedVersion:	2.0.0

mmbr_obj
mmbr_obj: required (object)
LDAP 정보

group_dn
group_dn: required (string)
타겟 그룹 DN

group_name
group_name: required (string)
타겟 그룹 이름

Example:
Example

{
		"use":	1,
		"name":	"AD	그룹	매핑	이름",
		"auth_serv_type":	1,
		"auth_serv_id":	1,
		"interval":	1,
		"dmn":	"example_com",
		"grp_filter":	"test",
		"grp_obj_class":	"group",
		"grp_name":	"name",
		"grp_mem":	"member",
		"usr_filter":	"test",
		"usr_obj_class":	"person",
		"usr_name":	"sAMAccountName",
		"usr_status_filter":	1,
		"mmbr_obj":	[{
				"group_dn":	"CN=QA_Group_1,OU=qatest,DC=firewall2008,DC=fwad,DC=com",
				"group_name":	"QA_Group_1"
		}]
}

Response

HTTP status code 200

그룹 매핑 수정 성공

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

useuse: required (one of 0, 1)
사용 여부  사용	안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 32)
이름

auth_serv_type
auth_serv_type: required (one of 1, 2)
연동 서버 타입
1:	AD
2:	LDAP

(지원버전:	2.1.0)

auth_serv_id
auth_serv_id: required (integer)
AD 연동 서버 ID

[AD 서버 목록 조회]
GET	{{url}}/api/sm/auth/ad/servers/names

interval
interval: required (integer - minimum: 1 - maximum: 1440)
연동 주기(분)

dmndmn: required (string - maxLength: 32)
도메인
영문,	숫자,	특수	문자('-',	'_')	만	허용,	공백	문자	입력	불가

grp_filter
grp_filter: (string - maxLength: 256)
그룹 객체 필터

grp_obj_class
grp_obj_class: required (string - maxLength: 32)
그룹 객체 클래스

grp_name
grp_name: required (string - maxLength: 32)
그룹 이름

grp_mem
grp_mem: required (string - maxLength: 32)
그룹 멤버

usr_filter: (string - maxLength: 256)
usr_filter
사용자 객체 필터

usr_obj_class
usr_obj_class: required (string - maxLength: 32)
사용자 객체 클래스

usr_name
usr_name: required (string - maxLength: 32)
사용자 이름

usr_status_filter
usr_status_filter: required (one of 0, 1)
사용자 상태 필터
사용안함:	0,	사용:	1

SupportedVersion:	2.0.0

ad_grp_map_id
ad_grp_map_id: required (integer)
그룹 매핑 ID(PK)

auth_serv_name
auth_serv_name: required (string)
연동 서버 이름

target_list: required (object)
target_list
LDAP 정보

group_dn
group_dn: required (string)
타겟 그룹 DN

group_name
group_name: required (string)
타겟 그룹 이름

ad_grp_map_target_id
ad_grp_map_target_id: required (integer)
타겟 ID

ad_grp_map_id
ad_grp_map_id: required (integer)
그룹 매핑 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ad_grp_map_id":	1,
				"use":	1,
				"name":	"AD	그룹	매핑	이름",
				"auth_serv_type":	1,
				"auth_serv_id":	1,
				"auth_serv_name":	"AD	연동	서버	이름",
				"interval":	1,
				"dmn":	"example_com",
				"grp_filter":	"test",
				"grp_obj_class":	"group",
				"grp_name":	"name",
				"grp_mem":	"member",
				"usr_filter":	"test",
				"usr_obj_class":	"person",
				"usr_name":	"sAMAccountName",
				"usr_status_filter":	1,
				"mmbr_obj":	[{
						"ad_grp_map_target_id":	1,
						"ad_grp_map_id":	1,
						"group_dn":	"CN=QA_Group_5,OU=qatest,DC=firewall2008,DC=fwad,DC=com",
						"group_name":	"Group_5"
				}]
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

DELETE

/ad-group/servers/{pk}

그룹 매핑을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
그룹 매핑 ID (ad_grp_map_id)

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

그룹 매핑 삭제 성공

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

dev_t
dev_t: (string)
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

GET

/ad-group/servers/{pk}/groups

그룹 매핑 그룹을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
그룹 매핑 ID (ad_grp_map_id)

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

Response

HTTP status code 200

그룹 매핑 그룹 조회 성공

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
result: required (array of AD 매핑 그룹)
결과 데이터

Items: AD 매핑 그룹
Items

group_name
group_name: required (string)
그룹 이름

usr_obj_type
usr_obj_type: required (integer)
사용자 객체 타입  AD	매핑	그룹:	6

usr_status_filter
usr_status_filter: required (one of 0, 1)
사용자 상태 필터
사용안함:	0,	사용:	1

refref: required (object)
참조 여부

fw_ref
fw_ref: required (one of true, false)
방화벽 정책 참조 여부

fwv6_ref
fwv6_ref: required (one of true, false)
IPv6 방화벽 정책 참조 여부

grp_ref
grp_ref: required (one of true, false)
그룹 객체 참조 여부

content_ref
content_ref: required (one of true, false)
콘텐츠 보안 참조 여부

qos_ref
qos_ref: required (one of true, false)
QoS 참조 여부

Example:
Example

{
		"fw_ref":	true,
		"fwv6_ref":	true,
		"grp_ref":	true,
		"content_ref":	true,
		"qos_ref":	true
}

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"group_name":	"grpName",
						"usr_obj_type":	6,
						"usr_status_filter":	1,
						"ref":	{
								//	상세	속성	정의	참고
						}
				}
		]
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

GET

/ad-group/servers/{pk}/groups/{group_name}/filters/{usr_status_filter}/users

그룹 매핑 사용자을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
그룹 매핑 ID (ad_grp_map_id)

group_name: required (string)
group_name
그룹 이름

usr_status_filter
usr_status_filter: required (one of 0, 1)
사용자 상태 필터
사용안함:	0,	사용:	1

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

그룹 매핑 사용자 조회 성공

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
result: required (array of AD 매핑 사용자)
결과 데이터

Items: AD 매핑 사용자
Items

user_name
user_name: required (string)
사용자 이름

usr_obj_type
usr_obj_type: required (integer)
사용자 객체 타입
AD	매핑	사용자:	5

usr_status: required (integer)
usr_status
상태
OFF:	0,	ON:	1

refref: required (object)
참조 여부

fw_ref: required (one of true, false)
fw_ref
방화벽 정책 참조 여부

fwv6_ref
fwv6_ref: required (one of true, false)
IPv6 방화벽 정책 참조 여부

grp_ref
grp_ref: required (one of true, false)
그룹 객체 참조 여부

content_ref
content_ref: required (one of true, false)
콘텐츠 보안 참조 여부

qos_ref
qos_ref: required (one of true, false)
QoS 참조 여부

Example:
Example

{
		"fw_ref":	true,
		"fwv6_ref":	true,
		"grp_ref":	true,
		"content_ref":	true,
		"qos_ref":	true
}

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"user_name":	"user1",
						"usr_obj_type":	5,
						"usr_status":	1,
						"ref":	{
								//	상세	속성	정의	참고
						}
				}
		]
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

매핑 그룹 연동, 사용자 참조 상세 정보

GET

/ad-group/types/{usr_obj_type}/names/{name}/ref

객체가 참조되고 있는 상세 항목을 조회한다.

Request

URI Parameters

usr_obj_type
usr_obj_type: required (one of 5, 6)
사용자 객체 타입  AD	매핑	사용자:	5,	AD	매핑	그룹:	6

name
name: required (string)
사용자 또는 그룹 이름

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

Response

HTTP status code 200

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

fw_ref
fw_ref: required (one of true, false)
방화벽 정책 참조 여부

fwv6_ref
fwv6_ref: required (one of true, false)
IPv6 방화벽 정책 참조 여부

grp_ref
grp_ref: required (one of true, false)
그룹 객체 참조 여부

content_ref: required (one of true, false)
content_ref
콘텐츠 보안 참조 여부

qos_ref
qos_ref: required (one of true, false)
QoS 참조 여부

fwfw: required (array of 방화벽 정책)
방화벽 정책 참조 상세 정보
fw_ref  속성이 true 일 경우 출력됨

Items: 방화벽 정책
Items

fw_set_id
fw_set_id: required (integer)
세트 ID

fw_set_name
fw_set_name: required (string)
세트명

fw_rule_id
fw_rule_id: required (integer)
정책 ID

fw_rule_name: required (string)
fw_rule_name
정책 명

is_backup
is_backup: required (integer)
백업 여부(타임라인으로 저장된 세트)
0:	정책	세트,	1:	백업	세트

SupportedVersion:	2.0.0

fwv6
fwv6: required (array of 방화벽 정책)
IPv6 방화벽 정책 참조 상세 정보
fwv6_ref  속성이 true 일 경우 출력됨

Items: 방화벽 정책
Items

fw_set_id
fw_set_id: required (integer)
세트 ID

fw_set_name
fw_set_name: required (string)
세트명

fw_rule_id
fw_rule_id: required (integer)
정책 ID

fw_rule_name
fw_rule_name: required (string)
정책 명

is_backup
is_backup: required (integer)
백업 여부(타임라인으로 저장된 세트)
0:	정책	세트,	1:	백업	세트

SupportedVersion:	2.0.0

grpgrp: required (array of 그룹 객체)
그룹 객체 참조 상세 정보
grp_ref  속성이 true 일 경우 출력됨

Items: 그룹 객체
Items

idid: required (integer)
그룹 객체 ID

name
name: required (string)
그룹 객체 이름

content
content: required (object)
콘텐츠 보안 참조 상세 정보
content_ref  속성이 true 일 경우 출력됨

sslv4
sslv4: required (array of 복호화 정책 설정)
Items: 복호화 정책 설정
Items

ssl_trfc_id
ssl_trfc_id: required (integer)
ID

sslv6
sslv6: required (array of 복호화 정책 설정)
Items: 복호화 정책 설정
Items

ssl_trfc_id
ssl_trfc_id: required (integer)
ID

ssl_excpt
ssl_excpt: required (array of 복호화 예외 목록)
Items: 복호화 예외 목록
Items

ssl_trfc_id
ssl_trfc_id: required (integer)
ID

wfwf: required (array of 웹 필터)
Items: 웹 필터
Items

wf_prf_id
wf_prf_id: required (integer)
프로파일 ID

name
name: required (string)
프로파일 이름

dlpdlp: required (array of DLP 예외 프로파일)
Items: DLP 예외 프로파일
Items

dlp_excpt_prf_id
dlp_excpt_prf_id: required (integer)
DLP 예외 프로파일 ID

name
name: required (string)
DLP 예외 프로파일 이름

filetype
filetype: required (array of 파일 유형 제어 프로파일)
Items: 파일 유형 제어 프로파일
Items

file_type_id
file_type_id: required (integer)
파일 유형 제어 프로파일 ID

name
name: required (string)
파일 유형 제어 프로파일 이름

qosqos: required (array of QoS)
QoS 참조 상세 정보
qos_ref  속성이 true 일 경우 출력됨

Items: QoS
Items

qos_prf_id
qos_prf_id: required (integer)
QoS 프로파일 ID(PK)

qos_prf_name
qos_prf_name: required (string)
QoS 프로파일 이름

qos_class_id: required (integer)
qos_class_id
QoS 큐 ID

qos_class_name
qos_class_name: required (string)
QoS 큐 이름

Example:
Example

{
		"fw_ref":	true,
		"fwv6_ref":	true,
		"grp_ref":	true,
		"content_ref":	true,
		"qos_ref":	true,
		"fw":	[{"fw_set_id":	1,	"fw_set_name":	"test_set",	"fw_rule_id":	2,	"fw_rule_name":	"test_rule"}],
		"fwv6":	[{"fw_set_id":	1,	"fw_set_name":	"test_set",	"fw_rule_id":	2,	"fw_rule_name":	"test_rule"}],
		"grp":	[{"id":	1,	"name":	"test_grp"}],
		"content":	{
				"sslv4":	[{"ssl_trfc_id":	1}],
				"sslv6":	[{"ssl_trfc_id":	1}],
				"ssl_excpt":	[{"ssl_trfc_id":	1}],
				"wf":	[{"wf_prf_id":	1,	"name":	"test"}],
				"dlp":	[{"dlp_excpt_prf_id":	1,	"name":	"test"}],
				"filetype":	[{"file_type_id":	1,	"name":	"test"}]
		},
		"qos":	[{"qos_prf_id":	1,	"qos_prf_name":	"test_prf",	"qos_class_id":	2,	"qos_class_name":	"test_rule"}]
}

Example:
Example

{
		"code":	"ok",
		"result":	{
				//	상세	속성	정의	참고
		}
}

AD 서버 연결 테스트(AD 설정 마법사)

POST

/ad/connect/server

AD 서버 연결 테스트를 실행한다.

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

servers
servers: required (array of AdServer)
AD 서버 목록

Items: AdServer
Items

ipip: required (string - maxLength: 255)

서버 주소(IPv4)

portport: required (integer - default: 389 - minimum: 0 - maximum: 65535)
서버 포트

adad: required (object)
접속 정보

conn_type
conn_type: required (one of 0, 1, 2)
보안 연결
(NONE:	0,	LDAPS:	1,	Start	TLS:	2)

base_dn
base_dn: required (string - maxLength: 128)
Base DN

bind_dn
bind_dn: required (string - maxLength: 128)
Bind DN

passwd: required (string - maxLength: 128)
passwd
패스워드(Base64 인코딩)

Example:
Example

{
		"ad":	{
				"conn_type":	0,
				"base_dn":	"dc=firewall2008,dc=fwad,dc=com",
				"bind_dn":	"administrator@firewall2008.fwad.com",
				"passwd":	"cWhka3MwMCEh"
		},
		"servers":	[
				{"ip":	"10.10.10.10",	"port":	389}
		]
}

Response

HTTP status code 200

AD 서버 연결 테스트 추가 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of GetLdap)
result
결과 데이터
HTTP 200 OK 이면 연결 성공, 그외 400 Bad Request면 연결 실패로 판단

Items: GetLdap
Items

type: required (string)
type
타입

idid: required (string)
ID

dndn: required (string)
DN

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"type":	"container",
						"id":	"Computers",
						"dn":	"CN=Computers\tDC=firewall2008\tDC=fwad\tDC=com"
				}
		]
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

그룹 매핑 연동 적용/취소

PUT

/command/ad-group-servers/apply

그룹 매핑 연동을 적용합니다.

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

그룹 매핑 연동 적용 성공

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

PUT

/command/ad-group-servers/cancel

그룹 매핑 연동을 취소합니다.

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

그룹 매핑 연동 취소 성공

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

