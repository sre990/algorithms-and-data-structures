#include <stdio.h>
#include <stdlib.h>
// Dato in array a e la sua lunghezza len, findVal cerca il valore val all'interno
// di a e restituisce un puntatore alla cella che lo contiene, o la costante NULL
// Scrivere un main che legga da input un array di 10 interi e un intero val e stampi trovato/non trovato.
// L'input e' formato da dieci righe contenenti gli elementi dell'array seguite dall'intero val da cercare.
int* findVal (int a[], int len, int val){
   int i;
   
   for(i=0; i<len; i++){
      if(*(a+i) == val) return a+i; 
   }

   return NULL;
}

int main (){
   int val, i, len, *a, *t;
   
   len = 10;
   //scanf("%d", &len);
   a = malloc(len * sizeof(int));
   for(i=0; i<len; i++) scanf("%d ", a+i);
   scanf("%d", &val);
   t = findVal(a, len, val);
   if(t==NULL) printf("non trovato\n");
   else printf("trovato\n");

   return 0;
}
