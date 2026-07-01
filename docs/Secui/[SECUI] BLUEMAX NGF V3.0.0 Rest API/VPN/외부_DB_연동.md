GET

POST

PUT

  DELETE

GET

PUT

  DELETE

POST

GET

GET

PUT

PUT

외부 Database 연동 REST API 문서

https://{url}/api/vp

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/vp

외부 Database 연동

/sslvpn/ext-dbs

/sslvpn/ext-dbs/{pk}

/sslvpn/ext-dbs/{pk}/test/user

/sslvpn/ext-dbs/{pk}/test/server

/sslvpn/ext-dbs/{pk}/test/server/{table}

외부 Database 연동 적용/취소

/command/sslvpn-ext-dbs/apply

/command/sslvpn-ext-dbs/cancel

외부 Database 연동

GET

/sslvpn/ext-dbs

외부 Database 목록을 조회한다.

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

외부 Database 목록 조회 성공

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
result: required (array of SslvpnExtDb)
결과 데이터

Items: SslvpnExtDb
Items

authsvr_extdb_id
authsvr_extdb_id: required (integer)
인증서버 외부 DB 아이디

useuse: required (one of 0, 1 - default: 1)
인증서버 사용 여부
사용안함:	0,	사용함:	1

name
name: required (string)
인증서버 외부 DB 이름

type
type: required (one of 0, 1, 2, 3, 4 - default: 0)
데이터베이스 종류
ORACLE:	0,	MS-SQL:	1,	MYSQL:	2,	PostgreSQL:	3,	내PC지키미:	4

tbl_name
tbl_name: required (string)
테이블 이름

col_name
col_name: required (string)
그룹 정보 컬럼

id_col
id_col: required (string)
ID 컬럼

pw_col
pw_col: required (string)
비밀번호 컬럼

pw_salt
pw_salt: (string - maxLength: 32)
비밀번호 salt 사용
요청할 때는 Base64 인코딩 처리하고 응답될 때는 Base64 디코딩이 필요함
필수 입력값이 아니고 입력될 경우 9~32자까지로 제한

pw_enc_type
pw_enc_type: required (one of 0, 1, 2 - default: 0)
비밀번호 암호화 사용
사용안함:	0,	SHA-256:	1,	SHA-512:	2

pw_encd_type: required (one of 0, 1 - default: 0)
pw_encd_type
비밀번호 인코딩
사용안함:	0,	BASE64:	1

extdb_svr_list
extdb_svr_list: required (array of items)
Items: items
Items

extdb_svr_id: required (integer)
extdb_svr_id
외부DB 아이디

ipip: required (string)
서버 주소

portport: required (integer - default: 3600)
서버 포트

group_list
group_list: required (array of items)
Items: items
Items

sslvpn_grp_id
sslvpn_grp_id: required (integer - default: 1)
SSLVPN 그룹의 고유한 아이디

name
name: required (string)
그룹 이름

grp_code
grp_code: required (string)
그룹 코드

auto_grp_use
auto_grp_use: required (one of 0, 1 - default: 1)
그룹 자동 변경
사용안함:	0,	사용함:	1

sqlsql: required (string)
Where절 추가 SQL

descdesc: required (string)
비고

db_name
db_name: required (string)
데이터베이스 이름

db_tbl
db_tbl: required (string)
데이터베이스 테이블

db_id
db_id: required (string)
데이터베이스 아이디

db_pw
db_pw: required (string)
데이터베이스 패스워드

name_col: required (string)
name_col
이름 컬럼
선택된	컬럼이	없을	경우	null로	설정

depart_col
depart_col: required (string)
부서 컬럼
선택된	컬럼이	없을	경우	null로	설정

email_col
email_col: required (string)
E-Mail 컬럼
선택된	컬럼이	없을	경우	null로	설정

