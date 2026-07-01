GET

GET

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

  DELETE

GET

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

DLP 프로파일 REST API 문서

https://{url}/api/op

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/op

DLP 프로토콜

/dlp/protocols

DLP 파일유형

/dlp/filetype/types

DLP 프로파일

/dlp/profiles

/dlp/profiles/{pk}

DLP 필터 정책

/dlp/profiles/{ppk}/filters

/dlp/profiles/{ppk}/filters/{pk}

DLP 아카이브 정책

/dlp/profiles/{ppk}/archives

/dlp/profiles/{ppk}/archives/{pk}

DLP 프로파일 목록 적용/취소

/command/dlp-profiles/apply

/command/dlp-profiles/cancel

DLP 프로토콜

GET

/dlp/protocols

DLP 프로토콜을(를) 조회한다.

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

Response

HTTP status code 200

DLP 프로토콜 조회 성공

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

string: required (object)
string
문자열,	정규식  데이터 객체 선택시 출력될 프로토콜 정보
프로토콜 별 상세 설정 정보를 포함
정책 추가/편집 시 요청으로 전달될 속성으로는 Key를 사용 -> smtp_cmd, pop3_sndr
추가/편집 파업에 상세 설정에 출력될 이름은 Value를 사용 -> command, sender

Example:
Example

{
		"smtp":	{
				"smtp_cmd":	"command"
		},
		"pop3":	{
				"pop3_sndr":	"sender"
		}
}

sizesize: required (object)
크기  데이터 객체 선택시 출력될 프로토콜 정보
프로토콜 별 상세 설정 정보를 포함
정책 추가/편집 시 요청으로 전달될 속성으로는 Key를 사용 -> smtp_cntn_size, pop3_cntn_size
추가/편집 파업에 상세 설정에 출력될 이름은 Value를 사용 -> content-size, content-size

Example:
Example

{
		"smtp":	{
				"smtp_cntn_size":	"content-size"
		},
		"pop3":	{
				"pop3_cntn_size":	"content-size"
		}
}

archive
archive: required (object)
아카이브 정책에서 출력될 프로토콜 정보 프로토콜 별 상세 설정 정보를 포함
정책 추가/편집 시 요청으로 전달될 속성으로는 Key를 사용 -> smtp_attach, pop3_attach
추가/편집 파업에 상세 설정에 출력될 이름은 Value를 사용 -> attachment, attachment

Example:
Example

{
		"smtp":	{
				"smtp_attach":	"attachment"
		},
		"pop3":	{
				"pop3_attach":	"attachment"
		}
}

filetype
filetype: required (object)
파일	유형  데이터 객체 선택시 출력될 프로토콜 정보
프로토콜 별 상세 설정 정보를 포함
정책 추가/편집 시 요청으로 전달될 속성으로는 Key를 사용 -> smtp_ftype
추가/편집 파업에 상세 설정에 출력될 이름은 Value를 사용 -> FileType

Example:
Example

{
		"smtp":	{
				"smtp_ftype":	"FileType"
		},
		"pop3":	{
				"pop3_ftype":	"FileType"
		}
}

Example:
Example

{
		"code":	"ok",
		"result":	{
				"string":	{
						"smtp":	{
								"smtp_cmd":	"command",
								"smtp_rsps":	"response",
								"smtp_sndr":	"sender",
								"smtp_rcvr":	"receiver",
								"smtp_sbjt":	"subject",
								"smtp_header":	"header",
								"smtp_body":	"body",
								"smtp_fname":	"filename",
								"smtp_fbody":	"filebody"
						},
						"pop3":	{
								"pop3_sndr":	"sender",
								"pop3_rcvr":	"receiver",
								"pop3_sbjt":	"subject",
								"pop3_header":	"header",
								"pop3_body":	"body",
								"pop3_fname":	"filename",
								"pop3_fbody":	"filebody"
						},
						"imap":	{
								"imap_sndr":	"sender",
								"imap_rcvr":	"receiver",
								"imap_sbjt":	"subject",
								"imap_header":	"header",
								"imap_body":	"body",
								"imap_fname":	"filename",
								"imap_fbody":	"filebody"
						},
						"http_req":	{
								"http_rqst_method":	"method",
								"http_rqst_url":	"url",
								"http_rqst_url_raw":	"url-raw",
								"http_rqst_host":	"host",
								"http_rqst_start_line":	"start-line",
								"http_rqst_header":	"header",
								"http_rqst_header_raw":	"header-raw",
								"http_rqst_body":	"body",
								"http_rqst_body_raw":	"body-raw",
								"http_rqst_fname":	"filename",
								"http_rqst_fbody":	"filebody"
						},
						"http_res":	{
								"http_rsps_start_line":	"start-line",
								"http_rsps_header":	"header",
								"http_rsps_header_raw":	"header-raw",
								"http_rsps_body":	"body",
								"http_rsps_body_raw":	"body-raw",
								"http_rsps_fname":	"filename",
								"http_rsps_fbody":	"filebody"
						},
						"ftp_to":	{
								"ftp_rqst_cmd":	"command",
								"ftp_rqst_fname":	"filename",
								"ftp_rqst_fbody":	"filebody"
						},
						"ftp_from":	{
								"ftp_rsps_rsps":	"response",
								"ftp_rsps	_fname":	"filename",
								"ftp_rsps	_fbody":	"filebody"
						}
				},
				"size":	{
						"smtp":	{
								"smtp_cntn_size":	"content-size",
								"smtp_attach_size":	"attachment-size"
						},
						"pop3":	{
								"pop3_cntn_size":	"content-size",
								"pop3_attach_size":	"attachment-size"
						},
						"imap":	{
								"imap_cntn_size":	"content-size",
								"imap_attach_size":	"attachment-size"
						},
						"http_req":	{
								"http_rqst_cntn_size":	"content-size",
								"http_rqst_file_size":	"file-size"
						},
						"http_res":	{
								"http_rsps_cntn_size":	"content-size",
								"http_rsps_file_size":	"file-size"
						},

						"ftp_to":	{
								"ftp_rqst_file_size":	"file-size"
						},
						"ftp_from":	{
								"ftp_rsps_file_size":	"file-size"
						}
				},
				"archive":	{
						"smtp":	{
								"smtp_attach":	"attachment",
								"smtp_header":	"header",
								"smtp_body":	"body"
						},
						"pop3":	{
								"pop3_attach":	"attachment",
								"pop3_header":	"header",
								"pop3_body":	"body"
						},
						"imap":	{
								"imap_attach":	"attachment",
								"imap_header":	"header",
								"imap_body":	"body"
						},
						"http_req":	{
								"http_rqst_header":	"header",
								"http_rqst_file":	"file",
								"http_rqst_body":	"body"
						},
						"http_res":	{
								"http_rsps_header":	"header",
								"http_rsps_file":	"file",
								"http_rsps_body":	"body"
						},
						"ftp_to":	{
								"ftp_rqst_file":	"file",
								"ftp_rqst_cmd":	"command"
						},
						"ftp_from":	{
								"ftp_rsps_file":	"file",
								"ftp_rsps_cmd":	"command"
						}
				},
				"filetype":	{
						"smtp":	{
								"smtp_ftype":	"FileType"
						},
						"pop3":	{
								"pop3_ftype":	"FileType"
						},
						"imap":	{
								"imap_ftype":	"FileType"
						},
						"http_req":	{
								"http_rqst_ftype":	"FileType"
						},
						"http_res":	{
								"http_rsps_ftype":	"FileType"
						},
						"ftp_to":	{
								"ftp_rqst_ftype":	"FileType"
						},
						"ftp_from":	{
								"ftp_rsps_ftype":	"FileType"
						}
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

dev_t: (string)
dev_t
개발용 메시지

Example:
Example

{
		"code":	"12001",
		"message":	"존재하지	않는	항목입니다."
}

DLP 파일유형

GET

/dlp/filetype/types

파일유형 목록을 조회한다.

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

Response

HTTP status code 200

파일유형 목록 조회 성공

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
result: required (array of DlpFiletype)
결과 데이터

Items: DlpFiletype
Items

idid: required (integer)
파일유형 ID

name
name: required (string)
파일유형명

descdesc: required (string)
설명

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"id":	10001,
						"name":	"pdf",
						"desc":	"Portable	Document	Format	(PDF)	is	a	file	format."
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

DLP 프로파일

GET

/dlp/profiles

DLP 프로파일 목록을 조회한다.

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

Response

HTTP status code 200

DLP 프로파일 목록 조회 성공

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
result: required (array of DlpGetProfile)
결과 데이터

Items: DlpGetProfile
Items

useuse: required (integer)
사용여부
사용안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
설명

dlp_prf_id
dlp_prf_id: required (integer)
DLP 프로파일 ID(PK)

filter_cnt: required (integer)
filter_cnt
필터 정책 개수(CLOAD 사용)
GUI에서	사용되지	않음

archive_cnt
archive_cnt: required (integer)
아카이브 정책 개수(CLOAD 사용)
GUI에서	사용되지	않음

Example:
Example

{
		"code":	"ok",c
		"result":	[{
				"dlp_prf_id":	1,
				"use":	1,
				"name":	"프로파일	이름",
				"desc":	"프로파일	설명",
				"filter_cnt":	0,
				"archive_cnt":	0
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

/dlp/profiles

DLP 프로파일를 추가한다.

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
사용여부
사용안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
설명

Example:
Example

{
		"use":	1,
		"name":	"New	프로파일	이름",
		"desc":	"New	프로파일	설명"
}

Response

HTTP status code 200

DLP 프로파일 추가 성공

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
사용여부
사용안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
설명

dlp_prf_id
dlp_prf_id: required (integer)
DLP 프로파일 ID(PK)

filter_cnt
filter_cnt: required (integer)
필터 정책 개수(CLOAD 사용)
GUI에서	사용되지	않음

archive_cnt
archive_cnt: required (integer)
아카이브 정책 개수(CLOAD 사용)
GUI에서	사용되지	않음

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_prf_id":	2,
				"use":	1,
				"name":	"New	프로파일	이름",
				"desc":	"New	프로파일	설명",
				"filter_cnt":	0,
				"archive_cnt":	0
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

/dlp/profiles

DLP 프로파일 목록을 (일괄)수정한다.

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
				{"dlp_prf_id":	1,	"use":	0},
				{"dlp_prf_id":	2,	"use":	0}
		]
}

Response

HTTP status code 200

DLP 프로파일 목록 수정 성공

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

DELETE

/dlp/profiles

DLP 프로파일 목록을 (일괄)삭제한다.

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
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"dlp_prf_id":	1},
				{"dlp_prf_id":	2}
		]
}

Response

HTTP status code 200

DLP 프로파일 목록 삭제 성공

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

/dlp/profiles/{pk}

DLP 프로파일을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

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

Response

HTTP status code 200

DLP 프로파일 조회 성공

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
사용여부
사용안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
설명

dlp_prf_id
dlp_prf_id: required (integer)
DLP 프로파일 ID(PK)

filter_cnt
filter_cnt: required (integer)
필터 정책 개수(CLOAD 사용)
GUI에서	사용되지	않음

archive_cnt
archive_cnt: required (integer)
아카이브 정책 개수(CLOAD 사용)
GUI에서	사용되지	않음

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_prf_id":	1,
				"use":	1,
				"name":	"프로파일	이름",
				"desc":	"프로파일	설명",
				"filter_cnt":	0,
				"archive_cnt":	0
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

/dlp/profiles/{pk}

DLP 프로파일을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

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

Properties
Properties

useuse: required (integer)
사용여부
사용안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
설명

Example:
Example

{
		"use":	0,
		"name":	"프로파일	이름",
		"desc":	"프로파일	설명"
}

Response

HTTP status code 200

DLP 프로파일 수정 성공

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
사용여부
사용안함:	0,	사용:	1

name
name: required (string - minLength: 1 - maxLength: 32)
프로파일 이름

descdesc: (string - maxLength: 128)
설명

dlp_prf_id
dlp_prf_id: required (integer)
DLP 프로파일 ID(PK)

filter_cnt
filter_cnt: required (integer)
필터 정책 개수(CLOAD 사용)
GUI에서	사용되지	않음

archive_cnt
archive_cnt: required (integer)
아카이브 정책 개수(CLOAD 사용)
GUI에서	사용되지	않음

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_prf_id":	1,
				"use":	0,
				"name":	"프로파일	이름",
				"desc":	"프로파일	설명",
				"filter_cnt":	0,
				"archive_cnt":	0
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

dev_t: (string)
dev_t
개발용 메시지

Example:
Example

{
		"code":	"12001",
		"message":	"존재하지	않는	항목입니다."
}

DELETE

/dlp/profiles/{pk}

DLP 프로파일을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

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

DLP 프로파일 삭제 성공

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

message: required (string)
message
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

DLP 필터 정책

GET

/dlp/profiles/{ppk}/filters

DLP 필터 정책 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

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

DLP 필터 정책 목록 조회 성공

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
result: required (array of DlpGetFilter)
결과 데이터

Items: DlpGetFilter
Items

name: required (string - minLength: 1 - maxLength: 32)
name
정책 이름

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

direct
direct: required (one of 1, 2, 3)
방향
내부:1,	외부:	2,	양방향:	3

action
action: required (one of 0, 1)
유형
탐지:	0,	차단:	1

log_use: required (one of 0, 1)
log_use
로그 사용 여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1)
덤프 사용 여부
사용안함:	0,	사용:	1

mail_use: required (one of 0, 1)
mail_use
메일 사용 여부
사용안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

smtp_use: required (one of 0, 1)
smtp_use
SMTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

pop3_use
pop3_use: required (one of 0, 1)
POP3 프로토콜 사용 여부
사용안함:	0,	사용:	1

imap_use
imap_use: required (one of 0, 1)
IMAP 프로토콜 사용 여부
사용안함:	0,	사용:	1

http_use
http_use: required (one of 0, 1)
HTTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

ftp_use
ftp_use: required (one of 0, 1)
FTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

smtp_cmd
smtp_cmd: required (one of 0, 1)
SMTP - command
사용안함:	0,	사용:	1

smtp_rsps
smtp_rsps: required (one of 0, 1)
SMTP - response
사용안함:	0,	사용:	1

smtp_sndr
smtp_sndr: required (one of 0, 1)
SMTP - sender
사용안함:	0,	사용:	1

smtp_rcvr
smtp_rcvr: required (one of 0, 1)
SMTP - receiver
사용안함:	0,	사용:	1

smtp_sbjt
smtp_sbjt: required (one of 0, 1)
SMTP - subject
사용안함:	0,	사용:	1

smtp_header
smtp_header: required (one of 0, 1)
SMTP - header
사용안함:	0,	사용:	1

smtp_body: required (one of 0, 1)
smtp_body
SMTP - body
사용안함:	0,	사용:	1

smtp_fname
smtp_fname: required (one of 0, 1)
SMTP - filename
사용안함:	0,	사용:	1

smtp_fbody: required (one of 0, 1)
smtp_fbody
SMTP - filebody
사용안함:	0,	사용:	1

smtp_ftype
smtp_ftype: required (one of 0, 1)
SMTP - filetype
사용안함:	0,	사용:	1

smtp_cntn_size
smtp_cntn_size: required (one of 0, 1)
SMTP - content size
사용안함:	0,	사용:	1

smtp_attach_size
smtp_attach_size: required (one of 0, 1)
SMTP - attachment size
사용안함:	0,	사용:	1

pop3_sndr
pop3_sndr: required (one of 0, 1)
POP - sender
사용안함:	0,	사용:	1

pop3_rcvr
pop3_rcvr: required (one of 0, 1)
POP - receiver
사용안함:	0,	사용:	1

pop3_sbjt
pop3_sbjt: required (one of 0, 1)
POP - subject
사용안함:	0,	사용:	1

pop3_header: required (one of 0, 1)
pop3_header
POP - header
사용안함:	0,	사용:	1

pop3_body
pop3_body: required (one of 0, 1)
POP - body
사용안함:	0,	사용:	1

pop3_fname
pop3_fname: required (one of 0, 1)
POP - filename
사용안함:	0,	사용:	1

pop3_fbody
pop3_fbody: required (one of 0, 1)
POP - filebody
사용안함:	0,	사용:	1

pop3_ftype
pop3_ftype: required (one of 0, 1)
POP - filetype
사용안함:	0,	사용:	1

pop3_cntn_size
pop3_cntn_size: required (one of 0, 1)
POP - content size
사용안함:	0,	사용:	1

pop3_attach_size
pop3_attach_size: required (one of 0, 1)
POP - attachment size
사용안함:	0,	사용:	1

imap_sndr
imap_sndr: required (one of 0, 1)
IMAP - sender
사용안함:	0,	사용:	1

imap_rcvr
imap_rcvr: required (one of 0, 1)
IMAP - receiver
사용안함:	0,	사용:	1

imap_sbjt
imap_sbjt: required (one of 0, 1)
IMAP - subject
사용안함:	0,	사용:	1

imap_header
imap_header: required (one of 0, 1)
IMAP - header
사용안함:	0,	사용:	1

imap_body: required (one of 0, 1)
imap_body
IMAP - body
사용안함:	0,	사용:	1

imap_fname
imap_fname: required (one of 0, 1)
IMAP - filename
사용안함:	0,	사용:	1

