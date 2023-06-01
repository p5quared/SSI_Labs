# Vector

Vector is a sequence container that encapsulates dynamic size arrays.
The specifics of the STL implementation is very complicated to understand, so I will not explain it here.
However, at its core, vector is incredibly simple.

## Vector Core
All vector does is encapsulate a dynamic array. The array is allocated on the heap, and the vector class manages the memory.
* The vector class has a pointer to the array, and it also has a size and capacity variable.
* The size variable is the number of elements in the vector, and the capacity variable is the number of elements that the vector can hold before it needs to reallocate.
* The vector class also has a pointer to the end of the array, which is the address of the last element in the vector.

## Vector Functions
The following are some of the basic functions of the vector class:
* `push_back()` adds an element to the end of the vector. If the vector is full, it will reallocate the array to a larger size.
* `pop_back()` removes the last element in the vector.
* `size()` returns the number of elements in the vector.
* `capacity()` returns the number of elements that the vector can hold before it needs to reallocate.

## Instructions
Implement the vector class. You can use the STL vector as a reference, but you cannot use any STL functions.
* You must implement the following functions:
  * `push_back()`
  * `pop_back()`
  * `size()`
  * `capacity()`
* You must also implement a constructor and destructor.
* Remember that the vector class must be templated.

Additional Challenge:
* Implement the `at()` function.
* Implement the `[]` operator.
* Implement the `front()` and `back()` functions (these return the first and last elements in the vector).
* Implement the `reserve()` function (this function allocates memory for the vector without adding any elements).
* Implement the `clear()` function (this function removes all elements from the vector).
* Implement the `insert()` function (this function inserts an element at a specified index).
* Implement the `erase()` function (this function removes an element at a specified index).
* Implement the `swap()` function (this function swaps the contents of two vectors).

_Very Hard:_
* Implement an iterator for the vector class.
* Implement `emplace_back()`.