phone_col
phone_col: required (string)
휴대폰 컬럼
선택된	컬럼이	없을	경우	null로	설정

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
		"result":	[{
				"authsvr_extdb_id":	1,
				"use":	1,
				"name":	"외부	DB	이름",
				"type":	0,
				"tbl_name":	"user_table",
				"col_name":	"user_grp",
				"id_col":	"usr_id",
				"pw_col":	"usr_pwd",
				"pw_salt":	"cmhzMDQxMCFA",
				"pw_enc_type":	0,
				"pw_encd_type":	0,
				"extdb_svr_list":	[{
						"extdb_svr_id":	1,
						"ip":	"1.1.1.1",
						"port":	3600
				}],
				"group_list":	[{
						"sslvpn_grp_id":	1,
						"name":	"기본	그룹",
						"grp_code":	"a001"
				}],
				"auto_grp_use":	1,
				"sql":	"status=1",
				"desc":	"비고",
				"db_name":	"company",
				"db_tbl":	"tuser",
				"db_id":	"sslvpn",
				"db_pw":	"P@ssw0rd",
				"name_col":	null,
				"depart_col":	null,
				"email_col":	null,
				"phone_col":	null,
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

/sslvpn/ext-dbs

외부 Database를 추가한다.

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

authsvr_extdb_id
authsvr_extdb_id: required (integer)
인증서버 외부 DB 아이디

useuse: required (one of 0, 1 - default: 1)
인증서버 사용 여부
사용안함:	0,	사용함:	1

tbl_name
tbl_name: required (string)
테이블 이름

col_name: required (string)
col_name
그룹 정보 컬럼

id_col
id_col: required (string)
ID 컬럼

pw_col
pw_col: required (string)
비밀번호 컬럼

pw_salt
pw_salt: (string - maxLength: 32)
비밀번호 salt 사용
요청할 때는 Base64 인코딩 처리하고 응답될 때는 Base64 디코딩이 필요함
필수 입력값이 아니고 입력될 경우 9~32자까지로 제한

pw_enc_type: required (one of 0, 1, 2 - default: 0)
pw_enc_type
비밀번호 암호화 사용
사용안함:	0,	SHA-256:	1,	SHA-512:	2

pw_encd_type
pw_encd_type: required (one of 0, 1 - default: 0)
비밀번호 인코딩
사용안함:	0,	BASE64:	1

group_list
group_list: required (array of items)
Items: items
Items

sslvpn_grp_id
sslvpn_grp_id: required (integer - default: 1)
SSLVPN 그룹의 고유한 아이디

name
name: required (string)
그룹 이름

grp_code
grp_code: required (string)
그룹 코드

auto_grp_use: required (one of 0, 1 - default: 1)
auto_grp_use
그룹 자동 변경
사용안함:	0,	사용함:	1

name_col
name_col: required (string)
이름 컬럼
선택된	컬럼이	없을	경우	null로	설정

depart_col
depart_col: required (string)
부서 컬럼
선택된	컬럼이	없을	경우	null로	설정

email_col
email_col: required (string)
E-Mail 컬럼
선택된	컬럼이	없을	경우	null로	설정

phone_col
phone_col: required (string)
휴대폰 컬럼
선택된	컬럼이	없을	경우	null로	설정

sqlsql: required (string)

Where절 추가 SQL

descdesc: required (string)
비고

Example:
Example

{
		"authsvr_extdb_id":	1,
		"use":	1,
		"tbl_name":	"user_table",
		"col_name":	"user_grp",
		"id_col":	"usr_id",
		"pw_col":	"usr_pwd",
		"pw_salt":	"cmhzMDQxMCFA",
		"pw_enc_type":	0,
		"pw_encd_type":	0,
		"group_list":	[{
				"sslvpn_grp_id":	1,
				"name":	"기본	그룹",
				"grp_code":	"a001"
		}],
		"auto_grp_use":	1,
		"name_col":	null,
		"depart_col":	null,
		"email_col":	null,
		"phone_col":	null,
		"sql":	"status=1",
		"desc":	"비고"
}

Response

HTTP status code 200

외부 Database 추가 성공

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

authsvr_extdb_id
authsvr_extdb_id: required (integer)
인증서버 외부 DB 아이디

useuse: required (one of 0, 1 - default: 1)
인증서버 사용 여부
사용안함:	0,	사용함:	1

name
name: required (string)
인증서버 외부 DB 이름

type
type: required (one of 0, 1, 2, 3, 4 - default: 0)
데이터베이스 종류
ORACLE:	0,	MS-SQL:	1,	MYSQL:	2,	PostgreSQL:	3,	내PC지키미:	4

tbl_name
tbl_name: required (string)
테이블 이름

col_name
col_name: required (string)
그룹 정보 컬럼

id_col: required (string)
id_col
ID 컬럼

pw_col
pw_col: required (string)
비밀번호 컬럼

pw_salt
pw_salt: (string - maxLength: 32)
비밀번호 salt 사용
요청할 때는 Base64 인코딩 처리하고 응답될 때는 Base64 디코딩이 필요함
필수 입력값이 아니고 입력될 경우 9~32자까지로 제한

pw_enc_type
pw_enc_type: required (one of 0, 1, 2 - default: 0)
비밀번호 암호화 사용
사용안함:	0,	SHA-256:	1,	SHA-512:	2

pw_encd_type
pw_encd_type: required (one of 0, 1 - default: 0)
비밀번호 인코딩
사용안함:	0,	BASE64:	1

extdb_svr_list
extdb_svr_list: required (array of items)
Items: items
Items

extdb_svr_id
extdb_svr_id: required (integer)
외부DB 아이디

ipip: required (string)
서버 주소

portport: required (integer - default: 3600)
서버 포트

group_list
group_list: required (array of items)
Items: items
Items

sslvpn_grp_id
sslvpn_grp_id: required (integer - default: 1)
SSLVPN 그룹의 고유한 아이디

name
name: required (string)
그룹 이름

grp_code
grp_code: required (string)
그룹 코드

auto_grp_use
auto_grp_use: required (one of 0, 1 - default: 1)
그룹 자동 변경
사용안함:	0,	사용함:	1

sqlsql: required (string)
Where절 추가 SQL

descdesc: required (string)
비고

db_name
db_name: required (string)
데이터베이스 이름

db_tbl
db_tbl: required (string)
데이터베이스 테이블

db_id
db_id: required (string)
데이터베이스 아이디

db_pw
db_pw: required (string)
데이터베이스 패스워드

name_col: required (string)
name_col
이름 컬럼
선택된	컬럼이	없을	경우	null로	설정

depart_col
depart_col: required (string)
부서 컬럼
선택된	컬럼이	없을	경우	null로	설정

email_col
email_col: required (string)
E-Mail 컬럼
선택된	컬럼이	없을	경우	null로	설정

phone_col
phone_col: required (string)
휴대폰 컬럼
선택된	컬럼이	없을	경우	null로	설정

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
				"authsvr_extdb_id":	1,
				"use":	1,
				"name":	"외부	DB	이름",
				"type":	0,
				"tbl_name":	"user_table",
				"col_name":	"user_grp",
				"id_col":	"usr_id",
				"pw_col":	"usr_pwd",
				"pw_salt":	"cmhzMDQxMCFA",
				"pw_enc_type":	0,
				"pw_encd_type":	0,
				"extdb_svr_list":	[{
						"extdb_svr_id":	1,
						"ip":	"1.1.1.1",
						"port":	3600
				}],
				"group_list":	[{
						"sslvpn_grp_id":	1,
						"name":	"기본	그룹",
						"grp_code":	"a001"
				}],
				"auto_grp_use":	1,
				"sql":	"status=1",
				"desc":	"비고",
				"db_name":	"company",
				"db_tbl":	"tuser",
				"db_id":	"sslvpn",
				"db_pw":	"P@ssw0rd",
				"name_col":	null,
				"depart_col":	null,
				"email_col":	null,
				"phone_col":	null,
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

PUT

/sslvpn/ext-dbs

외부 Database 목록을 (일괄)수정한다.

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
items: required (array of ReqListSslvpnExtDb)
수정 아이템 목록

Items: ReqListSslvpnExtDb
Items

authsvr_extdb_id
authsvr_extdb_id: required (integer)
인증서버 외부 DB 아이디

useuse: required (one of 0, 1 - default: 1)
인증서버 사용 여부
사용안함:	0,	사용함:	1

Example:
Example

{
		"items":	[
				{"authsvr_extdb_id":	1,	"use":	0}
		]
}

Response

HTTP status code 200

외부 Database 목록 수정 성공

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
수정 실패 시 에러 목록

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

DELETE

/sslvpn/ext-dbs

외부 Database 목록을 (일괄)삭제한다.

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
				{"authsvr_extdb_id":	1},
				{"authsvr_extdb_id":	2}
		]
}

