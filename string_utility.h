
/*
    This file is part of the String Manipulation program, it provides function prototypes for all the functions
    defined in string_utility.c file

    File name: string_utility.h
*/

#ifndef STRING_UTILITY_H_
#define STRING_UTILITY_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    ######################################################################################################################
                                                    FUNCTION PROTOTYPES
    ######################################################################################################################
*/

/* 	function to reverse the string 
	it returns NULL if the string 'str' is empty or NULL is passed to it or the string 'str' in the reverse order
*/
char *reverse_string(char *str);

/* 	function to remove a specified character from the string 
    it takes the pointer to a character string and the position where athe character is to be removed
	returns the string 'str' without the character at 'position' and or NULL when pos > length of str
*/
char *remove_character(char *str, int position);

/* 	function to remove a series of characters specified in the positions array 'positions[]' 
    it takes the pointer to a character string 'str' , the number of elements in the positions 'positions_size'
	array and the positions array which contain the positions which are to be removed returns the
	string 'str' without the characters at 'positions' specified in the positions arry 
    or NULL when str is NULL;
*/
char *delete_characters(char *str, int positions[], int positions_size);

/* 	function to replace a specified character from the string with another supplied character 'new_char'
	returns the string 'str' with the character at 'position' replaced with 'new_char'
    and or NULL when pos > length of str
*/
char *replace_character(char *str, unsigned char new_char, int position);

/* 	function to double the string 'str' 
    it return the string doubled or NULL if the string str supplied is empty ("") or if NULL is passed 
*/
const char *double_string(const char *str);
#endif