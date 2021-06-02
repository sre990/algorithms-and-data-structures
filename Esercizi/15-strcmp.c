#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000
int length(char *s){
   int i;
   for(i=0; *s!='\0'; s++) i++;
   return i;
}

int my_strcmp(char *s, char *z){

   while(*s!='\0'){
      if(*z=='\0') return +1;
      if(*s<*z) return -1;
      if(*z<*s) return +1;
      s++, z++;
   }
   if(*z!='\0') return -1;

   return 0;
}

int main(){
   char *s, *z;
   int i, res;
  
   s = malloc(MAX*sizeof(char));
   z = malloc(MAX*sizeof(char));
   scanf("%s %s", s, z);
   s = realloc(s, length(s));
   z = realloc(z, length(z));
   res = my_strcmp(s, z);
   printf("%d\n", res);

   return 0;
}
