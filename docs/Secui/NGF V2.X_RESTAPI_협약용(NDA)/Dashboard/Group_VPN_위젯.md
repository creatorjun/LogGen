GET

GET

GET

GET

GET

Group	VPN	대시보드	위젯	REST	API	문서

https://{url}/api

url:	required	(string)
장비	IP

Group	VPN	그룹	연결	상태

License:	 Basic ,	Feature:	 IPSec	VPN ,	스토리지	지원	모델

/lr/dashboard?type=group_vpn_current_status

Group	VPN	터널	수	추이

License:	 Basic ,	Feature:	 IPSec	VPN ,	스토리지	지원	모델

/lr/dashboard?type=group_vpn_tunnel_trend

Group	VPN	단절	터널	현황

License:	 Basic ,	Feature:	 IPSec	VPN ,	스토리지	지원	모델

/lr/dashboard?type=group_vpn_disconnection_status

Group	VPN	트래픽	추이

License:	 Basic ,	Feature:	 IPSec	VPN ,	스토리지	지원	모델

/lr/dashboard?type=group_vpn_traffic_trend

Group	VPN	터널별	트래픽	TOP	N

License:	 Basic ,	Feature:	 IPSec	VPN ,	스토리지	지원	모델

/lr/dashboard?type=group_vpn_tunnel_traffic_top

Group	VPN	그룹	연결	상태

GET

/lr/dashboard?type=group_vpn_current_status

Group	VPN	그룹	연결	상태 	위젯	정보를	조회한다.

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

Group	VPN	그룹	연결	상태 	위젯	정보	조회	성공

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
								"normal_cnt":	2,
								"abnormal_cnt":	2,
								"abnormal_tunnel_list":	[
										"M-TEST_GM",
										"M-TEST_GM2"
								]
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

Group	VPN	터널	수	추이

GET

/lr/dashboard?type=group_vpn_tunnel_trend

Group	VPN	터널	수	추이 	위젯	정보를	조회한다.

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

Group	VPN	터널	수	추이 	위젯	정보	조회	성공

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
								"time":	"2020-05-07	13:08:00",
								"tot_tunnel_cnt":	4,
								"normal_tunnel_cnt":	2
						},
						{
								"time":	"2020-05-07	13:09:00",
								"tot_tunnel_cnt":	4,
								"normal_tunnel_cnt":	2
						},
						{
								"time":	"2020-05-07	13:10:00",
								"tot_tunnel_cnt":	4,
								"normal_tunnel_cnt":	2
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

Group	VPN	단절	터널	현황

GET

/lr/dashboard?type=group_vpn_disconnection_status

Group	VPN	단절	터널	현황 	위젯	정보를	조회한다.

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

Group	VPN	단절	터널	현황 	위젯	정보	조회	성공

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
				"unit_time":	"/d",
				"result":	[
						{
								"name":	"M-TEST_GM",
								"type":	"",
								"value":	900
						},
						{
								"name":	"M-TEST_GM2",
								"type":	"",
								"value":	600
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

Group	VPN	트래픽	추이

GET

/lr/dashboard?type=group_vpn_traffic_trend

Group	VPN	트래픽	추이 	위젯	정보를	조회한다.

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

Group	VPN	트래픽	추이 	위젯	정보	조회	성공

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
								"name":	"2020-05-07	09:00:00",
								"type":	"",
								"value":	2944
						},
						{
								"name":	"2020-05-07	09:01:00",
								"type":	"",
								"value":	3072
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

Group	VPN	터널별	트래픽	TOP	N

GET

/lr/dashboard?type=group_vpn_tunnel_traffic_top

Group	VPN	터널별	트래픽	TOP	N 	위젯	정보를	조회한다.

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

Group	VPN	터널별	트래픽	TOP	N 	위젯	정보	조회	성공

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
								"name":	"M-GROUP1-GM1-secondary",
								"type":	"",
								"value":	75264
						},
						{
								"name":	"M-GROUP1-GM1-primary",
								"type":	"",
								"value":	68992
						},
						{
								"name":	"DataSA-M-GROUP1-GM1-primary",
								"type":	"",
								"value":	37632
						},
						{
								"name":	"DataSA-M-GROUP1-GM1-secondary",
								"type":	"",
								"value":	37632
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

