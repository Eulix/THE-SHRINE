
Lab Laptop  
Username: sitstudent  
pw: Student@sit

Steps to power on
1. 2x Red button at back, on both
2. Wait for boot
3. for rack equipment, when asked if want to enter initial configuration dailog; do not enter
4. Use 'Student@s1t' as password for rack equipment
5. When asked to save config, choose option\[0] to go to IDS without saving
6. Once "switch #" appear, ready to go
Dont change the password for the cable locker

2 Firewall
1 server
2 Router
2 Distribution Switch / Layer 3 Switch
4 Layer 2 Switch
## Lab1

### 2.6
Application:  Hypertext Transfer Protocol
Transport:  Transmission Control Protocol, Src Port: 58774, Dst Port: 80, Seq: 1, Ack: 1, Len: 478
Network:  
Data Link:



## Lab2

2.11
What version of Cisco IOS - 17.12.04
What system image filename - Cisco ISO EX
What problem encountered when 'show running-config' - cannot run
Can you use 'enable' can you  'show running-config' - can run

user mode -- enable --> enable mode -- Configure teminal --> config mode
config mode -- end/ctrl+z --> enable mode -- disable --> user mode

config mode -- interface *type/number* --> Interface mode
config mode -- vlan *x* --> vlan mode
config mode -- line console 0 --> Console mode
config mode -- line vty 0 15 --> VTY line mode

Switch 1

| interface | Line status | Protocol status | interface status |
| --------- | ----------- | --------------- | ---------------- |
| G1/0/6    | up          | up              | connected        |
| G1/0/24   | up          | up              | connected        |


Switch 2

| interface | Line status | Protocol status | interface status |
| --------- | ----------- | --------------- | ---------------- |
| G1/0/18   | up          | up              | connected        |
| G1/0/24   | up          | up              | connected        |

OUI portion of MAC address of PC A NIC (first 3 set f hex) - 74-D4-DD
OUI portion of MAC address of PC A NIC (last 3 set f hex) - 81-5C-4B
Vendor - _Quanta Computer Inc_.

OUI portion of MAC address of PC B NIC (first 3 set f hex) - 74-D4-DD
OUI portion of MAC address of PC B NIC (last 3 set f hex) - 81-5C-4A
Vendor - _Quanta Computer Inc_.


base Ethernet MAC address of your switch SW1 - b0:8d:57:73:d6:80

MAC address for port G1/0/6 on your switch SW1 - b0:8d:57:73:d6:86

MAC address for port G1/0/24 on your switch SW1 - b0:8d:57:73:d6:98

base Ethernet MAC address of your switch SW2 - b0:8d:57:73:b6:00

MAC address for port G1/0/18 on your switch SW2 - b0:8d:57:73:b6:12

MAC address for port G1/0/24 on your switch SW2 - b0:8d:57:73:b6:18

deduction: each port address is \[add port number to base ethernet address]

What is the MAC address ffff.ffff.ffff used for?  
What type of MAC address does 0180.c200.0000 belong to? What is it used for?
local mac addresses
belong to switch
are multicast addresses for services
this specific one is Spanning Tree Protocol

List down the dynamically learned MAC addresses and the corresponding ports on SW1.  
- 74d4.dd81.5c4b
- b08d.5773.b618
list down the dynamically learned MAC addresses and corresponding ports on SW2.  


3.7 Are you able to explain how the switches dynamically learned these MAC addresses?
enter the command clear mac address-table dynamic. 

When recieve packers from port, dynamically learn and record down

Immediately, enter the show mac address-table dynamic command again.  
What do you observe?

now info updated after new packets

Highlighted bytes corresponding to Ethernet II:
74 d4 dd 81 5c 4a 74 d4 dd 81 5c 4b 08 00

Highlighted bytes corresponding to Destination:  
74 d4 dd 81 5c 4a

Highlighted bytes corresponding to Source:
74 d4 dd 81 5c 4b

Highlighted bytes corresponding to Type:
08 00

represents that is ping request

need for type field to determine protocol

## Lab 3

Router commands
- show
	- version - display os version
	- running-config - display current running config
	- ip interface brief
