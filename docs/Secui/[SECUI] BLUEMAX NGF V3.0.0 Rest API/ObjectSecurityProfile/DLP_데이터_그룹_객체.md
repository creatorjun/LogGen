GET

GET

PUT

GET

GET

POST

PUT

  DELETE

GET

PUT

  DELETE

PUT

PUT

DLP 데이터 그룹 객체 REST API 문서

https://{url}/api/op

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/op

데이터 그룹 객체 전체 목록 조회

/dlp/data-group/objects

기본 데이터 그룹 객체

/dlp/data-group/predefined/objects

/dlp/data-group/predefined/objects/{pk}

사용자 정의 데이터 그룹 객체

/dlp/data-group/userdefined/objects

/dlp/data-group/userdefined/objects/{pk}

DLP 데이터 그룹 객체 적용/취소

/command/dlp-group/apply

/command/dlp-group/cancel

데이터 그룹 객체 전체 목록 조회

GET

/dlp/data-group/objects

데이터 그룹 객체 전체(기본정의/사용자정의) 목록을 조회한다.

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

데이터 그룹 객체 전체(기본정의/사용자정의) 목록 조회 성공

Body

Media type: application/json
Media type

TypeType: object

Properties
Properties
code
code: required (string)
결과 코드

result: required (array of GetDataGroupObject)
result
결과 데이터

Items: GetDataGroupObject
Items

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

name
name: required (string)
데이터 객체 이름

descdesc: required (string)
설명

dlp_data_obj_id: required (integer)
dlp_data_obj_id
DLP 데이터 그룹 객체 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def: required (integer)
pre_def
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

grp_type
grp_type: required (integer)
유형
문자열/정규표현식:	1,	파일유형:	2

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"dlp_data_obj_id":	30001,
				"type":	1,
				"use":	1,
				"name":	"기본	데이터	그룹	객체	이름",
				"desc":	"기본	데이터	그룹	객체	설명",
				"pre_def":	2,
				"grp_type":	1
		},
		{
				"dlp_data_obj_id":	30005,
				"type":	1,
				"name":	"사용자	정의	데이터	그룹	객체	이름",
				"desc":	"사용자	정의	데이터	그룹	객체	설명",
				"use":	1,
				"pre_def":	1,
				"grp_type":	1
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

기본 데이터 그룹 객체

GET

/dlp/data-group/predefined/objects

기본 데이터 그룹 객체 목록을 조회한다.

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

기본 데이터 그룹 객체 목록 조회 성공

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
result: required (array of GetDataGroupObject)
결과 데이터

Items: GetDataGroupObject
Items

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

name
name: required (string)
데이터 객체 이름

descdesc: required (string)
설명

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 그룹 객체 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def
pre_def: required (integer)
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

grp_type
grp_type: required (integer)
유형
문자열/정규표현식:	1,	파일유형:	2

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"dlp_data_obj_id":	30001,
				"type":	1,
				"use":	1,
				"name":	"기본	데이터	그룹	객체	이름",
				"desc":	"기본	데이터	그룹	객체	설명",
				"pre_def":	2,
				"grp_type":	1
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

/dlp/data-group/predefined/objects

기본 데이터 그룹 객체 목록을 (일괄)수정한다.

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
				{"dlp_data_obj_id":	30001,	"use":	0},
				{"dlp_data_obj_id":	30002,	"use":	0}
		]
}

Response

HTTP status code 200

기본 데이터 그룹 객체 목록 수정 성공

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

GET

/dlp/data-group/predefined/objects/{pk}

DLP 데이터 그룹 객체을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
DLP 데이터 그룹 객체 ID( dlp_data_obj_id )

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

DLP 데이터 그룹 객체 조회 성공

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
사용	안함:	0,	사용:	1

name
name: required (string)
데이터 객체 이름

descdesc: required (string)
설명

dlp_data_obj_id: required (integer)
dlp_data_obj_id

DLP 데이터 그룹 객체 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def
pre_def: required (integer)
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

grp_type
grp_type: required (integer)
유형
문자열/정규표현식:	1,	파일유형:	2

mmbr_dlp_data_obj_list
mmbr_dlp_data_obj_list: required (array of DataObject)
데이터 객체 또는 그룹 객체 ID 목록

Items: DataObject
Items

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체 또는 그룹 객체 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def
pre_def: required (integer)
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

name
name: required (string)
데이터 객체 이름

descdesc: required (string)
설명

value_type: required (one of 1, 2, 3, 4)
value_type
객체 유형
문자열:	1,	정규식:	2,	크기:	3,	파일유형:	4

value1
value1: required (string)
객체 유형이  문자열 ,  정규식 일 때 값
Base64 인코딩/디코딩 필요

