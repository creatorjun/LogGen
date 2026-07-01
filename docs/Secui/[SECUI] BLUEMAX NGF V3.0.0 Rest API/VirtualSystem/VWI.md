GET

PUT

GET

GET

PUT

GET

PUT

GET

PUT

GET

POST

GET

GET

GET

PUT

  DELETE

GET

PUT

GET

PUT

VWI 설정 REST API 문서

https://{url}/api/ho

urlurl: required (string)
장비 IP:Port

일반 설정

/vwi/{vs_id}/config

인터페이스

/vwi/{vs_id}/interfaces

/vwi/{vs_id}/interfaces/{if_name}

/vwi/{vs_id}/interfaces/{if_name}/advance

/vwi/{vs_id}/interfaces/{if_name}/status

트렁크 인터페이스

/vwi/{vs_id}/trunk-interfaces

/vwi/{vs_id}/trunk-interfaces/candidates

/vwi/{vs_id}/trunk-interfaces/slaves

/vwi/{vs_id}/trunk-interfaces/{if_name}

/vwi/{vs_id}/trunk-interfaces/{if_name}/advance

/vwi/{vs_id}/trunk-interfaces/{if_name}/status

일반 설정

GET

/vwi/{vs_id}/config

일반 설정을(를) 조회한다.

Request

URI Parameters

vs_id
vs_id: required (integer)
VS ID

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

일반 설정 조회 성공

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

mtumtu: required (integer - minimum: 68 - maximum: 1500)
MTU

jumbo_frame: required (one of 0, 1)
jumbo_frame
Jumbo Frame 지원 (OFF:	0,	ON:	1)

mac_aging_tm
mac_aging_tm: required (integer - minimum: 10 - maximum: 1000000)
MAC 주소 Aging 시간

stp_enable
stp_enable: required (one of 0, 1)
STP 사용 (OFF:	0,	ON:	1)

stp_prio
stp_prio: required (integer - minimum: 0 - maximum: 65535)
우선 순위

stp_forward_delay
stp_forward_delay: required (integer - minimum: 4 - maximum: 30)
Forward Delay

stp_hello_tm
stp_hello_tm: required (integer - minimum: 1 - maximum: 10)
Hello 시간

stp_max_age
stp_max_age: required (integer - minimum: 6 - maximum: 40)
최대 메시지 Age

igmp_snooping: required (one of 0, 1)
igmp_snooping
IGMP Snooping 사용 (OFF:	0,	ON:	1)

vlan_filtering
vlan_filtering: required (one of 0, 1)
VLAN 필터링 사용 (OFF:	0,	ON:	1)

forward_8021q
forward_8021q: required (one of 0, 1 - default: 0)
802.1Q 예약 주소 Forward 사용
(OFF:	0,	ON:	1)

SupportedVersion:	2.0.0

diffdiff: (array of any)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"mtu":68,
				"jumbo_frame":0,
				"mac_aging_tm":10,
				"stp_enable":1,
				"stp_prio":1,
				"stp_forward_delay":4,
				"stp_hello_tm":1,
				"stp_max_age":6,
				"igmp_snooping":0,
				"vlan_filtering":0,
				"forward_8021q":0
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

/vwi/{vs_id}/config

일반 설정을(를) 수정한다.

Request

URI Parameters

vs_id
vs_id: required (integer)
VS ID

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

mtumtu: required (integer - minimum: 68 - maximum: 1500)
MTU

jumbo_frame
jumbo_frame: required (one of 0, 1)
Jumbo Frame 지원 (OFF:	0,	ON:	1)

mac_aging_tm: required (integer - minimum: 10 - maximum: 1000000)
mac_aging_tm
MAC 주소 Aging 시간

stp_enable
stp_enable: required (one of 0, 1)
STP 사용 (OFF:	0,	ON:	1)

stp_prio
stp_prio: required (integer - minimum: 0 - maximum: 65535)
우선 순위

