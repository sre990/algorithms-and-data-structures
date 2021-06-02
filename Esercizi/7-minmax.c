#include <stdio.h>
#include <stdlib.h>
//Scrivere una funzione minmax avente i seguenti parametri:
//- un array di interi;
//- la lunghezza dell’array;
//- un puntatore a una variabile intera min;
//- un puntatore a una variabile intera max.
//La funzione scandisce l’array e salva in min la posizione in cui si trova 
//l’elemento minimo e in max la posizione in cui si trova l’elemento massimo.
//Si può assumere che l’array contenga valori distinti. 
//Scrivere poi un programma che
//- legga 10 interi da tastiera;
//- invochi minmax sull’array letto;
//- produca in output: la posizione di min/max e il valore di min/max.

void minmax(int *a, int n, int *min, int *max){
   int i;
   *min = 0;// sempre inizializzare puntatori
   *max = 0;
   
   for(i=0; i<n; i++){
      if(a[i]<a[*min]) *min = i;
      if(a[i]>a[*max]) *max = i;
      
   }
//i puntatori si inizializzano dentro la funzione chiamata dal main (ie minmax). 
//Quando una funzione deve modificare parametri si usano puntatori (cfr. 
//anche swap). Nel main si creano variabili locali e -una volta chiamata 
//la funzione con queste variabili- si collegano con &.

}

int main(){
   int len, i, mn, mx;
   int *a;
   len = 10;
   //scanf("%d", &len);
   a = malloc(len * sizeof(int));
   for(i = 0; i<len; i++) {
      scanf("%d", a+i);//a+i equivale a &a[i]
   }

   minmax(a, len, &mn, &mx);
//Come con scanf si usa & (indirizzo-di) per collegare l'indirizzo 
//di mn/mx nel main al puntatore *min/*max della funzione chiamata.
//Quindi *min/*max adesso punta all'indirizzo di mn/mx. 
 
   //printf("min=%d @pos=%d\nmax=%d @pos=%d\n", 
   //      a[mn], mn, a[mx], mx);  
   printf("%d\n%d\n%d\n%d\n", mn, a[mn], mx, a[mx]);
   
   return 0;
}
