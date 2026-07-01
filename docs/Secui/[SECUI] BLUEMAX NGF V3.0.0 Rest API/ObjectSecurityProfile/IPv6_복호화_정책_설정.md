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

IPv6 복호화 정책 설정 REST API 문서

https://{url}/api/op

urlurl: required (string)
IP:PORT

Example:
Example

https://192.168.100.100/api/op

미러링 인터페이스

/ssl/mirror/interfaces

IPv6 복호화 정책 설정

[호스트 객체 목록]
GET	{{url}}/api/op/host/6/objects
GET	{{url}}/api/op/network/6/objects?q=zone%3D1
zone(내부망: 1, 외부망: 2, DMZ: 3)

[네트워크 객체 목록]
GET	{{url}}/api/op/network/6/objects
GET	{{url}}/api/op/network/6/objects?q=zone%3D2
zone(내부망: 1, 외부망: 2, DMZ: 3)

[서비스 객체 목록]
GET	{{url}}/api/op/service/objects
서비스 유형(srv_cate)이 SSL, HTTPS, SMTPS, POP3S, IMAPS, FTPS 인 서비스 객체만 허용됨

[SSL 설정 인증서 목록]
GET	{{url}}/api/sm/cert-issue/ssl-certs

/ssl/6/policies

/ssl/6/policies/{pk}

IPv6 복호화 정책 설정 적용/취소

/command/ssl-6-policies/apply

/command/ssl-6-policies/cancel

미러링 인터페이스

GET

/ssl/mirror/interfaces

미러링 인터페이스 목록을 조회한다.

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

미러링 인터페이스 목록 조회 성공

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
result: required (array of 인터페이스)
결과 데이터

Items: 인터페이스
Items

ifc_id
ifc_id: required (integer)
인터페이스 ID

name
name: required (string)
인터페이스 명

Example:
Example

