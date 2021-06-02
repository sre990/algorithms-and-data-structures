#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 101

void swap(char *a, char *b){
   char *tmp = malloc(MAX*sizeof(char));
   //IMPORTANTE: usare strcpy invece del'assegnazione
   strcpy(tmp,a);
   strcpy(a, b);
   strcpy(b, tmp);
   free(tmp);
}
/* 
  stavolta con ARRAY di STRINGHE
  sx e dx sono le posizioni del primo e dell'ultimo elemento dell'array 
  mentre px è la posizione dell'elemento perno.
  La funzione deve restituire la posizione del perno dopo che gli elementi
  sono stati partizionati.
*/
int distribuzione(char *a[], int sx, int px, int dx){ 
//di solito si assume che il pivot sia in posizione dx(ultimo elemento)
   //modifichiamo in modo che il pivot sia scelto a random
   int i, j; 

   i = px;       // new: scegli indice i random
   swap(a[i], a[dx]);//scambia a[i] e a[dx]
   
   px = dx;//prosegui come algoritmo normale
   i = sx-1;

   // sposto tutti gli elementi < di px in a[i] e quelli > in a[j]
   for(j=sx; j<=dx-1; j++){
      //se un elemento di a[j] non e' > di px lo scambio con a[i]
      if(strcmp(a[j], a[px])<=0){ 
         i++;
         swap(a[i], a[j]);
         
      }
   }
   //il perno e' l'ultimo elemento non ancora ordinato
   //lo sposto fra a[i] e a[j]   
   swap(a[i+1], a[dx]);
   
   return i+1;
  
}

// test print
void print(char *a[], int len) {
   int i;

   for(i = 0; i < len; i++){ 
	   printf("%s\n", a[i]);
   }
}

void quicksort( char *a[], int sx, int dx ){
   int perno, pivot, r;
   r = rand();

   if(sx < dx){
      //scelgo una posizione a caso tra sx e dx inclusi.
      pivot = sx + rand() % (dx - sx + 1);
      //divido elementi < a[px] da quelli maggiori o uguali
      perno = distribuzione(a, sx, pivot, dx);
      //ordino ricorsivamente le due metà
      quicksort(a, sx, perno-1);
      quicksort(a, perno+1, dx);
    
  }

}

int main() {
   srand(time(NULL));
   int i, n;
   //IMPORTANTE:usare array di stringhe *A[]
   char **A;
   scanf("%d", &n);
   A = malloc(n * sizeof(char *));
   for(i=0; i<n; i++){
      A[i] = malloc(MAX * sizeof(char));
      scanf("%s", A[i]);
   }

   quicksort(A, 0, n-1);
  
   // Stampa l'array ordinato
   print(A, n);
   for(i=0; i<n; i++){
      free(A[i]);
   }
   free(A);

   return 0;
}
