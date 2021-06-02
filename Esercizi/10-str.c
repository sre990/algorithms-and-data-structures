#include <stdio.h>
#include <stdlib.h>
int my_strlen(char *s){
   int i;

   for(i=0; s[i] != '\0'; i++);
   return i;
}

int main(){
   int len;
   char *s;
   s = malloc(sizeof(char));
   scanf("%s", s);
   printf("%d\n", my_strlen(s));

   return 0; 
}
