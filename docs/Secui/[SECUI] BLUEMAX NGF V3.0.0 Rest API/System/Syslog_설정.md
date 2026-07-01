GET

PUT

PUT

PUT

GET

PUT

PUT

PUT

Syslog 설정 REST API 문서

https://{url}/api/sm

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/sm

Syslog 설정

/server/syslog

Syslog 설정 적용/취소

/command/server-syslog/apply

/command/server-syslog/cancel

Syslog 송신 주소 설정

/server/syslog/send-addr

Syslog 송신 주소 설정 적용/취소

/command/server-syslog-addr/apply

/command/server-syslog-addr/cancel

Syslog 설정

GET

/server/syslog

Syslog 설정을(를) 조회한다.

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

Syslog 설정 조회 성공

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

svr1_use
svr1_use: required (one of 0, 1 - default: 0)
로그 전송 사용 여부
사용안함:	0,	사용:	1

svr1_addr
svr1_addr: required (string)
로그 전송 대상 서버 IP 설정

svr1_port
svr1_port: required (integer - default: 0)
로그 전송 대상 서버 Port 설정

svr1_func
svr1_func: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 - default: 0)
로그 전송시 기능 설정
user:	0,	kern:	1,	Auth:	2,	daemon:	3,	local0:	4,	local1:	5,	local2:	6,	local3:	7,	local4:	8,	local5:	9,	local6:	10,	local7:	11

svr1_form: required (one of 0, 1, 2, 3, 4 - default: 0)
svr1_form
로그 전송 포멧 설정
CSV:	0,	TSV:	1,	WELF:	2,	BINARY:	3,	PRISM:	4

svr1_desc
svr1_desc: required (string)
전송 대상 서버에 대한 설명

svr2_use: required (one of 0, 1 - default: 0)
svr2_use
로그 전송 사용 여부
사용안함:	0,	사용:	1

svr2_addr
svr2_addr: required (string)
로그 전송 대상 서버 IP 설정

svr2_port: required (integer - default: 0)
svr2_port
로그 전송 대상 서버 Port 설정

svr2_func
svr2_func: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 - default: 0)
로그 전송시 기능 설정
user:	0,	kern:	1,	Auth:	2,	daemon:	3,	local0:	4,	local1:	5,	local2:	6,	local3:	7,	local4:	8,	local5:	9,	local6:	10,	local7:	11

svr2_form: required (one of 0, 1, 2, 3, 4 - default: 0)
svr2_form
로그 전송 포멧 설정
CSV:	0,	TSV:	1,	WELF:	2,	BINARY:	3,	PRISM:	4

svr2_desc
svr2_desc: required (string)
전송 대상 서버에 대한 설명

svr3_use: required (one of 0, 1 - default: 0)
svr3_use
로그 전송 사용 여부
사용안함:	0,	사용:	1

svr3_addr
svr3_addr: required (string)
로그 전송 대상 서버 IP 설정

svr3_port: required (integer - default: 0)
svr3_port
로그 전송 대상 서버 Port 설정

svr3_func
svr3_func: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 - default: 0)
로그 전송시 기능 설정
user:	0,	kern:	1,	Auth:	2,	daemon:	3,	local0:	4,	local1:	5,	local2:	6,	local3:	7,	local4:	8,	local5:	9,	local6:	10,	local7:	11

svr3_form: required (one of 0, 1, 2, 3, 4 - default: 0)
svr3_form
로그 전송 포멧 설정
CSV:	0,	TSV:	1,	WELF:	2,	BINARY:	3,	PRISM:	4

svr3_desc
svr3_desc: required (string)
전송 대상 서버에 대한 설명

svr4_use: required (one of 0, 1 - default: 0)
svr4_use
로그 전송 사용 여부
사용안함:	0,	사용:	1

svr4_addr
svr4_addr: required (string)
로그 전송 대상 서버 IP 설정

svr4_port: required (integer - default: 0)
svr4_port
로그 전송 대상 서버 Port 설정

svr4_func
svr4_func: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 - default: 0)
로그 전송시 기능 설정
user:	0,	kern:	1,	Auth:	2,	daemon:	3,	local0:	4,	local1:	5,	local2:	6,	local3:	7,	local4:	8,	local5:	9,	local6:	10,	local7:	11

