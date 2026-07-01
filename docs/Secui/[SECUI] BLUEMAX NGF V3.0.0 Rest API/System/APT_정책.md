컨텐츠 업데이트 REST API 문서

https://{url}/api/sm

urlurl: required (string)
장비 IP

컨텐츠 릴리즈

/contents/releases

/contents/releases/{version}

컨텐츠 업데이트

/contents/histories

업데이트 서버 설정

/contents/server

자동 업데이트 설정

/contents/auto

현재 버전

/contents/current-version

업데이트 실행

/contents/execute/file

/contents/execute/file/{task_id}

/contents/execute/online

/contents/execute/online/{task_id}

Device 업데이트 설정

/contents/device/cus

/contents/device/portal

/contents/device/portal-data

블랙리스트 사용 설정

/contents/backlist

/contents/backlist/apply

/contents/backlist/cancel

통합 클라이언트

/contents/client/file

/contents/client/histories

/contents/client/cus

/contents/client/current-versions

/contents/client/execute

/contents/client/execute/{task_id}

/contents/client/auto

컨텐츠 릴리즈

GET

GET

GET

GET

PUT

GET

PUT

GET

POST

GET

POST

GET

GET

PUT

GET

PUT

GET

GET

PUT

PUT

PUT

POST

GET

GET

PUT

GET

POST

GET

GET

PUT

GET

/contents/releases

컨텐츠 릴리즈 목록을 조회한다.

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

Query Parameters

qq: required (object)
파라미터(string)
q=속성 %3D 값 , 속성 %3D 값```

type: required (one of 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13)
type
컨텐츠 DB 종류
1:	IPS	컨텐츠	DB
2:	애플리케이션	제어	DB
3:	웹	필터	DB
4:	안티	바이러스	DB
5:	블랙리스트	DB
6:	DLP	DB
7:	APT	정책
8:	파일	유형	제어	DB
9:	SSL	예외	목록
10:	사설인증서	DB
12:	Geo	IP	DB
13:	DNS	보안	DB(2.5부터	지원)

subtype
subtype: (one of 1, 2, 3, 4, 5, 6)
컨텐츠 DB 종류가 웹 필터 DB(3)인 경우에만 사용하는 속성이다.
컨텐츠 DB 종류가 웹 필터 DB(3)인 경우에만 사용하는 속성이다.
[웹 필터 DB 종류]
1:	Anonymizer
2:	SafeNET
3:	클라우드	악성	URL
4:	Categorized	URL
5:	SafeNet	Light(MGMT	호스트에서	유효함)
6:	외부	연동(Endpoint	피쳐가	있을	경우)

MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
IPS DB 종류 (IPS	Light	DB:	1,	IPS	DB:	2)
안티 바이러스 DB 종류 (Stream	Based	DB:	1,	File	Based	DB:	2,	File	Based	DB(Light):	3)

Example:
Example

?q=type%3D1

Response

HTTP status code 200

컨텐츠 릴리즈 목록 조회 성공

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
result: required (array of items)
Items: items
Items

version
version: required (string)
릴리즈 버전

releasenote
releasenote: required (one of 0, 1)
릴리즈 노트 (릴리즈	노트	없음:	0,	릴리즈	노트	제공:	1)

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"version":	"1.1",
						"releasenote":	0
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

GET

/contents/releases/{version}

릴리즈 노트를 다운로드 한다.

Request

URI Parameters

version: required (string)
version
버전

Example:
Example

1.0.1

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

Query Parameters

qq: required (object)
파라미터(string)
q=속성 %3D 값 , 속성 %3D 값```

type
type: required (one of 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13)
컨텐츠 DB 종류
1:	IPS	컨텐츠	DB
2:	애플리케이션	제어	DB
3:	웹	필터	DB
4:	안티	바이러스	DB
5:	블랙리스트	DB
6:	DLP	DB
7:	APT	정책
8:	파일	유형	제어	DB
9:	SSL	예외	목록
10:	사설인증서	DB
12:	Geo	IP	DB
13:	DNS	보안	DB(2.5부터	지원)

subtype: (one of 1, 2, 3, 4, 5, 6)
subtype
컨텐츠 DB 종류가 웹 필터 DB(3)인 경우에만 사용하는 속성이다.
컨텐츠 DB 종류가 웹 필터 DB(3)인 경우에만 사용하는 속성이다.
[웹 필터 DB 종류]
1:	Anonymizer
2:	SafeNET
3:	클라우드	악성	URL
4:	Categorized	URL
5:	SafeNet	Light(MGMT	호스트에서	유효함)
6:	외부	연동(Endpoint	피쳐가	있을	경우)

MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
IPS DB 종류 (IPS	Light	DB:	1,	IPS	DB:	2)
안티 바이러스 DB 종류 (Stream	Based	DB:	1,	File	Based	DB:	2,	File	Based	DB(Light):	3)

Example:
Example

?q=type%3D1

Response

HTTP status code 200

릴리즈 노트 URI 조회 성공

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

pathpath: required (string)
릴리즈 노트 URI
URI를 사용하여 릴리즈 노트를 조회한다.(/release/ips_signature5/201808241700/RELEASENOTE.html)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"path":"ips_signature5/201808241700/RELEASENOTE.html"
		}
}

컨텐츠 업데이트

GET

/contents/histories

컨텐츠 업데이트 목록을 조회한다.

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

