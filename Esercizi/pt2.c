#include <stdio.h>

void printa(int a []){
   for(int i = 0; i<5; i++){
      printf("%d ", a[i]);
   }
   printf("\n");
}

int main (){
   // a e' un pt costante al primo elemento dell'array
   // e non si puo' modificare
   int a[5];
   // fill with 0
   for(int i = 0; i<5; i++){
      a[i] = 0;
   }
   //sono la stessa cosa *p = *q = a = &a[0]
   int *p = a;
   int *q = &a[0];
   printa(a);
   // sono la stessa cosa; p punta alla prima cella di a
   *p = 10;
   p[0] = 10;
   a[0] = 10;
   printa(a);
   // ora p punta alla seconda cella
   p + 1;
   // stampa tutto tranne prima cella
   printa(p+1);
   // modifichiamo l'elemento della terza quarta cella
   *(p+4) = 6;
   p[4] = 6;
   a[4] = 6;
   printa(a);
   printa(a+1);

   return 0;
}