imap_fbody: required (one of 0, 1)
imap_fbody
IMAP - filebody
사용안함:	0,	사용:	1

imap_ftype
imap_ftype: required (one of 0, 1)
IMAP - filetype
사용안함:	0,	사용:	1

imap_cntn_size
imap_cntn_size: required (one of 0, 1)
IMAP - content size
사용안함:	0,	사용:	1

imap_attach_size
imap_attach_size: required (one of 0, 1)
IMAP - attachment size
사용안함:	0,	사용:	1

http_rqst_method
http_rqst_method: required (one of 0, 1)
HTTP(Request) - method
사용안함:	0,	사용:	1

http_rqst_url
http_rqst_url: required (one of 0, 1)
HTTP(Request) - url
사용안함:	0,	사용:	1

http_rqst_url_raw
http_rqst_url_raw: required (one of 0, 1)
HTTP(Request) - url_raw
사용안함:	0,	사용:	1

http_rqst_host
http_rqst_host: required (one of 0, 1)
HTTP(Request) - host
사용안함:	0,	사용:	1

http_rqst_start_line
http_rqst_start_line: required (one of 0, 1)
HTTP(Request) - start_line
사용안함:	0,	사용:	1

http_rqst_header: required (one of 0, 1)
http_rqst_header
HTTP(Request) - header
사용안함:	0,	사용:	1

http_rqst_header_raw
http_rqst_header_raw: required (one of 0, 1)
HTTP(Request) - header_raw
사용안함:	0,	사용:	1

http_rqst_body: required (one of 0, 1)
http_rqst_body
HTTP(Request) - body
사용안함:	0,	사용:	1

http_rqst_body_raw
http_rqst_body_raw: required (one of 0, 1)
HTTP(Request) - body_raw
사용안함:	0,	사용:	1

http_rqst_fname
http_rqst_fname: required (one of 0, 1)
HTTP(Request) - filename
사용안함:	0,	사용:	1

http_rqst_fbody
http_rqst_fbody: required (one of 0, 1)
HTTP(Request) - filebody
사용안함:	0,	사용:	1

http_rqst_ftype
http_rqst_ftype: required (one of 0, 1)
HTTP(Request) - filetype
사용안함:	0,	사용:	1

http_rqst_cntn_size
http_rqst_cntn_size: required (one of 0, 1)
HTTP(Request) - content size
사용안함:	0,	사용:	1

http_rqst_file_size
http_rqst_file_size: required (one of 0, 1)
HTTP(Request) - file size
사용안함:	0,	사용:	1

http_rsps_start_line: required (one of 0, 1)
http_rsps_start_line
HTTP(Response) - start_line
사용안함:	0,	사용:	1

http_rsps_header
http_rsps_header: required (one of 0, 1)
HTTP(Response) - header
사용안함:	0,	사용:	1

http_rsps_header_raw
http_rsps_header_raw: required (one of 0, 1)
HTTP(Response) - header_raw
사용안함:	0,	사용:	1

http_rsps_body
http_rsps_body: required (one of 0, 1)
HTTP(Response) - body
사용안함:	0,	사용:	1

http_rsps_body_raw
http_rsps_body_raw: required (one of 0, 1)
HTTP(Response) - body_raw
사용안함:	0,	사용:	1

http_rsps_fname
http_rsps_fname: required (one of 0, 1)
HTTP(Response) - filename
사용안함:	0,	사용:	1

http_rsps_fbody
http_rsps_fbody: required (one of 0, 1)
HTTP(Response) - filebody
사용안함:	0,	사용:	1

http_rsps_ftype
http_rsps_ftype: required (one of 0, 1)
HTTP(Response) - filetype
사용안함:	0,	사용:	1

http_rsps_cntn_size
http_rsps_cntn_size: required (one of 0, 1)
HTTP(Response) - content size
사용안함:	0,	사용:	1

http_rsps_file_size
http_rsps_file_size: required (one of 0, 1)
HTTP(Response) - file size
사용안함:	0,	사용:	1

ftp_rqst_cmd
ftp_rqst_cmd: required (one of 0, 1)
FTP(To Server) - command
사용안함:	0,	사용:	1

ftp_rqst_fname: required (one of 0, 1)
ftp_rqst_fname
FTP(To Server) - filename
사용안함:	0,	사용:	1

ftp_rqst_fbody
ftp_rqst_fbody: required (one of 0, 1)
FTP(To Server) - filebody
사용안함:	0,	사용:	1

ftp_rqst_ftype: required (one of 0, 1)
ftp_rqst_ftype
FTP(To Server) - filetype
사용안함:	0,	사용:	1

ftp_rqst_file_size
ftp_rqst_file_size: required (one of 0, 1)
FTP(To Server) - file size
사용안함:	0,	사용:	1

ftp_rsps_rsps
ftp_rsps_rsps: required (one of 0, 1)
FTP(From Server) - response
사용안함:	0,	사용:	1

ftp_rsps_fname
ftp_rsps_fname: required (one of 0, 1)
FTP(From Server) - filename
사용안함:	0,	사용:	1

ftp_rsps_fbody
ftp_rsps_fbody: required (one of 0, 1)
FTP(From Server) - filebody
사용안함:	0,	사용:	1

ftp_rsps_ftype
ftp_rsps_ftype: required (one of 0, 1)
FTP(From Server) - filetype
사용안함:	0,	사용:	1

ftp_rsps_file_size
ftp_rsps_file_size: required (one of 0, 1)
FTP(From Server) - file size
사용안함:	0,	사용:	1

dlp_prf_id
dlp_prf_id: required (integer)
DLP 프로파일 ID

dlp_filter_rule_id
dlp_filter_rule_id: required (integer)
DLP 필터 정책 ID

dlp_data_obj_info
dlp_data_obj_info: required (object)
DLP 데이터 객체

dlp_data_obj_id: required (integer)
dlp_data_obj_id
DLP 데이터 객체/그룹 ID

type
type: required (integer)
객체 타입
객체:	0,	그룹:	1

pre_def: required (integer)
pre_def
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

name: required (string)
name
데이터 객체 이름

descdesc: required (string)
설명

value_type: required (one of 1, 2, 3, 4)
value_type

객체 유형
문자열:	1,	정규식:	2,	크기:	3,	파일유형:	4

value1
value1: required (string)
객체 유형이  문자열(1),	정규식(2) 일 때 값
Base64 인코딩/디코딩 필요

value2
value2: required (string)
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

dlp_excpt_prf_info: required (object)
dlp_excpt_prf_info
DLP 예외 프로파일

dlp_excpt_prf_id
dlp_excpt_prf_id: required (integer)
예외 프로파일 ID

name
name: required (string)
예외 프로파일 이름

descdesc: required (string)
예외 프로파일 설명

useuse: required (integer)
사용여부
사용안함:	0,	사용:	1

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"dlp_prf_id":	1,
				"dlp_filter_rule_id":	1,
				"dlp_data_obj_info":	{
						"dlp_data_obj_id":	10001,
						"type":	0,
						"name":	"객체	이름",
						"desc":	"객체	설명",
						"use":	1
				},
				"dlp_excpt_prf_info":	{
						"dlp_excpt_prf_id":	1,
						"name":	"예외	프로파일	이름",
						"desc":	"예외	프로파일	설명",
						"use":	1
				},
				"name":	"DLP	프로파일	이름",
				"use":	1,
				"direct":	1,
				"action":	1,
				"log_use":	1,
				"dump_use":	1,
				"mail_use":	1,
				"desc":	"DLP	프로파일	설명",
				"smtp_use":	0,
				"pop3_use":	0,
				"imap_use":	0,
				"http_use":	0,
				"ftp_use":	0,
				"smtp_cmd":	0,
				"smtp_rsps":	0,
				"smtp_sndr":	0,
				"smtp_rcvr":	0,
				"smtp_sbjt":	0,
				"smtp_header":	0,
				"smtp_body":	0,
				"smtp_fname":	0,
				"smtp_fbody":	0,
				"smtp_ftype":	0,
				"smtp_cntn_size":	0,
				"smtp_attach_size":	0,
				"pop3_sndr":	0,
				"pop3_rcvr":	0,
				"pop3_sbjt":	0,
				"pop3_header":	0,
				"pop3_body":	0,
				"pop3_fname":	0,
				"pop3_fbody":	0,
				"pop3_ftype":	0,
				"pop3_cntn_size":	0,
				"pop3_attach_size":	0,
				"imap_sndr":	0,
				"imap_rcvr":	0,
				"imap_sbjt":	0,
				"imap_header":	0,
				"imap_body":	0,
				"imap_fname":	0,
				"imap_fbody":	0,
				"imap_ftype":	0,
				"imap_cntn_size":	0,
				"imap_attach_size":	0,
				"http_rqst_method":	0,
				"http_rqst_url":	0,
				"http_rqst_url_raw":	0,
				"http_rqst_host":	0,
				"http_rqst_start_line":	0,
				"http_rqst_header":	0,
				"http_rqst_header_raw":	0,
				"http_rqst_body":	0,
				"http_rqst_body_raw":	0,
				"http_rqst_fname":	0,
				"http_rqst_fbody":	0,

				"http_rqst_ftype":	0,
				"http_rqst_cntn_size":	0,
				"http_rqst_file_size":	0,
				"http_rsps_start_line":	0,
				"http_rsps_header":	0,
				"http_rsps_header_raw":	0,
				"http_rsps_body":	0,
				"http_rsps_body_raw":	0,
				"http_rsps_fname":	0,
				"http_rsps_fbody":	0,
				"http_rsps_ftype":	0,
				"http_rsps_cntn_size":	0,
				"http_rsps_file_size":	0,
				"ftp_rqst_cmd":	0,
				"ftp_rqst_fname":	0,
				"ftp_rqst_fbody":	0,
				"ftp_rqst_ftype":	0,
				"ftp_rqst_file_size":	0,
				"ftp_rsps_rsps":	0,
				"ftp_rsps_fname":	0,
				"ftp_rsps_fbody":	0,
				"ftp_rsps_ftype":	0,
				"ftp_rsps_file_size":	0
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

/dlp/profiles/{ppk}/filters

DLP 필터 정책를 추가한다.

Request

URI Parameters

ppkppk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

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
name: required (string - minLength: 1 - maxLength: 32)
name
정책 이름

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

direct: required (one of 1, 2, 3)
direct
방향
내부:1,	외부:	2,	양방향:	3

action
action: required (one of 0, 1)
유형
탐지:	0,	차단:	1

log_use
log_use: required (one of 0, 1)
로그 사용 여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1)
덤프 사용 여부
사용안함:	0,	사용:	1

mail_use
mail_use: required (one of 0, 1)
메일 사용 여부
사용안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

smtp_use
smtp_use: required (one of 0, 1)
SMTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

pop3_use: required (one of 0, 1)
pop3_use
POP3 프로토콜 사용 여부
사용안함:	0,	사용:	1

imap_use
imap_use: required (one of 0, 1)
IMAP 프로토콜 사용 여부
사용안함:	0,	사용:	1

http_use
http_use: required (one of 0, 1)
HTTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

ftp_use
ftp_use: required (one of 0, 1)
FTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

smtp_cmd
smtp_cmd: required (one of 0, 1)
SMTP - command
사용안함:	0,	사용:	1

smtp_rsps: required (one of 0, 1)
smtp_rsps
SMTP - response
사용안함:	0,	사용:	1

smtp_sndr
smtp_sndr: required (one of 0, 1)
SMTP - sender
사용안함:	0,	사용:	1

smtp_rcvr
smtp_rcvr: required (one of 0, 1)
SMTP - receiver
사용안함:	0,	사용:	1

smtp_sbjt
smtp_sbjt: required (one of 0, 1)
SMTP - subject
사용안함:	0,	사용:	1

smtp_header
smtp_header: required (one of 0, 1)
SMTP - header
사용안함:	0,	사용:	1

smtp_body: required (one of 0, 1)
smtp_body
SMTP - body
사용안함:	0,	사용:	1

smtp_fname
smtp_fname: required (one of 0, 1)
SMTP - filename
사용안함:	0,	사용:	1

smtp_fbody
smtp_fbody: required (one of 0, 1)
SMTP - filebody
사용안함:	0,	사용:	1

smtp_ftype: required (one of 0, 1)
smtp_ftype

SMTP - filetype
사용안함:	0,	사용:	1

smtp_cntn_size
smtp_cntn_size: required (one of 0, 1)
SMTP - content size
사용안함:	0,	사용:	1

smtp_attach_size
smtp_attach_size: required (one of 0, 1)
SMTP - attachment size
사용안함:	0,	사용:	1

pop3_sndr: required (one of 0, 1)
pop3_sndr
POP - sender
사용안함:	0,	사용:	1

pop3_rcvr
pop3_rcvr: required (one of 0, 1)
POP - receiver
사용안함:	0,	사용:	1

pop3_sbjt
pop3_sbjt: required (one of 0, 1)
POP - subject
사용안함:	0,	사용:	1

pop3_header
pop3_header: required (one of 0, 1)
POP - header
사용안함:	0,	사용:	1

pop3_body
pop3_body: required (one of 0, 1)
POP - body
사용안함:	0,	사용:	1

pop3_fname: required (one of 0, 1)
pop3_fname
POP - filename
사용안함:	0,	사용:	1

pop3_fbody
pop3_fbody: required (one of 0, 1)
POP - filebody
사용안함:	0,	사용:	1

pop3_ftype
pop3_ftype: required (one of 0, 1)
POP - filetype
사용안함:	0,	사용:	1

pop3_cntn_size
pop3_cntn_size: required (one of 0, 1)
POP - content size
사용안함:	0,	사용:	1

pop3_attach_size
pop3_attach_size: required (one of 0, 1)
POP - attachment size
사용안함:	0,	사용:	1

imap_sndr: required (one of 0, 1)
imap_sndr
IMAP - sender
사용안함:	0,	사용:	1

imap_rcvr
imap_rcvr: required (one of 0, 1)
IMAP - receiver
사용안함:	0,	사용:	1

imap_sbjt
imap_sbjt: required (one of 0, 1)
IMAP - subject
사용안함:	0,	사용:	1

imap_header
imap_header: required (one of 0, 1)
IMAP - header
사용안함:	0,	사용:	1

imap_body
imap_body: required (one of 0, 1)
IMAP - body
사용안함:	0,	사용:	1

imap_fname: required (one of 0, 1)
imap_fname
IMAP - filename
사용안함:	0,	사용:	1

imap_fbody
imap_fbody: required (one of 0, 1)
IMAP - filebody
사용안함:	0,	사용:	1

imap_ftype
imap_ftype: required (one of 0, 1)
IMAP - filetype
사용안함:	0,	사용:	1

imap_cntn_size
imap_cntn_size: required (one of 0, 1)
IMAP - content size
사용안함:	0,	사용:	1

imap_attach_size
imap_attach_size: required (one of 0, 1)
IMAP - attachment size
사용안함:	0,	사용:	1

http_rqst_method
http_rqst_method: required (one of 0, 1)
HTTP(Request) - method
사용안함:	0,	사용:	1

http_rqst_url
http_rqst_url: required (one of 0, 1)
HTTP(Request) - url
사용안함:	0,	사용:	1

http_rqst_url_raw
http_rqst_url_raw: required (one of 0, 1)
HTTP(Request) - url_raw
사용안함:	0,	사용:	1

http_rqst_host
http_rqst_host: required (one of 0, 1)
HTTP(Request) - host
사용안함:	0,	사용:	1

http_rqst_start_line
http_rqst_start_line: required (one of 0, 1)
HTTP(Request) - start_line
사용안함:	0,	사용:	1

http_rqst_header: required (one of 0, 1)
http_rqst_header

HTTP(Request) - header
사용안함:	0,	사용:	1

http_rqst_header_raw
http_rqst_header_raw: required (one of 0, 1)
HTTP(Request) - header_raw
사용안함:	0,	사용:	1

http_rqst_body
http_rqst_body: required (one of 0, 1)
HTTP(Request) - body
사용안함:	0,	사용:	1

http_rqst_body_raw: required (one of 0, 1)
http_rqst_body_raw
HTTP(Request) - body_raw
사용안함:	0,	사용:	1

http_rqst_fname
http_rqst_fname: required (one of 0, 1)
HTTP(Request) - filename
사용안함:	0,	사용:	1

http_rqst_fbody
http_rqst_fbody: required (one of 0, 1)
HTTP(Request) - filebody
사용안함:	0,	사용:	1

http_rqst_ftype
http_rqst_ftype: required (one of 0, 1)
HTTP(Request) - filetype
사용안함:	0,	사용:	1

http_rqst_cntn_size
http_rqst_cntn_size: required (one of 0, 1)
HTTP(Request) - content size
사용안함:	0,	사용:	1

http_rqst_file_size: required (one of 0, 1)
http_rqst_file_size
HTTP(Request) - file size
사용안함:	0,	사용:	1

http_rsps_start_line
http_rsps_start_line: required (one of 0, 1)
HTTP(Response) - start_line
사용안함:	0,	사용:	1

http_rsps_header
http_rsps_header: required (one of 0, 1)
HTTP(Response) - header
사용안함:	0,	사용:	1

