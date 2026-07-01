윈스  TAXII/STIX 2.0  활용  안내서

(부제  : SBL, Reputation  정보  연동)

2020.07.30

Copyright ©2020 WINS.

Pangyo-seven Venture Valley WINS-dong 4F, 15, Pangyo-

ro  228beon-gil,  Bundang-gu,  Seongnam,  Gyeonggi-do,

KOREA 463-400

Tel. +82-31-622-8600 | Fax. +82-31-622-8601

Copyright © 2020 WINS. ALL RIGHTS RESERVED

Contents

1.  개요 ........................................................................................................................................................................ 4

2.  기본  정보 ............................................................................................................................................................... 4

2.1. TAXII 2.0 ............................................................................................................................................................................................... 4

2.2. STIX 2.0 ................................................................................................................................................................................................ 4

3.  윈스  TAXII 2.0  정보 ............................................................................................................................................. 5

3.1. api_root  확인 .................................................................................................................................................................................... 5

3.2. Collections  확인 .............................................................................................................................................................................. 5

3.3. Collections  종류 .............................................................................................................................................................................. 6

3.4. STIX Domain Objects  정보 ......................................................................................................................................................... 7

3.5. Collections  종류별  데이터  제약 .............................................................................................................................................. 7

3.5.1. SBL IP  데이터 ................................................................................................................................................................... 7

3.5.2. Reputation IP  데이터 .................................................................................................................................................... 8

3.5.3. Reputation URL  데이터 ................................................................................................................................................ 8

4.  윈스  TAXII 2.0  사용  샘플 ................................................................................................................................... 9

4.1.  모든  객체  정보  확인  (지정  collections) ............................................................................................................................. 9

4.2.  특정  객체  정보  확인  (지정  objects) .................................................................................................................................. 11

4.3.  객체  등록 ......................................................................................................................................................................................... 13

4.4.  객체  변경 ......................................................................................................................................................................................... 15

4.5.  객체  취소 ......................................................................................................................................................................................... 17

5.  변경사항  적용  API ............................................................................................................................................. 20

5.1.  요청 ..................................................................................................................................................................................................... 20

5.2.  결과 ..................................................................................................................................................................................................... 20

6.  부록 ...................................................................................................................................................................... 21

6.1.  참고자료 ............................................................................................................................................................................................ 21

2 / 21

본  문서는  윈스의  보안제품(ONE,  IPS  등)에서  활용하는  SBL(Static  Black  List  IP),

Reputation  정보를  외부  시스템으로부터  연동  받기  위해  운영하는  TAXII/STIX  2.0  활용

안내  문서이다.

변경  이력

작성자

일자

변경내용

임경문

2019.08.29

-  신규  작성

임경문

2019.08.30

- Collection 을  세  종류로  분리

- SBL IP  타입  제약  사항

임경문

2019.09.23

- Reputation IP  의  Collection ID  변경

-  오타수정  ip4-addr -> ipv4-addr

임경문

2020.07.30

- SBL IP  정보에  ipv6-addr  추가  지원

버전

1.0

1.1

1.2

1.3

3 / 21

1. 개요

TAXII/STIX 2.0 운영을  통해  특정  Collections  을  외부에  공개하고,  당사  보안제품에서

SBL(Static Black List IP), Reputation 용도로  사용  가능한  정보를  수집  한다.

2. 기본  정보

2.1. TAXII 2.0

Version : 2.0

TAXII 2.0  및  해당  버전에서  제공하는  API 를  이용한다. (참고  링크)

URL  체계

<api-root>/collections/

<api-root>/collections/<collections-id>/

Method

범위

GET

GET

collections

collections

<api-root>/collections/<collections-id>/objects/

GET, POST  objects

<api-root>/collections/<collections-id>/objects/<object-id>/

GET

objects

2.2. STIX 2.0

Version : 2.0

STIX  객체  도메인은  12 가지  타입이  존재한다. (참고  링크)

