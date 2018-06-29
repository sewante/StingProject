/*
    This file is part of the String Manipulation program, it provides function prototypes for all the functions
    defined in utility.c file

    File name: utility.h
*/

#ifndef UTILITY_H_
#define UTILITY_H_
/*  #####################################################################################################################
                                                    MACROS
    ######################################################################################################################
*/
#define NEW_LINE {printf("\n");}                //new line macro

/*
    ######################################################################################################################
                                                    FUNCTION PROTOTYPES
    ######################################################################################################################
*/


/* 	function to interprete the commands typed at the terminal
    it takes the a pointer to the constant character string to be interpreted
    it ruturns nothing
*/
void command_interpreter(const char *command);

/* 	function to print a message at the terminal
    it takes a pointer to the character string to be printed to the screen
    it ruturns nothing
*/
void print_message(char *message);

/* 	function to print error message on the terminal
    it takes a pointer to the character string to be pronted to the terminal
    it ruturns nothing
*/
void print_error(char *error_msg);

/* 
    function to print the prompt and capture the command from the terminal
    it takes as input a buffer where the command is stored
    it returns the buffer to which the command is written
*/
const char *prompt(char buffer[]);

/*
    Function to print the help menu for the list of permitted commands in the string manipulation program
    it takes nothing
    it returns nothing
*/
void print_help_menu(void);

#endif