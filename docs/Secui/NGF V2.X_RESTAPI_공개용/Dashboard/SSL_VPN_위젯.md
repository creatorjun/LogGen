GET

GET

GET

GET

GET

GET

SSL	VPN	대시보드	위젯	REST	API	문서

https://{url}/api

url:	required	(string)
장비	IP

SSL	VPN	터널	수	추이

License:	 Basic ,	Feature:	 SSL	VPN ,	스토리지	지원	모델

/lr/dashboard?type=ssl_vpn_tunnel_cnt_trend

SSL	VPN	트래픽	추이

License:	 Basic ,	Feature:	 SSL	VPN ,	스토리지	지원	모델

/lr/dashboard?type=ssl_vpn_traffic_trend

SSL	VPN	접속	상태

License:	 Basic ,	Feature:	 SSL	VPN ,	스토리지	지원	모델

/lr/dashboard?type=ssl_vpn_connection_status

SSL	VPN	사용자	TOP	N

License:	 Basic ,	Feature:	 SSL	VPN ,	스토리지	지원	모델

/lr/dashboard?type=ssl_vpn_user_traffic_top

SSL	VPN	서버	TOP	N

License:	 Basic ,	Feature:	 SSL	VPN ,	스토리지	지원	모델

/lr/dashboard?type=ssl_vpn_server_traffic_top

SSL	VPN	사용자	인증	현황

License:	 Basic ,	Feature:	 SSL	VPN ,	스토리지	지원	모델

/lr/dashboard?type=ssl_vpn_user_login_log

SSL	VPN	터널	수	추이

GET

/lr/dashboard?type=ssl_vpn_tunnel_cnt_trend

SSL	VPN	터널	수	추이 	정보를	조회한다.

Request

Headers

Authorization:	required	(string)
API	Token
로그인	후	응답에	포함된	 api_token 을	설정

Example:

fd9b3a9e18ac461cb036a8ea9053985e

Accept:	required	(string)
Example:

application/json

Content-Type:	required	(string)
Example:

application/json

Accept-Language:	(one	of	ko,	en	-	default:	ko)
언어	설정

필수가	아니며	요청	시	설정되지	않으면	로그인	시	사용된	언어로	설정됩니다.
한국어:	ko,	영어:	en

Example:

ko

Query	Parameters

type:	required	(object)
type 	query	string과	같이	설정	되어야	할	속성	정보

top:	(integer	-	default:	10)
TOP	수(optional)

stime:	required	(string)
검색	시작	시간
형식:	날짜+시간

Example:

2020-05-06+16:53:00

etime:	required	(string)
검색	종료	시간
형식:	날짜+시간

Example:

2020-05-06+16:53:09

ip_type:	(string)
IP	타입(optional)
v46:	ALL,	v4:	IPv4,	v6:	IPv6

data_type:	(string)
데이터	타입(optional)
hagroup:	HA	Group	전체,	local:	접속	장비

Response

HTTP	status	code	200

SSL	VPN	터널	수	추이 	정보	조회	성공

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

result:	required	(object)
Example:

{
		"code":	"ok",
		"result":	{
				"unit_time":	"/min",
				"result":	[
						{
								"name":	"2020-05-07	11:14:00",
								"type":	"",
								"value":	1
						},
						{
								"name":	"2020-05-07	11:15:00",
								"type":	"",
								"value":	1
						},
						{
								"name":	"2020-05-07	11:16:00",
								"type":	"",
								"value":	1
						}
				]
		}
}

HTTP	status	code	401

인증	또는	인가되지	않음 (UNAUTHORIZED)

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

message:	required	(string)
결과	메시지

Example:

