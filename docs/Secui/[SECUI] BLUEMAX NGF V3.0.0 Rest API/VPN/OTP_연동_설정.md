GET

GET

GET

POST

  DELETE

PUT

  DELETE

PUT

PUT

(3.0)OTP 연동 설정 REST API 문서

https://{url}/api/vp

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/vp

OTP 서버 종류

/sslvpn/otp/server/types

OTP 연동 설정

/sslvpn/otp/servers

/sslvpn/otp/servers/{pk}

OTP 연동 설정 적용/취소

/command/sslvpn-otp-servers/apply

/command/sslvpn-otp-servers/cancel

OTP 서버 종류

GET

/sslvpn/otp/server/types

OTP 서버 종류 목록을 조회한다.

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

OTP 서버 종류 목록 조회 성공

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
result: required (array of GetOtpServerType)
결과 데이터

Items: GetOtpServerType
Items

name
name: required (string)
OTP 서버 종류 이름

type
type: required (one of 1, 3, 4)
2차 인증 타입
1:	모바일	OTP,	3:	EMAIL	OTP,	4:	FIDO	OTP

sub_type
sub_type: required (integer)
OTP 서버 종류 코드값
ex)	11:	시큐아이	OTP

auth_url
auth_url: required (one of true, false)
인증 URL 활성 여부  true:	활성,	false:	비활성

site_id
site_id: required (one of true, false)
siteId 활성 여부  true:	활성,	false:	비활성

svc_id
svc_id: required (one of true, false)
svcId 활성 여부  true:	활성,	false:	비활성

api_key
api_key: required (one of true, false)
APIKey 활성 여부  true:	활성,	false:	비활성

api_password
api_password: required (one of true, false)
APIPassword 활성 여부  true:	활성,	false:	비활성

api_id
api_id: required (one of true, false)
API ID 활성 여부  true:	활성,	false:	비활성

Example:
Example

