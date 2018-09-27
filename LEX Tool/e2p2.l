%{ #include<stdio.h>
int n_chars=0;
int n_words=0;
int n_spaces=0;
int n_lines=0;
%}

%%

[^ \t\n] {++n_chars;}
[ \t]+  {++n_spaces;}
[a-z,A-Z]|[a-z,A-Z]* {++n_words, n_chars+=yyleng;}
\n {++n_lines;}

%%

int main(int argc, char** argv){
  yyin=fopen("pro.c", "r");
  yylex(); //perform tokenizing
  printf("n# of characters: %d", n_chars);
  printf("\n");
  printf("n# of words: %d", n_words);
  printf("\n");
  printf("n# of spaces: %d", n_spaces);
  printf("\n");
  printf("n# of lines: %d", n_lines);
  printf("\n");

return 0;
}
