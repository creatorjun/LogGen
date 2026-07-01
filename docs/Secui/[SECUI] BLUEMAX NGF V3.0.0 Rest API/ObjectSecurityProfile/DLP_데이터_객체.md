GET

GET

PUT

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

PUT

DLP 데이터 객체 REST API 문서

https://{url}/api/op

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/op

데이터 객체 전체 목록 조회

/dlp/data/objects

기본 데이터 객체

/dlp/data/predefined/objects

사용자 정의 데이터 객체

/dlp/data/userdefined/objects

/dlp/data/userdefined/objects/{pk}

/dlp/data/userdefined/objects/save?columns=(사용,데이터 객체 이름,데이터 유형,데이터값,설명)

/dlp/data/userdefined/objects/batch

DLP 데이터 객체 적용/취소

/command/dlp-data/apply

/command/dlp-data/cancel

데이터 객체 전체 목록 조회

GET

/dlp/data/objects

데이터 객체 전체(기본정의/사용자정의) 목록을 조회한다.

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

데이터 객체 전체(기본정의/사용자정의) 목록 조회 성공

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
result: required (array of GetPredefinedDataObject)
결과 데이터

Items: GetPredefinedDataObject
Items

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

name
name: required (string)
데이터 객체 이름

descdesc: required (string)
설명

value_type
value_type: required (one of 1, 2, 3, 4)
객체 유형
문자열:	1,	정규식:	2,	크기:	3,	파일유형:	4

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def
pre_def: required (integer)
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"dlp_data_obj_id":	10001,
				"type":	0,
				"use":	1,
				"name":	"기본	데이터	객체	이름",
				"desc":	"기본	데이터	객체	설명",
				"pre_def":	2,
				"value_type":	2
		},
		{
				"dlp_data_obj_id":	10100,
				"type":	0,
				"use":	1,
				"name":	"사용자	정의	데이터	객체	이름",
				"desc":	"사용자	정의	데이터	객체	설명",
				"pre_def":	1,
				"value_type":	1
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

기본 데이터 객체

GET

/dlp/data/predefined/objects

기본 데이터 객체 목록을 조회한다.

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

기본 데이터 객체 목록 조회 성공

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
result: required (array of GetPredefinedDataObject)
결과 데이터

Items: GetPredefinedDataObject
Items

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

name
name: required (string)
데이터 객체 이름

descdesc: required (string)
설명

value_type
value_type: required (one of 1, 2, 3, 4)
객체 유형
문자열:	1,	정규식:	2,	크기:	3,	파일유형:	4

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def
pre_def: required (integer)
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"dlp_data_obj_id":	10001,
				"type":	0,
				"use":	1,
				"name":	"기본	데이터	객체	이름",
				"desc":	"기본	데이터	객체	설명",
				"pre_def":	2,
				"value_type":	1
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

PUT

/dlp/data/predefined/objects

기본 데이터 객체 목록을 (일괄)수정한다.

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
items: required (array of object)
items
수정될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"dlp_data_obj_id":	10001,	"use":	0},
				{"dlp_data_obj_id":	10002,	"use":	0}
		]
}

Response

HTTP status code 200

기본 데이터 객체 목록 수정 성공

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

사용자 정의 데이터 객체

GET

/dlp/data/userdefined/objects

사용자 정의 데이터 객체 목록을 조회한다.

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

사용자 정의 데이터 객체 목록 조회 성공

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
result: required (array of GetUserdefinedDataObject)
결과 데이터

Items: GetUserdefinedDataObject
Items

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 32)
데이터 객체 이름

descdesc: (string - maxLength: 128)
설명

value_type
value_type: required (one of 1, 2, 3, 4)
데이터 유형
문자열:	1,	정규식:	2,	크기:	3,	파일유형:	4

value1
value1: required (string)
데이터 값

데이터 유형 속성이  문자열(1),	정규식(2) 일 때 값
Base64 인코딩/디코딩 필요

value2
value2: required (string)
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def
pre_def: required (integer)
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"dlp_data_obj_id":	10001,
				"type":	0,
				"use":	1,
				"name":	"사용자	정의	데이터	객체	이름",
				"desc":	"사용자	정의	데이터	객체	설명",
				"value_type":	1,
				"value1":	"ICAgIGFzYWFhYQ==",
				"value2":	"",
				"pre_def":	1
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

/dlp/data/userdefined/objects