Response

HTTP status code 200

외부 Database 목록 삭제 성공

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

errors: required (array of object)
errors
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

/sslvpn/ext-dbs/{pk}

외부 Database을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
인증서버 외부 DB 아이디 ( authsvr_extdb_id )

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

외부 Database 조회 성공

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

authsvr_extdb_id
authsvr_extdb_id: required (integer)
인증서버 외부 DB 아이디

useuse: required (one of 0, 1 - default: 1)
인증서버 사용 여부
사용안함:	0,	사용함:	1

name
name: required (string)
인증서버 외부 DB 이름

type
type: required (one of 0, 1, 2, 3, 4 - default: 0)
데이터베이스 종류
ORACLE:	0,	MS-SQL:	1,	MYSQL:	2,	PostgreSQL:	3,	내PC지키미:	4

tbl_name
tbl_name: required (string)
테이블 이름

col_name
col_name: required (string)
그룹 정보 컬럼

id_col
id_col: required (string)
ID 컬럼

pw_col
pw_col: required (string)
비밀번호 컬럼

pw_salt
pw_salt: (string - maxLength: 32)
비밀번호 salt 사용
요청할 때는 Base64 인코딩 처리하고 응답될 때는 Base64 디코딩이 필요함
필수 입력값이 아니고 입력될 경우 9~32자까지로 제한

