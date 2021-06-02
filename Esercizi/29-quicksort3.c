#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b){
   int tmp = *a;
   *a = *b;
   *b = tmp;
}
//Con Dijkstra 3-way partitioning (Dutch National Flag)
// a[sx] <= a[lt] <= pivot <= a[gt] <= a[dx]
void quicksort( int a[], int sx, int dx ){
   if(sx < dx){
	   int lt = sx;
	   int i = sx + 1;
	   int gt = dx;
      int pivot = a[sx];
      //scorro da sx a dx
	   while(i <= gt){
		   if(a[i] < pivot){
            //se a[i]<pivot, scambio a[i] e a[lt] e
            //incremento i e lt
			   swap(&a[i++], &a[lt++]);
		   }else if(a[i] > pivot){
            //se a[i]>pivot, scambio a[i] e a[gt] e
            //decremento gt
			   swap(&a[i], &a[gt--]);
		   }else{
            //se sono uguali continuo a scorrere
			   i++;
		   }
	   }

	   quicksort(a, sx, lt - 1);
      //gli elementi che vanno dall'indice lt a gt
      //sono uguali al pivot.
      quicksort(a, gt + 1, dx);  
   }

}

/* Lettura di un array di interi da input. 
Il primo elemento è la lunghezza dell'array */
int legge(int **a, int *len) {

  int i;
  scanf("%d", len);
  if(*len <= 0) return 1;

  *a = malloc(*len * sizeof(int));
  if(*a == NULL) return 1;
  
  for( i = 0; i < *len; i++ )
	  scanf("%d", (*a)+i);

  return 0;

}

int main(){
   srand(time(NULL));
   int i, n, *A;

   if(legge(&A, &n)) return 1;
  
   quicksort(A, 0, n-1);
  
  /* Stampa l'array ordinato */
   for( i = 0; i < n; i++ ) 
      printf("%d ", A[i]);
   //printf("\n");
   free(A);

   return 0;
}
