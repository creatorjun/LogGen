2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

WAPPLES Web API

v5.0  기준으로 작성된 문서입니다.
v4.0 의 경우WAPPLES 4.0 Web API 사용 가이드를 참고하세요.

목차

개요 & history

동작 방식

php 설정

rewrite 설정

접근 제어

Resources

기본 형식

URI Resource

Auth

/auth (type:JSON)

OAuth

/conf/oauth_client (type:JSON)

/conf/oauth_client/(client id) (type:JSON)

/conf/oauth_access_token (type:JSON)

Users

/conf/users (type:JSON)

/conf/users/(doc id) (type:JSON)

/conf/users/(administrators | website_administrators | monitors) (type:JSON)

/conf/users/(doc id)/last_activity (type:JSON)

/conf/groups (type:JSON)

/conf/groups/(doc id) (type:JSON)

/conf/user_application_data (type:JSON)

/conf/user_application_data/(doc_id) (type:JSON)

정책 및 웹 사이트 설정(Policy & Website)

/conf/policy (type:JSON)

/conf/policy/(doc id) (type:JSON)

/conf/policy/(doc_id)/rules (type:JSON)

/conf/rule (type:JSON)

/conf/rule/(doc id) (type:JSON)

/conf/detection_setting (type:JSON)

/conf/detection_setting/(doc id) (type:JSON)

/conf/uri_list (type:JSON)

/conf/uri_list/(doc id) (type:JSON)

/conf/web_site_defacement (type:JSON)

/conf/web_site_defacement/(doc id) (type:JSON)

/conf/rule_exception (type:JSON)

/conf/rule_exception/(doc id) (type:JSON)

/conf/ip_block (type:JSON)

/conf/ip_block_exception (type:JSON)

/conf/ip_block_exception/(doc_id) (type:JSON)

/conf/user_defined (type:JSON)

/conf/user_defined/(doc id) (type:JSON)

/conf/user_defined/(doc_id)/patterns (type:JSON)

/conf/user_defined_pattern (type:JSON)

/conf/user_defined_pattern/(doc id) (type:JSON)

/conf/exception_pattern(type:JSON)

/conf/exception_pattern/(doc id) (type:JSON)

/conf/website (type:JSON)

/conf/website/(doc id) (type:JSON)

/conf/http_dos(type:JSON)

탐지관련

/conf/parameter_encryption (type:JSON)

/conf/parameter_encryption/(doc id ) (type:JSON)

/conf/access_control (type:JSON)

/conf/access_control_filter (type:JSON)

/conf/access_control_filter/(doc_id) (type:JSON)

/conf/detect_exception_pattern (type:JSON)

/conf/detect_exception_pattern/(doc_id) (type:JSON)

/conf/error_handling_pattern (type:JSON)

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

1/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

/conf/error_handling_pattern/(doc_id) (type:JSON)

/conf/filter_by_xff (type:JSON)

/conf/src_ip_by_xff (type:JSON)

로그(Log)

/conf/audit (type:JSON)

/log/auditlog

/log/auditlog/count

/export/auditlog

/export/auditlog/(hash_id) (type:JSON)

/log/intrusionlog

/log/intrusionlog/count

/log/intrusionlog/sequence/(sequence_num)

/export/intrusionlog (type:JSON)

/export/intrusionlog/(hash_id) (type:JSON)

상태정보(Current Status)

/status/web_traffic(type:JSON) (~v4.0)

/info/redundant_psu(type:JSON)

/status/power_supply(type:JSON)

/status/database

/status/disk

/status/ha

/status/detection_engine (type:JSON)

/info/system/cpu (type:JSON)

/status/sw_bypass

/status/sw_nifc (type:JSON)

/status/network_interface (type:JSON)

/status/website_health (type:JSON)

/info/conf_db(type:JSON)

통계정보(Statistical Informations)

/statistics/intrusionlog (type:JSON)

탐지로그 통계

탐지룰별 대응 현황

웹사이트별 탐지로그

웹사이트별 룰 통계

탐지로그 검토하기

/statistics/system/cpu_mem (type:JSON)

/statistics/system/traffic (type:JSON)

/statistics/web_traffic(type:JSON) (v4.1~)

/statistics/nic_stat(type:JSON)

네트워크(Network)

/conf/proxy (type:JSON)

/conf/proxy/(doc id) (type:JSON)

/conf/webserver (type:JSON)

/conf/webserver/(doc id) (type:JSON)

/conf/ssl_profile (type:JSON)

/conf/ssl_profile/(doc id) (type:JSON)

/conf/network_interface (type:JSON)

/conf/management_route (type:JSON)

/conf/net_filter (type:JSON)

/conf/net_filter/(number) (type:JSON)

/conf/dns (type:JSON)

/conf/hosts (type:JSON)

/conf/third_party_integration (type:JSON)

/conf/email(type:JSON)

/conf/snmp_trap(type:JSON)

/info/nic (type:JSON)

외부 연동(External Interlock)

/conf/time_server (type:JSON)

/conf/time

/status/time_server

/conf/pls (type:JSON)

/status/pls (type:JSON)

/status/pls_missinglog

/conf/mail_sender (type:JSON)

/status/email/(email_id) (type:JSON)

/conf/syslog(type:JSON)

/conf/sims(type:JSON)

라이선스(License)

/conf/func_license (type:JSON)

/conf/wplicense_info

/conf/license_agreement (type:JSON)

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

2/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

/conf/alarm_license (type:JSON)

리소스 알람

/conf/alarm_resource

/status/alarm_resource

업데이트(WAPPLES update)

/conf/update(type:JSON)

/status/recently_update

/status/update

DB & 백업(DB & Backup)

/conf/db_backup (type:JSON)

/conf/db_restore (type:JSON)

/conf/db_restore/stop (type:JSON)

/info/backup_file_list (type:JSON)

/info/backup_file_list/(file_name)(type:JSON)

/status/restore (type:JSON)

/file/transfer

보고서(Report)

/conf/report_config (type:JSON)

/conf/report_form (type:JSON)

/conf/report_form/(doc_id) (type:JSON)

/conf/custom_report (type:JSON)

memcached

/conf/cache (type:JSON)

/conf/cache/(key) (type:JSON)

WAPPLES 정보

/info/sphere (type:JSON)

/info/version (type:JSON)

/info/issac_key (type:JSON)

/

SignalSender

/msgbus/signal

Notify 형식

audit message 형식

KT Resources

KT 전용 Resource별 URI 목록과 지원되는 method

/webservers (type:XML)
/webservers/id (type:XML)

/vhosts (type:XML)
/vhosts/id (type:XML)

KT 전용 Resource 표현 형식

웹서버 설정(class WebServer에 대응)

웹사이트 설정(class VirtualHost에 대응)

XML Schema

응답 오류 (Errors)

Error msg format

Result code

Reason code

Response Message

Format

Code

Category Code

Cause code

000 : Success

001 : Authentication failed

002 : Authentication required

003 : Invalid session

004 : Invalid client

005 : Unauthorized user

006 : Unauthorized group

007 : Bad request

008 : Could not get information

009 : Failed to set

010 : Failed to delete

011 : No connection information

012 : Failed to upload file

013 : Method not allowed

014 : Attempted CSS attacks

015 : Failed to download file

016 : Intrusionlog export failed

017 : Invalid IP

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

3/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

018 : Maximum number of DNS servers exceeded

019 : Session is locked

020 : Database Error

021 : Unauthorized function

검증 규칙

Port 검증

호스트 IP 검증

AbsPath

Netmask

도메인 검증

URL

이메일 검증

전화번호 검증

호스트명 검증

룰 별 Param (사용자 정의 입력값)

Buffer Overflow

Cookie Poisoning

Cross Site Scripting

Directory Listing

Directory Traversal

Error Handling

Extension Filtering

File Upload

Include Injection

Input Content Filtering

Invalid HTTP

Invalid URL

IP Filtering

Parameter Tampering

Privacy File Filtering

Privacy Input Filtering

Privacy Output Filtering

Request Header Filtering

Request Method Filtering

Response Header Filtering

SQL Injection

Stealth Commanding

Suspicious Access

Unicode Directory Traversal

URL Access Control

Stealth Commanding

Website Defacement

TODO

관련 문서

개요 & history

와플의 관리 목적을 위해서 와플과 외부와의 통신 채널이 필요하다. 와플 2.0과 와플 3.0에서는 기본적으로 관리 콘솔 접근을 위해서 직접 DB에 접속하였으나, 이 방식은 여러가지 문제를
야기하였다. 이러한 이유로 보다 정갈한 방식의 외부 인터페이스가 필요하게 되었는데, KT의 cloud 사업상 필요성 때문에 REST style의 API를 제공할 필요가 있었다. 따라서, KT를 위한
REST style의 API를 작성하고, 이를 확장하여 미래의 진보된 UI와 외부 연동 기반 구조를 제공하기로 한다. 또한, WAPPLES 기능들의 설정 파일을 저장하는 통로로 사용된다.Webapi를
사용한 WAPPLES 설정 저장 참조

추가적인 설명내용이 discussion 에 기술되어 있음.

동작 방식

REST API 참조

WAPPLES의 apache daemon과 php, postgresql을 통해서 API를 제공한다.

php 설정

httpd_consol.conf(왜 httpd_console.conf가 아닌 거야!)에서 php module을 load한다. 그리고 이 module이 load 돼 있을 때에만 확장자가 php인 파일에 대해서 handler를 등록하고,
/sphere/webapi/docroot/를  /webapi/로  alias를  건다.  console용  apache의  document  root는  /sphere/htdocs이지만  이  directory는  api용  php  소스를  넣기에  적당치  않기  때문에
/sphere/webapi 아래에 API용 php 소스들을 둔다.

rewrite 설정

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

4/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

API의 최상위 URL은 /webapi이고, 이 URL base, 즉 /sphere/webapi/docroot에 .htaccess file을 통해서 apache의 rewrite engine을 설정한다. /webapi 이하로 접근하는 URL에 대해서
는 /webapi/dispatch.php로 request를 전달한다. 실제 request를 처리하는 것은 모두 이 dispatch.php로부터 이루어지며, 이 php script는Tonic library의 일부이다.

접근 제어

v5.0  VirtualHost 설정을 통해서 web api로 접근하는 경로를 제한하고 있다. web api를 접근하기 위해서는 443 포트로 https 요청을 해야 한다.
이 때 인증 과정을 먼저 수행해야 하며, /webapi/auth URI로 관리자 ID와 password를 전달해야 한다.

v3.0R9  KT를 위해서 제공되고 있는 web api의 경우는 non-SSL port로 간단한 HTTP digest 방식의 인증을 사용한다. r14008부터는 기존에 제공되는 non-SSL port에 대한 접근은 그
대로  유지하면서  SSL  port로의  접근이  추가되었다.  SSL  port로의  접근을  위해서는  v5.0 에서와  같은  방식의  인증을  수행해야  하는데,  다른  점이  있다면  v5.0 에서는  관리자  ID와
password를 사용하는 데 반해서  v3.0R9 에서는 root 계정과 password를 전달해야 한다는 것이다.

Resources

