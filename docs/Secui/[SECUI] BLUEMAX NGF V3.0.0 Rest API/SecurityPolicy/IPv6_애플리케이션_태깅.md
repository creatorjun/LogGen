GET

POST

PUT

  DELETE

GET

PUT

  DELETE

PUT

PUT

IPv6 애플리케이션 태깅 REST API 문서

https://{url}/api/po

urlurl: required (string)
장비 IP:Port

IPv6 애플리케이션 태깅

/app-tagging/6/policies

/app-tagging/6/policies/{pk}

IPv6 애플리케이션 태깅 정책 설정 적용/취소

/command/app-tagging-6-policies/apply

/command/app-tagging-6-policies/cancel

IPv6 애플리케이션 태깅

GET

/app-tagging/6/policies

애플리케이션 태깅 목록을 조회한다.

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

애플리케이션 태깅 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: array of GetAppTaggingPolicy

Items: GetAppTaggingPolicy
Items

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

name: required (string - minLength: 1 - maxLength: 31)
name
앱 태깅 정책 이름

descdesc: (string - maxLength: 128)
설명

app_tag_rule_id
app_tag_rule_id: required (integer)
애플리케이션 태깅 정책 ID

seqseq: required (integer)
순번

srcsrc: required (array of ADDRESS_OBJ)
출발지 객체 목록

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체 이름 (ANY:	Any)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

dstdst: required (array of ADDRESS_OBJ)
목적지 객체 목록

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name: required (string)
name
객체 이름 (ANY:	Any)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type: required (integer)
addr_obj_type
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

srvsrv: required (array of SERVICE_OBJ)
서비스 객체 목록

Items: SERVICE_OBJ
Items

srv_obj_id: required (integer)
srv_obj_id
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

appapp: required (array of APPLICATION_OBJ)
애플리케이션 객체 목록

Items: APPLICATION_OBJ
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

name
name: required (integer)
애플리케이션 객체 이름

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"app_tag_rule_id":	1,
				"use":	1,
				"seq":	1,
				"name":	"애플리케이션	태깅	정책	이름",
				"desc":	"애플리케이션	태깅	정책	설명",
				"src":	[{
						"addr_obj_id":	1,
						"ip_ver":	2,
						"name":	"test_host_obj_1",
						"zone":	2,
						"addr_obj_type":	1,
						"excpt":	0
				}],
				"dst":	[{
						"addr_obj_id":	0,
						"ip_ver":	3,
						"name":	"Any",
						"zone":	0,
						"addr_obj_type":	0,
						"excpt":	0
				}],
				"srv":	[{
						"srv_obj_id":	7,
						"srv_obj_type":	1,
						"name":	"BOOTP",
						"pre_def":	1
				}],
				"app":	[																	{
								"app_obj_id":	31065,
								"name":	"0zz0-base"
				}]
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
		"dev_t":	"Authentication	Error"
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"dev_t":	"Authentication	Error",
		"message":	"인가되지	않은	API	요청입니다."
}

POST

/app-tagging/6/policies

애플리케이션 태깅를 추가한다.

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

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 31)
앱 태깅 정책 이름

descdesc: (string - maxLength: 128)
설명

pre_rule_id
pre_rule_id: (integer)
순번 설정의 기준이 될 아이디

up_down
up_down: (integer)
순번 설정시 pre_rule_id 기준 위인지 아래인지 설정(NULL 입력 시 위)
위:	1,	아래:	2

srcsrc: required (array of SetAddrObject)
출발지 객체 목록

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID(ANY: 0)

excpt
excpt: required (one of 0, 1)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

Example:
Example

[{"addr_obj_id":	1,	"excpt":	0}]

dstdst: required (array of SetAddrObject)
목적지 객체 목록

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID(ANY: 0)

excpt
excpt: required (one of 0, 1)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

Example:
Example

[{"addr_obj_id":	1,	"excpt":	0}]

srvsrv: required (array of SetServiceObject)
서비스 객체 목록

Items: SetServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID(ANY: 0)

Example:
Example

[{"srv_obj_id":	1}]

appapp: required (array of SetAppObject)
앱 객체 목록

Items: SetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

Example:
Example

[{"app_obj_id":	31000}]

Example:
Example

{
		"use":	1,
		"name":	"New	애플리케이션	태깅	정책	이름",
		"desc":	"New	애플리케이션	태깅	정책	설명",
		"src":	[
				{"addr_obj_id":	1,	"excpt":0}
		],
		"dst":	[
				{"addr_obj_id":	0,	"excpt":0}
		],
		"srv":	[
				{"srv_obj_id":	1}
		],
		"app":	[
				{"app_obj_id":	31065}
		]
}