svr4_form
svr4_form: required (one of 0, 1, 2, 3, 4 - default: 0)
로그 전송 포멧 설정
CSV:	0,	TSV:	1,	WELF:	2,	BINARY:	3,	PRISM:	4

svr4_desc
svr4_desc: required (string)
전송 대상 서버에 대한 설명

svr5_use
svr5_use: required (one of 0, 1 - default: 0)
로그 전송 사용 여부
사용안함:	0,	사용:	1

svr5_addr
svr5_addr: required (string)
로그 전송 대상 서버 IP 설정

svr5_port
svr5_port: required (integer - default: 0)
로그 전송 대상 서버 Port 설정

svr5_func
svr5_func: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 - default: 0)
로그 전송시 기능 설정
user:	0,	kern:	1,	Auth:	2,	daemon:	3,	local0:	4,	local1:	5,	local2:	6,	local3:	7,	local4:	8,	local5:	9,	local6:	10,	local7:	11

svr5_form
svr5_form: required (one of 0, 1, 2, 3, 4 - default: 0)
로그 전송 포멧 설정
CSV:	0,	TSV:	1,	WELF:	2,	BINARY:	3,	PRISM:	4

svr5_desc: required (string)
svr5_desc
전송 대상 서버에 대한 설명

Example:
Example

{
		"code":	"ok",
		"result":	{
				"svr1_use":	0,
				"svr1_addr":	"",
				"svr1_port":	0,
				"svr1_func":	0,
				"svr1_form":	0,
				"svr1_desc":	"",
				"svr2_use":	0,
				"svr2_addr":	"",
				"svr2_port":	0,
				"svr2_func":	0,
				"svr2_form":	0,
				"svr2_desc":	"",
				"svr3_use":	0,
				"svr3_addr":	"",
				"svr3_port":	0,
				"svr3_func":	0,
				"svr3_form":	0,
				"svr3_desc":	"",
				"svr4_use":	0,
				"svr4_addr":	"",
				"svr4_port":	0,
				"svr4_func":	0,
				"svr4_form":	0,
				"svr4_desc":	"",
				"svr5_use":	0,
				"svr5_addr":	"",
				"svr5_port":	0,
				"svr5_func":	0,
				"svr5_form":	0,
				"svr5_desc":	""
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

/server/syslog

Syslog 설정을(를) 수정한다.

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

svr1_use
svr1_use: required (one of 0, 1 - default: 0)
로그 전송 사용 여부
사용안함:	0,	사용:	1

svr1_addr
svr1_addr: required (string)
로그 전송 대상 서버 IP 설정

svr1_port
svr1_port: required (integer - default: 0)
로그 전송 대상 서버 Port 설정

svr1_func
svr1_func: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 - default: 0)
로그 전송시 기능 설정
user:	0,	kern:	1,	Auth:	2,	daemon:	3,	local0:	4,	local1:	5,	local2:	6,	local3:	7,	local4:	8,	local5:	9,	local6:	10,	local7:	11

svr1_form
svr1_form: required (one of 0, 1, 2, 3, 4 - default: 0)
로그 전송 포멧 설정
CSV:	0,	TSV:	1,	WELF:	2,	BINARY:	3,	PRISM:	4

svr1_desc
svr1_desc: required (string)
전송 대상 서버에 대한 설명

svr2_use
svr2_use: required (one of 0, 1 - default: 0)
로그 전송 사용 여부
사용안함:	0,	사용:	1

svr2_addr
svr2_addr: required (string)
로그 전송 대상 서버 IP 설정

svr2_port
svr2_port: required (integer - default: 0)
로그 전송 대상 서버 Port 설정

svr2_func
svr2_func: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 - default: 0)
로그 전송시 기능 설정
user:	0,	kern:	1,	Auth:	2,	daemon:	3,	local0:	4,	local1:	5,	local2:	6,	local3:	7,	local4:	8,	local5:	9,	local6:	10,	local7:	11

