GET

GET

POST

  DELETE

PUT

  DELETE

PUT

PUT

APT 프로파일 REST API 문서

https://{url}/api/op

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/op

APT 프로파일

/apt/profiles

/apt/profiles/{pk}

APT 프로파일 적용/취소

/command/apt-profiles/apply

/command/apt-profiles/cancel

APT 프로파일

GET

/apt/profiles

APT 프로파일 목록을 조회한다.

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

APT 프로파일 목록 조회 성공

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
result: required (array of AptGetProfile)
결과 데이터

Items: AptGetProfile
Items

name: required (string - minLength: 1 - maxLength: 32)
name
프로파일 이름

descdesc: (string - maxLength: 128)
설명

apt_prf_id
apt_prf_id: required (integer)
프로파일 ID

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"apt_prf_id":	1,
				"name":	"프로파일	이름",
				"desc":	"프로파일	설명"
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

/apt/profiles

APT 프로파일를 추가한다.

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
name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

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

APT 프로파일 추가 성공

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
설명

http_cache
http_cache: required (one of 0, 1)
HTTP 프로토콜 기반 검사 캐시 여부
사용	안함:	0,	사용:	1

http_use
http_use: required (one of 0, 1)
HTTP 프로토콜 기반 검사 사용 여부
사용	안함:	0,	사용:	1

http_action
http_action: required (one of 0, 1)
HTTP 프로토콜 기반 검사 조치
사용	안함:	0,	사용:	1

http_file_size
http_file_size: required (integer - default: 1024 - minimum: 1 - maximum: 5120)
HTTP 프로토콜 기반 검사 첨부 파일 최대 크기

smtp_cache
smtp_cache: required (one of 0, 1)
SMTP 프로토콜 기반 검사 캐시 여부
사용	안함:	0,	사용:	1

smtp_use
smtp_use: required (one of 0, 1)
SMTP 프로토콜 기반 검사 사용 여부
사용	안함:	0,	사용:	1

smtp_action
smtp_action: required (one of 0, 1)
SMTP 프로토콜 기반 검사 조치
사용	안함:	0,	사용:	1

smtp_file_size: required (integer - default: 1024 - minimum: 1 - maximum: 5120)
smtp_file_size
SMTP 프로토콜 기반 검사 첨부 파일 최대 크기

pop3_cache
pop3_cache: required (one of 0, 1)
POP3 프로토콜 기반 검사 캐시 여부
사용	안함:	0,	사용:	1

pop3_use
pop3_use: required (one of 0, 1)
POP3 프로토콜 기반 검사 사용 여부
사용	안함:	0,	사용:	1

pop3_action
pop3_action: required (one of 0, 1)
POP3 프로토콜 기반 검사 조치
사용	안함:	0,	사용:	1

pop3_file_size
pop3_file_size: required (integer - default: 1024 - minimum: 1 - maximum: 5120)
POP3 프로토콜 기반 검사 첨부 파일 최대 크기

ftp_cache: required (one of 0, 1)
ftp_cache

FTP 프로토콜 기반 검사 캐시 여부
사용	안함:	0,	사용:	1

ftp_use
ftp_use: required (one of 0, 1)
FTP 프로토콜 기반 검사 사용 여부
사용	안함:	0,	사용:	1

ftp_action
ftp_action: required (one of 0, 1)
FTP 프로토콜 기반 검사 조치
사용	안함:	0,	사용:	1

ftp_file_size: required (integer - default: 1024 - minimum: 1 - maximum: 5120)
ftp_file_size
FTP 프로토콜 기반 검사 첨부 파일 최대 크기

imap_cache
imap_cache: required (one of 0, 1)
IMAP 프로토콜 기반 검사 캐시 여부
사용	안함:	0,	사용:	1

imap_use: required (one of 0, 1)
imap_use
IMAP 프로토콜 기반 검사 사용 여부
사용	안함:	0,	사용:	1

imap_action
imap_action: required (one of 0, 1)
IMAP 프로토콜 기반 검사 조치
사용	안함:	0,	사용:	1

