GET

POST

PUT

  DELETE

GET

PUT

  DELETE

PUT

PUT

IPv6 원격 사용자 등록 REST API 문서

https://{url}/api/vp

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/vp

IPv6 원격 사용자 등록

/ipsec/6/remote-users

/ipsec/6/remote-users/{pk}

IPv6 원격 사용자 등록 적용/취소

/command/ipsec-ipv6-remote-users/apply

/command/ipsec-ipv6-remote-users/cancel

IPv6 원격 사용자 등록

GET

/ipsec/6/remote-users

IPv6 원격 사용자 등록 목록을 조회한다.

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

IPv6 원격 사용자 등록 목록 조회 성공

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
result: required (array of ResIpsecRemoteUser)
결과 데이터

Items: ResIpsecRemoteUser
Items

ip_pool_addr_obj_id: required (object)
ip_pool_addr_obj_id
원격 사용자 IP 할당의 IP Pool

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

ip_info2: required (string)
ip_info2
IP 정보2

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

usr_id: required (string)
usr_id
사용자 아이디

lftmlftm: required (integer - default: 80000 - minimum: 60 - maximum: 500000)
생명 주기

ike_lftm
ike_lftm: required (integer - default: 160000 - minimum: 120 - maximum: 1000000)
IKE 생명 주기

gwgw: required (string)
IKEv2 원격 게이트웨이 주소

local_auth_type
local_auth_type: required (one of 0, 1 - default: 0)
IKEv2 로컬 인증 유형
사전	공유키:	0,	RSA	인증서:	1

remote_auth_type: required (one of 0, 1, 2, 3, 4, 5 - default: 0)
remote_auth_type
IKEv2 원격 인증 유형
사전	공유키:	0,	RSA	인증서:	1,	EAP-MD5:	2,	EAP-RADIUS:	3,	EAP-MSCHAPv2:	4,	XAUTH-PSK:	5

ip_type
ip_type: required (one of 0, 1 - default: 0)
원격 사용자 IP할당
IP	pool:	0,	고정	ip:	1

ipip: required (string)
고정 IP 할당

access_policy
access_policy: required (array of AddrObject)
접근 정책 리스트

Items: AddrObject
Items

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

dnsdns: required (string)
DNS 서버 설정

descdesc: required (string)
설명

block
block: required (one of 0, 1 - default: 0)
차단 여부
허용:	0,	차단:	1

vpn_remote_usr_id
vpn_remote_usr_id: required (integer)
원격 사용자 등록 아이디

ip_ver
ip_ver: required (one of 1, 2 - default: 2)
유형
IPv4:	1,	IPv6:	2

login_dt
login_dt: required (string)
로그인 시간

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"vpn_remote_usr_id":	1,
				"ip_pool_addr_obj_id":	{
						"addr_obj_id":	8,
						"name":	"IP_EXT_RANGE_V6",
						"zone":	2,
						"desc":	"",
						"addr_obj_type":	3,
						"ip_info1":	"2001::1",
						"ip_info2":	"2001::10"
				},
				"ip_ver":	2,
				"use":	0,
				"usr_id":	"사용자	ID	1",
				"lftm":	80000,
				"ike_lftm":	160000,
				"gw":	"::",
				"local_auth_type":	0,
				"remote_auth_type":	0,
				"ip_type":	0,
				"ip":	"1001::1",
				"access_policy":	[{
						"addr_obj_id":	4,
						"name":	"Any_INT6",
						"zone":	1,
						"desc":	"",
						"addr_obj_type":	2,
						"ip_info1":	"::",
						"ip_info2":	"0"
				}],
				"dns":	"1::1",
				"desc":	"설명",
				"block":	0,
				"login_dt":	"2017-10-10	15:36:45"
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

/ipsec/6/remote-users

IPv6 원격 사용자 등록를 추가한다.

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

Properties
Properties

ip_pool_addr_obj_id: required (object)
ip_pool_addr_obj_id
addr_obj_id
addr_obj_id: required (integer)
객체 아이디

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

