IPv6 NAT 정책 설정 REST API 문서

https://{url}/api/po

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/po

NAT 세트

/nat6/sets

/nat6/sets/{pk}

/nat6/sets/{pk}/use

/nat6/sets/{pk}/tempsave

/nat6/sets/tempsave

NAT 그룹

/nat6/groups

/nat6/groups/{pk}

IPv6 NAT 정책

/nat6/rules

/nat6/rules/{pk}

/nat6/rules/save

/nat6/rules/batch

IPv6 NAT 정책 목록 이동

/nat6/move/rules

정책 내용 검색

/nat6/content-rules/search

Shadow 정책 검색

/nat6/shadow-rules/search

적용 정책 검색

/nat6/apply-rules/search

미참조 정책 검색

/nat6/unuse-rules/search

미참조 객체 검색

/nat6/unuse-objects/search/days/{day}

적용 인터페이스

/nat6/interfaces

적용 인터페이스(멀티라인)

/nat6/multiline/interfaces

GET

POST

PUT

  DELETE

PUT

POST

GET

GET

POST

GET

PUT

  DELETE

GET

GET

POST

  DELETE

PUT

  DELETE

GET

POST

PUT

POST

POST

POST

POST

GET

GET

GET

PUT

PUT

IPv6 NAT 정책 설정 적용/취소

/command/nat6-policies/apply

/command/nat6-policies/cancel

NAT 세트

GET

/nat6/sets

NAT 세트 목록을 조회한다.

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

NAT 세트 목록 조회 성공

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
result: required (array of GetNatSet)
결과 데이터

Items: GetNatSet
Items

name
name: required (string - maxLength: 32)
세트 이름

nat_set_id
nat_set_id: required (integer)
NAT 세트 ID(PK)

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm: required (string)
cfg_adm

관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

apply: required (integer)
apply
현재 적용 중인 세트 여부
적용	정책:	1,	적용	정책	아님:	0

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"nat_set_id":	1,
				"use":	1,
				"name":	"default",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-08	12:23:23",
				"apply":	1
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
		"dev_t":	"Authentication	Error"
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"dev_t":	"Authentication	Error",
		"message":	"인가되지	않은	API	요청입니다."
}

POST

/nat6/sets

(새로 만들기) NAT 세트를 추가한다.

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
name
name: required (string - maxLength: 32)
세트 이름

Example:
Example

{
		"name":	"New	세트	이름"
}

Response

HTTP status code 200

NAT 세트 추가 성공

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

name
name: required (string - maxLength: 32)
세트 이름

nat_set_id
nat_set_id: required (integer)
NAT 세트 ID(PK)

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt: required (string)
cfg_dt
수정 날짜

apply
apply: required (integer)
현재 적용 중인 세트 여부
적용	정책:	1,	적용	정책	아님:	0

Example:
Example

