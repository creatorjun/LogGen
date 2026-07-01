DDoS 프로파일 설정 REST API 문서

https://{url}/api/po

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/po

DDoS 프로파일 설정

/ddos/profiles

/ddos/profiles/{pk}

/ddos/profiles/exceptions

DDoS 프로파일 설정 적용/취소

/command/ddos-profiles/apply

/command/ddos-profiles/cancel

발신지 기반 Flooding 방어

/ddos/profiles/{ppk}/floodings

/ddos/profiles/{ppk}/floodings/exceptions

/ddos/profiles/{ppk}/floodings/{pk}/exceptions

발신지 기반 Flooding 방어 적용/취소

/command/ddos-floodings/apply

/command/ddos-floodings/cancel

DrDoS 공격 방어

/ddos/profiles/{ppk}/drdoses

/ddos/profiles/{ppk}/drdoses/exceptions

/ddos/profiles/{ppk}/drdoses/{pk}/exceptions

DrDoS 공격 방어 적용/취소

/command/ddos-drdoses/apply

/command/ddos-drdoses/cancel

스캔 공격 방어

/ddos/profiles/{ppk}/scans

/ddos/profiles/{ppk}/scans/exceptions

/ddos/profiles/{ppk}/scans/{pk}/exceptions

스캔 공격 방어 적용/취소

/command/ddos-scans/apply

/command/ddos-scans/cancel

보호 도메인 기반 트래픽 제한

/ddos/profiles/{ppk}/traffic-limites

/ddos/profiles/{ppk}/traffic-limites/exceptions

/ddos/profiles/{ppk}/traffic-limites/{pk}/exceptions

GET

GET

POST

  DELETE

PUT

  DELETE

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

PUT

PUT

GET

PUT

PUT

GET

PUT

GET

PUT

GET

POST

GET

  DELETE

GET

PUT

PUT

보호 도메인 기반 트래픽 제한 적용/취소

/command/ddos-traffic-limites/apply

/command/ddos-traffic-limites/cancel

행위 기반 웹 공격 방어

/ddos/profiles/{ppk}/webs

/ddos/profiles/{ppk}/webs/exceptions

/ddos/profiles/{ppk}/webs/{pk}/exceptions

행위 기반 웹 공격 방어 적용/취소

/command/ddos-webs/apply

/command/ddos-webs/cancel

응용 계층 방어

/ddos/profiles/{ppk}/app-layers

/ddos/profiles/{ppk}/app-layers/exceptions

/ddos/profiles/{ppk}/app-layers/{pk}/exceptions

응용 계층 방어 적용/취소

/command/ddos-app-layers/apply

/command/ddos-app-layers/cancel

스마트 패턴 학습 방어

/ddos/profiles/smarts/{pk}

/ddos/profiles/smarts/{pk}/exceptions

/ddos/profiles/smarts/{ppk}/exception-pattens

/ddos/profiles/smarts/{ppk}/exception-pattens/{pk}

/ddos/profiles/smarts/{pk}/study-statuses

스마트 패턴 학습 방어 적용/취소

/command/ddos-smarts/apply

/command/ddos-smarts/cancel

DDoS 프로파일 설정

GET

/ddos/profiles

DDoS 프로파일 설정 목록을 조회한다.

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

DDoS 프로파일 설정 목록 조회 성공

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
result: required (array of ResDDoSProfile)
결과 데이터

Items: ResDDoSProfile
Items

action
action: required (one of 0, 1 - default: 0)
대응 동작
탐지:	0,	차단:	1

name: required (string - minLength: 1 - maxLength: 32)
name
DDoS 프로파일 이름

descdesc: required (string - minLength: 0 - maxLength: 128)
DDoS 프로파일 설명

ddos_prf_id
ddos_prf_id: required (integer)
프로파일의 고유한 ID

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ddos_prf_id":	1,
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

/ddos/profiles

DDoS 프로파일 설정를 추가한다.

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
action
action: required (one of 0, 1 - default: 0)
대응 동작
탐지:	0,	차단:	1

name
name: required (string - minLength: 1 - maxLength: 32)
DDoS 프로파일 이름

descdesc: required (string - minLength: 0 - maxLength: 128)
DDoS 프로파일 설명

Example:
Example

{
		"action":	0,
		"name":	"DDoS	프로파일	이름",
		"desc":	"DDoS	프로파일	설명"
}

Response

HTTP status code 200

DDoS 프로파일 설정 추가 성공

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

action: required (one of 0, 1 - default: 0)
action
대응 동작
탐지:	0,	차단:	1

name
name: required (string - minLength: 1 - maxLength: 32)
DDoS 프로파일 이름

descdesc: required (string - minLength: 0 - maxLength: 128)
DDoS 프로파일 설명

ddos_prf_id
ddos_prf_id: required (integer)
프로파일의 고유한 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ddos_prf_id":	1,
				"action":	0,
				"name":	"DDoS	프로파일	이름",
				"desc":	"DDoS	프로파일	설명"
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

DELETE

/ddos/profiles

DDoS 프로파일 설정 목록을 (일괄)삭제한다.

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
items
items: required (array of object)
삭제 아이템 목록
default	프로파일(ddos_prf_id:	1)	삭제	불가

Example:
Example

{
		"items":	[
				{"ddos_prf_id":	2},
				{"ddos_prf_id":	3}
		]
}

Response

HTTP status code 200

DDoS 프로파일 설정 목록 삭제 성공

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

/ddos/profiles/{pk}

DDoS 프로파일 설정을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
프로파일의 고유한 ID ( ddos_prf_id )

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

DDoS 프로파일 설정 조회 성공

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

action
action: required (one of 0, 1 - default: 0)
대응 동작
탐지:	0,	차단:	1

name
name: required (string - minLength: 1 - maxLength: 32)
DDoS 프로파일 이름

descdesc: required (string - minLength: 0 - maxLength: 128)
DDoS 프로파일 설명

