# OwO Linux quick shit

. is current dir  
.. is one dir higher / previous dir  
~ is HOME dir of user  
/ is root dir of whole system  
/home/sysadmin is a ABSOLUTE PATH  
documents/School/art is a RELATIVE PATH (cus dont start with root /)  
cat food.txt > newfile1.txt;    will write output of cat cmd to newfil1.txt, overwriting content
cat food.txt >> newfile1.txt;    will write output of cat cmd to newfil1.txt, appending content
## commands n shit  

ls - list available dirs
pwd - **P**rint current **W**orking **D**ir
cd - **C**hange **D**ir
su - **S**uper **U**ser  
exit - exit su mode
sudo - **S**uper **U**ser **DO**  
chmod - **Ch**ange **mod**e or access (perms)  
chown - **Ch**ange **own**er  
cat - con**cat**enate, show entire contents of file, shld use on smaller file only
head - display first 10 lines of file
tail - display last 5 lines of file
cp - **copy** file
dd - bit level copy
mv - move file
rm - remove file; is permenant, no trash can
grep - search func for file contents
shutdown - prep device for shutdown
date - show date in format \[weekday month day hour:minute:second UTC year]
ifconfig - **I**nter**f**ace **config**; as in network interface
iwconfig - wireless Interface config; as in wireless network interface
ps - see processes, like task manager
apt-get update - update known list of packages and their versions
apt-cache search  - search known list for package name
apt-get install  - install package
apt-get upgrade  - update all packages and dependencies to latest version given by known list
apt-get remove  - uninstall package, leave config files
apt-get purge  - uninstall package and delete config files
passwd - update password
echo - print argument to terminal, can combine with > redirection to write to files

vi - atas, premier editor, pronounced *vee eye* btw {src: netdevgroup Linux Unmatched ccourse}
nano - tiny editor
vim - as in vi improved

vi pros:
- available on all Linux distros
- has CLI and GUI
- core funcs from 1970 with new features added, old fogies also can use
### Options for commands
| opt                          | what                        | deets                                                                             |
| ---------------------------- | --------------------------- | --------------------------------------------------------------------------------- |
| [ls] -l                      | **L**ong                    | lists **full deets** like rwx of files n shit                                     |
| [ls] -r                      | **R**everse                 | used to reverse the listing of shit                                               |
| [ls] -t                      | **T**imestamp               | sort by timestamp                                                                 |
| [ls] -s                      | **S**ize                    | sort by size                                                                      |
| [su] - / -l / --login        | **L**ogin                   | require login to fully configure new shell settings with settings of the new user |
| [head/tail] -n *someInteger* | **n**umber of lines to show |                                                                                   |
| [rm] -r / -R                 | recursive delete            | used to delete dirs, will delete all files and subdirs inside                     |

### Combined nonsense
|opt|what|deets|
|-|-|-|
|-lr / -rl|reverse & long|combine them chiggas|

### ls output breakdown

| file type | perms for OWNER | perms for GROUP | perms for OTHER | Hard links count | User owner |Group owner| File Size (Bytes) | date time | File name | [optional] link destination|
|-|-|-|-|-|-|-|-|-|-|-|
|d|rwx|r-x|r-x|2|root|root|4096|Apr 11  2014|upstart||
|-|rw-|r-|---|1|syslog|adm|1346|Oct  2  22:17|auth.log||
|l|rwx|rwx|rwx|1|root|root| |Nov  6  2012|/etc/grub.conf|-> ../boot/grub/grub.conf|


**Note**:  
Dirs and larger files ay be shown in Kb since Bytes is damn big  
OR  
Sometimes Dirs file size is in Blocks sincce Block size is size of seriese of data stored in file system  

When Dirs have r and not x perms, non-detailed listing  
When have r and x perms, detailed listing  
Dirs must have x to have w perm  
x perm allows user to chang dir if parent dir have x perm as well

### RWX perms  

|d|r|w|x|r|w|x|r|w|x|
|-|-|-|-|-|-|-|-|-|-|
|File type|-|Owner rwx perms|-|-|Group rwx perms|-|-|Others rwx perms|-|

### File type type shit

|Symbol|File type|Description|
|-|-|-|
|d|directory|File that stores other files|
|-|regular file|Inclds: readable files, img files, binary files, compressed files|
|l|symbolic link|Points to another file, like a Shortcut|
|s|socket|Allows for communicaiton between processes|
|p|pipe|Allows for communicaiton between processes|
|b|block|Used to communicate with hardware|
|c|character file|Used to communicate with hardware|

### chmod  deets

chmod \<SET\> \<ACTION\> \<PERMISSIONS\> \[options] FILE 

SET; set for who

|Symbol|Meaning|
|-|-|
|u|User; owner of file|
|g|Group; group that own file|
|o|Others; others that is not owner or in group|
|a|All; lmao|

ACTION; do what to existing perms

|Symbol|Meaning|
|-|-|
|+|Add this perm, if necessary|
|=|Set to this exact set of perms|
|-|Remove this perm, if necessary|

PERMISSIONS; perms

| Symbol | Meaning |
| ------ | ------- |
| r      | read    |
| w      | write   |
| x      | execute |

### Copy files deets

cp \[OPTIONS] SOURCE DESTINATION

SOURCE is a relative / absolute filepath to a file
DEST is a relative / absolute filepath to a dir,

to copy need:
	exec perms for SRC **DIR**  
	read perms for **actual file**
	write & exec perms for DEST **DIR**

can also copy with:

dd [OPTIONS] OPERAND

| operands | Definition                                                                                                                                     |
| -------- | ---------------------------------------------------------------------------------------------------------------------------------------------- |
| if       | input filepath                                                                                                                                 |
| of       | output filepath                                                                                                                                |
| bs       | block size; default is byte size, use suffix K,M,G,T for kilo, mega, giga, tera,<br>e.g. bs = 1M<br>if omit & omit count, will copy whole file |
| count    | numer of blocks to read from input file<br>if omit & omit bs, will copy whole file                                                             |

### Move file deets

mv \[OPTIONS] SOURCE DESTINATION

SOURCE  is a relative / absolute filepath to a file
DEST is a relative / absolute filepath to a dir **OR** file,

NOTE:
mv needs write exec perms at SRC and DST

### Remove file deets

rm \[OPTIONS] FILE/DIR

require write exec perms in that dir

### GREP
get a grep on things

grep \[OPTIONS] PATTERN \[FILE]

FILE can be file in current dir or filepath

finds the PATTERN in FILE, prints entire lines with said pattern found 
when using REGEX in pattern, wrap in single quote ' ', aka strong quotes

if FILE not give, grep will read standard input in cmd line

OPTIONS:
-E for extended regex
### REGEX

| Basic Regex Character(s) | Meaning                                                                                                                                                                   |
| ------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `.`                      | Any one single character                                                                                                                                                  |
| `[ ]`                    | Any one specified character OR Any one of the specified chars in range.<br>e.g. [0-9], [oe]<br>[oe] basically is a list of specified chars, so will search for 'o' OR 'e' |
| `[^ ]`                   | Not the one specified character<br>NOTE:<br>is not "does not contain specified chars"<br>is "lines which contain not specified chars"                                     |
| `*`                      | Zero or more of the previous character                                                                                                                                    |
| `^`                      | If first character in the pattern, then pattern must be at beginning of the line to match, otherwise just a literal `^`                                                   |
| `$`                      | If last character in the pattern, then pattern must be at the end of the line to match, otherwise just a literal `$`                                                      |

| Extended Regex Character(s) | Meaning                                                           |
| --------------------------- | ----------------------------------------------------------------- |
| `+`                         | One or more of the previous pattern                               |
| `?`                         | The preceding pattern is optional                                 |
| `{ }`                       | Specify minimum, maximum or exact matches of the previous pattern |
| `\|`                        | Alternation - a logical "or"                                      |
| `( )`                       | Used to create groups                                             |
### SHUTDOWN SHUTDOWN

shutdown arranges for system to be brought down safely
will notify all logged in users that system is shutting down  
if scheduled shutdown like at certain time, will prevent logins for 5 mins before shutdown

shutdown \[OPTIONS] TIME \[MESSAGE]

TIME arguments: 
- now
- hh:mm
- +*minutes*
Message will be broadcast to all users

### ifconfig not ipconfig cus Linux baby

interface as in network interface

ifconfig \[OPTIONS]

generally "eth0" is primary wired connection

"lo" interface is special interface for loopback, which is interface for sending network data to self

### "HE'S RIGHT THERE"; "PING PING PING I CANNOT SEE THE HIM"

ping \[OPTIONS] ADDRESS

-c *integer* ; stops after *integer* attempts

### PS, paiseh, here the processes

ps \[OPTIONS]

-e option will show every proccess running on system

-f option for even more deets

- PID
	- processs ID
- TTY
	- name of terminal where process is running
- Time
	- Total processor tie process used
- CMD
	- Which command started this process
### APT by Bruno Mars & Rosé

dpkg tool is most basic bitch, but hard to use

so many use Advanced Package Tool; apt-get
is front-end program meaning users can see and use

- apt-get update
	- refresh list of available packages
- apt-cache search \[keyword]
	- search for keyword within known list
- apt-get install \[package name]
	- install lmao
