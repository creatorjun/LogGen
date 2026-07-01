DNS 설정 REST API 문서

https://{url}/api/sm

urlurl: required (string)
장비 IP

DNS 서버 설정

/dns/config

/dns/config/servers

/dns/config/servers/{server_id}

/dns/config/apply

/dns/config/cancel

DDNS 설정

/ddns/status

/ddns/config

/ddns/config/hosts

/ddns/config/hosts/{host_index}

/ddns/config/apply

/ddns/config/cancel

Split DNS 설정 > 기본 설정

/splitdns/config

Split DNS 설정 > 고급 설정

/splitdns/{dns_type}

Split DNS 설정 > Zone 설정

/splitdns/{dns_type}/{zone_type}

/splitdns/{dns_type}/{zone_type}/{zone_index}

/splitdns/{dns_type}/{zone_type}/{zone_index}/hosts

/splitdns/{dns_type}/{zone_type}/{zone_index}/hosts/{host_index}

Split DNS 설정 적용/취소

/splitdns/apply

/splitdns/cancel

DNS 서버 설정

GET

/dns/config

DNS 서버 설정을(를) 조회한다.

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

GET

PUT

GET

POST

  DELETE

GET

  DELETE

PUT

PUT

GET

GET

PUT

GET

GET

POST

  DELETE

PUT

  DELETE

PUT

PUT

GET

PUT

GET

PUT

GET

GET

GET

POST

PUT

  DELETE

POST

  DELETE

GET

  DELETE

PUT

PUT

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

DNS 서버 설정 조회 성공

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
domain_name: required (string - maxLength: 255)
domain_name
도메인 이름

Example:
Example

