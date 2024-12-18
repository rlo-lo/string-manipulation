# string-manipulation

#String manipulater library 

## explanation
this project is a C library that provides string manipulation functions

## features
<stringlib.c>
- string_length : returns the length of the string
- to_upper_case : converts the string to uppercase
- to_lower_case : converts the string to lowercase
- trim_whitespace : removes leading and trailing whitespaces from the string


<stringlib.h>
Provides declarations for the functions implemented in stringlib.c.
Defines the functions that will be loaded from the dynamic library.


<test.c>
Loading the Dynamic Library: The dlopen function is used to load the libstringlib.so library.
dlsym: Retrieves the addresses of functions from the library and assigns them to function pointers.
String Processing: The loaded functions are used to calculate the string length, remove whitespace, and change the case of the string (uppercase and lowercase).
dlclose: Closes the library after its use.


## Execution Process
<Dynamic Linking>
dlopen: Loads the dynamic library.
dlsym: Retrieves the addresses of required functions (string_length, to_upper_case, to_lower_case, trim_whitespace).
String manipulation: Functions are executed on the string (str_literal), such as calculating the length, trimming whitespace, and changing the case.
dlclose: Closes the dynamic library after it is no longer needed.

//gcc -fPIC -shared -o libstringlib.so stringlib.c
//gcc -o test test.c -ldl
//./test


<Static linking>
//gcc -o -c stringlib.c          
//ar rcs libstringlib.a stringlib.o  
//gcc -o test test.c -L. -lstringlib
