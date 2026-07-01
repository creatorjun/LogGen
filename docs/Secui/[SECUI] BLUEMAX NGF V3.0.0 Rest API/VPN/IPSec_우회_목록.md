GET

POST

PUT

  DELETE

GET

PUT

  DELETE

PUT

PUT

IPSec 우회 목록 REST API 문서

https://{url}/api/vp

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/vp

IPSec 우회 목록

/ipsec/4/bypasses

/ipsec/4/bypasses/{pk}

IPSec 우회 목록 적용/취소

/command/ipsec-ipv4-bypasses/apply

/command/ipsec-ipv4-bypasses/cancel

IPSec 우회 목록

GET

/ipsec/4/bypasses

IPSec 우회 목록 목록을 조회한다.

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

IPSec 우회 목록 목록 조회 성공

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
result: required (array of ResIpsecBypass)
결과 데이터

Items: ResIpsecBypass
Items

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

idid: required (string)
ID

src_dst
src_dst: required (array of items)
Items: items
Items

srcsrc: required (object)
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

ip_info1
ip_info1: required (string)
IP 정보1

ip_info2
ip_info2: required (string)
IP 정보2

dstdst: required (object)
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

ip_info1: required (string)
ip_info1
IP 정보1

ip_info2
ip_info2: required (string)
IP 정보2

vpn_bypass_obj_id: required (integer)
vpn_bypass_obj_id
우회목록 아이디

ip_ver
ip_ver: required (one of 1, 2)
유형
IPv4:	1,	IPv6:	2

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"vpn_bypass_obj_id":	1,
				"ip_ver":	1,
				"use":	0,
				"id":	"우회목록	아이디	1",
				"src_dst":	[{
						"src":	{
								"addr_obj_id":	1,
								"name":	"Any_INT",
								"zone":	1,
								"desc":	"",
								"addr_obj_type":	2,
								"ip_info1":	"0.0.0.0",
								"ip_info2":	"0"
						},
						"dst":	{
								"addr_obj_id":	2,
								"name":	"Any_EXT",
								"zone":	2,
								"desc":	"",
								"addr_obj_type":	2,
								"ip_info1":	"0.0.0.0",
								"ip_info2":	"0"
						}
				}]
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

/ipsec/4/bypasses

IPSec 우회 목록를 추가한다.

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

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

idid: required (string)
ID

src_dst
src_dst: required (array of items)
Items: items
Items

srcsrc: required (object)
addr_obj_id
addr_obj_id: required (integer)
객체 아이디

dstdst: required (object)
addr_obj_id: required (integer)
addr_obj_id

객체 아이디

Example:
Example

{
		"use":	0,
		"id":	"우회목록	아이디	1",
		"src_dst":	[{
				"src":	{
						"addr_obj_id":	1
				},
				"dst":	{
						"addr_obj_id":	2
				}
		}]
}

Response

HTTP status code 200

IPSec 우회 목록 추가 성공

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

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

idid: required (string)
ID

src_dst: required (array of items)
src_dst
Items: items
Items

srcsrc: required (object)
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

ip_info1
ip_info1: required (string)
IP 정보1

ip_info2
ip_info2: required (string)
IP 정보2

dstdst: required (object)
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

ip_info1: required (string)
ip_info1
IP 정보1

ip_info2
ip_info2: required (string)
IP 정보2

vpn_bypass_obj_id: required (integer)
vpn_bypass_obj_id
우회목록 아이디

ip_ver
ip_ver: required (one of 1, 2)
유형
IPv4:	1,	IPv6:	2

Example:
Example

