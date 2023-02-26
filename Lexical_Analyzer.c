/* front.c - a lexical analyzer system for simple arithmetic expressions */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef FRONT_H
#define FRONT_H

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26
#define LESSER_OP 31
#define GREATER_OP 32
#define EQUAL_OP 33
#define NEQUAL_OP 34
#define LEQUAL_OP 35
#define GEQUAL_OP 36
#define SEMICOLON 37
#define MOD_OP 38
#define LEFT_CBRACE 39
#define RIGHT_CBRACE 40
#define KEY_READ 41
#define KEY_PRINT 42
#define KEY_WHILE 43
#define KEY_DO 44



int lex();

#endif

/* Global Variable */
int nextToken;

/* Local Variables */
static int charClass;
static char lexeme [100];
static char nextChar;
static int lexLen;
static FILE *in_fp;

/* Local Function declarations */
static void addChar();
static void getChar();
static void getNonBlank();

/******************************************************/
/* main driver */
int main(int argc, char *argv[]) 
{
    /* Open the input data file and process its contents */
    if ((in_fp = fopen(argv[1],"r")) == NULL) {
        printf("ERROR - cannot open front.in \n");
    } else {
        getChar();
        do {
            lex();
            //expr();
        } while (nextToken != EOF);
    }
    return 0;
}

/*****************************************************/
/* lookup - a function to lookup operators and parentheses and return the 
 * token */
static int lookup(char ch) {
    switch (ch) {
        case '(':
            addChar();
            nextToken = LEFT_PAREN;
            getChar();
            break;
        case ')':
            addChar();
            nextToken = RIGHT_PAREN;
            getChar();
            break;
        case '+':
            addChar();
            nextToken = ADD_OP;
            getChar();
            break;
        case '-':
            addChar();
            nextToken = SUB_OP;
            getChar();
            break;
        case '*':
            addChar();
            nextToken = MULT_OP;
            getChar();
            break;
        case '/':
            addChar();
            nextToken = DIV_OP;
            getChar();
            break;
        case '=':
            addChar();
            getChar();
            if(nextChar == '='){
                addChar();
                nextToken = EQUAL_OP;
                getChar();
                break;
            }
            else{
                nextToken = ASSIGN_OP;
            }
            break;
        case '<':
            addChar();
            getChar();
            if(nextChar == '>'){        // Determines whether < is Nequal, Lequal, or lesser operater
                addChar();
                nextToken = NEQUAL_OP;
                getChar();
                break;
            }
            else if(nextChar == '='){
                addChar();
                nextToken = LEQUAL_OP;
                getChar();
                break;
            }
            else{
                nextToken = LESSER_OP;
            }
            break;
        case '>':
            if(ch == '='){          // determines whether > is Gequal or Greater operater
                addChar();
                nextToken = GEQUAL_OP;
                getChar();
                break;
            }
            else{
                addChar();
                nextToken = GREATER_OP;
                getChar();
                break;
            }
        case ';':
            addChar();
            nextToken = SEMICOLON;
            getChar();
            break;
        case '%':
            addChar();
            nextToken = MOD_OP;
            getChar();
            break;
        case '{':
            addChar();
            nextToken = LEFT_CBRACE;
            getChar();
            break;
        case '}':
            addChar();
            nextToken = RIGHT_CBRACE;
            getChar();
            break;
        default:
            if(ch != EOF){      // checks to see if the unknown token is Unknown or EOF
                addChar();
                nextToken = UNKNOWN;
                getChar();
            }
            else{
                addChar();
                nextToken = EOF;
                getChar();  
            }
            break;
    }
    return nextToken;
}

/*****************************************************/
/* addChar - a function to add nextChar to lexeme */
static void addChar() {
    if (lexLen <= 98) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
    } else {
        printf("Error - lexeme is too long \n");
    }
}

/*****************************************************/
/* getChar - a function to get the next character of input and determine its 
 * character class */
