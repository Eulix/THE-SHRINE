All work done in this mod is on lvl 5 of tcp/ip, app layer

# Chap 1

Domain Name Service (DNS)  
Translate hostname to and from IP address  
english hostname easier to remember, re-locateable, same site multiple hosts  
DNS Resolver performs 2 funcs: gethostbyname(), gethostbyaddr()

Benefits of internet  
- Fully decentralised, highly robust,
  - part of non-functioning network does not affect others  
- Information is at edge node, routing is simple, 
  - means scalable to heavy traffic  
- Low cost
  - affodable to get connected
  - pay internet service provider to connect, not other costs to end user
  - may pay for new services but not for actual internet
  - VPN allow companies to use internet to create "private" networks
- many established services
  - e.g. Wikipedia
  - e-commerce
  - services

## History of World Wide Web

1989:  
Tim Berners Lee  
English, Study in swiwstzerland
CERN
Internet active but not by everyday user  
used by companies, goverments, militaries

issues then:  
- Doc format different based on OS used  
- how to transfer document in a safe manner  
- finding / looking up things

he creates Hyper Text Markup Language 
- uses ASCII, all computers can read this text
- allows insertion of links to other documents
also creates Hyper Text Transfer Protocol
- dont need FTP and account on destination to tansfer anymore
- as long as both sides have client for http, can transfer html
also creates Universal Reasource Identifier / Universal Resource Link
- solves issue on how to find thigns

## Web Browser History / The Browser wars

1993:  
Marc Anderson + Uni students  
WWW has potential, not intuitive to use, need open terminal, type in commands, recieve only text  
making GUI web browser
"NCSA MOSAIC", closed source but free to download and use

Jim Clark, Silicon Valley, Big money  
Marc try convince Jim make better browser
jim laze, want make game
Marc convince jim  
Make netscape Communication Corp together  
Hire the students who made MOSAIC

1994:  
change name, Netscape Navigator  
marc wants mozilla, mosaic killer  
build new browser, 30 million users in a year  
treid to do free for non commercial, 30usd for commercial  
didnt last, competition  
switched to selling servers or email services  

1995:  
Netscape IPO
microsoft makes IE, and win95 lmao  
cucks Netsccape  
IE was better performance  
Netscape cross platform yes, but also means cannot enhance netscape for only one platform, must enhance for all


## Components of WWW

Uniform Resource Identifier / Link (URI URL)
Hypertext Markup Language (HTML)
Hypertext Transfer protocol (HTTP)

## Web Browser


## Internet VS Web

internet is all forms of digital communication between commputers
Web is just 1 protocol that uses the internet

### Circuit Switched Networks
- telephone calls physically connected caller and receiver on a switchboard
- ineffecient use of bandwidth
- hard to scale

### Packet switched networks
- Came later
- does not need continuous connection
- types:
	- 1960s ARPANET  
	- 1974 X.25  
	- 1979 USENET  
	- 1981 TCP/IP was introduced to unify disparate network
	
## Web Apps VS Desktop Apps

| Advantage                                                                            | Disadvantage                                                               |
| ------------------------------------------------------------------------------------ | -------------------------------------------------------------------------- |
| can be accessed from any internet-enabled computer                                   | Need active internet connections                                           |
| different OS / browser ok                                                            | Security concern about sensitive data transmitted over internet            |
| easier to roll out program updates since software serverside rather than client side | Concern on storage / use / Licensing of uploaded data                      |
| Centralised storage, fewer security problem                                          | websites do not have identical appearance across all browsers              |
|                                                                                      | Restrictions on software from being installed and hardware being accessed  |
|                                                                                      | additional plugins may interfere with javascript, cookies or advertisments |

## HTML 5

Why use proper semantic elements?
ans: acessability, web scraping

Semantic tags give meaning to the machine maybe the dev a bit
E.g.
putting \<figure> and \<figcaption> tags makes it easier for accessibility machines to understand whats important

## What is HTML

Language made to standardize document styles and data format to allow adoption of accompanying HTTP and URI/URL

## Goal of HTML

| Improve Native Web                                                                                                                  | Do more with less code                                                                                                                                                                                                                                    | Realize Semantic Web                                                                       |
| ----------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------ |
| HTML 5 added syntactic features to web that previously needed plugins to work<br><br>e.g. \<audio>, \<video> and \<canvas> elements | simplify common design patterns (and more) by creating standardized ways to do in HTML alone no plugin<br><br>- e.g.<br>		- placeholder text in forms<br>		- autofocus on particular input element<br>		- client-side validation<br>		- date time pickers | Semantic Web refers to content that is readable and meaningful to both humans and machines |
| Enables richer desktop-like experience                                                                                              |                                                                                                                                                                                                                                                           |                                                                                            |