pw_enc_type
pw_enc_type: required (one of 0, 1, 2 - default: 0)
비밀번호 암호화 사용
사용안함:	0,	SHA-256:	1,	SHA-512:	2

pw_encd_type
pw_encd_type: required (one of 0, 1 - default: 0)
비밀번호 인코딩
사용안함:	0,	BASE64:	1

extdb_svr_list
extdb_svr_list: required (array of items)
Items: items
Items

extdb_svr_id: required (integer)
extdb_svr_id
외부DB 아이디

ipip: required (string)
서버 주소

portport: required (integer - default: 3600)
서버 포트

group_list
group_list: required (array of items)
Items: items
Items

sslvpn_grp_id
sslvpn_grp_id: required (integer - default: 1)
SSLVPN 그룹의 고유한 아이디

name
name: required (string)
그룹 이름

grp_code
grp_code: required (string)
그룹 코드

auto_grp_use
auto_grp_use: required (one of 0, 1 - default: 1)
그룹 자동 변경
사용안함:	0,	사용함:	1

sqlsql: required (string)
Where절 추가 SQL

descdesc: required (string)
비고

db_name
db_name: required (string)
데이터베이스 이름

db_tbl
db_tbl: required (string)
데이터베이스 테이블

db_id
db_id: required (string)
데이터베이스 아이디

db_pw: required (string)
db_pw
데이터베이스 패스워드

name_col
name_col: required (string)
이름 컬럼
선택된	컬럼이	없을	경우	null로	설정

depart_col: required (string)
depart_col
부서 컬럼
선택된	컬럼이	없을	경우	null로	설정

email_col
email_col: required (string)
E-Mail 컬럼
선택된	컬럼이	없을	경우	null로	설정

phone_col
phone_col: required (string)
휴대폰 컬럼
선택된	컬럼이	없을	경우	null로	설정

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
				"authsvr_extdb_id":	1,
				"use":	1,
				"name":	"외부	DB	이름",
				"type":	0,
				"tbl_name":	"user_table",
				"col_name":	"user_grp",
				"id_col":	"usr_id",
				"pw_col":	"usr_pwd",
				"pw_salt":	"cmhzMDQxMCFA",
				"pw_enc_type":	0,
				"pw_encd_type":	0,
				"extdb_svr_list":	[{
						"extdb_svr_id":	1,
						"ip":	"1.1.1.1",
						"port":	3600
				}],
				"group_list":	[{
						"sslvpn_grp_id":	1,
						"name":	"기본	그룹",
						"grp_code":	"a001"
				}],
				"auto_grp_use":	1,
				"sql":	"status=1",
				"desc":	"비고",
				"db_name":	"company",
				"db_tbl":	"tuser",
				"db_id":	"sslvpn",
				"db_pw":	"P@ssw0rd",
				"name_col":	null,
				"depart_col":	null,
				"email_col":	null,
				"phone_col":	null,
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

PUT

/sslvpn/ext-dbs/{pk}

외부 Database을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
인증서버 외부 DB 아이디 ( authsvr_extdb_id )

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

authsvr_extdb_id
authsvr_extdb_id: required (integer)
인증서버 외부 DB 아이디

useuse: required (one of 0, 1 - default: 1)
인증서버 사용 여부
사용안함:	0,	사용함:	1

tbl_name
tbl_name: required (string)
테이블 이름

col_name: required (string)
col_name
그룹 정보 컬럼

id_col
id_col: required (string)
ID 컬럼

pw_col
pw_col: required (string)
비밀번호 컬럼

