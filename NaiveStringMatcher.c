#include<stdio.h>
#include<string.h>
 // String Matching
 
void naive_matching(char text[],char pattern[]){
  int n = strlen(text);
  int m = strlen(pattern);

  for(int i=0;i<=n-m;i++){
    int j;
    for(j=0;j<m;j++){
      if(text[i+j] != pattern[j])
         break;
    }
    if(j == m)
      printf("\nPattern found at index %d",i);
  }
}

int main(){
  char text[] = "ABABDAABABABABDFBEAB";
  char pattern[] = "ABAB";

  naive_matching(text,pattern);
}