SBL(Static Black List IP), Reputation  용  데이터는  observed-data  타입을  사용한다.

4 / 21

3. 윈스  TAXII 2.0  정보

3.1. api_root  확인

https://IP:PORT/api/taxii2/taxii

위  URL 로  공개된  api_root  정보를  확인  할  수  있다.

Method

GET

URL

https://IP:PORT/api/taxii2/taxii

Response

{

예시

  "api_roots": [

https://rms.sniper.com:8500/api/taxii2/rms/,

  ],

  "contact": "연락처 정보",

  "description": "시스템 설명",

  "title": "WINS TAXII2.0 Server"

}

3.2. Collections  확인

공개된  API_ROOT  주소로  사용  가능한  collection  정보를  확인  할  수  있다.

Method

GET

URL

https://rms.sniper.com:8500/api/taxii2/rms/collections

Response

{

예시

  "collections": [

    {

      "can_read": true,

      "can_write": true,

      "description": "This data collection is for other system (ESM, SIEM,
CTI) collecting Static Black List IP.",

      "id": "d2a89ed6-c96e-11e9-a32f-2a2ae2dbcce4",

      "media_types": [

        "application/vnd.oasis.stix+json; version=2.0"

      ],

      "title": "SBL IP Data Observed in Other Systems"

    },

{

      "can_read": true,

      "can_write": true,
      "description": " This collection is published by other systems (ESM,
SIEM, CTI) to collect reputation IPs.",

5 / 21

      "id": "472c94ae-3113-4e3e-a4dd-a9f4ac7471d4",

      "media_types": [

        "application/vnd.oasis.stix+json; version=2.0"

      ],

      "title": "Reputation IPs Data Observed in Other Systems "

    },

{

      "can_read": true,

      "can_write": true,
      "description": " This collection is published by other systems (ESM,
SIEM, CTI) to collect reputation URLs.",

      "id": "2ed7e0b4-cadb-11e9-a32f-2a2ae2dbcce4",

      "media_types": [

        "application/vnd.oasis.stix+json; version=2.0"

      ],

      "title": "Reputation URLs Data Observed in Other Systems "

    }

  ]

}

3.3. Collections  종류

데이터  종류

Collection ID

SBL IP

d2a89ed6-c96e-11e9-a32f-2a2ae2dbcce4

Reputation IP

472c94ae-3113-4e3e-a4dd-a9f4ac7471d4

Reputation URL

2ed7e0b4-cadb-11e9-a32f-2a2ae2dbcce4

기타

SBL IP 정보

Reputation IP 정보

Reputation URL 정보

※  SBL IP  데이터는  공개된  컬렉션  중에서  SBL IP Collection id  를  사용한다.

6 / 21

3.4. STIX Domain Objects  정보

Type  종류를  Observed-Data  타입으로  사용한다.

필드  정보  (참고  링크)

도메인 객체 타입

observed-data

키

type

id

created

modified

revoked

first_observed

last_observed

number_observed

*

*

*

*

*

필수  데이터 타입

값

*

string

observed-data

*

string

observed-data--UUID

비고

고정 값

뒤 UUID 발급

timestamp

timestamp

2019-08-29T12:31:12.124Z

2019-08-29T12:31:12.124Z

UTC

UTC

false

삭제시 true

2019-08-29T18:07:15.213Z

2019-08-29T18:07:15.213Z

UTC

UTC

timestamp

timestamp

integer

1

관찰 횟수

데이터 제약

참조

objects

*

observable-objects  1 or more

name

string

SNIPER SBL

labels

list of string

["WINS", "SNIPER", "SBL"]

Tagging 문자

or

observer-ipv4-10.10.10.1

3.5. Collections  종류별  데이터  제약

3.5.1. SBL IP  데이터

Objects  값으로  사용  가능한  모델,  타입  및  예시  (  참조  : STIX Defined Object Data Models )

데이터  모델  타입