- enable - enable mode
- hostname - change hostname
- no ip domain lookup - disable dns


## Lab 4

in enable mode
- show interfaces
	- trunk - show trunking interfaces and allowed vlans
in config mode
- vlan \[ID num] - create new vlan with id \[ID num]
- name \[string] - name current vlan with \[string]; if last cmd was vlan 10, next name will name vlan 10
- no vlan \[ID num] - removes vlan \[ID num] from vlan interface
in interface config for specific port (e.g. g1/0/06 or range g1/0/11-24)
- switchport 
	- mode
		- access - statically disables trunking on the port(s), default mode is dynamic trunk
			- access vlan 10 - changes port(s) to only allow access to vlan 10; using no before this changes access vlan to default vlan (does not require vlan num)
		- trunk - statically changes mode to trunk; default trunking mode is  auto
			- trunk allow vlan - allows trunk to use vlan
- no shut - changes interface status to up
- switchport mode dynamic negotiate - switches port mode to dynamic trunk negotiate (default is auto)
- switchport trunk - allows vlan access to trunk but  like how tho????

note 
- before removing vlan from database, recommended reassign all ports in that vlan
- dynamic trunking protocol allows port to negotiate trunk mode, but it waits for others to initiate



can pc a ping pc b - yes
can pc a ping pc c - no
can pc b ping pc c - no

if no why
because default gateway is 192.168.10.1, so cannot ping 192.168.20.3
diff subnet

what is default vlan
vlan 1

what ports assigned to default vlan
g1/0/1-24   g1/1/1-4

can pc a ping pc b after assigning pc a to vlan 10
no lol
diff vlan not allowed to send frames across

which vlan is port 24 associated with after changing vlan
vlan 20 faculty

what is default name of lan 30? - vlan0030

after 'no switchport access vlan' to g1/0/24, which vlan is g1/0/24 assigned to? - defualt vlan

if delete vlan while port associated with it, port will not be associated with ANY vlan

after trunk enable

pc a to pc b - yes
pc a to pc c - no
pc b to pc c - no

Why might you want to manually configure an interface to trunk mode instead of using DTP?
not all equipment uses dtp, dtp is cisco only

Reflection  
1. What is needed to allow hosts on VLAN 10 to communicate to hosts on VLAN 20?  
	- trunk port
2. What are some primary benefits that an organization can receive through effective use of VLANs?
	- sectioning off different groups to improve network performance

legacy routing
a. On R1, issue the show ip route command. What routes are listed on R1?  
192.168.10.0 - 192.168.10.1
192.168.20.0 - 192.168.20.1

b. On both S1 and S2, issue the show interface trunk command. Are both S1  
G1/0/1 and S2 G1/0/1 ports set to trunk?
yes

c. Issue a show vlan brief command on both S1 and S2. Verify that VLANs 10  
and 20 are active and that the proper ports on the switches are in the correct  
VLANs. Why is S1 G1/0/1 and S2 G1/0/1 not listed in any of the active  
VLANs?  
they are trunks not part of vlan

d. Ping from PC-A in VLAN 10 to PC-C in VLAN 20. If inter-VLAN routing is setup  
correctly, the pings between the 192.168.10.0 network and the 192.168.20.0  
should be successful.  
Note: It may be necessary to disable the PC firewall to ping between PCs.  
yes

e. Verify connectivity between devices. You should be able to ping between all  
devices. Troubleshoot if you are not successful.
ok done

Reflection  
- What is an advantage of using legacy inter-VLAN routing?
	- ease of configuration.

router on stick
a. Enter the command to view the routing table in R1. What networks are  
listed?  
192.168.10.0/24 - 192.168.10.1/32
192.168.20.0/24 - 192.168.20.1/32

b. From PC-A, is it possible to ping the default gateway for VLAN 10?  
yes

c. From PC-A, is it possible to ping PC-C?
yes

What is the advantage of trunk-based or router-on-a-stick inter-VLAN routing?
less machines to maintain, all configs on one device


