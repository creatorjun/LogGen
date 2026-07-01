PAN-OS® and Panorama™API Usage
Guide

Version 9.1

docs.paloaltonetworks.com

Contact Informaon

Corporate Headquarters:

Palo Alto Networks

3000 Tannery Way

Santa Clara, CA 95054

www.paloaltonetworks.com/company/contact-support.html

About the Documentaon

• For the most recent version of this guide or for access to related documentaon, visit the

Technical Documentaon portal docs.paloaltonetworks.com.

• To search for a speciﬁc topic, go to our search page docs.paloaltonetworks.com/search.html.

• Have feedback or quesons for us? Leave a comment on any page in the portal, or write to us

at documentaon@paloaltonetworks.com.

Copyright

Palo Alto Networks, Inc.

www.paloaltonetworks.com
©2019–2022 Palo Alto Networks, Inc. Palo Alto Networks is a registered trademark of Palo
Alto Networks. A list of our trademarks can be found at www.paloaltonetworks.com/company/
trademarks.html. All other marks menoned herein may be trademarks of their respecve
companies.

Last Revised

June 22, 2022

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

2

©2022 Palo Alto Networks, Inc.

Table of Contents

About the PAN-OS API.................................................................................... 5
PAN-OS XML API Components............................................................................................... 6
Structure of a PAN-OS XML API Request.............................................................................7
API Authencaon and Security.................................................................................. 7
XML and XPath.................................................................................................................8
XPath Node Selecon..................................................................................................... 9

Get Started with the PAN-OS XML API.................................................... 11
Enable API Access.....................................................................................................................12
Get Your API Key...................................................................................................................... 13
Make Your First API Call......................................................................................................... 14
Authencate Your API Requests........................................................................................... 16
Explore the API..........................................................................................................................17
Use the API Browser.................................................................................................... 17
Use the CLI to Find XML API Syntax....................................................................... 19
Use the Web Interface to Find XML API Syntax................................................... 20
PAN-OS XML API Error Codes..............................................................................................23

PAN-OS XML API Use Cases........................................................................25
Upgrade a Firewall to the Latest PAN-OS Version (API)................................................. 26
Show and Manage GlobalProtect Users (API).................................................................... 30
Query a Firewall from Panorama (API)................................................................................ 32
Upgrade PAN-OS on Mulple HA Firewalls through Panorama (API).......................... 35
Automacally Check for and Install Content Updates (API)........................................... 43
Enforce Policy using External Dynamic Lists and AutoFocus Arfacts (API)...............48
Conﬁgure SAML 2.0 Authencaon (API).......................................................................... 50

PAN-OS XML API Request Types................................................................55
PAN-OS XML API Request Types and Acons..................................................................56
Request Types.................................................................................................................56
Conﬁguraon Acons................................................................................................... 56
Asynchronous and Synchronous Requests to the PAN-OS XML API........................... 59
Conﬁguraon (API)....................................................................................................................61
Get Acve Conﬁguraon............................................................................................. 61
Get Candidate Conﬁguraon...................................................................................... 63
Set Conﬁguraon........................................................................................................... 64
Edit Conﬁguraon..........................................................................................................66
Delete Conﬁguraon.....................................................................................................67
Rename Conﬁguraon.................................................................................................. 68

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

3

©2022 Palo Alto Networks, Inc.

Table of Contents

Clone Conﬁguraon...................................................................................................... 68
Move Conﬁguraon.......................................................................................................69
Override Conﬁguraon.................................................................................................69
Mul-Move or Mul-Clone Conﬁguraon.............................................................. 70
View Conﬁguraon Node Values for XPath............................................................70
Commit Conﬁguraon (API)....................................................................................................72
Commit............................................................................................................................. 72
Commit-All.......................................................................................................................74
Run Operaonal Mode Commands (API)............................................................................ 76
Get Reports (API).......................................................................................................................81
Dynamic Reports............................................................................................................81
Predeﬁned Reports........................................................................................................ 83
Custom Reports..............................................................................................................84
Export Files (API).......................................................................................................................86
Export Packet Captures................................................................................................86
Export Cerﬁcates and Keys...................................................................................... 88
Export Technical Support Data...................................................................................89
Import Files (API).......................................................................................................................92
Imporng Basics.............................................................................................................92
Import  Files......................................................................................................................93
Retrieve Logs (API).................................................................................................................... 94
API Log Retrieval Parameters..................................................................................... 94
Example: Use the API to Retrieve Traﬃc Logs....................................................... 95
Apply User-ID Mapping and Populate Dynamic Groups (API)........................................97
Get Version Info (API)............................................................................................................103

Get Started with the PAN-OS REST API................................................. 105
PAN-OS REST API.................................................................................................................. 106
Access the PAN-OS REST API.............................................................................................107
Resource Methods and Query Parameters (REST API)..................................................111
PAN-OS REST API Request and Response Structure.................................................... 114
PAN-OS REST API Error Codes.......................................................................................... 118
Work With Objects (REST API)........................................................................................... 119
Create a Security Policy Rule (REST API)..........................................................................123
Work with Policy Rules on Panorama (REST API)...........................................................127
Create a Tag (REST API)........................................................................................................131
Conﬁgure a Security Zone (REST API)...............................................................................132
Conﬁgure an SD-WAN Interface (REST API)................................................................... 133
Create an SD-WAN Policy Pre Rule (REST API)..............................................................137

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

4

©2022 Palo Alto Networks, Inc.

About the PAN-OS API

The PAN-OS® and Panorama™ API allows you to manage ﬁrewalls and Panorama
through a third-party service, applicaon, or script. The ﬁrewalls and Panorama
support two types of API—XML API and REST API.

The XML API uses a tree of XML nodes to map ﬁrewall or Panorama funconality. To
make an API request, you must specify the XPath (XML Path Language) to the XML
node that corresponds to a speciﬁc seng or acon. XPath allows you to navigate
through the hierarchical XML tree structure for ﬁrewalls and Panorama. To get started,
see:

> PAN-OS XML API Components

> Structure of a PAN-OS XML API Request

You can use the REST API to Create, Update, Read, Delete (CRUD) Objects and
Policies on the ﬁrewalls; you can access the REST API directly on the ﬁrewall or use
Panorama to perform these operaon on policies and objects from a central locaon
and push them to the managed ﬁrewalls. To get started, see Access the PAN-OS REST
API.

Because PAN-OS API funconality mirrors that of both the web interface and the
CLI, you should familiarize yourself with both. Reading relevant porons of the
PAN-OS Administrator’s Guide will help you get a beer understanding of ﬁrewall
funconalies that you can access using the API. You should also be knowledgeable
about web service APIs, HTTP, XML, and XPath.

5

About the PAN-OS API

PAN-OS XML API Components

Use the PAN-OS XML API when you want to automate tasks you need to perform, such as:

• Create, update, and modify ﬁrewall and Panorama conﬁguraons.

• Execute operaonal mode commands, such as restart the system or validate conﬁguraons.

• Retrieve reports.

• Manage users through User-ID.

• Update dynamic objects without having to modify or commit new conﬁguraons.

The PAN-OS XML API oﬀers a number of components to automate access and conﬁguraon of
Palo Alto Networks ﬁrewalls and Panorama.

Feature

Descripon

Full access to PAN-OS
funconality

The PAN-OS XML API allows you to access almost all of the
funconality normally provided through the ﬁrewall web
interface and CLI.

Secure authencaon and
access using API key and admin
roles

Use your administrave username and password to generate
an API key to authencate API calls. Granular roles allow you
to grant API access to speciﬁc funconality including reports,
logs, and operaonal mode commands.

Opons to view XML syntax
through API browser, CLI and
web interface debug mode

To explore all various funcons of the API, you can use the
API browser through the ﬁrewall web interface. You can
also enable debug mode through the CLI to see the API
equivalent of CLI commands.

To learn about the PAN-OS REST API, see PAN-OS REST API.

To learn about changes to the latest version of CLI commands that aﬀect corresponding PAN-OS
XML API requests, see the PAN-OS CLI Quick Start.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

6

©2022 Palo Alto Networks, Inc.

About the PAN-OS API

Structure of a PAN-OS XML API Request

A PAN-OS XML API request typically comprises a number of parameters, as shown in the example
below:

curl -X GET "https://<firewall>/api/?
type=<type>&action=<action>&xpath=<xpath>&key=<apikey>"

• API key (key=): The API key allows you to authencate yourself to the API when making
requests. Learn about API Authencaon and Security and how to Get Your API Key.

• Request type (type=): Because the XML API allows you to perform a wide array of requests,
you must ﬁrst specify the type of request you want, ranging from conﬁguraon to operaon,
imporng to exporng, and from reports to user ID. Learn more about Request Types.

• Acon (action=): When the request type is config (conﬁguraon) or op (operaonal mode
command), you must also specify an associated acon, such as edit, delete, or move. Learn
more about Conﬁguraon Acons.

• XML and XPath elements (xpath= or cmd=): When using conﬁguraon or operaonal mode

commands on the ﬁrewall, you include only the XML or the XPath that speciﬁes the XML node.
Learn more about XML and XPath and XPath Node Selecon.

To make requests to the PAN-OS XML API, you can use the GET and POST methods.

Use a GET request when the query size is less than 2K and you want to pass strings in the Request
URL. When using the GET method, append the query string to the request URL as a URL-encoded
parameter string:

GET /api/?type=keygen&user=<username>&password=<password>

Use a POST request when you are sending large amounts of form data (the request size is
between 2K to 5MB; limit the request size to 5MB) or when you are passing non-ASCII characters.
Some API requests, such as imporng ﬁles, require POST. When using the POST method, pass the
parameters in the request body. In this example, the request body includes the login credenals:

POST /api/ HTTP/1.1

Content-Type: application/x-www-form-urlencoded

password=<password>&user=<username>&type=keygen

If you want to learn about the PAN-OS REST API structure, see PAN-OS REST API Request and
Response Structure.

API Authencaon and Security

To use the API (XML or REST), you must enable API access for your administrators and get your
API key. By default, the ﬁrewall and Panorama support API requests over HTTPS. To make API
request over HTTP, you must conﬁgure an interface management proﬁle.

To authencate your API request to the ﬁrewall or Panorama, provide the API key in any of the
following ways:

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

7

©2022 Palo Alto Networks, Inc.

About the PAN-OS API

• Use the custom HTTP header, X-PAN-KEY: <key> to include the API key in the HTTP

header.

• For the XML API, include the API key as a query parameter in the HTTP request URL.

• Use Basic Authencaon to pass the admin credenals as username:password with Base64

encoding in an Authorizaon header ﬁeld.

Authorization: Basic amJPbLxpbw9UaTpXb3JrKjIwMDA=

You cannot use basic authencaon when you Get Your API Key.

To enforce key rotaon set an API key lifeme; you can also revoke all API keys to protect from
accidental exposure.

XML and XPath

The PAN-OS XML API uses XML for both requests and responses. When making requests,
construct an HTTPS GET or POST request with the correct type and acon along with the correct
XPath. Here is an example API request:

https://<firewall>/api/?type=config&action=show&key=<APIkey>&xpath=/
config/devices/entry/vsys/entry/rulebase/security

Ensure you replace variables such as <hostname> and <APIkey> with the IP address or hostname
of your ﬁrewall or Panorama and API key, respecvely.

When making conﬁguraon requests (type=config), you can use XPath, a syntax for selecng
nodes from within an XML document. Use the XPath to isolate and modify porons of your
conﬁguraon. The XML conﬁguraon within PAN-OS uses four diﬀerent types of nodes as shown
here:

<users>
  <entry name="admin">
    <permissions>
      <role-based>
        <superuser>yes</superuser>
      </role-based>
    </permissions>
  </entry>
  <entry name="guest">
    <permissions>
      <role-based>
        <custom>
          <profile>NewUser</profile>
        </custom>
      </role-based>
    </permissions>
  </entry>
</users>

• Root nodes are top-level nodes with no parent. Requesng the root node returns all child

elements.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

8

©2022 Palo Alto Networks, Inc.

About the PAN-OS API

• Element nodes represent containers of informaon. Element nodes can contain other

element nodes or simply act as a container of informaon. Example: <permissions></
permissions>

• Aribute nodes are nodes that contain name/value pairs. Example: <entry

name="admin"></entry>

• Text nodes contain plain text. Example: <superuser>yes</superuser>

Explore the API with the API browser, CLI, or debug console to learn how to construct XML
requests.

XPath Node Selecon

There are various ways to specify the XPath for an XML node in an API request. The simplest is
to use the locaon path of the resource. For example, to select all users within your management
conﬁguraon, use the following path:

/config/mgt-config/users

The above path speciﬁes the following XML node that includes all users:

<users>
  <entry name="admin">
    <permissions>
      <role-based>
        <superuser>yes</superuser>
      </role-based>
    </permissions>
  </entry>
  <entry name="guest">
    <permissions>
      <role-based>
        <custom>
          <profile>NewUser</profile>
        </custom>
      </role-based>
    </permissions>
  </entry>
</users>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

9

©2022 Palo Alto Networks, Inc.

About the PAN-OS API

Another method for selecng the XPath for an XML node is to select the speciﬁc node, such as
the superuser or NewUser node within the node shown above. Use XPath syntax similar to the
following to drill-down and select a speciﬁc node:

XML Node

XPath Syntax

/config/mgt-config/users/
entry/permissions/role-based/
superuser[text()='yes']

/config/mgt-config/users/entry/
permissions/role-based/custom/
profile[text()='NewUser']

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

10

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS XML API

To use the PAN-OS XML API, ﬁrst use your admin credenals to get an API key
through the keygen command type. You can then use the API key to test a simple
call.

> Enable API Access

> Get Your API Key

> Authencate Your API Requests

> Make Your First API Call

> Explore the API

> PAN-OS XML API Error Codes

This guide exercises API requests using cURL commands. However, you can use other
API tools such as Postman and RESTClient to make API requests. By default, PAN-OS
uses a self-signed cerﬁcate, so you will need to use -k parameter with cURL requests.
Alternavely, you must replace the self-signed cerﬁcate with one from a known
cerﬁcate authority. If you have an internal cerﬁcate authority, generate your own
cerﬁcate and install it on the ﬁrewall.

11

Get Started with the PAN-OS XML API

Enable API Access

The API supports the following types of Administrators and Admin roles:

• Dynamic roles: Superuser, Superuser (readonly), Device admin, Device admin (readonly), Vsys

admin, Vsys admin (readonly)

• Role-based Admins: Device, Vsys, Panorama.

Admin Role proﬁles enable or disable features on the management interfaces of the ﬁrewall
or Panorama, XML API, web interface, and CLI. For more details on Administrave Roles, see
Conﬁgure an Admin Role Proﬁle.

As a best pracce, set up a separate admin account for XML API access.

STEP 1 | Select an Admin Role proﬁle.

Go to Device > Admin Roles and select or create an admin role.

STEP 2 | Select features available to the admin role.

1. Select the XML API tab.

2. Enable or disable XML API features from the list, such as Report, Log, and Conﬁguraon.

3. Select OK to conﬁrm your change.

STEP 3 | Assign the admin role to an administrator account.

See Conﬁgure an Administrave Account.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

12

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS XML API

Get Your API Key

To use the API, you must generate the API key required for authencang API calls.

Then, when you use this API key in your request, you can either provide the URL encoded API key
in the request URL, or use the custom X-PAN-KEY: <key> parameter to add the key as a name-
value pair in the HTTP header.

If you have an exisng key and generate another key for the same user, all exisng sessions
will end for the user and previous API sessions will be deleted. If the cookie for the request
doesn’t exist but you make subsequent requests, conﬁguraon logs will show the user as
unknown.

STEP 1 | To generate an API key, make a GET or POST request to the ﬁrewall’s hostname or IP

addresses using the administrave credenals and type=keygen:

      curl -k -X GET 'https://<firewall>/api/?
type=keygen&user=<username>&password=<password>'

or

      curl -k -X POST 'https://<firewall>/api/?
type=keygen&user=<username>&password=<password>'

A successful API call returns status="success" along with the API key within the key
element:

      <response status="success">
  <result>
    <key>gJlQWE56987nBxIqyfa62sZeRtYuIo2BgzEA9UOnlZBhU==</key>
  </result>
</response>

STEP 2 |

( Oponal) Revoke API keys.

You can revoke all currently valid API keys, in the event one or more keys are compromised. To
change an API key associated with an administrator account change the password associated
with the administrator account. API keys that were generated before you expired all keys, or a
key that was created using the previous credenals will no longer be valid.

If you use Panorama to manage your ﬁrewalls, Panorama and all of the ﬁrewalls that it
manages must have the same master key.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

13

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS XML API

Make Your First API Call

Get Your API Key to make your ﬁrst call to the PAN-OS XML API. Make sure to URL encode the
request parameters in the HTTP request.

The API Docs use a number of general convenons and should not be copy and pasted verbam.
Adjust the call to your speciﬁc ﬁrewall before making the request.

Variable

<ﬁrewall>

Replace With

The IP address of the ﬁrewall or Panorama
appliance you intend to target with your
request.

apikey

The unique API key you generate.

All the query strings in Get requests must be a URL-Encoded parameter string. If you use a space
in the URL-Encoded request, you must include either a plus sign or %20 to replace the space.

If you have trouble replicang any of the API requests in our documentaon as a ﬁrst step, Use
the API Browser to build your requests.

STEP 1 | Make a cURL call to get system informaon, which returns the IP address, hostname, and

model of your ﬁrewall. Be sure to include the API key:

      curl -k 'https://<firewall>//api/?
type=op&cmd=<show><system><info></info></system></
show>&key=<apikey>'

When you make your API calls, as an alternave to providing the URL encoded API
key in the request URL, you can use the custom X-PAN-KEY: <key> parameter to add
the key as a name value pair in the HTTP header. For example, curl -H "X-PAN-
KEY: LU234T02234565s2Z1FtZWFyWXJOSTdk1234565234565==" -k
'https://firewall_IP/api/?
type=op&cmd=<show><system><info></info></system></show>'

STEP 2 | Conﬁrm that the response to the above request looks similar to this:

      <response status="success">
  <result>
    <system>
      <hostname>PA-3050-A</hostname>
      <ip-address>10.2.3.4</ip-address>
      <public-ip-address>unknown</public-ip-address>
      <netmask>255.255.252.0</netmask>
      <default-gateway>10.2.3.1</default-gateway>
      <is-dhcp>no</is-dhcp>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

14

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS XML API

      <ipv6-address>unknown</ipv6-address>
      <ipv6-link-local-address>c123::21b:ffff:feff:c1234/64</ipv6-
link-local-address>
      <ipv6-default-gateway/>
      <mac-address>00:00:00:ff:c7:00</mac-address>
      <time>Tue Jan  8 16:22:56 2019</time>
      <uptime>0 days, 18:28:38</uptime>
      <devicename>PA-3050-A</devicename>
      <family>3000</family>
      <model>PA-3050</model>
      <serial>001701000529</serial>
      <cloud-mode>non-cloud</cloud-mode>
      <sw-version>9.0.0-b36</sw-version>
      <global-protect-client-package-version>0.0.0</global-protect-
client-package-version>
      <app-version>8111-5239</app-version>
      <app-release-date>2019/01/07 15:51:30 PST</app-release-date>
      <av-version>3328-3783</av-version>
      <av-release-date>2019/01/07 11:22:02 PST</av-release-date>
      <threat-version>8111-5239</threat-version>
      <threat-release-date>2019/01/07 15:51:30 PST</threat-release-
date>
      <wf-private-version>0</wf-private-version>
      <wf-private-release-date>unknown</wf-private-release-date>
      <url-db>paloaltonetworks</url-db>
      <wildfire-version>0</wildfire-version>
      <wildfire-release-date/>
      <url-filtering-version>20190109.20005</url-filtering-version>
      <global-protect-datafile-version>unknown</global-protect-
datafile-version>
      <global-protect-datafile-release-date>unknown</global-
protect-datafile-release-date>
      <global-protect-clientless-vpn-version>0</global-protect-
clientless-vpn-version>
      <global-protect-clientless-vpn-release-date/>
      <logdb-version>9.0.10</logdb-version>
      <platform-family>3000</platform-family>
      <vpn-disable-mode>off</vpn-disable-mode>
      <multi-vsys>on</multi-vsys>
      <operational-mode>normal</operational-mode>
    </system>
  </result>
</response>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

15

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS XML API

Authencate Your API Requests

Palo Alto Networks encourages you to authencate your API requests by including a basic
authencaon token in the header of your requests. The basic authencaon header can be used
to authencate both XML and REST API requests.

STEP 1 | Convert your user name and password to Base64 format.

Example: username:password converts to dXNlcm5hbWU6cGFzc3dvcmQ=

STEP 2 | When making a request to the ﬁrewall, include the base64 converted token in the header

preceded by Authorization: Basic

Example:

curl -X GET 'https://firewall/api/?&type=config&action=get&xpath=/
config/devices/entry[@name=%27localhost.localdomain%27]/
network/interface/ethernet' -H 'Authorization: Basic
 dXNlcm5hbWU6cGFzc3dvcmQ='

STEP 3 |

Include the header in each of the subsequent requests to the ﬁrewall.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

16

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS XML API

Explore the API

There are several ways you can explore the API and learn how to construct your XML requests:

• Use the API Browser

• Use the CLI to Find XML API Syntax

