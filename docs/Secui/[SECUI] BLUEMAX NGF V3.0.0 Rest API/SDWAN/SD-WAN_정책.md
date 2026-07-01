GET

PUT

PUT

PUT

GET

POST

PUT

  DELETE

GET

PUT

  DELETE

PUT

PUT

SD-WAN 정책 REST API 문서

https://{host}/api/sw

host
host: required (string)
[IP]:[GUI 접속 PORT]
443	포트는	생략	가능

Example:
Example

192.168.100.100:443

기본 설정

/sdwan/4/default/config

적용/취소

/command/sdwan-4-default-config/apply

/command/sdwan-4-default-config/cancel

정책

/sdwan/4/rules

/sdwan/4/rules/{pk}

적용/취소

/command/sdwan-4-rules/apply

/command/sdwan-4-rules/cancel

기본 설정

GET

/sdwan/4/default/config

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
결과 데이터

check_interval
check_interval: required (integer - minimum: 1 - maximum: 600)
경로 검사 간격(ms)

failover
failover: required (integer - default: 5 - minimum: 1 - maximum: 1000)
실패 전환(회)

failback
failback: required (integer - default: 5 - minimum: 1 - maximum: 1000)
실패 복구(회)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"check_interval":	600,
				"failover":	5,
				"failback":	5
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

/sdwan/4/default/config

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

check_interval
check_interval: required (integer - minimum: 1 - maximum: 600)
경로 검사 간격(ms)

failover
failover: required (integer - default: 5 - minimum: 1 - maximum: 1000)
실패 전환(회)

failback: required (integer - default: 5 - minimum: 1 - maximum: 1000)
failback
실패 복구(회)

Example:
Example

