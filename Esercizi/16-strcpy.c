#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000
int length(char *s){
   int i;
   for(i=0; *s!='\0'; s++) i++;
   return i;
}

char *my_strcpy(char *dest, char *src){
   int i, j, l2;
   l2 = length(src);

   for(i=0; i<l2; i++) *(dest+i) = *(src+i);
   *(dest+i+1) = '\0';

   return dest;
}

int main(){
   char *d, *s;
   int i, slen;
  
   s = malloc(MAX*sizeof(char));
   scanf("%s", s);
   slen = length(s);   
   d = malloc(sizeof(char)*(slen+1));
   s = realloc(s, slen);
   d = my_strcpy(d, s);
   printf("%s\n", d);

   return 0;
}
