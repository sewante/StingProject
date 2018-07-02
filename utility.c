/*
    This file is part of the String Manipulation program, it provides function definitions for all the functions
    declared in utility.h file

    File utility.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "utility.h"


/* 	function to interprete the commands typed at the terminal
    it takes the a pointer to the constant character string to be interpreted
    it ruturns nothing
*/
void command_interpreter(const char *command){

    /* check to see if the command entered is not empty */
    if(command == NULL){
        return;
    }
    /* for doubling a string */
    if(strncmp(command, "double", 6) == 0){
        //do what u want with the double command
    }
    else if(strncmp(command, "reverse", 7) == 0){
        //do what u want with reverse coomad
    }
    else if(strncmp(command, "delete", 6) == 0){
        //do what you want with delete command >> delete <pos1, postn2,....,postnn> from <string>
        strtok((char *)command, " ");           //discard the delete word from the command

        char *postions_string = strtok(NULL, " ");   //extract the positions string "<pos1, postn2,....,postnn>""

        //********fix this error if only delete is typed

        char *from_keyword = strtok(NULL, " ");     //extract the from keyword "from"
        char *string = strtok(NULL," ");           //extract the string from which the characters are to be deleted "<string>"

        int positions[strlen(postions_string)];   //the array to contain the converted positions from string to int
        char *token;                              //token extracted
        int index = 0;                            //index to go through the positions[]
        //ensure that the from keyword is in the typed command
        if(strncmp(from_keyword, "from", 4) == 0){
            /* extract the positions specified in <pos1, postn2,....,postnn> and */
            token = strtok(postions_string, ",");

            while(token != NULL) {

                //convert the token to an int if it is a digit
                if(is_anumber(token)){           //****************fix this
                    positions[index] = atoi(token);
                    ++index;                    //go to next position
                }
                else{
                    print_error("wrong arguments in the command", WRONG_ARGUMENTS);
                    return;                         //if any of the argumens is wrong, return (do not process other arguments)
                }
                NEW_LINE;
                token = strtok(NULL, ",");
            }
            for(index = 0; index < 3; ++index){
                printf(">> %i, ",positions[index]);
            }
        }
        else{
            print_error((char *)command, UNKNOWN_COMMAND);
        }

    }
    else if(strncmp(command, "replace", 7) == 0){
        //do what you want with replace command
    }
    
    else if (strncmp(command, "encrypt", 7) == 0){
        //do waht you want with encrypt command
    }
    else if(strcmp(command, "help") == 0){
        //do what you want with the help command
    }
    else if(strcmp(command, "exit") == 0){
        //do what you want with exit command
        NEW_LINE;
        print_message("Bye...");
        NEW_LINE;
        exit(EXIT_SUCCESS);             //exit the program
    }
    //* In case of unsupported command 
    else{
        print_error((char *)command, UNKNOWN_COMMAND);   //print error message
    }
    
}

/* 
    function to print the prompt and capture the command from the terminal
    it takes as input a buffer where the command is stored, the buffer can accept a maximum of 1000 bytes (1000 ASCII characters)
    it returns the buffer to which the command is written
*/
const char *prompt(char buffer[]){
    NEW_LINE;
    printf(" Enter a command> ");
    fgets(buffer, 1000, stdin);
    NEW_LINE;
    buffer = strtok(buffer, "\n");  //remove the new line character which is appended implicitly by the fgets() function

    return (const char *)buffer;
}

/* 	function to print a message at the terminal
    it takes a pointer to the character string to be printed to the screen
    it ruturns nothing
*/
void print_message(char *message){
    NEW_LINE;
    printf(" MESSAGE: %s",message);
}

/* 	function to print error message on the terminal 
    it takes a pointer to the character string to be printed to the terminal
    and a pointer to the character string having the error type 'error_type'
    it ruturns nothing
*/
void print_error(char *error_msg, char *error_type){

    NEW_LINE;
    printf(" ERROR: %s> \" %s \", Type help to see the list of permitted commands!",error_type, error_msg);
    NEW_LINE;
}
/*
    Function to check if the entered string is a number, it looks at each character in the string entered, 
    when it encounters a character that is not a number, it returns 0 (false)
    it takes a string 'str' to be checked if it is a number
    it returns 1(true) if all the characters in the string are numbers or 0 (false) if at least one of the characters in the string 
    is not a number
*/
int is_anumber(char *str){
    int counter = 0;
    int isDigit = 0;
	/*	loop through the string 'str' and if a character at any position is not a number return false (0)
		otherwise if all the characters in the str are numbers return true (1) 
	*/
	do{
		if(isdigit(*str)){
			isDigit = 1;		//the char at this position is a number (true)
		}
		else{
			isDigit = 0;		//the char at this position is not a number (false)
		}
		*str++;
		++counter;
	}while((isDigit == 1) && (*str != '\0'));	

    return isDigit;
}

/* to beremoved */
void debug(void){
    printf("####> I havefailed ### \n");
}