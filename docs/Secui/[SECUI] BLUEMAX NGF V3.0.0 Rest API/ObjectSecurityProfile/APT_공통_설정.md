GET

GET

PUT

GET

PUT

PUT

APT 공통 설정 REST API 문서

https://{url}/api/op

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/op

APT DB 체크

/apt/dbcheck

APT 공통 설정

/apt/setting

클라우드 기반 데이터 수집 동의서 보기

/apt/cloud/collection/agreement

APT 공통 설정 적용/취소

/command/apt-setting/apply

/command/apt-setting/cancel

APT DB 체크

GET

/apt/dbcheck

APT DB 체크을(를) 조회한다.

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

APT DB 체크 조회 성공

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

result
result: required (integer)
DB 업데이트 여부
업데이트	필요:	0,	업데이트	완료:	1

Example:
Example

{
		"code":	"ok",
		"result":	{
				"result":	1
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

APT 공통 설정

GET

/apt/setting

APT 공통 설정을(를) 조회한다.

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

APT 공통 설정 조회 성공

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

svr_type
svr_type: required (integer - default: 1)
분석장비 타입
클라우드:	1,	MBAS:	2

svr_ip_type
svr_ip_type: required (integer)
MBAS IP 버전
IPv4:	1,	IPv6:	2

apt_svr_ip: required (string)
apt_svr_ip
분석 장비 IP 주소
svr_ip_type 가 1일 때 v4 IP
svr_ip_type 가 2일 때 v6 IP

cld_agree
cld_agree: required (integer)
클라우드 수집 동의 여부
사용	안함:	0,	사용:	1

cld_snd_type
cld_snd_type: required (integer - default: 1)
클라우드 전송 유형
파일:	0,	해시:	1

cnc_block_use: required (integer)
cnc_block_use
C&C 차단 설정 사용 여부
사용	안함:	0,	사용:	1

cnc_block_hour
cnc_block_hour: required (integer - default: 1 - minimum: 1 - maximum: 720)
C&C 차단 설정 차단 시간

hrst_detect_score: required (integer - default: 300 - minimum: 25 - maximum: 1000)
hrst_detect_score
휴리스틱 설정 탐지 점수

hrst_block_hour
hrst_block_hour: required (integer - default: 1 - minimum: 1 - maximum: 720)
휴리스틱 설정 차단 시간

apt_excpt_list: required (object)
apt_excpt_list

APT 예외 프로파일

idid: required (integer)
APT 예외 프로파일 ID

name: required (string)
name
APT 예외 프로파일 이름

mbas_key
mbas_key: required (string)
MBAS 키
GUI에서	사용하지	않음 GUI

gc_sleep_term
gc_sleep_term: required (integer)
GUI에서	사용하지	않음

report_sleep_term
report_sleep_term: required (integer)
GUI에서	사용하지	않음

white_cache_expire_tm: required (integer)
white_cache_expire_tm
GUI에서	사용하지	않음

black_cache_expire_tm
black_cache_expire_tm: required (integer)
GUI에서	사용하지	않음

hit_stat_term
hit_stat_term: required (integer)
GUI에서	사용하지	않음

hit_snd_cnt
hit_snd_cnt: required (integer)
GUI에서	사용하지	않음

ht_exp_time
ht_exp_time: required (integer)
GUI에서	사용하지	않음

cache_exp_time: required (integer)
cache_exp_time
GUI에서	사용하지	않음

conn_timeout_p
conn_timeout_p: required (integer)
GUI에서	사용하지	않음

recv_timeout_p: required (integer)
recv_timeout_p
GUI에서	사용하지	않음

Example:
Example

{
		"code":	"ok",
		"result":	{
				"svr_ip_type":	1,
				"apt_svr_ip":	"100.100.100.100",
				"cld_agree":	0,
				"cld_snd_type":	1,
				"cnc_block_use":	1,
				"cnc_block_hour":	1,
				"hrst_detect_score":	300,
				"hrst_block_hour":	1,
				"svr_type":	1,
				"mbas_key":	"",
				"gc_sleep_term":	300,
				"report_sleep_term":	10,
				"white_cache_expire_tm":	1,
				"black_cache_expire_tm":	7200,
				"hit_stat_term":	120,
				"hit_snd_cnt":	1,
				"ht_exp_time":	3600,
				"cache_exp_time":	3600,
				"conn_timeout_p":	1000,
				"recv_timeout_p":	1000,
				"apt_excpt_list":	{
						"id":	1,
						"name":	"APT	예외	프로파일	이름"
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

/apt/setting

APT 공통 설정을(를) 수정한다.

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

svr_type
svr_type: required (integer - default: 1)
분석장비 타입
클라우드:	1,	MBAS:	2

svr_ip_type: required (integer)
svr_ip_type
MBAS IP 버전
IPv4:	1,	IPv6:	2

apt_svr_ip
apt_svr_ip: required (string)
분석 장비 IP 주소
svr_ip_type 가 1일 때 v4 IP
svr_ip_type 가 2일 때 v6 IP

cld_agree
cld_agree: required (integer)
클라우드 수집 동의 여부
사용	안함:	0,	사용:	1

cld_snd_type: required (integer - default: 1)
cld_snd_type

클라우드 전송 유형
파일:	0,	해시:	1

cnc_block_use
cnc_block_use: required (integer)
C&C 차단 설정 사용 여부
사용	안함:	0,	사용:	1

cnc_block_hour
cnc_block_hour: required (integer - default: 1 - minimum: 1 - maximum: 720)
C&C 차단 설정 차단 시간

hrst_detect_score
hrst_detect_score: required (integer - default: 300 - minimum: 25 - maximum: 1000)
휴리스틱 설정 탐지 점수

hrst_block_hour
hrst_block_hour: required (integer - default: 1 - minimum: 1 - maximum: 720)
휴리스틱 설정 차단 시간

apt_excpt_list_id
apt_excpt_list_id: required (integer)
APT 예외 프로파일 ID

Example:
Example

{
		"svr_type":	1,
		"svr_ip_type":	1,
		"apt_svr_ip":	"100.100.100.100",
		"cld_agree":	0,
		"cld_snd_type":	1,
		"apt_excpt_list_id":	1,
		"cnc_block_use":	1,
		"cnc_block_hour":	1,
		"hrst_detect_score":	300,
		"hrst_block_hour":	1
}

Response

HTTP status code 200

APT 공통 설정 수정 성공

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

svr_type
svr_type: required (integer - default: 1)
분석장비 타입
클라우드:	1,	MBAS:	2

svr_ip_type
svr_ip_type: required (integer)
MBAS IP 버전
IPv4:	1,	IPv6:	2

apt_svr_ip
apt_svr_ip: required (string)
분석 장비 IP 주소
svr_ip_type 가 1일 때 v4 IP
svr_ip_type 가 2일 때 v6 IP

cld_agree
cld_agree: required (integer)
클라우드 수집 동의 여부
사용	안함:	0,	사용:	1

cld_snd_type
cld_snd_type: required (integer - default: 1)
클라우드 전송 유형
파일:	0,	해시:	1

cnc_block_use
cnc_block_use: required (integer)
C&C 차단 설정 사용 여부
사용	안함:	0,	사용:	1

cnc_block_hour: required (integer - default: 1 - minimum: 1 - maximum: 720)
cnc_block_hour
C&C 차단 설정 차단 시간

hrst_detect_score
hrst_detect_score: required (integer - default: 300 - minimum: 25 - maximum: 1000)
휴리스틱 설정 탐지 점수

hrst_block_hour
hrst_block_hour: required (integer - default: 1 - minimum: 1 - maximum: 720)
휴리스틱 설정 차단 시간

apt_excpt_list
apt_excpt_list: required (object)
APT 예외 프로파일

idid: required (integer)
APT 예외 프로파일 ID

name
name: required (string)
APT 예외 프로파일 이름

mbas_key
mbas_key: required (string)
MBAS 키
GUI에서	사용하지	않음 GUI

gc_sleep_term
gc_sleep_term: required (integer)
GUI에서	사용하지	않음

report_sleep_term
report_sleep_term: required (integer)
GUI에서	사용하지	않음

white_cache_expire_tm: required (integer)
white_cache_expire_tm

GUI에서	사용하지	않음

black_cache_expire_tm
black_cache_expire_tm: required (integer)
GUI에서	사용하지	않음

hit_stat_term: required (integer)
hit_stat_term
GUI에서	사용하지	않음

hit_snd_cnt
hit_snd_cnt: required (integer)
GUI에서	사용하지	않음

ht_exp_time: required (integer)
ht_exp_time
GUI에서	사용하지	않음

cache_exp_time
cache_exp_time: required (integer)
GUI에서	사용하지	않음

conn_timeout_p
conn_timeout_p: required (integer)
GUI에서	사용하지	않음

recv_timeout_p
recv_timeout_p: required (integer)
GUI에서	사용하지	않음

Example:
Example

{
		"code":	"ok",
		"result":	{
				"svr_type"	:	1,
				"mbas_key":	"",
				"svr_ip_type":	1,
				"apt_svr_ip":	"100.100.100.100",
				"cld_agree":	0,
				"cld_snd_type":	1,
				"apt_excpt_list":	{
						"id":	1,
						"name":	"APT	예외	프로파일	이름"
				},
				"cnc_block_use":	1,
				"cnc_block_hour":	1,
				"hrst_detect_score":	300,
				"hrst_block_hour":	1
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

클라우드 기반 데이터 수집 동의서 보기

GET

/apt/cloud/collection/agreement

동의서 보기을(를) 조회한다.

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

동의서 보기 조회 성공

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

notice
notice: required (string)
데이터 수집 동의서

Example:
Example

{
		"code":	"ok",
		"result":	{
				"notice":	"가.수집	정보\n회사는	서비스	제공을	위해..."
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

APT 공통 설정 적용/취소

PUT

/command/apt-setting/apply

APT 공통 설정을 적용합니다.

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

Example:
Example

{}

Response

HTTP status code 200

APT 공통 설정 적용 성공

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

/command/apt-setting/cancel

APT 공통 설정을 취소합니다.

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

APT 공통 설정 취소 성공

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