http_rsps_header_raw
http_rsps_header_raw: required (one of 0, 1)
HTTP(Response) - header_raw
사용안함:	0,	사용:	1

http_rsps_body
http_rsps_body: required (one of 0, 1)
HTTP(Response) - body
사용안함:	0,	사용:	1

http_rsps_body_raw: required (one of 0, 1)
http_rsps_body_raw
HTTP(Response) - body_raw
사용안함:	0,	사용:	1

http_rsps_fname
http_rsps_fname: required (one of 0, 1)
HTTP(Response) - filename
사용안함:	0,	사용:	1

http_rsps_fbody
http_rsps_fbody: required (one of 0, 1)
HTTP(Response) - filebody
사용안함:	0,	사용:	1

http_rsps_ftype
http_rsps_ftype: required (one of 0, 1)
HTTP(Response) - filetype
사용안함:	0,	사용:	1

http_rsps_cntn_size
http_rsps_cntn_size: required (one of 0, 1)
HTTP(Response) - content size
사용안함:	0,	사용:	1

http_rsps_file_size: required (one of 0, 1)
http_rsps_file_size
HTTP(Response) - file size
사용안함:	0,	사용:	1

ftp_rqst_cmd
ftp_rqst_cmd: required (one of 0, 1)
FTP(To Server) - command
사용안함:	0,	사용:	1

ftp_rqst_fname
ftp_rqst_fname: required (one of 0, 1)
FTP(To Server) - filename
사용안함:	0,	사용:	1

ftp_rqst_fbody
ftp_rqst_fbody: required (one of 0, 1)
FTP(To Server) - filebody
사용안함:	0,	사용:	1

ftp_rqst_ftype
ftp_rqst_ftype: required (one of 0, 1)
FTP(To Server) - filetype
사용안함:	0,	사용:	1

ftp_rqst_file_size
ftp_rqst_file_size: required (one of 0, 1)
FTP(To Server) - file size
사용안함:	0,	사용:	1

ftp_rsps_rsps
ftp_rsps_rsps: required (one of 0, 1)
FTP(From Server) - response
사용안함:	0,	사용:	1

ftp_rsps_fname
ftp_rsps_fname: required (one of 0, 1)
FTP(From Server) - filename
사용안함:	0,	사용:	1

ftp_rsps_fbody
ftp_rsps_fbody: required (one of 0, 1)
FTP(From Server) - filebody
사용안함:	0,	사용:	1

ftp_rsps_ftype
ftp_rsps_ftype: required (one of 0, 1)
FTP(From Server) - filetype
사용안함:	0,	사용:	1

ftp_rsps_file_size: required (one of 0, 1)
ftp_rsps_file_size

FTP(From Server) - file size
사용안함:	0,	사용:	1

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체 ID

dlp_excpt_prf_id
dlp_excpt_prf_id: required (integer)
DLP 예외 프로파일 ID

Example:
Example

{
		"dlp_data_obj_id":	10001,
		"dlp_excpt_prf_id":	1,
		"name":	"NEW	프로파일	이름",
		"use":	1,
		"direct":	1,
		"action":	1,
		"log_use":	1,
		"dump_use":	1,
		"mail_use":	1,
		"desc":	"New	DLP	프로파일	설명",
		"smtp_use":	0,
		"pop3_use":	0,
		"imap_use":	0,
		"http_use":	0,
		"ftp_use":	0,
		"smtp_cmd":	0,
		"smtp_rsps":	0,
		"smtp_sndr":	0,
		"smtp_rcvr":	0,
		"smtp_sbjt":	0,
		"smtp_header":	0,
		"smtp_body":	0,
		"smtp_fname":	0,
		"smtp_fbody":	0,
		"smtp_ftype":	0,
		"smtp_cntn_size":	0,
		"smtp_attach_size":	0,
		"pop3_sndr":	0,
		"pop3_rcvr":	0,
		"pop3_sbjt":	0,
		"pop3_header":	0,
		"pop3_body":	0,
		"pop3_fname":	0,
		"pop3_fbody":	0,
		"pop3_ftype":	0,
		"pop3_cntn_size":	0,
		"pop3_attach_size":	0,
		"imap_sndr":	0,
		"imap_rcvr":	0,
		"imap_sbjt":	0,
		"imap_header":	0,
		"imap_body":	0,
		"imap_fname":	0,
		"imap_fbody":	0,
		"imap_ftype":	0,
		"imap_cntn_size":	0,
		"imap_attach_size":	0,
		"http_rqst_method":	0,
		"http_rqst_url":	0,
		"http_rqst_url_raw":	0,
		"http_rqst_host":	0,
		"http_rqst_start_line":	0,
		"http_rqst_header":	0,
		"http_rqst_header_raw":	0,
		"http_rqst_body":	0,
		"http_rqst_body_raw":	0,
		"http_rqst_fname":	0,
		"http_rqst_fbody":	0,
		"http_rqst_ftype":	0,
		"http_rqst_cntn_size":	0,
		"http_rqst_file_size":	0,
		"http_rsps_start_line":	0,
		"http_rsps_header":	0,
		"http_rsps_header_raw":	0,
		"http_rsps_body":	0,
		"http_rsps_body_raw":	0,
		"http_rsps_fname":	0,
		"http_rsps_fbody":	0,
		"http_rsps_ftype":	0,
		"http_rsps_cntn_size":	0,
		"http_rsps_file_size":	0,
		"ftp_rqst_cmd":	0,
		"ftp_rqst_fname":	0,
		"ftp_rqst_fbody":	0,
		"ftp_rqst_ftype":	0,
		"ftp_rqst_file_size":	0,
		"ftp_rsps_rsps":	0,
		"ftp_rsps_fname":	0,
		"ftp_rsps_fbody":	0,
		"ftp_rsps_ftype":	0,
		"ftp_rsps_file_size":	0
}

Response

HTTP status code 200

DLP 필터 정책 추가 성공

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

name: required (string - minLength: 1 - maxLength: 32)
name
정책 이름

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

direct: required (one of 1, 2, 3)
direct
방향
내부:1,	외부:	2,	양방향:	3

action
action: required (one of 0, 1)
유형
탐지:	0,	차단:	1

log_use
log_use: required (one of 0, 1)
로그 사용 여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1)
덤프 사용 여부
사용안함:	0,	사용:	1

mail_use
mail_use: required (one of 0, 1)
메일 사용 여부
사용안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

smtp_use
smtp_use: required (one of 0, 1)
SMTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

pop3_use: required (one of 0, 1)
pop3_use
POP3 프로토콜 사용 여부
사용안함:	0,	사용:	1

imap_use
imap_use: required (one of 0, 1)
IMAP 프로토콜 사용 여부
사용안함:	0,	사용:	1

http_use
http_use: required (one of 0, 1)
HTTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

ftp_use
ftp_use: required (one of 0, 1)
FTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

smtp_cmd
smtp_cmd: required (one of 0, 1)
SMTP - command
사용안함:	0,	사용:	1

smtp_rsps: required (one of 0, 1)
smtp_rsps
SMTP - response
사용안함:	0,	사용:	1

smtp_sndr
smtp_sndr: required (one of 0, 1)
SMTP - sender
사용안함:	0,	사용:	1

smtp_rcvr
smtp_rcvr: required (one of 0, 1)
SMTP - receiver
사용안함:	0,	사용:	1

smtp_sbjt
smtp_sbjt: required (one of 0, 1)
SMTP - subject
사용안함:	0,	사용:	1

smtp_header
smtp_header: required (one of 0, 1)
SMTP - header
사용안함:	0,	사용:	1

smtp_body
smtp_body: required (one of 0, 1)
SMTP - body
사용안함:	0,	사용:	1

smtp_fname
smtp_fname: required (one of 0, 1)
SMTP - filename
사용안함:	0,	사용:	1

smtp_fbody: required (one of 0, 1)
smtp_fbody
SMTP - filebody
사용안함:	0,	사용:	1

smtp_ftype
smtp_ftype: required (one of 0, 1)
SMTP - filetype
사용안함:	0,	사용:	1

smtp_cntn_size
smtp_cntn_size: required (one of 0, 1)
SMTP - content size
사용안함:	0,	사용:	1

smtp_attach_size: required (one of 0, 1)
smtp_attach_size

SMTP - attachment size
사용안함:	0,	사용:	1

pop3_sndr
pop3_sndr: required (one of 0, 1)
POP - sender
사용안함:	0,	사용:	1

pop3_rcvr
pop3_rcvr: required (one of 0, 1)
POP - receiver
사용안함:	0,	사용:	1

pop3_sbjt: required (one of 0, 1)
pop3_sbjt
POP - subject
사용안함:	0,	사용:	1

pop3_header
pop3_header: required (one of 0, 1)
POP - header
사용안함:	0,	사용:	1

pop3_body
pop3_body: required (one of 0, 1)
POP - body
사용안함:	0,	사용:	1

pop3_fname
pop3_fname: required (one of 0, 1)
POP - filename
사용안함:	0,	사용:	1

pop3_fbody
pop3_fbody: required (one of 0, 1)
POP - filebody
사용안함:	0,	사용:	1

pop3_ftype: required (one of 0, 1)
pop3_ftype
POP - filetype
사용안함:	0,	사용:	1

pop3_cntn_size
pop3_cntn_size: required (one of 0, 1)
POP - content size
사용안함:	0,	사용:	1

pop3_attach_size
pop3_attach_size: required (one of 0, 1)
POP - attachment size
사용안함:	0,	사용:	1

imap_sndr
imap_sndr: required (one of 0, 1)
IMAP - sender
사용안함:	0,	사용:	1

imap_rcvr
imap_rcvr: required (one of 0, 1)
IMAP - receiver
사용안함:	0,	사용:	1

imap_sbjt: required (one of 0, 1)
imap_sbjt
IMAP - subject
사용안함:	0,	사용:	1

imap_header
imap_header: required (one of 0, 1)
IMAP - header
사용안함:	0,	사용:	1

imap_body
imap_body: required (one of 0, 1)
IMAP - body
사용안함:	0,	사용:	1

imap_fname
imap_fname: required (one of 0, 1)
IMAP - filename
사용안함:	0,	사용:	1

imap_fbody
imap_fbody: required (one of 0, 1)
IMAP - filebody
사용안함:	0,	사용:	1

imap_ftype: required (one of 0, 1)
imap_ftype
IMAP - filetype
사용안함:	0,	사용:	1

imap_cntn_size
imap_cntn_size: required (one of 0, 1)
IMAP - content size
사용안함:	0,	사용:	1

imap_attach_size
imap_attach_size: required (one of 0, 1)
IMAP - attachment size
사용안함:	0,	사용:	1

http_rqst_method
http_rqst_method: required (one of 0, 1)
HTTP(Request) - method
사용안함:	0,	사용:	1

http_rqst_url
http_rqst_url: required (one of 0, 1)
HTTP(Request) - url
사용안함:	0,	사용:	1

http_rqst_url_raw
http_rqst_url_raw: required (one of 0, 1)
HTTP(Request) - url_raw
사용안함:	0,	사용:	1

http_rqst_host
http_rqst_host: required (one of 0, 1)
HTTP(Request) - host
사용안함:	0,	사용:	1

http_rqst_start_line
http_rqst_start_line: required (one of 0, 1)
HTTP(Request) - start_line
사용안함:	0,	사용:	1

http_rqst_header
http_rqst_header: required (one of 0, 1)
HTTP(Request) - header
사용안함:	0,	사용:	1

http_rqst_header_raw
http_rqst_header_raw: required (one of 0, 1)
HTTP(Request) - header_raw
사용안함:	0,	사용:	1

http_rqst_body: required (one of 0, 1)
http_rqst_body

HTTP(Request) - body
사용안함:	0,	사용:	1

http_rqst_body_raw
http_rqst_body_raw: required (one of 0, 1)
HTTP(Request) - body_raw
사용안함:	0,	사용:	1

http_rqst_fname
http_rqst_fname: required (one of 0, 1)
HTTP(Request) - filename
사용안함:	0,	사용:	1

http_rqst_fbody: required (one of 0, 1)
http_rqst_fbody
HTTP(Request) - filebody
사용안함:	0,	사용:	1

http_rqst_ftype
http_rqst_ftype: required (one of 0, 1)
HTTP(Request) - filetype
사용안함:	0,	사용:	1

http_rqst_cntn_size
http_rqst_cntn_size: required (one of 0, 1)
HTTP(Request) - content size
사용안함:	0,	사용:	1

http_rqst_file_size
http_rqst_file_size: required (one of 0, 1)
HTTP(Request) - file size
사용안함:	0,	사용:	1

http_rsps_start_line
http_rsps_start_line: required (one of 0, 1)
HTTP(Response) - start_line
사용안함:	0,	사용:	1

http_rsps_header: required (one of 0, 1)
http_rsps_header
HTTP(Response) - header
사용안함:	0,	사용:	1

http_rsps_header_raw
http_rsps_header_raw: required (one of 0, 1)
HTTP(Response) - header_raw
사용안함:	0,	사용:	1

http_rsps_body
http_rsps_body: required (one of 0, 1)
HTTP(Response) - body
사용안함:	0,	사용:	1

http_rsps_body_raw
http_rsps_body_raw: required (one of 0, 1)
HTTP(Response) - body_raw
사용안함:	0,	사용:	1

http_rsps_fname
http_rsps_fname: required (one of 0, 1)
HTTP(Response) - filename
사용안함:	0,	사용:	1

http_rsps_fbody: required (one of 0, 1)
http_rsps_fbody
HTTP(Response) - filebody
사용안함:	0,	사용:	1

http_rsps_ftype
http_rsps_ftype: required (one of 0, 1)
HTTP(Response) - filetype
사용안함:	0,	사용:	1

http_rsps_cntn_size
http_rsps_cntn_size: required (one of 0, 1)
HTTP(Response) - content size
사용안함:	0,	사용:	1

http_rsps_file_size
http_rsps_file_size: required (one of 0, 1)
HTTP(Response) - file size
사용안함:	0,	사용:	1

ftp_rqst_cmd
ftp_rqst_cmd: required (one of 0, 1)
FTP(To Server) - command
사용안함:	0,	사용:	1

ftp_rqst_fname: required (one of 0, 1)
ftp_rqst_fname
FTP(To Server) - filename
사용안함:	0,	사용:	1

ftp_rqst_fbody
ftp_rqst_fbody: required (one of 0, 1)
FTP(To Server) - filebody
사용안함:	0,	사용:	1

ftp_rqst_ftype
ftp_rqst_ftype: required (one of 0, 1)
FTP(To Server) - filetype
사용안함:	0,	사용:	1

ftp_rqst_file_size
ftp_rqst_file_size: required (one of 0, 1)
FTP(To Server) - file size
사용안함:	0,	사용:	1

ftp_rsps_rsps
ftp_rsps_rsps: required (one of 0, 1)
FTP(From Server) - response
사용안함:	0,	사용:	1

ftp_rsps_fname
ftp_rsps_fname: required (one of 0, 1)
FTP(From Server) - filename
사용안함:	0,	사용:	1

ftp_rsps_fbody
ftp_rsps_fbody: required (one of 0, 1)
FTP(From Server) - filebody
사용안함:	0,	사용:	1

ftp_rsps_ftype
ftp_rsps_ftype: required (one of 0, 1)
FTP(From Server) - filetype
사용안함:	0,	사용:	1

ftp_rsps_file_size
ftp_rsps_file_size: required (one of 0, 1)
FTP(From Server) - file size
사용안함:	0,	사용:	1

dlp_prf_id
dlp_prf_id: required (integer)
DLP 프로파일 ID

dlp_filter_rule_id
dlp_filter_rule_id: required (integer)
DLP 필터 정책 ID

dlp_data_obj_info
dlp_data_obj_info: required (object)
DLP 데이터 객체

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체/그룹 ID

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

name: required (string)
name
데이터 객체 이름

descdesc: required (string)
설명

value_type
value_type: required (one of 1, 2, 3, 4)
객체 유형
문자열:	1,	정규식:	2,	크기:	3,	파일유형:	4

value1
value1: required (string)
객체 유형이  문자열(1),	정규식(2) 일 때 값
Base64 인코딩/디코딩 필요

value2: required (string)
value2
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

dlp_excpt_prf_info
dlp_excpt_prf_info: required (object)
DLP 예외 프로파일

dlp_excpt_prf_id
dlp_excpt_prf_id: required (integer)
예외 프로파일 ID

name
name: required (string)
예외 프로파일 이름

descdesc: required (string)
예외 프로파일 설명

