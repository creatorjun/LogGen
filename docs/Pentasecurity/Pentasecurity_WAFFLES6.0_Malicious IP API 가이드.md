Malicious IP API 가이드

개요

특정 클라이언트 IP를 웹방화벽에서 차단하는 기능입니다.

API를 통한 IP 등록시 차단을 하기 위해서는 우선 [정책]에서 IP Filtering 룰을
탐지가능하도록 설정 후 API를 통하여 차단 IP를 추가/삭제하여 적용할 수 있습니다.

자세한 사항은 아래 가이드를 참고해주세요.

기본설정

[정책 설정] 메뉴에서 IP차단을 적용할 웹사이트 정책을 추가 및 선택합니다.

IP Filtering 룰의 [수정]을 선택합니다.
수정 화면에서 [사용자 정의]를 선택하고, 대응설정은 연결 끊기 혹은 오류 코드 등
차단하고자 하는 대응을 설정합니다.
[사용자 정의] 항목 내에서 “Malicious IP 적용”을 ON으로 체크하고, [적용]을 선택합니다.
[적용]을 선택하여 수정창이 닫히면, 화면 하단의 [저장] 버튼을 선택하여야 설정이
저장됩니다.

API를 이용한 차단 IP 추가/삭제

IP 추가 /삭제 과정은 아래와 같습니다.

1.  auth API로 로그인 수행
2.  1번에서 로그인된 sessid를 cookie에 포함하여 추가/삭제 API 수행
3.  추가/삭제된 IP는 signal API를 실행하여 탐지엔진에 설정을 적용

※ 주의 : 2번에서의 추가/삭제 IP가 여러개라면 모두 추가/삭제 후 마지막에 3번 signal
API를 한 번만 수행하시기바랍니다.

참고 : Bash shell Curl 예시

●  192.168.43.162 장비에 세팅하는 예시입니다.
●  로그인

curl --insecure -H "Expect:" -vX POST https://192.168.43.162:5001/webapi/auth -d

'id=admin&password=[password]';

response 에서 받은 Set Cookie로 cookie 적용

Set-Cookie: WP_SESSID=b0681794f58d69278af2dce33074bd4a; path=/; HttpOnly

(cookie를 넣어서 시작하면 됩니다)

●  추가/삭제(description은 옵션입니다)

curl -k —insecure -b "WP_SESSID=b0681794f58d69278af2dce33074bd4a" -H "Content-

Type:application/json" -d '{"mode":"add","list":[{"ip":"1.1.1.1","description":"test"}]}' -vX

POST https://192.168.43.162:5001/webapi/conf/malicious_ip_list

curl -k —insecure -b "WP_SESSID=b0681794f58d69278af2dce33074bd4a" -H "Content-

Type:application/json" -d '{"mode":"delete","list":[{"ip":"1.1.1.1"},{"ip":2.2.2.2"}]' -vX POST

https://192.168.43.162:5001/webapi/conf/malicious_ip_list

●  룰 체인지(적용)

curl --insecure -H "Content-Type:application/json" -b

"WP_SESSID=b0681794f58d69278af2dce33074bd4a" -d

'{"type":"signal","sender_name":"com.penta.wapples.gui","message_name":"rule_change","m

essage_body":null}' -vX PUT https://192.168.43.162:5001/webapi/msgbus/signal

참고 : Python3 스크립트 예시

#!/usr/bin/python3
# -*- coding: utf-8 -*-

import os
import sys
import ssl
import urllib.request

#######################
# 관리도구 계정정보 입력
#######################
ID = ""
PASSWORD = ""
SITE = ""

auth_url = "https://{0}:5001/webapi/auth".format(SITE);
body = "id={0}&password={1}".format(ID, PASSWORD);

ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

request = urllib.request.Request(auth_url)
request.add_header("Content-Type","application/x-www-form-urlencoded")
response = urllib.request.urlopen(request, data=body.encode("utf-8"), context=ctx)
rescode = response.getcode()
if(rescode==200):
    response_body = response.read()
    cookies = response.getheader('Set-Cookie')
else:
    print("Authentication Error" + rescode)
    exit()

malicious_set_url = "https://{0}:5001/webapi/conf/malicious_ip_list".format(SITE)
#######################
# 추가/삭제 IP 입력
# "mode" 필드: 이 필드는 문자열 값을 가지며, "add/delete"라는 문자열 값으로 설정할 수
있습니다.
# "list" 필드: 이 필드는 배열 형식의 데이터를 포함하고 있습니다.
# 배열은 대괄호 [ ]로 묶여 있으며, "mode" 값에 따라 배열 안에 여러 개의 객체가 포함됩니다.
#   "add" : 배열 안의 각 객체: "list" 배열 안에 있는 각 객체는 다음과 같은 필드를 가지고
있습니다.

#       - "ip" 필드: 이 필드는 문자열 값을 가지며, IP 주소를 나타냅니다.
#       - "description" 필드: 이 필드는 문자열 값을 가지며, 옵션입니다. 해당 IP 주소에
대한 설명이나 레이블을 나타냅니다.
#   "delete" : 배열 안의 각 객체: "list" 배열 안에 있는 각 객체는 다음과 같은 필드를 가지고
있습니다.
#       - "ip" 필드: 이 필드는 문자열 값을 가지며, IP 주소를 나타냅니다.
#######################

# add example
body = '{"mode":"add","list":[{"ip":"3.3.3.3","description":"test"}, {"ip":"2.2.2.2"},
{"ip":"1.5.1.5", "description":"test3"}]}'

# delete example
#body = '{"mode":"delete","list":[{"ip":"1.5.1.5"}]}'

request = urllib.request.Request(malicious_set_url)
request.add_header("Content-Type","application/json")
request.add_header("Cookie", cookies)

response = urllib.request.urlopen(request, data=body.encode("utf-8"), context=ctx)
rescode = response.getcode()
if(rescode==200):
    response_body = response.read()
    print(response_body.decode('utf-8'))
else:
    print("Error Code:" + rescode)
    exit()

######################
# 룰에 적용
# 마지막에 한번 실행
######################

signal_url = "https://{0}:5001/webapi/msgbus/signal".format(SITE)
request = urllib.request.Request(signal_url, method='PUT')
request.add_header("Content-Type","application/json")
request.add_header("Cookie", cookies)

body =
'{"type":"signal","sender_name":"com.penta.wapples.gui","message_name":"rule_change","
message_body":null}'

response = urllib.request.urlopen(request, data=body.encode("utf-8"), context=ctx)
rescode = response.getcode()
if(rescode==200):

    response_body = response.read()
    print(response_body.decode('utf-8'))
else:
    print("Error Code:" + rescode)
    exit()

확인방법

보안설정 > 패턴 저장소 > Malicious IP 에 들어가면 등록되어 있는 IP를 볼 수 있고, 해당
화면에서 직접 추가/삭제도 가능합니다.

