GET

GET

GET

POST

PUT

  DELETE

GET

PUT

  DELETE

PUT

PUT

QoS 정책 설정 REST API 문서

https://{url}/api/po

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/po

설정 가능한 인터페이스 목록

/qos/able/interfaces

QoS 정책

/qos/all/policies

/qos/policies

/qos/policies/{pk}

QoS 정책 적용/취소

/command/qos-policies/apply

/command/qos-policies/cancel

설정 가능한 인터페이스 목록

GET

/qos/able/interfaces

설정 가능한 인터페이스 목록을 조회한다.

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

설정 가능한 인터페이스 목록 조회 성공

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
result: required (array of Inf)
결과 데이터

Items: Inf
Items

ifc_id
ifc_id: required (integer)
인터페이스 ID

ifc_name: required (string)
ifc_name
인터페이스 이름

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ifc_id":	1,
				"ifc_name":	"eth0"
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

QoS 정책

GET

/qos/all/policies

(GUI 호출 전용) NGF와 TAMS에서 생성된 QoS 정책 목록을 조회한다.

아래 기능에서 사용된다.

QoS 정책 설정

Request

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

QoS 정책 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of QosGetPolicyList)
result
결과 데이터

Items: QosGetPolicyList
Items

ifc_id
ifc_id: required (integer)
인터페이스 ID

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

ifc_name
ifc_name: required (string)
인터페이스 이름

shadow
shadow: required (one of 0, 1)
shadow 정책 여부
0:	shadow	정책	아님,	1:	shadow	정책

system
system: required (one of 0, 1)
제어대상
0:	인터페이스,	1:	시스템

qos_prf
qos_prf: required (array of QosGetProfile)
Items: QosGetProfile
Items

qos_prf_id
qos_prf_id: required (integer)
QoS 프로파일 ID

seqseq: required (integer)
프로파일 적용 순서

prf_name
prf_name: required (string)
프로파일 이름

qos_prf_type
qos_prf_type: required (integer)
프로파일 타입
1:	방화벽	QoS	프로파일
2:	사용자	QoS	프로파일
3:	애플리케이션	QoS	프로파일
4:	웹	카테고리	QoS	프로파일(2.0.0부터	지원)
5:	VLAN	QoS	프로파일(4단계	스쿨넷부터	지원)

cfg_layer
cfg_layer: required (integer)
TAMS 연동을 위한 속성

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ifc_id":	1,
				"ifc_name":	"eth0",
				"use":	1,
				"shadow":	0,
				"system":	0,
				"cfg_layer":	0,
				"qos_prf":	[{
						"use":	0,
						"seq":	1,
						"qos_prf_id":	1,
						"qos_prf_type":	1,
						"prf_name":	"프로파일	이름"
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

GET

/qos/policies

QoS 정책 목록을 조회한다.

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

Response

HTTP status code 200

QoS 정책 목록 조회 성공

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
result: required (array of QosGetPolicyList)
결과 데이터

Items: QosGetPolicyList
Items

ifc_id
ifc_id: required (integer)
인터페이스 ID

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

ifc_name
ifc_name: required (string)
인터페이스 이름

shadow
shadow: required (one of 0, 1)
shadow 정책 여부
0:	shadow	정책	아님,	1:	shadow	정책

system
system: required (one of 0, 1)
제어대상
0:	인터페이스,	1:	시스템

qos_prf: required (array of QosGetProfile)
qos_prf
Items: QosGetProfile
Items

qos_prf_id
qos_prf_id: required (integer)
QoS 프로파일 ID

seqseq: required (integer)
프로파일 적용 순서

prf_name
prf_name: required (string)
프로파일 이름

qos_prf_type
qos_prf_type: required (integer)
프로파일 타입
1:	방화벽	QoS	프로파일
2:	사용자	QoS	프로파일
3:	애플리케이션	QoS	프로파일
4:	웹	카테고리	QoS	프로파일(2.0.0부터	지원)
5:	VLAN	QoS	프로파일(4단계	스쿨넷부터	지원)

cfg_layer: required (integer)
cfg_layer
TAMS 연동을 위한 속성

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ifc_id":	1,
				"ifc_name":	"eth0",
				"use":	1,
				"shadow":	0,
				"system":	0,
				"cfg_layer":	0,
				"qos_prf":	[{
						"use":	0,
						"seq":	1,
						"qos_prf_id":	1,
						"qos_prf_type":	1,
						"prf_name":	"프로파일	이름"
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
		"dev_t":	"Authentication	Error"
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"dev_t":	"Authentication	Error",
		"message":	"인가되지	않은	API	요청입니다."
}

POST

/qos/policies

QoS 정책를 추가한다.

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
ifc_id
ifc_id: required (integer)
인터페이스 ID

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

qos_prf
qos_prf: required (array of QosProfile)
Items: QosProfile
Items

qos_prf_id
qos_prf_id: required (integer)
QoS 프로파일 ID

Example:
Example

{
		"ifc_id":	1,
		"use":	1,
		"qos_prf":	[{
				"qos_prf_id":	1
		}]
}

Response

HTTP status code 200

QoS 정책 추가 성공

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

ifc_id
ifc_id: required (integer)
인터페이스 ID

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

ifc_name
ifc_name: required (string)
인터페이스 이름

shadow
shadow: required (one of 0, 1)
shadow 정책 여부
0:	shadow	정책	아님,	1:	shadow	정책

system
system: required (one of 0, 1)
제어대상
0:	인터페이스,	1:	시스템

qos_prf: required (array of QosGetProfile)
qos_prf
Items: QosGetProfile
Items

qos_prf_id
qos_prf_id: required (integer)
QoS 프로파일 ID

seqseq: required (integer)
프로파일 적용 순서

prf_name
prf_name: required (string)
프로파일 이름

qos_prf_type
qos_prf_type: required (integer)
프로파일 타입
1:	방화벽	QoS	프로파일
2:	사용자	QoS	프로파일
3:	애플리케이션	QoS	프로파일
4:	웹	카테고리	QoS	프로파일(2.0.0부터	지원)
5:	VLAN	QoS	프로파일(4단계	스쿨넷부터	지원)

cfg_layer
cfg_layer: required (integer)
TAMS 연동을 위한 속성

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
				"ifc_id":	1,
				"ifc_name":	"eth0",
				"use":	1,
				"qos_prf":	[{
						"seq":	1,
						"qos_prf_id":	1,
						"qos_prf_type":	1,
						"prf_name":	"프로파일	이름"
				}],
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

/qos/policies

QoS 정책 목록을 (일괄)수정한다.

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
items: required (array of object)
수정될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"ifc_id":	1,	"use":	1},
				{"ifc_id":	2,	"use":	1}
		]
}

