GET

POST

PUT

  DELETE

GET

PUT

  DELETE

GET

GET

PUT

PUT

SD-WAN 터널 REST API 문서

https://{host}/api/sw

host
host: required (string)
[IP]:[GUI 접속 PORT]
443	포트는	생략	가능

Example:
Example

192.168.100.100:443

터널 설정

/sdwan/tunnel/settings

/sdwan/tunnel/settings/{pk}

인증 알고리즘

/sdwan/tunnel/auth-algr

암호 알고리즘

/sdwan/tunnel/crypto-algr

적용/취소

/command/sdwan-tunnel-settings/apply

/command/sdwan-tunnel-settings/cancel

터널 설정

GET

/sdwan/tunnel/settings

터널 설정 목록을 조회한다.

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

터널 설정 목록 조회 성공

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
result: required (array of 터널)
결과 데이터

Items: 터널
Items

useuse: required (one of 0, 1)
사용 여부
0:	사용안함,	1:	사용

name: required (string - minLength: 1 - maxLength: 32)
name
터널 이름

type
type: required (one of 0, 1, 2)
타입
0:	Initiator,	1:	Responder,	2:	Peer

sdwan_tunnel_group_id
sdwan_tunnel_group_id: required (integer - minimum: 1 - maximum: 250)
그룹 ID(1 ~ 250)

local_gateway
local_gateway: required (string)
로컬 게이트웨이(IPv4 주소)

local_tunnel_ip
local_tunnel_ip: required (string)
로컬 장비 터널 IP(IPv4 주소)

remote_gateway: required (string)
remote_gateway
리모트 게이트웨이(IPv4 주소)

remote_tunnel_ip
remote_tunnel_ip: required (string)
리모트 장비 터널 IP(IPv4 주소)

path_label_id
path_label_id: required (integer)
경로 레이블 ID

sdwan_auth_algr_id
sdwan_auth_algr_id: required (integer)
인증 알고리즘 ID
[GET] /api/sdwan/tunnel/auth-algr 요청 결과를 사용

sdwan_crypto_algr_id
sdwan_crypto_algr_id: required (integer)
암호 알고리즘 ID
[GET] /sdwan/tunnel/crypto-algr 요청 결과를 사용

descdesc: required (string - minLength: 0 - maxLength: 128)
설명

sdwan_tunnel_id
sdwan_tunnel_id: required (string)
터널 ID(PK)

cfg_layer: required (one of 0, 1)
cfg_layer
TAMS 연동을 위한 속성
0:	NGF	데이터,	1:	TAMS	연동	데이터

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"sdwan_tunnel_id":	"터널#1",
						"use":	1,
						"name":	"TunnelName",
						"type":	1,
						"sdwan_tunnel_group_id":	250,
						"local_gateway":	"192.168.175.100",
						"local_tunnel_ip":	"192.168.175.200",
						"remote_gateway":	"192.168.175.300",
						"remote_tunnel_ip":	"192.168.175.400",
						"path_label_id":	1,
						"sdwan_auth_algr_id":	1,
						"sdwan_crypto_algr_id":	1,
						"desc":	"설명",
						"cfg_layer":	0
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

/sdwan/tunnel/settings

터널 설정를 추가한다.

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

useuse: required (one of 0, 1)
사용 여부
0:	사용안함,	1:	사용

name: required (string - minLength: 1 - maxLength: 32)
name
터널 이름

type
type: required (one of 0, 1, 2)
타입
0:	Initiator,	1:	Responder,	2:	Peer

sdwan_tunnel_group_id: required (integer - minimum: 1 - maximum: 250)
sdwan_tunnel_group_id
그룹 ID(1 ~ 250)

local_gateway
local_gateway: required (string)
로컬 게이트웨이(IPv4 주소)

local_tunnel_ip
local_tunnel_ip: required (string)
로컬 장비 터널 IP(IPv4 주소)

remote_gateway
remote_gateway: required (string)
리모트 게이트웨이(IPv4 주소)

remote_tunnel_ip
remote_tunnel_ip: required (string)
리모트 장비 터널 IP(IPv4 주소)

path_label_id
path_label_id: required (integer)
경로 레이블 ID

sdwan_auth_algr_id
sdwan_auth_algr_id: required (integer)
인증 알고리즘 ID
[GET] /api/sdwan/tunnel/auth-algr 요청 결과를 사용