qq: required (object)
파라미터(string)
q=속성 %3D 값 , 속성 %3D 값```

type
type: required (one of 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13)
컨텐츠 DB 종류
1:	IPS	컨텐츠	DB
2:	애플리케이션	제어	DB
3:	웹	필터	DB
4:	안티	바이러스	DB
5:	블랙리스트	DB
6:	DLP	DB
7:	APT	정책
8:	파일	유형	제어	DB
9:	SSL	예외	목록
10:	사설인증서	DB
11:	디바이스	정책	DB
12:	Geo	IP	DB(2.0부터	지원)
13:	DNS	보안	DB(2.5부터	지원)

subtype
subtype: (one of 1, 2, 3, 4, 5, 6)
컨텐츠 DB 종류가 웹 필터 DB(3) 또는 디바이스 정책 DB(11)인 경우에만 사용하는 속성이다.
컨텐츠 DB 종류가 웹 필터 DB(3) 또는 디바이스 정책 DB(11)인 경우에만 사용하는 속성이다.
[웹 필터 DB 종류]
1:	Anonymizer
2:	SafeNET
3:	클라우드	악성	URL
4:	Categorized	URL
5:	SafeNet	Light(MGMT	호스트에서	유효함)
6:	외부	연동(Endpoint	피쳐가	있을	경우)

디바이스 DB 종류 (CUS:	1,	단말포탈:	2)
MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
IPS DB 종류 (IPS	Light	DB:	1,	IPS	DB:	2)
안티 바이러스 DB 종류 (Stream	Based	DB:	1,	File	Based	DB:	2,	File	Based	DB(Light):	3)

Example:
Example

?q=type%3D1

Response

HTTP status code 200

컨텐츠 업데이트 목록 조회 성공

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
result: required (array of contents_history)
Items: contents_history
Items

version
version: required (string)
버전 정보

datedate: required (string)
업데이트 날짜

result
result: required (one of succ, fail)
업데이트 결과
(성공:	'succ',	실패:	'fail')

reason
reason: required (string)
업데이트 상세 결과

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"version":	"버전	정보",
						"date":	"YYYY-MM-DD	hh:mm:ss",
						"result":	"succ",
						"reason":	"상세	결과"
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

업데이트 서버 설정

GET

/contents/server

업데이트 서버 설정을(를) 조회한다.

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

업데이트 서버 설정 조회 성공

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
urlurl: required (string)
업데이트 서버 주소

Example:
Example

{
		"code":	"ok",
		"result":	{
				"url":	"https://yyyyyy"
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

/contents/server

업데이트 서버 설정을(를) 수정한다.

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

urlurl: required (string)
업데이트 서버 주소

Example:
Example

{
		"url":	"https://yyyyyy"
}

Response

HTTP status code 200

업데이트 서버 설정 수정 성공

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
urlurl: required (string)
업데이트 서버 주소

Example:
Example

{
		"code":	"ok",
		"result":	{
				"url":	"https://yyyyyy"
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

자동 업데이트 설정

GET

/contents/auto

자동 업데이트 설정을(를) 조회한다.

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

Query Parameters

qq: required (object)
파라미터(string)
q=속성 %3D 값 , 속성 %3D 값```

type: required (one of 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13)
type
컨텐츠 DB 종류
1:	IPS	컨텐츠	DB
2:	애플리케이션	제어	DB
3:	웹	필터	DB
4:	안티	바이러스	DB
5:	블랙리스트	DB
6:	DLP	DB
7:	APT	정책
8:	파일	유형	제어	DB
9:	SSL	예외	목록
10:	사설인증서	DB
11:	디바이스	정책	DB
12:	Geo	IP	DB(2.0부터	지원)
13:	DNS	보안	DB(2.5부터	지원)

subtype
subtype: (one of 1, 2, 3, 4, 5, 6)
컨텐츠 DB 종류가 웹 필터 DB(3) 또는 디바이스 정책 DB(11)인 경우에만 사용하는 속성이다.
컨텐츠 DB 종류가 웹 필터 DB(3) 또는 디바이스 정책 DB(11)인 경우에만 사용하는 속성이다.
[웹 필터 DB 종류]
1:	Anonymizer
2:	SafeNET
3:	클라우드	악성	URL
4:	Categorized	URL
5:	SafeNet	Light(MGMT	호스트에서	유효함)
6:	외부	연동(Endpoint	피쳐가	있을	경우)

디바이스 DB 종류 (CUS:	1,	단말포탈:	2)
MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
IPS DB 종류 (IPS	Light	DB:	1,	IPS	DB:	2)
안티 바이러스 DB 종류 (Stream	Based	DB:	1,	File	Based	DB:	2,	File	Based	DB(Light):	3)

Example:
Example

?q=type%3D1

Response

HTTP status code 200

자동 업데이트 설정 조회 성공

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
업데이트 설정

action
action: required (one of 0, 1, 2)
자동 업데이트 (없음:	0,	일별:	1,	매일:	2)

day_of_week
day_of_week: (object)
업데이트 설정(일별)

daysdays: required (array of any)
요일별 배열 순번 (일:	0,	월:	1,	화:	2,	수:	3,	목:	4,	금:	5,	토:	6)
요일 ON/OFF (OFF:	0,	ON:	1)

hour
hour: required (integer - minimum: 0 - maximum: 23)
시간

