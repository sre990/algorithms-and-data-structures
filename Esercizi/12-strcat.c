#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int my_strlen(char *s){
   int xlen;
   for(xlen=0; *s!='\0'; s++) xlen++;
   return xlen;
}

char *my_strcat(char *s1, char *s2){
   int xlen, ylen, i, j;
   char *str;
   
//per prima cosa trovo la lunghezza delle stringhe
   xlen = my_strlen(s1);
   ylen = my_strlen(s2);
//assegno tanta memoria quante sono lunghe le 
//lettere + '\0'   
   str = malloc(sizeof(char)*(xlen + ylen + 1));
//se la stringa e' vuota, esco interrompendo il 
//processo. Quindi non c'e' bisogno di deallocare
//la memoria
   if(str==NULL) exit(1);

//copio gli input in str e chiudo con '\0'
   j = 0;
   for(i=0; i<xlen; i++) str[j++] = s1[i];
   for(i=0; i<ylen; i++) str[j++] = s2[i];
   str[j] = '\0';

   return str;
}

int main(){
   char *cat;
   char x [MAX];
   char y [MAX];

   scanf("%s", x);
   scanf("%s", y);
   cat = my_strcat(x, y);
   printf("%s\n", cat);
   
   return 0;
}
