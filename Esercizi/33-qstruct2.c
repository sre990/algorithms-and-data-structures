#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
/* Scrivere un programma che utilizzi la funzione qsort per
 * ordinare un array di stringhe. Le stringhe devono essere
 * ordinate per lunghezza crescente. A parita' di lunghezza, 
 * si utilizzi l’ordinamento lessicografico. Utilizzare una
 * struct che memorizzi una stringa e la sua lunghezza per 
 * evitare di calcolare quest’ultima ad ogni confronto.
 */
typedef struct{
   int len;
   char *str;
} string;

//ausiliaria per evitare di usare strcmp
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

int cmpStr(const void *a, const void *b){
   string x = *(string*)a; 
   string y = *(string*)b; 
   if(x.len-y.len<0) return -1;
   else if(x.len-y.len>0) return 1;
   else return my_strcmp(x.str, y.str); 
}

int main(){
   int n, i;
   string *ss;
   scanf("%d", &n);
   ss = malloc(n*sizeof(string));
   for(i=0; i<n; i++){
      ss[i].str = malloc(MAX*sizeof(char));
      scanf("%s", ss[i].str);
      //occorre assegnare anche len
      ss[i].len = strlen(ss[i].str);
   }
   qsort(ss, n, sizeof(string), cmpStr);
   for(i=0; i<n; i++) printf("%s\n", ss[i].str);
   for(i=0; i<n; i++) free(ss[i].str);
   free(ss);

   return 0;
}