- apt-get upgrade
	- updates all installed packages and dependencies to latest version in known list. 
	- use apt-get update to update know list and versions
- apt-get remove \[package name]
	- uninstall package
	- leaves config files
- apt-get purge \[package name]
	- PURGE THE HERETIC
	- BURN THEIR NAMES FROM THE ENTIRE SYSTEM
	- ERASE EVEN THEIR CONFIG FILES FROM THE RECORDS

### Passwd? more like pass away

passwd \[OPTIONS] \[USER]

| Options                                  |                                 |
| ---------------------------------------- | ------------------------------- |
| -s                                       | show status                     |
| {no option, no user}                     | reset password for current user |
| {as su, no option, have normal username} | reset password for given user   |

Example output:
sysadmin P 12/20/2017 0 99999 7 -1

| Output Field    | Example      | Meaning                                                                                                     |
| --------------- | ------------ | ----------------------------------------------------------------------------------------------------------- |
| User Name       | `sysadmin`   | The name of the user.                                                                                       |
| Password Status | `P`          | `P` indicates a usable password.<br><br>`L` indicates a locked password.<br><br>`NP` indicates no password. |
| Change Date     | `03/01/2015` | The date when the password was last changed.                                                                |
| Minimum         | `0`          | The minimum number of days that must pass before the current password can be changed by the user.           |
| Maximum         | `99999`      | The maximum number of days remaining for the password to expire.                                            |
| Warn            | `7`          | The number of days prior to password expiry that the user is warned.                                        |
| Inactive        | `-1`         | The number of days after password expiry that the user account remains active.                              |
### omg Vi, like from Arcane 2021

modes:
- Command
	- type commands like move doc, format text
	- return to command mode any time with esc key
	- need return to command mode to use cursor lmao
- Insert
- ex

#### Cursor movement commands:  

format: \[count] motion

| Motion     | Result              | vi alternatives |
| ---------- | ------------------- | --------------- |
| `h`        | Left one character  | ←               |
| `j`        | Down one line       | ↓               |
| `k`        | Up one line         | ↑               |
| `l`        | Right one character | →               |
| `w`        | One word forward    |                 |
| `b`        | One word back       |                 |
| `^`        | Beginning of line   |                 |
| `$`        | End of the line     |                 |
| \[count] G | go to \[count] line |                 |
| gg / 1G    | go to first line    |                 |
| G          | go to last line     |                 |
Note; ↑→↓↓↓

#### Command mode Actions
formats:
action \[count] motion
\[count] action motion

| Standard | Vi         | Meaning |
| -------- | ---------- | ------- |
| cut      | `d`        | delete  |
| copy     | `y`        | yank    |
| paste    | `P` \| `p` | put     |
|          | c          | Change  |

Deleting saves "deleted" content to buffer, like clipboard

| Delete Action | Result                             |
| ------------- | ---------------------------------- |
| `dd`          | Delete current line                |
| `3dd`         | Delete the next three lines        |
| `dw`          | Delete the current word            |
| `d3w`         | Delete the next three words        |
| `d4h`         | Delete four characters to the left |

Change like delete, text remove, save to buffer BUT
Change to insert mode and allow immediate changes to text

| Change Action | Result                             |
| ------------- | ---------------------------------- |
| `cc`          | Change current line                |
| `cw`          | Change current word                |
| `c3w`         | Change the next three words        |
| `c5h`         | Change five characters to the left |

Yank place content into buffer without clearing buffer

| YankAction | Result                      |
| ---------- | --------------------------- |
| `yy`       | Yank current line           |
| `3yy`      | Yank the next three lines   |
| `yw`       | Yank the current word       |
| `y$`       | Yank to the end of the line |

Put places text from buffer before or after cursor.
Does not use motions, only these 2 options

|Action|Result|
|---|---|
|`p`|Put (paste) after cursor|
|`P`|Put before cursor|
#### Searching

/ char will start search forward from Cursor position
? char will start search bbackward from Cursor position
e.g. /red; then hit enter
n - next match
shift + N - previous match

Note; will wrap to top once hit bottom and vice versa

#### Insert mode
Add text to doc
How to enter insert mode have a few ways, will change where you start editing from

| Input | Purpose                                                 |
| ----- | ------------------------------------------------------- |
| `a`   | Enter insert mode **right after** the cursor            |
| `A`   | Enter insert mode at the **end of the line**            |
| `i`   | Enter insert mode **right before** the cursor           |
| `I`   | Enter insert mode at the **beginning of the line**      |
| `o`   | Enter insert mode on a **blank line after the cursor**  |
| `O`   | Enter insert mode on a **blank line before the cursor** |

#### Ex Mode
used to be its own thing, bit Vi was better

use ':' in command mode and following options to get into ex mode
!  char attempts to force the operation

| Input            | Purpose                                         |
| ---------------- | ----------------------------------------------- |
| `:w`             | Write the current file to the filesystem        |
| `:w filename`    | Save a copy of the current file as `filename`   |
| `:w!`            | Force writing to the current file               |
| `:1`             | Go to line number 1 or whatever number is given |
| `:e filename`    | Open `filename`                                 |
| `:q`             | Quit if no changes made to file                 |
| `:q!`            | Quit without saving changes to file             |
| `:ZZ`            | same as `:wq`                                   |
| `:[line number]` | same as \[line number]G in command mode         |
## GDB things

`gdb-multiarch -x .gdbinit`

“.gdbinit” usually contains the target remote localhost:26000 symbol-file kernel/kernel.

`b [pattern]` - create breakpoint at next instance of pattern, if use '\*0x80002845' can even do break point by program counter  

`c` - continue
`q` - quit
`layout [option]` - can layout src, which shows c code, or layout asm, which shows machine code

`backtrace` - shows backtrace of where breakpoint was

`p [options]` - print
- possible options
	- `/x` is privilaged status
	- `*p` is process proc struct
	- `$sstatus` is special status register
	- `p->name` is print process name

`file [filepath]` - let gdb read symbols from filepath




# Temp revision

### OS goals:  
- Provide users with interface to hardware
  - execute user applications  
- Resource management
  - use hardware in efficient manner
  - cannot leave critical application to run later,
  - come form of hierarchy of running programs

Applications cannot directly manipulate many of the hardware components (CPU, Mem, I/O)  
Ask OS to do for them  
to maintain integrity of system

OS provides communication to applications
- Applications can use network for inter-process communication (loop-back devices)
- OS provide local communication
  - Pipes
  - Shared Mem
  - Passing messages

### Overall comparison
|               | Layered                                                                 | Modular                                                    | Micro Kernel                                                                | Monolithic Kernel                                           |
| ------------- | ----------------------------------------------------------------------- | ---------------------------------------------------------- | --------------------------------------------------------------------------- | ----------------------------------------------------------- |
| **Structure** | **Heirarchical Layers**; each layer only intereact with one layer below | **independant modules**; dynamically loaded and unloaded   | **Minimal kernel w/ only essential services**; other services in user space | **All Core services in Kernel Space**                       |
| Performance   | **Moderate** <br>(overheads from layering slows execution)              | **High** <br>(Modules run effeciently)                     | **Low** <br>(frequent inter process comms adds overhead)                    | **High** <br>(direcct function calls make quick execcution) |
| Reliability   | **Moderate** <br>(clear seperation, easy debug, limit effeciency)       | **High** <br>(Fault modules isolate easy, replace easy)    | **High** <br>(fault in user space dont affect kernel)                       | **Low** <br>(single fault can crash whole system)           |
| Flexibility   | **High** <br>(easy to modify & replace)                                 | **Very high**<br>(support extensibility and customisation) | **Very high** <br>(modular makes it easier to add services)                 | **Low** <br>(tightly coupled, make changes difficult)       |

### Micro Kernel
| Benefits                                                    | Detriment                                                             |
| ----------------------------------------------------------- | --------------------------------------------------------------------- |
| Easier to extend a microkernel                              | bigger performance overhead due to user space to kernel communication |
| Easier to port the operating system to new<br>architectures |                                                                       |
| More reliable (less code is running in )                    |                                                                       |
| More secure                                                 |                                                                       |
### Chap 1 others

xv6 is monolithic

Complexity of OS depends on the usage of device,
Dedicated devices (rockets, washing machine) - simple OS / API
General Devices (PCs, Mobile phones, Servers) - More complicated but flexible APIs

is organised into distinct directories & source files that correspond to major subsystems  
- kernel/:
  - contains all core xv6 kernel source files:
    - main.c: kernel init & boot process
    - syscall.c: system call implementation and dispatch
    - trap.c: trap and interrupt handling
    - proc.c: process management (creation, scheduling, context switchin)
    - vm.c: cirtual memory management and page tables  
    - fs.c, file.c, inode.c: filesystem implementation
- user/: user-level apps, including shells (sh.c), commands (ls.c, cat.c) and utilities
- makefile: Buidl instructions to compile kernel and user programs and run xv6 on QEMU
- README and other docs: Documentation and build/run instructions

### OS security
- Confidentiality
	- only users with the right privileges can access the data
	- Data encryption
	- Access Control
- Integrity
	- only users with the right privileges can modify data
	- Data Validation
	- Hash Checks
- Accessibility
	- Resources are available to users requiring them
	- High Availability
	- High Redundancy

