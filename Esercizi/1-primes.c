#include <stdio.h>
#include <math.h>
//Scrivere un programma che legga da tastiera un intero e stabilisca se il
//numero è primo.
//L’input consiste di una sola riga conente l’intero x.
//Il programma stampa in output 1 se x è primo, 0 altrimenti.
int isPrime(int x){
   int m, i;
    
   m = floor(sqrt(x));

   if(x<2)    return 0;
   if(x==2)   return 1;
   if(x==3)   return 1;
   if(x%2==0) return 0;
   for(i = 3; i<=m; i=i+2)
      if(x%i==0) return 0;
   return 1;
}

int main (){
   int x, res;

   //printf("Please enter number to test for primality:\n");
   scanf("%d", &x);
   res = isPrime(x);
   //if(res==1) printf("%d is prime.\n", x);
   //else       printf("%d is not prime.\n", x);
   printf("%d\n", res);

   return 0;
}

