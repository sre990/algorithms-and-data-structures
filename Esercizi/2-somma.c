#include <stdio.h>
//Scrivere un programma che legga da tastiera una sequenza di numeri interi
//terminata da 0 e ne stampi la somma.
//L’input una sequenza di numeri interi terminata da 0, un intero per riga.
//Il programma stampa in output la somma degli interi.

int main (){
   int s = 0;
   int in = -1;  
     
   while(in != 0){
      scanf("%d", &in);
      s += in;
   }    
   //printf("La somma e': %d\n", s);
   printf("%d\n", s);
   return 0;
}
