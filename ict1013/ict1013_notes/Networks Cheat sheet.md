# Topic 1

## Cisco Interface Status
| Line Status / layer 1 status | Protocol Status / layer 2 status | Interface Status | Typical root cause                                                                                                                    |
| ---------------------------- | -------------------------------- | ---------------- | ------------------------------------------------------------------------------------------------------------------------------------- |
| Administratively Down        | Down                             | disabled         | interface config-ed with `shutdown` command                                                                                           |
| Down                         | Down                             | notconnect       | - No / bad cable<br>- wrong cable pinouts<br>- speed mismatch between devices<br>- device on other end is off / `shutdown` / disabled |
| Up                           | Down                             | notconnect       | interface up/down state not expected on LAN switch physical interfaces                                                                |
| Down                         | Down (err-disabled)              | err-disabled     | port security disabled the interface                                                                                                  |
| Up                           | Up                               | connected        | interface OK                                                                                                                          |
# Topic 2

### Ethernet II vs IEEE 802.3 Ethernet
| Label                                                          | Notes                                                                                                       |
| -------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------- |
| img                                                            | ![[ethernet2-vs-802_3-frames.png]]                                                                          |
| Frame Check Sequence (FCS)                                     | used for error detection                                                                                    |
| interframe gap / 96-bit idle time                              | indicate end of frame                                                                                       |
| Length / type<br><br>ethernet header: dest + src + type/length | value $\leq$ 1500 in dec = length field;<br>value > 1500 ($\geq$ 1536) = type field;    e.g. 0x0800 is IPv4 |
### Ethernet Addr
48 bits; format of XX;XX;XX;YY;YY;YY
2 fields
- Organisation Unit Identifier
	- 1st 24 bits; Issued by IEEE to ID vendor/manufacturer
- Serial Number
	- last 24 bits; uniquely assigned by vendor; ID each interface made

### Casting
| Cast Type      | Unicast                                                            | Broadcast                                                            | Multicast                                                                                                      |
| -------------- | ------------------------------------------------------------------ | -------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------- |
| Definition     | one-to-one                                                         | one-to-all                                                           | one-to-many communication, but not all.                                                                        |
| Implementation | Any addr not braodcast / multicast                                 | Ethernet addr:<br>ff:ff:ff:ff:ff:ff                                  | has a '1' at the first octet bit 0 (b0) of the OUI subfield of the Ethernet address<br>![[multicast-addr.png]] |

# Topic 3

### IP network core functions
- Addressing
	- append IP addr as part of network header to ID src and dest
- Routing
	- determine next link to forward IP packet
- Fragmentation and reassembly
	- if ip packet size \> max transmission unit (MTU) of data link layer of next forward link
		- fragment original packet into smaller fragments \< MTU
		- send out
	- net layer of dest responsible for reassembly back to original packet
Note:
de-encapsulation and re-encapsulation of the data link frame carrying the IP packet at the router is done at the data link layer of the router

| IPv4   | IPv6    |
| ------ | ------- |
| 32 bit | 128 bit |
### IPv4 header
| Name                 | Size   | Use                                                                                                                       |
| -------------------- | ------ | ------------------------------------------------------------------------------------------------------------------------- |
| VER                  | 4 bit  | - indicate IP version<br>- IPv4 = b0100                                                                                   |
| HLEN                 | 4 bit  | - indicate length of IPv4 header in multiples of 4<br>- 20 byte = 5 x 4 = 0101                                            |
| Service              | 8 bit  | support differentiated service (RFC 2474)                                                                                 |
| Total Length         | 16 bit | max size = 2^16 = 65536 bytes                                                                                             |
| Identification       | 16 bit |                                                                                                                           |
| Flags                | 3 bit  |                                                                                                                           |
| Fragmentation offset | 13 bit |                                                                                                                           |
| Time to live         | 8 bit  | - countdown to prevent packet being circulated forever<br>- value decrement by 1 for each router<br>- discard packet at 0 |
| Protocol             | 8 bit  | - indicate type of data carried<br>	- ICMP 0x01<br>	- TCP 0x06<br>	- UDP 0x11                                             |
| Header checksum      | 16 bit |                                                                                                                           |
| Source IP            | 48 bit |                                                                                                                           |
| Dest IP              | 48 bit |                                                                                                                           |
| Options              |        | - rarely used<br>- deprecated (RFC 6814)                                                                                  |
Size: 20-60 byte

