GET

POST

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

DNS 보안 프로파일 REST API 문서

https://{host}/api/op

host
host: required (string)
[IP]:[GUI 접속 PORT]
443	포트는	생략	가능

Example:
Example

192.168.100.100:443

DNS 보안 프로파일

GUI에서 사용되는 API로 TAMS 프로파일과 NGF 프로파일 전체 목록을 리턴한다.

/dnssec/all/profiles

DNS 보안 프로파일

/dnssec/profiles

/dnssec/profiles/{pk}

DNS 보안 프로파일 적용/취소

/command/dnssec-profiles/apply

/command/dnssec-profiles/cancel

DNS 보안 프로파일

GET

/dnssec/all/profiles

DNS 보안 프로파일 목록을 조회한다.

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

DNS 보안 프로파일 목록 조회 성공

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
result: required (array of ResProfile)
결과 데이터

Items: ResProfile
Items

useuse: required (integer)
사용 여부
1:	사용,	2:	사용	안함

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
설명

white_domain_predef_use
white_domain_predef_use: required (integer)
신뢰 도메인 DB 사용 여부
1:	사용,	2:	사용	안함

white_domain_usrdef_use
white_domain_usrdef_use: required (integer)
사용자 정의 신뢰 도메인 사용 여부
1:	사용,	2:	사용	안함

black_domain_predef_use: required (integer)
black_domain_predef_use
차단 도메인 DB 사용 여부
1:	사용,	2:	사용	안함

black_domain_usrdef_use
black_domain_usrdef_use: required (integer)
사용자 정의 차단 도메인 사용 여부
1:	사용,	2:	사용	안함

black_domain_action
black_domain_action: required (integer)
사용자 정의 차단 도메인 대응 옵션
1:	탐지,	2:	차단

tunneling_scan_use
tunneling_scan_use: required (integer)
DNS 터널링 검사 사용 여부
1:	사용,	2:	사용	안함

tunneling_scan_action
tunneling_scan_action: required (integer)
DNS 터널링 검사 대응 옵션
1:	탐지,	2:	차단

dnssec_prf_id
dnssec_prf_id: required (integer)
DNS 보안 프로파일 ID

cfg_dt
cfg_dt: required (string)
최근 수정일

cfg_layer
cfg_layer: required (integer)
장비 구분
0:	NGF,	1:	TAMS

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"dnssec_prf_id":	1,
				"name":	"11",
				"desc":	"11",
				"use":	2,
				"white_domain_predef_use":	2,
				"white_domain_usrdef_use":	2,
				"black_domain_predef_use":	2,
				"black_domain_usrdef_use":	2,
				"black_domain_action":	1,
				"tunneling_scan_use":	1,
				"tunneling_scan_action":	1
				"cfg_dt":	"2021-04-21	09:31:40",
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

/dnssec/all/profiles

DNS 보안 프로파일를 추가한다.

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

useuse: required (integer)
사용 여부
1:	사용,	2:	사용	안함

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
설명

Example:
Example

{
		"use":	1,
		"name":	"New	DNS	보안	프로파일	이름",
		"desc":	"New	DNS	보안	프로파일	설명"
}

Response

HTTP status code 200

DNS 보안 프로파일 추가 성공

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

useuse: required (integer)
사용 여부
1:	사용,	2:	사용	안함

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
설명

white_domain_predef_use
white_domain_predef_use: required (integer)
신뢰 도메인 DB 사용 여부
1:	사용,	2:	사용	안함

white_domain_usrdef_use: required (integer)
white_domain_usrdef_use
사용자 정의 신뢰 도메인 사용 여부
1:	사용,	2:	사용	안함

black_domain_predef_use
black_domain_predef_use: required (integer)
차단 도메인 DB 사용 여부
1:	사용,	2:	사용	안함

black_domain_usrdef_use
black_domain_usrdef_use: required (integer)
사용자 정의 차단 도메인 사용 여부
1:	사용,	2:	사용	안함

black_domain_action
black_domain_action: required (integer)
사용자 정의 차단 도메인 대응 옵션
1:	탐지,	2:	차단

tunneling_scan_use
tunneling_scan_use: required (integer)
DNS 터널링 검사 사용 여부
1:	사용,	2:	사용	안함

tunneling_scan_action: required (integer)
tunneling_scan_action
DNS 터널링 검사 대응 옵션
1:	탐지,	2:	차단

dnssec_prf_id
dnssec_prf_id: required (integer)
DNS 보안 프로파일 ID