To make it easier to find and access documents on the internet

## Basic HTML syntax and document Structure

## Elements & attributes
element is part of web page, 
attributes are specific settings like the src in the img tag

### Nesting Elements
allows for things like clickable links

## Character Entities
allows display of special chars that could be interpreted as code
e.g. <> is html code but to display you need @lt; and @gt; to print
all char entities must start with @ and end with ;
## Images and links
Named anchors starts with a \# in the \<a href> tag
Scrolls down to element with given ID in same page

figure does not just have to be image, can be graphs and shit
alt tag in \<img> element is what is displayed when browser setting does not load images
title tag in \<img> element is what is displayed when mouse hover over image

## Semantic Markup

### What

### Why


## Header & Footer
Is semantic element for machines to understand and maybe skip
Also for styling


## Navigation


## Section & Articles


## Shld we still use div?
Can still use for styling


# Chap 2 CSS & Bootstrap

Responsiveness != Responsive Design

Responsive Design is to adjust the website to cater to different browsers with things like bootstrap

## CSS : Cascading Style Sheets

CSS is a styling language
HTML is a markup / positioning language (position elements on page)
### CSS Rule Sets
Always consists of the below 3 things
#### Selector
- Selects the type of tag or ID or class or element name
	- e.g.
	- section {}
	- figcaption {}
	- \#dogs {} ; ID
	- \. cats {} ; class
- Class selector will attempt to apply the given property to any tags with the given class
	- e.g.
	- \<p> and \<h1> can both have same class and therefore same color
	- \<img> may have same class as \<p> \<h1> but may not have the color property
- ID and Class allow application to multiple types of elements
	- Class meant to apply to multiple elements (may be of varying types) regardless of position in document tree
	- ID meant to apply to single element regardless of position in docuent tree
	- both can be used across pages
- May have sub tags
	- e.g.
	- section h2{}
	- h2 is the sub selector
	- this means all h2 tags within the section tags
- Attribute Selector
	- select HTML elements by presence of element attribute / value of attribute
	- e.g. style hyperlinks
	- can combine with ID and class selector
	- uses square brackets
- Pseudo element selector

|             | Matcher                                                                                                          | Example                                                                                                                          |
| ----------- | ---------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------- |
| []          | a Specific attribute                                                                                             | [title] Matches any element with a tiltle attribute                                                                              |
| [=]         | a specific attribute with a specific value                                                                       | a[title="posts from this country"]  <br>Matches any \<a> element whose title attribute is exactly “posts from  <br>this country” |
| [~=]        | A specific attribute whose value  <br>matches at least one of the words in a  <br>space-delimited list of words. | \[title~="Countries"]  <br>Matches any title attribute that contains the word “Countries“                                        |
| \[^=]  <br> | A specific attribute whose value begins  <br>with a specified value.  <br>a\[href^="mailto"]                     | Matches any \<a> element whose href attribute begins with “mailto“                                                               |
| \[*=]       | A specific attribute whose value  <br>contains a substring.                                                      | img\[src*="flag"]<br>Matches any \<img> element whose src attribute contains somewhere  <br>within it the text “flag             |
| \[$=]       | A specific attribute whose value ends  <br>with a specified value                                                | a\[href$=".pdf"]  <br>Matches any <a> element whose href attribute ends with the text “.pdf“                                     |

