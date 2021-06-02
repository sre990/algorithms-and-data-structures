#include <time.h>
#include <stdlib.h>
#include <stdio.h>
// forse non funzionava perche' non usavo
// swap coi puntatori
void swap(int *a, int *b){
   int tmp;
   tmp = *a;
   *a = *b;
   *b = tmp;
}
int cfr(int val1, int val2) {
   int mod1, mod2;
   /* L'ordinamento tra un pari e un dispari viene riflesso 
    * tra le loro classi di resto modulo 2. */
   mod1 = abs(val1 % 2);
   mod2 = abs(val2 % 2);
   if (mod1 != mod2) return mod1 - mod2;
   return val1 - val2;
}
/*
  sx e dx sono le posizioni del primo e dell'ultimo elemento
  dell'array mentre px è la posizione dell'elemento perno.
  La funzione deve restituire la posizione del perno dopo 
  che gli elementi sono stati partizionati.
*/
int distribuzione(int a[], int sx, int px, int dx) { 
   int i, j, tmp;

   i = px;           //new: random index
   swap(&a[i], &a[dx]);//new: swap a[i] e a[r]
      
   px = a[dx];//scelgo l'ultimo elemento (rand) come pivot 
   i = sx-1;  //a[i] numeri <= px
// a[j] numeri > px
   for(j=sx; j<=dx-1; j++){
      if(cfr(a[j],px)<=0){//se a[j] <= pivot, lo scambio 
                          //con a[i].
         i++;
         swap(&a[i], &a[j]); // swap
      }
   }
   //il perno e' l'ultimo elemento non ancora ordinato
   //lo sposto fra a[i] e a[j] 
   swap(&a[i+1], &a[dx]);  // swap a[i] e a[dx]

   return i+1;
}

void quicksort( int a[], int sx, int dx ) {
  
   int perno, pivot, r;
   r = rand();
   if( sx < dx ) {
    //Scegliere una posizione a caso tra sx e dx inclusi.
      pivot = sx + r % (dx - sx + 1);

      perno = distribuzione(a, sx, pivot, dx); /* separa gli elementi minori di a[pivot] 
					        da quelli maggiori o uguali */
    /* Ordina ricorsivamente le due metà */
         quicksort(a, sx, perno-1);
         quicksort(a, perno+1, dx);
    
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

   if( legge(&A, &n)) return 1;
  
   quicksort(A, 0, n-1);
  
  /* Stampa l'array ordinato */
   for( i = 0; i < n; i++ ) 
      printf("%d ", A[i]);
   //printf("\n");	
   
   return 0;
}