### Classful addressing
| Class | type         | change                     | range                        |
| ----- | ------------ | -------------------------- | ---------------------------- |
| A     | Unicast      | 1st bit 0                  | 0.0.0.0 - 127.255.255.255    |
| B     | Uni          | 1st bit 1. 2nd bit 0       | 128.0.0.0 - 191.255.255.255  |
| C     | Uni          | 1st & 2nd bit 1, 3rd bit 0 | 192.0.0.0 - 223.255.255.255  |
| D     | Multicast    | 1,2,3 bits 1, 4 bit 0      | 224.0..0.0 - 239.255.255.255 |
| E     | Experimental | 1,2,3,4 bits 1             | 240.0.0.0 - 255.255.255.255  |

| Special ip addrs   | reserved for                                                                           | e.g.                                                                                        |
| ------------------ | -------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------- |
| 0.0.0.0/8          | indicating network / host                                                              | src addr for DHCP discover msg when host has no IP addr but needs one to send out IP packet |
| 127.0.0.0/8        | loopback addr within host                                                              | commonly used to communicate with self                                                      |
| 169.254.0.0/16     | link-local addr for OS to assign to host when fails to obtain IP addr from DHCP server |                                                                                             |
| 255.255.255.255/32 | limited broadcast addr within subnet                                                   |                                                                                             |

| Img Example of subnetting | ![[CDIR-addressing.png]] |
| ------------------------- | ------------------------ |
| hosts                     | 1000                     |
| host id                   | 10 bit                   |
| net id                    | 22 bit                   |
### Public Private IPv4 addrs
| Private ip address ranges | ![[classless-addressing.png]] |
| ------------------------- | ----------------------------- |
### Fixed Length Subnet Mask (FLSM)
| divide host number into subnet number and host number<br>                                                                                                                                                                                     | ![[subnetting-base-idea.png]] |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------- |
| network prefix + subnet number = extended network prefix                                                                                                                                                                                      | ![[subnetting example.png]]   |
| note<br>host id of all 0 is network addr to ID network<br>host id of all 1 is directed broadcast addr for that sub nets<br>limited broadcast addr = send broadcast in same subnet<br>directed broadcast addr = send broadcast to given subnet | ![[changing-subnet.png]]      |
### Variable Length Subnet Mask (VLSM)
|            | ![[vlsm-example.png]] |
| ---------- | --------------------- |
| VLSM CHART | ![[VLSM CHART.png]]   |

# Topic 4

### Hierarchical network model
| Designs                   | Img                        | Advantage                                                                          | Disadvantage                                                 |
| ------------------------- | -------------------------- | ---------------------------------------------------------------------------------- | ------------------------------------------------------------ |
| Collapsed Core design     | ![[collapsed_core.png]]    | one less machine to maintain                                                       | need to manage the connections                               |
| Three Tier                | ![[three-tier.png]]        | simplify interconnection of distribution switches<br><br>save cost on cable-laying | Requires core switch / router<br><br>device costs money lmao |
| Layer-3/Multilayer switch | ![[multilayer design.png]] | reduce device type, still keep fast switching and routing capabilities             | can be used for access if you have the \$\$\$                |
### VLAN frame
| Vlan frame part                                                                                                                                                                                                          | use                                                         |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ----------------------------------------------------------- |
| Type                                                                                                                                                                                                                     | - same as Ethernet Header field<br>- fixed hex value 0x8100 |
| Priority & flag                                                                                                                                                                                                          | - for VoIP                                                  |
| VLAN ID                                                                                                                                                                                                                  | - 12-bit<br>- decimal value range 0-4095                    |
| VLAN frames can be ID-ed by the tag portion of the frame as part of ethernet header<br><br>VLAN tag is INSERTED into ethernet frame before sending over trunk<br><br>Receiving switch removes tag before sending to dest | ![[vlan frame.png]]                                         |
### Dynamic Trunking protocol (Cisco proprietary protocol)
automates trunk negotiation between ports
- dynamic auto
- dynamic desirable

| ![[DTP layout.png]] | ![[dtp table.png]]                   |
| ------------------- | ------------------------------------ |
|                     | table is for SW1 Gi0/1 and SW2 Gi0/2 |
if Gi0/1 = trunk (not dynamic) and Gi0/2 = access, will conflict and have unexpected network connectivity issues

### Inter VLAN routing
To enable communication between VLANs, use layer 3

| Name                      | parts                                                  | Img                               |
| ------------------------- | ------------------------------------------------------ | --------------------------------- |
| Legacy inter-VLAN routing | 1 switch, 1 route                                      | ![[legacy intervlan routing.png]] |
| Router on a stick         | 1 switch 1 router<br><br>save ports, only need 1 trunk | ![[router on a stick.png]]        |
| Layer 3 switch routing    | 1 device, better performance                           | ![[layer 3 switch routinng.png]]  |