#### Property
- Changes the property/characteristic of the selected element
	- e.g.
	- figcaption {color: "darkslategray;}
- 1 ruleset can have as many properties as you want

#### Value
- Value of property
- datatype is dictated by the property
	- e.g. color property can take string or hex (rgb color)
- special tag !important will FORCE the value regardless of position in the cascade (e.g. in external but bootstrap has own value for this property)
	- be careful when using

### Including CSS in HTML
order of application
external > internal > inline

this means
- inline settings will override all other settings
- internal will override external

Creating an external stylesheet allows you to write once and apply many times so all your pages look the same

internal is used when one specific page needs additional styles

Generally avoid inline as have to scroll to specific element to edit

#### External
- Write in .css file and include with \<link> tag
- e.g. 
	- \<link rel="stylesheet" href="css/main..css">
- Since HTML reads top to bottom, take care to link the stylesheets in the correct order
	- e.g.
	- bootstrap first
	- then own stylesheet

#### Internal (aka Embedded)
- Writing styles directly into html file with \<style> tag

#### Inline
- Writing styles into individual tags
	- e.g.
	- \<h1 style="color: green">
- inline overrides both external and internal

## BootStrap

### Intro to framework and Boootstrap

- Is a CSS framework lol
- Open source n free
- is basically a large amount of classes that you can apply to all your elements

### Responsive Design
- as you resize the website, the website should reformat and still look nice
- that is responsive design

### Including Bootstrap in HTML

### Bootstrap Grid System

### Jumbotron
- Title replacement
- Looks like the Giant TV screens in football stadiums i.e. THE jumbotron
- probably only used on main page

### Navigation Menu
- should be replicated on all pages

### Misc. Bootstrap Features


# Chap 3 JavaScript

## Intro to JS

### History

Servers used many languages
- ASP
- PHP
- PERL
all serverside, needed send post req to use

Made demand for client side script, running on browser

attempts:
- java applets
	- not good due to lack of control over access to machine
- active X
- plugins

want somethin 
- interpreted
- fast

Brenden Eich - worked at netscape later founded mozilla
wrote the basics of javascript
Sun Oracle, owner off Java name, suggested naming it Javascript, as it was a "we-hate-microsoft" together phase
so its not really related to Java, more related from C

IEEE has a specific name for Javascript as it is official but everyone calls is js lol

wont talk much about XML or JSON in the course but can use in project if you want

Java using var for all variables makes it prone to error if you dont handle the type of your variables well

Does not cascade / overwrite like css when having same function / variable name

Script tag does not have to be in header like style tag
Can be put at bottom of body, ensures script is only loaded when whole page is loaded
Location in code does matter since loading still loads from the top down

Now can just use defer tag in the script tag, rather than having to place it 

Or have a onload code in js to only add listeners when page fully loaded

or async, which implies your JS is all functions that do not require any information from the page and can be loaded before page is fully loaded
### Event Handling

Inline js is not secure, pls dont use

need to initialize listeners on load
make init function and add listeners for different things like banner or each caption


### Debugging

Use breakpoints

alt is like alt name for this specific tag, its like ID

### Advantages & Disadvantages of Client-side scripting
Advantages
- processing offload to client, reduce load on server
- browser responds rapidly to user events; improve user experience
- JS interact with HTML in a way that server cannot

Disadvantages:
- Client can disable to code, or admins can turn off js with policy
	- Means functionality req redundancy on server
- JS heavy web apps are complicated; hard to maintain
- Not fault tolerant
	- Will cease execution on invalid line
- Java script constantly being worked on, newer features may not be supported on all browsers

## Document Object Model (DOM)

Each tag is an element and becomes and object when the page is loaded

open using F12 inspect, elements tab

## JavaScript Libraries & frameworks

- Bootstrap JS
- jQuery
- Ajax
	- out of fashion, FetchAPI (2015) gaining popularity
- JSON
- Typescript


## TypeScript


# Chap 4 Web Accessibility and testing

## W3C Web accessibility Initiative

pre 2000
IE and netscape fighting, didnt care for standardisation
Developers  have to cook up funky javascript for netscape or for IE
Webpages may not work the same on diff browsers


- W3C overview
	- Who governs web
		- is the body set standands for browser maker and developers to follow
		- if both follow standard, all browsers work with all pages
- Web Standards
- Validating Web Pages
	- W3C Markup validation service
	- made to promote / make easier for people to follow the standard
	- can take public domain names
	- can take source code

## Web Content Accessibility
- Four principles (POUR)
	- Perceivable
		- Provide Text alternative for non-text content
		- Provide captions & other alternatives for multimedia
		- Create content that can be presented in different ways including assistive technologies w/o losing meaning
		- Make it easier to see and hear content (e.g. font size)
	- Operable
		- Make all functionality available from keyboard
		- Give users enough time to read and use content
		- Do not use content that can induce seizures or physical reactions
		- Help users navigate and find content
		- Make it easier to use inputs other than keyboard
	- Understandable
		- Make text readable / understandable
		- Make content appear and operate in predictable ways
		- Help users avoid and correct mistakes
	- Robust


## Accessibility Testing Tools
- deque's axe browser plugin
- used to test website for WCAG POUR

# Chap 5 Serverside web dev PHP

Some servers only return files  e.g, send html then .css then .js
those do not process any logic, all done by browserr software

Extensions that use php files require server to process logic as browser does not have ability to process raw php file
so server processes logic and makes / fetches correct html andor css andor js

advantage
- secret / security 
- cross platform compatibility (php chooses correct format to display)
- access to server-side resources like database
- works even if js disable by client, php always runs as is on server
disadvantage
- increased response time / latency may become an issue
- server requiers more processing power
- more work required serverside / more overhead serverside
- little bbit arcer to debug

75% of pages in world use php
- wordpress and wooCommerce use php thats why

php made from perl made from C so similar syntax, easier to learn
php has many existing examples, easy to find examples or implementations