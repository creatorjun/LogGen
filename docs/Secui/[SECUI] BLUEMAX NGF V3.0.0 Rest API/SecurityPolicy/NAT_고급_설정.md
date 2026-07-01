GET

PUT

GET

PUT

PUT

NAT 고급 설정 REST API 문서

https://{url}/api/po

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/po

NAT 고급 설정

/nat/config

NAT 정책 Low Rule 갯수

/nat/count/lowrule

NAT 고급 설정 적용/취소

/command/nat-config/apply

/command/nat-config/cancel

NAT 고급 설정

GET

/nat/config

NAT 고급 설정을(를) 조회한다.

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

NAT 고급 설정 조회 성공

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
NAT 사용 여부
사용	안함:	0,	사용:	1

chk_shadowed
chk_shadowed: required (one of 0, 1)
정책 적용 시 Shadow 정책 자동 제외
사용	안함:	0,	사용:	1

chk_src_dup
chk_src_dup: required (one of 0, 1)
정책 적용 시 변경 후 출발지 주소 중복 검사
사용	안함:	0,	사용:	1

ha_mmbr_use
ha_mmbr_use: required (one of 0, 1)
HA 멤버 별 NAT 설정
사용	안함:	0,	사용:	1

sync_nat_session: required (one of 0, 1)
sync_nat_session
NAT 세션 동기화 수행
사용	안함:	0,	사용:	1

del_all_session_on_apply
del_all_session_on_apply: required (one of 0, 1)
정책 적용 시 기존 NAT 세션 테이블 삭제
사용	안함:	0,	사용:	1

server_chk_interval
server_chk_interval: required (integer - default: 5 - minimum: 0 - maximum: 604800)
서버 상태 검사 주기

ip_alloc_method
ip_alloc_method: required (one of 1, 2, 3, 4)
IP 할당 방식
임의:	1,	순차:	2,	라운드로빈:	3,	Hole	Punching	교란:	4

port_alloc_method
port_alloc_method: required (one of 1, 3, 4)
포트 할당 방식
임의:	1,	라운드로빈:	3,	Hole	Punching	교란:	4

psnat_cuseeme
psnat_cuseeme: required (one of 0, 1)
프로토콜 별 NAT CuSeeMe
사용	안함:	0,	사용:	1

psnat_ftp
psnat_ftp: required (one of 0, 1)
프로토콜 별 NAT FTP
사용	안함:	0,	사용:	1

psnat_h323: required (one of 0, 1)
psnat_h323
프로토콜 별 NAT H.323
사용	안함:	0,	사용:	1

psnat_irc
psnat_irc: required (one of 0, 1)
프로토콜별 NAT IRC
사용	안함:	0,	사용:	1

psnat_mms
psnat_mms: required (one of 0, 1)
프로토콜 별 NAT MMS
사용	안함:	0,	사용:	1

psnat_netbios
psnat_netbios: required (one of 0, 1)
프로토콜 별 NAT NetBIOS
사용	안함:	0,	사용:	1

psnat_pptp
psnat_pptp: required (one of 0, 1)
프로토콜 별 NAT PPTP
사용	안함:	0,	사용:	1

psnat_rtsp
psnat_rtsp: required (one of 0, 1)
프로토콜 별 NAT RTSP
사용	안함:	0,	사용:	1

psnat_tftp
psnat_tftp: required (one of 0, 1)
프로토콜 별 NAT TFTP
사용	안함:	0,	사용:	1

psnat_sqlnet
psnat_sqlnet: required (one of 0, 1)
프로토콜 별 NAT SQLNET
사용	안함:	0,	사용:	1

psnat_sip
psnat_sip: required (one of 0, 1)
프로토콜 별 NAT SIP
사용	안함:	0,	사용:	1

port_pool_min_port
port_pool_min_port: required (integer - default: 10000 - minimum: 10000 - maximum: 50000)
포트 할당 범위 최솟값

SupportedVersion:	2.0.0

port_pool_max_port: required (integer - default: 60000 - maximum: 60000)
port_pool_max_port
포트 할당 범위 최댓값
최솟값	보다	큰값

SupportedVersion:	2.0.0