sdwan_crypto_algr_id
sdwan_crypto_algr_id: required (integer)
암호 알고리즘 ID
[GET] /sdwan/tunnel/crypto-algr 요청 결과를 사용

descdesc: required (string - minLength: 0 - maxLength: 128)
설명

password
password: required (string - maxLength: 32)
인증 비밀번호(Base64 인코딩)

Example:
Example

{
		"use":	1,
		"name":	"TunnelName",
		"type":	1,
		"sdwan_tunnel_group_id":	250,
		"local_gateway":	"192.168.175.100",
		"local_tunnel_ip":	"192.168.175.200",
		"remote_gateway":	"192.168.175.300",
		"remote_tunnel_ip":	"192.168.175.400",
		"path_label_id":	1,
		"sdwan_auth_algr_id":	1,
		"sdwan_crypto_algr_id":	1,
		"desc":	"설명"
}

Response

HTTP status code 200

터널 설정 추가 성공

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

useuse: required (one of 0, 1)
사용 여부
0:	사용안함,	1:	사용

name: required (string - minLength: 1 - maxLength: 32)
name
터널 이름

type
type: required (one of 0, 1, 2)
타입
0:	Initiator,	1:	Responder,	2:	Peer

sdwan_tunnel_group_id: required (integer - minimum: 1 - maximum: 250)
sdwan_tunnel_group_id
그룹 ID(1 ~ 250)

local_gateway
local_gateway: required (string)
로컬 게이트웨이(IPv4 주소)

local_tunnel_ip
local_tunnel_ip: required (string)
로컬 장비 터널 IP(IPv4 주소)

remote_gateway
remote_gateway: required (string)
리모트 게이트웨이(IPv4 주소)

remote_tunnel_ip
remote_tunnel_ip: required (string)
리모트 장비 터널 IP(IPv4 주소)

path_label_id: required (integer)
path_label_id
경로 레이블 ID

sdwan_auth_algr_id
sdwan_auth_algr_id: required (integer)
인증 알고리즘 ID
[GET] /api/sdwan/tunnel/auth-algr 요청 결과를 사용

sdwan_crypto_algr_id
sdwan_crypto_algr_id: required (integer)
암호 알고리즘 ID
[GET] /sdwan/tunnel/crypto-algr 요청 결과를 사용

descdesc: required (string - minLength: 0 - maxLength: 128)
설명

sdwan_tunnel_id
sdwan_tunnel_id: required (string)
터널 ID(PK)

cfg_layer
cfg_layer: required (one of 0, 1)
TAMS 연동을 위한 속성
0:	NGF	데이터,	1:	TAMS	연동	데이터

Example:
Example

