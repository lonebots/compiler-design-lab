/*
Jishnu Suresh
TCR18CS029
Experiment 1 : Lexical Analyser in C 
*/

// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// checking if buffer contains a keyword
int isKeyword(char buffer[])
{
    // keyword 
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef", "union",
                             "unsigned", "void", "volatile", "while"};
    // setting flag
    int i, flag = 0;
    for (i = 0; i < 32; ++i)
    {
        if (strcmp(keywords[i], buffer) == 0)
        {
            // setting flag to 1 
            flag = 1;
            break;
        }
    }
    // returning flag
    return flag;
}

// main function
int main()
{
    // variables initialised 
    char ch, buffer[15], operators[] = "+-*/%=";
    
    // file pointer 
    FILE *fp;

    // variables for counting
    int i, j = 0;

    // opening file
    fp = fopen("prg1.txt", "r");
    if (fp == NULL)
    {
        printf("error while opening the file\n");
        exit(0);
    }

    // while loop for looping through each character
    while ((ch = fgetc(fp)) != EOF)
    {
        for (i = 0; i < 6; ++i)
        {
            if (ch == operators[i]) // print if operator
                printf("%c is operator\n", ch);
        }
        if (isalnum(ch)) // print if alphanumeric
        {
            buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && (j != 0)) //for space and \n
        {
            buffer[j] = '\0';
            j = 0;
            if (isKeyword(buffer) == 1)
                printf("%s is keyword\n", buffer);// for keyword
            else
                printf("%s is indentifier\n", buffer); // for identifier
        }
    }

    fclose(fp); // closing file
    return 0;
}