{
		"code":	"ok",
		"result":	[{
				{
						"name":	"시큐아이	OTP",
						"type":	1,
						"sub_type":	11
						"auth_url":	false,
						"site_id":	false,
						"svc_id":	false,
						"api_key":	false,
						"api_password":	false,
						"api_id":	false
				},
				{
						"name":	"라온시큐어	OTP",
						"type":	1,
						"sub_type":	12,
						"auth_url":	true,
						"site_id":	true,
						"svc_id":	true,
						"api_key":	false,
						"api_password":	false,
						"api_id":	false
				}
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

OTP 연동 설정

GET

/sslvpn/otp/servers

OTP 연동 서버 목록을 조회한다.

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

OTP 연동 서버 목록 조회 성공

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
result: required (array of GetOtpServer)
결과 데이터

Items: GetOtpServer
Items

name
name: required (string - minLength: 1 - maxLength: 48)
이름

type
type: required (integer)
2차 인증 타입
1:	모바일	OTP,	3:	EMAIL	OTP,	4:	FIDO	OTP

sub_type
sub_type: required (integer)
OTP 서버 종류 코드값
ex)	11:	시큐아이	OTP

auth_url
auth_url: (string - maxLength: 256)
인증 URL
영문, 숫자, 특수문자

site_id
site_id: (string - maxLength: 256)
siteId
영문, 숫자, 특수문자

svc_id: (string - maxLength: 256)
svc_id
svcId
영문, 숫자, 특수문자

api_key
api_key: (string - maxLength: 256)
APIKey
영문, 숫자, 특수문자

api_password
api_password: (string - maxLength: 256)
APIPassword(Base64 인코딩)
영문, 숫자, 특수문자

api_id
api_id: (string - maxLength: 256)
API ID
영문, 숫자, 특수문자

descdesc: (string - maxLength: 128)
설명

sslvpn_otp_conn_id
sslvpn_otp_conn_id: required (integer)
OTP 서버 ID(PK)

cfg_adm_id: required (integer)
cfg_adm_id
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
		"result":	[{
				"sslvpn_otp_conn_id":	1,
				"name":	"RAON_OTP",
				"type":	1,
				"sub_type":	12,
				"auth_url":	"https://raon.com/",
				"site_id":	"SIT000001234",
				"svc_id":	"SVC012349888",
				"api_key":	"",
				"api_id":	"",
				"desc":	"테스트",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2017-10-10	15:36:45"
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

/sslvpn/otp/servers

OTP 연동 서버를 추가한다.

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
name: required (string - minLength: 1 - maxLength: 48)
이름

type
type: required (integer)
2차 인증 타입
1:	모바일	OTP,	3:	EMAIL	OTP,	4:	FIDO	OTP

sub_type
sub_type: required (integer)
OTP 서버 종류 코드값
ex)	11:	시큐아이	OTP

auth_url: (string - maxLength: 256)
auth_url
인증 URL
영문, 숫자, 특수문자

site_id
site_id: (string - maxLength: 256)
siteId
영문, 숫자, 특수문자

svc_id
svc_id: (string - maxLength: 256)
svcId
영문, 숫자, 특수문자

api_key
api_key: (string - maxLength: 256)
APIKey
영문, 숫자, 특수문자

api_password
api_password: (string - maxLength: 256)
APIPassword(Base64 인코딩)
영문, 숫자, 특수문자

api_id: (string - maxLength: 256)
api_id
API ID
영문, 숫자, 특수문자

descdesc: (string - maxLength: 128)
설명

Example:
Example

{
		"name":	"RAON_OTP",
		"type":	1,
		"sub_type":	12,
		"auth_url":	"https://raon.com/",
		"site_id":	"SIT000001234",
		"svc_id":	"SVC012349888",
		"api_key":	"",
		"api_id":	"",
		"desc":	"테스트"
}

Response

HTTP status code 200

OTP 연동 서버 추가 성공

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
name: required (string - minLength: 1 - maxLength: 48)
이름

type
type: required (integer)
2차 인증 타입
1:	모바일	OTP,	3:	EMAIL	OTP,	4:	FIDO	OTP

sub_type
sub_type: required (integer)
OTP 서버 종류 코드값
ex)	11:	시큐아이	OTP

auth_url
auth_url: (string - maxLength: 256)
인증 URL
영문, 숫자, 특수문자

site_id
site_id: (string - maxLength: 256)
siteId
영문, 숫자, 특수문자

svc_id: (string - maxLength: 256)
svc_id
svcId
영문, 숫자, 특수문자

api_key
api_key: (string - maxLength: 256)
APIKey
영문, 숫자, 특수문자

api_password
api_password: (string - maxLength: 256)
APIPassword(Base64 인코딩)
영문, 숫자, 특수문자

api_id
api_id: (string - maxLength: 256)
API ID
영문, 숫자, 특수문자

descdesc: (string - maxLength: 128)
설명

sslvpn_otp_conn_id
sslvpn_otp_conn_id: required (integer)
OTP 서버 ID(PK)

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
				"sslvpn_otp_conn_id":	1,
				"name":	"RAON_OTP",
				"type":	1,
				"sub_type":	12,
				"auth_url":	"https://raon.com/",
				"site_id":	"SIT000001234",
				"svc_id":	"SVC012349888",
				"api_key":	"",
				"api_id":	"",
				"desc":	"테스트",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2017-10-10	15:36:45"
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

/sslvpn/otp/servers

OTP 연동 서버 목록을 (일괄)삭제한다.

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
삭제 아이템 목록

Example:
Example

{
		"items":	[
				{"sslvpn_otp_conn_id":	1},
				{"sslvpn_otp_conn_id":	2}
		]
}

Response

HTTP status code 200

OTP 연동 서버 목록 삭제 성공

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

errors
errors: required (array of object)
삭제 실패 시 에러 목록

Example:
Example

{
		"code":	"ok",
		"result":	{
				"errors":	[]
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

GET

/sslvpn/otp/servers/{pk}

OTP 연동 서버을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
OTP 연동 서버 ID ( sslvpn_otp_conn_id )

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

OTP 연동 서버 조회 성공

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

name: required (string - minLength: 1 - maxLength: 48)
name
이름

type
type: required (integer)
2차 인증 타입
1:	모바일	OTP,	3:	EMAIL	OTP,	4:	FIDO	OTP

sub_type: required (integer)
sub_type
OTP 서버 종류 코드값
ex)	11:	시큐아이	OTP

auth_url
auth_url: (string - maxLength: 256)
인증 URL
영문, 숫자, 특수문자

site_id
site_id: (string - maxLength: 256)
siteId
영문, 숫자, 특수문자

svc_id
svc_id: (string - maxLength: 256)
svcId
영문, 숫자, 특수문자

api_key
api_key: (string - maxLength: 256)
APIKey
영문, 숫자, 특수문자

api_password: (string - maxLength: 256)
api_password
APIPassword(Base64 인코딩)
영문, 숫자, 특수문자

api_id
api_id: (string - maxLength: 256)
API ID
영문, 숫자, 특수문자

descdesc: (string - maxLength: 128)
설명

sslvpn_otp_conn_id
sslvpn_otp_conn_id: required (integer)
OTP 서버 ID(PK)

cfg_adm_id: required (integer)
cfg_adm_id
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
				"sslvpn_otp_conn_id":	1,
				"name":	"RAON_OTP",
				"type":	1,
				"sub_type":	12,
				"auth_url":	"https://raon.com/",
				"site_id":	"SIT000001234",
				"svc_id":	"SVC012349888",
				"api_key":	"",
				"api_id":	"",
				"desc":	"테스트",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2017-10-10	15:36:45"
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

/sslvpn/otp/servers/{pk}

OTP 연동 서버을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
OTP 연동 서버 ID ( sslvpn_otp_conn_id )

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
name
name: required (string - minLength: 1 - maxLength: 48)
이름

type
type: required (integer)
2차 인증 타입
1:	모바일	OTP,	3:	EMAIL	OTP,	4:	FIDO	OTP

sub_type
sub_type: required (integer)
OTP 서버 종류 코드값
ex)	11:	시큐아이	OTP

auth_url
auth_url: (string - maxLength: 256)
인증 URL
영문, 숫자, 특수문자

site_id: (string - maxLength: 256)
site_id
siteId
영문, 숫자, 특수문자

svc_id
svc_id: (string - maxLength: 256)
svcId
영문, 숫자, 특수문자

api_key
api_key: (string - maxLength: 256)
APIKey
영문, 숫자, 특수문자

api_password
api_password: (string - maxLength: 256)
APIPassword(Base64 인코딩)
영문, 숫자, 특수문자

api_id
api_id: (string - maxLength: 256)
API ID
영문, 숫자, 특수문자

descdesc: (string - maxLength: 128)
설명

Example:
Example

{
		"name":	"RAON_OTP",
		"type":	1,
		"sub_type":	12,
		"auth_url":	"https://raon.com/",
		"site_id":	"SIT000001234",
		"svc_id":	"SVC012349888",
		"api_key":	"",
		"api_id":	"",
		"desc":	"테스트"
}

Response

HTTP status code 200

OTP 연동 서버 수정 성공

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
name: required (string - minLength: 1 - maxLength: 48)
이름

type
type: required (integer)
2차 인증 타입
1:	모바일	OTP,	3:	EMAIL	OTP,	4:	FIDO	OTP

sub_type
sub_type: required (integer)
OTP 서버 종류 코드값
ex)	11:	시큐아이	OTP

auth_url
auth_url: (string - maxLength: 256)
인증 URL
영문, 숫자, 특수문자

site_id
site_id: (string - maxLength: 256)
siteId
영문, 숫자, 특수문자

svc_id
svc_id: (string - maxLength: 256)
svcId
영문, 숫자, 특수문자

api_key: (string - maxLength: 256)
api_key
APIKey
영문, 숫자, 특수문자

api_password
api_password: (string - maxLength: 256)
APIPassword(Base64 인코딩)
영문, 숫자, 특수문자

api_id
api_id: (string - maxLength: 256)
API ID
영문, 숫자, 특수문자

descdesc: (string - maxLength: 128)
설명

sslvpn_otp_conn_id
sslvpn_otp_conn_id: required (integer)
OTP 서버 ID(PK)

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
				"sslvpn_otp_conn_id":	1,
				"name":	"RAON_OTP",
				"type":	1,
				"sub_type":	12,
				"auth_url":	"https://raon.com/",
				"site_id":	"SIT000001234",
				"svc_id":	"SVC012349888",
				"api_key":	"",
				"api_id":	"",
				"desc":	"테스트",
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2017-10-10	15:36:45"
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

/sslvpn/otp/servers/{pk}

OTP 연동 서버을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
OTP 연동 서버 ID ( sslvpn_otp_conn_id )

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

OTP 연동 서버 삭제 성공

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

OTP 연동 설정 적용/취소

PUT

/command/sslvpn-otp-servers/apply

OTP 연동 설정을 적용합니다.

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

OTP 연동 설정 적용 성공

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

/command/sslvpn-otp-servers/cancel

OTP 연동 설정을 취소합니다.

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

OTP 연동 설정 취소 성공

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