{
		"code":	"ok",
		"result":	{
				"sdwan_tunnel_id":	"터널#1",
				"use":	1,
				"name":	"TunnelName",
				"type":	1,
				"sdwan_tunnel_group_id":	250,
				"local_gateway":	"192.168.175.100",
				"local_tunnel_ip":	"192.168.175.200",
				"remote_gateway":	"192.168.175.300",
				"remote_tunnel_ip":	"192.168.175.400",
				"path_label_id":	1,
				"sdwan_auth_algr_id":	1,
				"sdwan_crypto_algr_id":	1,
				"desc":	"설명",
				"cfg_layer":	0
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

PUT

/sdwan/tunnel/settings

터널 설정 목록을 (일괄)수정한다.

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
items: required (array of 터널)
수정될 정보 목록

Items: 터널
Items

sdwan_tunnel_id
sdwan_tunnel_id: required (string)
터널 ID(PK)

useuse: required (one of 0, 1)
사용 여부
0:	사용안함,	1:	사용

Example:
Example

{
		"items":	[
				{"sdwan_tunnel_id":	"터널#1",	"use":	0},
				{"sdwan_tunnel_id":	"터널#2",	"use":	0}
		]
}

Response

HTTP status code 200

터널 설정 목록 수정 성공

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

DELETE

/sdwan/tunnel/settings

터널 설정 목록을 (일괄)삭제한다.

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
items: required (array of object)
items
삭제 아이템 목록

Example:
Example

{
		"items":	[
				{"sdwan_tunnel_id":	"터널#1"},
				{"sdwan_tunnel_id":	"터널#2"}
		]
}

Response

HTTP status code 200

터널 설정 목록 삭제 성공

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

/sdwan/tunnel/settings/{pk}

터널 설정을(를) 조회한다.

Request

URI Parameters

pkpk: required (string)
터널 ID ( sdwan_tunnel_id )  요청	시	URI	인코딩	처리가	필요

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

터널 설정 조회 성공

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
0:	사용안함,	1:	사용

name
name: required (string - minLength: 1 - maxLength: 32)
터널 이름

type
type: required (one of 0, 1, 2)
타입
0:	Initiator,	1:	Responder,	2:	Peer

sdwan_tunnel_group_id
sdwan_tunnel_group_id: required (integer - minimum: 1 - maximum: 250)
그룹 ID(1 ~ 250)

local_gateway
local_gateway: required (string)
로컬 게이트웨이(IPv4 주소)

local_tunnel_ip: required (string)
local_tunnel_ip
로컬 장비 터널 IP(IPv4 주소)

remote_gateway
remote_gateway: required (string)
리모트 게이트웨이(IPv4 주소)

remote_tunnel_ip
remote_tunnel_ip: required (string)
리모트 장비 터널 IP(IPv4 주소)

path_label_id
path_label_id: required (integer)
경로 레이블 ID

sdwan_auth_algr_id
sdwan_auth_algr_id: required (integer)
인증 알고리즘 ID
[GET] /api/sdwan/tunnel/auth-algr 요청 결과를 사용

sdwan_crypto_algr_id
sdwan_crypto_algr_id: required (integer)
암호 알고리즘 ID
[GET] /sdwan/tunnel/crypto-algr 요청 결과를 사용

descdesc: required (string - minLength: 0 - maxLength: 128)
설명

sdwan_tunnel_id
sdwan_tunnel_id: required (string)
터널 ID(PK)

cfg_layer
cfg_layer: required (one of 0, 1)
TAMS 연동을 위한 속성
0:	NGF	데이터,	1:	TAMS	연동	데이터

Example:
Example

{
		"code":	"ok",
		"result":	{
				"sdwan_tunnel_id":	"터널#1",
				"use":	1,
				"name":	"TunnelName",
				"type":	1,
				"sdwan_tunnel_group_id":	250,
				"local_gateway":	"192.168.175.100",
				"local_tunnel_ip":	"192.168.175.200",
				"remote_gateway":	"192.168.175.300",
				"remote_tunnel_ip":	"192.168.175.400",
				"path_label_id":	1,
				"sdwan_auth_algr_id":	1,
				"sdwan_crypto_algr_id":	1,
				"desc":	"설명",
				"cfg_layer":	0
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

/sdwan/tunnel/settings/{pk}

터널 설정을(를) 수정한다.

Request

URI Parameters

pkpk: required (string)
터널 ID ( sdwan_tunnel_id )  요청	시	URI	인코딩	처리가	필요

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

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties

useuse: required (one of 0, 1)
사용 여부
0:	사용안함,	1:	사용

name: required (string - minLength: 1 - maxLength: 32)
name
터널 이름

type
type: required (one of 0, 1, 2)
타입
0:	Initiator,	1:	Responder,	2:	Peer

sdwan_tunnel_group_id: required (integer - minimum: 1 - maximum: 250)
sdwan_tunnel_group_id
그룹 ID(1 ~ 250)

local_gateway
local_gateway: required (string)
로컬 게이트웨이(IPv4 주소)

local_tunnel_ip
local_tunnel_ip: required (string)
로컬 장비 터널 IP(IPv4 주소)

remote_gateway
remote_gateway: required (string)
리모트 게이트웨이(IPv4 주소)

remote_tunnel_ip
remote_tunnel_ip: required (string)
리모트 장비 터널 IP(IPv4 주소)

path_label_id
path_label_id: required (integer)
경로 레이블 ID

sdwan_auth_algr_id
sdwan_auth_algr_id: required (integer)
인증 알고리즘 ID
[GET] /api/sdwan/tunnel/auth-algr 요청 결과를 사용

sdwan_crypto_algr_id
sdwan_crypto_algr_id: required (integer)
암호 알고리즘 ID
[GET] /sdwan/tunnel/crypto-algr 요청 결과를 사용

descdesc: required (string - minLength: 0 - maxLength: 128)
설명

password
password: required (string - maxLength: 32)
인증 비밀번호(Base64 인코딩)

Example:
Example

{
		"use":	1,
		"name":	"TunnelName",
		"type":	1,
		"sdwan_tunnel_group_id":	250,
		"local_gateway":	"192.168.175.100",
		"local_tunnel_ip":	"192.168.175.200",
		"remote_gateway":	"192.168.175.300",
		"remote_tunnel_ip":	"192.168.175.400",
		"path_label_id":	1,
		"sdwan_auth_algr_id":	1,
		"sdwan_crypto_algr_id":	1,
		"password":	"c2VjdWkwMEAh",
		"desc":	"설명"
}

Response

HTTP status code 200

터널 설정 수정 성공

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
0:	사용안함,	1:	사용

name: required (string - minLength: 1 - maxLength: 32)
name

터널 이름

type
type: required (one of 0, 1, 2)
타입
0:	Initiator,	1:	Responder,	2:	Peer

sdwan_tunnel_group_id
sdwan_tunnel_group_id: required (integer - minimum: 1 - maximum: 250)
그룹 ID(1 ~ 250)

local_gateway
local_gateway: required (string)
로컬 게이트웨이(IPv4 주소)

local_tunnel_ip
local_tunnel_ip: required (string)
로컬 장비 터널 IP(IPv4 주소)

remote_gateway
remote_gateway: required (string)
리모트 게이트웨이(IPv4 주소)

remote_tunnel_ip: required (string)
remote_tunnel_ip
리모트 장비 터널 IP(IPv4 주소)

path_label_id
path_label_id: required (integer)
경로 레이블 ID

sdwan_auth_algr_id
sdwan_auth_algr_id: required (integer)
인증 알고리즘 ID
[GET] /api/sdwan/tunnel/auth-algr 요청 결과를 사용

sdwan_crypto_algr_id
sdwan_crypto_algr_id: required (integer)
암호 알고리즘 ID
[GET] /sdwan/tunnel/crypto-algr 요청 결과를 사용

descdesc: required (string - minLength: 0 - maxLength: 128)
설명

sdwan_tunnel_id
sdwan_tunnel_id: required (string)
터널 ID(PK)

cfg_layer
cfg_layer: required (one of 0, 1)
TAMS 연동을 위한 속성
0:	NGF	데이터,	1:	TAMS	연동	데이터

Example:
Example

{
		"code":	"ok",
		"result":	{
				"sdwan_tunnel_id":	"터널#1",
				"use":	1,
				"name":	"TunnelName",
				"type":	1,
				"sdwan_tunnel_group_id":	250,
				"local_gateway":	"192.168.175.100",
				"local_tunnel_ip":	"192.168.175.200",
				"remote_gateway":	"192.168.175.300",
				"remote_tunnel_ip":	"192.168.175.400",
				"path_label_id":	1,
				"sdwan_auth_algr_id":	1,
				"sdwan_crypto_algr_id":	1
				"desc":	"설명",
				"cfg_layer":	0
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

DELETE

/sdwan/tunnel/settings/{pk}

터널 설정을(를) 삭제한다.

Request

URI Parameters

pkpk: required (string)
터널 ID ( sdwan_tunnel_id )  요청	시	URI	인코딩	처리가	필요

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

터널 설정 삭제 성공

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

인증 알고리즘

GET

/sdwan/tunnel/auth-algr

인증 알고리즘 목록을 조회한다.

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

Response

HTTP status code 200

인증 알고리즘 목록 조회 성공

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
result: required (array of AuthAlgr)
결과 데이터

Items: AuthAlgr
Items

idid: required (integer)
ID

name
name: required (string)
이름

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"id":	1,
						"name":	"SHA-256"
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

암호 알고리즘

GET

/sdwan/tunnel/crypto-algr

암호 알고리즘 목록을 조회한다.

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

암호 알고리즘 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of CryptoAlgr)
result
결과 데이터

Items: CryptoAlgr
Items

idid: required (integer)
ID

name
name: required (string)
이름

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"id":	1,
						"name":	"AES-128"
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

적용/취소

PUT

/command/sdwan-tunnel-settings/apply

터널을 적용합니다.

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

Body

Media type: application/json
Media type

TypeType: object

Example:
Example

{}

Response

HTTP status code 200

터널 적용 성공

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

/command/sdwan-tunnel-settings/cancel

터널을 취소합니다.

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

터널 취소 성공

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

