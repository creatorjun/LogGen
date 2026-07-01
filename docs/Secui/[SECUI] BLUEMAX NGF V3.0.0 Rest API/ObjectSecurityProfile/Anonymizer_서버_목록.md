GET

GET

POST

  DELETE

PUT

  DELETE

PUT

PUT

Anonymizer 서버 목록 REST API 문서

https://{url}/api/op

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/op

Anonymizer 서버

/wf/anonymizer-servers

/wf/anonymizer-servers/{pk}

Anonymizer 서버 목록 적용/취소

/command/wf-anonymizer-servers/apply

/command/wf-anonymizer-servers/cancel

Anonymizer 서버

GET

/wf/anonymizer-servers

Anonymizer 서버 목록을 조회한다.

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

Anonymizer 서버 목록 조회 성공

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
result: required (array of WfGetAnonymizer)
결과 데이터

Items: WfGetAnonymizer
Items

svr_url: required (string - minLength: 1 - maxLength: 1024)
svr_url
Anonymizer 서버 URL
영문,	숫자,	-,	.,	_,	~,	:,	/,	?,	#,	[,	],	@,	!,	$,	&,	‘,	(,	),	*,	+,	,,	;,	=

offset
offset: required (integer - minimum: 0 - maximum: 99)
종료문자로부터 실제 URL이 존재하는 위치까지의 오프셋

term_char
term_char: required (one of 1, 2, 3)
종료 문자
None:	1,	&:	2,	/:	3

encd_type
encd_type: required (one of 1, 2, 3, 4)
부호화 유형
None:	1,	Hexa:	2,	Base64:	3,	URL	Encoding:	4

anony_svr_id: required (integer)
anony_svr_id
Anonymizer 서버 ID

pre_def
pre_def: required (integer)
시스템 정의 여부
사용자	정의:	0,	시스템	정의:	1

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"anony_svr_id":	1,
				"svr_url":	"Anonymizer	서버	주소",
				"offset":	1,
				"term_char":	1,
				"encd_type":	1,
				"pre_def":	0
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

/wf/anonymizer-servers

Anonymizer 서버를 추가한다.

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
svr_url
svr_url: required (string - minLength: 1 - maxLength: 1024)
Anonymizer 서버 URL
영문,	숫자,	-,	.,	_,	~,	:,	/,	?,	#,	[,	],	@,	!,	$,	&,	‘,	(,	),	*,	+,	,,	;,	=

offset
offset: required (integer - minimum: 0 - maximum: 99)
종료문자로부터 실제 URL이 존재하는 위치까지의 오프셋

term_char
term_char: required (one of 1, 2, 3)
종료 문자
None:	1,	&:	2,	/:	3

encd_type
encd_type: required (one of 1, 2, 3, 4)
부호화 유형
None:	1,	Hexa:	2,	Base64:	3,	URL	Encoding:	4

Example:
Example

{
		"svr_url":	"New	Anonymizer	서버	주소",
		"offset":	1,
		"term_char":	1,
		"encd_type":	1
}

Response

HTTP status code 200

Anonymizer 서버 추가 성공

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

svr_url
svr_url: required (string - minLength: 1 - maxLength: 1024)
Anonymizer 서버 URL
영문,	숫자,	-,	.,	_,	~,	:,	/,	?,	#,	[,	],	@,	!,	$,	&,	‘,	(,	),	*,	+,	,,	;,	=

offset
offset: required (integer - minimum: 0 - maximum: 99)
종료문자로부터 실제 URL이 존재하는 위치까지의 오프셋

term_char
term_char: required (one of 1, 2, 3)
종료 문자
None:	1,	&:	2,	/:	3

encd_type
encd_type: required (one of 1, 2, 3, 4)
부호화 유형
None:	1,	Hexa:	2,	Base64:	3,	URL	Encoding:	4

anony_svr_id
anony_svr_id: required (integer)
Anonymizer 서버 ID

pre_def
pre_def: required (integer)
시스템 정의 여부
사용자	정의:	0,	시스템	정의:	1

Example:
Example