{
		"code":	"ok",
		"result":	{
				"nat_set_id":	2,
				"use":	0,
				"name":	"New	세트	이름",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-08	12:23:23",
				"apply":	0
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

/nat6/sets/{pk}

(다른 이름으로 저장) NAT 세트를 수정한다.

Request

URI Parameters

pkpk: required (integer)
세트 ID (nat_set_id)

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

nat_set_new_name
nat_set_new_name: required (string - maxLength: 32)
세트 이름

Example:
Example

{
		"nat_set_new_name":	"변경된	세트	이름"
}

Response

HTTP status code 200

NAT 세트 수정 성공

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

name
name: required (string - maxLength: 32)
세트 이름

nat_set_id: required (integer)
nat_set_id
NAT 세트 ID(PK)

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

cfg_adm_id: required (integer)
cfg_adm_id
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

apply
apply: required (integer)
현재 적용 중인 세트 여부
적용	정책:	1,	적용	정책	아님:	0

Example:
Example

{
		"code":	"ok",
		"result":	{
				"nat_set_id":	2,
				"use":	1,
				"name":	"변경된	세트	이름",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-08	12:23:23",
				"apply":	0
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

/nat6/sets/{pk}

NAT 세트을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
세트 ID (nat_set_id)

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

NAT 세트 삭제 성공

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

PUT

/nat6/sets/{pk}/use

(열기) NAT 세트를 수정한다.

Request

URI Parameters

pkpk: required (integer)
세트 ID( nat_set_id )

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

NAT 세트 수정 성공

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

name
name: required (string - maxLength: 32)
세트 이름

nat_set_id
nat_set_id: required (integer)
NAT 세트 ID(PK)

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

cfg_adm_id: required (integer)
cfg_adm_id
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

apply
apply: required (integer)
현재 적용 중인 세트 여부
적용	정책:	1,	적용	정책	아님:	0

Example:
Example

{
		"code":	"ok",
		"result":	{
				"nat_set_id":	1,
				"use":	1,
				"name":	"세트	이름",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-08	12:23:23",
				"apply":	0
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

dev_t: (string)
dev_t
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

/nat6/sets/{pk}/tempsave

임시저장을 한다.

Request

URI Parameters

pkpk: required (integer)
세트 ID (nat_set_id)

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

임시 저장 추가 성공

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

name
name: required (string - maxLength: 32)
세트 이름

nat_set_id
nat_set_id: required (integer)
NAT 세트 ID(PK)

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

apply
apply: required (integer)
현재 적용 중인 세트 여부
적용	정책:	1,	적용	정책	아님:	0

Example:
Example

{
		"code":	"ok",
		"result":	{
				"nat_set_id":	2,
				"use":	0,
				"name":	"test_rule",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-08	12:23:23",
				"apply":	0
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

GET

/nat6/sets/tempsave

임시저장 상태를 조회한다.

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

임시 저장 여부 확인 조회 성공

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
임시 저장된 경우에 임시 저장된 세트 정보가 출력됩니다.

name
name: required (string - maxLength: 32)
세트 이름

nat_set_id
nat_set_id: required (integer)
NAT 세트 ID(PK)

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

apply
apply: required (integer)
현재 적용 중인 세트 여부
적용	정책:	1,	적용	정책	아님:	0

Example:
Example

{
		"code":	"ok",
		"result":	{
				"nat_set_id":	2,
				"use":	1,
				"name":	"temp_rule",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-08	12:23:23",
				"apply":	0
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

NAT 그룹

GET

/nat6/groups

NAT 그룹 목록을 조회한다.

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

Response

HTTP status code 200

NAT 그룹 목록 조회 성공

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
result: required (array of GetNatGroup)
결과 데이터

Items: GetNatGroup
Items

name: required (string - minLength: 1 - maxLength: 32)
name
그룹 이름

descdesc: (string - maxLength: 128)
그룹 설명

pre_grp_id
pre_grp_id: (integer)
이동하려는 정책 그룹 ID
이동	기능에서	사용

up_down
up_down: (integer)
기준이 되는 정책 그룹의 위/아래
위:	1,	아래:	2
이동	기능에서	사용

nat_set_id: required (integer)
nat_set_id
세트 ID

nat_grp_id
nat_grp_id: required (integer)
그룹 ID(PK)

seqseq: required (integer)
순번

rule_cnt
rule_cnt: required (integer)
그룹에 할당된 룰 갯수

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
		"result":	[{
				"nat_set_id":	1,
				"nat_grp_id":	1,
				"seq":	1,
				"name":	"default",
				"rule_cnt":	0,
				"desc":	"",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-09	00:48:33"
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
		"dev_t":	"Authentication	Error"
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"dev_t":	"Authentication	Error",
		"message":	"인가되지	않은	API	요청입니다."
}

POST

/nat6/groups

NAT 그룹를 추가한다.

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
name
name: required (string - minLength: 1 - maxLength: 32)
그룹 이름

descdesc: (string - maxLength: 128)
그룹 설명

pre_grp_id
pre_grp_id: (integer)
이동하려는 정책 그룹 ID
이동	기능에서	사용

up_down: (integer)
up_down

기준이 되는 정책 그룹의 위/아래
위:	1,	아래:	2
이동	기능에서	사용

Example:
Example

{
		"name":	"New	그룹	이름",
		"desc":	"New	그룹	설명"
}

Response

HTTP status code 200

NAT 그룹 추가 성공

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

name
name: required (string - minLength: 1 - maxLength: 32)
그룹 이름

descdesc: (string - maxLength: 128)
그룹 설명

pre_grp_id
pre_grp_id: (integer)
이동하려는 정책 그룹 ID
이동	기능에서	사용

up_down
up_down: (integer)
기준이 되는 정책 그룹의 위/아래
위:	1,	아래:	2
이동	기능에서	사용

nat_set_id: required (integer)
nat_set_id
세트 ID

nat_grp_id
nat_grp_id: required (integer)
그룹 ID(PK)

seqseq: required (integer)
순번

rule_cnt
rule_cnt: required (integer)
그룹에 할당된 룰 갯수

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
				"nat_set_id":	1,
				"nat_grp_id":	2,
				"seq":	2,
				"name":	"New	그룹	이름",
				"desc":	"New	그룹	설명",
				"rule_cnt":	0,
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-09	00:48:33"
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

GET

/nat6/groups/{pk}

NAT 그룹을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
그룹 ID (nat_grp_id)

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

NAT 그룹 조회 성공

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

name: required (string - minLength: 1 - maxLength: 32)
name
그룹 이름

descdesc: (string - maxLength: 128)
그룹 설명

pre_grp_id
pre_grp_id: (integer)
이동하려는 정책 그룹 ID
이동	기능에서	사용

up_down
up_down: (integer)
기준이 되는 정책 그룹의 위/아래
위:	1,	아래:	2
이동	기능에서	사용

nat_set_id
nat_set_id: required (integer)
세트 ID

nat_grp_id
nat_grp_id: required (integer)
그룹 ID(PK)

seqseq: required (integer)
순번

rule_cnt
rule_cnt: required (integer)
그룹에 할당된 룰 갯수

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
				"nat_set_id":	1,
				"nat_grp_id":	1,
				"seq":	2,
				"name":	"그룹	이름",
				"desc":	"그룹	설명",
				"rule_cnt":	100,
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-09	00:48:33"
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

/nat6/groups/{pk}

NAT 그룹를 수정 또는 이동한다.

Request

URI Parameters

pkpk: required (integer)
그룹 ID (nat_grp_id)

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

pre_grp_id
pre_grp_id: required (integer)
이동하려는 정책 그룹 ID
이동	기능에서	사용

up_down
up_down: required (integer)
기준이 되는 정책 그룹의 위/아래
위:	1,	아래:	2
이동	기능에서	사용

name
name: required (string - minLength: 1 - maxLength: 32)
그룹 이름

descdesc: (string - maxLength: 128)
그룹 설명

Example:
Example

{
		"name":	"변경된	그룹	이름",
		"desc":	"변경된	그룹	설명",
		"pre_grp_id":	1,
		"up_down":	2
}

Response

HTTP status code 200

NAT 그룹 수정 성공

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

name
name: required (string - minLength: 1 - maxLength: 32)
그룹 이름

descdesc: (string - maxLength: 128)
그룹 설명

pre_grp_id
pre_grp_id: (integer)
이동하려는 정책 그룹 ID
이동	기능에서	사용

up_down
up_down: (integer)
기준이 되는 정책 그룹의 위/아래
위:	1,	아래:	2
이동	기능에서	사용

nat_set_id
nat_set_id: required (integer)
세트 ID

nat_grp_id
nat_grp_id: required (integer)
그룹 ID(PK)

seqseq: required (integer)
순번

rule_cnt
rule_cnt: required (integer)
그룹에 할당된 룰 갯수

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt: required (string)
cfg_dt
수정 날짜

Example:
Example

{
		"code":	"ok",
		"result":	{
				"nat_set_id":	1,
				"nat_grp_id":	2,
				"seq":	2,
				"name":	"그룹	이름",
				"desc":	"그룹	설명",
				"rule_cnt":	0,
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-09	00:48:33"
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

dev_t: (string)
dev_t
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

DELETE

/nat6/groups/{pk}

NAT 그룹을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
그룹 ID (nat_grp_id)

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

NAT 그룹 삭제 성공

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

message: required (string)
message
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

IPv6 NAT 정책

GET

/nat6/rules

IPv6 NAT 정책 목록을 조회한다.

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

Response

HTTP status code 200

IPv6 NAT 정책 목록 조회 성공

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
result: required (array of GetNatRuleList)
결과 데이터

Items: GetNatRuleList
Items

nat_grp_id
nat_grp_id: required (integer)
그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
정책 설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

basic_nat_mode
basic_nat_mode: required (integer)
기본 변환 방식
기본	변환	방식
1:1	변환:	2
N:M	변환(IP	POOL):	7
N:M	변환(PORT	POOL):	11
1:N	변환:	20
예외:	16

adv_nat_mode
adv_nat_mode: required (integer)
고급 변환 방식
1:1	확장변환:	3
1:1	동시변환:	4
1:1	단방향	확장변환:	5
1:1	단방향	동시변환:	6
N:M	확장변환(IP	POOL):	8
N:M	동시변환(IP	POOL):	10
N:M	확장변환(PORT	POOL):	12
N:M	동적할당(PORT	POOL):	13
N:M	멀티라인(PORT	POOL):	14
N:M	동시변환(PORT	POOL):	15
1:N	확장변환:	21
1:N	동적변환:	22
예외:	17
예외-단방향:	19

serv_sched: required (one of 0, 1, 2, 3, 4)
serv_sched
서버 스케쥴링 방식
비활성:	0,	라운드로빈:	1,	가중치	기반	라운드로빈:	2,	해싱:	3

serv_check
serv_check: required (one of 0, 1)
서버 상태 검사
사용	안함:	0,	사용:	1

nat_rule_id: required (integer)
nat_rule_id
정책 ID

seqseq: required (integer)
순번

srcsrc: required (array of ADDRESS_OBJ)
변경 전 출발지

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver: required (integer)
ip_ver
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list: (array of any)
ip_list
객체 별 IP 목록

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

dstdst: required (array of ADDRESS_OBJ)
변경 전 목적지

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list
ip_list: (array of any)
객체 별 IP 목록

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

srvsrv: required (array of SERVICE_OBJ)
변경 전 서비스

Items: SERVICE_OBJ
Items

srv_obj_id: required (integer)
srv_obj_id
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2

name: required (string)
name
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

prtcprtc: (object)
프로토콜 정보

srv_cate
srv_cate: (integer)
서비스 유형

start_port
start_port: (string)
출발지 포트

srv_port
srv_port: (string)
서비스 포트

life_time
life_time: (integer)
Lifetime(초)

prioprio: (integer)
우선 순위

descdesc: (string)
객체 설명

act_src
act_src: required (array of ADDRESS_OBJ)
변경 후 출발지

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver: required (integer)
ip_ver
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list: (array of any)
ip_list
객체 별 IP 목록

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

act_dst
act_dst: required (array of ADDRESS_OBJ)
변경 후 목적지

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type: required (integer)
addr_obj_type
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list
ip_list: (array of any)
객체 별 IP 목록

excpt: (integer)
excpt

예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

act_srv
act_srv: required (array of SERVICE_OBJ)
변경 후 서비스

Items: SERVICE_OBJ
Items

srv_obj_id: required (integer)
srv_obj_id
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2

name: required (string)
name
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

prtcprtc: (object)
프로토콜 정보

srv_cate
srv_cate: (integer)
서비스 유형

start_port
start_port: (string)
출발지 포트

srv_port
srv_port: (string)
서비스 포트

life_time
life_time: (integer)
Lifetime(초)

prioprio: (integer)
우선 순위

descdesc: (string)
객체 설명

ifcifc: required (array of GetInterface)
적용 인터페이스

Items: GetInterface
Items

ifc_name
ifc_name: required (string)
인터페이스 이름

rolerole: required (one of 0, 1)
역할(N:M 멀티라인-Port Pool 일 경우 전달 속성)
Active:	0,	Standby:	1

prioprio: (integer)
Standby 우선 순위(N:M 멀티라인-Port Pool 일 경우 전달 속성)

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"nat_set_id":	1,
						"nat_grp_id":	1,
						"seq":	1,
						"name":	"default",
						"rule_cnt":	1,
						"desc":	"",
						"cfg_adm_id":	0,
						"cfg_adm":	"",
						"cfg_dt":	"2019-01-11	12:09:58",
						"is_group":	true
				},
				{
						"nat_set_id":	1,
						"nat_grp_id":	1,
						"nat_rule_id":	1,
						"name":	"정책	이름",
						"desc":	"정책	설명",
						"seq":	1,
						"use":	1,
						"basic_nat_mode":	1,
						"adv_nat_mode":	null,
						"serv_sched":	0,
						"serv_check":	0,
						"src":	[{
								"addr_obj_id":	106,
								"ip_ver":	1,
								"name":	"test_host_obj_1",
								"zone":	1,
								"addr_obj_type":	1,
								"excpt":	0
						}],
						"dst":	[{
								"addr_obj_id":	106,
								"ip_ver":	1,
								"name":	"test_host_obj_1",
								"zone":	1,
								"addr_obj_type":	1,
								"excpt":	0
						}],
						"srv":	[{
								"srv_obj_id":	1,
								"srv_obj_type":	1,
								"name":	"AH",
								"pre_def":	1
						}],
						"act_src":	[{
								"addr_obj_id":	106,
								"ip_ver":	1,
								"name":	"test_host_obj_1",
								"zone":	1,
								"addr_obj_type":	1,
								"excpt":	0
						}],
						"act_dst":	[{
								"addr_obj_id":	106,
								"ip_ver":	1,
								"name":	"test_host_obj_1",
								"zone":	1,
								"addr_obj_type":	1,
								"excpt":	0
						}],
						"act_srv":	[{
								"srv_obj_id":	1,
								"srv_obj_type":	1,
								"name":	"AH",
								"pre_def":	1
						}],
						"ifc":	[]
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
		"dev_t":	"Authentication	Error"
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"dev_t":	"Authentication	Error",
		"message":	"인가되지	않은	API	요청입니다."
}

POST

/nat6/rules

IPv6 NAT 정책를 추가한다.

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

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties

nat_grp_id
nat_grp_id: required (integer)
그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
정책 설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

basic_nat_mode
basic_nat_mode: required (integer)
기본 변환 방식
기본	변환	방식
1:1	변환:	2
N:M	변환(IP	POOL):	7
N:M	변환(PORT	POOL):	11
1:N	변환:	20
예외:	16

adv_nat_mode
adv_nat_mode: required (integer)
고급 변환 방식
1:1	확장변환:	3
1:1	동시변환:	4
1:1	단방향	확장변환:	5
1:1	단방향	동시변환:	6
N:M	확장변환(IP	POOL):	8
N:M	동시변환(IP	POOL):	10

N:M	확장변환(PORT	POOL):	12
N:M	동적할당(PORT	POOL):	13
N:M	멀티라인(PORT	POOL):	14
N:M	동시변환(PORT	POOL):	15
1:N	확장변환:	21
1:N	동적변환:	22
예외:	17
예외-단방향:	19

serv_sched
serv_sched: required (one of 0, 1, 2, 3, 4)
서버 스케쥴링 방식
비활성:	0,	라운드로빈:	1,	가중치	기반	라운드로빈:	2,	해싱:	3

serv_check
serv_check: required (one of 0, 1)
서버 상태 검사
사용	안함:	0,	사용:	1

pre_rule_id: (integer)
pre_rule_id
기준이 되는 정책 ID
이동	기능에서	사용

up_down
up_down: (integer - default: 1)
기준이 되는 정책의 위/아래 위치 지정
위:	1,	아래:	2
이동	기능에서	사용

srcsrc: required (array of SetAddrObject)
변경 전 출발지(객체 목록)

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

weight: (integer)
weight
가중치
고급	-	1:N	확장	변환에서	옵션의	가중치	기반	라운드	로빈	설정에서	사용됨

Example:
Example

[{"addr_obj_id":	1,	"excpt":	0}]

::ANY::
[{"addr_obj_id":	0,	"excpt":	0}]

dstdst: required (array of SetAddrObject)
변경 전 목적지(객체 목록)

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

weight
weight: (integer)
가중치
고급	-	1:N	확장	변환에서	옵션의	가중치	기반	라운드	로빈	설정에서	사용됨

Example:
Example

[{"addr_obj_id":	1,	"excpt":	0}]

::ANY::
[{"addr_obj_id":	0,	"excpt":	0}]

::DYNAMIC_IP(1:N	동적	변환)::
[{"addr_obj_id":	0,	"excpt":	0}]

srvsrv: required (array of SetServiceObject)
변경 전 서비스(객체 목록)

Items: SetServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

Example:
Example

[{"srv_obj_id":	1}]

::ANY::
[{"srv_obj_id":	0}]

act_src
act_src: required (array of SetAddrObject)
변경 후 출발지(객체 목록)

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

weight
weight: (integer)
가중치
고급	-	1:N	확장	변환에서	옵션의	가중치	기반	라운드	로빈	설정에서	사용됨

Example:
Example

[{"addr_obj_id":	1,	"excpt":	0}]

::ORG::
[{"addr_obj_id":	0,	"excpt":	0}]

::DYNAMIC_IP(N:M	동적할당(Port	Pool))::
[{"addr_obj_id":	0,	"excpt":	0}]

::MULTILINE(N:M	멀티라인(Port	Pool))::
[{"addr_obj_id":	0,	"excpt":	0}]

act_dst
act_dst: required (array of SetAddrObject)
변경 후 목적지(객체 목록)

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

weight
weight: (integer)
가중치
고급	-	1:N	확장	변환에서	옵션의	가중치	기반	라운드	로빈	설정에서	사용됨

Example:
Example

[{"addr_obj_id":	1,	"excpt":	0}]

::ORG::
[{"addr_obj_id":	0,	"excpt":	0}]

act_srv
act_srv: required (array of SetServiceObject)
변경 후 서비스(객체 목록)

Items: SetServiceObject
Items

srv_obj_id: required (integer)
srv_obj_id
서비스 객체 ID

Example:
Example

[{"srv_obj_id":	1}]

::ORG::
[{"srv_obj_id":	0}]

ifcifc: required (array of SetInterface)
적용 인터페이스

Items: SetInterface
Items

ifc_name
ifc_name: required (string)
인터페이스 이름

Example:
Example

//	1:1	변환
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"basic_nat_mode":	2,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],
		"act_src":	[{"addr_obj_id":	222,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	N:M	변환(IP	Pool)
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"basic_nat_mode":	7,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],
		"act_src":	[{"addr_obj_id":	222,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	N:M	변환(Port	Pool)
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,

		"ifc":	[],
		"basic_nat_mode":	11,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],
		"act_src":	[{"addr_obj_id":	222,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	1:N	변환
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"basic_nat_mode":	11,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	111,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	예외
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"basic_nat_mode":	16,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	1:1	확장변환
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	3,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],
		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	444,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	1:1	동시변환
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	4,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],
		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	444,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	1:1	단방향	확장변환
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	5,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	444,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	1}]
}

//	1:1	단방향	동시변환
{

		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	6,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	444,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	1}]
}

//	N:M	확장변환(IP	Pool)
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	8,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	N:M	동시변환(IP	Pool)
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	10,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	N:M	확장변환(Port	Pool)
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	12,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	N:M	동적할당(Port	Pool)
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	13,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	N:M	멀티라인(Port	Pool)
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[{"ifc_name":	"eth10"}],
		"adv_nat_mode":	14,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	N:M	동시변환(Port	Pool)
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	15,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	1:N	확장	변환
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	21,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	1}]
}

//	1:N	동적	변환
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[{"ifc_name":	"eth11"}],
		"adv_nat_mode":	22,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	1}]
}

//	예외(고급)
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	17,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	예외-단방향
{
		"nat_grp_id":	1,
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	19,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

Response

HTTP status code 200

IPv6 NAT 정책 추가 성공

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

nat_grp_id: required (integer)
nat_grp_id
그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
정책 설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

basic_nat_mode: required (integer)
basic_nat_mode
기본 변환 방식
기본	변환	방식
1:1	변환:	2
N:M	변환(IP	POOL):	7
N:M	변환(PORT	POOL):	11
1:N	변환:	20
예외:	16

adv_nat_mode
adv_nat_mode: required (integer)
고급 변환 방식
1:1	확장변환:	3
1:1	동시변환:	4
1:1	단방향	확장변환:	5
1:1	단방향	동시변환:	6
N:M	확장변환(IP	POOL):	8
N:M	동시변환(IP	POOL):	10
N:M	확장변환(PORT	POOL):	12
N:M	동적할당(PORT	POOL):	13
N:M	멀티라인(PORT	POOL):	14
N:M	동시변환(PORT	POOL):	15
1:N	확장변환:	21
1:N	동적변환:	22
예외:	17
예외-단방향:	19

serv_sched
serv_sched: required (one of 0, 1, 2, 3, 4)
서버 스케쥴링 방식
비활성:	0,	라운드로빈:	1,	가중치	기반	라운드로빈:	2,	해싱:	3

serv_check
serv_check: required (one of 0, 1)
서버 상태 검사
사용	안함:	0,	사용:	1

nat_rule_id
nat_rule_id: required (integer)
정책 ID

seqseq: required (integer)
순번

trans_method
trans_method: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

bi_direct
bi_direct: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

dynamic_ip
dynamic_ip: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

same_time: required (integer)
same_time
히든 옵션
(GUI에서	사용하지	않음)

status_check
status_check: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

multiline
multiline: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

ml_if_cnt
ml_if_cnt: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

ml_active_cnt
ml_active_cnt: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

ls_weight: required (integer)
ls_weight
히든 옵션
(GUI에서	사용하지	않음)

ls_svr_cnt
ls_svr_cnt: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

weight
weight: required (array of integer)
가중치 설정

srcsrc: required (array of ADDRESS_OBJ)
변경 전 출발지

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list
ip_list: (array of any)
객체 별 IP 목록

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

dstdst: required (array of ADDRESS_OBJ)
변경 전 목적지

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name: required (string)
name
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type: required (integer)
addr_obj_type
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list
ip_list: (array of any)
객체 별 IP 목록

excpt: (integer)
excpt
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

srvsrv: required (array of SERVICE_OBJ)
변경 전 서비스

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

prtcprtc: (object)
프로토콜 정보

srv_cate
srv_cate: (integer)
서비스 유형

start_port
start_port: (string)
출발지 포트

srv_port
srv_port: (string)
서비스 포트

life_time
life_time: (integer)
Lifetime(초)

prioprio: (integer)
우선 순위

descdesc: (string)
객체 설명

act_src
act_src: required (array of ADDRESS_OBJ)
변경 후 출발지

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list
ip_list: (array of any)
객체 별 IP 목록

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

act_dst
act_dst: required (array of ADDRESS_OBJ)
변경 후 목적지

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type: required (integer)
addr_obj_type
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list
ip_list: (array of any)
객체 별 IP 목록

excpt: (integer)
excpt
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

act_srv
act_srv: required (array of SERVICE_OBJ)
변경 후 서비스

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

prtcprtc: (object)
프로토콜 정보

srv_cate
srv_cate: (integer)
서비스 유형

start_port
start_port: (string)
출발지 포트

srv_port
srv_port: (string)
서비스 포트

life_time
life_time: (integer)
Lifetime(초)

prioprio: (integer)
우선 순위

descdesc: (string)
객체 설명

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

ifcifc: required (array of GetInterface)
적용 인터페이스

Items: GetInterface
Items

ifc_name
ifc_name: required (string)
인터페이스 이름

rolerole: required (one of 0, 1)
역할(N:M 멀티라인-Port Pool 일 경우 전달 속성)
Active:	0,	Standby:	1

prioprio: (integer)
Standby 우선 순위(N:M 멀티라인-Port Pool 일 경우 전달 속성)

Example:
Example

{
		"code":	"ok",
		"result":	{

				"nat_set_id":	1,
				"nat_grp_id":	1,
				"nat_grp_name":	"default",
				"nat_rule_id":	3,
				"name":	"auto_nat_ruleId_3",
				"desc":	"",
				"seq":	1,
				"use":	1,
				"serv_sched":	0,
				"serv_check":	0,
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2019-01-24	14:42:01",
				"cfg_create_dt":	"2019-01-24	14:42:01",
				"trans_method":	1,
				"bi_direct":	1,
				"dynamic_ip":	0,
				"same_time":	0,
				"status_check":	0,
				"multiline":	0,
				"ml_if_cnt":	0,
				"ml_active_cnt":	0,
				"ls_weight":	0,
				"ls_svr_cnt":	0,
				"weight":	[],
				"adv_nat_mode":	3,
				"src":	[
						{
								"addr_obj_id":	12,
								"name":	"EH_1.1.1.1",
								"zone":	2,
								"desc":	"host	generator",
								"addr_obj_type":	1,
								"cfg_adm_id":	1,
								"cfg_adm":	"admin",
								"cfg_dt":	"2019-01-18	15:16:19",
								"cfg_layer":	0,
								"ip_list":	[
										"1234::5678"
								],
								"ref":	{
										"fw_ref":	false,
										"fwv6_ref":	false,
										"nat_ref":	true,
										"grp_ref":	false,
										"apptag_ref":	false,
										"apptagv6_ref":	false,
										"vpn_ref":	false,
										"sslvpn_ref":	false,
										"ipsddos_ref":	false,
										"content_ref":	false,
										"auth_ref":	false,
										"authv6_ref":	false,
										"qos_ref":	false
								},
								"excpt":	0
						}
				],
				"dst":	[
						{
								"addr_obj_id":	113,
								"name":	"EH_1.1.1.102",
								"zone":	2,
								"desc":	"host	generator",
								"addr_obj_type":	1,
								"cfg_adm_id":	1,
								"cfg_adm":	"admin",
								"cfg_dt":	"2019-01-18	15:16:23",
								"cfg_layer":	0,
								"ip_list":	[
										"1234::7890"
								],
								"ref":	{
										"fw_ref":	false,
										"fwv6_ref":	false,
										"nat_ref":	true,
										"grp_ref":	false,
										"apptag_ref":	false,
										"apptagv6_ref":	false,
										"vpn_ref":	false,
										"sslvpn_ref":	false,
										"ipsddos_ref":	false,
										"content_ref":	false,
										"auth_ref":	false,
										"authv6_ref":	false,
										"qos_ref":	false
								},
								"excpt":	0
						}
				],
				"srv":	[
						{
								"srv_obj_id":	0,
								"srv_obj_type":	0,
								"name":	"Any",
								"desc":	"",
								"pre_def":	1,
								"tcp":	1800,
								"udp":	60,

								"icmp":	10,
								"others":	10
						}
				],
				"act_src":	[
						{
								"addr_obj_id":	115,
								"name":	"EH_1.1.1.104",
								"zone":	2,
								"desc":	"host	generator",
								"addr_obj_type":	1,
								"cfg_adm_id":	1,
								"cfg_adm":	"admin",
								"cfg_dt":	"2019-01-18	15:16:23",
								"cfg_layer":	0,
								"ip_list":	[
										"1234::5678"
								],
								"ref":	{
										"fw_ref":	false,
										"fwv6_ref":	false,
										"nat_ref":	true,
										"grp_ref":	false,
										"apptag_ref":	false,
										"apptagv6_ref":	false,
										"vpn_ref":	false,
										"sslvpn_ref":	false,
										"ipsddos_ref":	false,
										"content_ref":	false,
										"auth_ref":	false,
										"authv6_ref":	false,
										"qos_ref":	false
								},
								"excpt":	0
						}
				],
				"act_dst":	[
						{
								"addr_obj_id":	129,
								"name":	"EH_1.1.1.118",
								"zone":	2,
								"desc":	"host	generator",
								"addr_obj_type":	1,
								"cfg_adm_id":	1,
								"cfg_adm":	"admin",
								"cfg_dt":	"2019-01-18	15:16:24",
								"cfg_layer":	0,
								"ip_list":	[
										"1234::7890"
								],
								"ref":	{
										"fw_ref":	false,
										"fwv6_ref":	false,
										"nat_ref":	true,
										"grp_ref":	false,
										"apptag_ref":	false,
										"apptagv6_ref":	false,
										"vpn_ref":	false,
										"sslvpn_ref":	false,
										"ipsddos_ref":	false,
										"content_ref":	false,
										"auth_ref":	false,
										"authv6_ref":	false,
										"qos_ref":	false
								},
								"excpt":	0
						}
				],
				"act_srv":	[
						{
								"srv_obj_id":	0,
								"srv_obj_type":	0,
								"name":	"org",
								"desc":	"",
								"pre_def":	1,
								"tcp":	1800,
								"udp":	60,
								"icmp":	10,
								"others":	10
						}
				],
				"ifc":	[
						{
								"ifc_name":	"eth0",
								"role":	0,
								"prio":	0
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

DELETE

/nat6/rules

IPv6 NAT 정책 목록을 (일괄)삭제한다.

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
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"nat_rule_id":	1},
				{"nat_rule_id":	2}
		]
}

Response

HTTP status code 200

IPv6 NAT 정책 목록 삭제 성공

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

GET

/nat6/rules/{pk}

IPv6 NAT 정책을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)

정책 ID (nat_rule_id)

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

IPv6 NAT 정책 조회 성공

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

nat_grp_id
nat_grp_id: required (integer)
그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
정책 설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

basic_nat_mode
basic_nat_mode: required (integer)
기본 변환 방식
기본	변환	방식
1:1	변환:	2
N:M	변환(IP	POOL):	7
N:M	변환(PORT	POOL):	11
1:N	변환:	20
예외:	16

adv_nat_mode
adv_nat_mode: required (integer)
고급 변환 방식
1:1	확장변환:	3
1:1	동시변환:	4
1:1	단방향	확장변환:	5
1:1	단방향	동시변환:	6
N:M	확장변환(IP	POOL):	8
N:M	동시변환(IP	POOL):	10
N:M	확장변환(PORT	POOL):	12
N:M	동적할당(PORT	POOL):	13
N:M	멀티라인(PORT	POOL):	14
N:M	동시변환(PORT	POOL):	15
1:N	확장변환:	21

1:N	동적변환:	22
예외:	17
예외-단방향:	19

serv_sched: required (one of 0, 1, 2, 3, 4)
serv_sched
서버 스케쥴링 방식
비활성:	0,	라운드로빈:	1,	가중치	기반	라운드로빈:	2,	해싱:	3

serv_check
serv_check: required (one of 0, 1)
서버 상태 검사
사용	안함:	0,	사용:	1

nat_rule_id
nat_rule_id: required (integer)
정책 ID

seqseq: required (integer)
순번

trans_method: required (integer)
trans_method
히든 옵션
(GUI에서	사용하지	않음)

bi_direct
bi_direct: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

dynamic_ip
dynamic_ip: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

same_time
same_time: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

status_check
status_check: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

multiline: required (integer)
multiline
히든 옵션
(GUI에서	사용하지	않음)

ml_if_cnt
ml_if_cnt: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

ml_active_cnt
ml_active_cnt: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

ls_weight
ls_weight: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

ls_svr_cnt
ls_svr_cnt: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

weight: required (array of integer)
weight
가중치 설정

srcsrc: required (array of ADDRESS_OBJ)
변경 전 출발지

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name: required (string)
name
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type: required (integer)
addr_obj_type
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list
ip_list: (array of any)
객체 별 IP 목록

excpt: (integer)
excpt
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

dstdst: required (array of ADDRESS_OBJ)
변경 전 목적지

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list
ip_list: (array of any)
객체 별 IP 목록

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

srvsrv: required (array of SERVICE_OBJ)
변경 전 서비스

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

pre_def: required (integer)
pre_def
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

prtcprtc: (object)
프로토콜 정보

srv_cate
srv_cate: (integer)
서비스 유형

start_port
start_port: (string)
출발지 포트

srv_port
srv_port: (string)
서비스 포트

life_time: (integer)
life_time
Lifetime(초)

prioprio: (integer)
우선 순위

descdesc: (string)
객체 설명

act_src
act_src: required (array of ADDRESS_OBJ)
변경 후 출발지

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type: required (integer)
addr_obj_type
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list
ip_list: (array of any)
객체 별 IP 목록

excpt: (integer)
excpt
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

act_dst
act_dst: required (array of ADDRESS_OBJ)
변경 후 목적지

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list
ip_list: (array of any)
객체 별 IP 목록

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

act_srv
act_srv: required (array of SERVICE_OBJ)
변경 후 서비스

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

pre_def: required (integer)
pre_def
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

prtcprtc: (object)
프로토콜 정보

srv_cate: (integer)
srv_cate
서비스 유형

start_port
start_port: (string)
출발지 포트

srv_port
srv_port: (string)
서비스 포트

life_time
life_time: (integer)
Lifetime(초)

prioprio: (integer)
우선 순위

descdesc: (string)
객체 설명

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm: required (string)
cfg_adm
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

ifcifc: required (array of GetInterface)
적용 인터페이스

Items: GetInterface
Items

ifc_name
ifc_name: required (string)
인터페이스 이름

rolerole: required (one of 0, 1)
역할(N:M 멀티라인-Port Pool 일 경우 전달 속성)
Active:	0,	Standby:	1

prioprio: (integer)
Standby 우선 순위(N:M 멀티라인-Port Pool 일 경우 전달 속성)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"nat_grp_id":	1,
				"nat_rule_id":	1,
				"name":	"IPv6	NAT	정책	이름",
				"desc":	"IPv6	NAT	정책	설명",
				"seq":	1,
				"use":	1,
				"basic_nat_mode":	1,
				"adv_nat_mode":	null,
				"serv_sched":	0,
				"serv_check":	0,
				"trans_method":	1,
				"bi_direct":	1,
				"dynamic_ip":	0,
				"same_time":	0,
				"status_check":	0,
				"multiline":	0,
				"ml_if_cnt":	0,
				"ml_active_cnt":	0,
				"ls_weight":	0,
				"ls_svr_cnt":	0,
				"weight":	[
				],
				"src":	[{
						"addr_obj_id":	1,
						"ip_ver":	1,
						"name":	"test_host_obj_1",
						"zone":	1,
						"addr_obj_type":	1,
						"excpt":	0
				}],
				"dst":	[{
						"addr_obj_id":	2,
						"ip_ver":	1,
						"name":	"test_host_obj_2",
						"zone":	1,
						"addr_obj_type":	1,
						"excpt":	1
				}],
				"srv":	[{
						"srv_obj_id":	1,
						"srv_obj_type":	1,
						"name":	"AH",
						"pre_def":	1
				}],
				"act_src":	[{
						"addr_obj_id":	1,
						"ip_ver":	1,
						"name":	"test_host_obj_1",
						"zone":	1,
						"addr_obj_type":	1,
						"excpt":	0
				}],
				"act_dst":	[{
						"addr_obj_id":	2,
						"ip_ver":	1,
						"name":	"test_host_obj_2",
						"zone":	1,
						"addr_obj_type":	1,
						"excpt":	0
				}],
				"act_srv":	[{
						"srv_obj_id":	1,
						"srv_obj_type":	1,
						"name":	"AH",
						"pre_def":	1
				}],
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-09	00:48:33"
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

/nat6/rules/{pk}

IPv6 NAT 정책을 수정 또는 이동한다.

Request

URI Parameters

pkpk: required (integer)
정책 ID (nat_rule_id)

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

nat_grp_id: required (integer)
nat_grp_id

그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
정책 설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

basic_nat_mode
basic_nat_mode: required (integer)
기본 변환 방식
기본	변환	방식
1:1	변환:	2
N:M	변환(IP	POOL):	7
N:M	변환(PORT	POOL):	11
1:N	변환:	20
예외:	16

adv_nat_mode
adv_nat_mode: required (integer)
고급 변환 방식
1:1	확장변환:	3
1:1	동시변환:	4
1:1	단방향	확장변환:	5
1:1	단방향	동시변환:	6
N:M	확장변환(IP	POOL):	8
N:M	동시변환(IP	POOL):	10
N:M	확장변환(PORT	POOL):	12
N:M	동적할당(PORT	POOL):	13
N:M	멀티라인(PORT	POOL):	14
N:M	동시변환(PORT	POOL):	15
1:N	확장변환:	21
1:N	동적변환:	22
예외:	17
예외-단방향:	19

serv_sched
serv_sched: required (one of 0, 1, 2, 3, 4)
서버 스케쥴링 방식
비활성:	0,	라운드로빈:	1,	가중치	기반	라운드로빈:	2,	해싱:	3

serv_check
serv_check: required (one of 0, 1)
서버 상태 검사
사용	안함:	0,	사용:	1

pre_rule_id
pre_rule_id: (integer)
기준이 되는 정책 ID
이동	기능에서	사용

up_down
up_down: (integer - default: 1)
기준이 되는 정책의 위/아래 위치 지정
위:	1,	아래:	2
이동	기능에서	사용

srcsrc: required (array of SetAddrObject)
변경 전 출발지(객체 목록)

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

weight
weight: (integer)
가중치
고급	-	1:N	확장	변환에서	옵션의	가중치	기반	라운드	로빈	설정에서	사용됨

Example:
Example

[{"addr_obj_id":	1,	"excpt":	0}]

::ANY::
[{"addr_obj_id":	0,	"excpt":	0}]

dstdst: required (array of SetAddrObject)
변경 전 목적지(객체 목록)

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

weight
weight: (integer)
가중치
고급	-	1:N	확장	변환에서	옵션의	가중치	기반	라운드	로빈	설정에서	사용됨

Example:
Example

[{"addr_obj_id":	1,	"excpt":	0}]

::ANY::
[{"addr_obj_id":	0,	"excpt":	0}]

::DYNAMIC_IP(1:N	동적	변환)::
[{"addr_obj_id":	0,	"excpt":	0}]

srvsrv: required (array of SetServiceObject)
변경 전 서비스(객체 목록)

Items: SetServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

Example:
Example

[{"srv_obj_id":	1}]

::ANY::
[{"srv_obj_id":	0}]

act_src
act_src: required (array of SetAddrObject)
변경 후 출발지(객체 목록)

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

weight
weight: (integer)
가중치
고급	-	1:N	확장	변환에서	옵션의	가중치	기반	라운드	로빈	설정에서	사용됨

Example:
Example

[{"addr_obj_id":	1,	"excpt":	0}]

::ORG::
[{"addr_obj_id":	0,	"excpt":	0}]

::DYNAMIC_IP(N:M	동적할당(Port	Pool))::
[{"addr_obj_id":	0,	"excpt":	0}]

::MULTILINE(N:M	멀티라인(Port	Pool))::
[{"addr_obj_id":	0,	"excpt":	0}]

act_dst
act_dst: required (array of SetAddrObject)
변경 후 목적지(객체 목록)

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

weight
weight: (integer)
가중치
고급	-	1:N	확장	변환에서	옵션의	가중치	기반	라운드	로빈	설정에서	사용됨

Example:
Example

[{"addr_obj_id":	1,	"excpt":	0}]

::ORG::
[{"addr_obj_id":	0,	"excpt":	0}]

act_srv
act_srv: required (array of SetServiceObject)
변경 후 서비스(객체 목록)

Items: SetServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

Example:
Example

[{"srv_obj_id":	1}]

::ORG::
[{"srv_obj_id":	0}]

ifcifc: required (array of SetInterface)
적용 인터페이스

Items: SetInterface
Items

ifc_name: required (string)
ifc_name
인터페이스 이름

Example:
Example

//	1:1	변환
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"basic_nat_mode":	2,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],

		"act_src":	[{"addr_obj_id":	222,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	N:M	변환(IP	Pool)
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"basic_nat_mode":	7,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],
		"act_src":	[{"addr_obj_id":	222,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	N:M	변환(Port	Pool)
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"basic_nat_mode":	11,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],
		"act_src":	[{"addr_obj_id":	222,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	1:N	변환
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"basic_nat_mode":	11,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	111,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	예외
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"basic_nat_mode":	16,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	1:1	확장변환
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	3,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],
		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	444,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	1:1	동시변환
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",

		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	4,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],
		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	444,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	1:1	단방향	확장변환
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	5,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	444,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	1}]
}

//	1:1	단방향	동시변환
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	6,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	444,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	1}]
}

