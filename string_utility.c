/*
    This file is part of the String Manipulation program, it provides function definitions for all the functions
    declared in string_utility.h file

    File name: string_utility.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "string_utility.h"


/* 	function to reverse the string 
	it returns NULL if the string 'str' is empty or NULL is passed to it or the string 'str' in the reverse order
*/
char *reverse_string(char *str){

	//check for null
	if(str == 0){
		return NULL;
	}
	//skip empty string
	if(*str == 0){
		return NULL;
	}

	//obtain the range of the string
	char *beginning = str;
	char *end = beginning + strlen(str) - 1; //remove the null terminater '\0'
	char temp;	//for swapping

	//as long as end is greater than beginning continue to reverse
	while(end > beginning){

		//swap
		temp = *beginning;
		*beginning = *end;
		*end = temp;

		//go to the next position
		++beginning;
		--end;
	}

	return str;
}

/* 	function to remove a specified character from the string 
	returns the string 'str' without the character at 'position' and or NULL when pos > length of str
*/
char *remove_character(char *str, int position){
	char buffer[strlen(str)];		//create a buffer of the same size as the string where u want to store the characters that you need
	int counter = 1;
	int pos = 0;
	
	/*	check if the position is less than or greater than the number of characters in the str 
		i.e. strlen(str) >= position 
	*/
	
	if(position > strlen(str)){
		return NULL;
	}
	else if(position < 0){
		return NULL;
	}
	
	/* loop through the str and identify the character that is not required */
	while(*str != '\0'){			//as long as the string has more characters

		if(counter != position){
			buffer[pos++] = *str;	//add the character to the buffer 
		}
		else{
			buffer[pos] = '\0';		//delete the character that is not needed
		}

		*str++;
		counter++;
	}
	buffer[pos] = '\0';		//terminate the string
	
	strcpy(str,buffer);		//copy the buffer to the str
	
	return str;
}

/* 	function to remove a series of characters specified in the positions array 'positions[]' 
    it takes the pointer to a character string 'str' , the number of elements in the positions 
	array and the positions array which contain the positions which are to be removed returns the
	string 'str' without the characters at 'positions' specified in the positions arry 
    or NULL when str is NULL;
*/
char *delete_characters(char *str, int positions[], int pos_size){
	
	int pos = 0;			//the position in the positions[] array
	/* loop through the string as long as there are more characters in it*/
	while(pos < pos_size){

		str = remove_character(str,positions[pos]);
		++pos;		//go to the next position in the positions[] array
	}
	return str;
}

/* 	function to replace a specified character from the string with another supplied character 'new_char'
	returns the string 'str' with the character at 'position' replaced with 'new_char'
    and or NULL when pos > length of str
*/
char *replace_character(char *str, unsigned char new_char, int position){
    char buffer[strlen(str)];		//create a buffer of the same size as the string where u want to store the characters that you need
	int counter = 1;                //counter to go through the entire string 'str'
	int pos = 0;                    //tracks the position in the buffer
	
	/*	check if the position is less than or greater than the number of characters in the str 
		i.e. strlen(str) >= position 
	*/
	
	if(position > strlen(str)){
		return NULL;
	}
	else if(position < 0){
		return NULL;
	}
	
	/* loop through the str and identify the character that is to be replaced */
	while(*str != '\0'){			//as long as the string has more characters

		if(counter != position){
			buffer[pos++] = *str;	//add the character to the buffer 
		}
		else{
			buffer[pos] = new_char;		//replace that character at the required position
		}

		*str++;
		counter++;
	}
	buffer[pos] = '\0';		//terminate the string
	
	strcpy(str,buffer);		//copy the buffer to the str
	
	return str;
}

/* 	function to double the string 'str' 
    it return the string doubled or NULL if the string str supplied is empty ("") or if NULL is passed 
*/
const char *double_string(const char *str){

    /* check if the string is empty and return NULL if true */
    if(*str == 0){
        return NULL;
    }
    /* check if the string is NULL and return NULL */
    if(str == NULL){
        return NULL;
    }

    char *str_duplicate = strdup(str);   //create a duplicate copy of the provided string

    strcat((char *)str, (const char *)str_duplicate);   //concatenate it to the previous str

    return str;
}