GET

PUT

GET

GET

POST

  DELETE

PUT

  DELETE

PUT

PUT

PUT

PUT

(2.0)DR 설정 REST API 문서

https://{url}/api/sm

urlurl: required (string)
장비 IP

DR 설정

/dr/config

대상 마스터(슬래이브 모드)

/dr/slave/targets

/dr/slave/targets/{pk}

상태 전환(슬래이브 모드)

/dr/slave/change/state

슬레이브 설정 초기화

/dr/slave/init/config

DR 설정 적용/취소

/command/dr-config/apply

/command/dr-config/cancel

DR 설정

GET

/dr/config

DR 설정을(를) 조회한다.

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

DR 설정 조회 성공

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
선택된 role에 의해서 slave 또는 master 속성이 사용

useuse: required (one of 0, 1 - default: 0)
사용
0:	사용안함,	1:	사용

rolerole: required (one of 0, 1 - default: 0)
역할
0:	슬레이브,	1:	마스터

slave
slave: (object)
슬레이브 설정

check_period: required (integer - default: 60 - minimum: 30 - maximum: 3600)
check_period
검사 주기(초)

tm_limit
tm_limit: required (integer - default: 10 - minimum: 10 - maximum: 30)
최대 응답 대기 시간(초)

retry_cnt
retry_cnt: required (integer - default: 3 - minimum: 1 - maximum: 10)
실패 허용 횟수(회)

dr_type
dr_type: required (one of 0, 1 - default: 0)
DR 구성
0:	N:1	설정,	1:	1:1설정

alive_condition
alive_condition: required (one of 0, 1 - default: 0)
Alive 판단 방식
dr_type  속성값이 0일 경우 설정
0:	하나	이상	IP	체크	성공	시,	1:	모든	IP	체크	성공	시

sync_type
sync_type: required (one of 0, 1 - default: 0)
동기화 설정 전환
0:	자동	복구,	1:	관리자	선택

nat_config_sync
nat_config_sync: required (one of 0, 1 - default: 1)
NAT 설정 동기화
0:	미사용,	1:	사용

admin
admin: required (string)
복구 관리자 계정(3레벨 관리자 지정)

Example:
Example

admin

per_day: required (one of 0, 1 - default: 1)
per_day
동기화 주기
0:	일별,	1:	매일

day_of_week
day_of_week: required (array of any)
per_day  속성값이 0일 때 설정

요일(일, 월, 화, 수, 목, 금, 토)가 선택된 배열
0:	요일	미선택,	1:	요일	선택

Example:
Example

일,	화,	목	->	[1,0,1,0,1,0,0]
월,	수,	금	->	[0,1,0,1,0,1,0]

hour
hour: required (integer - default: 23 - minimum: 0 - maximum: 23)
동기화 수행 시간(시)

minmin: required (integer - default: 59 - minimum: 0 - maximum: 59)
동기화 수행 시간(분)

current_state
current_state: required (one of 0, 1)
현재 상태
0:	Backup,	1:	Active

servers
servers: required (array of GetTargetMaster)
대상 목록

Items: GetTargetMaster
Items

ip_ver
ip_ver: required (one of 4, 6)
IP 버전
4:	IPv4,	6:	IPv6

ipip: required (string)
마스터 접속 IP
ip_ver	속성값이	4일	경우	IPv4	형식
ip_ver	속성값이	6일	경우	IPv6	형식

portport: required (integer - default: 34567 - minimum: 1 - maximum: 65535)
마스터 접속 포트

descdesc: required (string - maxLength: 64)
설명

ha_mode
ha_mode: required (one of 0, 1, 2)
역할
0:	설정없음,	1:	Master,	2:	Slave

idid: required (integer)
대상 마스터 ID

fail_cnt
fail_cnt: required (integer)
연결 실패 카운트

is_connected
is_connected: required (one of 0, 1, 2)
연결 상태
0:	초기상태,	1:	연결	상태,	2:	연결	해제

last_sync
last_sync: required (string)
동기화 일자
포맷:	YYYY-MM-DD

master
master: (object)
마스터 설정

ip_ver
ip_ver: required (one of 4, 6)
IP 버전
4:	IPv4,	6:	IPv6

ipip: required (string)
접속 허용 IP
ip_ver	속성값이	4일	경우	IPv4	형식
ip_ver	속성값이	6일	경우	IPv6	형식

portport: required (integer - default: 34567 - minimum: 1 - maximum: 65535)
접속 포트