//	N:M	확장변환(IP	Pool)
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	8,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	N:M	동시변환(IP	Pool)
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	10,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	N:M	확장변환(Port	Pool)
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	12,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],

		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	N:M	동적할당(Port	Pool)
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	13,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	N:M	멀티라인(Port	Pool)
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[{"ifc_name":	"eth10"}],
		"adv_nat_mode":	14,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	N:M	동시변환(Port	Pool)
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	15,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	1:N	확장	변환
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	21,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	333,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	1}]
}

//	1:N	동적	변환
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[{"ifc_name":	"eth11"}],
		"adv_nat_mode":	22,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	1}]
}

//	예외(고급)
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",

		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	17,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	0}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

//	예외-단방향
{
		"nat_grp_id":	1,
		"name":	"auto_nat_ruleId",
		"up_down":	1,
		"use":	1,
		"ifc":	[],
		"adv_nat_mode":	19,
		"serv_sched":	0,
		"serv_check":	0,
		"src":	[{"addr_obj_id":	111,	"excpt":	0}],
		"dst":	[{"addr_obj_id":	222,	"excpt":	0}],
		"srv":	[{"srv_obj_id":	1}],
		"act_src":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_dst":	[{"addr_obj_id":	0,	"excpt":	0}],
		"act_srv":	[{"srv_obj_id":	0}]
}