value2: required (string)
value2
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_data_obj_id":	1,
				"type":	1,
				"use":	1,
				"name":	"기본	정의	데이터	객체	이름",
				"desc":	"기본	정의	데이터	객체	설명",
				"pre_def":	2,
				"mmbr_dlp_data_obj_list":	[
						{
								"dlp_data_obj_id":	10001,
								"type":	0,
								"name":	"데이터	객체	이름",
								"desc":	"데이터	객체	설명",
								"use":	1,
								"pre_def":	1,
								"value_type":	1,
								"value1":	"ICAgIGFzYWFhYQ==",
								"value2":	""
						}
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

사용자 정의 데이터 그룹 객체

GET

/dlp/data-group/userdefined/objects

사용자 정의 데이터 그룹 객체 목록을 조회한다.

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

사용자 정의 데이터 그룹 객체 목록 조회 성공

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
result: required (array of GetDataGroupObject)
결과 데이터

Items: GetDataGroupObject
Items

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

name
name: required (string)
데이터 객체 이름

descdesc: required (string)
설명

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 그룹 객체 ID

type: required (integer)
type
객체 타입
객체:	0,	그룹:	1

pre_def
pre_def: required (integer)
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

grp_type: required (integer)
grp_type
유형
문자열/정규표현식:	1,	파일유형:	2

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"dlp_data_obj_id":	1,
				"type":	1,
				"use":	1,
				"name":	"사용자	정의	데이터	그룹	객체	이름",
				"desc":	"사용자	정의	데이터	그룹	객체	설명",
				"pre_def":	1,
				"grp_type":	1
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

/dlp/data-group/userdefined/objects

사용자 정의 데이터 그룹 객체를 추가한다.

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
사용	안함:	0,	사용:	1

name
name: required (string)
데이터 객체 이름

descdesc: required (string)
설명

mmbr_dlp_data_obj_id
mmbr_dlp_data_obj_id: required (array of integer)
데이터 객체 또는 그룹 객체 ID 목록

Example:
Example

{
		"use":	1,
		"name":	"New	사용자	정의	데이터	그룹	객체	이름",
		"desc":	"New	사용자	정의	데이터	그룹	객체	설명",
		"grp_tpe":	1,
		"mmbr_dlp_data_obj_id":	[10001,	10002]
}

Response

HTTP status code 200

사용자 정의 데이터 그룹 객체 추가 성공

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
사용	안함:	0,	사용:	1

name
name: required (string)
데이터 객체 이름

descdesc: required (string)
설명

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 그룹 객체 ID

type: required (integer)
type

객체 타입
객체:	0,	그룹:	1

pre_def
pre_def: required (integer)
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

grp_type
grp_type: required (integer)
유형
문자열/정규표현식:	1,	파일유형:	2

mmbr_dlp_data_obj_list: required (array of DataObject)
mmbr_dlp_data_obj_list
데이터 객체 또는 그룹 객체 ID 목록

Items: DataObject
Items

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체 또는 그룹 객체 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def
pre_def: required (integer)
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

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

value1
value1: required (string)
객체 유형이  문자열 ,  정규식 일 때 값
Base64 인코딩/디코딩 필요

value2
value2: required (string)
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_data_obj_id":	30002,
				"type":	1,
				"use":	1,
				"name":	"New	사용자	정의	데이터	그룹	객체	이름",
				"desc":	"New	사용자	정의	데이터	그룹	객체	설명",
				"pre_def":	1,
				"grp_tpe":	1,
				"mmbr_dlp_data_obj_list":	[
						{
								"dlp_data_obj_id":	10001,
								"type":	0,
								"name":	"데이터	객체	이름",
								"desc":	"데이터	객체	설명",
								"use":	1,
								"pre_def":	1,
								"value_type":	1,
								"value1":	"ICAgIGFzYWFhYQ==",
								"value2":	""
						}
				]
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

/dlp/data-group/userdefined/objects

사용자 정의 데이터 그룹 객체 목록을 (일괄)수정한다.

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
				{"dlp_data_obj_id":	1,	"use":	0},
				{"dlp_data_obj_id":	2,	"use":	0}
		]
}

Response

HTTP status code 200

사용자 정의 데이터 그룹 객체 목록 수정 성공

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

/dlp/data-group/userdefined/objects

사용자 정의 데이터 그룹 객체 목록을 (일괄)삭제한다.

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
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"dlp_data_obj_id":	1},
				{"dlp_data_obj_id":	2}
		]
}

Response

HTTP status code 200

사용자 정의 데이터 그룹 객체 목록 삭제 성공

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

GET

/dlp/data-group/userdefined/objects/{pk}

사용자 정의 데이터 그룹 객체을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
DLP 데이터 그룹 객체 ID( dlp_data_obj_id )

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