{
		"code":	"ok",
		"result":	[
				{
						"ifc_id":	2,
						"name":	"eth1"
				},
				{
						"ifc_id":	3,
						"name":	"eth2"
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

IPv6 복호화 정책 설정

GET

/ssl/6/policies

복호화 정책 설정 목록을 조회한다.

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

복호화 정책 설정 목록 조회 성공

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
result: required (array of GetPolicy)
결과 데이터

Items: GetPolicy
Items

seqseq: required (integer - minimum: 1 - maximum: 1023)
복호화 정책 순번

useuse: required (one of 0, 1 - default: 1)
사용 여부
사용	안함:	0,	사용:	1

descdesc: required (string - minLength: 0 - maxLength: 128)
설명

ssl_trfc_chk_cert_id
ssl_trfc_chk_cert_id: required (integer)
SSL 인증서 ID

dec_mirror_enable
dec_mirror_enable: required (one of 0, 1 - default: 0)
복화화 트래픽 미러링 사용 여부
0:	사용안함,	1:	사용

dec_https_port
dec_https_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(HTTPS)
default:	null(기존	서버	포트	사용)

dec_smtps_port: required (integer - minimum: 1 - maximum: 65535)
dec_smtps_port
복화화 트래픽 미러링 서버 포트(SMTPS)
default:	null(기존	서버	포트	사용)

dec_pop3s_port
dec_pop3s_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(POP3S)
default:	null(기존	서버	포트	사용)

dec_imaps_port: required (integer - minimum: 1 - maximum: 65535)
dec_imaps_port
복화화 트래픽 미러링 서버 포트(IMAPS)
default:	null(기존	서버	포트	사용)

dec_ftps_port
dec_ftps_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(FTPS)
default:	null(기존	서버	포트	사용)

ssh_shell_act
ssh_shell_act: required (one of 0, 1 - default: 0)
SSH SHELL 기반 접속 허용/거절
0:	허용,	1:	거절

ssh_exec_act
ssh_exec_act: required (one of 0, 1 - default: 0)
SSH Exec(1회성 명령) 허용/거절  0:	허용,	1:	거절

ssh_x11_act
ssh_x11_act: required (one of 0, 1 - default: 0)
SSH GUI 기반 접속 허용/거절  0:	허용,	1:	거절

ssh_sftp_act
ssh_sftp_act: required (one of 0, 1 - default: 0)
SSH SFTP 기반 접속 허용/거절  0:	허용,	1:	거절

ssh_port_forward_act
ssh_port_forward_act: required (one of 0, 1 - default: 0)
SSH Port Forward 사용 허용/거절  0:	허용,	1:	거절

ssl_trfc_chk_rule_id
ssl_trfc_chk_rule_id: required (integer)
복호화 정책 ID

client
client: required (array of 호스트/네트워크 객체)
Items: 호스트/네트워크 객체
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체 이름 (ANY:	Any)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

server: required (array of 호스트/네트워크 객체)
server
Items: 호스트/네트워크 객체
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체 이름 (ANY:	Any)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

service: required (array of 서비스 객체)
service
Items: 서비스 객체
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

prtcprtc: (object)
프로토콜 정보
상세	정보는	서비스	객체	참고

srv_cate
srv_cate: (integer)
서비스 유형

start_port
start_port: (string)
출발지 포트

srv_port
srv_port: (string)
서비스 포트

life_time: (integer)
life_time
Lifetime(초)

prioprio: (integer)
우선 순위

descdesc: (string)
객체 설명

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt: required (string)
cfg_dt
수정 날짜

refref: required (object)
참조 정보
상세	정보는	서비스	객체	참고

certcert: required (object)

ssl_trfc_chk_cert_id
ssl_trfc_chk_cert_id: required (integer)
인증서 ID

cert_name
cert_name: required (string)
인증서 이름

cert_type
cert_type: required (integer)
인증서 타입 (사설	인증서:	0,	신뢰할	수	있는	루트	인증서:	1)

subject
subject: required (string)
인증서 세부 정보

issuer
issuer: required (string)
인증서 세부 정보

expire_period
expire_period: required (string)
인증서 만료 기간

dec_mirror_ifc_select_list: required (array of 인터페이스)
dec_mirror_ifc_select_list
미러링 인터페이스 목록

Items: 인터페이스
Items

ifc_id
ifc_id: required (integer)
인터페이스 ID

name: required (string)
name
인터페이스 명

Example:
Example

{
		"code":	"ok",
		"result":	[{
				"ssl_trfc_chk_rule_id":	1,
				"seq":	1,
				"use":	1,
				"client":	[
						{
								"addr_obj_id":	1,
								"ip_ver":	2,
								"name":	"호스트객체1",
								"zone":	1,
								"addr_obj_type":	1
						}
				],
				"server":	[
						{
								"addr_obj_id":	2,
								"ip_ver":	2,
								"name":	"네트워크객체2",
								"zone":	2,
								"addr_obj_type":	2
						}
				],
				"service":	[
						{
								"srv_obj_id":	1,
								"srv_obj_type":	1,
								"name":	"FTPS",
								"srv_cate":	19,
								"start_port":	"*",
								"srv_port":	"990",
								"life_time":	1800,
								"prio":	38,
								"desc":	"",
								"pre_def":	1,
								"prtc":	{
										"prtc_obj_id":	5,
										"name":	"TCP",
										"prtc":	6,
										"desc":	"Transmission	Control	Protocol",
										"pre_def":	1
								},
								"cfg_adm_id":	0,
								"cfg_adm":	"",
								"cfg_dt":	"2019-01-11	12:09:58",
								"ref":	{}
						}
				],
				"desc":	"복호화	정책	설명",
				"ssl_trfc_chk_cert_id":	1,
				"cert":	{
						"ssl_trfc_chk_cert_id":	1,
						"cert_name":	"cacert",
						"cert_type":	0,
						"expire_period":	"August	14	11:13:57	2019	GMT	~	August	13	11:13:57	2020	GMT",
						"issuer":	"/C=KR/ST=example/L=example/O=example/OU=example/CN=example/emailAddress=example@example.com",
						"subject":	"/C=KR/ST=example/L=example/O=example/OU=example/CN=example/emailAddress=example@example.com"
				},
				"ssh_shell_act":	0,
				"ssh_exec_act":	0,
				"ssh_x11_act":	0,
				"ssh_sftp_act":	0,
				"ssh_port_forward_act":	0,
				"dec_mirror_enable":	0,
				"dec_https_port":	null,
				"dec_smtps_port":	null,
				"dec_imaps_port":	null,
				"dec_pop3s_port":	null,
				"dec_ftps_port":	null,
				"dec_mirror_ifc_select_list":	[
						{
								"ifc_id":	2,
								"name":	"eth1"
						}
				]
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

/ssl/6/policies

복호화 정책 설정를 추가한다.

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

seqseq: required (integer - minimum: 1 - maximum: 1023)
복호화 정책 순번

useuse: required (one of 0, 1 - default: 1)
사용 여부
사용	안함:	0,	사용:	1

descdesc: required (string - minLength: 0 - maxLength: 128)
설명

ssl_trfc_chk_cert_id
ssl_trfc_chk_cert_id: required (integer)
SSL 인증서 ID

dec_mirror_enable
dec_mirror_enable: required (one of 0, 1 - default: 0)
복화화 트래픽 미러링 사용 여부
0:	사용안함,	1:	사용

dec_https_port
dec_https_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(HTTPS)
default:	null(기존	서버	포트	사용)

dec_smtps_port
dec_smtps_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(SMTPS)
default:	null(기존	서버	포트	사용)

dec_pop3s_port: required (integer - minimum: 1 - maximum: 65535)
dec_pop3s_port
복화화 트래픽 미러링 서버 포트(POP3S)
default:	null(기존	서버	포트	사용)

dec_imaps_port
dec_imaps_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(IMAPS)
default:	null(기존	서버	포트	사용)

dec_ftps_port
dec_ftps_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(FTPS)
default:	null(기존	서버	포트	사용)

ssh_shell_act: required (one of 0, 1 - default: 0)
ssh_shell_act
SSH SHELL 기반 접속 허용/거절
0:	허용,	1:	거절

ssh_exec_act
ssh_exec_act: required (one of 0, 1 - default: 0)
SSH Exec(1회성 명령) 허용/거절  0:	허용,	1:	거절

ssh_x11_act: required (one of 0, 1 - default: 0)
ssh_x11_act
SSH GUI 기반 접속 허용/거절  0:	허용,	1:	거절

ssh_sftp_act
ssh_sftp_act: required (one of 0, 1 - default: 0)
SSH SFTP 기반 접속 허용/거절  0:	허용,	1:	거절

ssh_port_forward_act
ssh_port_forward_act: required (one of 0, 1 - default: 0)
SSH Port Forward 사용 허용/거절  0:	허용,	1:	거절

clnt_addr_obj_id
clnt_addr_obj_id: required (array of 호스트/네트워크 객체)
클라이언트 객체 목록
빈	리스트([])는	ANY

Items: 호스트/네트워크 객체
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

svr_addr_obj_id
svr_addr_obj_id: required (array of 호스트/네트워크 객체)
서버 객체 목록
빈	리스트([])는	ANY

Items: 호스트/네트워크 객체
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

srv_obj_id
srv_obj_id: required (array of 서비스 객체)
서비스 객체 목록
빈	리스트([])는	ANY

Items: 서비스 객체
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2

dec_interface
dec_interface: required (object)
미러링 인터페이스 목록

ifc_id: required (integer)
ifc_id
인터페이스 ID

Example:
Example

{
		"seq":	2,
		"use":	1,
		"clnt_addr_obj_id":	[
				{"addr_obj_id":	1,	"addr_obj_type":	1,	"zone":	1}
		],
		"svr_addr_obj_id":	[
				{"addr_obj_id":	2,	"addr_obj_type":	1,	"zone":	2}
		],
		"srv_obj_id":	[
				{"srv_obj_id":	1}
		],
		"desc":	"복호화	정책	설명",
		"ssl_trfc_chk_cert_id":	1,
		"ssh_shell_act":	0,
		"ssh_exec_act":	0,
		"ssh_x11_act":	0,
		"ssh_sftp_act":	0,
		"ssh_port_forward_act":	0,
		"dec_mirror_enable":	0,
		"dec_https_port":	null,
		"dec_smtps_port":	null,
		"dec_imaps_port":	null,
		"dec_pop3s_port":	null,
		"dec_ftps_port":	null,
		"dec_interface":	[
				{"ifc_id":	2}
		]
}

Response

HTTP status code 200

복호화 정책 설정 추가 성공

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

seqseq: required (integer - minimum: 1 - maximum: 1023)
복호화 정책 순번

useuse: required (one of 0, 1 - default: 1)
사용 여부
사용	안함:	0,	사용:	1

descdesc: required (string - minLength: 0 - maxLength: 128)
설명

ssl_trfc_chk_cert_id
ssl_trfc_chk_cert_id: required (integer)
SSL 인증서 ID

dec_mirror_enable
dec_mirror_enable: required (one of 0, 1 - default: 0)
복화화 트래픽 미러링 사용 여부
0:	사용안함,	1:	사용

dec_https_port
dec_https_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(HTTPS)
default:	null(기존	서버	포트	사용)

dec_smtps_port: required (integer - minimum: 1 - maximum: 65535)
dec_smtps_port
복화화 트래픽 미러링 서버 포트(SMTPS)
default:	null(기존	서버	포트	사용)

dec_pop3s_port
dec_pop3s_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(POP3S)
default:	null(기존	서버	포트	사용)

dec_imaps_port
dec_imaps_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(IMAPS)
default:	null(기존	서버	포트	사용)

dec_ftps_port
dec_ftps_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(FTPS)
default:	null(기존	서버	포트	사용)

ssh_shell_act
ssh_shell_act: required (one of 0, 1 - default: 0)
SSH SHELL 기반 접속 허용/거절
0:	허용,	1:	거절

ssh_exec_act: required (one of 0, 1 - default: 0)
ssh_exec_act
SSH Exec(1회성 명령) 허용/거절  0:	허용,	1:	거절

ssh_x11_act
ssh_x11_act: required (one of 0, 1 - default: 0)
SSH GUI 기반 접속 허용/거절  0:	허용,	1:	거절

ssh_sftp_act
ssh_sftp_act: required (one of 0, 1 - default: 0)
SSH SFTP 기반 접속 허용/거절  0:	허용,	1:	거절

ssh_port_forward_act
ssh_port_forward_act: required (one of 0, 1 - default: 0)
SSH Port Forward 사용 허용/거절  0:	허용,	1:	거절

ssl_trfc_chk_rule_id
ssl_trfc_chk_rule_id: required (integer)
복호화 정책 ID

client: required (array of 호스트/네트워크 객체)
client
Items: 호스트/네트워크 객체
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

ip_ver: required (integer)
ip_ver
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체 이름 (ANY:	Any)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

server
server: required (array of 호스트/네트워크 객체)
Items: 호스트/네트워크 객체
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

ip_ver: required (integer)
ip_ver
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체 이름 (ANY:	Any)

zone: required (integer)
zone

Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

service
service: required (array of 서비스 객체)
Items: 서비스 객체
Items

srv_obj_id: required (integer)
srv_obj_id
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

prtcprtc: (object)
프로토콜 정보
상세	정보는	서비스	객체	참고

srv_cate
srv_cate: (integer)
서비스 유형

start_port
start_port: (string)
출발지 포트

srv_port
srv_port: (string)
서비스 포트

life_time
life_time: (integer)
Lifetime(초)

prioprio: (integer)
우선 순위

descdesc: (string)
객체 설명

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

refref: required (object)
참조 정보
상세	정보는	서비스	객체	참고

certcert: required (object)

ssl_trfc_chk_cert_id
ssl_trfc_chk_cert_id: required (integer)
인증서 ID

cert_name
cert_name: required (string)
인증서 이름

cert_type
cert_type: required (integer)
인증서 타입 (사설	인증서:	0,	신뢰할	수	있는	루트	인증서:	1)

subject
subject: required (string)
인증서 세부 정보

issuer
issuer: required (string)
인증서 세부 정보

expire_period: required (string)
expire_period
인증서 만료 기간

dec_mirror_ifc_select_list
dec_mirror_ifc_select_list: required (array of 인터페이스)
미러링 인터페이스 목록

Items: 인터페이스
Items

ifc_id
ifc_id: required (integer)
인터페이스 ID

name
name: required (string)
인터페이스 명

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ssl_trfc_chk_rule_id":	1,
				"seq":	2,
				"use":	1,
				"client":	[
						{
								"addr_obj_id":	2,
								"ip_ver":	2,
								"name":	"호스트객체2",
								"zone":	1,
								"addr_obj_type":	1
						}
				],
				"server":	[
						{
								"addr_obj_id":	3,
								"ip_ver":	2,
								"name":	"네트워크객체3",
								"zone":	2,
								"addr_obj_type":	2
						}
				],
				"service":	[
						{
								"srv_obj_id":	1,
								"srv_obj_type":	1,
								"name":	"FTPS",
								"srv_cate":	19,
								"start_port":	"*",
								"srv_port":	"990",
								"life_time":	1800,
								"prio":	38,
								"desc":	"",
								"pre_def":	1,
								"prtc":	{
										"prtc_obj_id":	5,
										"name":	"TCP",
										"prtc":	6,
										"desc":	"Transmission	Control	Protocol",
										"pre_def":	1
								},
								"cfg_adm_id":	0,
								"cfg_adm":	"",
								"cfg_dt":	"2019-01-11	12:09:58",
								"ref":	{}
						}
				],
				"desc":	"복호화	정책설명",
				"ssl_trfc_chk_cert_id":	1,
				"cert":	{
						"ssl_trfc_chk_cert_id":	1,
						"cert_name":	"cacert",
						"cert_type":	0,
						"expire_period":	"August	14	11:13:57	2019	GMT	~	August	13	11:13:57	2020	GMT",
						"issuer":	"/C=KR/ST=example/L=example/O=example/OU=example/CN=example/emailAddress=example@example.com",
						"subject":	"/C=KR/ST=example/L=example/O=example/OU=example/CN=example/emailAddress=example@example.com"
				},
				"ssh_shell_act":	0,
				"ssh_exec_act":	0,
				"ssh_x11_act":	0,
				"ssh_sftp_act":	0,
				"ssh_port_forward_act":	0,
				"dec_mirror_enable":	0,
				"dec_https_port":	null,
				"dec_smtps_port":	null,
				"dec_imaps_port":	null,
				"dec_pop3s_port":	null,
				"dec_ftps_port":	null,
				"dec_mirror_ifc_select_list":	[
						{
								"ifc_id":	2,
								"name":	"eth1"
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

PUT

/ssl/6/policies

복호화 정책 설정 목록을 (일괄)수정한다.

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
수정될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"ssl_trfc_chk_rule_id":	1,	"use":	0},
				{"ssl_trfc_chk_rule_id":	2,	"use":	0}
		]
}

Response

HTTP status code 200

복호화 정책 설정 목록 수정 성공

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

/ssl/6/policies

복호화 정책 설정 목록을 (일괄)삭제한다.

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
items
items: required (array of object)
삭제될 정보 목록(최대 100건)

Example:
Example

{
		"items":	[
				{"ssl_trfc_chk_rule_id":	1},
				{"ssl_trfc_chk_rule_id":	2}
		]
}

Response

HTTP status code 200

복호화 정책 설정 목록 삭제 성공

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

GET

/ssl/6/policies/{pk}

복호화 정책 설정을(를) 조회한다.

Request

URI Parameters

pkpk: required (integer)
복호화 정책 ID( ssl_trfc_chk_rule_id )

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

복호화 정책 설정 조회 성공

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

seqseq: required (integer - minimum: 1 - maximum: 1023)
복호화 정책 순번

useuse: required (one of 0, 1 - default: 1)
사용 여부
사용	안함:	0,	사용:	1

descdesc: required (string - minLength: 0 - maxLength: 128)
설명

ssl_trfc_chk_cert_id
ssl_trfc_chk_cert_id: required (integer)
SSL 인증서 ID

dec_mirror_enable
dec_mirror_enable: required (one of 0, 1 - default: 0)
복화화 트래픽 미러링 사용 여부
0:	사용안함,	1:	사용

dec_https_port
dec_https_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(HTTPS)
default:	null(기존	서버	포트	사용)

dec_smtps_port
dec_smtps_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(SMTPS)
default:	null(기존	서버	포트	사용)

dec_pop3s_port: required (integer - minimum: 1 - maximum: 65535)
dec_pop3s_port
복화화 트래픽 미러링 서버 포트(POP3S)
default:	null(기존	서버	포트	사용)

dec_imaps_port
dec_imaps_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(IMAPS)
default:	null(기존	서버	포트	사용)

dec_ftps_port
dec_ftps_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(FTPS)
default:	null(기존	서버	포트	사용)

ssh_shell_act
ssh_shell_act: required (one of 0, 1 - default: 0)
SSH SHELL 기반 접속 허용/거절
0:	허용,	1:	거절

ssh_exec_act
ssh_exec_act: required (one of 0, 1 - default: 0)
SSH Exec(1회성 명령) 허용/거절  0:	허용,	1:	거절

ssh_x11_act
ssh_x11_act: required (one of 0, 1 - default: 0)
SSH GUI 기반 접속 허용/거절  0:	허용,	1:	거절

ssh_sftp_act
ssh_sftp_act: required (one of 0, 1 - default: 0)
SSH SFTP 기반 접속 허용/거절  0:	허용,	1:	거절

ssh_port_forward_act
ssh_port_forward_act: required (one of 0, 1 - default: 0)
SSH Port Forward 사용 허용/거절  0:	허용,	1:	거절

ssl_trfc_chk_rule_id
ssl_trfc_chk_rule_id: required (integer)
복호화 정책 ID

client
client: required (array of 호스트/네트워크 객체)
Items: 호스트/네트워크 객체
Items

addr_obj_id: required (integer)
addr_obj_id
객체 ID (ANY:	0)

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name: required (string)
name
객체 이름 (ANY:	Any)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

server
server: required (array of 호스트/네트워크 객체)
Items: 호스트/네트워크 객체
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name: required (string)
name
객체 이름 (ANY:	Any)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type: required (integer)
addr_obj_type
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

service
service: required (array of 서비스 객체)
Items: 서비스 객체
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

prtcprtc: (object)
프로토콜 정보
상세	정보는	서비스	객체	참고

srv_cate
srv_cate: (integer)
서비스 유형

start_port: (string)
start_port

출발지 포트

srv_port
srv_port: (string)
서비스 포트

life_time: (integer)
life_time
Lifetime(초)

prioprio: (integer)
우선 순위

descdesc: (string)
객체 설명

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt: required (string)
cfg_dt
수정 날짜

refref: required (object)
참조 정보
상세	정보는	서비스	객체	참고

certcert: required (object)

ssl_trfc_chk_cert_id
ssl_trfc_chk_cert_id: required (integer)
인증서 ID

cert_name
cert_name: required (string)
인증서 이름

cert_type
cert_type: required (integer)
인증서 타입 (사설	인증서:	0,	신뢰할	수	있는	루트	인증서:	1)

subject
subject: required (string)
인증서 세부 정보

issuer: required (string)
issuer
인증서 세부 정보

expire_period
expire_period: required (string)
인증서 만료 기간

dec_mirror_ifc_select_list
dec_mirror_ifc_select_list: required (array of 인터페이스)
미러링 인터페이스 목록

Items: 인터페이스
Items

ifc_id
ifc_id: required (integer)
인터페이스 ID

name: required (string)
name
인터페이스 명

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ssl_trfc_chk_rule_id":	1,
				"seq":	2,
				"use":	1,
				"client":	[
						{
								"addr_obj_id":	2,
								"ip_ver":	2,
								"name":	"호스트객체2",
								"zone":	1,
								"addr_obj_type":	1
						}
				],
				"server":	[
						{
								"addr_obj_id":	3,
								"ip_ver":	2,
								"name":	"네트워크객체3",
								"zone":	2,
								"addr_obj_type":	2
						}
				],
				"service":	[
						{
								"srv_obj_id":	1,
								"srv_obj_type":	1,
								"name":	"FTPS",
								"srv_cate":	19,
								"start_port":	"*",
								"srv_port":	"990",
								"life_time":	1800,
								"prio":	38,
								"desc":	"",
								"pre_def":	1,
								"prtc":	{
										"prtc_obj_id":	5,
										"name":	"TCP",
										"prtc":	6,
										"desc":	"Transmission	Control	Protocol",
										"pre_def":	1
								},
								"cfg_adm_id":	0,
								"cfg_adm":	"",
								"cfg_dt":	"2019-01-11	12:09:58",
								"ref":	{}
						}
				],
				"desc":	"복호화	정책	설명",
				"ssl_trfc_chk_cert_id":	1,
				"cert":	{
						"ssl_trfc_chk_cert_id":	1,
						"cert_name":	"cacert",
						"cert_type":	0,
						"expire_period":	"August	14	11:13:57	2019	GMT	~	August	13	11:13:57	2020	GMT",
						"issuer":	"/C=KR/ST=example/L=example/O=example/OU=example/CN=example/emailAddress=example@example.com",
						"subject":	"/C=KR/ST=example/L=example/O=example/OU=example/CN=example/emailAddress=example@example.com"
				},
				"ssh_shell_act":	0,
				"ssh_exec_act":	0,
				"ssh_x11_act":	0,
				"ssh_sftp_act":	0,
				"ssh_port_forward_act":	0,
				"dec_mirror_enable":	0,
				"dec_https_port":	null,
				"dec_smtps_port":	null,
				"dec_imaps_port":	null,
				"dec_pop3s_port":	null,
				"dec_ftps_port":	null,
				"dec_mirror_ifc_select_list":	[
						{
								"ifc_id":	2,
								"name":	"eth1"
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

PUT

/ssl/6/policies/{pk}

복호화 정책 설정을(를) 수정한다.

Request

URI Parameters

pkpk: required (integer)
복호화 정책 ID( ssl_trfc_chk_rule_id )

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

seqseq: required (integer - minimum: 1 - maximum: 1023)

복호화 정책 순번

useuse: required (one of 0, 1 - default: 1)
사용 여부
사용	안함:	0,	사용:	1

descdesc: required (string - minLength: 0 - maxLength: 128)
설명

ssl_trfc_chk_cert_id
ssl_trfc_chk_cert_id: required (integer)
SSL 인증서 ID

dec_mirror_enable
dec_mirror_enable: required (one of 0, 1 - default: 0)
복화화 트래픽 미러링 사용 여부
0:	사용안함,	1:	사용

dec_https_port
dec_https_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(HTTPS)
default:	null(기존	서버	포트	사용)

dec_smtps_port
dec_smtps_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(SMTPS)
default:	null(기존	서버	포트	사용)

dec_pop3s_port
dec_pop3s_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(POP3S)
default:	null(기존	서버	포트	사용)

dec_imaps_port
dec_imaps_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(IMAPS)
default:	null(기존	서버	포트	사용)

dec_ftps_port: required (integer - minimum: 1 - maximum: 65535)
dec_ftps_port
복화화 트래픽 미러링 서버 포트(FTPS)
default:	null(기존	서버	포트	사용)

ssh_shell_act
ssh_shell_act: required (one of 0, 1 - default: 0)
SSH SHELL 기반 접속 허용/거절
0:	허용,	1:	거절

ssh_exec_act
ssh_exec_act: required (one of 0, 1 - default: 0)
SSH Exec(1회성 명령) 허용/거절  0:	허용,	1:	거절

ssh_x11_act
ssh_x11_act: required (one of 0, 1 - default: 0)
SSH GUI 기반 접속 허용/거절  0:	허용,	1:	거절

ssh_sftp_act
ssh_sftp_act: required (one of 0, 1 - default: 0)
SSH SFTP 기반 접속 허용/거절  0:	허용,	1:	거절

ssh_port_forward_act
ssh_port_forward_act: required (one of 0, 1 - default: 0)
SSH Port Forward 사용 허용/거절  0:	허용,	1:	거절

clnt_addr_obj_id: required (array of 호스트/네트워크 객체)
clnt_addr_obj_id
클라이언트 객체 목록
빈	리스트([])는	ANY

Items: 호스트/네트워크 객체
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

svr_addr_obj_id
svr_addr_obj_id: required (array of 호스트/네트워크 객체)
서버 객체 목록
빈	리스트([])는	ANY

Items: 호스트/네트워크 객체
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

srv_obj_id
srv_obj_id: required (array of 서비스 객체)
서비스 객체 목록
빈	리스트([])는	ANY

Items: 서비스 객체
Items

srv_obj_id: required (integer)
srv_obj_id
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2

dec_interface
dec_interface: required (object)
미러링 인터페이스 목록

ifc_id
ifc_id: required (integer)
인터페이스 ID

Example:
Example

{
		"seq":	2,
		"use":	1,
		"clnt_addr_obj_id":	[
				{"addr_obj_id":	1,	"addr_obj_type":	1,	"zone":	1}
		],
		"svr_addr_obj_id":	[
				{"addr_obj_id":	2,	"addr_obj_type":	1,	"zone":	2}
		],
		"srv_obj_id":	[
				{"srv_obj_id":	1}
		],
		"desc":	"복호화	정책	설명",
		"ssl_trfc_chk_cert_id":	1,
		"ssh_shell_act":	0,
		"ssh_exec_act":	0,
		"ssh_x11_act":	0,
		"ssh_sftp_act":	0,
		"ssh_port_forward_act":	0,
		"dec_mirror_enable":	0,
		"dec_https_port":	null,
		"dec_smtps_port":	null,
		"dec_imaps_port":	null,
		"dec_pop3s_port":	null,
		"dec_ftps_port":	null,
		"dec_interface":	[
				{"ifc_id":	2}
		]
}

Response

HTTP status code 200

복호화 정책 설정 수정 성공

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

seqseq: required (integer - minimum: 1 - maximum: 1023)
복호화 정책 순번

useuse: required (one of 0, 1 - default: 1)
사용 여부
사용	안함:	0,	사용:	1

descdesc: required (string - minLength: 0 - maxLength: 128)
설명

ssl_trfc_chk_cert_id
ssl_trfc_chk_cert_id: required (integer)
SSL 인증서 ID

dec_mirror_enable: required (one of 0, 1 - default: 0)
dec_mirror_enable
복화화 트래픽 미러링 사용 여부
0:	사용안함,	1:	사용

dec_https_port
dec_https_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(HTTPS)
default:	null(기존	서버	포트	사용)

dec_smtps_port
dec_smtps_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(SMTPS)
default:	null(기존	서버	포트	사용)

dec_pop3s_port
dec_pop3s_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(POP3S)
default:	null(기존	서버	포트	사용)

dec_imaps_port
dec_imaps_port: required (integer - minimum: 1 - maximum: 65535)
복화화 트래픽 미러링 서버 포트(IMAPS)
default:	null(기존	서버	포트	사용)

dec_ftps_port: required (integer - minimum: 1 - maximum: 65535)
dec_ftps_port
복화화 트래픽 미러링 서버 포트(FTPS)
default:	null(기존	서버	포트	사용)

ssh_shell_act
ssh_shell_act: required (one of 0, 1 - default: 0)
SSH SHELL 기반 접속 허용/거절
0:	허용,	1:	거절

ssh_exec_act
ssh_exec_act: required (one of 0, 1 - default: 0)
SSH Exec(1회성 명령) 허용/거절  0:	허용,	1:	거절

ssh_x11_act
ssh_x11_act: required (one of 0, 1 - default: 0)
SSH GUI 기반 접속 허용/거절  0:	허용,	1:	거절

ssh_sftp_act: required (one of 0, 1 - default: 0)
ssh_sftp_act
SSH SFTP 기반 접속 허용/거절  0:	허용,	1:	거절

ssh_port_forward_act
ssh_port_forward_act: required (one of 0, 1 - default: 0)
SSH Port Forward 사용 허용/거절  0:	허용,	1:	거절

ssl_trfc_chk_rule_id: required (integer)
ssl_trfc_chk_rule_id

복호화 정책 ID

client
client: required (array of 호스트/네트워크 객체)
Items: 호스트/네트워크 객체
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name: required (string)
name
객체 이름 (ANY:	Any)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type: required (integer)
addr_obj_type
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

server
server: required (array of 호스트/네트워크 객체)
Items: 호스트/네트워크 객체
Items

addr_obj_id
addr_obj_id: required (integer)
객체 ID (ANY:	0)

ip_ver
ip_ver: required (integer)
IP 버전
IPv4:	1,	IPv6:	2

name
name: required (string)
객체 이름 (ANY:	Any)

zone
zone: required (integer)
Zone
(내부망:	1,	외부망:	2,	DMZ:	3)

addr_obj_type
addr_obj_type: required (integer)
주소 객체 타입 (ANY:	0)
호스트객체:	1,	네트워크	객체(넷마스크):	2,	네트워크	객체(범위):	3

service
service: required (array of 서비스 객체)
Items: 서비스 객체
Items

srv_obj_id
srv_obj_id: required (integer)
서비스 객체 ID

srv_obj_type
srv_obj_type: required (integer)
서비스 객체 종류
서비스	객체:	1,	서비스	그룹	객체:	2

name
name: required (string)
서비스 명

pre_def
pre_def: required (integer)
기본 정의 프로토콜 여부
1:기본	정의,	2:	사용자	정의

prtcprtc: (object)
프로토콜 정보
상세	정보는	서비스	객체	참고

srv_cate
srv_cate: (integer)
서비스 유형

start_port
start_port: (string)
출발지 포트

srv_port
srv_port: (string)
서비스 포트

life_time
life_time: (integer)
Lifetime(초)

prioprio: (integer)
우선 순위

descdesc: (string)
객체 설명

cfg_adm_id
cfg_adm_id: required (integer)
관리자 ID

cfg_adm
cfg_adm: required (string)
관리자명

cfg_dt
cfg_dt: required (string)
수정 날짜

refref: required (object)
참조 정보
상세	정보는	서비스	객체	참고

certcert: required (object)

ssl_trfc_chk_cert_id
ssl_trfc_chk_cert_id: required (integer)
인증서 ID

cert_name
cert_name: required (string)
인증서 이름

cert_type: required (integer)
cert_type
인증서 타입 (사설	인증서:	0,	신뢰할	수	있는	루트	인증서:	1)

subject
subject: required (string)
인증서 세부 정보

issuer
issuer: required (string)
인증서 세부 정보

expire_period
expire_period: required (string)
인증서 만료 기간

dec_mirror_ifc_select_list
dec_mirror_ifc_select_list: required (array of 인터페이스)
미러링 인터페이스 목록

Items: 인터페이스
Items

ifc_id
ifc_id: required (integer)
인터페이스 ID

name
name: required (string)
인터페이스 명

Example:
Example

{
		"code":	"ok",
		"result":	{
				"ssl_trfc_chk_rule_id":	1,
				"seq":	2,
				"use":	1,
				"client":	[
						{
								"addr_obj_id":	0,
								"ip_ver":	3,
								"name":	"Any",
								"zone":	0,
								"addr_obj_type":	0
						}
				],
				"server":	[
						{
								"addr_obj_id":	3,
								"ip_ver":	2,
								"name":	"네트워크객체3",
								"zone":	2,
								"addr_obj_type":	2
						}
				],
				"service":	[
						{
								"srv_obj_id":	1,
								"srv_obj_type":	1,
								"name":	"FTPS",
								"srv_cate":	19,
								"start_port":	"*",
								"srv_port":	"990",
								"life_time":	1800,
								"prio":	38,
								"desc":	"",
								"pre_def":	1,
								"prtc":	{
										"prtc_obj_id":	5,
										"name":	"TCP",
										"prtc":	6,
										"desc":	"Transmission	Control	Protocol",
										"pre_def":	1
								},
								"cfg_adm_id":	0,
								"cfg_adm":	"",
								"cfg_dt":	"2019-01-11	12:09:58",
								"ref":	{}
						}
				],
				"desc":	"SSL정책설명2",
				"ssl_trfc_chk_cert_id":	1,
				"cert":	{
						"ssl_trfc_chk_cert_id":	1,
						"cert_name":	"cacert",
						"cert_type":	0,
						"expire_period":	"August	14	11:13:57	2019	GMT	~	August	13	11:13:57	2020	GMT",
						"issuer":	"/C=KR/ST=example/L=example/O=example/OU=example/CN=example/emailAddress=example@example.com",
						"subject":	"/C=KR/ST=example/L=example/O=example/OU=example/CN=example/emailAddress=example@example.com"
				},
				"ssh_shell_act":	0,
				"ssh_exec_act":	0,
				"ssh_x11_act":	0,
				"ssh_sftp_act":	0,
				"ssh_port_forward_act":	0,
				"dec_mirror_enable":	0,
				"dec_https_port":	null,
				"dec_smtps_port":	null,
				"dec_imaps_port":	null,
				"dec_pop3s_port":	null,
				"dec_ftps_port":	null,
				"dec_mirror_ifc_select_list":	[
						{
								"ifc_id":	2,
								"name":	"eth1"
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

/ssl/6/policies/{pk}

복호화 정책 설정을(를) 삭제한다.

Request

URI Parameters

pkpk: required (integer)
복호화 정책 ID( ssl_trfc_chk_rule_id )

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

복호화 정책 설정 삭제 성공

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

IPv6 복호화 정책 설정 적용/취소

PUT

/command/ssl-6-policies/apply

IPv6 복호화 정책 설정을 적용합니다.

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

IPv6 복호화 정책 설정 적용 성공

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

/command/ssl-6-policies/cancel

IPv6 복호화 정책 설정을 취소합니다.

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

IPv6 복호화 정책 설정 취소 성공

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