usr_id
usr_id: required (string)
사용자 아이디

lftmlftm: required (integer - default: 80000 - minimum: 60 - maximum: 500000)
생명 주기

ike_lftm
ike_lftm: required (integer - default: 160000 - minimum: 120 - maximum: 1000000)
IKE 생명 주기

gwgw: required (string)
IKEv2 원격 게이트웨이 주소

local_auth_type
local_auth_type: required (one of 0, 1 - default: 0)
IKEv2 로컬 인증 유형
사전	공유키:	0,	RSA	인증서:	1

remote_auth_type: required (one of 0, 1, 2, 3, 4, 5 - default: 0)
remote_auth_type
IKEv2 원격 인증 유형
사전	공유키:	0,	RSA	인증서:	1,	EAP-MD5:	2,	EAP-RADIUS:	3,	EAP-MSCHAPv2:	4,	XAUTH-PSK:	5

passwd
passwd: required (string)
인증 비밀번호(Base64 인코딩)

ip_type: required (one of 0, 1 - default: 0)
ip_type
원격 사용자 IP할당
IP	pool:	0,	고정	ip:	1

ipip: required (string)
고정 IP 할당

access_policy
access_policy: required (array of items)
Items: items
Items

addr_obj_id
addr_obj_id: required (integer)
객체 아이디

dnsdns: required (string)
DNS 서버 설정

descdesc: required (string)
설명

block: required (one of 0, 1 - default: 0)
block
차단 여부
허용:	0,	차단:	1

Example:
Example

{
		"ip_pool_addr_obj_id":	{
				"addr_obj_id":	8
		},
		"use":	0,
		"usr_id":	"사용자	ID	1",
		"lftm":	80000,
		"ike_lftm":	160000,
		"gw":	"::",
		"local_auth_type":	0,
		"remote_auth_type":	0,
		"passwd":	"x2xAyWkwMEAh",
		"ip_type":	0,
		"ip":	"1001::1",
		"access_policy":	[{
				"addr_obj_id":	4
		}],
		"dns":	"1::1",
		"desc":	"설명",
		"block":	0
}

Response

HTTP status code 200

IPv6 원격 사용자 등록 추가 성공

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

ip_pool_addr_obj_id
ip_pool_addr_obj_id: required (object)
원격 사용자 IP 할당의 IP Pool

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

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

usr_id
usr_id: required (string)
사용자 아이디

lftmlftm: required (integer - default: 80000 - minimum: 60 - maximum: 500000)
생명 주기

ike_lftm: required (integer - default: 160000 - minimum: 120 - maximum: 1000000)
ike_lftm
IKE 생명 주기

gwgw: required (string)
IKEv2 원격 게이트웨이 주소

local_auth_type
local_auth_type: required (one of 0, 1 - default: 0)
IKEv2 로컬 인증 유형
사전	공유키:	0,	RSA	인증서:	1

remote_auth_type
remote_auth_type: required (one of 0, 1, 2, 3, 4, 5 - default: 0)
IKEv2 원격 인증 유형
사전	공유키:	0,	RSA	인증서:	1,	EAP-MD5:	2,	EAP-RADIUS:	3,	EAP-MSCHAPv2:	4,	XAUTH-PSK:	5

ip_type: required (one of 0, 1 - default: 0)
ip_type
원격 사용자 IP할당
IP	pool:	0,	고정	ip:	1

ipip: required (string)
고정 IP 할당

access_policy: required (array of AddrObject)
access_policy
접근 정책 리스트

Items: AddrObject
Items

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

dnsdns: required (string)
DNS 서버 설정

descdesc: required (string)
설명

block: required (one of 0, 1 - default: 0)
block
차단 여부
허용:	0,	차단:	1

vpn_remote_usr_id
vpn_remote_usr_id: required (integer)
원격 사용자 등록 아이디

