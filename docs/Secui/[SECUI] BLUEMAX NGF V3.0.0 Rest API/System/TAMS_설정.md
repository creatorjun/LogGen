GET

PUT

GET

PUT

PUT

PUT

TAMS 설정 REST API 문서

https://{url}/api/sm

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/sm

TAMS 설정

/server/tams

/server/tams/seq

TAMS 설정 적용/취소

/command/server-tams/apply

/command/server-tams/cancel

TAMS 설정

GET

/server/tams

TAMS 설정을(를) 조회한다.

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

TAMS 설정 조회 성공

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

cfg_addr
cfg_addr: (string)
설정 서버 주소

cfg_port
cfg_port: (integer - default: 4343 - minimum: 1 - maximum: 65535)
설정 서버 포트

cfg_login_id
cfg_login_id: (string - maxLength: 128)
설정 서버 아이디

cfg_desc: (string - maxLength: 128)
cfg_desc
설정 서버 설명

mon1_use
mon1_use: required (one of 0, 1 - default: 0)
모니터링 서버1 사용여부
사용안함:	0,	사용:	1

mon1_addr: required (string)
mon1_addr
모니터링 서버1 주소

mon1_port
mon1_port: required (integer - default: 4343)
모니터링 서버1 포트

mon1_login_id
mon1_login_id: required (string - maxLength: 128)
모니터링 서버1 아이디

mon1_desc
mon1_desc: (string - maxLength: 128)
모니터링 서버1 설명

mon2_use
mon2_use: required (one of 0, 1 - default: 0)
모니터링 서버2 사용여부
사용안함:	0,	사용:	1

mon2_addr
mon2_addr: required (string)
모니터링 서버2 주소

mon2_port
mon2_port: required (integer - default: 4343)
모니터링 서버2 포트

mon2_login_id
mon2_login_id: required (string - maxLength: 128)
모니터링 서버2 아이디

mon2_desc
mon2_desc: (string - maxLength: 128)
모니터링 서버2 설명

mon3_use: required (one of 0, 1 - default: 0)
mon3_use
모니터링 서버3 사용여부
사용안함:	0,	사용:	1

mon3_addr
mon3_addr: required (string)
모니터링 서버3 주소

mon3_port: required (integer - default: 4343)
mon3_port
모니터링 서버3 포트

mon3_login_id
mon3_login_id: required (string - maxLength: 128)
모니터링 서버3 아이디

mon3_desc
mon3_desc: (string - maxLength: 128)
모니터링 서버3 설명

Example:
Example

