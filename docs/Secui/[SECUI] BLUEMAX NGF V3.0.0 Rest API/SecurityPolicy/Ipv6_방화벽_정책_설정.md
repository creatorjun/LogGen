IPv6 방화벽 정책 설정 REST API 문서

https://{host}/api/po

host
host: required (string)
[IP]:[GUI 접속 PORT]
443	포트는	생략	가능

Example:
Example

192.168.100.100:443

방화벽 정책 세트

/fw/6/sets

/fw/6/sets/{pk}

/fw/6/sets/{pk}/use

/fw/6/sets/{pk}/tempsave

/fw/6/sets/tempsave

(GUI 전용)방화벽 정책 세트 백업(타임라인) 목록 조회

/fw/6/timeline/sets

/fw/6/timeline/sets/{pk}/use

방화벽 정책 그룹

/fw/6/groups

/fw/6/groups/{pk}

방화벽 정책

/fw/6/rules

/fw/6/rules/{pk}

/fw/6/rules/save

/fw/6/rules/batch

/fw/6/rules/batch/history

방화벽 정책 유효성 검사

/fw/6/rules-check

정책 일괄 변경

/fw/6/bulk/rules

정책 목록 이동

/fw/6/move/rules

정책 상세 보기

/fw/6/kernel/rules

특정 정책 상세 보기

/fw/6/kernel/sets/{sid}/rules/{rid}

정책 내용 검색

/fw/6/content-rules/search

GET

POST

PUT

  DELETE

PUT

POST

GET

GET

PUT

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

GET

POST

PUT

PUT

  DELETE

PUT

GET

GET

POST

POST

POST

POST

POST

POST

POST

POST

POST

GET

GET

GET

DELETE

POST

PUT

PUT

PUT

/fw/6/content-rules/search/save

시간 만료 정책 검색

/fw/6/expire-rules/search

/fw/6/expire-rules/search/save

Shadow 정책 검색

/fw/6/shadow-rules/search

/fw/6/shadow-rules/search/save

적용 정책 검색

/fw/6/apply-rules/search

미참조 정책 검색

/fw/6/unuse-rules/search

/fw/6/unuse-rules/search/save

미참조 객체 검색

/fw/6/unuse-objects/search/days/{days}

/fw/6/unuse-objects/search/days/{days}/save?columns=(객체 타입,객체 이름,참조 이력 정책 ID,미참조 일자,객체 생성일,정책 ID,정책생성일)

QoS

/fw/6/sets/{sid}/rules/{rid}/qos/profiles

방화벽 현재 세션

/fw/6/session

방화벽 정책(객체 자동 생성 기능)

정책을 추가/편집 할 때 출발지, 목적지에 객체를 자동으로 생성할 수 있는 기능을 제공한다.

/fw/6/auto/rules

IPv6 방화벽 정책 설정 적용/취소

/command/fw-6-policies/apply

/command/fw-6-policies/cancel

방화벽 정책 세트

GET

/fw/6/sets

정책 세트 목록을 조회한다.

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

정책 세트 목록 조회 성공

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
result: required (array of 정책 세트)
결과 데이터

Items: 정책 세트
Items

name
name: required (string - maxLength: 32)
세트 이름
임시	저장일	경우	temp_rule로	지정됨

fw_set_id
fw_set_id: required (integer)
방화벽 세트 ID(PK)

useuse: required (one of 0, 1)
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
		"result":	[
				{
						"fw_set_id":	1,
						"use":	1,
						"name":	"default",
						"cfg_adm_id":	1,
						"cfg_adm":	"admin",
						"cfg_dt":	"2018-05-08	12:23:23",
						"apply":	1
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
		"dev_t":	"Authentication	Error"
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"dev_t":	"Authentication	Error",
		"message":	"인가되지	않은	API	요청입니다."
}

POST

/fw/6/sets

(새로 만들기) 방화벽 정책 세트를 추가한다.

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
name: required (string - maxLength: 32)
name
세트 이름
임시	저장일	경우	temp_rule로	지정됨

Example:
Example

{
		"name":	"New	세트	이름"
}

Response

HTTP status code 200

정책 세트 추가 성공

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
임시	저장일	경우	temp_rule로	지정됨

fw_set_id
fw_set_id: required (integer)
방화벽 세트 ID(PK)

useuse: required (one of 0, 1)
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
				"fw_set_id":	2,
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

/fw/6/sets/{pk}

(다른 이름으로 저장) 정책 세트를 수정한다.

Request

URI Parameters

pkpk: required (integer)
정책 세트 ID (fw_set_id)

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

fw_set_new_name: required (string - maxLength: 32)
fw_set_new_name
다른 이름으로 저장될 세트 이름

Example:
Example

{
		"fw_set_new_name":	"변경된	세트	이름"
}

Response

HTTP status code 200

정책 세트 수정 성공

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
임시	저장일	경우	temp_rule로	지정됨

fw_set_id: required (integer)
fw_set_id
방화벽 세트 ID(PK)

useuse: required (one of 0, 1)
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
				"fw_set_id":	2,
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

/fw/6/sets/{pk}

정책 세트을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
정책 세트 ID (fw_set_id)

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

정책 세트 삭제 성공

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

PUT

/fw/6/sets/{pk}/use

(열기) 정책 세트를 수정한다.

Request

URI Parameters

pkpk: required (integer)
정책 세트 ID (fw_set_id)

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

정책 세트 수정 성공

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
임시	저장일	경우	temp_rule로	지정됨

fw_set_id
fw_set_id: required (integer)
방화벽 세트 ID(PK)

useuse: required (one of 0, 1)
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
				"fw_set_id":	3,
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

POST

/fw/6/sets/{pk}/tempsave

임시저장을 한다.

Request

URI Parameters

pkpk: required (integer)
정책 세트 ID (fw_set_id)

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
임시	저장일	경우	temp_rule로	지정됨

fw_set_id
fw_set_id: required (integer)
방화벽 세트 ID(PK)

useuse: required (one of 0, 1)
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
				"fw_set_id":	2,
				"use":	1,
				"name":	"temp_rule",
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

/fw/6/sets/tempsave

임시저장 상태를 조회한다.

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
임시	저장일	경우	temp_rule로	지정됨

fw_set_id: required (integer)
fw_set_id
방화벽 세트 ID(PK)

useuse: required (one of 0, 1)
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
				"fw_set_id":	2,
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

(GUI 전용)방화벽 정책 세트 백업(타임라인) 목록 조회

GET

/fw/6/timeline/sets

방화벽 정책 백업 목록을 조회한다.

Request

Annotations

Lib.SupportedVersion:
Lib.SupportedVersion

"2.0.0"

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

방화벽 정책 백업 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of GetFwSetBackup)
result
결과 데이터

Items: GetFwSetBackup
Items

fw_set_id
fw_set_id: required (integer)
방화벽 세트 ID(PK)

fw_org_name
fw_org_name: required (string)
세트 이름

dirty_flag
dirty_flag: required (one of 0, 1)
신뢰성 여부
신뢰:	0,	오염:	1

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
		"result":	[
				{
						"fw_set_id":	1,
						"fw_org_name":	"default",
						"dirty_flag":	1,
						"cfg_adm_id":	1,
						"cfg_adm":	"admin",
						"cfg_dt":	"2018-05-09	00:48:33"
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
		"dev_t":	"Authentication	Error"
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"dev_t":	"Authentication	Error",
		"message":	"인가되지	않은	API	요청입니다."
}

PUT

/fw/6/timeline/sets/{pk}/use

타임라인으로 백업된 정책 세트를 활성화한다.

Request

URI Parameters

pkpk: required (integer)
백업(타임라인) 세트 ID( fw_set_id )

Annotations

Lib.SupportedVersion:
Lib.SupportedVersion

"2.0.0"

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
name
name: required (string)
백업된 세트를 불러와서 생성될 세트 이름

Example:
Example

{
		"name":	"New	세트	이름"
}

Response

HTTP status code 200

정책 세트 수정 성공

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

name: required (string - maxLength: 32)
name

세트 이름
임시	저장일	경우	temp_rule로	지정됨

fw_set_id
fw_set_id: required (integer)
방화벽 세트 ID(PK)

useuse: required (one of 0, 1)
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
				"fw_set_id":	3,
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

방화벽 정책 그룹

GET

/fw/6/groups

방화벽 정책 그룹 목록을 조회한다.

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

방화벽 정책 그룹 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of GetFwGroup)
result
결과 데이터

Items: GetFwGroup
Items

name
name: required (string - minLength: 1 - maxLength: 32)
그룹 이름

descdesc: (string - maxLength: 128)
그룹 설명

fw_set_id
fw_set_id: required (integer)
방화벽 세트 ID

fw_grp_id
fw_grp_id: required (integer)
그룹 ID(PK)

seqseq: required (integer)
순번

