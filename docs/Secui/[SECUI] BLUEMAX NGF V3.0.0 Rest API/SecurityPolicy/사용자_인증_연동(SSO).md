GET

POST

PUT

  DELETE

GET

PUT

  DELETE

GET

POST

PUT

  DELETE

GET

PUT

  DELETE

GET

POST

PUT

  DELETE

GET

PUT

  DELETE

PUT

PUT

사용자 인증 연동(SSO) REST API 문서

https://{host}/api/po

host
host: required (string)
[IP]:[GUI 접속 PORT]
443	포트는	생략	가능

Example:
Example

192.168.100.100:443

모니터링 서버

/sso/monitor/servers

/sso/monitor/servers/{pk}

사용자 IP 주소 포함/미포함 대역

/sso/user-ip/bands

/sso/user-ip/bands/{pk}

예외 사용자 ID

/sso/exception/users

/sso/exception/users/{pk}

사용자 인증 연동(SSO) 적용/취소

/command/user-auth-sso/apply

/command/user-auth-sso/cancel

모니터링 서버

GET

/sso/monitor/servers

모니터링 서버 목록을 조회한다.

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

모니터링 서버 목록 조회 성공

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
result: required (array of MonitorGetServer)
결과 데이터

Items: MonitorGetServer
Items

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

is_redist_target
is_redist_target: required (one of 0, 1)
에이전트간 연동 여부
비활성:	0,	활성:	1

name
name: required (string - minLength: 1 - maxLength: 20)
서버 이름
공백	사용	불가

type
type: required (one of 1, 2, 3)
서버 종류
AD:	1,	Syslog:	2,	NGF2Agent:	3

flagflag: required (one of 1, 2)
IP 버전
IPv4:	1,	IPv6:	2

addr
addr: required (string)
IP 주소(IPv4 형식)

tm_out
tm_out: required (integer - default: 60 - minimum: 1 - maximum: 1440)
인증 정보 유지 시간(분)

interval
interval: required (integer - default: 3 - minimum: 1 - maximum: 65535)
서버 모니터링 주기(초)

dmndmn: required (string - maxLength: 32)
도메인
type	속성이	Syslog(2)를	선택한	경우	설정합니다.
영문,	숫자,	특수	문자('-',	'_')	만	허용,	공백	문자	입력	불가

syslog_filter_id
syslog_filter_id: required (integer)
Syslog 필터 ID
type	속성이	Syslog(2)를	선택한	경우	설정합니다.

[Syslog 분석 필터 목록 조회]
GET	{{url}}/api/po/user-auth/syslog/filters
상세	속성	정보는	사용자	인증	고급	설정	문서를	참고하세요.

proto
proto: required (one of 1, 2, 3)
Syslog 프로토콜
UDP:	1,	TCP:	2,	TLS:	3
type	속성이	Syslog(2)를	선택한	경우	설정합니다.

ntlmv2
ntlmv2: required (one of 0, 1)
NTLMv2 인증 사용 여부
사용	안함:	0,	사용:	1
서버 종류(type)가 AD(1)일 경우에 설정