ddos_prf_id
ddos_prf_id: required (integer)
프로파일의 고유한 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ddos_prf_id":	1,
				"action":	0,
				"name":	"default",
				"desc":	"default	profile"
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

/ddos/profiles/{pk}

DDoS 프로파일 설정을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
프로파일의 고유한 ID ( ddos_prf_id )

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
action: required (one of 0, 1 - default: 0)
action
대응 동작
탐지:	0,	차단:	1

name
name: required (string - minLength: 1 - maxLength: 32)
DDoS 프로파일 이름

descdesc: required (string - minLength: 0 - maxLength: 128)
DDoS 프로파일 설명

Example:
Example

{
		"action":	1,
		"name":	"DDoS	프로파일	이름	2",
		"desc":	"DDoS	프로파일	설명	2"
}

Response

HTTP status code 200

DDoS 프로파일 설정 수정 성공

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

action
action: required (one of 0, 1 - default: 0)
대응 동작
탐지:	0,	차단:	1

name: required (string - minLength: 1 - maxLength: 32)
name
DDoS 프로파일 이름

descdesc: required (string - minLength: 0 - maxLength: 128)
DDoS 프로파일 설명

ddos_prf_id
ddos_prf_id: required (integer)
프로파일의 고유한 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ddos_prf_id":	1,
				"action":	1,
				"name":	"DDoS	프로파일	이름	2",
				"desc":	"DDoS	프로파일	설명	2"
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

DELETE

/ddos/profiles/{pk}

DDoS 프로파일 설정을(를) 삭제한다.
default	프로파일(pk:	1)	삭제	불가

Request

URI Parameters

pkpk: required (integer)
프로파일의 고유한 ID ( ddos_prf_id )

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

DDoS 프로파일 설정 삭제 성공

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

/ddos/profiles/exceptions

DDoS 프로파일의 정책 예외 호스트 스펙 정보을(를) 조회한다.

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

DDoS 프로파일의 정책 예외 호스트 스펙 정보 조회 성공

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

rule_ex_count: required (integer)
rule_ex_count
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

DDoS 프로파일 설정 적용/취소

PUT

/command/ddos-profiles/apply

DDoS 프로파일 설정을 적용합니다.

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

DDoS 프로파일 설정 적용 성공

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

/command/ddos-profiles/cancel

DDoS 프로파일 설정을 취소합니다.

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

DDoS 프로파일 설정 취소 성공

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

발신지 기반 Flooding 방어

GET

/ddos/profiles/{ppk}/floodings

발신지 기반 Flooding 방어 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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

발신지 기반 Flooding 방어 목록 조회 성공

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
result: required (array of ResDDoSFlooding)
결과 데이터

Items: ResDDoSFlooding
Items

ddos_flooding_id
ddos_flooding_id: required (integer)
DDOS FLOODING ID

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

base_tm
base_tm: required (integer - minimum: 1 - maximum: 60)
기준 시간

limit
limit: required (integer)
임계치

block_tm: required (integer - minimum: 1 - maximum: 86400)
block_tm
차단 시간

action
action: required (one of 0, 1 - default: 0)
대응
탐지:	0,	차단:	1

log_use: required (one of 0, 1, 2 - default: 1)
log_use

로그 사용여부
없음:	0,	로그:	1,	로그덤프:	2,

catecate: required (one of 0, 1, 2)
카테고리
발신지별:	0,	내부	발신지별:	1,	1:1	Flooding:	2

name
name: required (string)
항목

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

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ddos_flooding_id":	900001,
				"use":	0,
				"cate":	0,
				"name":	"Flooding	이름",
				"base_tm":	10,
				"limit":	1000000,
				"block_tm":	10,
				"ehost":	"예외호스트	설명",
				"ehost_count":	1,
				"ehost_desc":	1,
				"action":	0,
				"log_use":	1
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

/ddos/profiles/{ppk}/floodings

발신지 기반 Flooding 방어 목록을 (일괄)수정한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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
items
items: required (array of ReqDDoSFlooding)
수정 아이템 목록

Items: ReqDDoSFlooding
Items

ddos_flooding_id
ddos_flooding_id: required (integer)
DDOS FLOODING ID

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

base_tm
base_tm: required (integer - minimum: 1 - maximum: 60)
기준 시간

limit
limit: required (integer)
임계치

block_tm
block_tm: required (integer - minimum: 1 - maximum: 86400)
차단 시간

action
action: required (one of 0, 1 - default: 0)
대응
탐지:	0,	차단:	1

log_use
log_use: required (one of 0, 1, 2 - default: 1)
로그 사용여부
없음:	0,	로그:	1,	로그덤프:	2,

Example:
Example

{
		"items":	[{
				"ddos_flooding_id":	900001,
				"use":	1,
				"base_tm":	30,
				"limit":	2000000,
				"block_tm":	60,
				"action":	1,
				"log_use":	2
		}]
}

Response

HTTP status code 200

발신지 기반 Flooding 방어 목록 수정 성공

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

/ddos/profiles/{ppk}/floodings/exceptions

발신지 기반 Flooding 방어을(를) 수정한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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
items: required (array of SetFloodingHostExceptionList)
수정 아이템 목록

Items: SetFloodingHostExceptionList
Items

ddos_prf_id
ddos_prf_id: required (integer)
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

ddos_flooding_id
ddos_flooding_id: required (integer)
DDOS FLOODING ID

Example:
Example

