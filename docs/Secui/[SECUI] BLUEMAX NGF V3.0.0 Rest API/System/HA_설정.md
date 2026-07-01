HA 설정 REST API 문서

https://{url}/api/sm

urlurl: required (string)
장비 IP

HA 설정

/ha/config

/ha/config/uuid

/ha/config/members

/ha/config/members/reference

/ha/config/members/{ha_mmbr_id}

/ha/config/members/{ha_mmbr_id}/reference

/ha/config/apply

/ha/config/cancel

HA 고급 설정

/ha/advance

/ha/advance/apply

/ha/advance/cancel

가상 IP가 설정된 인터페이스

/ha/virtual-ip-selfs

가상 IP

/ha/virtual-ips

/ha/virtual-ips/{vip_id}

/ha/virtual-ips/interface-candidates

/ha/virtual-ips/apply

/ha/virtual-ips/cancel

가상 IP 고급 설정

/ha/virtual-ips/advance

/ha/virtual-ips/advance/apply

/ha/virtual-ips/advance/cancel

현재 상태 > HA 멤버 상태 > HA 초기화

/ha/reset

현재 상태 > HA 가상 IP 주소 > 수동 장애복구

/ha/virtual-ips/failure-recovery

/ha/virtual-ips/failover-mode

/ha/virtual-ips/failover-mode

HA 설정

GET

/ha/config

HA 설정을(를) 조회한다.

GET

PUT

GET

PUT

POST

GET

POST

  DELETE

GET

GET

PUT

  DELETE

GET

PUT

PUT

GET

PUT

PUT

PUT

GET

GET

GET

POST

  DELETE

PUT

  DELETE

GET

PUT

PUT

GET

PUT

PUT

PUT

POST

POST

GET

PUT

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

HA 설정 조회 성공

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

modemode: required (one of 0, 1, 2, 3)
동작 모드 (stand-alone:	0,	active-active:	1,	active-standby:	2,	high-level-sync:	3)

grp_name: required (string - maxLength: 16)
grp_name
HA 그룹 이름

hello_intval
hello_intval: required (number - minimum: 0.1 - maximum: 15.9)
Hello 전송 주기

calc_chksum: required (one of 0, 1)
calc_chksum
HA 제어 패킷 체크섬 검사 (OFF:	0,	ON:	1)

io_err_failover
io_err_failover: required (one of 0, 1)
HDD 장애시 Fail Over (OFF:	0,	ON:	1)

packet_divert
packet_divert: required (one of 0, 1)
HA 고급 동기화 (OFF:	0,	ON:	1)

cloud_flag
cloud_flag: (one of 0, 1)
퍼블릭 클라우드 여부(VE에서 사용되는 설정)
1로	출력되면	퍼블릭	클라우드

Example:
Example