{
		"code":	"ok",
		"result":	{
				"vpn_bypass_obj_id":	1,
				"ip_ver":	1,
				"use":	0,
				"id":	"우회목록	아이디	1",
				"src_dst":	[{
						"src":	{
								"addr_obj_id":	1,
								"name":	"Any_INT",
								"zone":	1,
								"desc":	"",
								"addr_obj_type":	2,
								"ip_info1":	"0.0.0.0",
								"ip_info2":	"0"
						},
						"dst":	{
								"addr_obj_id":	2,
								"name":	"Any_EXT",
								"zone":	2,
								"desc":	"",
								"addr_obj_type":	2,
								"ip_info1":	"0.0.0.0",
								"ip_info2":	"0"
						}
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

PUT

/ipsec/4/bypasses

IPSec 우회 목록 목록을 (일괄)수정한다.

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
items: required (array of ReqIpsecBypassList)
items
수정 아이템 목록

Items: ReqIpsecBypassList
Items

vpn_bypass_obj_id
vpn_bypass_obj_id: required (integer)
우회목록 아이디

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

Example:
Example

{
		"items":	[
				{"vpn_bypass_obj_id":	1,	"use":	1}
		]
}

Response

HTTP status code 200

IPSec 우회 목록 목록 수정 성공

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

DELETE

/ipsec/4/bypasses

IPSec 우회 목록 목록을 (일괄)삭제한다.

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

Example:
Example

{
		"items":	[
				{"vpn_bypass_obj_id":	1},
				{"vpn_bypass_obj_id":	2}
		]
}

Response

HTTP status code 200

IPSec 우회 목록 목록 삭제 성공

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

/ipsec/4/bypasses/{pk}

IPSec 우회 목록을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
우회목록 아이디 ( vpn_bypass_obj_id )

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

IPSec 우회 목록 조회 성공

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

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

idid: required (string)
ID

src_dst
src_dst: required (array of items)
Items: items
Items

srcsrc: required (object)
addr_obj_id
addr_obj_id: required (integer)
객체 아이디

name
name: required (string)
객체 이름

zone: required (one of 1, 2, 3)
zone
Zone 정보
내부:	1,	외부:	2,	DMZ:	3

descdesc: required (string)
설명

addr_obj_type: required (one of 1, 2, 3, 4)
addr_obj_type
객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3,	그룹객체:	4

ip_info1
ip_info1: required (string)
IP 정보1

ip_info2
ip_info2: required (string)
IP 정보2

dstdst: required (object)
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

vpn_bypass_obj_id
vpn_bypass_obj_id: required (integer)
우회목록 아이디

ip_ver
ip_ver: required (one of 1, 2)
유형
IPv4:	1,	IPv6:	2

Example:
Example

{
		"code":	"ok",
		"result":	{
				"vpn_bypass_obj_id":	1,
				"ip_ver":	1,
				"use":	0,
				"id":	"우회목록	아이디	1",
				"src_dst":	[{
						"src":	{
								"addr_obj_id":	1,
								"name":	"Any_INT",
								"zone":	1,
								"desc":	"",
								"addr_obj_type":	2,
								"ip_info1":	"0.0.0.0",
								"ip_info2":	"0"
						},
						"dst":	{
								"addr_obj_id":	2,
								"name":	"Any_EXT",
								"zone":	2,
								"desc":	"",
								"addr_obj_type":	2,
								"ip_info1":	"0.0.0.0",
								"ip_info2":	"0"
						}
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

/ipsec/4/bypasses/{pk}

IPSec 우회 목록을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)

우회목록 아이디 ( vpn_bypass_obj_id )

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

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

idid: required (string)
ID

src_dst
src_dst: required (array of items)
Items: items
Items

srcsrc: required (object)
addr_obj_id
addr_obj_id: required (integer)
객체 아이디

dstdst: required (object)
addr_obj_id: required (integer)
addr_obj_id
객체 아이디

Example:
Example

{
		"use":	1,
		"id":	"우회목록	아이디	2",
		"src_dst":	[{
				"src":	{
						"addr_obj_id":	1
				},
				"dst":	{
						"addr_obj_id":	2
				}
		}]
}

Response

HTTP status code 200

IPSec 우회 목록 수정 성공

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

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

idid: required (string)
ID

src_dst
src_dst: required (array of items)
Items: items
Items

srcsrc: required (object)
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

dstdst: required (object)
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

vpn_bypass_obj_id
vpn_bypass_obj_id: required (integer)
우회목록 아이디

ip_ver
ip_ver: required (one of 1, 2)
유형
IPv4:	1,	IPv6:	2

Example:
Example

{
		"code":	"ok",
		"result":	{
				"vpn_bypass_obj_id":	1,
				"ip_ver":	1,
				"use":	1,
				"id":	"우회목록	아이디	2",
				"src_dst":	[{
						"src":	{
								"addr_obj_id":	1,
								"name":	"Any_INT",
								"zone":	1,
								"desc":	"",
								"addr_obj_type":	2,
								"ip_info1":	"0.0.0.0",
								"ip_info2":	"0"
						},
						"dst":	{
								"addr_obj_id":	2,
								"name":	"Any_EXT",
								"zone":	2,
								"desc":	"",
								"addr_obj_type":	2,
								"ip_info1":	"0.0.0.0",
								"ip_info2":	"0"
						}
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

/ipsec/4/bypasses/{pk}

IPSec 우회 목록을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
우회목록 아이디 ( vpn_bypass_obj_id )

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

IPSec 우회 목록 삭제 성공

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

IPSec 우회 목록 적용/취소

PUT

/command/ipsec-ipv4-bypasses/apply

IPSec 우회 목록을 적용합니다.

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

IPSec 우회 목록 적용 성공

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

/command/ipsec-ipv4-bypasses/cancel

IPSec 우회 목록을 취소합니다.

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

IPSec 우회 목록 취소 성공

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