ipv4-addr or ipv6-addr

IP  타입

키

type

value

single    (CIDR  사용  불가)

필수  데이터  타입

값

비고

*

*

string

string

ipv4-addr or ipv6-addr

198.51.100.1

fec0:0:0:80::100

단일 정보 예시

(ipv4)

"objects": {

  "0": {

    "type": "ipv4-addr",

    "value": "198.51.100.1"

7 / 21

  }

}

단일 정보 예시

(ipv6)

"objects": {

  "0": {

    "type": "ipv6-addr",

    "value": "1:2:3:4::5"

  }

}

멀티 정보 예시

(ipv4, ipv6)

"objects": {

  "0": {

    "type": "ipv4-addr",

    "value": "198.51.100.3"

  },

  "1": {

    "type": "ipv6-addr",

    "value": "fec0:0:0:80::100"

}

...

}

※  ipv6-addr  값이  축약된  값인  경우  full  값으로  치환하여  WINS  제품에  사용  됨.

3.5.2. Reputation IP  데이터

제공  예정

3.5.3. Reputation URL  데이터

제공  예정

8 / 21

비고

포맷

성공

4. 윈스  TAXII 2.0  사용  샘플

TAXII 2.0 API  을  이용해  사용한다. TAXII 2.0 API  문서  참조

4.1. 모든  객체  정보  확인  (지정  collections)

항목

Method

Header

URL

내용

GET

Content-Type: application/vnd.oasis.stix+json; version=2.0

Accept: application/vnd.oasis.stix+json; version=2.0

<api_root>/collections/d2a89ed6-c96e-11e9-a32f-
2a2ae2dbcce4/objects

Authorization  ID, PASS

Body

Response

없음

{

"type": "bundle",

    "id": "bundle--b79550e9-bcf3-4124-8cce-c1290b50259b",
    "objects": [
{

            "created": "2019-08-28T18:10:12.213Z",

"modified": "2019-08-28T18:10:12.213Z",

            "first_observed": "2019-08-28T18:07:12.213Z",

"last_observed": "2019-08-28T18:07:12.213Z",

            "id": "observed-data--2013e360-c96f-11e9-a32f-
2a2ae2dbcce4",
            "labels": [
                "WINS",
                "SNIPER",
                "SBL"
            ],

"name": "observed-ipv4-10.10.10.1",

            "number_observed": 1,
            "objects": {
                "0": {
                    "type": "ipv4-addr",
                    "value": "10.10.10.1"
                },
                "1": {
                    "type": "ipv4-addr",
                    "value": "10.11.11.1"
                }
            },
            "revoked": false,
            "type": "observed-data"

},
{

            "created": "2019-08-28T18:10:12.213Z",

"modified": "2019-08-28T18:10:12.213Z",

            "first_observed": "2019-08-28T18:07:12.213Z",

"last_observed": "2019-08-28T18:07:12.213Z",

9 / 21

            "id": "observed-data--2013e360-c96f-11e9-a32f-
2a2ae2dbcce5",
            "labels": [
                "WINS",
                "SNIPER",
                "SBL"
            ],

"name": "observed-ipv4-10.10.10.2",

            "number_observed": 1,
            "objects": {
                "0": {
                    "type": "ipv4-addr",
                    "value": "10.10.10.2"
                },
                "1": {
                    "type": "ipv4-addr",
                    "value": "10.12.12.2"
                }
            },
            "revoked": false,
            "type": "observed-data"
        }
],
"spec_version": "2.0"

}

Response

{
    "description": "Collection '12345678-2019-0828-8500-
c6fbd5a26117' not found. Root exception: None",
    "http_status": "404",
    "title": "ProcessingError"
}

실패

10 / 21

4.2. 특정  객체  정보  확인  (지정  objects)

URL 에  특정  객체  id  값을  붙여서  요청

항목

Method

Header

URL

내용

GET

