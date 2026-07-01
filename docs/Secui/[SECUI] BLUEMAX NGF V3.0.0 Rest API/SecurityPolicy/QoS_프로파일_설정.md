QoS 프로파일 설정 REST API 문서

https://{url}/api/po

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/po

QoS 프로파일 설정

/qos/all/profiles

/qos/profiles

/qos/profiles/{pk}

/qos/profiles/{pk}/copy

/qos/profiles/{pk}/interfaces

QoS 부모 큐

/qos/profiles/{ppk}/parent/queues

QoS 큐

/qos/profiles/{ppk}/queues

/qos/profiles/{ppk}/queues/{pk}

/qos/profiles/{ppk}/queues/{pk}/create/bandwidth

/qos/profiles/{ppk}/queues/{pk}/update/bandwidth

방화벽 QoS 프로파일

/qos/profiles/{pid}/fw/{version}/sets/{sid}/rules

방화벽 QoS 프로파일

/qos/profiles/{pid}/fw/sets/{sid}/rules

/qos/profiles/{pid}/fw/sets/{sid}/rules/{rid}

큐에 설정된 방화벽 세트 목록

/qos/profiles/{pid}/queues/{qid}/fw/sets

/qos/profiles/{pid}/queues/{qid}/fw/sets/{sid}/rules

사용자 QoS 프로파일

/qos/profiles/{pid}/users

/qos/profiles/{pid}/users/{uid}

큐에 설정된 사용자 목록

/qos/profiles/{pid}/queues/{qid}/users

애플리케이션 QoS 프로파일

/qos/profiles/{pid}/apps

/qos/profiles/{pid}/apps/{aid}

큐에 설정된 애플리케이션 목록

/qos/profiles/{pid}/queues/{qid}/apps

GET

GET

GET

POST

  DELETE

PUT

  DELETE

POST

GET

GET

GET

POST

GET

PUT

  DELETE

GET

GET

GET

PUT

  DELETE

PUT

  DELETE

GET

GET

GET

PUT

  DELETE

PUT

  DELETE

GET

GET

PUT

  DELETE

PUT

  DELETE

GET

웹 카테고리 QoS 프로파일

/qos/profiles/{pid}/webcategories

/qos/profiles/{pid}/webcategories/{wid}

큐에 설정된 웹 카테고리 객체 목록

GET

PUT

  DELETE

PUT

  DELETE

/qos/profiles/{pid}/queues/{qid}/webcategories

GET

GET

PUT

  DELETE

PUT

  DELETE

POST

  DELETE

DELETE

GET

PUT

PUT

VLAN QoS 프로파일

/qos/profiles/{pid}/vlans

/qos/profiles/{pid}/vlans/{vid}

VLAN 목록

/qos/profiles/{pid}/vlan/numbers

/qos/profiles/{pid}/vlan/numbers/{vid}

큐에 설정된 VLAN 목록

/qos/profiles/{pid}/queues/{qid}/vlans

QoS 프로파일 적용/취소

/command/qos-profiles/apply

/command/qos-profiles/cancel

QoS 프로파일 설정

GET

/qos/all/profiles

(GUI 호출 전용) NGF와 TAMS에서 생성된 QoS 프로파일 목록을 조회한다.

아래 기능에서 사용된다.

QoS 프로파일 설정
QoS 분석

Request

Annotations

SupportedVersion:
SupportedVersion

"4단계	스쿨넷"

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

QoS 프로파일 목록 조회 성공

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
result: required (array of QosGetProfileList)
결과 데이터

Items: QosGetProfileList
Items

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
프로파일 설명

qos_prf_type
qos_prf_type: required (one of 1, 2, 3, 4, 5)
프로파일 타입
1:	방화벽
2:	사용자
3:	애플리케이션
4:	웹	카테고리(2.0부터	지원)
5:	VLAN(4단계	스쿨넷부터	지원)

ceilceil: required (integer - minimum: 1000 - maximum: 100000000)
송신 제한 대역폭(Kbps)

qos_prf_id
qos_prf_id: required (integer)
QoS 프로파일 ID(PK)

ifc_ref
ifc_ref: required (one of 0, 1)
인터페이스 정책 사용여부
사용안함:	0,	사용:	1

SupportedVersion:	2.0.0

cfg_layer
cfg_layer: required (integer)
TAMS 연동을 위한 속성

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"qos_prf_id":	1,
				"qos_prf_type":	1,
				"ceil"	:	100000000,
				"auto_rate":	2,
				"name":	"프로파일이름",
				"desc":	"프로파일설명",
				"ifc_ref":	1,
				"cfg_layer":	0
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

GET

/qos/profiles

QoS 프로파일 목록을 조회한다.

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

QoS 프로파일 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of QosGetProfileList)
result
결과 데이터

Items: QosGetProfileList
Items

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
프로파일 설명

qos_prf_type
qos_prf_type: required (one of 1, 2, 3, 4, 5)
프로파일 타입
1:	방화벽
2:	사용자

3:	애플리케이션
4:	웹	카테고리(2.0부터	지원)
5:	VLAN(4단계	스쿨넷부터	지원)

ceilceil: required (integer - minimum: 1000 - maximum: 100000000)
송신 제한 대역폭(Kbps)

qos_prf_id
qos_prf_id: required (integer)
QoS 프로파일 ID(PK)

ifc_ref
ifc_ref: required (one of 0, 1)
인터페이스 정책 사용여부
사용안함:	0,	사용:	1

SupportedVersion:	2.0.0

cfg_layer
cfg_layer: required (integer)
TAMS 연동을 위한 속성

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"qos_prf_id":	1,
				"qos_prf_type":	1,
				"ceil"	:	100000000,
				"auto_rate":	2,
				"name":	"프로파일이름",
				"desc":	"프로파일설명",
				"ifc_ref":	1,
				"cfg_layer":	0
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

/qos/profiles

QoS 프로파일를 추가한다.

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
name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
프로파일 설명

qos_prf_type
qos_prf_type: required (one of 1, 2, 3, 4, 5)
프로파일 타입
1:	방화벽
2:	사용자
3:	애플리케이션
4:	웹	카테고리(2.0부터	지원)
5:	VLAN(4단계	스쿨넷부터	지원)

ceilceil: required (integer - minimum: 1000 - maximum: 100000000)
송신 제한 대역폭(Kbps)

auto_rate: required (integer - default: 1)
auto_rate
제한 전용 여부
OFF:	1,	ON:	2

Example:
Example

{
		"qos_prf_type":	1,
		"ceil"	:	100000000,
		"name":	"New	프로파일	이름",
		"desc":	"New	프로파일	설명",
		"auto_rate":	2
}

Response

HTTP status code 200

QoS 프로파일 추가 성공

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

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
프로파일 설명

qos_prf_type
qos_prf_type: required (one of 1, 2, 3, 4, 5)
프로파일 타입
1:	방화벽
2:	사용자
3:	애플리케이션
4:	웹	카테고리(2.0부터	지원)
5:	VLAN(4단계	스쿨넷부터	지원)

ceilceil: required (integer - minimum: 1000 - maximum: 100000000)
송신 제한 대역폭(Kbps)

auto_rate
auto_rate: required (integer - default: 1)
제한 전용 여부
OFF:	1,	ON:	2

qos_prf_id: required (integer)
qos_prf_id
QoS 프로파일 ID(PK)

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm: required (string)
cfg_adm

관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

Example:
Example

{
		"code":	"ok",
		"result":	{
				"qos_prf_id":	2,
				"qos_prf_type":	1,
				"ceil"	:	100000000,
				"name":	"New	프로파일	이름",
				"desc":	"New	프로파일	설명",
				"auto_rate":	2,
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-08	12:23:23"
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

/qos/profiles

QoS 프로파일 목록을 (일괄)삭제한다.

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
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"qos_prf_id":	1},
				{"qos_prf_id":	2}
		]
}

