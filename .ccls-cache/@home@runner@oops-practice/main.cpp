// oops is a programing technique in which things revolve around objects . 

// benifits of oops are to increase readability, managebility, flexability an reusability of code 

//the main four pillars of oops are 
//1.encapsulation
//2.inheritance 
//3.polymorphism
//4.abstraction

//class is user defined datatype which is used to create objects 

// State (or Attributes)or properties: This defines the characteristics or properties of the object. It's the data that describes what the object is.
// Examples: A car object might have a state that includes its color, model, year, mileage, and fuel level.
// Behavior (or Methods): This defines what the object can do. It's the set of actions or functions that the object can perform.
// Examples: The car object could have behaviors like start(), accelerate(), brake(), turn(), and refuel().

// EXAMPLE- MODELING A BANK ACCOUNT 
// lets imagine we want to create a software model for a bank account.

//Class: BankAccount

//object:An instace of BankAccount class(eg:account1,account2,account3)

//state(attributes):balance,account number,account holder name,account type,ifsc code

//Behaviour(methods):deposit(),withdraw(),check balance(),transfer())

//Why object is the "Instance of a Class"?

// The term "instance" signifies the relationship between an object and its class. It means:

// The object is a specific example or occurrence of the class-- Just like a house built from a blueprint is an instance of that blueprint, an object is an instance of its class.

// The object embodies the structure and behavior defined by the class-- It has the same attributes and can perform the same methods as other instances of that class.  //

#include<iostream>
using namespace std;
class BankAccount{
public:
int balance;
int accountNumber;
string accountHolderName;
string accountType;
int ifscCode;
void deposit(){
  cout<<"Enter the amount to be deposited"<<endl;
}
void withdraw(){
  cout<<"Enter Amount to be withdrawn"<<endl;
}
void checkBalance(){
  cout<<"Enter the account number"<<endl;
}
void transfer(){
  cout<<"Enter the account number to transfer"<<endl;
}
};

// int main(){
//   BankAccount account1;
//   account1.balance=10000;
//   account1.accountNumber=123456;
//   account1.accountHolderName="Raj";
//   account1.accountType="Savings";
//   account1.ifscCode=1234567;
//   account1.deposit(); 
//   account1.withdraw();
//   account1.checkBalance();
//   account1.transfer();
//   return 0;
// }


//for empty class means no properties , 1 byte of memory is allocated to object.
//for class with properties means memory is allocated to object.

//acess modifiers 
//public:
//private:
//protected:


// public:  Members declared as public are accessible from anywhere. This means that objects of the class, as well as functions outside the class, can directly access and modify public members.

//private: 
// private: Members declared as private are accessible only from within the class itself. This means that objects of the class cannot directly access or modify private members, and neither can functions outside the class. 

//protected: Members declared as protected are accessible from within the class itself, as well as from derived classes (classes that inherit from this class). This is a crucial concept in inheritance, as it allows controlled access to data and functions while maintaining encapsulation.


//getter setter 

//getter: a function that allows you to access the private member of a class.

//setter: a function that allows you to modify the private member of a class.

#include <iostream>
using namespace std;

class Employee{
private:
int salary;
public:
//setter
void setSalary(int s){
  salary=s;
}

//getter
int getSalary(){
  return salary;
}
};

int main(){
  Employee myObj;
  myObj.setSalary(50000);
  cout<<myObj.getSalary();
  return 0;
}


//----------------satatic and dynamic allocation--------------//

//Static Allocation

//Timing: Memory allocation happens at compile-time. The size of the memory block is fixed and known beforehand.

//Storage: Usually allocated on the stack.

//Lifetime: Memory remains allocated throughout the program's execution.

int num = 10;    // Static allocation of an integer
char name[20];   // Static allocation of a character array


//Dynamic Allocation

//Timing: Memory allocation happens at runtime using the new operator. The size of the memory block can be determined dynamically based on program needs.

//Storage: Usually allocated on the heap.

//Lifetime: Memory persists until explicitly deallocated using the delete operator

int* ptr = new int(5);       // Dynamic allocation of an integer
int* arr = new int[10];     // Dynamic allocation of an integer array
//delete ptr;                  // Deallocate the integer
//delete[] arr;                // Deallocate the array

//Constructor 

//Constructor is a special function that is automatically called when an object of a class is created. 

//Its primary purpose is to initialize the object's data members and ensure that the object is in a valid state before it can be used.

//Default constructor 

