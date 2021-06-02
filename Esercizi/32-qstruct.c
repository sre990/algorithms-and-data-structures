#include <stdio.h>
#include <stdlib.h>
/* Scrivere un programma che utilizzi la funzione qsort per
 * ordinare un vettore di punti del piano cartesiano. 
 * Ciascun punto e' formato da una coppia di coordinate. I 
 * punti devono essere ordinati per ascissa crescente. 
 * A parita' di ascissa, si ordini per ordinata decrescente
 */
typedef struct{
   int x;
   int y;
} point;

int cmp(const void *x, const void *y){
   point a = *(point *)x;
   point b = *(point *)y;
   if(a.x == b.x) return (b.y - a.y);
   else return a.x - b.x;
}

int main(){
   int n, i;
   point *pp;
   scanf("%d", &n);
   pp = malloc(n*sizeof(point));
   for(i=0; i<n; i++) scanf("%d %d", &pp[i].x, &pp[i].y);
   qsort(pp, n, sizeof(point), cmp);
   //for(i=0; i<n; i++) printf("(%d,%d)\n", pp[i].x, pp[i].y);
   for(i=0; i<n; i++) printf("%d %d\n", pp[i].x, pp[i].y);
   //for(i=0; i<n; i++) free(pp[i]);
   free(pp);

   return 0;
}