Response

HTTP status code 200

QoS 프로파일 목록 삭제 성공

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

GET

/qos/profiles/{pk}

QoS 프로파일을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
QoS 프로파일 ID( qos_prf_id )

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

QoS 프로파일 조회 성공

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

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
프로파일 설명

qos_prf_type
qos_prf_type: required (one of 1, 2, 3, 4, 5)
프로파일 타입
1:	방화벽
2:	사용자
3:	애플리케이션
4:	웹	카테고리(2.0부터	지원)
5:	VLAN(4단계	스쿨넷부터	지원)

ceilceil: required (integer - minimum: 1000 - maximum: 100000000)
송신 제한 대역폭(Kbps)

auto_rate
auto_rate: required (integer - default: 1)
제한 전용 여부
OFF:	1,	ON:	2

qos_prf_id
qos_prf_id: required (integer)
QoS 프로파일 ID(PK)

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt: required (string)
cfg_dt
수정 날짜

Example:
Example

{
		"code":	"ok",
		"result":	{
				"qos_prf_id":	1,
				"qos_prf_type":	1,
				"ceil"	:	100000000,
				"name":	"프로파일이름",
				"desc":	"프로파일설명",
				"auto_rate":	2,
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-08	12:23:23"
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

/qos/profiles/{pk}

QoS 프로파일을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
QoS 프로파일 ID( qos_prf_id )

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
name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
프로파일 설명

qos_prf_type
qos_prf_type: required (one of 1, 2, 3, 4, 5)
프로파일 타입
1:	방화벽
2:	사용자
3:	애플리케이션
4:	웹	카테고리(2.0부터	지원)
5:	VLAN(4단계	스쿨넷부터	지원)

ceilceil: required (integer - minimum: 1000 - maximum: 100000000)
송신 제한 대역폭(Kbps)

auto_rate
auto_rate: required (integer - default: 1)
제한 전용 여부
OFF:	1,	ON:	2

Example:
Example

{
		"qos_prf_type":	1,
		"ceil"	:	100000000,
		"name":	"프로파일	이름",
		"desc":	"프로파일	설명",
		"auto_rate":	2
}

Response

HTTP status code 200

QoS 프로파일 수정 성공

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

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
프로파일 설명

qos_prf_type: required (one of 1, 2, 3, 4, 5)
qos_prf_type
프로파일 타입
1:	방화벽
2:	사용자
3:	애플리케이션
4:	웹	카테고리(2.0부터	지원)
5:	VLAN(4단계	스쿨넷부터	지원)

ceilceil: required (integer - minimum: 1000 - maximum: 100000000)
송신 제한 대역폭(Kbps)

auto_rate
auto_rate: required (integer - default: 1)
제한 전용 여부
OFF:	1,	ON:	2

qos_prf_id
qos_prf_id: required (integer)
QoS 프로파일 ID(PK)

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
		"result":	{
				"qos_prf_id":	1,
				"qos_prf_type":	1,
				"ceil"	:	100000000,
				"name":	"프로파일	이름",
				"desc":	"프로파일	설명",
				"auto_rate":	2,
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-08	12:23:23"
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

DELETE

/qos/profiles/{pk}

QoS 프로파일을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
QoS 프로파일 ID( qos_prf_id )

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

Response

HTTP status code 200

QoS 프로파일 삭제 성공

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

dev_t: (string)
dev_t
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

POST

/qos/profiles/{pk}/copy

프로파일을 복사한다.

Request

URI Parameters

pkpk: required (integer)
QoS 프로파일 ID( qos_prf_id )

Annotations

SupportedVersion:
SupportedVersion

"2.5"

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
name
name: required (string - minLength: 1 - maxLength: 32)
새로운 프로파일 이름

descdesc: (string - maxLength: 128)
설명

Example:
Example

{
		"name":	"New	프로파일	이름",
		"desc":	"New	프로파일	설명"
}

Response

HTTP status code 200

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

name: required (string - minLength: 1 - maxLength: 32)
name
프로파일 이름

descdesc: (string - maxLength: 128)
프로파일 설명

qos_prf_type
qos_prf_type: required (one of 1, 2, 3, 4, 5)
프로파일 타입
1:	방화벽
2:	사용자
3:	애플리케이션
4:	웹	카테고리(2.0부터	지원)
5:	VLAN(4단계	스쿨넷부터	지원)

ceilceil: required (integer - minimum: 1000 - maximum: 100000000)
송신 제한 대역폭(Kbps)

auto_rate
auto_rate: required (integer - default: 1)
제한 전용 여부
OFF:	1,	ON:	2

qos_prf_id: required (integer)
qos_prf_id
QoS 프로파일 ID(PK)

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
		"result":	{
				"qos_prf_id":	2,
				"qos_prf_type":	1,
				"ceil":	100000000,
				"name":	"New	프로파일	이름",
				"auto_rate":	2,
				"desc":	"New	프로파일	설명",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2020-11-12	22:17:44"
		}
}

GET

/qos/profiles/{pk}/interfaces

QoS 프로파일을 사용 중인 인터페이스 목록을 조회한다.

Request

URI Parameters

pkpk: required (integer)
QoS 프로파일 ID( qos_prf_id )

Annotations

SupportedVersion:
SupportedVersion

"2.0"

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
result: required (array of GetMemberInterface)
결과 데이터

Items: GetMemberInterface
Items

hostname
hostname: required (string)
장비명

host_uuid
host_uuid: required (string)
장비 고유ID

ifc_id: required (integer)
ifc_id
인터페이스 ID

ifc_name
ifc_name: required (string)
인터페이스명

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"hostname":	"BLUEMAX",
				"host_uuid":	"NGF-510665007175",
				"ifc_id":	1,
				"ifc_name":	"eth0"
		}]
}

QoS 부모 큐

GET

/qos/profiles/{ppk}/parent/queues

QoS 부모 큐 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
QoS 프로파일 ID (qos_prf_id)

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

QoS 부모 큐 목록 조회 성공

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
result: required (array of GetParentQueue)
결과 데이터

Items: GetParentQueue
Items

qos_class_id: required (integer)
qos_class_id
큐 ID

name
name: required (integer)
큐 이름

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"qos_class_id":	1,
				"name":	"큐	이름"
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

QoS 큐

GET

/qos/profiles/{ppk}/queues

QoS 큐 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
QoS 프로파일 ID (qos_prf_id)

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

QoS 큐 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of GetQueueList)
result
결과 데이터

Items: GetQueueList
Items

set_rate
set_rate: (one of 0, 1)
보장 대역폭 수동 설정 (default	큐일	때	사용됨)
OFF:	0,	ON:	1

name
name: (string - minLength: 1 - maxLength: 32)
큐 이름 (default	큐가	아닐	경우	사용됨)

prioprio: (integer)
우선 순위 (default	큐가	아닐	경우	사용됨)
우선순위	없음,	그룹큐	:	0
가장	낮음	:	1
매우	낮음	:	2
낮음	:	3
보통	:	4

높음	:	5
매우	높음	:	6
가장	높음	:	7

raterate: required (integer)
송신 보장 대역폭
해당	프로파일의	auto_rate가	2일	경우	0으로	설정

ceilceil: required (integer - minimum: 8 - maximum: 100000000)
송신 제한 대역폭(Kbps)

descdesc: (string - maxLength: 128)
큐 설명 (default	큐가	아닐	경우	사용됨)

parent_qos_class_id
parent_qos_class_id: required (integer)
부모 큐 ID