useuse: required (integer)
사용여부
사용안함:	0,	사용:	1

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_prf_id":	1,
				"dlp_filter_rule_id":	2,
				"dlp_data_obj_info":	{
						"dlp_data_obj_id":	10001,
						"type":	0,
						"name":	"객체	이름",
						"desc":	"객체	설명",
						"use":	1
				},
				"dlp_excpt_prf_info":	{
						"dlp_excpt_prf_id":	1,
						"name":	"예외	프로파일	이름",
						"desc":	"예외	프로파일	설명",
						"use":	1
				},
				"name":	"NEW	프로파일	이름",
				"use":	1,
				"direct":	1,
				"action":	1,
				"log_use":	1,
				"dump_use":	1,
				"mail_use":	1,
				"desc":	"NEW	DLP	프로파일	설명",
				"smtp_use":	0,
				"pop3_use":	0,
				"imap_use":	0,
				"http_use":	0,
				"ftp_use":	0,
				"smtp_cmd":	0,
				"smtp_rsps":	0,
				"smtp_sndr":	0,
				"smtp_rcvr":	0,
				"smtp_sbjt":	0,
				"smtp_header":	0,
				"smtp_body":	0,
				"smtp_fname":	0,
				"smtp_fbody":	0,
				"smtp_ftype":	0,
				"smtp_cntn_size":	0,
				"smtp_attach_size":	0,
				"pop3_sndr":	0,
				"pop3_rcvr":	0,
				"pop3_sbjt":	0,
				"pop3_header":	0,
				"pop3_body":	0,
				"pop3_fname":	0,
				"pop3_fbody":	0,
				"pop3_ftype":	0,

				"pop3_cntn_size":	0,
				"pop3_attach_size":	0,
				"imap_sndr":	0,
				"imap_rcvr":	0,
				"imap_sbjt":	0,
				"imap_header":	0,
				"imap_body":	0,
				"imap_fname":	0,
				"imap_fbody":	0,
				"imap_ftype":	0,
				"imap_cntn_size":	0,
				"imap_attach_size":	0,
				"http_rqst_method":	0,
				"http_rqst_url":	0,
				"http_rqst_url_raw":	0,
				"http_rqst_host":	0,
				"http_rqst_start_line":	0,
				"http_rqst_header":	0,
				"http_rqst_header_raw":	0,
				"http_rqst_body":	0,
				"http_rqst_body_raw":	0,
				"http_rqst_fname":	0,
				"http_rqst_fbody":	0,
				"http_rqst_ftype":	0,
				"http_rqst_cntn_size":	0,
				"http_rqst_file_size":	0,
				"http_rsps_start_line":	0,
				"http_rsps_header":	0,
				"http_rsps_header_raw":	0,
				"http_rsps_body":	0,
				"http_rsps_body_raw":	0,
				"http_rsps_fname":	0,
				"http_rsps_fbody":	0,
				"http_rsps_ftype":	0,
				"http_rsps_cntn_size":	0,
				"http_rsps_file_size":	0,
				"ftp_rqst_cmd":	0,
				"ftp_rqst_fname":	0,
				"ftp_rqst_fbody":	0,
				"ftp_rqst_ftype":	0,
				"ftp_rqst_file_size":	0,
				"ftp_rsps_rsps":	0,
				"ftp_rsps_fname":	0,
				"ftp_rsps_fbody":	0,
				"ftp_rsps_ftype":	0,
				"ftp_rsps_file_size":	0
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

message: required (string)
message
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

/dlp/profiles/{ppk}/filters

DLP 필터 정책 목록을 (일괄)수정한다.

Request

URI Parameters

ppkppk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

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
				{"dlp_filter_rule_id":	1,	"use":	0},
				{"dlp_filter_rule_id":	2,	"use":	0}
		]
}

Response

HTTP status code 200

DLP 필터 정책 목록 수정 성공

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

DELETE

/dlp/profiles/{ppk}/filters

DLP 필터 정책 목록을 (일괄)삭제한다.

Request

URI Parameters

ppkppk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

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
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"dlp_filter_rule_id":	1},
				{"dlp_filter_rule_id":	2}
		]
}

Response

HTTP status code 200

DLP 필터 정책 목록 삭제 성공

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

/dlp/profiles/{ppk}/filters/{pk}

DLP 필터 정책을(를) 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

pkpk: required (integer)
정책 ID( dlp_filter_rule_id )

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

DLP 필터 정책 조회 성공

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
정책 이름

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

direct
direct: required (one of 1, 2, 3)
방향
내부:1,	외부:	2,	양방향:	3

action
action: required (one of 0, 1)
유형
탐지:	0,	차단:	1

log_use: required (one of 0, 1)
log_use
로그 사용 여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1)
덤프 사용 여부
사용안함:	0,	사용:	1

mail_use
mail_use: required (one of 0, 1)
메일 사용 여부
사용안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

smtp_use
smtp_use: required (one of 0, 1)
SMTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

pop3_use: required (one of 0, 1)
pop3_use
POP3 프로토콜 사용 여부
사용안함:	0,	사용:	1

imap_use
imap_use: required (one of 0, 1)
IMAP 프로토콜 사용 여부
사용안함:	0,	사용:	1

http_use
http_use: required (one of 0, 1)
HTTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

ftp_use
ftp_use: required (one of 0, 1)
FTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

smtp_cmd
smtp_cmd: required (one of 0, 1)
SMTP - command
사용안함:	0,	사용:	1

smtp_rsps: required (one of 0, 1)
smtp_rsps
SMTP - response
사용안함:	0,	사용:	1

smtp_sndr
smtp_sndr: required (one of 0, 1)
SMTP - sender
사용안함:	0,	사용:	1

smtp_rcvr
smtp_rcvr: required (one of 0, 1)
SMTP - receiver
사용안함:	0,	사용:	1

smtp_sbjt
smtp_sbjt: required (one of 0, 1)
SMTP - subject
사용안함:	0,	사용:	1

smtp_header
smtp_header: required (one of 0, 1)
SMTP - header
사용안함:	0,	사용:	1

smtp_body: required (one of 0, 1)
smtp_body
SMTP - body
사용안함:	0,	사용:	1

smtp_fname
smtp_fname: required (one of 0, 1)
SMTP - filename
사용안함:	0,	사용:	1

smtp_fbody
smtp_fbody: required (one of 0, 1)
SMTP - filebody
사용안함:	0,	사용:	1

smtp_ftype
smtp_ftype: required (one of 0, 1)
SMTP - filetype
사용안함:	0,	사용:	1

smtp_cntn_size
smtp_cntn_size: required (one of 0, 1)
SMTP - content size
사용안함:	0,	사용:	1

smtp_attach_size: required (one of 0, 1)
smtp_attach_size
SMTP - attachment size
사용안함:	0,	사용:	1

pop3_sndr
pop3_sndr: required (one of 0, 1)
POP - sender
사용안함:	0,	사용:	1

pop3_rcvr
pop3_rcvr: required (one of 0, 1)
POP - receiver
사용안함:	0,	사용:	1

pop3_sbjt
pop3_sbjt: required (one of 0, 1)
POP - subject
사용안함:	0,	사용:	1

pop3_header
pop3_header: required (one of 0, 1)
POP - header
사용안함:	0,	사용:	1

pop3_body
pop3_body: required (one of 0, 1)
POP - body
사용안함:	0,	사용:	1

pop3_fname
pop3_fname: required (one of 0, 1)
POP - filename
사용안함:	0,	사용:	1

pop3_fbody
pop3_fbody: required (one of 0, 1)
POP - filebody
사용안함:	0,	사용:	1

pop3_ftype
pop3_ftype: required (one of 0, 1)
POP - filetype
사용안함:	0,	사용:	1

pop3_cntn_size
pop3_cntn_size: required (one of 0, 1)
POP - content size
사용안함:	0,	사용:	1

pop3_attach_size: required (one of 0, 1)
pop3_attach_size

POP - attachment size
사용안함:	0,	사용:	1

imap_sndr
imap_sndr: required (one of 0, 1)
IMAP - sender
사용안함:	0,	사용:	1

imap_rcvr
imap_rcvr: required (one of 0, 1)
IMAP - receiver
사용안함:	0,	사용:	1

imap_sbjt: required (one of 0, 1)
imap_sbjt
IMAP - subject
사용안함:	0,	사용:	1

imap_header
imap_header: required (one of 0, 1)
IMAP - header
사용안함:	0,	사용:	1

imap_body
imap_body: required (one of 0, 1)
IMAP - body
사용안함:	0,	사용:	1

imap_fname
imap_fname: required (one of 0, 1)
IMAP - filename
사용안함:	0,	사용:	1

imap_fbody
imap_fbody: required (one of 0, 1)
IMAP - filebody
사용안함:	0,	사용:	1

imap_ftype: required (one of 0, 1)
imap_ftype
IMAP - filetype
사용안함:	0,	사용:	1

imap_cntn_size
imap_cntn_size: required (one of 0, 1)
IMAP - content size
사용안함:	0,	사용:	1

imap_attach_size
imap_attach_size: required (one of 0, 1)
IMAP - attachment size
사용안함:	0,	사용:	1

http_rqst_method
http_rqst_method: required (one of 0, 1)
HTTP(Request) - method
사용안함:	0,	사용:	1

http_rqst_url
http_rqst_url: required (one of 0, 1)
HTTP(Request) - url
사용안함:	0,	사용:	1

http_rqst_url_raw: required (one of 0, 1)
http_rqst_url_raw
HTTP(Request) - url_raw
사용안함:	0,	사용:	1

http_rqst_host
http_rqst_host: required (one of 0, 1)
HTTP(Request) - host
사용안함:	0,	사용:	1

http_rqst_start_line
http_rqst_start_line: required (one of 0, 1)
HTTP(Request) - start_line
사용안함:	0,	사용:	1

http_rqst_header
http_rqst_header: required (one of 0, 1)
HTTP(Request) - header
사용안함:	0,	사용:	1

http_rqst_header_raw
http_rqst_header_raw: required (one of 0, 1)
HTTP(Request) - header_raw
사용안함:	0,	사용:	1

http_rqst_body: required (one of 0, 1)
http_rqst_body
HTTP(Request) - body
사용안함:	0,	사용:	1

http_rqst_body_raw
http_rqst_body_raw: required (one of 0, 1)
HTTP(Request) - body_raw
사용안함:	0,	사용:	1

http_rqst_fname
http_rqst_fname: required (one of 0, 1)
HTTP(Request) - filename
사용안함:	0,	사용:	1

http_rqst_fbody
http_rqst_fbody: required (one of 0, 1)
HTTP(Request) - filebody
사용안함:	0,	사용:	1

http_rqst_ftype
http_rqst_ftype: required (one of 0, 1)
HTTP(Request) - filetype
사용안함:	0,	사용:	1

http_rqst_cntn_size
http_rqst_cntn_size: required (one of 0, 1)
HTTP(Request) - content size
사용안함:	0,	사용:	1

http_rqst_file_size
http_rqst_file_size: required (one of 0, 1)
HTTP(Request) - file size
사용안함:	0,	사용:	1

http_rsps_start_line
http_rsps_start_line: required (one of 0, 1)
HTTP(Response) - start_line
사용안함:	0,	사용:	1

http_rsps_header
http_rsps_header: required (one of 0, 1)
HTTP(Response) - header
사용안함:	0,	사용:	1

http_rsps_header_raw
http_rsps_header_raw: required (one of 0, 1)
HTTP(Response) - header_raw
사용안함:	0,	사용:	1

http_rsps_body: required (one of 0, 1)
http_rsps_body

HTTP(Response) - body
사용안함:	0,	사용:	1

http_rsps_body_raw
http_rsps_body_raw: required (one of 0, 1)
HTTP(Response) - body_raw
사용안함:	0,	사용:	1

http_rsps_fname
http_rsps_fname: required (one of 0, 1)
HTTP(Response) - filename
사용안함:	0,	사용:	1

http_rsps_fbody: required (one of 0, 1)
http_rsps_fbody
HTTP(Response) - filebody
사용안함:	0,	사용:	1

http_rsps_ftype
http_rsps_ftype: required (one of 0, 1)
HTTP(Response) - filetype
사용안함:	0,	사용:	1

http_rsps_cntn_size
http_rsps_cntn_size: required (one of 0, 1)
HTTP(Response) - content size
사용안함:	0,	사용:	1

http_rsps_file_size
http_rsps_file_size: required (one of 0, 1)
HTTP(Response) - file size
사용안함:	0,	사용:	1

ftp_rqst_cmd
ftp_rqst_cmd: required (one of 0, 1)
FTP(To Server) - command
사용안함:	0,	사용:	1

ftp_rqst_fname: required (one of 0, 1)
ftp_rqst_fname
FTP(To Server) - filename
사용안함:	0,	사용:	1

ftp_rqst_fbody
ftp_rqst_fbody: required (one of 0, 1)
FTP(To Server) - filebody
사용안함:	0,	사용:	1

ftp_rqst_ftype
ftp_rqst_ftype: required (one of 0, 1)
FTP(To Server) - filetype
사용안함:	0,	사용:	1

ftp_rqst_file_size
ftp_rqst_file_size: required (one of 0, 1)
FTP(To Server) - file size
사용안함:	0,	사용:	1

ftp_rsps_rsps
ftp_rsps_rsps: required (one of 0, 1)
FTP(From Server) - response
사용안함:	0,	사용:	1

ftp_rsps_fname: required (one of 0, 1)
ftp_rsps_fname
FTP(From Server) - filename
사용안함:	0,	사용:	1

ftp_rsps_fbody
ftp_rsps_fbody: required (one of 0, 1)
FTP(From Server) - filebody
사용안함:	0,	사용:	1

ftp_rsps_ftype
ftp_rsps_ftype: required (one of 0, 1)
FTP(From Server) - filetype
사용안함:	0,	사용:	1

ftp_rsps_file_size
ftp_rsps_file_size: required (one of 0, 1)
FTP(From Server) - file size
사용안함:	0,	사용:	1

dlp_prf_id
dlp_prf_id: required (integer)
DLP 프로파일 ID

dlp_filter_rule_id
dlp_filter_rule_id: required (integer)
DLP 필터 정책 ID

dlp_data_obj_info
dlp_data_obj_info: required (object)
DLP 데이터 객체

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체/그룹 ID

type: required (integer)
type
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
객체 유형이  문자열(1),	정규식(2) 일 때 값
Base64 인코딩/디코딩 필요

value2
value2: required (string)
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

dlp_excpt_prf_info
dlp_excpt_prf_info: required (object)
DLP 예외 프로파일

dlp_excpt_prf_id: required (integer)
dlp_excpt_prf_id

예외 프로파일 ID

name
name: required (string)
예외 프로파일 이름

descdesc: required (string)
예외 프로파일 설명

useuse: required (integer)
사용여부
사용안함:	0,	사용:	1

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_filter_rule_id":	1,
				"dlp_prf_id":	1,
				"dlp_data_obj_info":	{
						"dlp_data_obj_id":	10001,
						"type":	0,
						"name":	"객체	이름",
						"desc":	"객체	설명",
						"use":	1
				},
				"dlp_excpt_prf_info":	{
						"dlp_excpt_prf_id":	1,
						"name":	"예외	프로파일	이름",
						"desc":	"예외	프로파일	설명",
						"use":	1
				},
				"name":	"프로파일	이름",
				"use":	1,
				"direct":	1,
				"action":	1,
				"log_use":	1,
				"dump_use":	1,
				"mail_use":	1,
				"desc":	"DLP	프로파일	설명",
				"smtp_use":	0,
				"pop3_use":	0,
				"imap_use":	0,
				"http_use":	0,
				"ftp_use":	0,
				"smtp_cmd":	0,
				"smtp_rsps":	0,
				"smtp_sndr":	0,
				"smtp_rcvr":	0,
				"smtp_sbjt":	0,
				"smtp_header":	0,
				"smtp_body":	0,
				"smtp_fname":	0,
				"smtp_fbody":	0,
				"smtp_ftype":	0,
				"smtp_cntn_size":	0,
				"smtp_attach_size":	0,
				"pop3_sndr":	0,
				"pop3_rcvr":	0,
				"pop3_sbjt":	0,
				"pop3_header":	0,
				"pop3_body":	0,
				"pop3_fname":	0,
				"pop3_fbody":	0,
				"pop3_ftype":	0,
				"pop3_cntn_size":	0,
				"pop3_attach_size":	0,
				"imap_sndr":	0,
				"imap_rcvr":	0,
				"imap_sbjt":	0,
				"imap_header":	0,
				"imap_body":	0,
				"imap_fname":	0,
				"imap_fbody":	0,
				"imap_ftype":	0,
				"imap_cntn_size":	0,
				"imap_attach_size":	0,
				"http_rqst_method":	0,
				"http_rqst_url":	0,
				"http_rqst_url_raw":	0,
				"http_rqst_host":	0,
				"http_rqst_start_line":	0,
				"http_rqst_header":	0,
				"http_rqst_header_raw":	0,
				"http_rqst_body":	0,
				"http_rqst_body_raw":	0,
				"http_rqst_fname":	0,
				"http_rqst_fbody":	0,
				"http_rqst_ftype":	0,
				"http_rqst_cntn_size":	0,
				"http_rqst_file_size":	0,
				"http_rsps_start_line":	0,
				"http_rsps_header":	0,
				"http_rsps_header_raw":	0,
				"http_rsps_body":	0,
				"http_rsps_body_raw":	0,
				"http_rsps_fname":	0,
				"http_rsps_fbody":	0,
				"http_rsps_ftype":	0,
				"http_rsps_cntn_size":	0,
				"http_rsps_file_size":	0,

				"ftp_rqst_cmd":	0,
				"ftp_rqst_fname":	0,
				"ftp_rqst_fbody":	0,
				"ftp_rqst_ftype":	0,
				"ftp_rqst_file_size":	0,
				"ftp_rsps_rsps":	0,
				"ftp_rsps_fname":	0,
				"ftp_rsps_fbody":	0,
				"ftp_rsps_ftype":	0,
				"ftp_rsps_file_size":	0
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

