#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/*
 * Scrivere un programma che legga in input un array
 * di stringhe e utilizzi qsort per ordinarle in 
 * ordine alfabetico *decrescente*. Si assuma che la
 * lunghezza massima di una stringa sia 100
 */
int my_strcmp(char *s, char *z){
   while(*s != '\0'){
      if(*z == '\0') return  1;
      if(*s<*z)      return -1;
      if(*z<*s)      return  1;
      s++, z++;
   }
   if(*z != '\0') return -1;
   
   return 0;
}

int compare(const void *a, const void *b){
   char *s, *z;
   s = *(char **)a;
   z = *(char **)b;
   return -my_strcmp(s,z);
}

int main(){
   char **ss;
   int n, i;
   scanf("%d", &n);
   ss = malloc(n*sizeof(char *));
   for(i=0; i<n; i++){
      ss[i] = malloc(MAX*sizeof(char));
      scanf("%s", ss[i]);
   }
   qsort(ss, n, sizeof(char *), compare);
   for(i=0; i<n; i++) printf("%s\n", ss[i]);
   
   for(i=0; i<n; i++) free(ss[i]); 
   free(ss);   

   return 0;
}