qos_class_id
qos_class_id: required (integer)
큐 ID

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"qos_class_id":	1,
				"parent_qos_class_id":1,
				"name":	"큐	이름",
				"prio":	1,
				"rate":	100000000,
				"ceil":	100000000,
				"desc":	"큐	설명"
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

/qos/profiles/{ppk}/queues

QoS 큐를 추가한다.

Request

URI Parameters

ppkppk: required (integer)
QoS 프로파일 ID (qos_prf_id)

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

set_rate: (one of 0, 1)
set_rate
보장 대역폭 수동 설정 (default	큐일	때	사용됨)
OFF:	0,	ON:	1

name
name: (string - minLength: 1 - maxLength: 32)
큐 이름 (default	큐가	아닐	경우	사용됨)

prioprio: (integer)
우선 순위 (default	큐가	아닐	경우	사용됨)
우선순위	없음,	그룹큐	:	0
가장	낮음	:	1
매우	낮음	:	2
낮음	:	3
보통	:	4
높음	:	5
매우	높음	:	6
가장	높음	:	7

raterate: required (integer)
송신 보장 대역폭
해당	프로파일의	auto_rate가	2일	경우	0으로	설정

ceilceil: required (integer - minimum: 8 - maximum: 100000000)
송신 제한 대역폭(Kbps)

descdesc: (string - maxLength: 128)
큐 설명 (default	큐가	아닐	경우	사용됨)

parent_qos_class_id
parent_qos_class_id: required (integer)
부모 큐 ID

Example:
Example

{
		"parent_qos_class_id":	1,
		"name":	"New	큐	이름",
		"desc":	"New	큐	설명",
		"prio":	1,
		"rate":	0,
		"ceil":	100000000
}

Response

HTTP status code 200

QoS 큐 추가 성공

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

set_rate
set_rate: (one of 0, 1)
보장 대역폭 수동 설정 (default	큐일	때	사용됨)
OFF:	0,	ON:	1

parent_qos_class_id
parent_qos_class_id: required (integer)
부모 큐 ID (default	큐가	아닐	경우	사용됨)

name
name: required (string - minLength: 1 - maxLength: 32)
큐 이름 (default	큐가	아닐	경우	사용됨)

prioprio: required (integer)

우선 순위 (default	큐가	아닐	경우	사용됨)
우선순위	없음,	그룹큐	:	0
가장	낮음	:	1
매우	낮음	:	2
낮음	:	3
보통	:	4
높음	:	5
매우	높음	:	6
가장	높음	:	7

raterate: required (integer)
송신 보장 대역폭
해당	프로파일의	auto_rate가	2일	경우	0	입력

ceilceil: required (integer - minimum: 8 - maximum: 100000000)
송신 제한 대역폭(Kbps)

descdesc: (string - maxLength: 128)
큐 설명 (default	큐가	아닐	경우	사용됨)

qos_class_id
qos_class_id: (integer)
큐 ID( default	큐가	아닐	경우	사용됨 )

