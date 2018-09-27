%{ #include<stdio.h>
int neg_int=0;
int pos_int=0;
int neg_fl=0;
int pos_fl=0;
%}

%%

[0-9]+ {++pos_int;}
-[0-9]+ {++neg_int;}
[0-9]*\.[0-9]+ {++pos_fl;}
-[0-9]*\.[0-9]+ {++neg_fl;}
. {/*no action*/}
\n {/*no action*/}

%%

int main(int argc, char** argv){
  yyin=fopen("pro.c", "r");
  yylex(); //perform tokenizing
  printf("n# of positive integers: %d", pos_int);
  printf("\n");
  printf("n# of negative integers: %d", neg_int);
  printf("\n");
  printf("n# of positive floats: %d", pos_fl);
  printf("\n");
  printf("n# of negative floats: %d", neg_fl);
  printf("\n");

return 0;
}