imap_file_size
imap_file_size: required (integer - default: 1024 - minimum: 1 - maximum: 5120)
IMAP 프로토콜 기반 검사 첨부 파일 최대 크기

hrst_http_rsps_use
hrst_http_rsps_use: required (one of 0, 1)
휴리스틱 Suspicious HTTP 회신 사용 여부
사용	안함:	0,	사용:	1

hrst_http_rsps_score
hrst_http_rsps_score: required (integer - default: 50 - minimum: 0 - maximum: 100)
휴리스틱 Suspicious HTTP 회신의 점수

hrst_file_type_use
hrst_file_type_use: required (one of 0, 1)
휴리스틱 Suspicious 파일 유형 사용 여부
사용	안함:	0,	사용:	1

hrst_file_type_score
hrst_file_type_score: required (integer - default: 50 - minimum: 0 - maximum: 100)
휴리스틱 Suspicious 파일 유형의 점수

hrst_irc_prtc_over_http_use
hrst_irc_prtc_over_http_use: required (one of 0, 1)
휴리스틱 IRC 프로토콜 초과 HTTP 사용 여부
사용	안함:	0,	사용:	1

hrst_irc_prtc_over_http_score
hrst_irc_prtc_over_http_score: required (integer - default: 50 - minimum: 0 - maximum: 100)
휴리스틱 IRC 프로토콜 초과 HTTP의 점수

hrst_action
hrst_action: required (one of 0, 1)
휴리스틱 조치
탐지:	0,	차단:	1

apt_prf_id
apt_prf_id: required (integer)
프로파일 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"apt_prf_id":	2,
				"name":	"New	프로파일	이름",
				"desc":	"New	프로파일	설명",
				"http_cache":	1,
				"http_use":	0,
				"http_action":	0,
				"http_file_size":	1024,
				"smtp_cache":	1,
				"smtp_use":	0,
				"smtp_action":	0,
				"smtp_file_size":	1024,
				"pop3_cache":	1,
				"pop3_use":	0,
				"pop3_action":	0,
				"pop3_file_size":	1024,
				"ftp_cache":	1,
				"ftp_use":	0,
				"ftp_action":	0,
				"ftp_file_size":	1024,
				"imap_cache":	1,
				"imap_use":	0,
				"imap_action":	0,
				"imap_file_size":	1024,
				"hrst_file_type_use":	0,
				"hrst_file_type_score":	50,
				"hrst_http_rsps_use":	0,
				"hrst_http_rsps_score":	50,
				"hrst_irc_prtc_over_http_use":	0,
				"hrst_irc_prtc_over_http_score":	50,
				"hrst_action":	0
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

DELETE

/apt/profiles

APT 프로파일 목록을 (일괄)삭제한다.

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
				{"apt_prf_id":	1},
				{"apt_prf_id":	2}
		]
}

Response

HTTP status code 200

APT 프로파일 목록 삭제 성공

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

/apt/profiles/{pk}

APT 프로파일을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
프로파일 ID( apt_prf_id )

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

APT 프로파일 조회 성공

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
설명

http_cache
http_cache: required (one of 0, 1)
HTTP 프로토콜 기반 검사 캐시 여부
사용	안함:	0,	사용:	1

http_use
http_use: required (one of 0, 1)
HTTP 프로토콜 기반 검사 사용 여부
사용	안함:	0,	사용:	1

http_action
http_action: required (one of 0, 1)
HTTP 프로토콜 기반 검사 조치
사용	안함:	0,	사용:	1

http_file_size
http_file_size: required (integer - default: 1024 - minimum: 1 - maximum: 5120)
HTTP 프로토콜 기반 검사 첨부 파일 최대 크기

smtp_cache
smtp_cache: required (one of 0, 1)
SMTP 프로토콜 기반 검사 캐시 여부
사용	안함:	0,	사용:	1

smtp_use
smtp_use: required (one of 0, 1)
SMTP 프로토콜 기반 검사 사용 여부
사용	안함:	0,	사용:	1