• Use the Web Interface to Find XML API Syntax

Use the API Browser

Each ﬁrewall and Panorama provides an API browser that is accessible from your web browser.
The API browser lets you navigate through and view the corresponding XPath and API URL.

STEP 1 | Launch the web interface.

1. Use a web browser to navigate to the actual FQDN or IP address of your ﬁrewall:

https://<firewall>/

2. Log in with your administrator credenals when prompted to log in to the web interface.

STEP 2 | Launch the API Browser.

Go to the API browser URL on your ﬁrewall:

https://<firewall>/api

STEP 3 | Drill-down to a request.

When you ﬁrst open the API browser, the available Request Types display.

1. Select one of the request types to drill down to the next level of the XPath. Let’s start

with Conﬁguraon Commands, which equates to type=report:

2. Drill down further unl you select a request that you want to test.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

17

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS XML API

STEP 4 | Test a request.

1. Select the URL to then test that request in the browser.

The browser shows the resulng XML response in the browser:

Along with the URL, the API browser also provides the XPath as necessary, as shown
here for a descripon of a predeﬁned applicaon:

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

18

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS XML API

Use the CLI to Find XML API Syntax

Another method to determine the appropriate XML syntax and XPath for your API calls is through
the command-line interface (CLI). This method works for type=op and type=config API calls.

To learn about changes to the latest version of CLI commands that aﬀect corresponding
PAN-OS XML API requests, see the PAN-OS CLI Quick Start.

Use the CLI to enable debug mode and then run the CLI command to receive the corresponding
XML and XPath in the response.

STEP 1 | Access the CLI.

Use an SSH client or terminal to access your ﬁrewall or Panorama CLI.

STEP 2 | Enable debug mode.

Enter the following command:

debug cli on

STEP 3 | Run a CLI command.

Enter and run a CLI command. Example:

test url http://paloaltonetworks.com
<request cmd="op" cookie="7581536015878829"
 uid="1206"><operations><test><url>http://paloaltonetworks.com</
url></test></operations></request>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

19

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS XML API

STEP 4 | Use the resulng response to create an API call.

Use the cmd value and the XML elements within the operations tag to form the API call:

https://<firewall>/api/?type=op&cmd=<test><url>http://
paloaltonetworks.com</url></test>&key=<apikey>

Depending on the CLI command, the XML tag values for cmd will vary. For example,
here is a CLI command for showing ﬁrewall informaon: run show system info

The corresponding API call for the CLI command:

https://<firewall>/api/?type=op&cmd=<show><system><info></
info></system></show>&key=<apikey>

Use the Web Interface to Find XML API Syntax

You can use the web interface along with the available debug console to explore the XML and
XPath necessary for your API calls.

First log into the web interface and then open a separate window where you can view the
corresponding XML and XPath.

STEP 1 | Launch the web interface.

Launch a web browser and enter the ﬁrewall’s IP address or hostname. Enter your user
credenals.

STEP 2 | Launch the debug console.

In a separate web browser window or tab, launch the debug console:

http://<firewall>/debug

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

20

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS XML API

STEP 3 | Perform the acon you want to replicate through the API.

In the web browser, navigate to the menu and item or acon that you want to perform.

To aid in ﬁnding the relevant XML, select Clear in the debug console just before you select the
ﬁnal menu or acon.

STEP 4 | View the resulng XML syntax in the debug console.

In the debug console, select Refresh and then navigate through the console to the syntax
related to your choice or acon:

Example XML within debug console:

<request cmd="op" cookie="3885378180190727">
  <operations xml="yes">
    <show>
      <system>
        <info/>
      </system>
    </show>
  </operations>
</request>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

21

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS XML API

The corresponding API call looks like this:

https://<firewall>/api/?type=op&cmd=<show><system><info></info></
system></show>&key=<apikey>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

22

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS XML API

PAN-OS XML API Error Codes

The API response XML contains a status ﬁeld and an error ﬁeld. These are the available API error
codes and names:

Error
Code

Name

400

Bad request

403

Forbidden

Descripon

A required parameter is missing, an illegal parameter
value is used.

Authencaon or authorizaon errors including invalid
key or insuﬃcient admin access rights. Learn how to
Get Your API Key.

1

Unknown command

The speciﬁc conﬁg or operaonal command is not
recognized.

2-5

Internal errors

Check with technical support when seeing these errors.

6

7

8

Bad Xpath

Object not present

The xpath speciﬁed in one or more aributes of the
command is invalid. Check the API browser for proper
xpath values.

Object speciﬁed by the xpath is not present. For
example, entry[@name='value'] where no object with
name 'value' is present.

Object not unique

For commands that operate on a single object, the
speciﬁed object is not unique.

10

Reference count not zero

Object cannot be deleted as there are other objects
that refer to it. For example, address object sll in use
in policy.

11

12

13

14

Internal error

Check with technical support when seeing these errors.

Invalid object

Xpath or element values provided are not complete.

Object not found

Object presented in the request could not be found.

Operaon not possible

Operaon is allowed but not possible in this case.
For example, moving a rule up one posion when it is
already at the top.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

23

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS XML API

Error
Code

Name

15

Operaon denied

Descripon

Operaon is not allowed. For example, Admin not
allowed to delete own account, Running a command
that is not allowed on a passive device.

16

17

18

Unauthorized

The API role does not have access rights to run this
query.

Invalid command

Invalid command or parameters.

Malformed command

The XML is malformed.

19-20

Success

Command completed successfully.

21

22

Internal error

Check with technical support when seeing these errors.

Session med out

The session for this query med out.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

24

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

The following use cases highlight the use of the PAN-OS XML API, either to reduce
repeve steps or to automate tasks normally you perform through the web interface
or CLI.

Because the PAN-OS XML API uses a tree of XML nodes, in your API request you
must specify the correct type and acon along with the XPath Node Selecon. See
Explore the API to learn how to construct XML requests to be successful in using the
API to meet your automaon needs.

> Upgrade a Firewall to the Latest PAN-OS Version (API)

> Show and Manage GlobalProtect Users (API)

> Query a Firewall from Panorama (API)

> Upgrade PAN-OS on Mulple HA Firewalls through Panorama (API)

> Automacally Check for and Install Content Updates (API)

> Enforce Policy using External Dynamic Lists and AutoFocus Arfacts (API)

> Conﬁgure SAML 2.0 Authencaon (API)

25

PAN-OS XML API Use Cases

Upgrade a Firewall to the Latest PAN-OS Version (API)
You can use the PAN-OS XML API to update your ﬁrewall with the latest PAN-OS and Content
Release versions.

Because the PAN-OS XML API uses a tree of XML nodes, in your API request you must specify
the correct type and acon along with the XPath Node Selecon. See Explore the API to learn
how to construct XML requests.

STEP 1 | Download the latest content update.

Use the following request to ﬁrst download the latest content update:

      curl -X GET 'https://<firewall>/api/?
type=op&cmd=<request><content><upgrade><download><latest/></
download></upgrade></content></request>&key=<apikey>'

If successful, the response contains a jobid that you can use to check on the status of your
request.

      <response status="success" code="19">
  <result>
    <msg>
      <line>Download job enqueued with jobid 2</line>
    </msg>
    <job>2</job>
  </result>
</response>

STEP 2 | Check on the content download status.

Use the jobid to ensure that the content download completes successfully:

      curl -X GET 'https://<firewall>/api/?
type=op&cmd=<show><jobs><id>2</id></jobs></show>&key=<apikey>'

The response should include the following:

      <response status="success">…

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

26

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

STEP 3 |

Install the latest content update.

Use the following request to install the newly downloaded content:

      curl -X GET 'https://<firewall>/api/?
type=op&cmd<request><content><upgrade><install> <version>latest</
version></install></upgrade></content></request>key=<apikey>'

If successful, the response contains a jobid that you can use to check on the status of your
request.

      <response status="success" code="19">
  <result>
    <msg>
      <line>Content install job enqueued with jobid
       3</line>
    </msg>
    <job>3</job>
  </result>
</response>

STEP 4 | Check on the content installaon status.

Use the jobid to ensure that the content installaon completes successfully:

      curl -X GET 'https://<firewall>/api/?
type=op&cmd=<show><jobs><id>3</id></jobs></show>&key=<apikey>'

The response should include the following:

      <response status="success">…

STEP 5 | Check for the latest PAN-OS soware update.

Aer installing the latest Content Release update, check for the latest available PAN-OS
soware updates:

      curl -X GET 'https://<firewall>/api/?
type=op&cmd=<request><system><software><check></check>
       </software></system></request>&key=<apikey>'

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

27

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

In the response, the ﬁrst entry is the latest version of PAN-OS:

      <response
       status="success">
       <result>
       <sw-updates last-updated-at="2015/10/20 14:16:30">
       <msg />
       <versions>
       <version>7.1.0</version>
       <filename>PanOS_3000-7.1.0-c65</filename>
       <size>720</size>
       <size-kb>737504</size-kb>
       <released-on>2015/10/20 13:23:11</released-on>
       ...

STEP 6 | Download the latest PAN-OS soware update.

1.

In this case, the latest version is 7.1.0-c65, so download that version:

        curl -X GET 'https://<firewall>/api/?
type=op&cmd=<request><system><software><download><version>7.1.0-
c65</version></download></software></system></
request>&key=<apikey>'

2. Use the jobid in the response to ensure that the system update download completes

successfully:

        curl -X GET 'https://<firewall>/api/?
type=op&cmd=<show><jobs><id>318</id></jobs></
show>&key=<apikey>'

The response should include the following:

        <response status="success">…

STEP 7 |

Install the latest PAN-OS soware update.

To install the latest system update, include the version in a soware install request:

      curl -X GET 'https://<firewall>/api/?
type=op&cmd=<request><system><software><install><version>7.1.0-
c65</version></install></software></system></request>&key=<apikey>'

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

28

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

STEP 8 | Check on the soware installaon status.

Use the jobid in the response to ensure that the system update installs successfully:

      curl -X GET 'https://<firewall>/api/?
type=op&cmd=<show><jobs><id>320</id></jobs></show>&key=<apikey>'

The response should include the following:

      <response status="success">…

STEP 9 | Reboot the ﬁrewall.

Aer the system update installs successfully, trigger:

      curl -X GET 'https://<firewall>/api/?
type=op&cmd=<request><restart><system></system></restart></
request>&key=<apikey>'

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

29

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

Show and Manage GlobalProtect Users (API)

One common use of the PAN-OS XML API is to manage GlobalProtect users. You can use two API
requests to view and then disconnect a Global Protect user who has been logged in for too long.

STEP 1 | View all GlobalProtect users.

Make a request to view all GlobalProtect users:

      curl -X GET 'https://<firewall>/api/?
type=op&cmd=<show><global-protect-gateway><current-user/></global-
protect-gateway></show>&key=<apikey>'

The response contains a list of users along with related informaon including IP addresses,
logins, and client informaon:

      <response status="success">
  <result>
    <entry>
      <domain/>
      <islocal>yes</islocal>
      <username>dward</username>
      <computer>Dan’s iPhone</computer>
      <client>Apple iOS 8.1.2</client>
      <vpn-type>Device Level VPN</vpn-type>
      <virtual-ip>192.168.2.1</virtual-ip>
      <public-ip>166.173.63.240</public-ip>
      <tunnel-type>SSL</tunnel-type>
      <login-time>Jan.22 01:50:36</login-time>
      <login-time-utc>1421916636</login-time-utc>
      <lifetime>2592000</lifetime>
    </entry>
  </result>
</response>

The <login-time-utc> ﬁeld is the login date/me in UNIX me format (number of seconds
elapsed since 00:00:00 1 Jan 1970). To ﬁnd the list of users, ﬁlter the output for this ﬁeld and
compare the <login-time-utc> value to current date and me (or another date and me).

STEP 2 | Disconnect a GlobalProtect user.

Upon idenfying the user that you want to disconnect, send a request that includes the
GlobalProtect gateway, username, computer, and a force-logout reason:

      curl -X GET 'https://<firewall>/api/?
type=op&cmd=<request><global-protect-gateway><client-logout>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

30

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

       <gateway>Home-N</gateway><user>dward</user><reason>force-
logout</reason>
       <computer>Dan’s%20iPhone</computer></client-logout></global-
protect-gateway>
       </request>&key=<apikey>'

A successful response shows that the user has been successfully disconnected:

      <response status="success">
  <result>
    <response status="success">
      <gateway>Home-N</gateway>
      <domain>(null)</domain>
      <user>dward</user>
      <computer>Dan’s iPhone</computer>
    </response>
  </result>
</response>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

31

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

Query a Firewall from Panorama (API)

The target parameter on Panorama allows you to redirect queries to a managed ﬁrewall.
Redirecng queries to ﬁrewalls helps to reduce me and the number of steps required to issue
repeve commands. Use the scripng language of your choice to store ﬁrewall serial numbers
and use them to issue a query to several ﬁrewalls.

Because the PAN-OS XML API uses a tree of XML nodes, in your API request you must
specify the correct type and acon along with the XPath Node Selecon. See Explore
the API to learn how to construct XML requests.

STEP 1 | Get a list of managed ﬁrewalls.

      curl -X GET "https://<panorama>/api/?
key=<key>&type=op&cmd=<show><devices><all></all></devices></show>"

If you want to get a list of connected ﬁrewalls only, use

       curl -X GET "https://<panorama>/api/?
key=<key>&type=op&cmd=<show><devices><connected></
connected></devices></show>"

The response includes the serial number (serial) of each ﬁrewall.

      <response
       status="success">
       <result>
       <devices>
       name="007200002517">
       <serial>007200002342</serial>
       <connected>yes</connected>
       <unsupported-version>no</unsupported-version>
       <deactivated>no</deactivated>
       <hostname>PM-6-1-VM</hostname>
       <ip-address>10.3.4.137</ip-address>
       <mac-addr />
       <uptime>81 days, 20:39:41</uptime>
       <family>vm</family>
       <model>PA-VM</model>
       <sw-version>6.1.3</sw-version>
       <app-version>555-3129</app-version>
       <av-version>2254-2693</av-version>
       <wildfire-version>91873-101074</wildfire-version>
       <threat-version>555-3129</threat-version>
       <url-db>paloaltonetworks</url-db>
       <url-filtering-version>2016.02.02.416</url-filtering-
version>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

32

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

       <logdb-version>6.1.3</logdb-version>
       <vpnclient-package-version />
       <global-protect-client-package-version>0.0.0</global-
protect-client-package-version>
       <vpn-disable-mode>no</vpn-disable-mode>
       <operational-mode>normal</operational-mode>
       <multi-vsys>no</multi-vsys>
       <vsys>
       name="vsys1">
       <display-name>vsys1</display-name>
       <shared-policy-status />
       <shared-policy-md5sum>4a0913667df83ff1098492e2e2ec1756</
shared-policy-md5sum>
       </entry>
       </vsys>
       </entry>
       <!--truncated -->
       </devices>
       </result>
       </response>

The response contains a <serial> XML element for each ﬁrewall.

STEP 2 | Collect ﬁrewall serial numbers.

In your script or code, store the ﬁrewall serial numbers returned in the response to the
previous request.

STEP 3 | Query a ﬁrewall from Panorama.

A normal request to show system informaon on a ﬁrewall looks like this:

      curl -X GET "https://<firewall>/api/?
key=<key>&type=op&cmd=<show><system><info></info></system></show>"

To directly target a ﬁrewall through Panorama, append the ﬁrewall serial number to the
request:

      curl -X GET "https://<panorama>/api/?
key=<key>&type=op&cmd=<show><system><info></info></system></
show>&target=<device-serial-number>"

A successful response should look like this:

      <response status="success">
  <result>
    <system>
      <hostname>firewall</hostname>
      <ip-address>10.41.0.8</ip-address>
      <netmask>255.255.224.0</netmask>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

33

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

      <default-gateway>10.41.0.1</default-gateway>
      <is-dhcp>no</is-dhcp>
      <ipv6-address>unknown</ipv6-address>
      <ipv6-link-local-address>fe80::21c:17cf:feff:c04a/64</ipv6-
link-local-address>
      <ipv6-default-gateway/>
      <mac-address>00:1b:17:fc:c0:4a</mac-address>
      <time>Tue Oct 27 13:39:09 2015</time>
      <uptime>12 days, 0:05:26</uptime>
      <devicename>pm-firewall</devicename>
      <family>3000</family>
      <model>PA-3020</model>
      <serial>001802000104</serial>
      <sw-version>7.1.0-c54</sw-version>
      <global-protect-client-package-version>2.0.0</global-protect-
client-package-version>
      <app-version>537-2965</app-version>
      <app-release-date>2015/10/26 18:10:48</app-release-date>
      <av-version>2149-2586</av-version>
      <av-release-date>2015/10/26 15:31:55</av-release-date>
      <threat-version>537-2965</threat-version>
      <threat-release-date>2015/10/26 18:10:48</threat-release-
date>
      <wf-private-version>0</wf-private-version>
      <wf-private-release-date>unknown</wf-private-release-date>
      <url-db>paloaltonetworks</url-db>
      <wildfire-version>80683-89773</wildfire-version>
      <wildfire-release-date>unknown</wildfire-release-date>
      <url-filtering-version>2015.10.27.226</url-filtering-version>
      <global-protect-datafile-version>1445974904</global-protect-
datafile-version>
      <global-protect-datafile-release-date>2015/10/27 19:41:44</
global-protect-datafile-release-date>
      <logdb-version>7.0.9</logdb-version>
      <platform-family>3000</platform-family>
      <vpn-disable-mode>off</vpn-disable-mode>
      <multi-vsys>on</multi-vsys>
      <operational-mode>normal</operational-mode>
    </system>
  </result>
</response>

Repeat this request for each managed or connected ﬁrewall.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

34

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

Upgrade PAN-OS on Mulple HA Firewalls through
Panorama (API)

This use case highlights the ability of the PAN-OS XML API to automate a more complex
procedure, namely upgrading ﬁrewalls set up as acve-passive high-availability (HA) pair.
Normally, this procedure involves mulple, manual steps on individual ﬁrewalls.

This is a high-level overview of the steps you must take in this procedure. You script or
applicaon must incorporate error-checking and logic to implement this sequence of steps.

Because the PAN-OS XML API uses a tree of XML nodes, in your API request you must
specify the correct type and acon along with the XPath Node Selecon. See Explore
the API to learn how to construct XML requests.

STEP 1 | Check for the latest PAN-OS soware update through Panorama

Check for the latest available PAN-OS soware updates. Include the ﬁrewall serial number in
your request:

curl -X GET "https://<panorama>/api/?
type=op&cmd=<request><system><software><check></check></software></
system></request>&target=007200002517&key=<apikey>"

The response contains an array of results sorted to show the latest version ﬁrst:

<response status="success">

  <result>

    <sw-updates last-updated-at="2016/02/03 08:29:09">

      <msg />

      <versions>

        >

          <version>7.1</version>

          <filename>PanOS_vm-7.1</filename>

          <size>540</size>

          <size-kb>553964</size-kb>

          <released-on>2016/02/02 10:57:20</released-on>

          <release-notes><![CDATA[https://10.44.2.19/
updates/ReleaseNotes.aspx?type=sw&versionNumber=7.1.0-
c158&product=panos&platform=vm]]></release-notes>

          <downloaded>no</downloaded>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

35

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

          <current>no</current>

          <latest>yes</latest>

        </entry>

<!-- truncated -->

      </versions>

    </sw-updates>

  </result>

</response>

STEP 2 | Download the latest PAN-OS soware update.

1.

In this case, the latest version is 7.1.0-c65, so download that version:

curl -X GET

'https://<firewall>/api/?
type=op&cmd=<request><system><software><download><version>7.1.0

-c65</version></download></software></system></
request>&key=<apikey>'

2. Use the jobid in the response to ensure that the system update download completes

successfully:

curl -X GET 'https://<firewall>/api/?type=op&action=get&job-
id=318&key=<apikey>'

The response should include the following:

<response status="success">…

STEP 3 |

Install the latest PAN-OS soware update.

To install the latest system update, include the version in a soware install request:

curl -X GET 'https://<firewall>/api/?
type=op&cmd=<request><system><software><install><version>7.1.0-
c65</version></install></software></system></request>&key=<apikey>'

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

36

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

STEP 4 | Check on the soware installaon status.

Use the jobid in the response to ensure that the system update installs successfully:

curl -X GET 'https://<firewall>/api/?type=op&action=get&job-
id=<jobid>&key=<apikey>'

The response should include the following:

<response status="success">…

STEP 5 | Get a list of connected ﬁrewalls.

Get a list of connected ﬁrewalls that Panorama manages:

curl -X GET "https://<panorama>/api/?
type=op&cmd=<show><devices><connected></connected></devices></
show>&key=<apikey>"

The response includes the serial number (serial) of each ﬁrewall.

<response status="success">

:  <result>

:    <devices>

:       name="007200002517">

:        <serial>007200002342</serial>

:        <connected>yes</connected>

:        <unsupported-version>no</unsupported-version>

:        <deactivated>no</deactivated>

:        <hostname>PM-6-1-VM</hostname>

:        <ip-address>10.3.4.137</ip-address>

:        <mac-addr />