{
		"code":	"ok",
		"result":	{
				"mode"	:	0,
				"grp_name"	:	"그룹이름",
				"hello_intval"	:	0.1,
				"calc_chksum"	:	0,
				"io_err_failover"	:	0,
				"packet_divert"	:	0,
				"cloud_flag":	0
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

/ha/config

HA 설정을(를) 수정한다.

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

modemode: required (one of 0, 1, 2, 3)
동작 모드 (stand-alone:	0,	active-active:	1,	active-standby:	2,	high-level-sync:	3)

grp_name
grp_name: required (string - maxLength: 16)
HA 그룹 이름

Example:
Example

{
		"mode"	:	0,
		"grp_name"	:	"그룹이름"
}

Response

HTTP status code 200

HA 설정 수정 성공

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

modemode: required (one of 0, 1, 2, 3)
동작 모드 (stand-alone:	0,	active-active:	1,	active-standby:	2,	high-level-sync:	3)

grp_name
grp_name: required (string - maxLength: 16)
HA 그룹 이름

hello_intval
hello_intval: required (number - minimum: 0.1 - maximum: 15.9)
Hello 전송 주기

calc_chksum
calc_chksum: required (one of 0, 1)
HA 제어 패킷 체크섬 검사 (OFF:	0,	ON:	1)

io_err_failover
io_err_failover: required (one of 0, 1)
HDD 장애시 Fail Over (OFF:	0,	ON:	1)

packet_divert
packet_divert: required (one of 0, 1)
HA 고급 동기화 (OFF:	0,	ON:	1)

cloud_flag: (one of 0, 1)
cloud_flag
퍼블릭 클라우드 여부(VE에서 사용되는 설정)
1로	출력되면	퍼블릭	클라우드

Example:
Example

{
		"code":	"ok",
		"result":	{
				"mode"	:	0,
				"grp_name"	:	"그룹이름",
				"hello_intval"	:	0.1,
				"calc_chksum"	:	0,
				"io_err_failover"	:	0,
				"packet_divert"	:	0,
				"cloud_flag":	0
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

/ha/config/uuid

장비 고유 ID을(를) 조회한다.

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

장비 고유 ID 조회 성공

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

host_uuid
host_uuid: required (string)
장비 고유 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"host_uuid"	:	"NGF01234567890UUID"
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

/ha/config/uuid

장비 고유 ID을(를) 수정한다.

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

host_uuid
host_uuid: required (string)
장비 고유 ID

Example:
Example

{
		"host_uuid"	:	"NGF01234567890UUID"
}

Response

HTTP status code 200

장비 고유 ID 수정 성공

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

host_uuid
host_uuid: required (string)
장비 고유 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"host_uuid"	:	"NGF01234567890UUID"
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

POST

/ha/config/uuid

장비 고유 ID를 자동 생성 한다.

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

장비 고유 ID 추가 성공

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

host_uuid
host_uuid: required (string)
장비 고유 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"host_uuid"	:	"NGF01234567890UUID"
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

GET

/ha/config/members

HA 멤버 목록을 조회한다.

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

HA 멤버 목록 조회 성공

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
result: required (array of ha_member)
Items: ha_member
Items

ha_mmbr_id
ha_mmbr_id: (integer)
ID

mmbr_uuid
mmbr_uuid: required (string - maxLength: 16)
멤버의 장비 고유 ID

hostname: (string)
hostname
호스트이름

rolerole: required (one of 1, 2)
역할 (master:	1,	slave:	2)

prioprio: required (integer - minimum: 1 - maximum: 16)
우선순위

descdesc: required (string - maxLength: 64)
설명

ipip: (string)
VE 모델에서 퍼블릭 클라우드에서 HA 설정에 사용되는 IP
물리장비에서는 설정할 필요가 없음

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"ha_mmbr_id"	:	1,
						"mmbr_uuid"	:	"멤버	UUID",
						"hostname"	:	"멤버	호스트이름",
						"role"	:	1,
						"prio"	:	16,
						"desc"	:	"설명",
						"ip":	null
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

POST

/ha/config/members

HA 멤버를 추가한다.

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

Properties
Properties

ha_mmbr_id
ha_mmbr_id: (integer)
ID

mmbr_uuid
mmbr_uuid: required (string - maxLength: 16)
멤버의 장비 고유 ID

hostname
hostname: (string)
호스트이름

rolerole: required (one of 1, 2)
역할 (master:	1,	slave:	2)

prioprio: required (integer - minimum: 1 - maximum: 16)
우선순위

descdesc: required (string - maxLength: 64)
설명

ipip: (string)
VE 모델에서 퍼블릭 클라우드에서 HA 설정에 사용되는 IP
물리장비에서는 설정할 필요가 없음

Example:
Example

{
		"mmbr_uuid"	:	"멤버	UUID",
		"role"	:	1,
		"prio"	:	16,
		"desc"	:	"설명",
		"ip":	null
}

Response

HTTP status code 200

HA 멤버 추가 성공

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

ha_mmbr_id
ha_mmbr_id: (integer)
ID

mmbr_uuid
mmbr_uuid: required (string - maxLength: 16)
멤버의 장비 고유 ID

hostname
hostname: (string)
호스트이름

rolerole: required (one of 1, 2)
역할 (master:	1,	slave:	2)

prioprio: required (integer - minimum: 1 - maximum: 16)
우선순위

descdesc: required (string - maxLength: 64)

설명

ipip: (string)
VE 모델에서 퍼블릭 클라우드에서 HA 설정에 사용되는 IP
물리장비에서는 설정할 필요가 없음

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ha_mmbr_id"	:	1,
				"mmbr_uuid"	:	"멤버	UUID",
				"hostname"	:	"멤버	호스트이름",
				"role"	:	1,
				"prio"	:	16,
				"desc"	:	"설명",
				"ip":	null
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

/ha/config/members

HA 멤버 목록을 (일괄)삭제한다.

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
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"ha_mmbr_id":	1},
				{"ha_mmbr_id":	2}
		]
}

Response

HTTP status code 200

HA 멤버 목록 삭제 성공

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

GET

/ha/config/members/reference

HA 멤버 참조을(를) 조회한다.

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

HA 멤버 참조 조회 성공

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

vipvip: required (one of 0, 1)
Virtaul IP에서 참조 여부 (미참조:	0,	참조:	1)

rt_backup
rt_backup: required (one of 0, 1)
Router Backup에서 참조 여부 (미참조:	0,	참조:	1)

vpnvpn: required (one of 0, 1)
VPN에서 참조 여부 (미참조:	0,	참조:	1)

natnat: required (one of 0, 1)
NAT 정책에서 참조 여부 (미참조:	0,	참조:	1)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"vip"	:	0,
				"rt_backup"	:	0,
				"vpn"	:	0,
				"nat"	:	0
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

/ha/config/members/{ha_mmbr_id}

HA 멤버을(를) 조회한다.

Request

URI Parameters

ha_mmbr_id
ha_mmbr_id: required (string)
ID

Example:
Example

10

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

HA 멤버 조회 성공

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

ha_mmbr_id
ha_mmbr_id: (integer)
ID

mmbr_uuid
mmbr_uuid: required (string - maxLength: 16)
멤버의 장비 고유 ID

hostname
hostname: (string)
호스트이름

rolerole: required (one of 1, 2)
역할 (master:	1,	slave:	2)

prioprio: required (integer - minimum: 1 - maximum: 16)
우선순위

descdesc: required (string - maxLength: 64)
설명

ipip: (string)
VE 모델에서 퍼블릭 클라우드에서 HA 설정에 사용되는 IP
물리장비에서는 설정할 필요가 없음

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ha_mmbr_id"	:	1,
				"mmbr_uuid"	:	"멤버	UUID",
				"hostname"	:	"멤버	호스트이름",
				"role"	:	1,
				"prio"	:	16,
				"desc"	:	"설명",
				"ip":	null
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

/ha/config/members/{ha_mmbr_id}

HA 멤버을(를) 수정한다.

Request

URI Parameters

ha_mmbr_id: required (string)
ha_mmbr_id
ID

Example:
Example

10

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

ha_mmbr_id
ha_mmbr_id: (integer)
ID

mmbr_uuid
mmbr_uuid: required (string - maxLength: 16)
멤버의 장비 고유 ID

hostname
hostname: (string)
호스트이름

rolerole: required (one of 1, 2)
역할 (master:	1,	slave:	2)

prioprio: required (integer - minimum: 1 - maximum: 16)
우선순위

descdesc: required (string - maxLength: 64)
설명

ipip: (string)
VE 모델에서 퍼블릭 클라우드에서 HA 설정에 사용되는 IP
물리장비에서는 설정할 필요가 없음

Example:
Example

{
		"mmbr_uuid"	:	"멤버	UUID",
		"role"	:	1,
		"prio"	:	16,
		"desc"	:	"설명",
		"ip":	null
}

Response

HTTP status code 200

HA 멤버 수정 성공

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

ha_mmbr_id
ha_mmbr_id: (integer)
ID

mmbr_uuid: required (string - maxLength: 16)
mmbr_uuid
멤버의 장비 고유 ID

hostname
hostname: (string)
호스트이름

rolerole: required (one of 1, 2)
역할 (master:	1,	slave:	2)

prioprio: required (integer - minimum: 1 - maximum: 16)
우선순위

descdesc: required (string - maxLength: 64)
설명

ipip: (string)
VE 모델에서 퍼블릭 클라우드에서 HA 설정에 사용되는 IP
물리장비에서는 설정할 필요가 없음

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ha_mmbr_id"	:	1,
				"mmbr_uuid"	:	"멤버	UUID",
				"hostname"	:	"멤버	호스트이름",
				"role"	:	1,
				"prio"	:	16,
				"desc"	:	"설명",
				"ip":	null
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

/ha/config/members/{ha_mmbr_id}

HA 멤버을(를) 삭제한다.

Request

URI Parameters

ha_mmbr_id
ha_mmbr_id: required (string)
ID

Example:
Example

10

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

HA 멤버 삭제 성공

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

GET

/ha/config/members/{ha_mmbr_id}/reference

HA 멤버 참조을(를) 조회한다.

Request

URI Parameters

ha_mmbr_id
ha_mmbr_id: required (string)
ID

Example:
Example

10

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

HA 멤버 참조 조회 성공

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

vipvip: required (one of 0, 1)
Virtaul IP에서 참조 여부 (미참조:	0,	참조:	1)

rt_backup
rt_backup: required (one of 0, 1)
Router Backup에서 참조 여부 (미참조:	0,	참조:	1)

vpnvpn: required (one of 0, 1)
VPN에서 참조 여부 (미참조:	0,	참조:	1)

natnat: required (one of 0, 1)
NAT 정책에서 참조 여부 (미참조:	0,	참조:	1)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"vip"	:	0,
				"rt_backup"	:	0,
				"vpn"	:	0,
				"nat"	:	0
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

/ha/config/apply

HA 설정을 적용합니다.

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
logout
logout: (boolean - default: false)
로그아웃

Example:
Example

{
		"logout"	:	false
}

Response

HTTP status code 200

HA 설정 적용 성공

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

/ha/config/cancel

HA 설정을 취소합니다.

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

HA 설정 취소 성공

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

HA 고급 설정

GET

/ha/advance

HA 고급 설정을(를) 조회한다.

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

HA 고급 설정 조회 성공

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

modemode: required (one of 0, 1, 2, 3)
동작 모드 (stand-alone:	0,	active-active:	1,	active-standby:	2,	high-level-sync:	3)

grp_name
grp_name: required (string - maxLength: 16)
HA 그룹 이름

hello_intval
hello_intval: required (number - minimum: 0.1 - maximum: 15.9)
Hello 전송 주기

calc_chksum
calc_chksum: required (one of 0, 1)
HA 제어 패킷 체크섬 검사 (OFF:	0,	ON:	1)

io_err_failover
io_err_failover: required (one of 0, 1)
HDD 장애시 Fail Over (OFF:	0,	ON:	1)

packet_divert: required (one of 0, 1)
packet_divert
HA 고급 동기화 (OFF:	0,	ON:	1)

cloud_flag
cloud_flag: (one of 0, 1)
퍼블릭 클라우드 여부(VE에서 사용되는 설정)
1로	출력되면	퍼블릭	클라우드

Example:
Example

{
		"code":	"ok",
		"result":	{
				"mode"	:	0,
				"grp_name"	:	"그룹이름",
				"hello_intval"	:	0.1,
				"calc_chksum"	:	0,
				"io_err_failover"	:	0,
				"packet_divert"	:	0,
				"cloud_flag":	0
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

/ha/advance

HA 고급 설정을(를) 수정한다.

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

hello_intval: required (number - minimum: 0.1 - maximum: 15.9)
hello_intval
Hello 전송 주기

calc_chksum
calc_chksum: required (one of 0, 1)
HA 제어 패킷 체크섬 검사 (OFF:	0,	ON:	1)

io_err_failover
io_err_failover: required (one of 0, 1)
HDD 장애시 Fail Over (OFF:	0,	ON:	1)

packet_divert
packet_divert: required (one of 0, 1)
HA 고급 동기화 (OFF:	0,	ON:	1)

Example:
Example

{
		"hello_intval"	:	0.1,
		"calc_chksum"	:	0,
		"io_err_failover"	:	0,
		"packet_divert"	:	0
}

Response

HTTP status code 200

HA 고급 설정 수정 성공

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

modemode: required (one of 0, 1, 2, 3)
동작 모드 (stand-alone:	0,	active-active:	1,	active-standby:	2,	high-level-sync:	3)

grp_name: required (string - maxLength: 16)
grp_name
HA 그룹 이름

hello_intval
hello_intval: required (number - minimum: 0.1 - maximum: 15.9)
Hello 전송 주기

calc_chksum
calc_chksum: required (one of 0, 1)
HA 제어 패킷 체크섬 검사 (OFF:	0,	ON:	1)

io_err_failover
io_err_failover: required (one of 0, 1)
HDD 장애시 Fail Over (OFF:	0,	ON:	1)

packet_divert
packet_divert: required (one of 0, 1)
HA 고급 동기화 (OFF:	0,	ON:	1)

cloud_flag
cloud_flag: (one of 0, 1)
퍼블릭 클라우드 여부(VE에서 사용되는 설정)
1로	출력되면	퍼블릭	클라우드

Example:
Example

{
		"code":	"ok",
		"result":	{
				"mode"	:	0,
				"grp_name"	:	"그룹이름",
				"hello_intval"	:	0.1,
				"calc_chksum"	:	0,
				"io_err_failover"	:	0,
				"packet_divert"	:	0
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

PUT

/ha/advance/apply

HA 고급 설정을 적용합니다.

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

HA 고급 설정 적용 성공

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

/ha/advance/cancel

HA 고급 설정을 취소합니다.

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

HA 고급 설정 취소 성공

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

가상 IP가 설정된 인터페이스

GET

/ha/virtual-ip-selfs

가상 IP가 설정된 인터페이스 목록을 조회한다.

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

Query Parameters

ip_ver
ip_ver: (one of 4, 6 - default: 4)
IP Version (IPv4:	4,	IPv6:	6)

Example:
Example

?ip_ver=4

Response

HTTP status code 200

가상 IP가 설정된 인터페이스 목록 조회 성공

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
result: required (array of vip)
Items: vip
Items

vip_id
vip_id: (integer)
ID

zone
zone: required (one of 1, 2, 3)
Zone (내부망:	1,	외부망:	2,	DMZ:	3)

zone_id: required (integer)
zone_id
Zone ID

ha_mmbr_id
ha_mmbr_id: required (integer)
멤버 Table ID

mmbr_uuid
mmbr_uuid: required (string)
멤버 UUID 문자열

mmbr_hostname
mmbr_hostname: required (string)
멤버 호스트이름

ifc_name
ifc_name: required (string)
인터페이스 이름

vridvrid: required (integer - minimum: 1 - maximum: 255)
VRID

ip_ver
ip_ver: required (one of 4, 6)
IP 주소 버전 (IPv4:	4,	IPv6:	6)

ipip: required (string)
가상 IP(IPv4 Address or IPv6 Address)

netmask: required (integer)
netmask
Netmask

riprip: required (string)
참조 IP(IPv4 Address or IPv6 Address)

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"vip_id"	:	1,
						"zone"	:	1,
						"zone_id"	:	0,
						"ha_mmbr_id"	:	1,
						"mmbr_uuid"	:	"NGF0123456789ABC",
						"mmbr_hostname"	:	"NGF001",
						"ifc_name"	:	"eth0",
						"vrid"	:	1,
						"ip_ver"	:	4,
						"ip"	:	"192.168.0.1",
						"netmask"	:	24,
						"rip"	:	"192.168.0.254"
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

가상 IP

GET

/ha/virtual-ips

가상 IP 목록을 조회한다.

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

가상 IP 목록 조회 성공

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
result: required (array of vip_grp)
Items: vip_grp
Items

name: required (string)
name
그룹 이름

zone
zone: required (one of 1, 2, 3)
Zone (내부망:	1,	외부망:	2,	DMZ:	3)

zone_id
zone_id: required (integer)
Zone ID

children
children: (array of vip)
Virtual IP 목록(vip)

Items: vip
Items

vip_id
vip_id: (integer)
ID

zone
zone: required (one of 1, 2, 3)
Zone (내부망:	1,	외부망:	2,	DMZ:	3)

zone_id
zone_id: required (integer)
Zone ID

ha_mmbr_id: required (integer)
ha_mmbr_id
멤버 Table ID

mmbr_uuid
mmbr_uuid: required (string)
멤버 UUID 문자열

mmbr_hostname
mmbr_hostname: required (string)
멤버 호스트이름

ifc_name
ifc_name: required (string)
인터페이스 이름

vridvrid: required (integer - minimum: 1 - maximum: 255)
VRID

ip_ver: required (one of 4, 6)
ip_ver
IP 주소 버전 (IPv4:	4,	IPv6:	6)

ipip: required (string)
가상 IP(IPv4 Address or IPv6 Address)

netmask
netmask: required (integer)
Netmask

riprip: required (string)
참조 IP(IPv4 Address or IPv6 Address)

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"name"	:	"I-VIG0",
						"zone"	:	1,
						"zone_id"	:	0,
						"children":[
								{
										"vip_id"	:	1,
										"zone"	:	1,
										"zone_id"	:	0,
										"ha_mmbr_id"	:	1,
										"mmbr_uuid"	:	"NGF0123456789ABC",
										"mmbr_hostname"	:	"NGF001",
										"ifc_name"	:	"eth0",
										"vrid"	:	1,
										"ip_ver"	:	4,
										"ip"	:	"192.168.0.1",
										"netmask"	:	24,
										"rip"	:	"192.168.0.254"
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

/ha/virtual-ips

가상 IP를 추가한다.

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
vip_id
vip_id: (integer)
ID

zone: required (one of 1, 2, 3)
zone
Zone (내부망:	1,	외부망:	2,	DMZ:	3)

zone_id
zone_id: required (integer)
Zone ID

ha_mmbr_id
ha_mmbr_id: required (integer)
멤버 Table ID

mmbr_uuid
mmbr_uuid: required (string)
멤버 UUID 문자열

mmbr_hostname
mmbr_hostname: required (string)
멤버 호스트이름

ifc_name
ifc_name: required (string)
인터페이스 이름

vridvrid: required (integer - minimum: 1 - maximum: 255)
VRID

ip_ver: required (one of 4, 6)
ip_ver
IP 주소 버전 (IPv4:	4,	IPv6:	6)

ipip: required (string)
가상 IP(IPv4 Address or IPv6 Address)

netmask
netmask: required (integer)
Netmask

riprip: required (string)
참조 IP(IPv4 Address or IPv6 Address)

Example:
Example

{
		"zone"	:	1,
		"zone_id"	:	0,
		"ha_mmbr_id"	:	1,
		"mmbr_uuid"	:	"NGF0123456789ABC",
		"mmbr_hostname"	:	"NGF001",
		"ifc_name"	:	"eth0",
		"vrid"	:	1,
		"ip_ver"	:	4,
		"ip"	:	"192.168.0.1",
		"netmask"	:	24,
		"rip"	:	"192.168.0.254"
}

Response

HTTP status code 200

가상 IP 추가 성공

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
vip_id
vip_id: (integer)
ID

zone
zone: required (one of 1, 2, 3)
Zone (내부망:	1,	외부망:	2,	DMZ:	3)

zone_id
zone_id: required (integer)
Zone ID

ha_mmbr_id: required (integer)
ha_mmbr_id
멤버 Table ID

mmbr_uuid
mmbr_uuid: required (string)
멤버 UUID 문자열

mmbr_hostname: required (string)
mmbr_hostname

멤버 호스트이름

ifc_name
ifc_name: required (string)
인터페이스 이름

vridvrid: required (integer - minimum: 1 - maximum: 255)
VRID

ip_ver
ip_ver: required (one of 4, 6)
IP 주소 버전 (IPv4:	4,	IPv6:	6)

ipip: required (string)
가상 IP(IPv4 Address or IPv6 Address)

netmask
netmask: required (integer)
Netmask

riprip: required (string)
참조 IP(IPv4 Address or IPv6 Address)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"vip_id"	:	1,
				"zone"	:	1,
				"zone_id"	:	0,
				"ha_mmbr_id"	:	1,
				"mmbr_uuid"	:	"NGF0123456789ABC",
				"mmbr_hostname"	:	"NGF001",
				"ifc_name"	:	"eth0",
				"vrid"	:	1,
				"ip_ver"	:	4,
				"ip"	:	"192.168.0.1",
				"netmask"	:	24,
				"rip"	:	"192.168.0.254"
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

/ha/virtual-ips

가상 IP 목록을 (일괄)삭제한다.

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
items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"vip_id":	1},
				{"vip_id":	2}
		]
}

Response

HTTP status code 200

가상 IP 목록 삭제 성공

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

/ha/virtual-ips/{vip_id}

가상 IP을(를) 조회한다.

Request

URI Parameters

vip_id
vip_id: required (string)
ID

Example:
Example

10

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

가상 IP 조회 성공

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
vip_id
vip_id: (integer)
ID

zone
zone: required (one of 1, 2, 3)
Zone (내부망:	1,	외부망:	2,	DMZ:	3)

zone_id: required (integer)
zone_id
Zone ID

ha_mmbr_id
ha_mmbr_id: required (integer)
멤버 Table ID

mmbr_uuid
mmbr_uuid: required (string)
멤버 UUID 문자열

mmbr_hostname
mmbr_hostname: required (string)
멤버 호스트이름

ifc_name
ifc_name: required (string)
인터페이스 이름

vridvrid: required (integer - minimum: 1 - maximum: 255)
VRID

ip_ver
ip_ver: required (one of 4, 6)
IP 주소 버전 (IPv4:	4,	IPv6:	6)

ipip: required (string)
가상 IP(IPv4 Address or IPv6 Address)

netmask
netmask: required (integer)
Netmask

riprip: required (string)
참조 IP(IPv4 Address or IPv6 Address)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"vip_id"	:	1,
				"zone"	:	1,
				"zone_id"	:	0,
				"ha_mmbr_id"	:	1,
				"mmbr_uuid"	:	"NGF0123456789ABC",
				"mmbr_hostname"	:	"NGF001",
				"ifc_name"	:	"eth0",
				"vrid"	:	1,
				"ip_ver"	:	4,
				"ip"	:	"192.168.0.1",
				"netmask"	:	24,
				"rip"	:	"192.168.0.254"
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

/ha/virtual-ips/{vip_id}

가상 IP을(를) 수정한다.

Request

URI Parameters

vip_id
vip_id: required (string)
ID

Example:
Example

10

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
vip_id
vip_id: (integer)
ID

zone
zone: required (one of 1, 2, 3)
Zone (내부망:	1,	외부망:	2,	DMZ:	3)

zone_id
zone_id: required (integer)
Zone ID

ha_mmbr_id
ha_mmbr_id: required (integer)
멤버 Table ID

mmbr_uuid
mmbr_uuid: required (string)
멤버 UUID 문자열

mmbr_hostname: required (string)
mmbr_hostname
멤버 호스트이름

ifc_name
ifc_name: required (string)
인터페이스 이름

vridvrid: required (integer - minimum: 1 - maximum: 255)
VRID

ip_ver
ip_ver: required (one of 4, 6)
IP 주소 버전 (IPv4:	4,	IPv6:	6)

ipip: required (string)
가상 IP(IPv4 Address or IPv6 Address)

netmask
netmask: required (integer)
Netmask

riprip: required (string)
참조 IP(IPv4 Address or IPv6 Address)

Example:
Example

{
		"zone"	:	1,
		"zone_id"	:	0,
		"ha_mmbr_id"	:	1,
		"mmbr_uuid"	:	"NGF0123456789ABC",
		"mmbr_hostname"	:	"NGF001",
		"ifc_name"	:	"eth0",
		"vrid"	:	1,
		"ip_ver"	:	4,
		"ip"	:	"192.168.0.1",
		"netmask"	:	24,
		"rip"	:	"192.168.0.254"
}

Response

HTTP status code 200

가상 IP 수정 성공

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
vip_id: (integer)
vip_id
ID

zone
zone: required (one of 1, 2, 3)
Zone (내부망:	1,	외부망:	2,	DMZ:	3)

zone_id
zone_id: required (integer)
Zone ID

ha_mmbr_id
ha_mmbr_id: required (integer)
멤버 Table ID

mmbr_uuid
mmbr_uuid: required (string)
멤버 UUID 문자열

mmbr_hostname
mmbr_hostname: required (string)
멤버 호스트이름

ifc_name
ifc_name: required (string)
인터페이스 이름

vridvrid: required (integer - minimum: 1 - maximum: 255)
VRID

ip_ver
ip_ver: required (one of 4, 6)
IP 주소 버전 (IPv4:	4,	IPv6:	6)

ipip: required (string)
가상 IP(IPv4 Address or IPv6 Address)

netmask
netmask: required (integer)
Netmask

riprip: required (string)
참조 IP(IPv4 Address or IPv6 Address)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"vip_id"	:	1,
				"zone"	:	1,
				"zone_id"	:	0,
				"ha_mmbr_id"	:	1,
				"mmbr_uuid"	:	"NGF0123456789ABC",
				"mmbr_hostname"	:	"NGF001",
				"ifc_name"	:	"eth0",
				"vrid"	:	1,
				"ip_ver"	:	4,
				"ip"	:	"192.168.0.1",
				"netmask"	:	24,
				"rip"	:	"192.168.0.254"
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

/ha/virtual-ips/{vip_id}

가상 IP을(를) 삭제한다.

Request

URI Parameters

vip_id
vip_id: required (string)
ID

Example:
Example

10

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

가상 IP 삭제 성공

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

GET

/ha/virtual-ips/interface-candidates

후보 인터페이스 목록을 조회한다.

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

후보 인터페이스 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of InfIDName)
result
Items: InfIDName
Items

idid: required (integer)
인터페이스 ID

name
name: required (string)
인터페이스 이름

zone
zone: required (one of 0, 1, 2, 3, 4)
인터페이스 Zone (None:	0,	Internal:	1,	External:	2,	DMZ:	3,	HA:	4)

ipv4ipv4: required (one of 0, 1)
IPv4 설정 화면에서 설정할 수 있는 인터페이스 여부
0:	IPv4	인터페이스	목록에서	제외,	1:	IPv4	후보	인터페이스

ipv6ipv6: required (one of 0, 1)
IPv6 설정 화면에서 설정할 수 있는 인터페이스 여부
0:	IPv6	인터페이스	목록에서	제외,	1:	IPv6	후보	인터페이스

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"id":	1,
						"name":	"eth1",
						"zone":	1,
						"ipv4":	1,
						"ipv6":	0
				},
				{
						"id":	2,
						"name":	"eth2",
						"zone":	1,
						"ipv4":	1,
						"ipv6":	1
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

PUT

/ha/virtual-ips/apply

가상 IP을 적용합니다.

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

가상 IP 적용 성공

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

/ha/virtual-ips/cancel

가상 IP을 취소합니다.

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

가상 IP 취소 성공

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

가상 IP 고급 설정

GET

/ha/virtual-ips/advance

가상 IP 고급 설정을(를) 조회한다.

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

가상 IP 고급 설정 조회 성공

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

hello_intval
hello_intval: required (number - minimum: 0.1 - maximum: 25.5)
상태검사주기(초)

garp_intval
garp_intval: required (number - minimum: 0.1 - maximum: 25.5)
Gratuitous ARP / Unsolicited NA 전송 주기

garp_tx_num
garp_tx_num: required (integer - minimum: 1 - maximum: 10)
Gratuitous ARP / Unsolicited NA 전송 횟수

failback_delay_tm
failback_delay_tm: required (integer - minimum: 0 - maximum: 60)
자동 장애 복구 지연 시간(초)

manual_failback
manual_failback: required (one of 0, 1)
수동 장애 복구 (OFF:	0,	ON:	1)

vrrp_auth
vrrp_auth: required (one of 0, 1)
VRRP 인증 (OFF:	0,	ON:	1)

vrrp_auth_pw: required (string - maxLength: 4)
vrrp_auth_pw

VRRP 인증 비밀번호(Base64 인코딩)

rip_ping_req_cnt
rip_ping_req_cnt: required (integer - minimum: 1 - maximum: 10)
참조 IP에 대한 Ping 검사 횟수

ping_wait_delay: required (integer - minimum: 1 - maximum: 1000)
ping_wait_delay
참조 IP에 대한 Ping 응답대기 시간(ms)

ifup_vrrp_rx_tm
ifup_vrrp_rx_tm: required (integer - minimum: 0 - maximum: 1000)
인터페이스 UP 판단을 위한 VRRP 수신대기 시간(초)

svip_lb: required (one of 0, 1)
svip_lb
Single VIP 부하 분산 (OFF:	0,	ON:	1)

svip_lb_check_intval
svip_lb_check_intval: required (integer - minimum: 1 - maximum: 10)
Single VIP 부하 분산 상태 검사 주기(초)

svip_lb_ping_relay
svip_lb_ping_relay: required (one of 0, 1)
Single VIP 부하 분산 Ping 응답 (OFF:	0,	ON:	1)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"hello_intval"	:	0.5,
				"garp_intval"	:	15,
				"garp_tx_num"	:	5,
				"failback_delay_tm"	:	0,
				"manual_failback"	:	0,
				"vrrp_auth"	:	0,
				"vrrp_auth_pw"	:	"",
				"rip_ping_req_cnt"	:	3,
				"rip_	ping_wait_delay"	:	300,
				"ifup_vrrp_rx_tm"	:	0,
				"svip_lb"	:	0,
				"svip_lb_check_intval"	:	1,
				"svip_lb_ping_relay"	:	0
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

/ha/virtual-ips/advance

가상 IP 고급 설정을(를) 수정한다.

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

hello_intval
hello_intval: required (number - minimum: 0.1 - maximum: 25.5)
상태검사주기(초)

garp_intval
garp_intval: required (number - minimum: 0.1 - maximum: 25.5)
Gratuitous ARP / Unsolicited NA 전송 주기

garp_tx_num
garp_tx_num: required (integer - minimum: 1 - maximum: 10)
Gratuitous ARP / Unsolicited NA 전송 횟수

failback_delay_tm
failback_delay_tm: required (integer - minimum: 0 - maximum: 60)
자동 장애 복구 지연 시간(초)

manual_failback
manual_failback: required (one of 0, 1)
수동 장애 복구 (OFF:	0,	ON:	1)

vrrp_auth
vrrp_auth: required (one of 0, 1)
VRRP 인증 (OFF:	0,	ON:	1)

vrrp_auth_pw: required (string - maxLength: 4)
vrrp_auth_pw
VRRP 인증 비밀번호(Base64 인코딩)

rip_ping_req_cnt
rip_ping_req_cnt: required (integer - minimum: 1 - maximum: 10)
참조 IP에 대한 Ping 검사 횟수

ping_wait_delay
ping_wait_delay: required (integer - minimum: 1 - maximum: 1000)
참조 IP에 대한 Ping 응답대기 시간(ms)

ifup_vrrp_rx_tm
ifup_vrrp_rx_tm: required (integer - minimum: 0 - maximum: 1000)
인터페이스 UP 판단을 위한 VRRP 수신대기 시간(초)

svip_lb
svip_lb: required (one of 0, 1)
Single VIP 부하 분산 (OFF:	0,	ON:	1)

svip_lb_check_intval: required (integer - minimum: 1 - maximum: 10)
svip_lb_check_intval
Single VIP 부하 분산 상태 검사 주기(초)

svip_lb_ping_relay
svip_lb_ping_relay: required (one of 0, 1)
Single VIP 부하 분산 Ping 응답 (OFF:	0,	ON:	1)

Example:
Example

{
		"hello_intval"	:	0.5,
		"garp_intval"	:	15,
		"garp_tx_num"	:	5,
		"failback_delay_tm"	:	0,
		"manual_failback"	:	0,
		"vrrp_auth"	:	0,
		"vrrp_auth_pw"	:	"",
		"rip_ping_req_cnt"	:	3,
		"rip_	ping_wait_delay"	:	300,
		"ifup_vrrp_rx_tm"	:	0,
		"svip_lb"	:	0,
		"svip_lb_check_intval"	:	1,
		"svip_lb_ping_relay"	:	0
}

Response

HTTP status code 200

가상 IP 고급 설정 수정 성공

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

hello_intval
hello_intval: required (number - minimum: 0.1 - maximum: 25.5)
상태검사주기(초)

garp_intval: required (number - minimum: 0.1 - maximum: 25.5)
garp_intval
Gratuitous ARP / Unsolicited NA 전송 주기

garp_tx_num
garp_tx_num: required (integer - minimum: 1 - maximum: 10)
Gratuitous ARP / Unsolicited NA 전송 횟수

failback_delay_tm
failback_delay_tm: required (integer - minimum: 0 - maximum: 60)
자동 장애 복구 지연 시간(초)

manual_failback
manual_failback: required (one of 0, 1)
수동 장애 복구 (OFF:	0,	ON:	1)

vrrp_auth
vrrp_auth: required (one of 0, 1)
VRRP 인증 (OFF:	0,	ON:	1)

vrrp_auth_pw
vrrp_auth_pw: required (string - maxLength: 4)
VRRP 인증 비밀번호(Base64 인코딩)

rip_ping_req_cnt
rip_ping_req_cnt: required (integer - minimum: 1 - maximum: 10)
참조 IP에 대한 Ping 검사 횟수

ping_wait_delay: required (integer - minimum: 1 - maximum: 1000)
ping_wait_delay
참조 IP에 대한 Ping 응답대기 시간(ms)

ifup_vrrp_rx_tm
ifup_vrrp_rx_tm: required (integer - minimum: 0 - maximum: 1000)
인터페이스 UP 판단을 위한 VRRP 수신대기 시간(초)

svip_lb
svip_lb: required (one of 0, 1)
Single VIP 부하 분산 (OFF:	0,	ON:	1)

svip_lb_check_intval
svip_lb_check_intval: required (integer - minimum: 1 - maximum: 10)
Single VIP 부하 분산 상태 검사 주기(초)

svip_lb_ping_relay
svip_lb_ping_relay: required (one of 0, 1)
Single VIP 부하 분산 Ping 응답 (OFF:	0,	ON:	1)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"hello_intval"	:	0.5,
				"garp_intval"	:	15,
				"garp_tx_num"	:	5,
				"failback_delay_tm"	:	0,
				"manual_failback"	:	0,
				"vrrp_auth"	:	0,
				"vrrp_auth_pw"	:	"",
				"rip_ping_req_cnt"	:	3,
				"rip_	ping_wait_delay"	:	300,
				"ifup_vrrp_rx_tm"	:	0,
				"svip_lb"	:	0,
				"svip_lb_check_intval"	:	1,
				"svip_lb_ping_relay"	:	0
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

PUT

/ha/virtual-ips/advance/apply

가상 IP 고급 설정을 적용합니다.

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

가상 IP 고급 설정 적용 성공

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

/ha/virtual-ips/advance/cancel

가상 IP 고급 설정을 취소합니다.

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

Example:
Example

{}

Response

HTTP status code 200

가상 IP 고급 설정 취소 성공

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

현재 상태 > HA 멤버 상태 > HA 초기화

POST

/ha/reset

HA 초기화를 실행한다.

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

user_passwd: required (string)
user_passwd
관리자 비밀번호(Base64)

Example:
Example

{
		"user_passwd":	"c2VjdWkwMA=="
}

Response

HTTP status code 200

현재 상태 > HA 가상 IP 주소 > 수동 장애복구

POST

/ha/virtual-ips/failure-recovery

수동 장애복구를 실행한다.

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

/ha/virtual-ips/failover-mode

GET

/ha/virtual-ips/failover-mode

현재 상태 > HA 상태 > HA 가상 IP 주소 소유권 넘김을(를) 조회한다.

Request

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

현재 상태 > HA 상태 > HA 가상 IP 주소 소유권 넘김 조회 성공

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

vip_manual_failover_mode
vip_manual_failover_mode: required (one of 0, 1)
동작 모드 (OFF:	0,	ON:	1)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"vip_manual_failover_mode":	0
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

/ha/virtual-ips/failover-mode

현재 상태 > HA 상태 > HA 가상 IP 주소 소유권 넘김을(를) 수정한다.

Request

Annotations

SupportedVersion:
SupportedVersion

"2.0.0"

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

vip_manual_failover_mode: required (one of 0, 1)
vip_manual_failover_mode
동작 모드 (OFF:	0,	ON:	1)

Example:
Example

{
		"vip_manual_failover_mode":	1
}

Response

HTTP status code 200

현재 상태 > HA 상태 > HA 가상 IP 주소 소유권 넘김 수정 성공

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

vip_manual_failover_mode
vip_manual_failover_mode: required (one of 0, 1)
동작 모드 (OFF:	0,	ON:	1)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"vip_manual_failover_mode":	0
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

