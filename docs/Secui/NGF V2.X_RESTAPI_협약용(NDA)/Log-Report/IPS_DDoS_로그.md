IPS/DDoS	로그	REST	API	문서

https://{url}/api

url:	required	(string)
장비	IP

로그	검색	시작

주의)	이전에	현재	상태	또는	로그	검색	종료	후	검색	종료	REST	API가	호출되지	않았다면	검색	시작	전에	 /lr/log/{request_id}/end 	REST	API를	요청해	이전	검색	요청에	대한	리소스	정리가	필요합니다.

/lr/log/start

로그	추이	데이터	요청

/lr/log/{request_id}/trend

로그	검색	진행	상태	요청

응답	결과	중	status	속성	값이	 DONE 일	때까지	반복	요청(폴링)을	해야	합니다.

/lr/log/{request_id}/status

로그	검색	결과	조회

상태	조회(/{request_id}/status)	응답	결과에서	 searched_cnt 	속성	값이	0	일	경우	데이터가	없기	때문에	호출	될	필요	없습니다.

/lr/log/{request_id}/page/{start}/to/{end}

로그	다음	검색	수행

POST

GET

GET

GET

/lr/log/{request_id}/status 	응답	결과에서	allow_next	속성값이	true	일	경우	수행	가능하고	다음	검색을	수행	한	후	 /lr/log/{request_id}/status 	REST	API를	반복	요청(폴링)을	해서	검색	상태를	재	조회해야	합니다.

DELETE

DELETE

DELETE

/lr/log/{request_id}/page/next

로그	검색	중지

/lr/log/{request_id}/stop

로그	검색	종료

주의)	재	검색	전,	즉,	 /lr/log/start 	REST	API	호출	전에	이전	request_id에	해당하는	검색	작업이	종료되지	않았다면	반드시	호출되어야	합니다.

/lr/log/{request_id}/end

로그	검색	시작

POST

/lr/log/start

IPS/DDoS	로그 	검색을	시작한다.

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

Body

Media	type:	application/json

Type:	object

Properties
filters:	required	(array	of	필터)
필터	정보	목록
별첨으로	제공되는	로그	기능	별	컬럼	정의서	참고

Items:	필터

key:	required	(string)
컬럼

value:	required	(array	of	String)
필터	값	목록
숫자형식:	N	or	N1-N2	or	>N,	<N,	>=N,	<=N
문자열

is_not:	required	(one	of	true,	false)
NOT	여부

page_rows:	(integer)
페이지	당	건수

total_rows:	(integer)
검색	건수

print_object_name:	(one	of	true,	false)
객체명	출력	여부

columns:	required	(array	of	String)
컬럼	목록
별첨으로	제공되는	로그	기능	별	컬럼	정의서	참고

stime:	required	(string)
시작	시간

Example:

2020-05-18	07:28:51

etime:	required	(string)
종료	시간

Example:

2020-05-18	13:28:51

order_by:	required	(one	of	asc,	desc)
정렬	기준
asc:	오름차순,	desc:	내림차순

log_type:	required	(string)
로그	검색	타입(기능	별	ID)

ips_ddos_incident :	IPS/DDoS	공격	현황	로그
ddos_pd_traffic_cnt :	DDoS	보호	도메인	트래픽	현황	로그
ddos_pd_tcpflag_traffic_cnt :	DDoS	보호	도메인	별	TCP	Flag	별	트래픽	현황	로그
ddos_learning_traffic_cnt :	IPS/DDoS	트래픽	학습	현황	로그

Example:

//	예)	IPS/DDoS	공격	현황	로그
{
		"log_type":	"ips_ddos_incident",
		"stime":	"2020-05-18	09:47:53",
		"etime":	"2020-05-18	15:47:53",
		"total_rows":	1000,
		"page_rows":	30,
		"order_by":	"desc",
		"filters":	[],
		"print_object_name":	false,
		"columns":	[
				"stime",
				"etime",
				"mach_id",
				"type",
				"threat_category",
				"threat_id",
				"event_id",
				"event_name",
				"risk",
				"pd_name",
				"pf_name",
				"packets",
				"bytes",
				"action",
				"status"
		]
}

Response

HTTP	status	code	200

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

result:	required	(object)
request_id:	required	(string)
요청	ID
검색	라이프사이클	전반에	사용됩니다.

Example:

{
		"code":	"ok",
		"result":	{
				"request_id":	"00001220-005344"
		}
}

HTTP	status	code	400

잘못된	요청 (BAD	REQUEST)

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

message:	required	(string)
결과	메시지

dev_t:	(string)
개발용	메시지

Example:

