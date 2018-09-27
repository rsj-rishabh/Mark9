#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int isKeyword(char buffer[]){
    char keywords[][10] = {"include","iostream","namespace","using","std","main","break","cin","cout","char","const","continue","do","double","else","enum","float","for","if","int","long","return","short","struct","union","unsigned","void","while"};
    int i, flag = 0;

    for(i = 0; i < 32; ++i){
            if(strcmp(keywords[i], buffer) == 0){
                    flag = 1;
                    break;
            }
    }

    return flag;
}

int isDataType(char buffer[]){
    char dataType[][10] = {"int","char","float","double","long","union","enum","string","struct"};
    int i, flag = 0;

    for(i = 0; i < 10; ++i){
            if(strcmp(dataType[i], buffer) == 0){
                flag = 1;
                break;
            }
    }

    return flag;
}

int main(){
  char ch, buffer[30], operators[] = "+-*/%=", punc[] = ",.:;(){}[]";
  char datatype[][10] = {"int","float","char","float","union","enum","double","string","long"};
  int i,j=0,countt=0,cnt=0,k=0,l=0,m=0,n=0;
  string s[30],type[30],punct[30],op[10] ,num_buf="";
  bool error = false;
  int y, name_length;
  cout<<"Enter filename:- \n";
  char ext[3], name[260];
  cin>>name;
 
  //extract extension
  name_length = strlen(name);
  int ind = 0;
  for(i=name_length-1; name[i]!='.'; i--)
    ind += 1;
  for(i=name_length-3, y=0; (i!=ind) and y<3; i++, y++){
    ext[y] = name[i];
  }
  cout<<endl;
 
  //check correct extension and read
  if(name_length>4){
    if(strlen(ext)==3){
        if( strcmp(ext, "doc")==0 or strcmp(ext, "txt")==0 or strcmp(ext, "cpp")==0 ){
         ifstream fin(name);
            ofstream fout("output.txt");
         while ( !file.eof() ){
                  ch = fin.get();
                  if(ch !='\n'&& ch !=' ' && ch != '\t'){
                    fout<<ch;
              }
              for(i = 0; i < 10; ++i){
                    if(ch == punc[i]){
                          punct[m] = ch;
                      m++;
                }
          }
          for(i = 0; i < 6; ++i){
                if(ch == operators[i]){
                      op[n]=ch;
                      n++;
                }
          }
          if(ch=='\n'){
                countt++;
          }
          if(ch == '\n'|| ch == ' '){
                cnt++;
          }
          if(isalnum(ch)){
                buffer[j++] = ch;
          } else if((ch == ' ' || ch == '\n') && (j != 0)){
                  buffer[j] = '\0';
                  j = 0;
              if(isKeyword(buffer) == 1){
                type[l]=buffer;
                l++;
                *buffer=NULL;
              } else{
                  s[k]=buffer;
                  k++;
                  *buffer=NULL;
              }
          }
        }
        s[k+1]="\0";
        type[l+1]="\0";
        punct[m+1]="\0";
        op[n+1]="\0";
        cout<<"\n*******************";
        cout<<"\nNo of lines :"<<countt+1;
        cout<<"\nNo of words :"<<cnt+1;
        cout<<"\nKeywords :";
        for(l=0;type[l] != "\0";l++){
              cout<<type[l]<<" ";
        }
        cout<<"\nIdentifiers :";
        for(k=0;s[k] != "\0";k++){
              cout<<s[k]<<" ";
        }
        cout<<"\nPunctuations :";
        for(m=0;punct[m] != "\0";m++){
              cout<<punct[m]<<" ";
        }
        cout<<"\nOperators :";
        for(n=0;op[n] != "\0";n++){
              cout<<op[n]<<" ";
        }
        fin.close();
        fout.close();
      }
       }else{
       cout<<"Invalid file extension.\n";
  }
  }else{
    cout<<"Invalid file name.\n";
  }

return 0;
}

