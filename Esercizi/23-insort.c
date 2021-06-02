#include <stdio.h>
#include <stdlib.h>
//insertion sort su interi
//in-place, tempo dipende da dimesione input
//piu' efficiente per input quasi-ordinati
//complessita O(n^2)
int *sort(int *a, int n){
   int i, j, x;
   
   for(i=1; i<n; i++){
      x = a[i];
      j = i-1;
      //qui shift finche' non trova pos giusta
      while(j>=0 && a[j]>x){
         a[j+1] = a[j];
         j--;
      }
      a[j+1] = x;
  }

   return a;
}

int main(){
   int i, n , *a;
   scanf("%d", &n);
   a = malloc(sizeof(int)*n);
   for(i=0; i<n; i++) scanf("%d", a+i);
   a = sort(a, n);
   for(i=0; i<n; i++) printf("%d\n",a[i]);
   return 0;
}
