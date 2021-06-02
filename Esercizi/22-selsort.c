#include <stdio.h>
#include <stdlib.h>
//selection sort su interi
//in-place, tempo dipende da dimesione input
//stesso tempo sia che input ordinato o tutto
//uguale o scombinato
//complessita O(n^2)
void swap(int *a, int *b){
   int tmp;
   tmp = *a;
   *a = *b;
   *b = tmp;
}
//divide array in a[i] gia' ordinati
//e a[j] da ordinare
//nel loop interno trova il piu' piccolo degli
//elementi non ordinati e lo scambia con  
//l'ultimo degli elementi ordinati
int *sort(int *a, int n){
   int min, i, j;
   
   for(i=0; i<n-1; i++){
      min = i;
      for(j=i+1; j<n; j++){
         if(a[j]<a[min]) min = j;
      }
      if(min!=i) swap(a+i, a+min);
   }
   return a;

}

int main(){
   int i, n , *a;
   scanf("%d", &n);
   a = malloc(sizeof(int)*n);
   for(i=0; i<n; i++) scanf("%d", a+i);
   a = sort(a, n);
   for(i=0; i<n; i++) printf("%d\n", *(a+i));
   return 0;
}