{
		"items":	[
				{
						"ddos_prf_id":	1,
						"ddos_flooding_id":	910001,
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

발신지 기반 Flooding 방어 수정 성공

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

/ddos/profiles/{ppk}/floodings/{pk}/exceptions

발신지 기반 Flooding 방어 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

pkpk: required (integer)
DDOS FLOODING ID ( ddos_flooding_id )

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

발신지 기반 Flooding 방어 목록 조회 성공

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
result: required (array of GetFloodingHostExceptionList)
결과 데이터

Items: GetFloodingHostExceptionList
Items

ddos_prf_id
ddos_prf_id: required (integer)
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

ddos_flooding_id
ddos_flooding_id: required (integer)
DDOS FLOODING ID

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"ddos_prf_id":	1,
						"ddos_flooding_id":	900001,
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

발신지 기반 Flooding 방어 적용/취소

PUT

/command/ddos-floodings/apply

발신지 기반 Flooding 방어을 적용합니다.

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

발신지 기반 Flooding 방어 적용 성공

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

/command/ddos-floodings/cancel

발신지 기반 Flooding 방어을 취소합니다.

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

발신지 기반 Flooding 방어 취소 성공

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

DrDoS 공격 방어

GET

/ddos/profiles/{ppk}/drdoses

DrDoS 공격 방어 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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

DrDoS 공격 방어 목록 조회 성공

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
result: required (array of ResDDoSDrDos)
결과 데이터

Items: ResDDoSDrDos
Items

ddos_drdos_id
ddos_drdos_id: required (integer)
DDOS DRDOS ID

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

limit
limit: required (integer - minimum: 1 - maximum: 100000000)
임계치

log_type
log_type: required (one of 0, 1, 2 - default: 1)
로그 유형
없음:	0,	로그:	1,	로그덤프:	2,

action: required (one of 0, 1 - default: 0)
action
대응
탐지:	0,	차단:	1

name
name: required (string)
항목

ehost: required (string)
ehost
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

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ddos_drdos_id":	901001,
				"use":	0,
				"name":	"DrDoS	이름",
				"limit":	10000,
				"ehost":	"예외호스트	설명",
				"ehost_count":	1,
				"ehost_desc":	1,
				"log_type":	1,
				"action":	0
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

/ddos/profiles/{ppk}/drdoses

DrDoS 공격 방어 목록을 (일괄)수정한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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
items: required (array of ReqDDoSDrDos)
수정 아이템 목록

Items: ReqDDoSDrDos
Items

ddos_drdos_id
ddos_drdos_id: required (integer)
DDOS DRDOS ID

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

limit
limit: required (integer - minimum: 1 - maximum: 100000000)
임계치

log_type
log_type: required (one of 0, 1, 2 - default: 1)
로그 유형
없음:	0,	로그:	1,	로그덤프:	2,

action
action: required (one of 0, 1 - default: 0)
대응
탐지:	0,	차단:	1

Example:
Example

{
		"items":	[{
				"ddos_drdos_id":	901001,
				"use":	1,
				"limit":	100000000,
				"log_type":	2,
				"action":	1
		}]
}

Response

HTTP status code 200

DrDoS 공격 방어 목록 수정 성공

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

PUT

/ddos/profiles/{ppk}/drdoses/exceptions

DrDoS 공격 방어을(를) 수정한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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
items: required (array of SetDrDosHostExceptionList)
수정 아이템 목록

Items: SetDrDosHostExceptionList
Items

ddos_prf_id
ddos_prf_id: required (integer)
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

ddos_drdos_id
ddos_drdos_id: required (integer)
DDOS DRDOS ID

Example:
Example

{
		"items":	[
				{
						"ddos_prf_id":	1,
						"ddos_drdos_id":	901001,
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

DrDoS 공격 방어 수정 성공

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

/ddos/profiles/{ppk}/drdoses/{pk}/exceptions

DrDoS 공격 방어 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

pkpk: required (integer)
DDOS DRDOS ID ( ddos_drdos_id )

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

DrDoS 공격 방어 목록 조회 성공

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
result: required (array of GetDrDosHostExceptionList)
결과 데이터

Items: GetDrDosHostExceptionList
Items

ddos_prf_id
ddos_prf_id: required (integer)
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

ddos_drdos_id: required (integer)
ddos_drdos_id
DDOS DRDOS ID

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"ddos_prf_id":	1,
						"ddos_drdos_id":	901001,
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

DrDoS 공격 방어 적용/취소

PUT

/command/ddos-drdoses/apply

DrDoS 공격 방어을 적용합니다.

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

Example:
Example

{}

Response

HTTP status code 200

DrDoS 공격 방어 적용 성공

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

/command/ddos-drdoses/cancel

DrDoS 공격 방어을 취소합니다.

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

DrDoS 공격 방어 취소 성공

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

스캔 공격 방어

GET

/ddos/profiles/{ppk}/scans

스캔 공격 방어 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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

스캔 공격 방어 목록 조회 성공

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
result: required (array of ResDDoSScan)
결과 데이터

Items: ResDDoSScan
Items

ddos_scan_id
ddos_scan_id: required (integer)
DDOS SCAN ID

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

base_tm
base_tm: required (integer - default: 10 - minimum: 1 - maximum: 60)
기준 시간

limit
limit: required (integer)
임계치

block_tm
block_tm: required (integer - default: 1000 - minimum: 1 - maximum: 3600)
차단 시간

action
action: required (one of 0, 1 - default: 0)
대응
탐지:	0,	차단:	1

log_use: required (one of 0, 1, 2 - default: 1)
log_use
로그 사용여부
없음:	0,	로그:	1,	로그덤프:	2,

name
name: required (string)
항목

ehost: required (string)
ehost
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

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ddos_scan_id":	902001,
				"use":	0,
				"name":	"Scan	이름",
				"base_tm":	10,
				"limit":	300,
				"block_tm":	1000,
				"ehost":	"예외호스트	설명",
				"ehost_count":	1,
				"ehost_desc":	1,
				"action":	0,
				"log_use":	1
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

PUT

/ddos/profiles/{ppk}/scans

스캔 공격 방어 목록을 (일괄)수정한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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
items
items: required (array of ReqDDoSScan)
수정 아이템 목록

Items: ReqDDoSScan
Items

ddos_scan_id
ddos_scan_id: required (integer)
DDOS SCAN ID

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

base_tm
base_tm: required (integer - default: 10 - minimum: 1 - maximum: 60)
기준 시간

limit
limit: required (integer)
임계치

block_tm
block_tm: required (integer - default: 1000 - minimum: 1 - maximum: 3600)
차단 시간

action
action: required (one of 0, 1 - default: 0)
대응
탐지:	0,	차단:	1

log_use
log_use: required (one of 0, 1, 2 - default: 1)
로그 사용여부
없음:	0,	로그:	1,	로그덤프:	2,

Example:
Example

{
		"items":	[{
				"ddos_scan_id":	902001,
				"use":	1,
				"base_tm":	60,
				"limit":	65536,
				"block_tm":	3600,
				"action":	1,
				"log_use":	2
		}]
}

Response

HTTP status code 200

스캔 공격 방어 목록 수정 성공

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

PUT

/ddos/profiles/{ppk}/scans/exceptions

스캔 공격 방어을(를) 수정한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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
items: required (array of SetScanHostExceptionList)
수정 아이템 목록

Items: SetScanHostExceptionList
Items

ddos_prf_id
ddos_prf_id: required (integer)
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

ddos_scan_id
ddos_scan_id: required (integer - default: 902001)
DDOS SCAN ID

Example:
Example

{
		"items":	[
				{
						"ddos_prf_id":	1,
						"ddos_scan_id":	902001,
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

스캔 공격 방어 수정 성공

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

GET

/ddos/profiles/{ppk}/scans/{pk}/exceptions

스캔 공격 방어 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

pkpk: required (integer)
DDOS SCAN ID ( ddos_scan_id )

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

스캔 공격 방어 목록 조회 성공

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
result: required (array of GetScanHostExceptionList)
결과 데이터

Items: GetScanHostExceptionList
Items

ddos_prf_id
ddos_prf_id: required (integer)
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

dst_ip_ver: required (integer)
dst_ip_ver
목적지 IP 버전
1:	IPv4,	2:	IPv6

dst_name
dst_name: required (string)
목적지 주소 객체 이름

dst_type: required (integer)
dst_type
목적지 주소 객체 유형
1:	호스트,	2:	네트워크,	4:	그룹

dst_zone
dst_zone: required (integer)
목적지 주소 객체 Zone 정보
1:	내부,	2:	외부,	3:	DMZ

ddos_scan_id
ddos_scan_id: required (integer - default: 902001)
DDOS SCAN ID

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"ddos_prf_id":	1,
						"ddos_scan_id":	902001,
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

스캔 공격 방어 적용/취소

PUT

/command/ddos-scans/apply

스캔 공격 방어을 적용합니다.

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

스캔 공격 방어 적용 성공

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

/command/ddos-scans/cancel

스캔 공격 방어을 취소합니다.

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

스캔 공격 방어 취소 성공

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

보호 도메인 기반 트래픽 제한

GET

/ddos/profiles/{ppk}/traffic-limites

보호 도메인 기반 트래픽 제한 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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

보호 도메인 기반 트래픽 제한 목록 조회 성공

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
result: required (array of ResDDoSTrafficLimit)
결과 데이터

Items: ResDDoSTrafficLimit
Items

ddos_trfc_limit_id
ddos_trfc_limit_id: required (integer)
DDOS 트래픽 제한 ID

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

default: required (integer - minimum: 1 - maximum: 100000000)
default
기본값

minmin: required (integer - minimum: 1 - maximum: 100000000)
최소값

maxmax: required (integer - minimum: 1 - maximum: 100000000)
최대값

learn_type
learn_type: required (one of 0, 1, 2, 3 - default: 0)
학습 유형
학습안함:	0,	기본값:	1,	학습값:	2,	둘중큰값:	3

learn_prd
learn_prd: required (one of 0, 1, 2, 3 - default: 0)
학습 주기
사용안함:	0,	1일:	1,	1주일:	2,	한달:	3

log_type
log_type: required (one of 0, 1, 2 - default: 1)
로그 유형
없음:	0,	로그:	1,	로그덤프:	2,

action
action: required (one of 0, 1 - default: 0)
대응
탐지:	0,	차단:	1

name
name: required (string)
항목

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

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ddos_trfc_limit_id":	903001,
				"use":	0,
				"name":	"트래픽	제한	이름",
				"default":	200000,
				"min":	1000,
				"max":	20000000,
				"learn_type":	0,
				"learn_prd":	0,
				"ehost":	"예외호스트	설명",
				"ehost_count":	1,
				"ehost_desc":	1,
				"log_type":	1,
				"action":	0
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

/ddos/profiles/{ppk}/traffic-limites

보호 도메인 기반 트래픽 제한 목록을 (일괄)수정한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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
items: required (array of ReqDDoSTrafficLimit)
items
수정 아이템 목록

Items: ReqDDoSTrafficLimit
Items

ddos_trfc_limit_id
ddos_trfc_limit_id: required (integer)
DDOS 트래픽 제한 ID

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

default
default: required (integer - minimum: 1 - maximum: 100000000)
기본값

minmin: required (integer - minimum: 1 - maximum: 100000000)
최소값

maxmax: required (integer - minimum: 1 - maximum: 100000000)
최대값

learn_type
learn_type: required (one of 0, 1, 2, 3 - default: 0)
학습 유형
학습안함:	0,	기본값:	1,	학습값:	2,	둘중큰값:	3

learn_prd
learn_prd: required (one of 0, 1, 2, 3 - default: 0)
학습 주기
사용안함:	0,	1일:	1,	1주일:	2,	한달:	3

log_type: required (one of 0, 1, 2 - default: 1)
log_type
로그 유형
없음:	0,	로그:	1,	로그덤프:	2,

action
action: required (one of 0, 1 - default: 0)
대응
탐지:	0,	차단:	1

Example:
Example

{
		"items":	[{
				"ddos_trfc_limit_id":	903001,
				"use":	1,
				"default":	1000000,
				"min":	100000000,
				"max":	100000000,
				"learn_type":	1,
				"learn_prd":	1,
				"log_type":	2,
				"action":	1
		}]
}

Response

HTTP status code 200

보호 도메인 기반 트래픽 제한 목록 수정 성공

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

/ddos/profiles/{ppk}/traffic-limites/exceptions

보호 도메인 기반 트래픽 제한을(를) 수정한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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
items: required (array of SetTrafficLimitHostExceptionList)
수정 아이템 목록

Items: SetTrafficLimitHostExceptionList
Items

ddos_prf_id
ddos_prf_id: required (integer)
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

ddos_trfc_limit_id
ddos_trfc_limit_id: required (integer - default: 903001)
DDOS 트래픽 제한 ID

Example:
Example

{
		"items":	[
				{
						"ddos_prf_id":	1,
						"ddos_trfc_limit_id":	903001,
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

보호 도메인 기반 트래픽 제한 수정 성공

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

/ddos/profiles/{ppk}/traffic-limites/{pk}/exceptions

보호 도메인 기반 트래픽 제한 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

pkpk: required (integer)
DDOS 트래픽 제한 ID ( ddos_trfc_limit_id )

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

보호 도메인 기반 트래픽 제한 목록 조회 성공

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
result: required (array of GetTrafficLimitHostExceptionList)
결과 데이터

Items: GetTrafficLimitHostExceptionList
Items

ddos_prf_id
ddos_prf_id: required (integer)
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

ddos_trfc_limit_id
ddos_trfc_limit_id: required (integer - default: 903001)
DDOS 트래픽 제한 ID

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"ddos_prf_id":	1,
						"ddos_trfc_limit_id":	903001,
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

보호 도메인 기반 트래픽 제한 적용/취소

PUT

/command/ddos-traffic-limites/apply

보호 도메인 기반 트래픽 제한을 적용합니다.

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

보호 도메인 기반 트래픽 제한 적용 성공

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

/command/ddos-traffic-limites/cancel

보호 도메인 기반 트래픽 제한을 취소합니다.

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

보호 도메인 기반 트래픽 제한 취소 성공

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

행위 기반 웹 공격 방어

GET

/ddos/profiles/{ppk}/webs

행위 기반 웹 공격 방어 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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

행위 기반 웹 공격 방어 목록 조회 성공

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
result: required (array of ResDDoSWeb)
결과 데이터

Items: ResDDoSWeb
Items

ddos_web_id
ddos_web_id: required (integer)
DDOS WEB ID

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

name
name: required (string)
항목

base_tm
base_tm: required (integer)
기준 시간

paramparam: required (string)
파라미터

param1_key
param1_key: required (integer)
파라미터1 키값

param2_key
param2_key: required (integer)
파라미터2 키값

limit
limit: required (integer)
제한

block_tm
block_tm: required (integer - minimum: 1 - maximum: 3600)
차단 시간

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

log_type
log_type: required (one of 0, 1, 2 - default: 1)
로그 유형
없음:	0,	로그:	1,	로그덤프:	2,

action
action: required (one of 0, 1 - default: 0)
대응
탐지:	0,	차단:	1

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ddos_prf_id":	1,
				"ddos_web_id":	904001,
				"use":	0,
				"name":	"WEB	이름",
				"base_tm":	0,
				"param":	"100000/10",
				"param1_key":	1,
				"param2_key":	2,
				"limit":	500,
				"block_tm":	20,
				"ehost":	"예외호스트	설명",
				"ehost_count":	1,
				"ehost_desc":	1,
				"log_type":	1,
				"action":	0
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

/ddos/profiles/{ppk}/webs

행위 기반 웹 공격 방어 목록을 (일괄)수정한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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
items: required (array of ReqDDoSWeb)
items
수정 아이템 목록

Items: ReqDDoSWeb
Items

ddos_web_id
ddos_web_id: required (integer)
DDOS WEB ID

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

base_tm
base_tm: required (integer)
기준 시간

param1
param1: required (integer)
파라미터1 값

param2
param2: required (integer)
파라미터2 값

limit
limit: required (integer)
제한

block_tm
block_tm: required (integer - minimum: 1 - maximum: 3600)
차단 시간

log_type
log_type: required (one of 0, 1, 2 - default: 1)
로그 유형
없음:	0,	로그:	1,	로그덤프:	2,

action
action: required (one of 0, 1 - default: 0)
대응
탐지:	0,	차단:	1

Example:
Example

{
		"items":	[{
				"ddos_web_id":	904001,
				"use":	1,
				"base_tm":	60,
				"param1":	200000,
				"param2":	20,
				"limit":	100000000,
				"block_tm":	3600,
				"log_type":	2,
				"action":	1
		}]
}

Response

HTTP status code 200

행위 기반 웹 공격 방어 목록 수정 성공

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

/ddos/profiles/{ppk}/webs/exceptions

행위 기반 웹 공격 방어을(를) 수정한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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
items: required (array of SetWebHostExceptionList)
items
수정 아이템 목록

Items: SetWebHostExceptionList
Items

ddos_prf_id
ddos_prf_id: required (integer)
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

ddos_web_id
ddos_web_id: required (integer - default: 904001)
DDOS WEB ID

Example:
Example

{
		"items":	[
				{
						"ddos_prf_id":	1,
						"ddos_web_id":	904001,
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

행위 기반 웹 공격 방어 수정 성공

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

/ddos/profiles/{ppk}/webs/{pk}/exceptions

행위 기반 웹 공격 방어 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

pkpk: required (integer)
DDOS WEB ID ( ddos_web_id )

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

행위 기반 웹 공격 방어 목록 조회 성공

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
result: required (array of GetWebHostExceptionList)
결과 데이터

Items: GetWebHostExceptionList
Items

ddos_prf_id
ddos_prf_id: required (integer)
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

ddos_web_id
ddos_web_id: required (integer - default: 904001)
DDOS WEB ID

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"ddos_prf_id":	1,
						"ddos_web_id":	904001,
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

행위 기반 웹 공격 방어 적용/취소

PUT

/command/ddos-webs/apply

행위 기반 웹 공격 방어을 적용합니다.

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

행위 기반 웹 공격 방어 적용 성공

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

/command/ddos-webs/cancel

행위 기반 웹 공격 방어을 취소합니다.

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

행위 기반 웹 공격 방어 취소 성공

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

응용 계층 방어

GET

/ddos/profiles/{ppk}/app-layers

응용 계층 방어 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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

응용 계층 방어 목록 조회 성공

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
result: required (array of ResDDoSAppLayer)
결과 데이터

Items: ResDDoSAppLayer
Items

ddos_app_layer_id
ddos_app_layer_id: required (integer)
DDOS APP LAYER ID

useuse: required (one of 0, 1 - default: 0)

사용 여부
사용안함:	0,	사용:	1

catecate: required (one of 0, 1, 2, 3, 4, 5)
카테고리
HTTP:	0,	DNS:	1,	VoIP:	2,	POP3:	3,	IMAP:	04,	SMTP:	5

name
name: required (string)
항목

base_tm
base_tm: required (integer - minimum: 1 - maximum: 10000)
기준 시간

paramparam: required (string)
파라미터

param1_key
param1_key: required (integer)
파라미터1 키값

param2_key
param2_key: required (integer)
파라미터2 키값

limit
limit: required (integer)
제한

block_tm
block_tm: required (integer - minimum: 1 - maximum: 3600)
차단 시간

ehost: required (string)
ehost
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

log_type
log_type: required (one of 0, 1, 2 - default: 1)
로그 유형
없음:	0,	로그:	1,	로그덤프:	2,

action
action: required (one of 0, 1 - default: 0)
대응
탐지:	0,	차단:	1

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ddos_prf_id":	1,
				"ddos_app_layer_id":	905001,
				"use":	0,
				"cate":	0,
				"name":	"APP	LAYER	이름",
				"base_tm":	10,
				"param":	"100000/10",
				"param1_key":	1,
				"param2_key":	2,
				"limit":	10,
				"block_tm":	30,
				"ehost":	"예외호스트	설명",
				"ehost_count":	1,
				"ehost_desc":	1,
				"log_type":	1,
				"action":	0
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

/ddos/profiles/{ppk}/app-layers

응용 계층 방어 목록을 (일괄)수정한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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
items: required (array of ReqDDoSAppLayer)
수정 아이템 목록

Items: ReqDDoSAppLayer
Items

ddos_app_layer_id
ddos_app_layer_id: required (integer)
DDOS APP LAYER ID

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

base_tm
base_tm: required (integer - minimum: 1 - maximum: 10000)
기준 시간

param1
param1: required (integer)
파라미터1 값

param2: required (integer)
param2
파라미터2 값

limit
limit: required (integer)
제한

block_tm
block_tm: required (integer - minimum: 1 - maximum: 3600)
차단 시간

log_type
log_type: required (one of 0, 1, 2 - default: 1)
로그 유형
없음:	0,	로그:	1,	로그덤프:	2,

action
action: required (one of 0, 1 - default: 0)
대응
탐지:	0,	차단:	1

Example:
Example

{
		"items":	[{
				"ddos_app_layer_id":	905001,
				"use":	1,
				"base_tm":	10000,
				"param1":	200000,
				"param2":	20,
				"limit":	100000000,
				"block_tm":	3600,
				"log_type":	2,
				"action":	1
		}]
}

Response

HTTP status code 200

응용 계층 방어 목록 수정 성공

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

/ddos/profiles/{ppk}/app-layers/exceptions

DDoS 예외 호스트 목록을(를) 수정한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

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
items: required (array of SetAppLayerHostExceptionList)
수정 아이템 목록

Items: SetAppLayerHostExceptionList
Items

ddos_prf_id
ddos_prf_id: required (integer)
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

ddos_app_layer_id
ddos_app_layer_id: required (integer - default: 905001)
DDOS APP LAYER ID

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"ddos_prf_id":	1,
						"ddos_app_layer_id":	905001,
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

Response

HTTP status code 200

DDoS 예외 호스트 목록 수정 성공

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

/ddos/profiles/{ppk}/app-layers/{pk}/exceptions

DDoS 예외 호스트 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DDOS 프로파일 ID ( ddos_prf_id )

pkpk: required (integer)
DDOS APP LAYER ID ( ddos_app_layer_id )

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

DDoS 예외 호스트 목록 조회 성공

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
result: required (array of GetAppLayerHostExceptionList)
결과 데이터

Items: GetAppLayerHostExceptionList
Items

ddos_prf_id
ddos_prf_id: required (integer)
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

ddos_app_layer_id: required (integer - default: 905001)
ddos_app_layer_id
DDOS APP LAYER ID

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"ddos_prf_id":	1,
						"ddos_app_layer_id":	905001,
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

응용 계층 방어 적용/취소

PUT

/command/ddos-app-layers/apply

응용 계층 방어을 적용합니다.

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

응용 계층 방어 적용 성공

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

/command/ddos-app-layers/cancel

응용 계층 방어을 취소합니다.

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

응용 계층 방어 취소 성공

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

스마트 패턴 학습 방어

GET

/ddos/profiles/smarts/{pk}

스마트 패턴 학습 방어을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
DDoS 프로파일 ID ( ddos_prf_id )

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

스마트 패턴 학습 방어 조회 성공

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

useuse: required (one of 0, 1 - default: 0)
사용여부
사용안함:	0,	사용:	1

ptrn_cnt
ptrn_cnt: required (integer - default: 5 - minimum: 5 - maximum: 10)
패턴 수

active_pps: required (integer - default: 1000000 - minimum: 1 - maximum: 100000000)
active_pps
활성화 PPS

block_pps
block_pps: required (integer - default: 10000 - minimum: 1 - maximum: 100000000)
차단 PPS

block_tm
block_tm: required (integer - default: 20 - minimum: 1 - maximum: 3600)
차단 시간

action
action: required (one of 0, 1 - default: 0)
대응
탐지:	0,	차단:	1

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

ddos_prf_id
ddos_prf_id: required (integer)
DDoS 프로파일 ID

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

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ddos_prf_id":	1,
				"use":	0,
				"ptrn_cnt":	5,
				"active_pps":	1000000,
				"block_pps":	10000,
				"block_tm":	20,
				"ehost":	"예외호스트	설명",
				"ehost_count":	1,
				"ehost_desc":	1,
				"action":	0,
				"log_use":	1
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

/ddos/profiles/smarts/{pk}

스마트 패턴 학습 방어을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
DDoS 프로파일 ID ( ddos_prf_id )

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
items
items: required (array of ReqDDoSSmart)
수정 아이템 목록

Items: ReqDDoSSmart
Items

ddos_prf_id
ddos_prf_id: required (integer)
DDoS 프로파일 ID

useuse: required (one of 0, 1 - default: 0)
사용여부
사용안함:	0,	사용:	1

ptrn_cnt
ptrn_cnt: required (integer - default: 5 - minimum: 5 - maximum: 10)
패턴 수

active_pps
active_pps: required (integer - default: 1000000 - minimum: 1 - maximum: 100000000)
활성화 PPS

block_pps
block_pps: required (integer - default: 10000 - minimum: 1 - maximum: 100000000)
차단 PPS

block_tm
block_tm: required (integer - default: 20 - minimum: 1 - maximum: 3600)
차단 시간

action
action: required (one of 0, 1 - default: 0)
대응
탐지:	0,	차단:	1

log_use
log_use: required (one of 0, 1 - default: 1)
로그 사용여부
사용안함:	0,	사용:	1

Example:
Example

{
		"items":	[{
				"ddos_prf_id":	1,
				"use":	1,
				"ptrn_cnt":	10,
				"active_pps":	100000000,
				"block_pps":	100000000,
				"block_tm":	3600,
				"action":	1,
				"log_use":	0
		}]
}

Response

HTTP status code 200

스마트 패턴 학습 방어 수정 성공

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

GET

/ddos/profiles/smarts/{pk}/exceptions

스마트 패턴 예외 호스트 목록을 조회한다.

Request

URI Parameters

pkpk: required (integer)
DDoS 프로파일 ID ( ddos_prf_id )

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

스마트 패턴 예외 호스트 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of GetSmartPattenHostExceptionList)
result
결과 데이터

Items: GetSmartPattenHostExceptionList
Items

ddos_prf_id
ddos_prf_id: required (integer)
IPS 프로파일 ID

except_desc
except_desc: (string - minLength: 0 - maxLength: 128)
예외 호스트 설명

exception_ids
exception_ids: required (array of GetExceptObjectType)
Items: GetExceptObjectType
Items

src_addr_obj_id: required (integer)
src_addr_obj_id
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

dst_ip_ver: required (integer)
dst_ip_ver

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

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"ddos_prf_id":	1,
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

PUT

/ddos/profiles/smarts/{pk}/exceptions

스마트 패턴 예외 호스트 목록을 (일괄)수정한다.

Request

URI Parameters

pkpk: required (integer)
DDoS 프로파일 ID ( ddos_prf_id )

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

addr_obj_id_list
addr_obj_id_list: required (array of SetSmartPattenHostExceptionList)
예외 호스트 목록

Items: SetSmartPattenHostExceptionList
Items

ddos_prf_id: required (integer)
ddos_prf_id
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

items
items: required (array of object)
수정될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{
						"ddos_prf_id":	1,
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

스마트 패턴 예외 호스트 목록 수정 성공

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
result: required (array of object)
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

GET

/ddos/profiles/smarts/{ppk}/exception-pattens

학습 예외 패턴 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DDoS 프로파일 ID ( ddos_prf_id )

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

학습 예외 패턴 목록 조회 성공

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
result: required (array of ResSmartExceptionPatten)
결과 데이터

Items: ResSmartExceptionPatten
Items

dst_ip
dst_ip: required (string)
목적지 아이피

dst_port
dst_port: required (integer - minimum: 0 - maximum: 65535)
목적지 포트

tostos: required (integer)
TYPE OF SERVICE

ttlttl: required (integer)
TIME TO LIVE

proto
proto: required (integer)
프로토콜

fragfrag: required (integer)
FRAGEMENT FLAG

packet_size
packet_size: required (integer)
패킷 크기

param1: required (integer)
param1
PARAM1

param2
param2: required (integer)
PARAM2

header_len
header_len: required (integer)
헤더 길이

seq_num
seq_num: required (integer)
시퀀스 넘버

ddos_prf_id
ddos_prf_id: required (integer)
DDoS 프로파일 ID

ddos_smart_excpt_ptrn_id: required (integer)
ddos_smart_excpt_ptrn_id
DDoS 스마트 예외 패턴 ID

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ddos_prf_id":	1,
				"ddos_smart_excpt_ptrn_id":	1,
				"dst_ip":	"1.1.1.1",
				"dst_port":	80,
				"tos":	192,
				"ttl":	255,
				"proto":	6,
				"frag":	0,
				"packet_size":	78,
				"param1":	24,
				"param2":	4096,
				"header_len":	20,
				"seq_num":	12345
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

/ddos/profiles/smarts/{ppk}/exception-pattens

학습 예외 패턴를 추가한다.

Request

URI Parameters

ppkppk: required (integer)
DDoS 프로파일 ID ( ddos_prf_id )

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
dst_ip
dst_ip: required (string)
목적지 아이피

dst_port
dst_port: required (integer - minimum: 0 - maximum: 65535)
목적지 포트

tostos: required (integer)
TYPE OF SERVICE

ttlttl: required (integer)
TIME TO LIVE

proto
proto: required (integer)
프로토콜

fragfrag: required (integer)
FRAGEMENT FLAG

packet_size
packet_size: required (integer)
패킷 크기

param1
param1: required (integer)
PARAM1

param2
param2: required (integer)
PARAM2

header_len: required (integer)
header_len

헤더 길이

seq_num
seq_num: required (integer)
시퀀스 넘버

Example:
Example

{
		"dst_ip":	"1.1.1.1",
		"dst_port":	80,
		"tos":	192,
		"ttl":	255,
		"proto":	6,
		"frag":	0,
		"packet_size":	78,
		"param1":	24,
		"param2":	4096,
		"header_len":	20,
		"seq_num":	12345
}

Response

HTTP status code 200

학습 예외 패턴 추가 성공

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

dst_ip
dst_ip: required (string)
목적지 아이피

dst_port
dst_port: required (integer - minimum: 0 - maximum: 65535)
목적지 포트

tostos: required (integer)
TYPE OF SERVICE

ttlttl: required (integer)
TIME TO LIVE

proto
proto: required (integer)
프로토콜

fragfrag: required (integer)
FRAGEMENT FLAG

packet_size: required (integer)
packet_size
패킷 크기

param1
param1: required (integer)
PARAM1

param2
param2: required (integer)
PARAM2

header_len
header_len: required (integer)
헤더 길이

seq_num
seq_num: required (integer)
시퀀스 넘버

ddos_prf_id: required (integer)
ddos_prf_id
DDoS 프로파일 ID

ddos_smart_excpt_ptrn_id
ddos_smart_excpt_ptrn_id: required (integer)
DDoS 스마트 예외 패턴 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ddos_prf_id":	1,
				"ddos_smart_excpt_ptrn_id":	1,
				"dst_ip":	"1.1.1.1",
				"dst_port":	80,
				"tos":	192,
				"ttl":	255,
				"proto":	6,
				"frag":	0,
				"packet_size":	78,
				"param1":	24,
				"param2":	4096,
				"header_len":	20,
				"seq_num":	12345
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

GET

/ddos/profiles/smarts/{ppk}/exception-pattens/{pk}

학습 예외 패턴을(를) 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DDoS 프로파일 ID ( ddos_prf_id )

pkpk: required (integer)
DDoS 스마트 예외 패턴 ID ( ddos_smart_excpt_ptrn_id )

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

학습 예외 패턴 조회 성공

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

dst_ip
dst_ip: required (string)
목적지 아이피

dst_port
dst_port: required (integer - minimum: 0 - maximum: 65535)
목적지 포트

tostos: required (integer)
TYPE OF SERVICE

ttlttl: required (integer)
TIME TO LIVE

proto
proto: required (integer)
프로토콜

fragfrag: required (integer)
FRAGEMENT FLAG

packet_size
packet_size: required (integer)
패킷 크기

param1
param1: required (integer)
PARAM1

param2
param2: required (integer)
PARAM2

header_len
header_len: required (integer)
헤더 길이

seq_num
seq_num: required (integer)
시퀀스 넘버

ddos_prf_id
ddos_prf_id: required (integer)
DDoS 프로파일 ID

ddos_smart_excpt_ptrn_id: required (integer)
ddos_smart_excpt_ptrn_id
DDoS 스마트 예외 패턴 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ddos_prf_id":	1,
				"ddos_smart_excpt_ptrn_id":	1,
				"dst_ip":	"1.1.1.1",
				"dst_port":	80,
				"tos":	192,
				"ttl":	255,
				"proto":	6,
				"frag":	0,
				"packet_size":	78,
				"param1":	24,
				"param2":	4096,
				"header_len":	20,
				"seq_num":	12345
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

/ddos/profiles/smarts/{ppk}/exception-pattens/{pk}

학습 예외 패턴을(를) 삭제한다.

Request

URI Parameters

ppkppk: required (integer)
DDoS 프로파일 ID ( ddos_prf_id )

pkpk: required (integer)
DDoS 스마트 예외 패턴 ID ( ddos_smart_excpt_ptrn_id )

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

학습 예외 패턴 삭제 성공

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

/ddos/profiles/smarts/{pk}/study-statuses

학습 현황 목록을 조회한다.

Request

URI Parameters

pkpk: required (integer)
DDoS 프로파일 ID ( ddos_prf_id )

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

qq: (object)
검색 필터 조건(string)
q=속성 %3D 값 , 속성 %3D 값```

ipip: (string)
IP 주소

Example:
Example

?q=ip%3D1.1.1.1

Response

HTTP status code 200

학습 현황 목록 조회 성공

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
result: required (array of SmartStudyStatus)
결과 데이터

Items: SmartStudyStatus
Items

dst_ip: required (string)
dst_ip
목적지 아이피

dst_port
dst_port: required (integer - minimum: 0 - maximum: 65535)
목적지 포트

tostos: required (integer)
TYPE OF SERVICE

ttlttl: required (integer)
TIME TO LIVE

proto
proto: required (integer)
프로토콜

fragfrag: required (integer)
FRAGEMENT FLAG

packet_size
packet_size: required (integer)
패킷 크기

param1
param1: required (integer)
PARAM1

param2
param2: required (integer)
PARAM2

header_len
header_len: required (integer)
헤더 길이

seq_num
seq_num: required (integer)
시퀀스 넘버

remain
remain: required (integer)
남은시간

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"dst_ip":	"1.1.1.1",
				"dst_port":	80,
				"tos":	192,
				"ttl":	255,
				"proto":	6,
				"frag":	0,
				"packet_size":	78,
				"param1":	24,
				"param2":	4096,
				"header_len":	20,
				"seq_num":	12345,
				"remain":	11
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

스마트 패턴 학습 방어 적용/취소

PUT

/command/ddos-smarts/apply

스마트 패턴 학습 방어을 적용합니다.

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

스마트 패턴 학습 방어 적용 성공

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

/command/ddos-smarts/cancel

스마트 패턴 학습 방어을 취소합니다.

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

스마트 패턴 학습 방어 취소 성공

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

