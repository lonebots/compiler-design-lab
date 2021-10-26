%{
int COMMENT=0;
%}
identifier [a-zA-Z][a-zA-Z0-9]*
%%
#.* {printf("\n%s is a preprocessor directive",yytext);}
int|float|char|double|while|for|struct|typedef|do|if|break|continue|void|switch|return|else|goto|printf {printf("\n\t%s is a keyword",yytext);}
"/*" {COMMENT=1;}{printf("\n\t %s is a COMMENT",yytext);}
\{  {if(!COMMENT)printf("\n BLOCK BEGINS");}
\}  {if(!COMMENT)printf("BLOCK ENDS ");}
{identifier}(\[[0-9]*\])? {if(!COMMENT) printf("\n %s IDENTIFIER",yytext);}
\".*\" {if(!COMMENT)printf("\n\t %s is a STRING",yytext);}
[0-9]+ {if(!COMMENT) printf("\n %s is a NUMBER ",yytext);}
= {if(!COMMENT)printf("\n\t %s is an ASSIGNMENT OPERATOR",yytext);}
\( {if(!COMMENT)printf("\n\t %s is an OPENING BRACKET",yytext);}
\) {if(!COMMENT)printf("\n\t %s is an CLOSING BRACKET",yytext);}
\<= | \>= |\< | == | \> {if(!COMMENT) printf("\n\t%s is a RELATIONAL OPERATOR",yytext);}
\+ | \- | \\ | \* 	{if(!COMMENT) printf("\n\t%s is a OPERATOR",yytext);}
%%
int main()
{
FILE *file;
file=fopen("prg2.c","r");
if(!file)
{
printf("could not open the file");
exit(0);
}
yyin=file;
yylex();
printf("\n");
return(0);
}
int yywrap()
{
return(1);
}