{
		"code":	"ok",
		"result":	{
				"anony_svr_id":	2,
				"svr_url":	"New	Anonymizer	서버	주소",
				"offset":	1,
				"term_char":	1,
				"encd_type":	1,
				"pre_def":	0
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

/wf/anonymizer-servers

Anonymizer 서버 목록을 (일괄)삭제한다.

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

Response

HTTP status code 200

Anonymizer 서버 목록 삭제 성공

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

/wf/anonymizer-servers/{pk}

Anonymizer 서버을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
Anonymizer 서버 ID( anony_svr_id )

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

Anonymizer 서버 조회 성공

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

svr_url
svr_url: required (string - minLength: 1 - maxLength: 1024)
Anonymizer 서버 URL
영문,	숫자,	-,	.,	_,	~,	:,	/,	?,	#,	[,	],	@,	!,	$,	&,	‘,	(,	),	*,	+,	,,	;,	=

offset: required (integer - minimum: 0 - maximum: 99)
offset
종료문자로부터 실제 URL이 존재하는 위치까지의 오프셋

term_char
term_char: required (one of 1, 2, 3)
종료 문자
None:	1,	&:	2,	/:	3

encd_type: required (one of 1, 2, 3, 4)
encd_type
부호화 유형
None:	1,	Hexa:	2,	Base64:	3,	URL	Encoding:	4

anony_svr_id
anony_svr_id: required (integer)
Anonymizer 서버 ID

pre_def: required (integer)
pre_def
시스템 정의 여부
사용자	정의:	0,	시스템	정의:	1

Example:
Example

{
		"code":	"ok",
		"result":	{
				"anony_svr_id":	1,
				"svr_url":	"Anonymizer	서버	주소",
				"offset":	1,
				"term_char":	1,
				"encd_type":	1,
				"pre_def":	0
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

/wf/anonymizer-servers/{pk}

Anonymizer 서버을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
Anonymizer 서버 ID( anony_svr_id )

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
svr_url
svr_url: required (string - minLength: 1 - maxLength: 1024)
Anonymizer 서버 URL
영문,	숫자,	-,	.,	_,	~,	:,	/,	?,	#,	[,	],	@,	!,	$,	&,	‘,	(,	),	*,	+,	,,	;,	=

offset
offset: required (integer - minimum: 0 - maximum: 99)
종료문자로부터 실제 URL이 존재하는 위치까지의 오프셋

term_char
term_char: required (one of 1, 2, 3)
종료 문자
None:	1,	&:	2,	/:	3

encd_type
encd_type: required (one of 1, 2, 3, 4)
부호화 유형
None:	1,	Hexa:	2,	Base64:	3,	URL	Encoding:	4

Example:
Example

{
		"svr_url":	"Anonymizer	서버	주소",
		"offset":	1,
		"term_char":	1,
		"encd_type":	1
}

Response

HTTP status code 200

Anonymizer 서버 수정 성공

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

svr_url: required (string - minLength: 1 - maxLength: 1024)
svr_url
Anonymizer 서버 URL
영문,	숫자,	-,	.,	_,	~,	:,	/,	?,	#,	[,	],	@,	!,	$,	&,	‘,	(,	),	*,	+,	,,	;,	=

offset
offset: required (integer - minimum: 0 - maximum: 99)
종료문자로부터 실제 URL이 존재하는 위치까지의 오프셋

term_char
term_char: required (one of 1, 2, 3)
종료 문자
None:	1,	&:	2,	/:	3

encd_type
encd_type: required (one of 1, 2, 3, 4)
부호화 유형
None:	1,	Hexa:	2,	Base64:	3,	URL	Encoding:	4

anony_svr_id
anony_svr_id: required (integer)
Anonymizer 서버 ID

pre_def
pre_def: required (integer)
시스템 정의 여부
사용자	정의:	0,	시스템	정의:	1

Example:
Example

{
		"code":	"ok",
		"result":	{
				"anony_svr_id":	2,
				"svr_url":	"Anonymizer	서버	주소",
				"offset":	1,
				"term_char":	1,
				"encd_type":	1,
				"pre_def":	0
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

/wf/anonymizer-servers/{pk}

Anonymizer 서버을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
Anonymizer 서버 ID( anony_svr_id )

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

Anonymizer 서버 삭제 성공

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

Anonymizer 서버 목록 적용/취소

PUT

/command/wf-anonymizer-servers/apply

Anonymizer 서버 목록을 적용합니다.

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

Anonymizer 서버 목록 적용 성공

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

/command/wf-anonymizer-servers/cancel

Anonymizer 서버 목록을 취소합니다.

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

Anonymizer 서버 목록 취소 성공

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

