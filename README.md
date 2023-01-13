# Simple utils in C
> **IMPORTANT! This project is for recreational purposes and is a work in progress.**

This project is a collection of c libraries to solve some small needs when we are developing.
Some of these libraries are inspired by the [C++ standard libraries](https://en.cppreference.com/w/cpp/standard_library)
and the [Golang standard libraries](https://pkg.go.dev/std).

## Library list

- ***su_data_structures.h***: library with dynamic arrays, hash tables, linked list, binary trees, etc, implementations.
- ***su_flags.h***: library with functions to handle the program flags.
- ***su_show_memory.h***: library with functions to dhow the memory.
- ***su_string_view.h***: library with a string view implementation.
- ***su_testing.h***: library with functions to handle the testing.

## Usage

This collection of libraries are developed in [stb-style](https://github.com/nothings/stb) (header-only library), This 
means that you can find the declaration and definition of the structures and functions in the header file.

To use the library only as a header you have to include as usual.
```c
#include "su_string_view.h"
```

To include the definitions of the library you have to define the specified macro in the library.
```c
#define SU_STRING_VIEW_IMPLEMENTATION
#include "su_string_view.h"
```

## Documentation
> **IMPORTANT! Not documented yet.**

Each library is documented in the declaration part of the header with comments.

To build the general documentation use [doxygen](https://www.doxygen.nl/), it is a common tool to generate documentation 
from annotated code sources (C, C++, PHP, Java, Python, etc).

```shell
doxygen
```