stp_forward_delay
stp_forward_delay: required (integer - minimum: 4 - maximum: 30)
Forward Delay

stp_hello_tm
stp_hello_tm: required (integer - minimum: 1 - maximum: 10)
Hello 시간

stp_max_age
stp_max_age: required (integer - minimum: 6 - maximum: 40)
최대 메시지 Age

igmp_snooping
igmp_snooping: required (one of 0, 1)
IGMP Snooping 사용 (OFF:	0,	ON:	1)

vlan_filtering: required (one of 0, 1)
vlan_filtering
VLAN 필터링 사용 (OFF:	0,	ON:	1)

forward_8021q
forward_8021q: required (one of 0, 1 - default: 0)
802.1Q 예약 주소 Forward 사용
(OFF:	0,	ON:	1)

SupportedVersion:	2.0.0

diffdiff: (array of any)

Example:
Example

{
		"mtu":68,
		"jumbo_frame":0,
		"mac_aging_tm":10,
		"stp_enable":1,
		"stp_prio":1,
		"stp_forward_delay":4,
		"stp_hello_tm":1,
		"stp_max_age":6,
		"igmp_snooping":0,
		"vlan_filtering":0,
		"forward_8021q":0,
		"diff":[]
}

Response

HTTP status code 200

일반 설정 수정 성공

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

인터페이스

GET

/vwi/{vs_id}/interfaces

인터페이스 목록을 조회한다.

Request

URI Parameters

vs_id: required (integer)
vs_id
VS ID

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

인터페이스 목록 조회 성공

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
result: required (array of interface)
Items: interface
Items

if_name
if_name: (string)
인터페이스 이름

modemode: (one of 1, 2)
L2 모드 (L2:	1,	L2	Bridge:	2)

speed: (one of 1, 2, 3, 4, 5)
speed
속도 (10M:	1,	100M:	2,	1G:	3,	10G:	4,	40G:	5)

duplex
duplex: (one of 1, 2)
Duplex (Half:	1,	Full:	2)

auto_neg
auto_neg: (one of 0, 1)
자동협상 (OFF:	0,	ON:	1)

useuse: (one of 0, 1)
사용 (OFF:	0,	ON:	1)

descdesc: (string - maxLength: 256)
설명

diffdiff: (array of any)

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"if_name":"",
						"mode":1,
						"speed":1,
						"duplex":1,
						"auto_neg":1,
						"use":1,
						"desc":""
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

GET

/vwi/{vs_id}/interfaces/{if_name}

인터페이스 기본 설정을(를) 조회한다.

Request

URI Parameters

vs_id
vs_id: required (integer)
VS ID

Example:
Example

1

if_name: required (string)
if_name
인터페이스 이름

Example:
Example

eth0

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

인터페이스 기본 설정 조회 성공

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
if_name
if_name: (string)
인터페이스 이름

modemode: (one of 1, 2)
L2 모드 (L2:	1,	L2	Bridge:	2)

speed
speed: (one of 1, 2, 3, 4, 5)
속도 (10M:	1,	100M:	2,	1G:	3,	10G:	4,	40G:	5)

duplex
duplex: (one of 1, 2)
Duplex (Half:	1,	Full:	2)

auto_neg
auto_neg: (one of 0, 1)
자동협상 (OFF:	0,	ON:	1)

useuse: (one of 0, 1)
사용 (OFF:	0,	ON:	1)

descdesc: (string - maxLength: 256)
설명

diffdiff: (array of any)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"if_name":"",
				"mode":1,
				"desc":""
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

/vwi/{vs_id}/interfaces/{if_name}

인터페이스 기본 설정을(를) 수정한다.

Request

URI Parameters

vs_id: required (integer)
vs_id

VS ID

Example:
Example

1

if_name
if_name: required (string)
인터페이스 이름

Example:
Example

eth0

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

if_name
if_name: (string)
인터페이스 이름

modemode: (one of 1, 2)
L2 모드 (L2:	1,	L2	Bridge:	2)

