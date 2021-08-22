#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
static char a[MAX];
static int co;
void gen(int n){
  n++;
  char tmp;
  for(int i=n;i<co;i++){
    tmp=a[n];
    a[n]=a[i];
    a[i]=tmp;
    if(n==co-1)
      printf("%s\n",a);
    else
      gen(n);
      
    tmp=a[n];
    a[n]=a[i];
    a[i]=tmp;
  }
}

int main(){
  scanf("%s",a) ;
  co=strlen(a) ;
  gen(-1) ;
  return 0 ;
}
