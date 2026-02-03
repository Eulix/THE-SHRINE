
## Wk1
Java

start w/ class definition & main method as entry
emphasise OOP nature

c uses int main()
python use print() \[ no type decleration ]

public class HelloWorld {
    public static void main(String[] args) {
        system.out.println("Hello, Java");
    }
}

comments: // or /* */ or /** */

class header: public class HelloWorld  
method header: public static void main

system finds main method as entry  
main must be: public, static, void

static methods can be called without instantiating class  
instantiating is creating an object with that class  

static means even if havent make oject with thta class, you can still call the static function

other methods execcuted through main  

space, tabs still whitespace

good practice to start class name with caps

class has:  
method / behaviour  
attributes  

datatypes in java:  
primitive types: int, double, bool, char

when declare a class, it does not have values.  


Class definition: define attribute and methods  
Object instance: an instance of class

e.g.  
public class Student{
    String name;
    int year;
    public Student(String n, int y{
        name = n;
        year = y;
    })
}
student s = new Student("Nisha",3);
// s.name == "Nisha"  
// s.year == 3

UML diagram for this class:  
|Student|
|-|
|+ name|
|+ year|
|+ Student(String,int)|

memory is not allocated to any class until we use 'new' keyword to make an object instance of a class  
declaration of class does not reserve memory

java input using Scanner:  
Scanner class reads user input from console  
System.in is console input  
code:  
Scanner sc = new Scanner(System.in);
System.out.print("Enter name: ");
String name = sc.nextLine();

Output with System.out:  
System.out.print displays prompt and message to users

another input class is BufferedInput
BuffredReader input = new BufferedReader(new InputStreamReader(System.in));
String inputString = input.nextLine()

Arrays in java:  
arrays fixed size like C  
need know max cap at compile time  
Slow search  
addition/deletion of array entry more difficult  

Collections in java  
provvides effecient management of data structures
ArrayList is part of collections and os more dynamic  
ArrayList supports dynamic arrays (built in add, delete and access methods)  
the type can be objects not just primative type  
ArrayList\<Type> arraList = new ArrayList<> ();

LinkedList also part of collections  
doubly-linked list: fast insertion/deletion at ends or when have reference node

NOTE  
- there is no == in java.  use .equals()
- attempting to access a uninitialised object will throw NullPointerException and crash


## Wk2

### Project Yapping

Abstract Engine (wk 1-7):  
- not actual simulation/game
- generic foundation
- contains core functionality
- exists outside of specific context
- supposed to offer re-useable components
- think about it as raw engine, dont need to define anything like cards for specific game context
- just make placeholder entities to build abstract engine functions
- entities will not have anything that has context to the game like HP, damage, color
- entities only have characteristics like: Renderable, Mesh,
- base classes/interfaces/managers
- handle lifecycle and interactions
- implement reusable components
- abstract engine should be done by wk 7 and not recommended to adjust after that
- 
- MUST HAVE:
	- Scene Management  
		- Load scene
		- Unload scene
		- Transition between scenes
	- Entity Management  
		- Create
		- Manage
		- Update
	- Collision Management  
		- Detections
		- Resolution
	- Movement Management  
		- Movement of non-player entities
	- Input/Output Management
		- Manage All input & output

Logic Engine (wk8 -wk14)
- Creates concrete classes in context of game
- defines object properties & behaviors
- simulation rules

Develop a Simulation
- important components
	- entities
	- environment
	- logic
- From devs perspctive, of these componnents:
	- what are the main objects?
	- what is the main characteristics of these objects
- GOAL OF PROJECT
	- to apply OOP fundamentals in the creation of this project
- REQUIERMENTS
	- only use libgdx as the simulation env

Project split into:
- management of simulation elements is app part of abstract/non-contextual engine
- Simulation specific logic (contextual layer)
- 
- note
- is more important to focus on abstract engine
- (no  shortcuts to develop the components, e.g. no libraries).
- box2d extension allowed (wk2 lecture she say one)

