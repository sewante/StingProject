/*
    This file is part of the String Manipulation program, it provides test mechanism for the function written
    defined in string_utility.c file

    File main.c
*/

#include "string_utility.h"
#include "utility.h"

int main(int argc, char const *argv[])
{
    const char *input_string;
    while(1){
        input_string = prompt((char *)input_string);
        command_interpreter(input_string);
    }

}