//the default constructor is a constructor that is automatically called when an object of a class is created without any arguments.

//if we had not defined a constructor, the compiler would have generated a default constructor for us.

class MyClass {
public:
    MyClass() {
        // Default constructor implementation
    }
};

//paramateriized constructor

//a constructor with parameters is a constructor that is automatically called when an object of a class is created with

//parametric constructor helps in initializing each data member of the class to diffrent values.

class MyClass1 {
public:
    MyClass1(variable){
      //parametric constructor implementation
    }
};

///---------------------this pointer----------------------- 

class Building{
public:
};

//this pointer

//every object in c++ has acess to its own address through an important pointer called this pointer

//It points to the object itself, allowing you to access the object's members (variables and functions) within the function's body.

//this is a pointer pointing on the object itself.

class Person {
public:
    string name;
    int age;

    void introduce() {
        cout << "Hi, I'm " << this->name << " and I'm " << this->age << " years old." << endl; 
    }
};

int main() {
    Person p;
    p.name = "Alice";
    p.age = 30;
    p.introduce(); // Output: "Hi, I'm Alice and I'm 30 years old."
}

//In this example, this->name in the introduce function refers to the name variable of the object on which introduce is called.


//---------------------EXAMPLE----------------------//

/*Imagine you're in a large office building with many different offices. Each office is like an object in C++, and within each office, there are things like desks, chairs, and computers.

Now, imagine you're inside one of these offices and you want to refer to the desk in your own office. You wouldn't say "the desk in the building" because that's not specific enough. Instead, you would say "this desk" to indicate that you're talking about the desk that's right there in your current office.

In C++, the this pointer works similarly. It's like a little label that's attached to each object, saying "this is me!" When you're inside a member function of an object (like sitting in your office), you can use this to refer specifically to the members (like the desk) of that particular object.

So, this is just a way for an object to refer to itself within its own member functions. It helps avoid confusion and makes sure you're accessing the right things within the right object. */

#include <iostream>
#include <string>

using namespace std;

class Office {
public:
    string occupantName;
    int deskNumber;

    void describeOffice() {
        cout << "This office is occupied by " << this->occupantName << "." << endl;
        cout << "The desk number is " << this->deskNumber << "." << endl;
    }
};

int main() {
    Office office1;
    office1.occupantName = "John";
    office1.deskNumber = 123;

    Office office2;
    office2.occupantName = "Sarah";
    office2.deskNumber = 456;

    office1.describeOffice();  
    // Output:
    // This office is occupied by John.
    // The desk number is 123.

    office2.describeOffice();  
    // Output:
    // This office is occupied by Sarah.
    // The desk number is 456.

    return 0;
}

/* The Office class is like a blueprint for office objects and contains two members :

occupantName: to hold the name of the person who sits there
deskNumber: to hold the number of the desk
The describeOffice(): function is like a member function of the Office class. When this function is called on a specific office object it refers to members occupantName and deskNumber of that office.

In the main function, we create two office objects.

office1 with John as the occupant and desk number 123.
office2 with Sarah as the occupant and desk number 456.

We call describeOffice() on each object. Each object uses this to refer to its own occupantName and deskNumber.*/



//-----------------when we use this function-----------------//

class Person {
public:
    string name;

    void setName(string name) {
        name = name;  // Ambiguous! Which 'name' are we assigning to?
    }
};

/* In this example, the setName() function has a parameter named name, which is the same as the class's member variable name. When you write name = name, the compiler gets confused:*/

void setName(string name) {
    this->name = name;  // Now it's clear!
}

/*By using this->name, we explicitly tell the compiler that we're referring to the name member of the object (the one pointed to by this), not the local parameter name. */


/* Why this is Essential in Disambiguation:

Clarity: It makes the code much clearer and easier to understand.

Correctness: It ensures that the correct variable is being accessed and modified.

Good Practice: Using this-> explicitly, even when it's not strictly necessary, is considered good coding practice because it makes your intentions crystal clear. */

class Rectangle {
public:
    int width, height;

    Rectangle(int width, int height) {
        this->width = width;  // 'this->' clarifies for each member
        this->height = height;
    }
};

/*In this constructor, this->width and this->height refer to the member variables, while width and height in the parameter list are the values passed to the constructor. */


//-------------------copy Constructor-----------------//