{
		"code":	"ok",
		"result":	{
				"cfg_addr":	"",
				"cfg_port":	4343,
				"cfg_login_id":	"",
				"cfg_desc":	"",
				"mon1_use":	0,
				"mon1_addr":	"",
				"mon1_port":	4343,
				"mon1_login_id":	"",
				"mon1_desc":	"",
				"mon2_use":	0,
				"mon2_addr":	"",
				"mon2_port":	4343,
				"mon2_login_id":	"",
				"mon2_desc":	"",
				"mon3_use":	0,
				"mon3_addr":	"",
				"mon3_port":	4343,
				"mon3_login_id":	"",
				"mon3_desc":	""
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

/server/tams

TAMS 설정을(를) 수정한다.

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

cfg_addr
cfg_addr: (string)
설정 서버 주소

cfg_port
cfg_port: (integer - default: 4343 - minimum: 1 - maximum: 65535)
설정 서버 포트

cfg_login_id
cfg_login_id: (string - maxLength: 128)
설정 서버 아이디

cfg_desc
cfg_desc: (string - maxLength: 128)
설정 서버 설명

mon1_use
mon1_use: required (one of 0, 1 - default: 0)
모니터링 서버1 사용여부
사용안함:	0,	사용:	1

mon1_addr
mon1_addr: required (string)
모니터링 서버1 주소

mon1_port
mon1_port: required (integer - default: 4343)
모니터링 서버1 포트

mon1_login_id
mon1_login_id: required (string - maxLength: 128)
모니터링 서버1 아이디

mon1_desc: (string - maxLength: 128)
mon1_desc
모니터링 서버1 설명

mon2_use
mon2_use: required (one of 0, 1 - default: 0)
모니터링 서버2 사용여부
사용안함:	0,	사용:	1

mon2_addr: required (string)
mon2_addr
모니터링 서버2 주소

mon2_port
mon2_port: required (integer - default: 4343)
모니터링 서버2 포트

mon2_login_id
mon2_login_id: required (string - maxLength: 128)
모니터링 서버2 아이디

mon2_desc
mon2_desc: (string - maxLength: 128)
모니터링 서버2 설명

mon3_use
mon3_use: required (one of 0, 1 - default: 0)
모니터링 서버3 사용여부
사용안함:	0,	사용:	1

mon3_addr
mon3_addr: required (string)
모니터링 서버3 주소

mon3_port
mon3_port: required (integer - default: 4343)
모니터링 서버3 포트

mon3_login_id
mon3_login_id: required (string - maxLength: 128)
모니터링 서버3 아이디

mon3_desc
mon3_desc: (string - maxLength: 128)
모니터링 서버3 설명

cfg_login_pw: required (string - maxLength: 32)
cfg_login_pw
설정 서버 비밀번호(Base64 인코딩)

mon1_login_pw
mon1_login_pw: required (string - maxLength: 32)
모니터링 서버1 비밀번호(Base64 인코딩)

mon2_login_pw
mon2_login_pw: required (string - maxLength: 32)
모니터링 서버2 비밀번호(Base64 인코딩)

mon3_login_pw
mon3_login_pw: required (string - maxLength: 32)
모니터링 서버3 비밀번호(Base64 인코딩)

Example:
Example

{
		"cfg_addr":	"192.168.40.41",
		"cfg_port":	23783,
		"cfg_login_id":	"admin",
		"cfg_login_pw":	"x2xAyWkwMEAh",
		"cfg_desc":	"설명",
		"mon1_use":	1,
		"mon1_addr":	"192.168.40.61",
		"mon1_port":	23783,
		"mon1_login_id":	"admin",
		"mon1_login_pw":	"x2xAyWkwMEAh",
		"mon1_desc":	"설명	1",
		"mon2_use":	1,
		"mon2_addr":	"192.168.40.62",
		"mon2_port":	23783,
		"mon2_login_id":	"admin",
		"mon2_login_pw":	"x2xAyWkwMEAh",
		"mon2_desc":	"설명	2",
		"mon3_use":	1,
		"mon3_addr":	"192.168.40.63",
		"mon3_port":	23783,
		"mon3_login_id":	"admin",
		"mon3_login_pw":	"x2xAyWkwMEAh",
		"mon3_desc":	"설명	3"
}

Response

HTTP status code 200

TAMS 설정 수정 성공

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

cfg_addr
cfg_addr: (string)
설정 서버 주소

cfg_port
cfg_port: (integer - default: 4343 - minimum: 1 - maximum: 65535)
설정 서버 포트

cfg_login_id: (string - maxLength: 128)
cfg_login_id
설정 서버 아이디

cfg_desc
cfg_desc: (string - maxLength: 128)
설정 서버 설명

mon1_use: required (one of 0, 1 - default: 0)
mon1_use
모니터링 서버1 사용여부
사용안함:	0,	사용:	1

mon1_addr
mon1_addr: required (string)
모니터링 서버1 주소

mon1_port: required (integer - default: 4343)
mon1_port
모니터링 서버1 포트

mon1_login_id
mon1_login_id: required (string - maxLength: 128)
모니터링 서버1 아이디

mon1_desc
mon1_desc: (string - maxLength: 128)
모니터링 서버1 설명

mon2_use
mon2_use: required (one of 0, 1 - default: 0)
모니터링 서버2 사용여부
사용안함:	0,	사용:	1

mon2_addr
mon2_addr: required (string)
모니터링 서버2 주소

mon2_port
mon2_port: required (integer - default: 4343)
모니터링 서버2 포트

mon2_login_id
mon2_login_id: required (string - maxLength: 128)
모니터링 서버2 아이디

mon2_desc
mon2_desc: (string - maxLength: 128)
모니터링 서버2 설명

mon3_use
mon3_use: required (one of 0, 1 - default: 0)
모니터링 서버3 사용여부
사용안함:	0,	사용:	1

mon3_addr
mon3_addr: required (string)
모니터링 서버3 주소

mon3_port
mon3_port: required (integer - default: 4343)
모니터링 서버3 포트

mon3_login_id: required (string - maxLength: 128)
mon3_login_id
모니터링 서버3 아이디

mon3_desc
mon3_desc: (string - maxLength: 128)
모니터링 서버3 설명

Example:
Example

{
		"code":	"ok",
		"result":	{
				"cfg_addr":	"192.168.40.41",
				"cfg_port":	23783,
				"cfg_login_id":	"admin",
				"cfg_desc":	"설명",
				"mon1_use":	1,
				"mon1_addr":	"192.168.40.61",
				"mon1_port":	23783,
				"mon1_login_id":	"admin",
				"mon1_desc":	"설명	1",
				"mon2_use":	1,
				"mon2_addr":	"192.168.40.62",
				"mon2_port":	23783,
				"mon2_login_id":	"admin",
				"mon2_desc":	"설명	2",
				"mon3_use":	1,
				"mon3_addr":	"192.168.40.63",
				"mon3_port":	23783,
				"mon3_login_id":	"admin",
				"mon3_desc":	"설명	3"
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

/server/tams/seq

TAMS 시퀀스 목록을 조회한다.

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

TAMS 시퀀스 목록 조회 성공

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
result: required (array of ServerTamsSeq)
결과 데이터

Items: ServerTamsSeq
Items

menu_id
menu_id: required (integer)
메뉴 아이디

seqseq: required (integer)
시퀀스

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"menu_id":	1,
				"seq":	1000
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

/server/tams/seq

TAMS 시퀀스를 수정한다.

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

menu_id
menu_id: required (integer)
메뉴 아이디

seqseq: required (integer)
시퀀스

Example:
Example

{
		"menu_id":	1,
		"seq":	1000
}

Response

HTTP status code 200

TAMS 시퀀스 목록 수정 성공

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

TAMS 설정 적용/취소

PUT

/command/server-tams/apply

TAMS 설정을 적용합니다.

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

TAMS 설정 적용 성공

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

/command/server-tams/cancel

TAMS 설정을 취소합니다.

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

TAMS 설정 취소 성공

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