nat_at_fw: required (integer)
nat_at_fw
히든 옵션  (GUI에서	사용하지	않음)

create_except_drule
create_except_drule: required (integer)
히든 옵션  (GUI에서	사용하지	않음)

br_nat
br_nat: required (integer)
히든 옵션  (GUI에서	사용하지	않음)

garp_cnt
garp_cnt: required (integer - minimum: 1 - maximum: 10)
전송 횟수(1~10)
min: 1, max: 10, default: 1

SupportedVersion:	2.1.0

garp_interval
garp_interval: required (integer - default: 2 - minimum: 0 - maximum: 1000)
전송 시간 간격(ms)
min: 0, max: 1000, default: 2

SupportedVersion:	2.1.0

Example:
Example

{
		"code":	"ok",
		"result":	{
				"use":	1,
				"chk_shadowed":	1,
				"chk_src_dup":	1,
				"ha_mmbr_use":	1,
				"sync_nat_session":	1,
				"del_all_session_on_apply":	1,
				"server_chk_interval":	1,
				"ip_alloc_method":	1,
				"port_alloc_method":	1,
				"nat_at_fw":	0,
				"create_except_drule":	0,
				"br_nat":	0,
				"garp_cnt":	1,
				"garp_interval":	2,
				"port_pool_min_port":	10000,
				"port_pool_max_port":	60000,
				"psnat_cuseeme":	1,
				"psnat_ftp":	1,
				"psnat_h323":	1,
				"psnat_irc":	1,
				"psnat_mms":	1,
				"psnat_netbios":	1,
				"psnat_pptp":	1,
				"psnat_rtsp":	1,
				"psnat_tftp":	1,
				"psnat_sqlnet":	1,
				"psnat_sip":	1
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

/nat/config

NAT 고급 설정을(를) 수정한다.

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
NAT 사용 여부
사용	안함:	0,	사용:	1

chk_shadowed
chk_shadowed: required (one of 0, 1)
정책 적용 시 Shadow 정책 자동 제외
사용	안함:	0,	사용:	1

chk_src_dup
chk_src_dup: required (one of 0, 1)
정책 적용 시 변경 후 출발지 주소 중복 검사
사용	안함:	0,	사용:	1

ha_mmbr_use
ha_mmbr_use: required (one of 0, 1)
HA 멤버 별 NAT 설정
사용	안함:	0,	사용:	1

sync_nat_session
sync_nat_session: required (one of 0, 1)
NAT 세션 동기화 수행
사용	안함:	0,	사용:	1

del_all_session_on_apply
del_all_session_on_apply: required (one of 0, 1)
정책 적용 시 기존 NAT 세션 테이블 삭제
사용	안함:	0,	사용:	1

server_chk_interval
server_chk_interval: required (integer - default: 5 - minimum: 0 - maximum: 604800)
서버 상태 검사 주기

ip_alloc_method
ip_alloc_method: required (one of 1, 2, 3, 4)
IP 할당 방식
임의:	1,	순차:	2,	라운드로빈:	3,	Hole	Punching	교란:	4

port_alloc_method
port_alloc_method: required (one of 1, 3, 4)
포트 할당 방식
임의:	1,	라운드로빈:	3,	Hole	Punching	교란:	4

psnat_cuseeme
psnat_cuseeme: required (one of 0, 1)
프로토콜 별 NAT CuSeeMe
사용	안함:	0,	사용:	1

psnat_ftp: required (one of 0, 1)
psnat_ftp

프로토콜 별 NAT FTP
사용	안함:	0,	사용:	1

psnat_h323
psnat_h323: required (one of 0, 1)
프로토콜 별 NAT H.323
사용	안함:	0,	사용:	1

psnat_irc
psnat_irc: required (one of 0, 1)
프로토콜별 NAT IRC
사용	안함:	0,	사용:	1

psnat_mms: required (one of 0, 1)
psnat_mms
프로토콜 별 NAT MMS
사용	안함:	0,	사용:	1

psnat_netbios
psnat_netbios: required (one of 0, 1)
프로토콜 별 NAT NetBIOS
사용	안함:	0,	사용:	1

psnat_pptp
psnat_pptp: required (one of 0, 1)
프로토콜 별 NAT PPTP
사용	안함:	0,	사용:	1

psnat_rtsp
psnat_rtsp: required (one of 0, 1)
프로토콜 별 NAT RTSP
사용	안함:	0,	사용:	1

psnat_tftp
psnat_tftp: required (one of 0, 1)
프로토콜 별 NAT TFTP
사용	안함:	0,	사용:	1

psnat_sqlnet: required (one of 0, 1)
psnat_sqlnet
프로토콜 별 NAT SQLNET
사용	안함:	0,	사용:	1

psnat_sip
psnat_sip: required (one of 0, 1)
프로토콜 별 NAT SIP
사용	안함:	0,	사용:	1

port_pool_min_port
port_pool_min_port: required (integer - default: 10000 - minimum: 10000 - maximum: 50000)
포트 할당 범위 최솟값

SupportedVersion:	2.0.0

port_pool_max_port: required (integer - default: 60000 - maximum: 60000)
port_pool_max_port
포트 할당 범위 최댓값
최솟값	보다	큰값

SupportedVersion:	2.0.0

Example:
Example

{
		"use":	1,
		"chk_shadowed":	1,
		"chk_src_dup":	1,
		"ha_mmbr_use":	1,
		"sync_nat_session":	1,
		"del_all_session_on_apply":	1,
		"server_chk_interval":	1,
		"ip_alloc_method":	1,
		"port_alloc_method":	1,
		"nat_at_fw":	1,
		"create_except_drule":	1,
		"br_nat":	1,
		"garp_cnt":	1,
		"garp_interval":	2,
		"port_pool_min_port":	10000,
		"port_pool_max_port":	60000,
		"psnat_cuseeme":	1,
		"psnat_ftp":	1,
		"psnat_h323":	1,
		"psnat_irc":	1,
		"psnat_mms":	1,
		"psnat_netbios":	1,
		"psnat_pptp":	1,
		"psnat_rtsp":	1,
		"psnat_tftp":	1,
		"psnat_sqlnet":	1,
		"psnat_sip":	1
}

Response

HTTP status code 200

NAT 고급 설정 수정 성공

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

NAT 사용 여부
사용	안함:	0,	사용:	1

chk_shadowed
chk_shadowed: required (one of 0, 1)
정책 적용 시 Shadow 정책 자동 제외
사용	안함:	0,	사용:	1

chk_src_dup
chk_src_dup: required (one of 0, 1)
정책 적용 시 변경 후 출발지 주소 중복 검사
사용	안함:	0,	사용:	1

ha_mmbr_use: required (one of 0, 1)
ha_mmbr_use
HA 멤버 별 NAT 설정
사용	안함:	0,	사용:	1

sync_nat_session
sync_nat_session: required (one of 0, 1)
NAT 세션 동기화 수행
사용	안함:	0,	사용:	1

del_all_session_on_apply
del_all_session_on_apply: required (one of 0, 1)
정책 적용 시 기존 NAT 세션 테이블 삭제
사용	안함:	0,	사용:	1

server_chk_interval
server_chk_interval: required (integer - default: 5 - minimum: 0 - maximum: 604800)
서버 상태 검사 주기

ip_alloc_method
ip_alloc_method: required (one of 1, 2, 3, 4)
IP 할당 방식
임의:	1,	순차:	2,	라운드로빈:	3,	Hole	Punching	교란:	4

port_alloc_method
port_alloc_method: required (one of 1, 3, 4)
포트 할당 방식
임의:	1,	라운드로빈:	3,	Hole	Punching	교란:	4

psnat_cuseeme
psnat_cuseeme: required (one of 0, 1)
프로토콜 별 NAT CuSeeMe
사용	안함:	0,	사용:	1

psnat_ftp: required (one of 0, 1)
psnat_ftp
프로토콜 별 NAT FTP
사용	안함:	0,	사용:	1

psnat_h323
psnat_h323: required (one of 0, 1)
프로토콜 별 NAT H.323
사용	안함:	0,	사용:	1

psnat_irc
psnat_irc: required (one of 0, 1)
프로토콜별 NAT IRC
사용	안함:	0,	사용:	1

psnat_mms
psnat_mms: required (one of 0, 1)
프로토콜 별 NAT MMS
사용	안함:	0,	사용:	1

psnat_netbios
psnat_netbios: required (one of 0, 1)
프로토콜 별 NAT NetBIOS
사용	안함:	0,	사용:	1

psnat_pptp: required (one of 0, 1)
psnat_pptp
프로토콜 별 NAT PPTP
사용	안함:	0,	사용:	1

psnat_rtsp
psnat_rtsp: required (one of 0, 1)
프로토콜 별 NAT RTSP
사용	안함:	0,	사용:	1

psnat_tftp
psnat_tftp: required (one of 0, 1)
프로토콜 별 NAT TFTP
사용	안함:	0,	사용:	1

psnat_sqlnet
psnat_sqlnet: required (one of 0, 1)
프로토콜 별 NAT SQLNET
사용	안함:	0,	사용:	1

psnat_sip
psnat_sip: required (one of 0, 1)
프로토콜 별 NAT SIP
사용	안함:	0,	사용:	1

port_pool_min_port: required (integer - default: 10000 - minimum: 10000 - maximum: 50000)
port_pool_min_port
포트 할당 범위 최솟값

SupportedVersion:	2.0.0

port_pool_max_port
port_pool_max_port: required (integer - default: 60000 - maximum: 60000)
포트 할당 범위 최댓값
최솟값	보다	큰값

SupportedVersion:	2.0.0

nat_at_fw
nat_at_fw: required (integer)
히든 옵션  (GUI에서	사용하지	않음)

create_except_drule: required (integer)
create_except_drule
히든 옵션  (GUI에서	사용하지	않음)

br_nat
br_nat: required (integer)
히든 옵션  (GUI에서	사용하지	않음)

garp_cnt: required (integer - minimum: 1 - maximum: 10)
garp_cnt
전송 횟수(1~10)
min: 1, max: 10, default: 1

SupportedVersion:	2.1.0

garp_interval
garp_interval: required (integer - default: 2 - minimum: 0 - maximum: 1000)
전송 시간 간격(ms)
min: 0, max: 1000, default: 2

SupportedVersion:	2.1.0

Example:
Example

{
		"code":	"ok",
		"result":	{
				"use":	1,
				"chk_shadowed":	1,
				"chk_src_dup":	1,
				"ha_mmbr_use":	1,
				"sync_nat_session":	1,
				"del_all_session_on_apply":	1,
				"server_chk_interval":	1,
				"ip_alloc_method":	1,
				"port_alloc_method":	1,
				"port_pool_min_port":	10000,
				"port_pool_max_port":	60000,
				"psnat_cuseeme":	1,
				"psnat_ftp":	1,
				"psnat_h323":	1,
				"psnat_irc":	1,
				"psnat_mms":	1,
				"psnat_netbios":	1,
				"psnat_pptp":	1,
				"psnat_rtsp":	1,
				"psnat_tftp":	1,
				"psnat_sqlnet":	1,
				"psnat_sip":	1,
				"nat_at_fw":	1,
				"create_except_drule":	1,
				"br_nat":	1,
				"garp_cnt":	1,
				"garp_interval":	2
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

dev_t
dev_t: (string)
개발용 메시지

Example:
Example

{
		"code":	"12001",
		"message":	"존재하지	않는	항목입니다."
}

NAT 정책 Low Rule 갯수

GET

/nat/count/lowrule

NAT 정책 Low Rule 갯수을(를) 조회한다.

Request

Annotations

SupportedVersion:
SupportedVersion

"3.0.0"

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

NAT 정책 Low Rule 갯수 조회 성공

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

count
count: required (integer)
Low Rule 갯수

Example:
Example

{
		"code":	"ok",
		"result":	{
				"count":	100
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

NAT 고급 설정 적용/취소

PUT

/command/nat-config/apply

NAT 고급 설정을 적용합니다.

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

NAT 고급 설정 적용 성공

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

/command/nat-config/cancel

NAT 고급 설정을 취소합니다.

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

NAT 고급 설정 취소 성공

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