### What is system call
- is programming interface to services provided by OS
- syscalls invoked by triggering specific interruptions that the CPU Instruction Set Architecture (ISA) reserves for OS purposes
- syscalls mostly accessed by programs through API rather than direct call
- because API specifies set of functions that are available to programmer
	- including params passed and expected return values
	- handles the call and returns the values to the caller
	- caller does not need to know anything about the call, just obey API requirements and understand what OS will do as result of call
	- most details hidden from caller, managed by run-time support library
	- API provides 
		- abstraction of function call behaviors
		- interoperability among diff OS/HW versions
		- (usually) efficient access to System Calls
		- (with the above) convenient simplified way to access

Asm / kernel mode:
- ecall; go to interrupt table
	- this results in some overhead
- (x86)int 0x2E/0x80; read call from interrupt table
- 
- check register a7 for specific call
- Arguments to call  placed in registers a0-a6
- if even more arguments, place those in stack

### Syscall Param Passing

3 general Methods:
1. pass param in register (by value)
2. pass param in buffer (by value)
	- Param stored in block of mem
	- address of block passed as param inregister
3. Mixed, using mem block w/ registers

### syscall Security
- Hardware Security System calls can execute privilege ISA instructions
- what instructions should be privileged only and why
	- btw sudo may give user priv mode but is not kernel mode, still stuck in user mode
	- shutdown is priv
		- why? as may interfere with task other users may be doing
	- making mem executable
		- certain areas should not be executable due to safety or running reasons
		- may be used to exploit and get arbitrary remote code execution
	- Interrupt Handling
		- INT n: Software Interrupt
		- some interrupts may require privilege depending on vector (????)
		- IRET. IRETD (x64) sret/mret
		- return from interrupt (RISC-V) (restore processor state)
	- System Management
		- RDPMC
			- Read performance monitoring counters
			- May require privilege depending on config
	- Virtualization
		- VMRUN: Launch a virtual machine
	- Access / modification to registers
		- May compromise system integrity
		- LGDT/SGDT (x86): Load/Store Global descriptor table register
		- MOV CRx (CR0-4 in x64; sstatus, stvec, satp in RISC-V) : move val to control register
	- Certain (Virtual) Mem management
		- LGDT/LIDT: Manipulate descriptor tables for mem management
		- hfence\.vvma/ hfence\.gvma / sfence\.vma (RISC-V)

When CPU executes instruction that goes through kernel mode
automatically modify 2 bits in CS register indicate privilage mode in system
(CPL for intel; CPU internal state priv RISC-V)
set back to original val when return to user

### Privileged mode problem
how 2 do:
- Memory isolation  
	- ensures user programs cannot access kernel space directly  
- Privileged instructions (e.g., I/O control,  memory management) 
- non-privileged instructions (e.g., arithmetic)

### Trap handling
Traps
1. system call: user prog executes ecall instruction to request service from kernel
2. exception: instruction performs illegal action, e.g. accessing invalid virtual mem addr
3. interrupt: hardware signals that it needs attention, e.g. disk finished read/write
Execution of user code should resume transparently after trap
user should not be aware anything special has happened (especially for device interrupts)

![[xv6-trap-handling.png]]

- flow: 
- === Usermode ===
	- hardware declare interrupt or exception
		- syscall uses ecall to inform that kernel user want to exec service
		- exceptions raised y hardware
- === Usermode ===
- === Kernel Mode===
	- os saves users process' registers into *trapframe*
		- hardware sets sepc to current PC 
			- (supervisor exception program counter)
			- (special control = status register in RISC-V CPU)
		- Disable interrupts, sstatus.SIE=0
			- dont want to jump to other places incase have other interrupts simultaneously
		- record cause, scause
			- part of return capability
		- jump to addr indicated by stvecc (uservec in trampoline)
		- trampoline.S saves current user process' registers into trapframe + switch to kernel stack
	- distinguishes event type and executes requested kernel service
		- kernel exec trap.c
		- trap.c distinguish between syscall, execption, interrupt
		- exec requested kernel service
	- restores saved registers from *trapframe*
		- trampoline.S restores saved user process' registers
		- kernel increments sepc to resume next user instruction
		- exec sret (supervisor return) and CPU switches back to user mode
- === Kernel Modse===
- === Usermode ===
	- resume user process

### What is kernel stack

User stack is user space
used when process run in user mode

Kernel stack is kernel space
used when process traps into kernel
kernel stack is per-process; ever process has own kernel stack allocated in mem

enter kernel stack from user stack when ecall, exception, interrupt (trap occurs)
exit kernel stack to user space with sref (return from trap)

### Why  handle traps like this
- Security: 
	- prevent user prog from directly handling privileged events (interrupts)
- Isolation: 
	- devices shared among processes; 
	- only kernel coordinate access
- Simplicity: 
	- keep user programs focused on computation
	- kernel manage resources
- Consistency
	- Ensure all traps handled in uniform way by kernel

### What does syscall.c do in system call hanndling
- Syscall.c is dispatcher for system calls
- defines dispatching table mapping system calls numbers to handler functions

Read syscall number from reg a7 in trapframe
use dispatch table to find corresponding handler
Execute handler, place return val in a0 register for user program; if invalid, return -1

### What is a process
A program in a piece of memory being executed and the services needed to execute it
A program in execution; process execution must progress in a sequential fashion
Program is a passive entity stored on disk (executable file)
### examples of processes
batch system - called jobs
- time-shared systems - user programs or tasks

Process is active
- Program becomes process when executable file loaded into mem

Execution can be done in many ways
- CLI
- mouse double click

### What is process state

Scheduler determines the next state

- states
	- new: process is being created
	- running: process being executed
	- waiting: process waiting for some event to occur
	- ready: process waiting to be assigned to a processor
	- terminated: process has finished execution

![[process_states.png]]

### Process control block

info associated with each process (task control block)
- Process state
	- To check state of process and its child processes
- Process Identifier
- Program counter
- CPU registers
- CPU scheduling info
	- Priorities, scheduling queue pointers
- Mem-management info
	- mem allocated to process
- Accounting info
	- CPU used
	- clock time elapsed since start
	- time limits
- I/O status info
	- I/O devices allocated to process
	- list of open files
- Inter-process communication

![[what-is-process-control-block.png]]

### Process Memory
- Stack
	- function param
	- return addr
	- local variables
- heap
	- dynamically alloc-ed mem during rutime
	- managed via calls like malloc and free
- data section
	- global & static variables which are allocated and initialised prior to exec
- text section
	- compiled program code (from non-volatile storage) when launched (other sections (.init, .rodata))
- BSS (Block Stated by Symbol)
	- similar to Data sect, uninitialized global and static variables 

when processes are stored and restored, this additional info must be store and restored together
like PC and program registers

#### when might stack and the heap clash?  
- When invoking a function the OS uses the stack to create a new function frame
	- (passing arguments, local variables, and back up of the necessary registers).  
- When invoking a malloc the allocated memory area is taken from the top of the heap. 
	- If the distance between stack and heap is less than the required space an error will happen.

Note stack grow down in addr num, heap grow up in addr num
if meet, stack overflow / cannot malloc/new, insufficent mem

![[process-memory.png]]

### Why schedule? just run lol

Processes can be described as
- I/O bound
	- spend more time doing I/O than computation, many short cpu burst
- CPU-bound
	- spend more time doing computation; few long CPU bursts

- Long term scheduler
	- aka job scheduler
	- selects which processes shld be brought into ready queue
	- invoked infrequently (seconds / minutes); ay be slow
	- controls degree of multi-programming
	- strives for good process mix
- short-term scheduler
	- CPU scheduler
	- selects which process shld be executed next and allocates CPU
	- invoked very frequently (milliseconds); must be fast

Need schedule to maximuse CPU usage
share time
deliver acceptable response time

swapping PCB between processes is considered overhead and that cpu time is considered lost

### How is process queue

3 queues
- Job 
	- set of all system tasks
- Ready
	- set of all processes residing in main mem, ready and waiting to exec
- Device
	- set of all processes waiting for i/o device
Processes can migrate among various queues

# Chap 1: Intro to OS and xv6

Libraries and APIs are not OS-es  
GUIs are not OS-es  

OS definition:  
Program that acts as an intermediary between user and hardware
However no universally accepted definition  
"Everything the vendor ships when you order an OS" is good approximation but varies wildly  
"The one program running at all times" is the kernel  
Everything else is either a system program (which ships with OS) or application program

OS goals:  
- Provide users with interface to hardware
  - Provide friendly environment (dependent on type of user)
  - execute user applications  
  - make solving user problems easier
- Resource management
  - use hardware in efficient manner
  - cannot leave critical application to run later,
  - come form of hierarchy of running programs

Computer system components:  
- Hardware
  - basic computing resources
    - CPU
    - Mem
    - I/O
- OS
  - Control & Coordinate use of hardware among various applications and user
    - Word processor
    - Compiler
    - Web browser
    - database systems
    - video games
- Users
  - People
  - Machines
  - Oher computers

Applications cannot directly manipulate many of the hardware components  
Ask OS to do for them  
You dont want applications poking around your hardware  
dont want users to code  certain actions for hardware that may break it, e.g. moving harddrive arm beyond operating range
is for security  