사용자 정의 데이터 객체를 추가한다.

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

name
name: required (string - minLength: 1 - maxLength: 32)
데이터 객체 이름

descdesc: (string - maxLength: 128)
설명

value_type: required (one of 1, 2, 3, 4)
value_type
데이터 유형
문자열:	1,	정규식:	2,	크기:	3,	파일유형:	4

value1
value1: required (string)
데이터 값

데이터 유형 속성이  문자열(1),	정규식(2) 일 때 값
Base64 인코딩/디코딩 필요

value2
value2: required (string)
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

Example:
Example

{
		"use":	1,
		"name":	"New	사용자	정의	데이터	객체	이름",
		"desc":	"New	사용자	정의	데이터	객체	설명",
		"value_type":	1,
		"value1":	"ICAgIGFzYWFhYQ==",
		"value2":	""
}

Response

HTTP status code 200

사용자 정의 데이터 객체 추가 성공

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

name
name: required (string - minLength: 1 - maxLength: 32)
데이터 객체 이름

descdesc: (string - maxLength: 128)
설명

value_type
value_type: required (one of 1, 2, 3, 4)
데이터 유형
문자열:	1,	정규식:	2,	크기:	3,	파일유형:	4

value1: required (string)
value1

데이터 값

데이터 유형 속성이  문자열(1),	정규식(2) 일 때 값
Base64 인코딩/디코딩 필요

value2
value2: required (string)
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

dlp_data_obj_id: required (integer)
dlp_data_obj_id
DLP 데이터 객체 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def: required (integer)
pre_def
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_data_obj_id":	10002,
				"type":	0,
				"use":	1,
				"name":	"New	사용자	정의	데이터	객체	이름",
				"desc":	"New	사용자	정의	데이터	객체	설명",
				"value_type":	1,
				"value1":	"ICAgIGFzYWFhYQ==",
				"value2":	"",
				"pre_def":	1
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

/dlp/data/userdefined/objects

사용자 정의 데이터 객체 목록을 (일괄)수정한다.

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
items
items: required (array of object)
수정될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"dlp_data_obj_id":	10001,	"use":	0},
				{"dlp_data_obj_id":	10002,	"use":	0}
		]
}

Response

HTTP status code 200

사용자 정의 데이터 객체 목록 수정 성공

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

DELETE

/dlp/data/userdefined/objects

사용자 정의 데이터 객체 목록을 (일괄)삭제한다.

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
				{"dlp_data_obj_id":	10001},
				{"dlp_data_obj_id":	10002}
		]
}

Response

HTTP status code 200

사용자 정의 데이터 객체 목록 삭제 성공

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

/dlp/data/userdefined/objects/{pk}

DLP 데이터 객체을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
DLP 데이터 객체 ID( dlp_data_obj_id )

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

DLP 데이터 객체 조회 성공

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

name
name: required (string - minLength: 1 - maxLength: 32)
데이터 객체 이름

descdesc: (string - maxLength: 128)
설명

value_type
value_type: required (one of 1, 2, 3, 4)
데이터 유형
문자열:	1,	정규식:	2,	크기:	3,	파일유형:	4

value1
value1: required (string)
데이터 값

데이터 유형 속성이  문자열(1),	정규식(2) 일 때 값
Base64 인코딩/디코딩 필요

value2
value2: required (string)
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

dlp_data_obj_id: required (integer)
dlp_data_obj_id
DLP 데이터 객체 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def: required (integer)
pre_def
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_data_obj_id":	10001,
				"type":	0,
				"use":	1,
				"name":	"사용자	정의	데이터	객체	이름",
				"desc":	"사용자	정의	데이터	객체	설명",
				"value_type":	1,
				"value1":	"ICAgIGFzYWFhYQ==",
				"value2":	"",
				"pre_def":	1
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

/dlp/data/userdefined/objects/{pk}

DLP 데이터 객체을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
DLP 데이터 객체 ID( dlp_data_obj_id )

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

useuse: required (one of 0, 1)
사용 여부
사용	안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 32)
데이터 객체 이름

descdesc: (string - maxLength: 128)
설명

value_type
value_type: required (one of 1, 2, 3, 4)
데이터 유형
문자열:	1,	정규식:	2,	크기:	3,	파일유형:	4

value1
value1: required (string)
데이터 값

데이터 유형 속성이  문자열(1),	정규식(2) 일 때 값
Base64 인코딩/디코딩 필요

