# C++ Pointers
This README.md file provides a brief overview of C++ pointers, references, dynamic memory allocation, smart pointers, and other important concepts related to memory management in C++.

Table of Contents
* Introduction
* Pointers
* References
* Dynamic Memory Allocation
* Smart Pointers
* Conclusion
## Introduction
In C++, pointers are powerful tools that allow direct manipulation and access to memory. They enable efficient memory management and facilitate various programming techniques. Understanding pointers is crucial for writing efficient and flexible C++ code.

## Pointers
A pointer is a variable that stores the memory address of another variable. By using pointers, we can indirectly access and modify the value of the variable it points to. Pointers are denoted by the `*` symbol. Here's an example:
```c++
int number = 42;
int* pointer = &number;  // pointer points to the address of number
```
In the above example, `pointer` stores the address of the variable `number` using the address-of operator (`&`) We can dereference the pointer to access the value it points to:
```c++
int value = *pointer;  // dereferencing the pointer
```
Pointers are useful for various purposes, such as passing data by reference, creating dynamic data structures, and working with low-level memory operations.

## References
References provide an alternative way to create aliases or references to existing variables. Unlike pointers, references cannot be reassigned to refer to different variables. They are declared using the `&` symbol. Here's an example:
```c++
int number = 42;
int& reference = number;  // reference refers to the variable number
```
References are commonly used for function parameters to avoid making copies of large objects and to create more readable code.

## Dynamic Memory Allocation
Dynamic memory allocation allows us to allocate memory at runtime.
This is useful for creating data structures whose size is not known at compile time.
In C++, we can dynamically allocate memory using the `new` and `delete` operators. Here's an example:
```c++
int* pointer = new int;  // dynamically allocate memory for an integer
*pointer = 42;  // dereference the pointer to access the value it points to, assigning it the (integer) value 42
```
The `delete` operator is used to free the memory allocated by `new`:
```c++
delete pointer;  // free the memory allocated by new
```
It is important to deallocate dynamically allocated memory to avoid memory leaks. If memory is not deallocated, it will remain allocated until the program terminates.
Your computer cannot tell that the memory is no longer needed, so it will not be able to use it for other purposes.

## Smart Pointers
Smart pointers are objects that behave like pointers but provide additional functionality, such as automatic memory management.
They are useful for managing dynamically allocated memory and avoiding memory leaks.
Smart pointers are defined in the `<memory>` header file. 
There are three types of smart pointers: `unique_ptr`, `shared_ptr`, and `weak_ptr`.
* `unique_ptr` - A smart pointer that owns and manages the memory it points to. It cannot be copied, but it can be moved.
* `shared_ptr` - A smart pointer that can be copied and shared. It keeps track of the number of references to the memory it points to, and it automatically deallocates the memory when the last reference is destroyed.
* `weak_ptr` - A smart pointer that can be copied but not shared. It is used in conjunction with `shared_ptr` to prevent memory leaks caused by circular references.

To construct a smart pointer, we can use the `std::make_unique` and `std::make_shared` functions, which
take the arguments to be passed to the constructor of the object as parameters and return a smart pointer to the object.

`unique_ptr` is the simplest smart pointer and most of the time the answer for your needs.
Example:
```c++
std::unique_ptr<int> pointer = std::make_unique<int>(42);  // dynamically allocate memory for an integer
```



