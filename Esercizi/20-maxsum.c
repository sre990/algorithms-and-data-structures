#include <stdio.h>
#include <stdlib.h>
int maxsum(int *a, int alen){
   int i, j, sum, max;
   sum = 0;
   max = sum;
   for(i=0; i<alen; i++){
      //1: somma positiva
      if(sum>0) sum+=*(a+i);
      //2: il valore immediatamente precedente
      //da' somma negativa
      else sum=*(a+i);
      //aggiorniamo massimo   
      if(sum>max) max=sum;
      
   }
   return max;
}
int main(){
   int *x, lenx, i, res;
   scanf("%d", &lenx);
   x = malloc(sizeof(int)*(lenx));
   for(i=0; i<lenx; i++){
      scanf("%d", x+i);
   }

   printf("%d\n", maxsum(x, lenx));

   return 0;
}