pw_salt
pw_salt: (string - maxLength: 32)
비밀번호 salt 사용
요청할 때는 Base64 인코딩 처리하고 응답될 때는 Base64 디코딩이 필요함
필수 입력값이 아니고 입력될 경우 9~32자까지로 제한

pw_enc_type: required (one of 0, 1, 2 - default: 0)
pw_enc_type
비밀번호 암호화 사용
사용안함:	0,	SHA-256:	1,	SHA-512:	2

pw_encd_type
pw_encd_type: required (one of 0, 1 - default: 0)
비밀번호 인코딩
사용안함:	0,	BASE64:	1

group_list
group_list: required (array of items)
Items: items
Items

sslvpn_grp_id
sslvpn_grp_id: required (integer - default: 1)
SSLVPN 그룹의 고유한 아이디

name
name: required (string)
그룹 이름

grp_code
grp_code: required (string)
그룹 코드

auto_grp_use
auto_grp_use: required (one of 0, 1 - default: 1)
그룹 자동 변경
사용안함:	0,	사용함:	1

name_col: required (string)
name_col
이름 컬럼
선택된	컬럼이	없을	경우	null로	설정

depart_col
depart_col: required (string)
부서 컬럼
선택된	컬럼이	없을	경우	null로	설정

email_col
email_col: required (string)
E-Mail 컬럼
선택된	컬럼이	없을	경우	null로	설정

phone_col
phone_col: required (string)
휴대폰 컬럼
선택된	컬럼이	없을	경우	null로	설정

sqlsql: required (string)
Where절 추가 SQL

descdesc: required (string)
비고

Example:
Example

{
		"authsvr_extdb_id":	1,
		"use":	0,
		"tbl_name":	"user_table2",
		"col_name":	"user_grp2",
		"id_col":	"usr_id2",
		"pw_col":	"usr_pwd2",
		"pw_salt":	"cmhzMDQxMCFA",
		"pw_enc_type":	1,
		"pw_encd_type":	1,
		"group_list":	[{
				"sslvpn_grp_id":	2,
				"name":	"기본	그룹2",
				"grp_code":	"a002"
		}],
		"auto_grp_use":	0,
		"name_col":	null,
		"depart_col":	null,
		"email_col":	null,
		"phone_col":	null,
		"sql":	"status=2",
		"desc":	"비고2"
}

Response

HTTP status code 200

외부 Database 수정 성공

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

authsvr_extdb_id
authsvr_extdb_id: required (integer)
인증서버 외부 DB 아이디

useuse: required (one of 0, 1 - default: 1)
인증서버 사용 여부
사용안함:	0,	사용함:	1

name
name: required (string)
인증서버 외부 DB 이름

type
type: required (one of 0, 1, 2, 3, 4 - default: 0)
데이터베이스 종류
ORACLE:	0,	MS-SQL:	1,	MYSQL:	2,	PostgreSQL:	3,	내PC지키미:	4

tbl_name
tbl_name: required (string)
테이블 이름

col_name
col_name: required (string)
그룹 정보 컬럼

id_col
id_col: required (string)
ID 컬럼

pw_col
pw_col: required (string)
비밀번호 컬럼

pw_salt: (string - maxLength: 32)
pw_salt
비밀번호 salt 사용
요청할 때는 Base64 인코딩 처리하고 응답될 때는 Base64 디코딩이 필요함
필수 입력값이 아니고 입력될 경우 9~32자까지로 제한

pw_enc_type: required (one of 0, 1, 2 - default: 0)
pw_enc_type

비밀번호 암호화 사용
사용안함:	0,	SHA-256:	1,	SHA-512:	2

pw_encd_type
pw_encd_type: required (one of 0, 1 - default: 0)
비밀번호 인코딩
사용안함:	0,	BASE64:	1

extdb_svr_list
extdb_svr_list: required (array of items)
Items: items
Items

extdb_svr_id
extdb_svr_id: required (integer)
외부DB 아이디

ipip: required (string)
서버 주소

portport: required (integer - default: 3600)
서버 포트

group_list
group_list: required (array of items)
Items: items
Items

sslvpn_grp_id
sslvpn_grp_id: required (integer - default: 1)
SSLVPN 그룹의 고유한 아이디

name
name: required (string)
그룹 이름

grp_code
grp_code: required (string)
그룹 코드

auto_grp_use
auto_grp_use: required (one of 0, 1 - default: 1)
그룹 자동 변경
사용안함:	0,	사용함:	1