cfg_dt: required (string)
cfg_dt
최근 수정일

cfg_layer
cfg_layer: required (integer)
장비 구분
0:	NGF,	1:	TAMS

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dnssec_prf_id":	1,
				"name":	"New	DNS	보안	프로파일	이름",
				"desc":	"New	DNS	보안	프로파일	설명",
				"use":	1,
				"white_domain_predef_use":	1,
				"white_domain_usrdef_use":	1,
				"black_domain_predef_use":	1,
				"black_domain_usrdef_use":	1,
				"black_domain_action":	1,
				"tunneling_scan_use":	1,
				"tunneling_scan_action":	1
				"cfg_dt":	"2021-04-21	09:31:40",
				"cfg_layer":	0
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

PUT

/dnssec/all/profiles

DNS 보안 프로파일 목록을 (일괄)수정한다.

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
수정될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"dnssec_prf_id":	1,	"use":	0},
				{"dnssec_prf_id":	2,	"use":	0}
		]
}

Response

HTTP status code 200

DNS 보안 프로파일 목록 수정 성공

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

/dnssec/all/profiles

DNS 보안 프로파일 목록을 (일괄)삭제한다.

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
items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"dnssec_prf_id":	1},
				{"dnssec_prf_id":	2}
		]
}

Response

HTTP status code 200

DNS 보안 프로파일 목록 삭제 성공

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

DNS 보안 프로파일

GET

/dnssec/profiles

DNS 보안 프로파일 목록을 조회한다.

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

DNS 보안 프로파일 목록 조회 성공

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
result: required (array of ResProfile)
결과 데이터

Items: ResProfile
Items

useuse: required (integer)
사용 여부
1:	사용,	2:	사용	안함

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
설명

white_domain_predef_use
white_domain_predef_use: required (integer)
신뢰 도메인 DB 사용 여부
1:	사용,	2:	사용	안함

white_domain_usrdef_use
white_domain_usrdef_use: required (integer)
사용자 정의 신뢰 도메인 사용 여부
1:	사용,	2:	사용	안함

black_domain_predef_use
black_domain_predef_use: required (integer)
차단 도메인 DB 사용 여부
1:	사용,	2:	사용	안함

black_domain_usrdef_use: required (integer)
black_domain_usrdef_use
사용자 정의 차단 도메인 사용 여부
1:	사용,	2:	사용	안함

black_domain_action
black_domain_action: required (integer)
사용자 정의 차단 도메인 대응 옵션
1:	탐지,	2:	차단

tunneling_scan_use
tunneling_scan_use: required (integer)
DNS 터널링 검사 사용 여부
1:	사용,	2:	사용	안함

tunneling_scan_action
tunneling_scan_action: required (integer)
DNS 터널링 검사 대응 옵션
1:	탐지,	2:	차단

dnssec_prf_id
dnssec_prf_id: required (integer)
DNS 보안 프로파일 ID

cfg_dt
cfg_dt: required (string)
최근 수정일

cfg_layer: required (integer)
cfg_layer
장비 구분
0:	NGF,	1:	TAMS

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"dnssec_prf_id":	1,
				"name":	"11",
				"desc":	"11",
				"use":	2,
				"white_domain_predef_use":	2,
				"white_domain_usrdef_use":	2,
				"black_domain_predef_use":	2,
				"black_domain_usrdef_use":	2,
				"black_domain_action":	1,
				"tunneling_scan_use":	1,
				"tunneling_scan_action":	1
				"cfg_dt":	"2021-04-21	09:31:40",
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

/dnssec/profiles

DNS 보안 프로파일를 추가한다.

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

useuse: required (integer)
사용 여부
1:	사용,	2:	사용	안함

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
설명

Example:
Example

{
		"use":	1,
		"name":	"New	DNS	보안	프로파일	이름",
		"desc":	"New	DNS	보안	프로파일	설명"
}

Response

HTTP status code 200

DNS 보안 프로파일 추가 성공

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

useuse: required (integer)
사용 여부
1:	사용,	2:	사용	안함

name: required (string - minLength: 1 - maxLength: 32)
name
프로파일 이름

descdesc: (string - maxLength: 128)
설명

white_domain_predef_use
white_domain_predef_use: required (integer)
신뢰 도메인 DB 사용 여부
1:	사용,	2:	사용	안함

white_domain_usrdef_use
white_domain_usrdef_use: required (integer)
사용자 정의 신뢰 도메인 사용 여부
1:	사용,	2:	사용	안함

