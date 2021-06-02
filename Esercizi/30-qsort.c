#include <stdio.h>
#include <stdlib.h>
/*Scrivere un programma che utilizzi la funzione qsort e 
 * ordini un vettore di interi (in input), in modo che 
 * l’array ordinato deve contenere prima tutti i numeri pari
 * e, a seguire, i numeri dispari. Si assuma che il numero 0
 * sia pari. I numeri pari devono essere ordinati in modo
 * crescente fra di loro. I numeri dispari devono essere 
 * ordinati in modo decrescente fra di loro.
 */
int compareInt(const void *a, const void *b){
   int x, y, x1, y1;
   x = *(int *)a;
   y = *(int *)b;
   x1 = abs(x%2);
   y1 = abs(y%2);
   
   if(x1 != y1) return x1-y1;//se uno e' pari e l'laltro dispari
   else if(x1) return y-x; //se sono entrambi dispari
   else return x-y; //se sono entrambi pari

}

int main(){
   int n, i, *vec;
   scanf("%d", &n);
   vec = malloc(n*sizeof(int));
   for(i=0; i<n; i++) scanf("%d", vec+i);
   qsort(vec, n, sizeof(int), compareInt);
   for(i=0; i<n; i++) printf("%d\n", vec[i]);
   free(vec);

   return 0;
}
