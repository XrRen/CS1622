%{
/** Code by @author Wonsun Ahn, Fall 2024
 * 
 * The lexer implementation file.
 */

#include <stdlib.h>

extern void addStringTable(char* text, int tokenid ); /* install string constants & identifiers into string tbl */
void commentDealer();
void reportError(int type);
void stringConsSeprator();
void badSCHandler();

/* TODO: Add additional function declarations as needed. */

%}

/* TODO: Add token declarations as needed using regular expressions. */
identifier    [A-Za-z][A-Za-z0-9]*
integerConstants  [0-9][0-9]*
newline           [\n]
tab               [\t]
space             [ ]
stringConstants   '([^\'\n\\]|(\\[\'n\\t]))*\'
badSC             '([0-9]*[A-Za-z0-9_]*([^\'\n\\]|(\\[\'n\\t]))*)
malformedID  [0-9]*[A-Za-z0-9_]*
%%

 /* TODO: Add rules for actions for each declared token. */
"&&"            {yycolumn+=yyleng; return ANDnum;}
":="            {yycolumn+=yyleng; return ASSGNnum;}
"=="            {yycolumn+=yyleng; return EQUALnum;}
">"             {yycolumn+=yyleng; return GTnum;}
"<"             {yycolumn+=yyleng; return LTnum;}
">="             {yycolumn+=yyleng; return GEnum;}    
"<="             {yycolumn+=yyleng; return LEnum;}   
"+"              {yycolumn+=yyleng; return PLUSnum;}    
"-"             {yycolumn+=yyleng; return MINUSnum;}
"*"             {yycolumn+=yyleng; return TIMESnum;}
"/"             {yycolumn+=yyleng; return DIVIDEnum;}
"!="             {yycolumn+=yyleng; return NEnum;}
"||"             {yycolumn+=yyleng; return ORnum;}
"{"             {yycolumn+=yyleng; return LBRACEnum;}
"}"             {yycolumn+=yyleng; return RBRACEnum;}
"["             {yycolumn+=yyleng; return LBRACnum;}
"]"             {yycolumn+=yyleng; return RBRACnum;}
"("             {yycolumn+=yyleng; return LPARENnum; }
")"             {yycolumn+=yyleng; return RPARENnum; }
";"             {yycolumn+=yyleng; return SEMInum; }
"."             {yycolumn+=yyleng; return DOTnum; }
","             {yycolumn+=yyleng; return COMMAnum; }
"="             {yycolumn+=yyleng; return EQUALnum;}
"declarations"               {yycolumn+=yyleng; return DECLARATIONSnum; }
"enddeclarations"               {yycolumn+=yyleng; return ENDDECLARATIONSnum; }
"program"               {yycolumn+=yyleng; return PROGRAMnum; }
"val"               {yycolumn+=yyleng; return VALnum; }
"while"               {yycolumn+=yyleng; return WHILEnum; }
"class"               {yycolumn+=yyleng; return CLASSnum; }
"else"               {yycolumn+=yyleng; return ELSEnum; }
"if"               {yycolumn+=yyleng; return IFnum; }
"method"               {yycolumn+=yyleng; return METHODnum; }
"return"                {yycolumn+=yyleng; return RETURNnum; }
"void"               {yycolumn+=yyleng; return VOIDnum; }
"int"               {yycolumn+=yyleng; return INTnum; }
{identifier}        {addStringTable(yytext, IDnum); yycolumn+=yyleng; return IDnum;}
{integerConstants}  {yylval.intg = atoi(yytext); yycolumn+=yyleng; return ICONSTnum;}
{newline}           {yyline++; yycolumn = 1;}
{tab}               {yycolumn += yyleng;}
"/*"                {yycolumn += yyleng; commentDealer();}
{stringConstants}   {stringConsSeprator(); return SCONSTnum;}
{malformedID}       {reportError(1);yycolumn+=yyleng;}
{space}             {yycolumn++;}
{badSC}             {reportError(2); yycolumn+=yyleng;}
.                   {reportError(4); yycolumn+=yyleng;}

%%

/** Prints out an error message depending on error type.
 *
 * @param errorType - A number designating an error type.
 */
void reportError(int errorType)
{
  /* TODO: Report on 5 types of errors:
     1) Malformed identifier.
     2) A string constant with unmatched quotes.
     3) A comment with no matching end comment.
     4) An undefined token.

     The line and column numbers where the error occurred, as well as the erroneous
     token string as appropriate, should be printed as part of the output.  Refer to
     the error outputs under outputs_solution/code2.out and outputs_solution/string2.out
     and match the formatting exactly.
  */
  switch(errorType)
  {
    case 1:
    printf("Error: Malformed identifier '%s', at line %d column %d\n",yytext, yyline, yycolumn);
    break;
    case 2:
    printf("Error: Unmatched string constant, at line %d column %d\n", yyline, yycolumn);
    break;
    case 3:
    printf("Error: EOF found in comment, at line %d column %d\n", yyline, yycolumn);
    break;
    case 4:
    printf("Error: Undefined token '%s', at line %d column %d\n", yytext, yyline, yycolumn);
    break;
  }
}  
void commentDealer()
{
  char token = input();
  yycolumn++;
  while(token != 0)
  {
    if(token == '*') /*if we got a start sign, then we need to check what's next, if it's a back slash then we find the end comment*/
    {
      token = input();
      yycolumn++;
      if(token == '/')
      {
        return;
      }
    }
    if(token == '\n') /*newline is a sepcail case, we nned to increment the line counter and reset the column*/
    {
        yyline++;
        yycolumn = 1;
        
    }
    token = input(); //countinus searching
    yycolumn++;
    
  }
  yycolumn--;
  reportError(3); //if we cannot find the end, and we reached EOF, we reprost that error
}
/*
* this method will seperate the string constants accroding like
* if they contains \n \t \\ \', we need to find them and store them into the string addStringTable
* based on what special characters they are
*/
void stringConsSeprator()
{
  char strings[yyleng-1]; //this will be the final strings that will be added to the table
  int index = 0; //position of adding chars
  
  for(int i = 0 ;i < yyleng - 1;i++)
  {
    yycolumn++;
    /*if it start with a back slash, it can be a string iteral. check which sepcific one it so.*/
    if(yytext[i] == '\\')
    {
      i++;
      yycolumn++;
      /*put different stirng iterals into the final strings accrodingly*/
      if(yytext[i] == 'n')
      {
        strings[index] = '\n';
        
        index++;
      }
      else if(yytext[i] == 't')
      {
        strings[index] = '\t';
        index++;
      }
      else if(yytext[i] == '\\')
      {
        strings[index] = '\\';
        index++;
      }
      else if(yytext[i] == '\'')
      {
        strings[index] = '\'';
        index++;
      }
      else //if it's not any of them, then it's not a sybmol we declared, report error
      {
        reportError(2);
        return;
      }
    }
    else //just normal characters, simply add to the string
    {
      if(yytext[i] == '\'') //ignore single signle quote
      {

      }
      else
      {
        strings[index] = yytext[i];
        index++;
      }
      
    }
  }
  yycolumn++;
  strings[index] = '\0'; //avoid garbage input.
  addStringTable(strings,SCONSTnum); //add the string to the table
}       

/* TODO: Add additional function definitions as needed. */