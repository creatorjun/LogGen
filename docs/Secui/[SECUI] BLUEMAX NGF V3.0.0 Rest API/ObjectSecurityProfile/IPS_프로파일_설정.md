IPS 프로파일 설정 REST API 문서

https://{url}/api/op

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/op

IPS 프로파일 설정

/ips/profiles

/ips/profiles/{pk}

/ips/profiles/config/ips_on_off

/ips/profiles/config/oversubscription

/ips/profiles/signature-temp

/ips/profiles/protect-level

/ips/profiles/exceptions

/ips/profiles/signatures/{pk}/use-profiles

/ips/profiles/signatures/{pk}/update-profiles

IPS 프로파일 옵션 설정 적용/취소

/command/ips-profiles-config/apply

/command/ips-profiles-config/cancel

IPS 프로파일 설정 적용/취소

/command/ips-profiles/apply

/command/ips-profiles/cancel

비정상 프로토콜

/ips/profiles/{ppk}/abnormal-protocols

/ips/profiles/{ppk}/abnormal-protocols/exceptions

/ips/profiles/{ppk}/abnormal-protocols/{pk}/exceptions

비정상 프로토콜 적용/취소

/command/ips-abnormal-protocols/apply

/command/ips-abnormal-protocols/cancel

프로토콜 취약점 방어

/ips/profiles/{ppk}/protocol-vulners

/ips/profiles/{ppk}/protocol-vulners/exceptions

/ips/profiles/{ppk}/protocol-vulners/{pk}/exceptions

프로토콜 취약점 방어 적용/취소

/command/ips-protocol-vulners/apply

/command/ips-protocol-vulners/cancel

비정상 애플리케이션 방어

/ips/profiles/{ppk}/abnormal-apps

/ips/profiles/{ppk}/abnormal-apps/exceptions

/ips/profiles/{ppk}/abnormal-apps/{pk}/exceptions

GET

GET

POST

  DELETE

PUT

  DELETE

GET

PUT

GET

PUT

GET

GET

GET

GET

PUT

PUT

PUT

PUT

PUT

GET

PUT

PUT

GET

PUT

PUT

GET

PUT

PUT

GET

PUT

PUT

GET

PUT

PUT

GET

비정상 애플리케이션 방어 적용/취소

/command/ips-abnormal-apps/apply

/command/ips-abnormal-apps/cancel

시그니처

/ips/profiles/{ppk}/signatures

PUT

PUT

GET

PUT

  DELETE

/ips/profiles/{ppk}/signatures/save?columns=(IPS 시그니처 ID, 사용 여부, 카테고리, 메시지, 프로토콜, 출발지 포트, 목적지 포트, 예외 호스트, 대응, 차단 시간, 위험도, 탐
지 정확도, 성능 영향도, 로그 사용여부, 덤프 사용여부, 이메일 사용여부)

GET

GET

POST

GET

PUT

  DELETE

POST

PUT

  DELETE

PUT

GET

PUT

PUT

DELETE

DELETE

/ips/profiles/{ppk}/signatures/{pk}/detail

/ips/profiles/{ppk}/signatures/user-define

/ips/profiles/{ppk}/signatures/{pk}/user-define

/ips/profiles/{ppk}/signatures/snort

/ips/profiles/{ppk}/signatures/{pk}/snort

/ips/profiles/{ppk}/signatures/exceptions

/ips/profiles/{ppk}/signatures/{pk}/exceptions

시그니처 적용/취소

/command/ips-signatures/apply

/command/ips-signatures/cancel

IPS/DDoS 현재 상태

/ips/status/attackers

/ips/status/attacker/reset

IPS 프로파일 설정

GET

/ips/profiles

IPS 프로파일 설정 목록을 조회한다.

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

Response

HTTP status code 200

IPS 프로파일 설정 목록 조회 성공

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
result: required (array of ResIpsProfile)
결과 데이터

Items: ResIpsProfile
Items

base_signtr_tmplt_id
base_signtr_tmplt_id: required (integer - default: 1)
기본 시그니처 템플릿 ID

prtect_rqst_level_id: required (integer - default: 3)
prtect_rqst_level_id
보호요구 수준 ID

action
action: required (integer - default: 0)
탐지 여부
탐지:	0,	차단:	1

name
name: required (string)
이름

descdesc: required (string)
설명

ips_prf_id
ips_prf_id: required (integer - default: 1)
프로파일 ID

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ips_prf_id":	1,
				"base_signtr_tmplt_id":	1,
				"prtect_rqst_level_id":	3,
				"action":	0,
				"name":	"default",
				"desc":	"default	profile"
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

/ips/profiles

IPS 프로파일 설정를 추가한다.

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

base_signtr_tmplt_id
base_signtr_tmplt_id: required (integer - default: 1)
기본 시그니처 템플릿 ID

prtect_rqst_level_id
prtect_rqst_level_id: required (integer - default: 3)
보호요구 수준 ID

action
action: required (integer - default: 0)
탐지 여부
탐지:	0,	차단:	1

name
name: required (string)
이름

descdesc: required (string)
설명

Example:
Example

{
		"base_signtr_tmplt_id":	1,
		"prtect_rqst_level_id":	3,
		"action":	0,
		"name":	"IPS	프로파일	이름	1",
		"desc":	"IPS	프로파일	설명	1"
}

Response

HTTP status code 200

IPS 프로파일 설정 추가 성공

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

base_signtr_tmplt_id: required (integer - default: 1)
base_signtr_tmplt_id

기본 시그니처 템플릿 ID

prtect_rqst_level_id
prtect_rqst_level_id: required (integer - default: 3)
보호요구 수준 ID

action: required (integer - default: 0)
action
탐지 여부
탐지:	0,	차단:	1

name
name: required (string)
이름

descdesc: required (string)
설명

ips_prf_id
ips_prf_id: required (integer - default: 1)
프로파일 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ips_prf_id":	1,
				"base_signtr_tmplt_id":	1,
				"prtect_rqst_level_id":	3,
				"action":	0,
				"name":	"IPS	프로파일	이름	1",
				"desc":	"IPS	프로파일	설명	1"
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

DELETE

/ips/profiles

IPS 프로파일 설정 목록을 (일괄)삭제한다.

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
items: required (array of object)
items
삭제 아이템 목록
default	프로파일(ips_prf_id:	1)	삭제	불가

Example:
Example

{
		"items":	[
				{"ips_prf_id":	2},
				{"ips_prf_id":	3}
		]
}

Response

HTTP status code 200

IPS 프로파일 설정 목록 삭제 성공

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

/ips/profiles/{pk}

IPS 프로파일 설정을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
프로파일 ID ( ips_prf_id )

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

IPS 프로파일 설정 조회 성공

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

base_signtr_tmplt_id
base_signtr_tmplt_id: required (integer - default: 1)
기본 시그니처 템플릿 ID

prtect_rqst_level_id
prtect_rqst_level_id: required (integer - default: 3)
보호요구 수준 ID

action
action: required (integer - default: 0)
탐지 여부
탐지:	0,	차단:	1

name
name: required (string)
이름

descdesc: required (string)
설명

ips_prf_id
ips_prf_id: required (integer - default: 1)
프로파일 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ips_prf_id":	1,
				"base_signtr_tmplt_id":	1,
				"prtect_rqst_level_id":	3,
				"action":	0,
				"name":	"IPS	프로파일	이름	1",
				"desc":	"IPS	프로파일	설명	1"
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

PUT

/ips/profiles/{pk}

IPS 프로파일 설정을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)

프로파일 ID ( ips_prf_id )

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

base_signtr_tmplt_id
base_signtr_tmplt_id: required (integer - default: 1)
기본 시그니처 템플릿 ID

prtect_rqst_level_id
prtect_rqst_level_id: required (integer - default: 3)
보호요구 수준 ID

action
action: required (integer - default: 0)
탐지 여부
탐지:	0,	차단:	1

name
name: required (string)
이름

descdesc: required (string)
설명

Example:
Example

{
		"base_signtr_tmplt_id":	2,
		"prtect_rqst_level_id":	2,
		"action":	1,
		"name":	"IPS	프로파일	이름	2",
		"desc":	"IPS	프로파일	설명	2"
}

Response

HTTP status code 200

IPS 프로파일 설정 수정 성공

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

base_signtr_tmplt_id
base_signtr_tmplt_id: required (integer - default: 1)
기본 시그니처 템플릿 ID

prtect_rqst_level_id
prtect_rqst_level_id: required (integer - default: 3)
보호요구 수준 ID

action
action: required (integer - default: 0)
탐지 여부
탐지:	0,	차단:	1

name: required (string)
name
이름

descdesc: required (string)
설명

ips_prf_id
ips_prf_id: required (integer - default: 1)
프로파일 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ips_prf_id":	1,
				"base_signtr_tmplt_id":	2,
				"prtect_rqst_level_id":	2,
				"action":	1,
				"name":	"IPS	프로파일	이름	2",
				"desc":	"IPS	프로파일	설명	2"
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

/ips/profiles/{pk}

IPS 프로파일 설정을(를) 삭제한다.
default	프로파일(pk:	1)	삭제	불가

Request

URI Parameters

pkpk: required (integer)
프로파일 ID ( ips_prf_id )

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

IPS 프로파일 설정 삭제 성공

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

/ips/profiles/config/ips_on_off

IPS 사용 여부을(를) 조회한다.

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

IPS 사용 여부 조회 성공

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

value1: required (string)
value1
속성값1
사용안함:	0,	사용:	1

value2
value2: required (string)
속성값2

value3: required (string)
value3
속성값3

name
name: required (string)
속성명

Example:
Example

