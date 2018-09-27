%{ #include<stdio.h>
int n_scan=0;
int n_print=0;
%}

%%

scanf {printf("readf"); ++n_scan;}
printf {printf("writef"); ++n_print;}

%%

int main(int argc, char** argv){
  yyin=fopen("pro.c", "r");
  yylex(); //perform tokenizing
  printf("n# of scanf: %d", n_scan);
  printf("\n");
  printf("n# of printf: %d", n_print);
  printf("\n");

return 0;
}