svr2_form
svr2_form: required (one of 0, 1, 2, 3, 4 - default: 0)
로그 전송 포멧 설정
CSV:	0,	TSV:	1,	WELF:	2,	BINARY:	3,	PRISM:	4

svr2_desc
svr2_desc: required (string)
전송 대상 서버에 대한 설명

svr3_use
svr3_use: required (one of 0, 1 - default: 0)
로그 전송 사용 여부
사용안함:	0,	사용:	1

svr3_addr: required (string)
svr3_addr
로그 전송 대상 서버 IP 설정

svr3_port
svr3_port: required (integer - default: 0)
로그 전송 대상 서버 Port 설정

svr3_func
svr3_func: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 - default: 0)
로그 전송시 기능 설정
user:	0,	kern:	1,	Auth:	2,	daemon:	3,	local0:	4,	local1:	5,	local2:	6,	local3:	7,	local4:	8,	local5:	9,	local6:	10,	local7:	11

svr3_form
svr3_form: required (one of 0, 1, 2, 3, 4 - default: 0)
로그 전송 포멧 설정
CSV:	0,	TSV:	1,	WELF:	2,	BINARY:	3,	PRISM:	4

svr3_desc: required (string)
svr3_desc
전송 대상 서버에 대한 설명

svr4_use
svr4_use: required (one of 0, 1 - default: 0)
로그 전송 사용 여부
사용안함:	0,	사용:	1

svr4_addr: required (string)
svr4_addr
로그 전송 대상 서버 IP 설정

svr4_port
svr4_port: required (integer - default: 0)
로그 전송 대상 서버 Port 설정

svr4_func
svr4_func: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 - default: 0)
로그 전송시 기능 설정
user:	0,	kern:	1,	Auth:	2,	daemon:	3,	local0:	4,	local1:	5,	local2:	6,	local3:	7,	local4:	8,	local5:	9,	local6:	10,	local7:	11

svr4_form
svr4_form: required (one of 0, 1, 2, 3, 4 - default: 0)
로그 전송 포멧 설정
CSV:	0,	TSV:	1,	WELF:	2,	BINARY:	3,	PRISM:	4

svr4_desc: required (string)
svr4_desc
전송 대상 서버에 대한 설명

svr5_use
svr5_use: required (one of 0, 1 - default: 0)
로그 전송 사용 여부
사용안함:	0,	사용:	1

svr5_addr
svr5_addr: required (string)
로그 전송 대상 서버 IP 설정

svr5_port
svr5_port: required (integer - default: 0)
로그 전송 대상 서버 Port 설정

svr5_func: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 - default: 0)
svr5_func
로그 전송시 기능 설정
user:	0,	kern:	1,	Auth:	2,	daemon:	3,	local0:	4,	local1:	5,	local2:	6,	local3:	7,	local4:	8,	local5:	9,	local6:	10,	local7:	11

svr5_form
svr5_form: required (one of 0, 1, 2, 3, 4 - default: 0)
로그 전송 포멧 설정
CSV:	0,	TSV:	1,	WELF:	2,	BINARY:	3,	PRISM:	4

svr5_desc
svr5_desc: required (string)
전송 대상 서버에 대한 설명

Example:
Example

{
		"svr1_use":	1,
		"svr1_addr":	"1.1.1.1",
		"svr1_port":	1000,
		"svr1_func":	11,
		"svr1_form":	4,
		"svr1_desc":	"설명1",
		"svr2_use":	1,
		"svr2_addr":	"2.2.2.2",
		"svr2_port":	2000,
		"svr2_func":	11,
		"svr2_form":	4,
		"svr2_desc":	"설명2",
		"svr3_use":	1,
		"svr3_addr":	"3.3.3.3",
		"svr3_port":	3000,
		"svr3_func":	11,
		"svr3_form":	4,
		"svr3_desc":	"설명3",
		"svr4_use":	1,
		"svr4_addr":	"4.4.4.4",
		"svr4_port":	4000,
		"svr4_func":	11,
		"svr4_form":	4,
		"svr4_desc":	"설명4",
		"svr5_use":	1,
		"svr5_addr":	"5.5.5.5",
		"svr5_port":	5000,
		"svr5_func":	11,
		"svr5_form":	4,
		"svr5_desc":	"설명5"
}