wmi_id
wmi_id: required (string - minLength: 1 - maxLength: 32)
사용자 이름(WMI 설정)
입력 가능한 문자: 영문, 숫자, 특수 문자( _ ,  - ,  \ ,  . ,  ! ,  ~ ,  # ,  ^ ,  & ) 만 허용

wmi_pw
wmi_pw: required (string - minLength: 1 - maxLength: 32)
비밀번호(WMI 설정)
Base64	인코딩	처리	필요

event_id
event_id: required (integer)
모니터링 이벤트 ID
540,	672,	673,	674,	4624,	4768,	4769,	4770	순서대로	2진수	문자열

Example:
Example

11000000	->	540,	672	선택

sess_enable
sess_enable: required (one of 0, 1)
세션 모니터링 사용 여부
사용	안함:	0,	사용:	1

sess_interval: required (integer - default: 10 - minimum: 1 - maximum: 65535)
sess_interval
세션 모니터링 주기

prob_enable
prob_enable: required (one of 0, 1)
Client Probing 사용 여부
사용	안함:	0,	사용:	1

prob_interval: required (integer - default: 1 - minimum: 1 - maximum: 1440)
prob_interval
Client Probing 주기

keep_enable
keep_enable: required (one of 0, 1)
강제 인증 유지
사용	안함:	0,	사용:	1

descdesc: (string - maxLength: 128)

설명

sso_mon_id
sso_mon_id: required (integer)
모니터링 서버 ID(PK)

status: required (integer)
status
연동 상태
판단불가능:	0,	정상:	1,	비정상:	2

reason
reason: required (string - maxLength: 128)
연동 상태에 대한 설명

last_access: required (string)
last_access
마지막 연동 일자

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"sso_mon_id":	1,
				"use":	1,
				"is_redist_target":	1,
				"name":	"모니터링	서버	이름",
				"type":	1,
				"flag":	1,
				"addr":	"10.10.10.10",
				"tm_out":	60,
				"interval":	3,
				"dmn":	"",
				"syslog_filter_id":	null,
				"proto":	1,
				"ntlmv2":	1,
				"wmi_id":	"example\\administrator",
				"event_id":	"11111111",
				"sess_enable":	1,
				"sess_interval":	10,
				"prob_enable":	1,
				"prob_interval":	1,
				"keep_enable":	0,
				"status":	1,
				"last_access":	"2018-01-01	10:10:10",
				"desc":	"모니터링	서버	설명",
				"reason":	"Unknown"
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

/sso/monitor/servers

모니터링 서버를 추가한다.

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

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

is_redist_target: required (one of 0, 1)
is_redist_target
에이전트간 연동 여부
비활성:	0,	활성:	1

name
name: required (string - minLength: 1 - maxLength: 20)
서버 이름
공백	사용	불가

type
type: required (one of 1, 2, 3)
서버 종류
AD:	1,	Syslog:	2,	NGF2Agent:	3

flagflag: required (one of 1, 2)
IP 버전
IPv4:	1,	IPv6:	2

addr
addr: required (string)
IP 주소(IPv4 형식)

tm_out
tm_out: required (integer - default: 60 - minimum: 1 - maximum: 1440)
인증 정보 유지 시간(분)

interval
interval: required (integer - default: 3 - minimum: 1 - maximum: 65535)
서버 모니터링 주기(초)

dmndmn: required (string - maxLength: 32)
도메인
type	속성이	Syslog(2)를	선택한	경우	설정합니다.
영문,	숫자,	특수	문자('-',	'_')	만	허용,	공백	문자	입력	불가

syslog_filter_id
syslog_filter_id: required (integer)
Syslog 필터 ID
type	속성이	Syslog(2)를	선택한	경우	설정합니다.

[Syslog 분석 필터 목록 조회]
GET	{{url}}/api/po/user-auth/syslog/filters
상세	속성	정보는	사용자	인증	고급	설정	문서를	참고하세요.

proto
proto: required (one of 1, 2, 3)
Syslog 프로토콜
UDP:	1,	TCP:	2,	TLS:	3
type	속성이	Syslog(2)를	선택한	경우	설정합니다.

ntlmv2
ntlmv2: required (one of 0, 1)
NTLMv2 인증 사용 여부
사용	안함:	0,	사용:	1
서버 종류(type)가 AD(1)일 경우에 설정

wmi_id
wmi_id: required (string - minLength: 1 - maxLength: 32)
사용자 이름(WMI 설정)
입력 가능한 문자: 영문, 숫자, 특수 문자( _ ,  - ,  \ ,  . ,  ! ,  ~ ,  # ,  ^ ,  & ) 만 허용

wmi_pw: required (string - minLength: 1 - maxLength: 32)
wmi_pw
비밀번호(WMI 설정)
Base64	인코딩	처리	필요

event_id
event_id: required (integer)
모니터링 이벤트 ID
540,	672,	673,	674,	4624,	4768,	4769,	4770	순서대로	2진수	문자열

Example:
Example

11000000	->	540,	672	선택

sess_enable: required (one of 0, 1)
sess_enable

세션 모니터링 사용 여부
사용	안함:	0,	사용:	1

sess_interval
sess_interval: required (integer - default: 10 - minimum: 1 - maximum: 65535)
세션 모니터링 주기

prob_enable
prob_enable: required (one of 0, 1)
Client Probing 사용 여부
사용	안함:	0,	사용:	1

prob_interval
prob_interval: required (integer - default: 1 - minimum: 1 - maximum: 1440)
Client Probing 주기

keep_enable
keep_enable: required (one of 0, 1)
강제 인증 유지
사용	안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

Example:
Example

{
		"use":	1,
		"is_redist_target":	1,
		"name":	"New	모니터링	서버	이름",
		"type":	1,
		"flag":	1,
		"addr":	"10.10.10.10",
		"tm_out":	60,
		"interval":	3,
		"dmn":	"",
		"syslog_filter_id":	null,
		"proto":	1,
		"ntlmv2":	1,
		"wmi_id":	"example\\administrator",
		"wmi_pw":	"x2xAyWkwMEAh",
		"event_id":	"11111111",
		"sess_enable":	1,
		"sess_interval":	10,
		"prob_enable":	1,
		"prob_interval":	1,
		"keep_enable":	0,
		"desc":	"New	모니터링	서버	설명"
}

Response

HTTP status code 200

모니터링 서버 추가 성공

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
사용	안함:	0,	사용:	1

is_redist_target
is_redist_target: required (one of 0, 1)
에이전트간 연동 여부
비활성:	0,	활성:	1

name
name: required (string - minLength: 1 - maxLength: 20)
서버 이름
공백	사용	불가

type: required (one of 1, 2, 3)
type
서버 종류
AD:	1,	Syslog:	2,	NGF2Agent:	3

flagflag: required (one of 1, 2)
IP 버전
IPv4:	1,	IPv6:	2

addr
addr: required (string)
IP 주소(IPv4 형식)

tm_out
tm_out: required (integer - default: 60 - minimum: 1 - maximum: 1440)
인증 정보 유지 시간(분)

interval
interval: required (integer - default: 3 - minimum: 1 - maximum: 65535)
서버 모니터링 주기(초)

dmndmn: required (string - maxLength: 32)
도메인
type	속성이	Syslog(2)를	선택한	경우	설정합니다.
영문,	숫자,	특수	문자('-',	'_')	만	허용,	공백	문자	입력	불가

syslog_filter_id
syslog_filter_id: required (integer)
Syslog 필터 ID
type	속성이	Syslog(2)를	선택한	경우	설정합니다.

[Syslog 분석 필터 목록 조회]
GET	{{url}}/api/po/user-auth/syslog/filters
상세	속성	정보는	사용자	인증	고급	설정	문서를	참고하세요.

proto: required (one of 1, 2, 3)
proto
Syslog 프로토콜
UDP:	1,	TCP:	2,	TLS:	3
type	속성이	Syslog(2)를	선택한	경우	설정합니다.

ntlmv2
ntlmv2: required (one of 0, 1)
NTLMv2 인증 사용 여부
사용	안함:	0,	사용:	1
서버 종류(type)가 AD(1)일 경우에 설정

wmi_id
wmi_id: required (string - minLength: 1 - maxLength: 32)
사용자 이름(WMI 설정)
입력 가능한 문자: 영문, 숫자, 특수 문자( _ ,  - ,  \ ,  . ,  ! ,  ~ ,  # ,  ^ ,  & ) 만 허용

wmi_pw
wmi_pw: required (string - minLength: 1 - maxLength: 32)
비밀번호(WMI 설정)
Base64	인코딩	처리	필요

event_id
event_id: required (integer)
모니터링 이벤트 ID
540,	672,	673,	674,	4624,	4768,	4769,	4770	순서대로	2진수	문자열

Example:
Example

11000000	->	540,	672	선택

sess_enable: required (one of 0, 1)
sess_enable
세션 모니터링 사용 여부
사용	안함:	0,	사용:	1

sess_interval
sess_interval: required (integer - default: 10 - minimum: 1 - maximum: 65535)
세션 모니터링 주기

prob_enable: required (one of 0, 1)
prob_enable
Client Probing 사용 여부
사용	안함:	0,	사용:	1

prob_interval
prob_interval: required (integer - default: 1 - minimum: 1 - maximum: 1440)
Client Probing 주기

keep_enable: required (one of 0, 1)
keep_enable
강제 인증 유지
사용	안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

sso_mon_id: required (integer)
sso_mon_id
모니터링 서버 ID(PK)

status
status: required (integer)
연동 상태
판단불가능:	0,	정상:	1,	비정상:	2

reason: required (string - maxLength: 128)
reason
연동 상태에 대한 설명

last_access
last_access: required (string)
마지막 연동 일자

Example:
Example

{
		"code":	"ok",
		"result":	{
				"sso_mon_id":	2,
				"use":	1,
				"is_redist_target":	1,
				"name":	""New	모니터링	서버	이름",
				"type":	1,
				"flag":	1,
				"addr":	"10.10.10.10",
				"tm_out":	60,
				"interval":	3,
				"dmn":	"",
				"syslog_filter_id":	null,
				"proto":	1,
				"ntlmv2":	1,
				"wmi_id":	"example\\administrator",
				"wmi_pw":	"x2xAyWkwMEAh",
				"event_id":	"11111111",
				"sess_enable":	1,
				"sess_interval":	10,
				"prob_enable":	1,
				"prob_interval":	1,
				"keep_enable":	0,
				"status":	1,
				"last_access":	"2018-01-01	10:10:10",
				"desc":	"New	모니터링	서버	설명",
				"reason":	"Unknown"
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

/sso/monitor/servers

모니터링 서버 목록을 (일괄)수정한다.

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
수정될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"sso_mon_id":	1,	"use":	0},
				{"sso_mon_id":	2,	"use":	0}
		]
}

Response

HTTP status code 200

모니터링 서버 목록 수정 성공

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

/sso/monitor/servers

모니터링 서버 목록을 (일괄)삭제한다.

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

Properties
Properties
items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"sso_mon_id":	1},
				{"sso_mon_id":	2}
		]
}