# Topic 5

## Routing Concepts
| Who host communicate to | address                                                                     |
| ----------------------- | --------------------------------------------------------------------------- |
| Itself                  | 127.0.0.0                                                                   |
| Local host              | dest addr in same VLAN w/ IP address in same Subnet ID                      |
| Remote Host             | dest addr in diff VLAN w/ different Subnet ID; need help of default gateway |
| Default Gateway         | should be router, represent route to forward to if host dk how to route     |
## Routing Table
| Routing Table Info | Network Dest / Netmask                                                                                                            | Gateway                                                                               | Interface                                | Metric                                                                          |
| ------------------ | --------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- | ---------------------------------------- | ------------------------------------------------------------------------------- |
|                    | dest network / subnet ID / dest ip addr (if mask is 255.255.255.255)<br>for matching against dest IP address inside packet header | next hop addr to send packet if matches<br>on-link means host can directly reach dest | interface of the host to send out packet | measure of relative cost of chosen interface<br>used to choose lowest interface |
net dest w/ net mask 0.0.0.0 0.0.0.0 represent default route
added into routing table only after the configuration of default gateway
### Longest Prefix Matching Rule
| Step                                                                   | Img                                   |
| ---------------------------------------------------------------------- | ------------------------------------- |
| compare dest addr against every network mask in table with bitwise AND | ![[longest-prefix-matching-rule.png]] |
| if result matches network dest of that network mask, send there        |                                       |
## Address Resolution Protocol (ARP)
| ARP Request                                                   | ARP Reply                                                           |
| ------------------------------------------------------------- | ------------------------------------------------------------------- |
| for a device broadcast query for MAC address of given IP addr | for device w/ matching IP addr to reply with corresponding MAC addr |
| ![[ARP-req.png]]                                              | ![[ARP-reply.png]]                                                  |
ARP Cache
every device has own ARP cache / mem addrs in RAM for ARP
ARP cache time / aging time tracks duration since last corresponding pair was referenced
ARP cache timer removes ARP entries that have not been used in while

| Performance trade off |                                                                                                        |
| --------------------- | ------------------------------------------------------------------------------------------------------ |
| No ARP cache          | ARP continually request address translation for each frame placed on net<br>Add latency<br>Congest LAN |
| Unlimited Hold time   | cause errors with devices that leave network / change Layer 3 addr                                     |

| ARP security risk                                           |                                         |
| ----------------------------------------------------------- | --------------------------------------- |
| ARP spoofing / poisoning                                    | Prevention of ARP poisoning             |
| technique that injects wrong MAC address association in net | Manually config static ARP associations |
| attacker forge MAC address of device                        | authorized MAC addr list                |
| frames sent to wrong dest                                   |                                         |

| ARP req/reply Packet  | Size                                                                                            |
| --------------------- | ----------------------------------------------------------------------------------------------- |
| Layer 2 dest MAC      | 6 byte                                                                                          |
| Layer 2 Sender MAC    | 6 byte                                                                                          |
| Packet type           | 2 byte;        0x0806 (ARP code)                                                                |
| Layer 3 hardware type | 2 byte        0x0001 (Ethernet code)                                                            |
| Layer 3 Protocol Code | 2 byte        0x0800 (IPv4 code)                                                                |
| Layer 3 Hardware Size | 1 Byte;        Determines size of header        e.g. ethernet header is 6 bytes so this is 0x06 |
| Layer 3 Protocol Size | 1 Byte;        Determines length of layer 3 addr        IPv4 = 4 byte so this is 0x04           |
| Op-code               | 2 Byte        0x0001 is broadcast        0x0002 is reply                                        |
| Sender MAC            | 6 byte                                                                                          |
| Sender IP             | 4 byte                                                                                          |
| Target MAC            | 6 byte;        for broadcast, is 00:00:00:00:00:00                                              |
| Target IP             | 4 byte                                                                                          
### Data Passage after ARP
| img                             | Notes                                                                                                                                                                                                                                                                                                                                                                                                                         |
| ------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| ![[data-passage-after-arp.png]] | - Data link layer provide hop-to-hop communication<br>	- header and tail only valid within 1 hop<br>	- original data link layer header and trailer will be de-encapsulated then re-encapsulated with new data link header trailer for next hop<br>- Network layer provide host-to-host comms,<br>	- ip header used to determine next route at each hop<br>	- ip header remains the same throughout all hops to reach receiver |
# OTHER