Response

HTTP status code 200

애플리케이션 태깅 추가 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 31)
앱 태깅 정책 이름

descdesc: (string - maxLength: 128)
설명

app_tag_rule_id
app_tag_rule_id: required (integer)
애플리케이션 태깅 정책 ID

seqseq: required (integer)
순번

srcsrc: required (array of ADDRESS_OBJ)
출발지 객체 목록

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체 이름 (ANY:	Any)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

dstdst: required (array of ADDRESS_OBJ)
목적지 객체 목록

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체 이름 (ANY:	Any)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

srvsrv: required (array of SERVICE_OBJ)
서비스 객체 목록

Items: SERVICE_OBJ
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

appapp: required (array of APPLICATION_OBJ)
애플리케이션 객체 목록

Items: APPLICATION_OBJ
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

name
name: required (integer)
애플리케이션 객체 이름

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

Example:
Example

{
		"code":	"ok",
		"result":	{
				"app_tag_rule_id":	2,
				"use":	1,
				"seq":	1,
				"name":	"New	애플리케이션	태깅	정책	이름",
				"desc":	"New	애플리케이션	태깅	정책	설명",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-08-02	09:08:35",
				"src":	[{
						"addr_obj_id":	1,
						"ip_ver":	2,
						"name":	"IH_OBJECT_1",
						"zone":	1,
						"addr_obj_type":	1,
						"excpt":	0
				}],
				"dst":	[{
						"addr_obj_id":	0,
						"ip_ver":	3,
						"name":	"Any",
						"zone":	0,
						"addr_obj_type":	0,
						"excpt":	0
				}],
				"srv":	[{
						"srv_obj_id":	1,
						"srv_obj_type":	1,
						"name":	"AH",
						"pre_def":	1
				}],
				"app":	[{
						"app_obj_id":	31065,
						"name":	"0zz0-base"
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

PUT

/app-tagging/6/policies

애플리케이션 태깅 목록을 (일괄)수정한다.

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
items
items: required (array of object)
수정될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"app_tag_rule_id":	1,	"use":	0},
				{"app_tag_rule_id":	2,	"use":	0}
		]
}

Response

HTTP status code 200

애플리케이션 태깅 목록 수정 성공

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

/app-tagging/6/policies

애플리케이션 태깅 목록을 (일괄)삭제한다.

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
items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"app_tag_rule_id":	1},
				{"app_tag_rule_id":	2}
		]
}

Response

HTTP status code 200

애플리케이션 태깅 목록 삭제 성공

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

/app-tagging/6/policies/{pk}

애플리케이션 태깅을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
애플리케이션 태깅 정책 ID

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

애플리케이션 태깅 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 31)
앱 태깅 정책 이름

descdesc: (string - maxLength: 128)
설명

app_tag_rule_id
app_tag_rule_id: required (integer)
애플리케이션 태깅 정책 ID

seqseq: required (integer)
순번

srcsrc: required (array of ADDRESS_OBJ)

출발지 객체 목록

Items: ADDRESS_OBJ
Items

addr_obj_id: required (integer)
addr_obj_id
객체 ID (ANY:	0)

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체 이름 (ANY:	Any)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

dstdst: required (array of ADDRESS_OBJ)
목적지 객체 목록

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체 이름 (ANY:	Any)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

srvsrv: required (array of SERVICE_OBJ)
서비스 객체 목록

Items: SERVICE_OBJ
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

appapp: required (array of APPLICATION_OBJ)
애플리케이션 객체 목록

Items: APPLICATION_OBJ
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

name: required (integer)
name
애플리케이션 객체 이름

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm: required (string)
cfg_adm
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

Example:
Example

