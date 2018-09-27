%{
#include<stdio.h>
int com=0;
%}

%s COMMENT

%%

"/*"[ . ]*"*/" {com++;}
"/*" {BEGIN COMMENT ;}
<COMMENT>"*/" {BEGIN 0; com++ ;}
<COMMENT>\n {com++ ;}
<COMMENT>. {/*no action*/}
[.|\n] {fprintf(yyout,"%s",yytext);}

%%

int yywrap(){
  return 1;
}

int main(int argc, char *argv[]){
  if(argc!=3){
    printf("Usage: <./a.out> <sourcefile> <destn file>\n");
    exit(0);
  }
  yyin=fopen(argv[1],"r");
  yyout=fopen(argv[2],"w");
  yylex();
  printf("No of comment lines=%d\n",com);

return 0;
}