/dlp/profiles/{ppk}/filters/{pk}

DLP 필터 정책을(를) 수정한다.

Request

URI Parameters

ppkppk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

pkpk: required (integer)
정책 ID( dlp_filter_rule_id )

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
name
name: required (string - minLength: 1 - maxLength: 32)
정책 이름

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

direct
direct: required (one of 1, 2, 3)
방향
내부:1,	외부:	2,	양방향:	3

action
action: required (one of 0, 1)
유형
탐지:	0,	차단:	1

log_use
log_use: required (one of 0, 1)
로그 사용 여부
사용안함:	0,	사용:	1

dump_use: required (one of 0, 1)
dump_use
덤프 사용 여부
사용안함:	0,	사용:	1

mail_use
mail_use: required (one of 0, 1)
메일 사용 여부
사용안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

smtp_use
smtp_use: required (one of 0, 1)
SMTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

pop3_use
pop3_use: required (one of 0, 1)
POP3 프로토콜 사용 여부
사용안함:	0,	사용:	1

imap_use
imap_use: required (one of 0, 1)
IMAP 프로토콜 사용 여부
사용안함:	0,	사용:	1

http_use
http_use: required (one of 0, 1)
HTTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

ftp_use: required (one of 0, 1)
ftp_use
FTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

smtp_cmd
smtp_cmd: required (one of 0, 1)
SMTP - command
사용안함:	0,	사용:	1

smtp_rsps
smtp_rsps: required (one of 0, 1)
SMTP - response
사용안함:	0,	사용:	1

smtp_sndr
smtp_sndr: required (one of 0, 1)
SMTP - sender
사용안함:	0,	사용:	1

smtp_rcvr
smtp_rcvr: required (one of 0, 1)
SMTP - receiver
사용안함:	0,	사용:	1

smtp_sbjt: required (one of 0, 1)
smtp_sbjt
SMTP - subject
사용안함:	0,	사용:	1

smtp_header
smtp_header: required (one of 0, 1)
SMTP - header
사용안함:	0,	사용:	1

smtp_body
smtp_body: required (one of 0, 1)
SMTP - body
사용안함:	0,	사용:	1

smtp_fname: required (one of 0, 1)
smtp_fname
SMTP - filename
사용안함:	0,	사용:	1

smtp_fbody
smtp_fbody: required (one of 0, 1)
SMTP - filebody
사용안함:	0,	사용:	1

smtp_ftype
smtp_ftype: required (one of 0, 1)
SMTP - filetype
사용안함:	0,	사용:	1

smtp_cntn_size
smtp_cntn_size: required (one of 0, 1)
SMTP - content size
사용안함:	0,	사용:	1

smtp_attach_size
smtp_attach_size: required (one of 0, 1)
SMTP - attachment size
사용안함:	0,	사용:	1

pop3_sndr: required (one of 0, 1)
pop3_sndr
POP - sender
사용안함:	0,	사용:	1

pop3_rcvr
pop3_rcvr: required (one of 0, 1)
POP - receiver
사용안함:	0,	사용:	1

pop3_sbjt
pop3_sbjt: required (one of 0, 1)
POP - subject
사용안함:	0,	사용:	1

pop3_header
pop3_header: required (one of 0, 1)
POP - header
사용안함:	0,	사용:	1

pop3_body
pop3_body: required (one of 0, 1)
POP - body
사용안함:	0,	사용:	1

pop3_fname: required (one of 0, 1)
pop3_fname
POP - filename
사용안함:	0,	사용:	1

pop3_fbody
pop3_fbody: required (one of 0, 1)
POP - filebody
사용안함:	0,	사용:	1

pop3_ftype
pop3_ftype: required (one of 0, 1)
POP - filetype
사용안함:	0,	사용:	1

pop3_cntn_size
pop3_cntn_size: required (one of 0, 1)
POP - content size
사용안함:	0,	사용:	1

pop3_attach_size
pop3_attach_size: required (one of 0, 1)
POP - attachment size
사용안함:	0,	사용:	1

imap_sndr
imap_sndr: required (one of 0, 1)
IMAP - sender
사용안함:	0,	사용:	1

imap_rcvr
imap_rcvr: required (one of 0, 1)
IMAP - receiver
사용안함:	0,	사용:	1

imap_sbjt
imap_sbjt: required (one of 0, 1)
IMAP - subject
사용안함:	0,	사용:	1

imap_header
imap_header: required (one of 0, 1)
IMAP - header
사용안함:	0,	사용:	1

imap_body
imap_body: required (one of 0, 1)
IMAP - body
사용안함:	0,	사용:	1

imap_fname
imap_fname: required (one of 0, 1)
IMAP - filename
사용안함:	0,	사용:	1

imap_fbody
imap_fbody: required (one of 0, 1)
IMAP - filebody
사용안함:	0,	사용:	1

imap_ftype: required (one of 0, 1)
imap_ftype
IMAP - filetype
사용안함:	0,	사용:	1

imap_cntn_size
imap_cntn_size: required (one of 0, 1)
IMAP - content size
사용안함:	0,	사용:	1

imap_attach_size
imap_attach_size: required (one of 0, 1)
IMAP - attachment size
사용안함:	0,	사용:	1

http_rqst_method
http_rqst_method: required (one of 0, 1)
HTTP(Request) - method
사용안함:	0,	사용:	1

http_rqst_url
http_rqst_url: required (one of 0, 1)
HTTP(Request) - url
사용안함:	0,	사용:	1

http_rqst_url_raw: required (one of 0, 1)
http_rqst_url_raw

HTTP(Request) - url_raw
사용안함:	0,	사용:	1

http_rqst_host
http_rqst_host: required (one of 0, 1)
HTTP(Request) - host
사용안함:	0,	사용:	1

http_rqst_start_line
http_rqst_start_line: required (one of 0, 1)
HTTP(Request) - start_line
사용안함:	0,	사용:	1

http_rqst_header: required (one of 0, 1)
http_rqst_header
HTTP(Request) - header
사용안함:	0,	사용:	1

http_rqst_header_raw
http_rqst_header_raw: required (one of 0, 1)
HTTP(Request) - header_raw
사용안함:	0,	사용:	1

http_rqst_body
http_rqst_body: required (one of 0, 1)
HTTP(Request) - body
사용안함:	0,	사용:	1

http_rqst_body_raw
http_rqst_body_raw: required (one of 0, 1)
HTTP(Request) - body_raw
사용안함:	0,	사용:	1

http_rqst_fname
http_rqst_fname: required (one of 0, 1)
HTTP(Request) - filename
사용안함:	0,	사용:	1

http_rqst_fbody: required (one of 0, 1)
http_rqst_fbody
HTTP(Request) - filebody
사용안함:	0,	사용:	1

http_rqst_ftype
http_rqst_ftype: required (one of 0, 1)
HTTP(Request) - filetype
사용안함:	0,	사용:	1

http_rqst_cntn_size
http_rqst_cntn_size: required (one of 0, 1)
HTTP(Request) - content size
사용안함:	0,	사용:	1

http_rqst_file_size
http_rqst_file_size: required (one of 0, 1)
HTTP(Request) - file size
사용안함:	0,	사용:	1

http_rsps_start_line
http_rsps_start_line: required (one of 0, 1)
HTTP(Response) - start_line
사용안함:	0,	사용:	1

http_rsps_header: required (one of 0, 1)
http_rsps_header
HTTP(Response) - header
사용안함:	0,	사용:	1

http_rsps_header_raw
http_rsps_header_raw: required (one of 0, 1)
HTTP(Response) - header_raw
사용안함:	0,	사용:	1

http_rsps_body
http_rsps_body: required (one of 0, 1)
HTTP(Response) - body
사용안함:	0,	사용:	1

http_rsps_body_raw
http_rsps_body_raw: required (one of 0, 1)
HTTP(Response) - body_raw
사용안함:	0,	사용:	1

http_rsps_fname
http_rsps_fname: required (one of 0, 1)
HTTP(Response) - filename
사용안함:	0,	사용:	1

http_rsps_fbody: required (one of 0, 1)
http_rsps_fbody
HTTP(Response) - filebody
사용안함:	0,	사용:	1

http_rsps_ftype
http_rsps_ftype: required (one of 0, 1)
HTTP(Response) - filetype
사용안함:	0,	사용:	1

http_rsps_cntn_size
http_rsps_cntn_size: required (one of 0, 1)
HTTP(Response) - content size
사용안함:	0,	사용:	1

http_rsps_file_size
http_rsps_file_size: required (one of 0, 1)
HTTP(Response) - file size
사용안함:	0,	사용:	1

ftp_rqst_cmd
ftp_rqst_cmd: required (one of 0, 1)
FTP(To Server) - command
사용안함:	0,	사용:	1

ftp_rqst_fname
ftp_rqst_fname: required (one of 0, 1)
FTP(To Server) - filename
사용안함:	0,	사용:	1

ftp_rqst_fbody
ftp_rqst_fbody: required (one of 0, 1)
FTP(To Server) - filebody
사용안함:	0,	사용:	1

ftp_rqst_ftype
ftp_rqst_ftype: required (one of 0, 1)
FTP(To Server) - filetype
사용안함:	0,	사용:	1

ftp_rqst_file_size
ftp_rqst_file_size: required (one of 0, 1)
FTP(To Server) - file size
사용안함:	0,	사용:	1

ftp_rsps_rsps
ftp_rsps_rsps: required (one of 0, 1)
FTP(From Server) - response
사용안함:	0,	사용:	1

ftp_rsps_fname: required (one of 0, 1)
ftp_rsps_fname

FTP(From Server) - filename
사용안함:	0,	사용:	1

ftp_rsps_fbody
ftp_rsps_fbody: required (one of 0, 1)
FTP(From Server) - filebody
사용안함:	0,	사용:	1

ftp_rsps_ftype
ftp_rsps_ftype: required (one of 0, 1)
FTP(From Server) - filetype
사용안함:	0,	사용:	1

ftp_rsps_file_size: required (one of 0, 1)
ftp_rsps_file_size
FTP(From Server) - file size
사용안함:	0,	사용:	1

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체 ID

dlp_excpt_prf_id: required (integer)
dlp_excpt_prf_id
DLP 예외 프로파일 ID

Example:
Example

{
		"dlp_data_obj_id":	10001,
		"dlp_excpt_prf_id":	1,
		"name":	"프로파일	이름",
		"use":	1,
		"direct":	1,
		"action":	1,
		"log_use":	1,
		"dump_use":	1,
		"mail_use":	1,
		"desc":	"DLP	프로파일	설명",
		"smtp_use":	0,
		"pop3_use":	0,
		"imap_use":	0,
		"http_use":	0,
		"ftp_use":	0,
		"smtp_cmd":	0,
		"smtp_rsps":	0,
		"smtp_sndr":	0,
		"smtp_rcvr":	0,
		"smtp_sbjt":	0,
		"smtp_header":	0,
		"smtp_body":	0,
		"smtp_fname":	0,
		"smtp_fbody":	0,
		"smtp_ftype":	0,
		"smtp_cntn_size":	0,
		"smtp_attach_size":	0,
		"pop3_sndr":	0,
		"pop3_rcvr":	0,
		"pop3_sbjt":	0,
		"pop3_header":	0,
		"pop3_body":	0,
		"pop3_fname":	0,
		"pop3_fbody":	0,
		"pop3_ftype":	0,
		"pop3_cntn_size":	0,
		"pop3_attach_size":	0,
		"imap_sndr":	0,
		"imap_rcvr":	0,
		"imap_sbjt":	0,
		"imap_header":	0,
		"imap_body":	0,
		"imap_ftype":	0,
		"imap_fname":	0,
		"imap_fbody":	0,
		"imap_cntn_size":	0,
		"imap_attach_size":	0,
		"http_rqst_method":	0,
		"http_rqst_url":	0,
		"http_rqst_url_raw":	0,
		"http_rqst_host":	0,
		"http_rqst_start_line":	0,
		"http_rqst_header":	0,
		"http_rqst_header_raw":	0,
		"http_rqst_body":	0,
		"http_rqst_body_raw":	0,
		"http_rqst_fname":	0,
		"http_rqst_fbody":	0,
		"http_rqst_ftype":	0,
		"http_rqst_cntn_size":	0,
		"http_rqst_file_size":	0,
		"http_rsps_start_line":	0,
		"http_rsps_header":	0,
		"http_rsps_header_raw":	0,
		"http_rsps_body":	0,
		"http_rsps_body_raw":	0,
		"http_rsps_fname":	0,
		"http_rsps_fbody":	0,
		"http_rsps_ftype":	0,
		"http_rsps_cntn_size":	0,
		"http_rsps_file_size":	0,
		"ftp_rqst_cmd":	0,
		"ftp_rqst_fname":	0,
		"ftp_rqst_fbody":	0,
		"ftp_rqst_ftype":	0,
		"ftp_rqst_file_size":	0,
		"ftp_rsps_rsps":	0,
		"ftp_rsps_fname":	0,
		"ftp_rsps_fbody":	0,
		"ftp_rsps_ftype":	0,
		"ftp_rsps_file_size":	0
}

Response

HTTP status code 200

DLP 필터 정책 수정 성공

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
정책 이름

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

direct
direct: required (one of 1, 2, 3)
방향
내부:1,	외부:	2,	양방향:	3

action
action: required (one of 0, 1)
유형
탐지:	0,	차단:	1

log_use
log_use: required (one of 0, 1)
로그 사용 여부
사용안함:	0,	사용:	1

dump_use
dump_use: required (one of 0, 1)
덤프 사용 여부
사용안함:	0,	사용:	1

mail_use: required (one of 0, 1)
mail_use
메일 사용 여부
사용안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

smtp_use: required (one of 0, 1)
smtp_use
SMTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

pop3_use
pop3_use: required (one of 0, 1)
POP3 프로토콜 사용 여부
사용안함:	0,	사용:	1

imap_use
imap_use: required (one of 0, 1)
IMAP 프로토콜 사용 여부
사용안함:	0,	사용:	1

http_use
http_use: required (one of 0, 1)
HTTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

ftp_use
ftp_use: required (one of 0, 1)
FTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

smtp_cmd: required (one of 0, 1)
smtp_cmd
SMTP - command
사용안함:	0,	사용:	1

smtp_rsps
smtp_rsps: required (one of 0, 1)
SMTP - response
사용안함:	0,	사용:	1

smtp_sndr
smtp_sndr: required (one of 0, 1)
SMTP - sender
사용안함:	0,	사용:	1

smtp_rcvr
smtp_rcvr: required (one of 0, 1)
SMTP - receiver
사용안함:	0,	사용:	1

smtp_sbjt
smtp_sbjt: required (one of 0, 1)
SMTP - subject
사용안함:	0,	사용:	1

smtp_header: required (one of 0, 1)
smtp_header
SMTP - header
사용안함:	0,	사용:	1

smtp_body
smtp_body: required (one of 0, 1)
SMTP - body
사용안함:	0,	사용:	1

smtp_fname
smtp_fname: required (one of 0, 1)
SMTP - filename
사용안함:	0,	사용:	1

smtp_fbody
smtp_fbody: required (one of 0, 1)
SMTP - filebody
사용안함:	0,	사용:	1

smtp_ftype
smtp_ftype: required (one of 0, 1)
SMTP - filetype
사용안함:	0,	사용:	1

smtp_cntn_size: required (one of 0, 1)
smtp_cntn_size
SMTP - content size
사용안함:	0,	사용:	1

smtp_attach_size
smtp_attach_size: required (one of 0, 1)
SMTP - attachment size
사용안함:	0,	사용:	1

pop3_sndr
pop3_sndr: required (one of 0, 1)
POP - sender
사용안함:	0,	사용:	1

pop3_rcvr: required (one of 0, 1)
pop3_rcvr

POP - receiver
사용안함:	0,	사용:	1

pop3_sbjt
pop3_sbjt: required (one of 0, 1)
POP - subject
사용안함:	0,	사용:	1

pop3_header
pop3_header: required (one of 0, 1)
POP - header
사용안함:	0,	사용:	1

pop3_body: required (one of 0, 1)
pop3_body
POP - body
사용안함:	0,	사용:	1

pop3_fname
pop3_fname: required (one of 0, 1)
POP - filename
사용안함:	0,	사용:	1

pop3_fbody
pop3_fbody: required (one of 0, 1)
POP - filebody
사용안함:	0,	사용:	1

pop3_ftype
pop3_ftype: required (one of 0, 1)
POP - filetype
사용안함:	0,	사용:	1

pop3_cntn_size
pop3_cntn_size: required (one of 0, 1)
POP - content size
사용안함:	0,	사용:	1

pop3_attach_size: required (one of 0, 1)
pop3_attach_size
POP - attachment size
사용안함:	0,	사용:	1

imap_sndr
imap_sndr: required (one of 0, 1)
IMAP - sender
사용안함:	0,	사용:	1

imap_rcvr
imap_rcvr: required (one of 0, 1)
IMAP - receiver
사용안함:	0,	사용:	1

imap_sbjt
imap_sbjt: required (one of 0, 1)
IMAP - subject
사용안함:	0,	사용:	1