{
		"code":	"50101",
		"dev_t":	"System	API	Error",
		"message":	"Wrong	value.	(columns	:	'pid')"
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

dev_t:	(string)
개발용	메시지

Example:

//	로그인	필요
{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

//	(재)로그인	필요
{
		"code":	"94014",
		"dev_t":	"Authentication	Error",
		"message":	"세션이	만료되어	재로그인이	필요합니다."
}

//	권한이	필요
{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

HTTP	status	code	404

리소스를	찾을	수	없음 (NOT	FOUND)

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

message:	required	(string)
결과	메시지

dev_t:	(string)
개발용	메시지

Example:

{
		"code":	"50007",
		"dev_t":	"System	API	Error",
		"message":	"존재하지	않는	리소스입니다."
}

로그	추이	데이터	요청

GET

/lr/log/{request_id}/trend

IPS/DDoS	로그 	추이	데이터를	조회한다.

Request

URI	Parameters

request_id:	required	(string)
조회	시작	시	응답에	포함된	 요청	ID

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

Response

HTTP	status	code	200

IPS/DDoS	로그 	추이	데이터	결과	조회	성공

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

result:	required	(object)
trend:	required	(array	of	)
추이
형식:	[시작	시간,	종료	시간,	수치]

Example:

[
		["2020-05-18	07:10:00",	"2020-05-18	07:19:59",	814456]
]

unit_time:	required	(object)
단위

unit:	required	(string)
단위(ex:	minutes)

value:	required	(integer)
수치

Example:

{
		"code":	"ok",
		"result":	{
				"trend":	[
						[
								"2020-05-18	07:10:00",
								"2020-05-18	07:19:59",
								814456
						],
						[
								"2020-05-18	07:20:00",
								"2020-05-18	07:29:59",
								1058165
						]
				],
				"unit_time":	{
						"value":	10,
						"unit":	"minutes"
				}
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

dev_t:	(string)
개발용	메시지

Example:

//	로그인	필요
{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

//	(재)로그인	필요
{
		"code":	"94014",
		"dev_t":	"Authentication	Error",
		"message":	"세션이	만료되어	재로그인이	필요합니다."
}

//	권한이	필요
{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

HTTP	status	code	404

리소스를	찾을	수	없음 (NOT	FOUND)

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

message:	required	(string)
결과	메시지

dev_t:	(string)
개발용	메시지

Example:

{
		"code":	"50007",
		"dev_t":	"System	API	Error",
		"message":	"존재하지	않는	리소스입니다."
}

로그	검색	진행	상태	요청

GET

/lr/log/{request_id}/status

IPS/DDoS	로그 	검색	진행	상태를	조회한다.

Request

URI	Parameters

request_id:	required	(string)
조회	시작	시	응답에	포함된	 요청	ID

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

Response

HTTP	status	code	200

IPS/DDoS	로그 	검색	진행	상태	요청	성공

Body

Media	type:	application/json

Type:	object

Properties
status:	required	(string)
검색	진행	상태

INIT :	초기	단계
IN_PROGRESS :	검색	진행	단계
DONE :	검색	완료	단계

status가	DONE	일	경우	더	이상	상태	요청	REST	API를	호출하지	않아도	됩니다.

progress:	required	(integer	-	minimum:	0	-	maximum:	100)
검색	진행률(0~100)

searched_cnt:	required	(integer)
검색	완료	건수

allow_next:	required	(one	of	true,	false)
다음(next)	검색	가능	여부
true:	'/next'	API	호출	가능,	false:	'/next'	API	호출	불가능

Example:

{
		"code":	"ok",
		"result":	{
				"status":	"DONE",
				"progress":	100,
				"searched_cnt":	576,
				"allow_next":	false
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

dev_t:	(string)
개발용	메시지

Example:

//	로그인	필요
{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

//	(재)로그인	필요
{
		"code":	"94014",
		"dev_t":	"Authentication	Error",
		"message":	"세션이	만료되어	재로그인이	필요합니다."
}

//	권한이	필요
{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

HTTP	status	code	404

리소스를	찾을	수	없음 (NOT	FOUND)

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

message:	required	(string)
결과	메시지

dev_t:	(string)
개발용	메시지

Example:

{
		"code":	"50007",
		"dev_t":	"System	API	Error",
		"message":	"존재하지	않는	리소스입니다."
}

로그	검색	결과	조회

GET

/lr/log/{request_id}/page/{start}/to/{end}

IPS/DDoS	로그 	검색	결과를	조회한다.

Request

URI	Parameters

request_id:	required	(string)
조회	시작	시	응답에	포함된	 요청	ID

start:	required	(integer)

검색	시작	인덱스
결과	데이터에	대한	인덱스를	기준으로	합니다.

end:	required	(integer)
검색	종료	인덱스
결과	데이터에	대한	인덱스를	기준으로	합니다.

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

Response

HTTP	status	code	200

IPS/DDoS	로그 	검색	결과	조회	성공

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

result:	required	(object)
별첨으로	제공되는	로그	기능	별	컬럼	정의서	참고

Example:

//	예)	IPS/DDoS	공격	현황	로그
{
		"code":	"ok",
		"result":	{
				"log":	[
						{
								"stime":	"2020-05-18	15:42:40",
								"etime":	"2020-05-18	15:47:48",
								"mach_id":	"BLUEMAX_slave_4b21",
								"type":	"DDoS",
								"threat_category":	"DDoS",
								"threat_id":	"Flooding_App	Protocol",
								"event_id":	905103,
								"event_name":	"DNS	Response	Flooding	1:1",
								"risk":	"medium",
								"pd_name":	"전체도메인",
								"pf_name":	"ddos_profile_1",
								"packets":	392,
								"bytes":	55235,
								"action":	"detect",
								"status":	"End"
						}
				]
		}
}

//	예)	DDoS	보호	도메인	트래픽	현황	로그
{
		"code":	"ok",
		"result":	{
				"log":	[
						{
								"time":	"2020-05-18	15:49:40",
								"mach_id":	"BLUEMAX_slave_4b21",
								"pd_name":	"192.168.20.20도메인",
								"in_tcp_pps":	0,
								"in_tcp_detect_pps":	0,
								"in_tcp_bps":	0,
								"in_tcp_detect_bps":	0,

								"in_udp_pps":	0,
								"in_udp_detect_pps":	0,
								"in_udp_bps":	0,
								"in_udp_detect_bps":	0,
								"in_icmp_pps":	0,
								"in_icmp_detect_pps":	0,
								"in_icmp_bps":	0,
								"in_icmp_detect_bps":	0,
								"in_etc_pps":	0,
								"in_etc_detect_pps":	0,
								"in_etc_bps":	0,
								"in_etc_detect_bps":	0,
								"out_tcp_pps":	9702,
								"out_tcp_detect_pps":	5345,
								"out_tcp_bps":	62850360,
								"out_tcp_detect_bps":	39267240,
								"out_udp_pps":	65,
								"out_udp_detect_pps":	0,
								"out_udp_bps":	84528,
								"out_udp_detect_bps":	0,
								"out_icmp_pps":	20,
								"out_icmp_detect_pps":	6,
								"out_icmp_bps":	16320,
								"out_icmp_detect_bps":	4896,
								"out_etc_pps":	20,
								"out_etc_detect_pps":	0,
								"out_etc_bps":	1140,
								"out_etc_detect_bps":	0
						}
				]
		}
}

//	예)	DDoS	보호	도메인	별	TCP	Flag	별	트래픽	현황	로그
{
		"code":	"ok",
		"result":	{
				"log":	[
						{
								"time":	"2020-05-18	15:50:10",
								"mach_id":	"BLUEMAX_slave_4b21",
								"pd_name":	"192.168.20.20도메인",
								"in_syn_pps":	0,
								"in_syn_detect_pps":	0,
								"in_syn_bps":	0,
								"in_syn_detect_bps":	0,
								"in_fin_pps":	0,
								"in_fin_detect_pps":	0,
								"in_fin_bps":	0,
								"in_fin_detect_bps":	0,
								"in_rst_pps":	0,
								"in_rst_detect_pps":	0,
								"in_rst_bps":	0,
								"in_rst_detect_bps":	0,
								"in_push_pps":	0,
								"in_push_detect_pps":	0,
								"in_push_bps":	0,
								"in_push_detect_bps":	0,
								"in_ack_pps":	0,
								"in_ack_detect_pps":	0,
								"in_ack_bps":	0,
								"in_ack_detect_bps":	0,
								"in_urg_pps":	0,
								"in_urg_detect_pps":	0,
								"in_urg_bps":	0,
								"in_urg_detect_bps":	0,
								"in_etc_pps":	0,
								"in_etc_detect_pps":	0,
								"in_etc_bps":	0,
								"in_etc_detect_bps":	0,
								"out_syn_pps":	62,
								"out_syn_detect_pps":	16,
								"out_syn_bps":	34720,
								"out_syn_detect_bps":	8960,
								"out_fin_pps":	50,
								"out_fin_detect_pps":	12,
								"out_fin_bps":	23200,
								"out_fin_detect_bps":	5568,
								"out_rst_pps":	18,
								"out_rst_detect_pps":	4,
								"out_rst_bps":	8352,
								"out_rst_detect_bps":	1856,
								"out_push_pps":	2246,
								"out_push_detect_pps":	488,
								"out_push_bps":	7081400,
								"out_push_detect_bps":	1422608,
								"out_ack_pps":	2940,
								"out_ack_detect_pps":	750,
								"out_ack_bps":	24806928,
								"out_ack_detect_bps":	6749040,
								"out_urg_pps":	0,
								"out_urg_detect_pps":	0,
								"out_urg_bps":	0,
								"out_urg_detect_bps":	0,
								"out_etc_pps":	0,
								"out_etc_detect_pps":	0,
								"out_etc_bps":	0,
								"out_etc_detect_bps":	0
						}

				]
		}
}

//	예)	IPS/DDoS	트래픽	학습	현황	로그
{
		"code":	"ok",
		"result":	{
				"log":	[
						{
								"time":	"2020-05-18	15:50:46",
								"mach_id":	"BLUEMAX_master_9425",
								"pd_name":	"192.168.20.20도메인",
								"tot_pps":	0,
								"tot_bps":	0,
								"tcp_pps":	0,
								"tcp_bps":	0,
								"udp_pps":	0,
								"udp_bps":	0,
								"icmp_pps":	0,
								"icmp_bps":	0,
								"etc_pps":	0,
								"etc_bps":	0
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

dev_t:	(string)
개발용	메시지

Example:

//	로그인	필요
{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

//	(재)로그인	필요
{
		"code":	"94014",
		"dev_t":	"Authentication	Error",
		"message":	"세션이	만료되어	재로그인이	필요합니다."
}

//	권한이	필요
{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

HTTP	status	code	404

리소스를	찾을	수	없음 (NOT	FOUND)

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

message:	required	(string)
결과	메시지

dev_t:	(string)
개발용	메시지

Example:

{
		"code":	"50007",
		"dev_t":	"System	API	Error",
		"message":	"존재하지	않는	리소스입니다."
}

로그	다음	검색	수행

DELETE

/lr/log/{request_id}/page/next

IPS/DDoS	로그 	다음	검색을	수행한다.

Request

URI	Parameters

request_id:	required	(string)
조회	시작	시	응답에	포함된	 요청	ID

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

Response

HTTP	status	code	200

IPS/DDoS	로그 	다음	검색	성공

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

dev_t:	(string)
개발용	메시지

Example:

//	로그인	필요
{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

//	(재)로그인	필요
{
		"code":	"94014",
		"dev_t":	"Authentication	Error",
		"message":	"세션이	만료되어	재로그인이	필요합니다."
}

//	권한이	필요
{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

HTTP	status	code	404

리소스를	찾을	수	없음 (NOT	FOUND)

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

message:	required	(string)
결과	메시지

dev_t:	(string)
개발용	메시지

Example:

{
		"code":	"50007",
		"dev_t":	"System	API	Error",
		"message":	"존재하지	않는	리소스입니다."
}

로그	검색	중지

DELETE

/lr/log/{request_id}/stop

IPS/DDoS	로그 	진행	중인	검색을	중지한다.

Request

URI	Parameters

request_id:	required	(string)
조회	시작	시	응답에	포함된	 요청	ID

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

Response

HTTP	status	code	200

IPS/DDoS	로그 	검색	중지	성공

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

dev_t:	(string)
개발용	메시지

Example:

//	로그인	필요
{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

//	(재)로그인	필요
{
		"code":	"94014",
		"dev_t":	"Authentication	Error",
		"message":	"세션이	만료되어	재로그인이	필요합니다."
}

//	권한이	필요
{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

HTTP	status	code	404

리소스를	찾을	수	없음 (NOT	FOUND)

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

message:	required	(string)
결과	메시지

dev_t:	(string)
개발용	메시지

Example:

{
		"code":	"50007",
		"dev_t":	"System	API	Error",
		"message":	"존재하지	않는	리소스입니다."
}

로그	검색	종료

DELETE

/lr/log/{request_id}/end

IPS/DDoS	로그 	검색	종료	후	리소스를	해제한다.

Request

URI	Parameters

request_id:	required	(string)
조회	시작	시	응답에	포함된	 요청	ID

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

Response

HTTP	status	code	200

IPS/DDoS	로그 	검색	종료	성공

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

dev_t:	(string)
개발용	메시지

Example:

//	로그인	필요
{
		"code":	"94011",
		"message":	"인증되지	않은	상태에서	API가	요청되었습니다."
}

//	(재)로그인	필요
{
		"code":	"94014",
		"dev_t":	"Authentication	Error",
		"message":	"세션이	만료되어	재로그인이	필요합니다."
}

//	권한이	필요
{
		"code":	"94019",
		"message":	"인가되지	않은	API	요청입니다."
}

HTTP	status	code	404

리소스를	찾을	수	없음 (NOT	FOUND)

Body

Media	type:	application/json

Type:	object

Properties
code:	required	(string)
결과	코드

message:	required	(string)
결과	메시지

dev_t:	(string)
개발용	메시지

Example:

{
		"code":	"50007",
		"dev_t":	"System	API	Error",
		"message":	"존재하지	않는	리소스입니다."
}

