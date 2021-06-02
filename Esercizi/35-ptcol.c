#include <stdio.h>
#include <stdlib.h>
typedef struct{
   int x, y, c;
}point;

typedef struct{
   int len;
   point *array;
}array;

typedef struct{
   int x1, x2, y1, y2;
}inter;

//ordino per colore
int cmpCol(const void *a, const void *b){
   point *p1 = *(point **)a;
   point *p2 = *(point **)b;
   return p1->c - p2->c;
}

//dato un punto(x,y) e un rettangolo <(x1,y1),(x2,y2)>,
//se x1<=x<=x2 && y1<=y<=y2 il punto e' dentro il rettangolo
int isInside(point p, inter r){
   if((r.x1<=p.x && p.x<=r.x2) &&
      (r.y1<=p.y && p.y<=r.y2)) return 1;

   return 0;
}

//creo array di tutti i punti dentro rettangolo
array *createPoints(point *A, int n, inter r){
   array *pp;
   int i, j;
   j = 0;
   pp = malloc(sizeof(array));
   pp->len = n;
   pp->array = malloc(n*sizeof(point));
   for(i=0; i<n; i++){
      if(isInside(A[i],r)){
         pp->array[j] = A[i];
         j++;
      }
   }
   pp->len = j;
   //test
   /*printf("dentro il rettangolo(%d,%d,%d,%d) c'e':\n",
          r.x1,r.y1,r.x2,r.y2);
   for(i=0; i<j; i++){
      printf("(%d,%d,%d)\n", pp->array[i].x, 
      pp->array[i].y, pp->array[i].c);
   }*/
   return pp;
}

//conta colori distinti
int countDiff(point *pp, int len){
   int i, j, freq;
   point **aa = malloc(len*sizeof(point *));
   for(i=0; i<len; i++){
      aa[i] = malloc(sizeof(point));
      (*aa[i]).x = pp[i].x;
      (*aa[i]).y = pp[i].y;
      (*aa[i]).c = pp[i].c;
   }
   //ordino qui
   qsort(aa, len, sizeof(point *), cmpCol);
   freq = 1;
   if(len==0) return 0;
   for(i=0; i<len-1; i++){
      if((*aa[i]).c==(*aa[i+1]).c) continue;
      freq++;
   }
   return freq;
}

int main(){
   point *A;
   array *pp;
   inter *Q;
   int i, n, m, freq;
   
   scanf("%d %d", &n, &m);
   A = malloc(n*sizeof(point));
   Q = malloc(m*sizeof(inter)); 
   for(i=0; i<n; i++){
      scanf("%d %d %d", &A[i].x, &A[i].y, &A[i].c);
   }
   for(i=0; i<m; i++){ 
      scanf("%d %d %d %d", &Q[i].x1, &Q[i].y1,
            &Q[i].x2, &Q[i].y2);
   }
   
   for(i=0; i<m; i++){
      pp = createPoints(A, n, Q[i]);
      freq = countDiff(pp->array, pp->len);        
      //printf("ci sono %d colori distinti\n", freq);
      printf("%d\n", freq);
   }
   
   return 0;
}
