#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000
int length(char *s){
   int i;
   for(i=0; *s!='\0'; s++) i++;
   return i;
}

char *my_strcat(char *s1, char *s2){
   int i, j, l1, l2;
   l1 = length(s1);
   l2 = length(s2);

   for(i=0; *(s1+i) != '\0'; i++);
   for(j=0; *(s2+j) != '\0'; j++) *(s1+i+j) = *(s2+j);
   *(s1+i+j) = '\0';

   return s1;
}

int main(){
   char *s, *z;
   int i, slen, zlen;
   s = malloc(MAX*sizeof(char));
   z = malloc(MAX*sizeof(char));
   scanf("%s %s", s, z);
   slen = length(s);
   zlen = length(z);
   
   z = realloc(z, zlen);
   s = realloc(s, slen+zlen+1);
   
   s = my_strcat(s, z);
   printf("%s\n", s);
   return 0;
}