{
		"code":	"ok",
		"result":	{
				"name":	"ips_on_off",
				"value1":	"1",
				"value2":	null,
				"value3":	null
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

/ips/profiles/config/ips_on_off

IPS 사용 여부을(를) 수정한다.

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
value1
value1: required (string)
속성값1
사용안함:	0,	사용:	1

value2
value2: required (string)
속성값2

value3
value3: required (string)
속성값3

Example:
Example

{
		"value1":	"1"
}

Response

HTTP status code 200

IPS 사용 여부 수정 성공

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

value1
value1: required (string)
속성값1
사용안함:	0,	사용:	1

value2: required (string)
value2
속성값2

value3
value3: required (string)
속성값3

name
name: required (string)
속성명

Example:
Example

{
		"code":	"ok",
		"result":	{
				"name":	"ips_on_off",
				"value1":	"1",
				"value2":	null,
				"value3":	null
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

/ips/profiles/config/oversubscription

Oversubscription 사용 여부을(를) 조회한다.

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

Oversubscription 사용 여부 조회 성공

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

value1
value1: required (string)
속성값1
사용안함:	0,	사용:	1

value2
value2: required (string)
속성값2

value3
value3: required (string)
속성값3

name
name: required (string)
속성명

Example:
Example

{
		"code":	"ok",
		"result":	{
				"name":	"oversubscription",
				"value1":	"0",
				"value2":	null,
				"value3":	null
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

/ips/profiles/config/oversubscription

Oversubscription 사용 여부을(를) 수정한다.

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
value1
value1: required (string)
속성값1
사용안함:	0,	사용:	1

value2: required (string)
value2
속성값2

value3
value3: required (string)
속성값3

Example:
Example

{
		"value1":	"1",
		"value2":	null,
		"value3":	null
}

Response

HTTP status code 200

Oversubscription 사용 여부 수정 성공

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

value1
value1: required (string)
속성값1
사용안함:	0,	사용:	1

value2
value2: required (string)
속성값2

value3
value3: required (string)
속성값3

name
name: required (string)
속성명

Example:
Example

{
		"code":	"ok",
		"result":	{
				"name":	"oversubscription",
				"value1":	"1",
				"value2":	null,
				"value3":	null
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

/ips/profiles/signature-temp

시그니처 템플릿 목록을 조회한다.

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

Query Parameters

qq: required (string)
쿼리 파라메터  한국어:	1,	영어:	2,	일어:	3

Example:
Example

q=lang=1

Response

HTTP status code 200

시그니처 템플릿 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of IpsProfileSignatureTemplate)
result
결과 데이터

Items: IpsProfileSignatureTemplate
Items

base_signtr_tmplt_id
base_signtr_tmplt_id: required (integer - default: 1)
기본 시그니처 템플릿 ID

name
name: required (string)
시그니처 템플릿 이름

tagtag: required (string)
시그니처 종류 나열

descdesc: required (string)
설명

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"base_signtr_tmplt_id":	1,
				"name":	"시그니처	템플릿",
				"tag":	"시그니처	종류",
				"desc":	"시그니처	설명"
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

GET

/ips/profiles/protect-level

보호 요구 수준 목록을 조회한다.

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

qq: required (string)

쿼리 파라메터  한국어:	1,	영어:	2,	일어:	3

Example:
Example

q=lang=1

Response

HTTP status code 200

보호 요구 수준 목록 조회 성공

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
result: required (array of IpsProfileProtectLevel)
결과 데이터

Items: IpsProfileProtectLevel
Items

prtect_rqst_level_id
prtect_rqst_level_id: required (integer - default: 1)
보호요구 수준 ID

name
name: required (string)
보호요구 이름

cmdcmd: required (string)
보호요구 수준

descdesc: required (string)
설명

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"prtect_rqst_level_id":	1,
				"name":	"시그니처	템플릿",
				"cmd":	"시그니처	종류	",
				"desc":	"시그니처	설명"
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

GET

/ips/profiles/exceptions

IPS 프로파일의 정책 예외 호스트 스펙 정보을(를) 조회한다.

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

IPS 프로파일의 정책 예외 호스트 스펙 정보 조회 성공

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

rule_ex_count
rule_ex_count: required (integer)
정책 최대 예외 호스트 개수

Example:
Example

{
		"code":	"ok",
		"result":	{
				"rule_ex_count":	100
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

/ips/profiles/signatures/{pk}/use-profiles

시그니처 사용중인 프로파일 목록을 조회한다.

Request

URI Parameters

pkpk: required (integer)
IPS 시그니처 ID ( ips_signtr_id )

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

시그니처 사용중인 프로파일 목록 조회 성공

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
result: required (array of IpsSingatureUseProfile)
결과 데이터

Items: IpsSingatureUseProfile
Items

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

name
name: required (string)
IPS 프로파일 이름

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ips_signtr_id":	1,
				"ips_prf_id":	1,
				"name":	"IPS	프로파일	이름"
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

PUT

/ips/profiles/signatures/{pk}/update-profiles

단일 시그니처 복수 프로파일에 일괄 적용을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
IPS 시그니처 ID ( ips_signtr_id )

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

ips_prf_id_list
ips_prf_id_list: required (array of items)
Items: items
Items

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

options: required (object)
options

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

action
action: required (one of 0, 1, 2 - default: 0)
대응
탐지:	0,	차단:	1,	Rest:	2

block_tm
block_tm: required (integer - default: 150 - minimum: 1 - maximum: 3600)
차단 시간

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1 - default: 0)
덤프 사용여부
사용안함:	0,	사용:	1

email_use
email_use: required (one of 0, 1 - default: 0)
이메일 사용여부
사용안함:	0,	사용:	1

addr_obj_id_list
addr_obj_id_list: required (array of items)
Items: items
Items

addr_obj_id
addr_obj_id: required (integer)
예외 호스트 ID
호스트	주소,	네트워크	주소	객체(IP	주소만)

Example:
Example

{
		"ips_prf_id_list":	[{"ips_prf_id":	1},	{"ips_prf_id":	2}],
		"options":	{
				"use":	1,
				"action":	1,
				"block_tm":	100,
				"log_use":	0,
				"dump_use":	1,
				"email_use":	1,
				"addr_obj_id_list":	[{"addr_obj_id":	1},	{"addr_obj_id":	2}]
		}
}

Response

HTTP status code 200

단일 시그니처 복수 프로파일에 일괄 적용 수정 성공

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

errors: required (array of object)
errors
수정 실패 시 에러 목록

Example:
Example

{
		"code":	"ok",
		"result":	{
				"errors":	[]
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

IPS 프로파일 옵션 설정 적용/취소

PUT

/command/ips-profiles-config/apply

IPS 프로파일 사용 설정과 Oversubscription 설정 변경 사항을 적용한다.

Request

Annotations

SupportedVersion:
SupportedVersion

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

Example:
Example

{}

Response

HTTP status code 200

IPS 프로파일 옵션 설정 적용 성공

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

/command/ips-profiles-config/cancel

IPS 프로파일 사용 설정과 Oversubscription 설정 변경 사항을 취소한다.

Request

Annotations

SupportedVersion:
SupportedVersion

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

Example:
Example

{}

Response

HTTP status code 200

IPS 프로파일 옵션 설정 취소 성공

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

IPS 프로파일 설정 적용/취소

PUT

/command/ips-profiles/apply

IPS 프로파일 설정을 적용합니다.

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

Example:
Example

{}

Response

HTTP status code 200

IPS 프로파일 설정 적용 성공

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

/command/ips-profiles/cancel

IPS 프로파일 설정을 취소합니다.

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

IPS 프로파일 설정 취소 성공

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

비정상 프로토콜

GET

/ips/profiles/{ppk}/abnormal-protocols

비정상 프로토콜 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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

비정상 프로토콜 목록 조회 성공

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
result: required (array of ResIpsAbnormalProtocol)
결과 데이터

Items: ResIpsAbnormalProtocol
Items

ips_anmly_prtc_id
ips_anmly_prtc_id: required (integer)
IPS 비정상 프로토콜 ID

useuse: required (one of 0, 1 - default: 0)
사용여부
사용안함:	0,	사용:	1

catecate: required (one of 0, 1, 2, 3, 4)
카테고리
IP:	0,	TCP:	1,	UDP:	2,	ICMP:	3,	IPv6:	4

name
name: required (string)
이름

paramparam: required (integer)
파라미터

ehost
ehost: required (string)
예외 호스트 정보

설명이 있는 경우 설명을 전달
설명이 없는 경우 주소 객체의 이름을 전달(첫번째 설정 객체 이름)
ehost_count
ehost_count: required (integer)
예외 호스트 객체 갯수

ehost_desc: required (integer)
ehost_desc
예외 호스트 설명 존재 여부
0:	설명	없음,	1:	설명	있음

action
action: required (one of 0, 1 - default: 0)
조치
탐지:	0,	차단:	1

riskrisk: required (one of 1, 2, 3 - default: 1)

위험도
하:	1,	중:	2,	상:	3

acrcy
acrcy: required (one of 1, 2, 3 - default: 1)
정확도
하:	1,	중:	2,	상:	3

effect
effect: required (one of 1, 2, 3 - default: 1)
영향도
하:	1,	중:	2,	상:	3

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1 - default: 0)
덤프 사용여부
사용안함:	0,	사용:	1

email_use: required (one of 0, 1 - default: 0)
email_use
이메일 사용여부
사용안함:	0,	사용:	1

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ips_prf_id":	1,
				"ips_anmly_prtc_id":	910001,
				"use":	0,
				"cate":	0,
				"name":	"비정상	프로토콜",
				"param":	512,
				"ehost":	"예외호스트	설명",
				"ehost_count":	1,
				"ehost_desc":	1,
				"action":	0,
				"risk":	1,
				"acrcy":	1,
				"effect":	1,
				"log_use":	1,
				"dump_use":	0,
				"email_use":	0
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

/ips/profiles/{ppk}/abnormal-protocols

비정상 프로토콜 목록을 (일괄)수정한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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
items: required (array of ReqIpsAbnormalProtocol)
수정 아이템 목록

Items: ReqIpsAbnormalProtocol
Items

ips_anmly_prtc_id
ips_anmly_prtc_id: required (integer)
IPS 비정상 프로토콜 ID

useuse: required (one of 0, 1 - default: 0)
사용여부
사용안함:	0,	사용:	1

paramparam: required (integer)
파라미터

action
action: required (one of 0, 1 - default: 0)
조치
탐지:	0,	차단:	1

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1 - default: 0)
덤프 사용여부
사용안함:	0,	사용:	1

email_use
email_use: required (one of 0, 1 - default: 0)
이메일 사용여부
사용안함:	0,	사용:	1

Example:
Example

{
		"items":	[{
				"ips_anmly_prtc_id":	910001,
				"use":	1,
				"param":	1518,
				"action":	1,
				"log_use":	0,
				"dump_use":	1,
				"email_use":	1
		}]
}

Response

HTTP status code 200

비정상 프로토콜 목록 수정 성공

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

/ips/profiles/{ppk}/abnormal-protocols/exceptions

비정상 프로토콜 예외 호스트을(를) 수정한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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
items: required (array of SetIpsAbnormalProtocolHostExceptionList)
수정 아이템 목록

Items: SetIpsAbnormalProtocolHostExceptionList
Items

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

except_desc: (string - minLength: 0 - maxLength: 128)
except_desc
예외 호스트 설명

exception_ids
exception_ids: required (array of SetExceptObjectType)
Items: SetExceptObjectType
Items

src_addr_obj_id
src_addr_obj_id: required (integer)
출발지 주소 객체 ID

dst_addr_obj_id
dst_addr_obj_id: required (integer)
목적지 주소 객체 ID

ips_anmly_prtc_id
ips_anmly_prtc_id: required (integer)
IPS 비정상 프로토콜 ID

Example:
Example

{
		"items":	[
				{
						"ips_prf_id":	1,
						"ips_anmly_prtc_id":	910001,
						"except_desc":	"예외	호스트	설명",
						"exception_ids":	[
								{
										"src_addr_obj_id":	3,
										"dst_addr_obj_id":	4
								}
						]
				}
		]
}

Response

HTTP status code 200

비정상 프로토콜 예외 호스트 수정 성공

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

GET

/ips/profiles/{ppk}/abnormal-protocols/{pk}/exceptions

비정상 프로토콜 예외 호스트 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

pkpk: required (integer)
IPS 비정상 프로토콜 ID ( ips_anmly_prtc_id )

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

비정상 프로토콜 예외 호스트 목록 조회 성공

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
result: required (array of GetIpsAbnormalProtocolHostExceptionList)
결과 데이터

Items: GetIpsAbnormalProtocolHostExceptionList
Items

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

except_desc
except_desc: (string - minLength: 0 - maxLength: 128)
예외 호스트 설명

exception_ids
exception_ids: required (array of GetExceptObjectType)
Items: GetExceptObjectType
Items

src_addr_obj_id
src_addr_obj_id: required (integer)
출발지 주소 객체 ID

src_ip_ver: required (integer)
src_ip_ver
출발지 IP 버전
1:	IPv4,	2:	IPv6

src_name
src_name: required (string)
출발지 주소 객체 이름

src_type: required (integer)
src_type
출발지 주소 객체 유형
1:	호스트,	2:	네트워크,	4:	그룹

src_zone
src_zone: required (integer)
출발지 주소 객체 Zone 정보
1:	내부,	2:	외부,	3:	DMZ

dst_addr_obj_id
dst_addr_obj_id: required (integer)
목적지 주소 객체 ID

dst_ip_ver
dst_ip_ver: required (integer)
목적지 IP 버전
1:	IPv4,	2:	IPv6

dst_name: required (string)
dst_name
목적지 주소 객체 이름

dst_type
dst_type: required (integer)
목적지 주소 객체 유형
1:	호스트,	2:	네트워크,	4:	그룹

dst_zone: required (integer)
dst_zone
목적지 주소 객체 Zone 정보
1:	내부,	2:	외부,	3:	DMZ

ips_anmly_prtc_id
ips_anmly_prtc_id: required (integer)
IPS 비정상 프로토콜 ID

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"ips_prf_id":	1,
						"ips_anmly_prtc_id":	910001,
						"except_desc":	"예외	호스트	설명",
						"exception_ids":	[
								{
										"src_addr_obj_id":	3,
										"src_ip_ver":	1,
										"src_name":	"1_1_1_1_IN",
										"src_type":	1,
										"src_zone":	1,
										"dst_addr_obj_id":	4,
										"dst_ip_ver":	1,
										"dst_name":	"2_2_2_0_24",
										"dst_type":	2,
										"dst_zone":	1
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

비정상 프로토콜 적용/취소

PUT

/command/ips-abnormal-protocols/apply

비정상 프로토콜을 적용합니다.

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

비정상 프로토콜 적용 성공

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

/command/ips-abnormal-protocols/cancel

비정상 프로토콜을 취소합니다.

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

비정상 프로토콜 취소 성공

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

프로토콜 취약점 방어

GET

/ips/profiles/{ppk}/protocol-vulners

프로토콜 취약점 방어 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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

프로토콜 취약점 방어 목록 조회 성공

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
result: required (array of ResIpsProtocolVulner)
결과 데이터

Items: ResIpsProtocolVulner
Items

ips_prtc_vuln_id
ips_prtc_vuln_id: required (integer)
IPS 프로토콜 취약점 ID

useuse: required (one of 0, 1 - default: 0)
사용여부
사용안함:	0,	사용:	1

name
name: required (string)
이름

ehost
ehost: required (string)
예외 호스트 정보

설명이 있는 경우 설명을 전달
설명이 없는 경우 주소 객체의 이름을 전달(첫번째 설정 객체 이름)
ehost_count
ehost_count: required (integer)
예외 호스트 객체 갯수

ehost_desc
ehost_desc: required (integer)
예외 호스트 설명 존재 여부
0:	설명	없음,	1:	설명	있음

action
action: required (one of 0, 1 - default: 0)
조치
탐지:	0,	차단:	1

riskrisk: required (one of 1, 2, 3 - default: 1)
위험도
하:	1,	중:	2,	상:	3

acrcy
acrcy: required (one of 1, 2, 3 - default: 1)
정확도
하:	1,	중:	2,	상:	3

effect: required (one of 1, 2, 3 - default: 1)
effect
영향도
하:	1,	중:	2,	상:	3

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

dump_use: required (one of 0, 1 - default: 0)
dump_use
덤프 사용여부
사용안함:	0,	사용:	1

email_use
email_use: required (one of 0, 1 - default: 0)
이메일 사용여부
사용안함:	0,	사용:	1

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ips_prf_id":	1,
				"ips_prtc_vuln_id":	910037,
				"use":	0,
				"name":	"프로토콜	취약점",
				"ehost":	"예외호스트	설명",
				"ehost_count":	1,
				"ehost_desc":	1,
				"action":	0,
				"risk":	1,
				"acrcy":	1,
				"effect":	1,
				"log_use":	1,
				"dump_use":	0,
				"email_use":	0
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

PUT

/ips/profiles/{ppk}/protocol-vulners

프로토콜 취약점 방어 목록을 (일괄)수정한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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
items
items: required (array of ReqIpsProtocolVulner)
수정 아이템 목록

Items: ReqIpsProtocolVulner
Items

ips_prtc_vuln_id
ips_prtc_vuln_id: required (integer)
IPS 프로토콜 취약점 ID

useuse: required (one of 0, 1 - default: 0)
사용여부
사용안함:	0,	사용:	1

action: required (one of 0, 1 - default: 0)
action
조치
탐지:	0,	차단:	1

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1 - default: 0)
덤프 사용여부
사용안함:	0,	사용:	1

email_use
email_use: required (one of 0, 1 - default: 0)
이메일 사용여부
사용안함:	0,	사용:	1

Example:
Example

{
		"items":	[{
				"ips_prtc_vuln_id":	910037,
				"use":	1,
				"action":	1,
				"log_use":	0,
				"dump_use":	1,
				"email_use":	1
		}]
}

Response

HTTP status code 200

프로토콜 취약점 방어 목록 수정 성공

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

/ips/profiles/{ppk}/protocol-vulners/exceptions

프로토콜 취약점 방어 예외 호스트을(를) 수정한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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
items: required (array of SetIpsProtocolVulnerHostExceptionList)
수정 아이템 목록

Items: SetIpsProtocolVulnerHostExceptionList
Items

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

except_desc
except_desc: (string - minLength: 0 - maxLength: 128)
예외 호스트 설명

exception_ids
exception_ids: required (array of SetExceptObjectType)
Items: SetExceptObjectType
Items

src_addr_obj_id
src_addr_obj_id: required (integer)
출발지 주소 객체 ID

dst_addr_obj_id: required (integer)
dst_addr_obj_id
목적지 주소 객체 ID

ips_prtc_vuln_id
ips_prtc_vuln_id: required (integer)
IPS 프로토콜 취약점 ID

Example:
Example

{
		"items":	[
				{
						"ips_prf_id":	1,
						"ips_prtc_vuln_id":	910001,
						"except_desc":	"예외	호스트	설명",
						"exception_ids":	[
								{
										"src_addr_obj_id":	3,
										"dst_addr_obj_id":	4
								}
						]
				}
		]
}

Response

HTTP status code 200

프로토콜 취약점 방어 예외 호스트 수정 성공

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

errors: required (array of object)
errors
수정 실패 시 에러 목록

Example:
Example

{
		"code":	"ok",
		"result":	{
				"errors":	[]
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

GET

/ips/profiles/{ppk}/protocol-vulners/{pk}/exceptions

프로토콜 취약점 방어 예외 호스트 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

pkpk: required (integer)
IPS 프로토콜 취약점 ID ( ips_prtc_vuln_id )

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

프로토콜 취약점 방어 예외 호스트 목록 조회 성공

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
result: required (array of GetIpsProtocolVulnerHostExceptionList)
결과 데이터

Items: GetIpsProtocolVulnerHostExceptionList
Items

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

except_desc
except_desc: (string - minLength: 0 - maxLength: 128)
예외 호스트 설명

exception_ids: required (array of GetExceptObjectType)
exception_ids
Items: GetExceptObjectType
Items

src_addr_obj_id
src_addr_obj_id: required (integer)
출발지 주소 객체 ID

src_ip_ver
src_ip_ver: required (integer)
출발지 IP 버전
1:	IPv4,	2:	IPv6

src_name
src_name: required (string)
출발지 주소 객체 이름

src_type
src_type: required (integer)
출발지 주소 객체 유형
1:	호스트,	2:	네트워크,	4:	그룹

src_zone
src_zone: required (integer)
출발지 주소 객체 Zone 정보
1:	내부,	2:	외부,	3:	DMZ

dst_addr_obj_id
dst_addr_obj_id: required (integer)
목적지 주소 객체 ID

dst_ip_ver
dst_ip_ver: required (integer)
목적지 IP 버전
1:	IPv4,	2:	IPv6

dst_name
dst_name: required (string)
목적지 주소 객체 이름

dst_type
dst_type: required (integer)
목적지 주소 객체 유형
1:	호스트,	2:	네트워크,	4:	그룹

dst_zone
dst_zone: required (integer)
목적지 주소 객체 Zone 정보
1:	내부,	2:	외부,	3:	DMZ

ips_prtc_vuln_id
ips_prtc_vuln_id: required (integer)
IPS 프로토콜 취약점 ID

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"ips_prf_id":	1,
						"ips_prtc_vuln_id":	910001,
						"except_desc":	"예외	호스트	설명",
						"exception_ids":	[
								{
										"src_addr_obj_id":	3,
										"src_ip_ver":	1,
										"src_name":	"1_1_1_1_IN",
										"src_type":	1,
										"src_zone":	1,
										"dst_addr_obj_id":	4,
										"dst_ip_ver":	1,
										"dst_name":	"2_2_2_0_24",
										"dst_type":	2,
										"dst_zone":	1
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

프로토콜 취약점 방어 적용/취소

PUT

/command/ips-protocol-vulners/apply

프로토콜 취약점 방어을 적용합니다.

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

프로토콜 취약점 방어 적용 성공

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

/command/ips-protocol-vulners/cancel

프로토콜 취약점 방어을 취소합니다.

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

Example:
Example

{}

Response

HTTP status code 200

프로토콜 취약점 방어 취소 성공

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

비정상 애플리케이션 방어

GET

/ips/profiles/{ppk}/abnormal-apps

비정상 애플리케이션 방어 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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

비정상 애플리케이션 방어 목록 조회 성공

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
result: required (array of ResIpsAbnormalApp)
결과 데이터

Items: ResIpsAbnormalApp
Items

ips_anmly_app_id
ips_anmly_app_id: required (integer)
IPS 비정상 애플리케이션 ID

useuse: required (one of 0, 1 - default: 0)

사용여부
사용안함:	0,	사용:	1

catecate: required (one of 0, 1, 2, 3, 4, 5, 6)
카테고리
HTTP:	0,	FTP:	1,	DNS:	2,	VoIP:	3,	POP3:	4,	IMAP:	5,	SMTP:	6

name
name: required (string)
이름

limit
limit: required (integer)
제한값

ehost
ehost: required (string)
예외 호스트 정보

설명이 있는 경우 설명을 전달
설명이 없는 경우 주소 객체의 이름을 전달(첫번째 설정 객체 이름)
ehost_count: required (integer)
ehost_count
예외 호스트 객체 갯수

ehost_desc
ehost_desc: required (integer)
예외 호스트 설명 존재 여부
0:	설명	없음,	1:	설명	있음

action
action: required (one of 0, 1 - default: 0)
조치
탐지:	0,	차단:	1

riskrisk: required (one of 1, 2, 3 - default: 1)
위험도
하:	1,	중:	2,	상:	3

acrcy: required (one of 1, 2, 3 - default: 1)
acrcy
정확도
하:	1,	중:	2,	상:	3

effect
effect: required (one of 1, 2, 3 - default: 1)
영향도
하:	1,	중:	2,	상:	3

log_use: required (one of 0, 1 - default: 1)
log_use
로그 사용여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1 - default: 0)
덤프 사용여부
사용안함:	0,	사용:	1

email_use
email_use: required (one of 0, 1 - default: 0)
이메일 사용여부
사용안함:	0,	사용:	1

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ips_prf_id":	1,
				"ips_anmly_app_id":	910043,
				"use":	0,
				"cate":	0,
				"name":	"비정상	애플리케이션",
				"limit":	10,
				"ehost":	"예외호스트	설명",
				"ehost_count":	1,
				"ehost_desc":	1,
				"action":	0,
				"risk":	1,
				"acrcy":	1,
				"effect":	1,
				"log_use":	1,
				"dump_use":	0,
				"email_use":	0
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

PUT

/ips/profiles/{ppk}/abnormal-apps

비정상 애플리케이션 방어 목록을 (일괄)수정한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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
items
items: required (array of ReqIpsAbnormalApp)
수정 아이템 목록

Items: ReqIpsAbnormalApp
Items

ips_anmly_app_id
ips_anmly_app_id: required (integer)
IPS 비정상 애플리케이션 ID

useuse: required (one of 0, 1 - default: 0)
사용여부
사용안함:	0,	사용:	1

limit
limit: required (integer)
제한값

action
action: required (one of 0, 1 - default: 0)
조치
탐지:	0,	차단:	1

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1 - default: 0)
덤프 사용여부
사용안함:	0,	사용:	1

email_use: required (one of 0, 1 - default: 0)
email_use

이메일 사용여부
사용안함:	0,	사용:	1

Example:
Example

{
		"items":	[{
				"ips_anmly_app_id":	910043,
				"use":	1,
				"limit":	100,
				"action":	1,
				"log_use":	0,
				"dump_use":	1,
				"email_use":	1
		}]
}

Response

HTTP status code 200

비정상 애플리케이션 방어 목록 수정 성공

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

/ips/profiles/{ppk}/abnormal-apps/exceptions

비정상 애플리케이션 방어 예외 호스트을(를) 수정한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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
items: required (array of SetIpsAbnormalAppHostExceptionList)
수정 아이템 목록

Items: SetIpsAbnormalAppHostExceptionList
Items

ips_prf_id: required (integer)
ips_prf_id
IPS 프로파일 ID

except_desc
except_desc: (string - minLength: 0 - maxLength: 128)
예외 호스트 설명

exception_ids
exception_ids: required (array of SetExceptObjectType)
Items: SetExceptObjectType
Items

src_addr_obj_id
src_addr_obj_id: required (integer)
출발지 주소 객체 ID

dst_addr_obj_id
dst_addr_obj_id: required (integer)
목적지 주소 객체 ID

ips_anmly_app_id
ips_anmly_app_id: required (integer)
IPS 비정상 애플리케이션 ID

Example:
Example

{
		"items":	[
				{
						"ips_prf_id":	1,
						"ips_anmly_app_id":	910001,
						"except_desc":	"예외	호스트	설명",
						"exception_ids":	[
								{
										"src_addr_obj_id":	3,
										"dst_addr_obj_id":	4
								}
						]
				}
		]
}

Response

HTTP status code 200

비정상 애플리케이션 방어 예외 호스트 수정 성공

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

GET

/ips/profiles/{ppk}/abnormal-apps/{pk}/exceptions

비정상 애플리케이션 방어 예외 호스트 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

pkpk: required (integer)
IPS 비정상 애플리케이션 ID ( ips_anmly_app_id )

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

비정상 애플리케이션 방어 예외 호스트 목록 조회 성공

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
result: required (array of GetIpsAbnormalAppHostExceptionList)
결과 데이터

Items: GetIpsAbnormalAppHostExceptionList
Items

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

except_desc
except_desc: (string - minLength: 0 - maxLength: 128)
예외 호스트 설명

exception_ids
exception_ids: required (array of GetExceptObjectType)
Items: GetExceptObjectType
Items

src_addr_obj_id
src_addr_obj_id: required (integer)
출발지 주소 객체 ID

src_ip_ver
src_ip_ver: required (integer)
출발지 IP 버전
1:	IPv4,	2:	IPv6

src_name: required (string)
src_name
출발지 주소 객체 이름

src_type
src_type: required (integer)
출발지 주소 객체 유형
1:	호스트,	2:	네트워크,	4:	그룹

src_zone: required (integer)
src_zone

출발지 주소 객체 Zone 정보
1:	내부,	2:	외부,	3:	DMZ

dst_addr_obj_id
dst_addr_obj_id: required (integer)
목적지 주소 객체 ID

dst_ip_ver
dst_ip_ver: required (integer)
목적지 IP 버전
1:	IPv4,	2:	IPv6

dst_name
dst_name: required (string)
목적지 주소 객체 이름

dst_type
dst_type: required (integer)
목적지 주소 객체 유형
1:	호스트,	2:	네트워크,	4:	그룹

dst_zone
dst_zone: required (integer)
목적지 주소 객체 Zone 정보
1:	내부,	2:	외부,	3:	DMZ

ips_anmly_app_id
ips_anmly_app_id: required (integer)
IPS 비정상 애플리케이션 ID

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"ips_prf_id":	1,
						"ips_anmly_app_id":	910001,
						"except_desc":	"예외	호스트	설명",
						"exception_ids":	[
								{
										"src_addr_obj_id":	3,
										"src_ip_ver":	1,
										"src_name":	"1_1_1_1_IN",
										"src_type":	1,
										"src_zone":	1,
										"dst_addr_obj_id":	4,
										"dst_ip_ver":	1,
										"dst_name":	"2_2_2_0_24",
										"dst_type":	2,
										"dst_zone":	1
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

비정상 애플리케이션 방어 적용/취소

PUT

/command/ips-abnormal-apps/apply

비정상 애플리케이션 방어을 적용합니다.

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

비정상 애플리케이션 방어 적용 성공

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

/command/ips-abnormal-apps/cancel

비정상 애플리케이션 방어을 취소합니다.

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

Example:
Example

{}

Response

HTTP status code 200

비정상 애플리케이션 방어 취소 성공

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

시그니처

GET

/ips/profiles/{ppk}/signatures

시그니처 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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

시그니처 목록 조회 성공

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
result: required (array of ResIpsSignature)
결과 데이터

Items: ResIpsSignature
Items

ips_signtr_id
ips_signtr_id: required (integer)
IPS 시그니처 ID

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

catecate: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)
카테고리
Application:	0,	AV	Manager:	1,	Backup	Manager:	2,	Browser:	3,	DB:	4,	Information	Disclosure:	5,	MALWARE	Traffic:	6,	Miscellaneous:	7,	Office:	8,	OS:	9,	Web	Application:	10,	User	Signature:	11,	Snort
Signature:	12

msgmsg: required (string)
메시지

prtcprtc: required (one of 0, 1, 2, 3 - default: 0)
프로토콜
IP:	0,	ICMP:	1,	TCP:	2,	UDP:	3

src_port
src_port: required (string)
출발지 포트

dst_port
dst_port: required (string)
목적지 포트

ehost
ehost: required (string)
예외 호스트 정보

설명이 있는 경우 설명을 전달
설명이 없는 경우 주소 객체의 이름을 전달(첫번째 설정 객체 이름)
ehost_count
ehost_count: required (integer)
예외 호스트 객체 갯수

ehost_desc
ehost_desc: required (integer)
예외 호스트 설명 존재 여부
0:	설명	없음,	1:	설명	있음

action
action: required (one of 0, 1, 2, 3, 4 - default: 0)
대응
탐지:	0,	패킷	차단:	1,	IP	차단:	2,	패킷	차단/Reset:	3,	IP	주소	차단/Reset:	4

block_tm
block_tm: required (integer - default: 150 - minimum: 1 - maximum: 3600)
차단 시간

riskrisk: required (one of 1, 2, 3 - default: 1)
위험도
하:	1,	중:	2,	상:	3

acrcy
acrcy: required (one of 1, 2, 3 - default: 1)
탐지 정확도
하:	1,	중:	2,	상:	3

effect
effect: required (one of 1, 2, 3 - default: 1)
성능 영향도
하:	1,	중:	2,	상:	3

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1 - default: 0)
덤프 사용여부
사용안함:	0,	사용:	1

email_use
email_use: required (one of 0, 1 - default: 0)
이메일 사용여부
사용안함:	0,	사용:	1

kr_desc: required (string)
kr_desc
국문 설명

en_desc
en_desc: required (string)
영어 설명

jp_desc
jp_desc: required (string)
일어 설명

ptrnptrn: required (string)
패턴

attacker
attacker: required (one of 0, 1 - default: 0)
ATTACKER
출발지:	0,	목적지:	1

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ips_prf_id":	1,
				"ips_signtr_id":	103,
				"use":	0,
				"cate":	0,
				"msg":	"시그니처	메시지",
				"prtc":	0,
				"src_port":	"90",
				"dst_port":	"90",
				"ehost":	"예외호스트	설명",
				"ehost_count":	1,
				"ehost_desc":	1,
				"action":	0,
				"block_tm":	150,
				"risk":	1,
				"acrcy":	1,
				"effect":	1,
				"log_use":	1,
				"dump_use":	0,
				"email_use":	0,
				"kr_desc":	"시그니처	국문	설명",
				"en_desc":	"시그니처	영어	설명",
				"jp_desc":	"시그니처	일어	설명",
				"ptrn":	"alert	TCP	any	any	->	any	80	(msg:\"test_signature\";	content:\"abcdefg\";)",
				"attacker":	0
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

/ips/profiles/{ppk}/signatures

시그니처 목록을 (일괄)수정한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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
items: required (array of ReqIpsSignature)
수정 아이템 목록

Items: ReqIpsSignature
Items

ips_signtr_id: required (integer)
ips_signtr_id
IPS 시그니처 ID

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

action: required (one of 0, 1, 2, 3, 4 - default: 0)
action
대응
탐지:	0,	패킷	차단:	1,	IP	차단:	2,	패킷	차단/Reset:	3,	IP	주소	차단/Reset:	4

block_tm
block_tm: required (integer - default: 150 - minimum: 1 - maximum: 3600)
차단 시간

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1 - default: 0)
덤프 사용여부
사용안함:	0,	사용:	1

email_use: required (one of 0, 1 - default: 0)
email_use
이메일 사용여부
사용안함:	0,	사용:	1

Example:
Example

{
		"items":	[{
				"ips_signtr_id":	103,
				"use":	1,
				"action":	1,
				"block_tm":	100,
				"log_use":	0,
				"dump_use":	1,
				"email_use":	1
		}]
}

Response

HTTP status code 200

시그니처 목록 수정 성공

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

/ips/profiles/{ppk}/signatures

시그니처 목록을 (일괄)삭제한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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
items
items: required (array of integer)
삭제될 시그니처 ID 목록

Example:
Example

{
		"items":	[800000,	800001,	850001,	850002]
}

Response

HTTP status code 200

시그니처 목록 삭제 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (one of ok, pok, nok)
결과 코드

result: required (object)
result
결과 데이터

Example:
Example

{
		"code":	"ok",
		"result":	{
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

GET

/ips/profiles/{ppk}/signatures/save?columns=(IPS 시그니처 ID, 사용 여부, 카테고리, 메시지, 프로토콜, 출발지 포트, 목적지 포트, 예외 호스트, 대응, 차단 시간, 위험도, 탐지 정확
도, 성능 영향도, 로그 사용여부, 덤프 사용여부, 이메일 사용여부)

시그니처 다운로드을 PC로 저장합니다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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

Query Parameters

columns
columns: (string)
다운로드되는 엑셀 파일 내 테이블 헤더 값으로 사용될 값을 전달한다.(데이터 테이블에 표시되는 컬럼 순으로 지정)
columns 쿼리스트링에 값이 없을 경우 백엔드에 정의된 속성명으로 표시됩니다.
한글이	포함될	수	있기	때문에	UTF-8	인코딩되어야	합니다.

Example:
Example

?columns=(A,B,C)

Response

HTTP status code 200

시그니처 다운로드를 PC로 저장 성공

Body

Media type: application/vnd.openxmlformats-officedocument.spreadsheetml.sheet
Media type

TypeType: file

GET

/ips/profiles/{ppk}/signatures/{pk}/detail

시그니처 상세정보을(를) 조회한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

pkpk: required (string)

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

Query Parameters

qq: required (string)
쿼리 파라메터  한국어:	1,	영어:	2

Example:
Example

q=lang=1

Response

HTTP status code 200

시그니처 상세정보 조회 성공

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

IDID: required (string)
ID

Summary
Summary: required (string)
Summary

Category: required (string)
Category
Category

Severity
Severity: required (string)
Severity

Risk_5l
Risk_5l: required (string)
Risk_5l

Accuracy
Accuracy: required (string)
Accuracy

Degradation
Degradation: required (string)
Degradation

Impact
Impact: required (string)
Impact

FirstUpdate
FirstUpdate: required (string)
FirstUpdate

LastUpdate
LastUpdate: required (string)
LastUpdate

DetailedInformation
DetailedInformation: required (string)
DetailedInformation

AffectedSystems: required (string)
AffectedSystems
AffectedSystems

CorrectiveAction
CorrectiveAction: required (string)
CorrectiveAction

Reference
Reference: required (string)
Reference

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ID":	"1276",
				"Summary":	"ypserv	RPC	GETPORT	요청	메세지를	탐지한다.",
				"Category":	"Miscellaneous",
				"Severity":	"low",
				"Risk_5l":	"info",
				"Accuracy":	"medium",
				"Degradation":	"medium",
				"Impact":	"RPC를	통한	서버정보는	악의적인	목적으로	사용될	수	있다.",
				"FirstUpdate":	"2005-03-28",
				"LastUpdate":	"2015-07-08",
				"DetailedInformation":	"NIS는	네트워크	상에	호스트에	접근할	수	있다.	(인터넷	웹서비스의	DNS와	비슷하지만	구조는	간단함)",
				"AffectedSystems":	"UNIX	portmapper를	사용하는	모든	호스트",
				"CorrectiveAction":	"-	RPC	서비스에	접근하는	사용자를	제한한다.\n-	불필요하다면	RPC	관련	데몬	구동을	중지시킨다.\n-	제조사에서	제공하는	최신보안패치를	적용한다.",
				"Reference":	"bugtraq,6016\nbugtraq,5914\ncve,CVE-2002-1232\ncve,CVE-2000-1042\ncve,CVE-2000-1043\narachnids,12"
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

POST

/ips/profiles/{ppk}/signatures/user-define

사용자 정의 시그니처을(를) 추가한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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

catecate: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 - default: 11)
카테고리
Application:	0,	AV	Manager:	1,	Backup	Manager:	2,	Browser:	3,	DB:	4,	Information	Disclosure:	5,	MALWARE	Traffic:	6,	Miscellaneous:	7,	Office:	8,	OS:	9,	Web	Application:	10,	User	Signature:
11,	Snort	Signature:	12

type
type: required (one of 0, 1, 2, 3 - default: 0)
유형
없음:	0,	수동설정:	1,	고급설정:	2,	snort시그니처:	3

prtcprtc: required (one of 0, 1, 2, 3 - default: 0)
프로토콜
IP:	0,	ICMP:	1,	TCP:	2,	UDP:	3

msgmsg: required (string)
메시지

riskrisk: required (one of 1, 2, 3 - default: 1)
위험도
하:	1,	중:	2,	상:	3

acrcy
acrcy: required (one of 1, 2, 3 - default: 1)
탐지 정확도
하:	1,	중:	2,	상:	3

effect: required (one of 1, 2, 3 - default: 1)
effect
성능 영향도
하:	1,	중:	2,	상:	3

kr_desc
kr_desc: required (string)
국문 설명

en_desc: required (string)
en_desc
영어 설명

jp_desc
jp_desc: required (string)
일어 설명

ptrnptrn: required (string)
패턴

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

action: required (one of 0, 1, 2, 3, 4 - default: 0)
action
대응
탐지:	0,	패킷	차단:	1,	IP	차단:	2,	패킷	차단/Reset:	3,	IP	주소	차단/Reset:	4

block_tm
block_tm: required (integer - default: 150 - minimum: 1 - maximum: 3600)
차단 시간

log_use: required (one of 0, 1 - default: 1)
log_use
로그 사용여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1 - default: 0)
덤프 사용여부
사용안함:	0,	사용:	1

email_use
email_use: required (one of 0, 1 - default: 0)
이메일 사용여부
사용안함:	0,	사용:	1

src_ips_signtr_port_id
src_ips_signtr_port_id: required (integer)
출발지 IPS 시그니처 포트 ID

src_port
src_port: required (string)
출발지 포트

dst_ips_signtr_port_id
dst_ips_signtr_port_id: required (integer)
목적지 IPS 시그니처 포트 ID

dst_port: required (string)
dst_port
목적지 포트

ips_usr_def_signtr_obj
ips_usr_def_signtr_obj: required (array of items)
Items: items
Items

ips_usr_def_signtr_id: required (integer)
ips_usr_def_signtr_id
사용자 정의 시그니처 ID

type
type: required (one of 0, 1, 2, 3 - default: 0)
유형
Contenet:	0,	URI	Content:	1,	Rawbyte:	2,	PCRE:	3

nocase_use
nocase_use: required (one of 0, 1 - default: 0)
NOCASE 사용여부
사용안함:	0,	사용:	1

prtnprtn: required (string)
패턴

offset
offset: required (integer - minimum: 0 - maximum: 65535)
OFFSET

depth
depth: required (integer - minimum: 0 - maximum: 65535)
DEPTH

distance
distance: required (integer - minimum: 0 - maximum: 65535)
DISTANCE

withinwithin: required (integer - minimum: 0 - maximum: 65535)
WITHIN

str_addr_obj
str_addr_obj: required (array of items)
Items: items
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

dst_addr_obj
dst_addr_obj: required (array of items)
Items: items
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ips_profile_list
ips_profile_list: required (array of integer)
사용 선택 프로파일 리스트

Example:
Example

{
		"cate":	11,
		"type":	0,
		"prtc":	0,
		"msg":	"시그니처	메시지",
		"risk":	1,
		"acrcy":	1,
		"effect":	1,
		"kr_desc":	"시그니처	국문	설명",
		"en_desc":	"시그니처	영어	설명",
		"jp_desc":	"시그니처	일어	설명",
		"ptrn":	"시그니처	패턴",
		"use":	0,
		"action":	0,
		"block_tm":	150,
		"log_use":	1,
		"dump_use":	0,
		"email_use":	0,
		"src_ips_signtr_port_id":	null,
		"src_port":	"80",
		"dst_ips_signtr_port_id":	null,
		"dst_port":	"90",
		"ips_usr_def_signtr_obj":	[{
				"ips_usr_def_signtr_id":	null,
				"type":	0,
				"nocase_use":	0,
				"prtn":	"alert	TCP	any	any	->	any	80	(msg:\"test_signature\";	content:\"abcdefg\";)",
				"offset":	0,
				"depth":	0,
				"distance":	0,
				"within":	0
		}],
		"str_addr_obj":	[{
				"addr_obj_id":	1
		}],
		"dst_addr_obj":	[{
				"addr_obj_id":	1
		}],
		"ips_profile_list":	[1,	2]
}

Response

HTTP status code 200

사용자 정의 시그니처 추가 성공

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

catecate: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 - default: 11)
카테고리
Application:	0,	AV	Manager:	1,	Backup	Manager:	2,	Browser:	3,	DB:	4,	Information	Disclosure:	5,	MALWARE	Traffic:	6,	Miscellaneous:	7,	Office:	8,	OS:	9,	Web	Application:	10,	User
Signature:	11,	Snort	Signature:	12

type
type: required (one of 0, 1, 2, 3 - default: 0)
유형
없음:	0,	수동설정:	1,	고급설정:	2,	snort시그니처:	3

prtcprtc: required (one of 0, 1, 2, 3 - default: 0)
프로토콜
IP:	0,	ICMP:	1,	TCP:	2,	UDP:	3

msgmsg: required (string)
메시지

riskrisk: required (one of 1, 2, 3 - default: 1)
위험도
하:	1,	중:	2,	상:	3

acrcy: required (one of 1, 2, 3 - default: 1)
acrcy
탐지 정확도
하:	1,	중:	2,	상:	3

effect
effect: required (one of 1, 2, 3 - default: 1)
성능 영향도
하:	1,	중:	2,	상:	3

kr_desc
kr_desc: required (string)
국문 설명

en_desc
en_desc: required (string)
영어 설명

jp_desc: required (string)
jp_desc
일어 설명

ptrnptrn: required (string)
패턴

useuse: required (one of 0, 1 - default: 0)

사용 여부
사용안함:	0,	사용:	1

action
action: required (one of 0, 1, 2, 3, 4 - default: 0)
대응
탐지:	0,	패킷	차단:	1,	IP	차단:	2,	패킷	차단/Reset:	3,	IP	주소	차단/Reset:	4

block_tm
block_tm: required (integer - default: 150 - minimum: 1 - maximum: 3600)
차단 시간

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1 - default: 0)
덤프 사용여부
사용안함:	0,	사용:	1

email_use: required (one of 0, 1 - default: 0)
email_use
이메일 사용여부
사용안함:	0,	사용:	1

src_ips_signtr_port_id
src_ips_signtr_port_id: required (integer)
출발지 IPS 시그니처 포트 ID

src_port: required (string)
src_port
출발지 포트

dst_ips_signtr_port_id
dst_ips_signtr_port_id: required (integer)
목적지 IPS 시그니처 포트 ID

dst_port
dst_port: required (string)
목적지 포트

ips_usr_def_signtr_obj
ips_usr_def_signtr_obj: required (array of items)
Items: items
Items

ips_usr_def_signtr_id
ips_usr_def_signtr_id: required (integer)
사용자 정의 시그니처 ID

type
type: required (one of 0, 1, 2, 3 - default: 0)
유형
Contenet:	0,	URI	Content:	1,	Rawbyte:	2,	PCRE:	3

nocase_use
nocase_use: required (one of 0, 1 - default: 0)
NOCASE 사용여부
사용안함:	0,	사용:	1

prtnprtn: required (string)
패턴

offset
offset: required (integer - minimum: 0 - maximum: 65535)
OFFSET

depth: required (integer - minimum: 0 - maximum: 65535)
depth
DEPTH

distance
distance: required (integer - minimum: 0 - maximum: 65535)
DISTANCE

withinwithin: required (integer - minimum: 0 - maximum: 65535)
WITHIN

str_addr_obj
str_addr_obj: required (array of items)
Items: items
Items

addr_obj_id: required (integer)
addr_obj_id
객체 ID

ip_ver
ip_ver: required (one of 1, 2, 3)
아이피 버전
1:	IPv4,	2:	IPv6,	3:	공통

name
name: required (string)
객체 이름

zone
zone: required (one of 1, 2, 3)
Zone 정보
내부:	1,	외부:	2,	DMZ:	3

addr_obj_type
addr_obj_type: required (one of 1, 2, 3, 4)
객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3,	그룹객체:	4

ip_info1
ip_info1: required (string)
IP 정보1

ip_info2
ip_info2: required (string)
IP 정보2

dst_addr_obj
dst_addr_obj: required (array of items)
Items: items
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (one of 1, 2, 3)
아이피 버전
1:	IPv4,	2:	IPv6,	3:	공통

name
name: required (string)
객체 이름

zone
zone: required (one of 1, 2, 3)
Zone 정보
내부:	1,	외부:	2,	DMZ:	3

addr_obj_type
addr_obj_type: required (one of 1, 2, 3, 4)
객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3,	그룹객체:	4

ip_info1
ip_info1: required (string)
IP 정보1

ip_info2
ip_info2: required (string)
IP 정보2

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

ips_signtr_id
ips_signtr_id: required (integer)
IPS 시그니처 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ips_prf_id":	1,
				"ips_signtr_id":	800000,
				"cate":	11,
				"type":	0,
				"prtc":	0,
				"msg":	"시그니처	메시지",
				"risk":	1,
				"acrcy":	1,
				"effect":	1,
				"kr_desc":	"시그니처	국문	설명",
				"en_desc":	"시그니처	영어	설명",
				"jp_desc":	"시그니처	일어	설명",
				"ptrn":	"시그니처	패턴",
				"use":	0,
				"action":	0,
				"block_tm":	150,
				"log_use":	1,
				"dump_use":	0,
				"email_use":	0,
				"src_ips_signtr_port_id":	1,
				"src_port":	"80",
				"dst_ips_signtr_port_id":	1,
				"dst_port":	"90",
				"ips_usr_def_signtr_obj":	[{
						"ips_usr_def_signtr_id":	1,
						"type":	0,
						"nocase_use":	0,
						"prtn":	"alert	TCP	any	any	->	any	80	(msg:\"test_signature\";	content:\"abcdefg\";)",
						"offset":	0,
						"depth":	0,
						"distance":	0,
						"within":	0
				}],
				"str_addr_obj":	[{
						"addr_obj_id":	1,
						"ip_ver":	1,
						"name":	"test_network_obj_1",
						"zone":	1,
						"addr_obj_type":	2,
						"ip_info1":	"100.100.100.0",
						"ip_info2":	"100.100.100.1"
				}],
				"dst_addr_obj":	[{
						"addr_obj_id":	1,
						"ip_ver":	1,
						"name":	"test_network_obj_1",
						"zone":	1,
						"addr_obj_type":	2,
						"ip_info1":	"100.100.100.0",
						"ip_info2":	"100.100.100.1"
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

GET

/ips/profiles/{ppk}/signatures/{pk}/user-define

사용자 정의 시그니처을(를) 조회한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

pkpk: required (integer)
IPS 시그니처 ID ( ips_signtr_id )

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

사용자 정의 시그니처 조회 성공

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

catecate: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 - default: 11)
카테고리
Application:	0,	AV	Manager:	1,	Backup	Manager:	2,	Browser:	3,	DB:	4,	Information	Disclosure:	5,	MALWARE	Traffic:	6,	Miscellaneous:	7,	Office:	8,	OS:	9,	Web	Application:	10,	User
Signature:	11,	Snort	Signature:	12

type
type: required (one of 0, 1, 2, 3 - default: 0)
유형
없음:	0,	수동설정:	1,	고급설정:	2,	snort시그니처:	3

prtcprtc: required (one of 0, 1, 2, 3 - default: 0)
프로토콜
IP:	0,	ICMP:	1,	TCP:	2,	UDP:	3

msgmsg: required (string)
메시지

riskrisk: required (one of 1, 2, 3 - default: 1)
위험도
하:	1,	중:	2,	상:	3

acrcy
acrcy: required (one of 1, 2, 3 - default: 1)
탐지 정확도
하:	1,	중:	2,	상:	3

effect
effect: required (one of 1, 2, 3 - default: 1)
성능 영향도
하:	1,	중:	2,	상:	3

kr_desc: required (string)
kr_desc
국문 설명

en_desc
en_desc: required (string)
영어 설명

jp_desc
jp_desc: required (string)
일어 설명

ptrnptrn: required (string)
패턴

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

action
action: required (one of 0, 1, 2, 3, 4 - default: 0)
대응
탐지:	0,	패킷	차단:	1,	IP	차단:	2,	패킷	차단/Reset:	3,	IP	주소	차단/Reset:	4

block_tm
block_tm: required (integer - default: 150 - minimum: 1 - maximum: 3600)
차단 시간

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1 - default: 0)
덤프 사용여부
사용안함:	0,	사용:	1

email_use
email_use: required (one of 0, 1 - default: 0)
이메일 사용여부
사용안함:	0,	사용:	1

src_ips_signtr_port_id: required (integer)
src_ips_signtr_port_id
출발지 IPS 시그니처 포트 ID

src_port
src_port: required (string)
출발지 포트

dst_ips_signtr_port_id: required (integer)
dst_ips_signtr_port_id
목적지 IPS 시그니처 포트 ID

dst_port
dst_port: required (string)
목적지 포트

ips_usr_def_signtr_obj
ips_usr_def_signtr_obj: required (array of items)
Items: items
Items

ips_usr_def_signtr_id
ips_usr_def_signtr_id: required (integer)
사용자 정의 시그니처 ID

type
type: required (one of 0, 1, 2, 3 - default: 0)
유형
Contenet:	0,	URI	Content:	1,	Rawbyte:	2,	PCRE:	3

nocase_use
nocase_use: required (one of 0, 1 - default: 0)
NOCASE 사용여부
사용안함:	0,	사용:	1

prtnprtn: required (string)
패턴

offset
offset: required (integer - minimum: 0 - maximum: 65535)
OFFSET

depth
depth: required (integer - minimum: 0 - maximum: 65535)
DEPTH

distance
distance: required (integer - minimum: 0 - maximum: 65535)
DISTANCE

withinwithin: required (integer - minimum: 0 - maximum: 65535)
WITHIN

str_addr_obj
str_addr_obj: required (array of items)
Items: items
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver: required (one of 1, 2, 3)
ip_ver

아이피 버전
1:	IPv4,	2:	IPv6,	3:	공통

name
name: required (string)
객체 이름

zone
zone: required (one of 1, 2, 3)
Zone 정보
내부:	1,	외부:	2,	DMZ:	3

addr_obj_type
addr_obj_type: required (one of 1, 2, 3, 4)
객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3,	그룹객체:	4

ip_info1
ip_info1: required (string)
IP 정보1

ip_info2
ip_info2: required (string)
IP 정보2

dst_addr_obj
dst_addr_obj: required (array of items)
Items: items
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (one of 1, 2, 3)
아이피 버전
1:	IPv4,	2:	IPv6,	3:	공통

name
name: required (string)
객체 이름

zone: required (one of 1, 2, 3)
zone
Zone 정보
내부:	1,	외부:	2,	DMZ:	3

addr_obj_type
addr_obj_type: required (one of 1, 2, 3, 4)
객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3,	그룹객체:	4

ip_info1
ip_info1: required (string)
IP 정보1

ip_info2
ip_info2: required (string)
IP 정보2

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

ips_signtr_id
ips_signtr_id: required (integer)
IPS 시그니처 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ips_prf_id":	1,
				"ips_signtr_id":	800000,
				"cate":	11,
				"type":	0,
				"prtc":	0,
				"msg":	"시그니처	메시지",
				"risk":	1,
				"acrcy":	1,
				"effect":	1,
				"kr_desc":	"시그니처	국문	설명",
				"en_desc":	"시그니처	영어	설명",
				"jp_desc":	"시그니처	일어	설명",
				"ptrn":	"시그니처	패턴",
				"use":	0,
				"action":	0,
				"block_tm":	150,
				"log_use":	1,
				"dump_use":	0,
				"email_use":	0,
				"src_ips_signtr_port_id":	1,
				"src_port":	"80",
				"dst_ips_signtr_port_id":	1,
				"dst_port":	"90",
				"ips_usr_def_signtr_obj":	[{
						"ips_usr_def_signtr_id":	1,
						"type":	0,
						"nocase_use":	0,
						"prtn":	"alert	TCP	any	any	->	any	80	(msg:\"test_signature\";	content:\"abcdefg\";)",
						"offset":	0,
						"depth":	0,
						"distance":	0,
						"within":	0
				}],
				"str_addr_obj":	[{
						"addr_obj_id":	1,
						"ip_ver":	1,
						"name":	"test_network_obj_1",
						"zone":	1,
						"addr_obj_type":	2,
						"ip_info1":	"100.100.100.0",
						"ip_info2":	"100.100.100.1"
				}],
				"dst_addr_obj":	[{
						"addr_obj_id":	1,
						"ip_ver":	1,
						"name":	"test_network_obj_1",
						"zone":	1,
						"addr_obj_type":	2,
						"ip_info1":	"100.100.100.0",
						"ip_info2":	"100.100.100.1"
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

/ips/profiles/{ppk}/signatures/{pk}/user-define

사용자 정의 시그니처을(를) 수정한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

pkpk: required (integer)
IPS 시그니처 ID ( ips_signtr_id )

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

catecate: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 - default: 11)
카테고리
Application:	0,	AV	Manager:	1,	Backup	Manager:	2,	Browser:	3,	DB:	4,	Information	Disclosure:	5,	MALWARE	Traffic:	6,	Miscellaneous:	7,	Office:	8,	OS:	9,	Web	Application:	10,	User	Signature:
11,	Snort	Signature:	12

type
type: required (one of 0, 1, 2, 3 - default: 0)
유형
없음:	0,	수동설정:	1,	고급설정:	2,	snort시그니처:	3

prtcprtc: required (one of 0, 1, 2, 3 - default: 0)
프로토콜
IP:	0,	ICMP:	1,	TCP:	2,	UDP:	3

msgmsg: required (string)
메시지

riskrisk: required (one of 1, 2, 3 - default: 1)
위험도
하:	1,	중:	2,	상:	3

acrcy
acrcy: required (one of 1, 2, 3 - default: 1)
탐지 정확도
하:	1,	중:	2,	상:	3

effect
effect: required (one of 1, 2, 3 - default: 1)
성능 영향도
하:	1,	중:	2,	상:	3

kr_desc: required (string)
kr_desc
국문 설명

en_desc
en_desc: required (string)
영어 설명

jp_desc
jp_desc: required (string)
일어 설명

ptrnptrn: required (string)
패턴

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

action
action: required (one of 0, 1, 2, 3, 4 - default: 0)
대응
탐지:	0,	패킷	차단:	1,	IP	차단:	2,	패킷	차단/Reset:	3,	IP	주소	차단/Reset:	4

block_tm
block_tm: required (integer - default: 150 - minimum: 1 - maximum: 3600)
차단 시간

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1 - default: 0)
덤프 사용여부
사용안함:	0,	사용:	1

email_use
email_use: required (one of 0, 1 - default: 0)
이메일 사용여부
사용안함:	0,	사용:	1

src_ips_signtr_port_id: required (integer)
src_ips_signtr_port_id
출발지 IPS 시그니처 포트 ID

src_port
src_port: required (string)
출발지 포트

dst_ips_signtr_port_id: required (integer)
dst_ips_signtr_port_id
목적지 IPS 시그니처 포트 ID

dst_port
dst_port: required (string)
목적지 포트

ips_usr_def_signtr_obj
ips_usr_def_signtr_obj: required (array of items)
Items: items
Items

ips_usr_def_signtr_id
ips_usr_def_signtr_id: required (integer)
사용자 정의 시그니처 ID

type
type: required (one of 0, 1, 2, 3 - default: 0)
유형
Contenet:	0,	URI	Content:	1,	Rawbyte:	2,	PCRE:	3

nocase_use
nocase_use: required (one of 0, 1 - default: 0)
NOCASE 사용여부
사용안함:	0,	사용:	1

prtnprtn: required (string)
패턴

offset
offset: required (integer - minimum: 0 - maximum: 65535)
OFFSET

depth
depth: required (integer - minimum: 0 - maximum: 65535)
DEPTH

distance
distance: required (integer - minimum: 0 - maximum: 65535)
DISTANCE

withinwithin: required (integer - minimum: 0 - maximum: 65535)
WITHIN

str_addr_obj
str_addr_obj: required (array of items)
Items: items
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

dst_addr_obj: required (array of items)
dst_addr_obj
Items: items
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

Example:
Example

{
		"cate":	11,
		"type":	3,
		"prtc":	3,
		"msg":	"시그니처	메시지	2",
		"risk":	2,
		"acrcy":	2,
		"effect":	2,
		"kr_desc":	"시그니처	국문	설명	2",
		"en_desc":	"시그니처	영어	설명	2",
		"jp_desc":	"시그니처	일어	설명	2",
		"ptrn":	"시그니처	패턴	2",
		"use":	1,
		"action":	1,
		"block_tm":	100,
		"log_use":	0,
		"dump_use":	1,
		"email_use":	1,
		"src_ips_signtr_port_id":	1,
		"src_port":	"8080",
		"dst_ips_signtr_port_id":	1,
		"dst_port":	"9090",
		"ips_usr_def_signtr_obj":	[{
				"ips_usr_def_signtr_id":	1,
				"type":	3,
				"nocase_use":	1,
				"prtn":	"alert	udp	any	any	->	any	any	(msg:\"test_detect\";		pcre:\"/ABCD/i\";	sid:250001;)",
				"offset":	65535,
				"depth":	65535,
				"distance":	65535,
				"within":	65535
		}],
		"str_addr_obj":	[{
				"addr_obj_id":	1
		}],
		"dst_addr_obj":	[{
				"addr_obj_id":	1
		}]
}

Response

HTTP status code 200

사용자 정의 시그니처 수정 성공

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

catecate: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 - default: 11)
카테고리
Application:	0,	AV	Manager:	1,	Backup	Manager:	2,	Browser:	3,	DB:	4,	Information	Disclosure:	5,	MALWARE	Traffic:	6,	Miscellaneous:	7,	Office:	8,	OS:	9,	Web	Application:	10,	User
Signature:	11,	Snort	Signature:	12

type
type: required (one of 0, 1, 2, 3 - default: 0)
유형
없음:	0,	수동설정:	1,	고급설정:	2,	snort시그니처:	3

prtcprtc: required (one of 0, 1, 2, 3 - default: 0)
프로토콜
IP:	0,	ICMP:	1,	TCP:	2,	UDP:	3

msgmsg: required (string)
메시지

riskrisk: required (one of 1, 2, 3 - default: 1)
위험도
하:	1,	중:	2,	상:	3

acrcy
acrcy: required (one of 1, 2, 3 - default: 1)
탐지 정확도
하:	1,	중:	2,	상:	3

effect
effect: required (one of 1, 2, 3 - default: 1)
성능 영향도
하:	1,	중:	2,	상:	3

kr_desc: required (string)
kr_desc
국문 설명

en_desc
en_desc: required (string)
영어 설명

jp_desc
jp_desc: required (string)
일어 설명

ptrnptrn: required (string)
패턴

useuse: required (one of 0, 1 - default: 0)

사용 여부
사용안함:	0,	사용:	1

action
action: required (one of 0, 1, 2, 3, 4 - default: 0)
대응
탐지:	0,	패킷	차단:	1,	IP	차단:	2,	패킷	차단/Reset:	3,	IP	주소	차단/Reset:	4

block_tm
block_tm: required (integer - default: 150 - minimum: 1 - maximum: 3600)
차단 시간

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1 - default: 0)
덤프 사용여부
사용안함:	0,	사용:	1

email_use: required (one of 0, 1 - default: 0)
email_use
이메일 사용여부
사용안함:	0,	사용:	1

src_ips_signtr_port_id
src_ips_signtr_port_id: required (integer)
출발지 IPS 시그니처 포트 ID

src_port: required (string)
src_port
출발지 포트

dst_ips_signtr_port_id
dst_ips_signtr_port_id: required (integer)
목적지 IPS 시그니처 포트 ID

dst_port
dst_port: required (string)
목적지 포트

ips_usr_def_signtr_obj
ips_usr_def_signtr_obj: required (array of items)
Items: items
Items

ips_usr_def_signtr_id
ips_usr_def_signtr_id: required (integer)
사용자 정의 시그니처 ID

type
type: required (one of 0, 1, 2, 3 - default: 0)
유형
Contenet:	0,	URI	Content:	1,	Rawbyte:	2,	PCRE:	3

nocase_use
nocase_use: required (one of 0, 1 - default: 0)
NOCASE 사용여부
사용안함:	0,	사용:	1

prtnprtn: required (string)
패턴

offset
offset: required (integer - minimum: 0 - maximum: 65535)
OFFSET

depth: required (integer - minimum: 0 - maximum: 65535)
depth
DEPTH

distance
distance: required (integer - minimum: 0 - maximum: 65535)
DISTANCE

withinwithin: required (integer - minimum: 0 - maximum: 65535)
WITHIN

str_addr_obj
str_addr_obj: required (array of items)
Items: items
Items

addr_obj_id: required (integer)
addr_obj_id
객체 ID

ip_ver
ip_ver: required (one of 1, 2, 3)
아이피 버전
1:	IPv4,	2:	IPv6,	3:	공통

name
name: required (string)
객체 이름

zone
zone: required (one of 1, 2, 3)
Zone 정보
내부:	1,	외부:	2,	DMZ:	3

addr_obj_type
addr_obj_type: required (one of 1, 2, 3, 4)
객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3,	그룹객체:	4

ip_info1
ip_info1: required (string)
IP 정보1

ip_info2
ip_info2: required (string)
IP 정보2

dst_addr_obj
dst_addr_obj: required (array of items)
Items: items
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (one of 1, 2, 3)
아이피 버전
1:	IPv4,	2:	IPv6,	3:	공통

name
name: required (string)
객체 이름

zone
zone: required (one of 1, 2, 3)
Zone 정보
내부:	1,	외부:	2,	DMZ:	3

addr_obj_type
addr_obj_type: required (one of 1, 2, 3, 4)
객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3,	그룹객체:	4

ip_info1
ip_info1: required (string)
IP 정보1

ip_info2
ip_info2: required (string)
IP 정보2

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

ips_signtr_id
ips_signtr_id: required (integer)
IPS 시그니처 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ips_prf_id":	1,
				"ips_signtr_id":	800000,
				"cate":	11,
				"type":	3,
				"prtc":	3,
				"msg":	"시그니처	메시지	2",
				"risk":	2,
				"acrcy":	2,
				"effect":	2,
				"kr_desc":	"시그니처	국문	설명	2",
				"en_desc":	"시그니처	영어	설명	2",
				"jp_desc":	"시그니처	일어	설명	2",
				"ptrn":	"시그니처	패턴	2",
				"use":	1,
				"action":	1,
				"block_tm":	100,
				"log_use":	0,
				"dump_use":	1,
				"email_use":	1,
				"src_ips_signtr_port_id":	1,
				"src_port":	"8080",
				"dst_ips_signtr_port_id":	1,
				"dst_port":	"9090",
				"ips_usr_def_signtr_obj":	[{
						"ips_usr_def_signtr_id":	1,
						"type":	3,
						"nocase_use":	1,
						"prtn":	"alert	udp	any	any	->	any	any	(msg:\"test_detect\";		pcre:\"/ABCD/i\";	sid:250001;)",
						"offset":	65535,
						"depth":	65535,
						"distance":	65535,
						"within":	65535
				}],
				"str_addr_obj":	[{
						"addr_obj_id":	1,
						"ip_ver":	1,
						"name":	"test_network_obj_1",
						"zone":	1,
						"addr_obj_type":	2,
						"ip_info1":	"100.100.100.0",
						"ip_info2":	"100.100.100.1"
				}],
				"dst_addr_obj":	[{
						"addr_obj_id":	1,
						"ip_ver":	1,
						"name":	"test_network_obj_1",
						"zone":	1,
						"addr_obj_type":	2,
						"ip_info1":	"100.100.100.0",
						"ip_info2":	"100.100.100.1"
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

DELETE

/ips/profiles/{ppk}/signatures/{pk}/user-define

사용자 정의 시그니처을(를) 삭제한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

pkpk: required (integer)
IPS 시그니처 ID ( ips_signtr_id )

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

Response

HTTP status code 200

사용자 정의 시그니처 삭제 성공

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

/ips/profiles/{ppk}/signatures/snort

Snort 시그니처를 추가한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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

snort_signature_list
snort_signature_list: required (array of string)
스노트 시그니처 리스트

ips_profile_list
ips_profile_list: required (array of integer)
사용 선택 프로파일 리스트

Example:
Example

{
		"snort_signature_list":	["alert	TCP	any	any	->	any	80	(msg:\"test_signature\";	content:\"abcdefg\";)"],
		"ips_profile_list":	[1,	2]
}

Response

HTTP status code 200

Snort 시그니처 추가 성공

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
result: required (array of ResIpsSignature)
결과 데이터

Items: ResIpsSignature
Items

ips_signtr_id
ips_signtr_id: required (integer)
IPS 시그니처 ID

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

catecate: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)
카테고리
Application:	0,	AV	Manager:	1,	Backup	Manager:	2,	Browser:	3,	DB:	4,	Information	Disclosure:	5,	MALWARE	Traffic:	6,	Miscellaneous:	7,	Office:	8,	OS:	9,	Web	Application:	10,	User	Signature:	11,	Snort
Signature:	12

msgmsg: required (string)
메시지

prtcprtc: required (one of 0, 1, 2, 3 - default: 0)
프로토콜
IP:	0,	ICMP:	1,	TCP:	2,	UDP:	3

src_port
src_port: required (string)
출발지 포트

dst_port
dst_port: required (string)
목적지 포트

ehost
ehost: required (string)
예외 호스트 정보

설명이 있는 경우 설명을 전달
설명이 없는 경우 주소 객체의 이름을 전달(첫번째 설정 객체 이름)
ehost_count
ehost_count: required (integer)
예외 호스트 객체 갯수

ehost_desc
ehost_desc: required (integer)
예외 호스트 설명 존재 여부
0:	설명	없음,	1:	설명	있음

action
action: required (one of 0, 1, 2, 3, 4 - default: 0)
대응
탐지:	0,	패킷	차단:	1,	IP	차단:	2,	패킷	차단/Reset:	3,	IP	주소	차단/Reset:	4

block_tm
block_tm: required (integer - default: 150 - minimum: 1 - maximum: 3600)
차단 시간

riskrisk: required (one of 1, 2, 3 - default: 1)
위험도
하:	1,	중:	2,	상:	3

acrcy
acrcy: required (one of 1, 2, 3 - default: 1)
탐지 정확도
하:	1,	중:	2,	상:	3

effect
effect: required (one of 1, 2, 3 - default: 1)
성능 영향도
하:	1,	중:	2,	상:	3

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1 - default: 0)
덤프 사용여부
사용안함:	0,	사용:	1

email_use: required (one of 0, 1 - default: 0)
email_use
이메일 사용여부
사용안함:	0,	사용:	1

kr_desc
kr_desc: required (string)
국문 설명

en_desc: required (string)
en_desc
영어 설명

jp_desc
jp_desc: required (string)
일어 설명

ptrnptrn: required (string)
패턴

attacker
attacker: required (one of 0, 1 - default: 0)
ATTACKER
출발지:	0,	목적지:	1

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ips_prf_id":	1,
				"ips_signtr_id":	800000,
				"use":	0,
				"cate":	0,
				"msg":	"시그니처	메시지",
				"prtc":	0,
				"src_port":	"90",
				"dst_port":	"90",
				"host":	"host1",
				"action":	0,
				"block_tm":	150,
				"risk":	1,
				"acrcy":	1,
				"effect":	1,
				"log_use":	1,
				"dump_use":	0,
				"email_use":	0,
				"kr_desc":	"시그니처	국문	설명",
				"en_desc":	"시그니처	영어	설명",
				"jp_desc":	"시그니처	일어	설명",
				"ptrn":	"alert	TCP	any	any	->	any	80	(msg:\"test_signature\";	content:\"abcdefg\";)",
				"attacker":	0
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

/ips/profiles/{ppk}/signatures/{pk}/snort

Snort 시그니처을(를) 수정한다.

Request

URI Parameters

ppkppk: required (integer)

IPS 프로파일 ID ( ips_prf_id )

pkpk: required (integer)
IPS 시그니처 ID ( ips_signtr_id )

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

snort_signature
snort_signature: required (string)
스노트 시그니처

Example:
Example

{
		"snort_signature":	"alert	udp	any	any	->	any	any	(msg:\"test_detect\";		pcre:\"/ABCD/i\";	sid:250001;)"
}

Response

HTTP status code 200

Snort 시그니처 수정 성공

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

ips_signtr_id
ips_signtr_id: required (integer)
IPS 시그니처 ID

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

catecate: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)
카테고리
Application:	0,	AV	Manager:	1,	Backup	Manager:	2,	Browser:	3,	DB:	4,	Information	Disclosure:	5,	MALWARE	Traffic:	6,	Miscellaneous:	7,	Office:	8,	OS:	9,	Web	Application:	10,	User
Signature:	11,	Snort	Signature:	12

msgmsg: required (string)
메시지

prtcprtc: required (one of 0, 1, 2, 3 - default: 0)
프로토콜
IP:	0,	ICMP:	1,	TCP:	2,	UDP:	3

src_port: required (string)
src_port

출발지 포트

dst_port
dst_port: required (string)
목적지 포트

ehost: required (string)
ehost
예외 호스트 정보

설명이 있는 경우 설명을 전달
설명이 없는 경우 주소 객체의 이름을 전달(첫번째 설정 객체 이름)
ehost_count: required (integer)
ehost_count
예외 호스트 객체 갯수

ehost_desc
ehost_desc: required (integer)
예외 호스트 설명 존재 여부
0:	설명	없음,	1:	설명	있음

action: required (one of 0, 1, 2, 3, 4 - default: 0)
action
대응
탐지:	0,	패킷	차단:	1,	IP	차단:	2,	패킷	차단/Reset:	3,	IP	주소	차단/Reset:	4

block_tm
block_tm: required (integer - default: 150 - minimum: 1 - maximum: 3600)
차단 시간

riskrisk: required (one of 1, 2, 3 - default: 1)
위험도
하:	1,	중:	2,	상:	3

acrcy
acrcy: required (one of 1, 2, 3 - default: 1)
탐지 정확도
하:	1,	중:	2,	상:	3

effect
effect: required (one of 1, 2, 3 - default: 1)
성능 영향도
하:	1,	중:	2,	상:	3

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1 - default: 0)
덤프 사용여부
사용안함:	0,	사용:	1

email_use: required (one of 0, 1 - default: 0)
email_use
이메일 사용여부
사용안함:	0,	사용:	1

kr_desc
kr_desc: required (string)
국문 설명

en_desc: required (string)
en_desc
영어 설명

jp_desc
jp_desc: required (string)
일어 설명

ptrnptrn: required (string)
패턴

attacker
attacker: required (one of 0, 1 - default: 0)
ATTACKER
출발지:	0,	목적지:	1

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ips_prf_id":	1,
				"ips_signtr_id":	800000,
				"use":	1,
				"cate":	11,
				"msg":	"시그니처	메시지	2",
				"prtc":	3,
				"src_port":	"9090",
				"dst_port":	"9090",
				"host":	"host1",
				"action":	1,
				"block_tm":	100,
				"risk":	2,
				"acrcy":	2,
				"effect":	2,
				"log_use":	0,
				"dump_use":	1,
				"email_use":	1,
				"kr_desc":	"시그니처	국문	설명	2",
				"en_desc":	"시그니처	영어	설명	2",
				"jp_desc":	"시그니처	일어	설명	2",
				"ptrn":	"alert	udp	any	any	->	any	any	(msg:\"test_detect\";		pcre:\"/ABCD/i\";	sid:250001;)",
				"attacker":	1
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

DELETE

/ips/profiles/{ppk}/signatures/{pk}/snort

Snort 시그니처을(를) 삭제한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

pkpk: required (integer)
IPS 시그니처 ID ( ips_signtr_id )

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

Snort 시그니처 삭제 성공

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

PUT

/ips/profiles/{ppk}/signatures/exceptions

IPS 프로파일 예외 호스트을(를) 수정한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

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
items: required (array of SetIpsSignatureHostExceptionList)
수정 아이템 목록

Items: SetIpsSignatureHostExceptionList
Items

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

except_desc
except_desc: (string - minLength: 0 - maxLength: 128)
예외 호스트 설명

exception_ids
exception_ids: required (array of SetExceptObjectType)
Items: SetExceptObjectType
Items

src_addr_obj_id
src_addr_obj_id: required (integer)
출발지 주소 객체 ID

dst_addr_obj_id
dst_addr_obj_id: required (integer)
목적지 주소 객체 ID

ips_signtr_id
ips_signtr_id: required (integer)
IPS 시그니처 ID

Example:
Example

{
		"items":	[
				{
						"ips_prf_id":	1,
						"ips_signtr_id":	800000,
						"except_desc":	"예외	호스트	설명",
						"exception_ids":	[
								{
										"src_addr_obj_id":	3,
										"dst_addr_obj_id":	4
								}
						]
				}
		]
}

Response

HTTP status code 200

IPS 프로파일 예외 호스트 수정 성공

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

dev_t: (string)
dev_t
개발용 메시지

Example:
Example

{
		"code":	"12001",
		"message":	"존재하지	않는	항목입니다."
}

GET

/ips/profiles/{ppk}/signatures/{pk}/exceptions

IPS 프로파일 예외 호스트 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
IPS 프로파일 ID ( ips_prf_id )

pkpk: required (integer)
IPS 시그니처 ID ( ips_signtr_id )

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

Response

HTTP status code 200

IPS 프로파일 예외 호스트 목록 조회 성공

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
result: required (array of GetIpsSignatureHostExceptionList)
결과 데이터

Items: GetIpsSignatureHostExceptionList
Items

ips_prf_id
ips_prf_id: required (integer)
IPS 프로파일 ID

except_desc
except_desc: (string - minLength: 0 - maxLength: 128)
예외 호스트 설명

exception_ids
exception_ids: required (array of GetExceptObjectType)
Items: GetExceptObjectType
Items

src_addr_obj_id
src_addr_obj_id: required (integer)
출발지 주소 객체 ID

src_ip_ver: required (integer)
src_ip_ver
출발지 IP 버전
1:	IPv4,	2:	IPv6

src_name
src_name: required (string)
출발지 주소 객체 이름

src_type
src_type: required (integer)
출발지 주소 객체 유형
1:	호스트,	2:	네트워크,	4:	그룹

src_zone
src_zone: required (integer)
출발지 주소 객체 Zone 정보
1:	내부,	2:	외부,	3:	DMZ

dst_addr_obj_id: required (integer)
dst_addr_obj_id
목적지 주소 객체 ID

dst_ip_ver
dst_ip_ver: required (integer)
목적지 IP 버전
1:	IPv4,	2:	IPv6

dst_name
dst_name: required (string)
목적지 주소 객체 이름

dst_type
dst_type: required (integer)
목적지 주소 객체 유형
1:	호스트,	2:	네트워크,	4:	그룹

dst_zone
dst_zone: required (integer)
목적지 주소 객체 Zone 정보
1:	내부,	2:	외부,	3:	DMZ

ips_signtr_id
ips_signtr_id: required (integer)
IPS 시그니처 ID

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"ips_prf_id":	1,
						"ips_signtr_id":	800000,
						"except_desc":	"예외	호스트	설명",
						"exception_ids":	[
								{
										"src_addr_obj_id":	3,
										"src_ip_ver":	1,
										"src_name":	"1_1_1_1_IN",
										"src_type":	1,
										"src_zone":	1,
										"dst_addr_obj_id":	4,
										"dst_ip_ver":	1,
										"dst_name":	"2_2_2_0_24",
										"dst_type":	2,
										"dst_zone":	1
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

시그니처 적용/취소

PUT

/command/ips-signatures/apply

시그니처을 적용합니다.

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

시그니처 적용 성공

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

/command/ips-signatures/cancel

시그니처을 취소합니다.

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

시그니처 취소 성공

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

IPS/DDoS 현재 상태

DELETE

/ips/status/attackers

선택한 공격자 목록을 삭제한다.

Request

Annotations

SupportedVersion:
SupportedVersion

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

del_ip_list
del_ip_list: required (array of string)
공격자 IP 목록

items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"del_ip_list":	[
				"1.1.1.1",
				"2.2.2.2"
		]
}

Response

HTTP status code 200

IPS/DDoS 현재 상태 공격자 목록 삭제 성공

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
code	속성값이	'ok'가	아닐	경우	errors	속성이	포함됨

result
result: required (boolean)
삭제 성공 여부

Example:
Example

{
		"code":	"ok",
		"result":	{
				"result":	true
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

/ips/status/attacker/reset

공격자 목록을 초기화한다.

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

ipv6_only
ipv6_only: required (one of 0, 1 - default: 0)
ipv6 공격자 목록만 초기화할 때 사용
ipv4/ipv6	공격자	목록	초기화:	0,	ipv6	공격자	목록	초기화:	1

items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"ipv6_only":	0
}

Response

HTTP status code 200

IPS/DDoS 현재 상태 공격자 목록 삭제 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (one of ok, pok, nok)
결과 코드

result: required (object)
result
결과 데이터
code	속성값이	'ok'가	아닐	경우	errors	속성이	포함됨

result
result: required (boolean)
초기화 성공 여부

Example:
Example

{
		"code":	"ok",
		"result":	{
				"result":	true
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