Content-Type: application/vnd.oasis.stix+json; version=2.0

Accept: application/vnd.oasis.stix+json; version=2.0

비고

포맷

<api_root>/collections/d2a89ed6-c96e-11e9-a32f-
2a2ae2dbcce4/objects/observed-data--2013e360-c96f-11e9-
a32f-2a2ae2dbcce4

해당 객체

ID 필수

Authorization  ID, PASS

없음

{
    "id": "bundle--4ee42646-7008-462b-9a2e-1735a963ba8f",
    "objects": [
        {
            "created": "2019-08-28T18:10:12.213Z",
            "first_observed": "2019-08-28T18:07:12.213Z",
            "id": "observed-data--2013e360-c96f-11e9-a32f-
2a2ae2dbcce4",

"name": "observed-ipv4-10.10.10.1",

            "labels": [
                "WINS",
                "SNIPER",
                "SBL"
            ],
            "last_observed": "2019-08-28T18:07:12.213Z",
            "modified": "2019-08-28T18:10:12.213Z",

"number_observed": 1,

            "objects": {
                "0": {
                    "type": "ipv4-addr",
                    "value": "10.10.10.1"
                },
                "1": {
                    "type": "ipv4-addr",
                    "value": "10.11.11.2"
                }
            },
            "revoked": false,
            "type": "observed-data"
        }
    ],
    "spec_version": "2.0",
    "type": "bundle"
}
{
    "id": "bundle--5fea195f-a34b-4845-8258-8619a5d1e0f5",
    "objects": [],
    "spec_version": "2.0",

실패

Body

Response

Response

11 / 21

    "type": "bundle"
}

12 / 21

4.3. 객체  등록

항목

Method

Header

URL

내용

POST

Content-Type: application/vnd.oasis.stix+json; version=2.0

Accept: application/vnd.oasis.stix+json; version=2.0

<api_root>/collections/d2a89ed6-c96e-11e9-a32f-
2a2ae2dbcce4/objects

비고

포맷

Authorization  ID, PASS

Body

{

    "type": "bundle",

    "objects": [

        {

            "type": "observed-data",

            "id": "observed-data--2013e360-c96f-11e9-a32f-
2a2ae2dbcce5",

            "created": "2019-08-29T18:10:12.213Z",

            "modified": "2019-08-29T18:10:12.213Z",

            "name": "observed-ipv4-10.10.10.5",

            "labels": [

                "WINS",

                "SNIPER",

                "SBL"

            ],

            "first_observed": "2019-08-29T18:07:15.213Z",

            "last_observed": "2019-08-29T18:07:15.213Z",

            "number_observed": 1,

            "revoked": false,

            "objects": {

                    "0": {

                        "type": "ipv4-addr",

                        "value": "10.10.10.5"

                     }

}

},

{

            "type": "observed-data",

            "id": "observed-data--2013e360-c96f-11e9-a32f-
2a2ae2dbcce6",

            "created": "2019-08-28T18:11:12.213Z",

            "modified": "2019-08-28T18:11:12.213Z",

            "name": "observed-ipv4-10.10.10.6",

13 / 21

            "labels": [

                "WINS",

                "SNIPER",

                "SBL"

            ],

            "first_observed": "2019-08-29T18:08:15.213Z",

            "last_observed": "2019-08-29T18:08:15.213Z",

            "number_observed": 1,

            "revoked": false,

            "objects": {

                    "0": {

                        "type": "ipv4-addr",

                        "value": "10.10.10.6"

                    },

                    "1": {

                        "type": "ipv4-addr",

                        "value": "10.16.16.7"

                    }

            }

}

    ]

}