/*Imagine you have a favorite toy. You love it so much that you want an exact replica of it. A copy constructor in C++ is like a special machine that can create that exact replica for you.

Here's how it works:

1. **The Original:** You have your original toy.  
2. **The Copy Machine (Copy Constructor):** You put your toy in the copy machine. The machine carefully examines every detail of your toy – its color, shape, size, and any special features it might have.
3. **The Replica:** The machine then uses this information to create a brand new toy that is identical to your original. This new toy is independent of the original; if you change something on the new toy, it won't affect the original one.

In C++, instead of toys, we have objects (instances of classes). The copy constructor is a special function that takes an existing object and creates a new one with the same values for all its members (variables and sometimes other objects). This is important because, without a copy constructor, copying an object might just create a duplicate reference to the same object, which can cause problems if you modify one and expect the other to remain unchanged.

The copy constructor ensures that when you copy an object, you get a completely independent duplicate, just like getting a brand new replica of your favorite toy.
 */

//1- In C++, a copy constructor is a special type of constructor used to create a new object as a copy of an existing object of the same class. It is invoked automatically in certain scenarios, but you can also define your own custom copy constructor.

//Purpose: The main purpose of a copy constructor is to create a deep copy of an object, where a new object with its own distinct memory is created with the same values as the original object.

class MyClass {
public:
    MyClass(const MyClass& other); // Copy constructor declaration
};

//The copy constructor takes a reference to the object being copied as its argument (usually const to avoid modification)

//--------------------------------EXAMPLE---------------------//

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}  // Constructor

    Person(const Person& other) : name(other.name), age(other.age) {} // Copy constructor
};

int main() {
    Person p1("Alice", 30);  

    Person p2 = p1;    // Copy constructor called to create p2 as a copy of p1

    p2.name = "Bob";  // Modifying p2 doesn't affect p1

    cout << "p1: " << p1.name << ", " << p1.age << endl; 
    cout << "p2: " << p2.name << ", " << p2.age << endl; 
}

//output
//p1: Alice, 30
//p2: Bob, 30
//In this example, the copy constructor is used to create a new Person object p2 as a copy of the existing Person object p1. The copy constructor initializes the name and age members of p2 with the values from p1 

//In this example, the copy constructor ensures that p2 gets its own copy of the name string, so modifying p2.name doesn't affect p1.name.


//-------------------SHALLOW COPY AND DEEP COPY-----------------//

/* In the world of object copying in C++, you'll encounter two main types: shallow copy and deep copy. Imagine these as two different ways of duplicating a toy.

**Shallow Copy:**

Think of shallow copying as taking a quick snapshot of your toy. You capture the essential details: its name, color, maybe a few visible features. However, you don't recreate the intricate mechanisms or hidden compartments within the toy. In C++, a shallow copy simply duplicates the values of an object's member variables.

* **How it Works:** It copies the values stored in each member variable of the original object into the corresponding member variables of the new object.
* **When to Use:** Shallow copying is fine for simple objects that don't have pointers or complex data structures as members.
* **The Problem:** If an object has pointers to dynamically allocated memory (e.g., an array or another object), a shallow copy will simply copy the pointer's value. This means both the original and the copied object will point to the same memory location, leading to potential issues if one object modifies the shared data.

**Deep Copy:**

Imagine taking the time to meticulously recreate your toy, piece by piece, down to the smallest detail. You build every internal mechanism, every hidden compartment, ensuring a perfect replica. In C++, a deep copy goes beyond surface-level duplication; it creates a completely independent copy of an object, including any dynamically allocated resources.

* **How it Works:** It not only copies the values of member variables but also creates new copies of any objects or memory blocks pointed to by those members.
* **When to Use:** Deep copying is essential when an object has pointers to dynamically allocated memory. It ensures that changes made to the copy won't affect the original and vice versa.
* **Implementation:** You typically need to write a custom copy constructor and/or assignment operator overload to perform a deep copy.

**Illustrative Example:**

```c++
class Toy {
public:
    int id;
    string* name; // Pointer to dynamically allocated string

    Toy(int i, string n) : id(i) { name = new string(n); }

    // Shallow Copy Constructor (provided by default)
    // Toy(const Toy& other); 

    // Deep Copy Constructor
    Toy(const Toy& other) : id(other.id) { 
        name = new string(*other.name); // Create a new string
    }

    // Destructor (to prevent memory leaks)
    ~Toy() { delete name; }
};
```

In this code, the shallow copy constructor (commented out) would lead to both the original and copied `Toy` objects pointing to the same `name` string. The deep copy constructor fixes this by allocating a new `string` for the copy.

 */