imap_header
imap_header: required (one of 0, 1)
IMAP - header
사용안함:	0,	사용:	1

imap_body: required (one of 0, 1)
imap_body
IMAP - body
사용안함:	0,	사용:	1

imap_fname
imap_fname: required (one of 0, 1)
IMAP - filename
사용안함:	0,	사용:	1

imap_fbody
imap_fbody: required (one of 0, 1)
IMAP - filebody
사용안함:	0,	사용:	1

imap_ftype
imap_ftype: required (one of 0, 1)
IMAP - filetype
사용안함:	0,	사용:	1

imap_cntn_size
imap_cntn_size: required (one of 0, 1)
IMAP - content size
사용안함:	0,	사용:	1

imap_attach_size: required (one of 0, 1)
imap_attach_size
IMAP - attachment size
사용안함:	0,	사용:	1

http_rqst_method
http_rqst_method: required (one of 0, 1)
HTTP(Request) - method
사용안함:	0,	사용:	1

http_rqst_url
http_rqst_url: required (one of 0, 1)
HTTP(Request) - url
사용안함:	0,	사용:	1

http_rqst_url_raw
http_rqst_url_raw: required (one of 0, 1)
HTTP(Request) - url_raw
사용안함:	0,	사용:	1

http_rqst_host
http_rqst_host: required (one of 0, 1)
HTTP(Request) - host
사용안함:	0,	사용:	1

http_rqst_start_line
http_rqst_start_line: required (one of 0, 1)
HTTP(Request) - start_line
사용안함:	0,	사용:	1

http_rqst_header
http_rqst_header: required (one of 0, 1)
HTTP(Request) - header
사용안함:	0,	사용:	1

http_rqst_header_raw
http_rqst_header_raw: required (one of 0, 1)
HTTP(Request) - header_raw
사용안함:	0,	사용:	1

http_rqst_body
http_rqst_body: required (one of 0, 1)
HTTP(Request) - body
사용안함:	0,	사용:	1

http_rqst_body_raw
http_rqst_body_raw: required (one of 0, 1)
HTTP(Request) - body_raw
사용안함:	0,	사용:	1

http_rqst_fname: required (one of 0, 1)
http_rqst_fname

HTTP(Request) - filename
사용안함:	0,	사용:	1

http_rqst_fbody
http_rqst_fbody: required (one of 0, 1)
HTTP(Request) - filebody
사용안함:	0,	사용:	1

http_rqst_ftype
http_rqst_ftype: required (one of 0, 1)
HTTP(Request) - filetype
사용안함:	0,	사용:	1

http_rqst_cntn_size: required (one of 0, 1)
http_rqst_cntn_size
HTTP(Request) - content size
사용안함:	0,	사용:	1

http_rqst_file_size
http_rqst_file_size: required (one of 0, 1)
HTTP(Request) - file size
사용안함:	0,	사용:	1

http_rsps_start_line
http_rsps_start_line: required (one of 0, 1)
HTTP(Response) - start_line
사용안함:	0,	사용:	1

http_rsps_header
http_rsps_header: required (one of 0, 1)
HTTP(Response) - header
사용안함:	0,	사용:	1

http_rsps_header_raw
http_rsps_header_raw: required (one of 0, 1)
HTTP(Response) - header_raw
사용안함:	0,	사용:	1

http_rsps_body: required (one of 0, 1)
http_rsps_body
HTTP(Response) - body
사용안함:	0,	사용:	1

http_rsps_body_raw
http_rsps_body_raw: required (one of 0, 1)
HTTP(Response) - body_raw
사용안함:	0,	사용:	1

http_rsps_fname
http_rsps_fname: required (one of 0, 1)
HTTP(Response) - filename
사용안함:	0,	사용:	1

http_rsps_fbody
http_rsps_fbody: required (one of 0, 1)
HTTP(Response) - filebody
사용안함:	0,	사용:	1

http_rsps_ftype
http_rsps_ftype: required (one of 0, 1)
HTTP(Response) - filetype
사용안함:	0,	사용:	1

http_rsps_cntn_size: required (one of 0, 1)
http_rsps_cntn_size
HTTP(Response) - content size
사용안함:	0,	사용:	1

http_rsps_file_size
http_rsps_file_size: required (one of 0, 1)
HTTP(Response) - file size
사용안함:	0,	사용:	1

ftp_rqst_cmd
ftp_rqst_cmd: required (one of 0, 1)
FTP(To Server) - command
사용안함:	0,	사용:	1

ftp_rqst_fname
ftp_rqst_fname: required (one of 0, 1)
FTP(To Server) - filename
사용안함:	0,	사용:	1

ftp_rqst_fbody
ftp_rqst_fbody: required (one of 0, 1)
FTP(To Server) - filebody
사용안함:	0,	사용:	1

ftp_rqst_ftype: required (one of 0, 1)
ftp_rqst_ftype
FTP(To Server) - filetype
사용안함:	0,	사용:	1

ftp_rqst_file_size
ftp_rqst_file_size: required (one of 0, 1)
FTP(To Server) - file size
사용안함:	0,	사용:	1

ftp_rsps_rsps
ftp_rsps_rsps: required (one of 0, 1)
FTP(From Server) - response
사용안함:	0,	사용:	1

ftp_rsps_fname
ftp_rsps_fname: required (one of 0, 1)
FTP(From Server) - filename
사용안함:	0,	사용:	1

ftp_rsps_fbody
ftp_rsps_fbody: required (one of 0, 1)
FTP(From Server) - filebody
사용안함:	0,	사용:	1

ftp_rsps_ftype
ftp_rsps_ftype: required (one of 0, 1)
FTP(From Server) - filetype
사용안함:	0,	사용:	1

ftp_rsps_file_size
ftp_rsps_file_size: required (one of 0, 1)
FTP(From Server) - file size
사용안함:	0,	사용:	1

dlp_prf_id
dlp_prf_id: required (integer)
DLP 프로파일 ID

dlp_filter_rule_id
dlp_filter_rule_id: required (integer)
DLP 필터 정책 ID

dlp_data_obj_info: required (object)
dlp_data_obj_info
DLP 데이터 객체

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체/그룹 ID

type: required (integer)
type

객체 타입
객체:	0,	그룹:	1

pre_def
pre_def: required (integer)
사전 정의 여부
사용자	정의:	1,	기본	정의:	2

useuse: required (integer)
사용 여부
사용	안함:	0,	사용:	1

name: required (string)
name
데이터 객체 이름

descdesc: required (string)
설명

value_type
value_type: required (one of 1, 2, 3, 4)
객체 유형
문자열:	1,	정규식:	2,	크기:	3,	파일유형:	4

value1
value1: required (string)
객체 유형이  문자열(1),	정규식(2) 일 때 값
Base64 인코딩/디코딩 필요

value2: required (string)
value2
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

dlp_excpt_prf_info
dlp_excpt_prf_info: required (object)
DLP 예외 프로파일

dlp_excpt_prf_id
dlp_excpt_prf_id: required (integer)
예외 프로파일 ID

name
name: required (string)
예외 프로파일 이름

descdesc: required (string)
예외 프로파일 설명

useuse: required (integer)
사용여부
사용안함:	0,	사용:	1

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_filter_rule_id":	1,
				"dlp_prf_id":	1,
				"dlp_data_obj_info":	{
						"dlp_data_obj_id":	10001,
						"type":	0,
						"name":	"객체	이름",
						"desc":	"객체	설명",
						"use":	1
				},
				"dlp_excpt_prf_info":	{
						"dlp_excpt_prf_id":	1,
						"name":	"예외	프로파일	이름",
						"desc":	"예외	프로파일	설명",
						"use":	1
				},
				"name":	"프로파일	이름",
				"use":	1,
				"direct":	1,
				"action":	1,
				"log_use":	1,
				"dump_use":	1,
				"mail_use":	1,
				"desc":	"DLP	프로파일	설명",
				"smtp_use":	1,
				"pop3_use":	1,
				"imap_use":	1,
				"http_use":	1,
				"ftp_use":	1,
				"smtp_cmd":	0,
				"smtp_rsps":	0,
				"smtp_sndr":	0,
				"smtp_rcvr":	0,
				"smtp_sbjt":	0,
				"smtp_header":	0,
				"smtp_body":	0,
				"smtp_fname":	0,
				"smtp_fbody":	0,
				"smtp_ftype":	0,
				"smtp_cntn_size":	0,
				"smtp_attach_size":	0,
				"pop3_sndr":	0,
				"pop3_rcvr":	0,
				"pop3_sbjt":	0,
				"pop3_header":	0,
				"pop3_body":	0,
				"pop3_fname":	0,
				"pop3_fbody":	0,
				"pop3_ftype":	0,
				"pop3_cntn_size":	0,
				"pop3_attach_size":	0,
				"imap_sndr":	0,
				"imap_rcvr":	0,
				"imap_sbjt":	0,
				"imap_header":	0,

				"imap_body":	0,
				"imap_fname":	0,
				"imap_fbody":	0,
				"imap_ftype":	0,
				"imap_cntn_size":	0,
				"imap_attach_size":	0,
				"http_rqst_method":	0,
				"http_rqst_url":	0,
				"http_rqst_url_raw":	0,
				"http_rqst_host":	0,
				"http_rqst_start_line":	0,
				"http_rqst_header":	0,
				"http_rqst_header_raw":	0,
				"http_rqst_body":	0,
				"http_rqst_body_raw":	0,
				"http_rqst_fname":	0,
				"http_rqst_fbody":	0,
				"http_rqst_ftype":	0,
				"http_rqst_cntn_size":	0,
				"http_rqst_file_size":	0,
				"http_rsps_start_line":	0,
				"http_rsps_header":	0,
				"http_rsps_header_raw":	0,
				"http_rsps_body":	0,
				"http_rsps_body_raw":	0,
				"http_rsps_fname":	0,
				"http_rsps_fbody":	0,
				"http_rsps_ftype":	0,
				"http_rsps_cntn_size":	0,
				"http_rsps_file_size":	0,
				"ftp_rqst_cmd":	0,
				"ftp_rqst_fname":	0,
				"ftp_rqst_fbody":	0,
				"ftp_rqst_ftype":	0,
				"ftp_rqst_file_size":	0,
				"ftp_rsps_rsps":	0,
				"ftp_rsps_fname":	0,
				"ftp_rsps_fbody":	0,
				"ftp_rsps_ftype":	0,
				"ftp_rsps_file_size":	0
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

dev_t: (string)
dev_t
개발용 메시지

Example:
Example

{
		"code":	"12001",
		"message":	"존재하지	않는	항목입니다."
}

DELETE

/dlp/profiles/{ppk}/filters/{pk}

DLP 필터 정책을(를) 삭제한다.

Request

URI Parameters

ppkppk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

pkpk: required (integer)
정책 ID( dlp_filter_rule_id )

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

Response

HTTP status code 200

DLP 필터 정책 삭제 성공

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

DLP 아카이브 정책

GET

/dlp/profiles/{ppk}/archives

DLP 아카이브 정책 목록을 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

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

DLP 아카이브 정책 목록 조회 성공

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
result: required (array of DlpGetArchive)
결과 데이터

Items: DlpGetArchive
Items

name
name: required (string)
아카이브 정책 이름

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

direct
direct: required (one of 1, 2, 3)
방향
내부:1,	외부:	2,	양방향:	3

action
action: required (integer - default: 3)
대응
Archive:	3

log_use
log_use: required (one of 0, 1)
로그 사용 여부
사용안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

smtp_use
smtp_use: required (one of 0, 1)
SMTP 사용 여부
사용안함:	0,	사용:	1

smtp_attach
smtp_attach: required (one of 0, 1)
SMTP - attachment
사용안함:	0,	사용:	1

smtp_header
smtp_header: required (one of 0, 1)
SMTP - header
사용안함:	0,	사용:	1

smtp_body: required (one of 0, 1)
smtp_body
SMTP - body
사용안함:	0,	사용:	1

pop3_use
pop3_use: required (one of 0, 1)
POP3 사용 여부
사용안함:	0,	사용:	1

pop3_attach
pop3_attach: required (one of 0, 1)
POP3 - attachment
사용안함:	0,	사용:	1

pop3_header
pop3_header: required (one of 0, 1)
POP3 - header
사용안함:	0,	사용:	1

pop3_body
pop3_body: required (one of 0, 1)
POP3 - body
사용안함:	0,	사용:	1

imap_use
imap_use: required (one of 0, 1)
IMAP 사용 여부
사용안함:	0,	사용:	1

imap_attach
imap_attach: required (one of 0, 1)
IMAP - attachment
사용안함:	0,	사용:	1

imap_header
imap_header: required (one of 0, 1)
IMAP - header
사용안함:	0,	사용:	1

imap_body
imap_body: required (one of 0, 1)
IMAP - body
사용안함:	0,	사용:	1

http_use
http_use: required (one of 0, 1)
HTTP 사용 여부
사용안함:	0,	사용:	1

http_rqst_header
http_rqst_header: required (one of 0, 1)
HTTP(Request) - header
사용안함:	0,	사용:	1

http_rqst_file: required (one of 0, 1)
http_rqst_file
HTTP(Request) - file
사용안함:	0,	사용:	1

http_rqst_body
http_rqst_body: required (one of 0, 1)
HTTP(Request) - body
사용안함:	0,	사용:	1

http_rsps_header: required (one of 0, 1)
http_rsps_header
HTTP(Response) - header
사용안함:	0,	사용:	1

http_rsps_file
http_rsps_file: required (one of 0, 1)
HTTP(Response) - file
사용안함:	0,	사용:	1

http_rsps_body
http_rsps_body: required (one of 0, 1)
HTTP(Response) - body
사용안함:	0,	사용:	1

ftp_use
ftp_use: required (one of 0, 1)
FTP 사용 여부
사용안함:	0,	사용:	1

ftp_rqst_file
ftp_rqst_file: required (one of 0, 1)
FTP(To Server) - file
사용안함:	0,	사용:	1

ftp_rqst_cmd
ftp_rqst_cmd: required (one of 0, 1)
FTP(To Server) - command
사용안함:	0,	사용:	1

ftp_rsps_file
ftp_rsps_file: required (one of 0, 1)
FTP(From Server) - file
사용안함:	0,	사용:	1

ftp_rsps_cmd
ftp_rsps_cmd: required (one of 0, 1)
FTP(From Server) - command
사용안함:	0,	사용:	1

dlp_prf_id
dlp_prf_id: required (integer)
DLP 프로파일 ID

dlp_arch_rule_id
dlp_arch_rule_id: required (integer)
DLP 아카이브 정책 ID

dlp_data_obj_info
dlp_data_obj_info: required (object)
DLP 데이터 객체

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체/그룹 ID

type: required (integer)
type
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
객체 유형이  문자열(1),	정규식(2) 일 때 값
Base64 인코딩/디코딩 필요

value2
value2: required (string)
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

dlp_excpt_prf_info
dlp_excpt_prf_info: required (object)
DLP 예외 프로파일

dlp_excpt_prf_id
dlp_excpt_prf_id: required (integer)
예외 프로파일 ID

name
name: required (string)
예외 프로파일 이름

descdesc: required (string)
예외 프로파일 설명

useuse: required (integer)
사용여부
사용안함:	0,	사용:	1

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"dlp_prf_id":	1,
				"dlp_arch_rule_id":	1,
				"dlp_data_obj_info":	{
						"dlp_data_obj_id":	10001,
						"type":	0,
						"name":	"객체	이름",
						"desc":	"객체	설명",
						"use":	1
				},
				"dlp_excpt_prf_info":	{
						"dlp_excpt_prf_id":	1,
						"name":	"예외	프로파일	이름",
						"desc":	"예외	프로파일	설명",
						"use":	1
				},
				"name":	"아카이브	정책	이름",
				"use":	1,
				"direct":	1,
				"action":	3,
				"log_use":	1,
				"desc":	"아카이브	정책	설명",
				"smtp_use":	0,
				"smtp_attach":	0,
				"smtp_header":	0,
				"smtp_body":	0,
				"pop3_use":	0,
				"pop3_attach":	0,
				"pop3_header":	0,
				"pop3_body":	0,
				"imap_use":	0,
				"imap_attach":	0,
				"imap_header":	0,
				"imap_body":	0,
				"http_use":	0,
				"http_rqst_header":	0,
				"http_rqst_file":	0,
				"http_rqst_body":	0,
				"http_rsps_header":	0,
				"http_rsps_file":	0,
				"http_rsps_body":	0,
				"ftp_use":	0,
				"ftp_rqst_file":	0,
				"ftp_rqst_cmd":	0,
				"ftp_rsps_file":	0,
				"ftp_rsps_cmd":	0
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

/dlp/profiles/{ppk}/archives

DLP 아카이브 정책를 추가한다.

Request

URI Parameters

ppkppk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

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
name
name: required (string)
아카이브 정책 이름

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

direct
direct: required (one of 1, 2, 3)
방향
내부:1,	외부:	2,	양방향:	3

action
action: required (integer - default: 3)
대응
Archive:	3

log_use
log_use: required (one of 0, 1)
로그 사용 여부
사용안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

smtp_use
smtp_use: required (one of 0, 1)
SMTP 사용 여부
사용안함:	0,	사용:	1