smtp_action
smtp_action: required (one of 0, 1)
SMTP 프로토콜 기반 검사 조치
사용	안함:	0,	사용:	1

smtp_file_size
smtp_file_size: required (integer - default: 1024 - minimum: 1 - maximum: 5120)
SMTP 프로토콜 기반 검사 첨부 파일 최대 크기

pop3_cache: required (one of 0, 1)
pop3_cache
POP3 프로토콜 기반 검사 캐시 여부
사용	안함:	0,	사용:	1

pop3_use
pop3_use: required (one of 0, 1)
POP3 프로토콜 기반 검사 사용 여부
사용	안함:	0,	사용:	1

pop3_action
pop3_action: required (one of 0, 1)
POP3 프로토콜 기반 검사 조치
사용	안함:	0,	사용:	1

pop3_file_size: required (integer - default: 1024 - minimum: 1 - maximum: 5120)
pop3_file_size
POP3 프로토콜 기반 검사 첨부 파일 최대 크기

ftp_cache
ftp_cache: required (one of 0, 1)
FTP 프로토콜 기반 검사 캐시 여부
사용	안함:	0,	사용:	1

ftp_use: required (one of 0, 1)
ftp_use
FTP 프로토콜 기반 검사 사용 여부
사용	안함:	0,	사용:	1

ftp_action
ftp_action: required (one of 0, 1)
FTP 프로토콜 기반 검사 조치
사용	안함:	0,	사용:	1

ftp_file_size
ftp_file_size: required (integer - default: 1024 - minimum: 1 - maximum: 5120)
FTP 프로토콜 기반 검사 첨부 파일 최대 크기

imap_cache
imap_cache: required (one of 0, 1)
IMAP 프로토콜 기반 검사 캐시 여부
사용	안함:	0,	사용:	1

imap_use
imap_use: required (one of 0, 1)
IMAP 프로토콜 기반 검사 사용 여부
사용	안함:	0,	사용:	1

imap_action
imap_action: required (one of 0, 1)
IMAP 프로토콜 기반 검사 조치
사용	안함:	0,	사용:	1

imap_file_size
imap_file_size: required (integer - default: 1024 - minimum: 1 - maximum: 5120)
IMAP 프로토콜 기반 검사 첨부 파일 최대 크기

hrst_http_rsps_use
hrst_http_rsps_use: required (one of 0, 1)
휴리스틱 Suspicious HTTP 회신 사용 여부
사용	안함:	0,	사용:	1

hrst_http_rsps_score
hrst_http_rsps_score: required (integer - default: 50 - minimum: 0 - maximum: 100)
휴리스틱 Suspicious HTTP 회신의 점수

hrst_file_type_use
hrst_file_type_use: required (one of 0, 1)
휴리스틱 Suspicious 파일 유형 사용 여부
사용	안함:	0,	사용:	1

hrst_file_type_score
hrst_file_type_score: required (integer - default: 50 - minimum: 0 - maximum: 100)
휴리스틱 Suspicious 파일 유형의 점수

hrst_irc_prtc_over_http_use
hrst_irc_prtc_over_http_use: required (one of 0, 1)
휴리스틱 IRC 프로토콜 초과 HTTP 사용 여부
사용	안함:	0,	사용:	1

hrst_irc_prtc_over_http_score
hrst_irc_prtc_over_http_score: required (integer - default: 50 - minimum: 0 - maximum: 100)
휴리스틱 IRC 프로토콜 초과 HTTP의 점수

hrst_action
hrst_action: required (one of 0, 1)
휴리스틱 조치
탐지:	0,	차단:	1