{
		"code":	"ok",
		"result":	{
				"domain_name":	"secui.com"
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

/dns/config

DNS 서버 설정을(를) 수정한다.

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

domain_name
domain_name: required (string - maxLength: 255)
도메인 이름

Example:
Example

{
		"domain":	"secui.com"
}

Response

HTTP status code 200

DNS 서버 설정 수정 성공

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
domain_name
domain_name: required (string - maxLength: 255)
도메인 이름

Example:
Example

{
		"code":	"ok",
		"result":	{
				"domain_name":	"secui.com"
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

GET

/dns/config/servers

DNS 서버 목록을 조회한다.

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

DNS 서버 목록 조회 성공

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
result: required (array of server_ip)
Items: server_ip
Items

index
index: (integer)
서버 ID

ipip: required (string)
IP 주소(IPv4 Address or IPv6 Address)

version
version: required (one of 4, 6)
IP 버전 (IPv4:	4,	IPv6:	6)

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"index":	1,
						"ip":	"8.8.8.8",
						"version":	4
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

/dns/config/servers

DNS 서버를 추가한다.

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
index
index: (integer)
서버 ID

ipip: required (string)
IP 주소(IPv4 Address or IPv6 Address)

version
version: required (one of 4, 6)
IP 버전 (IPv4:	4,	IPv6:	6)

Example:
Example

{
		"ip":	"8.8.8.8",
		"version":	4
}

Response

HTTP status code 200

DNS 서버 추가 성공

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
index
index: (integer)
서버 ID

ipip: required (string)
IP 주소(IPv4 Address or IPv6 Address)

version
version: required (one of 4, 6)
IP 버전 (IPv4:	4,	IPv6:	6)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"index":	1,
				"ip":	"8.8.8.8",
				"version":	4
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

/dns/config/servers

DNS 서버 목록을 (일괄)삭제한다.

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
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"index":	1},
				{"index":	2}
		]
}

Response

HTTP status code 200

DNS 서버 목록 삭제 성공

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

/dns/config/servers/{server_id}

DNS 서버을(를) 조회한다.

Request

URI Parameters

server_id
server_id: required (string)
DNS 서버 ID

Example:
Example

10

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

DNS 서버 조회 성공

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
index
index: (integer)
서버 ID

ipip: required (string)
IP 주소(IPv4 Address or IPv6 Address)

version: required (one of 4, 6)
version
IP 버전 (IPv4:	4,	IPv6:	6)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"index":	1,
				"ip":	"8.8.8.8",
				"version":	4
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

/dns/config/servers/{server_id}

DNS 서버을(를) 삭제한다.

Request

URI Parameters

server_id: required (string)
server_id
DNS 서버 ID

Example:
Example

10

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

DNS 서버 삭제 성공

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

/dns/config/apply

DNS 서버 설정을 적용합니다.

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

Body

Media type: application/json
Media type

TypeType: object

Example:
Example

{}

Response

HTTP status code 200

DNS 서버 설정 적용 성공

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

/dns/config/cancel

DNS 서버 설정을 취소합니다.

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

DNS 서버 설정 취소 성공

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

DDNS 설정

GET

/ddns/status

DDNS 상태 보기을(를) 조회한다.

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

DDNS 상태 보기 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (string)
code
결과 코드

result: required (object)
result

status
status: required (string)
상태 보기 결과

Example:
Example

{
		"code":	"ok",
		"result":	{
				"status":"......................."
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

GET

/ddns/config

DDNS 설정을(를) 조회한다.

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

DDNS 설정 조회 성공

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

enable
enable: required (one of 0, 1)
사용 (OFF:	0,	ON:	1)

period
period: required (integer - default: 60 - minimum: 60 - maximum: 600)
IP 검사 주기

Example:
Example

{
		"code":	"ok",
		"result":	{
				"enable":	1,
				"period":	60
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

PUT

/ddns/config

DDNS 설정을(를) 수정한다.

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
enable
enable: required (one of 0, 1)
사용 (OFF:	0,	ON:	1)

period: required (integer - default: 60 - minimum: 60 - maximum: 600)
period
IP 검사 주기

Example:
Example

{
		"enable":	1,
		"period":	60
}

Response

HTTP status code 200

DDNS 설정 수정 성공

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

enable: required (one of 0, 1)
enable
사용 (OFF:	0,	ON:	1)

period
period: required (integer - default: 60 - minimum: 60 - maximum: 600)
IP 검사 주기

Example:
Example

{
		"code":	"ok",
		"result":	{
				"enable":	1,
				"period":	60
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

/ddns/config/hosts

호스트 목록을 조회한다.

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

호스트 목록 조회 성공

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
result: required (array of ddns_host)
Items: ddns_host
Items

host_index
host_index: required (integer)
ID

host_name
host_name: required (string - maxLength: 255)
호스트 이름

service_supplier: required (one of 0, 1, 2, 3, 4)
service_supplier
서비스 공급자 (Dyndns:	0,	ZoneEdit:	1,	EasyDNS:	2,	DtDNS:	3,	Namecheap:	4)

idid: required (string - maxLength: 32)
사용자 아이디

ssl_enable
ssl_enable: required (one of 0, 1)
SSL 사용 (OFF:	0,	ON:	1)

descdesc: required (string - maxLength: 255)
설명

passwd
passwd: (string - maxLength: 32)
사용자 비밀번호(Base64 인코딩)

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"host_name":	"host1",
						"service_supplier":	"0",
						"id":	"admin",
						"ssl_enable":	1,
						"desc":	"test"
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

/ddns/config/hosts

호스트를 추가한다.

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

host_index
host_index: required (integer)
ID

host_name
host_name: required (string - maxLength: 255)
호스트 이름

service_supplier: required (one of 0, 1, 2, 3, 4)
service_supplier
서비스 공급자 (Dyndns:	0,	ZoneEdit:	1,	EasyDNS:	2,	DtDNS:	3,	Namecheap:	4)

idid: required (string - maxLength: 32)
사용자 아이디

ssl_enable
ssl_enable: required (one of 0, 1)
SSL 사용 (OFF:	0,	ON:	1)

descdesc: required (string - maxLength: 255)
설명

passwd
passwd: (string - maxLength: 32)
사용자 비밀번호(Base64 인코딩)

Example:
Example

{
		"host_name":	"host1",
		"service_supplier":	"0",
		"id":	"admin",
		"passwd":	"c2VjdWkwMA==",
		"ssl_enable":	1,
		"desc":	"test"
}

Response

HTTP status code 200

호스트 추가 성공

Headers

Location: required (string)
Location
Example:
Example

/ddns/hosts/123

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (string)
code
결과 코드

result: required (object)
result

host_index
host_index: required (integer)
ID

host_name: required (string - maxLength: 255)
host_name
호스트 이름

service_supplier
service_supplier: required (one of 0, 1, 2, 3, 4)
서비스 공급자 (Dyndns:	0,	ZoneEdit:	1,	EasyDNS:	2,	DtDNS:	3,	Namecheap:	4)

idid: required (string - maxLength: 32)
사용자 아이디

ssl_enable
ssl_enable: required (one of 0, 1)
SSL 사용 (OFF:	0,	ON:	1)

descdesc: required (string - maxLength: 255)
설명

passwd
passwd: (string - maxLength: 32)
사용자 비밀번호(Base64 인코딩)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"host_index":	"10",
				"host_name":	"host1",
				"service_supplier":	"0",
				"id":	"admin",
				"ssl_enable":	1,
				"desc":	"test"
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

DELETE

/ddns/config/hosts

호스트 목록을 (일괄)삭제한다.

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
items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"host_index":	1},
				{"host_index":	2}
		]
}

Response

HTTP status code 200

호스트 목록 삭제 성공

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

/ddns/config/hosts/{host_index}

호스트을(를) 조회한다.

Request

URI Parameters

host_index
host_index: required (string)
호스트 ID

Example:
Example

10

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

Response

HTTP status code 200

호스트 조회 성공

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

host_index
host_index: required (integer)
ID

host_name
host_name: required (string - maxLength: 255)
호스트 이름

service_supplier
service_supplier: required (one of 0, 1, 2, 3, 4)
서비스 공급자 (Dyndns:	0,	ZoneEdit:	1,	EasyDNS:	2,	DtDNS:	3,	Namecheap:	4)

idid: required (string - maxLength: 32)
사용자 아이디

ssl_enable
ssl_enable: required (one of 0, 1)
SSL 사용 (OFF:	0,	ON:	1)

descdesc: required (string - maxLength: 255)
설명

passwd
passwd: (string - maxLength: 32)
사용자 비밀번호(Base64 인코딩)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"host_index":	"10",
				"host_name":	"host1",
				"service_supplier":	"0",
				"id":	"admin",
				"ssl_enable":	1,
				"desc":	"test"
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

/ddns/config/hosts/{host_index}

호스트을(를) 수정한다.

Request

URI Parameters

host_index
host_index: required (string)
호스트 ID

Example:
Example

10

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

host_index
host_index: required (integer)
ID

host_name
host_name: required (string - maxLength: 255)
호스트 이름

service_supplier: required (one of 0, 1, 2, 3, 4)
service_supplier
서비스 공급자 (Dyndns:	0,	ZoneEdit:	1,	EasyDNS:	2,	DtDNS:	3,	Namecheap:	4)

idid: required (string - maxLength: 32)
사용자 아이디

ssl_enable: required (one of 0, 1)
ssl_enable
SSL 사용 (OFF:	0,	ON:	1)

descdesc: required (string - maxLength: 255)
설명

passwd
passwd: (string - maxLength: 32)
사용자 비밀번호(Base64 인코딩)

Example:
Example

{
		"host_name":	"host1",
		"service_supplier":	"0",
		"id":	"admin",
		"passwd":	"c2VjdWkwMA==",
		"ssl_enable":	1,
		"desc":	"test"
}

Response

HTTP status code 200

호스트 수정 성공

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

host_index
host_index: required (integer)
ID

host_name: required (string - maxLength: 255)
host_name
호스트 이름

service_supplier
service_supplier: required (one of 0, 1, 2, 3, 4)
서비스 공급자 (Dyndns:	0,	ZoneEdit:	1,	EasyDNS:	2,	DtDNS:	3,	Namecheap:	4)

idid: required (string - maxLength: 32)
사용자 아이디

ssl_enable
ssl_enable: required (one of 0, 1)
SSL 사용 (OFF:	0,	ON:	1)

descdesc: required (string - maxLength: 255)
설명

passwd
passwd: (string - maxLength: 32)
사용자 비밀번호(Base64 인코딩)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"host_index":	"10",
				"host_name":	"host1",
				"service_supplier":	"0",
				"id":	"admin",
				"ssl_enable":	1,
				"desc":	"test"
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

/ddns/config/hosts/{host_index}

호스트을(를) 삭제한다.

Request

URI Parameters

host_index
host_index: required (string)
호스트 ID

Example:
Example

10

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

호스트 삭제 성공

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

/ddns/config/apply

DDNS 설정을 적용합니다.

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

DDNS 설정 적용 성공

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

/ddns/config/cancel

DDNS 설정을 취소합니다.

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

DDNS 설정 취소 성공

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

Split DNS 설정 > 기본 설정

GET

/splitdns/config

기본 설정을(를) 조회한다.

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

기본 설정 조회 성공

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

enable
enable: required (one of 0, 1)
사용 (OFF:	0,	ON:	1)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"enable":	1
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

/splitdns/config

기본 설정을(를) 수정한다.

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
enable
enable: required (one of 0, 1)
사용 (OFF:	0,	ON:	1)

Example:
Example

{
		"enable":	1
}

Response

HTTP status code 200

기본 설정 수정 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (string)
code

결과 코드

result: required (object)
result
enumenum: required (0)
description: required (사용```(OFF: 0, ON: 1)```)
description

Example:
Example

{
		"code":	"ok",
		"result":	{
				"enable":	1
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

Split DNS 설정 > 고급 설정

GET

/splitdns/{dns_type}

고급 설정을(를) 조회한다.

Request

URI Parameters

dns_type
dns_type: required (one of 0, 1)
구분
(내부	DNS:	0,	외부	DNS:	1)

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

고급 설정 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (string)
code
결과 코드

result: required (object)
result

forward
forward: required (one of 0, 1)
forward (only:	0,	first:	1)

notify: required (one of 0, 1)
notify
notify (no:	0,	yes:	1)

recursion
recursion: required (one of 0, 1)
recursion (no:	0,	yes:	1)

transfers_format
transfers_format: required (one of 0, 1)
transfers-format (one-answer:	0,	many-answers:	1)

max_transfer_time_in
max_transfer_time_in: required (integer - minimum: 0 - maximum: 525600)
max-transfer-time-in

transfer_in
transfer_in: required (integer - minimum: 0 - maximum: 10000)
transfer-in

interface_interval: required (integer - minimum: 0 - maximum: 525600)
interface_interval
interface-interval

lame_ttl
lame_ttl: required (integer - minimum: 0 - maximum: 604800)
lame-ttl

max_ncache_ttl: required (integer - minimum: 0 - maximum: 604800)
max_ncache_ttl

max-ncache-ttl

listenon_list
listenon_list: required (array of string)
Listen-on IPv4 주속 목록

Example:
Example

[
		"1.1.1.1",
		"1.1.1.2"
]

forwarders_list
forwarders_list: required (array of string)
Forwarders IPv4 주속 목록(내부 DNS 속성)

Example:
Example

[
		"1.1.1.1",
		"1.1.1.2"
]

allow_query
allow_query: required (object)
allow-query

allow_all
allow_all: required (one of 0, 1)
Allow Query (allow-list:	0,	allow-all:	1)

allow_list
allow_list: required (array of string)
IP 목록(IPv4 Address/Mask[8-32])

Example:
Example

[
		"1.1.1.1/24",
		"1.1.1.2/8"
]

allow_recursion
allow_recursion: required (object)
allow-recursion

allow_all
allow_all: required (one of 0, 1)
Allow Query (allow-list:	0,	allow-all:	1)

allow_list
allow_list: required (array of string)
IP 목록(IPv4 Address/Mask[8-32])

Example:
Example

[
		"1.1.1.1/24",
		"1.1.1.2/8"
]

allow_transfer
allow_transfer: required (object)
allow-recursion

allow_all
allow_all: required (one of 0, 1)
Allow Query (allow-list:	0,	allow-all:	1)

allow_list
allow_list: required (array of string)
IP 목록(IPv4 Address/Mask[8-32])

Example:
Example

[
		"1.1.1.1/24",
		"1.1.1.2/8"
]

Example:
Example

{
		"code":	"ok",
		"result":	{
				"forward":	1,
				"notify":	1,
				"recursion":	1,
				"transfers_format":	1,
				"max_transfer_time_in":	525600,
				"transfer_in":	10000,
				"interface_interval":	525600,
				"lame_ttl":	604800,
				"max_ncache_ttl":	604800,
				"listenon_list":	["1.1.1.1","1.1.1.2"],
				"forwarders_list":	["1.1.1.1","1.1.1.2"],
				"allow_query":	{
						"allow_all":	1,
						"allow_list":	["1.1.1.1","1.1.1.2"]
				},
				"allow_recursion":	{
						"allow_all":	1,
						"allow_list":	["1.1.1.1","1.1.1.2"]
				},
				"allow_transfer":	{
						"allow_all":	1,
						"allow_list":	["1.1.1.1","1.1.1.2"]
				}
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

/splitdns/{dns_type}

고급 설정을(를) 수정한다.

Request

URI Parameters

dns_type: required (one of 0, 1)
dns_type
구분
(내부	DNS:	0,	외부	DNS:	1)

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

forward: required (one of 0, 1)
forward
forward (only:	0,	first:	1)

notify
notify: required (one of 0, 1)
notify (no:	0,	yes:	1)

recursion
recursion: required (one of 0, 1)
recursion (no:	0,	yes:	1)

transfers_format
transfers_format: required (one of 0, 1)
transfers-format (one-answer:	0,	many-answers:	1)

max_transfer_time_in
max_transfer_time_in: required (integer - minimum: 0 - maximum: 525600)
max-transfer-time-in

transfer_in: required (integer - minimum: 0 - maximum: 10000)
transfer_in
transfer-in

interface_interval
interface_interval: required (integer - minimum: 0 - maximum: 525600)
interface-interval

lame_ttl
lame_ttl: required (integer - minimum: 0 - maximum: 604800)
lame-ttl

max_ncache_ttl
max_ncache_ttl: required (integer - minimum: 0 - maximum: 604800)
max-ncache-ttl

listenon_list
listenon_list: required (array of string)
Listen-on IPv4 주속 목록

Example:
Example

[
		"1.1.1.1",
		"1.1.1.2"
]

forwarders_list
forwarders_list: required (array of string)
Forwarders IPv4 주속 목록(내부 DNS 속성)

Example:
Example

[
		"1.1.1.1",
		"1.1.1.2"
]

allow_query: required (object)
allow_query
allow-query

allow_all
allow_all: required (one of 0, 1)
Allow Query (allow-list:	0,	allow-all:	1)

allow_list
allow_list: required (array of string)
IP 목록(IPv4 Address/Mask[8-32])

Example:
Example

[
		"1.1.1.1/24",
		"1.1.1.2/8"
]

allow_recursion
allow_recursion: required (object)
allow-recursion

allow_all
allow_all: required (one of 0, 1)
Allow Query (allow-list:	0,	allow-all:	1)

allow_list
allow_list: required (array of string)
IP 목록(IPv4 Address/Mask[8-32])

Example:
Example

[
		"1.1.1.1/24",
		"1.1.1.2/8"
]

allow_transfer: required (object)
allow_transfer
allow-recursion

allow_all
allow_all: required (one of 0, 1)
Allow Query (allow-list:	0,	allow-all:	1)

allow_list
allow_list: required (array of string)
IP 목록(IPv4 Address/Mask[8-32])

Example:
Example

[
		"1.1.1.1/24",
		"1.1.1.2/8"
]

Example:
Example

{
		"forward":	1,
		"notify":	1,
		"recursion":	1,
		"transfers_format":	1,
		"max_transfer_time_in":	525600,
		"transfer_in":	10000,
		"interface_interval":	525600,
		"lame_ttl":	604800,
		"max_ncache_ttl":	604800,
		"listenon_list":	["1.1.1.1","1.1.1.2"],
		"forwarders_list":	["1.1.1.1","1.1.1.2"],
		"allow_query":	{
				"allow_all":	1,
				"allow_list":	["1.1.1.1","1.1.1.2"]
		},
		"allow_recursion":	{
				"allow_all":	1,
				"allow_list":	["1.1.1.1","1.1.1.2"]
		},
		"allow_transfer":	{
				"allow_all":	1,
				"allow_list":	["1.1.1.1","1.1.1.2"]
		}
}

Response

HTTP status code 200

고급 설정 수정 성공

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

forward
forward: required (one of 0, 1)
forward (only:	0,	first:	1)

notify
notify: required (one of 0, 1)
notify (no:	0,	yes:	1)

recursion
recursion: required (one of 0, 1)
recursion (no:	0,	yes:	1)

transfers_format
transfers_format: required (one of 0, 1)
transfers-format (one-answer:	0,	many-answers:	1)

max_transfer_time_in
max_transfer_time_in: required (integer - minimum: 0 - maximum: 525600)
max-transfer-time-in

transfer_in
transfer_in: required (integer - minimum: 0 - maximum: 10000)
transfer-in

interface_interval: required (integer - minimum: 0 - maximum: 525600)
interface_interval
interface-interval

lame_ttl
lame_ttl: required (integer - minimum: 0 - maximum: 604800)
lame-ttl

max_ncache_ttl
max_ncache_ttl: required (integer - minimum: 0 - maximum: 604800)
max-ncache-ttl

listenon_list
listenon_list: required (array of string)
Listen-on IPv4 주속 목록

Example:
Example

[
		"1.1.1.1",
		"1.1.1.2"
]

forwarders_list
forwarders_list: required (array of string)
Forwarders IPv4 주속 목록(내부 DNS 속성)

Example:
Example

[
		"1.1.1.1",
		"1.1.1.2"
]

allow_query
allow_query: required (object)
allow-query

allow_all: required (one of 0, 1)
allow_all

Allow Query (allow-list:	0,	allow-all:	1)

allow_list
allow_list: required (array of string)
IP 목록(IPv4 Address/Mask[8-32])

Example:
Example

[
		"1.1.1.1/24",
		"1.1.1.2/8"
]

allow_recursion
allow_recursion: required (object)
allow-recursion

allow_all
allow_all: required (one of 0, 1)
Allow Query (allow-list:	0,	allow-all:	1)

allow_list
allow_list: required (array of string)
IP 목록(IPv4 Address/Mask[8-32])

Example:
Example

[
		"1.1.1.1/24",
		"1.1.1.2/8"
]

allow_transfer
allow_transfer: required (object)
allow-recursion

allow_all
allow_all: required (one of 0, 1)
Allow Query (allow-list:	0,	allow-all:	1)

allow_list
allow_list: required (array of string)
IP 목록(IPv4 Address/Mask[8-32])

Example:
Example

[
		"1.1.1.1/24",
		"1.1.1.2/8"
]

Example:
Example

{
		"code":	"ok",
		"result":	{
				"forward":	1,
				"notify":	1,
				"recursion":	1,
				"transfers_format":	1,
				"max_transfer_time_in":	525600,
				"transfer_in":	10000,
				"interface_interval":	525600,
				"lame_ttl":	604800,
				"max_ncache_ttl":	604800,
				"listenon_list":	["1.1.1.1","1.1.1.2"],
				"forwarders_list":	["1.1.1.1","1.1.1.2"],
				"allow_query":	{
						"allow_all":	1,
						"allow_list":	["1.1.1.1","1.1.1.2"]
				},
				"allow_recursion":	{
						"allow_all":	1,
						"allow_list":	["1.1.1.1","1.1.1.2"]
				},
				"allow_transfer":	{
						"allow_all":	1,
						"allow_list":	["1.1.1.1","1.1.1.2"]
				}
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

Split DNS 설정 > Zone 설정

GET

/splitdns/{dns_type}/{zone_type}

Zone 설정 목록을 조회한다.

Request

URI Parameters

dns_type
dns_type: required (one of 0, 1)
구분
(내부	DNS:	0,	외부	DNS:	1)

zone_type: required (one of 0, 1)
zone_type
호스트 Zone 타입 (ZONE:	0,	REVERSE	ZONE:	1)

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

Zone 설정 목록 조회 성공

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
result: required (array of splitdns_zone)
Items: splitdns_zone
Items

zone_index
zone_index: required (integer)
ID

address
address: required (string - maxLength: 255)
주소

parent_path: (string - maxLength: 255)
parent_path
부모 주소 경로

rolerole: required (one of 0, 1)
역활 (Slave:	0,	Master:	1)

transfer
transfer: required (one of 0, 1)
Transfer 허용 (OFF:	0,	ON:	1)

master_list
master_list: (array of string)
Master의 IP 주소 목록
role'속성값이 'Slave'일 경우 설정하는 속성이다.
복수개의 IPv4 Address를 설정할 수 있다.

Example:
Example

["1.1.1.1","1.1.1.10"]

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"zone_index":	1,
						"address":	"secui.com.Root",
						"role":	"0",
						"transfer":	1,
						"master_list":	["1.1.1.1","1.1.1.10"]
				},
				{
						"zone_index":	1,
						"address":	"samsung.net.Root",
						"role":	"0",
						"transfer":	1,
						"master_list":	["1.1.1.1","1.1.1.10"]
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

/splitdns/{dns_type}/{zone_type}

Zone 설정를 추가한다.

Request

URI Parameters

dns_type
dns_type: required (one of 0, 1)
구분
(내부	DNS:	0,	외부	DNS:	1)

zone_type
zone_type: required (one of 0, 1)
호스트 Zone 타입 (ZONE:	0,	REVERSE	ZONE:	1)

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

zone_index
zone_index: required (integer)
ID

address
address: required (string - maxLength: 255)
주소

parent_path
parent_path: (string - maxLength: 255)
부모 주소 경로

rolerole: required (one of 0, 1)
역활 (Slave:	0,	Master:	1)

transfer
transfer: required (one of 0, 1)
Transfer 허용 (OFF:	0,	ON:	1)

master_list
master_list: (array of string)
Master의 IP 주소 목록
role'속성값이 'Slave'일 경우 설정하는 속성이다.
복수개의 IPv4 Address를 설정할 수 있다.

Example:
Example

["1.1.1.1","1.1.1.10"]

Example:
Example

{
		"address":	"secui",
		"parent_path":	"com.Root",
		"role":	"0",
		"transfer":	1,
		"master_list":	["1.1.1.1","1.1.1.10"]
}

Response

HTTP status code 200

Zone 설정 추가 성공

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

zone_index
zone_index: required (integer)
ID

address
address: required (string - maxLength: 255)
주소

parent_path: (string - maxLength: 255)
parent_path
부모 주소 경로

rolerole: required (one of 0, 1)
역활 (Slave:	0,	Master:	1)

transfer
transfer: required (one of 0, 1)
Transfer 허용 (OFF:	0,	ON:	1)

master_list
master_list: (array of string)
Master의 IP 주소 목록
role'속성값이 'Slave'일 경우 설정하는 속성이다.
복수개의 IPv4 Address를 설정할 수 있다.

Example:
Example

["1.1.1.1","1.1.1.10"]

Example:
Example

{
		"code":	"ok",
		"result":	{
				"zone_index":	1,
				"address":	"secui.com.Root",
				"role":	"0",
				"transfer":	1,
				"master_list":	["1.1.1.1","1.1.1.10"]
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

GET

/splitdns/{dns_type}/{zone_type}/{zone_index}

Zone 설정을(를) 조회한다.

Request

URI Parameters

dns_type
dns_type: required (one of 0, 1)
구분
(내부	DNS:	0,	외부	DNS:	1)

zone_type
zone_type: required (one of 0, 1)
호스트 Zone 타입 (ZONE:	0,	REVERSE	ZONE:	1)

zone_index
zone_index: required (string)
ID

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

Zone 설정 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (string)
code
결과 코드

result: required (object)
result

zone_index
zone_index: required (integer)
ID

address
address: required (string - maxLength: 255)
주소

parent_path
parent_path: (string - maxLength: 255)
부모 주소 경로

rolerole: required (one of 0, 1)
역활 (Slave:	0,	Master:	1)

transfer
transfer: required (one of 0, 1)
Transfer 허용 (OFF:	0,	ON:	1)

master_list
master_list: (array of string)
Master의 IP 주소 목록
role'속성값이 'Slave'일 경우 설정하는 속성이다.
복수개의 IPv4 Address를 설정할 수 있다.

Example:
Example

["1.1.1.1","1.1.1.10"]

Example:
Example

{
		"code":	"ok",
		"result":	{
				"zone_index":	1,
				"address":	"secui.com.Root",
				"role":	"0",
				"transfer":	1,
				"master_list":	["1.1.1.1","1.1.1.10"]
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

/splitdns/{dns_type}/{zone_type}/{zone_index}

Zone 설정을(를) 수정한다.

Request

URI Parameters

dns_type: required (one of 0, 1)
dns_type
구분
(내부	DNS:	0,	외부	DNS:	1)

zone_type
zone_type: required (one of 0, 1)
호스트 Zone 타입 (ZONE:	0,	REVERSE	ZONE:	1)

zone_index: required (string)
zone_index
ID

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

zone_index
zone_index: required (integer)
ID

address: required (string - maxLength: 255)
address
주소

parent_path
parent_path: (string - maxLength: 255)
부모 주소 경로

rolerole: required (one of 0, 1)
역활 (Slave:	0,	Master:	1)

transfer
transfer: required (one of 0, 1)
Transfer 허용 (OFF:	0,	ON:	1)

master_list
master_list: (array of string)
Master의 IP 주소 목록
role'속성값이 'Slave'일 경우 설정하는 속성이다.
복수개의 IPv4 Address를 설정할 수 있다.

Example:
Example

["1.1.1.1","1.1.1.10"]

Example:
Example

{
		"role":	"0",
		"transfer":	1,
		"master_list":	["1.1.1.1","1.1.1.10"]
}

Response

HTTP status code 200

Zone 설정 수정 성공

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

zone_index: required (integer)
zone_index
ID

address
address: required (string - maxLength: 255)
주소

parent_path
parent_path: (string - maxLength: 255)
부모 주소 경로

rolerole: required (one of 0, 1)
역활 (Slave:	0,	Master:	1)

transfer
transfer: required (one of 0, 1)
Transfer 허용 (OFF:	0,	ON:	1)

master_list
master_list: (array of string)
Master의 IP 주소 목록
role'속성값이 'Slave'일 경우 설정하는 속성이다.
복수개의 IPv4 Address를 설정할 수 있다.

Example:
Example

["1.1.1.1","1.1.1.10"]

Example:
Example

{
		"code":	"ok",
		"result":	{
				"zone_index":	1,
				"address":	"secui.com.Root",
				"role":	"0",
				"transfer":	1,
				"master_list":	["1.1.1.1","1.1.1.10"]
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

DELETE

/splitdns/{dns_type}/{zone_type}/{zone_index}

Zone 설정을(를) 삭제한다.

Request

URI Parameters

dns_type
dns_type: required (one of 0, 1)
구분
(내부	DNS:	0,	외부	DNS:	1)

zone_type: required (one of 0, 1)
zone_type
호스트 Zone 타입 (ZONE:	0,	REVERSE	ZONE:	1)

zone_index
zone_index: required (string)
ID

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

Zone 설정 삭제 성공

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

GET

/splitdns/{dns_type}/{zone_type}/{zone_index}/hosts

호스트 목록을 조회한다.

Request

URI Parameters

dns_type
dns_type: required (one of 0, 1)
구분
(내부	DNS:	0,	외부	DNS:	1)

zone_type: required (one of 0, 1)
zone_type
호스트 Zone 타입 (ZONE:	0,	REVERSE	ZONE:	1)

zone_index
zone_index: required (string)
ID

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

호스트 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of splitdns_zone_host)
result
Items: splitdns_zone_host
Items

host_index
host_index: required (integer)
ID

fieldfield: required (one of 0, 1, 2, 3, 4, 5, 6)

Field (SOA:	0,	MX:	1,	NS:	2,	A:	3,	PTR:	4,	CNAME:	5,	TXT:	6)
Field별 아래와 같은 설정값 필수 포함 필요.
SOA - time,ip,host,email
MX - time,mx,host,priority(ZONE)
MX - time,ip,host,priority(REVERSE ZONE)
NS - time,ip,host
A - time,ip,host(ZONE)
PTR - time,ip,host(REVERSE ZONE)
CNAME - time,host,cname
TXT - time,txt,host(ZONE)
TXT - time,ip,txt(REVERSE ZONE)

time
time: required (integer - default: 3600 - minimum: 1 - maximum: 2147483647)
Time

ipip: required (string)
IP(IPv4 Address)

mxmx: required (string - maxLength: 128)
MX

host
host: required (string - maxLength: 255)
호스트 주소

email
email: required (string - maxLength: 255)
E-mail

priority
priority: required (integer - minimum: 1 - maximum: 65535)
우선순위

cname
cname: required (string)
CName(IPv4 Address)

txttxt: required (string - maxLength: 500)
TXT

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"host_index":	1,
						"field":	"0",
						"time":	"3600",
						"ip":	"10.10.10.10",
						"host":	"secui",
						"email":	"admin@secui.com",
						"priority":	1,
						"cname":	""
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

/splitdns/{dns_type}/{zone_type}/{zone_index}/hosts

호스트를 추가한다.

Request

URI Parameters

dns_type: required (one of 0, 1)
dns_type
구분
(내부	DNS:	0,	외부	DNS:	1)

zone_type
zone_type: required (one of 0, 1)
호스트 Zone 타입 (ZONE:	0,	REVERSE	ZONE:	1)

zone_index: required (string)
zone_index

ID

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

host_index
host_index: required (integer)
ID

fieldfield: required (one of 0, 1, 2, 3, 4, 5, 6)
Field (SOA:	0,	MX:	1,	NS:	2,	A:	3,	PTR:	4,	CNAME:	5,	TXT:	6)
Field별 아래와 같은 설정값 필수 포함 필요.
SOA - time,ip,host,email
MX - time,mx,host,priority(ZONE)
MX - time,ip,host,priority(REVERSE ZONE)
NS - time,ip,host
A - time,ip,host(ZONE)
PTR - time,ip,host(REVERSE ZONE)
CNAME - time,host,cname
TXT - time,txt,host(ZONE)
TXT - time,ip,txt(REVERSE ZONE)

time
time: required (integer - default: 3600 - minimum: 1 - maximum: 2147483647)
Time

ipip: required (string)
IP(IPv4 Address)

mxmx: required (string - maxLength: 128)
MX

host
host: required (string - maxLength: 255)
호스트 주소

email: required (string - maxLength: 255)
email
E-mail

priority
priority: required (integer - minimum: 1 - maximum: 65535)
우선순위

cname
cname: required (string)
CName(IPv4 Address)

txttxt: required (string - maxLength: 500)
TXT

Example:
Example

{
		"field":	"0",
		"time":	"3600",
		"ip":	"10.10.10.10",
		"host":	"secui",
		"email":	"admin@secui.com"
}

Response

HTTP status code 200

호스트 추가 성공

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

host_index: required (integer)
host_index
ID

fieldfield: required (one of 0, 1, 2, 3, 4, 5, 6)
Field (SOA:	0,	MX:	1,	NS:	2,	A:	3,	PTR:	4,	CNAME:	5,	TXT:	6)
Field별 아래와 같은 설정값 필수 포함 필요.
SOA - time,ip,host,email
MX - time,mx,host,priority(ZONE)
MX - time,ip,host,priority(REVERSE ZONE)
NS - time,ip,host
A - time,ip,host(ZONE)
PTR - time,ip,host(REVERSE ZONE)
CNAME - time,host,cname
TXT - time,txt,host(ZONE)
TXT - time,ip,txt(REVERSE ZONE)

time
time: required (integer - default: 3600 - minimum: 1 - maximum: 2147483647)
Time

ipip: required (string)
IP(IPv4 Address)

mxmx: required (string - maxLength: 128)
MX

host
host: required (string - maxLength: 255)
호스트 주소

email
email: required (string - maxLength: 255)
E-mail

priority
priority: required (integer - minimum: 1 - maximum: 65535)
우선순위

cname
cname: required (string)
CName(IPv4 Address)

txttxt: required (string - maxLength: 500)
TXT

Example:
Example

{
		"code":	"ok",
		"result":	{
				"host_index":	1,
				"field":	"0",
				"time":	"3600",
				"ip":	"10.10.10.10",
				"host":	"secui",
				"email":	"admin@secui.com",
				"cname":	""
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

DELETE

/splitdns/{dns_type}/{zone_type}/{zone_index}/hosts

호스트 목록을 (일괄)삭제한다.

Request

URI Parameters

dns_type
dns_type: required (one of 0, 1)
구분
(내부	DNS:	0,	외부	DNS:	1)

zone_type
zone_type: required (one of 0, 1)
호스트 Zone 타입 (ZONE:	0,	REVERSE	ZONE:	1)

zone_index
zone_index: required (string)
ID

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
items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"host_index":	1},
				{"host_index":	2}
		]
}

Response

HTTP status code 200

호스트 목록 삭제 성공

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

/splitdns/{dns_type}/{zone_type}/{zone_index}/hosts/{host_index}

호스트을(를) 조회한다.

Request

URI Parameters

dns_type
dns_type: required (one of 0, 1)
구분
(내부	DNS:	0,	외부	DNS:	1)

zone_type: required (one of 0, 1)
zone_type
호스트 Zone 타입 (ZONE:	0,	REVERSE	ZONE:	1)

zone_index
zone_index: required (string)
ID

host_index
host_index: required (string)
Host ID

Example:
Example

1

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

호스트 조회 성공

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

host_index
host_index: required (integer)
ID

fieldfield: required (one of 0, 1, 2, 3, 4, 5, 6)
Field (SOA:	0,	MX:	1,	NS:	2,	A:	3,	PTR:	4,	CNAME:	5,	TXT:	6)
Field별 아래와 같은 설정값 필수 포함 필요.
SOA - time,ip,host,email
MX - time,mx,host,priority(ZONE)
MX - time,ip,host,priority(REVERSE ZONE)
NS - time,ip,host
A - time,ip,host(ZONE)
PTR - time,ip,host(REVERSE ZONE)
CNAME - time,host,cname
TXT - time,txt,host(ZONE)
TXT - time,ip,txt(REVERSE ZONE)

time: required (integer - default: 3600 - minimum: 1 - maximum: 2147483647)
time
Time

ipip: required (string)
IP(IPv4 Address)

mxmx: required (string - maxLength: 128)
MX

host
host: required (string - maxLength: 255)
호스트 주소

email
email: required (string - maxLength: 255)
E-mail

priority
priority: required (integer - minimum: 1 - maximum: 65535)
우선순위

cname
cname: required (string)
CName(IPv4 Address)

txttxt: required (string - maxLength: 500)

TXT

Example:
Example

{
		"code":	"ok",
		"result":	{
				"host_index":	"1",
				"field":	"0",
				"time":	"3600",
				"ip":	"10.10.10.10",
				"host":	"secui",
				"email":	"admin@secui.com",
				"cname":	""
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

DELETE

/splitdns/{dns_type}/{zone_type}/{zone_index}/hosts/{host_index}

호스트을(를) 삭제한다.

Request

URI Parameters

dns_type
dns_type: required (one of 0, 1)
구분
(내부	DNS:	0,	외부	DNS:	1)

zone_type
zone_type: required (one of 0, 1)
호스트 Zone 타입 (ZONE:	0,	REVERSE	ZONE:	1)

zone_index
zone_index: required (string)
ID

host_index: required (string)
host_index
Host ID

Example:
Example

1

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

호스트 삭제 성공

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

Split DNS 설정 적용/취소

PUT

/splitdns/apply

Split DNS 설정을 적용합니다.

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

Split DNS 설정 적용 성공

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

PUT

/splitdns/cancel

Split DNS 설정을 취소합니다.

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

Split DNS 설정 취소 성공

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

