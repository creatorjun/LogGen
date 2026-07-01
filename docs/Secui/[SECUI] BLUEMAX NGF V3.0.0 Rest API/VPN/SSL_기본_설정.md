GET

PUT

GET

PUT

PUT

SSL 기본 설정 REST API 문서

https://{url}/api/vp

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/vp

SSL 기본 설정

/sslvpn/general

/sslvpn/general/interfaces

SSL 기본 설정 적용/취소

/command/sslvpn-general/apply

/command/sslvpn-general/cancel

SSL 기본 설정

GET

/sslvpn/general

SSL 기본 설정을(를) 조회한다.

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

SSL 기본 설정 조회 성공

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

useuse: required (one of 0, 1 - default: 0)
SSL VPN 기능 사용 여부
사용안함:	0,	사용:	1

access_ip
access_ip: required (string)
SSL VPN 접속 IPv4 주소
IPv4	형식
최초	조회	시	null

access_v6ip: (string)
access_v6ip
SSL VPN 접속 IPv6 주소
IPv6	형식
최초	조회	시	null

SupportedVersion:	2.0.0

access_port
access_port: (integer - default: 8443 - minimum: 1 - maximum: 65535)
SSL VPN 접속 포트

dns1dns1: required (string)
1차 DNS 설정 주소
최초	조회	시	null

dns2dns2: required (string)
2차 DNS 설정 주소
최초	조회	시	null

tnl_port
tnl_port: required (integer - default: 8080 - minimum: 1 - maximum: 65535)
터널 포트

lease_ip
lease_ip: required (string)
임대 IP 대역 IP
IPv4	형식

lease_netmask
lease_netmask: required (string)
임대 넷마스크
IPv4	형식

Example:
Example

255.255.255.0

ip_cnt: required (integer - default: 253)
ip_cnt
할당 가능한 임대 IP주소 갯수

prtc_type
prtc_type: required (one of 0, 1, 2, 3)
프로토콜 유형
None:	0,	TCP:	1,	TCP(가속):	2,	UDP:	3

tcp_accel_use: required (one of 0, 1 - default: 0)
tcp_accel_use
TCP 가속 사용 여부
TCP	최적화:	0,	TCP	가속화:	1

algr_type
algr_type: required (one of 0, 1, 2, 3, 4, 5, 6, 7 - default: 0)
알고리즘 유형
AES128:	0
AES192:	1
AES256:	2
SEED:	3
ARIA128:	4
ARIA192:	5
ARIA256:	6
3DES:	7

comp_use
comp_use: required (one of 0, 1 - default: 1)
압축 사용 여부
사용안함:	0,	사용:	1

idle_tm_use: required (one of 0, 1 - default: 1)
idle_tm_use
유휴 시간 사용 여부
사용안함:	0,	사용:	1

idle_tm_min
idle_tm_min: required (integer - default: 30 - minimum: 1 - maximum: 1440)
유휴 시간(분)

sess_chk_sec: required (integer - default: 10 - minimum: 10 - maximum: 60)
sess_chk_sec
세션 헬스 체크 주기

sess_chk_cnt
sess_chk_cnt: required (integer - default: 12 - minimum: 6 - maximum: 1440)
헬스 체크 시도 실패 제한 횟수

reconn_use
reconn_use: required (one of 0, 1 - default: 0)
자동 재접속 사용 여부
사용안함:	0,	사용:	1

reconn_type
reconn_type: required (one of 0, 1 - default: 0)
재접속 유형
주기	설정:0,	무한	재접속:	1

reconn_sec
reconn_sec: required (integer - default: 30 - minimum: 1 - maximum: 60)
재접속 시간

reconn_cnt
reconn_cnt: required (integer - default: 5 - minimum: 1 - maximum: 1440)
재접속 횟수

proxy_use: required (one of 0, 1 - default: 0)
proxy_use
프록시 사용 여부
사용안함:	0,	사용:	1

