#include <stdio.h>
#include <stdlib.h>
// merge di due array assumendo che che siano ordinati.
int *merge(int *a, int alen, int *b, int blen){
   int i, j, pos, *p; 
 
   p = malloc(sizeof(int)*(alen+blen));
   i = 0;
   j = 0;
   pos = 0;
//si riempie p confrontando a[i] e b[j] uno a uno  
   while(i<alen&&j<blen){
      if(a[i]<b[j]){
         p[pos++] = a[i++];
      }else if(a[i]>b[j]){
         p[pos++] = b[j++];
      }else{
         p[pos++] = a[i];
         i++;
         j++;
      }
   }
//se esaurisco uno degli array riempio p coi restanti elem.
   while(i<alen){
      p[pos++] = a[i++];
   }
   while(j<blen){
      p[pos++] = b[j++];
   }

   return p;
}

int main(){
   int *x, *y, *res, lenx, leny, i;
   scanf("%d", &lenx);
   x = malloc(sizeof(int)*lenx);
   for(i=0; i<lenx; i++){
      scanf("%d", x+i);
   }

   scanf("%d", &leny);
   y = (int *) malloc(sizeof(int)*leny);
   for(i=0; i<leny; i++){
      scanf("%d", y+i);
   }
   res = merge(x, lenx, y, leny);
   for(i=0; i<lenx+leny; i++){
      printf("%d\n", *(res+i));
   }
   return 0;
}