minmin: required (integer - minimum: 0 - maximum: 59)
분

every_day: (one of 0, 1)
every_day
업데이트 설정(매일) (60분	간격:	0,	360분	간격:	1)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"action":	1,
				"day_of_week":	{
						"days":	[
								0,1,1,1,0,1,1
						],
						"hour":	10,
						"min":	10
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

/contents/auto

자동 업데이트 설정을(를) 수정한다.

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

Query Parameters

qq: required (object)
파라미터(string)
q=속성 %3D 값 , 속성 %3D 값```

type
type: required (one of 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13)
컨텐츠 DB 종류
1:	IPS	컨텐츠	DB
2:	애플리케이션	제어	DB
3:	웹	필터	DB
4:	안티	바이러스	DB
5:	블랙리스트	DB
6:	DLP	DB
7:	APT	정책
8:	파일	유형	제어	DB
9:	SSL	예외	목록
10:	사설인증서	DB
11:	디바이스	정책	DB
12:	Geo	IP	DB(2.0부터	지원)
13:	DNS	보안	DB(2.5부터	지원)

subtype: (one of 1, 2, 3, 4, 5, 6)
subtype
컨텐츠 DB 종류가 웹 필터 DB(3) 또는 디바이스 정책 DB(11)인 경우에만 사용하는 속성이다.
컨텐츠 DB 종류가 웹 필터 DB(3) 또는 디바이스 정책 DB(11)인 경우에만 사용하는 속성이다.
[웹 필터 DB 종류]
1:	Anonymizer
2:	SafeNET
3:	클라우드	악성	URL
4:	Categorized	URL
5:	SafeNet	Light(MGMT	호스트에서	유효함)
6:	외부	연동(Endpoint	피쳐가	있을	경우)

디바이스 DB 종류 (CUS:	1,	단말포탈:	2)
MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
IPS DB 종류 (IPS	Light	DB:	1,	IPS	DB:	2)
안티 바이러스 DB 종류 (Stream	Based	DB:	1,	File	Based	DB:	2,	File	Based	DB(Light):	3)

Example:
Example

?q=type%3D1

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
action: required (one of 0, 1, 2)
action
자동 업데이트 (없음:	0,	일별:	1,	매일:	2)

day_of_week
day_of_week: (object)
업데이트 설정(일별)

daysdays: required (array of any)
요일별 배열 순번 (일:	0,	월:	1,	화:	2,	수:	3,	목:	4,	금:	5,	토:	6)
요일 ON/OFF (OFF:	0,	ON:	1)

hour
hour: required (integer - minimum: 0 - maximum: 23)
시간

minmin: required (integer - minimum: 0 - maximum: 59)
분

every_day
every_day: (one of 0, 1)
업데이트 설정(매일) (60분	간격:	0,	360분	간격:	1)

Example:
Example

{
		"action":	1,
		"day_of_week":	{
				"days":	[
						0,1,1,1,0,1,1
				],
				"hour":	10,
				"min":	10
		}
}

Response

HTTP status code 200

자동 업데이트 설정 수정 성공

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
업데이트 설정

action
action: required (one of 0, 1, 2)
자동 업데이트 (없음:	0,	일별:	1,	매일:	2)

day_of_week
day_of_week: (object)
업데이트 설정(일별)

daysdays: required (array of any)
요일별 배열 순번 (일:	0,	월:	1,	화:	2,	수:	3,	목:	4,	금:	5,	토:	6)
요일 ON/OFF (OFF:	0,	ON:	1)

hour
hour: required (integer - minimum: 0 - maximum: 23)
시간

minmin: required (integer - minimum: 0 - maximum: 59)
분

every_day
every_day: (one of 0, 1)
업데이트 설정(매일) (60분	간격:	0,	360분	간격:	1)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"action":	1,
				"day_of_week":	{
						"days":	[
								0,1,1,1,0,1,1
						],
						"hour":	10,
						"min":	10
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

현재 버전

GET

/contents/current-version

현재 버전을(를) 조회한다.

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

qq: required (object)
파라미터(string)
q=속성 %3D 값 , 속성 %3D 값```

type
type: required (one of 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13)
컨텐츠 DB 종류
1:	IPS	컨텐츠	DB
2:	애플리케이션	제어	DB
3:	웹	필터	DB
4:	안티	바이러스	DB
5:	블랙리스트	DB
6:	DLP	DB
7:	APT	정책
8:	파일	유형	제어	DB
9:	SSL	예외	목록
10:	사설인증서	DB
11:	디바이스	정책	DB
12:	Geo	IP	DB(2.0부터	지원)
13:	DNS	보안	DB(2.5부터	지원)

subtype
subtype: (one of 1, 2, 3, 4, 5, 6)
컨텐츠 DB 종류가 웹 필터 DB(3) 또는 디바이스 정책 DB(11)인 경우에만 사용하는 속성이다.
컨텐츠 DB 종류가 웹 필터 DB(3) 또는 디바이스 정책 DB(11)인 경우에만 사용하는 속성이다.
[웹 필터 DB 종류]
1:	Anonymizer
2:	SafeNET
3:	클라우드	악성	URL
4:	Categorized	URL
5:	SafeNet	Light(MGMT	호스트에서	유효함)
6:	외부	연동(Endpoint	피쳐가	있을	경우)

디바이스 DB 종류 (CUS:	1,	단말포탈:	2)
MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
IPS DB 종류 (IPS	Light	DB:	1,	IPS	DB:	2)
안티 바이러스 DB 종류 (Stream	Based	DB:	1,	File	Based	DB:	2,	File	Based	DB(Light):	3)

Example:
Example

?q=type%3D1

Response

HTTP status code 200

현재 버전 조회 성공

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

version
version: required (string)
현재 버전

Example:
Example

{
		"code":	"ok",
		"result":	{
				"version":	"1.1"
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

업데이트 실행

POST

/contents/execute/file

파일 업데이트를 실행한다.

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

Query Parameters

qq: required (object)
파라미터(string)
q=속성 %3D 값 , 속성 %3D 값```

type: required (one of 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13)
type
컨텐츠 DB 종류
1:	IPS	컨텐츠	DB
2:	애플리케이션	제어	DB
3:	웹	필터	DB
4:	안티	바이러스	DB
5:	블랙리스트	DB
6:	DLP	DB
7:	APT	정책
8:	파일	유형	제어	DB
9:	SSL	예외	목록
10:	사설인증서	DB
11:	디바이스	정책	DB
12:	Geo	IP	DB(2.0부터	지원)
13:	DNS	보안	DB(2.5부터	지원)

subtype
subtype: (one of 1, 2, 3, 4, 5, 6)
컨텐츠 DB 종류가 웹 필터 DB(3) 또는 디바이스 정책 DB(11)인 경우에만 사용하는 속성이다.
컨텐츠 DB 종류가 웹 필터 DB(3) 또는 디바이스 정책 DB(11)인 경우에만 사용하는 속성이다.
[웹 필터 DB 종류]
1:	Anonymizer
2:	SafeNET
3:	클라우드	악성	URL
4:	Categorized	URL
5:	SafeNet	Light(MGMT	호스트에서	유효함)
6:	외부	연동(Endpoint	피쳐가	있을	경우)

디바이스 DB 종류 (CUS:	1,	단말포탈:	2)
MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
IPS DB 종류 (IPS	Light	DB:	1,	IPS	DB:	2)
안티 바이러스 DB 종류 (Stream	Based	DB:	1,	File	Based	DB:	2,	File	Based	DB(Light):	3)

Example:
Example

?q=type%3D1

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties

pathpath: required (string)
파일 이름
파일 업로드 후 반환된 파일명을 인자로 전달
파일 업로드 API로 파일 업로드 후 호출
https://{url}/api/co/file/import

Example:
Example

{
		"path":	"550e8400-e29b-41d4-a716-446655440000.tar.gz"
}

Response

HTTP status code 200

파일 업데이트 추가 성공

HTTP status code 202

Headers

Location
Location: required (string)
Example:
Example

/contents/execute/file/f810f701-e732-4698-a5a9-a93000a828d9

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
idid: required (string)
태스크 ID

status
status: required (one of PENDING, PROGRESS, SUCCESS, REVOKED, FAILURE)
태스크 상태  ("태스크	실행	대기	상태":	"PENDING",	"태스크	실행	상태":	"PROGRESS",	"태스크	완료	상태":	"SUCCESS",	"태스크	중지	상태":	"REVOKED",	"태스크	실패	상태":	"FAILURE")

attributes: required (object)
attributes
logs
logs: required (array of string)
업데이트 진행 결과

Example:
Example

{
		"code":	"async",
		"result":	{
				"id":	"f810f701-e732-4698-a5a9-a93000a828d9",
				"status":	"PENDING",
				"attributes":	{
						"logs":[]
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

/contents/execute/file/{task_id}

파일 업데이트 태스크 결과 조회

Request

URI Parameters

task_id
task_id: required (string)
태스크 ID

Example:
Example

f810f701-e732-4698-a5a9-a93000a828d9

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

파일 업데이트 태스크 조회 성공

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
idid: required (string)
태스크 ID

status
status: required (one of PENDING, PROGRESS, SUCCESS, REVOKED, FAILURE)
태스크 상태  ("태스크	실행	대기	상태":	"PENDING",	"태스크	실행	상태":	"PROGRESS",	"태스크	완료	상태":	"SUCCESS",	"태스크	중지	상태":	"REVOKED",	"태스크	실패	상태":	"FAILURE")

attributes: required (object)
attributes
logs
logs: required (array of string)
업데이트 진행 결과

Example:
Example

{
		"code":	"ok",
		"result":	{
						"id":	"f810f701-e732-4698-a5a9-a93000a828d9",
						"status":	"SUCCESS",
						"attributes":	{
								"logs":	[
										"log1\n",
										"log2\n",
										"log3\n"
								]
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

POST

/contents/execute/online

온라인 업데이트를 실행한다.

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

Query Parameters

qq: required (object)
파라미터(string)
q=속성 %3D 값 , 속성 %3D 값```

type
type: required (one of 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13)
컨텐츠 DB 종류
1:	IPS	컨텐츠	DB
2:	애플리케이션	제어	DB
3:	웹	필터	DB
4:	안티	바이러스	DB
5:	블랙리스트	DB
6:	DLP	DB
7:	APT	정책
8:	파일	유형	제어	DB
9:	SSL	예외	목록
10:	사설인증서	DB
11:	디바이스	정책	DB
12:	Geo	IP	DB(2.0부터	지원)
13:	DNS	보안	DB(2.5부터	지원)

subtype
subtype: (one of 1, 2, 3, 4, 5, 6)
컨텐츠 DB 종류가 웹 필터 DB(3) 또는 디바이스 정책 DB(11)인 경우에만 사용하는 속성이다.
컨텐츠 DB 종류가 웹 필터 DB(3) 또는 디바이스 정책 DB(11)인 경우에만 사용하는 속성이다.
[웹 필터 DB 종류]
1:	Anonymizer
2:	SafeNET
3:	클라우드	악성	URL
4:	Categorized	URL
5:	SafeNet	Light(MGMT	호스트에서	유효함)
6:	외부	연동(Endpoint	피쳐가	있을	경우)

디바이스 DB 종류 (CUS:	1,	단말포탈:	2)
MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
MGMT HOST인 경우 컨텐츠 DB 종류가 IPS DB(1) 또는 안티 바이러스 DB(4)인 경우에만 사용하는 속성이다.
IPS DB 종류 (IPS	Light	DB:	1,	IPS	DB:	2)
안티 바이러스 DB 종류 (Stream	Based	DB:	1,	File	Based	DB:	2,	File	Based	DB(Light):	3)

Example:
Example

?q=type%3D1

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties

version
version: required (string)
버전

Example:
Example

{
		"version":	"201808241700"
}

Response

HTTP status code 200

온라인 업데이트 추가 성공

HTTP status code 202

Headers

Location
Location: required (string)
Example:
Example

/contents/execute/online/f810f701-e732-4698-a5a9-a93000a828d9

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
idid: required (string)
태스크 ID

status: required (one of PENDING, PROGRESS, SUCCESS, REVOKED, FAILURE)
status
태스크 상태  ("태스크	실행	대기	상태":	"PENDING",	"태스크	실행	상태":	"PROGRESS",	"태스크	완료	상태":	"SUCCESS",	"태스크	중지	상태":	"REVOKED",	"태스크	실패	상태":	"FAILURE")

attributes
attributes: required (object)
logs
logs: required (array of string)
업데이트 진행 결과

Example:
Example

{
		"code":	"async",
		"result":	{
				"id":	"f810f701-e732-4698-a5a9-a93000a828d9",
				"status":	"PENDING",
				"attributes":	{
						"logs":[]
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

GET

/contents/execute/online/{task_id}

파일 업데이트 태스크 결과 조회

Request

URI Parameters

task_id: required (string)
task_id
태스크 ID

Example:
Example

f810f701-e732-4698-a5a9-a93000a828d9

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

파일 업데이트 태스크 조회 성공

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
idid: required (string)
태스크 ID

status: required (one of PENDING, PROGRESS, SUCCESS, REVOKED, FAILURE)
status
태스크 상태  ("태스크	실행	대기	상태":	"PENDING",	"태스크	실행	상태":	"PROGRESS",	"태스크	완료	상태":	"SUCCESS",	"태스크	중지	상태":	"REVOKED",	"태스크	실패	상태":	"FAILURE")

attributes
attributes: required (object)
logs
logs: required (array of string)
업데이트 진행 결과

Example:
Example

{
		"code":	"ok",
		"result":	{
						"id":	"f810f701-e732-4698-a5a9-a93000a828d9",
						"status":	"SUCCESS",
						"attributes":	{
								"logs":	[
										"log1\n",
										"log2\n",
										"log3\n"
								]
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

Device 업데이트 설정

GET

/contents/device/cus

Device CUS 인증 및 접속 정보 설정을(를) 조회한다.

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

Device CUS 인증 및 접속 정보 설정 조회 성공

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

type
type: required (one of 1, 2)
접속 타입 (IP/Port:	1,	URL:	2)

ipip: required (string)
IP 주소

portport: required (integer - minimum: 1 - maximum: 65535)
포트

urlurl: required (string - maxLength: 128)
주소

auth_tm
auth_tm: (string)
날짜

ip_ver: (one of 1, 2)
ip_ver
IP 버전 (IPv4	주소:	1,	IPv6	주소:	2)

protocol
protocol: required (one of 1, 2 - default: 1)
프로토콜 (HTTP:	1,	HTTPS:	2)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"type":	1,
				"ip":	"1.1.1.1",
				"port":	4444,
				"url":	"http://xxx",
				"auth_tm":	"2018-09-15	19:11:34",
				"ip_ver":	1,
				"protocol":	2
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

/contents/device/cus

Device CUS 인증 및 접속 정보 설정을(를) 수정한다.

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

type
type: required (one of 1, 2)
접속 타입 (IP/Port:	1,	URL:	2)

ipip: required (string)
IP 주소

portport: required (integer - minimum: 1 - maximum: 65535)
포트

urlurl: required (string - maxLength: 128)
주소

auth_tm
auth_tm: (string)
날짜

ip_ver
ip_ver: (one of 1, 2)
IP 버전 (IPv4	주소:	1,	IPv6	주소:	2)

protocol
protocol: required (one of 1, 2 - default: 1)
프로토콜 (HTTP:	1,	HTTPS:	2)

Example:
Example

{
		"type":	1,
		"ip":	"1.1.1.1",
		"port":	4444,
		"url":	"http://xxx",
		"protocol":	2
}

Response

HTTP status code 200

Device CUS 인증 및 접속 정보 설정 수정 성공

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

type
type: required (one of 1, 2)
접속 타입 (IP/Port:	1,	URL:	2)

ipip: required (string)
IP 주소

portport: required (integer - minimum: 1 - maximum: 65535)
포트

urlurl: required (string - maxLength: 128)
주소

auth_tm
auth_tm: (string)
날짜

ip_ver
ip_ver: (one of 1, 2)
IP 버전 (IPv4	주소:	1,	IPv6	주소:	2)

protocol
protocol: required (one of 1, 2 - default: 1)
프로토콜 (HTTP:	1,	HTTPS:	2)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"type":	1,
				"ip":	"1.1.1.1",
				"port":	4444,
				"url":	"http://xxx",
				"protocol":	2
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

/contents/device/portal

Device Portal 인증 및 접속 정보 설정을(를) 조회한다.

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

Device Portal 인증 및 접속 정보 설정 조회 성공

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

type
type: required (one of 0, 1)
타입 (OFF:	0,	IP/Port:	1)

ipip: required (string)
IP 주소

portport: required (integer - minimum: 1 - maximum: 65535)
포트

Example:
Example

{
		"code":	"ok",
		"result":	{
				"type":	1,
				"ip":	"1.1.1.1",
				"port":	4444
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

/contents/device/portal

Device Portal 인증 및 접속 정보 설정을(를) 수정한다.

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

type
type: required (one of 0, 1)
타입 (OFF:	0,	IP/Port:	1)

ipip: required (string)
IP 주소

portport: required (integer - minimum: 1 - maximum: 65535)
포트

Example:
Example

{
		"type":	1,
		"ip":	"1.1.1.1",
		"port":	4444
}

Response

HTTP status code 200

Device Portal 인증 및 접속 정보 설정 수정 성공

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

type
type: required (one of 0, 1)
타입 (OFF:	0,	IP/Port:	1)

ipip: required (string)
IP 주소

portport: required (integer - minimum: 1 - maximum: 65535)
포트

Example:
Example

{
		"code":	"ok",
		"result":	{
				"type":	1,
				"ip":	"1.1.1.1",
				"port":	4444
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

/contents/device/portal-data

디바이스 DB 업데이트 데이터을(를) 조회한다.

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

qq: required (object)
파라미터(string)
q=속성 %3D 값 , 속성 %3D 값```

type
type: required (11)
디바이스 정책 DB (디바이스	정책	DB:	11)

subtype
subtype: required (one of 1, 2)
서브타입 (CUS:	1,	단말포탈:	2)

version
version: required (string)
버전

datedate: required (string)
날짜

Example:
Example

?q=type%3D11,subtype%3D1,version%3D1111

Response

HTTP status code 200

디바이스 DB 업데이트 데이터 조회 성공

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
Example:
Example

{
		"code":	"ok",
		"result":	{
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

블랙리스트 사용 설정

GET

/contents/backlist

블랙리스트 사용 설정을(를) 조회한다.

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

블랙리스트 사용 설정 조회 성공

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

status
status: required (one of 0, 1)
블랙리스트 사용 (OFF:	0,	ON:	1)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"status":	0
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

/contents/backlist

블랙리스트 사용 설정을(를) 수정한다.

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
status
status: required (one of 0, 1)
블랙리스트 사용 (OFF:	0,	ON:	1)

Example:
Example

{
		"status":	0
}

Response

HTTP status code 200

블랙리스트 사용 설정 수정 성공

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
status: required (one of 0, 1)
블랙리스트 사용 (OFF:	0,	ON:	1)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"status":	0
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

/contents/backlist/apply

블랙리스트 사용 설정을 적용합니다.

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

블랙리스트 사용 설정 적용 성공

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

/contents/backlist/cancel

블랙리스트 사용 설정을 취소합니다.

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

블랙리스트 사용 설정 취소 성공

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

통합 클라이언트

POST

/contents/client/file

통합 클라이언트 파일을 등록한다.

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

os_type
os_type: required (one of 1, 2, 3, 4, 6)
운영체제 타입 (Windows:	1,	Linux:	2,	Android:	3,	iOS:	4,	macOS:	6)

sub_type: required (one of 1, 2, 3)
sub_type
클라이언트 타입 (Client:	1,	OTP:	2,	IMAGE:	3)

filefile: required (string)
파일 이름

pwdpwd: (string)
파일 비밀번호(Base64)

Example:
Example

{
		"os_type":	1,
		"sub_type":	1,
		"file":	"abcd.zip",
		"pwd":	"x2xAyWkwMEAh"
}

Response

HTTP status code 200

GET

/contents/client/histories

통합 클라이언트 업데이트 목록을 조회한다.

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

통합 클라이언트 업데이트 목록 조회 성공

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
result: required (array of client_history)
Items: client_history
Items

dvc_clnt_up_history_id
dvc_clnt_up_history_id: required (integer)
ID

verver: required (string)
클라이언트 버전

update_type
update_type: required (one of 1, 2)
업데이트 경로 (파일	업데이트:	1,	CUS	업데이트:	2,	자동	업데이트:	3)

dvc_type
dvc_type: required (one of 1, 2)
클라이언트 타입 (Client:	1,	OTP:	2)

os_type
os_type: required (one of 1, 2, 3, 4, 6)
운영체제 타입 (Windows:	1,	Linux:	2,	Android:	3,	iOS:	4,	macOS:	6)

datedate: required (string)
날짜

result
result: required (one of 0, 1)
결과 (실패:	0,	성공:	1)

file_sz: required (integer)
file_sz
클라이언트 파일 크기(byte)

file_name
file_name: required (string)
파일 이름

result_msg
result_msg: required (string)
결과 메시지

is_use
is_use: required (one of 0, 1)
사용 (OFF:	0,	ON:	1)

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"dvc_clnt_up_history_id":	1,
						"ver":	"1.0.0",
						"update_type":	1,
						"dvc_type":	1,
						"os_type":	1,
						"date":	"2017-01-11	10:22:13",
						"result":	0,
						"file_sz":	100000,
						"file_name":	"client.zip",
						"result_msg":	"서버	연결실패(Timeout)",
						"is_use":	0
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

GET

/contents/client/cus

CUS 인증 및 접속 정보 설정을(를) 조회한다.

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

Response

HTTP status code 200

CUS 인증 및 접속 정보 설정 조회 성공

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

type
type: required (one of 1, 2)
접속 타입 (IP/Port:	1,	URL:	2)

ipip: required (string)
IP 주소

portport: required (integer - minimum: 1 - maximum: 65535)
포트

urlurl: required (string - maxLength: 128)
주소

auth_tm
auth_tm: (string)
날짜

ip_ver: (one of 1, 2)
ip_ver

IP 버전 (IPv4	주소:	1,	IPv6	주소:	2)

protocol
protocol: required (one of 1, 2 - default: 1)
프로토콜 (HTTP:	1,	HTTPS:	2)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"type":	1,
				"ip":	"1.1.1.1",
				"port":	4444,
				"url":	"http://xxx",
				"auth_tm":	"2018-09-15	19:11:34",
				"ip_ver":	1,
				"protocol":	2
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

PUT

/contents/client/cus

CUS 인증 및 접속 정보 설정을(를) 수정한다.

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

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties

type
type: required (one of 1, 2)
접속 타입 (IP/Port:	1,	URL:	2)

ipip: required (string)
IP 주소

portport: required (integer - minimum: 1 - maximum: 65535)
포트

urlurl: required (string - maxLength: 128)
주소

auth_tm
auth_tm: (string)
날짜

ip_ver
ip_ver: (one of 1, 2)
IP 버전 (IPv4	주소:	1,	IPv6	주소:	2)

protocol
protocol: required (one of 1, 2 - default: 1)
프로토콜 (HTTP:	1,	HTTPS:	2)

Example:
Example

{
		"type":	1,
		"ip":	"1.1.1.1",
		"port":	4444,
		"url":	"http://xxx",
		"protocol":	2
}

Response

HTTP status code 200

CUS 인증 및 접속 정보 설정 수정 성공

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

type
type: required (one of 1, 2)
접속 타입 (IP/Port:	1,	URL:	2)

ipip: required (string)
IP 주소

portport: required (integer - minimum: 1 - maximum: 65535)
포트

urlurl: required (string - maxLength: 128)
주소

auth_tm
auth_tm: (string)
날짜

ip_ver
ip_ver: (one of 1, 2)
IP 버전 (IPv4	주소:	1,	IPv6	주소:	2)

protocol
protocol: required (one of 1, 2 - default: 1)
프로토콜 (HTTP:	1,	HTTPS:	2)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"type":	1,
				"ip":	"1.1.1.1",
				"port":	4444,
				"url":	"http://xxx",
				"protocol":	2
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

GET

/contents/client/current-versions

클라이언트 파일 현재 버전을 조회한다.
q 파라미터가 없을 경우 전체를 조회한다.

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

Query Parameters

qq: required (object)
파라미터(string)
q=속성 %3D 값 , 속성 %3D 값```

os_type
os_type: (one of 1, 2, 3, 4, 6)
운영체제 타입 (Windows:	1,	Linux:	2,	Android:	3,	iOS:	4,	macOS:	6)

sub_type
sub_type: (one of 1, 2)
클라이언트 타입 (Client:	1,	OTP:	2)

Example:
Example

?q=os_type%3D1,sub_type%3D1

Response

HTTP status code 200

클라이언트 파일 현재 버전 조회 성공

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
result: required (array of client_history)
Items: client_history
Items

dvc_clnt_up_history_id: required (integer)
dvc_clnt_up_history_id
ID

verver: required (string)
클라이언트 버전

update_type
update_type: required (one of 1, 2)
업데이트 경로 (파일	업데이트:	1,	CUS	업데이트:	2,	자동	업데이트:	3)

dvc_type
dvc_type: required (one of 1, 2)
클라이언트 타입 (Client:	1,	OTP:	2)

os_type
os_type: required (one of 1, 2, 3, 4, 6)
운영체제 타입 (Windows:	1,	Linux:	2,	Android:	3,	iOS:	4,	macOS:	6)

datedate: required (string)

날짜

result
result: required (one of 0, 1)
결과 (실패:	0,	성공:	1)

file_sz: required (integer)
file_sz
클라이언트 파일 크기(byte)

file_name
file_name: required (string)
파일 이름

result_msg
result_msg: required (string)
결과 메시지

is_use
is_use: required (one of 0, 1)
사용 (OFF:	0,	ON:	1)

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"dvc_clnt_up_history_id":	1,
						"ver":	"1.0.0",
						"update_type":	1,
						"dvc_type":	1,
						"os_type":	1,
						"date":	"2017-01-11	10:22:13",
						"result":	0,
						"file_sz":	100000,
						"file_name":	"client.zip",
						"result_msg":	"서버	연결실패(Timeout)",
						"is_use":	0
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

POST

/contents/client/execute

업데이트를 실행한다.

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

os_type
os_type: required (one of 1, 2, 3, 4, 6)
운영체제 타입 (Windows:	1,	Linux:	2,	Android:	3,	iOS:	4,	macOS:	6)

sub_type
sub_type: required (one of 1, 2)
클라이언트 타입
Client:	1,	OTP:	2

Example:
Example

{
		"os_type":	1,
		"sub_type":	1
}

Response

HTTP status code 202

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
idid: required (string)
태스크 ID

status
status: required (one of PENDING, PROGRESS, SUCCESS, REVOKED, FAILURE)
태스크 상태  ("태스크	실행	대기	상태":	"PENDING",	"태스크	실행	상태":	"PROGRESS",	"태스크	완료	상태":	"SUCCESS",	"태스크	중지	상태":	"REVOKED",	"태스크	실패	상태":	"FAILURE")

attributes
attributes: required (object)
logs
logs: required (array of string)
업데이트 진행 결과

Example:
Example

{
		"code":	"async",
		"result":	{
				"id":	"f810f701-e732-4698-a5a9-a93000a828d9",
				"status":	"PENDING",
				"attributes":	{
						"logs":[]
				}
		}
}

GET

/contents/client/execute/{task_id}

업데이트 실행 태스크 결과 조회

Request

URI Parameters

task_id
task_id: required (string)
태스크 ID

Example:
Example

f810f701-e732-4698-a5a9-a93000a828d9

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

업데이트 실행 태스크 조회 성공

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
idid: required (string)
태스크 ID

status
status: required (one of PENDING, PROGRESS, SUCCESS, REVOKED, FAILURE)
태스크 상태  ("태스크	실행	대기	상태":	"PENDING",	"태스크	실행	상태":	"PROGRESS",	"태스크	완료	상태":	"SUCCESS",	"태스크	중지	상태":	"REVOKED",	"태스크	실패	상태":	"FAILURE")

attributes: required (object)
attributes

logs
logs: required (array of string)
업데이트 진행 결과

Example:
Example

{
		"code":	"ok",
		"result":	{
						"id":	"f810f701-e732-4698-a5a9-a93000a828d9",
						"status":	"SUCCESS",
						"attributes":	{
								"logs":	[
										"log1\n",
										"log2\n",
										"log3\n"
								]
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

/contents/client/auto

자동 업데이트 설정을(를) 조회한다.

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

자동 업데이트 설정 조회 성공

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
업데이트 설정

action: required (one of 0, 1, 2)
action
자동 업데이트 (없음:	0,	일별:	1,	매일:	2)

day_of_week
day_of_week: (object)
업데이트 설정(일별)

daysdays: required (array of any)
요일별 배열 순번 (일:	0,	월:	1,	화:	2,	수:	3,	목:	4,	금:	5,	토:	6)
요일 ON/OFF (OFF:	0,	ON:	1)

hour
hour: required (integer - minimum: 0 - maximum: 23)
시간

minmin: required (integer - minimum: 0 - maximum: 59)
분

every_day
every_day: (one of 0, 1)
업데이트 설정(매일) (60분	간격:	0,	360분	간격:	1)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"action":	1,
				"day_of_week":	{
						"days":	[
								0,1,1,1,0,1,1
						],
						"hour":	10,
						"min":	10
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

/contents/client/auto

자동 업데이트 설정을(를) 수정한다.

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
action
action: required (one of 0, 1, 2)
자동 업데이트 (없음:	0,	일별:	1,	매일:	2)

day_of_week
day_of_week: (object)
업데이트 설정(일별)

daysdays: required (array of any)
요일별 배열 순번 (일:	0,	월:	1,	화:	2,	수:	3,	목:	4,	금:	5,	토:	6)
요일 ON/OFF (OFF:	0,	ON:	1)

hour
hour: required (integer - minimum: 0 - maximum: 23)
시간

minmin: required (integer - minimum: 0 - maximum: 59)
분

every_day
every_day: (one of 0, 1)
업데이트 설정(매일) (60분	간격:	0,	360분	간격:	1)

Example:
Example

{
		"action":	1,
		"day_of_week":	{
				"days":	[
						0,1,1,1,0,1,1
				],
				"hour":	10,
				"min":	10
		}
}

Response

HTTP status code 200

자동 업데이트 설정 수정 성공

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
업데이트 설정

action
action: required (one of 0, 1, 2)
자동 업데이트 (없음:	0,	일별:	1,	매일:	2)

day_of_week: (object)
day_of_week
업데이트 설정(일별)

daysdays: required (array of any)
요일별 배열 순번 (일:	0,	월:	1,	화:	2,	수:	3,	목:	4,	금:	5,	토:	6)
요일 ON/OFF (OFF:	0,	ON:	1)

hour: required (integer - minimum: 0 - maximum: 23)
hour
시간

minmin: required (integer - minimum: 0 - maximum: 59)
분

every_day
every_day: (one of 0, 1)
업데이트 설정(매일) (60분	간격:	0,	360분	간격:	1)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"action":	1,
				"day_of_week":	{
						"days":	[
								0,1,1,1,0,1,1
						],
						"hour":	10,
						"min":	10
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