Response

HTTP status code 200

IPv6 NAT 정책 수정 성공

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

nat_grp_id
nat_grp_id: required (integer)
그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
정책 설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

basic_nat_mode
basic_nat_mode: required (integer)
기본 변환 방식
기본	변환	방식
1:1	변환:	2
N:M	변환(IP	POOL):	7
N:M	변환(PORT	POOL):	11
1:N	변환:	20
예외:	16

adv_nat_mode
adv_nat_mode: required (integer)
고급 변환 방식
1:1	확장변환:	3
1:1	동시변환:	4
1:1	단방향	확장변환:	5
1:1	단방향	동시변환:	6
N:M	확장변환(IP	POOL):	8
N:M	동시변환(IP	POOL):	10
N:M	확장변환(PORT	POOL):	12
N:M	동적할당(PORT	POOL):	13
N:M	멀티라인(PORT	POOL):	14
N:M	동시변환(PORT	POOL):	15
1:N	확장변환:	21
1:N	동적변환:	22
예외:	17
예외-단방향:	19

serv_sched
serv_sched: required (one of 0, 1, 2, 3, 4)
서버 스케쥴링 방식
비활성:	0,	라운드로빈:	1,	가중치	기반	라운드로빈:	2,	해싱:	3

serv_check
serv_check: required (one of 0, 1)
서버 상태 검사
사용	안함:	0,	사용:	1

