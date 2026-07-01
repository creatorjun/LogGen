GET

GET

POST

OT 정책 설정 REST API 문서

https://{host}/api/po

host
host: required (string)
[IP]:[GUI 접속 PORT]
443	포트는	생략	가능

Example:
Example

192.168.100.100:443

Claroty 수집 정책

/ot/collect/1/rules

/ot/collect/1/rules/{pk}/ref

OT 정책 자동 생성

/ot/fw/policy/rules

Claroty 수집 정책

GET

/ot/collect/1/rules

Claroty 수집 정책 목록을 조회한다.

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

Claroty 수집 정책 목록 조회 성공

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
result: required (array of OT 정책)
결과 데이터

Items: OT 정책
Items

ctd_id: required (integer)
ctd_id
OT 정책 ID

src_virtual_zone_id
src_virtual_zone_id: required (integer)
정책 자동 생성 시에 사용되는 출발지 ID

src_zone_name
src_zone_name: required (string)
출발지 이름

src_num_assets
src_num_assets: required (integer)
출발지 Assets 번호

dst_virtual_zone_id
dst_virtual_zone_id: required (integer)
정책 자동 생성 시에 사용되는 목적지 ID

dst_zone_name: required (string)
dst_zone_name
목적지 이름

dst_num_assets
dst_num_assets: required (integer)
목적지 Assets 번호

ot_action
ot_action: required (integer)
OT 동작 방식
0:	허용,	1:	차단

src_ip
src_ip: required (array of string)
출발지 IP 주소 목록

dst_ip
dst_ip: required (array of string)
목적지 IP 주소 목록

ports: required (array of string)
ports
OT 포트(서비스 포트) 목록

ot_protocol
ot_protocol: required (string)
OT 프로토콜

protocols
protocols: required (string)
정책 자동 생성시 사용되는 프로토콜 정보

prtc_obj_id
prtc_obj_id: required (integer)
프로토콜 ID

service_name
service_name: required (string)
서비스 이름

srv_cate_name: required (string)
srv_cate_name
서비스 유형 이름

srv_cate
srv_cate: required (integer)
서비스 유형 ID

policy_state
policy_state: required (integer)
변경 여부
0:	없음,	1:	추가,	2:	편집,	3:	삭제

last_modified
last_modified: required (string)
OT 정책이 마지막으로 업데이트된 시간
(GUI에서 사용되지 않음)

state
state: required (integer)
OT 정책 상태
(GUI에서 사용되지 않음)

useuse: required (one of 0, 1 - default: 0)
정책화 여부
정책	생성	안함:	0,	정책으로	생성:	1

creat_able: required (one of 0, 1)
creat_able
정책 생성 가능 여부
0:	생성	불가,	1:	생성	가능

type
type: required (integer)
수집 서버 타입
1:	Claroty

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"use":	0,
						"creat_able":	1,
						"ctd_id":	4,
						"src_virtual_zone_id":	90,
						"src_zone_name":	"Endpoint:	Other",
						"src_num_assets":	309,
						"dst_virtual_zone_id":	90,
						"dst_zone_name":	"Endpoint:	Other",
						"dst_num_assets":	309,
						"ot_action":	0,
						"src_ip":	[
								"1.1.1.1",
								"1.1.1.2"
						],
						"dst_ip":	[
								"2.2.2.1",
								"2.2.2.2"
						],
						"ot_protocol":	"TCP",
						"protocols":	"TCP",
						"prtc_obj_id":	4,
						"ports":	[
								"33000",
								"445"
						],
						"service_name":	"HTTP_",
						"srv_cate_name":	"HTTP",
						"srv_cate":	4,
						"policy_state":	0,
						"last_modified":	"2021-07-13	15:08:06",
						"state":	2,
						"type":	1
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

/ot/collect/1/rules/{pk}/ref

생성된 방화벽 정책 정보를 조회한다.

Request

URI Parameters

pkpk: required (integer)
OT 정책 ID(Claroty)

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

Claroty 수집 정책 참조 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of 방화벽 정책 정보)
result
결과 데이터

Items: 방화벽 정책 정보
Items

fw_set_id
fw_set_id: required (integer)
방화벽 세트 ID

fw_set_name
fw_set_name: required (string)
방화벽 세트 이름

fw_rule_id
fw_rule_id: required (integer)
정책 ID

fw_rule_name
fw_rule_name: required (string)
정책 이름

is_backup
is_backup: required (integer)
백업 여부
0:	백업	아님,	1:	백업

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"fw_set_id":	1,
						"fw_set_name":	"default",
						"fw_rule_id":	3,
						"fw_rule_name":	"fw_rule_1",
						"is_backup":	0
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

OT 정책 자동 생성

POST

/ot/fw/policy/rules

수집된 Claroty 정책을 방화벽 정책으로 자동 생성한다.

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

apply_action: required (one of 1, 2)
apply_action
정책 즉시 적용
1:	임시	저장
2:	즉시	저장

policy_info
policy_info: required (array of 정책 생성 정보)
생성할 정책/객체 정보

Items: 정책 생성 정보
Items

ctd_id
ctd_id: required (integer)
OT 정책 ID

src_zone: required (integer)
src_zone
출발지 Zone
1:	내부망,	2:	외부망,	3:	DMZ

src_virtual_zone_id
src_virtual_zone_id: required (integer)
OT 정책에서  src_virtual_zone_id  속성 값

dst_zone: required (integer)
dst_zone

목적지 Zone
1:	내부망,	2:	외부망,	3:	DMZ

dst_virtual_zone_id
dst_virtual_zone_id: required (integer)
OT 정책에서  dst_virtual_zone_id  속성 값

service_name
service_name: required (string)
서비스 이름

Example:
Example

SIP

protocol
protocol: required (string)
프로토콜 이름

Example:
Example

TCP

service_type
service_type: (integer)
서비스 객체 타입(1로 고정)

srv_cate_name
srv_cate_name: required (string)
서비스 유형 이름

src_port: required (string)
src_port
출발지 포트(서비스 객체 참고)

dst_port
dst_port: required (string)
서비스 포트(서비스 객체 참고)

action
action: required (integer)
방화벽 정책 동작 방식
1:	허용,	2:	차단

Example:
Example

{
		"type":	1,
		"apply_action":	2,
		"policy_info":	[
				{
						"ctd_id":	4,
						"src_zone":	1,
						"src_virtual_zone_id":	309,
						"src_zone_name":	"Endpoint:	Other",
						"dst_zone":	1,
						"dst_virtual_zone_id":	309,
						"dst_zone_name":	"Endpoint:	Other",
						"protocol":	"TCP",
						"service_name":	"SIP",
						"service_type":	1,
						"srv_cate_name":	"HTTP",
						"src_port":	"*",
						"dst_port":	"234-235,333,4000-4001",
						"action":	1
				}
		]
}

Response

HTTP status code 200

OT 정책 자동 생성 추가 성공

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

fw_set_id
fw_set_id: required (integer)
방화벽 세트 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"fw_set_id":	1
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

