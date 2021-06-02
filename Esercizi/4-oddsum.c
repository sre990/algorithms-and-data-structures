#include <stdio.h>
//Scrivere una funzione ricorsiva f che, dato un intero N , restituisca la somma
//dei primi N interi dispari. Scrivere un programma che prenda in input un
//intero x e stampi il valore di f (x).
//L’unica riga dell’input contiene il valore x.
//L’unica riga dell’output contiene la somma dei primi x numeri dispari.

int f(int n){
   if(n==1) return 1;
   else return f(n-1) + (2*n-1);
}

int main (){
   int n;
   //printf("Inserire quanti numeri dispari sommare:\n");
   scanf("%d", &n);
   printf("%d\n", f(n));  

   return 0;
}