사용자 정의 데이터 그룹 객체 조회 성공

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
사용	안함:	0,	사용:	1

name
name: required (string)
데이터 객체 이름

descdesc: required (string)
설명

dlp_data_obj_id: required (integer)
dlp_data_obj_id

DLP 데이터 그룹 객체 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def
pre_def: required (integer)
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

grp_type
grp_type: required (integer)
유형
문자열/정규표현식:	1,	파일유형:	2

mmbr_dlp_data_obj_list
mmbr_dlp_data_obj_list: required (array of DataObject)
데이터 객체 또는 그룹 객체 ID 목록

Items: DataObject
Items

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체 또는 그룹 객체 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def
pre_def: required (integer)
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

name
name: required (string)
데이터 객체 이름

descdesc: required (string)
설명

value_type: required (one of 1, 2, 3, 4)
value_type
객체 유형
문자열:	1,	정규식:	2,	크기:	3,	파일유형:	4

value1
value1: required (string)
객체 유형이  문자열 ,  정규식 일 때 값
Base64 인코딩/디코딩 필요

value2: required (string)
value2
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_data_obj_id":	1,
				"type":	1,
				"use":	1,
				"name":	"기본	데이터	그룹	객체	이름",
				"desc":	"기본	데이터	그룹	객체	설명",
				"pre_def":	1,
				"grp_tpe":	1,
				"mmbr_dlp_data_obj_list":	[
						{
								"dlp_data_obj_id":	10001,
								"type":	0,
								"name":	"데이터	객체	이름",
								"desc":	"데이터	객체	설명",
								"use":	1,
								"pre_def":	1,
								"value_type":	1,
								"value1":	"ICAgIGFzYWFhYQ==",
								"value2":	""
						}
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

/dlp/data-group/userdefined/objects/{pk}

사용자 정의 데이터 그룹 객체을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
DLP 데이터 그룹 객체 ID( dlp_data_obj_id )

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

useuse: required (integer)

사용 여부
사용	안함:	0,	사용:	1

name
name: required (string)
데이터 객체 이름

descdesc: required (string)
설명

mmbr_dlp_data_obj_id
mmbr_dlp_data_obj_id: required (array of integer)
데이터 객체 또는 그룹 객체 ID 목록

Example:
Example

{
		"use":	0,
		"name":	"사용자	정의	데이터	그룹	객체	이름",
		"desc":	"사용자	정의	데이터	그룹	객체	설명",
		"grp_tpe":	1,
		"mmbr_dlp_data_obj_id":	[10001,	10002]
}

Response

HTTP status code 200

사용자 정의 데이터 그룹 객체 수정 성공

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
사용	안함:	0,	사용:	1

name: required (string)
name
데이터 객체 이름

descdesc: required (string)
설명

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 그룹 객체 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def
pre_def: required (integer)
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

grp_type
grp_type: required (integer)
유형
문자열/정규표현식:	1,	파일유형:	2

mmbr_dlp_data_obj_list: required (array of DataObject)
mmbr_dlp_data_obj_list
데이터 객체 또는 그룹 객체 ID 목록

Items: DataObject
Items

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체 또는 그룹 객체 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def
pre_def: required (integer)
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

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

value1
value1: required (string)
객체 유형이  문자열 ,  정규식 일 때 값
Base64 인코딩/디코딩 필요

value2
value2: required (string)
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_data_obj_id":	1,
				"type":	1,
				"use":	0,
				"name":	"사용자	정의	데이터	그룹	객체	이름",
				"desc":	"사용자	정의	데이터	그룹	객체	설명",
				"pre_def":	1,
				"grp_tpe":	1,
				"mmbr_dlp_data_obj_list":	[
						{
								"dlp_data_obj_id":	10001,
								"type":	0,
								"name":	"데이터	객체	이름",
								"desc":	"데이터	객체	설명",
								"use":	1,
								"pre_def":	1,
								"value_type":	1,
								"value1":	"ICAgIGFzYWFhYQ==",
								"value2":	""
						}
				]
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

DELETE

/dlp/data-group/userdefined/objects/{pk}

사용자 정의 데이터 그룹 객체을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
DLP 데이터 그룹 객체 ID( dlp_data_obj_id )

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

사용자 정의 데이터 그룹 객체 삭제 성공

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

DLP 데이터 그룹 객체 적용/취소

PUT

/command/dlp-group/apply

DLP 데이터 그룹 객체을 적용합니다.

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

DLP 데이터 그룹 객체 적용 성공

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

/command/dlp-group/cancel

DLP 데이터 그룹 객체을 취소합니다.

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

DLP 데이터 그룹 객체 취소 성공

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