{
		"check_interval":	600,
		"failover":	5,
		"failback":	5
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
code
code: required (string)
결과 코드

result
result: required (object)
결과 데이터

check_interval
check_interval: required (integer - minimum: 1 - maximum: 600)
경로 검사 간격(ms)

failover
failover: required (integer - default: 5 - minimum: 1 - maximum: 1000)
실패 전환(회)

failback
failback: required (integer - default: 5 - minimum: 1 - maximum: 1000)
실패 복구(회)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"check_interval":	600,
				"failover":	5,
				"failback":	5
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

적용/취소

PUT

/command/sdwan-4-default-config/apply

기본 설정을 적용합니다.

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

기본 설정 적용 성공

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

/command/sdwan-4-default-config/cancel

기본 설정을 취소합니다.

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

기본 설정 취소 성공

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

정책

GET

/sdwan/4/rules

정책 목록을 조회한다.

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

정책 목록 조회 성공

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
result: required (array of GetRule)
결과 데이터

Items: GetRule
Items

useuse: required (one of 0, 1)
사용 여부
0:	사용안함,	1:	사용

name
name: required (string - minLength: 1 - maxLength: 32)
정책 이름

lblb: required (integer)
LB 방식
0:	Priority,	1:	Session

failaction
failaction: required (integer)
실패 액션
0:	Drop,	1:	Bypass

loglog: required (integer)
로그
0:	사용안함,	1:	사용

desdes: (string - maxLength: 256)
설명

sdwan_policy_id: required (integer)
sdwan_policy_id
정책 ID

priority
priority: required (integer)
순번

center
center: required (array of AddressObject)
출발지 객체 목록

Items: AddressObject
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone: required (integer)
zone

Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

branch
branch: required (array of AddressObject)
목적지 객체 목록

Items: AddressObject
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

srvsrv: required (array of ServiceObject)
서비스 객체 목록

Items: ServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type: required (integer)
srv_obj_type
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2,	애플리케이션	포트:	3

name
name: required (string)
서비스 명

pre_def: required (integer)
pre_def
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

appapp: required (array of GetAppObject)
앱 객체 목록

Items: GetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

app_obj_type
app_obj_type: required (one of 1, 2, 3)
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

name
name: required (string)
애플리케이션 관련 객체 이름
app_obj_type가	1일	경우	객체	이름
app_obj_type가	2일	경우	그룹	객체	이름
app_obj_type가	3일	경우	필터	객체	이름

path_label
path_label: required (array of 경로 레이블)
경로 레이블 목록

Items: 경로 레이블
Items

path_label_id
path_label_id: required (integer)
경로 레이블 ID(PK)

name
name: required (string)
이름

cfg_adm_id: required (integer)
cfg_adm_id
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"sdwan_policy_id":	1,
						"priority":	1,
						"use":	1,
						"name":	"정책	이름1",
						"lb":	1,
						"failaction":	1,
						"log":	1,
						"cfg_layer":	1,
						"desc":	"설명",
						"center":	[
								{
										"addr_obj_id":	1,
										"name":	"네트워크	객체	이름1",
										"zone":	1,
										"desc":	"설명",
										"addr_obj_type":	2,
										"ip_info1":	"200.200.200.0",
										"ip_info2":	"24"
								}
						],
						"branch":	[
								{
										"addr_obj_id":	1,
										"name":	"네트워크	객체이름2",
										"zone":	2,
										"desc":	"설명",
										"addr_obj_type":	2,
										"ip_info1":	"100.100.100.0",
										"ip_info2":	"24"
								}
						],
						"srv":	[
								{
										"srv_obj_id":	1,
										"srv_obj_type":	1,
										"name":	"서비스	객체	이름",
										"pre_def":	1
								}
						],
						"app":	[
								{
										"app_obj_id":	1,
										"app_obj_type":	1,
										"name":	"앱객체	이름1"
								}
						],
						"path_label":	[
								{
										"path_label_id":	1,
										"name":	"경로	레이블	이름1"
								}
						]
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

/sdwan/4/rules

정책를 추가한다.

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
정책 이름

lblb: required (integer)
LB 방식
0:	Priority,	1:	Session

failaction: required (integer)
failaction
실패 액션
0:	Drop,	1:	Bypass

loglog: required (integer)
로그
0:	사용안함,	1:	사용

desdes: (string - maxLength: 256)
설명

center
center: required (array of SetAddrObject)
출발지 객체 목록

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID

addr_obj_type
addr_obj_type: (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4

Example:
Example

[{"addr_obj_id":	1,	"addr_obj_type":	1}]

branch
branch: required (array of SetAddrObject)
목적지 객체 목록

Items: SetAddrObject
Items

addr_obj_id: required (integer)
addr_obj_id
주소 객체 ID

addr_obj_type
addr_obj_type: (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4

Example:
Example

[{"addr_obj_id":	1,	"addr_obj_type":	1}]

srv_obj: required (array of SetServiceObject)
srv_obj
서비스 객체 목록

Items: SetServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID
-1:	애플리케이션	포트

Example:
Example

[{"srv_obj_id":	1}]

app_obj
app_obj: required (array of SetAppObject)
앱 객체 목록

Items: SetAppObject
Items

app_obj_id: required (integer)
app_obj_id
애플리케이션 객체 ID

app_obj_type
app_obj_type: required (one of 1, 2, 3)
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

Example:
Example

[{"app_obj_id":	30003,	"app_obj_type":	1}]

path_label
path_label: required (array of 경로 레이블)
경로 레이블 목록
16개까지 입력 가능

Items: 경로 레이블
Items

path_label_id
path_label_id: required (integer)
경로 레이블 ID(PK)

Example:
Example

[{"path_label_id":	1}]

Example:
Example

{
		"use":	1,
		"name":	"정책	이름	1",
		"lb":	1,
		"failaction":	1,
		"log":	1,
		"desc":	"설명",
		"center":	[
				{
						"addr_obj_id":	1,
						"addr_obj_type":	2
				}
		],
		"branch":	[
				{
						"addr_obj_id":	2,
						"addr_obj_type":	1
				}
		],
		"srv_obj":	[
				{
						"srv_obj_id":	1,
						"srv_obj_type":	1
				}
		],
		"app_obj":	[
				{
						"app_obj_id":	1,
						"app_obj_type":	1
				}
		],
		"path_label":	[
				{
						"path_label_id":	1
				}
		]
}

Response

HTTP status code 200

정책 추가 성공

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
정책 이름

lblb: required (integer)
LB 방식
0:	Priority,	1:	Session

failaction
failaction: required (integer)
실패 액션
0:	Drop,	1:	Bypass

loglog: required (integer)
로그
0:	사용안함,	1:	사용

desdes: (string - maxLength: 256)
설명

sdwan_policy_id
sdwan_policy_id: required (integer)
정책 ID

priority
priority: required (integer)
순번

center
center: required (array of AddressObject)
출발지 객체 목록

Items: AddressObject
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

branch
branch: required (array of AddressObject)
목적지 객체 목록

Items: AddressObject
Items

addr_obj_id: required (integer)
addr_obj_id
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

srvsrv: required (array of ServiceObject)
서비스 객체 목록

Items: ServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2,	애플리케이션	포트:	3

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

appapp: required (array of GetAppObject)
앱 객체 목록

Items: GetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

app_obj_type
app_obj_type: required (one of 1, 2, 3)
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

name
name: required (string)
애플리케이션 관련 객체 이름
app_obj_type가	1일	경우	객체	이름
app_obj_type가	2일	경우	그룹	객체	이름
app_obj_type가	3일	경우	필터	객체	이름

path_label
path_label: required (array of 경로 레이블)
경로 레이블 목록

Items: 경로 레이블
Items

path_label_id
path_label_id: required (integer)
경로 레이블 ID(PK)

name
name: required (string)
이름

cfg_adm_id: required (integer)
cfg_adm_id
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"sdwan_policy_id":	1,
						"priority":	1,
						"use":	1,
						"name":	"정책	이름1",
						"lb":	1,
						"failaction":	1,
						"log":	1,
						"cfg_layer":	1,
						"desc":	"설명",
						"center":	[
								{
										"addr_obj_id":	1,
										"name":	"네트워크	객체	이름1",
										"zone":	1,
										"desc":	"설명",
										"addr_obj_type":	2,
										"ip_info1":	"200.200.200.0",
										"ip_info2":	"24"
								}
						],
						"branch":	[
								{
										"addr_obj_id":	1,
										"name":	"네트워크	객체이름2",
										"zone":	2,
										"desc":	"설명",
										"addr_obj_type":	2,
										"ip_info1":	"100.100.100.0",
										"ip_info2":	"24"
								}
						],
						"srv":	[
								{
										"srv_obj_id":	1,
										"srv_obj_type":	1,
										"name":	"서비스	객체	이름",
										"pre_def":	1
								}
						],
						"app":	[
								{
										"app_obj_id":	1,
										"app_obj_type":	1,
										"name":	"앱객체	이름1"
								}
						],
						"path_label":	[
								{
										"path_label_id":	1,
										"name":	"경로	레이블	이름1"
								}
						]
				}
		]
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

PUT

/sdwan/4/rules

정책 목록을 (일괄)수정한다.

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
items
items: required (array of UpdateRule)
수정될 정보 목록

Items: UpdateRule
Items

sdwan_policy_id
sdwan_policy_id: required (integer)
정책 ID

useuse: required (one of 0, 1)
사용 여부
0:	사용안함,	1:	사용

Example:
Example

{
		"items":	[
				{"sdwan_policy_id":	1,	"use":	0},
				{"sdwan_policy_id":	2,	"use":	0}
		]
}

Response

HTTP status code 200

정책 목록 수정 성공

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

/sdwan/4/rules

정책 목록을 (일괄)삭제한다.

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
				{"sdwan_policy_id":	1},
				{"sdwan_policy_id":	2}
		]
}