apt_prf_id
apt_prf_id: required (integer)
프로파일 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"apt_prf_id":	1,
				"name":	"프로파일	이름",
				"desc":	"프로파일	설명",
				"http_cache":	1,
				"http_use":	1,
				"http_action":	1,
				"http_file_size":	1024,
				"smtp_cache":	1,
				"smtp_use":	1,
				"smtp_action":	1,
				"smtp_file_size":	1024,
				"pop3_cache":	1,
				"pop3_use":	1,
				"pop3_action":	1,
				"pop3_file_size":	1024,
				"ftp_cache":	1,
				"ftp_use":	1,
				"ftp_action":	1,
				"ftp_file_size":	1024,
				"imap_cache":	1,
				"imap_use":	1,
				"imap_action":	1,
				"imap_file_size":	1024,
				"hrst_http_rsps_use":	1,
				"hrst_http_rsps_score":	50,
				"hrst_file_type_use":	1,
				"hrst_file_type_score":	50,
				"hrst_irc_prtc_over_http_use":	1,
				"hrst_irc_prtc_over_http_score":	50,
				"hrst_action":	1
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

/apt/profiles/{pk}

APT 프로파일을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
프로파일 ID( apt_prf_id )

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
설명

http_cache
http_cache: required (one of 0, 1)
HTTP 프로토콜 기반 검사 캐시 여부
사용	안함:	0,	사용:	1

http_use
http_use: required (one of 0, 1)
HTTP 프로토콜 기반 검사 사용 여부
사용	안함:	0,	사용:	1

http_action
http_action: required (one of 0, 1)
HTTP 프로토콜 기반 검사 조치
사용	안함:	0,	사용:	1

http_file_size
http_file_size: required (integer - default: 1024 - minimum: 1 - maximum: 5120)
HTTP 프로토콜 기반 검사 첨부 파일 최대 크기

smtp_cache
smtp_cache: required (one of 0, 1)
SMTP 프로토콜 기반 검사 캐시 여부
사용	안함:	0,	사용:	1

smtp_use
smtp_use: required (one of 0, 1)
SMTP 프로토콜 기반 검사 사용 여부
사용	안함:	0,	사용:	1

smtp_action: required (one of 0, 1)
smtp_action
SMTP 프로토콜 기반 검사 조치
사용	안함:	0,	사용:	1

smtp_file_size
smtp_file_size: required (integer - default: 1024 - minimum: 1 - maximum: 5120)
SMTP 프로토콜 기반 검사 첨부 파일 최대 크기

pop3_cache: required (one of 0, 1)
pop3_cache
POP3 프로토콜 기반 검사 캐시 여부
사용	안함:	0,	사용:	1

pop3_use
pop3_use: required (one of 0, 1)
POP3 프로토콜 기반 검사 사용 여부
사용	안함:	0,	사용:	1

pop3_action
pop3_action: required (one of 0, 1)
POP3 프로토콜 기반 검사 조치
사용	안함:	0,	사용:	1

pop3_file_size
pop3_file_size: required (integer - default: 1024 - minimum: 1 - maximum: 5120)
POP3 프로토콜 기반 검사 첨부 파일 최대 크기

ftp_cache
ftp_cache: required (one of 0, 1)
FTP 프로토콜 기반 검사 캐시 여부
사용	안함:	0,	사용:	1

ftp_use
ftp_use: required (one of 0, 1)
FTP 프로토콜 기반 검사 사용 여부
사용	안함:	0,	사용:	1

ftp_action
ftp_action: required (one of 0, 1)
FTP 프로토콜 기반 검사 조치
사용	안함:	0,	사용:	1

ftp_file_size: required (integer - default: 1024 - minimum: 1 - maximum: 5120)
ftp_file_size
FTP 프로토콜 기반 검사 첨부 파일 최대 크기

imap_cache
imap_cache: required (one of 0, 1)
IMAP 프로토콜 기반 검사 캐시 여부
사용	안함:	0,	사용:	1

imap_use: required (one of 0, 1)
imap_use
IMAP 프로토콜 기반 검사 사용 여부
사용	안함:	0,	사용:	1

imap_action
imap_action: required (one of 0, 1)
IMAP 프로토콜 기반 검사 조치
사용	안함:	0,	사용:	1

imap_file_size
imap_file_size: required (integer - default: 1024 - minimum: 1 - maximum: 5120)
IMAP 프로토콜 기반 검사 첨부 파일 최대 크기

