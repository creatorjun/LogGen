GET

GET

GET

GET

GET

IPSec VPN 대시보드 위젯 REST API 문서

https://{url}/api

urlurl: required (string)
장비 IP

IPSec VPN 현재 터널 상태

License:  Basic , Feature:  IPSec	VPN , 스토리지 지원 모델

/lr/dashboard?type=ipsec_vpn_current_status

IPSec VPN 터널 수 추이

License:  Basic , Feature:  IPSec	VPN , 스토리지 지원 모델

/lr/dashboard?type=ipsec_vpn_tunnel_trend

IPSec VPN 단절 터널 현황

License:  Basic , Feature:  IPSec	VPN , 스토리지 지원 모델

/lr/dashboard?type=ipsec_vpn_disconnection_status

IPSec VPN 트래픽 추이

License:  Basic , Feature:  IPSec	VPN , 스토리지 지원 모델

/lr/dashboard?type=ipsec_vpn_traffic_trend

IPSec VPN 터널별 트래픽 TOP N, IPSec VPN 터널별 트래픽 현황

License:  Basic , Feature:  IPSec	VPN , 스토리지 지원 모델

/lr/dashboard?type=ipsec_vpn_tunnel_traffic_top

IPSec VPN 현재 터널 상태

GET

/lr/dashboard?type=ipsec_vpn_current_status

IPSec	VPN	현재	터널	상태  정보를 조회한다.

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

Query Parameters

type
type: required (object)
type  query string과 같이 설정 되어야 할 속성 정보

toptop: (integer - default: 10)
TOP 수(optional)

stime: required (string)
stime
검색 시작 시간
형식:	날짜+시간

Example:
Example

2020-05-06+16:53:00

etime
etime: required (string)
검색 종료 시간
형식:	날짜+시간

Example:
Example

2020-05-06+16:53:09

ip_type
ip_type: (string)
IP 타입(optional)
v46:	ALL,	v4:	IPv4,	v6:	IPv6

data_type
data_type: (string)
데이터 타입(optional)
hagroup:	HA	Group	전체,	local:	접속	장비

Response

HTTP status code 200

IPSec	VPN	현재	터널	상태  정보 조회 성공

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
Example:
Example

