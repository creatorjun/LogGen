GET

PUT

PUT

PUT

L2TP 설정 REST API 문서

https://{url}/api/vp

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/vp

L2TP 설정

/tunnel/l2tp

L2TP 설정 적용/취소

/command/tunnel-l2tp/apply

/command/tunnel-l2tp/cancel

L2TP 설정

GET

/tunnel/l2tp

L2TP 설정을(를) 조회한다.

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

L2TP 설정 조회 성공

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

alloc_ip_range
alloc_ip_range: required (object)
IP 할당 범위

addr_obj_id
addr_obj_id: required (integer)
객체 아이디

name
name: required (string)
객체 이름

zone
zone: required (one of 1, 2, 3)
Zone 정보
내부:	1,	외부:	2,	DMZ:	3

descdesc: required (string)
설명

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

useuse: required (one of 0, 1)
PPTP 사용 여부
사용안함:	0,	사용:	1

dns1dns1: required (string)
DNS IP1

dns2dns2: required (string)
DNS IP2

wins1wins1: required (string)
WINS IP1

wins2wins2: required (string)
WINS IP2

local_ip
local_ip: required (string)
로컬 IP

dev_name
dev_name: required (string)
DEV 이름

Example:
Example

{
		"code":	"ok",
		"result":	{
				"alloc_ip_range":	null,
				"dev_name":	"localhost",
				"use":	0,
				"dns1":	null,
				"dns2":	null,
				"wins1":	null,
				"wins2":	null,
				"local_ip":	null
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

/tunnel/l2tp

L2TP 설정을(를) 수정한다.

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

alloc_ip_range
alloc_ip_range: required (object)
IP 할당 범위

addr_obj_id
addr_obj_id: required (integer)
객체 아이디

name
name: required (string)
객체 이름

zone
zone: required (one of 1, 2, 3)
Zone 정보
내부:	1,	외부:	2,	DMZ:	3

descdesc: required (string)
설명

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

useuse: required (one of 0, 1)
PPTP 사용 여부
사용안함:	0,	사용:	1

dns1dns1: required (string)
DNS IP1

dns2dns2: required (string)
DNS IP2

wins1wins1: required (string)
WINS IP1

wins2wins2: required (string)
WINS IP2

local_ip
local_ip: required (string)
로컬 IP

Example:
Example

{
		"alloc_ip_range":	{
				"addr_obj_id":	7,
				"name":	"IP_EXT_RANGE_V4",
				"zone":	2,
				"desc":	"",
				"addr_obj_type":	3,
				"ip_info1":	"1.1.1.1",
				"ip_info2":	"1.1.1.10"
		},
		"use":	1,
		"dns1":	"8.8.8.88",
		"dns2":	"8.8.8.99",
		"wins1":	"2.2.2.33",
		"wins2":	"2.2.2.44",
		"local_ip":	"129.128.127.2"
}

Response

HTTP status code 200

L2TP 설정 수정 성공

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

alloc_ip_range
alloc_ip_range: required (object)
IP 할당 범위

addr_obj_id
addr_obj_id: required (integer)
객체 아이디

name: required (string)
name
객체 이름

zone
zone: required (one of 1, 2, 3)
Zone 정보
내부:	1,	외부:	2,	DMZ:	3

descdesc: required (string)
설명

addr_obj_type
addr_obj_type: required (one of 1, 2, 3, 4)
객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3,	그룹객체:	4

ip_info1: required (string)
ip_info1
IP 정보1

ip_info2
ip_info2: required (string)
IP 정보2

useuse: required (one of 0, 1)
PPTP 사용 여부
사용안함:	0,	사용:	1

dns1dns1: required (string)
DNS IP1

dns2dns2: required (string)
DNS IP2

wins1wins1: required (string)
WINS IP1

wins2wins2: required (string)
WINS IP2

local_ip
local_ip: required (string)
로컬 IP

dev_name
dev_name: required (string)
DEV 이름

Example:
Example

{
		"code":	"ok",
		"result":	{
				"alloc_ip_range":	{
						"addr_obj_id":	7,
						"name":	"IP_EXT_RANGE_V4",
						"zone":	2,
						"desc":	"",
						"addr_obj_type":	3,
						"ip_info1":	"1.1.1.1",
						"ip_info2":	"1.1.1.10"
				},
				"dev_name":	"localhost",
				"use":	1,
				"dns1":	"8.8.8.88",
				"dns2":	"8.8.8.99",
				"wins1":	"2.2.2.33",
				"wins2":	"2.2.2.44",
				"local_ip":	"129.128.127.2"
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

L2TP 설정 적용/취소

PUT

/command/tunnel-l2tp/apply

L2TP 설정을 적용합니다.

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

L2TP 설정 적용 성공

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

/command/tunnel-l2tp/cancel

L2TP 설정을 취소합니다.

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

L2TP 설정 취소 성공

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

