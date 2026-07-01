GET

GET

PUT

PUT

PUT

DNS 보안 공통 설정 REST API 문서

https://{host}/api/op

host
host: required (string)
[IP]:[GUI 접속 PORT]
443	포트는	생략	가능

Example:
Example

192.168.100.100:443

DNS 보안 DB 체크

/dnssec/dbcheck

DNS 보안 공통 설정

/dnssec/setting

DNS 보안 공통 설정 적용/취소

/command/dnssec-setting/apply

/command/dnssec-setting/cancel

DNS 보안 DB 체크

GET

/dnssec/dbcheck

DNS 보안 DB 체크을(를) 조회한다.

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

DNS 보안 DB 체크 조회 성공

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

result
result: required (integer)
DB 업데이트 여부
업데이트	필요:	0,	업데이트	완료:	1

Example:
Example

{
		"code":	"ok",
		"result":	{
				"result":	1
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

DNS 보안 공통 설정

GET

/dnssec/setting

DNS 보안 공통 설정을(를) 조회한다.

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

DNS 보안 공통 설정 조회 성공

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

useuse: required (one of 1, 2 - default: 2)
사용 여부
1:	사용,	2:	사용	안함

repute_warning_score
repute_warning_score: required (integer - default: 10000 - minimum: 0 - maximum: 2000000)
평판 경고 점수(0~2,000,000)

repute_blocking_score
repute_blocking_score: required (integer - default: 10000 - minimum: 0 - maximum: 2000000)
평판 차단 점수(0~2,000,000)

repute_domain_del_cycle
repute_domain_del_cycle: required (integer - default: 86400 - minimum: 0 - maximum: 31536000)
평판 도메인 삭제 주기(초)
(0~31,536,000)

repute_sub_domain_del_cycle
repute_sub_domain_del_cycle: required (integer - default: 3600 - minimum: 0 - maximum: 31536000)
평판 서브 도메인 삭제 추기(초)
(0~31,536,000)

repute_tunnel_domain_del_cycle
repute_tunnel_domain_del_cycle: required (integer - default: 2592000 - minimum: 0 - maximum: 31536000)
평판 터널링 도메인 삭제 주기(초 단위, 0 ~ 31,536,000)

ml_use
ml_use: required (one of 1, 2 - default: 2)
ML 엔진 사용 여부
1:	사용,	2:	사용안함(기본값)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"use":	1,
				"repute_warning_score":	10000,
				"repute_blocking_score":	10000,
				"repute_domain_del_cycle":	86400,
				"repute_sub_domain_del_cycle":	3600,
				"repute_tunnel_domain_del_cycle":	2592000,
				"ml_use":	0
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

/dnssec/setting

DNS 보안 공통 설정을(를) 수정한다.

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

useuse: required (one of 1, 2 - default: 2)
사용 여부
1:	사용,	2:	사용	안함

repute_warning_score
repute_warning_score: required (integer - default: 10000 - minimum: 0 - maximum: 2000000)
평판 경고 점수(0~2,000,000)

repute_blocking_score
repute_blocking_score: required (integer - default: 10000 - minimum: 0 - maximum: 2000000)
평판 차단 점수(0~2,000,000)

repute_domain_del_cycle
repute_domain_del_cycle: required (integer - default: 86400 - minimum: 0 - maximum: 31536000)
평판 도메인 삭제 주기(초)
(0~31,536,000)

repute_sub_domain_del_cycle
repute_sub_domain_del_cycle: required (integer - default: 3600 - minimum: 0 - maximum: 31536000)
평판 서브 도메인 삭제 추기(초)
(0~31,536,000)

repute_tunnel_domain_del_cycle
repute_tunnel_domain_del_cycle: required (integer - default: 2592000 - minimum: 0 - maximum: 31536000)
평판 터널링 도메인 삭제 주기(초 단위, 0 ~ 31,536,000)

ml_use
ml_use: required (one of 1, 2 - default: 2)
ML 엔진 사용 여부
1:	사용,	2:	사용안함(기본값)

Example:
Example

{
		"use":	1,
		"repute_warning_score":	10000,
		"repute_blocking_score":	10000,
		"repute_domain_del_cycle":	86400,
		"repute_sub_domain_del_cycle":	3600,
		"repute_tunnel_domain_del_cycle":	2592000
}

Response

HTTP status code 200

DNS 보안 공통 설정 수정 성공

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

useuse: required (one of 1, 2 - default: 2)
사용 여부
1:	사용,	2:	사용	안함

repute_warning_score
repute_warning_score: required (integer - default: 10000 - minimum: 0 - maximum: 2000000)
평판 경고 점수(0~2,000,000)

repute_blocking_score
repute_blocking_score: required (integer - default: 10000 - minimum: 0 - maximum: 2000000)
평판 차단 점수(0~2,000,000)

repute_domain_del_cycle
repute_domain_del_cycle: required (integer - default: 86400 - minimum: 0 - maximum: 31536000)
평판 도메인 삭제 주기(초)
(0~31,536,000)

repute_sub_domain_del_cycle
repute_sub_domain_del_cycle: required (integer - default: 3600 - minimum: 0 - maximum: 31536000)
평판 서브 도메인 삭제 추기(초)
(0~31,536,000)

repute_tunnel_domain_del_cycle
repute_tunnel_domain_del_cycle: required (integer - default: 2592000 - minimum: 0 - maximum: 31536000)
평판 터널링 도메인 삭제 주기(초 단위, 0 ~ 31,536,000)

ml_use: required (one of 1, 2 - default: 2)
ml_use
ML 엔진 사용 여부
1:	사용,	2:	사용안함(기본값)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"use":	1,
				"repute_warning_score":	10000,
				"repute_blocking_score":	10000,
				"repute_domain_del_cycle":	86400,
				"repute_sub_domain_del_cycle":	3600,
				"repute_tunnel_domain_del_cycle":	2592000
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

DNS 보안 공통 설정 적용/취소

PUT

/command/dnssec-setting/apply

DNS 보안 공통 설정을 적용합니다.

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

DNS 보안 공통 설정 적용 성공

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

/command/dnssec-setting/cancel

DNS 보안 공통 설정을 취소합니다.

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

DNS 보안 공통 설정 취소 성공

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