Problem Statement Wk1-7: Develop an abstract engine

PROJECT REQUIERMENTS:  
- prototype to demonstrate the abstract engine technology and game mechanics
- Proper usage of OOP concepts  
	- Classes  
	- Objects  
	- Inheritance  
	- Polymorphism  
	- Error Handling
- Re-usability
	- Modularity
- Functionalities
	- Game features

Recommendations:
- UML diagram  
	- Identify the main entities to create classes  
	- Think how you want to structure and connect these classes  
- Code  
	- Store code in a repository  
	- Collaborate with your team-mates  
	- Use it for the entire project  
	- Code structure  
	- File, class and function naming convention should be followed (they should be self explanatory)
- Aim for Innovation/Complexity/Solving for the Problem  
- Should focus on solving a problem better than other solutions to same problem (market value)  
- Think whether proposed solution will work for client/target audience

OOP WEEK 4 DELIVERABLES:
- UML diagram for abstract engine
- Class hierarchies
- Relationships between different classes and interfaces

OOP WK 7 OTHER DELIVERABLES:
- Report
	- Professionally written with clear logic and structure
- Code
	- Dropbox submission of the entire code of prototype
	- Must include DEMO for engine, not just raw engine
- Presentation
	- Presentation Slides to showcase exactly what the team has done  
	- 
	- Innovation and functionalities
- Video
	- One short video to demonstrate all features and design of the system
- Peer eval
	- Gey

### Lecture shit

in switch case: 
if each case has no break
it will run found case, then default case

in java  
\== compares mem address
whereas .equals compares content

in java 
list.remove(0) will automatically shift all indexes down
0 here is the index


### SOLID BIRD BIRD
- The Single Responsibility Principle  
	- A class should only have one job / reason to change
	- e.g a report class that generates, formats and prints a report does not follow this principle
	- shld have Report class, ReportGenerator class, ReportFormatter, Report Printer
	- This way if anythign changes only one class is changed
- The Open-Closed Principle  
	- Open for extension, Closed for modification
	- PaymentService Class (Closed)
	- UPIPayment, CardPayment, Wallet Payment
	- each extends from payment service but is different based on exactly how they pay
- The Liskov Substitution Principle  
- The Interface Segregation Principle  
- The Dependency Inversion Principle

### Encapsulation
Hide mess
- Class:
	- Public variables & methods
		- Private variables & methods

Secures data
Restricts Access


Safe Control Access
- Public getter function returns value of private var
- Public setter function updates variable safely
- provides validation / checks

UML diagrams
- helps developers get overall view on how different classes talk to each other
- Start with title
- the all variables with - as the prefix
- then all methods incld constructors with + as the prefix

SOLID principles helps you write code that doesnt explode when you add new features


## Wk 3

### Inheritance

Parent Class's variables are copied to child class (not by values, just same name)
Child class can access Parent Class's variables if that already have a value
Child class's variables only exist within child class and parent cannot access.

Proper encapsulation should include validation in getter setter functions

### Polymorphism
The capability of a single method to operate on different types of objects

Allows same method name to behave differently based on object it is acting upon

e.g.
one area() function in parent class
but it reads what the this.type of the instance object is, then uses the correct formula to return correct value

overloading is also called compile time polymorphism because when compile function, programmer knows there are 2 funcs with diff arguments

#### Overloading
a func with multiple definitions based on arguments in a single class

#### Overriding
a func in child class has the same name as a func from parent class
it also takes the exacct same arguments as the parent class's func
calling this func from the child class will use the child class implementation, overridng the parent class implementation

### Liskov Substitution Principle

Inheritance should only be used when the child class can truly behave like the parent class w/o breaking exceptions

is Square extends Rectangle, any code that works for rectangle should work for square

### Recap Quiz

Class B extends Class A
inherits Public and protected methods
Does not inherit private field