black_domain_predef_use: required (integer)
black_domain_predef_use

차단 도메인 DB 사용 여부
1:	사용,	2:	사용	안함

black_domain_usrdef_use
black_domain_usrdef_use: required (integer)
사용자 정의 차단 도메인 사용 여부
1:	사용,	2:	사용	안함

black_domain_action
black_domain_action: required (integer)
사용자 정의 차단 도메인 대응 옵션
1:	탐지,	2:	차단

tunneling_scan_use: required (integer)
tunneling_scan_use
DNS 터널링 검사 사용 여부
1:	사용,	2:	사용	안함

tunneling_scan_action
tunneling_scan_action: required (integer)
DNS 터널링 검사 대응 옵션
1:	탐지,	2:	차단

dnssec_prf_id
dnssec_prf_id: required (integer)
DNS 보안 프로파일 ID

cfg_dt
cfg_dt: required (string)
최근 수정일

cfg_layer: required (integer)
cfg_layer
장비 구분
0:	NGF,	1:	TAMS

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dnssec_prf_id":	1,
				"name":	"New	DNS	보안	프로파일	이름",
				"desc":	"New	DNS	보안	프로파일	설명",
				"use":	1,
				"white_domain_predef_use":	1,
				"white_domain_usrdef_use":	1,
				"black_domain_predef_use":	1,
				"black_domain_usrdef_use":	1,
				"black_domain_action":	1,
				"tunneling_scan_use":	1,
				"tunneling_scan_action":	1
				"cfg_dt":	"2021-04-21	09:31:40",
				"cfg_layer":	0
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

PUT

/dnssec/profiles

DNS 보안 프로파일 목록을 (일괄)수정한다.

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
				{"dnssec_prf_id":	1,	"use":	0},
				{"dnssec_prf_id":	2,	"use":	0}
		]
}

Response

HTTP status code 200

DNS 보안 프로파일 목록 수정 성공

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

/dnssec/profiles

DNS 보안 프로파일 목록을 (일괄)삭제한다.

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
				{"dnssec_prf_id":	1},
				{"dnssec_prf_id":	2}
		]
}

Response

HTTP status code 200

DNS 보안 프로파일 목록 삭제 성공

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

/dnssec/profiles/{pk}

DNS 보안 프로파일을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)

DNS 보안 프로파일 ID( dnssec_prf_id )

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

DNS 보안 프로파일 조회 성공

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

useuse: required (integer)
사용 여부
1:	사용,	2:	사용	안함

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
설명

white_domain_predef_use
white_domain_predef_use: required (integer)
신뢰 도메인 DB 사용 여부
1:	사용,	2:	사용	안함

white_domain_usrdef_use
white_domain_usrdef_use: required (integer)
사용자 정의 신뢰 도메인 사용 여부
1:	사용,	2:	사용	안함

black_domain_predef_use: required (integer)
black_domain_predef_use
차단 도메인 DB 사용 여부
1:	사용,	2:	사용	안함

black_domain_usrdef_use
black_domain_usrdef_use: required (integer)
사용자 정의 차단 도메인 사용 여부
1:	사용,	2:	사용	안함

black_domain_action
black_domain_action: required (integer)
사용자 정의 차단 도메인 대응 옵션
1:	탐지,	2:	차단

tunneling_scan_use
tunneling_scan_use: required (integer)
DNS 터널링 검사 사용 여부
1:	사용,	2:	사용	안함

tunneling_scan_action
tunneling_scan_action: required (integer)
DNS 터널링 검사 대응 옵션
1:	탐지,	2:	차단

dnssec_prf_id: required (integer)
dnssec_prf_id

DNS 보안 프로파일 ID

cfg_dt
cfg_dt: required (string)
최근 수정일

cfg_layer: required (integer)
cfg_layer
장비 구분
0:	NGF,	1:	TAMS

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dnssec_prf_id":	1,
				"name":	"보안	프로파일	이름",
				"desc":	"보안	프로파일	설명",
				"use":	1,
				"white_domain_predef_use":	1,
				"white_domain_usrdef_use":	1,
				"black_domain_predef_use":	1,
				"black_domain_usrdef_use":	1,
				"black_domain_action":	1,
				"tunneling_scan_use":	1,
				"tunneling_scan_action":	1
				"cfg_dt":	"2021-04-21	09:31:40",
				"cfg_layer":	0
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