{
    "failure_count": 0,
    "id": "22da86f4-4c26-4fce-a12a-ef1c8de41a31",
    "pending_count": 0,
    "request_timestamp": "2019-08-29T06:25:32.782158Z",
    "status": "complete",
    "success_count": 2,
    "successes": [
        "observed-data--2013e360-c96f-11e9-a32f-
2a2ae2dbcce5",
        "observed-data--2013e360-c96f-11e9-a32f-
2a2ae2dbcce6"
    ],
    "total_count": 2
}
{
    "id": "bundle--5fea195f-a34b-4845-8258-8619a5d1e0f5",
    "objects": [],
    "spec_version": "2.0",
    "type": "bundle"
}

성공

실패

Response

Response

14 / 21

4.4. 객체  변경

객체  ID  값으로  정보를  확인  후  해당  객체  정보에  필요한  정보를  수정하고  반드시

변경시간을  마지막  변경시간  보다  큰  값(예:  현재시간)으로  반영  후  요청

항목

Method

Header

URL

내용

POST

Content-Type: application/vnd.oasis.stix+json; version=2.0

Accept: application/vnd.oasis.stix+json; version=2.0

<api_root>/collections/d2a89ed6-c96e-11e9-a32f-
2a2ae2dbcce4/objects

비고

포맷

Authorization  ID, PASS

Body

{

    "type": "bundle",

    "objects": [

        {

            "type": "observed-data",

            "id": "observed-data--2013e360-c96f-11e9-a32f-
2a2ae2dbcce5",

            "created": "2019-08-29T18:10:12.213Z",

            "modified": "2019-08-29T19:10:12.213Z",

            "name": "observed-ipv4-10.10.10.5",

            "labels": [

                "IGLOO",

                "SPIDER-TM",

                "SBL"

            ],

            "first_observed": "2019-08-29T18:07:15.213Z",

            "last_observed": "2019-08-29T19:07:15.213Z",

            "number_observed": 20,

            "revoked": false,

            "objects": {

                    "0": {

                        "type": "ipv4-addr",

                        "value": "10.10.10.5"

                     }

}

},

{

            "type": "observed-data",

            "id": "observed-data--2013e360-c96f-11e9-a32f-
2a2ae2dbcce6",

15 / 21

            "created": "2019-08-28T18:11:12.213Z",

            "modified": "2019-08-28T19:11:12.213Z",

            "name": "observed-ipv4-10.10.10.6",

            "labels": [

                "IGLOO",

                "SPIDER-TM",

                "SBL"

            ],

            "first_observed": "2019-08-29T18:08:15.213Z",

            "last_observed": "2019-08-29T19:08:15.213Z",

            "number_observed": 10,

            "revoked": false,

            "objects": {

                    "0": {

                        "type": "ipv4-addr",

                        "value": "10.10.10.6"

                    },

                    "1": {

                        "type": "ipv4-addr",

                        "value": "10.16.16.7"

                    }

              }

}

    ]

}

{
    "failure_count": 0,
    "id": "22da86f4-4c26-4fce-a12a-ef1c8de41a31",
    "pending_count": 0,
    "request_timestamp": "2019-08-29T06:25:32.782158Z",
    "status": "complete",
    "success_count": 2,
    "successes": [
        "observed-data--2013e360-c96f-11e9-a32f-
2a2ae2dbcce5",
        "observed-data--2013e360-c96f-11e9-a32f-
2a2ae2dbcce6"
    ],
    "total_count": 2
}
{
    "id": "bundle--5fea195f-a34b-4845-8258-8619a5d1e0f5",
    "objects": [],
    "spec_version": "2.0",
    "type": "bundle"
}

성공

실패

Response

Response

16 / 21

4.5. 객체  취소

TAXII 2.0  에서는  DELETE Method  미지원,  정보를  갱신  누적하며  revoked  처리

객체  ID  값으로  정보를  확인  후  해당  객체  정보에  아래  2 개  필드  값을  반영  후  요청

"revoked": true,  // 취소 상태

"modified": "2019-08-29T19:10:12.213Z", //변경시간은 최종 변경 시간보다 큰 값으로 해야 함

항목

Method

Header

URL

내용

POST

