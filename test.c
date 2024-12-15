#include "stringlib.h"
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
int main() {
void *lib_handle = dlopen("./libstringlib.so", RTLD_LAZY); 
if(!lib_handle){
fprintf(stderr, "Erorr loading library: %s\n", dlerror()); 
return 1; 
}

int(*string_length)(const char*); 
void(*to_upper_case)(char *); 
void(*to_lower_case)(char *); 
void(*trim_whitespace)(char *); 

string_length = (int(*)(const char*))dlsym(lib_handle, "string_length"); 
to_upper_case=(void (*)(char*))dlsym(lib_handle, "to_upper_case"); 
to_lower_case=(void (*)(char*))dlsym(lib_handle, "to_lower_case"); 
trim_whitespace = (void (*)(char*))dlsym(lib_handle, "trim_whitespace"); 

const char* str_literal = "goodbye, 2024!!!"; 
char str1[100]; 
strcpy(str1, str_literal); 

printf("String length: %d\n", string_length(str1)); 
trim_whitespace(str1); 
printf("Trimmed string: '%s'\n", str1); 

to_upper_case(str1);
printf("Uppercase string: %s\n", str1);

to_lower_case(str1);
printf("Lowercase string: %s\n", str1);
dlclose(lib_handle); 

return 0 ; 

}
