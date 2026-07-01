GET

GET

POST

  DELETE

PUT

  DELETE

GET

PUT

GET

POST

PUT

GET

PUT

  DELETE

GET

PUT

GET

PUT

PUT

PUT

PUT

PUT

SNMP 설정 REST API 문서

https://{url}/api/sm

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/sm

SNMP 사용자

/server/snmp/users

/server/snmp/users/{pk}

SNMP 설정

/server/snmp

/server/snmp/v3

/server/snmp/v3/{pk}

SNMP Trap 설정

/server/snmp/trap

/server/snmp/trap/send-addr

SNMP 설정 적용/취소

/command/server-snmp/apply

/command/server-snmp/cancel

/command/server-snmp-trap/apply

/command/server-snmp-trap/cancel

SNMP 사용자

GET

/server/snmp/users

SNMP 사용자 목록을 조회한다.

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

SNMP 사용자 목록 조회 성공

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
result: required (array of ResSnmpUser)
결과 데이터

Items: ResSnmpUser
Items

svr_name
svr_name: required (string)
사용자 서버 이름(수정 불가 항목)

usr_name
usr_name: required (string)
사용자 이름(수정 불가 항목)

security: required (one of 0, 1, 2 - default: 0)
security
사용자 보안
인증	없음:	0,	사용자	인증:	1,	사용자	인증	메시지	암호화:	2

auth_type
auth_type: required (one of 0, 1 - default: 0)
사용자 인증 타입
SHA-1:	0,	MD5:	1

msg_enc_type: required (one of 0, 1 - default: 0)
msg_enc_type
메시지 암호화 타입
AES-1:	0,	DES:	1

snmp_usr_id
snmp_usr_id: required (integer)
SNMP 사용자의 고유 ID

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"snmp_usr_id":	1,
				"svr_name":	"snmp_server",
				"usr_name":	"user",
				"security":	0,
				"auth_type":	0,
				"msg_enc_type":	0
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

/server/snmp/users

SNMP 사용자를 추가한다.

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

svr_name
svr_name: required (string)
사용자 서버 이름(수정 불가 항목)

usr_name
usr_name: required (string)
사용자 이름(수정 불가 항목)

security: required (one of 0, 1, 2 - default: 0)
security
사용자 보안
인증	없음:	0,	사용자	인증:	1,	사용자	인증	메시지	암호화:	2

auth_type
auth_type: required (one of 0, 1 - default: 0)
사용자 인증 타입
SHA-1:	0,	MD5:	1

msg_enc_type
msg_enc_type: required (one of 0, 1 - default: 0)
메시지 암호화 타입
AES-1:	0,	DES:	1

auth_pw
auth_pw: required (string)
사용자 인증에서 사용하기 위한 비밀번호(Base64 인코딩)

msg_enc_pw
msg_enc_pw: required (string)
메시지 인증에서 사용하기 위한 비밀번호(Base64 인코딩)

Example:
Example

{
		"svr_name":	"snmp_server",
		"usr_name":	"user",
		"security":	0,
		"auth_type":	0,
		"auth_pw":	"x2xAyWkwMEAh",
		"msg_enc_type":	0,
		"msg_enc_pw":	"x2xAyWkwMEAh"
}

Response

HTTP status code 200

SNMP 사용자 추가 성공

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

svr_name
svr_name: required (string)
사용자 서버 이름(수정 불가 항목)

usr_name
usr_name: required (string)
사용자 이름(수정 불가 항목)

security
security: required (one of 0, 1, 2 - default: 0)
사용자 보안
인증	없음:	0,	사용자	인증:	1,	사용자	인증	메시지	암호화:	2

auth_type
auth_type: required (one of 0, 1 - default: 0)
사용자 인증 타입
SHA-1:	0,	MD5:	1

msg_enc_type
msg_enc_type: required (one of 0, 1 - default: 0)
메시지 암호화 타입
AES-1:	0,	DES:	1

snmp_usr_id: required (integer)
snmp_usr_id
SNMP 사용자의 고유 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"snmp_usr_id":	1,
				"svr_name":	"snmp_server",
				"usr_name":	"user",
				"security":	0,
				"auth_type":	0,
				"msg_enc_type":	0
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