speed
speed: (one of 1, 2, 3, 4, 5)
속도 (10M:	1,	100M:	2,	1G:	3,	10G:	4,	40G:	5)

duplex
duplex: (one of 1, 2)
Duplex (Half:	1,	Full:	2)

auto_neg
auto_neg: (one of 0, 1)
자동협상 (OFF:	0,	ON:	1)

useuse: (one of 0, 1)
사용 (OFF:	0,	ON:	1)

descdesc: (string - maxLength: 256)
설명

diffdiff: (array of any)

Example:
Example

{
		"mode":1,
		"desc":"",
		"diff":[]
}

Response

HTTP status code 200

인터페이스 기본 설정 수정 성공

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
if_name
if_name: (string)
인터페이스 이름

modemode: (one of 1, 2)
L2 모드 (L2:	1,	L2	Bridge:	2)

speed
speed: (one of 1, 2, 3, 4, 5)
속도 (10M:	1,	100M:	2,	1G:	3,	10G:	4,	40G:	5)

duplex: (one of 1, 2)
duplex
Duplex (Half:	1,	Full:	2)

auto_neg
auto_neg: (one of 0, 1)
자동협상 (OFF:	0,	ON:	1)

useuse: (one of 0, 1)
사용 (OFF:	0,	ON:	1)

descdesc: (string - maxLength: 256)
설명

diffdiff: (array of any)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"if_name":"",
				"mode":1,
				"desc":""
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

/vwi/{vs_id}/interfaces/{if_name}/advance

인터페이스 고급 설정을(를) 조회한다.

Request

URI Parameters

vs_id
vs_id: required (integer)
VS ID

Example:
Example

1

if_name: required (string)
if_name
인터페이스 이름

Example:
Example

eth0

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

인터페이스 고급 설정 조회 성공

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
if_name
if_name: (string)
인터페이스 이름

vid_type
vid_type: required (one of 1, 2)
VLAN 필터링 종류 (PVID:	1,	VID:	2)

pvidpvid: required (integer - minimum: 1 - maximum: 4094)
PVID

vidvid: required (string)
VID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"if_name":"",
				"vid_type":1,
				"pvid":1,
				"vid":""
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

/vwi/{vs_id}/interfaces/{if_name}/advance

인터페이스 고급 설정을(를) 수정한다.

Request

URI Parameters

vs_id
vs_id: required (integer)
VS ID

Example:
Example

1

if_name: required (string)
if_name
인터페이스 이름

Example:
Example

eth0

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

if_name
if_name: (string)
인터페이스 이름

vid_type
vid_type: required (one of 1, 2)
VLAN 필터링 종류 (PVID:	1,	VID:	2)

pvidpvid: required (integer - minimum: 1 - maximum: 4094)
PVID

vidvid: required (string)
VID

Example:
Example

{
		"vid_type":1,
		"pvid":1,
		"vid":"",
		"diff":[]
}

Response

HTTP status code 200

인터페이스 고급 설정 수정 성공

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
if_name: (string)
if_name

인터페이스 이름

vid_type
vid_type: required (one of 1, 2)
VLAN 필터링 종류 (PVID:	1,	VID:	2)

pvidpvid: required (integer - minimum: 1 - maximum: 4094)
PVID

vidvid: required (string)
VID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"if_name":"",
				"vid_type":1,
				"pvid":1,
				"vid":""
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

GET

/vwi/{vs_id}/interfaces/{if_name}/status

인터페이스 상태 설정을(를) 조회한다.

Request

URI Parameters

vs_id
vs_id: required (integer)
VS ID

Example:
Example

1

if_name
if_name: required (string)
인터페이스 이름

Example:
Example

eth0

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

인터페이스 상태 설정 조회 성공

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
if_name
if_name: (string)
인터페이스 이름

modemode: (one of 1, 2)
L2 모드 (L2:	1,	L2	Bridge:	2)

speed
speed: (one of 1, 2, 3, 4, 5)
속도 (10M:	1,	100M:	2,	1G:	3,	10G:	4,	40G:	5)