Response

HTTP status code 200

정책 목록 삭제 성공

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

/sdwan/4/rules/{pk}

정책을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
정책 ID ( sdwan_policy_id )

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

정책 조회 성공

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
정책 이름

lblb: required (integer)
LB 방식
0:	Priority,	1:	Session

failaction: required (integer)
failaction
실패 액션
0:	Drop,	1:	Bypass

loglog: required (integer)
로그
0:	사용안함,	1:	사용

desdes: (string - maxLength: 256)
설명

sdwan_policy_id
sdwan_policy_id: required (integer)
정책 ID

priority: required (integer)
priority
순번

center
center: required (array of AddressObject)
출발지 객체 목록

Items: AddressObject
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

branch: required (array of AddressObject)
branch
목적지 객체 목록

Items: AddressObject
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver: required (integer)
ip_ver
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone: required (integer)
zone
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

srvsrv: required (array of ServiceObject)
서비스 객체 목록

Items: ServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2,	애플리케이션	포트:	3

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

appapp: required (array of GetAppObject)
앱 객체 목록

Items: GetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

app_obj_type
app_obj_type: required (one of 1, 2, 3)
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

name: required (string)
name
애플리케이션 관련 객체 이름
app_obj_type가	1일	경우	객체	이름
app_obj_type가	2일	경우	그룹	객체	이름
app_obj_type가	3일	경우	필터	객체	이름