Various apps/hardware  
Many versions of content or extensions  
Keeps changing  
OS can bridge/manage these updated systems on the users behalf

Hardware abstraction for applications:  
- CPU
- Memory
- I/O

Means OS is a resource allocator:  
- Manages resource
  - CPU
  - Memory
  - I/O
- Decides between conflicting requests for effecient and fair resource use
  - e.g. two processes need to use CPU, how to assign

OS manages user access control, allowing certain actions to be executed by superusers only

OS provides effecient synchronisation for processes

OS provides communication to applications
- Applications can use network for inter-process communication (loop-back devices)
- OS provide local communication
  - Pipes
  - Shared Mem
  - Passing messages


even with all these capabilities it may or may not be enough  

for specialied OS, e.g. rocket launch systems where users know what they are doing, or simple washing machine with less interactino with users,  
May be enough to do just these things  

For devices like Iphone, samsung, it must be more flexible and provide powerful APIs. So other users can develop apps and programms for the OS  
e.g. Google developed android focusing on developers, making well documented API that ease implementation of applications

## How is OS organised  

One or more CPU, device controller connected through common bus, providing shared access to shared mem  

Concurrent execution of CPUs and devices competing for memory cycles  

I/O devices and CPU can execute concurrently  
each device controller has local buffer, which CPU uses to move main mem to/from buffers  
CPU does not need to handle individual fragments of data for each device  
I/O is from device to controller buffer  
Device controller informs CPU of completion of op with interrupts  
Device driver provide OS with uniform interface to access device

## Approaches to OS design

- Layered approach
  - start at hardware layer, build on necessary layers without subcomponents that interact on same layer.
  - one layer is one big essential piece
  - each layer built on top of the last
  - bottom layer 0 is hardware
  - highest layer n is user interface
  - each layer designed to use functions and services of previous layers
  - used in linux, windows, macOS
- Modular approach
  - start at hardware and add on functionality in layers.
  - May contain components that live on same layer that interact with each other
  - uses object oriented approach
  - each core component is separate
  - each talks to others over known interfaces
  - each loadable as needed within kernel
- Micro-Kernel
  - Split into kernel Space and user space
  - Apps and services run in user space
  - essential abstractions run in kernel space
- Monolithic Kernel
  - clear separation between user and kernel
  - all aspects of kernel share same memory space
  - user mode apps do not have access to all instructions
  - certain cpu instructions are limited to kernel mode only
  - many parts are integrated into the kernel
  - like Virtual mem, drivers, User interface, mem management, file system
  - if any part is compromised, it exists in the kernal space and may grant access to other parts of the kernel

## Micro Kernel System Structure

Moves as many fucntions as possible into user space
e.g.  
HarmonyOS NEXT (Hwawei) is micro kernel extended with indipendent services  
Communication between user modules uses message passing  


| Benefits                                                    | Detriment                                                             |
| ----------------------------------------------------------- | --------------------------------------------------------------------- |
| Easier to extend a microkernel                              | bigger performance overhead due to user space to kernel communication |
| Easier to port the operating system to new<br>architectures |                                                                       |
| More reliable (less code is running in )                    |                                                                       |
| More secure                                                 |                                                                       |

## Monolithic System Structure

Consists of 2 seprable parts
- System Programs
- Kernel
  - Kernel is everything below system-call interface but above physical hardware
  - Provide large number of functions for 1 level:
    - File system
    - CPU scheduling
    - memory management
    - other OS functions

## Hybrid System

Combine Micro Kernel with extended functionality to enhance performance

## Overall comparison


|               | Layered                                                                 | Modular                                                    | Micro Kernel                                                                | Monolithic Kernel                                           |
| ------------- | ----------------------------------------------------------------------- | ---------------------------------------------------------- | --------------------------------------------------------------------------- | ----------------------------------------------------------- |
| **Structure** | **Heirarchical Layers**; each layer only intereact with one layer below | **independant modules**; dynamically loaded and unloaded   | **Minimal kernel w/ only essential services**; other services in user space | **All Core services in Kernel Space**                       |
| Performance   | **Moderate** <br>(overheads from layering slows execution)              | **High** <br>(Modules run effeciently)                     | **Low** <br>(frequent inter process comms adds overhead)                    | **High** <br>(direcct function calls make quick execcution) |
| Reliability   | **Moderate** <br>(clear seperation, easy debug, limit effeciency)       | **High** <br>(Fault modules isolate easy, replace easy)    | **High** <br>(fault in user space dont affect kernel)                       | **Low** <br>(single fault can crash whole system)           |
| Flexibility   | **High** <br>(easy to modify & replace)                                 | **Very high**<br>(support extensibility and customisation) | **Very high** <br>(modular makes it easier to add services)                 | **Low** <br>(tightly coupled, make changes difficult)       |

## xv6

simple modern version of Unix version 6  
Written in ANSI C  
for x86 and RISC-V multi-processor systems  
10 000 lines of ccoe  
made in MIT 2006  
Provides:  
- processes
- simple scheduler
- virtual memory
- heirarchical file system
- file descriptors
- shell

Deliberatly omit:  
- threads
- memory-mapped files
- advance features

Limited:  
- drivers
- system calls

Simplified hardware assumptions  
realistic Unix-like design  
Open source  
Multi processor support  
good for soid foundation to understand ore complex systems like Linux or BSD  

Is monoithic kernel  
Single address space contains all OS services:  
- Processes
- memory
- file system
- I/O

User vs Kernel Seperation:  

User mode:  
- Apps execute with limited access

Kernel Mode:  
- Privilaged acccess via traps/system calls for procetion

Mode Switch:
- Traps save context
- Dispatch handlers
- return

Key sub-systems / services:  
- kernel init
  - init hardware, mem and process structures
- System calls
  - dispatch user request and kernel functions
- Process Management
  - maintain process table for each process
  - implement scheduler for CPU time alloc
  - handle context switching between processes
- Memory management
  - set up virtual mem
  - provide isolation between proccess
  - manage allocation and freeing of physical mem
- File system
  - implement UNIX-like file system with inodes and directories  
  - provide file desccriptions
  - support pipes and device files
- device driver
  - provide I/O support for hardware

is organised into distinct directories & source files that correspond to major subsystems  
- kernel/:
  - contains all core xv6 kernel source files:
    - main.c: kernel init & boot process
    - syscall.c: system call implementation and dispatch
    - trap.c: trap and interrupt handling
    - proc.c: process management (creation, scheduling, context switchin)
    - vm.c: cirtual memory management and page tables  
    - fs.c, file.c, inode.c: filesystem implementation
- user/: user-level apps, including shells (sh.c), commands (ls.c, cat.c) and utilities
- makefile: Buidl instructions to compile kernel and user programs and run xv6 on QEMU
- README and other docs: Documentation and build/run instructions

xv6 vs Linux  

|                  | xv6                            | Linux                       |
| ---------------- | ------------------------------ | --------------------------- |
| Purpose          | simple unix-like, for teaching | Product grade, feature rich |
| Code Complexity  | ~10 000 lines                  | ~30 000 000 lines           |
| hardware support | x86 and RISC-V on QEMU only    | many diffeerent hardware    |
| Features         | basic unix                     | advanced features n shit    |
| system calls     | 21 basic syscalls              | 300+ syscalls               |
| organisation     | Single file per subsystem      | Modular subsystems          |

## RISC-V

- Open-Source instruction set architecture
- developed in 2010 by University of California, Berkeley
- Based on Reduced instruction Set Computing (RISC) principles
- keep simple and efffecient
- 4 corre
- 32 register  control register
- ALU and Mem Management Unit
- Timer and interrupt logic
- Bus interface
- 128 MB RAM
- UART for console device I/O
- Disk-like storage
- ethernet

# Chap 2 System Calls & Traps

## OS security
- Confidentiality
	- only users with the right privileges can access the data
	- Data encryption
	- Access Control
- Integrity
	- only users with the right privileges can modify data
	- Data Validation
	- Hash Checks
- Accessibility
	- Resources are available to users requiring them
	- High Availability
	- High Redundancy

## xv6 System Calls

### What is system call
- is programming interface to services provided by OS
- typically written in high level lang
- syscalls invoked by triggering specific interruptions that the CPU Instruction Set Architecture (ISA) reserves for OS purposes
- makes it convenient to call and use
- syscalls mostly accessed by programs through API rather than direct call
	- because API specifies set of functions that are available to programmer
	- including params passed and expected return values
	- handles the call and returns the values to the caller
	- caller does not need to know anything about the call, just obey API requirements and understand what OS will do as result of call
	- most details hidden from caller, managed by run-time support library
	- API provides 
		- abstraction of function call behaviors
		- interoperability among diff OS/HW versions
		- (usually) efficient access to System Calls
		- (with the above) convenient simplified way to access
	- examples of APIs
		- Win32 API
		- POSIX API
			- UNIX, Linux, MACOS
		- Java API

RISC-V uses ecall with register a7 to invoke system calls

Code / user mode:
- Olden x86
- int ISA call

Asm / kernel mode:
- ecall; go to interrupt table
	- this results in some overhead
- (x86)int 0x2E/0x80; read call from interrupt table
- 
- check register a7 for specific call
- Arguments to call  placed in registers a0-a6
- if even more arguments, place those in stack