duplex
duplex: (one of 1, 2)
Duplex (Half:	1,	Full:	2)

auto_neg
auto_neg: (one of 0, 1)
자동협상 (OFF:	0,	ON:	1)

useuse: (one of 0, 1)
사용 (OFF:	0,	ON:	1)

descdesc: (string - maxLength: 256)
설명

diffdiff: (array of any)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"if_name":"",
				"speed":1,
				"duplex":1,
				"auto_neg":1,
				"use":1
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

/vwi/{vs_id}/interfaces/{if_name}/status

인터페이스 상태 설정을(를) 수정한다.

Request

URI Parameters

vs_id
vs_id: required (integer)
VS ID

Example:
Example

1

if_name
if_name: required (string)
인터페이스 이름

Example:
Example

eth0

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

if_name: (string)
if_name
인터페이스 이름

modemode: (one of 1, 2)
L2 모드 (L2:	1,	L2	Bridge:	2)

speed: (one of 1, 2, 3, 4, 5)
speed
속도 (10M:	1,	100M:	2,	1G:	3,	10G:	4,	40G:	5)

duplex
duplex: (one of 1, 2)
Duplex (Half:	1,	Full:	2)

auto_neg
auto_neg: (one of 0, 1)
자동협상 (OFF:	0,	ON:	1)

useuse: (one of 0, 1)
사용 (OFF:	0,	ON:	1)

descdesc: (string - maxLength: 256)
설명

diffdiff: (array of any)

Example:
Example

{
		"speed":1,
		"duplex":1,
		"auto_neg":1,
		"use":1,
		"diff":[]
}

Response

HTTP status code 200

인터페이스 상태 설정 수정 성공

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
if_name
if_name: (string)
인터페이스 이름

modemode: (one of 1, 2)
L2 모드 (L2:	1,	L2	Bridge:	2)

speed
speed: (one of 1, 2, 3, 4, 5)
속도 (10M:	1,	100M:	2,	1G:	3,	10G:	4,	40G:	5)

duplex
duplex: (one of 1, 2)
Duplex (Half:	1,	Full:	2)

auto_neg
auto_neg: (one of 0, 1)
자동협상 (OFF:	0,	ON:	1)

useuse: (one of 0, 1)
사용 (OFF:	0,	ON:	1)

descdesc: (string - maxLength: 256)
설명

diffdiff: (array of any)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"if_name":"",
				"speed":1,
				"duplex":1,
				"auto_neg":1,
				"use":1
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

트렁크 인터페이스

GET

/vwi/{vs_id}/trunk-interfaces

트렁크 인터페이스 목록을 조회한다.

Request

URI Parameters

vs_id
vs_id: required (integer)
VS ID

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

트렁크 인터페이스 목록 조회 성공

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
result: required (array of trunk_interface)
Items: trunk_interface
Items

if_name
if_name: (string)
인터페이스 이름

modemode: (one of 1, 2, 3, 4)
밸런스 모드 (Round-Robin:	1,	XOR:	2,	Active-Backup:	3,	802.3ad:	4)

slave_if_name
slave_if_name: (array of any)
인터페이스 이름 목록

active_if_name
active_if_name: (string)
Active 인터페이스 이름

802_3ad_mode
802_3ad_mode: (one of 1, 2)
802.3ad 모드 (Fast:	1,	Slow:	2)

packet_dist
packet_dist: (one of 1, 2)
802.3ad 패킷 분배  (Layer:	0,	Layer	3/4:	1)

useuse: (one of 0, 1)
사용 (OFF:	0,	ON:	1)

vlanvlan: (string)
Vlan

descdesc: (string - maxLength: 256)
설명

diffdiff: (array of any)

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"if_name":"",
						"mode":1,
						"slave_if_name":[],
						"use":1,
						"vlan":"",
						"desc":""
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

POST

/vwi/{vs_id}/trunk-interfaces