path_label
path_label: required (array of 경로 레이블)
경로 레이블 목록

Items: 경로 레이블
Items

path_label_id
path_label_id: required (integer)
경로 레이블 ID(PK)

name
name: required (string)
이름

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"sdwan_policy_id":	1,
						"priority":	1,
						"use":	1,
						"name":	"정책	이름1",
						"lb":	1,
						"failaction":	1,
						"log":	1,
						"cfg_layer":	1,
						"desc":	"설명",
						"center":	[
								{
										"addr_obj_id":	1,
										"name":	"네트워크	객체	이름1",
										"zone":	1,
										"desc":	"설명",
										"addr_obj_type":	2,
										"ip_info1":	"200.200.200.0",
										"ip_info2":	"24"
								}
						],
						"branch":	[
								{
										"addr_obj_id":	1,
										"name":	"네트워크	객체이름2",
										"zone":	2,
										"desc":	"설명",
										"addr_obj_type":	2,
										"ip_info1":	"100.100.100.0",
										"ip_info2":	"24"
								}
						],
						"srv":	[
								{
										"srv_obj_id":	1,
										"srv_obj_type":	1,
										"name":	"서비스	객체	이름",
										"pre_def":	1
								}
						],
						"app":	[
								{
										"app_obj_id":	1,
										"app_obj_type":	1,
										"name":	"앱객체	이름1"
								}
						],
						"path_label":	[
								{
										"path_label_id":	1,
										"name":	"경로	레이블	이름1"
								}
						]
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

/sdwan/4/rules/{pk}

정책을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
정책 ID ( sdwan_policy_id )

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
0:	사용안함,	1:	사용

name
name: required (string - minLength: 1 - maxLength: 32)
정책 이름

lblb: required (integer)
LB 방식
0:	Priority,	1:	Session

failaction
failaction: required (integer)
실패 액션
0:	Drop,	1:	Bypass

loglog: required (integer)
로그
0:	사용안함,	1:	사용

desdes: (string - maxLength: 256)
설명

center
center: required (array of SetAddrObject)
출발지 객체 목록

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID

addr_obj_type
addr_obj_type: (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4

Example:
Example

[{"addr_obj_id":	1,	"addr_obj_type":	1}]

branch: required (array of SetAddrObject)
branch
목적지 객체 목록

Items: SetAddrObject
Items

addr_obj_id
addr_obj_id: required (integer)
주소 객체 ID

addr_obj_type
addr_obj_type: (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4

Example:
Example

[{"addr_obj_id":	1,	"addr_obj_type":	1}]

srv_obj
srv_obj: required (array of SetServiceObject)
서비스 객체 목록

Items: SetServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID
-1:	애플리케이션	포트

Example:
Example

[{"srv_obj_id":	1}]

app_obj
app_obj: required (array of SetAppObject)
앱 객체 목록

Items: SetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

app_obj_type
app_obj_type: required (one of 1, 2, 3)
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

Example:
Example

[{"app_obj_id":	30003,	"app_obj_type":	1}]

path_label
path_label: required (array of 경로 레이블)
경로 레이블 목록
16개까지 입력 가능

Items: 경로 레이블
Items

path_label_id
path_label_id: required (integer)
경로 레이블 ID(PK)

Example:
Example

[{"path_label_id":	1}]

pre_rule_id
pre_rule_id: (integer)
기준이 되는 정책 ID(이동 기능에서 사용)

up_down
up_down: (one of 0, 1)
기준이 되는 정책의 위/아래 위치 지정(이동 기능에서 사용)
위:	0,	아래:	1

Example:
Example

{
		"use":	1,
		"name":	"정책	이름	1",
		"lb":	1,
		"failaction":	1,
		"log":	1,
		"desc":	"설명",
		"center":	[
				{
						"addr_obj_id":	1,
						"addr_obj_type":	2,
				}
		],
		"branch":	[
				{
						"addr_obj_id":	2,
						"addr_obj_type":	1
				}
		],
		"srv":	[
				{
						"srv_obj_id":	1,
						"srv_obj_type":	1
				}
		],
		"app":	[
				{
						"app_obj_id":	1,
						"app_obj_type":	1
				}
		],
		"path_label":	[
				{
						"path_label_id":	1
				}
		]
}

Response

HTTP status code 200

정책 수정 성공

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
정책 이름

lblb: required (integer)
LB 방식
0:	Priority,	1:	Session

failaction
failaction: required (integer)
실패 액션
0:	Drop,	1:	Bypass

loglog: required (integer)
로그
0:	사용안함,	1:	사용

desdes: (string - maxLength: 256)
설명

sdwan_policy_id
sdwan_policy_id: required (integer)
정책 ID

priority
priority: required (integer)
순번

center
center: required (array of AddressObject)
출발지 객체 목록

Items: AddressObject
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

branch
branch: required (array of AddressObject)
목적지 객체 목록

Items: AddressObject
Items

addr_obj_id: required (integer)
addr_obj_id
객체 ID

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체명

zone
zone: required (integer)
Zone
(내부:	1,	외부:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
객체 타입
호스트객체:	1,	네트워크객체:	2(넷마스크)	or	3(범위),	그룹객체:	4

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

cloud_ref
cloud_ref: (one of 0, 1)
클라우드 객체 포함 여부 (그룹	객체에서	의미가	있는	속성)
0:	미포함,	1:	포함

srvsrv: required (array of ServiceObject)
서비스 객체 목록

Items: ServiceObject
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2,	애플리케이션	포트:	3

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

appapp: required (array of GetAppObject)
앱 객체 목록

Items: GetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

app_obj_type
app_obj_type: required (one of 1, 2, 3)
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

name
name: required (string)
애플리케이션 관련 객체 이름
app_obj_type가	1일	경우	객체	이름
app_obj_type가	2일	경우	그룹	객체	이름
app_obj_type가	3일	경우	필터	객체	이름

path_label
path_label: required (array of 경로 레이블)
경로 레이블 목록

Items: 경로 레이블
Items

path_label_id
path_label_id: required (integer)
경로 레이블 ID(PK)

name
name: required (string)
이름

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"sdwan_policy_id":	1,
						"priority":	1,
						"use":	1,
						"name":	"정책	이름1",
						"lb":	1,
						"failaction":	1,
						"log":	1,
						"cfg_layer":	1,
						"desc":	"설명",
						"center":	[
								{
										"addr_obj_id":	1,
										"name":	"네트워크	객체	이름1",
										"zone":	1,
										"desc":	"설명",
										"addr_obj_type":	2,
										"ip_info1":	"200.200.200.0",
										"ip_info2":	"24"
								}
						],
						"branch":	[
								{
										"addr_obj_id":	1,
										"name":	"네트워크	객체이름2",
										"zone":	2,
										"desc":	"설명",
										"addr_obj_type":	2,
										"ip_info1":	"100.100.100.0",
										"ip_info2":	"24"
								}
						],
						"srv":	[
								{
										"srv_obj_id":	1,
										"srv_obj_type":	1,
										"name":	"서비스	객체	이름",
										"pre_def":	1
								}
						],
						"app":	[
								{
										"app_obj_id":	1,
										"app_obj_type":	1,
										"name":	"앱객체	이름1"
								}
						],
						"path_label":	[
								{
										"path_label_id":	1,
										"name":	"경로	레이블	이름1"
								}
						]
				}
		]
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

/sdwan/4/rules/{pk}

정책을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
정책 ID ( sdwan_policy_id )

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

정책 삭제 성공

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

적용/취소

PUT

/command/sdwan-4-rules/apply

정책을 적용합니다.

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

정책 적용 성공

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

/command/sdwan-4-rules/cancel

정책을 취소합니다.

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

정책 취소 성공

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