Response

HTTP status code 200

모니터링 서버 목록 삭제 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code: required (one of ok, pok, nok)
code
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

/sso/monitor/servers/{pk}

모니터링 서버을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
모니터링 서버 ID( sso_mon_id )

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

모니터링 서버 조회 성공

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
사용	안함:	0,	사용:	1

is_redist_target: required (one of 0, 1)
is_redist_target
에이전트간 연동 여부
비활성:	0,	활성:	1

name
name: required (string - minLength: 1 - maxLength: 20)
서버 이름
공백	사용	불가

type
type: required (one of 1, 2, 3)
서버 종류
AD:	1,	Syslog:	2,	NGF2Agent:	3

flagflag: required (one of 1, 2)
IP 버전
IPv4:	1,	IPv6:	2

addr
addr: required (string)
IP 주소(IPv4 형식)

tm_out
tm_out: required (integer - default: 60 - minimum: 1 - maximum: 1440)
인증 정보 유지 시간(분)

interval
interval: required (integer - default: 3 - minimum: 1 - maximum: 65535)
서버 모니터링 주기(초)

dmndmn: required (string - maxLength: 32)
도메인
type	속성이	Syslog(2)를	선택한	경우	설정합니다.
영문,	숫자,	특수	문자('-',	'_')	만	허용,	공백	문자	입력	불가

