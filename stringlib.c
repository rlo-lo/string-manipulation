#include "stringlib.h"
#include <string.h>
#include <ctype.h>

int string_length(const char* str){
return strlen(str);
}

void trim_whitespace(char* str){
	char* end; 
	while(isspace((unsigned char)*str)) str++; 
	end = str + strlen(str)-1; 
	while (end > str && isspace((unsigned char)*end)) end--; 

	*(end+1) = 0;}

void to_upper_case(char* str) {
        while(*str) {
        *str = toupper((unsigned char)*str);
        str++;
}}

void to_lower_case(char *str) {
        while(*str) {
        *str = tolower((unsigned char)*str);
        str++;
}
}
 