트렁크 인터페이스를 추가한다.

Request

URI Parameters

vs_id
vs_id: required (integer)
VS ID

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

트렁크 인터페이스 추가 성공

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
if_name
if_name: (string)
인터페이스 이름

modemode: (one of 1, 2, 3, 4)
밸런스 모드 (Round-Robin:	1,	XOR:	2,	Active-Backup:	3,	802.3ad:	4)

slave_if_name
slave_if_name: (array of any)
인터페이스 이름 목록

active_if_name: (string)
active_if_name
Active 인터페이스 이름

802_3ad_mode
802_3ad_mode: (one of 1, 2)
802.3ad 모드 (Fast:	1,	Slow:	2)

packet_dist
packet_dist: (one of 1, 2)
802.3ad 패킷 분배  (Layer:	0,	Layer	3/4:	1)

useuse: (one of 0, 1)
사용 (OFF:	0,	ON:	1)

vlanvlan: (string)
Vlan

descdesc: (string - maxLength: 256)
설명

diffdiff: (array of any)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"if_name":"",
				"slave_if_name":[],
				"mode":1,
				"active_if_name":"",
				"802_3ad_mode":1,
				"packet_dist":1,
				"desc":""
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

GET

/vwi/{vs_id}/trunk-interfaces/candidates

트렁크 추가 가능 후보을(를) 조회한다.

Request

URI Parameters

vs_id: required (integer)
vs_id
VS ID

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

트렁크 추가 가능 후보 조회 성공

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
result: required (array of )
Example:
Example