syslog_filter_id
syslog_filter_id: required (integer)
Syslog 필터 ID
type	속성이	Syslog(2)를	선택한	경우	설정합니다.

[Syslog 분석 필터 목록 조회]
GET	{{url}}/api/po/user-auth/syslog/filters
상세	속성	정보는	사용자	인증	고급	설정	문서를	참고하세요.

proto
proto: required (one of 1, 2, 3)
Syslog 프로토콜
UDP:	1,	TCP:	2,	TLS:	3
type	속성이	Syslog(2)를	선택한	경우	설정합니다.

ntlmv2
ntlmv2: required (one of 0, 1)
NTLMv2 인증 사용 여부
사용	안함:	0,	사용:	1
서버 종류(type)가 AD(1)일 경우에 설정

wmi_id
wmi_id: required (string - minLength: 1 - maxLength: 32)
사용자 이름(WMI 설정)
입력 가능한 문자: 영문, 숫자, 특수 문자( _ ,  - ,  \ ,  . ,  ! ,  ~ ,  # ,  ^ ,  & ) 만 허용

wmi_pw
wmi_pw: required (string - minLength: 1 - maxLength: 32)
비밀번호(WMI 설정)
Base64	인코딩	처리	필요

event_id
event_id: required (integer)
모니터링 이벤트 ID
540,	672,	673,	674,	4624,	4768,	4769,	4770	순서대로	2진수	문자열

Example:
Example

11000000	->	540,	672	선택

sess_enable
sess_enable: required (one of 0, 1)
세션 모니터링 사용 여부
사용	안함:	0,	사용:	1

sess_interval
sess_interval: required (integer - default: 10 - minimum: 1 - maximum: 65535)
세션 모니터링 주기

prob_enable
prob_enable: required (one of 0, 1)
Client Probing 사용 여부
사용	안함:	0,	사용:	1

prob_interval
prob_interval: required (integer - default: 1 - minimum: 1 - maximum: 1440)
Client Probing 주기

keep_enable
keep_enable: required (one of 0, 1)
강제 인증 유지
사용	안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

sso_mon_id
sso_mon_id: required (integer)
모니터링 서버 ID(PK)

status
status: required (integer)
연동 상태
판단불가능:	0,	정상:	1,	비정상:	2

reason
reason: required (string - maxLength: 128)
연동 상태에 대한 설명

last_access
last_access: required (string)
마지막 연동 일자

Example:
Example

{
		"code":	"ok",
		"result":	{
				"sso_mon_id":	1,
				"use":	1,
				"is_redist_target":	1,
				"name":	""모니터링서버이름",
				"type":	1,
				"flag":	1,
				"addr":	"10.10.10.10",
				"tm_out":	60,
				"interval":	3,
				"dmn":	"",
				"syslog_filter_id":	null,
				"proto":	1,
				"ntlmv2":	1,
				"wmi_id":	"example\\administrator",
				"wmi_pw":	"x2xAyWkwMEAh",
				"event_id":	"11111111",
				"sess_enable":	1,
				"sess_interval":	10,
				"prob_enable":	1,
				"prob_interval":	1,
				"keep_enable":	0,
				"status":	1,
				"last_access":	"2018-01-01	10:10:10",
				"desc":	"모니터링서버설명",
				"reason":	"Unknown"
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

/sso/monitor/servers/{pk}

모니터링 서버을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
모니터링 서버 ID( sso_mon_id )

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
사용	안함:	0,	사용:	1

is_redist_target
is_redist_target: required (one of 0, 1)
에이전트간 연동 여부
비활성:	0,	활성:	1

name
name: required (string - minLength: 1 - maxLength: 20)
서버 이름
공백	사용	불가

type
type: required (one of 1, 2, 3)
서버 종류
AD:	1,	Syslog:	2,	NGF2Agent:	3

flagflag: required (one of 1, 2)
IP 버전
IPv4:	1,	IPv6:	2

addr: required (string)
addr
IP 주소(IPv4 형식)

tm_out
tm_out: required (integer - default: 60 - minimum: 1 - maximum: 1440)
인증 정보 유지 시간(분)

interval
interval: required (integer - default: 3 - minimum: 1 - maximum: 65535)
서버 모니터링 주기(초)

dmndmn: required (string - maxLength: 32)
도메인
type	속성이	Syslog(2)를	선택한	경우	설정합니다.
영문,	숫자,	특수	문자('-',	'_')	만	허용,	공백	문자	입력	불가

syslog_filter_id: required (integer)
syslog_filter_id
Syslog 필터 ID
type	속성이	Syslog(2)를	선택한	경우	설정합니다.

[Syslog 분석 필터 목록 조회]
GET	{{url}}/api/po/user-auth/syslog/filters
상세	속성	정보는	사용자	인증	고급	설정	문서를	참고하세요.

proto
proto: required (one of 1, 2, 3)
Syslog 프로토콜
UDP:	1,	TCP:	2,	TLS:	3
type	속성이	Syslog(2)를	선택한	경우	설정합니다.

ntlmv2: required (one of 0, 1)
ntlmv2
NTLMv2 인증 사용 여부
사용	안함:	0,	사용:	1
서버 종류(type)가 AD(1)일 경우에 설정

wmi_id: required (string - minLength: 1 - maxLength: 32)
wmi_id

사용자 이름(WMI 설정)
입력 가능한 문자: 영문, 숫자, 특수 문자( _ ,  - ,  \ ,  . ,  ! ,  ~ ,  # ,  ^ ,  & ) 만 허용

wmi_pw
wmi_pw: required (string - minLength: 1 - maxLength: 32)
비밀번호(WMI 설정)
Base64	인코딩	처리	필요

event_id
event_id: required (integer)
모니터링 이벤트 ID
540,	672,	673,	674,	4624,	4768,	4769,	4770	순서대로	2진수	문자열

Example:
Example

11000000	->	540,	672	선택

sess_enable
sess_enable: required (one of 0, 1)
세션 모니터링 사용 여부
사용	안함:	0,	사용:	1

sess_interval
sess_interval: required (integer - default: 10 - minimum: 1 - maximum: 65535)
세션 모니터링 주기

prob_enable
prob_enable: required (one of 0, 1)
Client Probing 사용 여부
사용	안함:	0,	사용:	1

prob_interval
prob_interval: required (integer - default: 1 - minimum: 1 - maximum: 1440)
Client Probing 주기

keep_enable
keep_enable: required (one of 0, 1)
강제 인증 유지
사용	안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

Example:
Example

{
		"use":	1,
		"is_redist_target":	1,
		"name":	"Syslog모니터링서버이름",
		"type":	2,
		"flag":	1,
		"addr":	"20.20.20.20",
		"tm_out":	60,
		"interval":	3,
		"dmn":	"test_example",
		"syslog_filter_id":	1,
		"proto":	1,
		"ntlmv2":	0,
		"wmi_id":	"",
		"wmi_pw":	"",
		"event_id":	"11111111",
		"sess_enable":	0,
		"sess_interval":	10,
		"prob_enable":	0,
		"prob_interval":	1,
		"keep_enable":	0,
		"desc":	"Syslog모니터링서버설명"
}

Response

HTTP status code 200

모니터링 서버 수정 성공

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

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

is_redist_target
is_redist_target: required (one of 0, 1)
에이전트간 연동 여부
비활성:	0,	활성:	1

name: required (string - minLength: 1 - maxLength: 20)
name
서버 이름
공백	사용	불가

type
type: required (one of 1, 2, 3)
서버 종류
AD:	1,	Syslog:	2,	NGF2Agent:	3

flagflag: required (one of 1, 2)
IP 버전
IPv4:	1,	IPv6:	2

addr
addr: required (string)
IP 주소(IPv4 형식)

tm_out
tm_out: required (integer - default: 60 - minimum: 1 - maximum: 1440)
인증 정보 유지 시간(분)

interval
interval: required (integer - default: 3 - minimum: 1 - maximum: 65535)
서버 모니터링 주기(초)

dmndmn: required (string - maxLength: 32)
도메인
type	속성이	Syslog(2)를	선택한	경우	설정합니다.
영문,	숫자,	특수	문자('-',	'_')	만	허용,	공백	문자	입력	불가

syslog_filter_id: required (integer)
syslog_filter_id
Syslog 필터 ID
type	속성이	Syslog(2)를	선택한	경우	설정합니다.

[Syslog 분석 필터 목록 조회]
GET	{{url}}/api/po/user-auth/syslog/filters
상세	속성	정보는	사용자	인증	고급	설정	문서를	참고하세요.

proto
proto: required (one of 1, 2, 3)
Syslog 프로토콜
UDP:	1,	TCP:	2,	TLS:	3
type	속성이	Syslog(2)를	선택한	경우	설정합니다.

ntlmv2
ntlmv2: required (one of 0, 1)
NTLMv2 인증 사용 여부
사용	안함:	0,	사용:	1
서버 종류(type)가 AD(1)일 경우에 설정

wmi_id
wmi_id: required (string - minLength: 1 - maxLength: 32)
사용자 이름(WMI 설정)
입력 가능한 문자: 영문, 숫자, 특수 문자( _ ,  - ,  \ ,  . ,  ! ,  ~ ,  # ,  ^ ,  & ) 만 허용

wmi_pw
wmi_pw: required (string - minLength: 1 - maxLength: 32)
비밀번호(WMI 설정)
Base64	인코딩	처리	필요

event_id: required (integer)
event_id
모니터링 이벤트 ID
540,	672,	673,	674,	4624,	4768,	4769,	4770	순서대로	2진수	문자열

Example:
Example

11000000	->	540,	672	선택

sess_enable
sess_enable: required (one of 0, 1)
세션 모니터링 사용 여부
사용	안함:	0,	사용:	1

sess_interval: required (integer - default: 10 - minimum: 1 - maximum: 65535)
sess_interval
세션 모니터링 주기

prob_enable
prob_enable: required (one of 0, 1)
Client Probing 사용 여부
사용	안함:	0,	사용:	1

prob_interval: required (integer - default: 1 - minimum: 1 - maximum: 1440)
prob_interval
Client Probing 주기

keep_enable
keep_enable: required (one of 0, 1)
강제 인증 유지
사용	안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

sso_mon_id
sso_mon_id: required (integer)
모니터링 서버 ID(PK)

status
status: required (integer)
연동 상태
판단불가능:	0,	정상:	1,	비정상:	2

reason
reason: required (string - maxLength: 128)
연동 상태에 대한 설명

last_access
last_access: required (string)
마지막 연동 일자

Example:
Example

{
		"code":	"ok",
		"result":	{
				"sso_mon_id":	2,
				"use":	1,
				"is_redist_target":	1,
				"name":	"Syslog모니터링서버이름",
				"type":	2,
				"flag":	1,
				"addr":	"1.1.1.1",
				"tm_out":	60,
				"interval":	3,
				"dmn":	"test_example",
				"syslog_filter_id":	1,
				"proto":	1,
				"ntlmv2":	0,
				"wmi_id":	"",
				"event_id":	"11111111",
				"sess_enable":	0,
				"sess_interval":	10,
				"prob_enable":	0,
				"prob_interval":	1,
				"keep_enable":	0,
				"status":	0,
				"last_access":	"",
				"desc":	"Syslog모니터링서버설명",
				"reason":	"Unknown"
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

/sso/monitor/servers/{pk}

모니터링 서버을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
모니터링 서버 ID( sso_mon_id )

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

모니터링 서버 삭제 성공

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

사용자 IP 주소 포함/미포함 대역

GET

/sso/user-ip/bands

사용자 IP 주소 포함/미포함 대역 목록을 조회한다.

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

사용자 IP 주소 포함/미포함 대역 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of GetBand)
result
결과 데이터

Items: GetBand
Items

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

seqseq: (integer)
순번
수정	시	지정된	순번으로	이동합니다.

name
name: required (string - minLength: 1 - maxLength: 64)
이름

type
type: required (one of 1, 2)
타입
포함:	1,	미포함:	2

ipip: required (string)
IP 주소(IPv4, IPv6 모두 지원)
IP 주소 범위와 IP 주소 두 가지 형식으로 설정

Example:
Example

10.10.10.10~20.20.20.20	or	1.2.3.4/24

descdesc: (string - maxLength: 128)
설명

sso_band_id
sso_band_id: required (integer)
포함/미포함 대역 ID(PK)

flagflag: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"sso_band_id":	1,
				"use":	1,
				"seq":	1,
				"name":	"IP	주소	대역	이름",
				"type":	1,
				"flag":	1,
				"ip":	"10.10.10.10/24",
				"desc":	"IP	주소	대역	설명"
		},	{
				"sso_band_id":	1,
				"use":	1,
				"seq":	1,
				"name":	"IP	주소	범위	대역	이름",
				"type":	1,
				"flag":	1,
				"ip":	"10.10.10.10~20.20.20.20",
				"desc":	"IP	주소	범위	대역	설명"
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

POST

/sso/user-ip/bands

사용자 IP 주소 포함/미포함 대역를 추가한다.

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
사용	안함:	0,	사용:	1

seqseq: (integer)
순번
수정	시	지정된	순번으로	이동합니다.

name
name: required (string - minLength: 1 - maxLength: 64)
이름

type
type: required (one of 1, 2)
타입
포함:	1,	미포함:	2

ipip: required (string)
IP 주소(IPv4, IPv6 모두 지원)
IP 주소 범위와 IP 주소 두 가지 형식으로 설정

Example:
Example

10.10.10.10~20.20.20.20	or	1.2.3.4/24

descdesc: (string - maxLength: 128)
설명

Example:
Example

{
		"use":	1,
		"name":	"New	IP	주소	대역	이름",
		"type":	1,
		"ip":	"10.10.10.10/24",
		"desc":	"New	IP	주소	대역	설명"
}

Response

HTTP status code 200

사용자 IP 주소 포함/미포함 대역 추가 성공

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
사용	안함:	0,	사용:	1

user_id
user_id: required (string - minLength: 1 - maxLength: 36)
사용자 ID

descdesc: (string - maxLength: 128)
설명

sso_exid_id
sso_exid_id: required (integer)
예외 사용자 ID(PK)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"sso_band_id":	2,
				"use":	1,
				"seq":	2,
				"use":	1,
				"name":	"New	IP	주소	대역	이름",
				"type":	1,
				"flag":	1,
				"ip":	"10.10.10.10/24",
				"desc":	"New	IP	주소	대역	설명"
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

/sso/user-ip/bands

사용자 IP 주소 포함/미포함 대역 목록을 (일괄)수정한다.

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
				{"sso_band_id":	1,	"use":	1},
				{"sso_band_id":	2,	"use":	1}
		]
}

Response

HTTP status code 200

사용자 IP 주소 포함/미포함 대역 목록 수정 성공

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

/sso/user-ip/bands

사용자 IP 주소 포함/미포함 대역 목록을 (일괄)삭제한다.

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
				{"sso_band_id":	1},
				{"sso_band_id":	2}
		]
}

Response

HTTP status code 200

사용자 IP 주소 포함/미포함 대역 목록 삭제 성공

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

/sso/user-ip/bands/{pk}

사용자 IP 주소 포함/미포함 대역을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
포함/미포함 대역 ID( sso_band_id )

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

사용자 IP 주소 포함/미포함 대역 조회 성공

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

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

seqseq: (integer)
순번
수정	시	지정된	순번으로	이동합니다.

name
name: required (string - minLength: 1 - maxLength: 64)
이름

type
type: required (one of 1, 2)
타입
포함:	1,	미포함:	2

ipip: required (string)
IP 주소(IPv4, IPv6 모두 지원)
IP 주소 범위와 IP 주소 두 가지 형식으로 설정

Example:
Example

10.10.10.10~20.20.20.20	or	1.2.3.4/24

descdesc: (string - maxLength: 128)
설명

sso_band_id
sso_band_id: required (integer)
포함/미포함 대역 ID(PK)

flagflag: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

Example:
Example

{
		"code":	"ok",
		"result":	{
				"sso_band_id":	1,
				"use":	1,
				"seq":	1,
				"use":	1,
				"name":	"IP	주소	대역	이름",
				"type":	1,
				"flag":	1,
				"ip":	"10.10.10.10/24",
				"desc":	"IP	주소	대역	설명"
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

/sso/user-ip/bands/{pk}

사용자 IP 주소 포함/미포함 대역을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
포함/미포함 대역 ID( sso_band_id )

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
사용	안함:	0,	사용:	1

seqseq: (integer)
순번
수정	시	지정된	순번으로	이동합니다.

name: required (string - minLength: 1 - maxLength: 64)
name
이름

type
type: required (one of 1, 2)
타입
포함:	1,	미포함:	2

ipip: required (string)

IP 주소(IPv4, IPv6 모두 지원)
IP 주소 범위와 IP 주소 두 가지 형식으로 설정

Example:
Example

10.10.10.10~20.20.20.20	or	1.2.3.4/24

descdesc: (string - maxLength: 128)
설명

Example:
Example

{
		"seq":	2
}

Response

HTTP status code 200

사용자 IP 주소 포함/미포함 대역 수정 성공

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
사용	안함:	0,	사용:	1

seqseq: (integer)
순번
수정	시	지정된	순번으로	이동합니다.

name
name: required (string - minLength: 1 - maxLength: 64)
이름

type
type: required (one of 1, 2)
타입
포함:	1,	미포함:	2

ipip: required (string)
IP 주소(IPv4, IPv6 모두 지원)
IP 주소 범위와 IP 주소 두 가지 형식으로 설정

Example:
Example

10.10.10.10~20.20.20.20	or	1.2.3.4/24

descdesc: (string - maxLength: 128)
설명

sso_band_id
sso_band_id: required (integer)
포함/미포함 대역 ID(PK)

flagflag: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

Example:
Example

{
		"code":	"ok",
		"result":	{
				"sso_band_id":	1,
				"use":	1,
				"seq":	2,
				"use":	1,
				"name":	"IP	주소	대역	이름",
				"type":	1,
				"flag":	1,
				"ip":	"10.10.10.10/24",
				"desc":	"IP	주소	대역	설명"
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

/sso/user-ip/bands/{pk}

사용자 IP 주소 포함/미포함 대역을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
포함/미포함 대역 ID( sso_band_id )

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

사용자 IP 주소 포함/미포함 대역 삭제 성공

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

예외 사용자 ID

GET

/sso/exception/users

예외 사용자 ID 목록을 조회한다.

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

예외 사용자 ID 목록 조회 성공

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
result: required (array of ExcptGetUser)
결과 데이터

Items: ExcptGetUser
Items

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

user_id
user_id: required (string - minLength: 1 - maxLength: 36)
사용자 ID

descdesc: (string - maxLength: 128)
설명

sso_exid_id
sso_exid_id: required (integer)
예외 사용자 ID(PK)

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"sso_exid_id":	1,
				"use":	1,
				"user_id":	"예외	사용자	ID",
				"desc":	"예외	사용자	설명"
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

POST

/sso/exception/users

예외 사용자 ID를 추가한다.

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

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

user_id
user_id: required (string - minLength: 1 - maxLength: 36)
사용자 ID

descdesc: (string - maxLength: 128)
설명

Example:
Example

{
		"use":	1,
		"user_id":	"New	예외	사용자	ID",
		"desc":	"New	예외	사용자	설명"
}

Response

HTTP status code 200

예외 사용자 ID 추가 성공

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
사용	안함:	0,	사용:	1

user_id
user_id: required (string - minLength: 1 - maxLength: 36)
사용자 ID

descdesc: (string - maxLength: 128)
설명

sso_exid_id
sso_exid_id: required (integer)
예외 사용자 ID(PK)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"sso_exid_id":	2,
				"use":	1,
				"user_id":	"New	예외	사용자	ID",
				"desc":	"New	예외	사용자	설명"
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

/sso/exception/users

예외 사용자 ID 목록을 (일괄)수정한다.

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
				{"sso_exid_id":	1,	"use":	1},
				{"sso_exid_id":	2,	"use":	1}
		]
}

Response

HTTP status code 200

예외 사용자 ID 목록 수정 성공

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

/sso/exception/users

예외 사용자 ID 목록을 (일괄)삭제한다.

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
				{"sso_exid_id":	1},
				{"sso_exid_id":	2}
		]
}

Response

HTTP status code 200

예외 사용자 ID 목록 삭제 성공

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

/sso/exception/users/{pk}

예외 사용자 ID을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
예외 사용자 ID( sso_exid_id )

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

예외 사용자 ID 조회 성공

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
사용	안함:	0,	사용:	1

user_id: required (string - minLength: 1 - maxLength: 36)
user_id
사용자 ID

descdesc: (string - maxLength: 128)
설명

sso_exid_id
sso_exid_id: required (integer)
예외 사용자 ID(PK)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"sso_exid_id":	1,
				"use":	1,
				"user_id":	"예외	사용자	ID",
				"desc":	"예외	사용자	설명"
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

/sso/exception/users/{pk}

예외 사용자 ID을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
예외 사용자 ID( sso_exid_id )

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

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

user_id: required (string - minLength: 1 - maxLength: 36)
user_id
사용자 ID

descdesc: (string - maxLength: 128)
설명

Example:
Example

{
		"use":	0,
		"user_id":	"예외	사용자	ID",
		"desc":	"예외	사용자	설명"
}

Response

HTTP status code 200

예외 사용자 ID 수정 성공

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

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

user_id
user_id: required (string - minLength: 1 - maxLength: 36)
사용자 ID

descdesc: (string - maxLength: 128)
설명

sso_exid_id
sso_exid_id: required (integer)
예외 사용자 ID(PK)

Example:
Example

{
		"code":	"ok",
		"result":	{
				"sso_exid_id":	1,
				"use":	0,
				"user_id":	"예외	사용자	ID",
				"desc":	"예외	사용자	설명"
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

/sso/exception/users/{pk}

예외 사용자 ID을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
예외 사용자 ID( sso_exid_id )

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

예외 사용자 ID 삭제 성공

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

사용자 인증 연동(SSO) 적용/취소

PUT

/command/user-auth-sso/apply

사용자 인증 연동(SSO)을 적용합니다.

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

사용자 인증 연동(SSO) 적용 성공

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

/command/user-auth-sso/cancel

사용자 인증 연동(SSO)을 취소합니다.

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

사용자 인증 연동(SSO) 취소 성공

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

