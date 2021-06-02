#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000
int length(char *s){
   int i;
   for(i=0; *s!='\0'; s++) i++;
   return i;
}

char *product(char *s, int k){
   int i, j, slen, plen;
   slen = length(s);
   plen = slen*k;

   for(i=0; i<plen; i++) *(s+i) = *(s+(i%slen));
   
   *(s+plen) = '\0';

   return s;
}

int main(){
   char *s;
   int i, slen, k;
  
   s = malloc(MAX*sizeof(char));
   scanf("%s %d", s, &k);
   slen = length(s);   
   s = realloc(s, slen*k+1);
   s = product(s, k);
   printf("%s\n", s);

   return 0;
}