sqlsql: required (string)
Where절 추가 SQL

descdesc: required (string)
비고

db_name
db_name: required (string)
데이터베이스 이름

db_tbl: required (string)
db_tbl
데이터베이스 테이블

db_id
db_id: required (string)
데이터베이스 아이디

db_pw
db_pw: required (string)
데이터베이스 패스워드

name_col
name_col: required (string)
이름 컬럼
선택된	컬럼이	없을	경우	null로	설정

depart_col
depart_col: required (string)
부서 컬럼
선택된	컬럼이	없을	경우	null로	설정

email_col
email_col: required (string)
E-Mail 컬럼
선택된	컬럼이	없을	경우	null로	설정

phone_col: required (string)
phone_col
휴대폰 컬럼
선택된	컬럼이	없을	경우	null로	설정

cfg_adm_id
cfg_adm_id: required (integer)
등록자 ID

cfg_adm: required (string)
cfg_adm
등록자

cfg_dt
cfg_dt: required (string)
최근 수정일

Example:
Example

{
		"code":	"ok",
		"result":	{
				"authsvr_extdb_id":	1,
				"use":	0,
				"name":	"외부	DB	이름	2",
				"type":	1,
				"tbl_name":	"user_table2",
				"col_name":	"user_grp2",
				"id_col":	"usr_id2",
				"pw_col":	"usr_pwd2",
				"pw_salt":	"cmhzMDQxMCFA",
				"pw_enc_type":	1,
				"pw_encd_type":	1,
				"extdb_svr_list":	[{
						"extdb_svr_id":	1,
						"ip":	"1.1.1.1",
						"port":	3600
				}],
				"group_list":	[{
						"sslvpn_grp_id":	2,
						"name":	"기본	그룹2",
						"grp_code":	"a002"
				}],
				"auto_grp_use":	0,
				"sql":	"status=2",
				"desc":	"비고2",
				"db_name":	"company",
				"db_tbl":	"tuser",
				"db_id":	"sslvpn",
				"db_pw":	"P@ssw0rd",
				"name_col":	null,
				"depart_col":	null,
				"email_col":	null,
				"phone_col":	null,
				"cfg_adm_id":	1,
				"cfg_adm":	"admin",
				"cfg_dt":	"2018-10-10	15:36:45"
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

DELETE

/sslvpn/ext-dbs/{pk}

외부 Database을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
인증서버 외부 DB 아이디 ( authsvr_extdb_id )

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

외부 Database 삭제 성공

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

POST

/sslvpn/ext-dbs/{pk}/test/user

사용자 접속 테스트한다.

Request

URI Parameters

pkpk: required (integer)
인증서버 외부 DB 아이디 ( authsvr_extdb_id )

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

idid: required (string)
사용자 아이디

pwdpwd: required (string)
사용자 패스워드(Base64 인코딩)

Example:
Example

{
		"id":	"usr1",
		"pwd":	"x2xAyWkwMEAh"
}

Response

HTTP status code 200

사용자 접속 테스트 성공

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

HTTP status code 400

사용자 접속 테스트 요청 실패

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

GET

/sslvpn/ext-dbs/{pk}/test/server

외부서버 접속 테이블을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
인증서버 외부 DB 아이디 ( authsvr_extdb_id )

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

Response

HTTP status code 200

외부서버 접속 테이블 조회 성공

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

items
items: required (array of string)
테이블 이름 리스트

Example:
Example

{
		"code":	"ok",
		"result":	{
				"items":	["table_name_1",	"table_name_2",	"table_name_3"]
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

GET

/sslvpn/ext-dbs/{pk}/test/server/{table}

외부서버 접속 테이블 컬럼을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
인증서버 외부 DB 아이디 ( authsvr_extdb_id )

table: required (string)
table
테이블 이름 ( tbl_name )

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

외부서버 접속 테이블 컬럼 조회 성공

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

items
items: required (array of string)
컬럼 이름 리스트

Example:
Example

{
		"code":	"ok",
		"result":	{
				"items":	["column_name_1",	"column_name_2",	"column_name_3"]
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

외부 Database 연동 적용/취소

PUT

/command/sslvpn-ext-dbs/apply

외부 Database 연동을 적용합니다.

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

외부 Database 연동 적용 성공

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

/command/sslvpn-ext-dbs/cancel

외부 Database 연동을 취소합니다.

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

외부 Database 연동 취소 성공

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

