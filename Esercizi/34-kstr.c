#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100
typedef struct _elem{
   char *str; 
   int freq;
}elem;

int cmpLen(const void *a, const void *b){
   elem *a1 = *(elem **)a;
   elem *b1 = *(elem **)b; 
   return (strlen(a1->str) - strlen(b1->str));
}

int cmpLex(const void *a, const void *b){
   elem *a1 = *(elem **)a;
   elem *b1 = *(elem **)b;
   return (strcmp(a1->str, b1->str));
}

int cmpFreq(const void *a, const void *b){
   elem *a1 = *(elem **)a;
   elem *b1 = *(elem **)b; 
   return -(a1->freq - b1->freq);
}

int main(){
   int n, k;
   elem **A;

   scanf("%d %d", &n, &k);
   A = malloc(n*sizeof(elem *));
   for(int i=0; i<n; i++){
      A[i] = malloc(sizeof(elem));
      A[i]->str = malloc(sizeof(char)*MAXLEN);
      scanf("%s", A[i]->str);
      A[i]->freq = 1;
   }
   int j = 1;
   qsort(A, n, sizeof(elem *), cmpLex); 
   for(int i=0; i<n && j<n; i++){
      if(strcmp(A[i]->str, A[j]->str)==0){
         A[i]->freq++;
         j++;
         i--;
      }else{
         i = j;
         j = i+1;
      }
   }
   qsort(A, n, sizeof(elem *), cmpFreq);
   qsort(A, k, sizeof(elem *), cmpLex);
   for(int i=0; i<k; i++){
      printf("%s\n", A[i]->str);
   } 
   for(int i=0; i<n; i++){
      free(A[i]->str);
      free(A[i]);
   }
   free(A);

   return 0;
}