smtp_attach: required (one of 0, 1)
smtp_attach

SMTP - attachment
사용안함:	0,	사용:	1

smtp_header
smtp_header: required (one of 0, 1)
SMTP - header
사용안함:	0,	사용:	1

smtp_body
smtp_body: required (one of 0, 1)
SMTP - body
사용안함:	0,	사용:	1

pop3_use: required (one of 0, 1)
pop3_use
POP3 사용 여부
사용안함:	0,	사용:	1

pop3_attach
pop3_attach: required (one of 0, 1)
POP3 - attachment
사용안함:	0,	사용:	1

pop3_header
pop3_header: required (one of 0, 1)
POP3 - header
사용안함:	0,	사용:	1

pop3_body
pop3_body: required (one of 0, 1)
POP3 - body
사용안함:	0,	사용:	1

imap_use
imap_use: required (one of 0, 1)
IMAP 사용 여부
사용안함:	0,	사용:	1

imap_attach: required (one of 0, 1)
imap_attach
IMAP - attachment
사용안함:	0,	사용:	1

imap_header
imap_header: required (one of 0, 1)
IMAP - header
사용안함:	0,	사용:	1

imap_body
imap_body: required (one of 0, 1)
IMAP - body
사용안함:	0,	사용:	1

http_use
http_use: required (one of 0, 1)
HTTP 사용 여부
사용안함:	0,	사용:	1

http_rqst_header
http_rqst_header: required (one of 0, 1)
HTTP(Request) - header
사용안함:	0,	사용:	1

http_rqst_file: required (one of 0, 1)
http_rqst_file
HTTP(Request) - file
사용안함:	0,	사용:	1

http_rqst_body
http_rqst_body: required (one of 0, 1)
HTTP(Request) - body
사용안함:	0,	사용:	1

http_rsps_header
http_rsps_header: required (one of 0, 1)
HTTP(Response) - header
사용안함:	0,	사용:	1

http_rsps_file
http_rsps_file: required (one of 0, 1)
HTTP(Response) - file
사용안함:	0,	사용:	1

http_rsps_body
http_rsps_body: required (one of 0, 1)
HTTP(Response) - body
사용안함:	0,	사용:	1

ftp_use: required (one of 0, 1)
ftp_use
FTP 사용 여부
사용안함:	0,	사용:	1

ftp_rqst_file
ftp_rqst_file: required (one of 0, 1)
FTP(To Server) - file
사용안함:	0,	사용:	1

ftp_rqst_cmd
ftp_rqst_cmd: required (one of 0, 1)
FTP(To Server) - command
사용안함:	0,	사용:	1

ftp_rsps_file
ftp_rsps_file: required (one of 0, 1)
FTP(From Server) - file
사용안함:	0,	사용:	1

ftp_rsps_cmd
ftp_rsps_cmd: required (one of 0, 1)
FTP(From Server) - command
사용안함:	0,	사용:	1

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체 ID

dlp_excpt_prf_id
dlp_excpt_prf_id: required (integer)
DLP 예외 프로파일 ID

Example:
Example

{
		"dlp_data_obj_id":	10000,
		"dlp_excpt_prf_id":	1,
		"name":	"New	아카이브	정책	이름",
		"use":	1,
		"direct":	1,
		"action":	3,
		"log_use":	1,
		"desc":	"New	아카이브	정책	설명",
		"smtp_use":	0,
		"smtp_attach":	1,
		"smtp_header":	1,
		"smtp_body":	0,
		"pop3_use":	0,
		"pop3_attach":	0,
		"pop3_header":	0,
		"pop3_body":	0,
		"imap_use":	0,
		"imap_attach":	0,
		"imap_header":	0,
		"imap_body":	0,
		"http_use":	0,
		"http_rqst_header":	0,
		"http_rqst_file":	0,
		"http_rqst_body":	0,
		"http_rsps_header":	0,
		"http_rsps_file":	0,
		"http_rsps_body":	0,
		"ftp_use":	0,
		"ftp_rqst_file":	0,
		"ftp_rqst_cmd":	0,
		"ftp_rsps_file":	0,
		"ftp_rsps_cmd":	0
}

Response

HTTP status code 200

DLP 아카이브 정책 추가 성공

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

name: required (string)
name
아카이브 정책 이름

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

direct: required (one of 1, 2, 3)
direct
방향
내부:1,	외부:	2,	양방향:	3

action
action: required (integer - default: 3)
대응
Archive:	3

log_use
log_use: required (one of 0, 1)
로그 사용 여부
사용안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

smtp_use
smtp_use: required (one of 0, 1)
SMTP 사용 여부
사용안함:	0,	사용:	1

smtp_attach
smtp_attach: required (one of 0, 1)
SMTP - attachment
사용안함:	0,	사용:	1

smtp_header
smtp_header: required (one of 0, 1)
SMTP - header
사용안함:	0,	사용:	1

smtp_body: required (one of 0, 1)
smtp_body
SMTP - body
사용안함:	0,	사용:	1

pop3_use
pop3_use: required (one of 0, 1)
POP3 사용 여부
사용안함:	0,	사용:	1

pop3_attach
pop3_attach: required (one of 0, 1)
POP3 - attachment
사용안함:	0,	사용:	1

pop3_header: required (one of 0, 1)
pop3_header

POP3 - header
사용안함:	0,	사용:	1

pop3_body
pop3_body: required (one of 0, 1)
POP3 - body
사용안함:	0,	사용:	1

imap_use
imap_use: required (one of 0, 1)
IMAP 사용 여부
사용안함:	0,	사용:	1

imap_attach: required (one of 0, 1)
imap_attach
IMAP - attachment
사용안함:	0,	사용:	1

imap_header
imap_header: required (one of 0, 1)
IMAP - header
사용안함:	0,	사용:	1

imap_body
imap_body: required (one of 0, 1)
IMAP - body
사용안함:	0,	사용:	1

http_use
http_use: required (one of 0, 1)
HTTP 사용 여부
사용안함:	0,	사용:	1

http_rqst_header
http_rqst_header: required (one of 0, 1)
HTTP(Request) - header
사용안함:	0,	사용:	1

http_rqst_file: required (one of 0, 1)
http_rqst_file
HTTP(Request) - file
사용안함:	0,	사용:	1

http_rqst_body
http_rqst_body: required (one of 0, 1)
HTTP(Request) - body
사용안함:	0,	사용:	1

http_rsps_header
http_rsps_header: required (one of 0, 1)
HTTP(Response) - header
사용안함:	0,	사용:	1

http_rsps_file
http_rsps_file: required (one of 0, 1)
HTTP(Response) - file
사용안함:	0,	사용:	1

http_rsps_body
http_rsps_body: required (one of 0, 1)
HTTP(Response) - body
사용안함:	0,	사용:	1

ftp_use: required (one of 0, 1)
ftp_use
FTP 사용 여부
사용안함:	0,	사용:	1

ftp_rqst_file
ftp_rqst_file: required (one of 0, 1)
FTP(To Server) - file
사용안함:	0,	사용:	1

ftp_rqst_cmd
ftp_rqst_cmd: required (one of 0, 1)
FTP(To Server) - command
사용안함:	0,	사용:	1

ftp_rsps_file
ftp_rsps_file: required (one of 0, 1)
FTP(From Server) - file
사용안함:	0,	사용:	1

ftp_rsps_cmd
ftp_rsps_cmd: required (one of 0, 1)
FTP(From Server) - command
사용안함:	0,	사용:	1

dlp_prf_id: required (integer)
dlp_prf_id
DLP 프로파일 ID

dlp_arch_rule_id
dlp_arch_rule_id: required (integer)
DLP 아카이브 정책 ID

dlp_data_obj_info
dlp_data_obj_info: required (object)
DLP 데이터 객체

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체/그룹 ID

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
객체 유형이  문자열(1),	정규식(2) 일 때 값
Base64 인코딩/디코딩 필요

value2
value2: required (string)
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

dlp_excpt_prf_info
dlp_excpt_prf_info: required (object)
DLP 예외 프로파일

dlp_excpt_prf_id
dlp_excpt_prf_id: required (integer)
예외 프로파일 ID

name
name: required (string)
예외 프로파일 이름

descdesc: required (string)
예외 프로파일 설명

useuse: required (integer)
사용여부
사용안함:	0,	사용:	1

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_prf_id":	1,
				"dlp_arch_rule_id":	2,
				"dlp_data_obj_info":	{
						"dlp_data_obj_id":	10001,
						"type":	0,
						"name":	"객체	이름",
						"desc":	"객체	설명",
						"use":	1
				},
				"dlp_excpt_prf_info":	{
						"dlp_excpt_prf_id":	1,
						"name":	"예외	프로파일	이름",
						"desc":	"예외	프로파일	설명",
						"use":	1
				},
				"name":	"New	아카이브	정책	이름",
				"use":	1,
				"direct":	1,
				"action":	3,
				"log_use":	1,
				"desc":	"New	아카이브	정책	설명",
			"smtp_use":	0,
				"smtp_attach":	1,
				"smtp_header":	1,
				"smtp_body":	0,
				"pop3_use":	0,
				"pop3_attach":	0,
				"pop3_header":	0,
				"pop3_body":	0,
				"imap_use":	0,
				"imap_attach":	0,
				"imap_header":	0,
				"imap_body":	0,
				"http_use":	0,
				"http_rqst_header":	0,
				"http_rqst_file":	0,
				"http_rqst_body":	0,
				"http_rsps_header":	0,
				"http_rsps_file":	0,
				"http_rsps_body":	0,
				"ftp_use":	0,
				"ftp_rqst_file":	0,
				"ftp_rqst_cmd":	0,
				"ftp_rsps_file":	0,
				"ftp_rsps_cmd":	0
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

/dlp/profiles/{ppk}/archives

DLP 아카이브 정책 목록을 (일괄)수정한다.

Request

URI Parameters

ppkppk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

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
				{"dlp_arch_rule_id":	1,	"use":	0},
				{"dlp_arch_rule_id":	2,	"use":	0}
		]
}

Response

HTTP status code 200

DLP 아카이브 정책 목록 수정 성공

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

/dlp/profiles/{ppk}/archives

DLP 아카이브 정책 목록을 (일괄)삭제한다.

Request

URI Parameters

ppkppk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

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
items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"dlp_arch_rule_id":	1},
				{"dlp_arch_rule_id":	2}
		]
}

Response

HTTP status code 200

DLP 아카이브 정책 목록 삭제 성공

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

/dlp/profiles/{ppk}/archives/{pk}

DLP 필터 정책을(를) 조회한다.

Request

URI Parameters

ppkppk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

pkpk: required (integer)
정책 ID( dlp_arch_rule_id )

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

DLP 필터 정책 조회 성공

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

name: required (string - minLength: 1 - maxLength: 32)
name
정책 이름

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

direct: required (one of 1, 2, 3)
direct

방향
내부:1,	외부:	2,	양방향:	3

action
action: required (one of 0, 1)
유형
탐지:	0,	차단:	1

log_use
log_use: required (one of 0, 1)
로그 사용 여부
사용안함:	0,	사용:	1

dump_use: required (one of 0, 1)
dump_use
덤프 사용 여부
사용안함:	0,	사용:	1

mail_use
mail_use: required (one of 0, 1)
메일 사용 여부
사용안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

smtp_use
smtp_use: required (one of 0, 1)
SMTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

pop3_use
pop3_use: required (one of 0, 1)
POP3 프로토콜 사용 여부
사용안함:	0,	사용:	1

imap_use
imap_use: required (one of 0, 1)
IMAP 프로토콜 사용 여부
사용안함:	0,	사용:	1

http_use
http_use: required (one of 0, 1)
HTTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

ftp_use: required (one of 0, 1)
ftp_use
FTP 프로토콜 사용 여부
사용안함:	0,	사용:	1

smtp_cmd
smtp_cmd: required (one of 0, 1)
SMTP - command
사용안함:	0,	사용:	1

smtp_rsps
smtp_rsps: required (one of 0, 1)
SMTP - response
사용안함:	0,	사용:	1

smtp_sndr
smtp_sndr: required (one of 0, 1)
SMTP - sender
사용안함:	0,	사용:	1

smtp_rcvr
smtp_rcvr: required (one of 0, 1)
SMTP - receiver
사용안함:	0,	사용:	1

smtp_sbjt: required (one of 0, 1)
smtp_sbjt
SMTP - subject
사용안함:	0,	사용:	1

smtp_header
smtp_header: required (one of 0, 1)
SMTP - header
사용안함:	0,	사용:	1

smtp_body
smtp_body: required (one of 0, 1)
SMTP - body
사용안함:	0,	사용:	1

smtp_fname
smtp_fname: required (one of 0, 1)
SMTP - filename
사용안함:	0,	사용:	1

smtp_fbody
smtp_fbody: required (one of 0, 1)
SMTP - filebody
사용안함:	0,	사용:	1

smtp_ftype: required (one of 0, 1)
smtp_ftype
SMTP - filetype
사용안함:	0,	사용:	1

smtp_cntn_size
smtp_cntn_size: required (one of 0, 1)
SMTP - content size
사용안함:	0,	사용:	1

smtp_attach_size
smtp_attach_size: required (one of 0, 1)
SMTP - attachment size
사용안함:	0,	사용:	1

pop3_sndr
pop3_sndr: required (one of 0, 1)
POP - sender
사용안함:	0,	사용:	1

pop3_rcvr
pop3_rcvr: required (one of 0, 1)
POP - receiver
사용안함:	0,	사용:	1

pop3_sbjt: required (one of 0, 1)
pop3_sbjt
POP - subject
사용안함:	0,	사용:	1

pop3_header
pop3_header: required (one of 0, 1)
POP - header
사용안함:	0,	사용:	1

pop3_body
pop3_body: required (one of 0, 1)
POP - body
사용안함:	0,	사용:	1

pop3_fname
pop3_fname: required (one of 0, 1)
POP - filename
사용안함:	0,	사용:	1

pop3_fbody
pop3_fbody: required (one of 0, 1)
POP - filebody
사용안함:	0,	사용:	1

pop3_ftype: required (one of 0, 1)
pop3_ftype
POP - filetype
사용안함:	0,	사용:	1

pop3_cntn_size
pop3_cntn_size: required (one of 0, 1)
POP - content size
사용안함:	0,	사용:	1

pop3_attach_size
pop3_attach_size: required (one of 0, 1)
POP - attachment size
사용안함:	0,	사용:	1

imap_sndr
imap_sndr: required (one of 0, 1)
IMAP - sender
사용안함:	0,	사용:	1

imap_rcvr
imap_rcvr: required (one of 0, 1)
IMAP - receiver
사용안함:	0,	사용:	1

imap_sbjt: required (one of 0, 1)
imap_sbjt
IMAP - subject
사용안함:	0,	사용:	1

imap_header
imap_header: required (one of 0, 1)
IMAP - header
사용안함:	0,	사용:	1

imap_body
imap_body: required (one of 0, 1)
IMAP - body
사용안함:	0,	사용:	1

imap_fname
imap_fname: required (one of 0, 1)
IMAP - filename
사용안함:	0,	사용:	1

imap_fbody
imap_fbody: required (one of 0, 1)
IMAP - filebody
사용안함:	0,	사용:	1

imap_ftype: required (one of 0, 1)
imap_ftype
IMAP - filetype
사용안함:	0,	사용:	1

imap_cntn_size
imap_cntn_size: required (one of 0, 1)
IMAP - content size
사용안함:	0,	사용:	1

imap_attach_size
imap_attach_size: required (one of 0, 1)
IMAP - attachment size
사용안함:	0,	사용:	1

http_rqst_method
http_rqst_method: required (one of 0, 1)
HTTP(Request) - method
사용안함:	0,	사용:	1

http_rqst_url
http_rqst_url: required (one of 0, 1)
HTTP(Request) - url
사용안함:	0,	사용:	1

http_rqst_url_raw
http_rqst_url_raw: required (one of 0, 1)
HTTP(Request) - url_raw
사용안함:	0,	사용:	1

http_rqst_host
http_rqst_host: required (one of 0, 1)
HTTP(Request) - host
사용안함:	0,	사용:	1

http_rqst_start_line
http_rqst_start_line: required (one of 0, 1)
HTTP(Request) - start_line
사용안함:	0,	사용:	1

http_rqst_header
http_rqst_header: required (one of 0, 1)
HTTP(Request) - header
사용안함:	0,	사용:	1

http_rqst_header_raw
http_rqst_header_raw: required (one of 0, 1)
HTTP(Request) - header_raw
사용안함:	0,	사용:	1

http_rqst_body
http_rqst_body: required (one of 0, 1)
HTTP(Request) - body
사용안함:	0,	사용:	1

http_rqst_body_raw
http_rqst_body_raw: required (one of 0, 1)
HTTP(Request) - body_raw
사용안함:	0,	사용:	1

http_rqst_fname: required (one of 0, 1)
http_rqst_fname
HTTP(Request) - filename
사용안함:	0,	사용:	1

http_rqst_fbody
http_rqst_fbody: required (one of 0, 1)
HTTP(Request) - filebody
사용안함:	0,	사용:	1

http_rqst_ftype
http_rqst_ftype: required (one of 0, 1)
HTTP(Request) - filetype
사용안함:	0,	사용:	1