other syscalls:
- X64
- less overhead as no interrupt table, go direct to specific call
	- RAX contains syscall number
	- RCX, RDX, R8, R9, R10, R11 contains args
	- (Windows) additional args go to stack
	- (Linux) no additional arguments beyond these 6
		- if really need, then one of the args would point to a buffer with the data

### Syscall Param Passing

3 general Methods:
1. pass param in register (by value)
2. pass param in buffer (by value)
	- Param stored in block of mem
	- address of block passed as param inregister
3. Mixed, using mem block w/ registers

### syscall Security
- Hardware Security System calls can execute privilege ISA instructions
- but how is it enforced?
- what instructions should be privileged only and why
	- btw sudo may give user priv mode but is not kernel mode, still stuck in user mode
	- shutdown is priv
		- why? as may interfere with task other users may be doing
	- making mem executable
		- certain areas should not be executable due to safety or running reasons
		- may be used to exploit and get arbitrary remote code execution
	- Interrupt Handling
		- INT n: Software Interrupt
		- some interrupts may require privilege depending on vector (????)
		- IRET. IRETD (x64) sret/mret
		- return from interrupt (RISC-V) (restore processor state)
	- System Management
		- RDPMC
			- Read performance monitoring counters
			- May require privilege depending on config
	- Virtualisation
		- VMRUN: Launch a virtual machine
	- Access / modification to registers
		- May compromise system integrity
		- LGDT/SGDT (x86): Load/Store Global descriptor table register
		- MOV CRx (CR0-4 in x64; sstatus, stvec, satp in RISC-V) : move val to control register
	- Certain (Viirtual) Mem management
		- LGDT/LIDT: Manipulate descriptor tables for mem management
		- hfence\.vvma/ hfence\.gvma / sfence\.vma (RISC-V)


### How does having a privileged mode of op benefit security

by forbidding inst, prevent user-mode applications from
- obtaining unauthorized access to critical resources
- Disabling / interfering with essential system functions (interrupts/mem management)
- Tamper kernel structures

## How syscall security works

When CPU executes instruction that goes through kernel mode
automatically modify 2 bits in CS register indicate privilage mode in system
(CPL for intel; CPU internal state priv RISC-V)
set back to original val when return to user

## What if no OS

can write apps but must implement every user interface, device driver, mem handling, control flow it needs

Cannot ensure multi process running simultaneously without interfering with each other
no scheduler

## What is Privileged Mode Problem

Switching mode is a hardware instruction, dont want to do through registers, opens attack surface

how 2 do:
- Memory isolation  
	- ensures user programs cannot access kernel space directly  
- Privileged instructions (e.g., I/O control,  memory management) 
- non-privileged instructions (e.g., arithmetic)


Difference in Modes:
User Mode: 
- Applications run in user mode by default.
- Can run only non-privileged instructions, memory isolation where applications can only access their assigned memory space
	- Memory isolation
		- they cannot access kernel or other applications memory, no direct hardware access.\
Kernel Mode
- Privileged access via traps/system calls for protection
- Can run all instructions, memory management, direct hardware access interrupt control CPUs detect illegal privileged instructions in user mode and raise exceptions (traps)

OS ENFORCES
Resource isolation
- applications must request resources through system call
- the kernel decides how to allocate them fairly 
- Memory isolation
	- applications cannot access memory outside its allocated space. If application tries, CPU raises a segmentation fault, protecting other processes and the kernel
Mode Switch
- Traps save context, dispatch handlers, return

## xv6 - handling traps

CPU may suspend normal instruction execution + transfer control to kernel mode in 3 situations (this is the Traps in xv6)
1. system call: user prog executes ecall instruction to request service from kernel
2. exception: instruction performs illegal action, e.g. accessing invalid virtual mem addr
3. interrupt: hardware signals that it needs attention, e.g. disk finished read/write
Execution of user code should resume transparently after trap
user should not be aware anything special has happened (especially for device interrupts)


user can initiate syscall like write to file through API
but sometimes is OS that initiate syscall

![[xv6-trap-handling.png]]

- flow: 
- === Usermode ===
	- hardware declare interrupt or exception
		- syscall uses ecall to inform that kernel user want to exec service
		- exceptions raised y hardware
- === Usermode ===
- === Kernel Mode===
	- os saves users process' registers into *trapframe*
		- hardware sets sepc to current PC 
			- (supervisor exception program counter)
			- (special control = status register in RISC-V CPU)
		- Disable interrupts, sstatus.SIE=0
			- dont want to jump to other places incase have other interrupts simultaneously
		- record cause, scause
			- part of return capability
		- jump to addr indicated by stvecc (uservec in trampoline)
		- trampoline.S saves current user process' registers into trapframe + switch to kernel stack
	- distinguishes event type and executes requested kernel service
		- kernel exec trap.c
		- trap.c distinguish between syscall, execption, interrupt
		- exec requested kernel service
	- restores saved registers from *trapframe*
		- trampoline.S restores saved user process' registers
		- kernel increments sepc to resume next user instruction
		- exec sret (supervisor return) and CPU switches back to user mode
- === Kernel Modse===
- === Usermode ===
	- resume user process

## What is kernel stack

User stack is user space
used when process run in user mode

Kernel stack is kernel space
used when process traps into kernel
kernel stack is per-process; ever process has own kernel stack allocated in mem

enter kernel stack from user stack when ecall, exception, interrupt (trap occurs)
exit kernel stack to user space with sref (return from trap)

## What does syscall.c do in system call hanndling
- Syscall.c is dispatcher for system calls
- defines dispatching table mapping system calls numbers to handler functions

Read syscall number from reg a7 in trapframe
use dispatch table to find corresponding handler
Execute handler, place return val in a0 register for user program; if invalid, return -1

## Why  handle traps like this
- Security: 
	- prevent user prog from directly handling privileged events (interrupts)
- Isolation: 
	- devices shared among processes; 
	- only kernel coordinate access
- Simplicity: 
	- keep user programs focused on computation
	- kernel manage resources
- Consistency
	- Ensure all traps handled in uniform way by kernel

# Chap 3 Processes & Threads

### What is a process
A program in a piece of memory being executed and the services needed to execute it
A program in execution; process execution must progress in a sequential fashion
Program is a passive entity stored on disk (executable file)
### examples of processes
batch system - called jobs
- time-shared systems - user programs or tasks

Process is active
- Program becomes process when executable file loaded into mem

Execution can be done in many ways
- CLI
- mouse double click

### What is process state

Scheduler determines the next state

- states
	- new: process is being created
	- running: process being executed
	- waiting: process waiting for some event to occur
	- ready: process waiting to be assigned to a processor
	- terminated: process has finished execution

![[process_states.png]]

### Process control block

info associated with each process (task control block)
- Process state
	- To check state of process and its child processes
- Process Identifier
- Program counter
- CPU registers
- CPU scheduling info
	- Priorities, scheduling queue pointers
- Mem-management info
	- mem allocated to process
- Accounting info
	- CPU used
	- clock time elapsed since start
	- time limits
- I/O status info
	- I/O devices allocated to process
	- list of open files
- Inter-process communication

![[what-is-process-control-block.png]]

### Process Memory
- Stack
	- Temp data like
	- function param
	- return addr
	- local variables
- heap
	- dynamically alloc-ed mem during rutime
	- managed via calls like malloc and free
- data section
	- global & static variables which are allocated and initialised prior to exec
- text section
	- compiled program code (from non-volatile storage) when launched (other sections (.init, .rodata))
- BSS (Block Stated by Symbol)
	- similar to Data sect, uninitialized global and static variables 

when processes are stored and restored, this additional info must be store and restored together
like PC and program registers

#### when might stack and the heap clash?  
- When invoking a function the OS uses the stack to create a new function frame
	- (passing arguments, local variables, and back up of the necessary registers).  
- When invoking a malloc the allocated memory area is taken from the top of the heap. 
	- If the distance between stack and heap is less than the required space an error will happen.

Note stack grow down in addr num, heap grow up in addr num
if meet, stack overflow / cannot malloc/new, insufficent mem

![[process-memory.png]]

### Why schedule? just run lol

Processes can be described as
- I/O bound
	- spend more time doing I/O than computation, many short cpu burst
- CPU-bound
	- spend more time doing computation; few long CPU bursts

- Long term scheduler
	- aka job scheduler
	- selects which processes shld be brought into ready queue
	- invoked infrequently (seconds / minutes); ay be slow
	- controls degree of multi-programming
	- strives for good process mix
- short-term scheduler
	- CPU scheduler
	- selects which process shld be executed next and allocates CPU
	- invoked very frequently (milliseconds); must be fast

Need schedule to maximuse CPU usage
share time
deliver acceptable response time

swapping PCB between processes is considered overhead and that cpu time is considered lost

### How is process queue

3 queues
- Job 
	- set of all system tasks
- Ready
	- set of all processes residing in main mem, ready and waiting to exec
- Device
	- set of all processes waiting for i/o device
Processes can migrate among various queues

### Processes in xv6

each process represented by struct proc in proc.h