nat_rule_id: required (integer)
nat_rule_id

정책 ID

seqseq: required (integer)
순번

trans_method: required (integer)
trans_method
히든 옵션
(GUI에서	사용하지	않음)

bi_direct
bi_direct: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

dynamic_ip
dynamic_ip: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

same_time
same_time: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

status_check
status_check: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

multiline: required (integer)
multiline
히든 옵션
(GUI에서	사용하지	않음)

ml_if_cnt
ml_if_cnt: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

ml_active_cnt
ml_active_cnt: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

ls_weight
ls_weight: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

ls_svr_cnt
ls_svr_cnt: required (integer)
히든 옵션
(GUI에서	사용하지	않음)

weight: required (array of integer)
weight
가중치 설정

srcsrc: required (array of ADDRESS_OBJ)
변경 전 출발지

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type: required (integer)
addr_obj_type
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list
ip_list: (array of any)
객체 별 IP 목록

excpt: (integer)
excpt
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

dstdst: required (array of ADDRESS_OBJ)
변경 전 목적지

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list
ip_list: (array of any)
객체 별 IP 목록

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

srvsrv: required (array of SERVICE_OBJ)
변경 전 서비스

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

pre_def: required (integer)
pre_def
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

prtcprtc: (object)
프로토콜 정보