hrst_http_rsps_use
hrst_http_rsps_use: required (one of 0, 1)
휴리스틱 Suspicious HTTP 회신 사용 여부
사용	안함:	0,	사용:	1

hrst_http_rsps_score
hrst_http_rsps_score: required (integer - default: 50 - minimum: 0 - maximum: 100)
휴리스틱 Suspicious HTTP 회신의 점수

hrst_file_type_use
hrst_file_type_use: required (one of 0, 1)
휴리스틱 Suspicious 파일 유형 사용 여부
사용	안함:	0,	사용:	1

hrst_file_type_score
hrst_file_type_score: required (integer - default: 50 - minimum: 0 - maximum: 100)
휴리스틱 Suspicious 파일 유형의 점수

hrst_irc_prtc_over_http_use
hrst_irc_prtc_over_http_use: required (one of 0, 1)
휴리스틱 IRC 프로토콜 초과 HTTP 사용 여부
사용	안함:	0,	사용:	1

hrst_irc_prtc_over_http_score
hrst_irc_prtc_over_http_score: required (integer - default: 50 - minimum: 0 - maximum: 100)
휴리스틱 IRC 프로토콜 초과 HTTP의 점수

hrst_action
hrst_action: required (one of 0, 1)
휴리스틱 조치
탐지:	0,	차단:	1

Example:
Example

{
		"name":	"프로파일	이름",
		"desc":	"프로파일	설명",
		"http_cache":	1,
		"http_use":	1,
		"http_action":	1,
		"http_file_size":	1024,
		"smtp_cache":	1,
		"smtp_use":	1,
		"smtp_action":	1,
		"smtp_file_size":	1024,
		"pop3_cache":	1,
		"pop3_use":	1,
		"pop3_action":	1,
		"pop3_file_size":	1024,
		"ftp_cache":	1,
		"ftp_use":	1,
		"ftp_action":	1,
		"ftp_file_size":	1024,
		"imap_cache":	1,
		"imap_use":	1,
		"imap_action":	1,
		"imap_file_size":	1024,
		"hrst_http_rsps_use":	1,
		"hrst_http_rsps_score":	50,
		"hrst_file_type_use":	1,
		"hrst_file_type_score":	50,
		"hrst_irc_prtc_over_http_use":	1,
		"hrst_irc_prtc_over_http_score":	50,
		"hrst_action":	1
}

Response

HTTP status code 200

APT 프로파일 수정 성공

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
설명

apt_prf_id
apt_prf_id: required (integer)
프로파일 ID

Example:
Example

{
		"code":	"ok",
		"result":	{
				"apt_prf_id":	1,
				"name":	"프로파일	이름",
				"desc":	"프로파일	설명",
				"http_cache":	1,
				"http_use":	1,
				"http_action":	1,
				"http_file_size":	1024,
				"smtp_cache":	1,
				"smtp_use":	1,
				"smtp_action":	1,
				"smtp_file_size":	1024,
				"pop3_cache":	1,
				"pop3_use":	1,
				"pop3_action":	1,
				"pop3_file_size":	1024,
				"ftp_cache":	1,
				"ftp_use":	1,
				"ftp_action":	1,
				"ftp_file_size":	1024,
				"imap_cache":	1,
				"imap_use":	1,
				"imap_action":	1,
				"imap_file_size":	1024,
				"hrst_http_rsps_use":	1,
				"hrst_http_rsps_score":	50,
				"hrst_file_type_use":	1,
				"hrst_file_type_score":	50,
				"hrst_irc_prtc_over_http_use":	1,
				"hrst_irc_prtc_over_http_score":	50,
				"hrst_action":	1
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

/apt/profiles/{pk}

APT 프로파일을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
프로파일 ID( apt_prf_id )

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

APT 프로파일 삭제 성공

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

APT 프로파일 적용/취소

PUT

/command/apt-profiles/apply

APT 프로파일을 적용합니다.

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

APT 프로파일 적용 성공

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

/command/apt-profiles/cancel

APT 프로파일을 취소합니다.

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

APT 프로파일 취소 성공

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