{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

SSL	VPN	트래픽	추이

GET

/lr/dashboard?type=ssl_vpn_traffic_trend

SSL	VPN	트래픽	추이 	정보를	조회한다.

Request

Headers

Authorization:	required	(string)
API	Token
로그인	후	응답에	포함된	 api_token 을	설정

Example:

fd9b3a9e18ac461cb036a8ea9053985e

Accept:	required	(string)
Example:

application/json

Content-Type:	required	(string)
Example:

application/json

Accept-Language:	(one	of	ko,	en	-	default:	ko)
언어	설정

필수가	아니며	요청	시	설정되지	않으면	로그인	시	사용된	언어로	설정됩니다.
한국어:	ko,	영어:	en

Example:

ko

Query	Parameters

type:	required	(object)
type 	query	string과	같이	설정	되어야	할	속성	정보

top:	(integer	-	default:	10)
TOP	수(optional)

stime:	required	(string)
검색	시작	시간
형식:	날짜+시간

Example:

2020-05-06+16:53:00

etime:	required	(string)
검색	종료	시간
형식:	날짜+시간

Example:

2020-05-06+16:53:09

ip_type:	(string)
IP	타입(optional)
v46:	ALL,	v4:	IPv4,	v6:	IPv6

data_type:	(string)
데이터	타입(optional)
hagroup:	HA	Group	전체,	local:	접속	장비

Response

HTTP	status	code	200

SSL	VPN	트래픽	추이 	정보	조회	성공

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

result:	required	(object)
Example:

{
		"code":	"ok",
		"result":	{
				"unit_time":	"/10s",
				"result":	[
						{
								"time":	"2020-05-07	11:10:10",
								"in_bps":	264,
								"out_bps":	-264
						},
						{
								"time":	"2020-05-07	11:10:20",
								"in_bps":	264,
								"out_bps":	-128
						}
				]
		}
}

HTTP	status	code	401

인증	또는	인가되지	않음 (UNAUTHORIZED)

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

message:	required	(string)
결과	메시지

Example:

{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

SSL	VPN	접속	상태

GET

/lr/dashboard?type=ssl_vpn_connection_status

SSL	VPN	접속	상태 	정보를	조회한다.

Request

Headers

Authorization:	required	(string)
API	Token
로그인	후	응답에	포함된	 api_token 을	설정

Example:

fd9b3a9e18ac461cb036a8ea9053985e

Accept:	required	(string)
Example:

application/json

Content-Type:	required	(string)
Example:

application/json

Accept-Language:	(one	of	ko,	en	-	default:	ko)
언어	설정

필수가	아니며	요청	시	설정되지	않으면	로그인	시	사용된	언어로	설정됩니다.
한국어:	ko,	영어:	en

Example:

ko

Query	Parameters

type:	required	(object)
type 	query	string과	같이	설정	되어야	할	속성	정보

top:	(integer	-	default:	10)
TOP	수(optional)

stime:	required	(string)
검색	시작	시간
형식:	날짜+시간

Example:

2020-05-06+16:53:00

etime:	required	(string)
검색	종료	시간
형식:	날짜+시간

Example:

2020-05-06+16:53:09

ip_type:	(string)
IP	타입(optional)
v46:	ALL,	v4:	IPv4,	v6:	IPv6

data_type:	(string)
데이터	타입(optional)
hagroup:	HA	Group	전체,	local:	접속	장비

Response

HTTP	status	code	200

SSL	VPN	접속	상태 	정보	조회	성공

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

result:	required	(object)
Example:

{
		"code":	"ok",
		"result":	{
				"unit_time":	"/h",
				"result":	[
						{
								"current_cnt":	1,
								"max_cnt":	500
						}
				]
		}
}

HTTP	status	code	401

인증	또는	인가되지	않음 (UNAUTHORIZED)

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

message:	required	(string)
결과	메시지

Example:

{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

SSL	VPN	사용자	TOP	N

GET

/lr/dashboard?type=ssl_vpn_user_traffic_top

SSL	VPN	사용자	TOP	N 	정보를	조회한다.

Request

Headers

Authorization:	required	(string)
API	Token
로그인	후	응답에	포함된	 api_token 을	설정

Example:

fd9b3a9e18ac461cb036a8ea9053985e

Accept:	required	(string)
Example:

application/json

Content-Type:	required	(string)
Example:

application/json

Accept-Language:	(one	of	ko,	en	-	default:	ko)
언어	설정

필수가	아니며	요청	시	설정되지	않으면	로그인	시	사용된	언어로	설정됩니다.
한국어:	ko,	영어:	en

Example:

ko

Query	Parameters

type:	required	(object)
type 	query	string과	같이	설정	되어야	할	속성	정보

top:	(integer	-	default:	10)
TOP	수(optional)

stime:	required	(string)
검색	시작	시간
형식:	날짜+시간

Example:

2020-05-06+16:53:00

etime:	required	(string)
검색	종료	시간
형식:	날짜+시간

Example:

2020-05-06+16:53:09

ip_type:	(string)
IP	타입(optional)
v46:	ALL,	v4:	IPv4,	v6:	IPv6

data_type:	(string)
데이터	타입(optional)
hagroup:	HA	Group	전체,	local:	접속	장비

Response

HTTP	status	code	200

SSL	VPN	사용자	TOP	N 	정보	조회	성공

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

result:	required	(object)
Example:

{
		"code":	"ok",
		"result":	{
				"unit_time":	"/h",
				"result":	[
						{
								"name":	"192.168.255.221(linux1)",
								"type":	"",
								"value":	1428
						}
				]
		}
}

HTTP	status	code	401

인증	또는	인가되지	않음 (UNAUTHORIZED)

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

message:	required	(string)
결과	메시지

Example:

{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

SSL	VPN	서버	TOP	N

GET

/lr/dashboard?type=ssl_vpn_server_traffic_top

SSL	VPN	서버	TOP	N 	정보를	조회한다.

Request

Headers

Authorization:	required	(string)
API	Token
로그인	후	응답에	포함된	 api_token 을	설정

Example:

fd9b3a9e18ac461cb036a8ea9053985e

Accept:	required	(string)
Example:

application/json

Content-Type:	required	(string)
Example:

application/json

Accept-Language:	(one	of	ko,	en	-	default:	ko)
언어	설정

필수가	아니며	요청	시	설정되지	않으면	로그인	시	사용된	언어로	설정됩니다.
한국어:	ko,	영어:	en

Example:

ko

Query	Parameters

type:	required	(object)
type 	query	string과	같이	설정	되어야	할	속성	정보

top:	(integer	-	default:	10)
TOP	수(optional)

stime:	required	(string)
검색	시작	시간
형식:	날짜+시간

Example:

2020-05-06+16:53:00

etime:	required	(string)
검색	종료	시간
형식:	날짜+시간

Example:

2020-05-06+16:53:09

ip_type:	(string)
IP	타입(optional)
v46:	ALL,	v4:	IPv4,	v6:	IPv6

data_type:	(string)
데이터	타입(optional)
hagroup:	HA	Group	전체,	local:	접속	장비

Response

HTTP	status	code	200

SSL	VPN	서버	TOP	N 	정보	조회	성공

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

result:	required	(object)
Example:

{
		"code":	"ok",
		"result":	{
				"unit_time":	"/h",
				"result":	[
						{
								"name":	"192.168.0.1",
								"type":	"",
								"value":	612
						},
						{
								"name":	"192.168.1.1",
								"type":	"",
								"value":	612
						},
						{
								"name":	"192.168.1.2",
								"type":	"",
								"value":	204
						}
				]
		}
}

HTTP	status	code	401

인증	또는	인가되지	않음 (UNAUTHORIZED)

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

message:	required	(string)
결과	메시지

Example:

{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

SSL	VPN	사용자	인증	현황

GET

/lr/dashboard?type=ssl_vpn_user_login_log

SSL	VPN	사용자	인증	현황 	정보를	조회한다.

Request

Headers

Authorization:	required	(string)
API	Token
로그인	후	응답에	포함된	 api_token 을	설정

Example:

fd9b3a9e18ac461cb036a8ea9053985e

Accept:	required	(string)
Example:

application/json

Content-Type:	required	(string)
Example:

application/json

Accept-Language:	(one	of	ko,	en	-	default:	ko)
언어	설정

필수가	아니며	요청	시	설정되지	않으면	로그인	시	사용된	언어로	설정됩니다.
한국어:	ko,	영어:	en

Example:

ko

Query	Parameters

type:	required	(object)
type 	query	string과	같이	설정	되어야	할	속성	정보

top:	(integer	-	default:	10)
TOP	수(optional)

stime:	required	(string)
검색	시작	시간
형식:	날짜+시간

Example:

2020-05-06+16:53:00

etime:	required	(string)
검색	종료	시간
형식:	날짜+시간

Example:

2020-05-06+16:53:09

ip_type:	(string)
IP	타입(optional)
v46:	ALL,	v4:	IPv4,	v6:	IPv6

data_type:	(string)
데이터	타입(optional)
hagroup:	HA	Group	전체,	local:	접속	장비

Response

HTTP	status	code	200

SSL	VPN	사용자	인증	현황 	정보	조회	성공

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

result:	required	(object)
Example:

{
		"code":	"ok",
		"result":	{
				"unit_time":	"/min",
				"result":	[
						{
								"time":	"2020-05-07	11:09:56",
								"user_id":	"linux1",
								"src_ip":	"192.168.145.6",
								"os_type":	"Embedded	Linux",
								"rent_ip":	"1.2.255.221",
								"group_name":	"linux_G",
								"auth_policy_name":	"linux",
								"auth_type":	"Local	DB",
								"connect_uri":	"/linux",
								"status":	"Allow",
								"failure_cnt":	"0/4",
								"auth_status":	"Login",
								"reason":	""
						},
						{
								"time":	"2020-05-07	11:09:45",
								"user_id":	"linux1",
								"src_ip":	"192.168.145.6",
								"os_type":	"Embedded	Linux",
								"rent_ip":	"1.2.255.221",
								"group_name":	"linux_G",
								"auth_policy_name":	"linux",
								"auth_type":	"Local	DB",
								"connect_uri":	"/linux",
								"status":	"Allow",
								"failure_cnt":	"0/4",
								"auth_status":	"Logout",
								"reason":	""
						}
				]
		}
}

HTTP	status	code	401

인증	또는	인가되지	않음 (UNAUTHORIZED)

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

message:	required	(string)
결과	메시지

Example:

{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

