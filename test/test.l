/*declaration*/
%{
#include <stdio.h>
%}
    
/*defenition*/
%%
"hi" {printf("bye");}
.* {printf("wrong");}
%%
main(){
 printf("enter input : ");
 yylex();


}

int yywrap(){
    return 1;
}