proxy_port
proxy_port: required (integer - default: 8070)
프록시 포트

clnt_gw_use: required (one of 0, 1 - default: 0)
clnt_gw_use

클라이언트 게이트웨이 사용 여부
사용안함:	0,	사용:	1

cfg_adm_id
cfg_adm_id: required (integer)
등록자 ID

cfg_adm
cfg_adm: required (string)
등록자

cfg_dt
cfg_dt: required (string)
최근 수정일

Example:
Example

{
		"code":	"ok",
		"result":	{
				"access_ip":	"192.168.10.10",
				"access_v6ip":	"1234::5678",
				"use":	1,
				"dns1":	"10.10.10.10",
				"dns2":	"11.11.11.11",
				"tnl_port":	8080,
				"lease_ip":	"1.2.3.0",
				"lease_netmask":	"255.255.255.0",
				"ip_cnt":	253,
				"prtc_type":	0,
				"tcp_accel_use":	0,
				"algr_type":	3,
				"comp_use":	1,
				"idle_tm_use":	1,
				"idle_tm_min":	30,
				"sess_chk_sec":	10,
				"sess_chk_cnt":	12,
				"reconn_use":	0,
				"reconn_type":	0,
				"reconn_sec":	30,
				"reconn_cnt":	5,
				"proxy_use":	0,
				"proxy_port":	8070,
				"clnt_gw_use":	0,
				"cfg_adm_id":	14,
				"cfg_adm":	"admin",
				"cfg_dt":	"2019-12-12	18:40:00"
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

/sslvpn/general

SSL 기본 설정을(를) 수정한다.

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

useuse: required (one of 0, 1 - default: 0)
SSL VPN 기능 사용 여부
사용안함:	0,	사용:	1

access_ip
access_ip: required (string)
SSL VPN 접속 IPv4 주소
IPv4	형식
최초	조회	시	null

access_v6ip
access_v6ip: (string)
SSL VPN 접속 IPv6 주소
IPv6	형식
최초	조회	시	null

SupportedVersion:	2.0.0

access_port
access_port: (integer - default: 8443 - minimum: 1 - maximum: 65535)
SSL VPN 접속 포트

dns1dns1: required (string)
1차 DNS 설정 주소
최초	조회	시	null

dns2dns2: required (string)
2차 DNS 설정 주소
최초	조회	시	null

tnl_port
tnl_port: required (integer - default: 8080 - minimum: 1 - maximum: 65535)
터널 포트

lease_ip
lease_ip: required (string)
임대 IP 대역 IP
IPv4	형식

lease_netmask
lease_netmask: required (string)
임대 넷마스크
IPv4	형식

Example:
Example

255.255.255.0

ip_cnt
ip_cnt: required (integer - default: 253)
할당 가능한 임대 IP주소 갯수

prtc_type
prtc_type: required (one of 0, 1, 2, 3)
프로토콜 유형
None:	0,	TCP:	1,	TCP(가속):	2,	UDP:	3

tcp_accel_use
tcp_accel_use: required (one of 0, 1 - default: 0)
TCP 가속 사용 여부
TCP	최적화:	0,	TCP	가속화:	1

algr_type
algr_type: required (one of 0, 1, 2, 3, 4, 5, 6, 7 - default: 0)
알고리즘 유형
AES128:	0
AES192:	1
AES256:	2
SEED:	3
ARIA128:	4
ARIA192:	5
ARIA256:	6
3DES:	7

comp_use
comp_use: required (one of 0, 1 - default: 1)
압축 사용 여부
사용안함:	0,	사용:	1

idle_tm_use
idle_tm_use: required (one of 0, 1 - default: 1)
유휴 시간 사용 여부
사용안함:	0,	사용:	1

idle_tm_min
idle_tm_min: required (integer - default: 30 - minimum: 1 - maximum: 1440)
유휴 시간(분)

sess_chk_sec
sess_chk_sec: required (integer - default: 10 - minimum: 10 - maximum: 60)
세션 헬스 체크 주기

sess_chk_cnt
sess_chk_cnt: required (integer - default: 12 - minimum: 6 - maximum: 1440)
헬스 체크 시도 실패 제한 횟수

reconn_use
reconn_use: required (one of 0, 1 - default: 0)
자동 재접속 사용 여부
사용안함:	0,	사용:	1

reconn_type
reconn_type: required (one of 0, 1 - default: 0)
재접속 유형
주기	설정:0,	무한	재접속:	1

reconn_sec
reconn_sec: required (integer - default: 30 - minimum: 1 - maximum: 60)
재접속 시간

reconn_cnt
reconn_cnt: required (integer - default: 5 - minimum: 1 - maximum: 1440)
재접속 횟수

proxy_use
proxy_use: required (one of 0, 1 - default: 0)
프록시 사용 여부
사용안함:	0,	사용:	1

proxy_port
proxy_port: required (integer - default: 8070)
프록시 포트

clnt_gw_use
clnt_gw_use: required (one of 0, 1 - default: 0)
클라이언트 게이트웨이 사용 여부
사용안함:	0,	사용:	1

Example:
Example

{
		"access_ip":	"192.168.10.10",
		"access_v6ip":	"1234::5678",
		"use":	1,
		"dns1":	"10.10.10.10",
		"dns2":	"11.11.11.11",
		"tnl_port":	8080,
		"lease_ip":	"1.2.3.0",
		"lease_netmask":	"255.255.255.0",
		"ip_cnt":	253,
		"prtc_type":	0,
		"tcp_accel_use":	0,
		"algr_type":	3,
		"comp_use":	1,
		"idle_tm_use":	1,
		"idle_tm_min":	30,
		"sess_chk_sec":	10,
		"sess_chk_cnt":	12,
		"reconn_use":	0,
		"reconn_type":	0,
		"reconn_sec":	30,
		"reconn_cnt":	5,
		"proxy_use":	0,
		"proxy_port":	8070,
		"clnt_gw_use":	0
}

Response

HTTP status code 200

SSL 기본 설정 수정 성공

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

useuse: required (one of 0, 1 - default: 0)
SSL VPN 기능 사용 여부
사용안함:	0,	사용:	1

access_ip
access_ip: required (string)
SSL VPN 접속 IPv4 주소
IPv4	형식
최초	조회	시	null

access_v6ip
access_v6ip: (string)
SSL VPN 접속 IPv6 주소
IPv6	형식
최초	조회	시	null

SupportedVersion:	2.0.0

access_port
access_port: (integer - default: 8443 - minimum: 1 - maximum: 65535)
SSL VPN 접속 포트

dns1dns1: required (string)
1차 DNS 설정 주소
최초	조회	시	null

dns2dns2: required (string)
2차 DNS 설정 주소
최초	조회	시	null

tnl_port
tnl_port: required (integer - default: 8080 - minimum: 1 - maximum: 65535)
터널 포트

lease_ip
lease_ip: required (string)
임대 IP 대역 IP
IPv4	형식

lease_netmask
lease_netmask: required (string)
임대 넷마스크
IPv4	형식

Example:
Example

255.255.255.0

ip_cnt
ip_cnt: required (integer - default: 253)
할당 가능한 임대 IP주소 갯수

prtc_type: required (one of 0, 1, 2, 3)
prtc_type
프로토콜 유형
None:	0,	TCP:	1,	TCP(가속):	2,	UDP:	3

tcp_accel_use
tcp_accel_use: required (one of 0, 1 - default: 0)
TCP 가속 사용 여부
TCP	최적화:	0,	TCP	가속화:	1

algr_type
algr_type: required (one of 0, 1, 2, 3, 4, 5, 6, 7 - default: 0)
알고리즘 유형
AES128:	0
AES192:	1
AES256:	2
SEED:	3
ARIA128:	4
ARIA192:	5
ARIA256:	6
3DES:	7

comp_use: required (one of 0, 1 - default: 1)
comp_use
압축 사용 여부
사용안함:	0,	사용:	1

idle_tm_use
idle_tm_use: required (one of 0, 1 - default: 1)
유휴 시간 사용 여부
사용안함:	0,	사용:	1

idle_tm_min
idle_tm_min: required (integer - default: 30 - minimum: 1 - maximum: 1440)
유휴 시간(분)

sess_chk_sec
sess_chk_sec: required (integer - default: 10 - minimum: 10 - maximum: 60)
세션 헬스 체크 주기

sess_chk_cnt: required (integer - default: 12 - minimum: 6 - maximum: 1440)
sess_chk_cnt
헬스 체크 시도 실패 제한 횟수

reconn_use
reconn_use: required (one of 0, 1 - default: 0)
자동 재접속 사용 여부
사용안함:	0,	사용:	1

reconn_type: required (one of 0, 1 - default: 0)
reconn_type
재접속 유형
주기	설정:0,	무한	재접속:	1

reconn_sec
reconn_sec: required (integer - default: 30 - minimum: 1 - maximum: 60)
재접속 시간

reconn_cnt: required (integer - default: 5 - minimum: 1 - maximum: 1440)
reconn_cnt
재접속 횟수

proxy_use
proxy_use: required (one of 0, 1 - default: 0)
프록시 사용 여부
사용안함:	0,	사용:	1

proxy_port
proxy_port: required (integer - default: 8070)
프록시 포트

clnt_gw_use
clnt_gw_use: required (one of 0, 1 - default: 0)
클라이언트 게이트웨이 사용 여부
사용안함:	0,	사용:	1

cfg_adm_id
cfg_adm_id: required (integer)
등록자 ID

cfg_adm
cfg_adm: required (string)
등록자

cfg_dt
cfg_dt: required (string)
최근 수정일

Example:
Example

{
		"code":	"ok",
		"result":	{
				"access_ip":	"192.168.10.10",
				"access_v6ip":	"1234::5678",
				"use":	1,
				"dns1":	"10.10.10.10",
				"dns2":	"11.11.11.11",
				"tnl_port":	8080,
				"lease_ip":	"1.2.3.0",
				"lease_netmask":	"255.255.255.0",
				"ip_cnt":	253,
				"prtc_type":	0,
				"tcp_accel_use":	0,
				"algr_type":	3,
				"comp_use":	1,
				"idle_tm_use":	1,
				"idle_tm_min":	30,
				"sess_chk_sec":	10,
				"sess_chk_cnt":	12,
				"reconn_use":	0,
				"reconn_type":	0,
				"reconn_sec":	30,
				"reconn_cnt":	5,
				"proxy_use":	0,
				"proxy_port":	8070,
				"clnt_gw_use":	0,
				"cfg_adm_id":	14,
				"cfg_adm":	"admin",
				"cfg_dt":	"2019-12-12	18:40:00"
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

GET

/sslvpn/general/interfaces

인터페이스 목록을 조회한다.

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

인터페이스 목록 조회 성공

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
result: required (array of Interface)
결과 데이터

Items: Interface
Items

eth1eth1: required (array of items)
인터페이스 이름이 키값으로 사용됨
ex)	eth1,	eth2,	eth3	...

Items: items
Items

inf_l3_static_addr_id
inf_l3_static_addr_id: required (string)
인터페이스 ID

ipip: required (string)
IP

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"eth1":	[{
								"inf_l3_static_addr_id":	"1",
								"ip":	"1.1.1.1"
						}]
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

SSL 기본 설정 적용/취소

PUT

/command/sslvpn-general/apply

SSL 기본 설정을 적용합니다.

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

Example:
Example

{}

Response

HTTP status code 200

SSL 기본 설정 적용 성공

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

/command/sslvpn-general/cancel

SSL 기본 설정을 취소합니다.

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

SSL 기본 설정 취소 성공

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