static void getChar() {
    if ((nextChar = getc(in_fp)) != EOF) {
        if (isalpha(nextChar)){
            charClass = LETTER;
        }
        else if (isdigit(nextChar)){
            charClass = DIGIT;
        }
        else{
        charClass = UNKNOWN;
        }
    }
    else {
        charClass = EOF;
    }
}

/*****************************************************/
/* getNonBlank - a function to call getChar until it returns a non-whitespace 
 * character */
static void getNonBlank() {
    while (isspace(nextChar)) getChar();
}
/*****************************************************/
/*tPrint - a function to print the token according to the token number.*/
static void tPrint(){
    if(nextToken == 10){
        printf("INT_LIT\n");
    }
    else if (nextToken == 11){
        printf("IDENT\n");
    }
    else if (nextToken == 20){
        printf("ASSIGN_OP\n");
    }
    else if (nextToken == 21){
        printf("ADD_OP\n");
    }
    else if (nextToken == 22){
        printf("SUB_OP\n");
    }
    else if(nextToken == 23){
        printf("MULT_OP\n");
    }
    else if(nextToken == 24){
        printf("DIV_OP\n");
    }
    else if(nextToken == 25){
        printf("LEFT_PAREN\n");
    }
    else if(nextToken == 26){
        printf("RIGHT_PAREN\n");
    }
    else if(nextToken == 31){
        printf("LESSER_OP\n");
    }
    else if(nextToken == 32){
        printf("GREATER_OP\n");
    }
    else if(nextToken == 33){
        printf("EQUAL_OP\n");
    }
    else if(nextToken == 34){
        printf("NEQUAL_OP\n");
    }
    else if(nextToken == 35){
        printf("LEQUAL_OP\n");
    }
    else if(nextToken == 36){
        printf("GEQUAL_OP\n");
    }
    else if(nextToken == 37){
        printf("SEMICOLON\n");
    }
    else if(nextToken == 38){
        printf("MOD_OP\n");
    }
    else if(nextToken == 39){
        printf("LEFT_CBRACE\n");
    }
    else if(nextToken == 40){
        printf("RIGHT_CBRACE\n");
    }
    else if(nextToken == 41){
        printf("KEY_READ\n");
    }
    else if(nextToken == 42){
        printf("KEY_PRINT\n");
    }
    else if(nextToken == 43){
        printf("KEY_WHILE\n");
    }
    else if(nextToken == 44){
        printf("KEY_DO\n");
    }
    else if(nextToken == 99){
        printf("UNKNOWN\n");
    }
    return;
}
/*****************************************************/
/* lex - a simple lexical analyzer for arithmetic expressions */
int lex() {
    lexLen = 0;
    getNonBlank();
    char strRead[] = "read";
    char strDo[] = "do";
    char strWhile[] = "while";
    char strPrint[] = "print";
    switch (charClass) {
        /* Parse identifiers */
        case LETTER:
            addChar();
            getChar();
            while (charClass == LETTER || charClass == DIGIT) {
                addChar();
                getChar();
            }
            if(strcmp(lexeme,strRead) == 0){    //compares the lexemes to see if the string is a keyword
                    nextToken = KEY_READ;
                }
            else if(strcmp(lexeme,strDo) == 0){
                    nextToken = KEY_DO;
                }
            else if(strcmp(lexeme,strWhile) == 0){
                    nextToken = KEY_WHILE;
                }    
            else if(strcmp(lexeme,strPrint) == 0){
                    nextToken = KEY_PRINT;
            }
            else{
                nextToken = IDENT;
            }
            break;
        /* Parse integer literals */
        case DIGIT:
            addChar();
            getChar();
            while (charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = INT_LIT;
            break;

        /* Parentheses and operators */
        case UNKNOWN:
            lookup(nextChar);
            break;

        /* EOF */
        case EOF:
            nextToken = EOF;
            lexeme[0] = 'E';
            lexeme[1] = 'O';
            lexeme[2] = 'F';
            lexeme[3] = 0;
            break;
    } /* End of switch */
    if (nextToken != EOF){
       printf("%s ", lexeme); 
        tPrint();
    }
    return nextToken;
} /* End of function lex */