ip_ver
ip_ver: required (one of 1, 2 - default: 2)
유형
IPv4:	1,	IPv6:	2

login_dt
login_dt: required (string)
로그인 시간

Example:
Example

{
		"code":	"ok",
		"result":	{
				"vpn_remote_usr_id":	1,
				"ip_pool_addr_obj_id":	{
						"addr_obj_id":	8,
						"name":	"IP_EXT_RANGE_V6",
						"zone":	2,
						"desc":	"",
						"addr_obj_type":	3,
						"ip_info1":	"2001::1",
						"ip_info2":	"2001::10"
				},
				"ip_ver":	2,
				"use":	0,
				"usr_id":	"사용자	ID	1",
				"lftm":	80000,
				"ike_lftm":	160000,
				"gw":	"::",
				"local_auth_type":	0,
				"remote_auth_type":	0,
				"ip_type":	0,
				"ip":	"1001::1",
				"access_policy":	[{
						"addr_obj_id":	4,
						"name":	"Any_INT6",
						"zone":	1,
						"desc":	"",
						"addr_obj_type":	2,
						"ip_info1":	"::",
						"ip_info2":	"0"
				}],
				"dns":	"1::1",
				"desc":	"설명",
				"block":	0,
				"login_dt":	"2017-10-10	15:36:45"
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

PUT

/ipsec/6/remote-users

IPv6 원격 사용자 등록 목록을 (일괄)수정한다.

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
items: required (array of ReqIpsecRemoteUserList)
수정 아이템 목록

Items: ReqIpsecRemoteUserList
Items

vpn_remote_usr_id: required (integer)
vpn_remote_usr_id

원격 사용자 등록 아이디

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

Example:
Example

{
		"items":	[
				{"vpn_remote_usr_id":	1,	"use":	1}
		]
}

Response

HTTP status code 200

IPv6 원격 사용자 등록 목록 수정 성공

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

/ipsec/6/remote-users

IPv6 원격 사용자 등록 목록을 (일괄)삭제한다.

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
삭제 아이템 목록

Example:
Example

{
		"items":	[
				{"vpn_remote_usr_id":	1},
				{"vpn_remote_usr_id":	2}
		]
}

Response

HTTP status code 200

IPv6 원격 사용자 등록 목록 삭제 성공

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

/ipsec/6/remote-users/{pk}

IPv6 원격 사용자 등록을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
원격 사용자 등록 아이디 ( vpn_remote_usr_id )

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

IPv6 원격 사용자 등록 조회 성공

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

ip_pool_addr_obj_id
ip_pool_addr_obj_id: required (object)
원격 사용자 IP 할당의 IP Pool

addr_obj_id: required (integer)
addr_obj_id
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

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

usr_id
usr_id: required (string)
사용자 아이디

lftmlftm: required (integer - default: 80000 - minimum: 60 - maximum: 500000)
생명 주기

ike_lftm
ike_lftm: required (integer - default: 160000 - minimum: 120 - maximum: 1000000)
IKE 생명 주기

gwgw: required (string)
IKEv2 원격 게이트웨이 주소

local_auth_type: required (one of 0, 1 - default: 0)
local_auth_type
IKEv2 로컬 인증 유형
사전	공유키:	0,	RSA	인증서:	1

remote_auth_type
remote_auth_type: required (one of 0, 1, 2, 3, 4, 5 - default: 0)
IKEv2 원격 인증 유형
사전	공유키:	0,	RSA	인증서:	1,	EAP-MD5:	2,	EAP-RADIUS:	3,	EAP-MSCHAPv2:	4,	XAUTH-PSK:	5

ip_type
ip_type: required (one of 0, 1 - default: 0)
원격 사용자 IP할당
IP	pool:	0,	고정	ip:	1

ipip: required (string)
고정 IP 할당

access_policy
access_policy: required (array of AddrObject)
접근 정책 리스트

Items: AddrObject
Items

addr_obj_id: required (integer)
addr_obj_id
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

dnsdns: required (string)
DNS 서버 설정

descdesc: required (string)
설명

block: required (one of 0, 1 - default: 0)
block
차단 여부
허용:	0,	차단:	1

vpn_remote_usr_id
vpn_remote_usr_id: required (integer)
원격 사용자 등록 아이디

ip_ver: required (one of 1, 2 - default: 2)
ip_ver
유형
IPv4:	1,	IPv6:	2

login_dt
login_dt: required (string)
로그인 시간

Example:
Example

{
		"code":	"ok",
		"result":	{
				"vpn_remote_usr_id":	1,
				"ip_pool_addr_obj_id":	{
						"addr_obj_id":	8,
						"name":	"IP_EXT_RANGE_V6",
						"zone":	2,
						"desc":	"",
						"addr_obj_type":	3,
						"ip_info1":	"2001::1",
						"ip_info2":	"2001::10"
				},
				"ip_ver":	2,
				"use":	0,
				"usr_id":	"사용자	ID	1",
				"lftm":	80000,
				"ike_lftm":	160000,
				"gw":	"::",
				"local_auth_type":	0,
				"remote_auth_type":	0,
				"ip_type":	0,
				"ip":	"1001::1",
				"access_policy":	[{
						"addr_obj_id":	4,
						"name":	"Any_INT6",
						"zone":	1,
						"desc":	"",
						"addr_obj_type":	2,
						"ip_info1":	"::",
						"ip_info2":	"0"
				}],
				"dns":	"1::1",
				"desc":	"설명",
				"block":	0,
				"login_dt":	"2017-10-10	15:36:45"
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

/ipsec/6/remote-users/{pk}

IPv6 원격 사용자 등록을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
원격 사용자 등록 아이디 ( vpn_remote_usr_id )

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

ip_pool_addr_obj_id: required (object)
ip_pool_addr_obj_id
addr_obj_id
addr_obj_id: required (integer)
객체 아이디

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

usr_id
usr_id: required (string)
사용자 아이디

lftmlftm: required (integer - default: 80000 - minimum: 60 - maximum: 500000)
생명 주기

ike_lftm
ike_lftm: required (integer - default: 160000 - minimum: 120 - maximum: 1000000)
IKE 생명 주기

gwgw: required (string)
IKEv2 원격 게이트웨이 주소

local_auth_type
local_auth_type: required (one of 0, 1 - default: 0)
IKEv2 로컬 인증 유형
사전	공유키:	0,	RSA	인증서:	1

remote_auth_type
remote_auth_type: required (one of 0, 1, 2, 3, 4, 5 - default: 0)
IKEv2 원격 인증 유형
사전	공유키:	0,	RSA	인증서:	1,	EAP-MD5:	2,	EAP-RADIUS:	3,	EAP-MSCHAPv2:	4,	XAUTH-PSK:	5

passwd
passwd: required (string)
인증 비밀번호(Base64 인코딩)

ip_type
ip_type: required (one of 0, 1 - default: 0)
원격 사용자 IP할당
IP	pool:	0,	고정	ip:	1

ipip: required (string)
고정 IP 할당

access_policy
access_policy: required (array of items)
Items: items
Items

addr_obj_id
addr_obj_id: required (integer)
객체 아이디

dnsdns: required (string)
DNS 서버 설정

descdesc: required (string)
설명

block
block: required (one of 0, 1 - default: 0)
차단 여부
허용:	0,	차단:	1

Example:
Example

{
		"ip_pool_addr_obj_id":	{
				"addr_obj_id":	8
		},
		"use":	1,
		"usr_id":	"사용자	ID	2",
		"lftm":	500000,
		"ike_lftm":	1000000,
		"gw":	"1001::1",
		"local_auth_type":	1,
		"remote_auth_type":	1,
		"passwd":	"x2xAyWkwMEAh",
		"ip_type":	1,
		"ip":	"1001::2",
		"access_policy":	[{
				"addr_obj_id":	4
		}],
		"dns":	"1::2",
		"desc":	"설명	2",
		"block":	1
}

Response

HTTP status code 200

IPv6 원격 사용자 등록 수정 성공

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

ip_pool_addr_obj_id
ip_pool_addr_obj_id: required (object)
원격 사용자 IP 할당의 IP Pool

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

useuse: required (one of 0, 1 - default: 0)
사용 여부
사용안함:	0,	사용:	1

usr_id
usr_id: required (string)
사용자 아이디

lftmlftm: required (integer - default: 80000 - minimum: 60 - maximum: 500000)
생명 주기

ike_lftm
ike_lftm: required (integer - default: 160000 - minimum: 120 - maximum: 1000000)
IKE 생명 주기

gwgw: required (string)
IKEv2 원격 게이트웨이 주소

local_auth_type
local_auth_type: required (one of 0, 1 - default: 0)
IKEv2 로컬 인증 유형
사전	공유키:	0,	RSA	인증서:	1

remote_auth_type
remote_auth_type: required (one of 0, 1, 2, 3, 4, 5 - default: 0)
IKEv2 원격 인증 유형
사전	공유키:	0,	RSA	인증서:	1,	EAP-MD5:	2,	EAP-RADIUS:	3,	EAP-MSCHAPv2:	4,	XAUTH-PSK:	5

ip_type
ip_type: required (one of 0, 1 - default: 0)
원격 사용자 IP할당
IP	pool:	0,	고정	ip:	1

ipip: required (string)

고정 IP 할당

access_policy
access_policy: required (array of AddrObject)
접근 정책 리스트

Items: AddrObject
Items

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

ip_info2: required (string)
ip_info2
IP 정보2

dnsdns: required (string)
DNS 서버 설정

descdesc: required (string)
설명

block
block: required (one of 0, 1 - default: 0)
차단 여부
허용:	0,	차단:	1

vpn_remote_usr_id: required (integer)
vpn_remote_usr_id
원격 사용자 등록 아이디

ip_ver
ip_ver: required (one of 1, 2 - default: 2)
유형
IPv4:	1,	IPv6:	2

login_dt
login_dt: required (string)
로그인 시간

Example:
Example

{
		"code":	"ok",
		"result":	{
				"vpn_remote_usr_id":	1,
				"ip_pool_addr_obj_id":	{
						"addr_obj_id":	8,
						"name":	"IP_EXT_RANGE_V6",
						"zone":	2,
						"desc":	"",
						"addr_obj_type":	3,
						"ip_info1":	"2001::1",
						"ip_info2":	"2001::10"
				},
				"ip_ver":	2,
				"use":	1,
				"usr_id":	"사용자	ID	2",
				"lftm":	500000,
				"ike_lftm":	1000000,
				"gw":	"1001::1",
				"local_auth_type":	1,
				"remote_auth_type":	1,
				"ip_type":	1,
				"ip":	"1001::2",
				"access_policy":	[{
						"addr_obj_id":	4,
						"name":	"Any_INT6",
						"zone":	1,
						"desc":	"",
						"addr_obj_type":	2,
						"ip_info1":	"::",
						"ip_info2":	"0"
				}],
				"dns":	"1::2",
				"desc":	"설명	2",
				"block":	1,
				"login_dt":	"2017-10-10	15:36:45"
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

DELETE

/ipsec/6/remote-users/{pk}

IPv6 원격 사용자 등록을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
원격 사용자 등록 아이디 ( vpn_remote_usr_id )

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

IPv6 원격 사용자 등록 삭제 성공

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

IPv6 원격 사용자 등록 적용/취소

PUT

/command/ipsec-ipv6-remote-users/apply

IPv6 원격 사용자 등록을 적용합니다.

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

IPv6 원격 사용자 등록 적용 성공

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

/command/ipsec-ipv6-remote-users/cancel

IPv6 원격 사용자 등록을 취소합니다.

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

IPv6 원격 사용자 등록 취소 성공

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

