#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
//parola e index
typedef struct{
   char *str;
   int id;
}string;
//array di duplicati delle parole con relativa lunghezza 
typedef struct{
   string *array;
   int size;
}array;
//crea duplicati di un array di parole con indici
array* createArray(char *a[], int len){
   array *dup;
   int i;
   dup = malloc(sizeof(array));
   dup->size = len; //accedo campo size della struttura
   dup->array = malloc(len*sizeof(string));//campo array
   for(i=0;i<len;i++){
      //uso -> quando ho a che fare con puntatori
      //(*dup).array[i]. sarebbe stato equivalente
      dup->array[i].id = i;
      dup->array[i].str = malloc(sizeof(strlen(a[i] + 1)));
      //usare sempre strcpy per le stringhe
      strcpy(dup->array[i].str, a[i]);
   
   }
   return dup;
}

//confronto di lettere per ordinare array di tipo string
int cmpChar(const void *a, const void *b){
   return *(char *)a - *(char *)b;
}
//confronto di parole per ordinare array di duplicati
int cmpStr(const void *a, const void *b){
   string s1 = *(string *)a;
   string s2 = *(string *)b;
   return strcmp(s1.str, s2.str);
}

int main(){
   int i, n, j;
   array *dup;
   //lettura parole
   scanf("%d", &n);
   char **A;
   A = malloc(n*sizeof(char *));
   for(i=0; i<n; i++){
      A[i] = malloc(MAX*sizeof(char));
      scanf("%s", A[i]);
   }
   //printf("output:\n");
   //ordino alfabeticamente
   qsort(A, n, sizeof(char *), cmpStr);
   //creo copia array di parole con indici delle parole
   dup = createArray(A, n);
   //scandisco dup e riordino le lettere delle parole
   for(i=0; i<n; i++){
      qsort(dup->array[i].str, strlen(dup->array[i].str), 
            sizeof(char), cmpChar);
   }
   //riordino array di parole
   qsort(dup->array, n, sizeof(array), cmpStr);
   //adesso le parole in dup sono insieme, ma sono sballate,
   //dobbiamo recuperare l'indice della parola originale
   for(i=0; i<n; i++){
      j = i+1;
      printf("%s", A[dup->array[i].id]);
      if(j>=n){
         i++;
      }else if(strcmp(dup->array[i].str, dup->array[j].str)==0){
         printf(" ");
      }else{
         printf("\n");
      }
   }
   
   return 0;
}