Response

HTTP status code 200

QoS 정책 목록 수정 성공

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

/qos/policies

QoS 정책 목록을 (일괄)삭제한다.

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
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"ifc_id":	1},
				{"ifc_id":	2}
		]
}

Response

HTTP status code 200

QoS 정책 목록 삭제 성공

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

result: required (object)
result
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

/qos/policies/{pk}

QoS 정책을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
인터페이스 ID (ifc_id)

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

QoS 정책 조회 성공

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

ifc_id
ifc_id: required (integer)
인터페이스 ID

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

ifc_name
ifc_name: required (string)
인터페이스 이름

shadow
shadow: required (one of 0, 1)
shadow 정책 여부
0:	shadow	정책	아님,	1:	shadow	정책

system
system: required (one of 0, 1)
제어대상
0:	인터페이스,	1:	시스템

qos_prf: required (array of QosGetProfile)
qos_prf
Items: QosGetProfile
Items

qos_prf_id
qos_prf_id: required (integer)
QoS 프로파일 ID

seqseq: required (integer)
프로파일 적용 순서

prf_name
prf_name: required (string)
프로파일 이름

qos_prf_type
qos_prf_type: required (integer)
프로파일 타입
1:	방화벽	QoS	프로파일
2:	사용자	QoS	프로파일
3:	애플리케이션	QoS	프로파일
4:	웹	카테고리	QoS	프로파일(2.0.0부터	지원)
5:	VLAN	QoS	프로파일(4단계	스쿨넷부터	지원)

cfg_layer: required (integer)
cfg_layer
TAMS 연동을 위한 속성

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
				"ifc_id":	1,
				"ifc_name":	"eth0",
				"use":	1,
				"qos_prf":	[{
						"seq":	1,
						"qos_prf_id":	1,
						"qos_prf_type":	1,
						"prf_name":	"프로파일명"
				}],
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

/qos/policies/{pk}

QoS 정책을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
인터페이스 ID (ifc_id)

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
ifc_id
ifc_id: required (integer)
인터페이스 ID

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

qos_prf
qos_prf: required (array of QosProfile)
Items: QosProfile
Items

qos_prf_id
qos_prf_id: required (integer)
QoS 프로파일 ID

Example:
Example

{
		"ifc_id":	1,
		"use":	1,
		"qos_prf":	[{
				"qos_prf_id":	1
		}]
}

Response

HTTP status code 200

QoS 정책 수정 성공

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

ifc_id
ifc_id: required (integer)
인터페이스 ID

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

ifc_name
ifc_name: required (string)
인터페이스 이름

shadow
shadow: required (one of 0, 1)
shadow 정책 여부
0:	shadow	정책	아님,	1:	shadow	정책

system
system: required (one of 0, 1)
제어대상
0:	인터페이스,	1:	시스템

qos_prf
qos_prf: required (array of QosGetProfile)
Items: QosGetProfile
Items

qos_prf_id
qos_prf_id: required (integer)
QoS 프로파일 ID

seqseq: required (integer)
프로파일 적용 순서

prf_name
prf_name: required (string)
프로파일 이름

qos_prf_type: required (integer)
qos_prf_type
프로파일 타입
1:	방화벽	QoS	프로파일
2:	사용자	QoS	프로파일
3:	애플리케이션	QoS	프로파일
4:	웹	카테고리	QoS	프로파일(2.0.0부터	지원)
5:	VLAN	QoS	프로파일(4단계	스쿨넷부터	지원)

cfg_layer
cfg_layer: required (integer)
TAMS 연동을 위한 속성

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
				"ifc_id":	1,
				"ifc_name":	"eth0",
				"use":	1,
				"qos_prf":	[{
						"seq":	1,
						"qos_prf_id":	1,
						"qos_prf_type":	1,
						"prf_name":	"프로파일	이름"
				}],
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

/qos/policies/{pk}

QoS 정책을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
인터페이스 ID (ifc_id)

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

QoS 정책 삭제 성공

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

QoS 정책 적용/취소

PUT

/command/qos-policies/apply

QoS 정책을 적용합니다.

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

QoS 정책 적용 성공

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

/command/qos-policies/cancel

QoS 정책을 취소합니다.

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

QoS 정책 취소 성공

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