rule_cnt: required (integer)
rule_cnt
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
		"result":	[
				{
						"fw_set_id":	1,
						"fw_grp_id":	1,
						"seq":	1,
						"name":	"default",
						"rule_cnt":	100,
						"desc":	"",
						"cfg_adm_id":	1,
						"cfg_adm":	"admin",
						"cfg_dt":	"2018-05-09	00:48:33"
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

/fw/6/groups

방화벽 정책 그룹를 추가한다.

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
name
name: required (string - minLength: 1 - maxLength: 32)
그룹 이름

descdesc: (string - maxLength: 128)
그룹 설명

Example:
Example

{
		"name":	"New	그룹	이름",
		"desc":	"New	그룹	설명"
}

Response

HTTP status code 200

방화벽 정책 그룹 추가 성공

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

name: required (string - minLength: 1 - maxLength: 32)
name
그룹 이름

descdesc: (string - maxLength: 128)
그룹 설명

fw_set_id
fw_set_id: required (integer)
방화벽 세트 ID

fw_grp_id
fw_grp_id: required (integer)
그룹 ID(PK)

seqseq: required (integer)
순번

rule_cnt: required (integer)
rule_cnt
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
		"result":	{
				"fw_set_id":	1,
				"fw_grp_id":	2,
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

/fw/6/groups/{pk}

방화벽 정책 그룹을(를) 조회한다.

Request

URI Parameters

pkpk: required (string)
그룹 ID (fw_grp_id)

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

방화벽 정책 그룹 조회 성공

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

name: required (string - minLength: 1 - maxLength: 32)
name
그룹 이름

descdesc: (string - maxLength: 128)
그룹 설명

fw_set_id
fw_set_id: required (integer)
방화벽 세트 ID

fw_grp_id
fw_grp_id: required (integer)
그룹 ID(PK)

seqseq: required (integer)
순번

rule_cnt: required (integer)
rule_cnt
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
		"result":	{
				"fw_set_id":	1,
				"fw_grp_id":	1,
				"seq":	1,
				"name":	"default",
				"desc":	"",
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

PUT

/fw/6/groups/{pk}

방화벽 정책 그룹을(를) 수정한다.

Request

URI Parameters

pkpk: required (string)
그룹 ID (fw_grp_id)

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

Properties
Properties
name
name: required (string - minLength: 1 - maxLength: 32)
그룹 이름

descdesc: (string - maxLength: 128)
그룹 설명

pre_grp_id
pre_grp_id: required (integer)
이동될 위치의 그룹 ID
null	입력	시	첫번째	또는	마지막으로	설정

up_down
up_down: required (integer - default: 1)
이동될 위치의 그룹 ID( pre_grp_id )의 위/아래 위치 지정
위:	1,	아래:	2

Example:
Example

{
		"pre_grp_id":	3,
		"up_down":	1,
		"name":	"변경된	그룹	이름",
		"desc":	"변경된	그룹	설명"
}

Response

HTTP status code 200

방화벽 정책 그룹 수정 성공

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

name: required (string - minLength: 1 - maxLength: 32)
name
그룹 이름

descdesc: (string - maxLength: 128)
그룹 설명

fw_set_id
fw_set_id: required (integer)
방화벽 세트 ID

fw_grp_id
fw_grp_id: required (integer)
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
		"result":	{
				"fw_set_id":	1,
				"fw_grp_id":	1,
				"seq":	1,
				"name":	"변경된	그룹	이름",
				"desc":	"변경된	그룹	설명",
				"rule_cnt":	100,
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

/fw/6/groups/{pk}

방화벽 정책 그룹을(를) 삭제한다.

Request

URI Parameters

pkpk: required (string)
그룹 ID (fw_grp_id)

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

방화벽 정책 그룹 삭제 성공

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

dev_t: (string)
dev_t
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

방화벽 정책

GET

/fw/6/rules

방화벽 정책 목록을 조회한다.

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

방화벽 정책 목록 조회 성공

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
result: required (array of GetFwRuleList)
결과 데이터

Items: GetFwRuleList
Items

fw_grp_id
fw_grp_id: required (integer)
그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

action: required (one of 1, 2, 3, 4)
action
동작 코드
허용:	1,	거부:	2,	거절(ICMP):	3,	거절(Reset):	4

bi_dir
bi_dir: required (one of 0, 1)
양방향 정책 설정
사용	안함:	0,	사용:	1

loglog: required (one of 0, 1)
로그 설정
사용	안함:	0,	사용:	1

tcp_flag
tcp_flag: required (one of 0, 1)
TCP 플래그
사용	안함:	0,	사용:	1

vlan_id
vlan_id: required (string - maxLength: 255)
VLAN ID를 콤마(,) 구분자로 연결한 문자열

Example:
Example

1,2,3,4,5

sess_limit
sess_limit: required (one of 0, 1, 2)
세션 제한 설정
미사용:	0,	전체	제한:	1,	정책	별	제한:	2

sess_limit_val
sess_limit_val: required (integer - default: 100000 - minimum: 60 - maximum: 2000000)
이 정책의 전체 세션 수 제한

sess_limit_ip_block
sess_limit_ip_block: required (integer - default: 10000 - minimum: 60 - maximum: 2000000)
각각의 출발지 IP당 세션 수 제한

sess_limit_block
sess_limit_block: required (one of 0, 1)
세션 수 초과 시 해당 IP의 모든 세션 차단 설정
사용	안함:	0,	사용:	1

fw_set_id
fw_set_id: required (integer)
정책 세트 ID

fw_rule_id
fw_rule_id: required (integer)
정책 ID(PK)

seqseq: required (integer)
순번

time
time: required (object)
시간 객체

tm_obj_id
tm_obj_id: required (integer)
시간 객체 ID( PK )

name
name: required (string)
객체 이름

expired
expired: required (string)
만료시간
포맷: YYYYMMDDhhmm 또는 0(ANY)

Example:
Example

201901011230

weekweek: required (object)
매주 설정

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

monthmonth: required (object)
매월 설정

useuse: required (integer)
매월 플래그
미사용:	0,	주:	1,	기간:	2,	일지정:	3

year
year: required (object)
매년 설정

useuse: required (integer)

사용 여부
사용	안함:	0,	사용:	1

period
period: required (object)
기간 설정

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

srcsrc: required (array of AddressObject)
출발지 객체 목록

Items: AddressObject
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
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

dstdst: required (array of AddressObject)
목적지 객체 목록

Items: AddressObject
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
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

srvsrv: required (array of ServiceObject)
서비스 객체 목록

Items: ServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2,	애플리케이션	포트:	3

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

user
user: required (array of GetUserObject)
사용자 객체 목록

Items: GetUserObject
Items

usr_obj_type: required (integer)
usr_obj_type
사용자 타입
사용자:	1
사용자	그룹:	2
IP	매핑	사용자:	3
IP	매핑	사용자	그룹:	4
AD	사용자:	5
AD	사용자	그룹:	6
String	사용자:	7
KNOWN	사용자:	8
UNKNOWN	사용자:	9

usr_obj_id
usr_obj_id: (integer)
사용자 객체 ID  (usr_obj_type이	1일	때)

usr_grp_id
usr_grp_id: (integer)
사용자 그룹 객체 ID  (usr_obj_type이	2일	때)

ip_map_usr_id
ip_map_usr_id: (integer)
IP 매핑 사용자 객체 ID  (usr_obj_type이	3일	때)

ip_map_svr_id: (integer)
ip_map_svr_id

IP 매핑 서버 ID, ip_map_usr_id와 함께 설정  (usr_obj_type이	3일	때)

ip_map_grp_id
ip_map_grp_id: (integer)
IP 매핑 사용자 그룹 ID  (usr_obj_type이	4일	때)

ad_map_usr: required (string)
ad_map_usr
AD 사용자  (usr_obj_type이	5일	때)

ad_map_grp
ad_map_grp: required (string)
AD 사용자 그룹  (usr_obj_type이	6일	때)

str_name
str_name: required (string)
String 사용자 (usr_obj_type이	7일	때)
KNOWN 사용자(고정값: KNOWN) (usr_obj_type이	8일	때)
UNKNOWN 사용자(고정값: UNKNOWN) (usr_obj_type이	9일	때)

login_id
login_id: required (string)
사용자 ID
(usr_obj_type이	1일	때)

usr_grp_dmn: required (string)
usr_grp_dmn
도메인
(usr_obj_type이	2일	때)

usr_grp_name
usr_grp_name: required (string)
사용자 그룹 이름
(usr_obj_type이	2일	때)

device
device: required (array of object)
디바이스 객체 목록
IPv6에서는	사용되지	않음

Items:
Items

appapp: required (array of GetAppObject)
앱 객체 목록

Items: GetAppObject
Items

app_obj_id: required (integer)
app_obj_id
애플리케이션 객체 ID

app_obj_type
app_obj_type: required (one of 1, 2, 3)
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

name: required (string)
name
애플리케이션 관련 객체 이름
app_obj_type가	1일	경우	객체	이름
app_obj_type가	2일	경우	그룹	객체	이름
app_obj_type가	3일	경우	필터	객체	이름

security_profile: required (object)
security_profile
보안 프로파일 정보 목록

Example:
Example

{
		"ips":	{"id":	1,	"name":	"default"},
		"av":	{"id":	1,	"name":	"default"},
		"as":	{"id":	1,	"name":	"default"},
		"wf":	{"id":	1,	"name":	"default"},
		"dlp":	{"id":	1,	"name":	"default"},
		"file_type":	{"id":	1,	"name":	"default"},
		"apt":	{"id":	1,	"name":	"default"},
		"dnssec":	{"id":	1,	"name":	"default"}
}

qosqos: required (integer)
QoS 정책 설정 여부(조회만 가능)
미사용:	0,	사용:	1

extheader: required (object)
extheader
확장 헤더

fragment
fragment: required (one of 0, 1)
Fragment
미사용:	0,	사용:	1

authauth: required (one of 0, 1)
인증
미사용:	0,	사용:	1

destdest: required (one of 0, 1)
목적지
미사용:	0,	사용:	1

espesp: required (one of 0, 1)
ESP
미사용:	0,	사용:	1

hophop: required (one of 0, 1)
Hop-by-Hop
미사용:	0,	사용:	1

routing
routing: required (one of 0, 1)
라우팅
미사용:	0,	사용:	1

hit_count
hit_count: required (array of integer)
Hitcount

Example:
Example

[
		100,
		1000,
		10000,
		null,
		null
]

tagtag: required (array of 태그 객체)
태그 객체 목록

Items: 태그 객체
Items

tag_obj_id
tag_obj_id: required (integer)
태그 객체 ID

name
name: required (string - minLength: 1 - maxLength: 32)
객체명(공백 입력 불가)

color
color: required (string)
RGB 포맷의 컬러값

Example:
Example

#ff0000

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"fw_set_id":	1,
						"fw_grp_id":	1,
						"seq":	1,
						"name":	"default",
						"rule_cnt":	1,
						"is_group":	true
				},
				{
						"fw_set_id":	1,
						"fw_grp_id":	1,
						"fw_rule_id":	1,
						"name":	"정책	이름",
						"desc":	"정책	설명"
						"seq":	"1",
						"use":	1,
						"action":	2,
						"bi_dir":	0,
						"log":	1,
						"tcp_flag":	0,
						"vlan_id":	"1,2,3,4,5",
						"sess_limit":	0,
						"sess_limit_val":	10000,
						"sess_limit_ip_block":	1000,
						"sess_limit_block":	0,
						"cfg_dt":	"2019-01-24	20:10:58",
						"cfg_adm_id":	1,
						"cfg_adm":	"admin",
						"src":	[
								{
										"addr_obj_id":	2,
										"ip_ver":	1,
										"name":	"test_host_obj_1",
										"zone":	1,
										"addr_obj_type":	1,
										"excpt":	0
								}
						],
						"dst":	[
								{
										"addr_obj_id":	3,
										"ip_ver":	1,
										"name":	"test_host_obj_11",
										"zone":	1,
										"addr_obj_type":	1,
										"excpt":	0
								}
						],
						"srv":	[
								{
										"srv_obj_id":	1,
										"srv_obj_type":	1,
										"name":	"AH",
										"pre_def":	1
								}
						],
						"user":	[{
								"usr_obj_id":	1,
								"login_id":	"example\\test_user1",
								"usr_obj_type":	1,
								"type":	1
						},
						{
								"usr_grp_id":	1,
								"usr_grp_dmn":	"example",
								"usr_grp_name":	"test_user_group",
								"usr_obj_type":	2
						}],
						"device":	[],
						"app":	[{
								"app_obj_id":	30003,
								"name":	"51.com",
								"app_obj_type":	1
						}],
						"security_profile":	{
								"ips":	{"id":	1,	"name":	"IPS	프로파일"},
								"av":	{"id":	1,	"name":	"안티바이러스	프로파일"},
								"as":	{"id":	1,	"name":	"안티스팸	프로파일"},
								"wf":	{"id":	1,	"name":	"웹필터	프로파일"},
								"dlp":	{"id":	1,	"name":	"DLP	프로파일"},

								"file_type":	{"id":	1,	"name":	"파일유형제어	프로파일"},
								"apt":	{"id":	1,	"name":	"APT	프로파일"},
								"dnssec":	{"id":	1,	"name":	"DNS	보안	프로파일"}
						},
						"time":	{
								"tm_obj_id":	1,
								"name":	"시간	객체	이름",
								"expired":	"201901011030",
								"week":	{
												"use":	1
								},
								"month":	{
												"use":	0
								},
								"year":	{
												"use":	0
								},
								"period":	{
												"use":	1
								}
						},
						"qos":	0,
						"extheader":	{
								"fragment":	1,
								"auth":	1,
								"dest":	1,
								"esp":	1,
								"hop":	1,
								"routing":	1
						},
						"hit_count":	[10,	100,	1000,	null,	null],
						"last_hit_time":	"-",
						"tag":	[
								{
										"tag_obj_id":	1,
										"name":	"재택	정책	태그",
										"color":	"#ff0000"
								}
						]
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

/fw/6/rules

방화벽 정책를 추가한다.

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

fw_grp_id
fw_grp_id: required (integer)
그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

action
action: required (one of 1, 2, 3, 4)
동작 코드
허용:	1,	거부:	2,	거절(ICMP):	3,	거절(Reset):	4

bi_dir
bi_dir: required (one of 0, 1)
양방향 정책 설정
사용	안함:	0,	사용:	1

loglog: required (one of 0, 1)
로그 설정
사용	안함:	0,	사용:	1

tcp_flag: required (one of 0, 1)
tcp_flag
TCP 플래그
사용	안함:	0,	사용:	1

vlan_id
vlan_id: required (string - maxLength: 255)
VLAN ID를 콤마(,) 구분자로 연결한 문자열

Example:
Example

1,2,3,4,5

sess_limit
sess_limit: required (one of 0, 1, 2)
세션 제한 설정
미사용:	0,	전체	제한:	1,	정책	별	제한:	2

sess_limit_val
sess_limit_val: required (integer - default: 100000 - minimum: 60 - maximum: 2000000)
이 정책의 전체 세션 수 제한

sess_limit_ip_block
sess_limit_ip_block: required (integer - default: 10000 - minimum: 60 - maximum: 2000000)
각각의 출발지 IP당 세션 수 제한

sess_limit_block
sess_limit_block: required (one of 0, 1)
세션 수 초과 시 해당 IP의 모든 세션 차단 설정
사용	안함:	0,	사용:	1

pre_rule_id
pre_rule_id: (integer)
기준이 되는 정책 ID

up_down
up_down: required (one of 1, 2)
기준이 되는 정책의 위/아래 위치 지정
위:	1,	아래:	2

time
time: required (integer)
시간 객체 ID

srcsrc: required (array of SetAddrObject)
출발지 객체 목록

Items: SetAddrObject
Items

addr_obj_id: required (integer)
addr_obj_id
주소 객체 ID

addr_obj_type
addr_obj_type: (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt: (one of 0, 1)
excpt

예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

Example:
Example

[{"addr_obj_id":	1,	"addr_obj_type":	1,	"excpt":	0}]

dstdst: required (array of SetAddrObject)
목적지 객체 목록

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID

addr_obj_type
addr_obj_type: (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: (one of 0, 1)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

Example:
Example

[{"addr_obj_id":	1,	"addr_obj_type":	1,	"excpt":	0}]

srvsrv: required (array of SetServiceObject)
서비스 객체 목록

Items: SetServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID
-1:	애플리케이션	포트

Example:
Example

[{"srv_obj_id":	1}]

user: required (array of SetUserObject)
user
사용자 객체 목록

Items: SetUserObject
Items

usr_obj_type
usr_obj_type: required (integer)
사용자 타입
사용자:	1
사용자	그룹:	2
IP	매핑	사용자:	3
IP	매핑	사용자	그룹:	4
AD	사용자:	5
AD	사용자	그룹:	6
String	사용자:	7
KNOWN	사용자:	8
UNKNOWN	사용자:	9

usr_obj_id
usr_obj_id: (integer)
사용자 객체 ID  (usr_obj_type이	1일	때)

usr_grp_id
usr_grp_id: (integer)
사용자 그룹 객체 ID  (usr_obj_type이	2일	때)

ip_map_usr_id
ip_map_usr_id: (integer)
IP 매핑 사용자 객체 ID  (usr_obj_type이	3일	때)

ip_map_svr_id
ip_map_svr_id: (integer)
IP 매핑 서버 ID, ip_map_usr_id와 함께 설정  (usr_obj_type이	3일	때)

ip_map_grp_id: (integer)
ip_map_grp_id
IP 매핑 사용자 그룹 ID  (usr_obj_type이	4일	때)

ad_map_usr
ad_map_usr: required (string)
AD 사용자  (usr_obj_type이	5일	때)

ad_map_grp
ad_map_grp: required (string)
AD 사용자 그룹  (usr_obj_type이	6일	때)

str_name
str_name: required (string)
String 사용자 (usr_obj_type이	7일	때)
KNOWN 사용자(고정값: KNOWN) (usr_obj_type이	8일	때)
UNKNOWN 사용자(고정값: UNKNOWN) (usr_obj_type이	9일	때)

appapp: required (array of SetAppObject)
앱 객체 목록

Items: SetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

app_obj_type
app_obj_type: required (one of 1, 2, 3)
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

Example:
Example

[{"app_obj_id":	30003,	"app_obj_type":	1}]

security_profile
security_profile: required (object)
보안 프로파일 설정 정보

ipsips: required (integer)
IPS 프로파일 ID

[IPS 프로파일 목록 조회]
GET	{{url}}/api/op/ips/profiles

avav: required (integer)

안티바이러스 프로파일 ID

[안티바이러스 프로파일 목록 조회]
GET	{{url}}/api/op/av/profiles

asas: required (integer)
안티스팸 프로파일 ID

[안티스팸 프로파일 목록 조회]
GET	{{url}}/api/op/as/profiles

wfwf: required (integer)
웹필터 프로파일 ID

[웹필터 프로파일 목록 조회]
GET	{{url}}/api/op/wf/profiles

dlpdlp: required (integer)
DLP 프로파일 ID

[DLP 프로파일 목록 조회]
GET	{{url}}/api/op/dlp/profiles

file_type: required (integer)
file_type
파일 유형 제어 프로파일 ID

[파일 유형 제어 프로파일 조회]
GET	{{url}}/api/op/filetype/profiles

aptapt: required (integer)
APT 프로파일 ID

[APT 프로파일 ID]
GET	{{url}}/api/op/apt/profiles

dnssec
dnssec: required (integer)
DNS 보안 프로파일 ID

[DNS 보안 프로파일 ID]
GET	{{url}}/api/op/dnssec/profiles

Example:
Example

{"ips":1,	"av":1,	"as":1,	"wf":1,	"dlp":1,	"file_type":1,	"apt":	1,	"dnssec":	1}

tagtag: required (array of 태그 객체)
태그 객체 목록

Items: 태그 객체
Items

tag_obj_id
tag_obj_id: required (integer)
태그 객체 ID

extheader
extheader: required (object)
확장 헤더

fragment
fragment: required (one of 0, 1)
Fragment
미사용:	0,	사용:	1

authauth: required (one of 0, 1)
인증
미사용:	0,	사용:	1

destdest: required (one of 0, 1)
목적지
미사용:	0,	사용:	1

espesp: required (one of 0, 1)
ESP
미사용:	0,	사용:	1

hophop: required (one of 0, 1)
Hop-by-Hop
미사용:	0,	사용:	1

routing
routing: required (one of 0, 1)
라우팅
미사용:	0,	사용:	1

Example:
Example

{
		"fw_grp_id":	1,
		"up_down":	1,
		"name":	"New	정책	이름",
		"desc":	"New	정책	설명",
		"use":	1,
		"action":	2,
		"bi_dir":	0,
		"log":	1,
		"tcp_flag":	1,
		"vlan_id":	"1,2,3,4,5",
		"sess_limit":	1,
		"sess_limit_val":	10000,
		"sess_limit_ip_block":	1000,
		"sess_limit_block":	0,
		"src":	[
				{"addr_obj_id":	1,	"addr_obj_type":	1,	"excpt":	0}
		],
		"dst":	[
				{"addr_obj_id":	2,	"addr_obj_type":	1,	"excpt":	0}
		],
		"srv":	[
				{"srv_obj_id":	1}
		],
		"user":	[
				{"usr_obj_type":	1,	"usr_obj_id":	1},
				{"usr_obj_type":	2,	"usr_grp_id":	1},
				{"usr_obj_type":	3,	"ip_map_svr_id":	1,	"ip_map_usr_id":	1},
				{"usr_obj_type":	4,	"ip_map_grp_id":	1},
				{"usr_obj_type":	5,	"ad_map_usr":	""},
				{"usr_obj_type":	6,	"ad_map_grp":	""},
				{"usr_obj_type":	7,	"str_name":	"string	user"},
				{"usr_obj_type":	8,	"str_name":	"KNOWN"},
				{"usr_obj_type":	9,	"str_name":	"UNKNOWN"}
		],
		"app":	[{
				"app_obj_id":	30003,
				"app_obj_type":	1
		}],
		"security_profile":	{
				"ips":	1,
				"av":	1,
				"as":	1,
				"wf":	1,
				"dlp":	1,
				"file_type":	1,
				"apt":	1,
				"dnssec":	1
		},
		"time":	1,
		"tag":	[
				{"tag_obj_id":	1}
		],
		"extheader":	{
				"fragment":	1,
				"auth":	1,
				"dest":	1,
				"esp":	1,
				"hop":	1,
				"routing":	1
		}
}

Response

HTTP status code 200

방화벽 정책 추가 성공

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

fw_grp_id
fw_grp_id: required (integer)
그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

action: required (one of 1, 2, 3, 4)
action

동작 코드
허용:	1,	거부:	2,	거절(ICMP):	3,	거절(Reset):	4

bi_dir
bi_dir: required (one of 0, 1)
양방향 정책 설정
사용	안함:	0,	사용:	1

loglog: required (one of 0, 1)
로그 설정
사용	안함:	0,	사용:	1

tcp_flag: required (one of 0, 1)
tcp_flag
TCP 플래그
사용	안함:	0,	사용:	1

vlan_id
vlan_id: required (string - maxLength: 255)
VLAN ID를 콤마(,) 구분자로 연결한 문자열

Example:
Example

1,2,3,4,5

sess_limit
sess_limit: required (one of 0, 1, 2)
세션 제한 설정
미사용:	0,	전체	제한:	1,	정책	별	제한:	2

sess_limit_val
sess_limit_val: required (integer - default: 100000 - minimum: 60 - maximum: 2000000)
이 정책의 전체 세션 수 제한

sess_limit_ip_block
sess_limit_ip_block: required (integer - default: 10000 - minimum: 60 - maximum: 2000000)
각각의 출발지 IP당 세션 수 제한

sess_limit_block
sess_limit_block: required (one of 0, 1)
세션 수 초과 시 해당 IP의 모든 세션 차단 설정
사용	안함:	0,	사용:	1

fw_rule_id
fw_rule_id: required (integer)
정책 ID

seqseq: required (integer)
순번

time
time: required (object)
시간 객체

srcsrc: required (array of AddressObject)
출발지 객체 목록

Items: AddressObject
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
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

dstdst: required (array of AddressObject)
목적지 객체 목록

Items: AddressObject
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
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

srvsrv: required (array of ServiceObject)
서비스 객체 목록

Items: ServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2,	애플리케이션	포트:	3

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

user: required (array of GetUserObject)
user
사용자 객체 목록

Items: GetUserObject
Items

usr_obj_type
usr_obj_type: required (integer)
사용자 타입
사용자:	1
사용자	그룹:	2
IP	매핑	사용자:	3
IP	매핑	사용자	그룹:	4
AD	사용자:	5
AD	사용자	그룹:	6
String	사용자:	7
KNOWN	사용자:	8
UNKNOWN	사용자:	9

usr_obj_id
usr_obj_id: (integer)
사용자 객체 ID  (usr_obj_type이	1일	때)

usr_grp_id: (integer)
usr_grp_id
사용자 그룹 객체 ID  (usr_obj_type이	2일	때)

ip_map_usr_id
ip_map_usr_id: (integer)
IP 매핑 사용자 객체 ID  (usr_obj_type이	3일	때)

ip_map_svr_id
ip_map_svr_id: (integer)
IP 매핑 서버 ID, ip_map_usr_id와 함께 설정  (usr_obj_type이	3일	때)

ip_map_grp_id
ip_map_grp_id: (integer)
IP 매핑 사용자 그룹 ID  (usr_obj_type이	4일	때)

ad_map_usr
ad_map_usr: required (string)
AD 사용자  (usr_obj_type이	5일	때)

ad_map_grp
ad_map_grp: required (string)
AD 사용자 그룹  (usr_obj_type이	6일	때)

str_name
str_name: required (string)
String 사용자 (usr_obj_type이	7일	때)
KNOWN 사용자(고정값: KNOWN) (usr_obj_type이	8일	때)
UNKNOWN 사용자(고정값: UNKNOWN) (usr_obj_type이	9일	때)

login_id: required (string)
login_id
사용자 ID
(usr_obj_type이	1일	때)

usr_grp_dmn
usr_grp_dmn: required (string)
도메인
(usr_obj_type이	2일	때)

usr_grp_name: required (string)
usr_grp_name
사용자 그룹 이름
(usr_obj_type이	2일	때)

device
device: required (array of object)
디바이스 객체 목록
IPv6에서는	사용되지	않음

Items:
Items

appapp: required (array of GetAppObject)
앱 객체 목록

Items: GetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

app_obj_type: required (one of 1, 2, 3)
app_obj_type
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

name
name: required (string)
애플리케이션 관련 객체 이름
app_obj_type가	1일	경우	객체	이름
app_obj_type가	2일	경우	그룹	객체	이름
app_obj_type가	3일	경우	필터	객체	이름

security_profile
security_profile: required (object)
보안 프로파일 목록

Example:
Example

{
		"ips":	{"id":	1,	"name":	"default"},
		"av":	{"id":	1,	"name":	"default"},
		"as":	{"id":	1,	"name":	"default"},
		"wf":	{"id":	1,	"name":	"default"},
		"dlp":	{"id":	1,	"name":	"default"},
		"file_type":	{"id":	1,	"name":	"default"},
		"apt":	{"id":	1,	"name":	"default"},
		"dnssec":	{"id":	1,	"name":	"default"}
}

tagtag: required (array of 태그 객체)
태그 객체 목록

Items: 태그 객체
Items

tag_obj_id: required (integer)
tag_obj_id

태그 객체 ID

name
name: required (string - minLength: 1 - maxLength: 32)
객체명(공백 입력 불가)

color: required (string)
color
RGB 포맷의 컬러값

Example:
Example

#ff0000

qosqos: required (integer)
QoS 정책 설정 여부(조회만 가능)
미사용:	0,	사용:	1

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
				"fw_set_id":	1,
				"fw_grp_id":	1,
				"fw_rule_id":	2,
				"name":	"New	정책	이름",
				"desc":	"New	정책	설명",
				"seq":	1,
				"use":	1,
				"action":	2,
				"bi_dir":	0,
				"log":	1,
				"tcp_flag":	0,
				"vlan_id":	"1,2,3,4,5",
				"sess_limit":	1,
				"sess_limit_val":	10000,
				"sess_limit_ip_block":	1000,
				"sess_limit_block":	0,
				"src":	[{
						"addr_obj_id":	2,
						"ip_ver":	1,
						"name":	"test_host_obj_1",
						"zone":	1,
						"addr_obj_type":	1,
						"excpt":	0
				}],
				"dst":	[{
						"addr_obj_id":	3,
						"ip_ver":	1,
						"name":	"test_host_obj_11",
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
				"user":	[{
						"usr_obj_id":	1,
						"login_id":	"example\\test_user1",
						"usr_obj_type":	1,
						"type":	1
				},	{
						"usr_grp_id":	1,
						"usr_grp_dmn":	"test",
						"usr_grp_name":	"test",
						"usr_obj_type":	2
				}],
				"device":	[],
				"app":	[{
						"port":	"TCP	80",
						"app_obj_type":	1
						"app_obj_id":	30003,
						"name":	"51.com"
				}],
				"security_profile":	{
						"ips":	{"id":	1,	"name":	"IPS	프로파일"},
						"av":	{"id":	1,	"name":	"안티바이러스	프로파일"},
						"as":	{"id":	1,	"name":	"안티스팸	프로파일"},
						"wf":	{"id":	1,	"name":	"웹필터	프로파일"},
						"dlp":	{"id":	1,	"name":	"DLP	프로파일"},
						"file_type":	{"id":	1,	"name":	"파일유형제어	프로파일"},
						"apt":	{"id":	1,	"name":	"APT	프로파일"},
						"dnssec":	{"id":	1,	"name":	"DNS	보안	프로파일"}
				},
				"time":	{
						"tm_obj_id":	1,
						"name":	"시간	객체",
						"expired":	"0",
						"week":	{
								"use":	1

						},
						"month":	{
								"use":	0
						},
						"year":	{
								"use":	0
						},
						"period":	{
								"use":	0
						}
				},
				"qos":	0,
				"tag":	[
						{
								"tag_obj_id":	1,
								"name":	"재택	정책	태그",
								"color":	"#ff0000"
						}
				],
				"extheader":	{
						"hop":	1,
						"routing":	1,
						"fragment":	1,
						"dest":	0,
						"auth":	1,
						"esp":	1
				},
				"last_hit_time":	"-",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-30	07:54:53"
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

DELETE

/fw/6/rules

방화벽 정책 목록을 (일괄)삭제한다.

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
items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"fw_rule_id":	1},
				{"fw_rule_id":	2}
		]
}

Response

HTTP status code 200

방화벽 정책 목록 삭제 성공

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

/fw/6/rules/{pk}

방화벽 정책을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
정책 ID (fw_rule_id)

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

방화벽 정책 조회 성공

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

fw_grp_id
fw_grp_id: required (integer)
그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

action
action: required (one of 1, 2, 3, 4)
동작 코드
허용:	1,	거부:	2,	거절(ICMP):	3,	거절(Reset):	4

bi_dir
bi_dir: required (one of 0, 1)
양방향 정책 설정
사용	안함:	0,	사용:	1

loglog: required (one of 0, 1)
로그 설정
사용	안함:	0,	사용:	1

tcp_flag
tcp_flag: required (one of 0, 1)
TCP 플래그
사용	안함:	0,	사용:	1

vlan_id: required (string - maxLength: 255)
vlan_id
VLAN ID를 콤마(,) 구분자로 연결한 문자열

Example:
Example

1,2,3,4,5

sess_limit
sess_limit: required (one of 0, 1, 2)
세션 제한 설정
미사용:	0,	전체	제한:	1,	정책	별	제한:	2

sess_limit_val
sess_limit_val: required (integer - default: 100000 - minimum: 60 - maximum: 2000000)
이 정책의 전체 세션 수 제한

sess_limit_ip_block
sess_limit_ip_block: required (integer - default: 10000 - minimum: 60 - maximum: 2000000)
각각의 출발지 IP당 세션 수 제한

sess_limit_block
sess_limit_block: required (one of 0, 1)
세션 수 초과 시 해당 IP의 모든 세션 차단 설정
사용	안함:	0,	사용:	1

fw_rule_id
fw_rule_id: required (integer)
정책 ID

seqseq: required (integer)
순번

time: required (object)
time
시간 객체

srcsrc: required (array of AddressObject)
출발지 객체 목록

Items: AddressObject
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
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

dstdst: required (array of AddressObject)
목적지 객체 목록

Items: AddressObject
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

zone: required (integer)
zone

Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

srvsrv: required (array of ServiceObject)
서비스 객체 목록

Items: ServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2,	애플리케이션	포트:	3

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

user
user: required (array of GetUserObject)
사용자 객체 목록

Items: GetUserObject
Items

usr_obj_type
usr_obj_type: required (integer)
사용자 타입
사용자:	1
사용자	그룹:	2
IP	매핑	사용자:	3
IP	매핑	사용자	그룹:	4
AD	사용자:	5
AD	사용자	그룹:	6
String	사용자:	7
KNOWN	사용자:	8
UNKNOWN	사용자:	9

usr_obj_id
usr_obj_id: (integer)
사용자 객체 ID  (usr_obj_type이	1일	때)

usr_grp_id
usr_grp_id: (integer)
사용자 그룹 객체 ID  (usr_obj_type이	2일	때)

ip_map_usr_id
ip_map_usr_id: (integer)
IP 매핑 사용자 객체 ID  (usr_obj_type이	3일	때)

ip_map_svr_id
ip_map_svr_id: (integer)
IP 매핑 서버 ID, ip_map_usr_id와 함께 설정  (usr_obj_type이	3일	때)

ip_map_grp_id
ip_map_grp_id: (integer)
IP 매핑 사용자 그룹 ID  (usr_obj_type이	4일	때)

ad_map_usr
ad_map_usr: required (string)
AD 사용자  (usr_obj_type이	5일	때)

ad_map_grp
ad_map_grp: required (string)
AD 사용자 그룹  (usr_obj_type이	6일	때)

str_name
str_name: required (string)
String 사용자 (usr_obj_type이	7일	때)
KNOWN 사용자(고정값: KNOWN) (usr_obj_type이	8일	때)
UNKNOWN 사용자(고정값: UNKNOWN) (usr_obj_type이	9일	때)

login_id
login_id: required (string)
사용자 ID
(usr_obj_type이	1일	때)

usr_grp_dmn
usr_grp_dmn: required (string)
도메인
(usr_obj_type이	2일	때)

usr_grp_name
usr_grp_name: required (string)
사용자 그룹 이름
(usr_obj_type이	2일	때)

device
device: required (array of object)
디바이스 객체 목록
IPv6에서는	사용되지	않음

Items:
Items

appapp: required (array of GetAppObject)
앱 객체 목록

Items: GetAppObject
Items

app_obj_id: required (integer)
app_obj_id
애플리케이션 객체 ID

app_obj_type
app_obj_type: required (one of 1, 2, 3)
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

name: required (string)
name
애플리케이션 관련 객체 이름
app_obj_type가	1일	경우	객체	이름
app_obj_type가	2일	경우	그룹	객체	이름
app_obj_type가	3일	경우	필터	객체	이름

security_profile: required (object)
security_profile

보안 프로파일 목록

Example:
Example

{
		"ips":	{"id":	1,	"name":	"default"},
		"av":	{"id":	1,	"name":	"default"},
		"as":	{"id":	1,	"name":	"default"},
		"wf":	{"id":	1,	"name":	"default"},
		"dlp":	{"id":	1,	"name":	"default"},
		"file_type":	{"id":	1,	"name":	"default"},
		"apt":	{"id":	1,	"name":	"default"},
		"dnssec":	{"id":	1,	"name":	"default"}
}

tagtag: required (array of 태그 객체)
태그 객체 목록

Items: 태그 객체
Items

tag_obj_id
tag_obj_id: required (integer)
태그 객체 ID

name: required (string - minLength: 1 - maxLength: 32)
name
객체명(공백 입력 불가)

color
color: required (string)
RGB 포맷의 컬러값

Example:
Example

#ff0000

qosqos: required (integer)
QoS 정책 설정 여부(조회만 가능)
미사용:	0,	사용:	1

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
				"fw_set_id":	1,
				"fw_grp_id":	1,
				"fw_rule_id":	1,
				"name":	"정책	이름",
				"desc":	"정책	설명",
				"seq":	1,
				"use":	1,
				"action":	2,
				"bi_dir":	0,
				"log":	1,
				"tcp_flag":	0,
				"vlan_id":	"1,2,3,4,5",
				"sess_limit":	0,
				"sess_limit_val":	1000,
				"sess_limit_ip_block":	1000,
				"sess_limit_block":	0,
				"src":	[
						{
								"addr_obj_id":	2,
								"ip_ver":	1,
								"name":	"test_host_obj_1",
								"zone":	1,
								"addr_obj_type":	1,
								"excpt":	0
						}
				],
				"dst":	[
						{
								"addr_obj_id":	3,
								"ip_ver":	1,
								"name":	"test_host_obj_11",
								"zone":	1,
								"addr_obj_type":	1,
								"excpt":	0
						}
				],
				"srv":	[
						{
								"srv_obj_id":	1,
								"srv_obj_type":	1,
								"name":	"AH",
								"pre_def":	1
						}
				],
				"user":	[{
						"usr_obj_id":	1,
						"login_id":	"gui1\\gui1",
						"usr_obj_type":	1,
						"type":	1
				},	{
						"usr_grp_id":	1,
						"usr_grp_dmn":	"test",

						"usr_grp_name":	"test",
						"usr_obj_type":	2
				}],
				"device":	[],
				"app":	[{
						"app_obj_id":	30003,
						"name":	"51.com",
						"app_obj_type":	1
				}],
				"security_profile":	{
						"ips":	{"id":	1,	"name":	"IPS	프로파일"},
						"av":	{"id":	1,	"name":	"안티바이러스	프로파일"},
						"as":	{"id":	1,	"name":	"안티스팸	프로파일"},
						"wf":	{"id":	1,	"name":	"웹필터	프로파일"},
						"dlp":	{"id":	1,	"name":	"DLP	프로파일"},
						"file_type":	{"id":	1,	"name":	"파일유형제어	프로파일"},
						"apt":	{"id":	1,	"name":	"APT	프로파일"},
						"dnssec":	{"id":	1,	"name":	"DNS	보안	프로파일"}
				},
				"time":	{
						"tm_obj_id":	1,
						"name":	"시간	객체",
						"expired":	"0",
						"week":	{
								"use":	1
						},
						"month":	{
								"use":	0
						},
						"year":	{
								"use":	0
						},
						"period":	{
								"use":	0
						}
				},
				"qos":	0,
				"tag":	[
						{
								"tag_obj_id":	1,
								"name":	"재택	정책	태그",
								"color":	"#ff0000"
						}
				],
				"extheader":	{
						"hop":	1,
						"routing":	1,
						"fragment":	1,
						"dest":	0,
						"auth":	1,
						"esp":	1
				},
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-30	07:54:53"
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

/fw/6/rules/{pk}

방화벽 정책을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
정책 ID (fw_rule_id)

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

fw_grp_id
fw_grp_id: required (integer)
그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

action
action: required (one of 1, 2, 3, 4)
동작 코드
허용:	1,	거부:	2,	거절(ICMP):	3,	거절(Reset):	4

bi_dir
bi_dir: required (one of 0, 1)
양방향 정책 설정
사용	안함:	0,	사용:	1

loglog: required (one of 0, 1)
로그 설정
사용	안함:	0,	사용:	1

tcp_flag
tcp_flag: required (one of 0, 1)
TCP 플래그
사용	안함:	0,	사용:	1

vlan_id: required (string - maxLength: 255)
vlan_id
VLAN ID를 콤마(,) 구분자로 연결한 문자열

Example:
Example

1,2,3,4,5

sess_limit
sess_limit: required (one of 0, 1, 2)
세션 제한 설정
미사용:	0,	전체	제한:	1,	정책	별	제한:	2

sess_limit_val
sess_limit_val: required (integer - default: 100000 - minimum: 60 - maximum: 2000000)
이 정책의 전체 세션 수 제한

sess_limit_ip_block
sess_limit_ip_block: required (integer - default: 10000 - minimum: 60 - maximum: 2000000)
각각의 출발지 IP당 세션 수 제한

sess_limit_block
sess_limit_block: required (one of 0, 1)
세션 수 초과 시 해당 IP의 모든 세션 차단 설정
사용	안함:	0,	사용:	1

pre_rule_id
pre_rule_id: (integer)
기준이 되는 정책 ID

up_down
up_down: required (one of 1, 2)
기준이 되는 정책의 위/아래 위치 지정
위:	1,	아래:	2

time
time: required (integer)
시간 객체 ID

srcsrc: required (array of SetAddrObject)
출발지 객체 목록

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID

addr_obj_type
addr_obj_type: (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: (one of 0, 1)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

Example:
Example

[{"addr_obj_id":	1,	"addr_obj_type":	1,	"excpt":	0}]

dstdst: required (array of SetAddrObject)
목적지 객체 목록

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID

addr_obj_type
addr_obj_type: (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: (one of 0, 1)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

Example:
Example

[{"addr_obj_id":	1,	"addr_obj_type":	1,	"excpt":	0}]

srvsrv: required (array of SetServiceObject)
서비스 객체 목록

Items: SetServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID
-1:	애플리케이션	포트

Example:
Example

[{"srv_obj_id":	1}]

user: required (array of SetUserObject)
user
사용자 객체 목록

Items: SetUserObject
Items

usr_obj_type
usr_obj_type: required (integer)
사용자 타입
사용자:	1
사용자	그룹:	2
IP	매핑	사용자:	3
IP	매핑	사용자	그룹:	4
AD	사용자:	5
AD	사용자	그룹:	6
String	사용자:	7
KNOWN	사용자:	8
UNKNOWN	사용자:	9

usr_obj_id
usr_obj_id: (integer)
사용자 객체 ID  (usr_obj_type이	1일	때)

usr_grp_id
usr_grp_id: (integer)
사용자 그룹 객체 ID  (usr_obj_type이	2일	때)

ip_map_usr_id
ip_map_usr_id: (integer)
IP 매핑 사용자 객체 ID  (usr_obj_type이	3일	때)

ip_map_svr_id
ip_map_svr_id: (integer)
IP 매핑 서버 ID, ip_map_usr_id와 함께 설정  (usr_obj_type이	3일	때)

ip_map_grp_id
ip_map_grp_id: (integer)
IP 매핑 사용자 그룹 ID  (usr_obj_type이	4일	때)

ad_map_usr
ad_map_usr: required (string)
AD 사용자  (usr_obj_type이	5일	때)

ad_map_grp: required (string)
ad_map_grp
AD 사용자 그룹  (usr_obj_type이	6일	때)

str_name
str_name: required (string)
String 사용자 (usr_obj_type이	7일	때)
KNOWN 사용자(고정값: KNOWN) (usr_obj_type이	8일	때)
UNKNOWN 사용자(고정값: UNKNOWN) (usr_obj_type이	9일	때)

appapp: required (array of SetAppObject)
앱 객체 목록

Items: SetAppObject
Items

app_obj_id: required (integer)
app_obj_id
애플리케이션 객체 ID

app_obj_type
app_obj_type: required (one of 1, 2, 3)
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

Example:
Example

[{"app_obj_id":	30003,	"app_obj_type":	1}]

security_profile
security_profile: required (object)
보안 프로파일 설정 정보

ipsips: required (integer)
IPS 프로파일 ID

[IPS 프로파일 목록 조회]
GET	{{url}}/api/op/ips/profiles

avav: required (integer)
안티바이러스 프로파일 ID

[안티바이러스 프로파일 목록 조회]
GET	{{url}}/api/op/av/profiles

asas: required (integer)
안티스팸 프로파일 ID

[안티스팸 프로파일 목록 조회]
GET	{{url}}/api/op/as/profiles

wfwf: required (integer)
웹필터 프로파일 ID

[웹필터 프로파일 목록 조회]
GET	{{url}}/api/op/wf/profiles

dlpdlp: required (integer)
DLP 프로파일 ID

[DLP 프로파일 목록 조회]
GET	{{url}}/api/op/dlp/profiles

file_type
file_type: required (integer)
파일 유형 제어 프로파일 ID

[파일 유형 제어 프로파일 조회]
GET	{{url}}/api/op/filetype/profiles

aptapt: required (integer)
APT 프로파일 ID

[APT 프로파일 ID]
GET	{{url}}/api/op/apt/profiles

dnssec
dnssec: required (integer)
DNS 보안 프로파일 ID

[DNS 보안 프로파일 ID]
GET	{{url}}/api/op/dnssec/profiles

Example:
Example

{"ips":1,	"av":1,	"as":1,	"wf":1,	"dlp":1,	"file_type":1,	"apt":	1,	"dnssec":	1}

tagtag: required (array of 태그 객체)
태그 객체 목록

Items: 태그 객체
Items

tag_obj_id
tag_obj_id: required (integer)
태그 객체 ID

extheader
extheader: required (object)
확장 헤더

fragment
fragment: required (one of 0, 1)
Fragment
미사용:	0,	사용:	1

authauth: required (one of 0, 1)

인증
미사용:	0,	사용:	1

destdest: required (one of 0, 1)
목적지
미사용:	0,	사용:	1

espesp: required (one of 0, 1)
ESP
미사용:	0,	사용:	1

hophop: required (one of 0, 1)
Hop-by-Hop
미사용:	0,	사용:	1

routing
routing: required (one of 0, 1)
라우팅
미사용:	0,	사용:	1

Example:
Example

{
		"fw_grp_id":	1,
		"up_down":	1,
		"name":	"정책	이름",
		"desc":	"정책	설명",
		"use":	1,
		"action":	2,
		"bi_dir":	0,
		"log":	1,
		"tcp_flag":	0,
		"vlan_id":	"1,2,3,4,5",
		"sess_limit":	0,
		"sess_limit_val":	1000,
		"sess_limit_ip_block":	1000,
		"sess_limit_block":	0,
		"src":	[
				{"addr_obj_id":	1,	"excpt":	0}
		],
		"dst":	[
				{"addr_obj_id":	2,	"excpt":	0}
		],
		"srv":	[
				{"srv_obj_id":	1}
		],
		"user":	[{
				"usr_obj_type":	1,
				"usr_obj_id":	1
		},	{
				"usr_obj_type":	2,
				"usr_grp_id":	1
		}],
		"app":	[
				{"app_obj_id":	30003,	"app_obj_type":	1}
		],
		"security_profile":	{
				"ips":1,
				"av":1,
				"as":1,
				"wf":1,
				"dlp":1,
				"file_type":1,
				"apt":	1,
				"dnssec":	1
		},
		"time":	1,
		"tag":	[
				{"tag_obj_id":	1}
		],
		"extheader":	{
				"fragment":	1,
				"auth":	1,
				"dest":	1,
				"esp":	1,
				"hop":	1,
				"routing":	1
		}
}

Response

HTTP status code 200

방화벽 정책 수정 성공

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

fw_grp_id: required (integer)
fw_grp_id

그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

action
action: required (one of 1, 2, 3, 4)
동작 코드
허용:	1,	거부:	2,	거절(ICMP):	3,	거절(Reset):	4

bi_dir
bi_dir: required (one of 0, 1)
양방향 정책 설정
사용	안함:	0,	사용:	1

loglog: required (one of 0, 1)
로그 설정
사용	안함:	0,	사용:	1

tcp_flag: required (one of 0, 1)
tcp_flag
TCP 플래그
사용	안함:	0,	사용:	1

vlan_id
vlan_id: required (string - maxLength: 255)
VLAN ID를 콤마(,) 구분자로 연결한 문자열

Example:
Example

1,2,3,4,5

sess_limit
sess_limit: required (one of 0, 1, 2)
세션 제한 설정
미사용:	0,	전체	제한:	1,	정책	별	제한:	2

sess_limit_val
sess_limit_val: required (integer - default: 100000 - minimum: 60 - maximum: 2000000)
이 정책의 전체 세션 수 제한

sess_limit_ip_block
sess_limit_ip_block: required (integer - default: 10000 - minimum: 60 - maximum: 2000000)
각각의 출발지 IP당 세션 수 제한

sess_limit_block
sess_limit_block: required (one of 0, 1)
세션 수 초과 시 해당 IP의 모든 세션 차단 설정
사용	안함:	0,	사용:	1

fw_rule_id
fw_rule_id: required (integer)
정책 ID

seqseq: required (integer)
순번

time
time: required (object)
시간 객체

srcsrc: required (array of AddressObject)
출발지 객체 목록

Items: AddressObject
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
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

dstdst: required (array of AddressObject)
목적지 객체 목록

Items: AddressObject
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
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

srvsrv: required (array of ServiceObject)
서비스 객체 목록

Items: ServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2,	애플리케이션	포트:	3

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

user: required (array of GetUserObject)
user
사용자 객체 목록

Items: GetUserObject
Items

usr_obj_type
usr_obj_type: required (integer)
사용자 타입
사용자:	1
사용자	그룹:	2
IP	매핑	사용자:	3
IP	매핑	사용자	그룹:	4
AD	사용자:	5
AD	사용자	그룹:	6
String	사용자:	7
KNOWN	사용자:	8
UNKNOWN	사용자:	9

usr_obj_id
usr_obj_id: (integer)
사용자 객체 ID  (usr_obj_type이	1일	때)

usr_grp_id
usr_grp_id: (integer)
사용자 그룹 객체 ID  (usr_obj_type이	2일	때)

ip_map_usr_id
ip_map_usr_id: (integer)
IP 매핑 사용자 객체 ID  (usr_obj_type이	3일	때)

ip_map_svr_id
ip_map_svr_id: (integer)
IP 매핑 서버 ID, ip_map_usr_id와 함께 설정  (usr_obj_type이	3일	때)

ip_map_grp_id: (integer)
ip_map_grp_id
IP 매핑 사용자 그룹 ID  (usr_obj_type이	4일	때)

ad_map_usr
ad_map_usr: required (string)
AD 사용자  (usr_obj_type이	5일	때)

ad_map_grp
ad_map_grp: required (string)
AD 사용자 그룹  (usr_obj_type이	6일	때)

str_name
str_name: required (string)
String 사용자 (usr_obj_type이	7일	때)
KNOWN 사용자(고정값: KNOWN) (usr_obj_type이	8일	때)
UNKNOWN 사용자(고정값: UNKNOWN) (usr_obj_type이	9일	때)

login_id
login_id: required (string)
사용자 ID
(usr_obj_type이	1일	때)

usr_grp_dmn
usr_grp_dmn: required (string)
도메인
(usr_obj_type이	2일	때)

usr_grp_name: required (string)
usr_grp_name
사용자 그룹 이름
(usr_obj_type이	2일	때)

device
device: required (array of object)
디바이스 객체 목록
IPv6에서는	사용되지	않음

Items:
Items

appapp: required (array of GetAppObject)
앱 객체 목록

Items: GetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

app_obj_type: required (one of 1, 2, 3)
app_obj_type
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

name
name: required (string)
애플리케이션 관련 객체 이름
app_obj_type가	1일	경우	객체	이름
app_obj_type가	2일	경우	그룹	객체	이름
app_obj_type가	3일	경우	필터	객체	이름

security_profile
security_profile: required (object)
보안 프로파일 목록

Example:
Example

{
		"ips":	{"id":	1,	"name":	"default"},
		"av":	{"id":	1,	"name":	"default"},
		"as":	{"id":	1,	"name":	"default"},
		"wf":	{"id":	1,	"name":	"default"},
		"dlp":	{"id":	1,	"name":	"default"},
		"file_type":	{"id":	1,	"name":	"default"},
		"apt":	{"id":	1,	"name":	"default"},
		"dnssec":	{"id":	1,	"name":	"default"}
}

tagtag: required (array of 태그 객체)
태그 객체 목록

Items: 태그 객체
Items

tag_obj_id
tag_obj_id: required (integer)
태그 객체 ID

name
name: required (string - minLength: 1 - maxLength: 32)
객체명(공백 입력 불가)

color
color: required (string)
RGB 포맷의 컬러값

Example:
Example

#ff0000

qosqos: required (integer)
QoS 정책 설정 여부(조회만 가능)
미사용:	0,	사용:	1

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
				"fw_set_id":	1,
				"fw_grp_id":	1,
				"fw_rule_id":	1,
				"name":	"정책	이름",
				"desc":	"정책	설명",
				"seq":	1,
				"use":	1,
				"action":	2,
				"bi_dir":	0,
				"log":	1,
				"tcp_flag":	0,
				"vlan_id":	"1,2,3,4,5",
				"sess_limit":	0,
				"sess_limit_val":	1000,
				"sess_limit_ip_block":	1000,
				"sess_limit_block":	0,
				"src":	[
						{
								"addr_obj_id":	2,
								"ip_ver":	1,
								"name":	"test_host_obj_1",
								"zone":	1,
								"addr_obj_type":	1,
								"excpt":	0
						}
				],
				"dst":	[
						{
								"addr_obj_id":	3,
								"ip_ver":	1,
								"name":	"test_host_obj_11",
								"zone":	1,
								"addr_obj_type":	1,
								"excpt":	0
						}
				],
				"srv":	[
						{
								"srv_obj_id":	1,
								"srv_obj_type":	1,
								"name":	"AH",
								"pre_def":	1
						}
				],
				"user":	[{
						"usr_obj_id":	1,
						"login_id":	"gui1\\gui1",
						"usr_obj_type":	1,
						"type":	1
				},	{
						"usr_grp_id":	1,
						"usr_grp_dmn":	"test",
						"usr_grp_name":	"test",
						"usr_obj_type":	2
				}],

				"device":	[],
				"app":	[{
						"app_obj_id":	30003,
						"name":	"51.com",
						"app_obj_type":	1
				}],
				"security_profile":	{
						"ips":	{"id":	1,	"name":	"IPS	프로파일"},
						"av":	{"id":	1,	"name":	"안티바이러스	프로파일"},
						"as":	{"id":	1,	"name":	"안티스팸	프로파일"},
						"wf":	{"id":	1,	"name":	"웹필터	프로파일"},
						"dlp":	{"id":	1,	"name":	"DLP	프로파일"},
						"file_type":	{"id":	1,	"name":	"파일유형제어	프로파일"},
						"apt":	{"id":	1,	"name":	"APT	프로파일"},
						"dnssec":	{"id":	1,	"name":	"DNS	보안	프로파일"}
				},
				"time":	{
						"tm_obj_id":	1,
						"name":	"시간	객체",
						"expired":	"0",
						"week":	{
								"use":	1
						},
						"month":	{
								"use":	0
						},
						"year":	{
								"use":	0
						},
						"period":	{
								"use":	0
						}
				},
				"qos":	0,
				"tag":	[
						{
								"tag_obj_id":	1,
								"name":	"재택	정책	태그",
								"color":	"#ff0000"
						}
				],
				"extheader":	{
						"fragment":	1,
						"auth":	1,
						"dest":	1,
						"esp":	1,
						"hop":	1,
						"routing":	1
				},
				"last_hit_time":	"-",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-30	07:54:53"
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

/fw/6/rules/{pk}

방화벽 정책을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
정책 ID (fw_rule_id)

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

방화벽 정책 삭제 성공

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

dev_t: (string)
dev_t
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

/fw/6/rules/save

방화벽 정책을 PC로 저장합니다.

[Task 진행 상태 조회]
GET	{{url}}/api/co/async/tasks/{{task_id}}

[상태가 성공인 Task에 대해 엑셀 파일을 다운로드]
GET	{{url}}/api/co/async/tasks/{{task_id}}/save

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

Query Parameters

columns
columns: (string)
사용되지 않음

Example:
Example

?columns=(A,B,C)

Response

HTTP status code 202

방화벽 정책를 비동기로 파일 생성 시작

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

status: required (string)
status

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

/fw/6/rules/batch

방화벽 정책을 일괄 배치로 추가한다.

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

Properties
Properties

filefile: required (string)
파일 업로드 후 반환된 파일명을 인자로 전달
파일 업로드 API로 배치 파일 업로드 후 호출
https://{url}/api/co/file/import

excel_location: required (integer)
excel_location

엑셀 입력 위치(엑셀 Row를 읽는 순서)
위에서	아래:	1,	아래에서	위:	2

2.8.0에서	속성명과	속성값이	변경됨

force
force: required (integer)
IP 중복 입력
허용:	1,	차단:	0

2.8.0에서	속성명과	속성값이	변경됨

policy_location
policy_location: required (integer)
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

방화벽 정책 배치 배치 실행

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

방화벽 정책 배치 배치 실행 실패

PUT

/fw/6/rules/batch

방화벽 정책을 일괄적으로 비활성 또는 삭제를 수행한다.

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

filefile: required (string)
파일 업로드 후 응답 데이터의 파일명을 인자로 전달

[파일 업로드 API]
POST	{{url}}/api/co/file/import

Example:
Example

{
		"file":	"batch_file.xlsx"
}

Response

HTTP status code 202

방화벽 정책 배치 배치 실행

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

attributes: required (object)
attributes

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

방화벽 정책 배치 배치 실행 실패

GET

/fw/6/rules/batch/history

방화벽 정책 배치 이력 목록을 조회한다.

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

Response

HTTP status code 200

방화벽 정책 배치 이력 목록 조회 성공

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
result: required (array of BatchHistory)
결과 데이터

Items: BatchHistory
Items

filename
filename: required (string)
파일 이름

mtimemtime: required (string)
날짜

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"filename":	"fwv4_batch_20181121130209.tmp",
				"mtime":	"2018-11-21	04:02:09"
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

/fw/6/rules/batch/history

방화벽 정책 배치 이력 파일을 다운로드한다.

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

filename
filename: required (string)
파일 이름

Example:
Example

{
		"filename":	"fwv4_batch_20181121130209.tmp"
}

Response

HTTP status code 200

다운로드 성공

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

방화벽 정책 유효성 검사

PUT

/fw/6/rules-check

방화벽 정책 유효성을 검사한다.

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

Response

HTTP status code 200

방화벽 정책 배치 이력 수정 성공

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

정책 일괄 변경

PUT

/fw/6/bulk/rules

선택된 정책 목록을 일괄로 수정한다.

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

useuse: (one of 0, 1)
사용여부
0:	사용안함,	1:	사용

bi_dir
bi_dir: required (one of 0, 1)
양방향 정책 사용
0:	사용안함,	1:	사용

loglog: required (one of 0, 1)
로그
0:	사용안함,	1:	사용

tcp_flag
tcp_flag: required (one of 0, 1)
TCP 플래그 검사
0:	사용안함,	1:	사용

security_profile
security_profile: required (object)
보안 프로파일

ipsips: required (integer)
IPS 프로파일 ID

[IPS 프로파일 목록 조회]
GET	{{url}}/api/op/ips/profiles

avav: required (integer)
안티바이러스 프로파일 ID

[안티바이러스 프로파일 목록 조회]
GET	{{url}}/api/op/av/profiles

asas: required (integer)
안티스팸 프로파일 ID

[안티스팸 프로파일 목록 조회]
GET	{{url}}/api/op/as/profiles

wfwf: required (integer)
웹필터 프로파일 ID

[웹필터 프로파일 목록 조회]
GET	{{url}}/api/op/wf/profiles

dlpdlp: required (integer)
DLP 프로파일 ID

[DLP 프로파일 목록 조회]
GET	{{url}}/api/op/dlp/profiles

file_type
file_type: required (integer)
파일 유형 제어 프로파일 ID

[파일 유형 제어 프로파일 조회]
GET	{{url}}/api/op/filetype/profiles

aptapt: required (integer)
APT 프로파일 ID

[APT 프로파일 ID]
GET	{{url}}/api/op/apt/profiles

dnssec
dnssec: required (integer)
DNS 보안 프로파일 ID

[DNS 보안 프로파일 ID]
GET	{{url}}/api/op/dnssec/profiles

items
items: required (array of integer)
수정 될 정책 ID 목록

Example:
Example

[1,	2,	3,	4,	5]

Example:
Example

{
		"use":	1,
		"bi_dir":	0,
		"log":1,
		"tcp_flag":	0,
		"security_profile":	{
						"ips":	1,
						"av":	1,
						"as":	1,
						"wf":	1,
						"dlp":	1,
						"file_type":	1,
						"apt":	1,
						"dnssec":	1
		},
		"items":	[1,	2,	3,	4,	5]
}

Response

HTTP status code 200

정책 일괄 변경 목록 수정 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (one of ok, pok, nok)
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

/fw/6/bulk/rules

선택된 정책 목록을 일괄로 삭제한다.

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

error_check
error_check: (string)
적용 정책 검색 결과에 대해서 정책을 삭제 한 후 재 검색 시 삭제된 정책이 조회되지 않도록 하기위한 플래그
적용된 정책 검색에서 정책 삭제 시  no 로 설정이 필요하고 그 외는 생략하면 됨

items: required (array of integer)
items
정책 ID 목록

Example:
Example

{
		"items":	[1,	2,	3,	4,	5]
}

Response

HTTP status code 200

정책 일괄 변경 목록 삭제 성공

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

Example:
Example

{
		"code":	"ok",
		"result":	{}
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

정책 목록 이동

PUT

/fw/6/move/rules

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

fw_grp_id
fw_grp_id: required (integer)
그룹 ID

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
		"fw_grp_id":	5,
		"pre_rule_id":	10,
		"up_down":1,
		"items":	[1,	2,	3,	4,	5]
}

Response

HTTP status code 200

정책 목록 이동 목록 수정 성공

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

정책 상세 보기

GET

/fw/6/kernel/rules

정책 상세 보기 목록을 조회한다.

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

정책 상세 보기 목록 조회 성공

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
result: required (array of KernelRule)
결과 데이터

Items: KernelRule
Items

seqseq: required (string)
순번

useuse: required (string)
사용

bi_dir: required (string)
bi_dir
양방향

vlan_id
vlan_id: required (string)
VLAN ID 목록

szone
szone: required (string)
출발지 Zone
ANY:	A,	내부:	I,	외부:	E,	DMZ:	D

sipsip: required (string)
출발지 정보 목록(콤마로 구분)

user
user: required (string)
사용자 정보 목록(콤마로 구분)
LU:	Local	User,	IU:	IP	매핑	사용자,	AU:	AD	사용자,	AG:	AD	그룹	사용자,	KN:	Know	user,	UN:	Unknow	user,	ST:	String	user

dzone
dzone: required (string)
목적지 Zone
ANY:	A,	내부:	I,	외부:	E,	DMZ:	D

dipdip: required (string)
목적지 정보 목록(콤마로 구분)

appapp: required (string)
애플리케이션 목록(이름만 콤마로 구분)

portport: required (string)
서비스 정보

Example:
Example

[tcp	0-65535>2626]|[udp	0-65535>512,1604,6347]|[icmp	->9]

action
action: required (string)
동작 정보

time: required (string)
time
시간 정보

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"use":	"Y",
				"bi_dir":	"N",
				"seq":	"1",
				"fw_rule_id":	"46",
				"vlan_id":	"any",
				"szone":	"A",
				"sip":	"::/0",
				"dzone":	"A",
				"dip":	"::/0",
				"port":	"[tcp	0-65535>2626]|[udp	0-65535>512,1604,6347]|[icmp	->9]",
				"action":	"allow",
				"time":	"ANY",
				"user":	"LU	localuser,LG	groupuser",
				"app":	"ANY"
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

특정 정책 상세 보기

GET

/fw/6/kernel/sets/{sid}/rules/{rid}

특정 정책 상세 보기을(를) 조회한다.

Request

URI Parameters

sidsid: required (integer)
정책 세트 ID (fw_set_id)

ridrid: required (integer)
정책 ID (fw_rule_id)

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

특정 정책 상세 보기 조회 성공

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
result: required (array of KernelRule)
결과 데이터

Items: KernelRule
Items

seqseq: required (string)
순번

useuse: required (string)
사용

bi_dir
bi_dir: required (string)
양방향

vlan_id
vlan_id: required (string)
VLAN ID 목록

szone
szone: required (string)
출발지 Zone
ANY:	A,	내부:	I,	외부:	E,	DMZ:	D

sipsip: required (string)
출발지 정보 목록(콤마로 구분)

user
user: required (string)
사용자 정보 목록(콤마로 구분)
LU:	Local	User,	IU:	IP	매핑	사용자,	AU:	AD	사용자,	AG:	AD	그룹	사용자,	KN:	Know	user,	UN:	Unknow	user,	ST:	String	user

dzone
dzone: required (string)
목적지 Zone
ANY:	A,	내부:	I,	외부:	E,	DMZ:	D

dipdip: required (string)
목적지 정보 목록(콤마로 구분)

appapp: required (string)
애플리케이션 목록(이름만 콤마로 구분)

portport: required (string)
서비스 정보

Example:
Example

[tcp	0-65535>2626]|[udp	0-65535>512,1604,6347]|[icmp	->9]

action
action: required (string)
동작 정보

time
time: required (string)
시간 정보

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"use":	"Y",
				"bi_dir":	"N",
				"seq":	"1",
				"fw_rule_id":	"46",
				"vlan_id":	"any",
				"szone":	"A",
				"sip":	"0.0.0.0/0",
				"dzone":	"A",
				"dip":	"0.0.0.0/0",
				"port":	"[tcp	0-65535>2626]|[udp	0-65535>512,1604,6347]|[icmp	->9]",
				"dvc":	"DM	device1,DM	device2,DG	dvc_group",
				"action":	"allow",
				"time":	"ANY",
				"user":	"LU	localuser,LG	groupuser",
				"app":	"ANY"
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

정책 내용 검색

POST

/fw/6/content-rules/search

방화벽 정책 내용을 검색한다.

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

useuse: required (one of 0, 1, 2)
사용
미사용:	0,	사용:	1,	ALL:	2

direction: required (integer)
direction
방향
양방향:	1,	단방향:	2,	ALL:	3

vlanvlan: required (string)
VLAN ID(문자열)
1 ~ 4096 범위의 숫자

fw_rule_id
fw_rule_id: required (array of integer)
정책 ID 목록
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

src_case
src_case: required (string)
'대소문자 구분', '완전 일치', '객체 내용 검색', '관련 정보(객체)포함' 옵션 순으로 선택 여부를 표시한 문자열
'IP 검색' 옵션이 V3.0에서 추가
0:	선택	안됨,	1:	선택됨

Example:
Example

"11110"	->	모두	선택된	경우

user
user: required (string - maxLength: 48)
사용자
도메인\사용자ID 또는 사용자ID

user_case
user_case: required (string)
'대소문자 구분', '완전 일치', '관련 정보(객체)포함' 옵션 순으로 선택 여부를 표시한 문자열
0:	선택	안됨,	1:	선택됨

Example:
Example

"111"	->	모두	선택된	경우

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

appapp: required (string - maxLength: 48)
애플리케이션(객체 이름)

app_case
app_case: required (string)
'대소문자 구분', '완전 일치' 옵션 순으로 선택 여부를 표시한 문자열
0:	선택	안됨,	1:	선택됨

Example:
Example

"11"	->	모두	선택된	경우

service: required (array of string)
service
서비스 객체 이름 목록
객체	이름은	최대	48자	입력	가능

Example:
Example

["obj1",	"obj2"]

srv_operator
srv_operator: required (one of 1, 2)
서비스 검색 조건
AND:	1,	OR:	2

service_case: required (string)
service_case
'대소문자 구분', '완전 일치', '객체 내용 검색', '관련 정보(객체)포함' 옵션 순으로 선택 여부를 표시한 문자열
0:	선택	안됨,	1:	선택됨

Example:
Example

"1111"	->	모두	선택된	경우

action
action: required (one of 1, 2, 3, 4, 5)
동작
허용:	1,	거부:	2,	거절(ICMP):	3,	거절(Reset):	4,	ALL:	5

etcetc: required (string - maxLength: 48)
기타 객체 이름
시간객체,	보안	프로파일

etc_case
etc_case: required (string)
'대소문자 구분', '완전 일치' 옵션 선택 여부를 표시하는 문자열
0:	선택	안됨,	1:	선택됨

Example:
Example

"11"	->	모두	선택된	경우

descdesc: required (string - maxLength: 256)
설명

desc_case
desc_case: required (string)
'대소문자 구분', '완전 일치' 옵션 선택 여부를 표시하는 문자열
0:	선택	안됨,	1:	선택됨

Example:
Example

"11"	->	모두	선택된	경우

create_dt
create_dt: (string)
정책 생성일(optional)
형식:	YYYYMMDDYYYYMMDD

Example:
Example

"2020010120191231"

Example:
Example

{
		"use":	0,
		"fw_rule_id":	[1,	2],
		"src":	["10::10_IH"],
		"src_operator":	1,
		"src_case":	"11110",
		"user":	"",
		"user_case":	"000",
		"dst":	["11::11_IH"],
		"dst_operator":	1,
		"dst_case":	"11110",
		"app":	"",
		"app_case":	"00",
		"service":	["AH"],
		"srv_operator":	1,
		"service_case":	"0000",
		"action":	1,
		"direction":	1,
		"vlan":	1000,
		"etc":	"",
		"etc_case":	"00",
		"desc":	"",
		"desc_case":	"00"
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

fw_set_id
fw_set_id: required (integer)
세트 ID

fw_rule_id
fw_rule_id: required (integer)
정책 ID

seqseq: required (integer)
순번

cfg_create_dt
cfg_create_dt: required (string)
정책 생성일

objobj: required (array of RelObject)
관련 객체 정보

Items: RelObject
Items

target
target: required (string)
검색 항목
src:	출발지,	dst:	목적지,	svc:	서비스,	aut:	사용자,	app:	애플리케이션

name
name: required (string)
객체 이름/사용자

detail
detail: required (string)
상세 정보

zone: (one of 1, 2, 3)
zone
Zone 정보, target이 src, dst인 경우 출력( 내부:	1,	외부:	2,	DMZ:	3 )

type
type: required (string)
문자열 형식의 객체 타입
host,	network,	grp,	domain.....

Example:
Example

{
		"code":	"ok",
		"result":	{
				"rule":	[{
						"fw_set_id":	1,
						"fw_rule_id":	1,
						"seq":	1,
						"cfg_create_dt":	"2019-01-06	09:20:23"
				}],
				"obj":	[{
						"target":	"src",
						"name":	"test_host_obj",
						"detail":	"Auto	created(Fw)",
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

POST

/fw/6/content-rules/search/save

비동기로 엑셀파일을 저장한다.

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

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties

fw_rule_id: required (array of integer)
fw_rule_id
검색된 방화벽 정책 ID 목록

Example:
Example

[1,	2,	3]

Response

HTTP status code 202

정책 내용 검색를 비동기로 파일 생성 시작

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

시간 만료 정책 검색

POST

/fw/6/expire-rules/search

시간 만료 정책을 검색한다.

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

tm_type
tm_type: required (one of 1, 2)
만료 기한 타입
1:	만료	기한,	2:	만료	기준일(날짜)

expired
expired: required (integer - minimum: 0 - maximum: 365)
만료 기한
tm_type	이	1일	때	필수	속성

expired_date
expired_date: required (string)
만료 기준일(날짜: YYYYMMDD)
tm_type	이	2일	때	필수	속성

Example:
Example

20200101

unuse_rule
unuse_rule: required (integer)
비활성화된 정책 포함 여부
포함:	1,	미포함:	0

Example:
Example

{
		"tm_type":	1,
		"expired":	10,
		"unuse_rule":	0
}

or

{
		"tm_type":	2,
		"expired_date":	"20200101",
		"unuse_rule":	0
}

Response

HTTP status code 200

시간 만료 정책 검색 추가 성공

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
result: required (array of ExpireSearchResult)
결과 데이터

Items: ExpireSearchResult
Items

seqseq: required (integer)
순번

fw_rule_id
fw_rule_id: required (integer)
정책 ID

expired: required (string)
expired
남은 기간

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"seq":	1,
				"fw_rule_id":	1,
				"expired":	"Expired(-1	day)"
		},	{
				"seq":	2,
				"fw_rule_id":	2,
				"expired":	"1	day	1	hr	2	mins	2secs"
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

POST

/fw/6/expire-rules/search/save

비동기로 엑셀파일을 저장한다.

[Task 진행 상태 조회]
GET	{{url}}/api/co/async/tasks/{{task_id}}

[상태가 성공인 Task에 대해 엑셀 파일을 다운로드]
GET	{{url}}/api/co/async/tasks/{{task_id}}/save

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

fw_rule_id: required (array of integer)
fw_rule_id
검색된 방화벽 정책 ID 목록

Example:
Example

[1,	2,	3]

Response

HTTP status code 202

시간 만료 정책 검색를 비동기로 파일 생성 시작

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

status: required (string)
status
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

Shadow 정책 검색

POST

/fw/6/shadow-rules/search

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

fw_rule_id
fw_rule_id: required (integer - minimum: 1 - maximum: 99999999)
정책 ID

unuse_rule
unuse_rule: required (integer)
비활성화된 정책 포함 여부
포함:	1,	미포함:	0

tm_check
tm_check: required (integer)
정책 기간 필터 사용 여부
사용:	1,	미사용:	0

Example:
Example

{
		"fw_rule_id":	1,
		"unuse_rule":	0,
		"tm_check":	1
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
code: required (string)
code
결과 코드

result
result: required (array of ShadowSearchResult)
결과 데이터

Items: ShadowSearchResult
Items

seqseq: required (integer)
순번

fw_rule_id
fw_rule_id: required (integer)
정책 ID

s_fw_rule_id: required (integer)
s_fw_rule_id
상위 정책 ID

descdesc: required (string)
설명

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"seq":	1,
				"fw_rule_id":	1,
				"s_fw_rule_id":	2,
				"desc":	"Completely	shadowed"
		},	{
				"seq":	2,
				"fw_rule_id":	2,
				"s_fw_rule_id":	4,
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

POST

/fw/6/shadow-rules/search/save

비동기로 엑셀파일을 저장한다.

[Task 진행 상태 조회]
GET	{{url}}/api/co/async/tasks/{{task_id}}

[상태가 성공인 Task에 대해 엑셀 파일을 다운로드]
GET	{{url}}/api/co/async/tasks/{{task_id}}/save

Request

Annotations

Lib.SupportedVersion:
Lib.SupportedVersion

"2.0.0"

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

Properties
Properties

fw_rule_id
fw_rule_id: required (array of integer)
검색된 방화벽 정책 ID 목록

Example:
Example

[1,	2,	3]

Response

HTTP status code 202

Shadow 정책 검색를 비동기로 파일 생성 시작

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

결과 메시지

idid: required (string)
태스크 ID

status: required (string)
status
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

적용 정책 검색

POST

/fw/6/apply-rules/search

적용 정책을 검색한다.

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

Properties
Properties
zone
zone: required (integer)
유입 Zone
내부:	1,	외부:	2,	DMZ:	3

protocol
protocol: required (integer)
프로토콜 ID(prtc_obj_id)
프로토콜	목록	조회:	https://{{url}}/api/op/service/protocols

vlanvlan: required (integer - minimum: 1 - maximum: 4094)
VLAN ID

srcsrc: required (string)
출발지 주소(IPv4 형식)

src_port: required (integer)
src_port

출발지 포트
프로토콜이 TCP, UDP일 때 입력 가능
TCP:	0~65535,	UDP:	0~65535

dstdst: required (string)
목적지 주소(IPv4 형식)

dst_port
dst_port: required (integer)
목적지 포트
프로토콜이 ICMP, TCP, UDP일 때 입력 가능
ICMP:	0~255,	TCP:	0~65535,	UDP:	0~65535

time
time: required (string)
유입 시간

Example:
Example

2018-01-01	12:12:12

appapp: required (string - minLength: 0 - maxLength: 48)
애플리케이션 이름

Example:
Example

{
		"zone":	1,
		"protocol":	5,
		"vlan":	1000,
		"src":	"10.10.10.10",
		"src_port":	"65535",
		"dst":	"20.20.20.20",
		"dst_port":	"65535",
		"time":	"2018-01-01	12:10:10",
		"app":	"exampleapp"
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

result
result: required (array of ApplyRuleSearchResult)
결과 데이터

Items: ApplyRuleSearchResult
Items

seqseq: required (integer)
순번

fw_rule_id
fw_rule_id: required (integer)
정책 ID

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"seq":	1,
				"fw_rule_id":	1
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

미참조 정책 검색

POST

/fw/6/unuse-rules/search

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

fw_rule_id
fw_rule_id: required (integer)
정책 ID

name
name: required (string)
정책명

unref_days
unref_days: required (integer)
미참조 일
빈	값일	수	있음

cfg_create_dt
cfg_create_dt: required (string)
정책 생성일

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"seq":	1,
				"fw_rule_id":	1,
				"name":	"fw_rule_name_1",
				"unref_days":	1,
				"cfg_create_dt":	"2018-01-01"
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

POST

/fw/6/unuse-rules/search/save

비동기로 엑셀파일을 저장한다.

[Task 진행 상태 조회]
GET	{{url}}/api/co/async/tasks/{{task_id}}

[상태가 성공인 Task에 대해 엑셀 파일을 다운로드]
GET	{{url}}/api/co/async/tasks/{{task_id}}/save

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

fw_rule_id: required (array of integer)
fw_rule_id
검색된 방화벽 정책 ID 목록

Example:
Example

[1,	2,	3]

datedate: required (integer - minimum: 1 - maximum: 365)
최종 검색에 사용된  미참조일

recent_rule
recent_rule: required (one of 0, 1)
최종 검색에 사용된  최근	생성일	포함	여부
0:	미포함,	1:	포함

Response

HTTP status code 202

미참조 정책 검색를 비동기로 파일 생성 시작

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
결과 메시지

idid: required (string)
태스크 ID

status
status: required (string)
태스크 상태
PENDING,	PROCESS,	FAILURE,	REVOKED,	SUCCESS

attributes: required (string)
attributes
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

미참조 객체 검색

GET

/fw/6/unuse-objects/search/days/{days}

미참조 객체를 검색한다.

Request

URI Parameters

daysdays: required (integer - minimum: 1 - maximum: 365)
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

미참조 객체 검색 목록 조회 성공

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

zone: required (integer)
zone
Zone
내부:	I,	외부:	E,	DMZ:	D

type
type: required (string)
객체 타입
호스트:	host
네트워크:	network
그룹:	group
서비스:	service
서비스	그룹:	service_group
애플리케이션:	app

unuse_date
unuse_date: required (integer)
미참조 일
-1:	현재까지	참조기록	없음

cfg_create_dt
cfg_create_dt: required (string)
객체 생성일

ref_fw_set_id
ref_fw_set_id: required (integer)
참조 이력 세트 ID

ref_fw_rule_id
ref_fw_rule_id: required (integer)
참조 이력 정책 ID

fw_rule
fw_rule: required (array of UnuseFw)
정책 목록

Items: UnuseFw
Items

fw_set_id
fw_set_id: required (integer)
세트 ID

fw_rule_id
fw_rule_id: required (integer)
정책 ID

cfg_create_dt: required (string)
cfg_create_dt
정책 생성일

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"obj_id":	1,
				"name":	"10.10.10.10_IH",
				"zone":	1,
				"type":	"host",
				"unuse_date":	1,
				"cfg_create_dt":	"2021-10-22	16:18:19",
				"ref_fw_set_id":	1,
				"ref_fw_rule_id":	1,
				"fw_rule":	[{
						"fw_set_id":	1,
						"fw_rule_id":	1,
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

GET

/fw/6/unuse-objects/search/days/{days}/save?columns=(객체 타입,객체 이름,참조 이력 정책 ID,미참조 일자,객체 생성일,정책 ID,정책생성일)

비동기로 검색된 미참조 객체를 엑셀로 저장한다.
Task 상태 조회:  GET	/api/co/async/tasks/{task_id}
종료된 Task에 대해 엑셀 다운로드:  GET	/api/co/async/tasks/{task_id}/save

Request

URI Parameters

daysdays: required (integer - minimum: 1 - maximum: 365)
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

Query Parameters

columns
columns: (string)
다운로드되는 엑셀 파일 내 테이블 헤더 값으로 사용될 값을 전달한다.(데이터 테이블에 표시되는 컬럼 순으로 지정)
columns 쿼리스트링에 값이 없을 경우 백엔드에 정의된 속성명으로 표시됩니다.
한글이	포함될	수	있기	때문에	UTF-8	인코딩되어야	합니다.

Example:
Example

?columns=(객체	타입,객체	이름,참조	이력	정책	ID,미참조	일자,객체	생성일,정책	ID,정책생성일)

Response

HTTP status code 202

미참조 객체 검색를 비동기로 파일 생성 시작

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
result: required (AsyncResult)
결과 메시지

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

QoS

GET

/fw/6/sets/{sid}/rules/{rid}/qos/profiles

사용 중인 QoS 목록을 조회한다.

Request

URI Parameters

sidsid: required (integer)
정책 세트 ID (fw_set_id)

ridrid: required (integer)
정책 ID (fw_rule_id)

Annotations

Lib.SupportedVersion:
Lib.SupportedVersion

"2.0.0"

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

사용 중인 QoS 목록 조회 성공

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
result: required (array of QosProfile)
결과 데이터

Items: QosProfile
Items

qos_prf_id
qos_prf_id: required (integer)
QoS 프로파일 ID

qos_prf_name
qos_prf_name: required (string)
QoS 프로파일 이름

qos_class_id
qos_class_id: required (integer)
QoS 큐 ID

qos_class_name: required (string)
qos_class_name
QoS 큐 이름

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"qos_prf_id":	1,
				"qos_prf_name":	"QoS	프로파일명",
				"qos_class_id":	"1",
				"qos_class_name":	"큐	이름"
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

방화벽 현재 세션

DELETE

/fw/6/session

방화벽 현재 세션을 삭제 또는 조건으로 삭제한다.

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

fw_rule_id
fw_rule_id: required (integer - minimum: 0 - maximum: 99999999)
방화벽 정책 ID(세션 삭제: 필수, 조건 삭제: 옵션)
ANY:	0	또는	null

vlanvlan: required (integer - minimum: 1 - maximum: 4094)
VLAN ID

sipsip: required (string)
출발지 IP(IPv4)
ANY:	문자열	'0'	또는	null

sip_mask
sip_mask: required (integer - minimum: 0 - maximum: 128)
출발지 서브넷 마스크
ANY:	0	또는	null

sport
sport: required (integer - minimum: 0 - maximum: 65535)
출발지 포트
ANY:	0	또는	null

dipdip: required (string)
목적지 IP(IPv4)
ANY:	문자열	'0'	또는	null

dip_mask
dip_mask: required (integer - minimum: 0 - maximum: 128)
목적지 서브넷 마스크
ANY:	0	또는	null

dport
dport: required (integer - minimum: 0 - maximum: 65535)
목적지 포트
ANY:	0	또는	null

proto
proto: required (integer)
프로토콜 ID
ANY:	0	또는	null
https://{url}/api/op/service/protocols	로	프로토콜	목록	조회

Response

HTTP status code 200

세션 삭제/조건 삭제 삭제 성공

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

방화벽 정책(객체 자동 생성 기능)

POST

/fw/6/auto/rules

방화벽 정책을 추가한다.
출발지, 목적지에 객체ID 뿐만 아니라 IP를 설정할 수 있다. IP로 설정될 경우 호스트객체 또는 네트워크 객체를 자동으로 생성한 후 정책 추가에 사용된다.

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

Properties
Properties

fw_grp_id: required (integer)
fw_grp_id
그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

action: required (one of 1, 2, 3, 4)
action
동작 코드
허용:	1,	거부:	2,	거절(ICMP):	3,	거절(Reset):	4

bi_dir
bi_dir: required (one of 0, 1)
양방향 정책 설정
사용	안함:	0,	사용:	1

loglog: required (one of 0, 1)
로그 설정
사용	안함:	0,	사용:	1

tcp_flag
tcp_flag: required (one of 0, 1)
TCP 플래그
사용	안함:	0,	사용:	1

vlan_id
vlan_id: required (string - maxLength: 255)
VLAN ID를 콤마(,) 구분자로 연결한 문자열

Example:
Example

1,2,3,4,5

sess_limit
sess_limit: required (one of 0, 1, 2)
세션 제한 설정
미사용:	0,	전체	제한:	1,	정책	별	제한:	2

sess_limit_val: required (integer - default: 100000 - minimum: 60 - maximum: 2000000)
sess_limit_val
이 정책의 전체 세션 수 제한

sess_limit_ip_block
sess_limit_ip_block: required (integer - default: 10000 - minimum: 60 - maximum: 2000000)
각각의 출발지 IP당 세션 수 제한

sess_limit_block: required (one of 0, 1)
sess_limit_block
세션 수 초과 시 해당 IP의 모든 세션 차단 설정
사용	안함:	0,	사용:	1

pre_rule_id
pre_rule_id: (integer)
기준이 되는 정책 ID

up_down: required (one of 1, 2)
up_down
기준이 되는 정책의 위/아래 위치 지정
위:	1,	아래:	2

time
time: required (integer)
시간 객체 ID

srcsrc: required (array of SetAddrObject)

출발지 객체 목록

Items: SetAddrObject
Items

addr_obj_id: required (integer)
addr_obj_id
주소 객체 ID

addr_obj_type
addr_obj_type: (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: (one of 0, 1)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

Example:
Example

[{"addr_obj_id":	1,	"addr_obj_type":	1,	"excpt":	0}]

dstdst: required (array of SetAddrObject)
목적지 객체 목록

Items: SetAddrObject
Items

addr_obj_id: required (integer)
addr_obj_id
주소 객체 ID

addr_obj_type
addr_obj_type: (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt: (one of 0, 1)
excpt
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

Example:
Example

[{"addr_obj_id":	1,	"addr_obj_type":	1,	"excpt":	0}]

srvsrv: required (array of SetServiceObject)
서비스 객체 목록

Items: SetServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID
-1:	애플리케이션	포트

Example:
Example

[{"srv_obj_id":	1}]

user
user: required (array of SetUserObject)
사용자 객체 목록

Items: SetUserObject
Items

usr_obj_type
usr_obj_type: required (integer)
사용자 타입
사용자:	1
사용자	그룹:	2
IP	매핑	사용자:	3
IP	매핑	사용자	그룹:	4
AD	사용자:	5
AD	사용자	그룹:	6
String	사용자:	7
KNOWN	사용자:	8
UNKNOWN	사용자:	9

usr_obj_id
usr_obj_id: (integer)
사용자 객체 ID  (usr_obj_type이	1일	때)

usr_grp_id
usr_grp_id: (integer)
사용자 그룹 객체 ID  (usr_obj_type이	2일	때)

ip_map_usr_id
ip_map_usr_id: (integer)
IP 매핑 사용자 객체 ID  (usr_obj_type이	3일	때)

ip_map_svr_id
ip_map_svr_id: (integer)
IP 매핑 서버 ID, ip_map_usr_id와 함께 설정  (usr_obj_type이	3일	때)

ip_map_grp_id
ip_map_grp_id: (integer)
IP 매핑 사용자 그룹 ID  (usr_obj_type이	4일	때)

ad_map_usr
ad_map_usr: required (string)
AD 사용자  (usr_obj_type이	5일	때)

ad_map_grp
ad_map_grp: required (string)
AD 사용자 그룹  (usr_obj_type이	6일	때)

str_name
str_name: required (string)
String 사용자 (usr_obj_type이	7일	때)
KNOWN 사용자(고정값: KNOWN) (usr_obj_type이	8일	때)
UNKNOWN 사용자(고정값: UNKNOWN) (usr_obj_type이	9일	때)

appapp: required (array of SetAppObject)
앱 객체 목록

Items: SetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

app_obj_type
app_obj_type: required (one of 1, 2, 3)
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

Example:
Example

[{"app_obj_id":	30003,	"app_obj_type":	1}]

security_profile
security_profile: required (object)
보안 프로파일 설정 정보

ipsips: required (integer)
IPS 프로파일 ID

[IPS 프로파일 목록 조회]
GET	{{url}}/api/op/ips/profiles

avav: required (integer)
안티바이러스 프로파일 ID

[안티바이러스 프로파일 목록 조회]
GET	{{url}}/api/op/av/profiles

asas: required (integer)
안티스팸 프로파일 ID

[안티스팸 프로파일 목록 조회]
GET	{{url}}/api/op/as/profiles

wfwf: required (integer)
웹필터 프로파일 ID

[웹필터 프로파일 목록 조회]
GET	{{url}}/api/op/wf/profiles

dlpdlp: required (integer)
DLP 프로파일 ID

[DLP 프로파일 목록 조회]
GET	{{url}}/api/op/dlp/profiles

file_type: required (integer)
file_type
파일 유형 제어 프로파일 ID

[파일 유형 제어 프로파일 조회]
GET	{{url}}/api/op/filetype/profiles

aptapt: required (integer)
APT 프로파일 ID

[APT 프로파일 ID]
GET	{{url}}/api/op/apt/profiles

dnssec
dnssec: required (integer)
DNS 보안 프로파일 ID

[DNS 보안 프로파일 ID]
GET	{{url}}/api/op/dnssec/profiles

Example:
Example

{"ips":1,	"av":1,	"as":1,	"wf":1,	"dlp":1,	"file_type":1,	"apt":	1,	"dnssec":	1}

tagtag: required (array of 태그 객체)
태그 객체 목록

Items: 태그 객체
Items

tag_obj_id
tag_obj_id: required (integer)
태그 객체 ID

extheader
extheader: required (object)
확장 헤더

fragment
fragment: required (one of 0, 1)
Fragment
미사용:	0,	사용:	1

authauth: required (one of 0, 1)
인증
미사용:	0,	사용:	1

destdest: required (one of 0, 1)
목적지
미사용:	0,	사용:	1

espesp: required (one of 0, 1)
ESP
미사용:	0,	사용:	1

hophop: required (one of 0, 1)
Hop-by-Hop
미사용:	0,	사용:	1

routing
routing: required (one of 0, 1)
라우팅
미사용:	0,	사용:	1

Example:
Example

{
		"fw_grp_id":	5,
		"up_down":	1,
		"name":	"New	정책	이름",
		"desc":	"New	정책	설명",
		"use":	1,
		"action":	1,
		"bi_dir":	0,
		"log":	1,
		"tcp_flag":	0,
		"vlan_id":	"",
		"sess_limit":	1,
		"sess_limit_val":	10000,
		"sess_limit_ip_block":	1000,
		"sess_limit_block":	0,
		"src":	[
				{"ip":	"1234::5678",	"zone":	1,	"excpt":	1},
				{"ip":	"1234::5678/128",	"zone":	1,	"excpt":	0}
		],
		"dst":	[
				{"ip":	"1234::5678",	"zone":	1,	"excpt":	1},
				{"ip":	"1234::5678/128",	"zone":	1,	"excpt":	0}
		],
		"srv":	[],
		"user":	[],
		"device":	[],
		"app":	[],
		"security_profile":	{},
		"time":	{
				"name":	"prefix_2020110720201110",
				"week":	{
								"sun":	{"use":	0,	"exp":	["00002359"]},
								"mon":	{"use":	1,	"exp":	["08001830"]},
								"tue":	{"use":	1,	"exp":	["08001830"]},
								"wed":	{"use":	1,	"exp":	["08001830"]},
								"thu":	{"use":	1,	"exp":	["08001830"]},
								"fri":	{"use":	1,	"exp":	["08001830"]},
								"sat":	{"use":	0,	"exp":	["08001830"]}
				},
				"month":	{"use":	0,	"week":	"000000",	"period":	"18-18",	"days":	"0000000000000000000000000000000"},
				"year":	{"use":	0,	"exp":	"000000000000"},
				"period":	{"use":	1,	"exp":	["202101010000202110102359",	"202110110000202112312359"]}
		},
		"routing_marker":	null
}

Response

HTTP status code 200

방화벽 정책 추가 성공

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

fw_grp_id
fw_grp_id: required (integer)
그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

action: required (one of 1, 2, 3, 4)
action
동작 코드
허용:	1,	거부:	2,	거절(ICMP):	3,	거절(Reset):	4

bi_dir
bi_dir: required (one of 0, 1)
양방향 정책 설정
사용	안함:	0,	사용:	1

loglog: required (one of 0, 1)
로그 설정
사용	안함:	0,	사용:	1

tcp_flag
tcp_flag: required (one of 0, 1)
TCP 플래그
사용	안함:	0,	사용:	1

vlan_id
vlan_id: required (string - maxLength: 255)
VLAN ID를 콤마(,) 구분자로 연결한 문자열

Example:
Example

1,2,3,4,5

sess_limit
sess_limit: required (one of 0, 1, 2)
세션 제한 설정
미사용:	0,	전체	제한:	1,	정책	별	제한:	2

sess_limit_val
sess_limit_val: required (integer - default: 100000 - minimum: 60 - maximum: 2000000)
이 정책의 전체 세션 수 제한

sess_limit_ip_block
sess_limit_ip_block: required (integer - default: 10000 - minimum: 60 - maximum: 2000000)
각각의 출발지 IP당 세션 수 제한

sess_limit_block
sess_limit_block: required (one of 0, 1)
세션 수 초과 시 해당 IP의 모든 세션 차단 설정
사용	안함:	0,	사용:	1

fw_rule_id
fw_rule_id: required (integer)
정책 ID

seqseq: required (integer)
순번

time
time: required (object)
시간 객체

srcsrc: required (array of AddressObject)
출발지 객체 목록

Items: AddressObject
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
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

dstdst: required (array of AddressObject)
목적지 객체 목록

Items: AddressObject
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
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

srvsrv: required (array of ServiceObject)
서비스 객체 목록

Items: ServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2,	애플리케이션	포트:	3

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

user
user: required (array of GetUserObject)
사용자 객체 목록

Items: GetUserObject
Items

usr_obj_type
usr_obj_type: required (integer)
사용자 타입
사용자:	1
사용자	그룹:	2

IP	매핑	사용자:	3
IP	매핑	사용자	그룹:	4
AD	사용자:	5
AD	사용자	그룹:	6
String	사용자:	7
KNOWN	사용자:	8
UNKNOWN	사용자:	9

usr_obj_id
usr_obj_id: (integer)
사용자 객체 ID  (usr_obj_type이	1일	때)

usr_grp_id: (integer)
usr_grp_id
사용자 그룹 객체 ID  (usr_obj_type이	2일	때)

ip_map_usr_id
ip_map_usr_id: (integer)
IP 매핑 사용자 객체 ID  (usr_obj_type이	3일	때)

ip_map_svr_id
ip_map_svr_id: (integer)
IP 매핑 서버 ID, ip_map_usr_id와 함께 설정  (usr_obj_type이	3일	때)

ip_map_grp_id
ip_map_grp_id: (integer)
IP 매핑 사용자 그룹 ID  (usr_obj_type이	4일	때)

ad_map_usr
ad_map_usr: required (string)
AD 사용자  (usr_obj_type이	5일	때)

ad_map_grp
ad_map_grp: required (string)
AD 사용자 그룹  (usr_obj_type이	6일	때)

str_name
str_name: required (string)
String 사용자 (usr_obj_type이	7일	때)
KNOWN 사용자(고정값: KNOWN) (usr_obj_type이	8일	때)
UNKNOWN 사용자(고정값: UNKNOWN) (usr_obj_type이	9일	때)

login_id: required (string)
login_id
사용자 ID
(usr_obj_type이	1일	때)

usr_grp_dmn
usr_grp_dmn: required (string)
도메인
(usr_obj_type이	2일	때)

usr_grp_name: required (string)
usr_grp_name
사용자 그룹 이름
(usr_obj_type이	2일	때)

device
device: required (array of object)
디바이스 객체 목록
IPv6에서는	사용되지	않음

Items:
Items

appapp: required (array of GetAppObject)
앱 객체 목록

Items: GetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

app_obj_type: required (one of 1, 2, 3)
app_obj_type
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

name
name: required (string)
애플리케이션 관련 객체 이름
app_obj_type가	1일	경우	객체	이름
app_obj_type가	2일	경우	그룹	객체	이름
app_obj_type가	3일	경우	필터	객체	이름

security_profile
security_profile: required (object)
보안 프로파일 목록

Example:
Example

{
		"ips":	{"id":	1,	"name":	"default"},
		"av":	{"id":	1,	"name":	"default"},
		"as":	{"id":	1,	"name":	"default"},
		"wf":	{"id":	1,	"name":	"default"},
		"dlp":	{"id":	1,	"name":	"default"},
		"file_type":	{"id":	1,	"name":	"default"},
		"apt":	{"id":	1,	"name":	"default"},
		"dnssec":	{"id":	1,	"name":	"default"}
}

tagtag: required (array of 태그 객체)
태그 객체 목록

Items: 태그 객체
Items

tag_obj_id: required (integer)
tag_obj_id
태그 객체 ID

name
name: required (string - minLength: 1 - maxLength: 32)
객체명(공백 입력 불가)

color
color: required (string)
RGB 포맷의 컬러값

Example:
Example

#ff0000

qosqos: required (integer)
QoS 정책 설정 여부(조회만 가능)
미사용:	0,	사용:	1

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
				"fw_set_id":	1,
				"fw_grp_id":	5,
				"fw_grp_name":	"default",
				"fw_rule_id":	1,
				"name":	"auto_ruleId_1",
				"desc":	"",
				"seq":	1,
				"use":	1,
				"action":	1,
				"bi_dir":	0,
				"log":	1,
				"tcp_flag":	0,
				"vlan_id":	"",
				"sess_limit":	0,
				"sess_limit_val":	10000,
				"sess_limit_ip_block":	1000,
				"sess_limit_block":	0,
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_create_dt":	"2020-11-11	20:10:25",
				"cfg_dt":	"2020-11-11	20:10:25",
				"src":	[{
						"addr_obj_id":	2,
						"ip_ver":	1,
						"name":	"test_host_obj_1",
						"zone":	1,
						"addr_obj_type":	1,
						"cloud_ref":	0,
						"excpt":	0
				}],
				"dst":	[{
						"addr_obj_id":	3,
						"ip_ver":	1,
						"name":	"test_host_obj_11",
						"zone":	1,
						"addr_obj_type":	1,
						"cloud_ref":	0,
						"excpt":	0
				}],
				"srv":	[{
						"srv_obj_id":	1,
						"srv_obj_type":	1,
						"name":	"AH",
						"pre_def":	1
				}],
				"user":	[{
						"usr_obj_id":	1,
						"login_id":	"example\\test_user1",
						"usr_obj_type":	1,
						"type":	1
				},	{
						"usr_grp_id":	1,
						"usr_grp_dmn":	"test",
						"usr_grp_name":	"test",
						"usr_obj_type":	2
				}],
				"device":	[{
						"dvc_obj_id":	1,
						"name":	"Device	객체	이름",
						"desc":	"Device	객체	설명",
						"cfg_adm_id":	1,
						"cfg_adm":	"admin",
						"cfg_dt":	"2019-02-07	17:57:15",
						"cfg_layer":	0,
						"dvc_obj_type":	1
				},	{
						"dvc_grp_id":	1,
						"name":	"Device	Group	객체	이름",
						"desc":	"Device	Group	객체	설명",
						"cfg_adm":	"admin",
						"cfg_dt":	"2019-02-07	17:57:15",
						"cfg_layer":	0,
						"dvc_obj_type":	2
				}],
				"app":	[{
						"port":	"TCP	80",
						"app_obj_type":	1
						"app_obj_id":	30003,
						"name":	"51.com"
				}],
				"security_profile":	{
						"ips":	{"id":	1,	"name":	"IPS	프로파일"},
						"av":	{"id":	1,	"name":	"안티바이러스	프로파일"},
						"as":	{"id":	1,	"name":	"안티스팸	프로파일"},
						"wf":	{"id":	1,	"name":	"웹필터	프로파일"},
						"dlp":	{"id":	1,	"name":	"DLP	프로파일"},
						"file_type":	{"id":	1,	"name":	"파일유형제어	프로파일"},
						"apt":	{"id":	1,	"name":	"APT	프로파일"}
				},

				"time":	{
						"tm_obj_id":	1,
						"name":	"시간	객체",
						"expired":	"202011101830",
						"week":	{
								"use":	1
						},
						"month":	{
								"use":	0
						},
						"year":	{
								"use":	0
						},
						"period":	{
								"use":	1
						}
				},
				"qos":	0,
				"routing_marker":	{},
				"last_hit_time":	"-"
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

PUT

/fw/6/auto/rules

방화벽 정책을 수정한다.
출발지, 목적지에 객체ID 뿐만 아니라 IP를 설정할 수 있다. IP로 설정될 경우 호스트객체 또는 네트워크 객체를 자동으로 생성한 후 정책 수정에 사용된다.

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

fw_grp_id
fw_grp_id: required (integer)
그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

action
action: required (one of 1, 2, 3, 4)
동작 코드
허용:	1,	거부:	2,	거절(ICMP):	3,	거절(Reset):	4

bi_dir
bi_dir: required (one of 0, 1)
양방향 정책 설정
사용	안함:	0,	사용:	1

loglog: required (one of 0, 1)
로그 설정
사용	안함:	0,	사용:	1

tcp_flag
tcp_flag: required (one of 0, 1)
TCP 플래그
사용	안함:	0,	사용:	1

vlan_id
vlan_id: required (string - maxLength: 255)
VLAN ID를 콤마(,) 구분자로 연결한 문자열

Example:
Example

1,2,3,4,5

sess_limit
sess_limit: required (one of 0, 1, 2)
세션 제한 설정
미사용:	0,	전체	제한:	1,	정책	별	제한:	2

sess_limit_val: required (integer - default: 100000 - minimum: 60 - maximum: 2000000)
sess_limit_val
이 정책의 전체 세션 수 제한

sess_limit_ip_block
sess_limit_ip_block: required (integer - default: 10000 - minimum: 60 - maximum: 2000000)
각각의 출발지 IP당 세션 수 제한

sess_limit_block
sess_limit_block: required (one of 0, 1)
세션 수 초과 시 해당 IP의 모든 세션 차단 설정
사용	안함:	0,	사용:	1

pre_rule_id
pre_rule_id: (integer)
기준이 되는 정책 ID

up_down
up_down: required (one of 1, 2)
기준이 되는 정책의 위/아래 위치 지정
위:	1,	아래:	2

time
time: required (integer)
시간 객체 ID

srcsrc: required (array of SetAddrObject)
출발지 객체 목록

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID

addr_obj_type: (integer)
addr_obj_type

객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: (one of 0, 1)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

Example:
Example

[{"addr_obj_id":	1,	"addr_obj_type":	1,	"excpt":	0}]

dstdst: required (array of SetAddrObject)
목적지 객체 목록

Items: SetAddrObject
Items

addr_obj_id: required (integer)
addr_obj_id
주소 객체 ID

addr_obj_type
addr_obj_type: (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: (one of 0, 1)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

Example:
Example

[{"addr_obj_id":	1,	"addr_obj_type":	1,	"excpt":	0}]

srvsrv: required (array of SetServiceObject)
서비스 객체 목록

Items: SetServiceObject
Items

srv_obj_id: required (integer)
srv_obj_id
서비스 객체 ID
-1:	애플리케이션	포트

Example:
Example

[{"srv_obj_id":	1}]

user
user: required (array of SetUserObject)
사용자 객체 목록

Items: SetUserObject
Items

usr_obj_type
usr_obj_type: required (integer)
사용자 타입
사용자:	1
사용자	그룹:	2
IP	매핑	사용자:	3
IP	매핑	사용자	그룹:	4
AD	사용자:	5
AD	사용자	그룹:	6
String	사용자:	7
KNOWN	사용자:	8
UNKNOWN	사용자:	9

usr_obj_id: (integer)
usr_obj_id
사용자 객체 ID  (usr_obj_type이	1일	때)

usr_grp_id
usr_grp_id: (integer)
사용자 그룹 객체 ID  (usr_obj_type이	2일	때)

ip_map_usr_id
ip_map_usr_id: (integer)
IP 매핑 사용자 객체 ID  (usr_obj_type이	3일	때)

ip_map_svr_id
ip_map_svr_id: (integer)
IP 매핑 서버 ID, ip_map_usr_id와 함께 설정  (usr_obj_type이	3일	때)

ip_map_grp_id
ip_map_grp_id: (integer)
IP 매핑 사용자 그룹 ID  (usr_obj_type이	4일	때)

ad_map_usr: required (string)
ad_map_usr
AD 사용자  (usr_obj_type이	5일	때)

ad_map_grp
ad_map_grp: required (string)
AD 사용자 그룹  (usr_obj_type이	6일	때)

str_name
str_name: required (string)
String 사용자 (usr_obj_type이	7일	때)
KNOWN 사용자(고정값: KNOWN) (usr_obj_type이	8일	때)
UNKNOWN 사용자(고정값: UNKNOWN) (usr_obj_type이	9일	때)

appapp: required (array of SetAppObject)
앱 객체 목록

Items: SetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

app_obj_type
app_obj_type: required (one of 1, 2, 3)
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

Example:
Example

[{"app_obj_id":	30003,	"app_obj_type":	1}]

security_profile
security_profile: required (object)
보안 프로파일 설정 정보

ipsips: required (integer)

IPS 프로파일 ID

[IPS 프로파일 목록 조회]
GET	{{url}}/api/op/ips/profiles

avav: required (integer)
안티바이러스 프로파일 ID

[안티바이러스 프로파일 목록 조회]
GET	{{url}}/api/op/av/profiles

asas: required (integer)
안티스팸 프로파일 ID

[안티스팸 프로파일 목록 조회]
GET	{{url}}/api/op/as/profiles

wfwf: required (integer)
웹필터 프로파일 ID

[웹필터 프로파일 목록 조회]
GET	{{url}}/api/op/wf/profiles

dlpdlp: required (integer)
DLP 프로파일 ID

[DLP 프로파일 목록 조회]
GET	{{url}}/api/op/dlp/profiles

file_type
file_type: required (integer)
파일 유형 제어 프로파일 ID

[파일 유형 제어 프로파일 조회]
GET	{{url}}/api/op/filetype/profiles

aptapt: required (integer)
APT 프로파일 ID

[APT 프로파일 ID]
GET	{{url}}/api/op/apt/profiles

dnssec
dnssec: required (integer)
DNS 보안 프로파일 ID

[DNS 보안 프로파일 ID]
GET	{{url}}/api/op/dnssec/profiles

Example:
Example

{"ips":1,	"av":1,	"as":1,	"wf":1,	"dlp":1,	"file_type":1,	"apt":	1,	"dnssec":	1}

tagtag: required (array of 태그 객체)
태그 객체 목록

Items: 태그 객체
Items

tag_obj_id
tag_obj_id: required (integer)
태그 객체 ID

extheader
extheader: required (object)
확장 헤더

fragment
fragment: required (one of 0, 1)
Fragment
미사용:	0,	사용:	1

authauth: required (one of 0, 1)
인증
미사용:	0,	사용:	1

destdest: required (one of 0, 1)
목적지
미사용:	0,	사용:	1

espesp: required (one of 0, 1)
ESP
미사용:	0,	사용:	1

hophop: required (one of 0, 1)
Hop-by-Hop
미사용:	0,	사용:	1

routing
routing: required (one of 0, 1)
라우팅
미사용:	0,	사용:	1

Example:
Example

{
		"fw_grp_id":	5,
		"up_down":	1,
		"name":	"New	정책	이름",
		"desc":	"New	정책	설명",
		"use":	1,
		"action":	1,
		"bi_dir":	0,
		"log":	1,
		"tcp_flag":	0,
		"vlan_id":	"",
		"sess_limit":	1,
		"sess_limit_val":	10000,
		"sess_limit_ip_block":	1000,
		"sess_limit_block":	0,
		"src":	[
				{"ip":	"1234::5678",	"zone":	1,	"excpt":	1},
				{"ip":	"1234::5678/128",	"zone":	1,	"excpt":	0}
		],
		"dst":	[
				{"ip":	"1234::5678",	"zone":	1,	"excpt":	1},
				{"ip":	"1234::5678/128",	"zone":	1,	"excpt":	0}
		],
		"srv":	[],
		"user":	[],
		"device":	[],
		"app":	[],
		"security_profile":	{},
		"time":	{
				"name":	"prefix_2020110720201110",
				"week":	{
								"sun":	{"use":	0,	"exp":	["00002359"]},
								"mon":	{"use":	1,	"exp":	["08001830"]},
								"tue":	{"use":	1,	"exp":	["08001830"]},
								"wed":	{"use":	1,	"exp":	["08001830"]},
								"thu":	{"use":	1,	"exp":	["08001830"]},
								"fri":	{"use":	1,	"exp":	["08001830"]},
								"sat":	{"use":	0,	"exp":	["08001830"]}
				},
				"month":	{"use":	0,	"week":	"000000",	"period":	"18-18",	"days":	"0000000000000000000000000000000"},
				"year":	{"use":	0,	"exp":	"000000000000"},
				"period":	{"use":	1,	"exp":	["202101010000202110102359",	"202110110000202112312359"]}
		},
		"routing_marker":	null
}

Response

HTTP status code 200

방화벽 정책 목록 수정 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (one of ok, pok, nok)
code
결과 코드

result
result: required (object)
결과 데이터

fw_grp_id
fw_grp_id: required (integer)
그룹 ID

name
name: required (string - maxLength: 31)
정책 이름
정책	추가	시에는	선택,	편집	시에는	필수

descdesc: (string - maxLength: 256)
설명

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

action: required (one of 1, 2, 3, 4)
action
동작 코드
허용:	1,	거부:	2,	거절(ICMP):	3,	거절(Reset):	4

bi_dir
bi_dir: required (one of 0, 1)
양방향 정책 설정
사용	안함:	0,	사용:	1

loglog: required (one of 0, 1)
로그 설정
사용	안함:	0,	사용:	1

tcp_flag
tcp_flag: required (one of 0, 1)
TCP 플래그
사용	안함:	0,	사용:	1

vlan_id
vlan_id: required (string - maxLength: 255)
VLAN ID를 콤마(,) 구분자로 연결한 문자열

Example:
Example

1,2,3,4,5

sess_limit
sess_limit: required (one of 0, 1, 2)
세션 제한 설정
미사용:	0,	전체	제한:	1,	정책	별	제한:	2

sess_limit_val
sess_limit_val: required (integer - default: 100000 - minimum: 60 - maximum: 2000000)
이 정책의 전체 세션 수 제한

sess_limit_ip_block
sess_limit_ip_block: required (integer - default: 10000 - minimum: 60 - maximum: 2000000)
각각의 출발지 IP당 세션 수 제한

sess_limit_block
sess_limit_block: required (one of 0, 1)
세션 수 초과 시 해당 IP의 모든 세션 차단 설정
사용	안함:	0,	사용:	1

fw_rule_id
fw_rule_id: required (integer)
정책 ID

seqseq: required (integer)
순번

time
time: required (object)
시간 객체

srcsrc: required (array of AddressObject)
출발지 객체 목록

Items: AddressObject
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
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

dstdst: required (array of AddressObject)
목적지 객체 목록

Items: AddressObject
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
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4,	도메인객체:	5,	클라우드객체:	7

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

srvsrv: required (array of ServiceObject)
서비스 객체 목록

Items: ServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2,	애플리케이션	포트:	3

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

user
user: required (array of GetUserObject)
사용자 객체 목록

Items: GetUserObject
Items

usr_obj_type
usr_obj_type: required (integer)
사용자 타입
사용자:	1
사용자	그룹:	2

IP	매핑	사용자:	3
IP	매핑	사용자	그룹:	4
AD	사용자:	5
AD	사용자	그룹:	6
String	사용자:	7
KNOWN	사용자:	8
UNKNOWN	사용자:	9

usr_obj_id
usr_obj_id: (integer)
사용자 객체 ID  (usr_obj_type이	1일	때)

usr_grp_id: (integer)
usr_grp_id
사용자 그룹 객체 ID  (usr_obj_type이	2일	때)

ip_map_usr_id
ip_map_usr_id: (integer)
IP 매핑 사용자 객체 ID  (usr_obj_type이	3일	때)

ip_map_svr_id
ip_map_svr_id: (integer)
IP 매핑 서버 ID, ip_map_usr_id와 함께 설정  (usr_obj_type이	3일	때)

ip_map_grp_id
ip_map_grp_id: (integer)
IP 매핑 사용자 그룹 ID  (usr_obj_type이	4일	때)

ad_map_usr
ad_map_usr: required (string)
AD 사용자  (usr_obj_type이	5일	때)

ad_map_grp
ad_map_grp: required (string)
AD 사용자 그룹  (usr_obj_type이	6일	때)

str_name
str_name: required (string)
String 사용자 (usr_obj_type이	7일	때)
KNOWN 사용자(고정값: KNOWN) (usr_obj_type이	8일	때)
UNKNOWN 사용자(고정값: UNKNOWN) (usr_obj_type이	9일	때)

login_id: required (string)
login_id
사용자 ID
(usr_obj_type이	1일	때)

usr_grp_dmn
usr_grp_dmn: required (string)
도메인
(usr_obj_type이	2일	때)

usr_grp_name: required (string)
usr_grp_name
사용자 그룹 이름
(usr_obj_type이	2일	때)

device
device: required (array of object)
디바이스 객체 목록
IPv6에서는	사용되지	않음

Items:
Items

appapp: required (array of GetAppObject)
앱 객체 목록

Items: GetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

app_obj_type: required (one of 1, 2, 3)
app_obj_type
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

name
name: required (string)
애플리케이션 관련 객체 이름
app_obj_type가	1일	경우	객체	이름
app_obj_type가	2일	경우	그룹	객체	이름
app_obj_type가	3일	경우	필터	객체	이름

security_profile
security_profile: required (object)
보안 프로파일 목록

Example:
Example

{
		"ips":	{"id":	1,	"name":	"default"},
		"av":	{"id":	1,	"name":	"default"},
		"as":	{"id":	1,	"name":	"default"},
		"wf":	{"id":	1,	"name":	"default"},
		"dlp":	{"id":	1,	"name":	"default"},
		"file_type":	{"id":	1,	"name":	"default"},
		"apt":	{"id":	1,	"name":	"default"},
		"dnssec":	{"id":	1,	"name":	"default"}
}

tagtag: required (array of 태그 객체)
태그 객체 목록

Items: 태그 객체
Items

tag_obj_id: required (integer)
tag_obj_id
태그 객체 ID

name
name: required (string - minLength: 1 - maxLength: 32)
객체명(공백 입력 불가)

color
color: required (string)
RGB 포맷의 컬러값

Example:
Example

#ff0000

qosqos: required (integer)
QoS 정책 설정 여부(조회만 가능)
미사용:	0,	사용:	1

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
				"fw_set_id":	1,
				"fw_grp_id":	5,
				"fw_grp_name":	"default",
				"fw_rule_id":	1,
				"name":	"auto_ruleId_1",
				"desc":	"",
				"seq":	1,
				"use":	1,
				"action":	1,
				"bi_dir":	0,
				"log":	1,
				"tcp_flag":	0,
				"vlan_id":	"",
				"sess_limit":	0,
				"sess_limit_val":	10000,
				"sess_limit_ip_block":	1000,
				"sess_limit_block":	0,
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_create_dt":	"2020-11-11	20:10:25",
				"cfg_dt":	"2020-11-11	20:10:25",
				"src":	[{
						"addr_obj_id":	2,
						"ip_ver":	1,
						"name":	"test_host_obj_1",
						"zone":	1,
						"addr_obj_type":	1,
						"cloud_ref":	0,
						"excpt":	0
				}],
				"dst":	[{
						"addr_obj_id":	3,
						"ip_ver":	1,
						"name":	"test_host_obj_11",
						"zone":	1,
						"addr_obj_type":	1,
						"cloud_ref":	0,
						"excpt":	0
				}],
				"srv":	[{
						"srv_obj_id":	1,
						"srv_obj_type":	1,
						"name":	"AH",
						"pre_def":	1
				}],
				"user":	[{
						"usr_obj_id":	1,
						"login_id":	"example\\test_user1",
						"usr_obj_type":	1,
						"type":	1
				},	{
						"usr_grp_id":	1,
						"usr_grp_dmn":	"test",
						"usr_grp_name":	"test",
						"usr_obj_type":	2
				}],
				"device":	[{
						"dvc_obj_id":	1,
						"name":	"Device	객체	이름",
						"desc":	"Device	객체	설명",
						"cfg_adm_id":	1,
						"cfg_adm":	"admin",
						"cfg_dt":	"2019-02-07	17:57:15",
						"cfg_layer":	0,
						"dvc_obj_type":	1
				},	{
						"dvc_grp_id":	1,
						"name":	"Device	Group	객체	이름",
						"desc":	"Device	Group	객체	설명",
						"cfg_adm":	"admin",
						"cfg_dt":	"2019-02-07	17:57:15",
						"cfg_layer":	0,
						"dvc_obj_type":	2
				}],
				"app":	[{
						"port":	"TCP	80",
						"app_obj_type":	1
						"app_obj_id":	30003,
						"name":	"51.com"
				}],
				"security_profile":	{
						"ips":	{"id":	1,	"name":	"IPS	프로파일"},
						"av":	{"id":	1,	"name":	"안티바이러스	프로파일"},
						"as":	{"id":	1,	"name":	"안티스팸	프로파일"},
						"wf":	{"id":	1,	"name":	"웹필터	프로파일"},
						"dlp":	{"id":	1,	"name":	"DLP	프로파일"},
						"file_type":	{"id":	1,	"name":	"파일유형제어	프로파일"},
						"apt":	{"id":	1,	"name":	"APT	프로파일"}
				},

				"time":	{
						"tm_obj_id":	1,
						"name":	"시간	객체",
						"expired":	"202011101830",
						"week":	{
								"use":	1
						},
						"month":	{
								"use":	0
						},
						"year":	{
								"use":	0
						},
						"period":	{
								"use":	1
						}
				},
				"qos":	0,
				"routing_marker":	{},
				"last_hit_time":	"-"
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

IPv6 방화벽 정책 설정 적용/취소

PUT

/command/fw-6-policies/apply

IPv6 방화벽 정책 설정을 적용합니다.

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

mod_rule
mod_rule: (one of 0, 1)
GUI	에서만	사용되는	속성
GUI 접속 계정이 아닐 경우 해당 속성은 무시됨

force: (one of 0, 1)
force
0 : 정책 적용 시 컬럼 별 Any 정책 확인이 차단인 경우 경고 메시지 출력
1 : 정책 적용 시 컬럼 별 Any 정책 확인이 차단인 경우도 정책 적용 수행

Example:
Example

{}

Response

HTTP status code 200

IPv6 방화벽 정책 설정 적용 성공

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

/command/fw-6-policies/cancel

IPv6 방화벽 정책 설정을 취소합니다.

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

IPv6 방화벽 정책 설정 취소 성공

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

Example:
Example

{
		"code":	"ok",
		"result":	{}
}