{
		"code":	"ok",
		"result":	{
				"unit_time":	"/h",
				"result":	[
						{
								"normal_cnt":	1,
								"abnormal_cnt":	1,
								"abnormal_tunnel_list":	[
										"B-BMster_Slave"
								]
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
code: required (string)
code
결과 코드

message
message: required (string)
결과 메시지

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

IPSec VPN 터널 수 추이

GET

/lr/dashboard?type=ipsec_vpn_tunnel_trend

IPSec	VPN	터널	수	추이  정보를 조회한다.

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

type
type: required (object)
type  query string과 같이 설정 되어야 할 속성 정보

toptop: (integer - default: 10)
TOP 수(optional)

stime
stime: required (string)
검색 시작 시간
형식:	날짜+시간

Example:
Example

2020-05-06+16:53:00

etime
etime: required (string)
검색 종료 시간
형식:	날짜+시간

Example:
Example

2020-05-06+16:53:09

ip_type
ip_type: (string)
IP 타입(optional)
v46:	ALL,	v4:	IPv4,	v6:	IPv6

data_type
data_type: (string)
데이터 타입(optional)
hagroup:	HA	Group	전체,	local:	접속	장비

Response

HTTP status code 200

IPSec	VPN	터널	수	추이  정보 조회 성공

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
Example:
Example

{
		"code":	"ok",
		"result":	{
				"unit_time":	"/min",
				"result":	[
						{
								"time":	"2020-05-07	09:52:00",
								"tot_tunnel_cnt":	4,
								"normal_tunnel_cnt":	1
						},
						{
								"time":	"2020-05-07	09:53:00",
								"tot_tunnel_cnt":	2,
								"normal_tunnel_cnt":	1
						},
						{
								"time":	"2020-05-07	09:54:00",
								"tot_tunnel_cnt":	2,
								"normal_tunnel_cnt":	0
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

IPSec VPN 단절 터널 현황

GET

/lr/dashboard?type=ipsec_vpn_disconnection_status

IPSec	VPN	단절	터널	현황  정보를 조회한다.

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

Query Parameters

type
type: required (object)
type  query string과 같이 설정 되어야 할 속성 정보

toptop: (integer - default: 10)
TOP 수(optional)

stime
stime: required (string)
검색 시작 시간
형식:	날짜+시간

Example:
Example

2020-05-06+16:53:00

etime
etime: required (string)
검색 종료 시간
형식:	날짜+시간

Example:
Example

2020-05-06+16:53:09

ip_type
ip_type: (string)
IP 타입(optional)
v46:	ALL,	v4:	IPv4,	v6:	IPv6

data_type
data_type: (string)
데이터 타입(optional)
hagroup:	HA	Group	전체,	local:	접속	장비

Response

HTTP status code 200

IPSec	VPN	단절	터널	현황  정보 조회 성공

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
Example:
Example

{
		"code":	"ok",
		"result":	{
				"unit_time":	"/d",
				"result":	[
						{
								"name":	"B-BB",
								"type":	"",
								"value":	8380
						},
						{
								"name":	"B-AA",
								"type":	"",
								"value":	8380
						},
						{
								"name":	"B-BMster_Master",
								"type":	"",
								"value":	4030
						},
						{
								"name":	"B-BMster_Slave",
								"type":	"",
								"value":	150
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

IPSec VPN 트래픽 추이

GET

/lr/dashboard?type=ipsec_vpn_traffic_trend

IPSec	VPN	트래픽	추이  정보를 조회한다.

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

type
type: required (object)
type  query string과 같이 설정 되어야 할 속성 정보

toptop: (integer - default: 10)
TOP 수(optional)

stime
stime: required (string)
검색 시작 시간
형식:	날짜+시간

Example:
Example

2020-05-06+16:53:00

etime
etime: required (string)
검색 종료 시간
형식:	날짜+시간

Example:
Example

2020-05-06+16:53:09

ip_type
ip_type: (string)
IP 타입(optional)
v46:	ALL,	v4:	IPv4,	v6:	IPv6

data_type
data_type: (string)
데이터 타입(optional)
hagroup:	HA	Group	전체,	local:	접속	장비

Response

HTTP status code 200

IPSec	VPN	트래픽	추이  정보 조회 성공

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
Example:
Example

{
		"code":	"ok",
		"result":	{
				"unit_time":	"/min",
				"result":	[
						{
								"name":	"2020-05-07	09:54:00",
								"type":	"",
								"value":	0
						},
						{
								"name":	"2020-05-07	09:55:00",
								"type":	"",
								"value":	4096
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

IPSec VPN 터널별 트래픽 TOP N, IPSec VPN 터널별 트래픽 현황

GET

/lr/dashboard?type=ipsec_vpn_tunnel_traffic_top

IPSec	VPN	터널별	트래픽	TOP	N|IPSec	VPN	터널별	트래픽	현황  정보를 조회한다.

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

Query Parameters

type: required (object)
type
type  query string과 같이 설정 되어야 할 속성 정보

toptop: (integer - default: 10)
TOP 수(optional)

stime
stime: required (string)
검색 시작 시간
형식:	날짜+시간

Example:
Example

2020-05-06+16:53:00

etime
etime: required (string)
검색 종료 시간
형식:	날짜+시간

Example:
Example

2020-05-06+16:53:09

ip_type
ip_type: (string)
IP 타입(optional)
v46:	ALL,	v4:	IPv4,	v6:	IPv6

data_type: (string)
data_type

데이터 타입(optional)
hagroup:	HA	Group	전체,	local:	접속	장비

Response

HTTP status code 200

IPSec	VPN	터널별	트래픽	TOP	N|IPSec	VPN	터널별	트래픽	현황  정보 조회 성공

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
Example:
Example

{
		"code":	"ok",
		"result":	{
				"unit_time":	"/h",
				"result":	[
						{
								"name":	"B-BMster_Master",
								"type":	"",
								"value":	10240
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