| Network # | IP Range    | Broad<br>cast | Network # | IP Range  | Broad<br>cast | Network # | IP Range  | Broad<br>cast |     | Addresses | Hosts | Netmask         | Amount of a Class C |
| --------- | ----------- | ------------- | --------- | --------- | ------------- | --------- | --------- | ------------- | --- | --------- | ----- | --------------- | ------------------- |
| /25       | 126 hosts   |               | /29       | 6 hosts   |               | /30       |           |               | /30 | 4         | 2     | 255.255.255.252 | 1/64                |
| .0<br>    | .1-.126<br> | .127<br>      | .0        | .1-.6     | .7            | .0        | .1-.2     | .3            | /29 | 8         | 6     | 255.255.255.248 | 1/32                |
| .128      | .129-.254   | .255          | .8        | .9-.14    | .15           | .4        | .5-.6     | .7            | /28 | 16        | 14    | 255.255.255.240 | 1/16                |
|           |             |               | .16       | .17-.22   | .23           | .8        | .9-.10    | .11           | /27 | 32        | 30    | 255.255.255.224 | 1/8                 |
| /26       | 62 host     |               | .24       | .25-.30   | .31           | .12       | .13-.14   | .15           | /26 | 64        | 62    | 255.255.255.192 | 1/4                 |
| .0        | .1-.62      | .63           | .32       | .33-.38   | .39           | .16       | .17-.18   | .19           | /25 | 128       | 126   | 255.255.255.128 | 1/2                 |
| .64       | .65-.126    | .127          | .40       | .41-.46   | .47           | .20       | .21-.22   | .23           | /24 | 256       | 254   | 255.255.255.0   | 1                   |
| .128      | .129-.190   | .191          | .48       | .49-.54   | .55           | .24       | .25-.26   | .27           | /23 | 512       | 510   | 255.255.254.0   | 2                   |
| .192      | .193-.254   | .255          | .56       | .57-.62   | .63           | .28       | .29-.30   | .31           | /22 | 1024      | 1022  | 255.255.252.0   | 4                   |
|           |             |               | .64       | .65-.70   | .71           | .32       | .33-.34   | .35           | /21 | 2048      | 2046  | 255.255.248.0   | 8                   |
| /27       | 30 host     |               | .72       | .73-.78   | .79           | .36       | .37-.38   | .39           | /20 | 4096      | 4094  | 255.255.240.0   | 16                  |
| .0        | .1-.30      | .31           | .80       | .81-.86   | .87           | .40       | .41-.42   | .43           | /19 | 8192      | 8190  | 255.255.224.0   | 32                  |
| .32       | .33-.62     | .63           | .88       | .89-.94   | .95           | .44       | .45-.46   | .47           | /18 | 16384     | 16382 | 255.255.192.0   | 64                  |
| .64       | .65-.94     | .95           | .96       | .97-.102  | .103          | .48       | .49-.50   | .51           | /17 | 32768     | 32766 | 255.255.128.0   | 128                 |
| .96       | .97-.126    | .127          | .104      | .105-.110 | .111          | .52       | .53-.54   | .55           | /16 | 65536     | 65534 | 255.255.0.0     | 256                 |
| .128      | .129-.158   | .159          | .112      | .113-.118 | .119          | .56       | .57-.58   | .59           |     |           |       |                 |                     |
| .160      | .161-.190   | .191          | .120      | .121-.126 | .127          | .60       | .61-.62   | .63           |     |           |       |                 |                     |
| .192      | .193-.222   | .223          | .128      | .129-.134 | .135          | .64       | .65-.66   | .67           |     |           |       |                 |                     |
| .224      | .225-..254  | .255          | .136      | .137-.142 | .143          | .68       | .69-.70   | .71           |     |           |       |                 |                     |
|           |             |               | .144      | .145-.150 | .151          | .72       | .73-.74   | .75           |     |           |       |                 |                     |
| /28       | 14 hosts    |               | .152      | .153-.158 | .159          | .76       | .77-.78   | .79           |     |           |       |                 |                     |
| .0        | .1-.14      | .15           | .160      | .161-.166 | .167          | .80       | .81-.82   | .83           |     |           |       |                 |                     |
| .16       | .17-.30     | .31           | .168      | .169-.174 | .175          | .84       | .85-.86   | .87           |     |           |       |                 |                     |
| .32       | .33-.46     | .47           | .176      | .177-.182 | .183          | .88       | .89-.90   | .91           |     |           |       |                 |                     |
| .48       | .49-62      | .63           | .184      | .185-.190 | .191          | .92       | .93-.94   | .95           |     |           |       |                 |                     |
| .64       | .65-.78     | .79           | .192      | .193-.198 | .199          | .96       | .97-.98   | .99           |     |           |       |                 |                     |
| .80       | .81-.94     | .95           | .200      | .201-.206 | .207          | .100      | .101-.102 | .103          |     |           |       |                 |                     |
| .96       | .97-.110    | .111          | .208      | .209-.214 | .215          | .104      | .105-.106 | .107          |     |           |       |                 |                     |
| .112      | .113-.126   | .127          | .216      | .217-.222 | .223          | .108      | .109-.110 | .111          |     |           |       |                 |                     |
| .128      | .129-.142   | .143          | .224      | .225-.230 | .231          | .112      | .113-.114 | .115          |     |           |       |                 |                     |
| .144      | .145-.158   | .159          | .232      | .233-.238 | .239          | .116      | .117-.118 | .119          |     |           |       |                 |                     |
| .160      | .161-.174   | .175          | .240      | .241-.246 | .247          | .120      | .121-.122 | .123          |     |           |       |                 |                     |
| .176      | .177-.190   | .191          | .248      | .249-.254 | .255          | .124      | .125-.126 | .127          |     |           |       |                 |                     |
| .192      | .193-.206   | .207          |           |           |               | .128      | .129-.130 | .131          |     |           |       |                 |                     |
| .208      | .225-.238   | .239          |           |           |               | .132      | .133-.134 | .135          |     |           |       |                 |                     |
| .224      | .225-..254  | .255          |           |           |               | .136      | .137-.138 | .139          |     |           |       |                 |                     |
|           |             |               |           |           |               | .140      | .141-.142 | .143          |     |           |       |                 |                     |
|           |             |               |           |           |               | .144      | .145-.146 | .147          |     |           |       |                 |                     |
|           |             |               |           |           |               | .148      | .149-.150 | .151          |     |           |       |                 |                     |
|           |             |               |           |           |               | .152      | .153-.154 | .155          |     |           |       |                 |                     |
|           |             |               |           |           |               | .156      | .157-.158 | .159          |     |           |       |                 |                     |
|           |             |               |           |           |               | .160      | .161-.162 | .163          |     |           |       |                 |                     |
|           |             |               |           |           |               | .164      | .165-.166 | .167          |     |           |       |                 |                     |
|           |             |               |           |           |               | .168      | .169-.170 | .171          |     |           |       |                 |                     |
|           |             |               |           |           |               | .172      | .173-.174 | .175          |     |           |       |                 |                     |
|           |             |               |           |           |               | .176      | .177-.178 | .179          |     |           |       |                 |                     |
|           |             |               |           |           |               | .180      | .181-.182 | .183          |     |           |       |                 |                     |
|           |             |               |           |           |               | .184      | .185-.186 | .187          |     |           |       |                 |                     |
|           |             |               |           |           |               | .188      | .189-.190 | .191          |     |           |       |                 |                     |
|           |             |               |           |           |               | .192      | .193-.194 | .195          |     |           |       |                 |                     |
|           |             |               |           |           |               | .196      | .197-.198 | .199          |     |           |       |                 |                     |
|           |             |               |           |           |               | .200      | .201-.202 | .203          |     |           |       |                 |                     |
|           |             |               |           |           |               | .204      | .205-.206 | .207          |     |           |       |                 |                     |
|           |             |               |           |           |               | .208      | .209-.210 | .211          |     |           |       |                 |                     |
|           |             |               |           |           |               | .212      | .213-.214 | .215          |     |           |       |                 |                     |
|           |             |               |           |           |               | .216      | .217-.218 | .219          |     |           |       |                 |                     |
|           |             |               |           |           |               | .220      | .221-.222 | .223          |     |           |       |                 |                     |
|           |             |               |           |           |               | .224      | .225-.226 | .227          |     |           |       |                 |                     |
|           |             |               |           |           |               | .228      | .229-.230 | .231          |     |           |       |                 |                     |
|           |             |               |           |           |               | .232      | .233-.234 | .235          |     |           |       |                 |                     |
|           |             |               |           |           |               | .236      | .237-.238 | .239          |     |           |       |                 |                     |
|           |             |               |           |           |               | .240      | .241-.242 | .243          |     |           |       |                 |                     |
|           |             |               |           |           |               | .244      | .245-.246 | .247          |     |           |       |                 |                     |
|           |             |               |           |           |               | .248      | .249-.250 | .251          |     |           |       |                 |                     |
|           |             |               |           |           |               | .252      | .253-.254 | .255          |     |           |       |                 |                     |