{
		"code":	"ok",
		"result":	{
				"app_tag_rule_id":	2,
				"use":	1,
				"seq":	1,
				"name":	"애플리케이션	태깅	정책	이름",
				"desc":	"애플리케이션	태깅	정책	설명",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-08-02	09:08:35",
				"src":	[{
						"addr_obj_id":	1,
						"ip_ver":	2,
						"name":	"IH_OBJECT_1",
						"zone":	1,
						"addr_obj_type":	1,
						"excpt":	0
				}],
				"dst":	[{
						"addr_obj_id":	0,
						"ip_ver":	3,
						"name":	"Any",
						"zone":	0,
						"addr_obj_type":	0,
						"excpt":	0
				}],
				"srv":	[{
						"srv_obj_id":	1,
						"srv_obj_type":	1,
						"name":	"AH",
						"pre_def":	1
				}],
				"app":	[{
						"app_obj_id":	31065,
						"name":	"0zz0-base"
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

/app-tagging/6/policies/{pk}

애플리케이션 태깅을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
애플리케이션 태깅 정책 ID

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

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 31)
앱 태깅 정책 이름

descdesc: (string - maxLength: 128)
설명

pre_rule_id: (integer)
pre_rule_id
순번 설정의 기준이 될 아이디

up_down
up_down: (integer)
순번 설정시 pre_rule_id 기준 위인지 아래인지 설정(NULL 입력 시 위)
위:	1,	아래:	2

srcsrc: required (array of SetAddrObject)
출발지 객체 목록

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID(ANY: 0)

excpt
excpt: required (one of 0, 1)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

Example:
Example

[{"addr_obj_id":	1,	"excpt":	0}]

dstdst: required (array of SetAddrObject)
목적지 객체 목록

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID(ANY: 0)

excpt
excpt: required (one of 0, 1)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

Example:
Example

[{"addr_obj_id":	1,	"excpt":	0}]

srvsrv: required (array of SetServiceObject)
서비스 객체 목록

Items: SetServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID(ANY: 0)

Example:
Example

[{"srv_obj_id":	1}]

appapp: required (array of SetAppObject)
앱 객체 목록

Items: SetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

Example:
Example

[{"app_obj_id":	31000}]

Example:
Example

{
		"use":	1,
		"name":	"애플리케이션	태깅	정책	이름",
		"desc":	"애플리케이션	태깅	정책	설명",
		"src":	[
				{"addr_obj_id":	1,	"excpt":0}
		],
		"dst":	[
				{"addr_obj_id":	0,	"excpt":0}
		],
		"srv":	[
				{"srv_obj_id":	1}
		],
		"app":	[
				{"app_obj_id":	31065}
		]
}

Response

HTTP status code 200

애플리케이션 태깅 수정 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 31)
앱 태깅 정책 이름

descdesc: (string - maxLength: 128)
설명

app_tag_rule_id: required (integer)
app_tag_rule_id
애플리케이션 태깅 정책 ID

seqseq: required (integer)
순번

srcsrc: required (array of ADDRESS_OBJ)
출발지 객체 목록

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

ip_ver: required (integer)
ip_ver
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체 이름 (ANY:	Any)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

excpt: required (integer)
excpt

예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

dstdst: required (array of ADDRESS_OBJ)
목적지 객체 목록

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체 이름 (ANY:	Any)

zone: required (integer)
zone
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

srvsrv: required (array of SERVICE_OBJ)
서비스 객체 목록

Items: SERVICE_OBJ
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type: required (integer)
srv_obj_type
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

appapp: required (array of APPLICATION_OBJ)
애플리케이션 객체 목록

Items: APPLICATION_OBJ
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

name
name: required (integer)
애플리케이션 객체 이름

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

Example:
Example

{
		"code":	"ok",
		"result":	{
				"app_tag_rule_id":	2,
				"use":	1,
				"seq":	1,
				"name":	"애플리케이션	태깅	정책	이름",
				"desc":	"애플리케이션	태깅	정책	설명",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-08-02	09:08:35",
				"src":	[{
						"addr_obj_id":	1,
						"ip_ver":	2,
						"name":	"IH_OBJECT_1",
						"zone":	1,
						"addr_obj_type":	1,
						"excpt":	0
				}],
				"dst":	[{
						"addr_obj_id":	0,
						"ip_ver":	3,
						"name":	"Any",
						"zone":	0,
						"addr_obj_type":	0,
						"excpt":	0
				}],
				"srv":	[{
						"srv_obj_id":	1,
						"srv_obj_type":	1,
						"name":	"AH",
						"pre_def":	1
				}],
				"app":	[{
						"app_obj_id":	31065,
						"name":	"0zz0-base"
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

/app-tagging/6/policies/{pk}

애플리케이션 태깅을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
애플리케이션 태깅 정책 ID

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

애플리케이션 태깅 삭제 성공

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

IPv6 애플리케이션 태깅 정책 설정 적용/취소

PUT

/command/app-tagging-6-policies/apply

IPv6 애플리케이션 태깅 정책을 적용합니다.

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

IPv6 애플리케이션 태깅 정책 적용 성공

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

/command/app-tagging-6-policies/cancel

IPv6 애플리케이션 태깅 정책을 취소합니다.

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

Body

Media type: application/json
Media type

TypeType: object

Example:
Example

{}

Response

HTTP status code 200

IPv6 애플리케이션 태깅 정책 취소 성공

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