Response

HTTP status code 200

Syslog 설정 수정 성공

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

svr1_use
svr1_use: required (one of 0, 1 - default: 0)
로그 전송 사용 여부
사용안함:	0,	사용:	1

svr1_addr
svr1_addr: required (string)
로그 전송 대상 서버 IP 설정

svr1_port
svr1_port: required (integer - default: 0)
로그 전송 대상 서버 Port 설정

svr1_func
svr1_func: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 - default: 0)
로그 전송시 기능 설정
user:	0,	kern:	1,	Auth:	2,	daemon:	3,	local0:	4,	local1:	5,	local2:	6,	local3:	7,	local4:	8,	local5:	9,	local6:	10,	local7:	11

svr1_form
svr1_form: required (one of 0, 1, 2, 3, 4 - default: 0)
로그 전송 포멧 설정
CSV:	0,	TSV:	1,	WELF:	2,	BINARY:	3,	PRISM:	4

svr1_desc
svr1_desc: required (string)
전송 대상 서버에 대한 설명

svr2_use
svr2_use: required (one of 0, 1 - default: 0)
로그 전송 사용 여부
사용안함:	0,	사용:	1

svr2_addr
svr2_addr: required (string)
로그 전송 대상 서버 IP 설정

svr2_port
svr2_port: required (integer - default: 0)
로그 전송 대상 서버 Port 설정

svr2_func
svr2_func: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 - default: 0)
로그 전송시 기능 설정
user:	0,	kern:	1,	Auth:	2,	daemon:	3,	local0:	4,	local1:	5,	local2:	6,	local3:	7,	local4:	8,	local5:	9,	local6:	10,	local7:	11

svr2_form
svr2_form: required (one of 0, 1, 2, 3, 4 - default: 0)
로그 전송 포멧 설정
CSV:	0,	TSV:	1,	WELF:	2,	BINARY:	3,	PRISM:	4

svr2_desc: required (string)
svr2_desc
전송 대상 서버에 대한 설명

svr3_use
svr3_use: required (one of 0, 1 - default: 0)
로그 전송 사용 여부
사용안함:	0,	사용:	1

svr3_addr: required (string)
svr3_addr
로그 전송 대상 서버 IP 설정

svr3_port
svr3_port: required (integer - default: 0)
로그 전송 대상 서버 Port 설정

svr3_func
svr3_func: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 - default: 0)
로그 전송시 기능 설정
user:	0,	kern:	1,	Auth:	2,	daemon:	3,	local0:	4,	local1:	5,	local2:	6,	local3:	7,	local4:	8,	local5:	9,	local6:	10,	local7:	11

svr3_form
svr3_form: required (one of 0, 1, 2, 3, 4 - default: 0)
로그 전송 포멧 설정
CSV:	0,	TSV:	1,	WELF:	2,	BINARY:	3,	PRISM:	4

svr3_desc: required (string)
svr3_desc
전송 대상 서버에 대한 설명

svr4_use
svr4_use: required (one of 0, 1 - default: 0)
로그 전송 사용 여부
사용안함:	0,	사용:	1

svr4_addr: required (string)
svr4_addr
로그 전송 대상 서버 IP 설정

svr4_port
svr4_port: required (integer - default: 0)
로그 전송 대상 서버 Port 설정

svr4_func
svr4_func: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 - default: 0)
로그 전송시 기능 설정
user:	0,	kern:	1,	Auth:	2,	daemon:	3,	local0:	4,	local1:	5,	local2:	6,	local3:	7,	local4:	8,	local5:	9,	local6:	10,	local7:	11

svr4_form
svr4_form: required (one of 0, 1, 2, 3, 4 - default: 0)
로그 전송 포멧 설정
CSV:	0,	TSV:	1,	WELF:	2,	BINARY:	3,	PRISM:	4

svr4_desc: required (string)
svr4_desc
전송 대상 서버에 대한 설명

svr5_use
svr5_use: required (one of 0, 1 - default: 0)
로그 전송 사용 여부
사용안함:	0,	사용:	1

