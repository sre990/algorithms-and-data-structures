#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//da introduction to algorithms, barre da tagliare
int max(int a, int b){ 
   return (a>b) ? a : b;
}

int num_rods;
int cutRod(int price[], int rods[], int n){
   int i, j, max_val, opt_sol; 
   int val[n+1];
   int sol[n+1];
   val[0] = 0;

   //bottom-up
   for(i=1; i<=n; i++){
      max_val = INT_MIN;
      opt_sol = -1;
      for(j=0; j < i; j++){
         if(max_val < price[j] + val[i-j-1]){
            max_val = price[j] + val[i-j-1];
            opt_sol = j;
         }
      }
         val[i] = max_val;
         sol[i] = opt_sol + 1;
   }

   for(i = n, j = 0; i>0; i -= sol[i]){
      rods[j++] = sol[i];
   }
   num_rods = j;
   
   return val[n];
}

int main(){
   int n, i;

   scanf("%d", &n);
   int price[n];
   int rods[n+1];
   //read
	for(i=0; i<n; i++){
      scanf("%d", &price[i]);
   }
   //output
   printf("%d\n",cutRod(price, rods, n));
   printf("%d ", rods[0]);
   for(i = 1; i < num_rods; i++){
        printf("%d ", rods[i]);
   }

   return 0;
}