key fields 
- state
	- states:
		- Unused
			- process slot in process table (proc\[]) is free, process not in use
		- Used
			- process slot allocated, process created but not yet runnable
		- Sleeping
			- process waiting for an event or condition
		- Runnable
			- process ready to run
			- waiting for CPU
		- Running
			- process currently executing on cpu
		- Zombie
			- process terminated
			- waiting for parent to collect exit status
- pid
- parent
	- pointer to parent process
- kstack
	- kernel stack for handling traps and system calls
- pgdir
	- page directory (address space mapping)
- trapframe
	- saved registers during system calls / traps
- context
	- CPU context for switching back


### Syscalls that manage processes

fork()
- creates new child processes by copying the parent process 
- child has copy of parent mem
- child has copy of parent register state
- copies file descriptors that the parent opened, so child has own pointers to those open files
- child is made in same working directory
	- with all these copies, the child effectively starts executing immediately after the fork() method, as if fork ha just returned a value
- After fork
- parent and child execute independently
- child process gets a 0 returned from fork
- parent process gets the child PID returned from fork
- if fork fails, -1 is returned to the parent

exit(status)
- terminates calling process
- i.e.
- releases user mem
- all opend file descriptors are closed
- process becomes a zombie until parent calls wait()
- integer status is saved so parent can retrieve via wait

wait(&status)
- suspend execution of calling process until one of its child processes exits
- if child already exit, wait immediately returns
- return value is pid of the exited child
- if status is non-null, child's exit status is stored at mem addr
- if calling proc has no children, return -1

kill(pid)
- requests termination of process with pid
- sets target processes kill flag
- if process is sleeping, wake
- process exits when it next returns to user space or enters kernel using exit()

exec(path, argv)
- replaces calling process's memory image with a new program loaded from file specified by path
- executable must be ELF file
- new user addr space created
- stack initialised with arguments strings from argv
- the process identifier remains unchanged
- on failure, return -1

getpid
- return process pid

pausn(n)
- suspend execution of calling process for at leaset n clock ticks
- blocks and yields the CPU while waiting
- when n ticks have elapsed, pause() returns 0
- if process killed while paused, return -1
### How do processes communicate xv6

pipe: small kernel buffer
exposed to processes as pair of file descriptors; one to read (p\[0]) one to write (p\[1])
buffer is writing data to one end of pipe, makes data available for reading from the other end of pipe

### How Processes start and end
e.g.
on boot, kernel runs init from userinit.c
userinit calls allocproc tomark free process slot as used
or 
on fork() kernel invokes allocproc to alloc new process struct for child process


????????????????????????????///
# Chap 4 CPU Scheduling  

## Process vs thread
- process can fork which makes new process w/ clone of memory
- to create a large amount of proccesses may not be efficient enough / memory intensive

Process are good but a bit restrictive

Modern Applications follow multi threaded design
Threads run within an application
Multiple tasks with the application can be implemented by separate threads  
▪ Update display  
▪ Fetch data  
▪ Spell checking  
▪ Answer a network request  
▪ Process creation is heavy-weight while thread creation is light-weight  
▪ Can simplify code, increase efficiency  
▪ Kernels are generally multithreaded

## Benefits of using threads
- Economy
	- Less mem allocation needed
	- cheaper than process creation
	- thread switching lower overhead than context switching.
- Resource sharing
	- Sharing of original process memory space
	- threads share memory and the resources of the process to which they belong to
	- easier than shared memory or message passing.
	- sharing code and data allows an application to have several different threads of activity within the same address space
- Scalability / Responsiveness
	- Scalability
		- threads can run in parallel on different processing cores.
	- Responsiveness
		- may allow continued execution if part of process is blocked, especially important for user interfaces

Some threads do not return their stack, depends on structure, but  stack may be needed for follow up functions

### When is it better to use process or use threads
| Processor                                                                                                                | Example                                                                                                                                                                                       |
| ------------------------------------------------------------------------------------------------------------------------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Fault-Tolerance  <br>▪ Reliability  <br>▪ Robustness  <br>▪ Isolation  <br>▪ Security  <br>▪ Multi-Core  <br>Utilization | Tabs in web-  <br>browsers  <br>▪ Critical Systems  <br>(Avionics /  <br>Autonomous  <br>Vehicles)  <br>▪ Distributed  <br>systems  <br>▪ Sandboxes or job  <br>pools for untrusted  <br>code |

| Threads                                                                                                     | Example                                                                                          |
| ----------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------ |
| Lightweight  <br>Applications  <br>▪ Performance  <br>▪ Shared memory  <br>allows faster  <br>communication | UI-Applications  <br>▪ I/O-bound tasks  <br>▪ Background tasks  <br>▪ Games and  <br>simulations |


| Aspect            | Thread                                                                                                   | Processes                                                                                               |
| ----------------- | -------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------- |
| Definition        | Lightweight execution units within a single process,  <br>sharing the same resources and memory space    | Independent execution units with their own memory  <br>space, resources, and operating system identity  |
| Memory Space      | Share the same address space, allowing direct  <br>access to shared data and faster communication        | Have independent address spaces, providing strong  <br>isolation but making communication slower        |
| Resource Sharing  | Share resources like file descriptors, sockets, and  <br>memory, enabling lightweight collaboration      | Have separate resources, requiring explicit  <br>mechanisms (e.g., IPC) for collaboration               |
| Creation Overhead | Lightweight and faster to create since they don’t need  <br>a new address space or resource duplication. | Heavier to create due to the need for new address  <br>space, resource tables, and kernel structures    |
| Context Switching | Faster because they share the same memory space  <br>and require less state saving/restoration.          | Slower as the kernel must switch the address space  <br>and reload memory management structures         |
| Communication     | Direct communication through shared memory,  <br>making it very fast and efficient                       | Requires inter-process communication (IPC)  <br>mechanisms like pipes, sockets, or shared memory        |
| Isolation         | Low; threads can access and modify each other’s  <br>memory, increasing the risk of corruption           | High; processes are fully isolated, ensuring that one  <br>process cannot directly affect another       |
| Crash Impact      | A crash in one thread can crash the entire process  <br>since all threads share the same address space   | A crash in one process does not affect others,  <br>providing fault isolation and robustness            |
| Performance       | Better performance for tasks requiring frequent  <br>communication or sharing of data                    | Higher overhead but more secure and robust for tasks  <br>requiring strict isolation or fault tolerance |
| Examples          | Threads in a multithreaded application, e.g., web  <br>servers or real-time applications.                | Processes like browser tabs (Chrome), isolated  <br>services, or separate system programs.              |


## Concurrency vs parallelism

Concurrent exec: each process does a little bit of processing, taking turns on 1 processor

Parallelism: multiple cores, executing different programs at one time

As num threads increase, architectural support for threading increases
- CPU need cores and hardware threads
- e.g. Oracle SPARC T4: 8 Core 8 threads

## Multicore programming

Multicore or multiprocessor systems.
challenges include:  
- Dividing activities: 
	- examining applications to find areas that can be divided into separate, concurrent tasks.  
- Balance:
	- even if tasks can run in parallel, still need ensure that tasks perform equal work of equal value.  
- Data splitting:
	- the data accessed and worked on by the tasks must be divided to run on separate cores.  
	- Avoid conflict of writing to same file
- Data dependency:
	- must ensure execution of tasks is synchronized, accommodate the data dependency.  
- Testing and debugging:
	- many different execution paths
	- testing and debugging such concurrent programs is inherently more difficult.

### Data Parallelism
distributes subsets of the same data across multiple cores, same operation on each
![[data-paralleism.png]]

### Task Parallelism
distributing threads across cores, each thread performing unique operation
![[task-paralleism.png]]


### Examples
| Data Parallelism                                                                                                              | Task Parallelism                                                                                         |
| ----------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------- |
| Matrix Multiplication  <br>Image Processing  <br>Training Neural Networks  <br>Sorting Large Data  <br>Scientific Simulations | Web Server  <br>Video Processing Pipeline  <br>Compilers  <br>Autonomous Driving  <br>Rendering Graphics |


## User vs Kernel threads

User thread
- managed by user-level library
	- e.g.
	- POSIX Pthreads
		- User threads
	- Win32 threads
		- Has both user and kernel threads
	- Java threads
		- user threads
- light, context switch need fewer ops

Kernel threads
- Supported by kernel
- more expensive, behave similar to process
- Need full context switch, req system calls
- have own TCB and kernel stack
- Scheduled by kernel

Examples using these threads
- Virtually all general-purpose OS
- Windows
- Solaris
- Linux
- Tru64 Linux
- Mac OS X