/server/snmp/users

SNMP 사용자 목록을 (일괄)삭제한다.

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
삭제 아이템 목록

Example:
Example

{
		"items":	[
				{"snmp_usr_id":	1},
				{"snmp_usr_id":	2}
		]
}

Response

HTTP status code 200

SNMP 사용자 목록 삭제 성공

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

/server/snmp/users/{pk}

SNMP 사용자을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
SNMP 사용자의 고유 ID ( snmp_usr_id )

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

SNMP 사용자 조회 성공

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

svr_name
svr_name: required (string)
사용자 서버 이름(수정 불가 항목)

usr_name
usr_name: required (string)
사용자 이름(수정 불가 항목)

security
security: required (one of 0, 1, 2 - default: 0)
사용자 보안
인증	없음:	0,	사용자	인증:	1,	사용자	인증	메시지	암호화:	2

auth_type
auth_type: required (one of 0, 1 - default: 0)
사용자 인증 타입
SHA-1:	0,	MD5:	1

msg_enc_type
msg_enc_type: required (one of 0, 1 - default: 0)
메시지 암호화 타입
AES-1:	0,	DES:	1

snmp_usr_id
snmp_usr_id: required (integer)
SNMP 사용자의 고유 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"snmp_usr_id":	1,
				"svr_name":	"snmp_server",
				"usr_name":	"user",
				"security":	0,
				"auth_type":	0,
				"msg_enc_type":	0
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

/server/snmp/users/{pk}

SNMP 사용자을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
SNMP 사용자의 고유 ID ( snmp_usr_id )

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

svr_name: required (string)
svr_name
사용자 서버 이름(수정 불가 항목)

usr_name
usr_name: required (string)
사용자 이름(수정 불가 항목)

security
security: required (one of 0, 1, 2 - default: 0)
사용자 보안
인증	없음:	0,	사용자	인증:	1,	사용자	인증	메시지	암호화:	2

auth_type
auth_type: required (one of 0, 1 - default: 0)
사용자 인증 타입
SHA-1:	0,	MD5:	1

msg_enc_type: required (one of 0, 1 - default: 0)
msg_enc_type
메시지 암호화 타입
AES-1:	0,	DES:	1

auth_pw
auth_pw: required (string)
사용자 인증에서 사용하기 위한 비밀번호(Base64 인코딩)

msg_enc_pw: required (string)
msg_enc_pw
메시지 인증에서 사용하기 위한 비밀번호(Base64 인코딩)

Example:
Example

{
		"svr_name":	"snmp_server",
		"usr_name":	"user",
		"security":	2,
		"auth_type":	1,
		"auth_pw":	"x2xAyWkwMEAh",
		"msg_enc_type":	1,
		"msg_enc_pw":	"x2xAyWkwMEAh"
}

Response

HTTP status code 200

SNMP 사용자 수정 성공

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

svr_name
svr_name: required (string)
사용자 서버 이름(수정 불가 항목)

usr_name
usr_name: required (string)
사용자 이름(수정 불가 항목)

security
security: required (one of 0, 1, 2 - default: 0)
사용자 보안
인증	없음:	0,	사용자	인증:	1,	사용자	인증	메시지	암호화:	2

auth_type
auth_type: required (one of 0, 1 - default: 0)
사용자 인증 타입
SHA-1:	0,	MD5:	1

msg_enc_type
msg_enc_type: required (one of 0, 1 - default: 0)
메시지 암호화 타입
AES-1:	0,	DES:	1

snmp_usr_id
snmp_usr_id: required (integer)
SNMP 사용자의 고유 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"snmp_usr_id":	1,
				"svr_name":	"snmp_server",
				"usr_name":	"user",
				"security":	2,
				"auth_type":	1,
				"msg_enc_type":	1
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

/server/snmp/users/{pk}

SNMP 사용자을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
SNMP 사용자의 고유 ID ( snmp_usr_id )

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

SNMP 사용자 삭제 성공

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

SNMP 설정

GET

/server/snmp

SNMP 설정을(를) 조회한다.

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

SNMP 설정 조회 성공

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
SNMP 사용 유무
사용안함:	0,	사용:	1

community
community: required (string)
SNMP Community

Example:
Example