/dnssec/profiles/{pk}

DNS 보안 프로파일을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
DNS 보안 프로파일 ID( dnssec_prf_id )

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

useuse: required (integer)
사용 여부
1:	사용,	2:	사용	안함

name: required (string - minLength: 1 - maxLength: 32)
name
프로파일 이름

descdesc: (string - maxLength: 128)
설명

white_domain_predef_use
white_domain_predef_use: required (integer)
신뢰 도메인 DB 사용 여부
1:	사용,	2:	사용	안함

white_domain_usrdef_use
white_domain_usrdef_use: required (integer)
사용자 정의 신뢰 도메인 사용 여부
1:	사용,	2:	사용	안함

black_domain_predef_use: required (integer)
black_domain_predef_use
차단 도메인 DB 사용 여부
1:	사용,	2:	사용	안함

black_domain_usrdef_use
black_domain_usrdef_use: required (integer)
사용자 정의 차단 도메인 사용 여부
1:	사용,	2:	사용	안함

black_domain_action
black_domain_action: required (integer)
사용자 정의 차단 도메인 대응 옵션
1:	탐지,	2:	차단

tunneling_scan_use
tunneling_scan_use: required (integer)
DNS 터널링 검사 사용 여부
1:	사용,	2:	사용	안함

tunneling_scan_action
tunneling_scan_action: required (integer)
DNS 터널링 검사 대응 옵션
1:	탐지,	2:	차단

Example:
Example

{
		"name":	"보안	프로파일	이름",
		"desc":	"보안	프로파일	설명",
		"use":	1,
		"white_domain_predef_use":	1,
		"white_domain_usrdef_use":	1,
		"black_domain_predef_use":	1,
		"black_domain_usrdef_use":	1,
		"black_domain_action":	1,
		"tunneling_scan_use":	1,
		"tunneling_scan_action":	1
}

Response

HTTP status code 200

DNS 보안 프로파일 수정 성공

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

useuse: required (integer)
사용 여부
1:	사용,	2:	사용	안함

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
설명

white_domain_predef_use
white_domain_predef_use: required (integer)
신뢰 도메인 DB 사용 여부
1:	사용,	2:	사용	안함

white_domain_usrdef_use: required (integer)
white_domain_usrdef_use
사용자 정의 신뢰 도메인 사용 여부
1:	사용,	2:	사용	안함

black_domain_predef_use
black_domain_predef_use: required (integer)
차단 도메인 DB 사용 여부
1:	사용,	2:	사용	안함

black_domain_usrdef_use
black_domain_usrdef_use: required (integer)
사용자 정의 차단 도메인 사용 여부
1:	사용,	2:	사용	안함

black_domain_action
black_domain_action: required (integer)
사용자 정의 차단 도메인 대응 옵션
1:	탐지,	2:	차단

tunneling_scan_use
tunneling_scan_use: required (integer)
DNS 터널링 검사 사용 여부
1:	사용,	2:	사용	안함

tunneling_scan_action
tunneling_scan_action: required (integer)
DNS 터널링 검사 대응 옵션
1:	탐지,	2:	차단

dnssec_prf_id
dnssec_prf_id: required (integer)
DNS 보안 프로파일 ID

cfg_dt: required (string)
cfg_dt
최근 수정일

cfg_layer
cfg_layer: required (integer)
장비 구분
0:	NGF,	1:	TAMS

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dnssec_prf_id":	1,
				"name":	"DNS	보안	프로파일	이름",
				"desc":	"DNS	보안	프로파일	설명",
				"use":	1,
				"white_domain_predef_use":	1,
				"white_domain_usrdef_use":	1,
				"black_domain_predef_use":	1,
				"black_domain_usrdef_use":	1,
				"black_domain_action":	1,
				"tunneling_scan_use":	1,
				"tunneling_scan_action":	1
				"cfg_dt":	"2021-04-21	09:31:40",
				"cfg_layer":	0
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

/dnssec/profiles/{pk}

DNS 보안 프로파일을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
DNS 보안 프로파일 ID( dnssec_prf_id )

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

DNS 보안 프로파일 삭제 성공

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

DNS 보안 프로파일 적용/취소

PUT

/command/dnssec-profiles/apply

DNS 보안 프로파일을 적용합니다.

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

DNS 보안 프로파일 적용 성공

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

/command/dnssec-profiles/cancel

DNS 보안 프로파일을 취소합니다.

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

DNS 보안 프로파일 취소 성공

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

