# CPP-Modules
CPP-Modules are C++ projects with the main goal of OOP where we will learn about Namespaces, classes, stdio streams, errors handling in C++, STL, Memory Allocation, References, Pointers to member functions.  
## CPP00  
In this module we learned how to create a class and use it and how to use namespaces correctly, and the usage of streams and correctly error handling in C++.  
EX00 (Megaphone):  
Create a program which take command line arguments then capitalize each alphapatical character in the arguments then output them to the standard output in C++ manner.  
EX01 (My Awesome PhoneBook):  
Create a program which is similar to an old contacts software that can only store 8 temporary contacts, the program accepts 3 commands: ADD, SEARCH, EXIT where ADD will add a contact and SEARCH will search for a contact with specific index and EXIT is self explanatory.  
EX02 (The Job Of Your Dreams):  
This exersice will simulate a problem about a lost source file where you only have the header file for the Account class declerations with tests.cpp source file which will test the Account class methods with an old log file of the expected result you should recreate the lost source file using the info provided.  
## CPP01
In this module we learned how to do memory allocation in C++ using new and delete, and we learned about the difference between pointers and references and how to create pointers to members functions.  
EX00 (BraiiiiiiinnnzzzZ):  
Create a class called zombie which has an attribute name and announce method which will print zombie name with Brainzzzzzz, then create 2 functions one newZombie which allocate zombie object then returns a pointer to it and the other is randomChump which will create a zombie then announce it and destroy it.  
EX01 (Moar brainz!):  
Create a function called zombieHorde which takes 2 arguments N and name, it will create an array of zombies with singl allocation then it will set each zombie name in the array then return the pointer to the first element in the array.   
EX02 (HI THIS IS BRAIN):  
Create a str variable which holds the value "HI THIS IS BRAIN", then create 2 variables first a pointer to str second a reference to str then print the address of the variables  
EX03 (Unnecessary violence):  
Create 3 classes Weapon which holds string attribute and getType, setType methods, HumanA with a constructor which always takes a name with a weapon, HumanB which is the same as HumanA but doesn't always have a weapon.  
EX04 (Sed is for losers):  
Create a program in C++ which takes 3 arguments: filename, s1, s2 it will create a new file with the same filename with .replace appended to it that has all matches of s1 replaced with s2.  
EX05 (Harl 2.0):
Create a class called Harl which has 5 methods debug, info, warning, error, complain which takes a string, the goal is to execute the correct method based on the level provided without a forest of if conditions using pointers to members functions.  
EX06 (Harl filter):  
The same as ex05 but it should print all the levels above the level provided as an argument with switch statment.  
## CPP02
In this module we learned about creating classes in orthodox canonical class and the fixed datatype which was used on older computers for memory optimization, Ad-hoc polymorphism, overloads.  
EX00 (My First Class in Orthodox Canonical Form):  
In this excercise we learned how to create our first class in orthodox canonical form where we always have a default constructor, copy constructor, destructor, copy assignment operator.  
EX01 (towards a more useful fixed-point number class):  
In this excercise we built the basics of fixed class to store a fixed point value and convert it to float/int  
EX02: (Now we’re talking):  
In this excercise we implemented overloads for arithmetics operators to use in our fixed class.  
EX03 (BSP):  
In this excercise we created a class called Point that stores x and y of fixed class and created a bsp function which is provided with a triangle vertices and a point, which should check if the point is inside the triangle or not which was done using the determinant.  
## CPP03
In this module we learned about inheritance by creating a derived classes that inherits members of a base class  
EX00 (Aaaaand... OPEN!):  
In this excersice we created a class called ClapTrap which is simply a trap with some attributes like health,energy,damage which will be used as base class in later excersices.  
EX01 (Serena, my love!):  
In this excersice we created a derived class called ScavTrap which will inherit from claptrap and override some members of claptrap to display the correct message and modify the base attributes, and create a unique capacity for this trap.  
EX02: (Repetitive work):  
This excercise we similar to the one before, a new derived class called FragTrap which override members and modify attributes and has a unique capacity.  
EX03 (Now it’s weird!):  
In this excersice we created a dervied class called DiamondTrap that inherits from FragTrap and ScavTrap, the point of this exercise is to learn about the diamond inheritance problem and how to fix it and shadowing by creating an attribute for diamondtrap with the same name as one in claptrap. 
## CPP04
In this module we learned about Subtype polymorphism, Abstract classes, Interfaces (Pure abstract classes)  
EX00 (Polymorphism):  
In this excersice we created an abstract animal class and 2 derived classes dog and cat which will inherit animal class and override makeSound member in the derived class to output the correct sound.  
EX01 (I don’t want to set the world on fire):  
In this exercise we created a class called brain which has an array of 100 ideas which dog and cat will create an instance of and use, the goal is to create a deep copy of the animals instead of shallow copy.  
EX02 (Abstract class):  
The goal of this excercise is simple, prevent animal class from being instantiable without a derived class.  
EX03 (Interface & recap):  
In this excercise the goal was to learn what an interface is and how it can be useful when creating a system of a game where we will create a lot of materials and characters of varying types that we want to be compatible with each other.  
## Resources:
OOP: https://www.w3schools.com/cpp/cpp_oop.asp  
iostream: https://cplusplus.com/reference/iostream/  
iomanip: https://cplusplus.com/reference/iomanip/  
ios_base: https://cplusplus.com/reference/ios/ios_base/  
iostate: https://cplusplus.com/reference/ios/ios_base/iostate/  
Input/output with files: https://cplusplus.com/doc/tutorial/files/  
endl: https://en.cppreference.com/w/cpp/io/manip/endl  
string: https://cplusplus.com/reference/string/string/  
basic_string: https://cplusplus.com/reference/string/basic_string/  
SSO: https://rrmprogramming.com/article/small-string-optimization-sso-in-c/  
getline: https://cplusplus.com/reference/string/string/getline/  
ctime: https://cplusplus.com/reference/ctime/  
STL: https://www.geeksforgeeks.org/the-c-standard-template-library-stl/  
operator overloading: https://en.cppreference.com/w/cpp/language/operators  
Vector Constructor: https://cplusplus.com/reference/vector/vector/vector/  
iterator: https://en.cppreference.com/w/cpp/iterator/iterator  
References: https://www.geeksforgeeks.org/references-in-cpp/  
C++ new/delete: https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/  
Pointers to member functions: https://websites.umich.edu/~eecs381/handouts/Pointers_to_memberfuncs.pdf  
for_each: https://en.cppreference.com/w/cpp/algorithm/for_each  
mem_fun_ref: https://en.cppreference.com/w/cpp/utility/functional/mem_fun_ref  
References: https://www.geeksforgeeks.org/references-in-cpp/  
Constructors and member initializer lists: https://en.cppreference.com/w/cpp/language/constructor  
Orthodox canonical form: https://riceset.com/C++/The-Orthodox-Canonical-Class-Form  
IEEE Standard 754 Floating Point Numbers: https://www.geeksforgeeks.org/ieee-standard-754-floating-point-numbers/  
FixedPoint: https://vanhunteradams.com/FixedPoint/FixedPoint.html  
Determinant: https://en.wikipedia.org/wiki/Determinant  
Shoelace formula: https://en.wikipedia.org/wiki/Shoelace_formula  
Inheritance: https://www.geeksforgeeks.org/inheritance-in-c/  
Virtual function: https://www.geeksforgeeks.org/virtual-function-cpp/  
Diamond inheritance problem: https://www.geeksforgeeks.org/diamond-problem-in-cpp/  
Variable Shadowing: https://en.wikipedia.org/wiki/Variable_shadowing  
GCC Warning Options: https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html  
Abstract Class: https://en.cppreference.com/w/cpp/language/abstract_class  