value2
value2: required (string)
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

Example:
Example

{
		"use":	1,
		"name":	"사용자	정의	데이터	객체	이름",
		"desc":	"사용자	정의	데이터	객체	설명",
		"value_type":	3,
		"value1":	"",
		"value2":	"12345"
}

Response

HTTP status code 200

DLP 데이터 객체 수정 성공

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

name
name: required (string - minLength: 1 - maxLength: 32)
데이터 객체 이름

descdesc: (string - maxLength: 128)
설명

value_type
value_type: required (one of 1, 2, 3, 4)
데이터 유형
문자열:	1,	정규식:	2,	크기:	3,	파일유형:	4

value1: required (string)
value1
데이터 값

데이터 유형 속성이  문자열(1),	정규식(2) 일 때 값
Base64 인코딩/디코딩 필요

value2: required (string)
value2
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def
pre_def: required (integer)
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_data_obj_id":	10001,
				"type":	0,
				"use":	1,
				"name":	"사용자	정의	데이터	객체	이름",
				"desc":	"사용자	정의	데이터	객체	설명",
				"value_type":	3,
				"value1":	"",
				"value2":	"12345",
				"pre_def":	1
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

/dlp/data/userdefined/objects/{pk}

DLP 데이터 객체을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
DLP 데이터 객체 ID( dlp_data_obj_id )

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

DLP 데이터 객체 삭제 성공

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

/dlp/data/userdefined/objects/save?columns=(사용,데이터 객체 이름,데이터 유형,데이터값,설명)

사용자 정의 데이터 객체을 PC로 저장합니다.

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

columns
columns: (string)
다운로드되는 엑셀 파일 내 테이블 헤더 값으로 사용될 값을 전달한다.(데이터 테이블에 표시되는 컬럼 순으로 지정)
columns 쿼리스트링에 값이 없을 경우 백엔드에 정의된 속성명으로 표시됩니다.
한글이	포함될	수	있기	때문에	UTF-8	인코딩되어야	합니다.

Example:
Example

?columns=(A,B,C)

Response

HTTP status code 200

사용자 정의 데이터 객체를 PC로 저장 성공

Body

Media type: application/vnd.openxmlformats-officedocument.spreadsheetml.sheet
Media type

TypeType: file

[Task 진행 상태 조회]
배치를 실행 후 응답된 태스크 ID로 상태를 체크합니다.
상태:  PENDING,	PROGRESS,	FAILURE,	REVOKED,	SUCCESS

PENDING: 준비 중
PROGRESS: 처리 중
FAILURE: 실패
REVOKED: 중지 성공
SUCCESS: 성공

GET	{{url}}/api/co/async/tasks/{{task_id}}
{ "code": "ok", "result": { "id": "c295d300-9b7f-4c10-9468-6538c0abab66", "status": "SUCCESS", "attributes": { } } }

POST

/dlp/data/userdefined/objects/batch

사용자 정의 데이터 객체을 배치 작업을 시작합니다.

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

Properties
Properties

filefile: required (string)
파일 업로드 후 응답 데이터의 파일명을 인자로 전달

[파일 업로드 API]
POST	{{url}}/api/co/file/import

Example:
Example

{
		"file":	"batch_file.xlsx"
}

Response

HTTP status code 202

사용자 정의 데이터 객체 배치 실행

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

idid: required (string)
비동기 태스크 ID

Example:
Example

f810f701-e732-4698-a5a9-a93000a828d9

status
status: required (string)
상태( PENDING,	PROGRESS,	FAILURE,	REVOKED,	SUCCESS )

PENDING: 준비 중
PROGRESS: 처리 중
FAILURE: 실패
REVOKED: 중지 성공
SUCCESS: 성공

attributes: required (object)
attributes
부가 정보

Example:
Example

{
		"code":	"async",
		"result":	{
				"id":	"f810f701-e732-4698-a5a9-a93000a828d9",
				"status":	"PENDING",
				"attributes":	{}
		}
}

HTTP status code 400

사용자 정의 데이터 객체 배치 실행 실패

DLP 데이터 객체 적용/취소

PUT

/command/dlp-data/apply

DLP 데이터 객체을 적용합니다.

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

DLP 데이터 객체 적용 성공

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

/command/dlp-data/cancel

DLP 데이터 객체을 취소합니다.

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

DLP 데이터 객체 취소 성공

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

