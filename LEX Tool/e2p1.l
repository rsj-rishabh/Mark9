%{ #include<stdio.h>
int n_vowels=0;
int n_char=0;
int n_consonant=0;
%}

%%

[a|e|i|o|u|A|E|I|O|U] {++n_vowels;}
[a-z,A-Z] {++n_char;}
.|\n {/*no action*/}

%%

int main(int argc, char** argv){
  yyin=fopen("pro.c", "r");
  yylex(); //perform tokenizing
  printf("n# of vowels: %d", n_vowels);
  printf("\n");
  n_consonant = n_char - n_vowels;
  printf("n# of consonants: %d", n_consonant);
  printf("\n");

return 0;
}