| Aspect            | Kernel Thread                                                                                                                 | User Thread                                                                                                                            |
| ----------------- | ----------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------- |
| Context Switching | Requires kernel intervention, involving a full context  <br>switch, including kernel mode transitions, making it  <br>slower. | Performed entirely in user space, involving only  <br>thread-specific data like registers and stack, making it  <br>faster             |
| Resource Sharing  | Share process-level resources like memory, file  <br>descriptors, and sockets, enabling fast communication                    | Also share process-level resources, just like kernel  <br>threads, since they run within the same process                              |
| Portability       | Dependent on operating system features, making  <br>them less portable across platforms                                       | Portable across platforms because they are  <br>implemented entirely in user-space libraries                                           |
| System Calls      | Require system calls for creation, synchronization, and  <br>scheduling, leading to higher overhead                           | Do not require system calls for thread management,  <br>avoiding kernel involvement and reducing overhead                              |
| Scalability       | Achieve true parallelism across multiple CPU cores as  <br>the kernel scheduler maps threads to cores                         | Limited parallelism since user threads are mapped to  <br>kernel threads (M:N mapping), depending on kernel  <br>threads for execution |
| Crash Impact      | A crash in a kernel thread affects only the thread or  <br>the process it belongs to, ensuring fault isolation.               | A crash in the user-space thread scheduler affects all  <br>threads managed by it, potentially crashing the  <br>process               |
| Performance       | Higher overhead due to kernel-level operations like  <br>thread creation, context switching, and scheduling                   | Lower overhead as thread management is lightweight  <br>and occurs entirely in user space                                              |
| Examples          | Linux kernel threads, Windows threads, POSIX threads  <br>(mapped to kernel threads in most OSes).                            | Green threads (Java), fibers (Ruby), or lightweight  <br>threads in user-space thread libraries                                        |

## Thread Models
![[thread-models.png]]

1-to-many
- less intensive
- still gives decent responsiveness / feeling of concurrency
- however, when 1 thread makes a syscall, other threads will not be able to run priv instructions as kernel thread is busy
- is stuck to 1 particular core as there is only one thread
	- 1 kernel thread manage 1 core

many-to-many
- provide more kernel threads
	- but always lass kernel threads than user threads
- now can do parallelism on multiple kernel threads

one-to-one
- each user thread map to kernel thread
	- Making new user thread makes new kernel thread
- More concurrency + parallel processors
- Num threads per process sometimes restricted
	- big overhead

two-level
- similar to mant-to-many
- allows threads to be bound to kernel threads
- so some user threads is many-to-many, some is one-to-one



## Pthreads
is from IEEE 1003.1c
POSIX is API for thread creation and synchronization
Is a specification not implementation
- API specifies behavior of thread library
- implementation up to developers
May be provided as user or kernel level

methods:
- pthread_create()
	- Create new thread
- pthread__attr_init()
	- init attributes like stack size, schedule size, priority
- pthread_exit()
	- terminates calling thread
- pthread_detach()
	- detach thread, releasing resources after termination
	- used to manage resources
- pthread_cancel
	- request cancellation of thread
	- e.g. master thread sees thread waiting too long


## Linux threads
Linux calls them tasks, special boi
methods
- sysccall clone()
	- create thread
	- allows cchild task to share addr space of parent
	- Control flags
		- CLONE_FS - share file-system info
		- CLONE_VM - same mem space is shared
		- CLONE_SIGHAND - Signal handles shared
		- CLONE_FILES - set of opened files shared
- struct task_struct - points to process data structures (shared / unique)

### xv6 threads
xv6 does not have native notion of threads, due to minimal design

- thread is within process
	-  share process resources
	- thread only has own stack and CPU state
- threads in xv6 is an extension of process struct
	- becus thread is like another process but no separate addr space
	- reuses parent mem
	- threads only carry minimal execution content needed to run independently

- Clone system reuses kfork, assigning the same page as parent to thread
- kfork
	- kfork takes unused proceedure (max 64, ids created on boot)
	- dupes info from parent, duping whole mem space
	- increase num processes accessing opened file descriptors of parent
- clone:
	- Clone receives pointer to function thread will exec
	- each thread uses own struct proc to store info
		- But all share same pagetable
	- threads have integer isThread that is set when invoking clone
		- Avoid duping mem space when making thread
	- each thread needs own stack
		- process that calls clone is responsible for calling sbkr/malloc_align to alloc stack space
		- clone allocs 22 pages using malloc
			- 1 for stack 
			- 1 for guard
			- this to avoid writing into heap (in case whole stack used)
		- if malloc cannot find space,
			- invoke sbkr to mape more pages into user space
	- thread need own trap frame
		- since trapframe only accessible to kernel,
		- clone copies each thread trapframe above PHYSTOP limit

how to close threads
- kexit
	- closes all open files
	- if there is any child process alive, assigned to init (to reparent)
	- wake parent of child/thread
		- this  parent will be incharge of freeing mem if waiting
	- all children that are threads are killed
- kwait/join
	- traverse all processes, check which children have exited
		- collect exit status into addr given
		- releases child mem
	- kwait ignores threads
	- join ignores non-threads
		- join returns pointer to stack that will be released to the user
	- if no processes/threads, return -1, else sleep, wait for children proccesses/threads to finish
# Chap 5 Synchronisation  

### What is CPU scheduling
OS decision-making processes for selecting which process runs on CPU when multiple processes ready
part of process management
ensure efficient use of CPU

|     | Teacher keep going | Teacher decide |     |     |
| --- | ------------------ | -------------- | --- | --- |
|     |                    |                |     |     |

### Why need schedule

Ensure CPU used efficiently, fairly, responsively
- Efficiency - keep CPU busy, minimize idle time
- Fairness - every process gets chance to run, avoid starving any one processes
- Responsiveness - interactive tasks get quick attention (typing, clicking)
- Balance - diff workloads handled appropriately
### How schedule

| CPU-IO Burst Cycle<br>- Process execution consists of cycle of CPU execution and I/O wait<br>- is CPU burst followed by I/O burst<br><br><br>                     | ![[cpu_burst_cycle.png]]     |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------- |
| CPU burst main concern<br>- many short CPU burst vs few long CPU bursts<br>- I/O bound process = many short CPU burst<br>- CPU bound process= few long CPU bursts | ![[cpu-burst-histogram.png]] |

### Long- Medium- Short- term scheduling

| Long-term                                                                                                                                                                                                                                      | Medium-term                                                                                                                                                                                                                                                                                       | Short-term                                                                                                                                                                                                                    |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| chooses <br>- which programs admitted to system for processing<br>- when to create new process<br>- degree of multiprogramming<br>- % of time per process (more processes; smaller % of time alloc-ed)<br><br>Strives for good process mix<br> | is part of swapping function (swapping processes in and out of mem)<br><br>Based on need to managed degree of multiproramming<br><br>May remove processes from memory, store on disk, bring back rom disk to continue execution<br>- may impact performance as main mem faster then secondary mem | invoked frequently<br><br>responsible for context switching<br><br>strive to maximise CPU utilisation + throughput<br><br>Load balancing for muli-core architectures<br><br>is adaptable????<br><br>selects among ready queue |
#### Context Switching

processes of saving state of running-proc and loading state of another proc
Enables multitasking and CPU scheduling
- process preemption
- interrupts
However, increases overheads as loadng state takes time and CPU is not running

### Ready queue
scheduling decisions occur when process
1. Switches from running to waiting
2. Terminates
3. Switches from running to ready
4. Switches from waiting to ready
1 and 2 are non-preemptive / cooperative
- process keeps CPU until release by terminate / switch to waiting
3 and 4 are pre-emptive

### CPU dispatcher
assigns control of CPU to process (selected by short-term scheduler)
involves: 
- switching context
- switching to user mode
- jump to proper location in user program, continue

Dispatch latency
- time taken for dispatcher to stop proc a and start proc b

Scheduler and dispatcher used tgt
- Scheduler select, dispatcher alloc CPU


### Pre-empting
A running process can be interrupted and moved back to the ready queue if a higher-  
priority or shorter job arrives
Better responsiveness, fairer for interactive systems
Higher overhead due to frequent context switches
e.g. Round Robin, SRTF, Preemptive Priority

Non-preemptive scheduling is simpler but less practical in real-world OS design
Once a process starts running, it cannot be interrupted until completion or voluntary  
release
Simple, less overhead
Poor responsiveness, risk of long waiting times for short jobs
e.g. FCFS, SJF, Priority

CPU looks to switch processes out to run others (pre-emptive)
Proc holds on to CPU until it releases (non-pre-emptive)

### Scheduling crieria

| CPU utilisation                                         | Throughput                                                                       | Turnaround time                                                                                                                                                                                                                                                                                                | Waiting time                                    | Response time                                                                        |
| ------------------------------------------------------- | -------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------- | ------------------------------------------------------------------------------------ |
| aim to Maximise<br><br>keep the CPU as busy as possible | aim to Maximise<br><br>number of processes that complete execution per time unit | aim to minimise<br><br>time to exec proc (time of submission to dispatch, time of completion)<br>- time in mem<br>- time in ready queue<br>- time on CPU/IO<br><br>In an interactive system, turnaround time may not be the best criterion<br><br>turnaround time is limited by the speed of the output device | aim to minimise<br><br>time proc in ready queue | aim to minimise<br><br>time from req submitted to 1st response produced (not output) |
### Types of scheduling algos