:        <uptime>81 days, 20:39:41</uptime>

        <family>vm</family>

        <model>PA-VM</model>

        <sw-version>6.1.3</sw-version>

        <app-version>555-3129</app-version>

        <av-version>2254-2693</av-version>

        <wildfire-version>91873-101074</wildfire-version>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

37

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

        <threat-version>555-3129</threat-version>

        <url-db>paloaltonetworks</url-db>

        <url-filtering-version>2016.02.02.416</url-filtering-
version>

        <logdb-version>6.1.3</logdb-version>

        <vpnclient-package-version />

        <global-protect-client-package-version>0.0.0</global-
protect-client-package-version>

        <vpn-disable-mode>no</vpn-disable-mode>

        <operational-mode>normal</operational-mode>

        <multi-vsys>no</multi-vsys>

        <vsys>

           name="vsys1">

            <display-name>vsys1</display-name>

            <shared-policy-status />

            <shared-policy-
md5sum>4a0913667df83ff1098492e2e2ec1756</shared-policy-md5sum>

          </entry>

        </vsys>

      </entry>

   <!--truncated -->

    </devices>

  </result>

</response>

The response contains a <serial> XML element that contains each ﬁrewall serial number.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

38

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

STEP 6 | Check for the latest PAN-OS soware update.

Check to see if new soware is available on your HA pair:

curl -X GET "https://<panorama>/api/?
type=op&cmd=<request><system><software><check></check></software></
system></request>&target=<serialnumber>&key=<apikey>"

The response contains an array of results sorted to show the latest version ﬁrst:

<response status="success">

<result>

<sw-updates last-updated-at="2016/02/03 08:29:09">

<msg />

<versions>

<version>7.1</version>

<filename>PanOS_vm-7.1</filename>

<size>540</size>

<size-kb>553964</size-kb>

<released-on>2016/02/02 10:57:20</released-on>

<release-notes><![CDATA[https://10.44.2.19/updates/
ReleaseNotes.aspx?type=sw&versionNumber=7.1.0-
c158&product=panos&platform=vm]]></release-notes>

<downloaded>no</downloaded>

<current>no</current>

<latest>yes</latest>

</entry>

<!-- truncated -->

</versions>

</sw-updates>

</result>

</response>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

39

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

STEP 7 | Download the latest PAN-OS soware update.

Aer determining the latest system update, download it to both ﬁrewalls in the HA pair:

curl -X GET "https://<panorama>/api/?
type=op&cmd=<request><system><software><download><version>7.1</
version></download></software></system></
request>&target=<serialnumber>&key=<apikey>"

The response contains a job ID:

<response status="success" code="19">
  <result>
    <msg>
      <line>Download job enqueued with jobid 3448</line>
    </msg>
    <job>3448</job>
  </result>
</response>

Use the job ID to check on the download status:

curl -X GET "https://<panorama>/api/?
type=op&cmd=<show><jobs><id>3448</id></jobs></
show>&target=<serialnumber>&key=<apikey>"

The response contains a job status of FIN when the download is complete:

<response status="success">
  <result>
    <job>
      <tenq>2016/02/03 08:32:00</tenq>
      <id>3448</id>
      <user/>
      <type>Downld</type>
      <status>FIN</status>
      <stoppable>no</stoppable>
      <result>OK</result>
      <tfin>08:32:10</tfin>
      <progress>08:32:10</progress>
      <details>
        <line>Successfully downloaded</line>
        <line>Preloading into software manager</line>
        <line>Successfully loaded into software manager</line>
      </details>
      <warnings/>
    </job>
  </result>
</response>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

40

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

STEP 8 | Suspend the acve HA ﬁrewall.

Suspend the acve ﬁrewall in your high-availability ﬁrewall pair:

curl -X GET "https://<panorama>/api/?type=op&cmd=<request><high-
availability><state><suspend></suspend></state></high-
availability></request>&target=<serialnumber>&key=<apikey>"

The response conﬁrms the acve ﬁrewall has been suspended:

<response status="success">
  <result>Successfully changed HA state to suspended</result>
</response>

STEP 9 |

Install the latest soware update on the suspended HA pair.

Aer suspending the acve HA ﬁrewall, install the system update on it:

curl -X GET "https://<panorama>/api/?
type=op&cmd=<request><system><software><install><version>version</
version></install></software></system></
request>&target=<serialnumber>&key=<apikey>"

The response shows the system update is queued:

<response status="success" code="19">
  <result>
    <msg>
      <line>Software install job enqueued with jobid 3453. Run
 'show jobs id 3453' to monitor its status. Please reboot the
 device after the installation is done.</line>
    </msg>
    <job>3453</job>
  </result>
</response>

STEP 10 | Check on the soware installaon status.

Use the jobid in the response to ensure that the system update installs successfully:

curl -X GET 'https://<panorama>/api/?type=op&action=get&job-
id=jobid&target=<serialnumber>&key=<apikey>

The response should include the following:

<response status="success">…

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

41

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

STEP 11 | Reboot the suspended HA peer.

Aer installing the latest system update, reboot the suspended HA peer:

curl -X GET "https://<panorama>/api/?
type=op&cmd=<request><restart><system></system></restart></
request>&target=<serialnumber>&key=<apikey>"

STEP 12 | Verify that the upgrade is successful.

Show system informaon on your upgraded HA peer to ensure it has the latest system update
and is operaonal:

curl -X GET "https://<panorama>/api/?
type=op&cmd=<show><system><info></info></system></
show>&target=<serialnumber>&key=<apikey>"

STEP 13 | Makes the suspended HA peer acve.

Aer you verify that the system update on the suspended HA peer is successful, make it acve
again:

curl -X GET "https://<panorama>/api/?type=op&cmd=<request><high-
availability><state><functional></functional></state></high-
availability></request>&target=<serialnumber>&key=<apikey>"

The response conﬁrms the acve ﬁrewall is now acve:

 <response status="success">
  <result>Successfully changed HA state to functional</result>
</response>

STEP 14 | Install the system update on the passive HA peer.

Once the suspended HA ﬁrewall is acve, you can then repeat steps 5-8 on the now passive
HA peer.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

42

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

Automacally Check for and Install Content Updates
(API)

Using the XML API, you can programmacally check and install new content updates, including
anvirus, WildFire, and GlobalProtect updates. Check for new updates available and download
updates that have been released for at least one week.

Download, upgrade, and installaon requests are asynchronous. The API responds with a
job ID while it processes your request. In your subsequent request, you use this job ID to
check on the result of your original request:

curl -X GET "https://<firewall>/api/?type=op&cmd=<show><jobs><id></
id></jobs></show>&key=<apikey>"

STEP 1 | Check for installed content on your ﬁrewall. Run the following request to view current

system informaon:

curl -X GET "https://<firewall>/api/?
type=op&cmd=<show><system><info></info></system></
show>&key=<apikey>"

STEP 2 | Conﬁrm that the API response to the request in the previous step includes the currently

installed updates on your ﬁrewall:

<response status="success">
  <result>
    <system>
      <hostname>pm-firewall</hostname>
      <ip-address>10.47.0.8</ip-address>
      <netmask>255.255.254.0</netmask>
      <default-gateway>10.47.0.1</default-gateway>
      <is-dhcp>no</is-dhcp>
      <ipv6-address>unknown</ipv6-address>
      <ipv6-link-local-address>fe80::21b:17ff:feff:c04a/64</ipv6-
link-local-address>
      <ipv6-default-gateway/>
      <mac-address>00:1b:17:ff:c0:4a</mac-address>
      <time>Mon Jul 11 17:51:37 2016</time>
      <uptime>11 days, 7:38:34</uptime>
      <devicename>pm-firewall</devicename>
      <family>3000</family>
      <model>PA-3020</model>
      <serial>001801000104</serial>
      <sw-version>7.1.3</sw-version>
      <global-protect-client-package-version>2.0.0</global-protect-
client-package-version>
      <app-version>598-3427</app-version>
      <app-release-date>2016/07/09 22:30:55</app-release-date>
      <av-version>2416-2855</av-version>
      <av-release-date>2016/07/10 11:27:57</av-release-date>
      <threat-version>598-3427</threat-version>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

43

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

      <threat-release-date>2016/07/09 22:30:55</threat-release-
date>
      <wf-private-version>0</wf-private-version>
      <wf-private-release-date>unknown</wf-private-release-date>
      <url-db>paloaltonetworks</url-db>
      <wildfire-version>80426-81466</wildfire-version>
      <wildfire-release-date>2016/07/11 17:45:11</wildfire-release-
date>
      <url-filtering-version>2016.07.11.248</url-filtering-version>
      <global-protect-datafile-version>1468280405</global-protect-
datafile-version>
      <global-protect-datafile-release-date>2016/07/11 23:40:05</
global-protect-datafile-release-date>
      <logdb-version>7.0.9</logdb-version>
      <platform-family>3000</platform-family>
      <vpn-disable-mode>off</vpn-disable-mode>
      <multi-vsys>on</multi-vsys>
      <operational-mode>normal</operational-mode>
    </system>
  </result>
</response>

STEP 3 | Note the currently installed versions for the following updates, so that you can compare the

values aer you check for the latest updates:

• global-protect-client-package-version: GlobaProtect

• app-version: Applicaon and threat signatures.

• av-version: Anvirus signatures

• wildﬁre-version: WildFire malware and anvirus signatures

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

44

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

STEP 4 | Check for new, available updates with the following requests and store the version ﬁeld in

the response, which is the version ﬁeld for GlobalProtect, and the app-version ﬁeld for
all others:

• GlobalProtect:

curl -X GET "https://<firewall>/api/?type=op&cmd=<request><global-
protect-client><software><check></check></software></global-
protect-client></request>&key=<apikey>"

• WildFire:

curl -X GET "https://<firewall>/api/?
type=op&cmd=<request><wildfire><upgrade><check></check></upgrade></
wildfire></request>&key=<apikey>"

• Applicaon & Threat:

curl -X GET "https://<firewall>/api/?
type=op&cmd=<request><content><upgrade><check></check></upgrade></
content></request>&key=<apikey>"

• Anvirus:

curl -X GET "https://<firewall>/api/?type=op&cmd=<request><anti-
virus><upgrade><check></check></upgrade></anti-virus></
request>&key=<apikey>"

Example response:

<response status="success">
<result>
<sw-updates last-updated-at="2016/05/19 14:34:34">
<msg/>
<versions>
<entry>
<version>4.0.0-c16</version>
<filename>PanGP-4.0.0-c16</filename>
<size>44</size>
<size-kb>45321</size-kb>
<released-on>2016/07/08 15:41:18</released-on>
<release-notes>
<![CDATA[
https://firewall/updates/ReleaseNotes.aspx?
type=sw&versionNumber=4.0.0-c16&product=gpclient&platform=any
]]>
</release-notes>
<downloaded>no</downloaded>
<current>no</current>
<latest>no</latest>
<uploaded>no</uploaded>
</entry>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

45

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

<!--TRUNCATED-->

Take note of the released-on XML ﬁeld to verify that updates have been released for at
least a week.

STEP 5 |

In your script or code, compare the version values for currently installed updates to new,
available updates. It is recommended that you only install updates that have been available
for at least a week.

STEP 6 | Download the latest content updates with these requests:

• GlobalProtect:

curl -X GET "https://<firewall>/api/?type=op&cmd=<request><global-
protect-client><software><download><version>versionnumber</
version></download></software></global-protect-client></
request>&key=<apikey>"

• WildFire:

curl -X GET "https://<firewall>/api/?
type=op&cmd=<request><wildfire><upgrade><download><latest></
latest></download></upgrade></wildfire></request>&key=<apikey>"

• Applicaon & Threat:

curl -X GET "https://<firewall>/api/?
type=op&cmd=<request><content><upgrade><download><latest></
latest></download></upgrade></content></request>"

• Anvirus:

curl -X GET "https://<firewall>/api/?type=op&cmd=<request><anti-
virus><upgrade><download><latest></latest></download></upgrade></
anti-virus></request>&key=<apikey>"

The response contains a job ID that you can use to check on the status of the request.
Example:

<response status="success" code="19">
  <result>
    <msg>
      <line>Content install job enqueued with jobid 299</line>
    </msg>
    <job>299</job>
  </result>
</response>

Learn more about Asynchronous and Synchronous Requests to the PAN-OS XML API.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

46

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

STEP 7 |

Install the latest content updates with these requests:

• GlobalProtect:

curl -X GET "https://<firewall>/api/?type=op&cmd=<request><global-
protect-client><software><activate><version>versionnumber</
version></activate></software></global-protect-client></
request>&key=<apikey>"

• WildFire:

curl -X GET "https://<firewall>/api/?
type=op&cmd=<request><wildfire><upgrade><install><version>latest</
version></install></upgrade></wildfire></request>&key=<apikey>"

• Applicaon & Threat:

curl -X GET "https://<firewall>/api/?
type=op&cmd=<request><content><upgrade><install>latest</latest></
install></upgrade></content></request>&key=<apikey>"

• Anvirus:

curl -X GET "https://<firewall>/api/?type=op&cmd=<request><anti-
virus><upgrade><install><version>latest</version></install></
upgrade></anti-virus></request>&key=<apikey>"

The response contains a job ID that you can use to check on the status of the request.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

47

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

Enforce Policy using External Dynamic Lists and
AutoFocus Arfacts (API)

This use case allows you to use data from AutoFocus threat intelligence to create an external
dynamic list for your ﬁrewall.

Use the AutoFocus API to export AutoFocus arfacts (IP addresses, domains, or URLs) as
an export list that you can host on a web server. Learn more about AutoFocus in AutoFocus
documentaon. Then use the PAN-OS XML API to add this URL as an external dynamic list to
enforce policy dynamically on the ﬁrewall. Learn more about how to use an external dynamic list
in policy.

To use AutoFocus, you must ﬁrst register and acvate AutoFocus.

STEP 1 | Build an AutoFocus export list. For example, if you want to block potenal aacks from the

Sofacy group, search for Sofacy as the Tag, and then add the appropriate arfacts shown
within the File Analysis tab, such as DNS Acvity, HTTP Requests, and Connecon Acvity.

      Use the AutoFocus API to export the AutoFocus artifacts.
 Include you the AutoFocus API key, the label of the export list,
 and specify that the list should be formatted for a PAN-OS block
 list. ("panosFormatted":true):
       curl -X POST -H "Content-Type: application/json" -d '{
    "apiKey": "<apikey>",
    "label": "<export-list-name>",
    "panosFormatted": true
}' "https://autofocus.paloaltonetworks.com/api/v1.0/export"

The response contains a list of IP addresses, domains, or URLs, depending on the arfacts you
save:

      {
    "bucket_info": {
        "daily_points": 100000,
        "minute_points": 200
    },
    "export_list": [
        "176.31.112.10",
        "31.220.43.99",
        "40.76.58.209",
        "62.113.232.196",
        "95.215.47.207"
    ]
}

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

48

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

STEP 2 | Host the export list as a text ﬁle on an external web server. To ensure that you have the

latest list of arfacts, frequently refresh the hosted list.

STEP 3 | Add the URL for the export list to an external dynamic list. In this example the external

dynamic list uses IP addresses:

      curl -X GET "https://<firewall>/api/?
type=config&action=set&xpath=/config/devices/
entry[@name='localhost.localdomain']/vsys/entry[@name='vsys1']/
external-list/entry[@name='export-list-name']/type/
ip&element=<url><edl-list-url></url><recurring><five-minute/></
recurring>&key=<apikey>"

STEP 4 | Add the external dynamic list as match criteria in a security policy rule. In this example, the

rule denies access to IP addresses on the external dynamic list for all users on your network:

      curl -X GET "https://<firewall>/api/?