srv_cate: (integer)
srv_cate
서비스 유형

start_port
start_port: (string)
출발지 포트

srv_port
srv_port: (string)
서비스 포트

life_time
life_time: (integer)
Lifetime(초)

prioprio: (integer)
우선 순위

descdesc: (string)
객체 설명

act_src
act_src: required (array of ADDRESS_OBJ)
변경 후 출발지

Items: ADDRESS_OBJ
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list
ip_list: (array of any)
객체 별 IP 목록

excpt: (integer)
excpt
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

act_dst
act_dst: required (array of ADDRESS_OBJ)
변경 후 목적지

Items: ADDRESS_OBJ
Items

addr_obj_id: required (integer)
addr_obj_id
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

ip_list
ip_list: (array of any)
객체 별 IP 목록

excpt
excpt: (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

descdesc: (string)
객체 설명

act_srv
act_srv: required (array of SERVICE_OBJ)
변경 후 서비스

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

pre_def: required (integer)
pre_def

기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

prtcprtc: (object)
프로토콜 정보

srv_cate
srv_cate: (integer)
서비스 유형

start_port
start_port: (string)
출발지 포트

srv_port: (string)
srv_port
서비스 포트

life_time
life_time: (integer)
Lifetime(초)

prioprio: (integer)
우선 순위

descdesc: (string)
객체 설명

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

ifcifc: required (array of GetInterface)
적용 인터페이스

Items: GetInterface
Items

ifc_name
ifc_name: required (string)
인터페이스 이름

rolerole: required (one of 0, 1)
역할(N:M 멀티라인-Port Pool 일 경우 전달 속성)
Active:	0,	Standby:	1

prioprio: (integer)
Standby 우선 순위(N:M 멀티라인-Port Pool 일 경우 전달 속성)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"nat_grp_id":	1,
				"nat_rule_id":	1,
				"name":	"IPv6	NAT	정책	이름",
				"desc":	"IPv6	NAT	정책	설명",
				"seq":	1,
				"use":	1,
				"basic_nat_mode":	1,
				"adv_nat_mode":	null,
				"serv_sched":	0,
				"serv_check":	0,
				"trans_method":	1,
				"bi_direct":	1,
				"dynamic_ip":	0,
				"same_time":	0,
				"status_check":	0,
				"multiline":	0,
				"ml_if_cnt":	0,
				"ml_active_cnt":	0,
				"ls_weight":	0,
				"ls_svr_cnt":	0,
				"weight":	[
				],
				"src":	[{
						"addr_obj_id":	1,
						"ip_ver":	1,
						"name":	"test_host_obj_1",
						"zone":	1,
						"addr_obj_type":	1,
						"excpt":	1
				}],
				"dst":	[{
						"addr_obj_id":	2,
						"ip_ver":	1,
						"name":	"test_host_obj_2",
						"zone":	1,
						"addr_obj_type":	1,
						"excpt":	1
				}],
				"srv":	[{
						"srv_obj_id":	1,
						"srv_obj_type":	1,
						"name":	"AH",
						"pre_def":	1
				}],
				"act_src":	[{
						"addr_obj_id":	1,
						"ip_ver":	1,
						"name":	"test_host_obj_1",
						"zone":	1,
						"addr_obj_type":	1,
						"excpt":	1
				}],
				"act_dst":	[{
						"addr_obj_id":	2,
						"ip_ver":	1,
						"name":	"test_host_obj_2",
						"zone":	1,
						"addr_obj_type":	1,
						"excpt":	1
				}],
				"act_srv":	[{
						"srv_obj_id":	1,
						"srv_obj_type":	1,
						"name":	"AH",
						"pre_def":	1
				}],
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-09	00:48:33"
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

DELETE

/nat6/rules/{pk}

IPv6 NAT 정책을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
정책 ID (nat_rule_id)

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

IPv6 NAT 정책 삭제 성공

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

message: required (string)
message
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

/nat6/rules/save

IPv6 NAT 정책을 PC로 저장합니다.

[Task 진행 상태 조회]
GET	{{url}}/api/co/async/tasks/{{task_id}}

[상태가 성공인 Task에 대해 엑셀 파일을 다운로드]
GET	{{url}}/api/co/async/tasks/{{task_id}}/save

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

Query Parameters

columns: (string)
columns

다운로드되는 엑셀 파일 내 테이블 헤더 값으로 사용될 값을 전달한다.(데이터 테이블에 표시되는 컬럼 순으로 지정)
columns 쿼리스트링에 값이 없을 경우 백엔드에 정의된 속성명으로 표시됩니다.
한글이	포함될	수	있기	때문에	UTF-8	인코딩되어야	합니다.

Example:
Example

?columns=(A,B,C)

Response

HTTP status code 202

IPv6 NAT 정책를 비동기로 파일 생성 시작

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
결과 메시지

idid: required (string)
태스크 ID

status
status: required (string)
태스크 상태
PENDING,	PROCESS,	FAILURE,	REVOKED,	SUCCESS

attributes
attributes: required (string)
태스트 속성

Example:
Example

{
		"code":	"async",
		"result":	{
				"id":	"38520e53-6a3e-473a-88d5-ffb9aa142524",
				"status":	"PENDING",
				"attributes":	{}
		}
}

[Task 진행 상태 조회]
배치를 실행 후 응답된 태스크 ID로 상태를 체크합니다.
상태:  PENDING,	PROGRESS,	FAILURE,	REVOKED,	SUCCESS

PENDING: 준비 중
PROGRESS: 처리 중
FAILURE: 실패
REVOKED: 중지 성공
SUCCESS: 성공

GET	{{url}}/api/co/async/tasks/{{task_id}}
{ "code": "ok", "result": { "id": "c295d300-9b7f-4c10-9468-6538c0abab66", "status": "SUCCESS", "attributes": { } } }

POST

/nat6/rules/batch

IPv6 NAT 정책을 배치 작업을 시작합니다.

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

filefile: required (string)
파일 업로드 후 반환된 파일명을 인자로 전달
파일 업로드 API로 배치 파일 업로드 후 호출
https://{url}/api/co/file/import

excel_location
excel_location: required (integer)
엑셀 입력 위치(엑셀 Row를 읽는 순서)
위에서	아래:	1,	아래에서	위:	2

2.8.0에서	속성명과	속성값이	변경됨

force
force: required (integer)
IP 중복 입력
허용:	1,	차단:	0

2.8.0에서	속성명과	속성값이	변경됨

policy_location: required (integer)
policy_location
정책 입력 위치
최상위:	1,	최하위:	2,	정책ID	3

2.8.0에서	속성명과	속성값이	변경됨

pre_rule_id: required (string)
pre_rule_id
정책입력위치: 지정정책ID
policy_location  속성값이 최상위(1) 또는 최하위(2) 일 경우 null
0	~	800,000

2.8.0에서	속성명과	속성값이	변경됨

Example:
Example

{
		"file":	"batch_file.xlsx",
		"excel_location":	1,
		"force":	1,
		"policy_location":	3,
		"pre_rule_id":	"0"
}

Response

HTTP status code 202

IPv6 NAT 정책 배치 실행

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

idid: required (string)
비동기 태스크 ID

Example:
Example

f810f701-e732-4698-a5a9-a93000a828d9

status
status: required (string)
상태( PENDING,	PROGRESS,	FAILURE,	REVOKED,	SUCCESS )

PENDING: 준비 중
PROGRESS: 처리 중
FAILURE: 실패
REVOKED: 중지 성공
SUCCESS: 성공

attributes
attributes: required (object)
부가 정보

Example:
Example

{
		"code":	"async",
		"result":	{
				"id":	"f810f701-e732-4698-a5a9-a93000a828d9",
				"status":	"PENDING",
				"attributes":	{}
		}
}

HTTP status code 400

IPv6 NAT 정책 배치 실행 실패

IPv6 NAT 정책 목록 이동

PUT

/nat6/move/rules

선택된 정책 목록을 일괄로 이동한다.

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

nat_grp_id
nat_grp_id: required (integer)
NAT 그룹 ID

pre_rule_id
pre_rule_id: (integer)
기준이 되는 정책 ID

up_down: required (one of 1, 2)
up_down
기준이 되는 정책의 위/아래 위치 지정
위:	1,	아래:	2

items
items: required (array of integer)
이동 될 정책 ID 목록
순번으로	내림차순	정렬	된	정책	ID	목록이여야	합니다.

Example:
Example

[1,	2,	3,	4,	5]

Example:
Example

{
		"nat_grp_id":	5,
		"pre_rule_id":	10,
		"up_down":1,
		"items":	[1,	2,	3,	4,	5]
}

Response

HTTP status code 200

IPv6 NAT 정책 목록 이동 목록 수정 성공

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
result: required (array of string)
결과 데이터

Example:
Example

{
		"code":	"ok",
		"result":	[]
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

정책 내용 검색

POST

/nat6/content-rules/search

IPv6 NAT 정책 내용을 검색한다.

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

infinf: required (integer)
적용 인터페이스 이름
빈칸은	null,	ANY는	"0"으로	입력

Example:
Example

eth1

nat_rule_id
nat_rule_id: required (array of integer)
IPv6 NAT 정책 ID 목록
최대	10개까지	지원

Example:
Example

[1,	2,	3,	4,	5]

srcsrc: required (array of string)
출발지 객체 이름 목록
객체	이름은	최대	48자	입력	가능

Example:
Example

["obj1",	"obj2"]

src_operator
src_operator: required (one of 1, 2)
출발지 검색 조건
AND:	1,	OR:	2

src_case: required (string)
src_case
'대소문자 구분', '완전 일치', '객체 내용 검색', '관련 정보(객체)포함' 옵션 순으로 선택 여부를 표시한 문자열
'IP 검색' 옵션이 V3.0에서 추가
0:	선택	안됨,	1:	선택됨

Example:
Example

"11110"	->	모두	선택된	경우

dstdst: required (array of string)
목적지 객체 이름 목록
객체	이름은	최대	48자	입력	가능

Example:
Example

["obj1",	"obj2"]

dst_operator
dst_operator: required (one of 1, 2)
목적지 검색 조건
AND:	1,	OR:	2

dst_case
dst_case: required (string)
'대소문자 구분', '완전 일치', '객체 내용 검색', '관련 정보(객체)포함' 옵션 순으로 선택 여부를 표시한 문자열
'IP 검색' 옵션이 V3.0에서 추가
0:	선택	안됨,	1:	선택됨

Example:
Example

"11110"	->	모두	선택된	경우

service
service: required (array of string)
서비스 객체 이름 목록
객체	이름은	최대	48자	입력	가능

Example:
Example

["obj1",	"obj2"]

srv_operator: required (one of 1, 2)
srv_operator
서비스 검색 조건
AND:	1,	OR:	2

service_case
service_case: required (string)
대소문자 구분, 완전일치, 객체 내용 검색, 관련 정보(객체)포함 순으로 비트 스트링

Example:
Example

1111	->	모두	선택된	경우

descdesc: required (string - maxLength: 256)
설명

desc_case
desc_case: required (string)
대소문자 구분, 완전일치 포함 순으로 비트 스트링

Example:
Example

11	->	모두	선택된	경우

create_dt
create_dt: (string)
정책 생성일(optional)
형식:	YYYYMMDDYYYYMMDD

Example:
Example

2019010120191231

Example:
Example

{
		"inf":	"Any",
		"nat_rule_id":	[1,	2],
		"src":	["10.10.10.10_IH"],
		"src_operator":	1,
		"src_case":	"1111",
		"dst":	["11.11.11.11_IH"],
		"dst_operator":	1,
		"dst_case":	"1111",
		"service":	["AH"],
		"srv_operator":	1,
		"service_case":	"0000",
		"desc":	"설명",
		"desc_case":	"00",
		"create_dt":	"2019010120191231"
}

Response

HTTP status code 200

정책 내용 검색 추가 성공

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
result: required (array of ContentSearchResult)
결과 데이터

Items: ContentSearchResult
Items

rulerule: required (array of RuleSearch)
검색 결과

Items: RuleSearch
Items

nat_set_id
nat_set_id: required (integer)
NAT 세트 ID

nat_rule_id
nat_rule_id: required (integer)
IPv6 NAT 정책 ID

seqseq: required (integer)
순번

cfg_create_dt: required (string)
cfg_create_dt
정책 생성일

objobj: required (array of RelObject)
관련 객체 정보

Items: RelObject
Items

target
target: required (string)
검색 항목
src:	출발지,	dst:	목적지,	svc:	서비스

name
name: required (string)
객체 이름/사용자

detail
detail: required (string)
상세 정보

zone
zone: (one of 1, 2, 3)
Zone 정보, target이 src, dst인 경우 출력( 내부:	1,	외부:	2,	DMZ:	3 )

type: required (string)
type
문자열 형식의 객체 타입
host,	network,	group,	service,	service_group,	domain

Example:
Example

{
		"code":	"ok",
		"result":	{
				"rule":	[{
						"nat_set_id":	1,
						"nat_rule_id":	1,
						"seq":	1,
						"cfg_create_dt":	"2019-01-06	09:20:23"
				}],
				"obj":	[{
						"target":	"src",
						"name":	"test_host_obj",
						"detail":	"Auto	created(NAT)",
						"zone":	1,
						"type":	"host"
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

Shadow 정책 검색

POST

/nat6/shadow-rules/search

Shadow 정책을 검색한다.

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

nat_rule_id
nat_rule_id: required (integer - minimum: 1 - maximum: 99999999)
IPv6 NAT 정책 ID

unuse_rule
unuse_rule: required (one of 0, 1)
비활성화된 정책 포함 여부
미포함:	0,	포함:	1

Example:
Example

{
		"nat_rule_id":	1,
		"unuse_rule":	0
}

Response

HTTP status code 200

Shadow 정책 검색 추가 성공

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
result: required (array of ShadowSearchResult)
결과 데이터

Items: ShadowSearchResult
Items

seqseq: required (integer)
순번

nat_rule_id
nat_rule_id: required (integer)
정책 ID

s_nat_rule_id
s_nat_rule_id: required (integer)
상위 정책 ID

descdesc: required (string)
설명

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"seq":	1,
				"nat_rule_id":	1,
				"s_nat_rule_id":	2,
				"desc":	"Completely	shadowed"
		},	{
				"seq":	2,
				"nat_rule_id":	2,
				"s_nat_rule_id":	4,
				"desc":	"Partially	shadowed"
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

적용 정책 검색

POST

/nat6/apply-rules/search

적용 정책을 검색한다.

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

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties

infinf: required (integer)
적용 인터페이스 이름
빈칸은	null,	ANY는	"0"으로	입력

Example:
Example

eth1

protocol
protocol: required (integer)
프로토콜 ID (prtc_obj_id)

[프로토콜 목록 조회]
GET	{{url}}/api/op/service/protocols

srcsrc: required (string)
출발지 주소(IPv6 형식)

src_port
src_port: required (integer - minimum: 0 - maximum: 65535)
출발지 포트
프로토콜이	TCP,	UDP일	때	입력	가능

dstdst: required (string)
목적지 주소(IPv6 형식)

dst_port
dst_port: required (integer - minimum: 0)
목적지 포트
프로토콜이	ICMP,	TCP,	UDP일	때	입력	가능
ICMP:	0~255,	TCP/UDP:	0~65535

Example:
Example

{
		"inf":	"eth0",
		"protocol":	5,
		"src":	"1234::5678",
		"src_port":	65535,
		"dst":	"1234::5678",
		"dst_port":	65535
}

Response

HTTP status code 200

적용 정책 검색 추가 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of ApplyRuleSearchResult)
result
결과 데이터

Items: ApplyRuleSearchResult
Items

seqseq: required (integer)
순번

nat_rule_id
nat_rule_id: required (integer)
정책 ID

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"seq":	1,
				"nat_rule_id":	1
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

미참조 정책 검색

POST

/nat6/unuse-rules/search

미참조 정책을 검색한다.

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

datedate: required (integer - minimum: 1 - maximum: 365)
미참조일

recent_rule
recent_rule: required (one of 0, 1)
최근 생성일 포함 여부
0:	미포함,	1:	포함

SupportedVersion:	2.0.0

Example:
Example

{
		"date":	1,
		"recent_rule":	1
}

Response

HTTP status code 200

미참조 정책 검색 추가 성공

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
result: required (array of UnuseRuleSearchResult)
결과 데이터

Items: UnuseRuleSearchResult
Items

seqseq: required (integer)
순번

nat_rule_id: required (integer)
nat_rule_id
정책 ID

name
name: required (string)
정책명

SupportedVersion:	2.0.0

unref_days
unref_days: required (integer)
미참조 일
-1:	현재가지	참조	기록	없음

cfg_create_dt
cfg_create_dt: required (string)
정책 생성일

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"seq":	1,
				"nat_rule_id":	1,
				"name":	"nat_rule_name_1",
				"unref_days":	-1,
				"cfg_create_dt":	"2019-11-06	09:19:57"
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

dev_t: (string)
dev_t
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

미참조 객체 검색

GET

/nat6/unuse-objects/search/days/{day}

미참조 객체를 검색한다.

Request

URI Parameters

dayday: required (integer - minimum: 1 - maximum: 365)
미참조 일

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

Response

HTTP status code 200

미참조 객체 검색 목록 조회 성공

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
result: required (array of UnuseObjectSearchResult)
결과 데이터

Items: UnuseObjectSearchResult
Items

obj_id
obj_id: required (integer)
객체 ID

name
name: required (string)
객체 이름

unuse_date
unuse_date: required (integer)
미참조 일
-1:	현재까지	참조	기록	없음

cfg_create_dt
cfg_create_dt: required (string)
객체 생성일

ref_nat_set_id: required (integer)
ref_nat_set_id
참조 이력 세트 ID

ref_nat_rule_id
ref_nat_rule_id: required (integer)
참조 이력 정책 ID

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

type
type: required (string)
객체 타입(host, network, service, domain)

nat_rule
nat_rule: required (array of UnuseNat)
정책 목록

Items: UnuseNat
Items

nat_set_id
nat_set_id: required (integer)
세트 ID

nat_rule_id
nat_rule_id: required (integer)
정책 ID

cfg_create_dt
cfg_create_dt: required (string)
정책 생성일

SupportedVersion:	2.0.0

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"obj_id":	1,
				"name":	"10.10.10.10_IH",
				"unuse_date":	1,
				"cfg_create_dt":	"2021-10-22	16:18:19",
				"ref_nat_set_id":	1,
				"ref_nat_rule_id":	1,
				"zone":	2,
				"type":	"host",
				"nat_rule":	[{
						"nat_set_id":	1,
						"nat_rule_id":	1,
						"cfg_create_dt":	"2019-10-22	13:52:05"
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

적용 인터페이스

GET

/nat6/interfaces

적용 인터페이스 목록을 조회한다.

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

적용 인터페이스 목록 조회 성공

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
result: required (array of object)
결과 데이터
상세한 속성 정보는  System	>	시스템	구성	>	인터페이스	설정 을 참고

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"id":	1,
				"name":	"eth0",
				"appeared":	1,
				"type":	1,
				"hwaddr":	"00:0c:29:4c:52:ed",
				"ipaddress":	"10.10.10.10",
				"netmask":	19,
				"ipv6address":	[],
				"zone":	3,
				"usage":	1,
				"desc":	"",
				"mode":	{
						"mode":	1,
						"type":	1,
						"static":	{
								"type":	"static",
								"IPv6":	"10.10.10.10/19",
								"ipv6":	[],
								"alias":	[]
						}
				},
				"mtu":	1500,
				"copper":	1,
				"active":	1,
				"if_up":	1,
				"link_up":	1,
				"children":	[],
				"circuit_check_enabled":	0,
				"speed":	"10G",
				"full_duplex":	1,
				"auto_nego":	0
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

적용 인터페이스(멀티라인)

GET

/nat6/multiline/interfaces

적용 인터페이스(멀티라인) 목록을 조회한다.

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

적용 인터페이스(멀티라인) 목록 조회 성공

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
result: required (array of object)
결과 데이터
상세한 속성 정보는  System	>	시스템	구성	>	인터페이스	설정 을 참고

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"id":	1,
				"name":	"eth0",
				"hwaddr":	"00:0c:29:b2:ac:ec",
				"zone":	"1",
				"mode":	{
						"mode":	1,
						"type":	1,
						"static":	{
								"type":	"static",
								"IPv6":	"1.1.1.1/24",
								"ipv6":	[
										{
												"ipv6_id":	1,
												"type":	1,
												"ipv6_ip":	"111::1/64"
										},
										{
												"ipv6_id":	2,
												"type":	1,
												"ipv6_ip":	"111::2/64"
										}
								],
								"alias":	[
										{
												"alias_id":	1,
												"type":	1,
												"alias_ip":	"1.1.1.1/24"
										},
										{
												"alias_id":	2,
												"type":	1,
												"alias_ip":	"1.1.2.1/24"
										}
								]
						}
				},
				"status":	{
						"id":	1,
						"name":	"eth0",
						"active":	1,
						"mtu":	1500,
						"speed":	"1G",
						"copper":	1,
						"full_duplex":	1,
						"auto_nego":	1
				},
				"children":	[]
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

IPv6 NAT 정책 설정 적용/취소

PUT

/command/nat6-policies/apply

IPv6 NAT 정책 설정을 적용합니다.

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

Example:
Example

{}

Response

HTTP status code 200

IPv6 NAT 정책 설정 적용 성공

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

/command/nat6-policies/cancel

IPv6 NAT 정책 설정을 취소합니다.

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

IPv6 NAT 정책 설정 취소 성공

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