a. Enter show ip route command to view the routing table in S3. What networks  
are listed?  
192.168.10.0/24 - 192.168.10.1/32
192.168.20.0/24 - 192.168.20.1/32

b. From PC-A, is it possible to ping the default gateway for VLAN 10?  
yes

c. From PC-A, is it possible to ping PC-C?
yes

# Lab 5

What command would be used to display all entries in the ARP cache?  
arp -a / arp -g
What command would be used to delete all ARP cache entries (flush ARP cache)?  
arp -d \*
What command would be used to delete the ARP cache entry for 192.168.1.11?
arp -d 192.168.1.11

What command would be used to add the ARP cache entry for 192.168.1.11 w/ mac address xx-xx-xx-xx-xx-xx to interface 192.168.1.3?
arp -a 192.168.1.11 xx-xx-xx-xx-xx-xx 192.168.1.3

What is the physical address for the host with IP address of 192.168.1.2?
74-d4-dd-81-5c-4b

Record the physical address for switch S2
192.168.1.12        b0-8d-57-73-b6-47

| 1st ARP packet | Field           | Value             |
| -------------- | --------------- | ----------------- |
|                | Sender MAC addr | 74:d4:dd:81:5c:4a |
|                | Sender IP addr  | 192.168.1.3       |
|                | Target MAC addr | 00:00:00:00:00:00 |
|                | Target IP addr  | 192.168.1.1       |
| 2nd ARP packet | Field           | Value             |
|                | Sender MAC addr | 60:b9:c0:3e:7b:c1 |
|                | Sender IP addr  | 192.168.1.1       |
|                | Target MAC addr | 74:d4:dd:81:5c:4a |
|                | Target IP addr  | 192.168.1.3       |
ARP of own interface will never have an age

# Lab 6
## Part a

PagP cmds

channel-group \[n]
- mode
	- auto
	- desirable
show
- run
	- interface \[inteface id]
- interface \[interface id] switchport
- etherchannel summary
interface
- port-channel \[id]

LACP cmds
channel-group \[n]
- mode
	- active
	- passive

What do the flags, SU and P, indicate in the EtherChannel summary?
SU is combination of S and U, S shows is "layer 2", U shows is "up/in use"
P is to show that the interfaces are part of the bundle

Issue the show run interface interface-id commands on SW1 and DSW1 for interfaces G1/0/3, G1/0/4 and Po1.
What commands are added for G1/0/3 and G1/0/4 on both switches?
What command is added for the Po1 interface? Record your observation.

G1/0/3
interface GigabitEthernet1/0/3
switchport mode trunk
channel-group 1 mode desirable
end

G1/0/4
interface GigabitEthernet1/0/4
switchport mode trunk
channel-group 1 mode desirable
end

Po1
interface Port-channel1
switchport mode trunk
end

Issue the show interfaces trunk command on SW1 and DSW1.
What trunk port is listed?    -    Po1
What is the native VLAN?    -    Vlan 1

What protocol is Po2 using for link aggregation?    -    LACP
Which ports are aggregated to form Po2?    -    Gi1/0/1 and Gi1/0/2
What command did you use to verify?    -    show etherchannel summary

What could prevent EtherChannels from forming?
- incorrect trunk mode
- channel-group mode

## part b

What does the flag RU indicate in the EtherChannel summary?
R = layer 3
U = Up/is running

## part c

Spanning tree cmds

spanning-tree
- vlan \[id]
	- root
		- primary
		- secondary
	- priority
		- 0 - 61440, multiples of 4096

show
- spanning-tree
	- vlan \[id]
		- bridge


what are their BIDs
DSW1 - 24577 <24576, 1> 70da.48fb.fd80
DSW2 - 28673 \<28672, 1> 70da.48fb.3f80
SW3   - 32769 \<32768,1> b08d.576e.7e80


which switch is the root bridge/switch? - DSW 1
Why? - lowest priority, therefore root
DSW2, which is the root port and what is the root path cost? - root port is Gi1/0/1 and root cost is 20 000.
Why is this port the root port? - first port in ether channel that connects to root
SW3, which is the root port and what is the root path cost? - root port is Gi1/0/5 and root cost is 20 000.