{
		"code":	"ok",
		"result":	{
				"use":	0,
				"community":	""
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

/server/snmp

SNMP 설정을(를) 수정한다.

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

Properties
Properties

useuse: required (one of 0, 1 - default: 0)
SNMP 사용 유무
사용안함:	0,	사용:	1

community: required (string)
community
SNMP Community

Example:
Example

{
		"use":	1,
		"community":	"set_community"
}

Response

HTTP status code 200

SNMP 설정 수정 성공

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
SNMP 사용 유무
사용안함:	0,	사용:	1

community
community: required (string)
SNMP Community

Example:
Example

{
		"code":	"ok",
		"result":	{
				"use":	1,
				"community":	"set_community"
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

/server/snmp/v3

SNMP V3 설정 목록을 조회한다.

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

SNMP V3 설정 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of ResSnmpV3)
result
결과 데이터

Items: ResSnmpV3
Items

useuse: required (one of 0, 1 - default: 0)
SNMP V3 사용 유무
사용안함:	0,	사용:	1

snmp_usr_id
snmp_usr_id: required (integer)
SNMP 사용자의 고유 ID

svr_name
svr_name: required (string)
사용자 서버 이름

usr_name
usr_name: required (string)
사용자 이름

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"snmp_usr_id":	1,
				"use":	0,
				"svr_name":	"snmp_server1",
				"usr_name":	"user1"
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

/server/snmp/v3

SNMP V3 설정를 추가한다.

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

snmp_usr_id
snmp_usr_id: required (integer)
SNMP 사용자의 고유 ID

useuse: required (one of 0, 1 - default: 0)
SNMP V3 사용 유무
사용안함:	0,	사용:	1

Example:
Example

{
		"snmp_usr_id":	1,
		"use":	0
}

Response

HTTP status code 200

SNMP V3 설정 추가 성공

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
result: required (array of ResSnmpV3)
결과 데이터

Items: ResSnmpV3
Items

useuse: required (one of 0, 1 - default: 0)
SNMP V3 사용 유무
사용안함:	0,	사용:	1

snmp_usr_id
snmp_usr_id: required (integer)
SNMP 사용자의 고유 ID

svr_name
svr_name: required (string)
사용자 서버 이름

usr_name
usr_name: required (string)
사용자 이름

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"snmp_usr_id":	1,
				"use":	0,
				"svr_name":	"snmp_server1",
				"usr_name":	"user1"
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

PUT

/server/snmp/v3

SNMP V3 설정 목록을 (일괄)수정한다.

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
items: required (array of SnmpV3)
수정 아이템 목록

Items: SnmpV3
Items

useuse: required (one of 0, 1 - default: 0)
SNMP V3 사용 유무
사용안함:	0,	사용:	1

Example:
Example

{
		"items":	[
				{"snmp_usr_id":	1,	"use":	1}
		]
}

Response

HTTP status code 200

SNMP V3 설정 목록 수정 성공

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

/server/snmp/v3/{pk}

SNMP V3 설정을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
SNMP 사용자의 고유 ID ( snmp_usr_id )

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

SNMP V3 설정 조회 성공

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
SNMP V3 사용 유무
사용안함:	0,	사용:	1

snmp_usr_id
snmp_usr_id: required (integer)
SNMP 사용자의 고유 ID

svr_name
svr_name: required (string)
사용자 서버 이름

usr_name: required (string)
usr_name

사용자 이름

Example:
Example

{
		"code":	"ok",
		"result":	{
				"snmp_usr_id":	1,
				"use":	0,
				"svr_name":	"snmp_server1",
				"usr_name":	"user1"
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

/server/snmp/v3/{pk}

SNMP V3 설정을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
SNMP 사용자의 고유 ID ( snmp_usr_id )

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

useuse: required (one of 0, 1 - default: 0)
SNMP V3 사용 유무
사용안함:	0,	사용:	1

Example:
Example

{
		"use":	1
}

Response

HTTP status code 200

SNMP V3 설정 수정 성공

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
SNMP V3 사용 유무
사용안함:	0,	사용:	1

snmp_usr_id
snmp_usr_id: required (integer)
SNMP 사용자의 고유 ID

svr_name: required (string)
svr_name
사용자 서버 이름

usr_name
usr_name: required (string)
사용자 이름

Example:
Example

{
		"code":	"ok",
		"result":	{
				"snmp_usr_id":	1,
				"use":	1,
				"svr_name":	"snmp_server2",
				"usr_name":	"user2"
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

/server/snmp/v3/{pk}

SNMP V3 설정을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
SNMP 사용자의 고유 ID ( snmp_usr_id )

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

Response

HTTP status code 200

SNMP V3 설정 삭제 성공

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

SNMP Trap 설정

GET

/server/snmp/trap

SNMP Trap 설정을(를) 조회한다.

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

SNMP Trap 설정 조회 성공

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

svr1_snmp_usr_id: required (integer)
svr1_snmp_usr_id
SNMP 사용자 고유 ID

svr1_use
svr1_use: required (one of 0, 1 - default: 0)
SNMP TRAP 사용 유무
사용안함:	0,	사용:	1

svr1_addr: required (string)
svr1_addr
SNMP 수신지 IP

svr1_port
svr1_port: required (integer - default: 0)
SNMP 수신지 Port

svr1_community
svr1_community: required (string)
수신지 Community

svr1_ver
svr1_ver: required (one of 1, 2, 3 - default: 0)
SNMP 버전
1:	1,	2c:	2,	3:	3

svr1_desc
svr1_desc: required (string)
설명

svr2_snmp_usr_id
svr2_snmp_usr_id: required (integer)
SNMP 사용자 고유 ID

svr2_use
svr2_use: required (one of 0, 1 - default: 0)
SNMP TRAP 사용 유무
사용안함:	0,	사용:	1

svr2_addr
svr2_addr: required (string)
SNMP 수신지 IP

svr2_port
svr2_port: required (integer - default: 0)
SNMP 수신지 Port

svr2_community
svr2_community: required (string)
수신지 Community

svr2_ver
svr2_ver: required (one of 1, 2, 3 - default: 0)
SNMP 버전
1:	1,	2c:	2,	3:	3

svr2_desc
svr2_desc: required (string)
설명

svr3_snmp_usr_id
svr3_snmp_usr_id: required (integer)
SNMP 사용자 고유 ID

svr3_use: required (one of 0, 1 - default: 0)
svr3_use
SNMP TRAP 사용 유무
사용안함:	0,	사용:	1

svr3_addr
svr3_addr: required (string)
SNMP 수신지 IP

svr3_port: required (integer - default: 0)
svr3_port
SNMP 수신지 Port

svr3_community
svr3_community: required (string)
수신지 Community

svr3_ver
svr3_ver: required (one of 1, 2, 3 - default: 0)
SNMP 버전
1:	1,	2c:	2,	3:	3

svr3_desc
svr3_desc: required (string)
설명

svr1_svr_name
svr1_svr_name: required (string)
SNMP 서버 이름

svr1_usr_name
svr1_usr_name: required (string)
SNMP 사용자 이름

svr2_svr_name
svr2_svr_name: required (string)
SNMP 서버 이름

svr2_usr_name
svr2_usr_name: required (string)
SNMP 사용자 이름

svr3_svr_name
svr3_svr_name: required (string)
SNMP 서버 이름

svr3_usr_name: required (string)
svr3_usr_name
SNMP 사용자 이름

Example:
Example

{
		"code":	"ok",
		"result":	{
				"svr1_snmp_usr_id":	0,
				"svr1_use":	0,
				"svr1_addr":	"",
				"svr1_port":	0,
				"svr1_community":	"",
				"svr1_ver":	0,
				"svr1_svr_name":	"",
				"svr1_usr_name":	"",
				"svr1_desc":	"",
				"svr2_snmp_usr_id":	0,
				"svr2_use":	0,
				"svr2_addr":	"",
				"svr2_port":	0,
				"svr2_community":	"",
				"svr2_ver":	0,
				"svr2_svr_name":	"",
				"svr2_usr_name":	"",
				"svr2_desc":	"",
				"svr3_snmp_usr_id":	0,
				"svr3_use":	0,
				"svr3_addr":	"",
				"svr3_port":	0,
				"svr3_community":	"",
				"svr3_ver":	0,
				"svr3_svr_name":	"",
				"svr3_usr_name":	"",
				"svr3_desc":	""
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

/server/snmp/trap

SNMP Trap 설정을(를) 수정한다.

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

svr1_snmp_usr_id
svr1_snmp_usr_id: required (integer)
SNMP 사용자 고유 ID

svr1_use
svr1_use: required (one of 0, 1 - default: 0)
SNMP TRAP 사용 유무
사용안함:	0,	사용:	1

svr1_addr
svr1_addr: required (string)
SNMP 수신지 IP

svr1_port
svr1_port: required (integer - default: 0)
SNMP 수신지 Port

svr1_community
svr1_community: required (string)
수신지 Community

svr1_ver
svr1_ver: required (one of 1, 2, 3 - default: 0)
SNMP 버전
1:	1,	2c:	2,	3:	3

svr1_desc
svr1_desc: required (string)
설명

svr2_snmp_usr_id
svr2_snmp_usr_id: required (integer)
SNMP 사용자 고유 ID

svr2_use
svr2_use: required (one of 0, 1 - default: 0)
SNMP TRAP 사용 유무
사용안함:	0,	사용:	1

svr2_addr
svr2_addr: required (string)
SNMP 수신지 IP

svr2_port
svr2_port: required (integer - default: 0)
SNMP 수신지 Port

svr2_community
svr2_community: required (string)
수신지 Community

svr2_ver: required (one of 1, 2, 3 - default: 0)
svr2_ver
SNMP 버전
1:	1,	2c:	2,	3:	3

svr2_desc
svr2_desc: required (string)
설명

svr3_snmp_usr_id: required (integer)
svr3_snmp_usr_id
SNMP 사용자 고유 ID

svr3_use
svr3_use: required (one of 0, 1 - default: 0)
SNMP TRAP 사용 유무
사용안함:	0,	사용:	1

svr3_addr: required (string)
svr3_addr
SNMP 수신지 IP

svr3_port
svr3_port: required (integer - default: 0)
SNMP 수신지 Port

svr3_community: required (string)
svr3_community

수신지 Community

svr3_ver
svr3_ver: required (one of 1, 2, 3 - default: 0)
SNMP 버전
1:	1,	2c:	2,	3:	3

svr3_desc
svr3_desc: required (string)
설명

Example:
Example

{
		"svr1_snmp_usr_id":	1,
		"svr1_use":	1,
		"svr1_addr":	"1.1.1.1",
		"svr1_port":	1000,
		"svr1_community":	"community1",
		"svr1_ver":	1,
		"svr1_desc":	"설명",
		"svr2_snmp_usr_id":	2,
		"svr2_use":	1,
		"svr2_addr":	"2.2.2.2",
		"svr2_port":	1000,
		"svr2_community":	"community2",
		"svr2_ver":	2,
		"svr2_desc":	"설명",
		"svr3_snmp_usr_id":	3,
		"svr3_use":	1,
		"svr3_addr":	"3.3.3.3",
		"svr3_port":	1000,
		"svr3_community":	"community3",
		"svr3_ver":	3,
		"svr3_desc":	"설명"
}

Response

HTTP status code 200

SNMP Trap 설정 수정 성공

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

svr1_snmp_usr_id
svr1_snmp_usr_id: required (integer)
SNMP 사용자 고유 ID

svr1_use
svr1_use: required (one of 0, 1 - default: 0)
SNMP TRAP 사용 유무
사용안함:	0,	사용:	1

svr1_addr
svr1_addr: required (string)
SNMP 수신지 IP

svr1_port
svr1_port: required (integer - default: 0)
SNMP 수신지 Port

svr1_community
svr1_community: required (string)
수신지 Community

svr1_ver: required (one of 1, 2, 3 - default: 0)
svr1_ver
SNMP 버전
1:	1,	2c:	2,	3:	3

svr1_desc
svr1_desc: required (string)
설명

svr2_snmp_usr_id: required (integer)
svr2_snmp_usr_id
SNMP 사용자 고유 ID

svr2_use
svr2_use: required (one of 0, 1 - default: 0)
SNMP TRAP 사용 유무
사용안함:	0,	사용:	1

svr2_addr: required (string)
svr2_addr
SNMP 수신지 IP

svr2_port
svr2_port: required (integer - default: 0)
SNMP 수신지 Port

svr2_community
svr2_community: required (string)
수신지 Community

svr2_ver
svr2_ver: required (one of 1, 2, 3 - default: 0)
SNMP 버전
1:	1,	2c:	2,	3:	3

svr2_desc
svr2_desc: required (string)
설명

svr3_snmp_usr_id
svr3_snmp_usr_id: required (integer)
SNMP 사용자 고유 ID

svr3_use: required (one of 0, 1 - default: 0)
svr3_use

SNMP TRAP 사용 유무
사용안함:	0,	사용:	1

svr3_addr
svr3_addr: required (string)
SNMP 수신지 IP

svr3_port
svr3_port: required (integer - default: 0)
SNMP 수신지 Port

svr3_community
svr3_community: required (string)
수신지 Community

svr3_ver
svr3_ver: required (one of 1, 2, 3 - default: 0)
SNMP 버전
1:	1,	2c:	2,	3:	3

svr3_desc
svr3_desc: required (string)
설명

svr1_svr_name
svr1_svr_name: required (string)
SNMP 서버 이름

svr1_usr_name
svr1_usr_name: required (string)
SNMP 사용자 이름

svr2_svr_name: required (string)
svr2_svr_name
SNMP 서버 이름

svr2_usr_name
svr2_usr_name: required (string)
SNMP 사용자 이름

svr3_svr_name
svr3_svr_name: required (string)
SNMP 서버 이름

svr3_usr_name
svr3_usr_name: required (string)
SNMP 사용자 이름

Example:
Example

{
		"code":	"ok",
		"result":	{
				"svr1_snmp_usr_id":	1,
				"svr1_use":	1,
				"svr1_addr":	"1.1.1.1",
				"svr1_port":	1000,
				"svr1_community":	"community1",
				"svr1_ver":	1,
				"svr1_svr_name":	"snmp_server1",
				"svr1_usr_name":	"user1",
				"svr1_desc":	"설명",
				"svr2_snmp_usr_id":	2,
				"svr2_use":	1,
				"svr2_addr":	"2.2.2.2",
				"svr2_port":	1000,
				"svr2_community":	"community2",
				"svr2_ver":	2,
				"svr2_svr_name":	"snmp_server2",
				"svr2_usr_name":	"user2",
				"svr2_desc":	"설명",
				"svr3_snmp_usr_id":	3,
				"svr3_use":	1,
				"svr3_addr":	"3.3.3.3",
				"svr3_port":	1000,
				"svr3_community":	"community3",
				"svr3_ver":	3,
				"svr3_svr_name":	"snmp_server3",
				"svr3_usr_name":	"user3",
				"svr3_desc":	"설명"
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

/server/snmp/trap/send-addr

SNMP Trap 송신 주소 설정을(를) 조회한다.

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

SNMP Trap 송신 주소 설정 조회 성공

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

snd_addr
snd_addr: required (string)
송신지 IP 주소

Example:
Example

{
		"code":	"ok",
		"result":	{
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

/server/snmp/trap/send-addr

SNMP Trap 송신 주소 설정을(를) 수정한다.

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

snd_addr
snd_addr: required (string)
송신지 IP 주소

Example:
Example

{
		"snd_addr":	"127.0.0.1"
}

Response

HTTP status code 200

SNMP Trap 송신 주소 설정 수정 성공

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

snd_addr
snd_addr: required (string)
송신지 IP 주소

Example:
Example

{
		"code":	"ok",
		"result":	{
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

SNMP 설정 적용/취소

PUT

/command/server-snmp/apply

SNMP 설정을 적용합니다.

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

SNMP 설정 적용 성공

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

/command/server-snmp/cancel

SNMP 설정을 취소합니다.

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

SNMP 설정 취소 성공

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

/command/server-snmp-trap/apply

SNMP Trap 송신 주소 설정을 적용합니다.

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

SNMP Trap 송신 주소 설정 적용 성공

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

/command/server-snmp-trap/cancel

SNMP Trap 송신 주소 설정을 취소합니다.

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

Example:
Example

{}

Response

HTTP status code 200

SNMP Trap 송신 주소 설정 취소 성공

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