svr5_addr: required (string)
svr5_addr
로그 전송 대상 서버 IP 설정

svr5_port
svr5_port: required (integer - default: 0)
로그 전송 대상 서버 Port 설정

svr5_func
svr5_func: required (one of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 - default: 0)
로그 전송시 기능 설정
user:	0,	kern:	1,	Auth:	2,	daemon:	3,	local0:	4,	local1:	5,	local2:	6,	local3:	7,	local4:	8,	local5:	9,	local6:	10,	local7:	11

svr5_form
svr5_form: required (one of 0, 1, 2, 3, 4 - default: 0)
로그 전송 포멧 설정
CSV:	0,	TSV:	1,	WELF:	2,	BINARY:	3,	PRISM:	4

svr5_desc
svr5_desc: required (string)
전송 대상 서버에 대한 설명

Example:
Example

{
		"code":	"ok",
		"result":	{
				"svr1_use":	1,
				"svr1_addr":	"1.1.1.1",
				"svr1_port":	1000,
				"svr1_func":	11,
				"svr1_form":	4,
				"svr1_desc":	"설명1",
				"svr2_use":	1,
				"svr2_addr":	"2.2.2.2",
				"svr2_port":	2000,
				"svr2_func":	11,
				"svr2_form":	4,
				"svr2_desc":	"설명2",
				"svr3_use":	1,
				"svr3_addr":	"3.3.3.3",
				"svr3_port":	3000,
				"svr3_func":	11,
				"svr3_form":	4,
				"svr3_desc":	"설명3",
				"svr4_use":	1,
				"svr4_addr":	"4.4.4.4",
				"svr4_port":	4000,
				"svr4_func":	11,
				"svr4_form":	4,
				"svr4_desc":	"설명4",
				"svr5_use":	1,
				"svr5_addr":	"5.5.5.5",
				"svr5_port":	5000,
				"svr5_func":	11,
				"svr5_form":	4,
				"svr5_desc":	"설명5"
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

Syslog 설정 적용/취소

PUT

/command/server-syslog/apply

Syslog 설정을 적용합니다.

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

Syslog 설정 적용 성공

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

/command/server-syslog/cancel

Syslog 설정을 취소합니다.

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

Syslog 설정 취소 성공

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

Syslog 송신 주소 설정

GET

/server/syslog/send-addr

Syslog 송신 주소 설정을(를) 조회한다.

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

Response

HTTP status code 200

Syslog 송신 주소 설정 조회 성공

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

snd_addr_type
snd_addr_type: required (one of 1, 2 - default: 1)
송신지 IP 주소 타입 설정
IPv4:	1,	IPv6:	2

snd_addr: required (string)
snd_addr

송신지 IP 주소

Example:
Example

{
		"code":	"ok",
		"result":	{
				"snd_addr_type":1,
				"snd_addr":	""
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

/server/syslog/send-addr

Syslog 송신 주소 설정을(를) 수정한다.

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

snd_addr_type
snd_addr_type: required (one of 1, 2 - default: 1)
송신지 IP 주소 타입 설정
IPv4:	1,	IPv6:	2

snd_addr
snd_addr: required (string)
송신지 IP 주소

Example:
Example

{
		"snd_addr_type":1,
		"snd_addr":	"127.0.0.1"
}

Response

HTTP status code 200

Syslog 송신 주소 설정 수정 성공

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

snd_addr_type
snd_addr_type: required (one of 1, 2 - default: 1)
송신지 IP 주소 타입 설정
IPv4:	1,	IPv6:	2

snd_addr
snd_addr: required (string)
송신지 IP 주소

Example:
Example

{
		"code":	"ok",
		"result":	{
				"snd_addr_type":1,
				"snd_addr":	"127.0.0.1"
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

Syslog 송신 주소 설정 적용/취소

PUT

/command/server-syslog-addr/apply

Syslog 송신 주소 설정을 적용합니다.

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

Syslog 송신 주소 설정 적용 성공

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

/command/server-syslog-addr/cancel

Syslog 송신 주소 설정을 취소합니다.

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

Syslog 송신 주소 설정 취소 성공

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

