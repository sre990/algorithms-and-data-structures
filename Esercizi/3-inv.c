#include <stdio.h>
#include <stdlib.h>
//Scrivere un programma che legga da input gli N interi di un array A. Il pro-
//gramma deve invertire A in loco (cioè senza utilizzare un array di appoggio),
//ossia scambiare il contenuto della prima e dell’ultima cella, della seconda e
//della penultima, ecc. Si assuma che N=10000. La prima riga dell’input è il 
//valore N. Seguono N interi, uno per riga. Il programma stampa in output gli 
//elementi dell’array invertito, uno per riga.
void swap(int *a, int *b){
   int tmp;
   tmp = *a;
   *a = *b;
   *b = tmp;
}

int main(){
   int *a, len, i, j;

   scanf("%d", &len);
   j = len - 1;
   //read
   a = malloc(sizeof(int)*len);
   for(i=0; i<len; i++){
      scanf("%d", &a[i]);
   }
   //inv
   for(i=0; i<len/2; i++){
      swap(&a[i], &a[j]);
      j--;
   }
   //print
   for(i=0; i<len; i++){
      printf("%d\n", a[i]);
   }
   printf("\n");

   return 0;   
}