{
		"code":	"ok",
		"result":	[
				"bond0","bond1"
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

/vwi/{vs_id}/trunk-interfaces/slaves

트렁크 인터페이스 Slave 목록을 조회한다.

Request

URI Parameters

vs_id
vs_id: required (integer)
VS ID

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

트렁크 인터페이스 Slave 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of )
result
Example:
Example

{
		"code":	"ok",
		"result":	[
				"bond0","bond1"
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

GET

/vwi/{vs_id}/trunk-interfaces/{if_name}

트렁크 인터페이스 기본 설정을(를) 조회한다.

Request

URI Parameters

vs_id
vs_id: required (integer)
VS ID

Example:
Example

1

if_name
if_name: required (string)
인터페이스 이름

Example:
Example

eth0

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

트렁크 인터페이스 기본 설정 조회 성공

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
if_name
if_name: (string)
인터페이스 이름

modemode: (one of 1, 2, 3, 4)
밸런스 모드 (Round-Robin:	1,	XOR:	2,	Active-Backup:	3,	802.3ad:	4)

slave_if_name
slave_if_name: (array of any)
인터페이스 이름 목록

active_if_name
active_if_name: (string)
Active 인터페이스 이름

802_3ad_mode: (one of 1, 2)
802_3ad_mode
802.3ad 모드 (Fast:	1,	Slow:	2)

packet_dist
packet_dist: (one of 1, 2)
802.3ad 패킷 분배  (Layer:	0,	Layer	3/4:	1)

useuse: (one of 0, 1)
사용 (OFF:	0,	ON:	1)

vlanvlan: (string)
Vlan

descdesc: (string - maxLength: 256)
설명

diffdiff: (array of any)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"if_name":"",
				"slave_if_name":[],
				"mode":1,
				"active_if_name":"",
				"802_3ad_mode":1,
				"packet_dist":1,
				"desc":""
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

/vwi/{vs_id}/trunk-interfaces/{if_name}

트렁크 인터페이스 기본 설정을(를) 수정한다.

Request

URI Parameters

vs_id
vs_id: required (integer)
VS ID

Example:
Example

1

if_name
if_name: required (string)
인터페이스 이름

Example:
Example

eth0

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

if_name
if_name: (string)
인터페이스 이름

modemode: (one of 1, 2, 3, 4)
밸런스 모드 (Round-Robin:	1,	XOR:	2,	Active-Backup:	3,	802.3ad:	4)

slave_if_name
slave_if_name: (array of any)
인터페이스 이름 목록

active_if_name
active_if_name: (string)
Active 인터페이스 이름

802_3ad_mode
802_3ad_mode: (one of 1, 2)
802.3ad 모드 (Fast:	1,	Slow:	2)

packet_dist: (one of 1, 2)
packet_dist

802.3ad 패킷 분배  (Layer:	0,	Layer	3/4:	1)

useuse: (one of 0, 1)
사용 (OFF:	0,	ON:	1)

vlanvlan: (string)
Vlan

descdesc: (string - maxLength: 256)
설명

diffdiff: (array of any)

Example:
Example

{
		"slave_if_name":[],
		"mode":1,
		"active_if_name":"",
		"802_3ad_mode":1,
		"packet_dist":1,
		"desc":"",
		"diff":[]
}

Response

HTTP status code 200

트렁크 인터페이스 기본 설정 수정 성공

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
if_name
if_name: (string)
인터페이스 이름

modemode: (one of 1, 2)
L2 모드 (L2:	1,	L2	Bridge:	2)

speed
speed: (one of 1, 2, 3, 4, 5)
속도 (10M:	1,	100M:	2,	1G:	3,	10G:	4,	40G:	5)

duplex
duplex: (one of 1, 2)
Duplex (Half:	1,	Full:	2)

auto_neg
auto_neg: (one of 0, 1)
자동협상 (OFF:	0,	ON:	1)

useuse: (one of 0, 1)
사용 (OFF:	0,	ON:	1)

descdesc: (string - maxLength: 256)
설명

diffdiff: (array of any)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"if_name":"",
				"slave_if_name":[],
				"mode":1,
				"active_if_name":"",
				"802_3ad_mode":1,
				"packet_dist":1,
				"desc":""
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

/vwi/{vs_id}/trunk-interfaces/{if_name}

트렁크 인터페이스 기본 설정을(를) 삭제한다.

Request

URI Parameters

vs_id
vs_id: required (integer)
VS ID

Example:
Example

1

if_name
if_name: required (string)
인터페이스 이름

Example:
Example

eth0

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

modelmodel: required (string)
모델

Example:
Example

{
		"model":""
}

Response

HTTP status code 200

트렁크 인터페이스 기본 설정 삭제 성공

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

GET

/vwi/{vs_id}/trunk-interfaces/{if_name}/advance

트렁크 인터페이스 고급 설정을(를) 조회한다.

Request

URI Parameters

vs_id: required (integer)
vs_id
VS ID

Example:
Example

1

if_name
if_name: required (string)
인터페이스 이름

Example:
Example

eth0

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

트렁크 인터페이스 고급 설정 조회 성공

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
if_name: (string)
if_name
인터페이스 이름

vid_type
vid_type: required (one of 1, 2)
VLAN 필터링 종류 (PVID:	1,	VID:	2)

pvidpvid: required (integer - minimum: 1 - maximum: 4094)
PVID

vidvid: required (string)
VID

diffdiff: (array of any)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"if_name":"",
				"vid_type":1,
				"pvid":1,
				"vid":""
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

/vwi/{vs_id}/trunk-interfaces/{if_name}/advance

트렁크 인터페이스 고급 설정을(를) 수정한다.

Request

URI Parameters

vs_id
vs_id: required (integer)
VS ID

Example:
Example

1

if_name
if_name: required (string)
인터페이스 이름

Example:
Example

eth0

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

if_name
if_name: (string)
인터페이스 이름

vid_type
vid_type: required (one of 1, 2)
VLAN 필터링 종류 (PVID:	1,	VID:	2)

pvidpvid: required (integer - minimum: 1 - maximum: 4094)
PVID

vidvid: required (string)
VID

diffdiff: (array of any)

Example:
Example

{
		"vid_type":1,
		"pvid":1,
		"vid":"",
		"diff":[]
}

Response

HTTP status code 200

트렁크 인터페이스 고급 설정 수정 성공

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
if_name
if_name: (string)
인터페이스 이름

vid_type
vid_type: required (one of 1, 2)
VLAN 필터링 종류 (PVID:	1,	VID:	2)

pvidpvid: required (integer - minimum: 1 - maximum: 4094)
PVID

vidvid: required (string)
VID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"if_name":"",
				"vid_type":1,
				"pvid":1,
				"vid":""
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

/vwi/{vs_id}/trunk-interfaces/{if_name}/status

트렁크 인터페이스 상태 설정을(를) 조회한다.

Request

URI Parameters

vs_id: required (integer)
vs_id
VS ID

Example:
Example

1

if_name: required (string)
if_name
인터페이스 이름

Example:
Example

eth0

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

트렁크 인터페이스 상태 설정 조회 성공

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
if_name
if_name: (string)
인터페이스 이름

modemode: (one of 1, 2, 3, 4)
밸런스 모드 (Round-Robin:	1,	XOR:	2,	Active-Backup:	3,	802.3ad:	4)

slave_if_name
slave_if_name: (array of any)
인터페이스 이름 목록

active_if_name
active_if_name: (string)
Active 인터페이스 이름

802_3ad_mode
802_3ad_mode: (one of 1, 2)
802.3ad 모드 (Fast:	1,	Slow:	2)

packet_dist: (one of 1, 2)
packet_dist
802.3ad 패킷 분배  (Layer:	0,	Layer	3/4:	1)

useuse: (one of 0, 1)
사용 (OFF:	0,	ON:	1)

vlanvlan: (string)
Vlan

descdesc: (string - maxLength: 256)
설명

diffdiff: (array of any)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"if_name":"",
				"use":1
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

/vwi/{vs_id}/trunk-interfaces/{if_name}/status

트렁크 인터페이스 상태 설정을(를) 수정한다.

Request

URI Parameters

vs_id
vs_id: required (integer)
VS ID

Example:
Example

1

if_name
if_name: required (string)
인터페이스 이름

Example:
Example

eth0

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

if_name
if_name: (string)
인터페이스 이름

modemode: (one of 1, 2, 3, 4)
밸런스 모드 (Round-Robin:	1,	XOR:	2,	Active-Backup:	3,	802.3ad:	4)

slave_if_name: (array of any)
slave_if_name
인터페이스 이름 목록

active_if_name
active_if_name: (string)
Active 인터페이스 이름

802_3ad_mode
802_3ad_mode: (one of 1, 2)
802.3ad 모드 (Fast:	1,	Slow:	2)

packet_dist
packet_dist: (one of 1, 2)
802.3ad 패킷 분배  (Layer:	0,	Layer	3/4:	1)

useuse: (one of 0, 1)
사용 (OFF:	0,	ON:	1)

vlanvlan: (string)
Vlan

descdesc: (string - maxLength: 256)
설명

diffdiff: (array of any)

Example:
Example

{
		"use":1,
		"diff":[]
}

Response

HTTP status code 200

트렁크 인터페이스 상태 설정 수정 성공

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
if_name
if_name: (string)
인터페이스 이름

modemode: (one of 1, 2, 3, 4)
밸런스 모드 (Round-Robin:	1,	XOR:	2,	Active-Backup:	3,	802.3ad:	4)

slave_if_name
slave_if_name: (array of any)
인터페이스 이름 목록

active_if_name: (string)
active_if_name
Active 인터페이스 이름

802_3ad_mode
802_3ad_mode: (one of 1, 2)
802.3ad 모드 (Fast:	1,	Slow:	2)

packet_dist
packet_dist: (one of 1, 2)
802.3ad 패킷 분배  (Layer:	0,	Layer	3/4:	1)

useuse: (one of 0, 1)
사용 (OFF:	0,	ON:	1)

vlanvlan: (string)
Vlan

descdesc: (string - maxLength: 256)
설명

diffdiff: (array of any)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"if_name":"",
				"use":1
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