API의 최상위 URL은 /webapi이고 아래의 디렉토리에 접근할 때 /webapi/* 등으로 접근해야 한다.

Web API로 전달된 HTTP method가 이 section에서 정의하는 method 외의 것일 경우에는 와플은 405 Method Not Allowed를 응답하고, Allow header field를 통해 사용 가
능한 method들을 전달한다. 또한, OPTIONS method에 대해서도 Allow header field를 통해 사용 가능한 method들을 전달한다.

multi document의 경우 doc_format, doc_type column을 추가함.

 Note: v4.0.5 CC version에 쓰이는 web api는/v4.0.5_CC 페이지를 참조.

 Note: v4.0까지 제공되는 web api는 KT 전용 URL와 resource 표현 형식을 사용해야 한다.

기본 형식

아래 형식으로 작성합니다. Resource에 대한 설명이 있은후 각 method에 대해 Request Parameter와 Response fields를 작성합니다.

 Note: Data Type은Json Data Type (https://en.wikipedia.org/wiki/JSON#Data_types.2C_syntax_and_example)을 따릅니다.

URI Resource

설명

method

Request Parameter

Request
Parameter

Data Type

Explanation

Required

--

Example

Response fields

Response
field

Data Type

Explanation

--

Example

Auth

/auth (type:JSON)

사용자 인증을 합니다. ( v3.0R9 , v4.0 에도 제공되지만 관리자 계정이 아니라 root 계정 정보를 사용해야 한다.)
Request의 Content-Type: application/x-www-form-urlencoded 입니다.

POST

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

5/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

Explanation

Required

id

String

인증을 위한 사용자 ID 값

password

String

패스워드

Example

Response fields

Response
field

Data Type

String

String

String

result msg

접속한 client IP

인증 된 user doc ID

res_msg

client_ip

doc_id

Example

O

O

공백 입력 불가

길이: 4~30

문자 규칙: 영어,

공백 입력 불가

길이: 0~15

문자 규칙:

1. 1개 이상의 특수

2. 영어+특수문자

Explanation

인증에 성공하면 200OK를 리턴하고 WP_SESSID라는 이름의 cookie를 설정한다. cookie를 자동으로 handling하지 않는 web client의 경우에는 Set-Cookie
header를 통해서 전달되는 cookie를 직접 저장하고 있다가, 이후의 webapi에 접근할 때마다 Cookie header를 통해서 webapi에 전달해야 한다. 이 WP_SESSID
cookie는 해당 client IP에 대해서만 유효하다. 사용하지 않은지 24분이 지나면 만료된다. (24분 제한은 php의 기본 동작이다.)

인증에 실패하면 오류메시지를 리턴합니다.

OAuth

/conf/oauth_client (type:JSON)

WAPPLES OAuth2.0을 사용할 서비스를 등록합니다.
Request의 Content-Type: json 입니다.

GET

Request Parameter

Request
Parameter

Data Type

--

--

--

Explanation

Required

--

--

Example

Response fields

Response
field

client_id

client_secret

product

Example

Data Type

Explanation

클라이언트 ID

client_secret

등록된 서비스 이름

POST

Request Parameter

Request
Parameter

Data Type

Explanation

Required

product

String

등록할 서비스 이름

O

공백 및 중복 입력

Example

Response fields

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

6/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

client_id

String

클라이언트 ID

client_secret

String

클라이언트 비밀키

product

String

등록된 서비스 이름

Example

product 이름은 중복하여 등록하 수 없습니다.

/conf/oauth_client/(client id) (type:JSON)

GET

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

client_id

String

클라이언트 ID

client_secret

String

client_secret

product

String

등록된 서비스 이름

Example

DELETE

특정 서비스를 삭제합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

Explanation

/conf/oauth_access_token (type:JSON)

OAuth2.0 access_token을 발급 받습니다.
Request의 Content-Type: json 입니다. POST

Request Parameter

Request
Parameter

Data Type

grant_type

username

password

client_id

String

String

String

String

grant_type ( password, refresh_token )

인증을 위한 사용자 ID 값

비밀번호

클라이언트 ID

refresh_token

String

클라이언트 ID

Example

Response fields

Explanation

Required

O

O

O

O

O

"password", "refr

--

--

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

7/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

access_token

String

사용자 인증 임시 토큰

expires_in

Number

access_token 만료시간(초)

refresh_token

String

access_token 재발급을 위한 refresh_token

token_type

String

토큰 타입

Example

product 이름은 중복하여 등록할 수 없습니다.

Explanation

Users

/conf/users (type:JSON)

GET

User 목록 정보를 요청합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

8/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response fields

Data Type

Explanation

username

realname

description

company

email

licensedate_from

licensedate_to

address

phone

password

String

String

String

String

String

String

String

String

String

String

아이디

이름

비고

소속

이메일

유효기간 시작날짜.

ISO 8601 형식: YYYY-MM-DD HH:mm:SS

유효기간 종료날짜.

ISO 8601 형식: YYYY-MM-DD HH:mm:SS

주소

전화번호

비밀번호

passwd_change_on_new_access

Boolean

최초 로그인 시 비밀번호 변경 여부

true : 최초 로그인시 비밀번호 변경

false: 최초 로그인시 비밀번호 변경하지 않음

read_only

Boolean

조회자만 설정 할 수 있으며 true의 경우 웹사이트를 할당 할 수 없다.

시스템 조회 기능 여부

created_on

String

계정 생성 날짜.

ISO 8601 형식: YYYY-MM-DD HH:mm:SS

created_by

String

계정을 생성한 계정.

ISO 8601 형식: YYYY-MM-DD HH:mm:SS

last_activity

String

ISO 8601 형식 형식: YYYY-MM-DD HH:mm:SS

마지막 접속시간.

language

String

언어설정.

ko 한국어

ja 일본어

en 영어

session_lock_time

Number

세션잠금시간

indelible

Boolean

삭제 가능한 계정 여부.

true 삭제 불가

false 삭제 가능

admin 같이 삭제가 불가능한 계정은 true 아니면 false

Example

POST

User 목록 정보를 추가합니다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

9/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request Parameter

Data Type

Explanation

Required

username

String

아이디

realname

description

company

email

licensedate_from

String

String

String

String

String

이름

비고

소속

이메일

유효기간 시작날짜.

ISO 8601 형식: YYYY-MM-DD HH:mm:SS

licensedate_to

String

유효기간 종료날짜.

ISO 8601 형식: YYYY-MM-DD HH:mm:SS

address

phone

String

주소

String

전화번호

password

String

비밀번호

passwd_change_on_new_access

Boolean

read_only

Boolean

최초 로그인 시 비밀번호 변경 여부

true 최초 로그인시 비밀번호를 변경

false 최초 로그인시 비밀번호를 변경하지 않음

시스템 조회 기능 여부. 조회자만 설정 가능

true 웹사이트 할당 불가

false 웹사이트 할당 가능

created_on

created_by

String

String

계정 생성 날짜.

계정을 생성한 계정.

last_activity

String

마지막 접속시간.

language

String

X

언어설정.

ko 한국어

ja 일본어

en 영어

session_lock_time

Number

세션잠금시간

indelible

Boolean

삭제 가능한 계정 여부.

true 삭제 불가

false 삭제 가능

중복 입력 불

공백 입력 불

길이: 4~30

문자 규칙: 영

공백 입력 불

--

공백 입력 불

이메일 검증

유효기간  시작

거인지 확인

유효기간  시작

거인지 확인

--

--

전화번호 검증

공백 입력 불

길이: 9~15

문자 규칙:

1. 1개 이상의

2. 영어+특수

3.  비밀번호와

항목중  하나

롤에 오류메세

--

--

ISO 8601 형

ISO 8601 형

ISO 8601 형

--

0 이상의 숫자

--

O

O

X

O

X

X

X

x

x

O

X

X

X

X

X

X

X

Example

Response fields

Response
fields

Data Type

ok

Boolean

Example

/conf/users/(doc id) (type:JSON)

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

10/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

user정보에 언어 설정이 저장되어, 어느 client PC 에서 접속하든 해당 언어로 보이도록 언어 설정이 변경됨.

user정보에 세션 잠금 설정이 저장되어, user 별로, 세션 잠근 설정이 가능함.

user정보에 "indelible" 필드를 추가하여 삭제가 불가능하 계정(admin)에 대해 표시함.

GET

특정 User 정보를 요청 합니다.

Request Parameter

Request
Parameter

Data Type

Explanation

Required

password_include

Boolean

패스워드 포함 여부(optional)

X

--

Example

Response fields

Response fields

Data Type

Explanation

username

realname

description

company

email

licensedate_from

licensedate_to

address

phone

password

String

String

String

String

String

String

String

String

String

String

아이디

이름

비고

소속

이메일

유효기간 시작날짜.

형식: YYYY-MM-DD HH:mm:SS

유효기간 종료날짜.

형식: YYYY-MM-DD HH:mm:SS

주소

전화번호

비밀번호

passwd_change_on_new_access

Boolean

최초 로그인 시 비밀번호 변경 여부

true 최초 로그인시 비밀번호를 변경

false 최초 로그인시 비밀번호를 변경하지 않음

read_only

Boolean

시스템 조회 기능 여부 (조회자만 설정 할 수 있으며 true의 경우 웹사이트를 할당 할 수 없음)

created_on

String

created_by

String

last_activity

String

계정 생성 날짜.

형식: YYYY-MM-DD HH:mm:SS

계정을 생성한 계정.

형식: YYYY-MM-DD HH:mm:SS

마지막 접속시간.

형식: YYYY-MM-DD HH:mm:SS

language

String

언어설정.

한국어 ko, 일본어 ja, 영어 en

session_lock_time

Number

세션잠금시간

indelible

Boolean

삭제 가능한 계정 여부.

true 삭제불가

false 삭제가능

Example

PUT

특정 User 정보를 수정합니다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

11/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request Parameter

Data Type

Explanation

Required

중복 입력 불

공백 입력 불

길이: 4~30

문자 규칙: 영

공백 입력 불

--

공백 입력 불

이메일 검증

ISO 8601 형

유효기간  시작

거인지 확인

ISO 8601 형

유효기간  시작

거인지 확인

--

전화번호 검증

공백 입력 불

길이: 0~15

문자 규칙:

1. 1개 이상의

2. 영어+특수

비밀번호와 비

위의  항목중

당컨트롤에 오

--

--

ISO 8601 형

ISO 8601 형

ISO 8601 형

--

--

--

O

O

X

O

X

X

X

X

X

O

X

X

X

X

X

X

X

X

username

String

아이디

realname

description

company

String

String

String

이름

비고

소속

email

String

이메일

licensedate_from

String

유효기간 시작날짜.

ISO 8601 형식: YYYY-MM-DD HH:mm:SS

licensedate_to

String

유효기간 종료날짜.

address

phone

String

주소

String

전화번호

password

String

비밀번호

passwd_change_on_new_access

Boolean

최초 로그인 시 비밀번호 변경 여부 (true의 경우 최초 로그인시 비밀번호를 변경하는
창이 나오고 비밀번호를 변경하면 false로 변경)

read_only

Boolean

시스템 조회 기능 여부 (조회자만 설정 할 수 있으며 true의 경우 웹사이트를 할당 할
수 없음)

created_on

created_by

last_activity

String

String

String

계정 생성 날짜.

계정을 생성한 계정.

마지막 접속시간.

language

String

언어설정.

ko 한국어

ja 일본어

en 영어

session_lock_time

Number

세션잠금시간

indelible

Boolean

삭제 가능한 계정 여부.

true 삭제 불가

false 삭제 가능

admin 같이 삭제가 불가능한 계정은 true 아니면 false

Example

Response fields

Response
fields

Data Type

ok

Boolean

--

Example

DELET

특정 User 정보를 삭제합니다.

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

12/141

2020. 8. 7.

Request Parameter

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
fields

Data Type

ok

Boolean

--

Example

Explanation

Required

--

--

Explanation

/conf/users/(administrators | website_administrators | monitors) (type:JSON)

각 resource에 맞는 group에 대항하는 users 정보를 가져올 수 있다.

GET

Request Parameter

Request
Parameter

Data Type

Explanation

Required

password_include

Boolean

패스워드 포함 여부.

X

--

Example

Response fields

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

13/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response fields

Data Type

Explanation

username

realname

description

company

email

licensedate_from

licensedate_to

address

phone

password

String

String

String

String

String

String

String

String

String

String

아이디

이름

비고

소속

이메일

유효기간 시작날짜.

형식: YYYY-MM-DD HH:mm:SS

유효기간 종료날짜.

형식: YYYY-MM-DD HH:mm:SS

주소

전화번호

비밀번호

passwd_change_on_new_access

Boolean

최초 로그인 시 비밀번호 변경 여부 true 최초 로그인시 비밀번호를 변경 false 최초 로그인시 비밀번호를 변경하지 않음

read_only

Boolean

시스템 조회 기능 여부 (조회자만 설정 할 수 있으며 true의 경우 웹사이트를 할당 할 수 없다.)

created_on

String

created_by

String

last_activity

String

생성 날짜.

형식: YYYY-MM-DD HH:mm:SS

계정을 생성한 계정.

형식: YYYY-MM-DD HH:mm:SS

접속시간.

형식: YYYY-MM-DD HH:mm:SS

language

String

언어설정.

한국어 ko, 일본어 ja, 영어 en

session_lock_time

Number

세션잠금시간

indelible

Boolean

삭제 가능한 계정 여부.

true 삭제불가

false 삭제가능

Example

/conf/users/(doc id)/last_activity (type:JSON)

저장 장소 : /tmp/connection_state/(doc_id)

GET

User's last activity time을 조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Response
field

Data Type

time

String

형식: YYYY-MM-DD HH:mm:SS

마지막 접속시간.

Explanation

Example

PUT

User's last activity time을 갱신합니다.

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

14/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

일정한 주기로 관리도구에서 해당 webapi를 호출하여 시간을 갱신합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

--

--

--

Example

/conf/groups (type:JSON)

GET

User group 목록 정보를 조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

Response
field

Data Type

groupname

String

그룹이름

members[]

Array

그룹에 추가할 계정(user doc id)

created_on

String

ISO 8601 형식: YYYY-MM-DD HH:mm:SS

만들어진 날짜.

created_by

String

만든 계정

Explanation

Example

POST

User group 목록 정보를 추가합니다.

Request Parameter

Request
Parameter

Data Type

groupname

String

그룹이름

members[]

Array

그룹에 추가할 계정(user_doc_id)

created_on

String

만들어진 날짜.

created_by

String

만든 계정

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/groups/(doc id) (type:JSON)

Explanation

Required

X

X

X

X

--

--

ISO 8601형식: YY

--

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

15/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

한 user는 여러 개의 group에 속할 수 있음.

GET

특정 Group의 정보를 조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Response
field

Data Type

groupname

String

그룹이름

members[]

Array

그룹에 추가할 계정(user doc id)

created_on

String

ISO 8601 형식: YYYY-MM-DD HH:mm:SS

만들어진 날짜.

created_by

String

만든 계정

Explanation

Example

PUT

특정 Group의 정보를 설정합니다.

Request Parameter

Request
Parameter

Data Type

groupname

String

그룹이름

members[]

Array

그룹에 속하는 ID(user doc id)

Explanation

Required

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

DELETE

특정 Group의 정보를 삭제합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/user_application_data (type:JSON)

 Note: 비공개 webapi입니다

GET

Explanation

Explanation

Required

Explanation

--

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

16/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

user_application_data 목록을 조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

17/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response field

Data Type

Explanation

users_doc_id

data

intrusionlog_filter

intrusionlog_filter[name]

intrusionlog_filter[website]

intrusionlog_filter[period]

String

String

Array

String

String

String

users doc_id

탐지로그 필터

탐지로그 필터 이름

탐지로그 필터 웹사이트

탐지로그 필터 기간

intrusionlog_filter[state]

Number

탐지로그 필터 상태

intrusionlog_filter[action]

String

intrusionlog_filter[src_ip]

Object

"src_ip":{ "Include":false, "Values":[] }

intrusionlog_filter[src_ip]
[Include]

Boolean

intrusionlog_filter[src_ip][Values]

String

intrusionlog_filter[dest_ip]

Object

"dest_ip":{ "Include":false, "Values":[] }

intrusionlog_filter[dest_ip]
[Include]

intrusionlog_filter[dest_ip]
[Values]

Boolean

String

intrusionlog_filter[url]

Object

"url":{ "Include":false, "Values":[] }

intrusionlog_filter[url][Include]

Boolean

intrusionlog_filter[url][Values]

String

intrusionlog_filter[country]

Object

"country":{ "Include":false, "Values":[] }

intrusionlog_filter[country]
[Include]

intrusionlog_filter[country]
[Values]

Boolean

String

intrusionlog_filter[rule]

Object

"rule":{ "Include":false, "Values":[] }

intrusionlog_filter[rule][Include]

Boolean

intrusionlog_filter[rule][Values]

String

auditLog_filter[name]

auditLog_filter[type]

auditLog_filter[period]

String

String

String

감사로그 필터 이름

감사로그 필터 로그종류

감사로그 필터 기간

period_custom_data

Object

{ "period": 1, "method": 3, "value": -1, "time": "2015-10-16 14:53:00", "start": "2015-09-01 14:48:00", "end": "2015-10-1

period_custom_data[period]

Number

기간 사용자 정의

period_custom_data[method]

Number

period_custom_data[value]

Number

period_custom_data[time]

String

period_custom_data[start]

String

period_custom_data[end]

String

기간 사용자 정의 설정한 기간.

ISO 8601 형식: YYYY-MM-DD HH:mm:SS

기간 사용자 정의 설정한 기간.

ISO 8601 형식: YYYY-MM-DD HH:mm:SS

기간 사용자 정의 설정한 기간.

ISO 8601 형식: YYYY-MM-DD HH:mm:SS

intrusionFilterCB_data[ruleName]

String

탐지로그 룰 사용자 정의 룰 이름.

intrusionFilterCB_data[ruleData]

String

탐지로그 룰 사용자 정의 룰 데이터

intrusionFilterCB_data[name]

String

사용자 정의 이름

intrusionFilterCB_data[state]

Number

로그상태

전체 로그 표시: 0

숨김 로그 표시: 1

전체 로그 표시: 2 (숨김 로그 포함)

intrusionFilterCB_data[action]

String

대응상태

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

18/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

intrusionFilterCB_data[src_ip]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[src_ip]
[Values][]

Array

출발 ip 목록

intrusionFilterCB_data[dest_ip]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[dest_ip]
[Values][]

Array

목록

intrusionFilterCB_data[url]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[url]
[Values][]

Array

url 목록

intrusionFilterCB_data[country]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[countryl]
[Values][]

Array

국가 목록

intrusionFilterCB_data[rule]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[rule]
[Values][]

Array

룰 목록

Example

/conf/user_application_data/(doc_id) (type:JSON)

 Note: 비공개 webapi입니다

GET

특정 user_application_data를 조회 합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

19/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response field

Data Type

Explanation

users_doc_id

data

intrusionlog_filter

intrusionlog_filter[name]

intrusionlog_filter[website]

intrusionlog_filter[period]

String

String

Array

String

String

String

users doc_id

탐지로그 필터

탐지로그 필터 이름

탐지로그 필터 웹사이트

탐지로그 필터 기간

intrusionlog_filter[state]

Number

탐지로그 필터 상태

intrusionlog_filter[action]

intrusionlog_filter[src_ip]

intrusionlog_filter[src_ip]
[Include]

String

Object

Boolean

intrusionlog_filter[src_ip][Values]

String

"src_ip":{"Include":false,"Values":[]}

intrusionlog_filter[dest_ip]

Object

"dest_ip":{"Include":false,"Values":[]}

intrusionlog_filter[dest_ip]
[Include]

intrusionlog_filter[dest_ip]
[Values]

Boolean

String

intrusionlog_filter[url]

Object

"url":{"Include":false,"Values":[]}

intrusionlog_filter[url][Include]

Boolean

intrusionlog_filter[url][Values]

String

intrusionlog_filter[country]

Object

"country":{"Include":false,"Values":[]}

intrusionlog_filter[country]
[Include]

intrusionlog_filter[country]
[Values]

Boolean

String

intrusionlog_filter[rule]

Object

"rule":{"Include":false,"Values":[]}

intrusionlog_filter[rule][Include]

Boolean

intrusionlog_filter[rule][Values]

String

auditLog_filter[name]

auditLog_filter[type]

auditLog_filter[period]

String

String

String

감사로그 필터 이름

감사로그 필터 로그종류

감사로그 필터 기간

period_custom_data

Object

{ "period": 1, "method": 3, "value": -1, "time": "2015-10-16 14:53:00", "start": "2015-09-01 14:48:00", "end": "2015-10-1

period_custom_data[period]

Number

기간 사용자 정의

period_custom_data[method]

Number

period_custom_data[value]

Number

period_custom_data[time]

String

사용자 정의 설정한 기간.

ISO 8601 형식: YYYY-MM-DD HH:mm:SS

period_custom_data[start]

String

ISO 8601 형식: YYYY-MM-DD HH:mm:SS

사용자 정의 설정한 기간.

period_custom_data[end]

String

기간 사용자 정의 설정한 기간.

ISO 8601 형식: YYYY-MM-DD HH:mm:SS

intrusionFilterCB_data[ruleName]

String

탐지로그 룰 사용자 정의 룰 이름.

intrusionFilterCB_data[ruleData]

String

탐지로그 룰 사용자 정의 룰 데이터

intrusionFilterCB_data[name]

String

사용자 정의 이름

intrusionFilterCB_data[state]

Number

로그상태

전체 로그 표시: 0

숨김 로그 표시: 1

전체 로그 표시: 2 (숨김 로그 포함)

intrusionFilterCB_data[action]

String

대응상태

intrusionFilterCB_data[src_ip]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[src_ip]

Array

출발 ip 목록

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

20/141

2020. 8. 7.

[Values][]

WAPPLES Web API - Penta Security Wiki

intrusionFilterCB_data[dest_ip]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[dest_ip]
[Values][]

Array

목록

intrusionFilterCB_data[url]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[url]
[Values][]

Array

url 목록

intrusionFilterCB_data[country]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[countryl]
[Values][]

Array

국가 목록

intrusionFilterCB_data[rule]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[rule]
[Values][]

Array

룰 목록

Example

PUT

특정 user_application_data를 추가 합니다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

21/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request Parameter

Data Type

Explanation

Required

users_doc_id

data

intrusionlog_filter

intrusionlog_filter[name]

intrusionlog_filter[website]

intrusionlog_filter[period]

String

String

Array

String

String

String

users doc_id

data

탐지로그 필터

탐지로그 필터 이름

탐지로그 필터 웹사이트

탐지로그 필터 기간

intrusionlog_filter[state]

Number

탐지로그 필터 상태

intrusionlog_filter[action]

String

intrusionlog_filter[src_ip]

Object

"src_ip":{ "Include":false, "Values":[] }

intrusionlog_filter[src_ip]
[Include]

Boolean

intrusionlog_filter[src_ip][Values]

String

intrusionlog_filter[dest_ip]

Object

"dest_ip":{ "Include":false, "Values":[] }

intrusionlog_filter[dest_ip]
[Include]

intrusionlog_filter[dest_ip]
[Values]

Boolean

String

intrusionlog_filter[url]

Object

"url":{ "Include":false, "Values":[] }

intrusionlog_filter[url][Include]

Boolean

intrusionlog_filter[url][Values]

String

intrusionlog_filter[country]

Object

"country":{ "Include":false, "Values":[] }

intrusionlog_filter[country]
[Include]

intrusionlog_filter[country]
[Values]

Boolean

String

intrusionlog_filter[rule]

Object

"rule":{ "Include":false, "Values":[] }

intrusionlog_filter[rule][Include]

Boolean

intrusionlog_filter[rule][Values]

String

auditLog_filter[name]

auditLog_filter[type]

auditLog_filter[period]

String

String

String

감사로그 필터 이름

감사로그 필터 로그종류

감사로그 필터 기간

period_custom_data

Object

09-01 14:48:00", "end": "2015-10-16 14:53:00" }

{ "period": 1, "method": 3, "value": -1, "time": "2015-10-16 14:53:00", "start": "2015-

period_custom_data[period]

Number

기간 사용자 정의

period_custom_data[method]

Number

period_custom_data[value]

Number

period_custom_data[time]

period_custom_data[start]

period_custom_data[end]

String

String

String

기간 사용자 정의 설정한 기간.

기간 사용자 정의 설정한 기간.

기간 사용자 정의 설정한 기간.

intrusionFilterCB_data[ruleName]

String

탐지로그 룰 사용자 정의 룰 이름.

intrusionFilterCB_data[ruleData]

String

탐지로그 룰 사용자 정의 룰 데이터

intrusionFilterCB_data[name]

String

사용자 정의 이름

intrusionFilterCB_data[state]

Number

로그상태

전체 로그 표시: 0

숨김 로그 표시: 1

전체 로그 표시: 2 (숨김 로그 포함)

intrusionFilterCB_data[action]

String

대응상태

intrusionFilterCB_data[src_ip]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[src_ip]

Array

출발 ip 목록

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

--

--

--

공백 및 중복

URL 참고

ISO 8601 형

--

--

--

--

호스트 IP 검

--

--

호스트 IP 검

--

--

URL 참고

--

--

--

--

--

--

--

--

--

--

--

--

--

ISO 8601 형

ISO 8601 형

ISO 8601 형

중복 및 공백

--

중복 및 공백

--

--

--

호스트 IP 검

22/141

2020. 8. 7.

[Values][]

WAPPLES Web API - Penta Security Wiki

intrusionFilterCB_data[dest_ip]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[dest_ip]
[Values][]

Array

목록

intrusionFilterCB_data[url]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[url]
[Values][]

Array

url 목록

intrusionFilterCB_data[country]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[countryl]
[Values][]

Array

국가 목록

intrusionFilterCB_data[rule]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[rule]
[Values][]

Array

룰 목록

intrusionFilterCB_data[url]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[url]
[Values][]

Array

url 목록

intrusionFilterCB_data[country]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[countryl]
[Values][]

Array

국가 목록

intrusionFilterCB_data[rule]
[Include]

Boolean

필터링 설정

포함: true

제외: flase

intrusionFilterCB_data[rule]
[Values][]

Array

룰 목록

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

DELETE

특정 user_application_data를 삭제 합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

--

--

--

URL 참고

--

--

--

룰 이름

--

URL 참고

--

--

--

룰 이름

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

23/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

ok

Boolean

Example

정책 및 웹 사이트 설정(Policy & Website)

Explanation

/conf/policy (type:JSON)

GET

정책설정을 조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

owner

name

String

String

정책 소유자

정책이름

Explanation

Required

--

--

Explanation

read_only

Boolean

수정가능여부, 기본정책처럼 수정 불가능한 정책은 true 나머지는 false

rules

Array

rule doc id, 정책설정의 설정한 룰

Example

POST

정책설정을 추가합니다.

Request Parameter

Request
Parameter

Data Type

owner

String

정책 소유자

name

String

정책이름

read_only

Boolean

true: 수정 불가능 false: 수정 가능

수정가능여부.

rules

Array

rule doc id, 정책설정의 설정한 룰

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/policy/(doc id) (type:JSON)

GET

특정 정책의 설정을 조회합니다.

Request Parameter

Explanation

Required

X

O

X

X

--

공백 및 중복 입력

길이: 64자 이내

--

--

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

24/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

--

--

--

Example

Response Parameter

Response
field

Data Type

owner

name

String

String

정책 소유자

정책이름

read_only

Boolean

수정가능여부.

true: 수정 불가능

false: 수정 가능

rules

Array

rule doc id, 정책설정의 설정한 룰

Example

PUT

특정 정책의 설정을 수정합니다.

Request Parameter

Request
Parameter

Data Type

owner

String

정책 소유자

name

String

정책이름

read_only

Boolean

수정가능여부

true: 수정 불가능

false: 수정 가능

rules

Array

정책설정의 설정한 룰(rule_doc_id)

Example

Response fields

Response
field

Data Type

ok

Boolean

--

Example

DELETE

특정 정책을 삭제합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/policy/(doc_id)/rules (type:JSON)

GET

Explanation

Required

--

--

Explanation

Explanation

Required

X

O

X

Xc

--

공백 및 중복 입력

길이: 64자 이내

--

--

Explanation

Explanation

Required

--

--

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

25/141

2020. 8. 7.

특정한 정책의 룰 설정들을 조회

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response field

Data Type

rule_id

Number

rule id

rule_name

String

룰 이름

level

Number

탐지설정

WAPPLES Web API - Penta Security Wiki

Explanation

Required

--

--

Explanation

param

Array

{\"사용자 정의 항목\":\"사용자 정의값\",....}

사용자 정의 설정값.

response_type

Number

대응설정

response_arg

String

사용 x

response_errorcode

String

에러코드

response_redirect

String

페이지 이름

ipblock_weight

Number

룰 위험도

Example

/conf/rule (type:JSON)

GET

전체 룰 설정을 조회한다. collection of rule documents

available uri query

when GET, policy=policy_name

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response field

Data Type

rule_id

Number

rule id

rule_name

String

룰 이름

level

Number

탐지설정

Explanation

Required

--

--

Explanation

param

Object

{\"사용자 정의 항목\":\"사용자 정의값\",....}

사용자 정의 설정값.

response_type

Number

대응설정

response_arg

Object

사용하지 않음

response_errorcode

String

에러코드

response_redirect

String

페이지 이름

ipblock_weight

Number

룰 위험도

warn_level

Number

탐지설정 설정개수

policy_name

rule_version

Example

String

String

정책명

탐지설정 설정개수

POST

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

26/141

2020. 8. 7.

룰 설정을 추가 한다.

Request Parameter

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

Explanation

Required

rule_id

rule_name

level

param

Number

String

rule_id

룰 이름

Number

탐지설정

Object

사용자 정의 설정값. {\"사용자 정의 항목\":\"사용자 정의값\",....}

X

X

X

X

X

X

X

X

X

X

X

X

rule_id

룰 이름

--

룰 별 Param 참고

--

--

--

--

--

--

--

--

Explanation

response_type

Number

대응설정

response_arg

Object

사용하지 않음

response_errorcode

String

에러코드

response_redirect

String

페이지 이름

ipblock_weight

Number

룰 위험도

warn_level

Number

탐지설정 설정개수

String

String

정책명

룰 버전

policy_name

rule_version

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/rule/(doc id) (type:JSON)

GET

특정한 룰의 설정을 조회한다 collection of rule documents

available uri query

when GET, policy=policy_name

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response field

Data Type

rule_id

Number

rule id

rule_name

String

룰 이름

Explanation

Required

--

--

Explanation

level

param

Number

탐지설정

String

사용자 정의 설정값, {\"사용자 정의 항목\":\"사용자 정의값\",....}

response_type

Number

대응설정

response_arg

String

사용하지 않음

response_errorcode

String

에러코드

response_redirect

String

페이지 이름

ipblock_weight

Number

룰 위험도

warn_level

Number

탐지설정 설정개수

policy_name

rule_version

Example

String

String

해당 정책 명

룰 버전

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

27/141

2020. 8. 7.

PUT

특정한 룰의 설정을 수정한다

Request Parameter

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

Explanation

Required

rule_id

rule_name

level

param

Number

String

rule_id

룰 이름

Number

탐지설정

Object

사용자 정의 설정값. {\"사용자 정의 항목\":\"사용자 정의값\",....}

response_type

Number

대응설정

response_arg

Object

사용하지 않음

response_errorcode

String

에러코드

response_redirect

String

페이지 이름

ipblock_weight

Number

룰 위험도

warn_level

Number

탐지설정 설정개수

String

String

정책명

탐지설정 설정개수

policy_name

rule_version

Example

Response fields

X

X

X

X

X

X

X

X

X

X

X

rule_id

룰 이름

--

룰 별 Param 참고

--

--

--

--

--

--

--

Response
field

Data Type

ok

Boolean

Example

DELETE

특정한 룰을 삭제한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/detection_setting (type:JSON)

GET

정책의 룰별 사용자 정의 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

28/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

Explanation

param

Object

사용자 설정값
ex) {\"key_len\": \"64\", \"uri_len\": \"1024\", \"header_len\": \"768\"}

Example

/conf/detection_setting/(doc id) (type:JSON)

GET

정책의 룰별 사용자 정의 중 특정한 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

param

Object

사용자 설정값

Example

/conf/uri_list (type:JSON)

GET

접근제어에 등록되어있는 모든 정보를 조회한다.

collection of uri documents (uri list for Uri Access Control function)

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

website

uri

String

String

웹사이트 doc id

접근제어 url

등록 날짜.

m_time

String

형식: YYYY-MMDD HH:mm:ss

secret

Number

페이지 설정

Example

POST

접근제어에 새로운 설정을 추가한다.

Request Parameter

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

29/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

website

String

웹사이트 doc id

uri

String

접근제어 url

String

등록 날짜.

Number

페이지 설정

m_time

secret

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/uri_list/(doc id) (type:JSON)

GET

접근제어에 등록되어있는 특정 정보를 조회한다.

collection of uri documents (uri list for Uri Access Control function)

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

String

String

String

웹사이트 doc id

접근제어 url

등록 날짜. 형식: YYYY-MMDD HH:mm:ss

Number

페이지 설정

website

uri

m_time

secret

Example

PUT

특정 접근제어 정보를 수정한다.

Request Parameter

Request
Parameter

Data Type

website

String

웹사이트 doc id

uri

String

접근제어 url

String

등록 날짜.

Number

페이지 설정

m_time

secret

Example

Response fields

Explanation

Required

X

X

X

X

--

AbsPath 참고

중복 입력 불가

공개/비공개 디렉

로 끝나야함

ISO 8601 형식: Y

--

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

X

X

X

X

--

AbsPath 참고

중복 입력 불가

공개/비공개 디렉

로 끝나야함

ISO 8601 형식: Y

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

30/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

Explanation

Response
field

Data Type

--

--

--

Example

DELETE

특정 접근제어 정보를 삭제한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/web_site_defacement (type:JSON)

GET

WebSiteDefacement의 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

website

uri

pattern

String

String

String

웹사이트 doc id

url

비교 문자열

replace_page

String

복구페이지 경로

code_page

Number

응답코드

match_full

String

비교 페이지 파일 내용

mime

String

웹사이트 컨텐트 타입

Example

POST

WebSiteDefacement 설정을 추가 한다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

31/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Required

X

O

X

X

X

X

O

--

공백 입력 불가

중복 입력 불가

--

--

--

--

공백 입력 불가

Explanation

Explanation

Required

--

--

Explanation

Request
Parameter

Data Type

website

String

웹사이트 doc id

uri

String

url

pattern

String

비교 문자열

replace_page

String

복구페이지 경로

code_page

Number

응답코드

String

String

비교 페이지 파일 내용

웹사이트 컨텐트 타입

match_full

mime

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/web_site_defacement/(doc id) (type:JSON)

GET

특정한 WebSiteDefacement 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

website

uri

pattern

String

String

String

웹사이트 doc id

url

비교 문자열

replace_page

String

복구페이지 경로

code_page

Number

응답코드

match_full

String

비교 페이지 파일 내용

mime

String

웹사이트 컨텐트 타입

Example

PUT

특정한 WebSiteDefacement 정보를 수정 한다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

32/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

website

String

웹사이트 doc id

uri

String

url

pattern

String

비교 문자열

replace_page

String

복구페이지 경로

code_page

Number

응답코드

String

String

비교 페이지 파일 내용

웹사이트 컨텐트 타입

match_full

mime

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

DELETE

특정한 WebSiteDefacement 정보를 삭제 한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/rule_exception (type:JSON)

GET

탐지 예외 전체 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

X

O

X

X

X

X

O

--

공백 입력 불가

중복 입력 불가

--

--

--

--

공백 입력 불가

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

33/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

website

String

웹사이트 doc id

rule_id

Number

rule id

detect_name

String

uri

ip

String

Array

룰 이름

예외 url

ip

http_method

String

http_method

netmask

String

netmask

Example

POST

탐지 예외 설정을 추가한다.

Request Parameter

Request
Parameter

Data Type

website

rule_id

String

Number

detect_name

String

웹사이트 doc id

rule id

룰이름

uri

ip

String

예외 url

Array

ip

http_method

String

http_method

netmask

String

netmask

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/rule_exception/(doc id) (type:JSON)

룰 예외처리(virtual host rule exception) 포멧

GET

특정 탐지 예외 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Explanation

Required

X

X

X

O

O

X

O

--

--

--

AbsPath 참고

호스트 IP 검증 참

길이 32767 미만

Netmask 참고

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

34/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Explanation

Required

X

X

X

O

O

X

O

--

--

--

AbsPath 참고

호스트 IP 검증 참

길이 32767 미만

Netmask 참고

Explanation

Explanation

Required

--

--

Explanation

Response
field

Data Type

website

String

웹사이트 doc id

rule_id

Number

detect_name

String

uri

ip

String

Array

rule id

룰이름

예외 url

ip

http_method

String

http_method

netmask

String

netmask

Example

PUT

특정 탐지 예외 정보를 수정한다.

Request Parameter

Request
Parameter

Data Type

website

rule_id

String

Number

detect_name

String

웹사이트 doc id

rule id

룰이름

uri

ip

String

예외 url

Array

ip

http_method

String

http_method

netmask

String

netmask

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

DELETE

특정 탐지 예외 정보를 삭제한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/ip_block (type:JSON)

GET

룰별위험도 정보를 조회한다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

35/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Required

--

--

Explanation

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

check_time

Number

지속시간. 초단위

check_count

Number

누적 위험도

block_time

Number

트래픽 차단 유지 기간. 초단위

enable

Boolean

룰별 위험도 사용 여부 (true, false)

Example

PUT

룰별위험도 정보를 수정한다.

Request Parameter

Request
Parameter

Data Type

check_time

Number

지속시간. 초단위

check_count

Number

누적 위험도

block_time

Number

트래픽 차단 유지 기간. 초단위

enable

Boolean

룰별 위험도 사용 여부

Explanation

Required

X

X

X

X

--

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

Explanation

/conf/ip_block_exception (type:JSON)

IP Block 에 대한 예외 처리 기능이 있습니다.

이 기능은 룰에 대해서는 문제 없이 다 탐지 하나, IP Block에 자동 차단에 대해서만 filtering 되지 않는 기능입니다.

GET

넷필터 - 자동 등록 방지 설정 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

String

String

방지 대상 정보 ip

방지 대상 정보 netmask

ip

netmask

Example

POST

넷필터 - 자동 등록 방지 설정 정보를 추가 한다.

Explanation

Required

--

--

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

36/141

2020. 8. 7.

Request Parameter

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

ip

String

방지 대상 정보 ip

netmask

String

방지 대상 정보 netmask

Explanation

Required

O

O

호스트 IP 검증 참

Netmask 참고

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/ip_block_exception/(doc_id) (type:JSON)

GET

특정한 넷필터 - 자동 등록 방지 설정 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

String

String

방지 대상 정보 ip

방지 대상 정보 netmask

ip

netmask

Example

PUT

특정한 넷필터 - 자동 등록 방지 설정 정보를 수정한다.

Request Parameter

Request
Parameter

Data Type

ip

String

방지 대상 정보 ip

netmask

String

방지 대상 정보 netmask

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

DELETE

특정한 넷필터 - 자동 등록 방지 설정 정보를 삭제한다.

Request Parameter

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

O

O

호스트 IP 검증 참

Netmask 참고

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

37/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/user_defined (type:JSON)

GET

패턴그룹 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

Response
field

Data Type

group_name

String

패턴 그룹명

pattern[]

Array

그룹에 속하는 user_defined_pattern의 doc_id

Explanation

Example

POST

패턴그룹 정보를 추가한다.

Request Parameter

Request
Parameter

Data Type

group_name

String

패턴 그룹명

pattern[]

Array

pttern doc id

Explanation

Required

O

X

공백 및 중복 입력

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/user_defined/(doc id) (type:JSON)

GET

특정 패턴그룹 정보를 조회 한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

38/141

2020. 8. 7.

Response fields

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

group_name

String

패턴 그룹명

pattern[]

Array

pttern doc id

Example

PUT

특정 패턴그룹 정보를 수정 한다.

Request Parameter

Explanation

Request
Parameter

Data Type

group_name

String

패턴 그룹명

pattern[]

Array

pttern doc id

Explanation

Required

O

X

공백 및 중복 입력

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

DELETE

특정 패턴그룹 정보를 삭제 한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/user_defined/(doc_id)/patterns (type:JSON)

GET

특정에 그룹에 해당하는 모든 패턴을 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

39/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Explanation

Required

--

--

Explanation

Response
field

Data Type

type

Number

Regular Expression 설정.

1 설정

0 설정하지 않음

name

loc

s_key

pattern

String

패턴 명

Number

탐지 위치

String

String

Key

탐지 패턴

codepage

Number

codepage

user

String

작업자

update_time

String

수정시간.

형식: YYYY-MMDD HH:mm:ss

Example

/conf/user_defined_pattern (type:JSON)

GET

등록되어있는 패턴정보를 모두 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

name

loc

s_key

pattern

String

패턴 명

Number

탐지 위치

String

String

Key

탐지 패턴

codepage

Number

codepage

user

String

작업자

update_time

String

수정시간. ISO 8601 형식: YYYY-MMDD HH:mm:ss

Example

POST

패턴 정보를 추가 한다.

Request Parameter

Request
Parameter

Data Type

name

String

패턴 명

탐지 위치

Explanation

Required

loc

Number

[] 안의 값 중 하나가 입력된다.

[URL, REQLINE, PARAM, REQHEADER, REQCONTENT, RESHEADER]

s_key

pattern

String

String

Key

탐지 패턴

codepage

Number

codepage

user

String

작업자

update_time

String

수정시간.

Example

O

X

O

O

X

X

X

공백 및 중복 입력

--

공백 입력 불가

공백 입력 불가

--

--

ISO 8601 형식: Y

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

40/141

2020. 8. 7.

Response fields

Response
field

Data Type

ok

Boolean

Example

WAPPLES Web API - Penta Security Wiki

Explanation

/conf/user_defined_pattern/(doc id) (type:JSON)

GET

특정 패턴정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

name

loc

s_key

pattern

String

패턴 명

Number

탐지 위치

String

String

Key

user_defined_pattern doc_id

codepage

Number

codepage

user

String

작업자

update_time

String

수정시간. 형식: YYYY-MMDD HH:mm:ss

Example

PUT

특정 패턴정보를 수정한다.

Request Parameter

Request
Parameter

Data Type

name

String

패턴 명

탐지 위치

Explanation

Required

--

--

Explanation

Explanation

Required

O

X

O

O

X

X

X

공백 및 중복 입력

--

공백 입력 불가

공백 입력 불가

--

--

ISO 8601 형식: Y

Explanation

loc

Number

[] 안의 값 중 하나가 입력된다.

[URL, REQLINE, PARAM, REQHEADER, REQCONTENT, RESHEADER]

s_key

pattern

String

String

Key

탐지 패턴

codepage

Number

codepage

user

String

작업자

update_time

String

수정시간.

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

DELETE

특정 패턴정보를 삭제한다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

41/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/exception_pattern(type:JSON)

GET

탐지후 예외처리 리스트를 조회한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

Example

Response fields

Response
field

Data Type

String

String

String

pattern

opt

website

Example

POST

탐지후 예외처리 리스트를 추가한다.

Request Parameter

예외 패턴

옵션

탐지 후 예외 처리 설정을 등록한 website. webserver의 doc_id

Explanation

Explanation

Required

Request
Parameter

Data Type

pattern

opt

String

String

예외 패턴

옵션

website

String

탐지 후 예외 처리 설정을 등록한 website.
webserver의 doc_id

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/exception_pattern/(doc id) (type:JSON)

GET

특정 탐지후 예외처리 리스트를 조회한다

Request Parameter

O

X

O

공백 및 중복 입력

--

공백 입력 불가

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

42/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

--

--

--

Explanation

Required

--

--

Example

Response fields

Response
field

Data Type

String

String

String

pattern

opt

website

Example

PUT

특정 탐지후 예외처리 리스트를 수정한다

Request Parameter

예외 패턴

옵션

탐지 후 예외 처리 설정을 등록한 website. webserver의 doc_id

Explanation

Explanation

Required

Request
Parameter

Data Type

pattern

opt

String

String

예외 패턴

옵션

website

String

탐지 후 예외 처리 설정을 등록한 website.
webserver의 doc_id

O

X

O

공백 및 중복 입력

--

공백 입력 불가

Explanation

Explanation

Required

--

--

Explanation

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

DELETE

특정 탐지후 예외처리 리스트를 삭제한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/website (type:JSON)

GET

등록되어있는 모든 웹사이트 목록을 조회한다

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

43/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Response field

Data Type

Explanation

host_name

description

policy

owner

case_sensitive

encoding_type

encryption_key

String

String

String

String

host 명

Explanation

웹사이트가 포함되어있는 policy doc_id

웹사이트가 할당된 doc_id

Boolean

대소문자 구별. 구별 O true, 구별 X false

Number

인코딩 타입

String

웹 서버 보안 키

issacweb_integrity[issacweb_mode]

Number

암호화 설정 선택. 사용안함 0, issac-web 사용 1, parameter Encryption 2

issacweb_integrity[issacweb_key]

String

보안 키 값

issacweb_integrity[issacweb_pubkey]

String

공개 키 값

alias[]

trusted_ip[]

Array

Array

웹사이트 다른 이름

신뢰할 수 있는 IP 목록

health_check[enable]

Boolean

웹 사이트 상태 체크 사용 유무 (true, false)

health_check[url]

health_check[request_method]

String

String

웹사이트 상태 체크 할 url

웹사이트 상태 Request Method

health_check[timeout]

Number

웹사이트 상태 응답 대기 시간

health_check[interval]

String

웹사이트 상태 체크 주기

Example

POST

웹사이트 목록을 추가한다

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

44/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request Parameter

Data Type

Explanation

Required

host_name

String

host 명

description

policy

owner

String

String

String

Explanation

웹사이트가 포함되어있는 policy doc_id

웹사이트가 할당된 doc_id

대소문자 구별.

case_sensitive

Boolean

true 구별 O, false 구별 X

encoding_type

encryption_key

Number

인코딩 타입

String

웹 서버 보안 키

issacweb_integrity[issacweb_mode]

Number

암호화 설정 선택. 사용안함 0, issac-web 사용 1, parameter Encryption 2

issacweb_integrity[issacweb_key]

String

보안 키 값

issacweb_integrity[issacweb_pubkey]

String

공개 키 값

alias[]

Array

웹사이트 다른 이름

trusted_ip[]

Array

신뢰할 수 있는 IP 목록

health_check[enable]

Boolean

웹 사이트 상태 체크 사용 유무 (true, false)

health_check[url]

String

웹사이트 상태 체크 할 url

health_check[request_method]

String

웹사이트 상태 Request Method

health_check[timeout]

Number

웹사이트 상태 응답 대기 시간

health_check[interval]

String

웹사이트 상태 체크 주기

공백 및 중복

길이 64자 이

프로토콜은

호스트 IP 검

도메인 검증

AbsPath 참

공백 입력 불

--

--

--

--

--

--

암호화 설정
체크했을때
오류메세지

--

--

공백 입력 불

호스트 IP 검

--

공백 입력 불

프로토콜 입

호스트 IP 검

AbsPath 참

Port 검증 참

--

1 이상

1 이상

O

O

X

X

X

X

X

X

X

X

X

O

X

O

X

X

X

Example

Response fields

Response
field

Data Type

ok

Boolean

--

Example

/conf/website/(doc id) (type:JSON)

GET

특정 웹사이트 목록을 조회한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

45/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response field

Data Type

Explanation

host_name

description

policy

owner

case_sensitive

encoding_type

encryption_key

String

String

String

String

host 명

Explanation

웹사이트가 포함되어있는 policy doc_id

웹사이트가 할당된 doc_id

Boolean

대소문자 구별. 구별 O true, 구별 X false

Number

인코딩 타입

String

웹 서버 보안 키

issacweb_integrity[issacweb_mode]

Number

암호화 설정 선택. 사용안함 0, issac-web 사용 1, parameter Encryption 2

issacweb_integrity[issacweb_key]

String

보안 키 값

issacweb_integrity[issacweb_pubkey]

String

공개 키 값

alias[]

trusted_ip[]

Array

Array

웹사이트 다른 이름

신뢰할 수 있는 IP 목록

health_check[enable]

Boolean

웹 사이트 상태 체크 사용 유무 (true, false)

health_check[url]

health_check[request_method]

String

String

웹사이트 상태 체크 할 url

웹사이트 상태 Request Method

health_check[timeout]

Number

웹사이트 상태 응답 대기 시간

health_check[interval]

String

웹사이트 상태 체크 주기

Example

PUT

특정 웹사이트 목록을 수정한다

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

46/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request Parameter

Data Type

Explanation

Required

host_name

String

host 명

description

policy

owner

String

String

String

case_sensitive

Boolean

Explanation

웹사이트가 포함되어있는 policy doc_id

웹사이트가 할당된 doc_id

대소문자 구별.

true 구별 O, false 구별 X

X

encoding_type

Number

인코딩 타입

웹 서버 보안 키

encryption_key

String

X

issacweb_integrity[issacweb_mode]

Number

암호화 설정 선택. 사용안함 0, issac-web 사용 1, parameter Encryption 2

issacweb_integrity[issacweb_key]

String

보안 키 값

X

issacweb_integrity[issacweb_pubkey]

String

공개 키 값

alias[]

Array

웹사이트 다른 이름

trusted_ip[]

Array

신뢰할 수 있는 IP 목록

health_check[enable]

Boolean

웹 사이트 상태 체크 사용 유무 (true, false)

health_check[url]

String

웹사이트 상태 체크 할 url

health_check[request_method]

String

웹사이트 상태 Request Method

health_check[timeout]

Number

웹사이트 상태 응답 대기 시간

health_check[interval]

String

웹사이트 상태 체크 주기

공백 및 중복

길이 64자 이

프로토콜은

호스트 IP 검

도메인 검증

AbsPath 참

Port 검증 참

공백 입력 불

--

--

--

--

--

--

공백 입력 불

호스트 IP 검

--

공백 입력 불

프로토콜 입

호스트 IP 검

AbsPath 참

--

1 이상

1 이상

O

O

X

X

--

X

--

X

암호화 설정
에서
Parameter
Encryption
체크했을때
보안키와 공
개키가 빈칸
이면 오류메
세지

X

X

O

X

O

X

X

X

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

DELETE

특정 웹사이트 목록을 삭제한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

47/141

WAPPLES Web API - Penta Security Wiki

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

X

X

X

X

X

1 이상

1 이상

1 이상

1 이상

--

Explanation

2020. 8. 7.

Response fields

Response
field

Data Type

ok

Boolean

--

Example

/conf/http_dos(type:JSON)

GET

네트워크 필터 - HTTP DoS의 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response field

Data Type

check_time

Number

지속 시간

check_count

Number

횟수

may_block_time Number

트래픽 지연 시간. 초단위

block_time

Number

트래픽 차단 유지 기간

enable

Boolean

HTTP Dos 사용여부 (true, false)

Example

PUT

네트워크 필터 - HTTP DoS의 정보를 수정한다.

Request Parameter

Request
Parameter

Data Type

check_time

Number

지속 시간

check_count

Number

횟수

may_block_time Number

트래픽 지연 시간. 초단위

block_time

Number

트래픽 차단 유지 기간

enable

Boolean

HTTP Dos 사용여부 (true, false)

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

탐지관련

/conf/parameter_encryption (type:JSON)

GET

모든 parameter encryption 정보를 조회한다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

48/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Response field

Data Type

Explanation

core_website

String

암호화 대상 포함 website doc_id

core_url

refer_url

String

String

암호화 대상 website url

접근경로

core_description

String

암호화할 웹사이트 이름(사용x)

trigger_website

String

parameter encryption 설정한 website

trigger_url

String

parameter encryption 설정한 website의 url

Example

POST

parameter encryption 정보를 추가한다.

Request Parameter

Request
Parameter

Data Type

Explanation

Required

core_website

String

암호화 대상 포함 website doc_id

core_url

refer_url

String

String

암호화 대상 website url

접근경로

core_description

String

암호화할 웹사이트 이름(사용x)

trigger_website

String

parameter encryption 설정한 website

trigger_url

String

parameter encryption 설정한 website의 url

X

O

O

X

O

X

--

공백 입력 불가

공백 입력 불가

--

공백 입력 불가

--

Example

Response fields

Response
field

Data Type

ok

Boolean

--

Example

/conf/parameter_encryption/(doc id ) (type:JSON)

GET

특정 parameter encryption 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

49/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response field

Data Type

Explanation

core_website

String

암호화 대상 포함 website doc_id

core_url

refer_url

String

String

암호화 대상 website url

접근경로

core_description

String

암호화할 웹사이트 이름(사용x)

trigger_website

String

parameter encryption 설정한 website

trigger_url

String

parameter encryption 설정한 website의 url

Example

PUT

특정 parameter encryption 정보를 수정한다.

Request Parameter

Request
Parameter

Data Type

Explanation

Required

core_website

String

암호화 대상 포함 website doc_id

core_url

refer_url

String

String

암호화 대상 website url

접근경로

core_description

String

암호화할 웹사이트 이름(사용x)

trigger_website

String

parameter encryption 설정한 website

trigger_url

String

parameter encryption 설정한 website의 url

X

O

O

X

O

X

--

공백 입력 불가

공백 입력 불가

--

공백 입력 불가

--

Example

Response fields

Response
field

Data Type

ok

Boolean

--

Example

DELETE

특정 parameter encryption 정보를 삭제한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/access_control (type:JSON)

GET

access_control 전체 설정 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

50/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

enable

Boolean

access control 사용여부

Explanation

Example

PUT

access_control 전체 설정 정보를 수정한다.

Request Parameter

Request
Parameter

Data Type

Explanation

Required

enable

Boolean

access control 사용여부

X

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/access_control_filter (type:JSON)

GET

등록된 모든 access_control목록의 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Explanation

Required

--

--

Response field

Data Type

Explanation

name

enable

filter[src_ip]

filter[src_port]

filter[src_netmask]

filter[dest_ip]

String

이름

Boolean

필터 사용여부

String

출발지 ip

Number

출발지 port

String

String

출발지 netmask

도착지 ip

filter[dest_port]

Number

도착지 port

filter[dest_netmask]

String

도착지 netmask

filter[method][]

filter[host][]

filter[uri][]

Array

Array

Array

method

host

uri

counting_combination[src_ip]

Boolean

출발지 ip필터 조합 여부

counting_combination[dest_ip]

Boolean

목적지 ip 필터 조합 여부

counting_combination[method]

Boolean

Method 필터 조합 여부

counting_combination[host]

Boolean

Host 필터 조합 여부

counting_combination[uri]

Boolean

URL 필터 조합 여부

detection[check_time]

Number

감시 기간

detection[check_count]

Number

최대 횟수

detection[block_time]

Number

차단 시간

Example

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

51/141

2020. 8. 7.

POST

access_control목록의 정보를 추가한다.

Request Parameter

WAPPLES Web API - Penta Security Wiki

Request Parameter

Data Type

Explanation

Required

name

enable

String

이름

Boolean

필터 사용여부. true, false

filter[src_ip]

String

출발지 ip

filter["src_port]

Number

출발

filter[src_netmask]

String

출발지 netmask

filter[dest_ip]

String

도착지 ip

filter[dest_port]

Number

도착지 port

filter[dest_netmask]

String

도착지 netmask

filter[method][]

filter[host][]

filter[uri][]

Array

Array

Array

method

host

uri

counting_combination[src_ip]

Boolean

출발지 ip필터 조합 여부. true, false

counting_combination[dest_ip]

Boolean

목적지 ip 필터 조합 여부

counting_combination[method]

Boolean

Method필터 조합 여부

counting_combination[host]

Boolean

Host필터 조합 여부

counting_combination[uri]

Boolean

URL필터 조합 여부

detection[check_time]

Number

감시 기간

detection[check_count]

Number

최대 횟수

detection[block_time]

Number

차단 시간

O

X

O

O

O

O

O

O

X

X

X

X

X

X

X

X

X

X

X

공백 및 중복

--

호스트 IP 검

Port 검증 참

Netmask 참고

호스트 IP 검

Port 검증 참

Netmask 참고

--

--

--

--

--

--

--

--

숫자외 입력

숫자외 입력

숫자외 입력

Example

Response fields

Response
field

Data Type

ok

Boolean

--

Example

/conf/access_control_filter/(doc_id) (type:JSON)

GET

특정 access_control목록의 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

52/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response field

Data Type

Explanation

name

enable

String

이름

Boolean

필터 사용여부. true, false

filter[src_ip]

String

출발지 ip

filter["src_port]

Number

출발

filter[src_netmask]

filter[dest_ip]

String

String

출발지 netmask

도착지 ip

filter[dest_port]

Number

도착지 port

filter[dest_netmask]

String

도착지 netmask

filter[method][]

filter[host][]

filter[uri][]

Array

Array

Array

method

host

uri

counting_combination[src_ip]

Boolean

출발지 ip필터 조합 여부. true, false

counting_combination[dest_ip]

Boolean

목적지 ip 필터 조합 여부

counting_combination[method]

Boolean

Method필터 조합 여부

counting_combination[host]

Boolean

Host필터 조합 여부

counting_combination[uri]

Boolean

URL필터 조합 여부

detection[check_time]

Number

감시 기간

detection[check_count]

Number

최대 횟수

detection[block_time]

Number

차단 시간

Example

PUT

특정 access_control목록의 정보를 수정한다.

Request Parameter

Request Parameter

Data Type

Explanation

Required

name

enable

String

이름

Boolean

필터 사용여부. true, false

filter[src_ip]

String

출발지 ip

filter["src_port]

Number

출발

filter[src_netmask]

String

출발지 netmask

filter[dest_ip]

String

도착지 ip

filter[dest_port]

Number

도착지 port

filter[dest_netmask]

String

도착지 netmask

filter[method][]

filter[host][]

filter[uri][]

Array

Array

Array

method

host

uri

counting_combination[src_ip]

Boolean

출발지 ip필터 조합 여부. true, false

counting_combination[dest_ip]

Boolean

목적지 ip 필터 조합 여부

counting_combination[method]

Boolean

Method필터 조합 여부

counting_combination[host]

Boolean

Host필터 조합 여부

counting_combination[uri]

Boolean

URL필터 조합 여부

detection[check_time]

Number

감시 기간

detection[check_count]

Number

최대 횟수

detection[block_time]

Number

차단 시간

Example

Response fields

O

X

O

O

O

O

O

O

X

X

X

X

X

X

X

X

X

X

X

공백 및 중복

--

호스트 IP 검

Port 검증 참

Netmask 참고

호스트 IP 검

Port 검증 참

Netmask 참고

--

--

--

--

--

--

--

--

숫자외 입력

숫자외 입력

숫자외 입력

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

53/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

ok

Boolean

Example

DELETE

특정 access_control목록의 정보를 삭제한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/detect_exception_pattern (type:JSON)

GET

등록된 모든 탐지 예외 패턴 목록의 정보를 조회 합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

Explanation

Response field

Data Type

exception_name

String

예외 패턴 명

description

user

String

String

설명

작성자 계정의 Hash ID

update_time

String

마지막 수정 시간(형식:YYYY-MM-DD HH:mm:SS)

enable

Boolean

예외 패턴 적용 여부

source_ip[]

method[]

uri[]

Array

Array

Array

출발지 IP 목록

Http Method 목록

uri 목록

position : 탐지 위치 - String

key : 탐지 키

patterns[]

Array

pattern_type : 패턴 종류 - String

pattern : 탐지 패턴 - String

case_sensitive : 대소문자 구분여부 - Boolean

destination[]

rule[]

websites[]

Example

Array

Array

Array

도착지 목록(웹서버 Hash ID)

룰 목록(룰 이름)

웹사이트 목록(웹사이트 Hash ID)

POST

특정 탐지 예외 패턴 정보를 추가한다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

54/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Required

Request
Parameter

Data Type

exception_name

String

예외 패턴 명

description

user

String

String

설명

작성자 계정의 Hash ID

update_time

String

마지막 수정 시간(형식:YYYY-MM-DD HH:mm:SS)

enable

Boolean

예외 패턴 적용 여부

source_ip[]

method[]

uri[]

Array

Array

Array

출발지 IP 목록

Http Method 목록

uri 목록

position : 탐지 위치(String) - 4개 항목 중 택 1.

patterns[]

Array

key : 탐지 키(String)

pattern_type : 패턴 종류(String) - 3개 항목 중 택 1.

pattern : 탐지 패턴

case_sensitive : 대소문자 구분여부(Boolean)

도착지 목록(웹서버 Hash ID)

룰 목록(룰 이름)

웹사이트 목록(웹사이트 Hash ID)

destination[]

rule[]

websites[]

Example

Array

Array

Array

Response fields

Response
field

Data Type

ok

Boolean

Example

O

O

O

O

O

O

O

O

O

O

O

O

O

O

O

O

중복 불가.

--

--

--

--

--

대문자 입력

--

Request Header
Response Heade
Request Line Par
Detection Raw D

--

텍스트 : "text"
정규식 : "regexp
*포함 텍스트 : "a

--

true, false

--

--

--

Explanation

/conf/detect_exception_pattern/(doc_id) (type:JSON)

GET

특정 탐지 예외 패턴 정보를 조회 합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

55/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Response field

Data Type

exception_name

String

예외 패턴 명

description

user

String

String

설명

작성자 계정의 Hash ID

update_time

String

마지막 수정 시간(형식:YYYY-MM-DD HH:mm:SS)

enable

Boolean

예외 패턴 적용 여부

source_ip[]

method[]

uri[]

Array

Array

Array

출발지 IP 목록

Http Method 목록

uri 목록

position : 탐지 위치 - String

key : 탐지 키

patterns[]

Array

pattern_type : 패턴 종류 - String

pattern : 탐지 패턴 - String

case_sensitive : 대소문자 구분여부 - Boolean

destination[]

rule[]

websites[]

Example

Array

Array

Array

도착지 목록(웹서버 Hash ID)

룰 목록(룰 이름)

웹사이트 목록(웹사이트 Hash ID)

PUT

특정 탐지 예외 패턴 정보를 수정한다.

Request Parameter

Request
Parameter

Data Type

Explanation

Required

O

O

O

O

O

O

O

O

O

O

O

O

O

O

O

O

중복 불가.

--

--

--

--

--

대문자 입력

--

Request Header
Response Heade
Request Line Par
Detection Raw D

--

텍스트 : "text"
정규식 : "regexp
*포함 텍스트 : "a

--

true, false

--

--

--

exception_name

String

예외 패턴 명

description

user

String

String

설명

작성자 계정의 Hash ID

update_time

String

마지막 수정 시간(형식:YYYY-MM-DD HH:mm:SS)

enable

Boolean

예외 패턴 적용 여부

source_ip[]

method[]

uri[]

Array

Array

Array

출발지 IP 목록

Http Method 목록

uri 목록

position : 탐지 위치(String) - 4개 항목 중 택 1.

patterns[]

Array

key : 탐지 키(String)

pattern_type : 패턴 종류(String) - 3개 항목 중 택 1.

pattern : 탐지 패턴

case_sensitive : 대소문자 구분여부(Boolean)

도착지 목록(웹서버 Hash ID)

룰 목록(룰 이름)

웹사이트 목록(웹사이트 Hash ID)

Explanation

destination[]

rule[]

websites[]

Example

Array

Array

Array

Response fields

Response
field

Data Type

ok

Boolean

Example

DELETE

특정 탐지 예외 패턴 정보를 삭제한다.

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

56/141

2020. 8. 7.

Request Parameter

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/error_handling_pattern (type:JSON)

GET

등록된 모든 Error Handling 패턴 목록의 정보를 조회 합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

pattern_name

String

패턴 명

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

Explanation

user

String

작성자 계정의 Hash ID

update_time

String

마지막 수정 시간(형식:YYYY-MM-DD HH:mm:SS)

pattern

Array

패턴 목록

Example

POST

특정 Error Handling 패턴 정보를 추가한다.

Request Parameter

Request
Parameter

Data Type

Explanation

Required

pattern_name

String

패턴 명

user

String

작성자 계정의 Hash ID

update_time

String

마지막 수정 시간(형식:YYYY-MM-DD HH:mm:SS)

pattern

Array

패턴 목록

O

O

O

O

--

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/error_handling_pattern/(doc_id) (type:JSON)

GET

특정 Error Handling 패턴 정보를 조회 합니다.

Request Parameter

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

57/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

pattern_name

String

패턴 명

Explanation

Required

--

--

Explanation

user

String

작성자 계정의 Hash ID

update_time

String

마지막 수정 시간(형식:YYYY-MM-DD HH:mm:SS)

pattern

Array

패턴 목록

Example

PUT

특정 Error Handling 패턴 정보를 수정한다.

Request Parameter

Request
Parameter

Data Type

Explanation

Required

pattern_name

String

패턴 명

user

String

작성자 계정의 Hash ID

update_time

String

마지막 수정 시간(형식:YYYY-MM-DD HH:mm:SS)

pattern

Array

패턴 목록

O

O

O

O

--

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

DELETE

특정 Error Handling 패턴 정보를 삭제한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/filter_by_xff (type:JSON)

GET

X-Forwarded-For에 있는 IP로 차단여부 설정 정보를 요청합니다.

Request Parameter

Explanation

Explanation

Required

--

--

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

58/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

enable

Boolean

차단 사용여부

Example

PUT

X-Forwarded-For에 있는 IP로 차단여부를 설정 합니다.

Request Parameter

Request
Parameter

Data Type

Explanation

Required

--

--

Explanation

Explanation

Required

enable

Boolean

차단 사용여부

O

--

Example

Response fields

Response
field

Data Type

ok

Boolean

--

Example

/conf/src_ip_by_xff (type:JSON)

GET

X-Forwarded-For에 있는 IP로 탐지 설정여부 정보를 요청합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

enable

Boolean

탐지 사용여부

Example

PUT

X-Forwarded-For에 있는 IP로 탐지 여부를 설정 합니다.

Request Parameter

Request
Parameter

Data Type

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

enable

Boolean

탐지 사용여부

O

--

Example

Response fields

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

59/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

ok

Boolean

--

Example

로그(Log)

/conf/audit (type:JSON)

GET

시스템 - 감사레벨의 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

level

Number

감사레벨.
1 전체감사
0 부분감사

alarm

Boolean

감사 경고 팝업 사용 여부

Example

PUT

시스템 - 감사레벨의 정보를 수정한다.

Request Parameter

Request
Parameter

Data Type

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

Number

Boolean

감사레벨. 전체감사 - 1, 부분감사 - 0

감사 경고 팝업 사용 여부

X

X

--

--

level

alarm

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/log/auditlog

GET

등록된(조건에 맞는) 모든 감사로그의 정보를 조회한다.

Request Parameter ( where절의 조건이 됨. 확장가능함. )

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

60/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

stime

etime

sort_key

sort_order

get_count

offset

user_name

String

String

String

String

String

String

String

Explanation

Required

시작 시간.

끝날 시간.

정렬할 column

column의 정렬방법. ASC: 오름차순, DESC : 내림차순

Query결과 중 가져올 개수

건너뛸 행 수를 지정.

웹사이트 관리자

type

String

[감사로그 type 참고 (https://wiki.pentasecurity.com/index.php/WAPPLES_%EA%B0%90%EC%8

2%AC_%EB%A1%9C%EA%B7%B8#.EA.B0.90.EC.82.AC.EB.A1.9C.EA.B7.B8_.EC.A2.85.EB.A5.98%7

가져올 type 구간. 형식: 시작 type value, 끝 type value

C)]

Example

Response fields

Response field

Data Type

Explanation

param[stime]

param[etime]

String

String

시작 시간. 형식: YYYY-MMDD HH:mm:ss

끝날 시간. 형식: YYYY-MMDD HH:mm:ss

param[sort_key]

String

정렬할 column

param[sort_order]

String

column의 정렬방법. ASC: 오름차순, DESC : 내림차순

param[get_count]

String

Query결과 중 가져올 개수

param[offset]

result[time]

result[source]

result[info]

result[type]

String

String

String

String

String

건너뛸 행 수를 지정.

시간

원본

정보

감사로그 번호

result[msg_type]

String

메세지 타입

result[comment]

String

사용자 메모

Example

/log/auditlog/count

GET

등록된(조건에 맞는) 감사로그의 개수를 조회한다.

Request Parameter ( where절의 조건이 됨. 확장가능함. )

Request
Parameter

Data Type

stime

etime

user_name

String

String

String

시작 시간.

끝날 시간.

웹사이트 관리자

Explanation

Required

type

String

[감사로그 type 참고 (https://wiki.pentasecurity.com/index.php/WAPPLES_%EA%B0%90%EC%8

2%AC_%EB%A1%9C%EA%B7%B8#.EA.B0.90.EC.82.AC.EB.A1.9C.EA.B7.B8_.EC.A2.85.EB.A5.98%7

가져올 type 구간. 형식: 시작 type value, 끝 type value

C)]

Example

Response fields

ISO 8601 형식: Y

ISO 8601 형식: Y

--

--

--

--

--

--

ISO 8601 형식: Y

ISO 8601 형식: Y

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

61/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

Explanation

param[type]

String

가져올 type 구간. 시작 type value, 끝 type value

param[stime]

String

시작 시간. 형식: YYYY-MMDD HH:mm:ss

param[etime]

String

끝날 시간. 형식: YYYY-MMDD HH:mm:ss

count

Number

감사로그 개수

Example

/export/auditlog

GET

등록된(조건에 맞는) 모든 감사로그의 정보를 조회한다.

Request Parameter ( where절의 조건이 됨. 확장가능함. )

Request
Parameter

Data Type

hash_id

String

해당 작업의 hash id값

감사로그 내보내기 파일 언어 설정.

language

String

stime

etime

sort_key

String

String

String

ko 한국어

en 영어

ja 일본어

시작 시간.

끝날 시간.

정렬할 column

column의 정렬방법.

sort_order

String

ASC: 오름차순, DESC : 내림차순

get_count

offset

user_name

String

String

String

Query결과 중 가져올 개수

건너뛸 행 수를 지정.

웹사이트 관리자

Explanation

Required

X

X

X

X

X

X

X

X

X

X

--

--

ISO 8601 형식: Y

ISO 8601 형식: Y

--

--

--

--

--

--

type

String

감사로그 종류[type 링크 (https://wiki.pentasecurity.com/index.php/WAPPLES_%EA%B0%90%E

C%82%AC_%EB%A1%9C%EA%B7%B8#.EA.B0.90.EC.82.AC.EB.A1.9C.EA.B7.B8_.EC.A2.85.EB.A5.9

가져올 type 구간. 시작 type value, 끝 type value

8%7C감사로그)]

Example

Response fields

Response
field

Data Type

--

--

--

Example

/export/auditlog/(hash_id) (type:JSON)

GET

감사로그를 내보낸 결과를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

62/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

내보내기 결과. 진행중 "start", 종료 "done"

내보낸 파일명 (기존에 만들어진 file과 동일한 이름을 가지고 있다면 rename해서 저장하므로 'status'가 'done'일 때, 이 field를 확인 해야

Explanation

Response
field

Data Type

String

String

status

file_name

Example

/log/intrusionlog

GET

조건에 맞는 탐지로그를 조회한다.

Request Parameter( where절의 조건이 됨. 확장가능함. )

 Note: query string으로 주고 받기 때문에 webapi 사용시 'urlencode'해서 요청해야함.

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

63/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request Parameter

Data Type

Explanation

Required

stime

etime

sort_key

String

시작 시간.

String

String

끝날 시간.

정렬할 column

sort_order

String

X

정렬할 방식. ASC: 오름차순, DESC : 내림차순

get_count

offset

hidden

String

String

Boolean

Query결과 중 가져올 개수

건너뛸 행 수를 지정.

숨김 로그(이 조건을 주지 않으면 숨김로그 설정과 관계없이 모두 가져옴.) true : 숨김로그
만, false : 숨김로그제외

action

String

no_response, redirect, error_code, disconnect

대응 방식

sequence_from

Number

sequence 범위

sequence_to

Number

sequence 범위

website_include

String

탐지 할 웹사이트. 형식: 웹사이트+ %3a + Port

website_exclude

String

탐지 제외 할 웹사이트. 형식: 웹사이트+ %3a + Port

source_ip_include

String

탐지 할 출발지 ip

source_ip_exclude

String

destination_ip_include

String

destination_ip_exclude

String

uri_include

String

uri_exclude

String

country_code_include

String

country_code_exclude

String

탐지 제외 할 출발지 ip.

형식에 맞는 ip %2c ...

탐지 할 도착지 ip.

형식에 맞는 ip %2c ...

탐지 제외할 도착지 ip

형식에 맞는 ip %2c ...

탐지 할 url

url %2c ...

탐지 제외 할 url

url %2c ...

탐지 할 국가

국가 코드 %2c ...

탐지 제외 할 국가.

국가 코드 %2c ...

rule_name_include

String

탐지 할 룰

rule_name_exclude

String

탐지 제외 할 룰

policy_name_include

String

탐지 할 정책

policy_name_exclude

String

탐지 제외 할 정책

creator_include

creator_exclude

String

String

탐지 할 장비 id

탐지 제외 할 장비 id

Example

Response fields

X

X

X

--

X

X

X

X

X

X

O

O

O

O

O

O

O

O

X

X

X

X

X

X

X

ISO 8601 형식:
DD+HH%3amm

ISO 8601 형식:
DD+HH%3amm

--

--

--

--

--

--

--

중복 입력 불가

URL 참고

중복 입력 불가

URL 참고

중복 입력 불가

호스트 IP 검증

중복 입력 불가

호스트 IP 검증

중복 입력 불가

호스트 IP 검증

중복 입력 불가

호스트 IP 검증

URL 참고

URL 참고

--

--

--

--

--

--

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

64/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response field

Data Type

Explanation

param[stime]

param[etime]

param[hidden]

param[sort_key]

param[sort_order]

param[get_count]

param[offset]

result[sequence]

result[rule_name]

String

String

String

String

String

String

String

String

String

시작시간 형식: YYYY-MM-DD+HH%3amm%3ass

끝날 시간 형식: YYYY-MM-DD+HH%3amm%3ass

숨김 로그 true : 숨김로그만, false : 숨김로그제외 (이 조건을 주지 않으면 숨김로그 설정과 관계없이 모두 가져옴.)

정렬할 column

정렬할 방식 ASC: 오름차순, DESC : 내림차순

Query결과 중 가져올 개수

건너뛸 행 수를 지정.

sequence

탐지된 로그의 해당하는 룰

result[policy_name]

String

탐지된 정책

result[source_ip]

result[source_port]

result[uri]

result[time]

String

String

String

String

탐지된 로그의 출발지 ip

탐지된 로그의 출발지 port

탐지된 로그의 uri

탐지된 로그의 시각

result[country_code]

String

탐지된 로그의 국가

result[action]

String

탐지된 로그의 대응

result[hidden]

Boolean

탐지된 로그의 숨김여부. true : 숨김, false : 숨김x

result[destination_ip]

String

탐지된 로그의 도착지 ip

result[destination_port]

String

탐지된 로그의 도착지 port

result[ipblock_weight]

String

탐지된 로그의 위험도

result[creator]

result[website]

Example

String

String

로그가 탐지된 장비 id

탐지된 로그의 웹사이트

PUT

탐지로그 숨김, 숨김해제 정보를 수정 합니다

Request Parameter

 Note: hidden 조건을 주지 않으면 안됨.
 Note: query string으로 주고 받기 때문에 webapi 사용시 'urlencode'해서 요청해야함.

Request
Parameter

Data Type

Explanation

Required

hidden

sequence

stime

etime

Boolean

로그 숨김여부. true : 로그 숨기기, false : 로그 숨김 해제

String

String

String

숨기고자 하는 log의 sequence

시작 시간

끝날 시간

website_include

String

탐지 할 웹사이트

website_exclude

String

탐지 제외 할 웹사이트

uri_include

uri_exclude

String

String

탐지 할 url

탐지 제외 할 url

rule_name_include

String

탐지 할 룰

rule_name_exclude

String

탐지 제외 할 룰

Example

Response fields

X

X

X

X

O

O

O

O

X

X

--

--

ISO 8601 형식("

ISO 8601 형식("

URL 참고

URL 참고

URL 참고

URL 참고

--

--

Request Parameter

Data Type

Explanation

--

--

--

Example

/log/intrusionlog/count

GET

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

65/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

조건에 맞는 탐지로그의 개수를 조회한다

 Note: query string으로 주고 받기 때문에 webapi 사용시 'urlencode'해서 요청해야함.

Request Parameter( where절의 조건이 됨. 확장가능함. )

Request Parameter

Data Type

Explanation

Required

stime

etime

hidden

action

String

String

Boolean

시작시간

끝날 시간

숨김 로그 (이 조건을 주지 않으면 숨김로그 설정과 관계없이 모두 가져옴.).
true : 숨김로그만, false : 숨김로그제외

String

대응 방식. no_response, redirect, error_code, disconnect

website_include

String

탐지 할 웹사이트 형식: 웹사이트+ %3a + Port

website_exclude

String

탐지 제외 할 웹사이트 형식: 웹사이트+ %3a + Port

source_ip_include

String

탐지 할 출발지 ip. 형식에 맞는 ip %2c ...

source_ip_exclude

String

탐지 제외 할 출발지 ip. 형식에 맞는 ip %2c ...

destination_ip_include

String

탐지 할 도착지 ip. 형식에 맞는 ip %2c ...

destination_ip_exclude

String

탐지 제외할 도착지 ip. 형식에 맞는 ip %2c ...

uri_include

String

탐지 할 url. url %2c ...

uri_exclude

String

탐지 제외 할 url. url %2c ...

country_code_include

String

탐지 할 국가. 국가 코드 %2c ...

country_code_exclude

String

탐지 제외 할 국가. 국가 코드 %2c ...

rule_name_include

String

탐지 할 룰

rule_name_exclude

String

탐지 제외 할 룰

policy_name_include

String

탐지 할 정책

policy_name_exclude

String

탐지 제외 할 정책

Example

Response fields

X

X

X

X

O

O

O

O

O

O

O

O

X

X

X

X

X

X

YYYY-MM-DD+

YYYY-MM-DD+

--

--

중복 입력 불가

URL 참고

중복 입력 불가

URL 참고

중복 입력 불가

호스트 IP 검증

중복 입력 불가

호스트 IP 검증

중복 입력 불가

호스트 IP 검증

중복 입력 불가

호스트 IP 검증

중복 입력 불가

URL 참고

중복 입력 불가

URL 참고

--

--

--

--

--

--

Request Parameter

Data Type

Explanation

param[stime]

param[etime]

result

Example

String

String

Array

/log/intrusionlog/sequence/(sequence_num)

GET

특정 탐지로그의 정보를 조회한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

시작시간 형식: YYYY-MM-DD+HH%3amm%3ass

끝날 시간 형식: YYYY-MM-DD+HH%3amm%3ass

조건에 맞는 intrusionlog

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

66/141

WAPPLES Web API - Penta Security Wiki

Explanation

2020. 8. 7.

Response fields

Response field

Data Type

source_ip

source_port

String

String

출발지 ip

출발지 port

country_code

String

국가

time

String

탐지 시간

rule_name

Stromg

탐지된 룰 이름

policy_name

uri

raw_data

raw_position

String

String

String

String

hidden

Boolean

ipblock_weight

String

action

base_type

base_str

base_int

String

String

String

String

탐지된 정책 이름

url

raw data

탐지 원인

로그 숨김설정.
true 숨김 false 숨기지 않음

위험도

대응

탐지 근거 타입

탐지 근거

탐지 근거

destination_ip

String

도착지 ip

destination_port

String

도착지 port

host_name

String

호스트 네임

req_line_headers

String

res_line_headers

String

status_code

website

Example

String

String

웹사이트

/export/intrusionlog (type:JSON)

POST

탐지로그(탐지로그 보고서)와 탐지로그 통계(탐지로그 통계 보고서)를 내보내 준다.

Request Parameter

Request Parameter

Data Type

Explanation

Required

content[]

String

내보내기 종류

language

String

한국어 ko, 영어 en, 일본어 ja

언어 설정.

stime

etime

time_zone

sort_key

sort_order

log_count

offset

String

String

String

String

String

시작 시간.

끝날 시간.

시간대 "+GMT"

정렬기준

정렬방법

Number

내보낼 탐지로그 개수, content = list일 때만 필요.

Number

건너뛸 행 수를 지정, content = list일 때만 필요.

hidden_state

String

none 숨김 로그 제외 hidden 숨김로그만 all 전체

숨김로그.

action

String

대응방식. no_response, redirect, error_code, disconnect, all : 전체

extend_filter[name]

String

website, source_ip, destination_ip, uri, country_code, rule_name, policy_name

필터 항목

extend_filter[include]

Boolean

필터링 설정

포함 true, 제외 false

extend_filter[value]

Array

필터링 목록

Example

X

X

X

X

X

X

X

X

X

X

X

X

X

X

--

--

ISO 8601 형식 Y

ISO 8601 형식 Y

--

--

--

--

--

--

--

--

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

67/141

2020. 8. 7.

Response fields

Response
field

Data Type

--

--

--

Example

WAPPLES Web API - Penta Security Wiki

Explanation

/export/intrusionlog/(hash_id) (type:JSON)

GET

탐지로그(탐지로그 보고서)와 탐지로그 통계(탐지로그 통계 보고서)를 내보낸 결과를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Explanation

Required

--

--

Example

Response fields

Response
field

Data Type

String

String

status

file_name

Example

내보내기 결과. 진행중 "start", 종료 "done"

내보낸 파일명 (기존에 만들어진 file과 동일한 이름을 가지고 있다면 rename해서 저장하므로 'status'가 'done'일 때, 이 field를 확인 해야

Explanation

상태정보(Current Status)

/status/web_traffic(type:JSON) (~v4.0)

GET

v5.0 은 #/statistics/web_traffic(type:JSON) (v4.1~)을 참고

조회하고자하는 host name과 날짜(format xxxx-xx-xx 년 월 일)로 요청하면 traffic정보를 받음.

둘 중에 하나라도 빠지거나 날짜의 format이 맞지않는 경우, 잘못된 날짜를 적는 경우 BABREQUEST가 된다.

traffic정보는 web_statistics_day Table에서 정보를 가져온다.

Request Parameter

Request
Parameter

Data Type

Explanation

Required

String

String

조회하고자 하는 Host Name

조회 날짜

O

O

URL 참고

ISO 8601 형식: Y

hostName

date

Example

Response fields

Explanation

Response field

Data Type

virtual_host_name

String

start_time

end_time

String

String

형식: YYYY-MMDD HH:mm:ss

형식: YYYY-MMDD HH:mm:ss

traffic_bytes_avg

Number

Example

/info/redundant_psu(type:JSON)

GET

PSU(power supply unit) check 기능 제공하는 장비 인지 아닌지 확인.

v4.0 이하 : /sphere/var/redundant_psu file에서 읽어온 값을 전달해줌.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

68/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

redundant_psu

Boolean

psu기능 지원 여부 true, false

Example

/status/power_supply(type:JSON)

GET

PSU(power supply unit) 정보를 보여줌.

v4.0 이하 : /sphere/var/stat_psu file에서 읽어온 값을 전달해줌.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

Response
field

Data Type

ps_number

Number

psu 장비 개수

psu_stat

Boolean

장비 각각의 상태. 정상 true, 비정상 false

Explanation

temperature

Number

장비 온도

12_voltage

Number

3.3_voltage

Number

5_voltage

Number

전압

전압

전압

Example

/status/database

GET

db정보를 조회한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

available_size

Number

사용가능한 db크기(byte)

used_size

Number

사용하고있는 db크기(byte)

total_size

Number

총 db크기(byte)

Example

/status/disk

Explanation

Required

--

--

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

69/141

2020. 8. 7.

 Note:  v4.0 은 /stat/disk

GET

disk 정보를 조회한다

단위 byte

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

name

mount

String

String

disk 명

mount위치

partition_label

String

파티션 라벨

total_size

Number

총 사이즈 (byte)

used_size

Number

사용하고있는 사이즈 (byte)

Example

/status/ha

GET

ha 정보를 조회한다.

저장장소 : /proc/np/ha_info

ha info 참조 : http://npdev.pentasecurity.com/index.php/HA_CLI#show

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

WAPPLES Web API - Penta Security Wiki

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

70/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response field

Data Type

Explanation

enable

Boolean

HA 이중화 기능을 활성화/비활성화. true/false

ha_preemption

String

HA 이중화 장비에서 아무도 Active가 없는 조건이 되면 본인이 Standby에서 Active로 변경 Enable/Disable

HA preemption 기능을 활성화/비활성화. HA Preemption은 Active의 선점권을 의미

ha_conf_own_state

String

HA 이중화 환경에서, 설정된 자신의 State 정보를 확인
NP_STANDBY/NP_ACTIVE

ha_conf_opp_state

String

주의)HA가 off인 경우에는 NP_NONE으로 표시된다.

NP_STANDBY/NP_ACTIVE/NP_NONE

HA 이중화 환경에서, 설정된 상대편 장비의 State 정보를 확인

ha_run_own_state

String

HA 이중화 환경에서, 자신의 현재 State를 확인
NP_DOWN/NP_READY/NP_STANDBY/NP_ACTIVE

ha_run_opp_state

String

HA 이중화 환경에서, 상대편 장비의 현재 State를 확인
NP_DOWN/NP_READY/NP_STANDBY/NP_ACTIVE

시스템 자원 중에서 Detection Engine, Service link등의 상태값을 체크할 것인지에 대한 설정 정보를 확인

체크 결과에서 문제가 있는 경우 자신의 State가 NP_DOWN라고 변경

NP_DOWN은 시스템이 정상운용 상태가 아님을 구분할 때 사용

condition_flag

String

DETECTION_ENGINE_DOWN(ON)

DETECTION_ENGINE_UP(ON)

DETECTION_ENGINE_UP(OFF)

SERVICE_LINK_DOWN(ON)

SERVICE_LINK_UP(ON)

SERVICE_LINK_UP(OFF)

FORCE_DETECTION_ENGINE_UP

FORCE_DETECTION_ENGINE_DOWN

packet forwarding 설정을 확인한다.

packet_forwarding

String

이중화된 장비에서 들어온 패킷에 대해 세션이 생성되어 있지 않다면, 상대편 장비로 패킷을 전달하는 기능

on/off

hot_line_link

String

hotline으로 사용되는 link 이름과 state(UP/DOWN)를 표시 HA State 정보를 주고 받을 때 사용

source_ip

Number

hotline link의 IP(ipv4)를 의미 형식: X.X.X.X

dest_ip

String

상대편장비의 hotline link의 IP(ipv4)를 의미 형식: X.X.X.X

source_port

Number

hotline link에서 사용할 TCP port를 의미 ex) 20000

dest_port

Number

상대편장비의 hotline link에서 사용할 TCP port를 의미 ex) 20000

source_mac_addr

String

hotline link의 mac address를 의미 형식: XX:XX:XX:XX:XX:XX

dest_mac_addr

String

상대편장비의 hotline link mac address를 의미 형식: XX:XX:XX:XX:XX:XX

Example

/status/detection_engine (type:JSON)

GET

탐지엔진의 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Response field

Data Type

Explanation

de_total

de_info

de_info[status]

Number

탐지엔진 개수

Array

String

탐지엔진 상태.[start, normal, warning, critical, error]

de_info[cpu_used_rate] Number

cpu점유율

Example

/info/system/cpu (type:JSON)

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

71/141

2020. 8. 7.

GET

cpu의 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

WAPPLES Web API - Penta Security Wiki

Explanation

Required

--

--

Response field

Data Type

Explanation

model_name

String

CPU Processor

physical_cpu_count Number

physical cpu 개수

logical_cpu_count

Number

logical cpu 개수

core_count

Number

Core 개수

Example

/status/sw_bypass

(점검필요)밑의 de_engine과 합할지 고민. 두 정보 다 mariadb의 sysmonlog에서 가지고 옴.

GET

bypass의 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

Explanation

Required

--

--

Explanation

sw_bypass

String

sysmonlog table의 sw_bypass 컬럼 값. 0은 off, 1은 on

Example

/status/sw_nifc (type:JSON)

/proc/np/swnifc_info 파일 읽어서 보여줌.

1. Network Interface Failure Check 상태 정보

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

72/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response field

Data Type

swnifc

Array

swnifc[group_id]

String

pair로 관리되는 두개이상의 포트 그룹 id

swnifc[state]

String

nifc 사용 상태. 사용 on, 사용 안함은 off

Explanation

swnifc[info]

Array

swnifc[info]
{port}

String

관리되는 port

swnifc[info]{link}

String

Example

link 상태.
up 살아있음
- 죽어있음

/status/network_interface (type:JSON)

GET

네트워크 인터페이스의 현황을 조회합니다.

Request Parameter

Request
Parameter

Data Type

Explanation

Required

interface

String

조회하고자하는 interface name

X

--

Example

Response fields

Response
field

Data Type

interface_name

String

nic 이름

link

duplex

speed

String

String

연결 상태

duplex 설정 값

Number

속도(Mb단위)

hw_bypass

hw_nifc

String

String

hw bypass 상태. (off, on, auto )

H/W NIFC 상태. nifc off/on

hw_default_act

String

인터페이스 상태(사용X) bypass/disconnect

hw_slot_pair

String

하드웨어 슬롯 페어 정보(사용X)

Example

Explanation

/status/website_health (type:JSON)

GET

웹사이트의 응답결과를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

host_name

String

host name

url

String

status_code

Number

url

코드

Explanation

Required

--

--

Explanation

end_time

String

마지막 시간. ISO 8601 형식("yyyy-MM-dd HH:mm:ss")

Example

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

73/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

/info/conf_db(type:JSON)

GET

업데이트 시간을 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Explanation

Required

--

--

Example

Response fields

Response
field

Data Type

String

String

String

name

mtime

hash

Example

업데이트 항목. appliance, detect, network

업데이트 시간. 형식: YYYY-MMDD HH:mm:ss

db의 hash값

Explanation

통계정보(Statistical Informations)

/statistics/intrusionlog (type:JSON)

탐지로그 통계

GET

탐지된 로그 개수별 통계를 조회한다.

Request Parameter

Request
Parameter

Data Type

Explanation

Required

key1

String

by_policy, by_rule, by_country, by_source_ip, by_website

통계 target.

stime

etime

String

String

시작 시간.

끝날 시간.

website_include

Array

웹사이트 목록(없을 경우 웹사이트 전체가 대상)

website_exclude

Array

웹사이트 목록(없을 경우 웹사이트 전체가 대상)

top

Number

탐지 개수가 가장 많은 것 부터 몇개의 결과를 가져올 것인가 정하는 값. (0인 경우 전체)

O

O

O

X

X

X

공백 입력 불가

ISO 8601 형식: Y

ISO 8601 형식: Y

URL 참고

URL 참고

--

Example

Response fields

Response
field

Data Type

Request Parameter

Explanation

param

Object

"param" : { "key1":"by_policy", "top":"5", "stime":"2013-05-06 14:11:00", "etime":"2013-05-06 15:11:00", }

String

정책이름

Number

탐지된 개수

key1

count

Example

탐지룰별 대응 현황

GET

탐지로그 현황 페이지에서 사용되는 통계정보로 탐지로그 대응 코드값별 통계정보 조회

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

74/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Required

website_include

Array

웹사이트 목록(없을 경우 웹사이트 전체가 대상)

website_exclude

Array

웹사이트 목록(없을 경우 웹사이트 전체가 대상)

top

Number

탐지 개수가 가장 많은 것 부터 몇개의 결과를 가져올 것인가 정하는 값. (0인 경우 전체)

O

O

O

O

X

X

X

공백 입력 불가

공백 입력 불가

ISO 8601 형식("y

ISO 8601 형식("y

URL 참고

URL 참고

--

Request
Parameter

Data Type

key1

key2

stime

etime

String

String

String

String

by_rule

for_action

시작 시간.

끝날 시간.

Example

Response fields

Response
field

Data Type

param{}

name

total

Object

String

Request Parameter

룰 이름

Number

총개수

disconnect

Number

연결 끊기

redirect

Number

재전송

error_code

Number

에러코드

not_blocked

Number

차단하지 않음

Example

웹사이트별 탐지로그

GET

웹사이트별 탐지로그를 조회한다.

Request Parameter

Request
Parameter

Data Type

key1

key2

stime

etime

String

String

String

String

by_website

for_time

시작 시간

끝날 시간

Explanation

Explanation

Required

O

O

O

O

X

X

공백 입력 불가

공백 입력 불가

ISO 8601 형식("y

ISO 8601 형식("y

URL 참고

URL 참고

website_include

String

웹사이트 목록(없을 경우 웹사이트 전체가 대상) , 로 구분

website_exclude

String

웹사이트 목록(없을 경우 웹사이트 전체가 대상) , 로 구분

Example

Response fields

입력 시간 구간에 따른 반환 되는 시간 간격이 다름.

1. 끝날 시간 - 시작 시간 = 5분 => 5초 간격

2. 끝날 시간 - 시작 시간 = 1시간 => 1분 간격

3. 끝날 시간 - 시작 시간 = 1일 => 1시간 간격

4. 끝날 시간 - 시작 시간 = 1주일 => 4시간 간격

5. 끝날 시간 - 시작 시간 = 1달 => 1일 간격

6. 끝날 시간 - 시작 시간 = 1년 => 1달 간격

Response field

Data Type

Explanation

param{}

key1

Object

String

Request Parameter

웹사이트 명

statistics[key2]

String

탐지된 시간

statistics[count] Number

탐지된 개수

Example

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

75/141

2020. 8. 7.

웹사이트별 룰 통계

GET

탐지된 로그의 웹사이트별 룰 통계를 조회한다.

Request Parameter

Request
Parameter

Data Type

key1

key2

stime

etime

String

String

String

String

by_website

for_rule

시작 시간.

끝날 시간.

WAPPLES Web API - Penta Security Wiki

Explanation

Required

website_include

String

웹사이트 목록(없을 경우 웹사이트 전체가 대상).

website_exclude

String

웹사이트 목록(없을 경우 웹사이트 전체가 대상).

rule_include

String

룰 목록(없을 경우 룰 전체가 대상).

Example

Response fields

Response field

Data Type

Explanation

param{}

key1

Object

String

Request Parameter

웹사이트 명

statistics[key2]

String

탐지 룰 이름

statistics[count] Number

탐지된 개수

Example

탐지로그 검토하기

GET

탐지로그 검토의 정보들을 조회합니다

 Note: query string으로 주고 받기 때문에 webapi 사용시 'urlencode'해서 요청해야함.

Request Parameter

O

O

O

X

X

X

X

공백 입력 불가

공백 입력 불가

ISO 8601 형식("y

ISO 8601 형식("y

--

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

76/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request Parameter

Data Type

Explanation

Required

O

O

X

O

O

X

X

X

X

O

O

O

O

O

O

X

X

X

X

X

X

공백 입력 불가

공백 입력 불가

--

ISO 8601 형식(

ISO 8601 형식(

--

--

URL 참고

URL 참고

호스트 IP 검증

호스트 IP 검증

호스트 IP 검증

호스트 IP 검증

URL 참고

URL 참고

--

--

--

--

--

--

key1

key2

hash_id

stime

etime

String

String

Number

String

String

by_uri

for_rule

hash id

시작 시간

끝날 시간

hidden

Boolean

true : 숨김로그만, false : 숨김로그제외

숨김 로그 (이 조건을 주지 않으면 숨김로그 설정과 관계없이 모두 가져옴.)

action

String

no_response, redirect, error_code, disconnect

대응 방식.

website_include

Array

website_exclude

Array

source_ip_include

Array

source_ip_exclude

Array

destination_ip_include

Array

destination_ip_exclude

Array

uri_include

Array

uri_exclude

Array

country_code_include

Array

country_code_exclude

Array

탐지 할 웹사이트

웹사이트+ %3a + Port

탐지 제외 할 웹사이트

웹사이트+ %3a + Port

탐지 할 출발지 ip

형식에 맞는 ip %2c ...

탐지 제외 할 출발지 ip

형식에 맞는 ip %2c ...

탐지 할 도착지 ip

형식에 맞는 ip %2c ...

탐지 제외할 도착지 ip

형식에 맞는 ip %2c ...

탐지 할 url

url %2c ...

탐지 제외 할 url

url %2c ...

탐지 할 국가

국가 코드 %2c ...

탐지 제외 할 국가

국가 코드 %2c ...

rule_name_include

rule_name_exclude

Array

Array

탐지 할 룰

탐지 제외 할 룰

policy_name_include

Array

탐지 할 정책

policy_name_exclude

Array

탐지 제외 할 정책

Example

Response fields

Response
field

Data Type

param{}

Object

Request Parameter

order

Number

요청횟수

end_point

Boolean

end_point 여부

website

uri

rules

String

String

Object

웹사이트

uri

rules[name]

String

탐지된 룰 이름

rules[count]

Number

탐지된 횟수

Example

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

77/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

/statistics/system/cpu_mem (type:JSON)

GET

시스템 CPU & Memory의 정보를 조회한다

Request Parameter

 Note: 시간 조건과 get_count은 동시에 쓰일 수 없습니다.

Request
Parameter

Data Type

stime

etime

String

String

시작 시간. timestamp

끝날 시간. timestamp

get_count

Number

가져올 data 개수

Example

Response fields

입력 시간 구간에 따른 반환 되는 시간 간격이 다름.

1. 끝날 시간 - 시작 시간 = 5분 => 5초 간격

2. 끝날 시간 - 시작 시간 = 1시간 => 1분 간격

3. 끝날 시간 - 시작 시간 = 1일 => 1시간 간격

4. 끝날 시간 - 시작 시간 = 1주일 => 4시간 간격

Response
field

Data Type

time

String

시간. 형식: YYYY-MMDD HH:mm:ss

cpu_idle

Number

사용가능한 cpu (%)

memory_tatal

Number

총 메모리 (byte)

memory_free

Number

사용가능한 메모리 (byte)

memory_cache Number

캐시 메모리 (byte)

memory_buffer Number

버퍼 메모리 (byte)

Example

/statistics/system/traffic (type:JSON)

GET

시스템 TRAFFIC cps, tps, throughput을 조회한다

Request Parameter

 Note: 시간 조건과 get_count은 동시에 쓰일 수 없습니다.

Request
Parameter

Data Type

String

String

String

시작 시간.

끝날 시간.

가져올 data 개수

stime

etime

get_count

Example

Response fields

입력 시간 구간에 따른 반환 되는 시간 간격이 다름.

1. 끝날 시간 - 시작 시간 = 5분 => 5초 간격

2. 끝날 시간 - 시작 시간 = 1시간 => 1분 간격

3. 끝날 시간 - 시작 시간 = 1일 => 1시간 간격

4. 끝날 시간 - 시작 시간 = 1주일 => 4시간 간격

Explanation

Required

O

O

O

ISO 8601 형식 YY

ISO 8601 형식 YY

--

Explanation

Explanation

Required

O

O

O

ISO 8601 형식: Y

ISO 8601 형식: Y

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

78/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response field

Data Type

Explanation

Explanation

Required

O

O

X

X

ISO 8601 형식:YY

ISO 8601 형식:YY

URL 참고

URL 참고

param[stime]

String

param[etime]

String

result[time]

String

시작 시간.
ISO 8601 형식:YYYY-MMDD HH:mm:ss

끝 시간.
ISO 8601 형식:YYYY-MMDD HH:mm:ss

시간.
ISO 8601 형식:YYYY-MMDD HH:mm:ss

result[cps]

result[tps]

Number

Number

cps

tps

result[throughput] Number

throughput

Example

/statistics/web_traffic(type:JSON) (v4.1~)

GET

시스템 TRAFFIC과 page hit를 조회한다

Request Parameter

Request
Parameter

Data Type

stime

etime

Array

Array

시작 시간

끝날 시간

website_include

Array

웹사이트 목록(없을 경우 웹사이트 전체가 대상)

website_exclude

Array

웹사이트 목록(없을 경우 웹사이트 전체가 대상)

Example

Response fields

입력 시간 구간에 따른 반환 되는 시간 간격이 다름.

1. 끝날 시간 - 시작 시간 = 5분 => 5초 간격

2. 끝날 시간 - 시작 시간 = 1시간 => 5분 간격

3. 끝날 시간 - 시작 시간 = 1일 => 1시간 간격

4. 끝날 시간 - 시작 시간 = 1주일 => 4시간 간격

5. 끝날 시간 - 시작 시간 = 1달 => 1일 간격

6. 끝날 시간 - 시작 시간 = 1년 => 1달 간격

Response field

Data Type

Explanation

param

Object

Request Parameter

param[stime]

param[etime]

String

String

시작 시간

끝 시간

param[website_include]

String

웹사이트 목록(없을 경우 웹사이트 전체가 대상)

result[website]

String

웹사이트

result[statistics][time]

String

시간

result[statistics]
[hit_count]

result[statistics]
[traffic_bytes]

Example

Number

hit 개수

Number

트래픽

/statistics/nic_stat(type:JSON)

GET

시스템현황에서 사용하는 nic 정보를 조회한다

network interface stat

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

79/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request Parameter

Data Type

Explanation

Required

stime

etime

String

String

시작 시간.

끝날 시간.

interface_name_include

String

조회 하고자하는 interface name (없을 경우 전체가 대상)

interface_name_exclude

String

조회 제외하고자하는 interface name(없을 경우 전체가 대상)

interface_name

String

조회하고자하는 특정 interface name

O

O

X

X

X

ISO 8601 형식

ISO 8601 형식

--

--

--

Example

Response fields

입력 시간 구간에 따른 반환 되는 시간 간격이 다름.

1. 끝날 시간 - 시작 시간 = 5분 => 20초 간격

2. 끝날 시간 - 시작 시간 = 1시간 => 5분 간격

3. 끝날 시간 - 시작 시간 = 1일 => 1시간 간격

4. 끝날 시간 - 시작 시간 = 1주일 => 4시간 간격

5. 끝날 시간 - 시작 시간 = 1달 => 1일 간격

6. 끝날 시간 - 시작 시간 = 1년 => 1달 간격

Response field

Data Type

Explanation

param

param[stime]

param[etime]

Object

Request Parameter

String

String

시작 시간

끝날 시간

param[interface_name_include]

String

조회 하고자하는 interface name (없을 경우 전체가 대상)

param[interface_name_exclude]

String

조회 제외하고자하는 interface name(없을 경우 전체가 대상)

param[interface_name]

interface_name

statistics[time]

String

String

String

조회하고자 하는 특정 interface name

네트워크 인터페이스명

시간
ISO 8601 형식("yyyy-MM-dd HH:mm:ss")

statistics[rx_bytes_avg]

Number

RX bytes 정보

statistics[rx_pkt_avg]

Number

RX packets 정보

statistics[rx_err_avg]

Number

RX errors 정보

statistics[rx_drop_avg]

Number

RX dropped 정보

statistics[tx_bytes_avg]

Number

TX bytes 정보

statistics[tx_pkt_avg]

Number

TX packets 정보

statistics[tx_err_avg]

Number

TX errors 정보

statistics[tx_drop_avg]

Number

TX dropped 정보

statistics[collisions]

Number

collisions 정보

Example

네트워크(Network)

/conf/proxy (type:JSON)

GET

서비스네트워크의 모든 정보를 조회한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

80/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Explanation

Required

O

O

O

X

중복 입력 불가

호스트 IP 검증 참

호스트 IP 검증 참

Netmask 참고

--

Explanation

Explanation

Required

--

--

Explanation

Response
field

Data Type

String

String

String

String

proxy ip

gateway

netmask

nic

proxy_ip

gateway

netmask

nic

Example

POST

서비스네트워크 정보를 추가 한다

Request Parameter

Request
Parameter

Data Type

proxy_ip

String

proxy ip

gateway

String

gateway

String

String

netmask

nic

netmask

nic

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/proxy/(doc id) (type:JSON)

특정 서비스네트워크 정보를 조회한다

netmask field를 추가할 필요가 있는가?

 Note: nic 정보 필요 없어짐. ( filter설정만으로, proxy 통신 가능함. )

GET

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

String

String

String

String

proxy ip

gateway

netmask

nic

proxy_ip

gateway

netmask

nic

Example

PUT

특정 서비스네트워크 정보를 수정한다

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

81/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

proxy_ip

String

proxy ip

gateway

String

gateway

String

String

netmask

nic

netmask

nic

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

DELETE

특정 서비스네트워크 정보를 삭제한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/webserver (type:JSON)

GET

웹서버에 등록된 모든 정보를 조회한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

중복 입력 불가

호스트 IP 검증 참

호스트 IP 검증 참

Netmask 참고

--

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

82/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Explanation

Required

O

P

X

O

X

X

X

X

X

X

X

X

X

호스트 IP 검증 참

Port 검증 참고

--

Port 검증 참고

--

--

--

--

--

--

--

--

--

Explanation

Response field

Data Type

webserver_ip

String

웹서버 IP

webserver_port

Number

웹서버 Port

wp_proxy_id

String

proxy doc_id

wp_proxy_port

Number

proxy port

ssl

ssl_crt

ssl_key

ssl_chain

Boolean

SSL 사용여부. true, false

String

String

String

인증서

인증서 key

중개 인증서

ssl_termination

Number

ssl termination 여부. 0, 1

ssl_ca_crt

Boolean

클라이언트 인증서

ssl_ca

Boolean

Client Authentication 사용여부. true, false

webserver_vlan_id Number

VLAN ID

proxy_mode

Number

모드. inline 0, proxy 1, T.Proxy 2

Example

POST

웹서버 정보를 추가한다

Request Parameter

Request
Parameter

Data Type

webserver_ip

String

웹서버 IP

webserver_port

Number

웹서버 Port

wp_proxy_id

String

proxy doc_id

wp_proxy_port

Number

proxy port

ssl

ssl_crt

ssl_key

ssl_chain

Boolean

SSL 사용여부. true, false

String

String

String

인증서

인증서 key

중개 인증서

ssl_termination

Number

ssl termination 여부. 0, 1

ssl_ca_crt

ssl_ca

Boolean

Boolean

클라이언트 인증서

Client Authentication 사용여부. true, false

webserver_vlan_id Number

VLAN ID

proxy_mode

Number

모드. inline 0, proxy 1, T.Proxy 2

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/webserver/(doc id) (type:JSON)

GET

특정 웹서버 정보를 조회한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

83/141

2020. 8. 7.

Response fields

WAPPLES Web API - Penta Security Wiki

Explanation

Explanation

Required

O

O

X

O

X

X

X

X

X

X

X

X

X

호스트 IP 검증 참

Port 검증 참고

--

Port 검증 참고

--

--

--

--

--

--

--

--

--

Explanation

Response field

Data Type

webserver_ip

String

웹서버 IP

webserver_port

Number

웹서버 Port

wp_proxy_id

String

proxy doc_id

wp_proxy_port

Number

proxy port

ssl

ssl_crt

ssl_key

ssl_chain

Boolean

SSL 사용여부. true, false

String

String

String

인증서

인증서 key

중개 인증서

ssl_termination

Number

ssl termination 여부. 0, 1

ssl_ca_crt

Boolean

클라이언트 인증서

ssl_ca

Boolean

Client Authentication 사용여부. true, false

webserver_vlan_id Number

VLAN ID

proxy_mode

Number

모드. inline 0, proxy 1, T.Proxy 2

Example

PUT

특정 웹서버 정보를 수정한다

Request Parameter

Request
Parameter

Data Type

webserver_ip

String

웹서버 IP

webserver_port

Number

웹서버 Port

wp_proxy_id

String

proxy doc_id

wp_proxy_port

Number

proxy port

ssl

ssl_crt

ssl_key

ssl_chain

Boolean

SSL 사용여부. true, false

String

String

String

인증서

인증서 key

중개 인증서

ssl_termination

Number

ssl termination 여부. 0, 1

ssl_ca_crt

ssl_ca

Boolean

Boolean

클라이언트 인증서

Client Authentication 사용여부. true, false

webserver_vlan_id Number

VLAN ID

proxy_mode

Number

모드. inline 0, proxy 1, T.Proxy 2

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

DELETE

특정 웹서버 정보를 삭제 한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

84/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

ok

Boolean

Example

/conf/ssl_profile (type:JSON)

GET

SSL 프로파일에 등록된 모든 정보를 조회한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Explanation

Required

--

--

Response field

Data Type

Explanation

crt

crt_subject_cn

crt_issuer

crt_issue_date

crt_expired_date

private_key

string

string

string

string

string

string

인증서 내용

인증서 Common Name

인증서 발행자

인증서 발행일자

인증서 만료일자

비밀키

private_key_length

int

비밀키 길이

client_ca_crt

client_ca _cn

string

string

클라이언트 CA 인증서

클라이언트 CA 인증서 Common Name

client_ca_issuer_date

string

클라이언트 CA 인증서 발행일자

client_ca_expired_date

string

클라이언트 CA 인증서 만료일자

chain_crt_list

webserver

Example

array

array

체인 인증서 리스트

webserver doc id array

POST

SSL 프로파일 정보를 추가한다

Request Parameter

Request
Parameter

Data Type

Explanation

Required

Validate

crt

string

인증서 내용

private_key

string

개인키

client_ca_crt

string

클라이언트 CA 인증서

chain_crt_list

array

체인 인증서 리스트

O

O

X

X

인증서 내용은 pem 형태로 시작은 "-----BEGIN CERTIFICATE-----\n" 으로 시작
CERTIFICATE-----\n"로 끝나야 함.

개인키 내용은 pem 형태로 시작은 "-----BEGIN RSA PRIVATE KEY-----\n" 으로
RSA PRIVATE KEY-----\n"로 끝나야 함.

인증서 내용은 pem 형태로 시작은 "-----BEGIN CERTIFICATE-----\n" 으로 시작
CERTIFICATE-----\n"로 끝나야 함.

리스트의 인증서 내용은 pem 형태로 시작은 "-----BEGIN CERTIFICATE-----\n"
END CERTIFICATE-----\n"로 끝나야 함.

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

Explanation

/conf/ssl_profile/(doc id) (type:JSON)

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

85/141

2020. 8. 7.

GET

특정 SSL 프로파일 정보를 조회한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

WAPPLES Web API - Penta Security Wiki

Explanation

Required

--

--

Response field

Data Type

Explanation

crt

crt_subject_cn

crt_issuer

crt_issue_date

crt_expired_date

private_key

string

string

string

string

string

string

인증서 내용

인증서 Common Name

인증서 발행자

인증서 발행일자

인증서 만료일자

비밀키

private_key_length

int

비밀키 길이

client_ca_crt

client_ca _cn

string

string

클라이언트 CA 인증서

클라이언트 CA 인증서 Common Name

client_ca_issuer_date

string

클라이언트 CA 인증서 발행일자

client_ca_expired_date

string

클라이언트 CA 인증서 만료일자

chain_crt_list

webserver

Example

array

array

체인 인증서 리스트

webserver doc id array

PUT

SSL 프로파일 정보를 추가한다

Request Parameter

Request
Parameter

Data Type

Explanation

Required

Validate

crt

string

인증서 내용

private_key

string

개인키

client_ca_crt

string

클라이언트 CA 인증서

chain_crt_list

array

체인 인증서 리스트

O

O

X

X

인증서 내용은 pem 형태로 시작은 "-----BEGIN CERTIFICATE-----\n" 으로 시작
CERTIFICATE-----\n"로 끝나야 함.

개인키 내용은 pem 형태로 시작은 "-----BEGIN RSA PRIVATE KEY-----\n" 으로
RSA PRIVATE KEY-----\n"로 끝나야 함.

인증서 내용은 pem 형태로 시작은 "-----BEGIN CERTIFICATE-----\n" 으로 시작
CERTIFICATE-----\n"로 끝나야 함.

리스트의 인증서 내용은 pem 형태로 시작은 "-----BEGIN CERTIFICATE-----\n"
END CERTIFICATE-----\n"로 끝나야 함.

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

DELETE

특정 SSL 프로파일 정보를 삭제 한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

86/141

2020. 8. 7.

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/network_interface (type:JSON)

저장 장소 : daemons.conf에 의해 저장됨.

GET

등록된 NIC 모든 정보들을 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

WAPPLES Web API - Penta Security Wiki

Explanation

Explanation

Required

--

--

Response field

Data Type

Explanation

network_interface

Array

network_interface[address]

Array

network_interface[address]
[ip]

network_interface[address]
[netmask]

network_interface[address]
[version]

String

ip

String

netmask

String

ip version. ipv4, ipv6

network_interface[bonding]

String

bonding

network_interface[bridge]

String

bridge

network_interface[nic]

String

nic

Example

PUT

NIC 정보를 수정한다.

Request Parameter

Request Parameter

Data Type

Explanation

Required

network_interface

Array

network_interface[address]

Array

network_interface[address]
[ip]

String

ip

network_interface[address]
[netmask]

String

netmask

network_interface[address]
[version]

String

ip version. ipv4, ipv6

network_interface[bonding]

String

bonding

network_interface[bridge]

String

bridge

network_interface[nic]

String

nic

 X

Example

--

--

ip와 netmask합
중복가능)

IP와 netmak의

호스트 IP 검증

ip와 netmask합
중복가능)

IP와 netmak의

호스트 IP 검증

--

--

--

O

O

O

O

X

X

X

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

87/141

WAPPLES Web API - Penta Security Wiki

Explanation

2020. 8. 7.

Response fields

Response
field

Data Type

--

--

--

Example

/conf/management_route (type:JSON)

저장 장소 : /tmp/route_info

Note: TODO

최초 설치된 상태에서 UI를 통해서 아무것도 설정하지 않은 상태에서도, OS에서 이미 설정된 route 정보를 GET 해서 볼 수 있도록 해야 함. 이것은 migration 과정에서 OS에 설정된 정보
를 DB에 넣는 것으로 처리하든, web api가 DB뿐만 아니라 OS의 설정 정보도 보도록 하든, 방법은 몇가지가 될 수 있음. 어찌 됐든 UI에는 web api가 알려줘야 함.

Note: TODO

nprdTransd에 의해 nprd통해 설정하도록 함. 설정한후 설정 내용은 np에 의한 daemons.conf에 의해 저장됨. list형식으로 가는 이유는 control ip를 설정함과 동시에 현재 붙어 있는 gui
는 통신이 끊어지기 때문에 한번에 설정할 내용을 다 받고, 적용하도록 하기 위함이며, webapi는 nprd로 통신하기 전에 먼저 ui에 응답 코드를 보냄으로써 GUI의 통신 끊김이 자연스럽게
유지되어야 함.

GET

관리라우트 정보를 조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Response field

Data Type

Explanation

management_route[dest_ip]

String

dest_ip

management_route[gateway]

String

gateway

management_route[netmask]

String

netmask

management_route[nic]

String

nic

Example

PUT

관리라우트 정보를 수정합니다.

Request Parameter

Request Parameter

Data Type

Explanation

Required

management_route[dest_ip]

String

dest_ip

management_route[gateway]

String

gateway

management_route[netmask]

String

netmask

management_route[nic]

String

nic

Example

Response fields

중복 입력 불가

IP, netmask,

이 동일해야 함

호스트 IP 검증

IP, netmask, g
이 동일해야 함

호스트 IP 검증

IP, netmask, g
이 동일해야 함

Netmask 참고

--

O

O

O

X

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

88/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

--

--

--

Example

/conf/net_filter (type:JSON)

GET

네트워크 필터 설정들을 조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

priority

Number

번호

protocol

String

프로토콜.

tcp, udp, icmp, icmpv6

액션

action

String

허용 allow, 탐지 detect, 거부 deny

src_ip

String

출발지 ip

src_netmask

String

출발지 netmask

src_port

dst_ip

String

String

출발지 port

도착지 ip

dst_netmask

String

도착지 netmask

dst_port

String

도착지 port

Example

PUT

네트워크 필터 설정을 추가합니다.

추가시 따로 doc_id를 전달하지 않아도 번호에 따라서 doc_id 를 생성합니다

Request Parameter

Request
Parameter

Data Type

priority

Number

번호

protocol

String

프로토콜.

tcp, udp, icmp, icmpv6

액션

action

String

허용 allow, 탐지 detect, 거부 deny

src_ip

String

출발지 ip

src_netmask

String

출발지 netmask

src_port

String

출발지 port

dst_ip

String

도착지 ip

dst_netmask

String

도착지 netmask

dst_port

String

도착지 port

Example

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

X

X

O

O

O

O

O

O

O

--

--

--

호스트 IP 검증 참

Netmask 참고

Port 검증 참고

호스트 IP 검증 참

Netmask 참고

Port 검증 참고

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

89/141

WAPPLES Web API - Penta Security Wiki

Explanation

Explanation

Required

--

--

Explanation

2020. 8. 7.

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/net_filter/(number) (type:JSON)

GET 특정 네트워크 필터의 설정을 조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

priority

Number

번호

protocol

String

프로토콜.

tcp, udp, icmp, icmpv6

액션

action

String

허용 allow, 탐지 detect, 거부 deny

src_ip

String

출발지 ip

src_netmask

String

출발지 netmask

src_port

dst_ip

String

String

출발지 port

도착지 ip

dst_netmask

String

도착지 netmask

dst_port

String

도착지 port

Example

PUT

특정 네트워크 필터의 설정을 수정합니다.

사용자가 입력한 doc_id가 유효하지 않을시에는 해당 doc_id에 새로운 정보를 추가해준다

Request Parameter

Request
Parameter

Data Type

priority

Number

번호

protocol

String

프로토콜.

tcp, udp, icmp, icmpv6

액션

action

String

허용 allow, 탐지 detect, 거부 deny

src_ip

String

출발지 ip

src_netmask

String

출발지 netmask

src_port

dst_ip

String

String

출발지 port

도착지 ip

dst_netmask

String

도착지 netmask

dst_port

String

도착지 port

Example

Response fields

Explanation

Required

X

X

X

O

O

O

O

O

O

--

--

--

호스트 IP 검증 참

Netmask 참고

Port 검증 참고

호스트 IP 검증 참

Netmask 참고

Port 검증 참고

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

90/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

ok

Boolean

true, false

Example

DELETE 특정 네트워크 필터의 설정을 삭제합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

true, false

Example

Explanation

Explanation

Required

--

--

Explanation

 Note: ip 항목은 ipv4와 ipv6 용 field를 따로 두지 않고 하나의 field로 두가지 주소를 모두 전달.

 Note: enable은 UI에서는 항상 true로 webapi에 전달, wapples에서는 expire_on에 적힌 시간이 지난 항목은 enable을 false로 변경함.

 Note: expire_on field는 원하지 않을 때 field를 아예 적지 않거나 비워서 전달함.

 Note: webapi 의 시나리오. couchdb 라 적힌 부분은 couch db 에 저장한다. 그리고, data를 msgBody로 하여, dbus 통신한다 ( msgbus.php 이용 가능 ).

PUT :
    1. /proc/np/session_filter 파일을 보아, 사용중인 index를 확인한다.
    2. priority 값이 이미 사용중이라면,
         msg_name은 "filter_del" msgBody는 Data로 하여 dbus 명령 한 뒤,
         msg_name은 "filter_add" msgBody는 Data로 하여 dbus 명령 한다.
    3. priority 값이 사용중이 아니라면,
         msg_name은 "filter_add" msgBody는 Data로 하여 dbu s 명령 한다.
DEL :
    1. /proc/np/session_filter 파일을 보아, 사용중인 index를 확인한다.
    2. priority 값이 이미 사용중이라면,
         msg_name은 "filter_del" msgBody는 Data로 하여 dbus 명령 한다,
    3. priority 값이 사용중이 아니라면,
         존재하지 않는 filter라고 알려준다. 404 not found.

GET :
    1. /proc/np/session_filter 파일을 보아, 사용중인 index를 return 한다..

/conf/dns (type:JSON)

저장장소 : /etc/resolv.conf

system 설정상 3개 이하만 등록 가능하다.

GET

dns의 설정을 조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

nameserver[]

Array

dns 목록.

Example

PUT

dns의 설정을 수정합니다.

Request Parameter

Explanation

Required

--

--

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

91/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Required

O

3 개 이상 입력 불
호스트 IP 검증 참

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

O

O

O

X

호스트 IP 검증 참

호스트명 검증 참

--

Explanation

Request
Parameter

Data Type

nameserver[]

Array

dns 목록

Example

Response fields

Response
field

Data Type

--

--

--

Example

/conf/hosts (type:JSON)

저장장소 : /etc/hosts

GET

host ip의 설정조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response field

Data Type

hosts

hosts[ip]

Array

String

Host IP

hosts[host_name]

String

Host Name

hosts[alias]

String

Alias

Example

PUT

host ip의 설정을 수정합니다.

Request Parameter

Request
Parameter

Data Type

hosts

hosts[ip]

Array

String

Host IP

hosts[host_name]

String

Host Name

hosts[alias]

String

Alias

Example

Response fields

Response
field

Data Type

--

--

--

Example

/conf/third_party_integration (type:JSON)

GET

통합연동설정의 설정값을 조회합니다

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

92/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

--

--

--

Explanation

Required

--

--

Example

Response fields

Response field

Data Type

email{}, syslog{},
snmp{},
snmp_trap{},
sims{}

Array

해당 설정의 연동설정의 목록 (다음 아래에 있는 값들이 목록의 값들)

intrusionlog, website_check, system_status, ip_block, auditlog, network_status, db_load_monitor

Explanation

intrusionlog

String

탐지로그 연동 설정( email, syslog, snmp_trap, sims 지원 )

연동 설정 활성화 on, 연동 설정 비활성화 off, 지원하지 않는기능 unsupported

website_check

String

웹사이트 상태 연동 설정( snmp_trap 지원 )

연동 설정 활성화 on, 연동 설정 비활성화 off, 지원하지 않는기능 unsupported

system_status

String

WAPPLES 상태 연동 설정( snmp_trap 지원 )

연동 설정 활성화 on, 연동 설정 비활성화 off, 지원하지 않는기능 unsupported

ip_block

String

IP Block 연동 설정( snmp_trap 지원 )

연동 설정 활성화 on, 연동 설정 비활성화 off, 지원하지 않는기능 unsupported

auditlog

String

감사로그 연동 설정( syslog 지원 )

연동 설정 활성화 on, 연동 설정 비활성화 off, 지원하지 않는기능 unsupported

network_status

String

탐지로그 연동 설정( 지원안함 )

연동 설정 활성화 on, 연동 설정 비활성화 off, 지원하지 않는기능 unsupported

db_load_monitor

String

탐지로그 연동 설정( 지원안함 )

연동 설정 활성화 on, 연동 설정 비활성화 off, 지원하지 않는기능 unsupported

Example

PUT

통합연동설정의 설정값을 수정합니다

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

93/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

email{}, syslog{},
snmp{},
snmp_trap{},
sims{}

Array

Explanation

Required

해당 설정의 연동설정의 목록 (다음 아래에 있는 값들이 목록의 값들)

intrusionlog,  website_check,

system_status,

ip_block,

auditlog,

network_status,

db_load_monitor

intrusionlog

String

탐지로그 연동 설정( email, syslog, snmp_trap, sims 지원 )

연동 설정 활성화 on, 연동 설정 비활성화 off, 지원하지 않는기능 unsupported

website_check

String

웹사이트 상태 연동 설정( snmp_trap 지원 )

연동 설정 활성화 on, 연동 설정 비활성화 off, 지원하지 않는기능 unsupported

system_status

String

WAPPLES 상태 연동 설정( snmp_trap 지원 )

연동 설정 활성화 on, 연동 설정 비활성화 off, 지원하지 않는기능 unsupported

ip_block

String

IP Block 연동 설정( snmp_trap 지원 )

연동 설정 활성화 on, 연동 설정 비활성화 off, 지원하지 않는기능 unsupported

auditlog

String

감사로그 연동 설정( syslog 지원 )

연동 설정 활성화 on, 연동 설정 비활성화 off, 지원하지 않는기능 unsupported

network_status

String

탐지로그 연동 설정( 지원안함 )

연동 설정 활성화 on, 연동 설정 비활성화 off, 지원하지 않는기능 unsupported

db_load_monitor

String

탐지로그 연동 설정( 지원안함 )

연동 설정 활성화 on, 연동 설정 비활성화 off, 지원하지 않는기능 unsupported

X

X

X

X

X

X

X

X

--

--

--

--

--

--

--

--

Example

Response fields

Response fields

Data Type

Explanation

ok

Example

Boolean

--

/conf/email(type:JSON)

저장장소: couch appliance/email

intrusion_email -> email

GET

이메일 연동 받는 메일 서버를 조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Response
field

Data Type

interval

receiver

Number

시간 간격

String

받는 이메일 주소

trans_standard

String

전송기준. 시간이면 time, 실시간이면 number

enable

Boolean

연동 설정 true, false

Explanation

Example

PUT

이메일 연동 받는 메일 서버를 수정합니다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

94/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Required

Request
Parameter

Data Type

interval

Number

시간 간격

receiver

String

받는 이메일 주소

trans_standard

String

전송기준. 시간이면 time, 실시간이면 number

enable

Boolean

연동 설정 true, false

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/snmp_trap(type:JSON)

snmp의 설정값들을 불러오거나 설정할 수 있다. 저장장소 : couchdb /appliance/snmp_trap

X

O

X

X

공백 입력 불가

입력값 사이에 공

이메일 검증 참고

--

--

Explanation

GET

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Response field

Data Type

Explanation

enable

server

Boolean

연동설정 여부

Array

server[community]

String

public

server[ip]

String

server[port]

Number

ip

port

Example

PUT

Request Parameter

Request
Parameter

Data Type

enable

server

Boolean

연동설정 여부

Array

server[community]

String

public

server[ip]

String

server[port]

Number

ip

port

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

Explanation

Required

X

O

X

O

O

--

--

SNMP 연동설정
이 하나 이상 입

호스트 IP 검증 참

Port 검증 참고

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

95/141

2020. 8. 7.

/info/nic (type:JSON)

 Note: 현재 관리도구에서 사용되지 않는다

lo를 제외한 wapples의 nic를 모두 가져온다

GET

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

[]

Array

nic 목록

Example

외부 연동(External Interlock)

/conf/time_server (type:JSON)

시간동기화 설정의 자동동기화 설정값을 불러오거나 설정할 수 있다.

GET

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

WAPPLES Web API - Penta Security Wiki

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

Explanation

enable

Boolean

자동 동기화 사용 여부

locale

port

server

String

국가 코드. 표준 시간대 국가 설정

Number

port

String

시간 서버 IP

summer

Boolean

일광 절약 시간 사용 여부

동기화 주기

기본 형식: "분 시간 일 * 요일목록"

매 시 5 분 마다 동기화할 경우: "5 * * * *"

sync_period

String

매 일 오후 2시 20 분마다 동기화할 경우: "20 14 * * *"

매 주 월요일, 목요일 오전 2시 20분마다 동기화할 경우: "20 2 * * 1,4"

(일:0, 월:1, 화:2, 수:3, 목:4, 금:5, 토:6) 매 월 5일 오후 2시 56분마다 동기화할 경우: "56 14 5 * *"

time_zone

String

표준 시간대 도시

Example

PUT

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

96/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

Explanation

Required

enable

Boolean

자동 동기화 사용 안 함 설정시에는 유효성 검사를 하지않음

자동 동기화 사용 여부

locale

String

X

국가 코드. 표준 시간대 국가 설정

port

server

Number

port

String

시간 서버 IP

summer

Boolean

일광 절약 시간 사용 여부

동기화 주기

기본 형식: "분 시간 일 * 요일목록"

매 시 5 분 마다 동기화할 경우: "5 * * * *"

sync_period

String

매 일 오후 2시 20 분마다 동기화할 경우: "20 14 * * *"

매 주 월요일, 목요일 오전 2시 20분마다 동기화할 경우: "20 2 * * 1,4"

(일:0, 월:1, 화:2, 수:3, 목:4, 금:5, 토:6) 매 월 5일 오후 2시 56분마다 동기화할 경우: "56 14 5 *

*"

X

--

O

O

X

--

Port 검증 참고

호스트 IP 검증 참

--

동기화 주기 설정
설정 했을경우 요

time_zone

String

표준 시간대 도시

X

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/time

저장 장소 : 없음.

설명 :
PUT : webapi dbus통신하여 sphered를 통해 시간을 설정함.
GET : os 시간을 넘겨줌 ( date +"%Y-%m-%d %H:%M:%S %z" )

Explanation

webapi에서는  /sphere/bin/msgbus_gateway  -a  unix:path=/var/run/dbus/namsgbus.socket  -n  ui.com  -m  time_sync
message_name 은 time_sync message body에 받은 데이타를 넣어서 넘겨주면 됩니다.

'{"time":"2013-02-05  17:50:00  +9:00"}'  이처럼,

GET

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

Explanation

Required

--

--

Explanation

time

String

현재시간 ISO 8601 형식("yyyy-MM-dd HH:mm:ss (+offset)")

Example

PUT

Request Parameter

Request
Parameter

Data Type

time

String

현재시간.

Example

Response fields

Explanation

Required

X

ISO 8601 형식("y
(+offset)")

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

97/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

--

--

--

Example

/status/time_server

시간 동기화 실행 결과를 불러올 수 있다.

저장 장소

v4.0 이하 : /sphere/var/time_server

v5.0 이상 : /var/wapples/time_server

GET

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Explanation

Required

--

--

Response field

Data Type

Explanation

last_sync_succeed_server

String

마지막 동기화 성공한 서버 ip

last_sync_success_time

String

마지막 동기화 성공 시간. ISO 8601 형식("YYYY-MM-DD HH:mm:ss +GMT")

last_sync_trie

String

마지막 동기화 시도 시간. ISO 8601 형식("YYYY-MM-DD HH:mm:ss +GMT")

last_sync_tried_server

String

마지막 동기화 시도한 서버 ip

res_code

Example

Number

Response code

/conf/pls (type:JSON)

PLS 설정 정보를 불러오거나 설정할 수 있다.

저장장소: couchdb /appliance/pls 문서

GET

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Response field

Data Type

Explanation

enable

pls_ip

Boolean

pls 연동 사용여부

String

상대 장비 IP

pls_port

Number

상대 장비 port

pls_admin_id

String

PLS장비 user id

pls_admin_pwd

String

PLS장비 user password

log_synchronize

Boolean

탐지로그 동기화 여부

pls_wapples_id

String

PLS장비 id

Example

PUT

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

98/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

enable

pls_ip

Boolean

pls 연동 사용여부

String

상대 장비 IP

pls_port

Number

상대 장비 port

pls_admin_id

String

PLS장비 user id

pls_admin_pwd

String

PLS장비 user password

log_synchronize

Boolean

탐지로그 동기화 여부

pls_wapples_id

String

PLS장비 id

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/status/pls (type:JSON)

GET

PLS 관련 상태 정보를 조회 합니다.

저장장소

v4.0 이하 : /sphere/var/pls_stat 파일

v5.0 이상 : /var/wapples/pls_stat 파일

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

Explanation

Required

X

O

O

X

O

X

X

--

호스트 IP 검증 참

Port 검증 참고

--

공백 입력 불가

--

--

Explanation

Explanation

Required

--

--

Explanation

status

Number

PLS 상태값.상대 장비의 연결되지 않으면 -2,
두 장비의 버전이 다를 경우 -1,
PLS WAPPLES ID가 상대방이 아닌 경우 0,
상대방 WAPPLES의 PLS기능이 꺼져있지 않거나, 내가 아닌 다른 WAPPLES을 PLS ID로 설정한 경우 1,

PLS 동기화가 깨어진 상태 2,

PLS 정상 구동 상태 3

sync_result

Number

동기화 결과. success 1, fail 0

sync_time

String

마지막으로 PLS sync가 이루어진 시간. ISO 8601 형식("yyyy-MM-dd HH:mm:ss)

Example

 Note: 더 자세한 PLS 상태값: PLS(Policy_Log_Sync)#PLS_PLS 상태 확인 (GUI) 참조

/status/pls_missinglog

GET

pls연동중 누락된 로그가 있는지 조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

99/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

저장장소: /sphere/pls_missing_log/상대방장비id/

Response
field

Data Type

status

Boolean

누락로그의 여부. 누락로그o true, 누락로그x false

Example

Explanation

/conf/mail_sender (type:JSON)

GET

SMTP 설정 정보를 조회한다

저장장소: couch appliance/mail_sender

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

sender

server

String

String

보내는 주소

SMTP 주소

codepage

Number

코드 페이지

charset

String

인코딩

port

Number

SMTP port

use_ssl

Boolean

ssl 사용여부

Boolean

사용자 인증 체크 여부

String

String

id

passwd

auth

id

passwd

Example

PUT

SMTP 설정 정보를 수정한다 ( 보내는 메일 서버 셋팅 )

Request Parameter

Request
Parameter

Data Type

sender

String

보내는 주소

server

String

SMTP 주소

codepage

Number

코드 페이지

String

Number

Boolean

Boolean

String

String

인코딩

SMTP port

ssl 사용여부

사용자 인증 체크 여부

id

passwd

charset

port

use_ssl

auth

id

passwd

Example

Response fields

Explanation

Required

--

--

Explanation

Explanation

Required

O

O

X

X

O

X

X

X

X

공백 입력 불가

입력값 사이에 공

이메일 검증 참고

호스트 IP 검증 참

--

--

Port 검증 참고

--

--

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

100/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

Explanation

Response
field

Data Type

ok

Boolean

Example

/status/email/(email_id) (type:JSON)

GET

보고서 자동 내보내기에서 이메일 보낸 결과를 조회한다

저장장소

v4.0  이하 : /sphere/var/email_result/(email_id)

v5.0  이상 : /var/wapples/email_result/(email_id)

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

send_ok

Boolean

전송 성공여부

send_time

Number

전송 시간

error_code

Number

에러코드

Example

/conf/syslog(type:JSON)

저장장소: couch db /appliance/syslog

GET

등록된 모든 syslog 정보 목록을 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

enable

server

Boolean

syslog 연동설정 여부

Array

server[ip]

String

syslog 서버 ip

server[port]

Number

port

Example

PUT

syslog 정보 목록을 수정한다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

101/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

enable

Boolean

syslog 연동설정 여부

server[ip]

String

syslog 서버 ip

server[port]

Number

port

Explanation

Required

X

O

O

--

호스트 IP 검증 참

Port 검증 참고

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/sims(type:JSON)

저장장소: couchdb /appliance/sims

GET

sims정보를 조회한다

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

enable

Boolean

sims 연동설정 여부

id

port

server_ip

auth_ip

String

SIMS ID

Number

SIMS porrt

String

String

SIMS 서버 ip

관리도구 ip

auth_code

String

인증 코드

sleep_time

Number

sleep time

Example

PUT

sims정보를 수정한다

Request Parameter

Request
Parameter

Data Type

enable

Boolean

sims 연동설정 여부

id

port

server_ip

auth_ip

auth_code

String

SIMS ID

Number

SIMS port

String

String

String

SIMS 서버 ip

관리도구 ip

인증 코드

sleep_time

Number

sleep time

Example

Response fields

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

X

O

O

O

O

O

O

--

공백 입력 불가

Port 검증 참고

호스트 IP 검증 참

호스트 IP 검증 참

공백 입력 불가

공백 입력 불가

숫자외 입력 불가

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

102/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

ok

Boolean

Example

라이선스(License)

/conf/func_license (type:JSON)

저장 장소: couchdb /appliance/func_license

GET

라이선스의 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

custom_name

String

고객 명

Explanation

Explanation

Required

--

--

Explanation

start_date

end_date

String

String

라이선스 시작 날짜. ISO 8601 형식("yyyy-MM-dd HH:mm:ss")

라이선스 만기 날짜. ISO 8601 형식("yyyy-MM-dd HH:mm:ss")

status

Number

라이선스 상태. license request 0, license success 1, license fail 2, license expired 3

webserver_limit Number

웹서버 제한

check_sum

String

체크썸

Example

/conf/wplicense_info

 Note: 비공개 webapi입니다

GET

기능 라이선스 (/sphere/.info/wp_license.cer) 파일 내용을 반환한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

Explanation

Required

--

--

Explanation

wp_license_cer

String

기능 라이선스 (/sphere/.info/wp_license.cer) 파일 내용

Example

/conf/license_agreement (type:JSON)

저장장소: couchdb /appliance/license_agreement file

license_agreement document와 데이타 형식 동일.

GET

최초 로그인시에 펜타 시큐 리티 약관 동의 정보를 조회한다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

103/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Response field

Data Type

Explanation

license_agreement

Boolean

최초 로그인시에 펜타 시큐 리티 약관 동의서 동의여부

Example

PUT

최초 로그인시에 펜타 시큐 리티 약관 동의 정보를 수정한다.

Request Parameter

Request
Parameter

Data Type

Explanation

Required

license_agreement

Boolean

최초 로그인시에 펜타 시큐 리티 약관 동의서 동의여부

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/alarm_license (type:JSON)

GET

라이선스 만료 알림 설정 정보를 가져옵니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Explanation

Required

--

--

Response field

Data Type

enable

Boolean

사용 여부

Explanation

pre_d_day

Number

알림 시작 일 수(만료일 기준으로 pre_d_day일 이전부터 알림)

day_interval

Number

알림 간격(일)

email_notification

Boolean

E-mail 알림 여부

Example

PUT

라이선스 만료 알림 설정 정보를 설정한다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

104/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

enable

pre_d_day

Boolean

Number

사용 여부

알림 시작 일 수(만료일 기준으로 pre_d_day일 이전부터 알림)

Explanation

Required

O

O

O

O

--

--

pre_d_day 보다

--

Explanation

day_interval

Number

알림 간격(일)

email_notification

Boolean

E-mail 알림 여부

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

리소스 알람

/conf/alarm_resource

저장 장소: couchdb /appliance/alarm_resource

GET

리소스의 알람 설정 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

Explanation

Required

resource_name

String

조회하고자 하는 리소스명 입력
resource_name = ["cpu", "memory", "disk"]

X

--

Example

Response fields

Response field

Data Type

Explanation

resource_name

Array

리소스명

resource_name["enable"]

Boolean

알람 활성화 여부

resource_name["usage_threshold"]

Number

사용율 임계치: 0 ~ 100(단위: %)

resource_name["max_num_of_occurs"] Number

발생 횟수 임계치(즉, 최대 연속 발생 횟수): 1 ~ ???(단위: 회)

resource_name["once_every_day"]

Boolean

하루에 한 번만 메일을 발송할 것인지 여부

Example

PUT

리소스 알람을 설정한다.

Request Parameter

Request Parameter

Data Type

Explanation

Required

resource_name

Array

리소스명

resource_name["enable"]

Boolean

알람 활성화 여부

resource_name["usage_threshold"]

Number

사용율 임계치: 0 ~ 100(단위: %)

resource_name["max_num_of_occurs"] Number

발생 횟수 임계치(즉, 최대 연속 발생 횟수): 1 ~ ???(단위: 회)

resource_name["once_every_day"]

Boolean

하루에 한 번만 메일을 발송할 것인지 여부

O

O

O

O

--

--

--

--

Example

Response fields

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

105/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

ok

Boolean

--

Example

/status/alarm_resource

저장 장소: couchdb /appliance/alarm_resource_status

GET

리소스의 알람 상태를 조회한다.

Request Parameter

Request
Parameter

Data Type

Explanation

Explanation

Required

resource_name

String

조회하고자 하는 리소스명 입력
resource_name = ["cpu", "memory", "disk"]

X

--

Example

Response fields

Response field

Data Type

Explanation

resource_name

Array

리소스명

resource_name["cur_num_of_occurs"] Number

현재까지 연속으로 발생한 횟수: 0 ~ max_num_of_occurs(단위: 회)

resource_name["last_send_time"]

String

마지막으로 알람을 보낸 시각: ISO 8601 형식("yyyy-MM-dd HH:mm:ss")

Example

PUT

리소스의 알람 상태를 업데이트한다.

Request Parameter

Request Parameter

Data Type

Explanation

Required

resource_name

Array

리소스명

resource_name["cur_num_of_occurs"] Number

현재까지 연속으로 발생한 횟수: 0 ~ max_num_of_occurs(단위: 회)

resource_name["last_send_time"]

String

마지막으로 알람을 보낸 시각: ISO 8601 형식("yyyy-MM-dd HH:mm:ss")

O

X

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

--

Example

업데이트(WAPPLES update)

/conf/update(type:JSON)

저장장소: couchdb /appliance/update

GET

업데이트 설정 정보를 조회한다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

106/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response field

Data Type

Explanation

업데이트 모드 설정

mode

Number

1 : 자동 업데이트 기능(true), 관리자 승인 후 업데이트(true) - 자동이지만, 사용자 동의 후 업데이트 모드 = 2 : 자동 업데이트 기능(f

0 - 자동 업데이트, 1- 관리자 승인 업데이트 2 - 수동 업데이트 모드 = 0 : 자동 업데이트 기능(true), 관리자 승인 후 업데이트(false

(false) - 수동으로 업데이트

server_ip[]

Array

업데이트 서버 ip 목록

connection_period Number

업데이트 주기 (초 단위)

Example

PUT

업데이트 설정 정보를 수정한다.

Request Parameter

Request
Parameter

Data Type

Explanation

Required

mode

Number

0 - 자동 업데이트, 1- 관리자 승인 업데이트 2 - 수동 업데이트

업데이트 모드 설정

server_ip[]

Array

업데이트 서버 ip 목록

connection_period Number

업데이트 주기 (초 단위)

X

O

X

중복 입력 불가

호스트 IP 검증 참

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/status/recently_update

GET

Explanation

업데이트되었을떄 업데이트한 버전 정보를 조회한다

업데이트가 되었을시에 데이터가 들어가져 있지만 사용자에게 업데이트 완료 팝업 알림을 주고난 이후에는 데이터가 사라진다

저장장소: /var/wapples/recently_update

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Response field

Data Type

Explanation

UPDATED_VERSION String

업데이트한 버전 정보

Example

/status/update

저장장소

/iupdater/stat/IUPDATER

/iupdater/stat/WAPPLES

/iupdater/stat/WAPPLES_PATTERN

GET

업데이트 상태정보(실행결과)를 조회한다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

107/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Policy - Policy(업데이트 정보를 가져오는 프로그램) 실행 결과 및 업데이트 버전의 존재 여부 , 업데이트를 계속 진행할지 여부

Downloader - 다운로더 실행 결과 및 다운로드 받고 있는 지 여부 (총 받을 파일 개수 : 다운 받은 개수)

Update - 업데이트 진행 사항 및 결과

STAT를 남기는 프로
세스

Request Parameter

Data Type

Explanation

POLICY_START

INQUERY_UPDATE

UPDATE_VERSION

POLICY_RESULT

String

String

String

String

DOWNLOAD_START

String

TOTAL_DOWNLOAD_FILE_NUM Number

CURRENT_DOWNLOAD_NUM

Number

DOWNLOAD_RESULT

UPDATE_START

UPDATE_COMPLETE_TIME

UPDATE_RESULT

String

String

String

String

Policy

Downloader

UPDATE

Example

DB & 백업(DB & Backup)

/conf/db_backup (type:JSON)

GET

백업 설정의 정보를 조회 합니다.

저장장소: couchdb appliance

db_backup document 데이타 형식 동일.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

POLICY 시작 시간 ISO 8601 형식("yyyy-MM-dd HH:mm:ss")

실행 결과 및 업데이트 버전의 존재 여부

NEED_TO_UPDATE, NEWEST_VERSION, HAVE_NO_LICENSE, FAIL

업데이트 버전(업데이트 버전이 있을때만 있음)

POLICY 결과

SUCCESS, FAIL

DOWNLOAD 시작시간

총 다운로드 파일 수

현재 다운로드 파일 수

DOWNLOAD 결과 SUCCESS, FAIL

UPDATE 시작 시간

UPDATE 완료 시간

UPDATE 결과

SUCCESS , ROLLBACK_SUCCESS , COMPLETE_FAIL

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

108/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response field

Data Type

Explanation

ftp{ip}

ftp{port}

ftp{path}

ftp{user}

ftp{passwd}

log_db{location}

String

ftp 서버 ip

Number

ftp 서버 port

String

String

String

String

ftp 서버 경로

ftp ID

ftp 비밀번호

로그 DB 백업위치. WAPPLES "local", SERVER "ftp"

log_db{auto_enable}

String

로그 DB 백업 설정 사용 여부. true, false

log_db{period}

conf_db{location}

String

String

로그 DB 백업주기

설정 DB 백업위치. WAPPLES "local", SERVER "ftp"

conf_db{auto_enable}

Boolean

설정 DB 백업 설정 사용 여부. true, false

conf_db{period}

String

설정 DB 백업주기

Example

PUT

백업설정의 정보를 수정 합니다.

저장장소: couchdb appliance

db_backup document에 "audit_source" 정보 추가 데이타 형식.

Request Parameter

Request Parameter

Data Type

Explanation

Required

ftp{ip}

ftp{port}

ftp{path}

ftp{user}

ftp{passwd}

String

ftp 서버 ip

Number

ftp 서버 port

String

String

String

ftp 서버 경로

ftp ID

ftp 비밀번호

log_db{immediately_backup}

Boolean

즉시 백업 여부 ( couch에 저장하는 값은 아님. )

log_db{location}

String

로그 DB 백업위치. WAPPLES "local", SERVER "ftp"

log_db{auto_enable}

Boolean

로그 DB 백업 설정 사용 여부

log_db{period}

String

로그 DB 백업주기

매 일 오후 2시 20 분의 경우: "20 14 * * *"

매 주 월요일, 목요일 오전 2시 20분의 경우: "20 2 * * 1,4"

(일:0, 월:1, 화:2, 수:3, 목:4, 금:5, 토:6) 매 월 5일 오후 2시 56분의 경우: "56 14 5 * *"

conf_db{immediately_backup}

Boolean

즉시 백업 여부 ( couch에 저장하는 값은 아님. )

conf_db{location}

String

설정 DB 백업위치. WAPPLES "local", SERVER "ftp"

conf_db{auto_enable}

Boolean

설정 DB 백업 설정 사용 여부

conf_db{period}

String

설정 DB 백업주기

audit_source

String

X

Example

호스트 IP 검증

Port 검증 참고

공백 입력 불

공백 입력 불

공백 입력 불

--

--

--

백업 주기를
하나이상 선택

--

--

--

백업 주기를
하나이상 선택

O

O

O

O

O

X

X

X

X

X

X

X

X

"GUI : ip". 실
행 주체(감사
로그에 기록하
기 위함)
(couch에 저장
하는 값은 아
님).

webapi는  위  정보중
/sphere/bin/msgbus_gateway
unix:path=/var/run/dbus/namsgbus.socket -n xxx.com -m db_backup '아래 정보' 이처럼, message_name 은 db_backup message body에 받은 데이타를 넣어서 넘겨주면 됩니다.

couch에  저장하지  말고,  msgbus로  데몬에  알려준다.  webapi에서는

immediately_backup관련정보는

-a

{
   "conf_db_immediately_backup" : True,
   "log_db_immediately_backup" : False,
   "audit_source" : "GUI : ip"
}

Response fields

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

109/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

ok

Boolean

Example

/conf/db_restore (type:JSON)

Explanation

:  없음.

저장소
-a
unix:path=/var/run/dbus/namsgbus.socket -n xxx.com -m run_db_restore '아래 정보' 이처럼, message_name 은 run_db_restore message body에 받은 데이타를 넣어서 넘겨주면
됩니다.

couch  에  저장되는  정보  아님.

"run_db_restore"  webapi에서는

/sphere/bin/msgbus_gateway

notify  msg_name

restore

:

PUT

전달받은 백업파일의 데이터로 restore합니다.

Request Parameter

Request
Parameter

Data Type

Explanation

Required

file_name[]

Array

restore 할 백업 파일명 목록

log_db_clear

Boolean

로그db초기화 설정

X

X

--

--

Example

Response fields

Response
field

Data Type

result

String

성공하면 ok, 실패하면 에러코드 반환

Example

Explanation

/conf/db_restore/stop (type:JSON)

저장소 : 없음. couch 에 저장되는 정보 아님.

notify msg_name restore : "stop_db_restore"
webapi에서는 /sphere/bin/msgbus_gateway -a unix:path=/var/run/dbus/namsgbus.socket -n xxx.com -m stop_db_restore

PUT

진행중이던 restore를 중단합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

Explanation

Required

--

--

Explanation

result

String

성공하면 ok, 실패하면 에러코드 반환

Example

/info/backup_file_list (type:JSON)

GET

저장소 : 없음.

대상 위치 : /sphere/wapples_backup

backup file 경로에 있는 파일 명들 중, wapples에서 백업된 것(확장자가 .wlb, .wcb 것)들을 조회합니다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

110/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Response
field

Data Type

file_name

String

백업 파일명

file_size

Number

백업 파일의 사이즈 (byte)

file_date

String

백업 날짜 ISO 8601 형식("yyyy-MM-dd HH:mm:ss timezone/city")

file_count

Number

백업 파일 개수

Example

Explanation

로그 DB 백업 파일 형태 : WAPPLES-LOG_DB-xxxxx.wlb.000 ( .000은 분할 압축 표시 )
설정 DB 백업 파일 형태 : WAPPLES-CONF_DB-xxxxx.wcb.000 ( .000은 분할 압축 표시 )

/info/backup_file_list/(file_name)(type:JSON)

저장소 : 없음.

대상 위치 : /sphere/wapples_backup

 Note: /sphere/wapples_backup dir 권한 777

DELETE

backup file 경로에 있는 특정한 파일을 삭제합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

--

--

--

Example

/status/restore (type:JSON)

GET

restore한 결과(진행상태)를 조회합니다.

저장장소: /var/wapples/restore_stat

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

111/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response field

Data Type

Explanation

conf_state

String

idle( 정지or완료등), doing(복구 진행중), finishing (정지 대기)

설정 DB 복구 상태.

log_state

String

idle( 정지or완료등), doing(복구 진행중), finishing (정지 대기)

로그 DB 복구 상태.

restore_files[name]

String

restore한 파일명

restore_files[start_time]

String

restore가 이루어진 시간. ISO 8601 형식("yyyy-MM-dd HH:mm:ss")

restore_files[end_time]

String

restore가 끝난 시간. ISO 8601 형식("yyyy-MM-dd HH:mm:ss")

restore_files[state]

String

restore 진행상태(결과). todo( 할것 ), doing(복구 진행중), done(완료)

Example

/file/transfer

 Note: download시 cpu, memory 사용으로 인해 최고 속도를 10MB/s으로 제한한다.

GET

db backup 파일이나 탐지로그파일을 download 합다.

query string으로 받고자하는 file의 name과 type을 전송한다.

Request Parameter

Request
Parameter

Data Type

name

type

Example

String

String

Response fields

Response
field

Data Type

--

--

--

Example

Explanation

Required

다운로드할 파일명

다운로드할 파일의 종류 "db_bakcup", "detection_log"

확장자 '.wlb','.wc
자리는 분할된 파

-

Explanation

POST

form에 form name을 'file'로 하고 file을 담고, form name을 'type'로 하고 file 종류를 담아 post로 전송한다.

지원되는 type은 "license", "db_bakcup", "report" 이다.

파일 전송이 정상적으로 완료 되면 각각 저장되어야 할 곳으로 옮겨진다.

Explanation

Required

파일경로. @/+파일경로

업로드할 파일의 정보. "license", "db_bakcup", "report"

확장자 '.wlb','.wc
자리는 분할된 파

--

Explanation

Request Parameter

Request
Parameter

Data Type

file

type

Example

String

String

Response fields

Response
field

Data Type

--

--

--

Example

보고서(Report)

/conf/report_config (type:JSON)

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

112/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

report_config document와 데이타 형식 동일.

GET

보고서 자동으로 E-mail 보내기 정보를 조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

Response field

Data Type

Explanation

time

String

메일 주기. cron time

quarterly_report

Boolean

분기별 보고서

semi_annual_report

Boolean

반기별 보고서

annual_report

Boolean

년별 보고서

String

String

String

메일 작성자

메일 제목 포멧

메일 내용 포멧

email_writer

email_subject

email_content

Example

PUT

보고서 자동으로 E-mail 보내기 정보를 수정합니다.

Request Parameter

Request
Parameter

Data Type

time

String

메일 주기. cron time

quarterly_report

Boolean

분기별 보고서

semi_annual_report

Boolean

반기별 보고서

annual_report

Boolean

년별 보고서

String

String

String

메일 작성자

메일 제목 포멧

메일 내용 포멧

email_writer

email_subject

email_content

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/report_form (type:JSON)

GET

보고서 E-mail 즉시 보내기 정보를 조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

--

공백 입력 불가

공백 입력 불가

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

113/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response field

Data Type

Explanation

uerid

email_writer

String

String

유저아이디. user doc_id

메일 작성자

email_subject

String

메일 제목 포멧

email_content

String

메일 내용 포멧

report_subject

String

보고서 제목

report_reception

String

보고서 수신처

report_writer

String

보고서 작성자

Example

POST

보고서 E-mail 즉시 보내기 정보를 추가합니다.

Request Parameter

Request
Parameter

Data Type

uerid

email_writer

String

String

유저아이디. user doc_id

메일 작성자

email_subject

String

메일 제목 포멧

email_content

String

메일 내용 포멧

report_subject

String

보고서 제목

report_reception

String

보고서 수신처

report_writer

String

보고서 작성자

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/report_form/(doc_id) (type:JSON)

GET

보고서 E-mail 즉시 보내기의 특정 정보를 조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

--

공백 입력 불가

공백 입력 불가

--

공백 입력 불가

--

--

Explanation

Explanation

Required

--

--

Response field

Data Type

Explanation

uerid

email_writer

String

String

유저아이디. user doc_id

메일 작성자

email_subject

String

메일 제목 포멧

email_content

String

메일 내용 포멧

report_subject

String

보고서 제목

report_reception

String

보고서 수신처

report_writer

String

보고서 작성자

Example

PUT

보고서 E-mail 즉시 보내기의 특정 정보를 수정합니다.

Request Parameter

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

114/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Required

X

O

O

X

O

X

X

--

공백 입력 불가

공백 입력 불가

--

공백 입력 불가

--

--

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

Explanation

Request
Parameter

Data Type

uerid

email_writer

String

String

유저아이디. user doc_id

메일 작성자

email_subject

String

메일 제목 포멧

email_content

String

메일 내용 포멧

report_subject

String

보고서 제목

report_reception

String

보고서 수신처

report_writer

String

보고서 작성자

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

DELETE

보고서 E-mail 즉시 보내기의 특정 정보를 삭제합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

ok

Boolean

Example

/conf/custom_report (type:JSON)

GET

정책, 웹사이트, 룰 선택 보고서 설정 정보를 요청합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

user_id

name

String

String

사용자 hash_id

설정 명

description

String

비고

Array

Array

Array

선택된 정책 id 목록

선택된 웹사이트 id 목록

선택된 룰 id 목록

policy

website

rule

Example

POST

정책, 웹사이트, 룰 선택 보고서 설정 정보를 추가합니다.

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

115/141

2020. 8. 7.

Request Parameter

WAPPLES Web API - Penta Security Wiki

사용자 hash_id

설정 명

비고

선택된 정책 id 목록

선택된 웹사이트 id 목록

선택된 룰 id 목록

Request
Parameter

Data Type

user_id

name

description

policy

website

rule

Example

String

String

String

Array

Array

Array

Response fields

Response
field

Data Type

ok

Boolean

Example

PUT

정책, 웹사이트, 룰 선택 보고서 설정 정보를 수정합니다.

Request Parameter

Request
Parameter

Data Type

user_id

name

description

policy

website

rule

Example

String

String

String

Array

Array

Array

사용자 hash_id

설정 명

비고

선택된 정책 id 목록

선택된 웹사이트 id 목록

선택된 룰 id 목록

Response fields

Response
field

Data Type

ok

Boolean

Example

memcached

/conf/cache (type:JSON)

 Note: 비공개 webapi입니다

delete

memcached에서 cache한 data를 전부 삭제합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Required

Explanation

Explanation

Required

--

--

--

--

--

--

--

--

--

--

--

--

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

116/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Response
field

Data Type

--

--

--

Example

/conf/cache/(key) (type:JSON)

 Note: 비공개 webapi입니다

delete

memcached에서 cache한 data중 key에 해당하는 것을 삭제함.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

--

--

--

Example

WAPPLES 정보

/info/sphere (type:JSON)

저장장소 : /sphere/id

GET

장비 id를 조회한다. (환경설정 첫화면에서 사용된다)

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response
field

Data Type

id

String

wapples 장비 id

Example

/info/version (type:JSON)

WAPPLES 장비의 각각의 버전 정보를 조회합니다.

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

Explanation

Explanation

Required

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

117/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Explanation

Required

--

--

Explanation

Response field

Data Type

kernel

util

ui

String

String

String

kernel 버전

util 버전

관리도구 버전

detection_engine

String

탐지엔진 버전

foundation

wapples

data

Example

String

String

String

foundation 버전

wapples 버전

/info/issac_key (type:JSON)

GET

Request Parameter

Request
Parameter

Data Type

--

--

--

Example

Response fields

Response field

Data Type

issac_private_key

String

issac 개인키

issac_public_key

String

issac 공개키

Example

4.1에서 "issac_publicKey.key","issac_privateKey.key" 경로가 수정됨.

/usr/penta_np/download => /sphere/conf

.

/

(점검필요) welcome.php

SignalSender

/msgbus/signal

Notify 형식

PUT

변경알림을 Wapples의 메세지버스에 전송합니다

Request Parameter

메세지명 종류

pls_check : pls 설정변경

pls_sync : pls 동기화 실행

rule_change : 룰 변경

webserver_change : 웹서버 변경

proxy_ip_change : 서비스 네트워크 변경

set_intrusion_log : 연동설정 변경

sims_change : sims 변경

set_email :smtp 변경

set_syslog : syslog 변경

set_license : 라이선스 변경

send_new_email : 이메일 전송

set_date : 시간설정변경

sync_date : 시간 동기화

save_config : 업데이트 설정 변경

update_initalize :업데이트 버전체크, 요청

wapples_new_update : 업데이트 실행

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

118/141

--

--

--

--

--

--

--

--

--

--

--

--

--

--

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Required

Request
Parameter

Data Type

type

String

"signal"(고정값)

sender_name

String

ex) "sender_name" : "com.penta.wapples.gui"

전송자(서비스 명)

message_name

String

메세지명.

message_body

String

메세지명이 "audit"(감사로그)일 때 사용

메세지 내용(Optional)

Example

Response fields

Response
field

Data Type

result

String

결과 ok

Example

audit message 형식

PUT

감사로그에 기록하기 위하여 전송합니다.

Request Parameter

O

O

O

X

Explanation

Request Parameter

Data Type

Explanation

Required

X

X

X

X

X

X

X

X

X

X

Explanation

type

String

"signal"(고정값)

sender_name

String

ex) "sender_name" : "com.penta.wapples.gui"

전송자(서비스 명)

message_name

String

"audit"

message_body{type}

String

"audit"(고정값)

message_body{value}
{source}

String

기록한 pc

message_body{value}
{type}

String

감사로그 번호

감사로그 종류 참고

message_body{value}
{info}[]

Array

감사로그에 기록될 body 목록

감사로그 항목별 내용 참고

message_body{value}
{msg_type}

String

메세지타입

감사로그 항목별 MSG_TYPE 필드 참고

String

감사로그 기록 시간

String

사용자가 남기는 comment

message_body{value}
{time}

message_body{value}
{comment}

Example

Response fields

Response
field

Data Type

result

String

결과 ok

Example

KT Resources

KT 전용 Resource별 URI 목록과 지원되는 method

v3.0R5

/webservers (type:XML)

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

119/141

2020. 8. 7.

KT 웹서버 목록.

req method

req body

설명

GET

POST

-

웹서버 목록 조회

새로운 웹서버 설정 웹서버 추가

WAPPLES Web API - Penta Security Wiki

status code

res body

설명

200 OK

웹서버 목록

GET method에 의해서 웹서버 목록을 조회.

201 Created

생성된 웹서버 설정 POST method에 의해서 웹서버가 생성.

400 Bad Request

409 Conflict

-

-

POST method에 전달된 XML 형식에 오류가 있음.

POST method에 전달된 설정 내용에 오류가 있음.

/webservers/id (type:XML)
KT id가 id인 웹서버 설정

req method

req body

설명

GET

PUT

-

웹서버 설정 조회

새로운 웹서버 설정 웹서버 설정 변경

DELETE

-

웹서버 삭제

status code

res body

설명

200 OK

200 OK

200 OK

400 Bad Request

404 Not Found

409 Conflict

현재 웹서버 설정

GET method에 의해서 웹서버 설정을 조회.

변경된 웹서버 설정 PUT method에 의해서 웹서버 설정이 변경됨.

-

-

-

-

DELETE method에 의해서 웹서버 설정이 삭제됨.

PUT method에 전달된 XML 형식에 오류가 있음.

요청된 URI에 해당하는 웹서버가 없음.

PUT method에 전달된 설정 내용에 오류가 있음.

/vhosts (type:XML)

KT 웹사이트 목록

req method

req body

설명

GET

POST

-

웹사이트 목록 조회

새로운 웹사이트 설정 웹사이트 추가

status code

res body

설명

200 OK

웹사이트 목록

GET method에 의해서 웹사이트 목록을 조회.

201 Created

생성된 웹사이트 설정 POST method에 의해서 웹사이트가 생성.

400 Bad Request

409 Conflict

-

-

POST method에 전달된 XML 형식에 오류가 있음.

POST method에 전달된 설정 내용에 오류가 있음.

/vhosts/id (type:XML)
KT id가 id인 웹사이트 설정

req method

req body

설명

GET

PUT

-

웹사이트 설정 조회

새로운 웹사이트 설정 웹사이트 설정 변경

DELETE

-

웹사이트 삭제

status code

res body

설명

200 OK

200 OK

200 OK

400 Bad Request

404 Not Found

409 Conflict

현재 웹사이트 설정

GET method에 의해서 웹사이트 설정을 조회.

변경된 웹사이트 설정 PUT method에 의해서 웹사이트 설정이 변경됨.

-

-

-

-

DELETE method에 의해서 웹사이트 설정이 삭제됨.

PUT method에 전달된 XML 형식에 오류가 있음.

요청된 URI에 해당하는 웹사이트가 없음.

PUT method에 전달된 설정 내용에 오류가 있음.

KT 전용 Resource 표현 형식

v3.0R5  Request body나 response body를 통해서 전달되는 Resource의 representation은 XML 형식을 사용하며, 포함되어야 하는 정보들은 다음과 같다.

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

120/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

웹서버 설정(class WebServer에 대응)

id: 웹서버 식별자이다. request일 경우에는 의미가 없다.

ip: 웹서버 IP이다.

port: 웹서버 port이다.

proxy_mode: {true|false} 중에서 선택한다.

proxy_address: proxy 설정이다.

ip: proxy IP이다.

port: proxy port이다.

ssl_mode: {disabled|ssl_true|ssl_term} 중에서 선택한다.

ssl_conf: SSL 설정이다.

server_cert: 웹서버 인증서이다. X.509 형식이다. encoding은 PEM 형식이다.

server_key: 웹서버 인증서에 대응하는 private key이다. encoding은 PEM 형식이다.

chain_cert: 추가로 필요한 체인 인증서이다. X.509 형식이다. encoding은 PEM 형식이다.

웹사이트 설정(class VirtualHost에 대응)

id: 웹사이트 식별자이다. request일 경우에는 의미가 없다.

hostname: 웹사이트의 hostname이다.

port: 웹사이트의 port 번호이다.

description: 웹사이트에 대한 설명이다.

policy_num: 보안 정책 번호. {0|1|2|3} 중에서 선택한다.

aliases: alias들의 목록이다. 각 alias는 hostname과 같은 형식이다.

hostname: alias이름

hostname: alias이름

...

XML Schema

XML Schema는 다음과 같으며, /webapi/wapples.xsd라는 URI를 통해서도 얻을 수 있도록 한다.

<?xml version="1.0"?>
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema">

<!-- basic types -->
<xs:attribute name="id" type="xs:integer"/>
<xs:element name="hostname" type="xs:string"/>
<xs:complexType name="ipv4address">
  <xs:sequence>
    <xs:element name="ip"/>
    <xs:element name="port"/>
  </xs:sequence>
</xs:complexType>
<xs:element name="ip" type="xs:string"/>
<xs:element name="port" type="xs:integer"/>
<xs:element name="proxy_mode" type="xs:boolean" default="false"/>
<xs:element name="ssl_mode">
  <xs:simpleType>
    <xs:restriction base="xs:string">
      <xs:enumeration value="disabled"/>
      <xs:enumeration value="ssl_thru"/>
      <xs:enumeration value="ssl_term"/>
    </xs:restriction>
  </xs:simpleType>
</xs:element>
<xs:element name="server_cert" type="xs:string"/> <!-- -->
<xs:element name="server_key" type="xs:string"/> <!-- -->
<xs:element name="chain_cert" type="xs:string"/> <!-- -->

<!-- main object types -->
<xs:element name="webserver">
  <xs:complexType>
    <xs:sequence>
      <xs:element name="server_address" type="ipv4address"/>
      <xs:element name="proxy_mode"/>
      <xs:element name="proxy_address" type="ipv4address" minOccurs="0"/>
      <xs:element name="ssl_mode"/>
      <xs:element name="ssl_conf" minOccurs="0">
        <xs:complexType>
          <xs:sequence>
            <xs:element name="server_cert"/>
            <xs:element name="server_key"/>
            <xs:element name="chain_cert"/>
          </xs:sequence>
        </xs:complexType>
      </xs:element>
    </xs:sequence>
    <xs:attribute name="id"/>
  </xs:complexType>
</xs:element>
<xs:element name="vhost">
  <xs:complexType>
    <xs:sequence>
      <xs:element name="hostname"/>
      <xs:element name="port"/>
      <xs:element name="description" type="xs:string"/>
      <xs:element name="policy_num" type="xs:integer"/>
      <xs:element name="aliases" minOccurs="0">
        <xs:complexType>
          <xs:sequence>
            <xs:element name="hostname" maxOccurs="unbounded"/>
          </xs:sequence>
        </xs:complexType>
      </xs:element>
    </xs:sequence>
    <xs:attribute name="id"/>
  </xs:complexType>

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

121/141

WAPPLES Web API - Penta Security Wiki

2020. 8. 7.

</xs:element>

<!-- collection types -->
<xs:element name="webservers">
  <xs:complexType>
    <xs:sequence>
      <xs:element name="webserver" maxOccurs="unbounded"/>
    </xs:sequence>
  </xs:complexType>
</xs:element>
<xs:element name="vhosts">
  <xs:complexType>
    <xs:sequence>
      <xs:element name="vhost" maxOccurs="unbounded"/>
    </xs:sequence>
  </xs:complexType>
</xs:element>

<!-- end of schema -->
</xs:schema>

XML Sample

<!-- webserver object sample -->
<webserber>
  <server_address>
    <ip>192.168.22.32</ip>
    <port>80</port>
  </server_address>
  <proxy_mode>true</proxy_mode>
  <proxy_address>
    <ip>214.124.112.23</ip>
    <port>80</port>
  </proxy_address>
  <ssl_mode>ssl_thru<ssl_mode>
  <ssl_conf>
    <server_cert>-----BEGIN CERTIFICATE-----MIIDljCCAn6gA.....(생략)</server_cert>
    <server_key>----BEGIN RSA PRIVATE KEY-----MIIEogIBAAK.....(생략)</server_key>
    <chain_cert></chain_cert>
  </ssl_conf>
  <id>1</id>
</webserver>

응답 오류 (Errors)

Error msg format

{
     "result_code" : "RES12345",
     "reason_code" : "REA12345",
     "result_msg" : "...",
     "reason_msg" : "..."
}

Example

Result code

result_code : webapi에 요청한 것에 대한 결과이다.

 result_code 는 RES + '5자리 숫자'

RES00001 : 인증실패

RES00002 : 인증필요

RES00003 : 잘못된 세션

RES00004 : 잘못된 Client

RES00005 : 인증되지 않은 사용자

RES00006 : 인증되지 않은 그룹

RES00007 : 잘못된 요청

RES00008 : ??? 정보를 가져올 수 없음

RES00009 : ??? 설정을 실패하였음

RES00010 : ??? 삭제을 실패하였음

RES00011 : 접속 정보가 없음

RES00012 : 파일 업로드 실패

RES00013 : 허용되지 않는 method

RES00014 : Cross Site Scripting공격 시도

RES00015 : 파일 다운로드 실패

Reason code

result_code : webapi에 요청한 것이 실패한 이유를 나타낸다.

 reason_code는 REA + '5자리 숫자'

REA00001 : ID or Password 누락

REA00002 : 존재하지 않는 ID

REA00003 : Password 틀림

[펼치기]

REA00004 : 인증은 성공하였지만, 서버의 SESSION정보를 남기지 못함

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

122/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

REA00005 : 설정 DB Restore 중임

REA00006 : doc id 누락

REA00007 : file 없음

REA00008 : file이 비어 있음

REA00009 : file 쓰기 실패

REA00010 : system 오류

REA00011 : data가 DB에 없음

REA00012 : body data가 없음

REA00013 : network interface가 없음

REA00014 : 요청시 filname, path, stream 누락

REA00015 : path가 directory가 아님 (file path의 마지막 문자가 '/'이 아님)

REA00016 : 등록된 session filter 가 하나도 없음

REA00017 : 찾는 session filter 가 없음

REA00018 : filter setting 실패 or 파일 업음

REA00019 : couch db에 pls doc에 ip, id, pwd가 없음(설정된 pls 정보가 없음)

REA00020 : '/sphere/pls_missing_log/' 하위에 상대방장비 id로 된 dir이 없음

REA00021 : email_id 가 없음

REA00022 : 해당 모듈이 존재하지 않음

REA00023 : hostname, date가 전달되지 않음

REA00024 : 날짜가 형식에 맞지 않음

REA00025 : 읽기 전용 데이터

REA00026 : NPRD 오류

REA00027 : 백업 Dir이 존재하지 않음

REA00028 : 현재 사용중인 Document를 삭제할 수 없음

REA00029 : 상대방 장비에 연결 할 수 없음

REA00030 : 상대방 장비의 id를 알아오지 못함

REA00031 : 쿼리 실패

REA00032 : hidden 또는 sequence 누락

REA00033 : sequence 누락

REA00034 : audit type의 짝이 맞지 않음

REA00035 : 요청한 파일을 찾을 수 없음

REA00036 : 지원하지 않은 file type

REA00037 : 파일이 POST로 전송되지 않았음

Response Message

(변경안...)

Format

{
     "Code" : "XXYYY",
     "Message" : "...",
     "Cause" : "..."
}

Example

Code

[펼치기]

webapi 요청에 대한 결과를 다섯자리의 숫자로 표현한 것이다. 처음 세자리는 WebAPI 수행 결과에 대해 종류별로 분류한 코드 값이며, 다음 두자리는 결과의 원인에 대해 번호를 매겨 놓
은 것인다.

 '카테고리 코드(3자리 숫자)' + '세부 항목 코드(2자리 숫자)'

Category Code

두자리 코드와 메세지로 구성되어 있다.

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

123/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Category Code

Message

설명

000

001

002

003

004

005

006

007

008

009

010

011

012

013

014

015

016

017

018

019

020

021

Success

Authentication failed

Authentication required

Invalid session

Invalid client

Unauthorized user

Unauthorized group

Bad request

인증실패

인증필요

잘못된 세션

잘못된 Client

인증되지 않은 사용자

인증되지 않은 그룹

잘못된 요청

Could not get information

정보를 가져올 수 없음

Failed to set

Failed to delete

No connection information

Failed to upload file

Method not allowed

설정을 실패하였음

삭제을 실패하였음

접속 정보가 없음

파일 업로드 실패

허용되지 않는 method

Attempted CSS attacks

CSS 공격 시도

Failed to download file

파일 다운로드 실패

Intrusionlog export failed

Intrusionlog export 실패

Invalid IP

잘못된 IP

Maximum number of DNS servers exceeded

dns 설정 개수 초과

Session is locked

Database Error

session 잠김

Unauthorized function

인증되지 않은 기능

Cause code

카테고리로 분류된 결과의 구체적인 원인을 의미하며, Cause 메세지를 포함한다.

000 : Success

001 : Authentication failed

FullCode

Cause Code

Cause

설명

00101

00102

00103

00104

00105

00106

00107

01

02

03

04

05

06

07

ID or password missing

ID or Password 누락

ID not found

존재하지 않는 ID

{0} times wrong password

x번 Password 틀림

Failed to make session

인증은 성공하였지만 서버의 SESSION정보를 남기지 못함

Restoring configuration DB 설정 DB Restore 중임

User license date expired

계정 license date가 expire 됨.

It is not control ip

계정의 접속 불가능 ip에서 접속시도

002 : Authentication required

003 : Invalid session

004 : Invalid client

005 : Unauthorized user

006 : Unauthorized group

007 : Bad request

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

124/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

FullCode

Cause Code

Cause

설명

00701

00702

00703

00704

00705

00706

00707

00708

01

02

03

04

05

06

07

08

Document ID missing

Body data missing

PLS info not found

Invalid date format

doc id 누락

body data가 없음

couch db에 pls doc에 ip, id, pwd가 없음(설정된 pls 정보가 없음)

날짜가 형식에 맞지 않음

Hidden or sequence field missing

hidden 또는 sequence 누락

Sequence missing

sequence 누락

Audit types do not match

audit type의 짝이 맞지 않음

stime or etime or get_count parameter missing

stime 혹은 etime get_count이 없습니다.

008 : Could not get information

FullCode

Cause Code

Cause

설명

00801

00802

00803

00804

00805

00806

00807

00808

00809

00810

00811

00812

00813

00814

00815

00816

00817

00818

00819

01

02

03

04

05

06

07

08

09

10

11

12

13

14

15

16

17

18

19

File does not exist

System error

file 없음

system 오류

Data does not exist in the DB

data가 DB에 없음

No session filter

등록된 session filter 가 하나도 없음

Session filter not found

찾는 session filter 가 없음

No info directory for peer WAPPLES

/sphere/pls_missing_log/' 하위에 상대방장비 id로 된 dir이 없음

Email ID missing

email_id 가 없음

The module does not exist

해당 모듈이 존재하지 않음

Hostname or date is missing

hostname date가 전달되지 않음

Backup directory does not exist

Could not connect to peer WAPPLES

상대방 장비에 연결 할 수 없음

Could not get the ID of peer WAPPLES 상대방 장비의 id를 알아오지 못함

Query failed

쿼리 실패

Network interface does not exist

network interface가 존재하지 않습니다.

Website health log does not exist

Website Health Log가 존재하지 않음

Websites do not exist

Websites가 존재하지 않음

No websites enabled to check health

health check가 enable된 website가 없습니다.

Setting route table

Setting network_interface

009 : Failed to set

FullCode

Cause Code

Cause

설명

00901

00902

00903

00904

00905

01

02

03

04

05

File does not exist

file 없음

Failed to write file

file 쓰기 실패

System error

system 오류

Read only data

읽기 전용 데이터

NPRD Error

NPRD 오류

010 : Failed to delete

FullCode

Cause Code

Cause

설명

01001

01002

01003

01

02

03

Session filter not found

찾는 session filter 가 없음

Cannot delete document because it is currently in use

The cache does not exist

cache가 존재하지않음

011 : No connection information

012 : Failed to upload file

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

125/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

FullCode

Cause Code

Cause

설명

01201

01202

01203

01204

01

02

03

04

Filname or path or stream missing

요청시 filname path stream 누락

Requested file not found

요청한 파일을 찾을 수 없음

File was not uploaded via HTTP POST 파일이 POST로 전송되지 않았음

Invalid upload File

upload 할 수 없는 file

013 : Method not allowed

014 : Attempted CSS attacks

015 : Failed to download file

FullCode

Cause Code

Cause

설명

01501

01

Requested file not found 요청한 파일을 찾을 수 없음

016 : Intrusionlog export failed

017 : Invalid IP

018 : Maximum number of DNS servers exceeded

019 : Session is locked

FullCode

Cause Code

Cause

설명

01901

01

{0} times wrong password

Password 오류

020 : Database Error

FullCode

Cause Code

Cause

설명

02001

02002

01

02

already exist database name

database가 존재 하지 않음

Failed to import the database

database import 실패

021 : Unauthorized function

검증 규칙

Port 검증

Number

1

2

3.

공백 입력 불가

숫자외 입력 불가

범위 0~65535

호스트 IP 검증

Number

[IP v4

Explanation

Explanation

닷넷에서 제공하는 IPAddress.Parse 메소드를 사용하여 검증

[[1] (http://msdn.microsoft.com/ko-kr/library/system.net.ipaddress.parse(v=vs.110).aspx%7C링크)]

IP v6

IPv6 주소 표현을 따름 [[2] (https://ko.wikipedia.org/wiki/IPv6#.EC.A3.BC.EC.86.8C_.ED.91.9C.ED.98.84%7C링크)]

1

2

AbsPath

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

126/141

2020. 8. 7.

Number

WAPPLES Web API - Penta Security Wiki

Explanation

RFC-3986 URI component: path

1

[[3] (https://tools.ietf.org/html/rfc3986%7C링크)]

Netmask

Number

1. 255.255.255.[255|254|252|248|240|224|192|128|0]

2. 255.255.[255|254|252|248|240|224|192| 28|0].0

3. 255.[255|254|252|248|240|224|192|128|0].0.0

4.[255|254|252|248|240|224|192|128|0].0.0.0

1

1~4의 유형 중 하나라도 만족하면 True

[ ]:[ ] 안의 값 중 하나가 올 수 있다.

Explanation

정규식:

@"^(((255\.){3}(255|254|252|248|240|224|192|128|0+))|((255\.){2}(255|254|252|248|240|224|192|128|0+)\.0)|((255\.)(255|254|252|248|240

((255|254|252|248|240|224|192|128|0+)(\.0+){3}))$"

도메인 검증

Number

Explanation

첫 글자는 항상 영소대문자, 숫자로 시작

다음 글자부터는 영소대문자, 숫자가 0~61 개 올 수 있다.

1

그 후 dot(.)이 하나 온다.

dot(.) 뒤에는 영소대문자가 2~6개 올 수 있다.

정규식: @"^([a-zA-Z0-9]([a-zA-Z0-9\-]{0,61}[a-zA-Z0-9])?\.)+[a-zA-Z]{2,6}$"

URL

IP 검증과 호스트 검증은 둘 중에 하나라도 통과하면 True

Number

Explanation

1

2

3

4.

IP 검증

Validation 단락 IP 항목 참고

도메인 검증

도메인 검증 단락 도메인 항목 참고

포트 검증

Validation Port 검증 항목 참고

AbsPath 검증

Validation AbsPath 항목 참고

이메일 검증

Number

1

2

3

4

전화번호 검증

Number

1

호스트명 검증

'@'가 하나만 있는지 없는지 확인. 없거나 하나 이상이면 오류메세지 출력

'@'뒤에 문자가 있는지 확인 없으면 오류메세지 출력

'.'이 잘 있는지 확인 없으면 오류메세지 출력

'.' 뒤에 문자가 있는지 확인 없으면 오류메세지 출력

정규식을 사용하여 검증

@"^\d{1,3}-\d{3,4}-\d{4}

ex) 000-0000-0000 000-000-0000

Explanation

Explanation

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

127/141

2020. 8. 7.

Number

WAPPLES Web API - Penta Security Wiki

Explanation

1

2

3

4

공백 및 중복 입력 불가

길이 64자 이내

프로토콜은 입력하지 않음

IP 검증호스트 IP 검증 참고

룰 별 Param (사용자 정의 입력값)

Buffer Overflow

Request
Parameter

Data Type

key_len

uri_len

header_len

String

String

String

키 길이

URL 길이

헤더 길이

Explanation

Required

0~129

0~2048

0~100000

Cookie Poisoning

Request
Parameter

Data Type

detect_modified

String

변조된 쿠키 탐지 여부

detect_added

String

클라이언트에서 추가된 쿠키 탐지 여부

ignored_list

Array

탐지 예외 쿠키 목록

Explanation

Required

V

--

--

O

개수 총 500개 이하

';', ',', ' '(세미콜론, 쉼

Cross Site Scripting

Request
Parameter

Data Type

tag

String

HTML 태그 필터 목록

pattern

Array

문자열 필터 목록

Directory Listing

Request
Parameter

Data Type

--

--

--

Directory Traversal

Request
Parameter

Data Type

Explanation

Required

V

입력개수가 40개 이하

길이 2~40

입력개수가 40개 이하

길이 2~40

Explanation

Required

--

--

Explanation

Required

mode

String

탐지 조건 확장 여부

체크시에는 '../'에서 './'까지 탐지 조건이 확장

"0" 탐지 조건 확장하지 않음 "1" 탐지 조건 확장

--

Error Handling

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

128/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

Explanation

Required

V

errorHandling

Array

차단할 에러코드 목록

공백 및 중복 입력 불

개수 500 개 이하

숫자외 입력 불가

에러코드의  범위

400~417, 500~505)

patterns

Array

패턴 목록

--

--

Explanation

Required

V

Extension Filtering

Request
Parameter

Data Type

extension_list

String

확장자 목록

File Upload

Request
Parameter

Data Type

공백 및 중복 입력 불

개수 200 개 이하

크기 총 1800 바이트

--

공백 입력 불가

공백 입력 불가

파일  확장자와  MIM

록되어  있는  파일

복 검사

MIME  Type이  ALL

복체크

--

--

Explanation

Required

file_type_list

Array

{"file_type_list":[{"extension":"jpg","mime_type":"ALL","howto_mime":"0"},

{"extension":"txt","mime_type":"ALL","howto_mime":"0"}]

파일 확장자 목록

file_type_list[]
[extension]

String

확장자

file_type_list[]
[mime_type]

String

MIME Type

file_type_list[]
[howto_mime]

String

MIME 검색

allow

String

허용 여부

"0" 입력 불가 "1" 허용

업로드 파일 크기 제한

fileSize

String

0 일 경우 업로드 파일 크기 제한을 두지 않음

--

0~100

fileSizeDetect

String

--

Include Injection

Request
Parameter

Data Type

allow_url_list

Array

허용 호스트 목록

allow

String

허용 여부

"0" 입력 불가

"1" 허용

Input Content Filtering

Explanation

Required

V

입력값의 개수가 100

총 2400바이트 이하

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

129/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

변환 목록

Explanation

Required

change

Array

{"change":[{"pattern":"fff","replace":"gf","encoding":"65001"},

{"pattern":"/n","replace":"/nh","encoding":"65001"}]}

--

공백 입력 불가

문자 길이 100 이하

사용자가  입력한  패

등록되어있는  패턴

중복체크 (하나라도

공백 입력 불가

100 이하

--

--

--

Explanation

Required

change[]
[pattern]

String

패턴

change[]
[replace]

change[]
[encoding]

String

변환값

String

인코딩

Invalid HTTP

Request
Parameter

Data Type

allowHttpProxy

String

allowEmptyHost

String

HTTP 프록시 허용 여부

"0" 입력 불가

"1" 허용

Emyty 호스트 허용 여부

"0" 입력 불가

"1" 허용

Invalid URL

Request
Parameter

Data Type

--

--

--

IP Filtering

Request
Parameter

Data Type

Explanation

Required

--

--

Explanation

Required

V

ip

Array

아이피 목록

country

Array

include

String

"0" 목록에 있는 국가, IP "1" 목록에 없는 국가, IP

포함 여부

Parameter Tampering

Request Parameter

Data Type

Explanation

Required

detect_modified

String

detect_added_deleted

String

변조된 Hidden 필드 탐지 여부

"0" 탐지하지 않음

"1" 탐지

추가/삭제된 파라미터 탐지 여부

"0" 탐지하지 않음

"1" 탐지

validate_range

String

"0" 탐지하지 않음

"1" 탐지

최대/최소 값이 지정된 input 값의 유효성 탐지 여부

Privacy File Filtering

중복 입력 불가

호스트 IP 검증 참고

국가 코드

--

--

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

130/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Required

V

Request
Parameter

Data Type

download

String

upload

String

address

String

다운로드 탐지 설정

"0" 탐지안함

"1" 탐지함

업로드 탐지 설정

"0" 탐지안함

"1" 탐지함

주소 탐지 설정

"0" 탐지안함

"1" 탐지함

busi

String

사업자 등록 번호 탐지 설정

"0" 탐지안함

"1" 탐지함

card

String

corp

String

email

String

카드 번호 탐지 설정

"0" 탐지안함

"1" 탐지함

법인 번호 탐지 설정

"0" 탐지안함

"1" 탐지함

이메일 탐지 설정

"0" 탐지안함

"1" 탐지함

passport

String

기본값 0

phone

String

ko_id

String

전화번호 탐지 설정

"0" 탐지안함

"1" 탐지함

국가별 탐지 여부(한국)

"0" 탐지안함

"1" 탐지함

ko_id_space

String

"0" 허용안함

"1" 허용

국가별 가운데 공백 허용 여부(한국)

sg_id

String

국가별 탐지 여부(싱가포르)

"0" 탐지안함

"1" 탐지함

국가별 가운데 공백 허용 여부(싱가포르)

sg_id_space

String

"0" 허용안함

"1" 허용

th_id

String

국가별 탐지 여부(태국)

"0" 탐지안함

"1" 탐지함

th_id_spcae

String

"0" 허용안함

"1" 허용

국가별 가운데 공백 허용 여부(태국)

cn_id

String

국가별 탐지 여부(중국)

"0" 탐지안함

"1" 탐지함

cn_id_space

String

"0" 허용안함

"1" 허용

국가별 가운데 공백 허용 여부(중국)

tw_id

String

국가별 탐지 여부(대만)

--

--

--

--

--

--

--

--

--

--

--

--

--

--

--

--

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

131/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

"0" 탐지안함

"1" 탐지함

국가별 가운데 공백 허용 여부(대만)

tw_id_space

String

"0" 허용안함

"1" 허용

my_id

String

국가별 탐지 여부(말레이시아)

"0" 탐지안함

"1" 탐지함

국가별 가운데 공백 허용 여부(말레이시아)

my_id_space

String

"0" 허용안함

"1" 허용

au_id

String

국가별 탐지 여부(호주)

"0" 탐지안함

"1" 탐지함

au_id_space

String

"0" 허용안함

"1" 허용

국가별 가운데 공백 허용 여부(호주)

jp_id

String

국가별 탐지 여부(일본)

"0" 탐지안함

"1" 탐지함

jp_id_space

String

"0" 허용안함

"1" 허용

국가별 가운데 공백 허용 여부(일본)

custom

String

사용자 정의 탐지 여부

"0" 탐지안함

"1" 탐지함

custom_number

Array

ex) 000-00-0000

사용자 정의 탐지 필터 목록

Privacy Input Filtering

--

--

--

--

--

--

--

--

공백 및 중복 입력 불

'-'가 필수 포함

'-'로 시작하거나 끝낼

0이 연속하여 최대 9

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

132/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Required

V

Request
Parameter

Data Type

download

String

upload

String

address

String

다운로드 탐지 설정

"0" 탐지안함

"1" 탐지함

업로드 탐지 설정

"0" 탐지안함

"1" 탐지

주소 탐지 설정

"0" 탐지안함

"1" 탐지함

busi

String

사업자 등록 번호 탐지 설정

"0" 탐지안함

"1" 탐지함

card

String

corp

String

email

String

카드 번호 탐지 설정

"0" 탐지안함

"1" 탐지함

법인 번호 탐지 설정

"0" 탐지안함

"1" 탐지함

이메일 탐지 설정

"0" 탐지안함

"1" 탐

passport

String

기본값 0

phone

String

ko_id

String

전화번호 탐지 설정

"0" 탐지안함

"1" 탐지함

국가별 탐지 여부(한국)

"0" 탐지안함

"1" 탐지함

ko_id_space

String

"0" 허용안함

"1" 허용

국가별 가운데 공백 허용 여부(한국)

sg_id

String

국가별 탐지 여부(싱가포르)

"0" 탐지안함

"1" 탐지함

국가별 가운데 공백 허용 여부(싱가포르)

sg_id_space

String

"0" 허용안함

"1" 허용

th_id

String

국가별 탐지 여부(태국)

"0" 탐지안함

"1" 탐지함

th_id_spcae

String

"0" 허용안함

"1" 허용

국가별 가운데 공백 허용 여부(태국)

cn_id

String

국가별 탐지 여부(중국)

"0" 탐지안함

"1" 탐지함

cn_id_space

String

"0" 허용안함

"1" 허용

국가별 가운데 공백 허용 여부(중국)

tw_id

String

국가별 탐지 여부(대만)

--

--

--

--

--

--

--

--

--

--

--

--

--

--

--

--

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

133/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

"0" 탐지안함

"1" 탐지함

국가별 가운데 공백 허용 여부(대만)

tw_id_space

String

"0" 허용안함

"1" 허용

my_id

String

국가별 탐지 여부(말레이시아)

"0" 탐지안함

"1" 탐지함

국가별 가운데 공백 허용 여부(말레이시아)

my_id_space

String

"0" 허용안함

"1" 허용

au_id

String

국가별 탐지 여부(호주)

"0" 탐지안함

"1" 탐지함

au_id_space

String

"0" 허용안함

"1" 허용

국가별 가운데 공백 허용 여부(호주)

jp_id

String

국가별 탐지 여부(일본)

"0" 탐지안함

"1" 탐지함

jp_id_space

String

"0" 허용안함

"1" 허용

국가별 가운데 공백 허용 여부(일본)

custom

String

사용자 정의 탐지 여부(한국)

"0" 탐지안함

"1" 탐지함

custom_number

Array

ex) 000-00-0000

사용자 정의 탐지 필터 목록

Privacy Output Filtering

--

--

--

--

--

--

--

--

X

공백 및 중복 입력 불

'-'가 필수 포함

'-'로 시작하거나 끝낼

0이 연속하여 최대 9

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

134/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Explanation

Required

V

Request
Parameter

Data Type

download

String

upload

String

address

String

다운로드 탐지 설정

"0" 탐지안함

"1" 탐지함

업로드 탐지 설정

"0" 탐지안함

"1" 탐지함

주소 탐지 설정

"0" 탐지안함

"1" 탐지함

busi

String

사업자 등록 번호 탐지 설정

"0" 탐지안함

"1" 탐지함

card

String

corp

String

email

String

카드 번호 탐지 설정

"0" 탐지안함

"1" 탐지함

법인 번호 탐지 설정

"0" 탐지안함

"1" 탐지함

이메일 탐지 설정

"0" 탐지안함

"1" 탐지함

passport

String

기본값 0

phone

String

ko_id

String

전화번호 탐지 설정

"0" 탐지안함

"1" 탐지함

국가별 탐지 여부(한국)

"0" 탐지안함

"1" 탐지함

ko_id_space

String

"0" 허용안함

"1" 허용

국가별 가운데 공백 허용 여부(한국)

sg_id

String

국가별 탐지 여부(싱가포르)

"0" 탐지안함

"1" 탐지함

국가별 가운데 공백 허용 여부(싱가포르)

sg_id_space

String

"0" 허용안함

"1" 허용

th_id

String

국가별 탐지 여부(태국)

"0" 탐지안함

"1" 탐지함

th_id_spcae

String

"0" 허용안함

"1" 허용

국가별 가운데 공백 허용 여부(태국)

cn_id

String

국가별 탐지 여부(중국)

"0" 탐지안함

"1" 탐지함

cn_id_space

String

"0" 허용안함

"1" 허용

국가별 가운데 공백 허용 여부(중국)

tw_id

String

국가별 탐지 여부(대만)

--

--

--

--

--

--

--

--

--

--

--

--

--

--

--

--

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

135/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

"0" 탐지안함

"1" 탐지함

국가별 가운데 공백 허용 여부(대만)

tw_id_space

String

"0" 허용안함

"1" 허용

my_id

String

국가별 탐지 여부(말레이시아)

"0" 탐지안함

"1" 탐지함

국가별 가운데 공백 허용 여부(말레이시아)

my_id_space

String

"0" 허용안함

"1" 허용

au_id

String

국가별 탐지 여부(호주)

"0" 탐지안함

"1" 탐지함

au_id_space

String

"0" 허용안함

"1" 허용

국가별 가운데 공백 허용 여부(호주)

jp_id

String

국가별 탐지 여부(일본)

"0" 탐지안함

"1" 탐지함

jp_id_space

String

"0" 허용안함

"1" 허용

국가별 가운데 공백 허용 여부(일본)

custom

String

사용자 정의 탐지 여부(한국)

"0" 탐지안함

"1" 탐지함

custom_number

Array

ex) 000-00-0000

사용자 정의 탐지 필터 목록

Request Header Filtering

--

--

--

--

--

--

--

--

공백 및 중복 입력 불

'-'가 필수 포함

'-'로 시작하거나 끝낼

0이 연속하여 최대 9

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

136/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

필터링 목록

Explanation

Required

Array

Array

{"header_name":"If-Unmodified-Since","header_only":"0","header_mode":"1","values":

--

--

[{"header_name":"User-Agent","header_only":"1","header_mode":"0","values":[]},

[{"name":"fff","mode":"0","match":"0"}]}]

header_name

header_name

String

Control, Connection, Content-Encdoing, Content-Language, Content-Length

헤더이름 필수 선택

Accpet,  Accept-Charset,  Accept-Encoding,  Accept-Language,  Allow,  Authorization,  Cache-

Content-Type, ETag, Expires, Host, If-Match, If-Modified-Since, If-None-Match, If-Range, If-

Unmodified-Since, Last-Modified, Max-Forwards, Rferer, User-Agent

header_only

String

header_mode

String

차단 설정

header_only "1" Header_mode "0" 모두 허용

header_only "1" Header_mode "1" 모두 차단

header_only "0" Header_mode "1" 개별 차단

차단 설정

header_only "1" Header_mode "0" 모두 허용

header_only "1" Header_mode "1" 모두 차단

header_only "0" Header_mode "1" 개별 차단

values

Array

[{"name":"d","mode":"0","match":"0"}]}]

내용

values[][name]

String

이름

values[][mode]

String

차단여부

"0" 차단

"1" 차단하지 않음

values[][match]

String

필터링 방식

헤더에 개별로 등록
나, 모두 허용은 등록

헤더에 모두 차단이

되어 있다면 따로 개

헤더에 개별로 등록
나, 모두 허용은 등록

헤더에 모두 차단이

되어 있다면 따로 개

공백 및 중복 입력

--

--

"0" 포함

"1" 일치

Request Method Filtering

Request
Parameter

Data Type

method_list

Array

메소드 리스트

allow

String

"0" 요청 허용 안함 "1" 요청 허용함

요청 허용 여부

Response Header Filtering

Request
Parameter

Data Type

header_list

Array

헤더 리스트

allow

String

"0" 요청 허용 안함 "1" 요청 허용함

요청 허용 여부

SQL Injection

Explanation

Required

V

공백 및 중복 입력 불

입력값 100개 이하

총 800바이트 이하

--

Explanation

Required

V

공백 및 중복 입력 불

입력값 100개 이하

총 800바이트 이하

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

137/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

keyword_check

String

strict_check

String

mode_mysql

String

mode_split

String

키워드 탐지 여부

"1" 탐지

"0" 탐지하지 않음

엄격한 탐지 여부

"1" 탐지

"0" 탐지하지 않음

mysql 주석 확장 여부

"1" 확장

"0" 확장하지 않음

쿼리문 분할 여부

"1" 분할

"0" 분할하지 않음

Stealth Commanding

Request
Parameter

Data Type

param[tag]

Array

태그 필터

param[pattern]

Array

문자열 필터

param[mode]

String

태그 자동 변환 여부

param[img]

String

이미지 태그 탐지 여부

0 탐지하지 않음

1 잘못된 이미지 태그 탐지

2 외부 경로의 이미지 태그 탐지

Suspicious Access

Explanation

Required

--

--

--

--

Explanation

Required

V

--

--

중복 입력 불가

입력 개수 40개 이하

입력 길이 2~40자

중복 입력 불가

입력 개수 40개 이하

입력 길이 2~40자

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

138/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request Parameter

Data Type

Explanation

Required

validate_user_agent

String

"0" 검증안함 "1" 검증

클라이언트 유저 에이전트 검증 여부

validate_cookie

String

클라이언트 Cookie 여부

"0" 검증안함 "1" 검증

Cookie 만기 시간 (단위: 시간)

expire_hour

String

기본 "24" (24 시간)

bot_user_agent

String

"0" 미설정 "1" 설정

탐지 예외 조건 Bot User-Agent 설정 여부

bot_ip

String

"0" 미설정 "1" 설정

탐지 예외 조건 BotIP 설정 여부

bot_from

String

"0" 미설정 "1" 설정

탐지 예외 조건 Bot From 설정 여부

parameter

String

"0" 미설정 "1" 설정

탐지 예외 조건 Parameter 설정 여부

cookie

String

"0" 미설정 "1" 설정

탐지 예외 조건 Cookie 필드 설정 여부

referer

String

"0" 미설정 "1" 설정

탐지 예외 조건 Referer 필드 설정 여부

video

Array

"0" 미설정 "1" 설정

탐지 예외 조건 동영상 확장자 설정 여부

image

Array

"0" 미설정 "1" 설정

탐지 예외 조건 이미지 확장자 설정 여부

validate_post_method

String

"0" 미설정 "1" 설정

클라이언트 POST Method 검증 설정 여부

post_feedback_time

String

기본 "10"(10 시간)

클라이언트 POST Method 검증 유효 시간(단위: 시간)

post_request_size

String

기본 "1024"(1024 KB)

클라이언트 POST Method 검증 탐지 예외 조건 Request Raw 사이즈(단위: KByte)

Unicode Directory Traversal

Request
Parameter

Data Type

--

--

--

URL Access Control

Explanation

Required

--

--

--

--

--

--

--

--

--

--

--

--

--

--

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

139/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

Request
Parameter

Data Type

learn

String

trust_ip

String

referer

String

browser

String

detect

String

학습 설정 여부

"0" 비설정

"1" 설정

신뢰 IP 설정 여부

"0" 비설정

"1" 설정

referer 설정 여부

"0" 비설정

"1" 설정

browser 설정 여부

"0" 비설정

"1" 설정

detect 설정 여부

"0" 비설정

"1" 설정

Explanation

Required

--

--

--

--

--

Stealth Commanding

Request Parameter

Data Type

Explanation

Required

user_defined_name

Array

User Defiend Pattern 목록

Message Control 목록

http_message_control

Array

"http_message_control":[{"location":"URL","max_length":11,"detail":

[{"all":true,"key_name":"","duplication":1,"max_count":1,"max_key_length":-1,"max_value_length":1}]}]

http_message_control[]
[location]

String

탐지 위치

"URL", "HEADER", "BODY"

http_message_control[]
[max_length]

Number

최대 길이

http_message_control[]
[detail]

Array

Message Control 목록

"detail":

[{"all":true,"key_name":"","duplication":1,"max_count":1,"max_key_length":-1,"max_value_length":1}]

http_message_control[]
[detail][][all]

http_message_control[]
[detail][][key_name]

http_message_control[]
[detail][][duplication]

http_message_control[]
[detail][][max_count]

http_message_control[]
[detail][]
[max_key_length]

http_message_control[]
[detail][]
[max_value_length]

Boolean

모두 탐지 여부

String

키 이름

Number

중복 개수 제한

Number

총 개수 제한

Number

키 길이 제한

Number

Value 길이 제한

Website Defacement

Request
Parameter

Data Type

--

--

--

TODO

미래에는 아래 URI와 method도 추가

/policies

정책 목록
GET - 정책 목록 보기

Explanation

Required

--

--

--

--

--

--

--

--

--

--

--

--

--

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

140/141

2020. 8. 7.

WAPPLES Web API - Penta Security Wiki

PUT - 정책 추가

/policies/id

id가 id인 정책 설정
GET - 정책 내용 보기
PUT - 정책 내용 변경

/policies/id/vhosts

id가 id인 정책에 연결된 웹 사이트 목록
GET - 목록 보기
PUT - 웹 사이트를 정책에 추가

PLS

PLS WAPPLES ID를 STAT 정보로 빼서 GUI에서 그 값을 참조 하도록 수정 필요

 Note: 현재는 ADMIN ID가 나오게 되어 있음.

관련 문서

WAPPLES 4.0 Web API 사용 가이드

WAPPLES v4.0 Web API와 v4.1 Web API 비교

WAPPLES 기능 설정 구조

Memcached 기능 및 동작 방식

원본 주소 "https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API&oldid=104028"

이 문서는 2017년 7월 21일 (금) 10:26에 마지막으로 편집되었습니다.

https://wiki.pentasecurity.com/index.php?title=WAPPLES_Web_API

141/141