Derive theoretically the minimum interface cost to be configured on SW3 root port in  
Step 2.2 so that its root port role will be removed.
theoretically just need to be higher than total cost of the alternate route, probably should be in according to Spanning-tree port cost table, 40001

Is the root port role in Step 2.2 being removed a6er Step 2.4?
- yes has changed to port gi1/0/3

Which is the new root port ion SW3 and what is the root path cost after changing cost?
- gi1/0/3
- cost 40000

Which is the new root port ion SW3 and what is the root path cost after changing DSW2 g1/0/4 priority?
- gi1/0/4
- cost 40000

Which tie-breaker rule is being applied now?
- lowest port priority

show spanning-tree vlan 1 on access switch SW3. Which are the designated ports and alternate (blocked) ports?
desg port: 
- g1/0/18
altn port:
- g1/0/3
- g1/0/5

Why are these ports designated or alternate (blocked)?


show spanning-tree vlan 1 on DSW2. Which are the designated ports and alternate (blocked) ports?
root port:
- g1/0/1
desg port: 
- g1/0/3
- g1/0/4
- g1/0/18
altn port:
- g1/0/2

Observe the LED status lights on the ports of DSW1, DSW2 and SW3.
Are there any lights that are amber? Why?
- ports 3 & 5 on SW3
- port 2 on DSW2
- reason
	- these are alternate ports

What is the destination MAC address of the BPDUs captured at PC-A, PC-B, PC-C?
- PC-A
	- Nearest-Customer-Bridge for Standard STP / RSTP / MSTP
		- uses addr code: 01:80:C2:00:00:00
- PC-B
	- Nearest-Customer-Bridge for Standard STP / RSTP / MSTP
		- uses addr code: 01:80:C2:00:00:00
- PC-C
	- Nearest-Customer-Bridge for Standard STP / RSTP / MSTP
		- uses addr code: 01:80:C2:00:00:00

What class of address does the MAC address in Step 4.3 belongs to? 
- multiclass

Where will the switches forward the BPDUs to?
- forward to designated port
- if unavailable, will select new designated port from alternates

How does Wireshark know that the BPDU frames are encapsulated in IEEE 802.3 instead of Ethernet II?
- ethertype field is greater than max_val of 1536, which implies it is not ethernet II protocol
- then reads this field as part of Logical-Link Control sections with DSAP, SSAP and control,
- it declares the usage of BDPU

On PC-A, PC-B and PC-C, what are the root IDs of the captured BPDU?
- PC-A
	- root id
		- 24576 / 1 / 70:da:48:fb:fd:80
- PC-B
	- root id
		- 24576 / 1 / 70:da:48:fb:fd:80
- PC-C
	- root id
		- 24576 / 1 / 70:da:48:fb:fd:80

On PC-A, PC-B and PC-C, what are the root IDs of the captured BPDU?
- PC-A
	- bridge id
		- 24576 / 1 / 70:da:48:fb:fd:80
- PC-B
	- bridge id
		- 28672 / 1 / 70:da:48:fb:3f80
- PC-C
	- root id
		- 32768 / 1 / b0:8d:57:6e:7e:80

Are the bridge IDs the same as root IDs in the BPDUs captured at PC-A, PC-B and PC-C?  
Why?
- PC-A
	- yes, is root
- PC-B
	- no, is connected to DSW2, which is nearest bridge
- PC-C
	- no, is connected to SW3, which is nearest bridge

What are the root path cost in the BPDUs captured at PC-A, PC-B and PC-C? Why?
- PC-A
	- 0, is root
- PC-B
	- 20000, 20k from DSW1 to DSW2
- PC-C
	- 40000, 20k from DSW1 to DSW2, 20k from DSW2 to SW3

What are the port priorities in the BPDUs captured at PC-A, PC-B and PC-C? Why
- PC-A
	- 0x8006
	- prio 128
	- port 6
	- direct conneection to root
- PC-B
	- 0x8012
	- prio 128
	- port 12
	- to bridge
- PC-C
	- 0x8012
	- prio 128
	- port 12
	- to bridge