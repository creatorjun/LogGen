FortiOS - REST API Reference

Version 6.0.4

FORTINET DOCUMENT LIBRARY

https://docs.fortinet.com

FORTINET VIDEO GUIDE

https://video.fortinet.com

FORTINET BLOG

https://blog.fortinet.com

CUSTOMER SERVICE & SUPPORT

https://support.fortinet.com

FORTINET COOKBOOK

https://cookbook.fortinet.com

FORTINET TRAINING & CERTIFICATION PROGRAM

https://www.fortinet.com/support-and-training/training.html

NSE INSTITUTE

https://training.fortinet.com

FORTIGUARD CENTER

https://fortiguard.com/

END USER LICENSE AGREEMENT

https://www.fortinet.com/doc/legal/EULA.pdf

FEEDBACK

Email: techdocs@fortinet.com

January 10, 2018

FortiOS 6.0.4 REST API Reference

01-604-472442-20190110

TABLE OF CONTENTS

Change Log
Introduction

What's New in the REST API
Authentication

Session-based authentication
Token-based authentication

Authorization
Supported HTTP methods
Response codes
Debugging
CMDB API
URL path
URL parameters

Generic parameters
Specific parameters

Body data

Limitation

Filter with multiple key/value pairs

Filter Syntax
Filter Operators
Combining Filters
Reserved Characters

List of Methods
collection
resource

Examples

Retrieve table
Retrieve table schema
Retrieve table default
Purge table
Retrieve object
Create object
Edit object
Delete object
Clone object
Move object
Append child object
Edit child object
Delete child object
Purge child table
Retrieve complex table
Edit complex table
Send requests to multiple vdoms

5
6
6
7
7
9
12
12
12
13
15
15
15
16
16
17
18
18
18
18
19
19
20
20
21
24
24
24
25
25
25
25
25
26
26
26
26
27
27
27
27
27
28

FortiOS REST API Reference

Fortinet Inc.

Monitor API
URL path
URL parameters

Generic parameters
Specific parameters

Body data
File upload

File upload via JSON data
File upload via multi-part file

File download

File download via browser
File download via script

List of Methods

endpoint-control
firewall
geoip
ips
license
log
registration
router
system
switch-controller
extender-controller
user
utm
virtual-wan
webfilter
vpn
vpn-certificate
wanopt
webproxy
webcache
wifi
Examples

4

29
29
29
29
30
30
30
30
31
31
31
31
32
43
48
58
59
59
60
65
69
72
86
113
114
124
125
126
129
132
135
137
137
138
144

FortiOS REST API Reference

Fortinet Inc.

Change Log

Date

Change Description

2019-01-10

Initial release.

FortiOS REST API Reference

Fortinet Inc.

Introduction

All requests to FortiOS REST APIs require valid authentication and authorization before being processed.

The following REST APIs are supported:

 l CMDB API

 l Retrieve object meta data (default, schema)
 l Retrieve object/table (with filter, format, start, count, other flags)
 l Create object
 l Modify object
 l Delete object
 l Clone object
 l Move object

 l Monitor API

 l Retrieve/Reset endpoint stats (with filter, start, count)
 l Perform endpoint operations
 l Upload/Download file
 l Restore/Backup config
 l Upgrade/Downgrade firmware
 l Restart/Shutdown FGT

What's New in the REST API

 l Added support for testing the connectivity of a given Sandbox IP
 l Added support for retrieving the list of device types
 l Updated the access groups for the endpoints
 l Updated a few parameters including change in types and description

New APIs

Method

URI

Description

Change Summary

GET

GET

/system/sandbox/test-connect/

Test the connectivity of a given
FortiSandbox IP

New API

/user/device-type/select/

Retrieve a list of device types.

New API

FortiOS REST API Reference

Fortinet Inc.

Introduction

Updated APIs

7

Method

URI

Description

Change Summary

GET

/firewall/session/select

List all active firewall sessions
(optionally filtered).

Added a new parameter
"policytype" of type string Filter:
Policy type [policy6].

GET

GET

GET

GET

/firewall/session/select

List all active firewall sessions
(optionally filtered).

Updated protocol parameter type
from integer to string.

/router/policy/select

Retrieve a list of active IPv4
policy routes.

Added new parameters : start,
count, count_only

/router/policy6/select

Retrieve a list of active IPv6
policy routes.

Added new parameters : start,
count, count_only

/vpn/one-click/members

GET

/vpn/one-click/status

Get information on devices
registered in the Overlay
Controller VPN cloud assisted
group.

Get the last status message
from FortiCloud? Overlay
Controller VPN cloud service.

Updated summary to use the new
name overlay controller VPN

Updated summary to use the new
name overlay controller VPN

Removed APIs

Method

URI

Description

GET

/firewall/session-top/select/

List of top sessions by specified grouping
criteria.

Change
Summary

Removed API

Authentication

Starting in FortiOS 5.6.1, there are two ways that user can authenticate against the API:

 l Session-based authentication (legacy)
 l Token-based authentication (5.6.1 and newer)

Session-based authentication

As the name suggests, the authentication is valid per login session. The user needs to send a login request to obtain a
authentication cookie and CSRF token to be used for subsequent requests. The user then needs to send a logout
request to invalidate the authentication cookie and CSRF token.

FortiOS REST API Reference

Fortinet Inc.

Introduction

Authentication Cookie

8

Authentication cookie (APSCOOKIE) is provided by the API after a successful login request. All subsequent requests
must include this cookie to be authorized by the API. Any request without the cookie or with mismatched cookie will be
denied access to the API (HTTP 401 error code).

CSRF Tokens

Cross-Site Request Forgery (CSRF) Tokens are alphanumeric values that are passed back-and-forth between client and
server to ensure that a user's form submission does not originate from an offsite document.

The CSRF token is available in the session ccsrftoken cookie, which must be included in the request header under
X-CSRFTOKEN. See test script sample for how to handle CSRF token.

Only write requests (HTTP POST/PUT/DELETE) need CSRF tokens. Read requests (HTTP
GET) do not require CSRF tokens.

Setting Up an Authenticated Session

To authenticate with the FortiGate and request a session, send a POST request to the log in request handler with your
username and password.

Login URL

/logincheck

The request body must contain the following keys in URL form encoding:

Type

String

String

Int (1)

Key

username

secretkey

ajax

Example:

Description

The admin username.

The password for that admin.

Required: Format the response for easier parsing. Enable using 1.

POST /logincheck
username=AdminUser&secretkey=AdminPassword&ajax=1

Ensure that you're using the correct protocol. By default, a FortiGate will redirect HTTP requests to HTTPS and your
login requests may fail. As well, FortiGate 's will use a self-signed server certificate by default. Refer to the
documentation for the specific library or framework that you're using to validate the certificate manually.

The response to this request will be in the following format:

<status_code><javascript>

A successful login response would be:

1document.location="/ng/prompt?viewOnly&redir=%2Fng%2F";

For most uses, you only need to read the first character of the response body to get the response status code.

FortiOS REST API Reference

Fortinet Inc.

Introduction

9

Code

Description

0

1

2

3

Log in failure. Most likely an incorrect username/password combo.

Successful log in*

Admin is now locked out

Two-factor Authentication is needed**

* In some cases users may receive a successful login status but not be completely authenticated, such as when there is
a post-login-banner configured.

** For Two-Factor log in, make another POST request with the same username and password, but include the token_
code parameter with the value of the one-time-password.

Once you've received a successful login status, read each Set-Cookie header and retain the following Cookies:

Name

Description

APSCOOKIE_<NUMBER>

This cookie authenticates you with the FortiGate. You must present this cookie
with every subsequent request you make after logging in.

ccsrftoken

This is the (c)CSRF token. As described in Authorization on page 12, you must
provide the value of this cookie as a X-CSRFTOKEN header. *

*There may be two ccsrftoken cookies, one with a number suffix that matches the APSCOOKIE. For simplicity, you
don't need to locate that cookie and can rely on the ccsrftoken cookie.

Logging out of an Authenticated Session

Authenticated sessions will remain active with the device until any of the following occurs:

 l The admin logs out
 l The session remains inactive for longer than the timeout specified by the admintimeout setting in config

system global

 l The admin is disconnected by another admin

There are a limited number of admins that can have active sessions on the device, therefore it's recommended that you
log out when you're finished using the device.

To log out, a POST request to the /logout URL will remove the current session.

Logout URL

Body data

/logout

none needed

Token-based authentication

The authentication is done via a single API token. This token is only generated once when creating an API admin. The
user must store this token in a safe place because it cannot be retrieved again. The user can however regenerate the
token at any time. Each API request must include the token in order to be authenticated as the associated API admin.

FortiOS REST API Reference

Fortinet Inc.

Introduction

10

Only HTTPS access is allowed with token-based authentication to ensure maximum security.

Create API admin

In order to use the token-based authentication, user must first create a special API admin. The user can assign vdom
provision and admin profile to this API admin which defines the admin's privileges.

Only Super admin can create or modify API admin.

config system api-user
edit "api-admin"

set comments "admin for API access only"
set api-key ENC SH23sQt? +/9D9/mKb1oQoDvlP32ggn/cpQeGcY/VGUe5S5WIr5nqU20xcNMYDQE=
set accprofile "API profile"
set vdom "root"
config trusthost

edit 1

set ipv4-trusthost 192.168.10.0 255.255.255.0

next

end

next

end

Trusted host

GUI does not allow user to pick super admin or prof_admin profile for API admin to encourage
user to use a special profile.

At least one trusted host must be configured for the API admin. The user can define multiple trusted host/subnet. IPv6
hosts are also supported.

PKI Certificate

Token-based also supports certificate matching as an extra layer of security (set PKI group in api-user). Both client
certificate and token must match to be granted access to the API. PKI option is enabled by default.

CORS permission

Token-based also supports Cross Origin Resource Sharing (CORS) allowing third-party web apps to make API requests
to FGT using the token. CORS is disabled by default.

FortiOS REST API Reference

Fortinet Inc.

Introduction

Generate API token

11

After creating the api-user, user can generate new token via CLI command, GUI, or REST API. The token is only shown
once and cannot be retrieved after. The user needs to generate new token if they forget.

CLI command:

execute api-user generate-key [API user name]

New API key: fccys3cfbhyhqbqghkyzm1QGNnm31r

The bearer of this API key will be granted all access privileges assigned to the api-user api-
admin.

REST API

Request

Body data

Description

POST /api/v2/monitor/system/api-
user/generate-key?vdom=root