parent_name
parent_name: (string)
부모 큐 이름( default	큐가	아닐	경우	사용됨 )

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
		"result":	{
				"qos_class_id":	2,
				"parent_qos_class_id":1,
				"name":	"New	큐	이름",
				"prio":	1,
				"rate":	50000000,
				"ceil":	100000000,
				"desc":	"New	큐	설명",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-08	12:23:23"
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

/qos/profiles/{ppk}/queues/{pk}

QoS 큐을(를) 조회한다.

Request

URI Parameters

ppkppk: required (integer)
QoS 프로파일 ID (qos_prf_id)

pkpk: required (integer)
큐 ID( qos_class_id )

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

QoS 큐 조회 성공

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

set_rate: (one of 0, 1)
set_rate
보장 대역폭 수동 설정 (default	큐일	때	사용됨)
OFF:	0,	ON:	1

parent_qos_class_id
parent_qos_class_id: required (integer)
부모 큐 ID (default	큐가	아닐	경우	사용됨)

name: required (string - minLength: 1 - maxLength: 32)
name

큐 이름 (default	큐가	아닐	경우	사용됨)

prioprio: required (integer)
우선 순위 (default	큐가	아닐	경우	사용됨)
우선순위	없음,	그룹큐	:	0
가장	낮음	:	1
매우	낮음	:	2
낮음	:	3
보통	:	4
높음	:	5
매우	높음	:	6
가장	높음	:	7

raterate: required (integer)
송신 보장 대역폭
해당	프로파일의	auto_rate가	2일	경우	0	입력

ceilceil: required (integer - minimum: 8 - maximum: 100000000)
송신 제한 대역폭(Kbps)

descdesc: (string - maxLength: 128)
큐 설명 (default	큐가	아닐	경우	사용됨)

qos_class_id
qos_class_id: (integer)
큐 ID( default	큐가	아닐	경우	사용됨 )

parent_name
parent_name: (string)
부모 큐 이름( default	큐가	아닐	경우	사용됨 )

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

#	default	큐가	아닐때
{
		"code":	"ok",
		"result":	{
				"qos_class_id":	1,
				"parent_qos_class_id":1,
				"parent_name":	"default",
				"name":	"큐	이름",
				"prio":	1,
				"rate":	100000000,
				"ceil":	100000000,
				"desc":	"큐	설명",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-08	12:23:23"
		}
}

#	default	큐	일때
{
		"code":	"ok",
		"result":	{
				"set_rate":	0,
				"rate":	5000000,
				"ceil":	100000000,
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-06-07	08:36:57"
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

/qos/profiles/{ppk}/queues/{pk}

QoS 큐을(를) 수정한다.

Request

URI Parameters

ppkppk: required (integer)
QoS 프로파일 ID (qos_prf_id)

pkpk: required (integer)
큐 ID( qos_class_id )

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

set_rate
set_rate: (one of 0, 1)
보장 대역폭 수동 설정 (default	큐일	때	사용됨)
OFF:	0,	ON:	1

name
name: (string - minLength: 1 - maxLength: 32)
큐 이름 (default	큐가	아닐	경우	사용됨)

prioprio: (integer)
우선 순위 (default	큐가	아닐	경우	사용됨)
우선순위	없음,	그룹큐	:	0
가장	낮음	:	1
매우	낮음	:	2

낮음	:	3
보통	:	4
높음	:	5
매우	높음	:	6
가장	높음	:	7

raterate: required (integer)
송신 보장 대역폭
해당	프로파일의	auto_rate가	2일	경우	0으로	설정

ceilceil: required (integer - minimum: 8 - maximum: 100000000)
송신 제한 대역폭(Kbps)

descdesc: (string - maxLength: 128)
큐 설명 (default	큐가	아닐	경우	사용됨)

Example:
Example

#	default	큐가	아닐때
{
		"name":	"큐	이름",
		"prio":	2,
		"rate":	0,
		"ceil":	100000000,
		"desc":	"큐	설명",
}

#	default	큐	일때
{
		"set_rate":	0,
		"rate":	0,
		"ceil":	100000000
}

Response

HTTP status code 200

QoS 큐 수정 성공

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

set_rate
set_rate: (one of 0, 1)
보장 대역폭 수동 설정 (default	큐일	때	사용됨)
OFF:	0,	ON:	1

parent_qos_class_id: required (integer)
parent_qos_class_id
부모 큐 ID (default	큐가	아닐	경우	사용됨)

name
name: required (string - minLength: 1 - maxLength: 32)
큐 이름 (default	큐가	아닐	경우	사용됨)

prioprio: required (integer)
우선 순위 (default	큐가	아닐	경우	사용됨)
우선순위	없음,	그룹큐	:	0
가장	낮음	:	1
매우	낮음	:	2
낮음	:	3
보통	:	4
높음	:	5
매우	높음	:	6
가장	높음	:	7

raterate: required (integer)
송신 보장 대역폭
해당	프로파일의	auto_rate가	2일	경우	0	입력

ceilceil: required (integer - minimum: 8 - maximum: 100000000)
송신 제한 대역폭(Kbps)

descdesc: (string - maxLength: 128)
큐 설명 (default	큐가	아닐	경우	사용됨)

qos_class_id
qos_class_id: (integer)
큐 ID( default	큐가	아닐	경우	사용됨 )

parent_name
parent_name: (string)
부모 큐 이름( default	큐가	아닐	경우	사용됨 )

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

#	default	큐가	아닐때
{
		"code":	"ok",
		"result":	{
				"qos_class_id":	1,
				"parent_qos_class_id":1,
				"parent_name":	"default",
				"name":	"큐	이름",
				"prio":	1,
				"rate":	50000000,
				"ceil":	100000000,
				"desc":	"큐	설명",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-05-08	12:23:23"
		}
}

#	default	큐	일때
{
		"code":	"ok",
		"result":	{
				"set_rate":	0,
				"rate":	50000000,
				"ceil":	100000000,
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-06-07	08:36:57"
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

/qos/profiles/{ppk}/queues/{pk}

QoS 큐을(를) 삭제한다.

Request

URI Parameters

ppkppk: required (integer)
QoS 프로파일 ID (qos_prf_id)

pkpk: required (integer)
큐 ID( qos_class_id )

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

QoS 큐 삭제 성공

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

dev_t: (string)
dev_t
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

/qos/profiles/{ppk}/queues/{pk}/create/bandwidth

생성 가능한 대역폭 범위을(를) 조회한다.

Request

URI Parameters

ppkppk: required (integer)
QoS 프로파일 ID (qos_prf_id)

pkpk: required (integer)
큐 ID( qos_class_id )

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

생성 가능한 대역폭 범위 조회 성공

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

min_rate
min_rate: required (integer - minimum: 8 - maximum: 100000000)
최소 보장 대역폭

max_rate
max_rate: required (integer - minimum: 8 - maximum: 100000000)
최대 보장 대역폭

min_ceil
min_ceil: required (integer - minimum: 8 - maximum: 100000000)
최소 제한 대역폭

max_ceil
max_ceil: required (integer - minimum: 8 - maximum: 100000000)
최대 제한 대역폭

Example:
Example

{
		"code":	"ok",
		"result":	{
				"min_rate":	null,
				"max_rate":	null,
				"min_ceil":	8,
				"max_ceil":	100000000
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

GET

/qos/profiles/{ppk}/queues/{pk}/update/bandwidth

수정 가능한 대역폭 범위을(를) 조회한다.

Request

URI Parameters

ppkppk: required (integer)
QoS 프로파일 ID (qos_prf_id)

pkpk: required (integer)
큐 ID( qos_class_id )

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

수정 가능한 대역폭 범위 조회 성공

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

min_rate
min_rate: required (integer - minimum: 8 - maximum: 100000000)
최소 보장 대역폭

max_rate
max_rate: required (integer - minimum: 8 - maximum: 100000000)
최대 보장 대역폭

min_ceil
min_ceil: required (integer - minimum: 8 - maximum: 100000000)
최소 제한 대역폭

max_ceil
max_ceil: required (integer - minimum: 8 - maximum: 100000000)
최대 제한 대역폭

Example:
Example

{
		"code":	"ok",
		"result":	{
				"min_rate":	0,
				"max_rate":	0,
				"min_ceil":	8,
				"max_ceil":	100000000
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

방화벽 QoS 프로파일

GET

/qos/profiles/{pid}/fw/{version}/sets/{sid}/rules

방화벽 정책 목록을 조회한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	1인	QoS	프로파일	ID	여야함

version
version: required (one of 4, 6)
IP 버전
IPv4	정책:	4,	IPv6	정책:	6

sidsid: required (integer)
방화벽 세트 ID (fw_set_id)

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

방화벽 목록 조회 성공

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
result: required (array of FwRuleQueue)
결과 데이터

Items: FwRuleQueue
Items

fw_set_id
fw_set_id: required (integer)
정책 세트 ID

fw_grp_id
fw_grp_id: required (integer)
정책 그룹 ID

fw_grp_name
fw_grp_name: required (string)
정책 그룹 이름

fw_rule_id
fw_rule_id: required (integer)
정책 ID

name: required (string)
name
정책 이름

descdesc: required (string)
설명

seqseq: required (integer)
순번

bi_dir
bi_dir: required (integer)
양방향 정책  사용	안함:	0,	사용:	1

time
time: required (object)
시간 객체

srcsrc: required (array of AddressObject)
출발지 객체 목록

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
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

excpt: required (integer)
excpt
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

dstdst: required (array of AddressObject)
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
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

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
서비스	객체:	1,	서비스	그룹	객체:	2

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

user
user: required (array of object)
사용자 객체 목록

Items:
Items

device
device: (array of object)
디바이스 객체 목록
IPv4	일	때만	표시

Items:
Items

appapp: required (array of GetAppObject)
앱 객체 목록

Items: GetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

app_obj_type
app_obj_type: required (integer)
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

name
name: required (string)
애플리케이션 관련 객체 이름
app_obj_type가	1일	경우	객체	이름
app_obj_type가	2일	경우	그룹	객체	이름
app_obj_type가	3일	경우	필터	객체	이름

security_profile
security_profile: required (object)
보안 프로파일 정보

ipsips: required (object)
IPS 프로파일 ID와 이름

Example:
Example

{"id":	1,	"name":	"default"}

avav: required (object)
안티바이러스 프로파일 ID와 이름

Example:
Example

{"id":	1,	"name":	"default"}

asas: required (object)
안티스팸 프로파일 ID와 이름

Example:
Example

{"id":	1,	"name":	"default"}

wfwf: required (object)
웹필터 프로파일 ID와 이름

Example:
Example

{"id":	1,	"name":	"default"}

dlpdlp: required (object)
DLP 프로파일 ID와 이름

Example:
Example

{"id":	1,	"name":	"default"}

file_type: required (object)
file_type
파일 유형 제어 프로파일 ID와 이름

Example:
Example

{"id":	1,	"name":	"default"}

aptapt: required (object)
APT 프로파일 ID와 이름

Example:
Example

{"id":	1,	"name":	"default"}

Example:
Example

{
		"ips":	{"id":	1,	"name":	"default"},
		"av":	{"id":	1,	"name":	"default"},
		"as":	{"id":	1,	"name":	"default"},
		"wf":	{"id":	1,	"name":	"default"},
		"dlp":	{"id":	1,	"name":	"default"},
		"file_type":	{"id":	1,	"name":	"default"},
		"apt":	{"id":	1,	"name":	"default"}
}

qosqos: required (object)
할당된 큐 정보

qos_class_id
qos_class_id: required (integer)
큐 ID

queue_name
queue_name: required (string)
큐 이름

routing_marker
routing_marker: required (object)
라우터 마커

idid: required (integer)
라우팅 마커 ID

name: required (string)
name
라우팅 마커 이름

qos_class_id
qos_class_id: required (integer)
큐 ID

queue_name
queue_name: required (string)
큐 이름

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"fw_set_id":	1,
				"fw_grp_id":	5,
				"fw_grp_name":	"default",
				"fw_rule_id":	1,
				"name":	"auto_ruleId_1",
				"desc":	"",
				"seq":	1,
				"use":	1,
				"action":	1,
				"bi_dir":	0,
				"log":	1,
				"tcp_flag":	0,
				"vlan_id":	"",
				"sess_limit":	0,
				"sess_limit_val":	10000,
				"sess_limit_ip_block":	1000,
				"sess_limit_block":	0,
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2019-01-16	20:55:17",
				"src":	[],
				"dst":	[],
				"srv":	[],
				"app":	[],
				"user":	[],
				"device":	[],
				"security_profile":	{
								"ips":	null,
								"av":	null,
								"as":	null,
								"wf":	null,
								"dlp":	null,
								"file_type":	null,
								"apt":	null
				},
				"time":	{},
				"qos":	[],
				"routing_marker":	{},
				"hit_count":	[
								2555,
								57095,
								64516,
								null,
								null
				],
				"last_hit_time":	"2019-01-24	11:07:00"
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

방화벽 QoS 프로파일

PUT

/qos/profiles/{pid}/fw/sets/{sid}/rules

방화벽 정책 목록에 큐를 일괄 설정(할당)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	1인	QoS	프로파일	ID	여야함

sidsid: required (integer)
방화벽 세트 ID (fw_set_id)

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

qos_class_id
qos_class_id: required (integer)
큐 ID

app_obj_id_list
app_obj_id_list: required (array of object)
방화벽 정책 목록

items: required (array of object)
items
수정될 정보 목록(최대 100건)

Example:
Example

{
		"qos_class_id":	1,
		"fw_rule_id_list":	[
				{"fw_rule_id	":	1},
				{"fw_rule_id	":	2}
		]
}

Response

HTTP status code 200

방화벽 목록 수정 성공

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

Example:
Example

{
		"code":	"ok",
		"result":	{
				"qos_class_id":	1
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

/qos/profiles/{pid}/fw/sets/{sid}/rules

방화벽 정책 목록에 큐를 일괄 삭제(제거)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	1인	QoS	프로파일	ID	여야함

sidsid: required (integer)
방화벽 세트 ID (fw_set_id)

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

usr_list: required (array of object)
usr_list
방화벽 정책 목록

items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"fw_rule_id_list":	[
				{"fw_rule_id	":	1},
				{"fw_rule_id	":	2}
		]
}

Response

HTTP status code 200

방화벽 목록 삭제 성공

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

Example:
Example

{
		"code":	"ok",
		"result":	{
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

PUT

/qos/profiles/{pid}/fw/sets/{sid}/rules/{rid}

방화벽 정책에 큐를 설정(할당)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	1인	QoS	프로파일	ID	여야함

sidsid: required (integer)
방화벽 세트 ID (fw_set_id)

ridrid: required (string)
uiduid: required (integer)

정책 ID (fw_rule_id)

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

qos_class_id
qos_class_id: required (integer)
큐 ID

Example:
Example

{
		"qos_class_id":	1
}

Response

HTTP status code 200

정책 큐 수정 성공

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
		"result":	{
				"qos_class_id":	1
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

/qos/profiles/{pid}/fw/sets/{sid}/rules/{rid}

방화벽 정책에 설정된 큐를 삭제(제거)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	1인	QoS	프로파일	ID	여야함

sidsid: required (integer)
방화벽 세트 ID (fw_set_id)

ridrid: required (string)
uiduid: required (integer)
정책 ID (fw_rule_id)

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

Response

HTTP status code 200

정책 큐 삭제 성공

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

큐에 설정된 방화벽 세트 목록

GET

/qos/profiles/{pid}/queues/{qid}/fw/sets

방화벽 세트 목록을 조회한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	1인	QoS	프로파일	ID	여야함

qidqid: required (integer)
큐 ID (qos_class_id)

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

방화벽 세트 목록 조회 성공

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
result: required (array of FwSet)
결과 데이터

Items: FwSet
Items

fw_set_id
fw_set_id: required (integer)
방화벽 세트 ID

fw_ver
fw_ver: required (integer)
방화벽 정책 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
방화벽 세트 이름

cntcnt: required (integer)
정책 세트에 설정된 큐 수

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"fw_set_id":	1,
				"fw_ver":	1,
				"name":	"default",
				"cnt":	1
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

GET

/qos/profiles/{pid}/queues/{qid}/fw/sets/{sid}/rules

방화벽 정책 목록을 조회한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	1인	QoS	프로파일	ID	여야함

qidqid: required (integer)
큐 ID (qos_class_id)

sidsid: required (integer)
방화벽 세트 ID( fw_set_id )

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

방화벽 정책 목록 조회 성공

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
result: required (array of FwRule)
결과 데이터

Items: FwRule
Items

fw_set_id
fw_set_id: required (integer)
정책 세트 ID

fw_grp_id
fw_grp_id: required (integer)
정책 그룹 ID

fw_grp_name
fw_grp_name: required (string)
정책 그룹 이름

fw_rule_id
fw_rule_id: required (integer)
정책 ID

name
name: required (string)
정책 이름

descdesc: required (string)
설명

seqseq: required (integer)
순번

bi_dir
bi_dir: required (integer)
양방향 정책  사용	안함:	0,	사용:	1

time
time: required (object)
시간 객체

srcsrc: required (array of AddressObject)
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
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

dstdst: required (array of AddressObject)
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
주소 객체 타입
호스트객체:	1,	넷마스크:	2,	범위:	3

excpt
excpt: required (integer)
예외 객체 여부
예외	객체	아님:	0,	예외	객체:	1

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
서비스	객체:	1,	서비스	그룹	객체:	2

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

user
user: required (array of object)
사용자 객체 목록

Items:
Items

device
device: (array of object)
디바이스 객체 목록
IPv4	일	때만	표시

Items:
Items

appapp: required (array of GetAppObject)
앱 객체 목록

Items: GetAppObject
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

app_obj_type
app_obj_type: required (integer)
애플리케이션 객체 유형
객체:	1,	그룹	객체:	2,	필터	객체:	3

name
name: required (string)
애플리케이션 관련 객체 이름
app_obj_type가	1일	경우	객체	이름
app_obj_type가	2일	경우	그룹	객체	이름
app_obj_type가	3일	경우	필터	객체	이름

security_profile
security_profile: required (object)
보안 프로파일 정보

ipsips: required (object)
IPS 프로파일 ID와 이름

Example:
Example

{"id":	1,	"name":	"default"}

avav: required (object)
안티바이러스 프로파일 ID와 이름

Example:
Example

{"id":	1,	"name":	"default"}

asas: required (object)
안티스팸 프로파일 ID와 이름

Example:
Example

{"id":	1,	"name":	"default"}

wfwf: required (object)
웹필터 프로파일 ID와 이름

Example:
Example

{"id":	1,	"name":	"default"}

dlpdlp: required (object)
DLP 프로파일 ID와 이름

Example:
Example

{"id":	1,	"name":	"default"}

file_type
file_type: required (object)
파일 유형 제어 프로파일 ID와 이름

Example:
Example

{"id":	1,	"name":	"default"}

aptapt: required (object)
APT 프로파일 ID와 이름

Example:
Example

{"id":	1,	"name":	"default"}

Example:
Example

{
		"ips":	{"id":	1,	"name":	"default"},
		"av":	{"id":	1,	"name":	"default"},
		"as":	{"id":	1,	"name":	"default"},
		"wf":	{"id":	1,	"name":	"default"},
		"dlp":	{"id":	1,	"name":	"default"},
		"file_type":	{"id":	1,	"name":	"default"},
		"apt":	{"id":	1,	"name":	"default"}
}

qosqos: required (object)
할당된 큐 정보

qos_class_id
qos_class_id: required (integer)
큐 ID

queue_name
queue_name: required (string)
큐 이름

routing_marker
routing_marker: required (object)
라우터 마커

idid: required (integer)
라우팅 마커 ID

name
name: required (string)
라우팅 마커 이름

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"fw_rule_id":	1,
				"rule_name":	"정책	이름",
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

사용자 QoS 프로파일

GET

/qos/profiles/{pid}/users

사용자 목록을 조회한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	2인	QoS	프로파일	ID	여야함

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

사용자 목록 조회 성공

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
result: required (array of UserQueue)
결과 데이터

Items: UserQueue
Items

user_id
user_id: required (string)
사용자 문자열 ID

qos_class_id
qos_class_id: required (integer)
큐 ID

queue_name
queue_name: required (string)
큐 이름

user_name
user_name: required (string)
사용자 이름

usr_obj_type: required (string)
usr_obj_type
사용자 타입
로컬	DB	사용자:	1,	IP	매핑	사용자:	3,	AD	사용자:	5

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"user_id":	"사용자	문자열	ID",
				"user_name":	"사용자	이름",
				"usr_obj_type":	1,
				"desc":	"사용자	설명",
				"qos_class_id":	1,
				"queue_name":	"큐	이름"
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

PUT

/qos/profiles/{pid}/users

사용자 목록에 큐를 일괄 설정(할당)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	2인	QoS	프로파일	ID	여야함

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

qos_class_id
qos_class_id: required (integer)
큐 ID

usr_list: required (array of object)
usr_list
사용자 목록

items
items: required (array of object)
수정될 정보 목록(최대 100건)

Example:
Example

{
		"qos_class_id":	1,
		"usr_list":	[
				{"user_id":	"user1"},
				{"user_id":	"user2"}
		]
}

Response

HTTP status code 200

사용자 목록 수정 성공

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

Example:
Example

{
		"code":	"ok",
		"result":	{
				"qos_class_id":	1
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

DELETE

/qos/profiles/{pid}/users

사용자 목록에 큐를 일괄 삭제(제거)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	2인	QoS	프로파일	ID	여야함

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

usr_list: required (array of object)
usr_list
사용자 목록

items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"usr_list":	[
				{"user_id":	"user1"},
				{"user_id":	"user2"}
		]
}

Response

HTTP status code 200

사용자 목록 삭제 성공

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

Example:
Example

{
		"code":	"ok",
		"result":	{
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

PUT

/qos/profiles/{pid}/users/{uid}

사용자에 큐를 설정(할당)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	2인	QoS	프로파일	ID	여야함

uiduid: required (string)
사용자 문자열 ID (user_id)
URI	인코딩	처리	필요

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

qos_class_id
qos_class_id: required (integer)
큐 ID

Example:
Example

{
		"qos_class_id":	1
}

Response

HTTP status code 200

사용자 큐 수정 성공

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
		"result":	{
				"qos_class_id":	1
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

/qos/profiles/{pid}/users/{uid}

사용자에 설정된 큐를 삭제(제거)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	2인	QoS	프로파일	ID	여야함

uiduid: required (string)
사용자 문자열 ID (user_id)
URI	인코딩	처리	필요

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

사용자 큐 삭제 성공

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

큐에 설정된 사용자 목록

GET

/qos/profiles/{pid}/queues/{qid}/users

큐에 설정된 사용자 목록을 조회한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	2인	QoS	프로파일	ID	여야함

qidqid: required (integer)
큐 ID (qos_class_id)

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

사용자 큐 목록 조회 성공

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
result: required (array of UserObj)
결과 데이터

Items: UserObj
Items

user_id
user_id: required (string)
사용자 문자열 ID

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"user_id":	"사용자	문자열	ID"
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

애플리케이션 QoS 프로파일

GET

/qos/profiles/{pid}/apps

애플리케이션 목록을 조회한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	3인	QoS	프로파일	ID	여야함

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

애플리케이션 목록 조회 성공

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
result: required (array of AppObjTreeQueue)
결과 데이터

Items: AppObjTreeQueue
Items

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

type
type: required (integer)
애플리케이션 유형
시스템	정의:	0,	사용자	정의:	1

app_obj_type
app_obj_type: required (one of 1, 2, 3)
객체 타입
애플리케이션	객체:	1,	애플리케이션	그룹	객체:	2,	애플리케이션	필터	객체:	3

name: required (string)
name
애플리케이션 객체명

grp_id
grp_id: required (integer)
해당 애플리케이션이 포함한 애플리케이션 그룹 객체 ID

descdesc: required (string)
설명

cfg_adm_id
cfg_adm_id: required (string)
수정한 관리자 ID

cfg_adm
cfg_adm: required (string)
수정한 관리자 이름

cfg_dt
cfg_dt: required (string)
수정 날짜

level
level: required (integer)
트리를 구성하기 위한 깊이(depth)
최상위는  0

children
children: required (array of AppObjQueue)
소속 애플리케이션 객체 목록

Items: AppObjQueue
Items

qos_class_id
qos_class_id: required (integer)
큐 ID

queue_name
queue_name: required (string)
큐 이름

app_obj_id
app_obj_id: required (integer)
애플리케이션 객체 ID

type
type: required (integer)
애플리케이션 유형
시스템	정의:	0,	사용자	정의:	1

app_obj_type
app_obj_type: required (one of 1, 2, 3)
객체 타입
애플리케이션	객체:	1,	애플리케이션	그룹	객체:	2,	애플리케이션	필터	객체:	3

name
name: required (string)
애플리케이션 객체명

grp_id
grp_id: required (integer)
해당 애플리케이션이 포함한 애플리케이션 그룹 객체 ID

portport: required (string)
기본 애플리케이션 표준 포트

app_risk_id: required (integer)
app_risk_id
애플리케이션 위험도
Very	Low:	1,	Low:	2,	Medium:	3,	High:	4,	Very	High:	5

app_cate
app_cate: required (string)
카테고리(콤마로 구분)

app_tech
app_tech: required (string)
적용 기술(콤마로 구분)

app_char
app_char: required (string)
특징(콤마로 구분)

app_tag
app_tag: required (string)
태그(콤마로 구분)

app_cntry_code
app_cntry_code: required (string)
국가 코드

useuse: required (integer)
식별( 식별않음:	0,	식별:	1 )

cfg_adm_id
cfg_adm_id: required (string)
수정한 관리자 ID

cfg_adm
cfg_adm: required (string)
수정한 관리자 이름

cfg_dt: required (string)
cfg_dt
수정 날짜

refref: required (object)
참조 여부

level
level: required (integer)
트리를 구성하기 위한 깊이(depth)
최상위는  0

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"app_obj_id":	50282,
						"type":	3,
						"name":	"0zz0",
						"grp_id":	0,
						"desc":	"0zz0는	아랍의	온라인	파일	호스팅	서비스이다.",
						"cfg_adm_id":	0,
						"cfg_adm":	"root",
						"cfg_dt":	"2019-04-03	18:16:20",
						"level":	0,
						"children":	[
								{
										"app_obj_id":	31065,
										"type":	0,
										"app_obj_type":	1,
										"name":	"0zz0-base",
										"desc":	"0zz0는	아랍의	온라인	파일	호스팅	서비스이다.",
										"grp_id":	50282,
										"port":	"TCP	80",
										"app_risk_id":	4,
										"app_cate":	"Storage-File-Sharing",
										"app_tech":	"web-based",
										"app_char":	"bandwidth,file	transfer",
										"app_tag":	"FileSharing,HTTP",
										"app_cntry_code":	"US",
										"use":	1,
										"cfg_adm_id":	0,
										"cfg_adm":	"root",
										"cfg_dt":	"2019-04-03	18:16:27",
										"ref":	{
												"fw_ref":	true,
												"fwv6_ref":	false,
												"apptag_ref":	false,
												"apptagv6_ref":	false,
												"grp_ref":	false,
												"content_ref":	false,
												"qos_ref":	false
										},
										"level":	1,
										"qos_class_id":	null,
										"queue_name":	""
								}
						]
				},
				{
						"app_obj_id":	30897,
						"type":	0,
						"app_obj_type":	1,
						"name":	"10jqka",
						"desc":	"10jqka는	중국의	온라인	주식	사이트이다.",
						"grp_id":	0,
						"port":	"TCP	80",
						"app_risk_id":	2,
						"app_cate":	"Finance-Stock",
						"app_tech":	"client-to-server",
						"app_char":	"bandwidth",
						"app_tag":	"Stock,HTTP",
						"app_cntry_code":	"CN",
						"use":	1,
						"cfg_adm_id":	0,
						"cfg_adm":	"root",
						"cfg_dt":	"2019-04-03	18:16:27",
						"ref":	{
								"fw_ref":	true,
								"fwv6_ref":	false,
								"apptag_ref":	false,
								"apptagv6_ref":	false,
								"grp_ref":	false,
								"content_ref":	false,
								"qos_ref":	false
						},
						"level":	0,
						"qos_class_id":	null,
						"queue_name":	""
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

PUT

/qos/profiles/{pid}/apps

애플리케이션 목록에 큐를 일괄 설정(할당)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	3인	QoS	프로파일	ID	여야함

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

qos_class_id
qos_class_id: required (integer)
큐 ID

app_obj_id_list: required (array of object)
app_obj_id_list
애플리케이션 목록

items
items: required (array of object)
수정될 정보 목록(최대 100건)

Example:
Example

{
		"qos_class_id":	1,
		"app_obj_id_list":	[
				{"app_obj_id":	1},
				{"app_obj_id":	2}
		]
}

Response

HTTP status code 200

애플리케이션 목록 수정 성공

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

Example:
Example

{
		"code":	"ok",
		"result":	{
				"qos_class_id":	1
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

DELETE

/qos/profiles/{pid}/apps

애플리케이션 목록에 큐를 일괄 삭제(제거)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	3인	QoS	프로파일	ID	여야함

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

usr_list
usr_list: required (array of object)
애플리케이션 목록

items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"app_obj_id_list":	[
				{"app_obj_id":	1},
				{"app_obj_id":	2}
		]
}

Response

HTTP status code 200

애플리케이션 목록 삭제 성공

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

Example:
Example

{
		"code":	"ok",
		"result":	{
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

PUT

/qos/profiles/{pid}/apps/{aid}

애플리케이션에 큐를 설정(할당)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	3인	QoS	프로파일	ID	여야함

aidaid: required (integer)
애플리케이션 객체 ID (app_obj_id)

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

qos_class_id
qos_class_id: required (integer)
큐 ID

Example:
Example

{
		"qos_class_id":	1
}

Response

HTTP status code 200

애플리케이션 큐 수정 성공

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
		"result":	{
				"qos_class_id":	1
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

/qos/profiles/{pid}/apps/{aid}

애플리케이션에 설정된 큐를 삭제(제거)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	3인	QoS	프로파일	ID	여야함

aidaid: required (integer)
애플리케이션 객체 ID (app_obj_id)

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

애플리케이션 큐 삭제 성공

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

큐에 설정된 애플리케이션 목록

GET

/qos/profiles/{pid}/queues/{qid}/apps

큐에 설정된 애플리케이션 목록을 조회한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	3인	QoS	프로파일	ID	여야함

qidqid: required (integer)
큐 ID (qos_class_id)

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

애플리케이션 큐 목록 조회 성공

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
result: required (array of AppObj)
결과 데이터

Items: AppObj
Items

app_obj_id: required (integer)
app_obj_id
앱 ID

app_name
app_name: required (string)
애플리케이션 객체명

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"app_obj_id":	1,
				"app_name":	"애플리케이션	객체명"
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

웹 카테고리 QoS 프로파일

GET

/qos/profiles/{pid}/webcategories

웹 카테고리 목록을 조회한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	4인	QoS	프로파일	ID	여야함

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

웹 카테고리 목록 조회 성공

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
result: required (array of WebCategoryObjQueue)
결과 데이터

Items: WebCategoryObjQueue
Items

qos_class_id: required (integer)
qos_class_id
큐 ID

queue_name
queue_name: required (string)
큐 이름

web_cate_obj_id
web_cate_obj_id: required (integer)
웹 카테고리 객체 ID

name
name: required (string)
웹 카테고리 객체 이름

descdesc: required (string - maxLength: 128)
웹 카테고리 객체 설명

upper_web_cate_obj_id
upper_web_cate_obj_id: required (integer)
상위 객체 ID

upper_cate_name
upper_cate_name: required (string)
상위 객체 이름

predef: required (one of 0, 1)
predef
사용자 정의 객체 여부
사용자	정의:	0,	시스템	정의:	1

example_site
example_site: required (string)
예제 사이트
시스템	정의(1)  웹 카테고리 객체일 경우

cfg_adm_id: required (string)
cfg_adm_id
수정한 관리자 ID

cfg_adm
cfg_adm: required (string)
수정한 관리자 이름

cfg_dt
cfg_dt: required (string)
수정 날짜

refref: required (object)
참조 여부

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"web_cate_obj_id":	1,
				"name":	"웹	카테고리	객체	이름",
				"upper_web_cate_obj_id":	1,
				"upper_cate_name":	"상위	웹	카테고리	객체	이름",
				"desc":	"웹	카테고리	객체	설명",
				"example_site":	"http://example.com",
				"predef":	1,
				"mmbr_count":	2,
				"ref":	{
						"fw_ref":	false,
						"fwv6_ref":	false,
						"apptag_ref":	true,
						"apptagv6_ref":	true,
						"grp_ref":	false,
						"content_ref":	false,
						"qos_ref":	false
				},
				"qos_class_id":	null,
				"queue_name":	""
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

PUT

/qos/profiles/{pid}/webcategories

웹 카테고리 목록에 큐를 일괄 설정(할당)한다.

Request

URI Parameters

pidpid: required (integer)

QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	4인	QoS	프로파일	ID	여야함

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

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties

qos_class_id: required (integer)
qos_class_id
큐 ID

web_cate_obj_id_list
web_cate_obj_id_list: required (array of object)
웹 카테고리 목록

items
items: required (array of object)
수정될 정보 목록(최대 100건)

Example:
Example

{
		"qos_class_id":	1,
		"web_cate_obj_id_list":	[
				{"web_cate_obj_id":	1},
				{"web_cate_obj_id":	2}
		]
}

Response

HTTP status code 200

웹 카테고리 목록 수정 성공

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

Example:
Example

{
		"code":	"ok",
		"result":	{
				"qos_class_id":	1
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

/qos/profiles/{pid}/webcategories

웹 카테고리 목록에 큐를 일괄 삭제(제거)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	4인	QoS	프로파일	ID	여야함

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

web_cate_obj_id_list
web_cate_obj_id_list: required (array of object)
웹 카테고리 목록

items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"web_cate_obj_id_list":	[
				{"web_cate_obj_id":	1},
				{"web_cate_obj_id":	2}
		]
}

Response

HTTP status code 200

웹 카테고리 목록 삭제 성공

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

Example:
Example

{
		"code":	"ok",
		"result":	{
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

PUT

/qos/profiles/{pid}/webcategories/{wid}

웹 카테고리 객체에 큐를 설정(할당)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	4인	QoS	프로파일	ID	여야함

widwid: required (integer)
웹 카테고리 객체 ID (web_cate_obj_id)

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

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties

qos_class_id: required (integer)
qos_class_id
큐 ID

Example:
Example

{
		"qos_class_id":	1
}

Response

HTTP status code 200

웹 카테고리 큐 수정 성공

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
		"result":	{
				"qos_class_id":	1
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

/qos/profiles/{pid}/webcategories/{wid}

웹 카테고리 객체에 설정된 큐를 삭제(제거)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	4인	QoS	프로파일	ID	여야함

widwid: required (integer)
웹 카테고리 객체 ID (web_cate_obj_id)

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

웹 카테고리 큐 삭제 성공

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

dev_t: (string)
dev_t
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

큐에 설정된 웹 카테고리 객체 목록

GET

/qos/profiles/{pid}/queues/{qid}/webcategories

큐에 설정된 웹 카테고리 객체 목록을 조회한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	4인	QoS	프로파일	ID	여야함

qidqid: required (integer)
큐 ID (qos_class_id)

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

Response

HTTP status code 200

웹 카테고리 객체 큐 목록 조회 성공

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
result: required (array of WebCategoryObj)
결과 데이터

Items: WebCategoryObj
Items

web_cate_obj_id
web_cate_obj_id: required (integer)
웹 카테고리 객체 ID

web_name: required (string)
web_name
웹 카테고리 객체 이름

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"web_cate_obj_id":	1,
				"web_name":	"웹	카테고리	객체명"
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

VLAN QoS 프로파일

GET

/qos/profiles/{pid}/vlans

VLAN 목록을 조회한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	5인	QoS	프로파일	ID	여야함

Annotations

SupportedVersion:
SupportedVersion

"4단계	스쿨넷"

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

VLAN 목록 조회 성공

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
result: required (array of VlanQueue)
결과 데이터

Items: VlanQueue
Items

qos_class_id
qos_class_id: required (integer)
큐 ID

queue_name
queue_name: required (string)
큐 이름

vlan_id
vlan_id: required (integer)
VLAN ID

vlan_name
vlan_name: required (string)
VLAN 이름

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"vlan_id":	1,
				"vlan_name":	"VLAN명",
				"qos_class_id":	1,
				"queue_name":	"큐명"
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

PUT

/qos/profiles/{pid}/vlans

VLAN 목록에 큐를 일괄 설정(할당)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	5인	QoS	프로파일	ID	여야함

Annotations

SupportedVersion:
SupportedVersion

"4단계	스쿨넷"

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

qos_class_id
qos_class_id: required (integer)
큐 ID

vlan_id_list
vlan_id_list: required (array of object)
VLAN 목록

items
items: required (array of object)
수정될 정보 목록(최대 100건)

Example:
Example

{
		"qos_class_id":	1,
		"vlan_id_list":	[
				{"vlan_id":	1},
				{"vlan_id":	2}
		]
}

Response

HTTP status code 200

VLAN 목록 수정 성공

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
		"result":	{
				"qos_class_id":	1
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

/qos/profiles/{pid}/vlans

VLAN 목록에 큐를 일괄 삭제(제거)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	5인	QoS	프로파일	ID	여야함

Annotations

SupportedVersion:
SupportedVersion

"4단계	스쿨넷"

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

vlan_id_list
vlan_id_list: required (array of object)
웹 카테고리 목록

items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"vlan_id_list":	[
				{"vlan_id":	1},
				{"vlan_id":	2}
		]
}

Response

HTTP status code 200

VLAN 목록 삭제 성공

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
		"result":	{
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

PUT

/qos/profiles/{pid}/vlans/{vid}

VLAN에 큐를 설정(할당)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	5인	QoS	프로파일	ID	여야함

vidvid: required (integer)
VLAN ID (vlan_id)

Annotations

SupportedVersion:
SupportedVersion

"4단계	스쿨넷"

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

qos_class_id
qos_class_id: required (integer)
큐 ID

Example:
Example

{
		"qos_class_id":	1
}

Response

HTTP status code 200

VLAN 큐 수정 성공

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
		"result":	{
				"qos_class_id":	1
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

/qos/profiles/{pid}/vlans/{vid}

VLAN에 설정된 큐를 삭제(제거)한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	5인	QoS	프로파일	ID	여야함

vidvid: required (integer)
VLAN ID (vlan_id)

Annotations

SupportedVersion:
SupportedVersion

"4단계	스쿨넷"

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

VLAN 큐 삭제 성공

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

VLAN 목록

POST

/qos/profiles/{pid}/vlan/numbers

VLAN을 추가한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	5인	QoS	프로파일	ID	여야함

Annotations

SupportedVersion:
SupportedVersion

"4단계	스쿨넷"

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

vlan_num
vlan_num: required (integer)
VLAN 번호

vlan_opt
vlan_opt: required (integer)
VLAN 태깅 옵션
0:	Trunk,	Tagged
1:	Untagged

Example:
Example

{
		"vlan_num":	1,
		"vlan_opt":	0
}

Response

HTTP status code 200

VLAN 추가 성공

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

vlan_id: required (integer)
vlan_id
VLAN ID

vlan_name
vlan_name: required (string)
VLAN 이름

Example:
Example

{
		"code":	"ok",
		"result":	{
				"vlan_id":	1,
				"vlan_name":	"VLAN	ID	1	(Trunk,	Tagged)"
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

DELETE

/qos/profiles/{pid}/vlan/numbers

VLAN 목록을 일괄 삭제한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	5인	QoS	프로파일	ID	여야함

Annotations

SupportedVersion:
SupportedVersion

"4단계	스쿨넷"

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

vlan_id_list
vlan_id_list: required (array of object)
웹 카테고리 목록

items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"vlan_id_list":	[
				{"vlan_id":	1},
				{"vlan_id":	2}
		]
}

Response

HTTP status code 200

VLAN 목록 삭제 성공

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

Example:
Example

//	성공
{
		"code":	"ok",
		"result":	{
		}
}

//	전체	또는	일부	실패
{
		"code":	"nok",
		"result":	{
				"errors":	[
						{
								"vlan_id":	1,
								"qos_prf_id":	3,
								"cause":	"1은(는)	존재하지	않는	vlan_id	항목입니다.(12001)"
						},
						{
								"vlan_id":	2,
								"qos_prf_id":	3,
								"cause":	"2은(는)	존재하지	않는	vlan_id	항목입니다.(12001)"
						}
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

DELETE

/qos/profiles/{pid}/vlan/numbers/{vid}

선택된 VLAN을 삭제한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	5인	QoS	프로파일	ID	여야함

vidvid: required (integer)
VLAN ID (vlan_id)

Annotations

SupportedVersion:
SupportedVersion

"4단계	스쿨넷"

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

VLAN 삭제 성공

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

message: required (string)
message
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

큐에 설정된 VLAN 목록

GET

/qos/profiles/{pid}/queues/{qid}/vlans

큐에 설정된 VLAN 목록을 조회한다.

Request

URI Parameters

pidpid: required (integer)
QoS 프로파일 ID (qos_prf_id)
프로파일의	qos_prf_type	속성이	5인	QoS	프로파일	ID	여야함

qidqid: required (integer)
큐 ID (qos_class_id)

Annotations

SupportedVersion:
SupportedVersion

"4단계	스쿨넷"

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

VLAN 큐 목록 조회 성공

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
result: required (array of VLAN 정보)
결과 데이터

Items: VLAN 정보
Items

vlan_id
vlan_id: required (integer)
VLAN ID

vlan_name
vlan_name: required (string)
VLAN 명

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"vlan_id":	1,
				"vlan_name":	"VLAN	명"
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

QoS 프로파일 적용/취소

PUT

/command/qos-profiles/apply

QoS 프로파일을 적용합니다.

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

QoS 프로파일 적용 성공

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

/command/qos-profiles/cancel

QoS 프로파일을 취소합니다.

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

QoS 프로파일 취소 성공

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