http_rqst_cntn_size
http_rqst_cntn_size: required (one of 0, 1)
HTTP(Request) - content size
사용안함:	0,	사용:	1

http_rqst_file_size
http_rqst_file_size: required (one of 0, 1)
HTTP(Request) - file size
사용안함:	0,	사용:	1

http_rsps_start_line: required (one of 0, 1)
http_rsps_start_line

HTTP(Response) - start_line
사용안함:	0,	사용:	1

http_rsps_header
http_rsps_header: required (one of 0, 1)
HTTP(Response) - header
사용안함:	0,	사용:	1

http_rsps_header_raw
http_rsps_header_raw: required (one of 0, 1)
HTTP(Response) - header_raw
사용안함:	0,	사용:	1

http_rsps_body: required (one of 0, 1)
http_rsps_body
HTTP(Response) - body
사용안함:	0,	사용:	1

http_rsps_body_raw
http_rsps_body_raw: required (one of 0, 1)
HTTP(Response) - body_raw
사용안함:	0,	사용:	1

http_rsps_fname
http_rsps_fname: required (one of 0, 1)
HTTP(Response) - filename
사용안함:	0,	사용:	1

http_rsps_fbody
http_rsps_fbody: required (one of 0, 1)
HTTP(Response) - filebody
사용안함:	0,	사용:	1

http_rsps_ftype
http_rsps_ftype: required (one of 0, 1)
HTTP(Response) - filetype
사용안함:	0,	사용:	1

http_rsps_cntn_size: required (one of 0, 1)
http_rsps_cntn_size
HTTP(Response) - content size
사용안함:	0,	사용:	1

http_rsps_file_size
http_rsps_file_size: required (one of 0, 1)
HTTP(Response) - file size
사용안함:	0,	사용:	1

ftp_rqst_cmd
ftp_rqst_cmd: required (one of 0, 1)
FTP(To Server) - command
사용안함:	0,	사용:	1

ftp_rqst_fname
ftp_rqst_fname: required (one of 0, 1)
FTP(To Server) - filename
사용안함:	0,	사용:	1

ftp_rqst_fbody
ftp_rqst_fbody: required (one of 0, 1)
FTP(To Server) - filebody
사용안함:	0,	사용:	1

ftp_rqst_ftype: required (one of 0, 1)
ftp_rqst_ftype
FTP(To Server) - filetype
사용안함:	0,	사용:	1

ftp_rqst_file_size
ftp_rqst_file_size: required (one of 0, 1)
FTP(To Server) - file size
사용안함:	0,	사용:	1

ftp_rsps_rsps
ftp_rsps_rsps: required (one of 0, 1)
FTP(From Server) - response
사용안함:	0,	사용:	1

ftp_rsps_fname
ftp_rsps_fname: required (one of 0, 1)
FTP(From Server) - filename
사용안함:	0,	사용:	1

ftp_rsps_fbody
ftp_rsps_fbody: required (one of 0, 1)
FTP(From Server) - filebody
사용안함:	0,	사용:	1

ftp_rsps_ftype: required (one of 0, 1)
ftp_rsps_ftype
FTP(From Server) - filetype
사용안함:	0,	사용:	1

ftp_rsps_file_size
ftp_rsps_file_size: required (one of 0, 1)
FTP(From Server) - file size
사용안함:	0,	사용:	1

dlp_prf_id
dlp_prf_id: required (integer)
DLP 프로파일 ID

dlp_filter_rule_id
dlp_filter_rule_id: required (integer)
DLP 필터 정책 ID

dlp_data_obj_info: required (object)
dlp_data_obj_info
DLP 데이터 객체

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체/그룹 ID

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

value1: required (string)
value1

객체 유형이  문자열(1),	정규식(2) 일 때 값
Base64 인코딩/디코딩 필요

value2
value2: required (string)
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

dlp_excpt_prf_info
dlp_excpt_prf_info: required (object)
DLP 예외 프로파일

dlp_excpt_prf_id: required (integer)
dlp_excpt_prf_id
예외 프로파일 ID

name
name: required (string)
예외 프로파일 이름

descdesc: required (string)
예외 프로파일 설명

useuse: required (integer)
사용여부
사용안함:	0,	사용:	1

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_prf_id":	1,
				"dlp_arch_rule_id":	1,
				"dlp_data_obj_info":	{
						"dlp_data_obj_id":	10001,
						"type":	0,
						"name":	"객체	이름",
						"desc":	"객체	설명",
						"use":	1
				},
				"dlp_excpt_prf_info":	{
						"dlp_excpt_prf_id":	1,
						"name":	"예외	프로파일	이름",
						"desc":	"예외	프로파일	설명",
						"use":	1
				},
				"name":	"아카이브	정책	이름",
				"use":	1,
				"direct":	1,
				"action":	3,
				"log_use":	1,
				"desc":	"아카이브	정책	설명",
				"smtp_use":	0,
				"smtp_attach":	1,
				"smtp_header":	1,
				"smtp_body":	0,
				"pop3_use":	0,
				"pop3_attach":	0,
				"pop3_header":	0,
				"pop3_body":	0,
				"imap_use":	0,
				"imap_attach":	0,
				"imap_header":	0,
				"imap_body":	0,
				"http_use":	0,
				"http_rqst_header":	0,
				"http_rqst_file":	0,
				"http_rqst_body":	0,
				"http_rsps_header":	0,
				"http_rsps_file":	0,
				"http_rsps_body":	0,
				"ftp_use":	0,
				"ftp_rqst_file":	0,
				"ftp_rqst_cmd":	0,
				"ftp_rsps_file":	0,
				"ftp_rsps_cmd":	0
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

/dlp/profiles/{ppk}/archives/{pk}

DLP 필터 정책을(를) 수정한다.

Request

URI Parameters

ppkppk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

pkpk: required (integer)
정책 ID( dlp_arch_rule_id )

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
name: required (string)
아카이브 정책 이름

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

direct
direct: required (one of 1, 2, 3)
방향
내부:1,	외부:	2,	양방향:	3

action
action: required (integer - default: 3)
대응
Archive:	3

log_use
log_use: required (one of 0, 1)
로그 사용 여부
사용안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

smtp_use
smtp_use: required (one of 0, 1)
SMTP 사용 여부
사용안함:	0,	사용:	1

smtp_attach
smtp_attach: required (one of 0, 1)
SMTP - attachment
사용안함:	0,	사용:	1

smtp_header: required (one of 0, 1)
smtp_header
SMTP - header
사용안함:	0,	사용:	1

smtp_body
smtp_body: required (one of 0, 1)
SMTP - body
사용안함:	0,	사용:	1

pop3_use
pop3_use: required (one of 0, 1)
POP3 사용 여부
사용안함:	0,	사용:	1

pop3_attach
pop3_attach: required (one of 0, 1)
POP3 - attachment
사용안함:	0,	사용:	1

pop3_header
pop3_header: required (one of 0, 1)
POP3 - header
사용안함:	0,	사용:	1

pop3_body: required (one of 0, 1)
pop3_body
POP3 - body
사용안함:	0,	사용:	1

imap_use
imap_use: required (one of 0, 1)
IMAP 사용 여부
사용안함:	0,	사용:	1

imap_attach
imap_attach: required (one of 0, 1)
IMAP - attachment
사용안함:	0,	사용:	1

imap_header
imap_header: required (one of 0, 1)
IMAP - header
사용안함:	0,	사용:	1

imap_body
imap_body: required (one of 0, 1)
IMAP - body
사용안함:	0,	사용:	1

http_use: required (one of 0, 1)
http_use
HTTP 사용 여부
사용안함:	0,	사용:	1

http_rqst_header
http_rqst_header: required (one of 0, 1)
HTTP(Request) - header
사용안함:	0,	사용:	1

http_rqst_file
http_rqst_file: required (one of 0, 1)
HTTP(Request) - file
사용안함:	0,	사용:	1

http_rqst_body
http_rqst_body: required (one of 0, 1)
HTTP(Request) - body
사용안함:	0,	사용:	1

http_rsps_header
http_rsps_header: required (one of 0, 1)
HTTP(Response) - header
사용안함:	0,	사용:	1

http_rsps_file
http_rsps_file: required (one of 0, 1)
HTTP(Response) - file
사용안함:	0,	사용:	1

http_rsps_body
http_rsps_body: required (one of 0, 1)
HTTP(Response) - body
사용안함:	0,	사용:	1

ftp_use
ftp_use: required (one of 0, 1)
FTP 사용 여부
사용안함:	0,	사용:	1

ftp_rqst_file
ftp_rqst_file: required (one of 0, 1)
FTP(To Server) - file
사용안함:	0,	사용:	1

ftp_rqst_cmd
ftp_rqst_cmd: required (one of 0, 1)
FTP(To Server) - command
사용안함:	0,	사용:	1

ftp_rsps_file: required (one of 0, 1)
ftp_rsps_file

FTP(From Server) - file
사용안함:	0,	사용:	1

ftp_rsps_cmd
ftp_rsps_cmd: required (one of 0, 1)
FTP(From Server) - command
사용안함:	0,	사용:	1

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체 ID

dlp_excpt_prf_id
dlp_excpt_prf_id: required (integer)
DLP 예외 프로파일 ID

Example:
Example

{
		"dlp_data_obj_id":	10001,
		"dlp_excpt_prf_id":	1,
		"name":	"아카이브	정책	이름",
		"use":	1,
		"direct":	1,
		"action":	3,
		"log_use":	1,
		"desc":	"아카이브	정책	설명",
		"smtp_use":	0,
		"smtp_attach":	1,
		"smtp_header":	1,
		"smtp_body":	0,
		"pop3_use":	0,
		"pop3_attach":	0,
		"pop3_header":	0,
		"pop3_body":	0,
		"imap_use":	0,
		"imap_attach":	0,
		"imap_header":	0,
		"imap_body":	0,
		"http_use":	0,
		"http_rqst_header":	0,
		"http_rqst_file":	0,
		"http_rqst_body":	0,
		"http_rsps_header":	0,
		"http_rsps_file":	0,
		"http_rsps_body":	0,
		"ftp_use":	0,
		"ftp_rqst_file":	0,
		"ftp_rqst_cmd":	0,
		"ftp_rsps_file":	0,
		"ftp_rsps_cmd":	0
}

Response

HTTP status code 200

DLP 필터 정책 수정 성공

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
name: required (string)
아카이브 정책 이름

useuse: required (one of 0, 1)
사용 여부
사용안함:	0,	사용:	1

direct
direct: required (one of 1, 2, 3)
방향
내부:1,	외부:	2,	양방향:	3

action
action: required (integer - default: 3)
대응
Archive:	3

log_use
log_use: required (one of 0, 1)
로그 사용 여부
사용안함:	0,	사용:	1

descdesc: (string - maxLength: 128)
설명

smtp_use
smtp_use: required (one of 0, 1)
SMTP 사용 여부
사용안함:	0,	사용:	1

smtp_attach: required (one of 0, 1)
smtp_attach
SMTP - attachment
사용안함:	0,	사용:	1

smtp_header
smtp_header: required (one of 0, 1)
SMTP - header
사용안함:	0,	사용:	1

smtp_body
smtp_body: required (one of 0, 1)
SMTP - body
사용안함:	0,	사용:	1

pop3_use: required (one of 0, 1)
pop3_use
POP3 사용 여부
사용안함:	0,	사용:	1

pop3_attach
pop3_attach: required (one of 0, 1)
POP3 - attachment
사용안함:	0,	사용:	1

pop3_header
pop3_header: required (one of 0, 1)
POP3 - header
사용안함:	0,	사용:	1

pop3_body
pop3_body: required (one of 0, 1)
POP3 - body
사용안함:	0,	사용:	1

imap_use
imap_use: required (one of 0, 1)
IMAP 사용 여부
사용안함:	0,	사용:	1

imap_attach: required (one of 0, 1)
imap_attach
IMAP - attachment
사용안함:	0,	사용:	1

imap_header
imap_header: required (one of 0, 1)
IMAP - header
사용안함:	0,	사용:	1

imap_body
imap_body: required (one of 0, 1)
IMAP - body
사용안함:	0,	사용:	1

http_use
http_use: required (one of 0, 1)
HTTP 사용 여부
사용안함:	0,	사용:	1

http_rqst_header
http_rqst_header: required (one of 0, 1)
HTTP(Request) - header
사용안함:	0,	사용:	1

http_rqst_file: required (one of 0, 1)
http_rqst_file
HTTP(Request) - file
사용안함:	0,	사용:	1

http_rqst_body
http_rqst_body: required (one of 0, 1)
HTTP(Request) - body
사용안함:	0,	사용:	1

http_rsps_header
http_rsps_header: required (one of 0, 1)
HTTP(Response) - header
사용안함:	0,	사용:	1

http_rsps_file
http_rsps_file: required (one of 0, 1)
HTTP(Response) - file
사용안함:	0,	사용:	1

http_rsps_body
http_rsps_body: required (one of 0, 1)
HTTP(Response) - body
사용안함:	0,	사용:	1

ftp_use
ftp_use: required (one of 0, 1)
FTP 사용 여부
사용안함:	0,	사용:	1

ftp_rqst_file
ftp_rqst_file: required (one of 0, 1)
FTP(To Server) - file
사용안함:	0,	사용:	1

ftp_rqst_cmd
ftp_rqst_cmd: required (one of 0, 1)
FTP(To Server) - command
사용안함:	0,	사용:	1

ftp_rsps_file
ftp_rsps_file: required (one of 0, 1)
FTP(From Server) - file
사용안함:	0,	사용:	1

ftp_rsps_cmd
ftp_rsps_cmd: required (one of 0, 1)
FTP(From Server) - command
사용안함:	0,	사용:	1

dlp_prf_id
dlp_prf_id: required (integer)
DLP 프로파일 ID

dlp_arch_rule_id
dlp_arch_rule_id: required (integer)
DLP 아카이브 정책 ID

dlp_data_obj_info
dlp_data_obj_info: required (object)
DLP 데이터 객체

dlp_data_obj_id
dlp_data_obj_id: required (integer)
DLP 데이터 객체/그룹 ID

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

value1: required (string)
value1
객체 유형이  문자열(1),	정규식(2) 일 때 값
Base64 인코딩/디코딩 필요

value2
value2: required (string)
객체 유형이  크기(3)  또는  파일유형(4)  일 때 값
크기	유효성	체크:	최소값:	2bytes,	최대값:	2,147,483,648bytes
파일유형	유효성	체크:	GET	/api/op/dlp/filetype/types	응답	결과의	id	값

dlp_excpt_prf_info
dlp_excpt_prf_info: required (object)
DLP 예외 프로파일

dlp_excpt_prf_id
dlp_excpt_prf_id: required (integer)
예외 프로파일 ID

name
name: required (string)
예외 프로파일 이름

descdesc: required (string)
예외 프로파일 설명

useuse: required (integer)
사용여부
사용안함:	0,	사용:	1

Example:
Example

{
		"code":	"ok",
		"result":	{
				"dlp_prf_id":	1,
				"dlp_arch_rule_id":	1,
				"dlp_data_obj_info":	{
						"dlp_data_obj_id":	10001,
						"type":	0,
						"name":	"객체	이름",
						"desc":	"객체	설명",
						"use":	1
				},
				"dlp_excpt_prf_info":	{
						"dlp_excpt_prf_id":	1,
						"name":	"예외	프로파일	이름",
						"desc":	"예외	프로파일	설명",
						"use":	1
				},
				"name":	"아카이브	정책	이름",
				"use":	1,
				"direct":	1,
				"action":	3,
				"log_use":	1,
				"desc":	"아카이브	정책	설명",
				"smtp_use":	0,
				"smtp_attach":	1,
				"smtp_header":	1,
				"smtp_body":	0,
				"pop3_use":	0,
				"pop3_attach":	0,
				"pop3_header":	0,
				"pop3_body":	0,
				"imap_use":	0,
				"imap_attach":	0,
				"imap_header":	0,
				"imap_body":	0,
				"http_use":	0,
				"http_rqst_header":	0,
				"http_rqst_file":	0,
				"http_rqst_body":	0,
				"http_rsps_header":	0,
				"http_rsps_file":	0,
				"http_rsps_body":	0,
				"ftp_use":	0,
				"ftp_rqst_file":	0,
				"ftp_rqst_cmd":	0,
				"ftp_rsps_file":	0,
				"ftp_rsps_cmd":	0
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

dev_t: (string)
dev_t
개발용 메시지

Example:
Example

{
		"code":	"12001",
		"message":	"존재하지	않는	항목입니다."
}

DELETE

/dlp/profiles/{ppk}/archives/{pk}

DLP 필터 정책을(를) 삭제한다.

Request

URI Parameters

ppkppk: required (integer)
DLP 프로파일 ID( dlp_prf_id )

pkpk: required (integer)
정책 ID( dlp_arch_rule_id )

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

DLP 필터 정책 삭제 성공

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

DLP 프로파일 목록 적용/취소

PUT

/command/dlp-profiles/apply

DLP 프로파일을 적용합니다.

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

DLP 프로파일 적용 성공

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

/command/dlp-profiles/cancel

DLP 프로파일을 취소합니다.

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

DLP 프로파일 취소 성공

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