{'api-user':"api-
admin"}

"Generate a new api-key for the specified
api-key-auth admin. The old api-key will be
replaced. The response contains the only
chance to read the new api-key plaintext in
the access_token field."

Use the API token

The API token can be included in any REST API request via either request header or URL parameter

Passing API token via request header

The user needs to explicitly add the following field to the request header: 'Authorization': 'Bearer ' +
[api_token]

Authorization: Bearer fccys3cfbhyhqbqghkyzm1QGNnm31r

Passing API token via request URL parameter

The user needs to explicitly include the following field in the request URL parameter: access_token=[api_token]

Method URL

GET

/api/v2/cmdb/firewall/address  ?vdom=root&access_

token=fccys3cfbhyhqbqghkyzm1QGNnm31r

Body
data

Description

Retrieve all
IPv4 firewall
addresses,
vdom root

FortiOS REST API Reference

Fortinet Inc.

Introduction

Authorization

12

After the request is authenticated, the API will check if the associated admin has the permission to perform the
operation. Each admin or API admin has an admin profile and vdom scope which define the privileges of the admin. For
example, if the admin has vdom scope set to "vdom1" and a profile that only has read-only permission to Firewall
objects access group, the admin can only access vdom1 resource, and cannot make change to Firewall objects (policy,
address, etc).

Each endpoint requires specific group permission defined in 'Access Group' of the endpoint summary table. Request to
the endpoint will be checked against this access group to ensure the admin has proper permission to access the
resource. Make sure the administrative account you login with has the permissions required to perform the intended
actions.

Admin with read-only permission to the resource can only send read requests (HTTP GET) to the resource. Admin with
write permission to the resource can send read/write requests (HTTP GET/POST/PUT/DELETE) to the resource. Admin
with no permission to the resource cannot access the resource.

Request with insufficient profile permission will return 403 error.

Supported HTTP methods

FortiOS REST APIs support the following HTTP methods:

HTTP Method

Description

GET

POST

PUT

DELETE

Retrieve a resource or collection of resources.

Create a resource or execute actions.

Update a resource.

Delete a resource or collection of resources.

For any action other than GET, you must provide the X-CSRFTOKEN header in the request. The value of this header is
the value of the ccsrftoken cookie that is provided by the FortiGate when you log in.

If the request is submitted using HTTP POST , the HTTP method can also be overridden using the "X-HTTP-Method-
Override" HTTP header.

Response codes

FortiOS APIs use well-defined HTTP status codes to indicate the results of queries to the API.

The following table shows how some of the HTTP status codes are used in the context of FortiOS REST APIs.

FortiOS REST API Reference

Fortinet Inc.

Introduction

13

HTTP Response Code

Description

200 - OK

Request returns successful.

400 - Bad Request

Request cannot be processed by the API.

401 - Not Authorized

Request without successful login session.

403 - Forbidden

Request is missing CSRF token or administrator is missing access profile
permissions.

404 - Resource Not Found

Unable to find the specified resource.

405 - Method Not Allowed

Specified HTTP method is not allowed for this resource.

413 - Request Entity Too Large

Request cannot be processed due to large entity.

424 - Failed Dependency

Fail dependency can be duplicate resource, missing required parameter, missing
required attribute, invalid attribute value.

429 - Too many requests

The request is actively blocked by FGT due to a rate limit. For example, if an
admin uses invalid credentials too many times, there will be a timeout before
they can try again.

500 - Internal Server Error

Internal error when processing the request.

Debugging

Verbose debug output can be enabled in the FortiGate CLI with the following commands:

diagnose debug enable
diagnose debug application httpsd -1

This will produce the following output when the REST API for IPv4 policy statistics is queried:

[httpsd 228 - 1418751787] http_config.c[558] ap_invoke_handler -- new request (handler='api_

monitor_v2-handler', uri='/api/v2/monitor/firewall/policy', method='GET')

[httpsd 228 - 1418751787] http_config.c[562] ap_invoke_handler -- User-Agent: Mozilla/5.0

(Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko)
Chrome/39.0.2171.71 Safari/537.36

[httpsd 228 - 1418751787] http_config.c[565] ap_invoke_handler -- Source: 192.168.1.100:56256

Destination: 192.168.1.99:443

[httpsd 228 - 1418751787] api_monitor.c[1427] api_monitor_v2_handler -- received api_monitor_

v2_request from '192.168.1.100'

[httpsd 228 - 1418751787] aps_access.c[3652] aps_chk_rolebased_perm -- truncated URI
(/api/v2/monitor/firewall/policy) to (/api/v2/monitor) for permission check

[httpsd 228 - 1418751787] api_monitor.c[1265] handle_req_v2_vdom -- attempting to change from

vdom "root" to vdom "root"

[httpsd 228 - 1418751787] api_monitor.c[1280] handle_req_v2_vdom -- new API request
(action='select',path='firewall',name='policy',vdom='root',user='admin')

[httpsd 228 - 1418751787] api_monitor.c[1286] handle_req_v2_vdom -- returning to original vdom

"root"

[httpsd 228 - 1418751787] http_config.c[581] ap_invoke_handler -- request completed

(handler='api_monitor_v2-handler' result==0)

FortiOS REST API Reference

Fortinet Inc.

Introduction

14

This debug will also include all requests to/from the FortiOS web interface, in addition to
REST API requests.

FortiOS REST API Reference

Fortinet Inc.

CMDB API

CMDB API is used to retrieve and modify CLI configurations. For example, create/edit/delete firewall policy.

URL path

All CMDB requests start with '/api/v2/cmdb/'. Below is the format of CMDB URL path.

/api/v2/cmdb/<path>/<name>/<mkey>(optional)/<child_name>(optional)/<child_mkey>(optional)/

CMDB URL path follows CLI commands syntax with an exception of vdom configuration.

CLI Command

path

name

mkey

child_
name

child_
mkey

Full URL

configure vdom

system

vdom

/api/v2/cmdb/system/vdom/

configure vdom, edit vdom1

system

vdom

vdom1

configure firewall schedule
recurring

firewall.
schedule

recurring

configure firewall policy

firewall

policy

configure firewall policy,
edit 1

configure firewall policy,
edit 1, set srcintf

configure firewall policy,
edit 1, delete srcintf lan

firewall

policy

firewall

policy

firewall

policy

1

1

1

/api/v2/cmdb/system/
vdom/vdom1/

/api/v2/cmdb/
firewall.schedule/recurring/

/api/v2/cmdb/firewall/policy/

/api/v2/cmdb/firewall/policy/1/

srcintf

srcintf

lan

/api/v2/cmdb/firewall/
policy/1/srcintf/

/api/v2/cmdb/firewall/
policy/1/srcintf/lan/

For operations on the entire table, mkey is not needed. For instance, add new entry, get all entries, purge table.

For operations on a specific resource, mkey is required. For example, edit/delete/clone/move a firewall policy.

For operations on the child table, child_name is required. For example, retrieve child table, purge child table, add new
entry to child table.

For operations on the child table entry, child_mkey is required. For example, delete/move child object.

URL parameters

In addition to the URL path, user can specify URL parameters which are appended to the URL path.

FortiOS REST API Reference

Fortinet Inc.

CMDB API

Generic parameters

The following URL parameters are generic to all CMDB requests.

URL parameter

Example

vdom=root

GET /api/v2/cmdb/firewall/address/?vdom=root

vdom=root,vdom1

GET /api/v2/cmdb/firewall/address/?vdom=root,vdom1

vdom=root&vdom=vdom1  GET

/api/v2/cmdb/firewall/address/?vdom=root&vdom=vdom1

vdom=*

GET /api/v2/cmdb/firewall/address/?vdom=*

16

Description

Return result/apply changes
on the specified vdom. If
vdom parameter is  not
provided, use current vdom
instead. If admin does not
have access to the vdom,
return permission error.

Return result/apply changes
on the specified vdoms. If
vdom parameter  is not
provided, use current vdom
instead. If admin does not
have access to the vdom,
return permission error.

Return result/apply changes
on the specified vdoms. If
vdom parameter  is not
provided, use current vdom
instead. If admin does not
have access to the vdom,
return permission error.

Return a list of results/apply
changes on all provisioned
vdoms. The  request is only
applicable to vdoms that the
admin has access to.

Specific parameters

Each CMDB method may require extra URL parameters which are unique to the method. Those extra parameters are
documented in the "Extra Parameters" section of each CMDB method.

Below are some examples.

URL parameter

Example

Description

action=schema

action=default

GET /api/v2/cmdb/firewall/policy
/?action=schema

GET /api/v2/cmdb/firewall/policy
/?action=default

Return schema of the resource table

Return default attributes of the resource

FortiOS REST API Reference

Fortinet Inc.

CMDB API

17

URL parameter

Example

Description

action=move

action=clone

skip=1

skip=1

PUT /api/v2/cmdb/firewall/policy/1
/?action=move&after=2

POST
/api/v2/cmdb/firewall/address/address1
/?action=clone&nkey=address1_clone

Move policy 1 to after policy 2

Clone 'address1' to 'address1_clone'

GET
/api/v2/cmdb/firewall/policy/?skip=1

Return a list of all firewall policy but only show
relevant attributes

GET
/api/v2/cmdb/firewall/policy/1/?skip=1

Return firewall policy 1 but only show relevant
attributes

format=policyid|action

GET /api/v2/cmdb/firewall/policy
/?format=policyid|action

Return a list of all firewall policy, however,
only show policyid and action for each policy

format=policyid|action

GET /api/v2/cmdb/firewall/policy
/1?format=policyid|action

Return firewall policy 1, however, only show
policyid and action

start=0&count=10

key=type&pattern=fqdn

filter=type==fqdn

GET /api/v2/cmdb/firewall/address
/?start=0&count=10

GET /api/v2/cmdb/firewall/address
/?key=type&pattern=fqdn

GET /api/v2/cmdb/firewall/address
/?filter=type==fqdn

filter=type==
fqdn,type==ipmask&filter=
visibility==enable

GET /api/v2/cmdb/firewall/address
/?filter=type==fqdn,type==
ipmask&filter=visibility==enable

Return the first 10 firewall addresses

Return all addresses with type fqdn

Return all addresses with type fqdn

Return all addresses with type fqdn or ipmask
which has visibility enabled

Body data

Beside URL parameters, some POST/PUT requests also require body data, which must be included in the HTTP body.
For example, to create/edit firewall address object, user needs to specify the new/edit object data.

GET/DELETE requests do not accept body data.

Request

Body data

Description

POST /api/v2/cmdb/firewall/address?vdom=root

{'name':"address1", 'type':
"ipmask", 'subnet': "1.1.1.0
255.255.255.0"}

create new firewall address
with the specified data

PUT
/api/v2/cmdb/firewall/address/address1?vdom=root

{'subnet': "2.2.2.0
255.255.255.0"}

edit firewall address with the
specified data

FortiOS REST API Reference

Fortinet Inc.

CMDB API

Limitation

18

If the body data has the same name as some reserved URL parameters, such as name, path, or action, the request
would fail due to the conflict. For example, firewall policy has 'name' and 'action' attribute which conflict with the
reserved URL parameter 'name' and 'action'. POST/PUT with normal method would fail with 405 error. A workaround is
to enclosed all object data in a 'json' keyword so the API can correctly identify object data. For example:

Request

Body data

POST
/api/v2/cmdb/firewall/policy?vdom
=root

{'name':"test_policy", 'srcintf': [{"name":"port1"}], 'dstintf':
[{"name":"port2"}],'srcaddr': [{"name":"all"}],'dstaddr':
[{"name":"all"}],'action':"accept",'status':"enable",'schedule':"always
",'service':[{'name':"ALL"}],'nat':"disable"}

POST
/api/v2/cmdb/firewall/policy?vdom
=root

{'json':{'name':"test_policy", 'srcintf': [{"name":"port1"}], 'dstintf':
[{"name":"port2"}],'srcaddr': [{"name":"all"}],'dstaddr':
[{"name":"all"}],'action':"accept",'status':"enable",'schedule':"always
",'service':[{'name':"ALL"}],'nat':"disable"}}

Descripti
on

This would
fail with
405 error

This would
work

Filter with multiple key/value pairs

Filtering multiple key/value pairs are also supported for all CMDB retrieval requests via 'filter' URL parameter.

Filter Syntax

Filters are defined in the following syntax: key operator pattern

Key

Operator Pattern

Full Request

Description

schedule

==

always

schedule

!=

always

GET
/api/v2/cmdb/firewall/policy/?filter=
schedule==always

GET
/api/v2/cmdb/firewall/policy/?filter=
schedule!=always

Only return firewall policy with
schedule 'always'

Return all firewall policy with
schedule other than 'always'

Filter Operators

Operator

Description

==

!=

Case insensitive match with pattern.

Does not match with pattern (case insensitive).

FortiOS REST API Reference

Fortinet Inc.

CMDB API

19

Operator

Description

=@

!@

<=

<

>=

>

Pattern found in object value (case insensitive).

Pattern not found in object value (case insensitive).

Value must be less than or equal to pattern.

Value must be less than pattern.

Value must be greater than or equal to pattern.

Value must be greater than pattern.

Combining Filters

Filters can be combined to create complex queries.

Combination Description

Example

Logical OR

Logical AND

Combining
AND and OR

Separate filters using commas ",". The
following example returns all policies
using the always schedule or the once
schedule.

Filter strings can be combined to create
logical AND queries by including multiple
filters in the request. This example
includes all policies using schedule
always AND action accept.

You can combine AND and OR filters
together to create more complex filters.
This example includes all policies using
schedule always AND action accept OR
action deny.

GET /api/v2/cmdb/firewall/policy?filter=
schedule==always,schedule==once

GET /api/v2/cmdb/firewall/policy/?filter=
schedule==always&filter=action==accept

GET /api/v2/cmdb/firewall/policy/?filter=
schedule==always&filter=action==accept,action==deny

Reserved Characters

The following characters need to be escaped if they are part of a filter pattern.

Character

Escaped Value

,

\

\,

\\

FortiOS REST API Reference

Fortinet Inc.

CMDB API

List of Methods

20

Type

HTTP Method Action

Summary

collection

resource

resource

resource

resource

resource

GET

GET

GET

GET

GET

GET

collection

DELETE

collection

POST

resource

resource

resource

resource

resource

resource

GET

PUT

PUT

POST

DELETE

GET

default

default

schema

schema

revision

move

clone

Select all entries in a CLI table.

Return the CLI default values for this object type.

Return the CLI default values for entire CLI tree.

Return the CLI schema for this object type.

Return schema for entire CLI tree.

Return the CMDB revision for this object type.

Delete all objects in this table.

Create an object in this table.

Select a specific entry from a CLI table.

Update this specific resource.

Move this specific resource.

Clone this specific resource.

Delete this specific resource.

Build API directory.

collection

GET

Summary

HTTP Method

ETag Caching

Response Type

Extra parameters

Select all entries in a CLI table.

GET

Enabled

array

Name

Type

Summary

datasource

boolean

Enable to include datasource information for each linked object.

start

count

int

int

Starting entry index.

Maximum number of entries to return.

Required

No

No

No

FortiOS REST API Reference

Fortinet Inc.

CMDB API

Name

Type

Summary

21

Required

with_meta

boolean

Enable to include meta information about each object (type id,
references, etc).

skip

format

boolean

Enable to call CLI skip operator to hide skipped properties.

string

List of property names to include in results, separated by | (i.e.
policyid|srcintf).

filter

string

key

pattern

scope

string

string

string

Comma separated list of key value pairs to filter on. Filters will be
logically OR'd together.

If present, objects will be filtered on property with this name.

If present, objects will be filtered on property with this value.

Scope [global|vdom|both*]

No

No

No

No

No

No

No

resource

GET: default

Summary

HTTP Method

ETag Caching

Response Type

GET: default

Summary

HTTP Method

Response Type

GET: schema

Summary

HTTP Method

ETag Caching

Response Type

Return the CLI default values for this object type.

GET

Enabled

object

Return the CLI default values for entire CLI tree.

GET

object

Return the CLI schema for this object type.

GET

Enabled

object

FortiOS REST API Reference

Fortinet Inc.

CMDB API

22

GET: schema

Summary

HTTP Method

Response Type

GET: revision

Summary

HTTP Method

ETag Caching

Response Type

DELETE

Summary

HTTP Method

POST

Summary

HTTP Method

GET

Summary

HTTP Method

ETag Caching

Response Type

Extra parameters

Return schema for entire CLI tree.

GET

object

Return the CMDB revision for this object type.

GET

Enabled

object

Delete all objects in this table.

DELETE

Create an object in this table.

POST

Select a specific entry from a CLI table.

GET

Enabled

array

Name

Type

Summary

datasource

boolean

Enable to include datasource information for each linked object.

with_meta

boolean

Enable to include meta information about each object (type id,
references, etc).

Required

No

No

FortiOS REST API Reference

Fortinet Inc.

Type

Summary

boolean

Enable to call CLI skip operator to hide skipped properties.

string

List of property names to include in results, separated by | (i.e.
policyid|srcintf).

23

Required

No

No

CMDB API

Name

skip

format

PUT

Summary

HTTP Method

PUT: move

Summary

HTTP Method

Extra parameters

Name

before

after

Type

string

string

POST: clone

Summary

HTTP Method

Extra parameters

Update this specific resource.

PUT

Move this specific resource.

PUT

Summary

The ID of the resource that this resource will be moved before.

The ID of the resource that this resource will be moved after.

Required

No

No

Clone this specific resource.

POST

Name

nkey

Type

string

Summary

The ID for the new resouce to be created.

Required

No

DELETE

Summary

HTTP Method

Delete this specific resource.

DELETE

FortiOS REST API Reference

Fortinet Inc.

24

CMDB API

GET

Summary

HTTP Method

Build API directory.

GET

Examples

Retrieve table

Method  URL

URL Parameters

Body
Data

Description

GET

GET

GET

GET

GET

GET

GET

/api/v2/cmdb/
firewall/address

?vdom=root

/api/v2/cmdb/
firewall/address

?vdom=root&start=
0&count=10&skip=1

/api/v2/cmdb/
firewall/address

?vdom=root&format=name|type

/api/v2/cmdb/
firewall/address

?vdom=root&key=
type&pattern=fqdn

/api/v2/cmdb/
firewall/address

?vdom=root&filter=
type==fqdn

/api/v2/cmdb/
firewall/address

?vdom=root&filter=
type==fqdn,type==iprange

/api/v2/cmdb/
firewall/address

?vdom=root&filter=type==
fqdn&filter=associated-
interface==lan

Retrieve all IPv4 firewall addresses,
vdom root

Retrieve the first 10 firewall
addresses, skip inapplicable
attributes, vdom root

Retrieve all firewall addresses but only
show name and type, vdom root

Retrieve all fqdn firewall addresses,
vdom root

Retrieve all fqdn firewall addresses,
vdom root

Retrieve all fqdn or iprange firewall
addresses, vdom root

Retrieve all fqdn firewall addresses
that belong to lan interface, vdom root

Retrieve table schema

Method  URL

URL Parameters  Body
Data

Description

GET

/api/v2/cmdb/firewall/address ?action=schema

Retrieve firewall address object's
schema

FortiOS REST API Reference

Fortinet Inc.

CMDB API

Retrieve table default

25

Method  URL

URL Parameters  Body
Data

Description

GET

/api/v2/cmdb/firewall/address ?action=default

Retrieve firewall address object's default

Purge table

Method  URL

URL Parameters  Body
Data

Description

DELETE

/api/v2/cmdb/firewall/address ?vdom=root

Purge all firewall addresses, vdom root

Retrieve object

Method  URL

URL Parameters

Body
Data

Description

GET

/api/v2/cmdb/
firewall/address/address1

?action=select&vdom=root

Retrieve only firewall address
'address1', vdom root

Create object

Method  URL

URL
Parameters

Body Data

Description

POST

/api/v2/cmdb/firewall/address

?vdom=root

{"name":"address1"} Create firewall address

POST

/api/v2/cmdb/application/list

?vdom=root

{"name":"profile1"}

'address1', root vdom

Create application list profile1,
vdom root

Edit object

Method  URL

URL
Parameters

Body Data

Description

PUT

PUT

/api/v2/cmdb/firewall/
address/address1

/api/v2/cmdb/firewall/
address/address1

?vdom=root

{"name":"address2"}

Rename 'address1' to 'address2',
vdom root

?vdom=root

{"comment":"test
comment"}

Edit 'address1' to update comment
'test comment', vdom root

FortiOS REST API Reference

Fortinet Inc.

CMDB API

Method  URL

PUT

/api/v2/cmdb/
application/list/profile1

Delete object

26

URL
Parameters

?vdom=root

Body Data

Description

{"entries":
[{"id":1,"application":
[{"id":31236},
{"id":31237}]}]}

Edit profile1 to add child object '1'
which has child table 'applications',
vdom root

Method  URL

URL Parameters

Body
Data

Description

DELETE

/api/v2/cmdb/firewall/
address/address1

?vdom=root

Delete firewall address 'address1', root vdom

Clone object

Method  URL

URL Parameters

Body
Data

Description

POST

/api/v2/cmdb/
firewall/address/address1

?vdom=root&action=
clone&nkey=address1_
clone

Clone 'address1' to 'address1_clone', root
vdom

Move object

Method  URL

URL Parameters

Body
Data

Description

PUT

/api/v2/cmdb/
firewall/policy/1

?vdom=root&action=
move&after=2

Move policy 1 to after policy 2, root vdom

Append child object

Method  URL

URL Parameters

POST

/api/v2/cmdb/application
/list/profile1/entries

?vdom=root

Body
Data

{"id":3}

Description

Add 3 to application profile1 child table
entries, vdom root

FortiOS REST API Reference

Fortinet Inc.

CMDB API

Edit child object

Method  URL

PUT

/api/v2/cmdb/application
/list/profile1/entries/3

Delete child object

27

URL
Parameters

?vdom=root

Body Data

Description

{"application":
[{"id":31236},
{"id":31237}]}

Edit child entry 3 to update child
application list, vdom root

Method  URL

URL Parameters

Body
Data

Description

DELETE /api/v2/cmdb/application

?vdom=root

/list/profile1/entries/3

Delete 3 from application profile1 child
table entries, vdom root

Purge child table

Method  URL

URL Parameters

Body
Data

Description

DELETE /api/v2/cmdb/application

?vdom=root

/list/profile1/entries

Purge application profile1 child table
entries, vdom root

Retrieve complex table

Method  URL

URL Parameters

Body
Data

Description

GET

/api/v2/cmdb/
vpn.ssl/settings

?action=select

Retrieve vpn ssl settings object

Edit complex table

Method  URL

PUT

/api/v2/cmdb/
vpn.ssl/settings

URL
Parameters

?vdom=root

Body Data

Description

{"authentication-
rule":[{"id":"1"},
{"id":"2"}]}

Edit complex object vpn.ssl.settings to
create/modify child table, vdom root

FortiOS REST API Reference

Fortinet Inc.

CMDB API

28

Send requests to multiple vdoms

Method  URL

URL Parameters

Body
Data

Description

GET

GET

GET

/api/v2/cmdb/
firewall/address

/api/v2/cmdb/
firewall/address

/api/v2/cmdb/
firewall/address

?vdom=root,vdom1

?vdom=root&vdom=vdom1

?vdom=*

Retrieve all IPv4 firewall addresses for
both root and vdom1

Retrieve all IPv4 firewall addresses for
both root and vdom1

Retrieve all IPv4 firewall addresses for all
accessible vdoms

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Monitor API is used to perform specific actions on endpoint resources. For example, retrieve/close firewall sessions,
restart/shutdown FGT, backup/restore config file.

URL path

All Monitor API requests start with '/api/v2/monitor/'. Below is the format of Monitor URL path:

/api/v2/monitor/<uri>/

Each Monitor endpoint has a specific URI, which are provided by the URI field of each endpoint.

URI

Full URL

Description

/firewall/policy/

GET
/api/v2/monitor/firewall/policy/

List traffic statistics for all IPv4 policies

/firewall/policy/reset

POST
/api/v2/monitor/firewall/policy/reset

Reset traffic statistics for all IPv4 policies

URL parameters

In addition to the URL path, user can specify URL parameters which are appended to the URL path.

Generic parameters

The following URL parameters are generic to all Monitor requests.

URL parameter

Example

Description

vdom=root

GET /api/v2/monitor/firewall/
policy/?vdom=root

vdom=root,vdom1

vdom=*

GET /api/v2/monitor/firewall/
policy/?vdom=root,vdom1

GET /api/v2/monitor/firewall/
policy/?vdom=*

Return result/apply changes on the specified vdom. If
vdom parameter is not provided, use current vdom
instead. If admin does not have access to the vdom,
return permission error.

Return a list of results/apply changes on provided vdoms.

Return a list of results/apply changes on all provisioned
vdoms. The request is only applicable to vdoms that the
admin has access to.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Specific parameters

30

Each Monitor endpoint may require extra URL parameters which are unique to the endpoint. Those extra parameters
are documented in the "Extra Parameters" section of each endpoint.

Required parameters are marked with "required: true" flag.

Below are some examples.

URL parameter

Example

Description

count=-1

GET /api/v2/monitor/firewall/session?count=1

Return all ipv4 firewall sessions

ip_
version=ipv6&count=10

GET /api/v2/monitor/firewall/session?ip_
version=ipv6&count=10

Return the first 10 ipv6 firewall
sessions

Body data

Beside URL parameters, some POST requests also require body data, which must be included in the HTTP body. The
extra body data are documented in "Extra Parameters" section of each endpoint.

GET requests do not accept body data.

Required body data are marked with "required: true" flag.

Below are some examples.

Request

Body Data

Description

POST /api/v2/monitor/firewall/
session/close?vdom=root

{'pro': "udp", 'saddr': "192.168.100.110",
'daddr': "96.45.33.73", 'sport': 55933,
'dport': 8888}

Close the specific ipv4 firewall
sessions

File upload

File upload is supported for some endpoints. For example, upload VM license, restore config file. The upload file must
be stored in the HTTP body. There are two different methods to do so: via JSON data or multi-part file.

File upload via JSON data

The upload file can be encoded directly into the HTTP body as JSON data using the 'file_content' field.

The JSON data must be encoded in base64 format.

For instance, below is how you can upload/restore config file via JSON data using Python Requests module.

self.session.post(url='/api/v2/monitor/system/config/restore',

params={"vdom": "vdom1"},
data={"source": "upload",

FortiOS REST API Reference

Fortinet Inc.

Monitor API

31

"scope": "vdom",
"file_content": b64encode(open("vd1.conf.txt", "r").read())})

File upload via multi-part file

Another way to store upload file in HTTP body is to include it as a multi-part file.

The multi-part file does not need to be encoded in base64 format.

For instance, below is how you can upload/restore config file via multi-part file using Python Requests module.

self.session.post(url='/api/v2/monitor/system/config/restore',

params={"vdom": "vdom1"},
data={"source": "upload",

"scope": "vdom"},
files=[('random_name',

('random_conf.conf', open("vd1.conf.txt", "r"), 'text/plain'))])

File download

File download is also supported in some endpoints. For example, download CA certificate, backup config file.

The downloaded file is stored in the response's raw content, not JSON data.

For example, here is the request to download global certificate name Fortinet_Factory, type local, scope
global:

GET /api/v2/monitor/system/certificate/download?mkey=Fortinet_

Factory&type=local&scope=global

File download via browser

When sending file download request via a browser, the browser automatically checks the response's header for
'Content-Disposition': attachment. If present, the browser will download the file to local directory using the
name.

File download via script

When sending file download request via a script, the script will need to manually perform the above steps to convert the
response's content into a file. For example, the script needs to check the response header for 'Content-
Disposition': attachment, and write the content into a local file with the given name.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

List of Methods

32

URI

HTTP Method Summary

endpoint-control/profile/xml/

GET

List XML representation for each endpoint-control profile.

endpoint-control/registration-
password/check/

endpoint-control/record-
list/select/

endpoint-
control/registration/summary/

endpoint-
control/registration/quarantine/

endpoint-
control/registration/unquarantine/

endpoint-
control/registration/block/

endpoint-
control/registration/unblock/

endpoint-
control/registration/deregister/

POST

GET

GET

Check if provided registration password is valid for current
VDOM.

List endpoint records.

Summary of FortiClient registrations.

POST

Quarantine endpoint by FortiClient UID or MAC.

POST

Unquarantine endpoint by FortiClient UID or MAC.

POST

Block endpoint by FortiClient UID or MAC.

POST

Unblock endpoint by FortiClient UID or MAC.

POST

Deregister endpoint by FortiClient UID or MAC.

endpoint-control/installer/select/

GET

List available FortiClient installers.

endpoint-
control/installer/download/

endpoint-
control/avatar/download/

firewall/health/select/

firewall/local-in/select/

firewall/acl/select/

firewall/acl/clear_counters/

firewall/acl6/select/

firewall/acl6/clear_counters/

firewall/internet-service-
match/select/

firewall/internet-service-
details/select/

firewall/policy/select/

GET

GET

GET

GET

GET

POST

GET

POST

GET

GET

GET

Download a FortiClient installer via FortiGuard.

Download an endpoint avatar image.

List configured load balance server health monitors.

List implicit and explicit local-in firewall policies.

List counters for all IPv4 ACL.

Reset counters for one or more IPv4 ACLs by policy ID.

List counters for all IPv6 ACL.

Reset counters for one or more IPv6 ACLs by policy ID.

List internet services that exist at a given IP or Subnet.

List all details for a given Internet Service ID.

List traffic statistics for IPv4 policies.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

33

URI

HTTP Method Summary

firewall/policy/reset/

POST

Reset traffic statistics for all IPv4 policies.

firewall/policy/clear_counters/

POST

Reset traffic statistics for one or more IPv4 policies by policy
ID.

firewall/policy6/select/

firewall/policy6/reset/

GET

POST

firewall/policy6/clear_counters/

POST

firewall/proxy-policy/select/

firewall/proxy-policy/clear_
counters/

GET

POST

firewall/policy-lookup/select/

GET

firewall/session/select/

firewall/session/clear_all/

GET

POST

firewall/session/close/

POST

firewall/shaper/select/

firewall/shaper/reset/

GET

POST

List traffic statistics for IPv6 policies.

Reset traffic statistics for all IPv6 policies.

Reset traffic statistics for one or more IPv6 policies by policy
ID.

List traffic statistics for all explicit proxy policies.

Reset traffic statistics for one or more explicit proxy policies by
policy ID.

Performs a policy lookup by creating a dummy packet and
asking the kernel which policy would be hit.

List all active firewall sessions (optionally filtered).

Immediately clear all active IPv4 and IPv6 sessions and IPS
sessions of current VDOM.

Close a specific firewall session that matches all provided
criteria.

List of statistics for configured firewall shared traffic shapers.

Reset statistics for all configured traffic shapers.

firewall/per-ip-shaper/select/

GET

List of statistics for configured firewall per-IP traffic shapers.

firewall/per-ip-shaper/reset/

POST

Reset statistics for all configured firewall per-IP traffic shapers.

firewall/load-balance/select/

firewall/address-fqdns/select/

firewall/address-fqdns6/select/

firewall/ippool/select/

GET

GET

GET

GET

firewall/address-dynamic/select/

GET

firewall/address6-dynamic/select/ GET

geoip/geoip-query/select/

GET

List all firewall load balance servers.

List of FQDN address objects and the IPs they resolved to.

List of IPv6 FQDN address objects and the IPs they resolved
to.

List IPv4 pool statistics.

List of Fabric Connector address objects and the IPs they
resolve to.

List of IPv6 Fabric Connector address objects and the IPs they
resolve to.

Retrieve location details for IPs queried against FortiGuard's
geoip service.

ips/rate-based/select/

license/status/select/

GET

GET

Returns a list of rate-based signatures in IPS package.

Get current license & registration status.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

34

URI

HTTP Method Summary

license/database/upgrade/

POST

Upgrade a license database on this device using uploaded file.

license/forticare-resellers/select/

GET

Get current FortiCare resellers for the requested country.

license/forticare-org-list/select/

log/current-disk-usage/select/

log/device/state/

log/forticloud/select/

log/fortianalyzer/select/

log/fortianalyzer-queue/select/

log/hourly-disk-usage/select/

log/historic-daily-remote-
logs/select/

log/stats/select/

log/stats/reset/

log/forticloud-report/download/

log/ips-archive/download/

log/policy-archive/download/

log/av-archive/download/

log/event/select/

registration/forticloud/login/

registration/forticloud/create/

registration/forticloud/logout/

GET

GET

GET

GET

GET

GET

GET

GET

GET

POST

GET

GET

GET

GET

GET

POST

POST

POST

Get FortiCare organization size and industry lists.

Return current used, free and total disk bytes.

Retrieve information on state of log devices.

Return FortiCloud log status.

Return FortiAnalyzer/FortiManager log status.

Retrieve information on FortiAnalyzer's queue state. Note:-
FortiAnalyzer logs are queued only if upload-option is realtime.

Return historic hourly disk usage in bytes.

Returns the amount of logs in bytes sent daily to a remote
logging service (FortiCloud or FortiAnalyzer).

Return number of logs sent by category per day for a specific
log device.

Reset logging statistics for all log devices.

Download PDF report from FortiCloud.

Download IPS/application control packet capture files. Uses
configured log display device.

Download policy-based packet capture archive.

Download file quarantined by AntiVirus.

List all event log descriptions.

Login to FortiCloud.

Create a FortiCloud account.

Logout from FortiCloud.

registration/forticloud/disclaimer/ GET

Retrieve the FortiCloud disclaimer.

registration/forticloud/domains/

GET

Retrieve a list of FortiCloud login domains.

registration/forticare/login/

registration/forticare/create/

POST

POST

Login to FortiCare.

Create a new FortiCare account.

registration/forticare/add-license/ POST

Add a FortiCare license.

router/ipv4/select/

router/ipv6/select/

GET

GET

List all active IPv4 routing table entries.

List all active IPv6 routing table entries.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

35

URI

HTTP Method Summary

router/statistics/select/

router/lookup/select/

router/policy/select/

router/policy6/select/

system/admin/toggle-vdom-
mode/

GET

GET

GET

GET

POST

system/api-user/generate-key/

POST

Retrieve routing table statistics, including number of matched
routes.

Performs a route lookup by querying the routing table.

Retrieve a list of active IPv4 policy routes.

Retrieve a list of active IPv6 policy routes.

Toggles VDOM mode on/off. Enables or disables VDOM mode
if it is disabled or enabled respectively.

Generate a new api-key for the specified api-key-auth admin.
The old api-key will be replaced. The response contains the
only chance to read the new api-key plaintext in the api_key
field.

system/config-revision/select/

GET

Returns a list of system configuration revisions.

system/config-revision/update-
comments/

POST

Updates comments for a system configuration file.

system/config-revision/delete/

POST

Deletes one or more system configuration revisions.

system/config-revision/file/

system/config-revision/info/

GET

GET

Download a specific configuration revision.

Retrieve meta information for a specific configuration revision.

system/config-revision/save/

POST

Create a new config revision checkpoint.

system/current-admins/select/

GET

Return a list of currently logged in administrators.

system/disconnect-
admins/select/

system/time/set/

system/time/select/

system/os/reboot/

system/os/shutdown/

POST

Disconnects logged in administrators.

POST

GET

POST

POST

Sets current system time stamp.

Gets current system time stamp.

Immediately reboot this device.

Immediately shutdown this device.

system/global-resources/select/

GET

system/vdom-resource/select/

GET

system/dhcp/select/

system/dhcp/revoke/

system/dhcp6/revoke/

system/firmware/select/

GET

POST

POST

GET

Retrieve current usage of global resources as well as both the
default and user configured maximum values.

Retrieve VDOM resource information, including CPU and
memory usage.

Returns a list of all DHCP IPv4 and IPv6 DHCP leases.

Revoke IPv4 DHCP leases.

Revoke IPv6 DHCP leases.

Retrieve a list of firmware images available to use for upgrade
on this device.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

36

URI

HTTP Method Summary

system/firmware/upgrade/

POST

Upgrade firmware image on this device using uploaded file.

system/firmware/upgrade-paths/ GET

Retrieve a list of supported firmware upgrade paths.

system/fsck/start/

POST

Set file system check flag so that it will be executed on next
device reboot.

system/storage/select/

GET

Retrieve information for the non-boot disk.

system/change-password/select/

POST

Save admin and guest-admin passwords.

system/password-policy-
conform/select/

system/csf/select/

system/csf/pending-
authorizations/

system/modem/select/

system/modem/reset/

system/modem/connect/

system/modem/disconnect/

system/modem/update/

system/3g-modem/select/

system/resource/usage/

system/sniffer/select/

system/sniffer/restart/

system/sniffer/start/

system/sniffer/stop/

system/sniffer/download/

POST

Check whether password conforms to the password policy.

GET

GET

GET

POST

POST

POST

POST

GET

GET

GET

POST

POST

POST

GET

Retrieve a full tree of downstream FortiGates registered to the
Security Fabric.

Retrieve FortiGates with pending authorizations for joining the
Security Fabric. Note:- This list is currently available on
Security Fabric root only.

Retrieve statistics for internal/external configured modem.

Reset statistics for internal/external configured modem.

Trigger a connect for the configured modem.

Trigger a disconnect for the configured modem.

Update supported modem list from FortiGuard.

List all 3G modems available via FortiGuard.

Retreive current and historical usage data for a provided
resource.

Return a list of all configured packet captures.

Restart specified packet capture.

Start specified packet capture.

Stop specified packet capture.

Download a stored packet capture.

system/automation-stitch/stats/

GET

Stats for automation stitches.

system/automation-stitch/test/

POST

Triggers an automation stitch for testing purposes.

switch-controller/managed-
switch/select/

GET

Retrieve statistics for configured FortiSwitches

switch-controller/managed-
switch/update/

POST

Update administrative state for a given FortiSwitch (enable or
disable authorization).

FortiOS REST API Reference

Fortinet Inc.

Monitor API

37

URI

HTTP Method Summary

switch-controller/managed-
switch/restart/

switch-controller/managed-
switch/poe-reset/

switch-controller/managed-
switch/faceplate-xml/

switch-controller/managed-
switch/factory-reset/

switch-controller/managed-
switch/dhcp-snooping/

switch-controller/fsw-
firmware/select/

switch-controller/fsw-
firmware/download/

switch-controller/fsw-
firmware/push/

switch-controller/fsw-
firmware/upload/

switch-controller/detected-
device/select/

switch-controller/validate-switch-
prefix/select/

system/interface/select/

system/interface/dhcp-status/

POST

Restart a given FortiSwitch.

POST

Reset PoE on a given FortiSwitch's port.

GET

Retrieve XML for rendering FortiSwitch faceplate widget.

POST

Send 'Factory Reset' command to a given FortiSwitch.

GET

GET

POST

Retrieve DHCP servers monitored by FortiSwitches.

Retrieve a list of recommended firmware for managed
FortiSwitches.

Download FortiSwitch firmware from FortiGuard to the
FortiGate according to FortiSwitch image ID.

POST

Push FortiSwitch firmware to the given device.

POST

GET

GET

GET

GET

Upload FortiSwitch firmware to the management FortiGate
and then push to target FortiSwitches.

Retrieve a list of devices detected on all switches.

Validate a FortiSwitch serial number prefix.

Retrieve statistics for all system interfaces.

Retrieve the DHCP client status of an interface.

system/interface/dhcp-renew/

POST

Renew DHCP lease of an interface.

system/available-
interfaces/select/

system/acquired-dns/select/

system/resolve-fqdn/select/

system/nat46-ippools/select/

system/usb-log/select/

system/usb-log/start/

system/usb-log/stop/

GET

GET

GET

GET

GET

POST

POST

Retrieve a list of all interfaces along with some meta
information regarding their availability.

Retrieve a list of interfaces and their acquired DNS servers.

Resolves the provided FQDNs to FQDN -> IP mappings.

Retrieve a list of all IPv6 IP pools that are valid for NAT 46
policies.

Retrieve information about connected USB drives, including
estimated log sizes.

Start backup of logs from current VDOM to USB drive.

Stop backup of logs to USB drive.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

38

URI

HTTP Method Summary

system/usb-device/eject/

system/ipconf/select/

system/fortiguard/update/

POST

GET

POST

Eject USB drives for safe removal.

Determine if there is an IP conflict for a specific IP using ARP.

Immediately update status for FortiGuard services.

system/fortiguard/clear-statistics/ POST

Immediately clear all FortiGuard statistics.

system/fortiguard/test-
availability/

POST

Test availability of FortiGuard services.

system/fortiguard/server-info/

system/fortimanager/status/

GET

GET

system/fortimanager/config/

POST

Get FortiGuard server list and information.

Get FortiManager status.

Configure FortiManager IP. Register FortiManager if
'fortimanager_ip' is provided. Unregister FortiManager if only
'unregister' parameter is specified and set to true.

GET

Get FortiManager backup summary.

POST

Import or update from FortiManager objects.

system/fortimanager/backup-
summary/

system/fortimanager/backup-
action/

system/fortimanager/backup-
details/

system/available-
certificates/select/

system/certificate/download/

system/debug/download/

system/com-log/dump/

system/com-log/update/

system/com-log/download/

system/botnet/stat/

system/botnet/select/

GET

GET

GET

GET

POST

GET

GET

GET

GET

system/botnet-domains/select/

GET

system/botnet-domains/stat/

GET

Get the properties of a FortiManager object.

Get available certificates.

Download certificate.

Download debug report for technical support.

Dump system com-log to file.

Fetch system com-log file dump progress.

Download com-log file (after file dump is complete).

Retrieve statistics for FortiGuard botnet database.

List all known IP-based botnet entries in FortiGuard botnet
database.

List all known domain-based botnet entries in FortiGuard
botnet database.

List statistics on domain-based botnet entries in FortiGuard
botnet database.

system/botnet-domains/hits/

system/ha-statistics/select/

system/ha-history/select/

GET

GET

GET

List hit botnet domains with hit count > 0.

List of statistics for members of HA cluster.

Get HA cluster historical logs.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

39

URI

HTTP Method Summary

system/ha-checksums/select/

system/ha-peer/select/

system/ha-peer/update/

system/ha-peer/disconnect/

system/link-monitor/select/

system/compliance/run/

system/config/restore/

system/config/backup/

system/config/usb-filelist/

system/sandbox/stats/

system/sandbox/status/

system/sandbox/test-connect/

system/object/usage/

system/object-tagging/usage/

system/status/select/

system/timezone/select/

GET

GET

POST

POST

GET

POST

POST

GET

GET

GET

GET

GET

GET

GET

GET

GET

List of checksums for members of HA cluster.

Get configuration of peer(s) in HA cluster. Uptime is expressed
in seconds.

Update configuration of peer in HA cluster.

Update configuration of peer in HA cluster.

Retrieve per-interface statistics for active link monitors.

Immediately run compliance checks for the selected VDOM.

Restore system configuration from uploaded file or from USB.

Backup system config

List configuration files available on connected USB drive.

Retrieve sandbox statistics.

Retrieve sandbox status.

Test the connectivity of a given FortiSandbox IP.

Retrieve all objects that are currently using as well as objects
that can use the given object.

Retrieve usage count for tags in all tag categories.

Retrieve basic system status.

Get world timezone and daylight saving time.

system/vmlicense/upload/

POST

Update VM license using uploaded file. Reboots immediately if
successful.

system/sensor-info/select/

system/security-rating/select/

GET

GET

Retrieve system sensor status.

Retrieve a Security Rating result. Without file specified, returns
the most recent result.

system/security-rating/history/

GET

Retrieve Security Rating history.

system/security-rating/trigger/

POST

Trigger a Security Rating.

system/security-rating/status/

system/security-rating/lang/

system/fortiguard-
blacklist/select/

system/check-port-
availability/select/

system/external-resource/entry-
list/

GET

GET

GET

GET

GET

Check if a Security Rating is currently running.

Returns the requested Security Rating language mapping.

Retrieve blacklist information for a specified IP.

Check whether a list of TCP port ranges is available for a
certain service.

Retrieve resource file status with a list of valid/invalid entries
(skip empty and comment lines) for the specific external
resource.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

40

URI

HTTP Method Summary

extender-
controller/extender/select/

extender-
controller/extender/reset/

GET

Retrieve statistics for specific configured FortiExtender units.

POST

Reset a specific FortiExtender unit.

system/sdn-connector/status/

GET

Retrieve connection status for SDN connectors.

system/sdn-connector/validate-
gcp-key/

user/firewall/select/

user/firewall/deauth/

user/banned/select/

user/banned/clear_users/

user/banned/add_users/

user/banned/clear_all/

user/fortitoken/select/

user/fortitoken/activate/

user/detected-device/select/

user/device/select/

user/device-type/select/

user/device-category/select/

user/fortitoken/refresh/

user/fortitoken/provision/

POST

GET

POST

GET

POST

POST

POST

GET

POST

GET

GET

GET

GET

POST

POST

Validate a string representing a private key from GCP in PEM
format.

List authenticated firewall users.

Deauthenticate single, multiple, or all firewall users.

Return a list of all banned users by IP.

Immediately clear a list of specific banned users by IP.

Immediately add one or more users to the banned list.

Immediately clear all banned users.

Retrieve a map of FortiTokens and their status.

Activate a set of FortiTokens by serial number.

Retrieve a list of detected devices.

Retrieve a list of detected devices.

Retrieve a list of device types.

Retrieve a list of device categories.

Refresh a set of FortiTokens by serial number.

Provision a set of FortiTokens by serial number.

user/fortitoken/send-activation/

POST

Send a FortiToken activation code to a user via SMS or Email.

user/fortitoken/import-trial/

POST

Import trial mobile FortiTokens.

user/fortitoken/import-mobile/

POST

Import a list of tokens from FortiGuard to the FortiGate unit.

user/fortitoken/import-seed/

user/fsso/refresh-server/

user/fsso/select/

user/radius/test-connect/

user/tacacs-plus/test/

utm/rating-lookup/select/

POST

POST

GET

POST

POST

GET

Import a FortiToken seed file.

Refresh remote agent group list for all fsso agents.

Get a list of fsso and fsso polling status.

Test the connectivity of the given RADIUS server and,
optionally, the validity of a username & password.

Test the connectivity of the given TACACS+ server.

Lookup FortiGuard rating for a specific URL.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

41

URI

HTTP Method Summary

utm/app-lookup/select/

utm/application-
categories/select/

utm/antivirus/stats/

GET

GET

GET

Query remote FortiFlow database to resolve hosts to
application control entries.

Retrieve a list of application control categories.

Retrieve antivirus scanning statistics.

virtual-wan/health-check/select/

GET

Retrieve health-check statistics for each SD-WAN link.

virtual-wan/members/select/

webfilter/override/select/

webfilter/override/delete/

webfilter/malicious-urls/select/

webfilter/malicious-urls/stat/

GET

GET

POST

GET

GET

Retrieve interface statistics for each SD-WAN link.

List all administrative and user initiated webfilter overrides.

Delete a configured webfilter override.

List all URLs in FortiSandbox malicious URL database.

Retrieve statistics for the FortiSandbox malicious URL
database.

webfilter/category-quota/select/

GET

Retrieve quota usage statistics for webfilter categories.

webfilter/category-quota/reset/

POST

Reset webfilter quota for user or IP.

GET

Return FortiGuard web filter categories.

webfilter/fortiguard-
categories/select/

webfilter/trusted-urls/select/

vpn/ipsec/select/

vpn/ipsec/tunnel_up/

vpn/ipsec/tunnel_down/

vpn/ipsec/tunnel_reset_stats/

vpn/one-click/members/

GET

GET

POST

POST

POST

GET

vpn/one-click/status/

GET

vpn/ssl/select/

vpn/ssl/clear_tunnel/

vpn/ssl/delete/

vpn/ssl/stats/

vpn-certificate/ca/import/

vpn-certificate/crl/import/

vpn-certificate/local/import/

GET

POST

POST

GET

POST

POST

POST

List all URLs in FortiGuard trusted URL database.

Return an array of active IPsec VPNs.

Bring up a specific IPsec VPN tunnel.

Bring down a specific IPsec VPN tunnel.

Reset statistics for a specific IPsec VPN tunnel.

Get information on devices registered in the Overlay Controller
VPN cloud assisted group.

Get the last status message from FortiCloud Overlay
Controller VPN cloud service.

Retrieve a list of all SSL-VPN sessions and sub-sessions.

Remove all active tunnel sessions in current virtual domain.

Terminate the provided SSL-VPN session.

Return statistics about the SSL-VPN.

Import CA certificate.

Import certificate revocation lists (CRL) from file content.

Import local certificate.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

42

URI

HTTP Method Summary

vpn-certificate/remote/import/

POST

Import remote certificate.

vpn-certificate/csr/generate/

POST

Generate a certificate signing request (CSR) and a private key.
The CSR can be retrieved / downloaded from CLI, GUI and
REST API.

wanopt/history/select/

wanopt/history/reset/

wanopt/webcache/select/

wanopt/webcache/reset/

wanopt/peer_stats/select/

wanopt/peer_stats/reset/

webproxy/pacfile/download/

webcache/stats/select/

webcache/stats/reset/

wifi/client/select/

wifi/managed_ap/select/

GET

POST

GET

POST

GET

POST

GET

GET

POST

GET

GET

wifi/managed_ap/set_status/

POST

wifi/firmware/select/

GET

wifi/firmware/download/

POST

wifi/firmware/push/

wifi/firmware/upload/

POST

POST

Retrieve WAN opt. statistics history.

Reset WAN opt. statistics.

Retrieve webcache statistics history.

Reset webcache statistics.

Retrieve a list of WAN opt peer statistics.

Reset WAN opt peer statistics.

Download webproxy PAC file.

Retrieve webcache statistics.

Reset all webcache statistics.

Retrieve a list of connected WiFi clients.

Retrieve a list of managed FortiAPs.

Update administrative state for a given FortiAP (enable or
disable authorization).

Retrieve a list of current and recommended firmware for
FortiAPs in use.

Download FortiAP firmware from FortiGuard to the FortiGate
according to FortiAP image ID.

Push FortiAP firmware to the given device.

Upload FortiAP firmware to the management FortiGate and
then push to target FortiAPs.

wifi/managed_ap/restart/

POST

Restart a given FortiAP.

wifi/ap_status/select/

wifi/interfering_ap/select/

wifi/euclid/select/

wifi/euclid/reset/

wifi/rogue_ap/select/

wifi/rogue_ap/clear_all/

wifi/rogue_ap/set_status/

wifi/spectrum/select/

GET

GET

GET

POST

GET

POST

POST

GET

Retrieve statistics for all managed FortiAPs.

Retrieve a list of interfering APs for one FortiAP radio.

Retrieve presence analytics statistics.

Reset presence analytics statistics.

Retrieve a list of detected rogue APs.

Clear all detected rogue APs.

Mark detected APs as rogue APs.

Retrieve spectrum analysis information for a specific FortiAP.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

endpoint-control

profile: xml

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

mkey

Type

string

43

List XML representation for each endpoint-control profile.

endpoint-control/profile/xml/

GET

xml

utmgrp.endpoint-control

array

Summary

Name of endpoint-control profile.

Required

No

registration-password: check

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Check if provided registration password is valid for current VDOM.

endpoint-control/registration-password/check/

POST

check

utmgrp.endpoint-control

boolean

Name

password

Type

string

Summary

Registration password to test.

Required

Yes

record-list: select

Summary

URI

HTTP Method

Action

List endpoint records.

endpoint-control/record-list/select/

GET

select

FortiOS REST API Reference

Fortinet Inc.

Monitor API

44

Access Group

Response Type

Extra parameters

Name

intf_name

Type

string

registration: summary

utmgrp.endpoint-control

array

Summary

Required

Filter: Name of interface where the endpoint was detected.

No

Summary

URI

HTTP Method

Action

Summary of FortiClient registrations.

endpoint-control/registration/summary/

GET

summary

Access Group

utmgrp.endpoint-control

registration: quarantine

Summary

URI

HTTP Method

Action

Quarantine endpoint by FortiClient UID or MAC.

endpoint-control/registration/quarantine/

POST

quarantine

Access Group

utmgrp.endpoint-control

Extra parameters

Name

uid

uid

mac

mac

Type

array

string

array

string

registration: unquarantine

Summary

Required

Array of FortiClient UIDs to quarantine.

Single FortiClient UID to quarantine.

Array of MACs to quarantine.

Single MAC to quarantine.

No

No

No

No

Summary

Unquarantine endpoint by FortiClient UID or MAC.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

URI

HTTP Method

Action

endpoint-control/registration/unquarantine/

POST

unquarantine

Access Group

utmgrp.endpoint-control

45

Extra parameters

Name

uid

uid

mac

mac

Type

array

string

array

string

registration: block

Summary

URI

HTTP Method

Action

Summary

Required

Array of FortiClient UIDs to unquarantine.

Single FortiClient UID to unquarantine.

Array of MACs to unquarantine.

Single MAC to unquarantine.

No

No

No

No

Block endpoint by FortiClient UID or MAC.

endpoint-control/registration/block/

POST

block

Access Group

utmgrp.endpoint-control

Extra parameters

Name

uid

uid

mac

mac

Type

array

string

array

string

registration: unblock

Summary

Array of FortiClient UIDs to block.

Single FortiClient UID to block.

Array of MACs to block.

Single MAC to block.

Required

No

No

No

No

Summary

URI

HTTP Method

Action

Unblock endpoint by FortiClient UID or MAC.

endpoint-control/registration/unblock/

POST

unblock

Access Group

utmgrp.endpoint-control

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Extra parameters

Name

uid

uid

mac

mac

Type

array

string

array

string

registration: deregister

46

Summary

Required

Array of FortiClient UIDs to unblock.

Single FortiClient UID to unblock.

Array of MACs to unblock.

Single MAC to unblock.

No

No

No

No

Summary

URI

HTTP Method

Action

Deregister endpoint by FortiClient UID or MAC.

endpoint-control/registration/deregister/

POST

deregister

Access Group

utmgrp.endpoint-control

Extra parameters

Name

uid

uid

mac

mac

Type

array

string

array

string

installer: select

Summary

URI

HTTP Method

Action

Summary

Required

Array of FortiClient UIDs to deregister.

Single FortiClient UID to deregister.

Array of MACs to deregister.

Single MAC to deregister.

No

No

No

No

List available FortiClient installers.

endpoint-control/installer/select/

GET

select

Access Group

utmgrp.endpoint-control

Extra parameters

Name

Type

Summary

Required

min_version

string

Filter: Minimum installer version. (String of the format n[.n[.n]]).

No

FortiOS REST API Reference

Fortinet Inc.

47

Monitor API

installer: download

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Download a FortiClient installer via FortiGuard.

endpoint-control/installer/download/

GET

download

utmgrp.endpoint-control

object

Name

mkey

Type

string

Summary

Name of installer (image_id).

Required

Yes

avatar: download

Summary

URI

HTTP Method

Action

Access Group

ETag Caching

Response Type

Extra parameters

Name

uid

user

alias

Type

string

string

string

default

string

Download an endpoint avatar image.

endpoint-control/avatar/download/

GET

download

utmgrp.endpoint-control

Enabled

object

Summary

Single FortiClient UID.

User name of the endpoint.

Alias of the device. Used to lookup device avatar when endpoint
avatar is not available.

Default avatar name ['authuser'|'unauthuser'|'authuser_
72'|'unauthuser_72']. Default avatar when endpoint / device avatar is
not available. If default is not set, Not found 404 is returned.

Required

No

No

No

No

FortiOS REST API Reference

Fortinet Inc.

48

Monitor API

firewall

health: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

local-in: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

acl: select

Summary

URI

HTTP Method

Action

List configured load balance server health monitors.

firewall/health/select/

GET

select

sysgrp.cfg

array

List implicit and explicit local-in firewall policies.

firewall/local-in/select/

GET

select

fwgrp.policy

array

List counters for all IPv4 ACL.

firewall/acl/select/

GET

select

Access Group

fwgrp.policy

acl: clear_counters

Summary

URI

Reset counters for one or more IPv4 ACLs by policy ID.

firewall/acl/clear_counters/

HTTP Method

POST

Action

Access Group

clear_counters

fwgrp.policy

FortiOS REST API Reference

Fortinet Inc.

Monitor API

49

Extra parameters

Name

policy

policy

Type

array

int

acl6: select

Summary

URI

HTTP Method

Action

Summary

Array of policy IDs to reset.

Single policy ID to reset.

List counters for all IPv6 ACL.

firewall/acl6/select/

GET

select

Access Group

fwgrp.policy

acl6: clear_counters

Summary

URI

Reset counters for one or more IPv6 ACLs by policy ID.

firewall/acl6/clear_counters/

HTTP Method

POST

Action

Access Group

Extra parameters

clear_counters

fwgrp.policy

Name

policy

policy

Type

array

int

Summary

Array of policy IDs to reset.

Single policy ID to reset.

internet-service-match: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

List internet services that exist at a given IP or Subnet.

firewall/internet-service-match/select/

GET

select

fwgrp.address

array

Required

No

No

Required

No

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

50

Extra parameters

Name

ip

mask

Type

string

string

Summary

IP (in dot-decimal notation).

IP Mask (in dot-decimal notation).

Required

Yes

Yes

internet-service-details: select

Summary

URI

HTTP Method

Action

List all details for a given Internet Service ID.

firewall/internet-service-details/select/

GET

select

Access Group

fwgrp.address

Extra parameters

Name

id

Type

int

policy: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Summary

ID of the Internet Service to get details for.

Required

Yes

List traffic statistics for IPv4 policies.

firewall/policy/select/

GET

select

fwgrp.policy

array

Name

policyid

Type

int

Summary

Filter: Policy ID.

Required

No

policy: reset

Summary

Reset traffic statistics for all IPv4 policies.

FortiOS REST API Reference

Fortinet Inc.

51

Required

No

No

Monitor API

URI

HTTP Method

Action

firewall/policy/reset/

POST

reset

Access Group

fwgrp.policy

policy: clear_counters

Summary

URI

Reset traffic statistics for one or more IPv4 policies by policy ID.

firewall/policy/clear_counters/

HTTP Method

POST

Action

Access Group

Extra parameters

clear_counters

fwgrp.policy

Name

policy

policy

Type

array

int

Summary

Array of policy IDs to reset.

Single policy ID to reset.

policy6: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

List traffic statistics for IPv6 policies.

firewall/policy6/select/

GET

select

fwgrp.policy

array

Name

policyid

Type

int

Summary

Filter: Policy ID.

Required

No

FortiOS REST API Reference

Fortinet Inc.

52

Required

No

No

Monitor API

policy6: reset

Summary

URI

HTTP Method

Action

Reset traffic statistics for all IPv6 policies.

firewall/policy6/reset/

POST

reset

Access Group

fwgrp.policy

policy6: clear_counters

Summary

URI

Reset traffic statistics for one or more IPv6 policies by policy ID.

firewall/policy6/clear_counters/

HTTP Method

POST

Action

Access Group

Extra parameters

clear_counters

fwgrp.policy

Name

policy

policy

Type

array

int

Summary

Array of policy IDs to reset.

Single policy ID to reset.

proxy-policy: select

Summary

URI

HTTP Method

Action

List traffic statistics for all explicit proxy policies.

firewall/proxy-policy/select/

GET

select

Access Group

fwgrp.policy

proxy-policy: clear_counters

Summary

URI

Reset traffic statistics for one or more explicit proxy policies by policy ID.

firewall/proxy-policy/clear_counters/

HTTP Method

POST

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Action

Access Group

Extra parameters

clear_counters

fwgrp.policy

Name

policy

policy

Type

array

int

Summary

Array of policy IDs to reset.

Single policy ID to reset.

53

Required

No

No

policy-lookup: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Performs a policy lookup by creating a dummy packet and asking the kernel which
policy would be hit.

firewall/policy-lookup/select/

GET

select

fwgrp.policy

object

Name

ipv6

srcintf

Type

Summary

boolean

Perform an IPv6 lookup?

string

Source interface.

sourceport

int

Source port.

sourceip

protocol

dest

destport

icmptype

icmpcode

string

string

string

int

int

int

session: select

Source IP.

Protocol.

Destination IP/FQDN.

Destination port.

ICMP type.

ICMP code.

Summary

List all active firewall sessions (optionally filtered).

Required

No

Yes

No

No

Yes

Yes

No

No

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

54

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

ip_version

start

count

Type

string

int

int

firewall/session/select/

GET

select

sysgrp.cfg

array

Summary

IP version [*ipv4 | ipv6 | ipboth].

Starting entry index.

Maximum number of entries to return. Valid range is [20, 1000]; if
a value is specified out of that range, it will be rounded up or
down.

Required

No

No

Yes

summary

boolean

Enable/disable inclusion of session summary (setup rate, total
sessions, etc).

sourceport

policyid

policytype

application

application

protocol

destport

srcintf

dstintf

srcintfrole

dstintfrole

source

destination

username

shaper

country

int

int

string

int

string

string

int

string

string

array

array

string

string

string

string

string

Filter: Source port.

Filter: Policy ID.

Filter: Policy type [policy|policy6].

Filter: Application ID.

Filter: Application PROTO/PORT. (e.g. "TCP/443")

Filter: Protocol name [all|igmp|tcp|udp|icmp|etc].

Filter: Destination port.

Filter: Source interface name.

Filter: Destination interface name.

Filter: Source interface roles.

Filter: Destination interface roles.

Filter: Source IP address.

Filter: Destination IP address.

Filter: Authenticated username.

Filter: Forward traffic shaper name.

Filter: Destination country name.

natsourceaddress

string

Filter: NAT source address.

natsourceport

string

Filter: NAT source port.

No

No

No

No

No

No

No

No

No

No

No

No

No

No

No

No

No

No

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

session: clear_all

Summary

URI

HTTP Method

Action

Access Group

Response Type

session: close

Summary

URI

HTTP Method

Action

55

Immediately clear all active IPv4 and IPv6 sessions and IPS sessions of current
VDOM.

firewall/session/clear_all/

POST

clear_all

sysgrp.cfg

int

Close a specific firewall session that matches all provided criteria.

firewall/session/close/

POST

close

Access Group

sysgrp.cfg

Extra parameters

Name

pro

saddr

daddr

sport

dport

Type

string

string

string

int

int

shaper: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Summary

Protocol name [tcp|udp|icmp|...].

Source address.

Destination address.

Source port.

Destination port.

Required

Yes

Yes

Yes

Yes

Yes

List of statistics for configured firewall shared traffic shapers.

firewall/shaper/select/

GET

select

fwgrp.others

array

FortiOS REST API Reference

Fortinet Inc.

56

Monitor API

shaper: reset

Summary

URI

HTTP Method

Action

Reset statistics for all configured traffic shapers.

firewall/shaper/reset/

POST

reset

Access Group

fwgrp.others

per-ip-shaper: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

per-ip-shaper: reset

Summary

URI

HTTP Method

Action

List of statistics for configured firewall per-IP traffic shapers.

firewall/per-ip-shaper/select/

GET

select

fwgrp.others

array

Reset statistics for all configured firewall per-IP traffic shapers.

firewall/per-ip-shaper/reset/

POST

reset

Access Group

fwgrp.others

load-balance: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

List all firewall load balance servers.

firewall/load-balance/select/

GET

select

fwgrp.others

array

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Extra parameters

Name

start

count

Type

Summary

int

int

Starting entry index.

Maximum number of entries to return.

57

Required

No

Yes

address-fqdns: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

address-fqdns6: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

ippool: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

List of FQDN address objects and the IPs they resolved to.

firewall/address-fqdns/select/

GET

select

fwgrp.address

object

List of IPv6 FQDN address objects and the IPs they resolved to.

firewall/address-fqdns6/select/

GET

select

fwgrp.address

object

List IPv4 pool statistics.

firewall/ippool/select/

GET

select

fwgrp.policy

object

FortiOS REST API Reference

Fortinet Inc.

Monitor API

58

address-dynamic: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

address6-dynamic: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

geoip

geoip-query: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

List of Fabric Connector address objects and the IPs they resolve to.

firewall/address-dynamic/select/

GET

select

fwgrp.address

object

List of IPv6 Fabric Connector address objects and the IPs they resolve to.

firewall/address6-dynamic/select/

GET

select

fwgrp.address

object

Retrieve location details for IPs queried against FortiGuard's geoip service.

geoip/geoip-query/select/

GET

select

sysgrp.cfg

object

Name

Type

Summary

Required

ip_addresses

string

One or more IP address strings to query for location details.

Yes

FortiOS REST API Reference

Fortinet Inc.

Monitor API

ips

rate-based: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

license

status: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

database: upgrade

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

db_name

Type

string

59

Required

Returns a list of rate-based signatures in IPS package.

ips/rate-based/select/

GET

select

utmgrp.ips

array

Get current license & registration status.

license/status/select/

GET

select

sysgrp.cfg

object

Upgrade a license database on this device using uploaded file.

license/database/upgrade/

POST

upgrade

sysgrp.upd

object

Summary

Security service database name [ips_appctrl|antivirus|...]

Yes

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Name

Type

Summary

file_content

string

Provided when uploading a file: base64 encoded file data. Must not
contain whitespace or other invalid base64 characters. Must be
included in HTTP body.

60

Required

No

forticare-resellers: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Get current FortiCare resellers for the requested country.

license/forticare-resellers/select/

GET

select

sysgrp.cfg

object

Name

Type

Summary

country_code

int

FortiGuard country code

Required

No

forticare-org-list: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

log

current-disk-usage: select

Get FortiCare organization size and industry lists.

license/forticare-org-list/select/

GET

select

sysgrp.cfg

object

Summary

URI

Return current used, free and total disk bytes.

log/current-disk-usage/select/

HTTP Method

GET

FortiOS REST API Reference

Fortinet Inc.

Monitor API

61

Action

select

Access Group

loggrp.data-access

device: state

Summary

URI

HTTP Method

Action

Access Group

Response Type

forticloud: select

Summary

URI

HTTP Method

Action

Retrieve information on state of log devices.

log/device/state/

GET

state

loggrp.data-access

object

Return FortiCloud log status.

log/forticloud/select/

GET

select

Access Group

loggrp.config

fortianalyzer: select

Summary

URI

HTTP Method

Action

Return FortiAnalyzer/FortiManager log status.

log/fortianalyzer/select/

GET

select

Access Group

loggrp.config

Extra parameters

Name

server

Type

string

Summary

FortiAnalyzer/FortiManager address.

Required

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

62

fortianalyzer-queue: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

scope

Type

string

Retrieve information on FortiAnalyzer's queue state. Note:- FortiAnalyzer logs are
queued only if upload-option is realtime.

log/fortianalyzer-queue/select/

GET

select

loggrp.config

object

Summary

Scope from which to retrieve FortiAnalyzer's queue state
[vdom*|global].

Required

No

hourly-disk-usage: select

Summary

URI

HTTP Method

Action

Return historic hourly disk usage in bytes.

log/hourly-disk-usage/select/

GET

select

Access Group

loggrp.data-access

historic-daily-remote-logs: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Returns the amount of logs in bytes sent daily to a remote logging service
(FortiCloud or FortiAnalyzer).

log/historic-daily-remote-logs/select/

GET

select

loggrp.data-access

object

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Extra parameters

Name

server

Type

string

stats: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

dev

Type

string

stats: reset

Summary

URI

HTTP Method

Action

63

Summary

Service name [forticloud | fortianalyzer].

Required

Yes

Return number of logs sent by category per day for a specific log device.

log/stats/select/

GET

select

loggrp.data-access

array

Summary

Required

Log device [*memory | disk | fortianalyzer | forticloud].

No

Reset logging statistics for all log devices.

log/stats/reset/

POST

reset

Access Group

loggrp.data-access

forticloud-report: download

Summary

URI

HTTP Method

Action

Access Group

Response Type

Download PDF report from FortiCloud.

log/forticloud-report/download/

GET

download

loggrp.data-access

object

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Extra parameters

Name

mkey

inline

Type

Summary

int

int

FortiCloud Report ID.

Set to 1 to download the report inline.

ips-archive: download

64

Required

Yes

No

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

mkey

pcap_no

pcap_category

Download IPS/application control packet capture files. Uses configured log
display device.

log/ips-archive/download/

GET

download

loggrp.data-access

object

Type

Summary

int

int

int

IPS archive ID.

Packet capture roll number (required when log device is 'disk')

Packet capture category (required when log device is 'disk')

Required

Yes

No

No

policy-archive: download

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Download policy-based packet capture archive.

log/policy-archive/download/

GET

download

loggrp.data-access

object

Name

mkey

Type

int

Summary

Session ID (from traffic log).

Required

Yes

FortiOS REST API Reference

Fortinet Inc.

65

Required

Yes

Yes

Monitor API

Name

srcip

dstip

Type

string

string

Summary

Source IP.

Destination IP.

av-archive: download

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Download file quarantined by AntiVirus.

log/av-archive/download/

GET

download

loggrp.data-access

object

Name

mkey

Type

string

Summary

Checksum for quarantined file.

Required

Yes

event: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

registration

forticloud: login

List all event log descriptions.

log/event/select/

GET

select

any

array

Summary

URI

Login to FortiCloud.

registration/forticloud/login/

HTTP Method

POST

FortiOS REST API Reference

Fortinet Inc.

66

Required

Yes

Yes

No

No

Required

Yes

Yes

No

Monitor API

Action

Access Group

Response Type

Extra parameters

login

sysgrp.cfg

object

Name

email

password

Type

string

string

Summary

Account email.

Account password.

send_logs

boolean

Send logs to FortiCloud.

domain

string

FortiCloud domain.

forticloud: create

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

email

password

Type

string

string

Create a FortiCloud account.

registration/forticloud/create/

POST

create

sysgrp.cfg

object

Summary

Account email.

Account password.

send_logs

boolean

Send logs to FortiCloud.

forticloud: logout

Summary

URI

HTTP Method

Action

Access Group

Response Type

Logout from FortiCloud.

registration/forticloud/logout/

POST

logout

sysgrp.cfg

object

FortiOS REST API Reference

Fortinet Inc.

67

Monitor API

forticloud: disclaimer

Summary

URI

HTTP Method

Action

Access Group

Response Type

forticloud: domains

Summary

URI

HTTP Method

Action

Access Group

Response Type

forticare: login

Summary

URI

HTTP Method

Action

Access Group

Response Type

Retrieve the FortiCloud disclaimer.

registration/forticloud/disclaimer/

GET

disclaimer

sysgrp.cfg

object

Retrieve a list of FortiCloud login domains.

registration/forticloud/domains/

GET

domains

sysgrp.cfg

object

Login to FortiCare.

registration/forticare/login/

POST

login

sysgrp.cfg

object

Extra parameters

Name

email

password

Type

string

string

Summary

Account email.

Account password.

reseller_name

string

Reseller name.

reseller_id

int

Reseller ID.

Required

Yes

Yes

Yes

Yes

FortiOS REST API Reference

Fortinet Inc.

Monitor API

forticare: create

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

email

password

first_name

last_name

title

company

address

city

Type

string

string

string

string

string

string

string

string

Create a new FortiCare account.

registration/forticare/create/

POST

create

sysgrp.cfg

object

Summary

Account email.

Account password.

First name.

Last name.

Title.

Company.

Address.

City.

country_code

int

Country code.

state

state_code

string

string

State/Province.

State/Province code.

postal_code

string

Postal code.

phone

fax

industry

industry_id

orgsize_id

string

string

string

int

int

Phone number.

Fax number.

Industry.

Industry ID.

Organization size ID.

reseller_name

string

Reseller name.

reseller_id

int

Reseller ID.

68

Required

Yes

Yes

Yes

Yes

No

Yes

Yes

Yes

Yes

Yes

No

Yes

Yes

No

Yes

Yes

Yes

Yes

Yes

FortiOS REST API Reference

Fortinet Inc.

Monitor API

forticare: add-license

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

registration_
code

Type

string

69

Add a FortiCare license.

registration/forticare/add-license/

POST

add-license

sysgrp.cfg

object

Summary

FortiCare contract number.

Required

Yes

router

ipv4: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

start

count

ip_mask

gateway

type

interface

List all active IPv4 routing table entries.

router/ipv4/select/

GET

select

netgrp.route-cfg

array

Type

Summary

Required

int

int

string

string

string

string

Starting entry index.

Maximum number of entries to return (Default for all routes).

Filter: IP/netmask.

Filter: gateway.

Filter: route type.

Filter: interface name.

No

No

No

No

No

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

70

ipv6: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

start

count

ip_mask

gateway

type

interface

List all active IPv6 routing table entries.

router/ipv6/select/

GET

select

netgrp.route-cfg

array

Type

Summary

Required

int

int

string

string

string

string

Starting entry index.

Maximum number of entries to return (Default for all routes).

Filter: IP/netmask.

Filter: gateway.

Filter: route type.

Filter: interface name.

No

No

No

No

No

No

statistics: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Retrieve routing table statistics, including number of matched routes.

router/statistics/select/

GET

select

sysgrp.cfg

object

Name

Type

Summary

Required

ip_version

int

IP version (4|6). If not present, IPv4 and IPv6 will be returned.

ip_mask

gateway

type

interface

string

string

string

string

Filter: IP/netmask.

Filter: gateway.

Filter: route type.

Filter: interface name.

No

No

No

No

No

FortiOS REST API Reference

Fortinet Inc.

71

Monitor API

lookup: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Performs a route lookup by querying the routing table.

router/lookup/select/

GET

select

netgrp.route-cfg

object

Name

ipv6

Type

Summary

boolean

Perform an IPv6 lookup?

destination

string

Destination IP/FQDN

Required

No

Yes

policy: select

Summary

URI

HTTP Method

Action

Retrieve a list of active IPv4 policy routes.

router/policy/select/

GET

select

Access Group

netgrp.route-cfg

Extra parameters

Name

start

count

Type

Summary

int

int

Starting entry index.

Maximum number of entries to return.

count_only

boolean

Returns the number of IPv4 policy routes only.

Required

No

No

No

policy6: select

Summary

URI

Retrieve a list of active IPv6 policy routes.

router/policy6/select/

HTTP Method

GET

FortiOS REST API Reference

Fortinet Inc.

Monitor API

72

Action

select

Access Group

netgrp.route-cfg

Extra parameters

Name

start

count

Type

Summary

int

int

Starting entry index.

Maximum number of entries to return.

count_only

boolean

Returns the number of IPv6 policy routes only.

Required

No

No

No

system

admin: toggle-vdom-mode

Summary

URI

Toggles VDOM mode on/off. Enables or disables VDOM mode if it is disabled or
enabled respectively.

system/admin/toggle-vdom-mode/

HTTP Method

POST

Action

Access Group

Response Type

toggle-vdom-mode

sysgrp.cfg

object

api-user: generate-key

Summary

Generate a new api-key for the specified api-key-auth admin. The old api-key will
be replaced. The response contains the only chance to read the new api-key
plaintext in the api_key field.

URI

system/api-user/generate-key/

HTTP Method

POST

Action

Access Group

Response Type

Extra parameters

Name

api-user

Type

string

FortiOS REST API Reference

generate-key

sysgrp.admin

object

Summary

Generate a new token for this api-user.

Required

Yes

Fortinet Inc.

73

Required

No

No

Monitor API

config-revision: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Returns a list of system configuration revisions.

system/config-revision/select/

GET

select

sysgrp.cfg

object

config-revision: update-comments

Summary

URI

Updates comments for a system configuration file.

system/config-revision/update-comments/

HTTP Method

POST

Action

Access Group

Response Type

Extra parameters

update-comments

sysgrp.cfg

object

Name

Type

Summary

config_id

int

Configuration id.

comments

string

Configuration comments.

config-revision: delete

Summary

URI

HTTP Method

Action

Access Group

Response Type

Deletes one or more system configuration revisions.

system/config-revision/delete/

POST

delete

sysgrp.cfg

object

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Extra parameters

Name

config_ids

Type

array

Summary

List of configuration ids.

74

Required

Yes

config-revision: file

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Download a specific configuration revision.

system/config-revision/file/

GET

file

sysgrp.cfg

object

Name

Type

Summary

config_id

int

Configuration id.

Required

No

config-revision: info

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Retrieve meta information for a specific configuration revision.

system/config-revision/info/

GET

info

sysgrp.cfg

object

Name

Type

Summary

config_id

int

Configuration id.

Required

No

config-revision: save

Summary

Create a new config revision checkpoint.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

75

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

system/config-revision/save/

POST

save

sysgrp.cfg

object

Name

comments

Type

string

Summary

Optional revision comments

Required

No

current-admins: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

disconnect-admins: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

id

method

admins

Type

int

string

array

Return a list of currently logged in administrators.

system/current-admins/select/

GET

select

sysgrp.cfg

array

Disconnects logged in administrators.

system/disconnect-admins/select/

POST

select

sysgrp.cfg

object

Summary

Admin ID

Login method used to connect admin to FortiGate.

List of objects with admin id and method.

Required

No

No

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

76

time: set

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

year

month

day

hour

minute

second

time: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

os: reboot

Summary

URI

HTTP Method

Action

Sets current system time stamp.

system/time/set/

POST

set

sysgrp.cfg

object

Type

Summary

Required

int

int

int

int

int

int

Specifies the year for setting/updating time manually.

Specifies the month (0 - 11) for setting/updating time manually.

Specifies the day for setting/updating time manually.

Specifies the hour (0 - 23) for setting/updating time manually.

Specifies the minute (0 - 59) for setting/updating time manually.

Specifies the second (0 - 59) for setting/updating time manually.

Yes

Yes

Yes

Yes

Yes

Yes

Gets current system time stamp.

system/time/select/

GET

select

sysgrp.cfg

object

Immediately reboot this device.

system/os/reboot/

POST

reboot

FortiOS REST API Reference

Fortinet Inc.

Monitor API

77

Access Group

Response Type

Extra parameters

Name

event_log_
message

Type

string

os: shutdown

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

event_log_
message

Type

string

sysgrp.cfg

object

Summary

Message to be logged in event log.

Immediately shutdown this device.

system/os/shutdown/

POST

shutdown

sysgrp.cfg

object

Summary

Message to be logged in event log.

Required

No

Required

No

global-resources: select

Summary

URI

HTTP Method

Action

Retrieve current usage of global resources as well as both the default and user
configured maximum values.

system/global-resources/select/

GET

select

Access Group

sysgrp.cfg

vdom-resource: select

Summary

Retrieve VDOM resource information, including CPU and memory usage.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

URI

HTTP Method

Action

system/vdom-resource/select/

GET

select

Access Group

sysgrp.cfg

78

dhcp: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

ipv6

dhcp: revoke

Summary

URI

HTTP Method

Action

Access Group

Extra parameters

Name

ip

Type

array

dhcp6: revoke

Returns a list of all DHCP IPv4 and IPv6 DHCP leases.

system/dhcp/select/

GET

select

netgrp.cfg

array

Type

Summary

boolean

Include IPv6 addresses in the response.

Required

No

Revoke IPv4 DHCP leases.

system/dhcp/revoke/

POST

revoke

netgrp.cfg

Summary

Required

Optional list of addresses to revoke. Defaults to all addresses if not
provided.

No

Summary

Revoke IPv6 DHCP leases.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

URI

HTTP Method

Action

Access Group

Extra parameters

Name

ip

Type

array

firmware: select

Summary

URI

HTTP Method

Action

system/dhcp6/revoke/

POST

revoke

netgrp.cfg

Summary

79

Required

Optional list of addresses to revoke. Defaults to all addresses if not
provided.

No

Retrieve a list of firmware images available to use for upgrade on this device.

system/firmware/select/

GET

select

Access Group

sysgrp.mnt

firmware: upgrade

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

source

filename

format_
partition

Upgrade firmware image on this device using uploaded file.

system/firmware/upgrade/

POST

upgrade

sysgrp.mnt

object

Summary

Firmware file data source [upload|usb|fortiguard].

Name of file on fortiguard or USB disk to upgrade to.

Type

string

string

boolean

Set to true to format boot partition before upgrade.

Required

Yes

No

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Name

Type

Summary

file_content

string

Provided when uploading a file: base64 encoded file data. Must not
contain whitespace or other invalid base64 characters. Must be
included in HTTP body.

firmware: upgrade-paths

Summary

URI

Retrieve a list of supported firmware upgrade paths.

system/firmware/upgrade-paths/

HTTP Method

GET

80

Required

No

Action

Access Group

fsck: start

Summary

URI

HTTP Method

Action

upgrade-paths

sysgrp.mnt

Set file system check flag so that it will be executed on next device reboot.

system/fsck/start/

POST

start

Access Group

sysgrp.cfg

storage: select

Summary

URI

HTTP Method

Action

Retrieve information for the non-boot disk.

system/storage/select/

GET

select

Access Group

sysgrp.cfg

change-password: select

Summary

URI

HTTP Method

Action

Access Group

Save admin and guest-admin passwords.

system/change-password/select/

POST

select

any

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Extra parameters

Name

mkey

Type

string

Summary

User ID for password change.

old_password

string

Old password.

new_password

string

New password.

password-policy-conform: select

Summary

URI

HTTP Method

Action

Access Group

Extra parameters

Name

mkey

apply_to

password

Type

string

string

string

Check whether password conforms to the password policy.

system/password-policy-conform/select/

POST

select

any

Summary

User ID for password change.

Password Policy ID.

Password.

old_password

string

Old password.

81

Required

No

No

No

Required

No

No

No

No

csf: select

Summary

URI

HTTP Method

Action

Access Group

ETag Caching

Response Type

Retrieve a full tree of downstream FortiGates registered to the Security Fabric.

system/csf/select/

GET

select

secfabgrp

Enabled

object

FortiOS REST API Reference

Fortinet Inc.

Monitor API

82

csf: pending-authorizations

Summary

URI

Retrieve FortiGates with pending authorizations for joining the Security Fabric.
Note:- This list is currently available on Security Fabric root only.

system/csf/pending-authorizations/

HTTP Method

GET

Action

Access Group

Response Type

modem: select

Summary

URI

HTTP Method

Action

pending-authorizations

secfabgrp

array

Retrieve statistics for internal/external configured modem.

system/modem/select/

GET

select

Access Group

sysgrp.cfg

modem: reset

Summary

URI

HTTP Method

Action

Reset statistics for internal/external configured modem.

system/modem/reset/

POST

reset

Access Group

sysgrp.cfg

modem: connect

Summary

URI

HTTP Method

Action

Access Group

Trigger a connect for the configured modem.

system/modem/connect/

POST

connect

sysgrp.cfg

FortiOS REST API Reference

Fortinet Inc.

83

Monitor API

modem: disconnect

Summary

URI

HTTP Method

Action

Access Group

modem: update

Summary

URI

HTTP Method

Action

Access Group

3g-modem: select

Summary

URI

HTTP Method

Action

Trigger a disconnect for the configured modem.

system/modem/disconnect/

POST

disconnect

sysgrp.cfg

Update supported modem list from FortiGuard.

system/modem/update/

POST

update

sysgrp.cfg

List all 3G modems available via FortiGuard.

system/3g-modem/select/

GET

select

Access Group

sysgrp.cfg

resource: usage

Summary

URI

HTTP Method

Action

Access Group

Response Type

Retreive current and historical usage data for a provided resource.

system/resource/usage/

GET

usage

sysgrp.cfg

object

FortiOS REST API Reference

Fortinet Inc.

Monitor API

84

Extra parameters

Name

resource

Type

string

interval

string

sniffer: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

sniffer: restart

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Summary

Resource to get usage data for [cpu|memory|disk|sessions|lograte].
Defaults to all resources if not provided.

Time interval of resource usage [1-min|10-min|30-min|1-hour|12-
hour|24-hour]. Defaults to all intervals if not provided.

Required

No

No

Return a list of all configured packet captures.

system/sniffer/select/

GET

select

netgrp.packet-capture

array

Restart specified packet capture.

system/sniffer/restart/

POST

restart

netgrp.packet-capture

array

Name

mkey

Type

int

Summary

ID of packet capture entry.

Required

Yes

sniffer: start

Summary

URI

Start specified packet capture.

system/sniffer/start/

HTTP Method

POST

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Action

Access Group

Response Type

Extra parameters

start

netgrp.packet-capture

array

85

Name

mkey

Type

int

Summary

ID of packet capture entry.

Required

Yes

sniffer: stop

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Stop specified packet capture.

system/sniffer/stop/

POST

stop

netgrp.packet-capture

array

Name

mkey

Type

int

Summary

ID of packet capture entry.

Required

Yes

sniffer: download

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Download a stored packet capture.

system/sniffer/download/

GET

download

netgrp.packet-capture

object

Name

mkey

Type

int

Summary

ID of packet capture entry.

Required

Yes

FortiOS REST API Reference

Fortinet Inc.

Monitor API

86

automation-stitch: stats

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Stats for automation stitches.

system/automation-stitch/stats/

GET

stats

any

array

Name

mkey

Type

string

Summary

Filter: Automation stitch name.

Required

No

automation-stitch: test

Summary

URI

HTTP Method

Action

Access Group

Extra parameters

Name

mkey

log

Type

string

string

switch-controller

managed-switch: select

Triggers an automation stitch for testing purposes.

system/automation-stitch/test/

POST

test

any

Summary

ID of automation stitch to trigger.

Log message to send with the event.

Required

Yes

No

Summary

URI

Retrieve statistics for configured FortiSwitches

switch-controller/managed-switch/select/

HTTP Method

GET

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Action

Access Group

Response Type

Extra parameters

Name

mkey

poe

Type

string

boolean

select

wifi

array

Summary

Filter: FortiSwitch ID.

Filter: Retrieve PoE statistics for ports of configured FortiSwitches.
Port power usage is in Watt units.

87

Required

No

No

port_stats

boolean

Filter: Retrieve tx/rx statistics for ports of configured FortiSwitches.

No

managed-switch: update

Summary

URI

HTTP Method

Action

Access Group

Extra parameters

Name

mkey

admin

Type

string

string

managed-switch: restart

Summary

URI

HTTP Method

Action

Access Group

Response Type

Update administrative state for a given FortiSwitch (enable or disable
authorization).

switch-controller/managed-switch/update/

POST

update

wifi

Summary

FortiSwitch name.

New FortiSwitch administrative state [enable|disable|discovered].

Restart a given FortiSwitch.

switch-controller/managed-switch/restart/

POST

restart

wifi

object

Required

No

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Extra parameters

Name

mkey

Type

string

Summary

Name of managed FortiSwitch.

managed-switch: poe-reset

88

Required

Yes

Summary

URI

HTTP Method

Action

Access Group

Extra parameters

Name

mkey

port

Type

string

string

Reset PoE on a given FortiSwitch's port.

switch-controller/managed-switch/poe-reset/

POST

poe-reset

wifi

Summary

Name of managed FortiSwitch.

Name of port to reset PoE on.

Required

Yes

Yes

managed-switch: faceplate-xml

Summary

URI

Retrieve XML for rendering FortiSwitch faceplate widget.

switch-controller/managed-switch/faceplate-xml/

HTTP Method

GET

Action

Access Group

Response Type

Extra parameters

Name

mkey

Type

string

faceplate-xml

wifi

array

Summary

Name of managed FortiSwitch.

Required

No

managed-switch: factory-reset

Summary

Send 'Factory Reset' command to a given FortiSwitch.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

mkey

Type

string

89

switch-controller/managed-switch/factory-reset/

POST

factory-reset

wifi

object

Summary

Name of managed FortiSwitch.

Required

Yes

managed-switch: dhcp-snooping

Summary

URI

Retrieve DHCP servers monitored by FortiSwitches.

switch-controller/managed-switch/dhcp-snooping/

HTTP Method

GET

Action

Access Group

Response Type

dhcp-snooping

wifi

array

fsw-firmware: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

mkey

timeout

Type

string

string

Retrieve a list of recommended firmware for managed FortiSwitches.

switch-controller/fsw-firmware/select/

GET

select

wifi

object

Summary

Filter: FortiSwitch ID.

FortiGuard connection timeout (defaults to 3 seconds).

Required

No

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

90

fsw-firmware: download

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Download FortiSwitch firmware from FortiGuard to the FortiGate according to
FortiSwitch image ID.

switch-controller/fsw-firmware/download/

POST

download

wifi

object

Name

image_id

Type

string

Summary

FortiSwitch image ID.

Required

Yes

fsw-firmware: push

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

serial

image_id

Type

string

string

fsw-firmware: upload

Push FortiSwitch firmware to the given device.

switch-controller/fsw-firmware/push/

POST

push

wifi

object

Summary

The target device's serial.

FortiSwitch image ID.

Required

Yes

Yes

Summary

URI

Upload FortiSwitch firmware to the management FortiGate and then push to
target FortiSwitches.

switch-controller/fsw-firmware/upload/

HTTP Method

POST

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Action

Access Group

Response Type

Extra parameters

Name

serials

serials

file_content

Type

array

string

string

upload

wifi

object

Summary

A list of target devices' serials.

The target device's serial.

Provided when uploading a file: base64 encoded file data. Must not
contain whitespace or other invalid base64 characters. Must be
included in HTTP body.

91

Required

No

No

No

detected-device: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Retrieve a list of devices detected on all switches.

switch-controller/detected-device/select/

GET

select

wifi

array

validate-switch-prefix: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

prefix

Type

string

Validate a FortiSwitch serial number prefix.

switch-controller/validate-switch-prefix/select/

GET

select

wifi

object

Summary

Prefix of FortiSwitch serial number.

Required

No

FortiOS REST API Reference

Fortinet Inc.

92

Required

No

No

Monitor API

interface: select

Summary

URI

HTTP Method

Action

Access Group

ETag Caching

Response Type

Extra parameters

Name

interface_
name

Retrieve statistics for all system interfaces.

system/interface/select/

GET

select

netgrp.cfg

Enabled

array

Type

string

Summary

Filter: interface name.

include_vlan

boolean

Enable to include VLANs in result list.

interface: dhcp-status

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Retrieve the DHCP client status of an interface.

system/interface/dhcp-status/

GET

dhcp-status

netgrp.cfg

object

Name

mkey

Type

string

Summary

Name of the interface.

Required

Yes

interface: dhcp-renew

Summary

URI

Renew DHCP lease of an interface.

system/interface/dhcp-renew/

HTTP Method

POST

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Action

Access Group

Response Type

Extra parameters

dhcp-renew

netgrp.cfg

object

93

Name

mkey

Type

string

Summary

Name of the interface.

Required

Yes

available-interfaces: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

view_type

Type

string

Retrieve a list of all interfaces along with some meta information regarding their
availability.

system/available-interfaces/select/

GET

select

any

array

Summary

Optionally include additional information for interfaces. This
parameter can be repeated multiple times. 'poe': Includes PoE
information for supported ports. 'ha': Includes extra meta
information useful when dealing with interfaces related to HA
configuration. Interfaces that are used by an HA cluster as
management interfaces are also included in this view. 'zone':
Includes extra meta information for determining zone membership
eligibility.'vwp': Includes extra meta information for determining
virtual wire pair eligibility.'sdwan': Includes extra meta information
for determining SD-WAN eligibility.'switch': Includes extra meta
information for determining switch eligibility.'hard-switch': Includes
extra meta information for determining hard-switch eligibility.

Required

No

acquired-dns: select

Summary

URI

Retrieve a list of interfaces and their acquired DNS servers.

system/acquired-dns/select/

FortiOS REST API Reference

Fortinet Inc.

Monitor API

HTTP Method

Action

Access Group

Response Type

GET

select

any

array

94

resolve-fqdn: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Resolves the provided FQDNs to FQDN -> IP mappings.

system/resolve-fqdn/select/

GET

select

any

object

Name

Type

Summary

ipv6

fqdn

fqdn

boolean

Resolve for the AAAA record?

string

array

FQDN

List of FQDNs to be resolved

nat46-ippools: select

Required

No

Yes

No

Summary

URI

HTTP Method

Action

Access Group

Response Type

usb-log: select

Summary

URI

Retrieve a list of all IPv6 IP pools that are valid for NAT 46 policies.

system/nat46-ippools/select/

GET

select

any

array

Retrieve information about connected USB drives, including estimated log sizes.

system/usb-log/select/

FortiOS REST API Reference

Fortinet Inc.

Monitor API

95

HTTP Method

Action

GET

select

Access Group

sysgrp.cfg

usb-log: start

Summary

URI

HTTP Method

Action

Start backup of logs from current VDOM to USB drive.

system/usb-log/start/

POST

start

Access Group

sysgrp.cfg

usb-log: stop

Summary

URI

HTTP Method

Action

Stop backup of logs to USB drive.

system/usb-log/stop/

POST

stop

Access Group

sysgrp.cfg

usb-device: eject

Summary

URI

HTTP Method

Action

Eject USB drives for safe removal.

system/usb-device/eject/

POST

eject

Access Group

sysgrp.cfg

ipconf: select

Summary

URI

HTTP Method

Action

Determine if there is an IP conflict for a specific IP using ARP.

system/ipconf/select/

GET

select

FortiOS REST API Reference

Fortinet Inc.

Monitor API

96

Required

Yes

Yes

Access Group

Response Type

Extra parameters

Name

devs

ipaddr

Type

array

string

fortiguard: update

Summary

URI

HTTP Method

Action

Access Group

netgrp.cfg

array

Summary

List of interfaces to check for conflict.

IPv4 address to check for conflict.

Immediately update status for FortiGuard services.

system/fortiguard/update/

POST

update

sysgrp.cfg

fortiguard: clear-statistics

Summary

URI

Immediately clear all FortiGuard statistics.

system/fortiguard/clear-statistics/

HTTP Method

POST

Action

Access Group

clear-statistics

sysgrp.cfg

fortiguard: test-availability

Summary

URI

Test availability of FortiGuard services.

system/fortiguard/test-availability/

HTTP Method

POST

Action

Access Group

test-availability

sysgrp.cfg

FortiOS REST API Reference

Fortinet Inc.

Monitor API

fortiguard: server-info

Summary

URI

HTTP Method

Action

Access Group

fortimanager: status

Summary

URI

HTTP Method

Action

Access Group

Response Type

fortimanager: config

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

fortimanager_
ip

Type

string

97

Get FortiGuard server list and information.

system/fortiguard/server-info/

GET

server-info

sysgrp.cfg

Get FortiManager status.

system/fortimanager/status/

GET

status

sysgrp.cfg

object

Configure FortiManager IP. Register FortiManager if 'fortimanager_ip' is
provided. Unregister FortiManager if only 'unregister' parameter is specified and
set to true.

system/fortimanager/config/

POST

config

sysgrp.cfg

object

Summary

FortiManager IP address.

unregister

boolean

Unregister the FortiManager (default=false).

Required

No

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

98

fortimanager: backup-summary

Summary

URI

Get FortiManager backup summary.

system/fortimanager/backup-summary/

HTTP Method

GET

Action

Access Group

Response Type

backup-summary

fwgrp

object

fortimanager: backup-action

Summary

URI

Import or update from FortiManager objects.

system/fortimanager/backup-action/

HTTP Method

POST

Action

Access Group

Response Type

Extra parameters

Name

operation

objects

Type

string

array

backup-action

fwgrp

object

Summary

Operation to perform on the given CMDB objects [import|update].

Array of CMDB tables and mkeys.

Required

Yes

Yes

fortimanager: backup-details

Summary

URI

Get the properties of a FortiManager object.

system/fortimanager/backup-details/

HTTP Method

GET

Action

Access Group

Response Type

backup-details

fwgrp

object

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Extra parameters

Name

mkey

datasource

Type

string

string

Summary

Object name.

Object datasource.

available-certificates: select

99

Required

Yes

Yes

Summary

URI

HTTP Method

Action

Access Group

Extra parameters

Name

scope

Type

string

certificate: download

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Get available certificates.

system/available-certificates/select/

GET

select

any

Summary

Scope of certificate [vdom*|global].

Required

No

Download certificate.

system/certificate/download/

GET

download

vpngrp

object

Name

mkey

type

scope

Type

string

string

string

Summary

Name of certificate.

Type of certificate [local|csr|remote|ca|crl].

Scope of certificate [vdom*|global].

Required

Yes

Yes

No

FortiOS REST API Reference

Fortinet Inc.

100

Monitor API

debug: download

Summary

URI

HTTP Method

Action

Access Group

Response Type

com-log: dump

Summary

URI

HTTP Method

Action

Download debug report for technical support.

system/debug/download/

GET

download

sysgrp.cfg

object

Dump system com-log to file.

system/com-log/dump/

POST

dump

Access Group

sysgrp.cfg

com-log: update

Summary

URI

HTTP Method

Action

Access Group

com-log: download

Summary

URI

HTTP Method

Action

Access Group

Response Type

Fetch system com-log file dump progress.

system/com-log/update/

GET

update

sysgrp.cfg

Download com-log file (after file dump is complete).

system/com-log/download/

GET

download

sysgrp.cfg

object

FortiOS REST API Reference

Fortinet Inc.

Monitor API

101

botnet: stat

Summary

URI

HTTP Method

Action

Access Group

ETag Caching

Response Type

botnet: select

Summary

URI

HTTP Method

Action

Access Group

ETag Caching

Response Type

Extra parameters

Name

start

count

include_hit_
only

Retrieve statistics for FortiGuard botnet database.

system/botnet/stat/

GET

stat

sysgrp.cfg

Enabled

object

List all known IP-based botnet entries in FortiGuard botnet database.

system/botnet/select/

GET

select

sysgrp.cfg

Enabled

array

Type

Summary

int

int

Starting entry index.

Maximum number of entries to return.

boolean

Include entries with hits only.

Required

No

No

No

botnet-domains: select

Summary

URI

HTTP Method

Action

List all known domain-based botnet entries in FortiGuard botnet database.

system/botnet-domains/select/

GET

select

Access Group

sysgrp.cfg

FortiOS REST API Reference

Fortinet Inc.

Monitor API

ETag Caching

Response Type

Extra parameters

Enabled

array

102

Name

start

count

Type

Summary

int

int

Starting entry index.

Maximum number of entries to return.

Required

No

No

botnet-domains: stat

Summary

URI

HTTP Method

Action

Access Group

ETag Caching

Response Type

botnet-domains: hits

Summary

URI

HTTP Method

Action

Access Group

Response Type

ha-statistics: select

Summary

URI

HTTP Method

Action

List statistics on domain-based botnet entries in FortiGuard botnet database.

system/botnet-domains/stat/

GET

stat

sysgrp.cfg

Enabled

object

List hit botnet domains with hit count > 0.

system/botnet-domains/hits/

GET

hits

sysgrp.cfg

array

List of statistics for members of HA cluster.

system/ha-statistics/select/

GET

select

FortiOS REST API Reference

Fortinet Inc.

Monitor API

103

Access Group

Response Type

sysgrp.cfg

array

ha-history: select

Summary

URI

HTTP Method

Action

Access Group

ETag Caching

Response Type

Get HA cluster historical logs.

system/ha-history/select/

GET

select

sysgrp.cfg

Enabled

object

ha-checksums: select

Summary

URI

HTTP Method

Action

Access Group

ETag Caching

Response Type

ha-peer: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

List of checksums for members of HA cluster.

system/ha-checksums/select/

GET

select

sysgrp.cfg

Enabled

array

Get configuration of peer(s) in HA cluster. Uptime is expressed in seconds.

system/ha-peer/select/

GET

select

sysgrp.cfg

array

FortiOS REST API Reference

Fortinet Inc.

Monitor API

104

Summary

Serial number of the HA member. If not specified, fetch information
for all HA members

Virtual cluster number. If not specified, fetch information for all
active vclusters

Required

No

No

Extra parameters

Name

serial_no

Type

string

vcluster_id

int

ha-peer: update

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

serial_no

vcluster_id

priority

Type

string

int

int

Update configuration of peer in HA cluster.

system/ha-peer/update/

POST

update

sysgrp.cfg

object

Summary

Serial number of the HA member.

Virtual cluster number.

Priority to assign to HA member.

hostname

string

Name to assign the HA member.

ha-peer: disconnect

Summary

URI

HTTP Method

Action

Access Group

Response Type

Update configuration of peer in HA cluster.

system/ha-peer/disconnect/

POST

disconnect

sysgrp.cfg

object

Required

Yes

No

No

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Extra parameters

Name

serial_no

interface

ip

mask

Type

string

string

string

string

link-monitor: select

Summary

URI

HTTP Method

Action

Summary

Serial number of the HA member.

Name of the interface which should be assigned for management.

IP to assign to the selected interface.

Full network mask to assign to the selected interface.

Retrieve per-interface statistics for active link monitors.

system/link-monitor/select/

GET

select

105

Required

Yes

Yes

Yes

Yes

Access Group

sysgrp.cfg

Extra parameters

Name

mkey

Type

string

Summary

Name of link monitor.

Required

No

compliance: run

Summary

URI

HTTP Method

Action

Immediately run compliance checks for the selected VDOM.

system/compliance/run/

POST

run

Access Group

sysgrp.cfg

config: restore

Summary

URI

HTTP Method

Action

Restore system configuration from uploaded file or from USB.

system/config/restore/

POST

restore

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Access Group

Response Type

Extra parameters

Name

source

Type

string

usb_filename

string

config_id

int

password

scope

vdom

string

string

string

file_content

string

config: backup

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

destination

Type

string

usb_filename

string

password

scope

vdom

string

string

string

sysgrp.mnt

object

Summary

Configuration file data source [upload | usb | revision].

When using 'usb' source: the filename to restore from the connected
USB device.

106

Required

Yes

No

When using 'revision' source: valid ID of configuration stored on disk
to revert to.

No

Password to decrypt configuration data.

Specify global or VDOM only restore [global | vdom].

If 'vdom' scope specified, the name of the VDOM to restore
configuration.

Provided when uploading a file: base64 encoded file data. Must not
contain whitespace or other invalid base64 characters. Must be
included in HTTP body.

No

Yes

No

No

Backup system config

system/config/backup/

GET

backup

sysgrp.mnt

object

Summary

Configuration file destination [file* | usb]

When using 'usb' destination: the filename to save to on the
connected USB device

Password to encrypt configuration data.

Specify global or VDOM only backup [global | vdom].

If 'vdom' scope specified, the name of the VDOM to backup
configuration.

Required

No

No

No

Yes

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

config: usb-filelist

Summary

URI

HTTP Method

Action

Access Group

Response Type

sandbox: stats

Summary

URI

HTTP Method

Action

Access Group

Response Type

sandbox: status

Summary

URI

HTTP Method

Action

Access Group

Response Type

107

List configuration files available on connected USB drive.

system/config/usb-filelist/

GET

usb-filelist

sysgrp.cfg

array

Retrieve sandbox statistics.

system/sandbox/stats/

GET

stats

sysgrp.cfg

object

Retrieve sandbox status.

system/sandbox/status/

GET

status

sysgrp.cfg

object

sandbox: test-connect

Summary

URI

HTTP Method

Action

Access Group

Response Type

Test the connectivity of a given FortiSandbox IP.

system/sandbox/test-connect/

GET

test-connect

sysgrp.cfg

object

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Extra parameters

Name

server

Type

string

Summary

IP of the FortiSandbox to test.

108

Required

Yes

object: usage

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Retrieve all objects that are currently using as well as objects that can use the
given object.

system/object/usage/

GET

usage

any

object

Required

No

No

No

Yes

Name

q_path

q_name

qtypes

mkey

Type

string

string

array

string

Summary

The CMDB table's path

The CMDB table's name

List of CMDB table qTypes

The mkey for the object

object-tagging: usage

Summary

URI

HTTP Method

Action

Access Group

Response Type

status: select

Summary

URI

Retrieve usage count for tags in all tag categories.

system/object-tagging/usage/

GET

usage

any

array

Retrieve basic system status.

system/status/select/

FortiOS REST API Reference

Fortinet Inc.

Monitor API

HTTP Method

Action

Access Group

Response Type

GET

select

any

object

109

timezone: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

vmlicense: upload

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Get world timezone and daylight saving time.

system/timezone/select/

GET

select

any

array

Update VM license using uploaded file. Reboots immediately if successful.

system/vmlicense/upload/

POST

upload

sysgrp.cfg

object

Name

Type

Summary

file_content

string

Provided when uploading a file: base64 encoded file data. Must not
contain whitespace or other invalid base64 characters. Must be
included in HTTP body.

Required

No

sensor-info: select

Summary

URI

Retrieve system sensor status.

system/sensor-info/select/

HTTP Method

GET

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Action

Access Group

Response Type

security-rating: select

select

sysgrp.cfg

object

110

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Retrieve a Security Rating result. Without file specified, returns the most recent
result.

system/security-rating/select/

GET

select

secfabgrp

object

Name

id

Type

int

Summary

Security Rating result ID.

Required

No

security-rating: history

Summary

URI

HTTP Method

Action

Access Group

Response Type

security-rating: trigger

Summary

URI

HTTP Method

Action

Access Group

Response Type

Retrieve Security Rating history.

system/security-rating/history/

GET

history

secfabgrp

object

Trigger a Security Rating.

system/security-rating/trigger/

POST

trigger

secfabgrp

object

FortiOS REST API Reference

Fortinet Inc.

Monitor API

security-rating: status

Summary

URI

HTTP Method

Action

Access Group

Response Type

security-rating: lang

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

key

Type

string

111

Check if a Security Rating is currently running.

system/security-rating/status/

GET

status

secfabgrp

object

Returns the requested Security Rating language mapping.

system/security-rating/lang/

GET

lang

secfabgrp

object

Summary

Required

Requested language mapping (en, fr, big5, euc-kr, GB2312, pg, sp,
x-sjis).

No

fortiguard-blacklist: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Retrieve blacklist information for a specified IP.

system/fortiguard-blacklist/select/

GET

select

sysgrp.cfg

object

FortiOS REST API Reference

Fortinet Inc.

Monitor API

112

Extra parameters

Name

ip

timeout

Type

string

int

Summary

IPv4 address to check against.

Timeout period in seconds (defaults to 5).

Required

Yes

No

check-port-availability: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Check whether a list of TCP port ranges is available for a certain service.

system/check-port-availability/select/

GET

select

sysgrp.cfg

array

Name

Type

Summary

port_ranges

array

List of TCP port range objects to check against.

service

string

The service in which the ports could be available. 'service' options
are [reserved | sysglobal | webproxy | ftpproxy | sslvpn | slaprobe |
fsso | ftm_push]. If 'service' is not specified, the port ranges
availability is checked against all services.

Required

Yes

No

external-resource: entry-list

Summary

URI

HTTP Method

Action

Access Group

Response Type

Retrieve resource file status with a list of valid/invalid entries (skip empty and
comment lines) for the specific external resource.

system/external-resource/entry-list/

GET

entry-list

sysgrp.cfg

object

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Extra parameters

Name

mkey

Type

string

Summary

The external resource name to query.

status_only

boolean

Retrieve resource file status only and skip entries.

113

Required

Yes

No

extender-controller

extender: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

id

Type

array

extender: reset

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Retrieve statistics for specific configured FortiExtender units.

extender-controller/extender/select/

GET

select

netgrp.cfg

array

Summary

List of FortiExtender IDs to query.

Reset a specific FortiExtender unit.

extender-controller/extender/reset/

POST

reset

netgrp.cfg

object

Required

Yes

Name

id

Type

string

Summary

FortiExtender ID to reset.

Required

Yes

FortiOS REST API Reference

Fortinet Inc.

Monitor API

sdn-connector: status

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

mkey

type

Type

string

string

114

Retrieve connection status for SDN connectors.

system/sdn-connector/status/

GET

status

sysgrp.cfg

array

Summary

Filter: SDN Connector ID.

Filter: SDN Connector type.

Required

No

No

sdn-connector: validate-gcp-key

Summary

URI

Validate a string representing a private key from GCP in PEM format.

system/sdn-connector/validate-gcp-key/

HTTP Method

POST

Action

Access Group

Response Type

Extra parameters

validate-gcp-key

any

object

Name

private-key

Type

string

Summary

Private key in PEM format.

Required

Yes

user

firewall: select

Summary

URI

List authenticated firewall users.

user/firewall/select/

FortiOS REST API Reference

Fortinet Inc.

Monitor API

HTTP Method

Action

Access Group

Response Type

Extra parameters

GET

select

authgrp

array

115

Name

Type

Summary

Required

start

count

ipv4

ipv6

int

int

boolean

boolean

Starting entry index.

Maximum number of entries to return.

Include IPv4 user (default=true).

Include IPv6 users.

No

No

No

No

firewall: deauth

Summary

URI

HTTP Method

Action

Access Group

Extra parameters

Name

user_type

id

ip

ip_version

method

Type

string

int

string

string

string

Deauthenticate single, multiple, or all firewall users.

user/firewall/deauth/

POST

deauth

authgrp

Summary

Required

User type [proxy|firewall]. Required for both proxy and firewall users. No

User ID. Required for both proxy and firewall users.

User IP address. Required for both proxy and firewall users.

IP version [ip4|ip6]. Only required if user_type is firewall.

Authentication method [fsso|rsso|ntlm|firewall|wsso|fsso_citrix|sso_
guest]. Only required if user_type is firewall.

No

No

No

No

No

No

all

boolean

Set to true to deauthenticate all users. Other parameters will be
ignored.

users

array

Array of user objects to deauthenticate. Use this to deauthenticate
multiple users at once. Each object should include the above
properties.

FortiOS REST API Reference

Fortinet Inc.

116

Monitor API

banned: select

Summary

URI

HTTP Method

Action

Access Group

banned: clear_users

Summary

URI

HTTP Method

Action

Access Group

Extra parameters

Return a list of all banned users by IP.

user/banned/select/

GET

select

authgrp

Immediately clear a list of specific banned users by IP.

user/banned/clear_users/

POST

clear_users

authgrp

Name

Type

Summary

ip_addresses

array

List of banned user IPs to clear. IPv4 and IPv6 addresses are
allowed.

Required

Yes

banned: add_users

Summary

URI

HTTP Method

Action

Access Group

Extra parameters

Immediately add one or more users to the banned list.

user/banned/add_users/

POST

add_users

authgrp

Name

Type

Summary

ip_addresses

array

List of IP Addresses to ban. IPv4 and IPv6 addresses are allowed.

expiry

int

Time until expiry in seconds. 0 for indefinite ban.

Required

Yes

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

banned: clear_all

Summary

URI

HTTP Method

Action

Access Group

fortitoken: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

fortitoken: activate

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

tokens

Type

array

117

Immediately clear all banned users.

user/banned/clear_all/

POST

clear_all

authgrp

Retrieve a map of FortiTokens and their status.

user/fortitoken/select/

GET

select

authgrp

object

Activate a set of FortiTokens by serial number.

user/fortitoken/activate/

POST

activate

authgrp

array

Summary

Required

List of FortiToken serial numbers to activate. If omitted, all tokens
will be used.

No

detected-device: select

Summary

Retrieve a list of detected devices.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

118

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

user/detected-device/select/

GET

select

authgrp

array

Name

Type

Summary

Required

expand_child_
macs

with_
compliance

boolean

Include child devices as separate entries in the list.

boolean

Retrieve compliance status.

with_dhcp

boolean

Retrieve DHCP lease information.

with_endpoint

boolean

Retrieve FortiClient endpoint information.

boolean

Retrieve advanced FortiClient endpoint information.

with_
endpoint_
advanced

with_fortilink

boolean

Retrieve FortiLink information.

with_fortiap

boolean

Retrieve FortiAP information.

No

No

No

No

No

No

No

device: select

Summary

URI

HTTP Method

Action

Access Group

ETag Caching

Response Type

Extra parameters

Retrieve a list of detected devices.

user/device/select/

GET

select

authgrp

Enabled

array

Name

Type

Summary

master_only

boolean

List of master device only.

Required

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Name

compliance_
visibility

Type

boolean

intf_name

string

Summary

Add compliance status to indicate if a device is 'exempt' or 'non-
compliant' by interface's FortiClient host check.

Filter: Name of interface where the device was detected. Only
available when compliance_visibility is true.

119

Required

No

No

master_mac

string

Filter: Master MAC of a device. Multiple entries could be returned.

No

device-type: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

device-category: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

fortitoken: refresh

Summary

URI

HTTP Method

Action

Access Group

Response Type

Retrieve a list of device types.

user/device-type/select/

GET

select

any

array

Retrieve a list of device categories.

user/device-category/select/

GET

select

any

array

Refresh a set of FortiTokens by serial number.

user/fortitoken/refresh/

POST

refresh

authgrp

array

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Extra parameters

Name

tokens

Type

array

fortitoken: provision

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

tokens

Type

array

120

Summary

Required

List of FortiToken serial numbers to refresh. If omitted, all tokens
will be used.

No

Provision a set of FortiTokens by serial number.

user/fortitoken/provision/

POST

provision

authgrp

array

Summary

Required

List of FortiToken serial numbers to provision. If omitted, all tokens
will be used.

No

fortitoken: send-activation

Summary

URI

Send a FortiToken activation code to a user via SMS or Email.

user/fortitoken/send-activation/

HTTP Method

POST

Action

Access Group

Response Type

Extra parameters

Name

token

Type

string

method

string

send-activation

authgrp

object

Summary

FortiToken serial number. The token must be assigned to a
user/admin.

Method to send activation code [email|sms]. If not set, SMS will be
attempted first, then email.

Required

Yes

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Name

email

sms_phone

Type

string

string

fortitoken: import-trial

Summary

Override email address.

Override SMS phone number. SMS provider must be set in the
assigned user/admin.

121

Required

No

No

Summary

URI

HTTP Method

Action

Access Group

Response Type

Import trial mobile FortiTokens.

user/fortitoken/import-trial/

POST

import-trial

authgrp

object

fortitoken: import-mobile

Summary

URI

Import a list of tokens from FortiGuard to the FortiGate unit.

user/fortitoken/import-mobile/

HTTP Method

POST

Action

Access Group

Response Type

Extra parameters

Name

code

Type

string

fortitoken: import-seed

import-mobile

authgrp

object

Summary

Activation code on redemption certificate.

Summary

URI

HTTP Method

Action

Access Group

Response Type

Import a FortiToken seed file.

user/fortitoken/import-seed/

POST

import-seed

authgrp

object

Required

Yes

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Extra parameters

Name

Type

Summary

file_content

string

Provided when uploading a file: base64 encoded file data. Must not
contain whitespace or other invalid base64 characters. Must be
included in HTTP body.

fsso: refresh-server

Summary

URI

Refresh remote agent group list for all fsso agents.

user/fsso/refresh-server/

HTTP Method

POST

122

Required

No

Action

Access Group

fsso: select

Summary

URI

HTTP Method

Action

Access Group

radius: test-connect

Summary

URI

HTTP Method

Action

Access Group

Response Type

refresh-server

authgrp

Get a list of fsso and fsso polling status.

user/fsso/select/

GET

select

authgrp

Test the connectivity of the given RADIUS server and, optionally, the validity of a
username & password.

user/radius/test-connect/

POST

test-connect

authgrp

object

FortiOS REST API Reference

Fortinet Inc.

Monitor API

123

Extra parameters

Name

mkey

ordinal

Type

string

string

server

string

secret

string

Summary

Required

Name of FortiGate's RADIUS object whose settings to test.

If 'mkey' is provided, the server-secret pair to use from the object:
'primary', 'secondary' or 'tertiary'. Defaults to 'primary'.

Host name or IP of a RADIUS server. If 'mkey' is provided, this
overrides the 'server' value in the object.

Secret password for the RADIUS server. If 'mkey' is provided, this
overrides the 'secret' value in the object.

No

No

No

No

No

No

user

password

string

string

User name whose access to check.

User's password.

tacacs-plus: test

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

mkey

ordinal

Type

string

string

server

string

secret

string

port

int

source_ip

string

Test the connectivity of the given TACACS+ server.

user/tacacs-plus/test/

POST

test

authgrp

object

Summary

Required

Name of FortiGate's TACACS+ object whose settings to test.

If 'mkey' is provided, the server-key pair to use from the object:
'primary', 'secondary' or 'tertiary'. Defaults to 'primary'.

Host name of IP of a TACACS+ server. If 'mkey' is provided, this
overrides the 'server' value in the object.

Secret key for the TACACS+ server. If 'mkey' is provided, this
overrides the 'key' value in the object.

Port number of the TACACS+ server. If 'mkey' is provided, this
overrides the 'port' value in the object. Defaults to 49.

Source IP for communications to TACACS+ server. If 'mkey' is
provided, this overrides the 'source-ip' value in the object.

No

No

No

No

No

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

utm

rating-lookup: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

url

url

Type

string

array

app-lookup: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

124

Required

Yes

No

Lookup FortiGuard rating for a specific URL.

utm/rating-lookup/select/

GET

select

utmgrp.webfilter

object

Summary

URL to query.

List of URLs to query.

Query remote FortiFlow database to resolve hosts to application control entries.

utm/app-lookup/select/

GET

select

any

array

Name

hosts

Type

array

Summary

List of hosts to resolve.

Required

No

application-categories: select

Summary

URI

Retrieve a list of application control categories.

utm/application-categories/select/

HTTP Method

GET

FortiOS REST API Reference

Fortinet Inc.

Monitor API

125

select

any

array

Retrieve antivirus scanning statistics.

utm/antivirus/stats/

GET

stats

utmgrp.antivirus

object

Action

Access Group

Response Type

antivirus: stats

Summary

URI

HTTP Method

Action

Access Group

Response Type

virtual-wan

health-check: select

Summary

URI

HTTP Method

Action

Retrieve health-check statistics for each SD-WAN link.

virtual-wan/health-check/select/

GET

select

Access Group

netgrp.cfg

members: select

Summary

URI

HTTP Method

Action

Retrieve interface statistics for each SD-WAN link.

virtual-wan/members/select/

GET

select

Access Group

netgrp.cfg

FortiOS REST API Reference

Fortinet Inc.

Monitor API

webfilter

override: select

Summary

URI

HTTP Method

Action

List all administrative and user initiated webfilter overrides.

webfilter/override/select/

GET

select

126

Access Group

utmgrp.webfilter

override: delete

Summary

URI

HTTP Method

Action

Delete a configured webfilter override.

webfilter/override/delete/

POST

delete

Access Group

utmgrp.webfilter

Extra parameters

Name

mkey

Type

string

malicious-urls: select

Summary

URI

HTTP Method

Action

Access Group

ETag Caching

Response Type

Summary

ID of webfilter override to delete.

Required

No

List all URLs in FortiSandbox malicious URL database.

webfilter/malicious-urls/select/

GET

select

utmgrp.webfilter

Enabled

object

FortiOS REST API Reference

Fortinet Inc.

127

Monitor API

malicious-urls: stat

Summary

URI

HTTP Method

Action

Access Group

ETag Caching

Response Type

category-quota: select

Summary

URI

HTTP Method

Action

Retrieve statistics for the FortiSandbox malicious URL database.

webfilter/malicious-urls/stat/

GET

stat

utmgrp.webfilter

Enabled

object

Retrieve quota usage statistics for webfilter categories.

webfilter/category-quota/select/

GET

select

Access Group

utmgrp.webfilter

Extra parameters

Name

profile

user

Type

string

string

category-quota: reset

Summary

Webfilter profile.

User or IP (required if profile specified).

Required

No

No

Summary

URI

HTTP Method

Action

Reset webfilter quota for user or IP.

webfilter/category-quota/reset/

POST

reset

Access Group

utmgrp.webfilter

FortiOS REST API Reference

Fortinet Inc.

Monitor API

128

Extra parameters

Name

profile

user

Type

string

string

Summary

Webfilter profile to reset.

User or IP to reset with.

fortiguard-categories: select

Required

No

No

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

include_
unrated

convert_
unrated_id

Return FortiGuard web filter categories.

webfilter/fortiguard-categories/select/

GET

select

any

array

Type

Summary

boolean

Include Unrated category in result list.

boolean

Convert Unrated category id to the one for CLI use.

Required

No

No

trusted-urls: select

Summary

URI

HTTP Method

Action

Access Group

ETag Caching

Response Type

List all URLs in FortiGuard trusted URL database.

webfilter/trusted-urls/select/

GET

select

utmgrp.webfilter

Enabled

object

FortiOS REST API Reference

Fortinet Inc.

Monitor API

vpn

ipsec: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

tunnel

start

count

Type

string

int

int

ipsec: tunnel_up

Summary

URI

HTTP Method

Action

Access Group

Extra parameters

Name

p1name

p2name

p2serial

Type

string

string

int

ipsec: tunnel_down

Return an array of active IPsec VPNs.

vpn/ipsec/select/

GET

select

vpngrp

array

Summary

Filter for a specific IPsec tunnel name.

Starting entry index.

Maximum number of entries to return.

Bring up a specific IPsec VPN tunnel.

vpn/ipsec/tunnel_up/

POST

tunnel_up

vpngrp

Summary

IPsec phase1 name.

IPsec phase2 name.

IPsec phase2 serial.

129

Required

No

No

No

Required

Yes

Yes

No

Summary

Bring down a specific IPsec VPN tunnel.

FortiOS REST API Reference

Fortinet Inc.

Monitor API

URI

HTTP Method

Action

Access Group

Extra parameters

Name

p1name

p2name

p2serial

Type

string

string

int

ipsec: tunnel_reset_stats

vpn/ipsec/tunnel_down/

POST

tunnel_down

vpngrp

Summary

IPsec phase1 name.

IPsec phase2 name.

IPsec phase2 serial.

Summary

URI

Reset statistics for a specific IPsec VPN tunnel.

vpn/ipsec/tunnel_reset_stats/

HTTP Method

POST

Action

tunnel_reset_stats

Access Group

vpngrp

Extra parameters

Name

p1name

Type

string

Summary

IPsec phase1 name.

one-click: members

130

Required

Yes

Yes

No

Required

Yes

Summary

URI

HTTP Method

Action

Access Group

Response Type

Get information on devices registered in the Overlay Controller VPN cloud
assisted group.

vpn/one-click/members/

GET

members

vpngrp

array

FortiOS REST API Reference

Fortinet Inc.

Monitor API

one-click: status

Summary

URI

HTTP Method

Action

Access Group

Response Type

ssl: select

Summary

URI

HTTP Method

Action

Access Group

ssl: clear_tunnel

Summary

URI

HTTP Method

Action

Access Group

ssl: delete

Summary

URI

HTTP Method

Action

Access Group

131

Get the last status message from FortiCloud Overlay Controller VPN cloud
service.

vpn/one-click/status/

GET

status

vpngrp

object

Retrieve a list of all SSL-VPN sessions and sub-sessions.

vpn/ssl/select/

GET

select

vpngrp

Remove all active tunnel sessions in current virtual domain.

vpn/ssl/clear_tunnel/

POST

clear_tunnel

vpngrp

Terminate the provided SSL-VPN session.

vpn/ssl/delete/

POST

delete

vpngrp

FortiOS REST API Reference

Fortinet Inc.

Monitor API

132

Extra parameters

Name

type

index

Type

string

int

ssl: stats

Summary

URI

HTTP Method

Action

Access Group

vpn-certificate

ca: import

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Summary

The session type [websession|subsession].

The session index.

Required

Yes

Yes

Return statistics about the SSL-VPN.

vpn/ssl/stats/

GET

stats

vpngrp

Import CA certificate.

vpn-certificate/ca/import/

POST

import

vpngrp

object

Name

Type

Summary

Required

import_method string

Method of importing CA certificate.[file|scep]

scep_url

scep_ca_id

scope

string

string

string

file_content

string

SCEP server URL. Required for import via SCEP

SCEP server CA identifier for import via SCEP.

Scope of CA certificate [vdom*|global]. Global scope is only
accessible for global administrators

Provided when uploading a file: base64 encoded file data. Must not
contain whitespace or other invalid base64 characters. Must be
included in HTTP body.

Yes

No

No

No

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

crl: import

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

scope

Type

string

file_content

string

local: import

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

type

certname

password

key_file_
content

Type

string

string

string

string

Import certificate revocation lists (CRL) from file content.

vpn-certificate/crl/import/

POST

import

vpngrp

object

Summary

Scope of CRL [vdom*|global]. Global scope is only accessible for
global administrators

Provided when uploading a file: base64 encoded file data. Must not
contain whitespace or other invalid base64 characters. Must be
included in HTTP body.

133

Required

No

No

Import local certificate.

vpn-certificate/local/import/

POST

import

vpngrp

object

Summary

Required

Type of certificate.[local|pkcs12|regular]

Certificate name for pkcs12 and regular certificate types.

Optional password for pkcs12 and regular certificate types.

Key content encoded in BASE64 for regular certificate type.

Yes

No

No

No

No

scope

string

Scope of local certificate [vdom*|global]. Global scope is only
accessible for global administrators

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Name

Type

Summary

file_content

string

Provided when uploading a file: base64 encoded file data. Must not
contain whitespace or other invalid base64 characters. Must be
included in HTTP body.

134

Required

No

remote: import

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Import remote certificate.

vpn-certificate/remote/import/

POST

import

vpngrp

object

Name

Type

Summary

file_content

string

Provided when uploading a file: base64 encoded file data. Must not
contain whitespace or other invalid base64 characters. Must be
included in HTTP body.

Required

No

csr: generate

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

certname

Type

string

Generate a certificate signing request (CSR) and a private key. The CSR can be
retrieved / downloaded from CLI, GUI and REST API.

vpn-certificate/csr/generate/

POST

generate

vpngrp

object

Summary

Required

Certicate name. Used to retrieve / download the CSR. Not included
in CSR and key content.

Yes

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Name

subject

Type

string

keytype

string

keysize

int

curvename

string

Summary

Subject (Host IP/Domain Name/E-Mail). Common Name (CN) of the
certificate subject.

Generate a RSA or an elliptic curve certificate request [rsa|ec]. The
Elliptic Curve option is unavailable if the FortiGate is a Low
Encryption Device (LENC)

Key size.[1024|1536|2048|4096]. 512 only if the FortiGate is a Low
Encryption Device (LENC). Required when keytype is RSA.

Elliptic curve name. [secp256r1|secp384r1|secp521r1]. Unavailable
if the FortiGate is a Low Encryption Device (LENC). Required when
keytype is ec.

orgunits

array

List of organization units. Organization Units (OU) of the certificate
subject.

org

city

state

string

string

string

Organization (O) of the certificate subject.

Locality (L) of the certificate subject.

State (ST) of the certificate subject.

countrycode

string

Country (C) of the certificate subject.

email

string

Email of the certificate subject.

sub_alt_name

string

Subject alternative name (SAN) of the certificate.

password

string

scep_url

string

scep_password string

scope

string

Password / pass phrase for the private key. If not provided,
FortiGate generates a random one.

SCEP server URL. If provided, use the url to enroll the csr through
SCEP.

SCEP challenge password. Some SCEP servers may require
challege password. Provide it when SCEP server requires.

Scope of CSR [vdom*|global]. Global scope is only accessible for
global administrators

135

Required

Yes

Yes

No

No

No

No

No

No

No

No

No

No

No

No

No

wanopt

history: select

Summary

URI

HTTP Method

Action

Retrieve WAN opt. statistics history.

wanopt/history/select/

GET

select

Access Group

wanoptgrp

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Extra parameters

Name

period

Type

string

history: reset

Summary

URI

HTTP Method

Action

136

Summary

Statistics period [10-min*|hour|day|week|30-day].

Required

No

Reset WAN opt. statistics.

wanopt/history/reset/

POST

reset

Access Group

wanoptgrp

webcache: select

Summary

URI

HTTP Method

Action

Retrieve webcache statistics history.

wanopt/webcache/select/

GET

select

Access Group

wanoptgrp

Extra parameters

Name

period

Type

string

webcache: reset

Summary

URI

HTTP Method

Action

Summary

Statistics period [10-min*|hour|day|week|30-day].

Required

No

Reset webcache statistics.

wanopt/webcache/reset/

POST

reset

Access Group

wanoptgrp

FortiOS REST API Reference

Fortinet Inc.

Monitor API

peer_stats: select

137

Summary

URI

HTTP Method

Action

Retrieve a list of WAN opt peer statistics.

wanopt/peer_stats/select/

GET

select

Access Group

wanoptgrp

peer_stats: reset

Summary

URI

HTTP Method

Action

Reset WAN opt peer statistics.

wanopt/peer_stats/reset/

POST

reset

Access Group

wanoptgrp

webproxy

pacfile: download

Summary

URI

HTTP Method

Action

Access Group

Response Type

webcache

stats: select

Summary

URI

Download webproxy PAC file.

webproxy/pacfile/download/

GET

download

netgrp.cfg

object

Retrieve webcache statistics.

webcache/stats/select/

HTTP Method

GET

FortiOS REST API Reference

Fortinet Inc.

138

Required

No

Monitor API

Action

Access Group

Response Type

Extra parameters

Name

period

Type

string

stats: reset

Summary

URI

HTTP Method

Action

select

wanoptgrp

array

Summary

Statistics period [10min|hour|day|month].

Reset all webcache statistics.

webcache/stats/reset/

POST

reset

Access Group

wanoptgrp

wifi

client: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Retrieve a list of connected WiFi clients.

wifi/client/select/

GET

select

wifi

array

Name

Type

Summary

start

count

type

int

int

Starting entry index.

Maximum number of entries to return.

string

Request type [all*|fail-login].

Required

No

No

No

FortiOS REST API Reference

Fortinet Inc.

Monitor API

managed_ap: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

wtp_id

Type

string

Retrieve a list of managed FortiAPs.

wifi/managed_ap/select/

GET

select

wifi

array

Summary

Filter: single managed FortiAP by ID.

incl_local

boolean

Enable to include the local FortiWiFi device in the results.

managed_ap: set_status

139

Required

No

No

Summary

URI

HTTP Method

Action

Access Group

Extra parameters

Name

wtpname

admin

Type

string

string

firmware: select

Summary

URI

HTTP Method

Action

Update administrative state for a given FortiAP (enable or disable authorization).

wifi/managed_ap/set_status/

POST

set_status

wifi

Summary

FortiAP name.

New FortiAP administrative state [enable|disable|discovered].

Required

No

No

Retrieve a list of current and recommended firmware for FortiAPs in use.

wifi/firmware/select/

GET

select

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Access Group

Response Type

Extra parameters

Name

timeout

Type

string

firmware: download

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

wifi

object

140

Summary

Required

FortiGuard connection timeout (defaults to 2 seconds).

No

Download FortiAP firmware from FortiGuard to the FortiGate according to
FortiAP image ID.

wifi/firmware/download/

POST

download

wifi

object

Name

image_id

Type

string

Summary

FortiAP image ID.

Required

Yes

firmware: push

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

serial

image_id

Type

string

string

Push FortiAP firmware to the given device.

wifi/firmware/push/

POST

push

wifi

object

Summary

The target device's serial.

FortiAP image ID.

Required

Yes

Yes

FortiOS REST API Reference

Fortinet Inc.

Monitor API

firmware: upload

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

serials

serials

file_content

Type

array

string

string

141

Upload FortiAP firmware to the management FortiGate and then push to target
FortiAPs.

wifi/firmware/upload/

POST

upload

wifi

object

Summary

A list of target devices' serials.

The target device's serial.

Provided when uploading a file: base64 encoded file data. Must not
contain whitespace or other invalid base64 characters. Must be
included in HTTP body.

managed_ap: restart

Summary

URI

HTTP Method

Action

Access Group

Extra parameters

Restart a given FortiAP.

wifi/managed_ap/restart/

POST

restart

wifi

Name

wtpname

Type

string

Summary

FortiAP name.

ap_status: select

Summary

URI

Retrieve statistics for all managed FortiAPs.

wifi/ap_status/select/

Required

No

No

No

Required

No

FortiOS REST API Reference

Fortinet Inc.

142

Required

No

No

No

No

Monitor API

HTTP Method

Action

Access Group

GET

select

wifi

interfering_ap: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Name

wtp

radio

start

count

Type

string

int

int

int

euclid: select

Summary

URI

HTTP Method

Action

Access Group

euclid: reset

Summary

URI

Retrieve a list of interfering APs for one FortiAP radio.

wifi/interfering_ap/select/

GET

select

wifi

array

Summary

FortiAP ID to query.

Radio ID.

Starting entry index.

Maximum number of entries to return.

Retrieve presence analytics statistics.

wifi/euclid/select/

GET

select

wifi

Reset presence analytics statistics.

wifi/euclid/reset/

HTTP Method

POST

FortiOS REST API Reference

Fortinet Inc.

Monitor API

143

Action

Access Group

reset

wifi

rogue_ap: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

Retrieve a list of detected rogue APs.

wifi/rogue_ap/select/

GET

select

wifi

array

Name

start

count

Type

Summary

int

int

Starting entry index.

Maximum number of entries to return.

Required

No

No

rogue_ap: clear_all

Summary

URI

HTTP Method

Action

Access Group

rogue_ap: set_status

Clear all detected rogue APs.

wifi/rogue_ap/clear_all/

POST

clear_all

wifi

Summary

URI

HTTP Method

Action

Access Group

Mark detected APs as rogue APs.

wifi/rogue_ap/set_status/

POST

set_status

wifi

FortiOS REST API Reference

Fortinet Inc.

Monitor API

Extra parameters

Name

bssid

ssid

status

Type

array

array

string

spectrum: select

Summary

URI

HTTP Method

Action

Access Group

Response Type

Extra parameters

144

Required

No

No

No

Summary

List of rogue AP MAC addresses.

Corresponding list of rogue AP SSIDs.

Status to assign matching APs
[unclassified|rogue|accepted|suppressed].

Retrieve spectrum analysis information for a specific FortiAP.

wifi/spectrum/select/

GET

select

wifi

object

Name

wtp_id

Type

string

Summary

FortiAP ID to query.

Required

Yes

Examples

Method URL

/api/v2/monitor/
firewall/policy

/api/v2/monitor/
firewall/policy

GET

GET

POST

POST

/api/v2/monitor/
firewall/policy/reset

?vdom=root

/api/v2/monitor/
firewall/policy/reset

?vdom=*

URL
Parameters

?vdom=root

Body Data

Access
Group

Description

fwgrp.policy List traffic statistics for all

IPv4 policies, vdom root

?vdom=*

fwgrp.policy  List traffic statistics for all

IPv4 policies, all
accessible vdoms

fwgrp.policy Reset traffic statistics for

all IPv4 policies, vdom root

fwgrp.policy  Reset traffic statistics for

all IPv4 policies, all
accessible vdoms

FortiOS REST API Reference

Fortinet Inc.

Monitor API

145

Method URL

URL
Parameters

Body Data

Access
Group

Description

POST

POST

GET

POST

POST

POST

POST

/api/v2/monitor/
firewall/policy6/
clear_counters

/api/v2/monitor/
firewall/policy6/
clear_counters

/api/v2/monitor/
firewall/session

/api/v2/monitor/
firewall/session/
clear_all

/api/v2/monitor/
firewall/session/
close

/api/v2/monitor/
system/os/
reboot

/api/v2/monitor/
system/os/
shutdown

?vdom=root

{'policy': 1,}

fwgrp.policy Reset traffic statistics for
single IPv4 policy, vdom
root

?vdom=root

{'policy': [1, 2]}

fwgrp.policy Reset traffic statistics for

?vdom=root&
ip_version=ipv4&
start=0&count=
1&summary=True

?vdom=root

?vdom=root

{'pro': "udp", 'saddr':
"192.168.100.110",
'daddr': "96.45.33.
73", 'sport': 55933,
'dport': 8888}

sysgrp

sysgrp

sysgrp

sysgrp

sysgrp

multiple IPv4 policies,
vdom root

List the first active ipv4
firewall sessions, vdom
root

Immediately clear all
active IPv4 and IPv6
sessions, vdom root

Immediately close specific
session matched with the
filter, vdom root

Immediately reboot this
device

Immediately shutdown this
device

FortiOS REST API Reference

Fortinet Inc.

Copyright© 2019 Fortinet, Inc. All rights reserved. Fortinet®, FortiGate®, FortiCare® and FortiGuard®, and certain other marks are registered trademarks of Fortinet, Inc., in
the U.S. and other jurisdictions, and other Fortinet names herein may also be registered and/or common law trademarks of Fortinet. All other product or company names may be
trademarks of their respective owners. Performance and other metrics contained herein were attained in internal lab tests under ideal conditions, and actual performance and
other results may vary. Network variables, different network environments and other conditions may affect performance results. Nothing herein represents any binding
commitment by Fortinet, and Fortinet disclaims all warranties, whether express or implied, except to the extent Fortinet enters a binding written contract, signed by Fortinet’s
General Counsel, with a purchaser that expressly warrants that the identified product will perform according to certain expressly-identified performance metrics and, in such
event, only the specific performance metrics expressly identified in such binding written contract shall be binding on Fortinet. For absolute clarity, any such warranty will be
limited to performance in the same ideal conditions as in Fortinet’s internal lab tests. In no event does Fortinet make any commitment related to future deliverables, features or
development, and circumstances may change such that any forward-looking statements herein are not accurate. Fortinet disclaims in full any covenants, representations, and
guarantees pursuant hereto, whether express or implied. Fortinet reserves the right to change, modify, transfer, or otherwise revise this publication without notice, and the most
current version of the publication shall be applicable.