Content-Type: application/vnd.oasis.stix+json; version=2.0

Accept: application/vnd.oasis.stix+json; version=2.0

<api_root>/collections/d2a89ed6-c96e-11e9-a32f-
2a2ae2dbcce4/objects

비고

포맷

Authorization  ID, PASS

Body

{

    "type": "bundle",

    "objects": [

        {

            "type": "observed-data",

            "id": "observed-data--2013e360-c96f-11e9-a32f-
2a2ae2dbcce5",

            "created": "2019-08-29T18:10:12.213Z",

            "modified": "2019-08-29T19:10:12.213Z",

            "name": "observed-ipv4-10.10.10.5",

            "labels": [

                "IGLOO",

                "SPIDER-TM",

                "ESM"

            ],

            "first_observed": "2019-08-29T18:07:15.213Z",

            "last_observed": "2019-08-29T18:07:15.213Z",

            "number_observed": 20,

            "revoked": true,

            "objects": {

                    "0": {

                        "type": "ipv4-addr",

                        "value": "10.10.10.5"

                     }

}

17 / 21

},

{

            "type": "observed-data",

            "id": "observed-data--2013e360-c96f-11e9-a32f-
2a2ae2dbcce6",

            "created": "2019-08-28T18:11:12.213Z",

            "modified": "2019-08-28T19:11:12.213Z",

            "name": "observed-ipv4-10.10.10.6",

            "labels": [

                "IGLOO",

                "SPIDER-TM",

                "SBL"

            ],

            "first_observed": "2019-08-29T18:08:15.213Z",

            "last_observed": "2019-08-29T18:08:15.213Z",

            "number_observed": 10,

            "revoked": true,

            "objects": {

                    "0": {

                        "type": "ipv4-addr",

                        "value": "10.10.10.6"

                    },

                    "1": {

                        "type": "ipv4-addr",

                        "value": "10.16.16.7"

                    }

              }

}

    ]

}

성공

{
    "failure_count": 0,
    "id": "22da86f4-4c26-4fce-a12a-ef1c8de41a31",
    "pending_count": 0,
    "request_timestamp": "2019-08-29T06:25:32.782158Z",
    "status": "complete",
    "success_count": 2,
    "successes": [
        "observed-data--2013e360-c96f-11e9-a32f-
2a2ae2dbcce5",
        "observed-data--2013e360-c96f-11e9-a32f-
2a2ae2dbcce6"
    ],
    "total_count": 2
}

Response

18 / 21

Response

{
    "id": "bundle--5fea195f-a34b-4845-8258-8619a5d1e0f5",
    "objects": [],
    "spec_version": "2.0",
    "type": "bundle"
}

실패

19 / 21

5. 변경사항  적용  API (옵션)

외부  시스템에서  TAXII 에  정보를  등록/변경/취소  하는  작업과  별개로  TAXII 에

업데이트된  정보를  당사  보안  시스템이  적용하기  위해서는  별도  API 를  이용  해야한다.

필요시  당사  시스템(예: RMS)  에서  제공하는  API 를  이용한다.

5.1. 요청

외부  시스템과  연계하는  당사  시스템  (ex : RMS)  에  설계된  API 를  제공한다.

필요시  별도  제공  예정

5.2. 결과

{

  "error_num" : "2000",

  "error_info" : "Success"
}

ERROR_NUM
2000
9000

<ERROR_INFO>
Success
Fali

<ERROR_INFO>
성공하였습니다.
실패하였습니다.

20 / 21

6. 부록

6.1. 참고자료

[1]    STIX Version 2.0. Part1: STIX Core Concepts

[2]    STIX Version 2.0. Part2: STIX Objects

[3]    STIX Version 2.0. Part3: Cyber Observable Core Concepts

[4]    STIX Version 2.0. Part4: Cyber Observable Objects

[5]    STIX Version 2.0. Part5: STIX Pattering

[6]    TAXII Version 2.0

21 / 21

