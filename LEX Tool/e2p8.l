%{ #include<stdio.h>
int n_id=0;
%}

start [a-z,A-Z,\_]
digit [0-9]

%%

{start}({start}|{digit})* {++n_id;}
\n {/*no action*/}
. {/*no action*/}

%%

int main(int argc, char** argv){
  yyin=fopen("pro.c", "r");
  yylex(); //perform tokenizing
  printf("n# of valid identifiers: %d", n_id);
  printf("\n");

return 0;
}
