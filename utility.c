/*
    This file is part of the String Manipulation program, it provides function definitions for all the functions
    declared in utility.h file

    File utility.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utility.h"

char *token;        //the token extracted from the command

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
        strtok((char *)command, " ");           //discard the delete worf from the command

        //obatin the remainder of the command>> <pos1, postn2,....,postnn> from <string>
        while(token = strtok(NULL, " ")){
            print_message(token);
            NEW_LINE;
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
        exit(EXIT_SUCCESS);             //exit the program
    }
    //* In case of unsupported command 
    else{
        NEW_LINE;
        printf(" UNKNOWN COMMAND \" %s \" Type help to see the list of permitted commands!", command);
        NEW_LINE;
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