#include <stdio.h>
#include <stdlib.h>
#define MAX 10
// Programma che legge una sequenza di interi che termina con -1, tenga traccia delle
// frequenze di interi comprese fra 0 e 9. In output stampare le frequenze, mantenute 
// in un array di lunghezza dieci inizializzato a 0;
void reset(int *a, int len){
   int i;

   for(i=0; i<len; i++) *(a+i) = 0;

}

void add(int a[], int len, int val){
   
   if(val<len && val>=0) a[val]++;

}

void print(int a[], int len){
   int i;
   
   for(i=0; i<len; i++){
      //printf("%d compare %d volta/e\n", i, a[i]);
      printf("%d\n", a[i]);
   }
}

int main (){
   int vl, len, *a;  
   a = malloc(MAX*sizeof(int));
   reset(a, MAX);
   scanf("%d", &vl);   

   while(vl != -1){
      add(a, MAX, vl);
      scanf("%d", &vl);
          
   }
   
   print(a, MAX);

   return 0;
}