| Shortest Job First (SJF)                                                                                                                                                             | Shortest Remaining time first                                                                                                                                   | First come, first served (FCFS)                                                                                                                                                                                                                                                               | Priority                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     | Round Robin (RR)                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| - Select proc w/ shortest CPU time<br>- Optimal avg waiting time<br>- Require burst prediction<br>- Risk starving longer CPU time procs if keep adding short CPU time procs to queue | - Select proc w/ least remaining CPU burst time<br>- preemptive version of SJK<br>- Optimal avg waiting time<br>- req accurate estimate of remaining burst time | - Simplest<br>- Proc that req first alloced first<br>- implementation easily managed w/ FIFO queue<br>- avg waiting time quite long<br><br>- Proc enters ready queue<br>- Proc PCB linked to tail of queue<br>- When CPU free, run proc at head of queue<br>- running proc removed from queue | - Priority int assigned to each proc<br>- CPU runs proc w/ highest priority (smallest int)<br><br>Pre-emptive ver.<br>- Will preempt CPU if priority of newly arrived process higher than priority of running proc<br><br>SJF is special case, Priority inverse of predicted next CPU burst time<br>(greater CPU burst time =  lower priority)<br><br>runs risk of starvation if high priority processes frequently added to queue<br>need use aging to solve (as time proc waiting in ready queue increase, increase Priority of that proc) | - each proc gets small unit  of CPU time (called time quantum *q*)<br>-after *q* elapsed, preempt proc, added to end of ready queue<br><br>if n procs in ready queue and time quantum *q*, each proc gets 1/n of CPU time in chunks of at most *q* times<br>No proc waits > (n-1)q time units<br><br>Designed for time-sharing systems<br><br>Performance may be impacted<br>- *q* large -> FIFO<br>- *q* small -> must be arge enough w/ respect to context switch, large overhead |

#### Advanced Scheduling algo

| Multilevel Queue Scheduling (MLQ)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              | Multilevel Feedback Queue (MLFQ)                                                                                                                                                                                                                                                                                                                                                                                                                                                          | Linux’s Completely Fair Scheduler (CFS)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Ready queue is partitioned into separate queues, for example<br>▪ Foreground (interactive)  <br>▪ Background (batch)<br><br>Process permanently in a given queue<br>Each queue has its own scheduling algorithm<br>▪ Foreground – RR  <br>▪ Background – FCFS<br><br>Scheduling must be done between the queue<br>▪ Fixed priority scheduling; (i.e., serve all from  <br>foreground then from background).  <br>▪ Possibility of starvation for background  <br>processes  <br>▪ Time slice – each queue gets a certain amount  <br>of CPU time which it can schedule amongst its processes; i.e.,  <br>• 80% to foreground in RR  <br>• 20% to background in FCFS<br><br>![[MLQ-queues.png]] | A process can move between the various queues<br>aging can be implemented this way<br><br>Multilevel-feedback-queue scheduler defined by the  <br>following parameters:  <br>▪ number of queues  <br>▪ scheduling algorithms for each queue  <br>▪ method used to determine when to upgrade a process  <br>▪ method used to determine when to demote a process  <br>▪ method used to determine which queue a process will  <br>enter when that process needs service<br><br>![[MLQF.png]] | Based on proportional fairness  <br>▪ Each process gets CPU time proportional to its weight  <br>▪ Uses a red-black tree to track runnable processes  <br>▪ Fair distribution of CPU time; scalable to many processes  <br>▪ More complex than classical algorithms<br><br><br>Scheduling classes  <br>▪ Each has specific priority  <br>▪ Scheduler picks highest priority task in highest scheduling class  <br>▪ Rather than quantum based on fixed time allotments, based on proportion  <br>of CPU time  <br>▪ 2 scheduling classes included, others can be added  <br>1. default  <br>2. real-time  <br>▪ Quantum calculated based on nice value from -20 to +19  <br>▪ Lower value is higher priority  <br>▪ Calculates target latency – interval of time during which task should run at  <br>least once  <br>▪ Target latency can increase if say number of active tasks increases  <br>▪ CFS scheduler maintains per task virtual run time in variable vruntime  <br>▪ Associated with decay factor based on priority of task – lower priority is  <br>higher decay rate  <br>▪ Normal default priority yields virtual run time = actual run time. E.g. a task  <br>with default priority runs for 200ms, its vruntime is 200ms, a task with lower  <br>priority run will have vruntime higher than 200ms, a task with higher priority  <br>will have vruntime less than 200ms  <br>▪ To decide next task to run, scheduler picks task with lowest virtual run time<br><br>![[Completely-fair-scheduler.png]]<br><br><br><br>Real-time scheduling according to POSIX.1b  <br>▪ Real-time tasks have static priorities  <br>▪ Real-time plus normal map into global priority scheme  <br>▪ Nice value of -20 maps to global priority 100  <br>▪ Nice value of +19 maps to priority 139<br><br>![[Completely-fair-scheduler-2.png]]<br> |


#### Gnatt chart
 ![[gnatt-chart.png]]

#### Convoy Effect
When a long process holds the CPU, shorter processes pile up behind it
Increases waiting time for short jobs, reduces system responsiveness
short procs behind long procs result in longer avg waiting time

#### Starvation (Indefinite Blocking)  
▪ A process waits indefinitely because higher-priority processes keep getting scheduled  
▪ Priority scheduling without aging  
▪ Some processes may never execute  
▪ Aging – gradually increasing the priority of waiting processe

#### Thrashing  
▪ Excessive context switching due to small time quantum or paging activity  
▪ CPU spends more time switching than executing resulting in unresponsive system  
▪ CPU utilization drops sharply

## xv6 scheduling

implements short-term scheduler
medium/long term implicit/ommited by design
admission of proc to queue driven by user action / system call
- fork() make proc
- exec() load program
- kernel admit if have free slot in proc table (NPROC)
- if full, fork() fail
no swapping / mem-based suspension (no medium-term)

short term scheduling: 
- scan proc table for runnable
- choose 1
- use dispatcher for context switch

other OS-es schedule diff procs directly from kernel space

xv6 scheduler is own proc and has own thread
means need switch to scheduler proc from running proc then switch back

### xv6 short-term scheduling sequence of events
![[xv6-short-term-scheduling.png]]

#### Timer Interrupt *usertrap()*
xv6 triggering preemption

- RISC-V timer hardware generate interrupt periodically whle proc running
- scause register gets val from timer interrupt (as reason for interrupt)
- Trampoline.s save user state in trapframe
- Proc move to kernel state
- user-mode trap handler (trap.c) check if is timer interrupt; return control to scheduler with *yeild()*
- enforce preemptive, ensure no single proc monopolise CPU

#### Current Process yields CPU *yield()*

proc may voluntarily give up CPU / force to give up by timer

*yield()* in proc.c transition proc to RUNNABLE state
then switch back to scheduler context/proc using *sched()*

xv6 hold *p->lock* across context switch
this prevents other processes from attempting to use the current CPU
important as MUST switch to scheduler proc first to choose next proc
hence, *yield()* is bridge from running proc to scheduler proc, enforcing clean state transition and correct locking

another one is if 2 CPUs see process A is RUNABLE at the same time, both will call swtch() and whichever is first will lock process A, causing the later CPU to be unable to lock and go back to scanning

#### Performs Context Switch *swtch()*
swtch() updates registers and data structs to change the kernel process execution context (kernel space stack, registers)

swtch(&p->context, &mycpu()->context)    &p->context : a0    &mycpu()->context : a1
Save kernel registers that need to be used later (ra, sp, s0..s11) to context structure and restore the scheduler

swtch.s saves old context + restore new context at asm level
save from old context and load from new context:
- return addr (ra)
- stack pointer (sp)
- frame pointer (s0)
- callee-saved registers (s1-s11) 
then return to new exec point

time taken to do this is dispatch latency
#### Choose next RUNNABLE process *scheduler()*
xv6 triggering preemption

on boot
scheduler() is called inside main() in main.c after setting up memory, devices and init
scheduler() implements a simple Round Robin policy by iterating the process table

once in scheduler proc,
Each CPU runs infinite loop in scheduler() in proc.c that scans for RUNNABLE processes
finds a RUNNABLE process, mark it RUNNING, and dispatch via swtch()
once return from proc (be it through interrupt or yield), back in the loop, look for next runnable

#### Perform Context Switch *swtch()* \[again]
#### Exec next process

### Overall look

start `main()` from main.c
call `init()` from init.c
start `scheduler()` from proc.c
- scheduler proc check if procXX == RUNABLE
	- call `swtch(&mycpu()->context, procXX->context);`  switch to procXX
	- run procXX
	- \[SCHEDULING EVENT]:  `exit()` OR `sleep()` OR timer interrupt
		- scheduling event causes `usertrap()` from trampoline.s and trap.c
			-  calls `yield()`
				- `acquire(myproc()-> lock)`
				- `myproc()->state = RUNABLE`
				- `sched()`
					- `swtch()`; switch to scheduler proc
					- after `swtch()`, go back to `yield()`
				- `release(myproc()->lock)`
				- after release, jumps to scheduler proc as last `swtch()` context was to scheduler

## How many procs can run concurrently in xv6

param.h dictates global constants; including process limits, buffer sizes ect.
NPROC = max num processes in system
NCPU = num CPUs xv6 supports
- each CPU runs own `scheduler()` loop
- more CPU = more `scheduler()` = more processes scheduled simultaneously
### other qns this lec
paging is seperating out and only loading partial parts of the process from secondary mem to main mem, useful if proc is very large but only have small amount of mem
e.g.
16Gb process
1Gb ram
load certain parts into ram with paging and offset


# Chap 6 File Systems  

# Chap 7 Mem Management  

# Chap 8 Virtual Memmory