sync_port
sync_port: required (integer - default: 22 - minimum: 1 - maximum: 65535)
정책 동기화 포트

Example:
Example

{
		"code":	"ok",
		"result":	{
				"use":	1,
				"role":	0,
				"slave":	{
						"check_period":	60,
						"tm_limit":	10,
						"retry_cnt":	3,
						"alive_condition":	0,
						"current_state":	0,
						"servers":	[
								{
										"id":	1,
										"ip_ver":	4,
										"ip":	"100.100.100.100",
										"port":	3000,
										"desc":	"설명",
										"fail_cnt":	0,
										"is_connected":	0,
										"ha_mode":	1
								}
						]
				},
				"master":	{
						"ip_ver":	4,
						"ip":	"",
						"port":	0,
						"shared_key":	"",
						"sync_port":	22
				}
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

/dr/config

DR 설정을(를) 수정한다.

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

useuse: required (one of 0, 1 - default: 0)
사용
0:	사용안함,	1:	사용

rolerole: required (one of 0, 1 - default: 0)
역할
0:	슬레이브,	1:	마스터

slave
slave: required (object)
슬레이브 설정
role	속성값이	0	일	경우	설정

check_period
check_period: required (integer - default: 60 - minimum: 30 - maximum: 3600)
검사 주기(초)

tm_limit
tm_limit: required (integer - default: 10 - minimum: 10 - maximum: 30)
최대 응답 대기 시간(초)

retry_cnt: required (integer - default: 3 - minimum: 1 - maximum: 10)
retry_cnt

실패 허용 횟수(회)

dr_type
dr_type: required (one of 0, 1 - default: 0)
DR 구성
0:	N:1	설정,	1:	1:1설정

alive_condition
alive_condition: required (one of 0, 1 - default: 0)
Alive 판단 방식
dr_type  속성값이 0일 경우 설정
0:	하나	이상	IP	체크	성공	시,	1:	모든	IP	체크	성공	시

sync_type: required (one of 0, 1 - default: 0)
sync_type
동기화 설정 전환
0:	자동	복구,	1:	관리자	선택

nat_config_sync
nat_config_sync: required (one of 0, 1 - default: 1)
NAT 설정 동기화
0:	미사용,	1:	사용

admin
admin: required (string)
복구 관리자 계정(3레벨 관리자 지정)

Example:
Example

admin

per_day
per_day: required (one of 0, 1 - default: 1)
동기화 주기
0:	일별,	1:	매일

day_of_week
day_of_week: required (array of any)
per_day  속성값이 0일 때 설정

요일(일, 월, 화, 수, 목, 금, 토)가 선택된 배열
0:	요일	미선택,	1:	요일	선택

Example:
Example

일,	화,	목	->	[1,0,1,0,1,0,0]
월,	수,	금	->	[0,1,0,1,0,1,0]

hour
hour: required (integer - default: 23 - minimum: 0 - maximum: 23)
동기화 수행 시간(시)

minmin: required (integer - default: 59 - minimum: 0 - maximum: 59)
동기화 수행 시간(분)

master
master: required (object)
마스터 설정
role	속성값이	1	일	경우	설정

ip_ver
ip_ver: required (one of 4, 6)
IP 버전
4:	IPv4,	6:	IPv6

ipip: required (string)
접속 허용 IP
ip_ver	속성값이	4일	경우	IPv4	형식
ip_ver	속성값이	6일	경우	IPv6	형식

portport: required (integer - default: 34567 - minimum: 1 - maximum: 65535)
접속 포트

sync_port: required (integer - default: 22 - minimum: 1 - maximum: 65535)
sync_port
정책 동기화 포트

shared_key
shared_key: required (string - minLength: 1 - maxLength: 16)
Base64 인코딩된 공유키

Example:
Example

{
		"use":	1,
		"role":	1,
		"slave":	{
				"check_period":	1,
				"tm_limit":	1,
				"retry_cnt":	1,
				"alive_condition":	1
		},
		"master":	{
				"ip_ver":	4,
				"ip":	"192.168.10.10",
				"port":	10000,
				"shared_key":	"x2xAyWkwMEAh"
		}
}

Response

HTTP status code 200

DR 설정 수정 성공

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
선택된 role에 의해서 slave 또는 master 속성이 사용

useuse: required (one of 0, 1 - default: 0)
사용
0:	사용안함,	1:	사용

rolerole: required (one of 0, 1 - default: 0)
역할
0:	슬레이브,	1:	마스터

slave: (object)
slave
슬레이브 설정

check_period
check_period: required (integer - default: 60 - minimum: 30 - maximum: 3600)
검사 주기(초)

tm_limit
tm_limit: required (integer - default: 10 - minimum: 10 - maximum: 30)
최대 응답 대기 시간(초)

retry_cnt
retry_cnt: required (integer - default: 3 - minimum: 1 - maximum: 10)
실패 허용 횟수(회)

dr_type
dr_type: required (one of 0, 1 - default: 0)
DR 구성
0:	N:1	설정,	1:	1:1설정

alive_condition
alive_condition: required (one of 0, 1 - default: 0)
Alive 판단 방식
dr_type  속성값이 0일 경우 설정
0:	하나	이상	IP	체크	성공	시,	1:	모든	IP	체크	성공	시

sync_type: required (one of 0, 1 - default: 0)
sync_type
동기화 설정 전환
0:	자동	복구,	1:	관리자	선택

nat_config_sync
nat_config_sync: required (one of 0, 1 - default: 1)
NAT 설정 동기화
0:	미사용,	1:	사용

admin
admin: required (string)
복구 관리자 계정(3레벨 관리자 지정)

Example:
Example

admin

per_day
per_day: required (one of 0, 1 - default: 1)
동기화 주기
0:	일별,	1:	매일

day_of_week: required (array of any)
day_of_week
per_day  속성값이 0일 때 설정

요일(일, 월, 화, 수, 목, 금, 토)가 선택된 배열
0:	요일	미선택,	1:	요일	선택

Example:
Example

일,	화,	목	->	[1,0,1,0,1,0,0]
월,	수,	금	->	[0,1,0,1,0,1,0]

hour
hour: required (integer - default: 23 - minimum: 0 - maximum: 23)
동기화 수행 시간(시)

minmin: required (integer - default: 59 - minimum: 0 - maximum: 59)
동기화 수행 시간(분)

current_state
current_state: required (one of 0, 1)
현재 상태
0:	Backup,	1:	Active

servers
servers: required (array of GetTargetMaster)
대상 목록

Items: GetTargetMaster
Items

ip_ver: required (one of 4, 6)
ip_ver
IP 버전
4:	IPv4,	6:	IPv6

ipip: required (string)
마스터 접속 IP
ip_ver	속성값이	4일	경우	IPv4	형식
ip_ver	속성값이	6일	경우	IPv6	형식

portport: required (integer - default: 34567 - minimum: 1 - maximum: 65535)
마스터 접속 포트

descdesc: required (string - maxLength: 64)
설명

ha_mode: required (one of 0, 1, 2)
ha_mode
역할
0:	설정없음,	1:	Master,	2:	Slave

idid: required (integer)
대상 마스터 ID

fail_cnt
fail_cnt: required (integer)
연결 실패 카운트

is_connected
is_connected: required (one of 0, 1, 2)
연결 상태
0:	초기상태,	1:	연결	상태,	2:	연결	해제

last_sync: required (string)
last_sync
동기화 일자
포맷:	YYYY-MM-DD

master
master: (object)
마스터 설정

ip_ver: required (one of 4, 6)
ip_ver

IP 버전
4:	IPv4,	6:	IPv6

ipip: required (string)
접속 허용 IP
ip_ver	속성값이	4일	경우	IPv4	형식
ip_ver	속성값이	6일	경우	IPv6	형식

portport: required (integer - default: 34567 - minimum: 1 - maximum: 65535)
접속 포트

sync_port: required (integer - default: 22 - minimum: 1 - maximum: 65535)
sync_port
정책 동기화 포트

Example:
Example

{
		"code":	"ok",
		"result":	{
				"use":	1,
				"role":	0,
				"slave":	{
						"check_period":	1,
						"tm_limit":	1,
						"retry_cnt":	1,
						"alive_condition":	1,
						"current_state":	0,
						"servers":	[
								{
										"id":	1,
										"ip_ver":	4,
										"ip":	"100.100.100.100",
										"port":	3000,
										"desc":	"설명",
										"is_connected":	0,
										"ha_mode":	1
								}
						]
				},
				"master":	{
						"ip_ver":	4,
						"ip":	"192.168.10.10",
						"port":	10000,
						"sync_port":	22
				}
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

대상 마스터(슬래이브 모드)

GET

/dr/slave/targets

대상 마스터 목록을 조회한다.

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

대상 마스터 목록 조회 성공

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
result: required (array of GetTargetMaster)
결과 데이터

Items: GetTargetMaster
Items

ip_ver
ip_ver: required (one of 4, 6)
IP 버전
4:	IPv4,	6:	IPv6

ipip: required (string)
마스터 접속 IP
ip_ver	속성값이	4일	경우	IPv4	형식
ip_ver	속성값이	6일	경우	IPv6	형식

portport: required (integer - default: 34567 - minimum: 1 - maximum: 65535)
마스터 접속 포트

descdesc: required (string - maxLength: 64)
설명

ha_mode
ha_mode: required (one of 0, 1, 2)
역할
0:	설정없음,	1:	Master,	2:	Slave

idid: required (integer)
대상 마스터 ID

fail_cnt
fail_cnt: required (integer)
연결 실패 카운트

is_connected
is_connected: required (one of 0, 1, 2)
연결 상태
0:	초기상태,	1:	연결	상태,	2:	연결	해제

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"id":	1,
						"ip_ver":	4,
						"ip":	"100.100.100.100",
						"port":	3000,
						"desc":	"설명",
						"fail_cnt":	0,
						"is_connected":	0,
						"ha_mode":	1
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

/dr/slave/targets

대상 마스터를 추가한다.

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
ip_ver
ip_ver: required (one of 4, 6)
IP 버전
4:	IPv4,	6:	IPv6

ipip: required (string)
마스터 접속 IP
ip_ver	속성값이	4일	경우	IPv4	형식
ip_ver	속성값이	6일	경우	IPv6	형식

portport: required (integer - default: 34567 - minimum: 1 - maximum: 65535)
마스터 접속 포트

descdesc: required (string - maxLength: 64)
설명

ha_mode: required (one of 0, 1, 2)
ha_mode
역할
0:	설정없음,	1:	Master,	2:	Slave

shared_key
shared_key: required (string - minLength: 1 - maxLength: 16)
Base64 인코딩된 공유키

Example:
Example

{
		"ip_ver":	4,
		"ip":	"100.100.100.100",
		"port":	3000,
		"shared_key":	"x2xAyWkwMEAh",
		"desc":	"설명",
		"ha_mode":	1
}

Response

HTTP status code 200

대상 마스터 추가 성공

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

ip_ver
ip_ver: required (one of 4, 6)
IP 버전
4:	IPv4,	6:	IPv6

ipip: required (string)
마스터 접속 IP
ip_ver	속성값이	4일	경우	IPv4	형식
ip_ver	속성값이	6일	경우	IPv6	형식

portport: required (integer - default: 34567 - minimum: 1 - maximum: 65535)
마스터 접속 포트

descdesc: required (string - maxLength: 64)
설명

ha_mode
ha_mode: required (one of 0, 1, 2)
역할
0:	설정없음,	1:	Master,	2:	Slave

idid: required (integer)
대상 마스터 ID

fail_cnt
fail_cnt: required (integer)
연결 실패 카운트

is_connected
is_connected: required (one of 0, 1, 2)
연결 상태
0:	초기상태,	1:	연결	상태,	2:	연결	해제

Example:
Example

{
		"code":	"ok",
		"result":	{
				"id":	1,
				"ip_ver":	4,
				"ip":	"100.100.100.100",
				"port":	3000,
				"desc":	"설명",
				"fail_cnt":	0,
				"is_connected":	0,
				"ha_mode":	1
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

/dr/slave/targets

대상 마스터 목록을 (일괄)삭제한다.

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
				{"id":	1},
				{"id":	2}
		]
}

Response

HTTP status code 200

대상 마스터 목록 삭제 성공

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

/dr/slave/targets/{pk}

대상 마스터을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
대상 마스터 ID( id )

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

대상 마스터 조회 성공

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

ip_ver
ip_ver: required (one of 4, 6)
IP 버전
4:	IPv4,	6:	IPv6

ipip: required (string)
마스터 접속 IP
ip_ver	속성값이	4일	경우	IPv4	형식
ip_ver	속성값이	6일	경우	IPv6	형식

portport: required (integer - default: 34567 - minimum: 1 - maximum: 65535)
마스터 접속 포트

descdesc: required (string - maxLength: 64)
설명

ha_mode
ha_mode: required (one of 0, 1, 2)
역할
0:	설정없음,	1:	Master,	2:	Slave

idid: required (integer)
대상 마스터 ID

fail_cnt
fail_cnt: required (integer)
연결 실패 카운트

is_connected
is_connected: required (one of 0, 1, 2)
연결 상태
0:	초기상태,	1:	연결	상태,	2:	연결	해제

Example:
Example

{
		"code":	"ok",
		"result":	{
				"id":	1,
				"ip_ver":	4,
				"ip":	"100.100.100.100",
				"port":	3000,
				"desc":	"설명",
				"fail_cnt":	0,
				"is_connected":	0,
				"ha_mode":	1
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

/dr/slave/targets/{pk}

대상 마스터을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
대상 마스터 ID( id )

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
ip_ver
ip_ver: required (one of 4, 6)
IP 버전
4:	IPv4,	6:	IPv6

ipip: required (string)
마스터 접속 IP
ip_ver	속성값이	4일	경우	IPv4	형식
ip_ver	속성값이	6일	경우	IPv6	형식

portport: required (integer - default: 34567 - minimum: 1 - maximum: 65535)
마스터 접속 포트

descdesc: required (string - maxLength: 64)
설명

ha_mode
ha_mode: required (one of 0, 1, 2)
역할
0:	설정없음,	1:	Master,	2:	Slave

shared_key: required (string - minLength: 1 - maxLength: 16)
shared_key

Base64 인코딩된 공유키

Example:
Example

{
		"ip_ver":	4,
		"ip":	"100.100.100.100",
		"port":	3000,
		"shared_key":	"x2xAyWkwMEAh",
		"desc":	"설명",
		"ha_mode":	1
}

Response

HTTP status code 200

대상 마스터 수정 성공

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

ip_ver
ip_ver: required (one of 4, 6)
IP 버전
4:	IPv4,	6:	IPv6

ipip: required (string)
마스터 접속 IP
ip_ver	속성값이	4일	경우	IPv4	형식
ip_ver	속성값이	6일	경우	IPv6	형식

portport: required (integer - default: 34567 - minimum: 1 - maximum: 65535)
마스터 접속 포트

descdesc: required (string - maxLength: 64)
설명

ha_mode
ha_mode: required (one of 0, 1, 2)
역할
0:	설정없음,	1:	Master,	2:	Slave

idid: required (integer)
대상 마스터 ID

fail_cnt
fail_cnt: required (integer)
연결 실패 카운트

is_connected
is_connected: required (one of 0, 1, 2)
연결 상태
0:	초기상태,	1:	연결	상태,	2:	연결	해제

Example:
Example

{
		"code":	"ok",
		"result":	{
				"id":	1,
				"ip_ver":	4,
				"ip":	"100.100.100.100",
				"port":	3000,
				"desc":	"설명",
				"fail_cnt":	0,
				"is_connected":	0,
				"ha_mode":	1
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

/dr/slave/targets/{pk}

대상 마스터을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
대상 마스터 ID( id )

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

대상 마스터 삭제 성공

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

상태 전환(슬래이브 모드)

PUT

/dr/slave/change/state

동기화 설정 전환이 '관리자 선택'으로 설정된 경우 활성화
!상태 전환 시 장비가 재부팅됩니다.

Request

Annotations

SupportedVersion:
SupportedVersion

"2.8"

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

user_passwd
user_passwd: required (string)
패스워드(Base64 인코딩)

nat_opt
nat_opt: required (one of 0, 1)
NAT 설정동기화
0:	사용안함,	1:	사용

admin_name
admin_name: required (string)
복구관리자 계정

Example:
Example

{
		"user_passwd":	"x2xAyWkwMEAh",
		"nat_opt":	1,
		"admin_name"	:	"admin"
}

Response

HTTP status code 200

상태 전환 수정 성공

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

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"12001",
		"message":	"존재하지	않는	항목입니다."
}

슬레이브 설정 초기화

PUT

/dr/slave/init/config

슬레이브 설정을 초기화 한다.
!N:1 설정, 1:1 설정 전환 시에 호출되어야 한다.

Request

Annotations

SupportedVersion:
SupportedVersion

"2.8"

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

dr_type
dr_type: required (one of 0, 1 - default: 0)
DR 구성
0:	N:1	설정,	1:	1:1설정

Example:
Example

{
		"dr_type":	1
}

Response

HTTP status code 200

슬레이브 설정 초기화 성공

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

DR 설정 적용/취소

PUT

/command/dr-config/apply

DR 설정을 적용합니다.

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

user_passwd
user_passwd: (string)
관리자 패스워드(Base64 인코딩)

admin_name: (string)
admin_name
관리자 계정

Example:
Example

{
		"user_passwd":	"x2xAyWkwMEAh",
		"admin_name"	:	"admin"
}

Response

HTTP status code 200

DR 설정 적용 성공

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

/command/dr-config/cancel

DR 설정을 취소합니다.

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

DR 설정 취소 성공

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