type=config&action=set&xpath=/config/devices/
entry[@name='localhost.localdomain']/vsys/entry[@name='vsys1']/
rulebase/security/rules/entry[@name='<security-
policy-rulename>']@element=<to><member>any</member></
to><from><member>any</member></from><source>any</
source><destination><member><edl-list-name></member></
destination><source-user><member>any</member></source-
user><service><member>application-default</member></
service><action>deny</action>&key=<apikey>"

STEP 5 | Commit the changes to the ﬁrewall:

      curl -X GET "https://<firewall>/api/?
type=commit&cmd=<commit></commit>&key=<apikey>"

You must commit only once when you add the reference to the EDL in a policy rule. Any
changes to the external dynamic list do not require a commit.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

49

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

Conﬁgure SAML 2.0 Authencaon (API)

Use the PAN-OS XML API to automate the conﬁguraon of SAML 2.0 single sign-on (SSO)
and single logout (SLO). To conﬁgure SAML using the API, create scripts that import the SAML
metadata ﬁle, create a SAML authencaon proﬁle, add users and user groups, and assign the
authencaon proﬁle to ﬁrewall services. The following workﬂow provides an example of how to
conﬁgure SAML using the XML API.

Because the PAN-OS XML API uses a tree of XML nodes, in your API request you must specify
the correct type and acon along with the XPath Node Selecon. See Explore the API to learn
how to construct XML requests.

STEP 1 |

(Recommended) Import a metadata ﬁle from the IdP

The metadata ﬁle contains registraon informaon and the cerﬁcate that the IdP uses to
sign SAML messages. If you import a metadata ﬁle, you do not need to independently Create
a SAML Identy Provider (IdP) server proﬁle. Include the metadata ﬁle path and SAML server
proﬁle name in your GET request:

• key: API key

• ﬁle: ﬁle path to SAML metadata ﬁle. The metadata ﬁle contains registraon informaon, as
well as the cerﬁcate that the IdP uses to sign SAML messages. Export the metadata ﬁle
from the IdP to a client system that the ﬁrewall can access. The cerﬁcate speciﬁed in the
ﬁle must meet SAML requirements. Refer also to your IdP documentaon for instrucons.

• proﬁle-name: passphrase, up to 31 characters

curl -k -F file=@filename.txt -g 'https://<firewall>/
api/?key=apikey&type=import&category=idp-metadata&profile-
name=<profilename>'

If you perform this step, you can skip Step 2, Create a SAML Identy Provider (IdP) server
proﬁle.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

50

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

STEP 2 | Create a SAML Identy Provider (IdP) server proﬁle

If you do not import a metadata ﬁle, include IdP conﬁguraon parameters in your GET request
to create a SAML IdP server proﬁle:

• key: API key

• vsys: locaon, example values: shared, vsys1, vsys2

• name: server proﬁle name

• enty-id: identy provider id

• cerﬁcate: (Best Pracce) identy provider cerﬁcate

• sso-url: identy provider SSO URL

• slo-url: identy provider SLO URL

• sso-binding: SSO SAML HTTP binding, acceptable values: post, redirect

• ssl-binding: SSL SAML HTTP binding, acceptable values: post, redirect

• max-clock-skew: diﬀerence in system me as measured in seconds between ﬁrewall and

IdP. The default value is 60 with a range of 1-900.

• validate-idp-cerﬁcate: (Best Pracce) specify whether you want to validate the IdP

cerﬁcate. The default value is yes.

• want-auth-requests-signed: specify whether the IdP expects a digital signature on

authencaon requests. The default value is no.

curl -X GET "https://<firewall>/api/?
key=<apikey>&type=config&action=set&xpath=/config/shared/
server-profile/saml-idp/entry[@name='<server-profile-
name>']&element=<certificate><cert-name></certificate><entity-
id><https://example.com/sso></entity-id><sso-url><https://
example.com/sso></sso-url><sso-bindings><post></sso-
bindings><slo-url><https://example.com/slo></slo-url><slo-
bindings>post</slo-bindings><max-clock-skew><max-clock-skew></
max-clock-skew><validate-idp-certificate><yes></validate-idp-
certificate><want-auth-requests-signed><yes></want-auth-requests-
signed>"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

51

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

STEP 3 | Create a SAML authencaon proﬁle using the PAN-OS XML API

Include SAML authencaon proﬁle parameters in your GET request:

• key: API key

• authencaon-proﬁle: authencaon proﬁle name

• enable-single-logout: specify whether you want to enable SAML single logout. The default

value is no.

• request-signing-cerﬁcate: request signing cerﬁcate name

• server-proﬁle: SAML Identy Provider (IdP) server proﬁle name

• cerﬁcate-proﬁle: cerﬁcate proﬁle name

• aribute-name-username: SAML username aribute

• aribute-name-usergroup: SAML user group aribute

• aribute-name-access-domain: SAML admin domain aribute

• aribute-name-admin-role: SAML admin role aribute

curl -X GET "https://<firewall>/api/?
key=<apikey>&type=config&action=set&xpath=/config/shared/
authentication-profile/entry[@name='<authentication-profile-
name>']/method/saml-idp&element=<enable-single-logout>no</enable-
single-logout><request-signing-certificate><certificate-name></
request-signing-certificate><server-profile><server-profile-name></
server-profile><certificate-profile>profile-name</certificate-
profile><attribute-name-username><username></attribute-name-
username><attribute-name-usergroup><usergroup></attribute-name-
usergroup><attribute-name-access-domain><access-domain></attribute-
name-access-domain><attribute-name-admin-role><admin-role></
attribute-name-admin-role>"

STEP 4 | Add users and user groups that are allowed to authencate with this authencaon proﬁle

Include proﬁle name and member list in your request:

• key: API key

• authencaon-proﬁle: authencaon proﬁle name

• member: users or user groups. To include speciﬁc users or group, include them in brackets:

[member1,member 3]. To include all users, include all.

curl -X GET "https://<firewall>/api/?
key=<apikey>&type=config&action=set&xpath=/config/shared/
authentication-profile/entry[@name='<authentication-profile-
name>']/allow-list&element=<member><all></member>"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

52

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

STEP 5 | Assign the authencaon proﬁle to ﬁrewall services that require authencaon

For example, to assign the authencaon proﬁle to a superuser administrator account for web
access, include these parameters in your GET request:

• key: API key

• name: admin username

• authencaon-proﬁle: name of the SAML authencaon proﬁle

curl -X GET "https://<firewall>/api/?
key=<apikey>&type=config&action=set&xpath=/config/mgt-config/
users/entry[@name='<adminname>']&element=<permissions><role-
based><superuser>yes</superuser></role-based></
permissions><authentication-profile><authprofilename></
authentication-profile>"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

53

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Use Cases

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

54

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

The following topics provide common request examples that you can use to beer
understand the PAN-OS XML API.

>

>

>

>

>

>

PAN-OS XML API Request Types and
Acons

Asynchronous and Synchronous
Requests to the PAN-OS XML API

Conﬁguraon (API)

Commit Conﬁguraon (API)

Run Operaonal Mode Commands
(API)

Get Reports (API)

>

>

>

>

>

Export Files (API)

Import Files (API)

Retrieve Logs (API)

Apply User-ID Mapping and Populate
Dynamic Groups (API)

Get Version Info (API)

55

PAN-OS XML API Request Types

PAN-OS XML API Request Types and Acons

Use PAN-OS XML API to run various requests depending on the request type that you specify:

• Request Types

• Conﬁguraon Acons

Request Types

You can currently use the following request types:

Syntax

Descripon

type=keygen

type=config

type=commit

type=op

type=report

type=log

type=import

type=export

type=user-id

type=version

Generate API keys for authencaon.

Modify the conﬁguraon.

Commit ﬁrewall conﬁguraon, including paral commits.

Perform operaonal mode commands, including checking
system status and validang conﬁguraons.

Get reports, including predeﬁned, dynamic, and custom
reports.

Get logs, including traﬃc, threat, and event logs.

Import ﬁles including conﬁguraons and cerﬁcates.

Export ﬁles including packet captures, cerﬁcates, and keys.

Update User-ID mappings.

Show the PAN-OS version, serial number, and model
number.

Conﬁguraon Acons

In addion to the request type that you specify, use available acons to modify or read
conﬁguraons using type=config:

• Acons for Modifying a Conﬁguraon

• Acons for Reading a Conﬁguraon

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

56

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Acons for Modifying a Conﬁguraon

Conﬁguraon Acon Type

Syntax

Set candidate conﬁguraon

Edit candidate conﬁguraon

Delete candidate object

Rename a conﬁguraon object

Clone a conﬁguraon object

Move a conﬁguraon object

Override a template seng

Move mulple objects in a device group or virtual
system

action=set

action=edit

action=delete

action=rename

action=clone

action=move

action=override

action=multi-move

Clone mulple objects in a device group or virtual
system

action=multi-clone

Show available subnode values and XPaths for a
given XPath.

action=complete

Set and edit acons diﬀer in two important ways:

• Set acons add, update, or merge conﬁguraon nodes, while edit acons replace conﬁguraon

nodes.

• Set acons are non-destrucve and are only addive, while edit acons can be destrucve.

Acons for Reading a Conﬁguraon

Conﬁguraon Acon Type

Syntax

Get acve conﬁguraon

Get candidate conﬁguraon

action=show

action=get

Show and get acons diﬀer in three important ways:

• Show acons retrieve the acve conﬁguraon, while get acons retrieve the candidate,

uncommied conﬁguraon.

• Show acons only work when the provided XPath speciﬁes a single node. Get acons work

with single and mulple nodes.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

57

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

• Show acons can use relave XPath, while get acons require absolute XPath.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

58

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Asynchronous and Synchronous Requests to the PAN-
OS XML API

Most PAN-OS XML API requests are synchronous, meaning the response immediately provides
the requested data. For example, when you Make Your First API Call and request system
informaon, the API response is immediate and contains informaon such as the IP address,
hostname, and model of your ﬁrewall.

However, there are some Request Types that require more me to process and are asynchronous,
meaning they require more than one request to get ﬁnal results. These API requests include the
following:

• Get Reports (API)

• Retrieve Logs (API)

• Export Technical Support Data

• Some requests to Run Operaonal Mode Commands (API), including download, upgrade, and

installaon requests

With asynchronous requests, you ﬁrst iniate a request. The API responds with a job ID while it
processes your request. In your subsequent requests, you use this job ID to check on the results of
your original request.

Examples (replace jobid with the actual job ID):

• Get reports:

     curl -X GET "https://<firewall>/api/?
type=report&action=get&job-id=jobid&key=<apikey>"

• Retrieve logs:

     curl -X GET "https://<firewall>/api/?type=log&action=get&job-
id=jobid&key=<apikey>"

• Export technical support data:

     curl -X GET "https://<firewall>/api/?
type=export&category=tech-support&action=get&job-
id=jobid&key=<apikey>"

• Commit:

     curl -X GET "https://<firewall>/api/?
type=commit&cmd=<commit></commit>&key=<apikey>"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

59

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

• Operaonal commands:

     curl -X GET "https://<firewall>/api/?
type=op&cmd=<show><jobs><id>jobid</id></jobs></show>&key=<apikey>"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

60

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Conﬁguraon (API)

The requests examples in these topics illustrate how you can use the PAN-OS XML API to
conﬁgure your ﬁrewall.

• Get Acve Conﬁguraon

• Get Candidate Conﬁguraon

• Set Conﬁguraon

• Edit Conﬁguraon

• Delete Conﬁguraon

• Rename Conﬁguraon

• Clone Conﬁguraon

• Move Conﬁguraon

• Override Conﬁguraon

• Mul-Move or Mul-Clone Conﬁguraon

• View Conﬁguraon Node Values for XPath

Get Acve Conﬁguraon

• Use XPath to Get Acve Conﬁguraon

• Use XPath to Get ARP Informaon

Use XPath to Get Acve Conﬁguraon

Use action=show with no addional parameters to retrieve the enre acve conﬁguraon.

STEP 1 | Use the xpath parameter to target a speciﬁc poron of the conﬁguraon. For example, to

retrieve just the security rulebase: xpath=/config/devices/entry/vsys/entry/
rulebase/security:

      curl -X GET "https://<firewall>/api/?
type=config&action=show&key=apikey&xpath=/config/devices/entry/
vsys/entry/rulebase/security"

There is no trailing backslash character at the end of the XPath.

STEP 2 | Conﬁrm that the XML response for the query looks similar to the following (truncated):

      <response status="success">
  <result>
    <security>
      <rules><entry name="IT DNS Services"><profile-
setting><group><member>best-practice</member></
group></profile-setting><to><member>untrust</member></
to><from><member>trust</member></from><source><member>any</

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

61

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

member></source><destination><member>Data Center</
member></destination><source-user><member>any</
member></source-user><category><member>any</
member></category><application><member>dns</member></
application><service><member>application-default</
member></service><hip-profiles><member>any</member></hip-
profiles><action>allow</action><tag><member>Best Practice</
member></tag><log-start>no</log-start><log-setting>default</log-
setting></entry>
       ...
                   </rules>
    </security>
  </result>
</response>

Use XPath to Get ARP Informaon

Follow this procedure to use XPath to Get ARP Informaon.

STEP 1 | Use the following request to retrieve ARP informaon:

      curl -X GET "https://<firewall>//api/?
type=op&command=<show><arp><entry name='all'/></arp></
show>&key=<apikey>"

STEP 2 | Conﬁrm that the XML response for the query looks like the following (truncated):

      <response status="success">
       <result>
       <max>3000</max>
       <total>16</total>
       <timeout>1800</timeout>
       <dp>dp0</dp>
       <entries>
       <entry>
       <status>c</status>
       <ip>10.47.0.1</ip>
       <mac>00:1b:17:00:2f:13</mac>
       <ttl>1743</ttl>
       <interface>ethernet1/1</interface>
       <port>ethernet1/1</port>
       </entry>
       <entry>
       <status>c</status>
       <ip>10.47.0.10</ip>
       <mac>00:50:56:93:68:6f</mac>
       <ttl>386</ttl>
       <interface>ethernet1/1</interface>
       <port>ethernet1/1</port>
       </entry>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

62

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

       <!-- truncated -->
       </result>
       </response>

Get Candidate Conﬁguraon

Get the candidate conﬁguraon from a ﬁrewall by specifying the poron of the conﬁguraon
to get. Use the following request, including the xpath parameter to specify the poron of the
conﬁguraon to get.

   curl -X GET "https://<firewall>/api/?
type=config&action=get&xpath=<path-to-config-node>&key=<apikey>"

Conﬁguraon Node

API Request

Firewall candidate
conﬁguraon

Firewall candidate
conﬁguraon through
Panorama

Firewall candidate
conﬁguraon through
Panorama without
specifying a ﬁrewall

        curl -X GET "https://<firewall>/
api/?type=config&action=get&xpath=/
config/devices/entry/vsys/
entry[@name='vsys1']&key=<api_key>"

        https://<panorama>/api/?
type=config&action=get&
         xpath=/config/devices/entry/vsys/
entry[@name='vsys1']

 &target=<serial>&key=<panorama_api_key>

        curl -X GET "https://<panorama>/
api/?type=config&action=get&xpath=/
config/devices/entry/*[name()!
='vsys']|/config/devices/entry/vsys/
entry[@name='vsys1']&key=<panorama_api_key>"

Address objects in a virtual
system (vsys).

        curl -X GET "https://<firewall>//
api/?type=config&action=get&xpath=/config/
devices/entry/vsys/entry[@name='vsys1']/
address&key=<apikey>"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

63

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Conﬁguraon Node

API Request

The response looks similar to the following:

        <response status="success" code="19">
  <result total-count="1" count="1">
    <address admin="name" dirtyId="8"
 time="2015/10/20          15:32:36"><entry
 name="testobject"><ip-netmask>192.0.2.2</
ip-netmask></entry><entry name="test1"><ip-
netmask>192.0.2.12</ip-netmask></entry>
         ...</address>
  </result>
</response>

Pre-rules pushed from
Panorama.

Full list of all applicaons.

Details on the speciﬁc
applicaon.

        curl -X GET "https://<firewall>//
api/?type=config&action=get&xpath=/config/
panorama/vsys/entry[@name='vsys']/pre-
rulebase/security&key=<apikey>"

        curl -X GET "https://<firewall>/
api/?type=config&action=get&xpath=/config/
predefined/application&key=<apikey>"

        curl -X GET "https://<firewall>/
api/?type=config&action=get&xpath=/
config/predefined/application/
entry[@name='hotmail']&key=<apikey>"

Set Conﬁguraon

Use action=set to add or create a new object at a speciﬁed locaon in the PAN-OS
conﬁguraon. Use the xpath parameter to specify the locaon of the object in the conﬁguraon.
For example, if you are adding a new rule to the security rulebase, the xpath-value would be:

   /config/devices/entry[@name='localhost.localdomain']/vsys/
entry[@name='vsys1']/rulebase/security

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

64

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Use the element parameter to specify a value for the object you are adding or creang using
XML.

Conﬁguraon Node

API Request

Create a new rule called
rule1 in security policy

        https://<firewall>/api/?
key=apikey&type=config&action=set&
         xpath=xpath-value&element=element-
value

where the xpath-value is:

        /config/devices/entry/vsys/entry/
rulebase/security/rules/entry[@name='rule1']

and the element-value is:

        <source><member>src</member></
source><destination><member>dst</member></
destination><service><member>service</
member></
service><application><member>application</
member></application><action>action</
action><source-user><member>src-user</
member></source-user><option><disable-
server-response-inspection>yes-or-no</
disable-server-response-inspection></
option><negate-source>yes-or-no</negate-
source><negate-destination>yes-or-
no</negate-destination><disabled>yes-
or-no</disabled><log-start>yes-or-
no</log-start><log-end>yes-or-no</
log-end><description>description</
description><from><member>src-zone</member></
from><to><member>dst-zone</member></to>

Add an addional member
to an address group or list

Include the 'list' node in the xpath using the
member[text()='name'] syntax and include the members in
the element parameter. For example, to add an addional stac
address object named abc to an address group named test,
use:

        curl -X GET "https://<firewall>/api/?
key=<apikey>&type=config&action=set&xpath=/

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

65

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Conﬁguraon Node

API Request

config/devices/entry/vsys/
entry[@name='vsys1']/address-group/
entry[@name='test']&element=<static><member>abc</
member></static>"

Create a new IP address on
a speciﬁc interface

Specify the interface and IP address in the request:

Enable or disable a security
rule

        curl -X GET "https://<firewall>/api?
key=<apikey>&type=config&action=set&xpath=/
config/devices/
entry[@name='localhost.localdomain']/
network/interface/ethernet/
entry[@name='ethernet1/1']/layer3/
ip&element=<entry name='5.5.5.5/24'/>"

        curl -X GET "https://<firewall>/api/?
key=<apikey>&type=config&action=set&xpath=/
config/devices/
entry[@name='localhost.localdomain']/
vsys/entry[@name='<vsys1>']/rulebase/
security/rules/entry[@name='<rule-
name>']&element=<disabled>yes</disabled>"

Altenavely, use <disabled>no</disabled> to enable a
rule.

Edit Conﬁguraon

Use action=edit to replace an exisng object hierarchy at a speciﬁed locaon in the
conﬁguraon with a new value. Use the xpath parameter to specify the locaon of the object,
including the node to be replaced. Use the element parameter to specify a new value for the
object using its XML object hierarchy (as seen in the output of action=show).

STEP 1 | Replace the applicaon(s) currently used in a rule rule1 with a new applicaon:

      curl -X GET "https://<firewall>/api/?
type=config&action=edit&key=apikey&xpath=xpath-
value&element=element-value"

where

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

66

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

      xpath=/config/devices/entry/vsys/entry/
rulebase/security/rules/entry[@name='rule1']/
application&element=<application><member>app-name</member></
application>

STEP 2 | Use the response from the conﬁg show API request to create the XML body for the element.

      curl -X GET "https://<firewall>/api/?
key=apikey&type=config&action=show"

STEP 3 | Oponally replace all members in a node with a new set of members using the entry tag in

both the xpath and element parameters. For example, to replace all the address objects in the
address group named test with two new stac members named abc and xyz, use:

      curl -X GET "https://<firewall>/api/?
key=apikey&type=config&action=edit&xpath=/config/
devices/entry/vsys/entry[@name='vsys1']/address-
group/entry[@name='test']&element=<static><entry
 name='test'><member>abc</member><member>xyz</member></entry></
static>"

Delete Conﬁguraon

Use action=delete to delete an object at a speciﬁed locaon in the conﬁguraon. Use the
xpath parameter to specify the locaon of the object to be deleted.

Delete a rule named rule1 in the security policy:

      curl -X GET "https://<firewall>/api/?
key=apikey&type=config&action=delete&xpath=/config/devices/entry/
vsys/entry/rulebase/security/rules/entry[@name='rule1']"

Delete a single member object in a group, use the object name in the xpath as
member[text()='name']. For example, to delete a stac address object named abc in an
address group named test, use the following xpath:

      curl -X GET "https://<firewall>/api/?
key=apikey&type=config&action=delete&xpath=/config/devices/entry/
vsys/entry[@name='vsys1']/address-group/entry[@name='test']/static/
member[text()='abc']"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

67

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Rename Conﬁguraon

Use action=rename to rename an object at a speciﬁed locaon in the conﬁguraon. Use the
xpath parameter to specify the locaon of the object to be renamed. Use the newname parameter
to provide a new name for the object.

STEP 1 | Use the following API query to rename an address object called old_address to

new_address:

      curl -X GET "https://<firewall>/api/?
key=<apikey>&type=config&action=rename&xpath=/config/
devices/entry/vsys/entry[@name='vsys1']/address/
entry[@name='old_address']&newname=new_address"

STEP 2 | Conﬁrm that the XML response for the request looks like the following:

      <response status="success" code="20">
  <msg>command succeeded</msg>
</response>

Clone Conﬁguraon

Use action=clone to clone an exisng conﬁguraon object. Use the xpath parameter to
specify the locaon of the object to be cloned. Use the from parameter to specify the source
object, and the newname parameter to provide a name for the cloned object.

STEP 1 | Use the following API query to clone a security policy called rule1 to rule2:

      curl -X GET "https://<firewall>/api/?
key=<apikey>&type=config&action=clone&xpath=/config/devices/entry/
vsys/entry[@name='vsys1']/rulebase/security/rules&from=/config/
devices/entry/vsys/entry[@name='vsys1']/rulebase/security/rules/
entry[@name='rule1']&newname=rule2"

STEP 2 | Conﬁrm that the XML response for the request looks like the following:

      <response status="success" name="rule2"/>

A corresponding success log is recorded in the Conﬁguraon log:

      1,2014/03/19 19:07:45,0009C100708,CONFIG,0,0,2014/03/19

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

68

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

       19:07:45,10.66.18.1,,clone,admin,Web,Succeeded, config
 devices entry vsys
       vsys1 rulebase security rules,384,0x8000000000000000

Move Conﬁguraon

Use action=move to move the locaon of an exisng conﬁguraon object. Use the xpath
parameter to specify the locaon of the object to be moved, the where parameter to specify type
of move, and dst parameter to specify the desnaon path.

• where=after&dst=xpath

• where=before&dst=xpath

• where=top

• where=bottom

STEP 1 | Use the following API query to move a security policy called rule1 to come aer rule2:

      curl -X GET "https://<firewall>/api/?
key=<apikey>&type=config&action=move&xpath=/config/devices/
entry/vsys/entry[@name='vsys1']/rulebase/security/rules/
entry[@name='rule1']&where=after&dst=rule2"

STEP 2 | Conﬁrm that the XML response for the request looks like the following:

      <response status="success" code="20">
  <msg>command succeeded</msg>
</response>

Override Conﬁguraon

Use action=override to override a seng that was pushed to a ﬁrewall from a template. Use
the xpath parameter to specify the locaon of the object to override.

STEP 1 | Override the SNMP Trap proﬁle conﬁguraon sengs that were pushed to the ﬁrewall using

a template:

      curl -X GET "https://<firewall>/api/?
key=<apikey>&type=config&action=override&xpath=/config/shared/log-
settings/snmptrap&element=<entry name="snmp" src="tpl"><version
 src="tpl"><v2c src="tpl"><server src="tpl"><entry name="test"
 src="tpl"><manager src="tpl">2.2.2.2</manager><community
 src="tpl">test</community></entry></server></v2c></version></
entry>"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

69

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

STEP 2 | Conﬁrm that the XML response for the request looks like the following:

      <response status="success" code="20">
  <msg>command succeeded</msg>
</response>

Mul-Move or Mul-Clone Conﬁguraon

Use the action=multi-move and action=multi-clone acons to move and clone
addresses, address groups, services, and more across device groups and virtual systems. Templates
do not support the mul-move and mul-clone capability.

The syntax for mul-move and mul-clone speciﬁes the xpath for the desnaon where the
addresses will be moved to, the xpath for the source and the list of objects within the speciﬁed
source. It also includes a ﬂag for displaying the errors when the ﬁrewall performs a referenal
integrity check on the mul-move or mul-clone acon.

Move addresses addr1, addr2, to device group norcal from device group socal:

      curl -X GET "https://<firewall>/api/?
key=<apikey>&type=config&action=multi-move&xpath=/config/
devices/entry[@name='localhost.localdomain']/devicegroup/
entry[@name='norcal']/address&element=<selected-list><source
 xpath="/config/devices/entry[@name='localhost.localdomain']/
devicegroup/entry[@name='socal']/address"><member>addr1</
member><member>addr2</member></source></selected-list><all-
errors>no</all-errors>"

Clone addresses addr1, addr2, to device group norcal from device group socal:

      curl -X GET "https://<firewall>/api/?
key=<apikey>&type=config&action=multi-clone&xpath=/config/
devices/entry[@name='localhost.localdomain']/devicegroup/
entry[@name='norcal']/address&element=<selected-list><source
 xpath="/config/devices/entry[@name='localhost.localdomain']/
devicegroup/entry[@name='socal']/address"><member>addr1</
member><member>addr2</member></source></selected-list><all-
errors>no</all-errors>"

View Conﬁguraon Node Values for XPath

Use action=complete acon along with an XPath to see possible values that are available with
the XPath node.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

70

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

STEP 1 | View the possible values, such as network interfaces, for mul-vsys ﬁrewalls, use the

following command:

      curl -X GET "https://<firewall>/api/?
type=config&action=complete&xpath=/config/devices/
entry[@name='localhost.localdomain']/vsys&key=apikey"

STEP 2 | Conﬁrm that the XML response for the request looks like the following:

      <response status="success" code="19">
  <completions>
    <completion value="vsys1" vxpath="/config/devices/
entry[@name='localhost.localdomain']/vsys/entry[@name='vsys1']"
 current="yes" help-string="vsys1"/>
  </completions>
</response>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

71

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Commit Conﬁguraon (API)

You can use the commit API request to commit a candidate conﬁguraon to a ﬁrewall.

You can validate or revert a candidate conﬁguraon before comming it using Run
Operaonal Mode Commands (API).

• Commit

• Commit-All

Commit

Replace the body element in the cmd parameter with the XML element for the corresponding
commit operaon.

Use the API Browser to ﬁnd diﬀerent opons available for use with force and paral
commits.

STEP 1 | Use one of the following requests to commit a conﬁguraon:

• Commit— Commit candidate changes to the ﬁrewall.

      curl -X GET "https://<firewall>/api/?
key=apikey&type=commit&cmd=<commit></commit>"

• Force Commit—

      curl -X GET "https://<firewall>/api/?
key=apikey&type=commit&cmd=<commit><force></force></commit>"

• Paral commit while excluding shared objects and device and network conﬁguraon—

      curl -X GET "https://<firewall>/api/?
key=apikey&type=commit&action=partial&cmd=<commit><partial><device-
and-network>excluded</device-and-network><shared-object>excluded</
shared-object></partial></commit>"

• Paral commit admin-level changes— To commit admin-level changes on a ﬁrewall, include

the administrator name in the request.

      curl -X GET "https://<firewall>/api/?
key=apikey&type=commit&action=partial&cmd=<commit><partial><admin><member>
$admin-name</member></admin></partial></commit>"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

72

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

• Paral commit admin-level changes on a ﬁrewall or Panorama while excluding shared

objects—Include the administrator name in the request. Replace the $admin-name Replace

      curl -X GET "https://<firewall>/api/?
key=apikey&type=commit&action=partial&cmd=<commit><partial><device-
and-network>excluded</device-and-network><shared-object>excluded</
shared-object><admin><member>socadmin</member></admin></partial></
commit>"

STEP 2 | Conﬁrm that the XML response indicates that there were no changes to commit or that the

changes are queued for commit:

• No pending changes to commit:

        <response status="success" code="19">
           <msg>There are no changes to commit.</msg></response>

• Pending changes:

        <response status="success" code="19">
  <result>
    <msg>
      <line>Commit job enqueued with jobid 4</line>
    </msg>
    <job>4</job>
  </result>
</response>

STEP 3 | Query the status of the job using the job ID:

      curl -X GET "https://<firewall>/api/?
key=apikey&type=op&cmd=<show><jobs><id>4</id></jobs></show>"

STEP 4 | Conﬁrm that the XML response details state the Conﬁguraon was commied successfully:

      <response status="success">
  <result>
    <job>
      <tenq>2021/07/21 14:33:55</tenq>
      <tdeq>14:33:55</tdeq>
      <id>4</id>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

73

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

      <user>admin</user>
      <type>Commit</type>
      <status>ACT</status>
      <queued>NO</queued>
      <stoppable>yes</stoppable>
      <result>PEND</result>
      <tfin/>
      <description/>
      <positionInQ>0</positionInQ>
      <progress>55</progress>
      <warnings>
        <line>Aggregate-ethernet interface ae1 has no member
 interfaces.</line>
      </warnings>
      <details/>
    </job>
  </result>
</response>

Commit-All

To centrally manage ﬁrewalls from Panorama, use the commit-all API request type to push and
validate shared policy to the ﬁrewalls using device groups and conﬁguraon to Log Collectors and
ﬁrewalls using templates or template stacks.

Commit Type

API Request

Pre-commit policy
validaon.

Speciﬁc Device group
commit.

        curl -X GET "https://<panorama>/api/?
key=apikey&type=commit&action=all&cmd=<commit-
all><shared-policy><validate-only></validate-
only></shared-policy></commit-all>"

        curl -X GET "https://<panorama>/api/?
key=apikey&type=commit&action=all&cmd=<commit-
all><shared-policy><device-
group><entry name="<device-group-name>"/></
device-group></shared-policy></commit-all>"

Speciﬁc device group
commit without including
default device/network
template changes.

        curl -X GET "https://<panorama>/api/?
key=apikey&type=commit&action=all&cmd=<commit-
all><shared-policy><include-
template>no</include-template><device-
group><entry name="<device-group-name>"/></
device-group></shared-policy></commit-all>"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

74

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Commit Type

API Request

Virtual system (vsys)
commit.

Speciﬁc ﬁrewall commit.

        curl -X GET "https://<panorama>/api/?
key=apikey&type=commit&action=all&cmd=<commit-
all><shared-policy><device-
group><entry name="<device-group-name>"/
><devices><entry name="<serial_number>"><vsys><member>vsys-
name</member></vsys></entry></devices></
device-group></shared-policy></commit-all>"

curl -X GET "https://<panorama>/api/?
key=apikey&type=commit&action=all&cmd=<commit-
all><shared-policy><device-
group><entry name="<device-group-
name>"><devices><entry name="<serial_number>"></
entry></devices></entry></device-group></
shared-policy></commit-all>"

Use the API Browser to ﬁnd other opons available for granular commit operaons on Panorama.
In the cmd parameter, you must replace the XML element for the corresponding commit-all
operaon.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

75

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Run Operaonal Mode Commands (API)

Use any of the operaonal mode commands available on the command line interface with the
following API request:

curl -X GET "https://<firewall>/api/?key=apikey&type=op&cmd=<xml-
body>"

Use the API Browser to explore operaonal mode commands and a complete lisng of all the
opons available for the xml-body and their corresponding operaon.

Some requests operaonal mode commands, including download, upgrade, and
installaon requests, are asynchronous, meaning they require more than one request to get
ﬁnal results. Learn more about Asynchronous and Synchronous Requests to the PAN-
OS XML API.

Operaonal Command

API Request

System restart.

System soware version
installaon.

Mul-vsys mode.

User Acvity Report
scheduling.

curl -X GET "https://<firewall>/api/?
key=apikey&type=op&cmd=<request><restart><system></
system></restart></request>"

https://<firewall>/api/?
key=apikey&type=op&cmd=<request>
<system><software><install><version>version_number</
version></install></software></system></
request>

curl -X GET "https://<firewall>/api/?
key=apikey&type=op&cmd=<set><system><setting><multi-
vsys></multi-vsys></setting></system></set>"

curl -X GET "https://<firewall>/api/?
key=apikey&type=op&cmd=<schedule><uar-
report><user>username</
user><title>titlename</title></uar-report></
schedule>"

Detailed informaon on
applicaons and threats
from the ﬁrewall.

curl -X GET "https://<firewall>/api/?
key=apikey&type=op&cmd=<show><predefined><xpath>/
predefined/threats/vulnerability/

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

76

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Operaonal Command

API Request

Full conﬁguraon
validaon.

Paral conﬁguraon
validaon.

Conﬁguraon saving.

Conﬁguraon loading.

entry[@name='30003']</xpath></predefined></
show>"

curl -X GET "https://<firewall>/api/?
key=apikey&type=op&cmd=<validate><full></
full></validate>"

curl -X GET "https://<firewall>/api/?
key=apikey&type=op&cmd=<validate><partial><device-
and-network>excluded</device-and-network></
partial></validate>"

curl -X GET "https://<firewall>/api/?
key=apikey&type=op&cmd=<save><config><to>filename</
to></config></save>"

curl -X GET "https://<firewall>/api/?
key=apikey&type=op&cmd=<load><config><from>filename</
from></config></load>"

Paral revert of admin-level
changes for a candidate
conﬁguraon on a ﬁrewall.

https://<firewall>/api/?
key=apikey&type=op&cmd=<revert>
<config><partial><admin><member>admin-name</
member></admin></partial></config></revert>

Paral revert of admin-
level changes to Panorama
by a speciﬁc administrator
within a speciﬁc device
group

https://<panorama>/api/?key=apikey&key=apikey
&type=op&cmd=<revert><config><partial><admin><member>
<admin-name></member></admin>
<device-group><member>
<device-group-name></member></device-group>
<no-template/><no-template-stack/><no-log-
collector-group/><no-log-collector/><device-
and-network>excluded</device-and-network></
partial>
</config></revert>

Base64-encoded metadata
of a SAML authencaon
proﬁle.

curl -X GET "https://<firewall>/api/?
key=apikey&type=op&cmd=<show><sp-
metadata><management><authprofile><SAML-auth-

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

77

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Operaonal Command

API Request

Summary of changes
between the acve and
candidate conﬁguraon.

Commit locks

Show WildFire appliances
connected to Panorama.

System summary about
WildFire appliances or
WildFire clusters.

Generate a list of Firewalls
connected and sending
data to a WildFire
appliance or WildFire
cluster.

profile-name></authprofile></management></sp-
metadata></show>"

curl -X GET "https://<firewall>/api/?
key=apikey&type=op&cmd=<show><config><list><change-
summary/></list></config></show>"

curl -X GET "https://<firewall>/api/?
key=<apikey>&type=op&cmd=<show><commit-locks/
></show>"

curl -X GET "https://<panorama>/api/?
key=<apikey>&&type=op&cmd=<show><wildfire-
appliance><connected></connected></wildfire-
appliance></show>"

• WildFire Appliance:

curl -X GET "https://<panorama>/api/?
key=<apikey>&&type=op&cmd=<show><wildfire-
appliance><all></all></wildfire-
appliance></show>"

• WildFire Cluster:

curl -X GET "https://<panorama>/api/?
key=<apikey>&&type=op&cmd=<show><wildfire-
appliance-cluster><all></all></wildfire-
appliance-cluster></show>"

• WildFire Appliance:

curl -X GET "https://<panorama>/api/?
key=<apikey>&&type=op&cmd=<show><wildfire-
appliance><devices-reporting-data><serial-
number><serial_number></serial-number></
devices-reporting-data></wildfire-
appliance></show>"

• WildFire Cluster:

curl -X GET "https://<panorama>/api/?
key=<apikey>&&type=op&cmd=<show><wildfire-
appliance-cluster><devices-reporting-
data><name><cluster_name></name></devices-
reporting-data></wildfire-appliance-
cluster></show>"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

78

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Operaonal Command

API Request

Display conﬁguraon
details about a speciﬁed
WildFire appliance or
WildFire cluster.

Display registraon acvity
for a speciﬁed WildFire
appliance or WildFire
cluster.

Display stascs for
a speciﬁed WildFire
appliance or WildFire
cluster.

• WildFire Appliance:

curl -X GET "https://<panorama>/api/?
key=<apikey>&&type=op&cmd=<show><wildfire-
appliance><info><serial-
number><serial_number></serial-number></
info></wildfire-appliance></show>"

• WildFire Cluster:

curl -X GET "https://<panorama>/api/?
key=<apikey>&&type=op&cmd=<show><wildfire-
appliance-
cluster><info><name><cluster_name></name></
info></wildfire-appliance-cluster></show>"

• WildFire Appliance:

curl -X GET "https://<panorama>/api/?
key=<apikey>&&type=op&cmd=<show><wildfire-
appliance><last-device-
registration><all><serial-
number><serial_number></serial-number></
all></last-device-registration></wildfire-
appliance></show>"

• WildFire Cluster:

curl -X GET "https://<panorama>/api/?
key=<apikey>&&type=op&cmd=<show><wildfire-
appliance-cluster><last-device-
registration><all><name><cluster_name></
name></all></last-device-registration></
wildfire-appliance-cluster></show>"

• WildFire Appliance:

curl -X GET "https://<panorama>/api/?
key=<apikey>&&type=op&cmd=<show><wildfire-
appliance><statistics><days><days_up_to_31></
days><type><all_or_file_or_general></
type><serial-number><serial_number></
name></statistics></wildfire-appliance></
show>"

• WildFire Cluster:

curl -X GET "https://<panorama>/api/?
key=<apikey>&&type=op&cmd=<show><wildfire-
appliance-
cluster><statistics><hours><hours_up_to_24></

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

79

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Operaonal Command

API Request

minutes><type><all_or_file_or_general></
type><name><cluster_name></name></
statistics></wildfire-appliance-cluster></
show>"

Display a list of supported
VM images on the speciﬁed
WildFire appliance.

curl -X GET "https://<panorama>/api/?
key=<apikey>&&type=op&cmd=<show><wildfire-
appliance><vm-images><serial-
number><serial_number></serial-number></vm-
images></wildfire-appliance></show>"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

80

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Get Reports (API)

The XML API provides a way to quickly pull the results of any report deﬁned in the system using
the type=report parameter.

You can access three kinds of reports:

• Dynamic Reports (ACC reports)— reporttype=dynamic

• Predeﬁned Reports— reporttype=predefined

• Custom Reports— reporttype=custom

To retrieve a speciﬁc report by name, use the reportname parameter:

   curl -X GET "https://<firewall>/api/?
key=<apikey>&type=report&reporttype=dynamic|predefined|
custom&reportname=<name>"

When you request a report, the API responds asynchronously with a job ID, which you can
use to retrieve the reports. Learn more about Asynchronous and Synchronous Requests
to the PAN-OS XML API.

• Dynamic Reports

• Predeﬁned Reports

• Custom Reports

Dynamic Reports

You can use the API to view a number of dynamic reports, such as top-applications-
summary, top-blocked-url-summary, and top-spyware-threats-summary. For dynamic
reports, provide either a speciﬁc period using the period or a me frame using starttime
and endtime opons (use a + instead of a space between the date and mestamp). Use topn to
determine the number of rows.

Dynamic Report Type

API Request

Full dynamic report list.

        curl -X GET "https://<firewall>/api/?
key=apikey&type=report&reporttype=dynamic"

Last 60 seconds.

        https://<firewall>/api/?key=apikey&
         type=report&reporttype=dynamic&
         reportname=top-app-
summary&period=last-60-seconds&topn=5

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

81

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Dynamic Report Type

API Request

Last 15 minutes.

Last hour.

Last 12 hours.

Last calendar day.

Last 7 days

        https://<firewall>/api/?key=apikey&
         type=report&reporttype=dynamic
         &reportname=top-app-
summary&period=last-15-minutes&topn=5

        https://<firewall>/api/?key=apikey&
         type=report&reporttype=dynamic&
         reportname=top-app-
summary&period=last-hour&topn=5

        https://<firewall>/api/?key=apikey&
         type=report&reporttype=dynamic&
         reportname=top-app-
summary&period=last-12-hrs&topn=5

        https://<firewall>/api/?key=apikey&
         type=report&reporttype=dynamic&
         reportname=top-app-
summary&period=last-calendar-day&topn=5

        https://<firewall>/api/?key=apikey&
         type=report&reporttype=dynamic&
         reportname=top-app-
summary&period=last-7-days&topn=5

Last 7 calendar days

        https://<firewall>/api/?key=apikey&
         type=report&reporttype=dynamic&
         reportname=top-app-
summary&period=last-hour&topn=5

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

82

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Dynamic Report Type

API Request

Last calendar week.

Last 30 days

        https://<firewall>/api/?key=apikey&
         type=report&reporttype=dynamic&
         reportname=top-app-
summary&period=last-calendar-week&topn=5

        https://<firewall>/api/?key=apikey&
         type=report&reporttype=dynamic&
         reportname=top-app-
summary&period=last-30-days&topn=5

Predeﬁned Reports

Predeﬁned reports always return data for the last 24-hour period. You can also get this list by
following the link for predeﬁned reports, such as top-applications, top-attackers, and
bandwidth-trend on the API browser.

Dynamic Report Type

API Request

Full predeﬁned report list.

        curl -X GET "https://<firewall>/api/?
key=apikey&type=report&reporttype=predefined"

Top applicaons.

Top aackers.

        curl -X GET "https://<firewall>/api/?
key=apikey&type=report&async=yes&reporttype=predefined&reportname=top-
application-categories"

        curl -X GET "https://<firewall>/api/?
key=apikey&type=report&async=yes&reporttype=predefined&reportname=top-
attackers"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

83

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Dynamic Report Type

API Request

Top vicms.

Custom Reports

        curl -X GET "https://<firewall>/api/?
key=apikey&type=report&async=yes&reporttype=predefined&reportname=top-
victims"

For custom reports, the selecon criteria, such as me frame, group-by, and sort-by are part of the
report deﬁnion. The API returns any shared custom reports. Note that quotes are not required
around the report name and any spaces in the report name must be URL encoded to %20.

For custom reports created in a speciﬁc VSYS, you can retrieve them directly by specifying the
vsys parameters.

STEP 1 | Retrieve the report deﬁnion from the conﬁguraon:

      curl -X GET "https://<firewall>/api/?
key=<apikey>&type=config&action=get&xpath=/config/devices/entry/
vsys/entry[@name='vsys1']/reports/entry[@name='report-abc']"

STEP 2 | Create a job to retrieve a dynamic report using reporttype=dynamic,

reportname=custom-dynamic-report, and cmd=report-definition where
report-definition is the XML deﬁnion retrieved in the previous query:

      https://<firewall>/api/?
key=apikey&type=report&reporttype=dynamic&reportname=custom-
dynamic-report&cmd=<type><appstat><aggregate-by><member>category-
of-name</member><member>technology-of-name</member></aggregate-
by></appstat></type><period>last-24-hrs</period><topn>10</
topn><topm>10</topm><query>(name+neq+'')AND(vsys+eq+'vsys1')</
query>

The response includes the job ID you can use to view the results:

      <response
       status="success">
       <result>
       <msg>
       <line>Report job enqueued with jobid 6</line>
       </msg>
       <job>6</job>
       </result>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

84

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

       </response>

STEP 3 | View the dynamic report:

      https://<firewall>/api/?
key=apikey&type=report&action=get&job-id=jobid

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

85

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Export Files (API)

You can export certain types of ﬁles from the ﬁrewall using the type=export parameter in the
API request.

Use the category parameter to specify the type of ﬁle that you want to export.

• Conﬁguraon—category=configuration

• Cerﬁcates/Keys—category=certificate

• Response pages—category= application-block-page | captive-portal-text |
file-block-continue-page | file-block-page | global-protect-portal-
custom-help-page | global-protect-portal-custom-login-page | global-
protect-portal-custom-welcome-page | ssl-cert-status-page | ssl-
optout-text | url-block-page | url-coach-text | virus-block-page>

• Technical support data—category=tech-support

• Device State—category=device-state

Use cURL tools to export the ﬁle from the ﬁrewall and save locally with a local ﬁle name:

curl -o <filename> "https://<firewall>/api/?<query-parameters>"

When using the API query from a web browser, you can specify to=filename as an oponal
parameter if you would like to provide a diﬀerent name when saving the ﬁle locally.

• Export Packet Captures

• Export Cerﬁcates and Keys

• Export Technical Support Data

Export Packet Captures

You can export packet captures from the ﬁrewall by specifying the PCAP type using the
category parameter:

• Export Applicaon PCAPS

• Export Threat, Filter, and Data Filtering PCAPs

Export Applicaon PCAPS

Applicaon PCAPs are organized by a directory/ﬁlename structure where the directory is a
date in yyyymmdd format. Filenames for applicaon pcaps use a SourceIP-SourcePort-
DestinationIP-DestinationPort-SessionID.pcap format.

Applicaon PCAP Type

API Request

Applicaon PCAP directory
list.

        curl -X GET "https://<firewall>/api/?
key=apikey&type=export&category=application-
pcap"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

86

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Applicaon PCAP Type

API Request

List of ﬁles under a
directory using the from
parameter to indicate date.

Applicaon PCAP ﬁle
by name using the from
parameter.

        curl -X GET "https://<firewall>/api/?
key=apikey&type=export&category=application-
pcap&from=<yyyymmdd>"

        curl -X GET "https://<firewall>/api/?
key=apikey&type=export&category=application-
pcap&from=<yyyymmdd>/<filename>"

The ﬁle will be retrieved and saved locally using the name
yyyymmdd-ﬁlename.

Applicaon PCAP ﬁle saved
locally with a custom name
using the to parameter.

        curl -X GET "https://<firewall>/api/?
key=apikey&type=export&category=application-
pcap&from=<yyyymmdd>/
<filename>&to=<localfile>"

Export Threat, Filter, and Data Filtering PCAPs

To export threat PCAPs, you need to provide the PCAP ID from the threat log and the search
me, which is the me that the PCAP was received on the ﬁrewall. Threat PCAP ﬁlenames use a
pcapID.pcap format.

PCAP Type

API Request

Threat PCAP using PCAP
ID, device name, session ID,
and search

List of ﬁltered PCAPs

        curl -X GET "https://<firewall>/
api/?key=apikey&type=export&category=threat-
pcap&pcap-id=<id>&device_name=<device
 name>&sessionid=<session id>&search-
time=<yyyy/mm/dd+hr:min:sec>"

        curl -X GET "https://<firewall>/api/?
key=apikey&type=export&category=filters-pcap"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

87

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

PCAP Type

API Request

Speciﬁc ﬁltered PCAP ﬁle

List of data ﬁltering PCAP
ﬁle names

Speciﬁc data ﬁltering PCAP
ﬁle

        curl -X GET "https://<firewall>/api/?
key=apikey&type=export&category=filters-
pcap&from=<filename>"

        curl -X GET "https://<firewall>/api/?
key=apikey&type=export&category=dlp-pcap&dlp-
password=<password>"

        curl -X GET "https://<firewall>/api/?
key=apikey&type=export&category=dlp-pcap&dlp-
password=<password>&from=<filename>&to=<localfile>"

Export Cerﬁcates and Keys

Use the following procedure to export cerﬁcates and keys.

STEP 1 | To export cerﬁcates and keys, specify query parameters certificate-name, format,

and passphrase:

      https://<firewall>/api/?
key=apikey&type=export&category=<certificate>
       &certificate-name=<certificate_name>
       &passphrase=<passphrase>
       &format=<pkcs12><pem><pkcs10>
       &include-key=<yes><no>&vsys=<vsys>
       <omit this parameter to import it into a shared location>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

88

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

• certificate-name—name of the cerﬁcate object on the ﬁrewall

• passphrase—required when including the cerﬁcate key

• format—cerﬁcate format: pkcs12, pem, or pkcs10

• include-key—yes or no parameter to include or exclude the key

• vsys—virtual system where the cerﬁcate object is used. Ignore this parameter if the

cerﬁcate is a shared object.

You can use the example above to export a cerﬁcate signing request (CSR). If you do so, then
specify the following two parameters as shown:

• format— pkcs10

• include-key— no

STEP 2 | Conﬁrm that the XML response includes the cerﬁcate:

      -----BEGIN CERTIFICATE-----
       MIIDXTCCAkWgAwIBAgIJAJC1HiIAZAiIMA0GCSqGSIb3Df
       BAYTAkFVMRMwEQYDVQQIDApTb21lLVN0YXRlMSEwHwYDVx
       aWRnaXRzIFB0eSBMdGQwHhcNMTExMjMxMDg1OTQ0WhcNMT
       <!-- TRUNCATED -->
       -----END CERTIFICATE-----

Export Technical Support Data

Debug log data sizes are large, so the API uses an asynchronous job scheduling approach to
retrieve technical support data. Learn more about Asynchronous and Synchronous Requests to the
PAN-OS XML API. The values for the acon parameter are:

• action=<null>—When an acon parameter is not speciﬁed, the system creates a new job to
retrieve tech support data. The inial query creates a job ID that you can then use to check on
the status of the job, retrieve results, or delete the job.

• action=status—Check the status of the job. This returns an XML response with a status

element; when the status text data is FIN the job is completed and the tech support ﬁle can be
retrieved. Example:

    https://<firewall>/api/?key=apikey&type=export&category=tech-
support&action=status&job-id=299

• action=get—Retrieve the tech support ﬁle as an aachment. The response contains a
application/octet-stream content-type and a content-disposion header with a
suggested ﬁlename; for example:

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

89

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

    Content-Type: application/octet-stream

     Content-Length: 19658186

     Content-Description: File Transfer

     Content-Transfer-Encoding: binary

     Content-Disposition: attachment; filename=techsupport-8469.tgz

• action=finish—Stop an acve job.

STEP 1 | Create a job to retrieve technical support data.

Use the following request:

      https://<firewall>/api/?key=apikey&type=export&category=tech-
support

The response includes a job ID:

<response status="success"code="19"> <result> <msg> <line>Exec job
enqueued with jobid 2</line> </msg> <job>2</job> </result></response>

STEP 2 | Check on the status of the job.

Use the job ID returned in the previous response as the job-id parameter:

      https://<firewall>/api/?key=apikey&type=export&category=tech-
support&action=status&job-id=id

A status value of FIN indicates the data is ready to be retrieved.

      <response status="success">
  <result>
    <job>
      <tenq>2012/06/14 10:11:09</tenq>
      <id>2</id>
      <user/>
      <type>Exec</type>
      <status>FIN</status>
      <stoppable>no</stoppable>
      <result>0K</result>
      <tfin>10:12:39</tfin>
      <progress>10:12:39</progress>
      <details/>
      <warnings/>
      <resultfile>//tmp/techsupport.tgz</resultfile>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

90

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

    </job>
  </result>
</response>

STEP 3 | Retrieve the tech support data.

      https://<firewall>/api/?key=apikey&type=export&category=tech-
support&action=get&job-id=id

When using cURL, you can specify the output ﬁle name as an opon to cURL ( -o). Aer a
successful retrieval of the job data, the job is automacally deleted by the system.

STEP 4 |

( Oponal) Stop the acve job in case of error.

If there is an error or issue with the export job, it may not complete. In cases like this, stop the
acve job:

      https://<firewall>/api/?key=apikey&type=export&category=tech-
support&action=finish&job-id=id

The response includes a success message:

      <response status"success">

         <msg>Job  2  removed.</msg>

       </response>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

91

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Import Files (API)

You can import certain types of ﬁles, including as soware, content, licenses, and conﬁguraons
into the ﬁrewall using the type=import parameter in the API request.

Use type=import and specify the category to import these types of ﬁles:

• Soware—category=software

• Content—category=<anti-virus | content | url-database | signed-url-

database>

• Licenses—category=license

• Conﬁguraon—category=configuration

• Cerﬁcates/key—category=<certificate | high-availability-key | key-

pair>

• Response pages—category=<application-block-page | captive-portal-text |
file-block-continue-page | file-block-page | global-protect-portal-
custom-help-page | global-protect-portal-custom-login-page | global-
protect-portal-custom-welcome-page | ssl-cert-status-page | ssl-
optout-text | url-block-page | url-coach-text | virus-block-page>

• Clients—category=global-protect-client

• Custom logo—category=custom-logo

• Imporng Basics

• Import Files

Imporng Basics

Use cURL to import ﬁles to the ﬁrewall.

Import ﬁles to a ﬁrewall:

      curl --form file=@<filename> “https://firewall/api/?<query-
parameters>”

Import ﬁles to a ﬁrewall via Panorama. First import the ﬁle to Panorama, then run a request
batch upload-install op command:

      curl -X GET "http://<panorama>/api/?
key=apikey&type=op&cmd=<request><batch><anti-virus><upload-
install><uploaded-file><your-file-name-here></uploaded-
file><devices><serialnumber></devices></upload-install></anti-
virus></batch></request>"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

92

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Import Files

Use the API Browser to see a full list of import categories.

Import a cerﬁcate or key by specifying the type of the cerﬁcate or key ﬁle using the
category parameter:

• category=certificate

• category=keypair

• category=high-availability-key

( category=certificate or category=keypair only) Specify these addional
parameters for the cerﬁcate ﬁle and keypair imports:

• certificate-name—name of the cerﬁcate object on the ﬁrewall

• format—cerﬁcate format, pkcs12 or pem

• passphrase—required when including the cerﬁcate key

• vsys—virtual system where the cerﬁcate object is used. Ignore this parameter if the

cerﬁcate is a shared object.

      curl -X GET "https://<firewall>/api/?
key=<apikey>&type=import&category=certificate&certificate-
name=<certificate_name>&format=pkcs12 |
 pem&passphrase=text&vsys=<vsys>"

Import a GlobalProtect response pages using an addional parameter for the security proﬁle in
which the page should be imported:

      profile=profilename

Import custom logos to diﬀerent locaons based on the where parameter:

      where=<login-screen | main-ui | pdf-report-footer | pdf-
report-header>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

93

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Retrieve Logs (API)

Retrieve logs from a ﬁrewall using the API.

• API Log Retrieval Parameters

• Example: Use the API to Retrieve Traﬃc Logs

API Log Retrieval Parameters

Specify the log type with addional oponal parameters to retrieve logs from a ﬁrewall.

Parameter

Descripon

log-type

The type of logs to retrieve:

• log-type=traffic—Traﬃc logs

• log-type=threat—Threat logs

• log-type=config—Conﬁg logs

• log-type=system—System logs

• log-type=hipmatch— GlobalProtect Host Informaon Proﬁle

(HIP) matching logs

• log-type=wildfire—WildFire logs

• log-type=url—URL ﬁltering logs

• log-type=data—Data ﬁltering logs

• log-type=corr—Correlated event logs as seen in the user
interface within Monitor > Automated Correlated Engine >
Correlated Events.

• log-type=corr-detail—Correlated event details as seen in
the user interface when you select an event within Monitor >
Automated Correlated Engine > Correlated Events.

• log-type=corr-categ—Correlated events by category,

currently compromised hosts seen within ACC > Threat Acvity >
Compromised Hosts.

• log-type=userid—User-ID logs

• log-type=auth—Authencaon logs

• log-type=gtp—GPRS Tunneling Protocol (GTP) logs

• log-type=external—External logs

• log-type=iptag—IP tag logs

query

(Oponal) Specify the match criteria for the logs. This is similar to
the query provided in the web interface under the Monitor tab when
viewing the logs. The query must be URL encoded.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

94

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Parameter

Descripon

nlogs

skip

dir

acon

(Oponal) Specify the number of logs to retrieve. The default is 20
when the parameter is not speciﬁed. The maximum is 5000.

(Oponal) Specify the number of logs to skip when doing a log
retrieval. The default is 0. This is useful when retrieving logs in batches
where you can skip the previously retrieved logs.

(Oponal) Specify whether logs are shown oldest ﬁrst (forward) or
newest ﬁrst (backward). Default is backward.

(Oponal) Log data sizes can be large so the API uses an asynchronous
job scheduling approach to retrieve log data. The inial query returns
a Job ID (job-id) that you can then use for future queries with the
action parameter:

• action=get—Check status of an acve job or retrieve the log

data when the status is FIN (ﬁnished). This is slightly diﬀerent than
the asynchronous approach to retrieve tech support data where a
separate status acon is available.

• action=finish—Stop an acve job.

• Not speciﬁed—When not speciﬁed, such as during an inial query,

the system creates a new job to retrieve log data.

Learn more about Asynchronous and Synchronous
Requests to the PAN-OS XML API.

Example: Use the API to Retrieve Traﬃc Logs

Follow these steps to use the API retrieve traﬃc logs.

STEP 1 | Create a job to retrieve all traﬃc logs that occurred aer a certain me:

      curl -X GET "https://<firewall>/api/?
key=<apikey>type=log&log-type=traffic&query=(receive_time geq
 '2012/06/22 08:00:00')"

A web-browser will automacally URL encode the parameters, but when using cURL,
the query parameter must be URL encoded.

Response:

      <response status="success" code="19">
  <result>
    <msg>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

95

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

      <line>query job enqueued with jobid 18</line>
    </msg>
    <job>18</job>
  </result>
</response>

STEP 2 | Retrieve traﬃc log data using the following request using the job ID as the value returned in

the previous response:

      curl -X GET "https://<firewall>/api/?
key=<apikey>type=log&action=get&job-id=<id>"

STEP 3 | Conﬁrm that the XML response looks similar to the following:

      <response status="success"">
       <result>
       <job>...</job>
       <log>
       <logs count="20" progress="100n>
       <entry logid="5753304543500710425"> <domain>1</
domain> <receive_time>2012/06/13 15:43:17</receive_time>
 <serial>001606000117</serial> <segno>6784588</segno>
       <actionflags>0x0</actionflags> <type>TRAFFIC</
type> <subtype>start</subtype> <config_ver>1</config_ver>
 <time_generated>2012/06/13 15:43:17</time_generated>
       <src>172.16.1.2</src> <dst>10.0.0.246</dst>
 <natsrc>10.16.0.96</natsrc> <natdst>10.0.0.246</natdst>
 <rule>default allow</rule>

When the job status is FIN (ﬁnished), the response automacally includes all the logs in the
XML data response. The <log> node in XML is not present when the job status is sll pending.
Aer successful log data retrieval, the system automacally deletes the job.

STEP 4 |

( Oponal) Delete and acve log retrieval job.To delete an acve log retrieval job, run the
following query:

      curl -X GET "https://<firewall>/api/?
key=<apikey>type=log&action=finish&job-id=<id>"

A successful compleon returns a job ID.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

96

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Apply User-ID Mapping and Populate Dynamic Groups
(API)

Use the type=user-id parameter to apply User-ID mapping informaon directly to the ﬁrewall.
If you are using a third-party VPN soluon or have users who are connecng to an 802.1x enabled
wireless network, the User-ID API enables you to map users to groups so that you can capture
login events and send them to the User-ID agent or directly to the ﬁrewall. Addionally, you can
use the API to register the IP-to-user mapping informaon from the input ﬁle to populate the
members of a dynamic address group or dynamic user group on the ﬁrewall.

curl -F key=<apikey> --form file=@<filename> "https://<firewall>/
api/?type=user-id"

or

curl --data-urlencode key=<apikey> -d type=user-id --data-urlencode
 "cmd=xml-document" https://<firewall>/api/

With your User-ID API requests, you can use the following oponal parameters:

• vsys=vsys_id—Specify the vsys where you want to apply User-ID mapping.

• target=serialnumber—Specify the ﬁrewall by serial number when redirecng through

Panorama.

• Use a GET request if the URL query size is less than 2K and a POST request if the

request size is between 2K to 5MB. Limit the query size to 5MB.

• When mulple login or logout events are generated at the same me, make sure to

follow these guidelines to ensure opmal ﬁrewall performance:

• Design your applicaon to queue events and perform batch API updates instead of

sending single event or mapping updates.

• Limit the number of concurrent API calls to ﬁve. This limit ensures that there is no
performance impact to the ﬁrewall web interface as the management plane web
server handles requests from both the API and the web interface.

• (Panorama managed ﬁrewalls only) You cannot view the IP addresses of a DAG

registered using XML API on the Panorama web interface. You must log in to the
Panorama CLI to view the registered IP addresses of a DAG populated using XML
API on Panorama and use the following command:

 show object registered-ip all

Use the informaon in the following table to apply User-ID mapping informaon to a ﬁrewall:

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

97

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Mapping or Registraon
Acon

API Request

User-ID mapping for a
login, logout, or groups.

Use this input ﬁle format when providing a User-ID mapping for
a login event, logout event, or for groups:

<uid-message>
     <version>1.0</version>
     <type>update</type>
     <payload>
          <login>
               <entry name="domain\uid1"
 ip="10.1.1.1" timeout="20">
               </entry>
          </login>
          <groups>
               <entry name="group1">
                    <members>
                         <entry name="user1"/
>
                         <entry name="user2"/
>
                    </members>
               </entry>
               <entry name="group2">
                    <members>
                         <entry name="user3"/
>
                    </members>
               </entry>
          </groups>
     </payload>
</uid-message>

You can include a HIP report by including a <hip-report></
hip-report> XML container within an <entry> parent
element.

Use the following input ﬁle format to set up a terminal server
entry on the ﬁrewall and to specify the port range and block
size of ports that will be assigned per user. If you are using the
default port range (1025 to 65534) and block size (200) you do
not need to send a multiusersystem setup message; the
ﬁrewall will automacally create the terminal server object when
it receives the ﬁrst login message.

<uid-message>
<payload>
          <multiusersystem>
              <entry ip="10.1.1.2"
 startport="xxxxx" endport="xxxxx"
blocksize="xxx">
          </multiusersystem>

Mul-User System Entry

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

98

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Mapping or Registraon
Acon

API Request

     </payload>
     <type>update</type>
     <version>1.0</version>
</uid-message>

User-ID XML muluser
system login event

When the terminal servers sends a login event payload to the
ﬁrewall, it can contain mulple login events. The ﬁrewall uses the
informaon in the informaon in the login message to populate
its user mapping table. For example, if the ﬁrewall received a
packet with a source address and port of 10.1.1.23:20101, it
would map the request to user jparker for policy enforcement.

<uid-message>
<payload>
          <login>
               <entry name="acme\jparker"
 ip="10.1.1.23" blockstart="20100">
          </login>
     </payload>
     <type>update</type>
     <version>1.0</version>
</uid-message>

User-ID XML muluser
system logout

Upon receipt of a logout event message with a blockstart
parameter, the ﬁrewall removes the corresponding IP address-
port-user mapping. If the logout message contains a username
and IP address, but no blockstart parameter, the ﬁrewall
removes all mappings for the user. If the logout message contains
an IP address only, the ﬁrewall removes the mul-user system
and all associated mappings.

<uid-message>
<payload>
          <logout>
              <entry user="domain\uid2"
 ip="10.1.1.2" blockstart="xxxxx">
</logout>
     </payload>
     <type>update</type>
     <version>1.0</version>
</uid-message>

Dynamic address group IP
address registraon

Use the following input ﬁle format to dynamically register and
unregister IP addresses.

You can conﬁgure a meout as part of the member element
to automacally unregister IP address-to-tag mapping aer a
speciﬁed amount of me. By default, no meout is speciﬁed
meaning the mapping will not meout and must be manually

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

99

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Mapping or Registraon
Acon

API Request

unregistered. Addionally, a meout of zero (0) seconds does not
meout. You can specify a meout between zero (0) seconds and
2,592,000 seconds (30 days).

<uid-message>
     <version>1.0</version>
     <type>update</type>
     <payload>
         <register>
             <entry ip="10.1.1.1">
               <tag>
  <member timeout="3600">CBB09C3D-3416-4734-
BE90-0395B7598DE3</member>
    </tag>
           </entry>
         </register>
          <unregister>
               <entry ip="10.1.1.3"/>
     <tag>
  <member>CBB09C3D-3416-4734-
BE90-0395B7598DE5</member>
      </tag>
               </entry>
          </unregister>
     </payload>
</uid-message>

Register tags for a user to
add that user to a dynamic
user group

Use the following input ﬁle format to dynamically register tags to
a user and include that user in a dynamic user group.

To register a tag for a user, that user must have an
exisng user mapping or group mapping.

You can conﬁgure a meout to automacally unregister the user-
to-tag mapping aer a speciﬁed amount of me. By default,
no meout is speciﬁed meaning the mapping will not meout
and must be manually unregistered. You can specify a meout
between zero (0) and 2,562,000 seconds (30 days).

<uid-message>
  <version>1.0</version>
  <type>update</type>
  <payload>
    <register-user>
      <entry user="paloaltonetworks\john">
        <tag>
          <member>finished_ethics_training</
member>
          <member>mac_user</member>
        </tag>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

100

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Mapping or Registraon
Acon

API Request

      </entry>
      <entry user="paloaltonetworks\jane">
        <tag>
          <member timeout="120">building_1</
member>
          <member>pc_user</member>
        </tag>
      </entry>
    </register-user>
  </payload>
</uid-message>

Unregister speciﬁc tags
for a user to remove that
user from the dynamic user
group

Use the following input ﬁle format to unregister a speciﬁc
dynamic tag from a user and remove the user from the dynamic
user group associated with that tag.

<uid-message>
  <version>1.0</version>
  <type>update</type>
  <payload>
    <unregister-user>
      <entry user="paloaltonetworks\john">
        <tag>
          <member>mac_user</member>
        </tag>
      </entry>
    </unregister-user>
  </payload>
</uid-message>

Unregister all tags for a
user

Use the following input ﬁle format to unregister all tags for a
speciﬁc user.

<uid-message>
  <version>1.0</version>
  <type>update</type>
  <payload>
    <unregister-user>
      <entry user="paloaltonetworks\john">
      </entry>
    </unregister-user>
  </payload>
</uid-message>

Clear all tags for all users

Use the following input ﬁle format to unregister all tags from all
users.

<uid-message>
  <version>1.0</version>
  <type>update</type>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

101

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Mapping or Registraon
Acon

API Request

  <payload>
    <clear>
      <registered-user>
        <all/>
      </registered-user>
    </clear>
  </payload>
</uid-message>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

102

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

Get Version Info (API)

Use the type=version request type to show the PAN-OS version for a ﬁrewall or Panorama. In
addion to the PAN-OS version, this request provides a direct way to obtain the serial number and
model number.

STEP 1 | Make a request to the PAN-OS XML API and with type=version along with your API key:

      curl -X GET "https://<firewall>/api/?
type=version&key=<apikey>"

STEP 2 | Conﬁrm that the XML response contains the soware version, model, serial number, and

whether mul-vsys mode is on:

      <response status="success">
  <result>
    <sw-version>7.1.0</sw-version>
    <multi-vsys>off</multi-vsys>
    <model>pa-vm</model>
    <serial>007000001222</serial>
  </result>
</response>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

103

©2022 Palo Alto Networks, Inc.

PAN-OS XML API Request Types

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

104

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

To use the PAN-OS® and Panorama™ REST API, ﬁrst use your administrave
credenals to get an API key. You can then use the API key to make API requests.

>

>

>

>

>

PAN-OS REST API

Access the PAN-OS REST API

Resource Methods and Query
Parameters (REST API)

PAN-OS REST API Request and
Response Structure

PAN-OS REST API Error Codes

> Work With Objects (REST API)

>

Create a Security Policy Rule (REST
API)

> Work with Policy Rules on Panorama

>

>

>

>

(REST API)

Create a Tag (REST API)

Conﬁgure a Security Zone (REST API)

Conﬁgure a Virtual SD-WAN
Interface (REST API)

Create an SD-WAN Policy Pre Rule
(REST API)

The PAN-OS REST API covers a subset of the ﬁrewall and Panorama funcons, and
you’ll need to use the XML API to complete the conﬁguraon and commit your
changes.

The API requests in this guide use cURL commands. However, you can make API
requests with other tools such as Postman or a RESTClient. By default, PAN-OS uses
a self-signed cerﬁcate, so you will need to use the -k parameter with cURL requests.
Alternavely, you can replace the self-signed cerﬁcate with one from a trusted
cerﬁcate authority. If you have an internal cerﬁcate authority, generate your own
cerﬁcate and install it on the ﬁrewall.

105

Get Started with the PAN-OS REST API

PAN-OS REST API

The PAN-OS® and Panorama™ REST API allow you to manage ﬁrewalls and Panorama through a
third-party service, applicaon, or script.

You can use the REST API to Create, Read, Update, Delete (CRUD) Objects and Policies on the
ﬁrewalls; you can access the REST API directly on the ﬁrewall or use Panorama to perform these
operaon on policies and objects from a central locaon and push them to the managed ﬁrewalls.

The inputs in the PAN-OS REST API generally match the web interface, and you can use the
PAN-OS Web Interface Help to familiarize yourself with the ﬁeld properes, descripons, and
supported values for each product. Reading relevant porons of the PAN-OS Administrator’s
Guide will help you get a beer understanding of ﬁrewall capabilies that you can access using the
API. To use the API, you should also be knowledgeable about web service APIs and HTTP.

To get started, see:

• Access the PAN-OS REST API

• Resource Methods and Query Parameters (REST API)

• PAN-OS REST API Request and Response Structure

• PAN-OS REST API Error Codes

• Work With Objects (REST API)

• Create a Security Policy Rule (REST API)

• Work with Policy Rules on Panorama (REST API)

• Create a Tag (REST API)

• Conﬁgure a Security Zone (REST API)

• Conﬁgure a Virtual SD-WAN Interface (REST API)

• Create an SD-WAN Policy Pre Rule (REST API)

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

106

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Access the PAN-OS REST API

The PAN-OS REST API URL format includes a base path and the URI for the endpoint:

curl -X GET "https://<IP address or FQDN>/restapi/<PAN-OS version>/
<resource URI>."

The base path includes the FQDN or IP address of the ﬁrewall or Panorama and the version. The
resource URI is the path for the resource or endpoint you want to work with, and it corresponds
with the resources you can access on the web interface. Use the PAN-OS Web Interface Help to
familiarize yourself with the ﬁeld properes, descripons, and supported values for each resource.

You can view the full list of resources in the REST API Reference on the ﬁrewall or Panorama at
https://<IP_address>/restapi-doc.

To use the REST API, you must Enable API Access for your administrators and Get Your API Key.
See API Authencaon and Security for details on authencang your API requests.

The following table lists the PAN-OS 9.1 REST API resource URIs that are available on
the ﬁrewall. The resource URIs on Panorama are analogous except that resources support
both pre rule and post rule policies. The PAN-OS 9.1 REST API resources oﬀer abilies
like managing policies on the ﬁrewall or conﬁguring SD-WAN interfaces and policies on
Panorama. To complete the conﬁguraon, you’ll need to use the XML API on the ﬁrewall
and Panorama.

Resource

OBJECTS

URI

/restapi/v9.1/Objects/Addresses

/restapi/v9.1/Objects/AddressGroups

/restapi/v9.1/Objects/Regions

/restapi/v9.1/Objects/Applicaons

/restapi/v9.1/Objects/ApplicaonGroups

/restapi/v9.1/Objects/ApplicaonFilters

/restapi/v9.1/Objects/Services

/restapi/v9.1/Objects/ServiceGroups

/restapi/v9.1/Objects/Tags

/restapi/v9.1/Objects/
GlobalProtectHIPObjects

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

107

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Resource

URI

/restapi/v9.1/Objects/
GlobalProtectHIPProﬁles

/restapi/v9.1/Objects/ExternalDynamicLists

/restapi/v9.1/Objects/CustomDataPaerns

/restapi/v9.1/Objects/
CustomSpywareSignatures

/restapi/v9.1/Objects/
CustomVulnerabilitySignatures

/restapi/v9.1/Objects/CustomURLCategories

/restapi/v9.1/Objects/
AnvirusSecurityProﬁles

/restapi/v9.1/Objects/
AnSpywareSecurityProﬁles

/restapi/v9.1/Objects/
VulnerabilityProteconSecurityProﬁles

/restapi/v9.1/Objects/
URLFilteringSecurityProﬁles

/restapi/v9.1/Objects/
FileBlockingSecurityProﬁles

/restapi/v9.1/Objects/
WildFireAnalysisSecurityProﬁles

/restapi/v9.1/Objects/
DataFilteringSecurityProﬁles

/restapi/v9.1/Objects/
DoSProteconSecurityProﬁles

/restapi/v9.1/Objects/SecurityProﬁleGroups

/restapi/v9.1/Objects/LogForwardingProﬁles

/restapi/v9.1/Objects/
AuthencaonEnforcements

/restapi/v9.1/Objects/DecryponProﬁles

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

108

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Resource

URI

/restapi/v9.1/Objects/
DecryponForwardingProﬁles

/restapi/v9.1/Objects/Schedules

/restapi/v9.1/Objects/
SDWANPathQualityProﬁles

/restapi/v9.1/Objects/
SDWANTraﬃcDistribuonProﬁles

POLICIES

/restapi/v9.1/Policies/SecurityRules

/restapi/v9.1/Policies/NATRules

/restapi/v9.1/Policies/QoSRules

/restapi/v9.1/Policies/
PolicyBasedForwardingRules

/restapi/v9.1/Policies/DecryponRules

/restapi/v9.1/Policies/TunnelInspeconRules

/restapi/v9.1/Policies/
ApplicaonOverrideRules

/restapi/v9.1/Policies/AuthencaonRules

/restapi/v9.1/Policies/DoSRules

/restapi/v9.1/Policies/SDWANRules

NETWORK

/restapi/v9.1/Network/SDWANInterfaces

/restapi/v9.1/Network/
SDWANInterfaceProﬁles

/restapi/v9.1/Network/EthernetInterfaces

/restapi/v9.1/Network/TunnelIntefaces

/restapi/v9.1/Network/Zones

/restapi/v9.1/Network/VirtualRouters

/restapi/v9.1/Network/QoSInterfaces

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

109

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Resource

DEVICE

URI

/restapi/v9.1/Device/VirtualSystems

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

110

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Resource Methods and Query Parameters (REST API)
The PAN-OS REST API requires query parameters for all API requests. The following table
describes the methods that the PAN-OS REST API supports and includes the query parameters
required for each operaon.

For a list of all resource URIs, see Access the PAN-OS REST API. To start using the API, see Work
With Objects (REST API) or Create a Security Policy Rule (REST API).

Resource Method

Read the
list of
resources

Create a
resource

Modify a
resource

Delete a
resource

Rename
a
resource

Move a
policy
rule(Policies
only)

HTTP Method

GET

POST

PUT

DELETE

POST

POST

Query
Parameters

name

oponal

required

required

required

required

required

locaon

required,

required,

required,

required,

required,

required,

valid
values
on the
ﬁrewall:

valid
values
on the
ﬁrewall:

valid
values
on the
ﬁrewall:

valid
values
on the
ﬁrewall:

valid
values
on the
ﬁrewall:

valid
values
on the
ﬁrewall:

predefined

shared
 for

shared
 for

shared
 for

shared
 for

shared

,

,

Objects

Objects

Objects

Objects

shared
 for

only

only

only

only

Objects

,

,

,

,

only

vsys

vsys

vsys

vsys

valid
values on
Panorama:

valid
values on
Panorama:

valid
values on
Panorama:

valid
values on
Panorama:

shared

shared

shared

shared

vsys

, or

,

vsys

valid
values on
Panorama:

shared

or

device-
group

panorama-
or
pushed

or

or

or

device-
group

device-
group

device-
group

device-
group

vsys

required,
if

required,
if

required,
if

required,
if

required,
if

required,
if

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

111

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

locaon
is

locaon
is

locaon
is

locaon
is

locaon
is

locaon
is

vsys

vsys

vsys

vsys

vsys

vsys

or

panorama-
pushed

device-
group

(Panorama
only)
required,
if
locaon
is device-
group

(Panorama
only)
required,
if
locaon
is device-
group

(Panorama
only)
required,
if
locaon
is device-
group

(Panorama
only)
required,
if
locaon
is device-
group

(Panorama
only)
required,
if
locaon
is device-
group

(Panorama
only)
required,
if
locaon
is device-
group

input-
format

—

output-
format

oponal,
default
format is
JSON

oponal,
default
format is
JSON

oponal,
default
format is
JSON

oponal,
default
format is
JSON

oponal,
default
format is
JSON

—

—

—

oponal,
default
format is
JSON

oponal,
default
format is
JSON

oponal,
default
format is
JSON

newname —

where

—

—

—

—

—

—

—

required

—

—

required,

valid
values:

top

,

,

,

bottom

before

after

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

112

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

dst

—

—

—

—

—

required,
when

where

is

before

or

after

Request Body

—

required

required

—

—

—

The following table shows examples of request formats with query parameters.

Acon

List

Create

Edit

Delete

Rename

Move

Example of Query Parameters in URL

GET https://<firewall or Panorama IP>/restapi/v9.1/
<resource URI>?location=location&output-format=json

POST https://<firewall or Panorama IP>/restapi/v9.1/
<resource URI>?location=location&name=name

PUT https://<firewall or Panorama IP>/restapi/v9.1/
<resource URI>?location=location&name=name

DELETE https://<firewall or Panorama IP>/restapi/
v9.1/<resource URI>?location=location&name=name

POST https://<firewall or Panorama IP>/restapi/v9.1/
<resource URI>:rename?location=location&name=name
 &newname=newname

POST https://<firewall or Panorama IP>/restapi/v9.1/
<resource URI>:move?location=location&name=name
 &where=<move to>

<move to> can be top, bottom, before &dst=<policy name>, aer
&dst=<policy name>

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

113

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

PAN-OS REST API Request and Response Structure

The PAN-OS REST API enables you to perform CRUD operaons with objects and use them
in policy rules. A resource in the PAN-OS REST API is an endpoint that you can conﬁgure with
parameters. When you make requests with the endpoints, you get responses that contain
informaon. The request and response formats support JSON (default) and XML.

In PAN-OS 9.1, aer you conﬁgure the ﬁrewalls and Panorama using the REST API, you
must use the XML API or the other management interfaces to commit your changes to the
running conﬁguraon.

Request Format

The API request format is constructed as shown in the example below:

https://<IP address or FQDN of the firewall or Panorama>/restapi/
<PAN-OS version>/<resource URI>?<query parameters>request body

• Base path and the resource URI for the endpoint. See Access the PAN-OS REST API for details.

• Query parameters. Every request includes query parameters that are passed to the API

endpoint using query strings. The query parameters are  appended to the URL with a ? that
indicates the start of the query string. The query parameters appear aer the  ?, the parameter
are concatenated with other parameters using the ampersand  & symbol.

Query Parameters on the ﬁrewall

• name (name) of the resource.

• locaon (vsys, predeﬁned, shared,

panorama-pushed) of the resource on
which you want to perform the operaon.
A predeﬁned object or rule is built-in to
the ﬁrewall and you cannot edit, rename or
delete predeﬁned objects or policy rules.

• virtual system (vsys) name for the resource,
if locaon is vsys or panorama-pushed.

• input format (input-format). JSON is

default, or XML. You can specify an input
format for HTTP methods that have a
request body, such as PUT to update and
POST to create a resource.

• output format (output-format) JSON

default, or XML

Query Parameters on Panorama

• name (name) of the resource.

• locaon (predeﬁned, shared, device-group,
panorama-pushed) of the resource on
which you want to perform the operaon.
A predeﬁned object or rule is built-in to

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

114

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Panorama and you cannot edit, rename or
delete predeﬁned objects or policy rules.

• device group (device-group) name of the

Panorama device group to which you have
assigned the ﬁrewalls, if locaon is device-
group.

• input format (input-format). JSON is

default, or XML. You can specify an input
format for HTTP methods that have a
request body, such as PUT to update and
POST to create a resource.

• output format (output-format) JSON

default, or XML

• Request body. When you create a resource with a POST request or edit a resource with a

PUT request, you include a JSON or XML formaed request body in which you specify the
properes for the resource you want to create or modify on the endpoint.

When you make an API request to the ﬁrewall or Panorama, the API key is required to
authencate the user who is making the request. You can enter the key with the custom
HTTP header X-PAN-KEY: <key>. Learn about API Authencaon and Security and
how to Get Your API Key.

Success Response Format

The HTTP response for a successful call has three elements: status, code, and result. The code is a
numeric value. Refer to the PAN-OS XML API Error Codes for details on the code included in the
HTTP response message.

     {
    "@code": "19",
    "@status": "success",
    "result": {
        "@count": "3",
        "@total-count": "3",
        "entry": [
            {
                "@location": "vsys",
                "@name": "fqdn1",
                "@vsys": "vsys1",
                "fqdn": "www.test.com"
            },
            {
                "@location": "vsys",
                "@name": "Peer1",
                "@vsys": "vsys1",
                "ip-netmask": "172.0.0.1/24"
            },
            {
                "@location": "vsys",
                "@name": "Peer2renamed",

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

115

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

                "@oldname": "Peer2",
                "@vsys": "vsys1",
                "ip-netmask": "200.0.0.1/24"
            }
        ]
    }
}

Error Response Format

In addion to the HTTP status code, the error response includes a JSON object or XML with error
informaon. The following is an example of an error response body from a REST API call to get an
address. In this example, the request is missing a query parameter:

     {
    "code": 3,
    "details": [
        {
            "@type": "CauseInfo",
            "causes": [
                {
                    "code": 7,
                    "description": "Missing Query Parameter: name",
                    "module": "panui_restapi"
                }
            ]
        }
    ],
    "message": "Missing Query Parameter: name"
}

The following table describes the error response ﬁelds.

Field

code

message

details

details.@type

Descripon

Feature-speciﬁc error code. The codes are listed in PAN-OS REST
API Error Codes

Human-readable message that corresponds to the code

Array of objects containing detailed data about the error

Type of data in details. Currently, the only type available is
CauseInfo

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

116

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Field

Descripon

The details under CauseInfo are for readability
and debugging purposes. The value can change
between soware releases. To avoid your scripts
breaking between releases, don’t parse the values in
details.causes.

details.causes

Array of objects that convey module-level error data

details.causes.module

Feature-speciﬁc module that reported the error

details.causes.code

Module-level error code. If details.causes.module is panui_mgmt,
then you can ﬁnd this module-level code in PAN-OS REST API
Error Codes

details.causes.descripon

Details about the error, from the feature-speciﬁc module.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

117

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

PAN-OS REST API Error Codes

The possible REST API feature-speciﬁc error response codes and their descripons are as follows:

Error
Code

Descripon

1

2

3

4

5

6

7

16

8

9

10

11

12

13

14

15

The operaon was canceled, typically by the caller.

Unknown internal server error.

Bad request. The caller speciﬁed an invalid parameter.

Gateway meout. A ﬁrewall or Panorama module med out before a backend
operaon completed.

Not found. The requested enty was not found.

Conﬂict. The enty that the caller aempted to create already exists.

Forbidden. The caller does not have permission to execute the speciﬁed operaon.

Unauthorized. The request does not have valid authencaon credenals to perform
the operaon.

Resource exhausted. Some resource has been exhausted.

Failed precondion. The operaon was rejected because the system is not in a state
required for the execuon of the operaon.

Aborted because of conﬂict. A typical cause is a concurrency issue.

Out of range. The operaon was aempted past a valid range. And example is
reaching an end-of-ﬁle.

Not implemented. The operaon is disabled, not implemented, or not supported.

Internal server error. An unexpected and potenally serious internal error occurred.

Service unavailable. The service is temporarily unavailable.

Internal server error. Unrecoverable data loss or data corrupon occurred.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

118

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Work With Objects (REST API)

Objects are elements that you use within policy rules. The ﬁrewalls and Panorama support a large
number of objects such as tags, address objects, log forwarding proﬁles, and security proﬁles.

The examples in this secon show you how to perform CRUD operaons with an address
object. You can use this example to work with other objects of the ﬁrewall. Access the REST
API reference documentaon at https://<IP address or FQDN of the firewall
or Panorama>/restapi-doc/ for help with the resource URIs for diﬀerent objects and the
structure of the request. For an overview, see PAN-OS REST API Request and Response Structure.

• Create an Address Object

• Edit an Address Object

• Rename an Address Object

• Delete an Address Object

• Get Address Objects

Create an Address Object

Make a POST request to create an address object. In the request, the query parameters must
include the name and the locaon on where you want to create the object. And in the request
body include the same name, locaon and other properes to deﬁne the object. For example:

    curl -X POST \
     'https://10.1.1.4/restapi/v9.1/Objects/Addresses?
location=shared&name=web-servers-production' \
     -H 'X-PAN-KEY: LUFRPT0=' \
     -d '{
    "entry": [
        {
            "@location": "shared",
            "@name": "web-servers-production",
            "description": "what is this for?",
            "fqdn": "docs.paloaltonetworks.com",
            "tag": {
                "member": [
                    "blue"
                ]
            }
        }
    ]
}'

Edit an Address Object

Make a PUT request and include the name and locaon of the object as query parameters. Include
the same locaon and name in the request body and deﬁne the properes of the object you’d
like to change. In the following example, you are modifying the descripon and adding a new tag

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

119

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

called red to the address object. If the tag does not already exist, you must ﬁrst create the tag
before you can reference it in the address object.

    curl -X PUT \
     'https://10.1.1.4/restapi/v9.1/Objects/Addresses?
location=shared&name=web-servers-production' \
     -H 'X-PAN-KEY: LUFRPT0=' \
     -d '{
    "entry": [
        {
            "@location": "shared",
            "@name": "web-servers-production",
            "description": "publish servers",
            "fqdn": "docs.paloaltonetworks.com",
            "tag": {
                "member": [
                    "blue",
                    "red"
                ]
            }
        }
    ]
}'

The response is

    {
    "@code": "20",
    "@status": "success",
    "msg": "command succeeded"
}

Rename an Address Object

When renaming an object, make a POST request with the following query parameters—name of
the object name=<name>, l ocation=<location>, and the new name newname=<name>. The
following example renames web-servers-producon to web-server-publish.

    curl -X POST \
     'https://10.5.196.4/restapi/v9.1/Objects/Addresses:rename?
location=shared&name=web-servers-production&newname=web-server-
publish' \
     -H 'X-PAN-KEY: LUFRPT0='

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

120

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Delete an Address Object

Make a DELETE request and include the name and the locaon of the object as query parameters.
For example:

    curl -X DELETE \
     'https://10.1.1.4/restapi/v9.1/Objects/Addresses?
location=shared&name=web-server-production' \
     -H 'X-PAN-KEY: LUFRPT0='

Get Address Objects

Make a GET request to retrieve a list of all address objects within a speciﬁed locaon. For
example, the following query reads all address objects in vsys1 which is indicated with
location=vsys&vsys=vsys1in the query parameter.

    curl -X GET \
     'https://10.1.1.4/restapi/v9.1/Objects/Addresses?
location=vsys&vsys=vsys1' \
     -H 'X-PAN-KEY: LUFRPT0='

And the response includes the list of address objects that are conﬁgured on vsys1 on the ﬁrewall.

    {
    "@code": "19",
    "@status": "success",
    "result": {
        "@count": "3",
        "@total-count": "3",
        "entry": [
            {
                "@location": "vsys",
                "@name": "fqdn1",
                "@vsys": "vsys1",
                "fqdn": "www.test.com"
            },
            {
                "@location": "vsys",
                "@name": "Peer1",
                "@vsys": "vsys1",
                "ip-netmask": "172.0.0.1/24"
            },
            {
                "@location": "vsys",
                "@name": "Peer2renamed",
                "@oldname": "Peer2",
                "@vsys": "vsys1",
                "ip-netmask": "200.0.0.1/24"
            }
        ]

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

121

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

    }
}

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

122

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Create a Security Policy Rule (REST API)

The example in this secon shows you how to create and update a Security policy rule on the
ﬁrewall. Use this example to get familiar with the REST API and then make it work with other
policy types on the ﬁrewall. Access the REST API reference documentaon at https://<IP
address or FQDN of the firewall or Panorama>/restapi-doc/for help with the
resource URIs for the diﬀerent objects and policies and for help with the properes supported for
each type of request. For an overview, see PAN-OS REST API Request and Response Structure.

• Create an Applicaon Object

• Create a Security Policy Rule

• Reference an Address Object in the Rule

Create an Applicaon Object

Make a POST request to create an applicaon object that allows you to allow browser-based
applicaons that belong to the category collaboraon and subcategory email. To make this
applicaon object named email-collaboration-apps available across all virtual systems
on a ﬁrewall, create the object at location=shared. Use Palo Alto Networks Applipedia,
the applicaon database to view the aributes (Category, Subcategory, Technology, Risk
or Characterisc) that you can use to deﬁne the object. You can also refer to https://
<firewall_IP>/restapi-doc/#tag/objects-applications for details on how to
construct an applicaon object. Here is an example.

curl -X POST \
  'https://10.1.1.4/restapi/v9.1/Objects/Applications?
location=shared&name=email-collaboration-apps' \
  -H 'X-PAN-KEY: LUFRPT=' \
  -d '{
    "entry": [
        {
            "@location": "shared",
            "@name": "email-collaboration-apps",
            "able-to-transfer-file": "yes",
            "category": "collaboration",
            "description": "apps we allow for collaboration",
            "risk": "2",
            "subcategory": "email",
            "technology": "browser-based"
        }
    ]
}'

You can now use this applicaon object in a Security policy rule.

Create a Security Policy Rule

Before you start here, use the XML API or any of the other management interfaces to set up
interfaces and zones on the ﬁrewall.

To create a Security policy rule, make a POST request. In the following example, the API key is
provided as a custom header X-PAN-KEY instead of as query parameter. For more details, see

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

123

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Access the PAN-OS REST API. The query parameters include the name of the rule, locaon and
vsys name location=vsys&vsys=<vsys_name>&name=<rule_name>. And in the request
body specify the same name, locaon, vsys name, and includes addional properes for the
Security policy rule including the applicaon object you created earlier.

curl -X POST \

  'https://10.1.1.4/restapi/v9.1/Policies/SecurityRules?
location=vsys&vsys=vsys1&name=rule-example1' \
  -H 'X-PAN-KEY: LUFRPT=' \
  -d '{
    "entry": [
        {
            "@location": "vsys",
            "@name": "rule-example1",
            "@vsys": "vsys1",
            "action": "allow",
            "application": {
                "member": [
                    "email-collaboration-apps"
                ]
            },
            "category": {
                "member": [
                    "any"
                ]
            },
            "destination": {
                "member": [
                    "any"
                ]
            },
            "from": {
                "member": [
                    "zone-edge1"
                ]
            },
            "hip-profiles": {
                "member": [
                    "any"
                ]
            },
            "service": {
                "member": [
                    "application-default"
                ]
            },
            "source": {
                "member": [
                    "any"
                ]
            },
            "source-user": {
                "member": [
                    "any"
                ]

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

124

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

            },
            "to": {
                "member": [
                    "any"
                ]
            }
        }
    ]
}'

Instead of using an applicaon object, you can list applicaons by name as long as the
applicaons are included in the applicaon content version installed on the ﬁrewall.

 "application": {
    "member": [
        "gmail",
        "linkedin",
        "sendgrid",
        "front"
    ]
}

Reference an Address Object in the Rule

To allow access to only speciﬁc addresses in the source zone, you can include an address object
and restrict access to only those members in the source zone with "source": {"member":
["web-servers-production"]} as shown in the following example:

curl -X PUT \
  'https://10.1.1.4/restapi/v9.1/Policies/SecurityRules?
location=vsys&name=rule-example1&vsys=vsys1' \
  -H 'X-PAN-KEY: LUFRPT=' \
  -d '{
    "entry": [
        {
            "@location": "vsys",
            "@name": "rule-example1",
            "@vsys": "vsys1",
            "action": "allow",
            "application": {
                "member": [
                    "email-collaboration-apps"
                ]
            },
            "category": {
                "member": [
                    "any"
                ]
            },
            "destination": {
                "member": [
                    "any"
                ]
            },
            "from": {

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

125

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

                "member": [
                    "zone-edge1"
                ]
            },
            "hip-profiles": {
                "member": [
                    "any"
                ]
            },
            "service": {
                "member": [
                    "application-default"
                ]
            },
            "source": {
                "member": [
                    "web-servers-production"
                ]
            },
            "source-user": {
                "member": [
                    "any"
                ]
            },
            "to": {
                "member": [
                    "any"
                ]
            }
        }
    ]
}'

If successful, the response is

{"@status": "success","@code": "20","msg":"command succeeded"
    }
}

If the address object does not exist, the response is as follows:

{"code": 3,"message": "Invalid Object","details": [
        {"@type": "CauseInfo","causes": [
                {"code": 12,"module": "panui_mgmt","description":
 "Invalid Object:  rule-example1 -> source 'web-servers-production'
 is not an allowed keyword.  rule-example1 -> source web-servers-
production is an invalid ipv4/v6 address. rule-example1 -> source
 web-servers-production invalid range start IP.
 rule-example1 -> source 'web-servers-production' is not a valid
 reference. rule-example1 -> source is invalid."
                }
            ]
        }
    ]
}

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

126

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Work with Policy Rules on Panorama (REST API)

On Panorama, you create policy rules as Pre Rules or Post Rules and then push them from
Panorama to the managed ﬁrewalls. While you can view these rules on the managed ﬁrewalls,
you can edit the Pre Rules and Post Rules only on Panorama. Pre Rules are added to the top of
the rule order and are evaluated ﬁrst, and Post Rules are added aer any locally deﬁned rules on
the ﬁrewall and are at the boom of the rule hierarchy, so they evaluated last. Post Rules typically
include rules to deny access to traﬃc based on the App-ID, User-ID, or Service. Pre Rules and
Post Rules are of two types: Shared Post Rules are shared across all managed devices and device
groups, and device group Post Rules are speciﬁc to a device group.

The example in this secon shows you how to create and update a Security policy rule on
Panorama. Use this example to get familiar with the REST API and then make it work with
other policy types on the ﬁrewall. Access the REST API reference documentaon at https://
<Panorama IP address or FQDN>/restapi-doc/ for help with the resource URIs for the
diﬀerent objects and policies and for help with the properes supported for each type of request.
For an overview, see PAN-OS REST API Request and Response Structure.

• Create a Log Forwarding Proﬁle

• Edit a Security Policy Pre Rule

Create a Log Forwarding Object

Make a POST request to create an log forwarding object that allows you to forward traﬃc and
threat logs to the Logging Service. To make this log forwarding object named log-forwarding-
LS available for all ﬁrewalls in the device group named devicegroup-7, create the object
at location=devicegroup-7. Include the name of the object, specify the locaon as
device-group and the device-group name in the query parameters location=device-
group&device-group=<dg_name>&name=<object_name>and create the request body. The
API key is provided as a custom header X-PAN-KEY.

    curl -X POST \
     'http://10.5.1.70/restapi/v9.1/Objects/LogForwardingProfiles?
name=log-forwarding-LS&location=device-group&device-
group=devicegroup-7' \
     -H 'X-PAN-KEY: LUFRPT1=' \
     -d ' {
    "entry": {
        "@name": "log-forwarding-LS",
        "match-list": {
            "entry": [
                {
                    "@name": "only_traffic_logs",
                    "filter": "All Logs",
                    "log-type": "traffic",
                    "send-to-panorama": "yes"
                },
                {
                    "@name": "only_threat_logs",
                    "filter": "All Logs",
                    "log-type": "threat",

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

127

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

                    "send-to-panorama": "yes"
                }
            ]
        }
    }
}'

You can now use this log forwarding object in a Security policy rule.

Edit a Security Policy Pre Rule

To modify a Security policy Pre Rule, make a PUT request to https://<Panorama
IP address or FQDN>/restapi/v9.1/Policies/SecurityPreRules
. The query parameters include the name of the rule, locaon and device group
name if the locaon is a device group location=device-group&device-
group=<device_group_name>&name=<rule_name>. And in the request body specify the
same name, locaon, device group name, and include the required properes for the Security
policy pre rule. This example shows you how to reference the log forwarding object you created
earlier. Refer to the REST API reference documentaon at https://<Panorama IP address
or FQDN>/restapi-doc/  for help with the required and oponal properes in the request
body.

Use a GET request to fetch the conﬁguraon of the Security policy pre rule you want to
modify and copy the response. You can then use this as a starng point for the request
body in your PUT request and modify as needed to edit the rule.

     curl -X PUT \
      'http://10.1.1.7/restapi/v9.1/Policies/SecurityPreRules?
LOCATION=device-group&device-group=devicegroup-7&name=allow-dns' \
      -H 'X-PAN-KEY: LUFRPT=' \
      -d '{
    "entry": [
        {
            "@device-group": "devicegroup-7",
            "@location": "device-group",
            "@name": "allow-dns",
            "action": "allow",
            "application": {
                "member": [
                    "dns"
                ]
            },
            "category": {
                "member": [
                    "any"
                ]
            },
            "destination": {
                "member": [
                    "any"
                ]
            },

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

128

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

            "from": {
                "member": [
                    "any"
                ]
            },
            "hip-profiles": {
                "member": [
                    "any"
                ]
            },
            "log-setting": "log-forwarding-LS",
            "log-start": "yes",
            "service": {
                "member": [
                    "application-default"
                ]
            },
            "source": {
                "member": [
                    "any"
                ]
            },
            "source-user": {
                "member": [
                    "any"
                ]
            },
            "target": {
                "negate": "no"
            },
            "to": {
                "member": [
                    "any"
                ]
            }
        }
    ]
}

The response body indicates the success or failure of the request. If you reference a Security
policy Pre Rule that does not exist because the name of the rule is invalid or the locaon is
incorrect, the response displays as

     {
    "code": 5,
    "details": [
        {
            "@type": "CauseInfo",
            "causes": [
                {
                    "code": 7,
                    "description": "Object Not Present: No object to
 edit.",
                    "module": "panui_mgmt"

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

129

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

                }
            ]
        }
    ],
    "message": "Object Not Present"
}

For help with the error codes, see PAN-OS REST API Error Codes.

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

130

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Create a Tag (REST API)

Tags allow you to group objects using keywords or phrases.

Link tags are tags that enable you use to idenfy groups of physical interfaces speciﬁcally for an
SD-WAN conﬁguraon on Panorama™. Some examples of link tags are Low Cost Paths, General
Access, Private HQ, and Backup. The following is an example of a REST API request to create a
link tag.

   curl -X POST
    'https://<Panorama>/restapi/v9.1/objects/tags?location=device-
group&device-group=SD-WAN_Branch&name=Low-Cost-Paths'
    -H 'X-PAN-KEY: <your key>
    -d '{"entry": {"@name": "Low-Cost-Paths”,
    “Comments”: “Groups two low cost broadband links and a backup
 link”
    }
    }'

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

131

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Conﬁgure a Security Zone (REST API)

Security zones are a logical way to group physical and virtual interfaces on the ﬁrewall to control
and log the traﬃc that traverses speciﬁc interfaces on your network. You must assign an interface
on the ﬁrewall to a security zone before that interface can process traﬃc. A zone can have
mulple interfaces of the same type, but an interface can belong to only one zone. You can create
zones directly on the ﬁrewall or as part of a network template on Panorama™.

The following example shows you how to use a Panorama REST API request to create a security
zone with Ethernet interfaces and a virtual SD-WAN interface. See Conﬁgure an SD-WAN
Interface (REST API) for an example of a REST API request to create a virtual SD-WAN interface
and an example of a REST API request to conﬁgure an Ethernet interface.

   curl -X POST
    'https://<Panorama>/restapi/v9.1/network/zones?
location=template&template=SDWAN-Branch-Network&name=Untrust'
    -H 'X-PAN-KEY: <api key>'
    -d '{
    "entry": {
        "@name": "Untrust",
        "enable-user-identification": "no",
        "network": {
            "layer3": {
                "member": [
                    "ethernet1/1",
                    "ethernet1/2",
                    "sdwan.1"
                ]
            }
        }
    }
}'

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

132

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Conﬁgure an SD-WAN Interface (REST API)

A virtual SD-WAN interface groups mulple physical links use to communicate with the same
desnaon.
This example shows you how to create a virtual SD-WAN interface on Panorama™. This interface
is meant for direct Internet access from a branch, so the SD-WAN interface will include only
physical Ethernet interfaces. It’s assumed that you’ve already set up necessary templates and
device groups on Panorama. The examples use a template called SD-Branch-Network.

STEP 1 | Create a link tag.

A link tag enables you use to group physical links so that SD-WAN path selecon and traﬃc
redirecon can use the groups to maximize applicaon and service quality. See Create a Tag
(REST API) for an example of an API request to create a link tag.

STEP 2 | Create an SD-WAN interface proﬁle.

Create an SD-WAN interface proﬁle to deﬁne the characteriscs of ISP connecons and
to control the speed of links and how frequently the ﬁrewalls monitors the link. This proﬁle
includes both the link tag you created and the type of link that the interface is (ADSL/DLS,
Cable modem, Ethernet, Fiber, LTE/3G/4G/5G, MPLS, etc.). The following POST request
creates an SD-WAN interface proﬁle.

      curl -X POST
       'https://<Panorama>/restapi/v9.1/network/
sdwanInterfaceprofiles?location=template&template=SDWAN-Branch-
Network&name=BroadBand-low-cost'
       -H 'X-PAN-KEY: <api key>
       -d '{
    "entry": {
        "@name": "BroadBand-low-cost",
        "comment": "Low cost",
        "failback-hold-time": 20,
        "link-tag": "Broadband-ISP",
        "link-type": "Cablemodem",
        "maximum-download": 100,
        "maximum-upload": 50,
        "path-monitoring": "Aggressive",
        "probe-frequency": 5,
        "probe-idle-time": 60,
        "vpn-data-tunnel-support": "yes"
    }
}'

STEP 3 | Conﬁgure one or more physical interfaces.

Conﬁgure the physical interface(s) that the virtual SD-WAN interface will include. This example
conﬁgures one Ethernet interface. Conﬁguring an Ethernet interface for SD-WAN involves
three steps, which are (a) conﬁgure a Layer 3 Ethernet interface without an SD-WAN interface

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

133

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

proﬁle, (b) import the Ethernet interface into a virtual system, and (c) update the Ethernet
interface to specify the SD-WAN interface proﬁle.

1. Conﬁgure a Layer 3 Ethernet interface.

The following is an example of an API request to conﬁgure a Layer 3 Ethernet interface
that uses DHCP for IP address assignment.

        curl -X POST
         'https://<Panorama>/restapi/v9.1/network/
ethernetinterfaces?location=template&template=SDWAN-Branch-
Network&name=ethernet1/4'
         -H 'X-PAN-KEY: <api key>
         -d '{
    "entry": {
        "@name": "ethernet1/4",
        "layer3": {
            "dhcp-client": {
                "create-default-route": "yes",
                "default-route-metric": 10,
                "enable": "yes",
                "send-hostname": {
                    "enable": "no",
                    "hostname": "system-hostname"
                }
            },
            "sdwan-link-settings": {
                "enable": "no"
            }
        }
    }
}'

2.

Import the Ethernet interface into a virtual system (vsys).

Make an API request on Panorama to import the Ethernet interface into a vsys
conﬁguraon. The example below imports the newly created Ethernet interface into
vsys1, which exists in template Branch_template. In this example, there is only one
interface. If other interfaces already exist in the vsys, though, include them all in the
interface member list.

        curl -X POST
         'https://<Panorama>/restapi/v9.1/device/
virtualsystems?location=template&template=SDWAN-Branch-
Network&name=vsys1'
         -H 'X-PAN-KEY: <api key>
         -d '{
    "entry": [
        {
            "@location": "template",
            "@name": "vsys1",
            "@template": "Branch_template",

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

134

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

            "import": {
                "network": {
                    "interface": {
                        "member": [
                            "ethernet1/4"
                        ]
                    }
                }
            }
        }
    ]
}'

3. Apply an SD-WAN interface proﬁle to the Ethernet interface.

The example below applies an SD-WAN interface proﬁle to the Ethernet interface to
complete the Ethernet interface conﬁguraon for SD-WAN.

        curl -X PUT
         'https://<Panorama>/restapi/v9.1/network/
ethernetinterfaces?location=template&template=SDWAN-Branch-
Network&name=ethernet1/4'
         -H 'X-PAN-KEY: <api key>
         -d '{
    "entry": {
        "@name": "ethernet1/4",
        "layer3": {
            "dhcp-client": {
                "create-default-route": "yes",
                "default-route-metric": 10,
                "enable": "yes",
                "send-hostname": {
                    "enable": "no",
                    "hostname": "system-hostname"
                }
            },
            "sdwan-link-settings": {
                "enable": "yes",
                "sdwan-interface-profile": "BroadBand-test"
            }
        }
    }
}'

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

135

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

STEP 4 | Conﬁgure a virtual SD-WAN interface.

The following is an example to conﬁgure a virtual SD-WAN interface.

1. Create a parent SD-WAN interface named sdwan if one doesn’t already exist.

The following example creates the parent interface sdwan for template SDWAN-
Branch-Network.

        curl -X POST
         'https://<Panorama>/restapi/v9.1/network/
sdwanInterfaces?location=template&template=SDWAN-Branch-
Network&name=sdwan'
         -H 'X-PAN-KEY: <api key>
         -d '{
    "entry": {
        "@name": "sdwan"
    }
}'

2. Create and conﬁgure an SD-WAN interface.

Specify one or more SD-WAN-capable Ethernet interfaces that have the same
desnaon, for example directly to the Internet. The following example creates a virtual
SD-WAN interface that has two Ethernet interfaces, including the Ethernet interface you
conﬁgured earlier.

        curl -X POST
         'https://<Panorama>/restapi/v9.1/network/
sdwanInterfaces?location=template&template=SDWAN-Branch-
Network&name=sdwan.1'
         -H 'X-PAN-KEY: <api key>
         -d '{
    "entry": {
        "@name": "sdwan.1",
        "interface": {
            "member": [
                "ethernet1/3",
                "ethernet1/4"
            ]
        }
    }
}'

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

136

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

Create an SD-WAN Policy Pre Rule (REST API)

An SD-WAN policy rule speciﬁes when and how a ﬁrewall performs applicaon-based SD-WAN
path selecon. You can conﬁgure an SD-WAN policy pre rule or post rule on Panorama™ and
push the rule to the ﬁrewalls in your device group.

The examples in this secon show how to use the REST API to create an SD-WAN policy pre rule
on Panorama. An SD-WAN policy rule includes both a path quality proﬁle and a traﬃc distribuon
proﬁle. The policy rule uses these two proﬁles to idenfy network quality requirements and to
determine path selecon when the network doesn’t meet those quality requirements.

STEP 1 | Create a path quality proﬁle.

A path quality proﬁle idenﬁes network quality or health requirements based on packet loss
percentage, jier, and latency. Once included in an SD-WAN policy rule, the path quality proﬁle
will control the threshold at which the ﬁrewall replaces a deteriorang path with a new path
for matching applicaon packets. A number of predeﬁned path quality proﬁles exist, but you
can create your own if none of the exisng proﬁles meets your needs. The following POST
request creates a path quality proﬁle called general-business2.

      curl -X POST
       'https://<Panorama>/restapi/v9.1/objects/
sdwanpathqualityprofiles?location=device-group&device-group=SD-
WAN_Branch&name=general-business2'
       -H 'X-PAN-KEY: <api key>
       -d '{
    "entry": {
        "@name": "general-business2",
        "metric": {
            "jitter": {
                "sensitivity": "medium",
                "threshold": 20
            },
            "latency": {
                "sensitivity": "medium",
                "threshold": 300
            },
            "pkt-loss": {
                "sensitivity": "medium",
                "threshold": 5
            }
        }
    }
}'

STEP 2 | Create a traﬃc distribuon proﬁle.

Create a traﬃc distribuon proﬁle, which speciﬁes how a ﬁrewall determines a new best path
if the current preferred path exceeds a path quality threshold. A traﬃc distribuon proﬁle
speciﬁes one of three possible distribuon methods: Best Available Path, Top-Down Priority,

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

137

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

and Weighted Session Distribuon. The proﬁle also includes one or more link tags, which the
distribuon method uses to narrow its selecon of a new path.

The POST request below creates a traﬃc distribuon proﬁle that uses top-down priority and
includes two link tags: Broadband-ISP and LTE-ISP. See Create a Tag (REST API) for an
example of a REST API request to create a link tag.

      curl -X POST
       'https://<Panorama>/restapi/v9.1/objects/
sdwantrafficdistributionprofiles?location=device-group&device-
group=SD-WAN_Branch&name=BroadBand2'
       -H 'X-PAN-KEY: <api key>
       -d '{"entry": {"@name": "BroadBand2","traffic-distribution":
 "Top Down Priority","link-tags": {"entry": [
       {"@name": "Broadband-ISP"
       },
       {"@name": "LTE-ISP",
       }
       ]
       }
       }
       }'

STEP 3 | Create an SD-WAN policy pre rule.

An SD-WAN policy pre rule speciﬁes applicaon(s) and/or service(s) and a traﬃc distribuon
proﬁle to determine how a ﬁrewall selects the preferred path for an incoming packet that
doesn’t belong to an exisng session and that matches all other criteria. Examples of the
criteria are source and desnaon zones, source and desnaon IP addresses, and source user.
The SD-WAN policy pre rule also speciﬁes a path quality proﬁle of thresholds for packet loss,
jier, and latency. When one of the thresholds is exceeded, the ﬁrewall selects a new path for
the applicaon(s) and/or service(s).

The POST request below creates an SD-WAN policy pre rule that Panorama will push to a
device group called SD-WAN_Branch. The request body parameters include both a path
quality proﬁle and a traﬃc distribuon proﬁle. The parameters also include Trust-PA220 and
Wireless-PA220 as the source zones and Untrust-PA220 as the desnaon zone. See
Conﬁgure a Security Zone (REST API) for an example of a REST API request to create a zone.

      curl -X POST
       'https://<Panorama>/restapi/v9.1/policies/
sdwanprerules?location=device-group&device-group=SD-
WAN_Branch&name=HQ_Service_Test'
       -H 'X-PAN-KEY: <api key>'
       -d '{"entry": {"@name": "HQ_Service_Test","from": {"member":
 ["Trust-PA220”
       ]
       },"to": {"member": ["Untrust-PA220"
       ]
       },"source": {"member": ["any”
       ]

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

138

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

       },"source-user": {"member": ["any"
       ]
       },"destination": {"member": ["any"
       ]
       },"application": {"member": ["ping"
       ]
       },"service": {"member": ["any"
       ]
       },"negate-source": "no","negate-destination":
 "no","disabled": "no","description": "For SD-WAN test","path-
quality-profile": "general-business","action": {"traffic-
distribution-profile": "BroadBand2"
       }
       }
       }'

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

139

©2022 Palo Alto Networks, Inc.

Get Started with the PAN-OS REST API

PAN-OS® and Panorama™API Usage Guide Version Version 9.1

140

©2022 Palo Alto Networks, Inc.

