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

#define UNKNOWN_COMMAND "UNKNOWN COMMAND "     //unknown command macro
#define WRONG_ARGUMENTS "WRONG ARGUMENTS "      //wrong arguments macro

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
    it takes a pointer to the character string to be printed to the terminal
    and a pointer to the character string having the error type 'error_type'
    it ruturns nothing
*/
void print_error(char *error_msg, char *error_type);

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


/*
    Function to check if the entered string is a number, it looks at each character in the string entered, when it encounters a 
    character that is not a number, it returns 0 (false)
    it takes a string 'str' to be checked if it is a number
    it returns 1 if all the characters in the string are numbers or 0 (false) if at least one of the characters in the string 
    is not a number
*/
int is_anumber(char str[]);

void debug(void);   //to be removed

#endif