Overloading does not support Dynamic Binding
- Same method name, diff arguments (method signature)
- Static / Compile Time polymorph
Overriding supports Dynamic Binding
- Depends on which object calls method
- Same method Name and signature, diff class diff declaration
## Wk 4

### UML yap

if have general functions because havent make yet, its ok

fking
all the parent class or whatever is see mood
there is literally no requirements
you just take a shot in the dark
"meaningful class connections" dawg this means nothing, never even teach us UML still expect us to do, retarded



### Abstraction
- Hiding complex, low-level details with a simpler, high-level layer  
• The process of hiding certain details and showing only essential  
information to the user.  

E.g.
Ordering from grab w/o about how the restaurant works
Posting on instagram w/o knowing how the server stores the img


Abstraction: Show necessary, hide complexity, focus on what object does w/o worrying about back end. 
Encapsulation: Wrap the data, hide internal state, protect internal from misuse, focus on how object is built

Abstract methods do not have a body, only the method name and arguments required
Any classes that extend from an abstract class MUST have a definition for each abstract function declared in parent
Objects cannot be instantiated from abstract classes
### Interfaces
is a way through which unrelated objects interact with one another
is like a rulebook that says what functions a class must have - does not say how to write them
i.e. define a set of method signatures that a class must adhere to

e.g.
all instagram influencers must : post stories, post photos, reply to DMs
interface from instagram to influencers

Multi inheritance is not possible but can have multiple interfaces

interfaces are declared outside of any class, any class that requires the interface uses keyword implements

interfaces are not classes
interfaces cannot have objects instantiated from it
interfaces do not tell you how to write the method

interfaces can have default, static and private methods, as well as constant/final/static variables
default and static methods may help explain what the interface is supposed to do
e.g. static test(){}

static method can be like check if obj is active then set val

default methods can be overridden, static cannot

Is like a layer 2 switch in the way that only those "plugged" into the switch by implementing the interface must define methods declared in the interface and can call those methods

e.g. iMovable interface
each class that implements iMovable must define each method in iMovable
any class that implements iMovable can call the methods declared in the interface


### Relationships
| Relationship | Meaning                        |                                                                                                                                                                      |
| ------------ | ------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Inheritance  | Parent -> Child(is-a)          | "I got it from my mom"<br>Dog extends Animal means Dog is an animal<br>Student extends person means Student is a person                                              |
| Association  | Connected but independent      | "We talk somtimes"                                                                                                                                                   |
| Aggregation  | Has-a<br>parts are independent | "Group project but each lives own lives"<br>Library is collection of books yet  each book is unique                                                                  |
| Composition  | Has-a<br>Parts are dependent   | "We die together"<br>If object A exists, object B will also exist<br>Book has pages, without pages, book does not exist, without book, pages of that book dont exist |
| Dependency   | Temporary Use                  | "A quick situationship"<br>Student study in Library, both can exist without the other yet, in order to study, the student is dependent on the library                |

#### E.g.
class Engine{
	private int horsePower;

	public Engine(int horsepower){
		this.horsePower = horsepower
	}

	public void start(){
		System.out.println("Engine starting with " + horsepower + " HP")
	}
}

class Van{
	private Engine engine;
	public Van(){
		this.engine = new Engine(120);
		// since allocating mem, strong ownership of Engine obj
		// thus is a Composition
		// does not need inheritance here, yet connected due to mem alloc
		// engine must be part of van,, if van does not exist, mem is not alloced for engine to be made
	}
}


## Wk 5

### Assignement of Variables

Value
- for primitives like int, char
Reference
- pointers
- for instanced objects


### Cloning
Is not inheritance
is not creating obj with new keyword
is not serialisation
#### Shallow Clone

Two pointers to same underlying object
if either makes change, other can see

#### Deep Clone

2nd pointer points to ca new mem addr with copy of data from 1st pointer


