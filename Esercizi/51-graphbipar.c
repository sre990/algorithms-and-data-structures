#include <stdio.h>
#include <stdlib.h>

typedef struct _edges{
   int num;
   int *edges;
}edges;

typedef struct _queue{
   int size;
   int *elems;
   int head;
   int tail;
}queue;

queue *init(int num_elems){
   queue *q = malloc(sizeof(queue));
   q->elems = malloc(sizeof(int)*num_elems);
   q->size = 0;
   q->head = 0;
   q->tail = -1;
   
   return q;
}

void deinit(queue *q){
   free(q->elems);
   q->size = 0;
   q->head = 0;
   q->tail = -1;
   free(q);
}

void enqueue(queue *q, int elem){
   q->size++;
   q->tail = q->tail + 1;
   q->elems[q->tail] = elem;
}

int dequeue(queue *q){
   if(q->size==0) return -1;
   int head = q->elems[q->head];
   q->size--;
   q->head++;
   return head;
}

int *bfs(int src, edges *E, int n){
   int *colors = malloc(sizeof(int) * n);
   int dest, i;
   // inizializzo i colori
   for(i=0; i < n; i++) colors[i] = -1;
   colors[src] = 1;
   // inizializzo la coda
   queue *q = init(n);
   enqueue(q, src);
   // loop fino a terminazione della coda
   while(q->size){
      src = dequeue(q);
      //printf("%d\n", src);//test
      for(i=0; i < E[src].num; i++){
         dest = E[src].edges[i];
         if(colors[dest]==-1){
            colors[dest] = 1 - colors[src];
            enqueue(q, dest);
         }else if(colors[src]==colors[dest]){
            deinit(q);
            return NULL;
         }
      }
   }
   // libero la memoria
   deinit(q);
   return colors;
}

int is_bipartite(int *colors){
   if(colors) return 1;
   
   return 0;
}

edges *read(int n){
   int i, j;
   edges *E = malloc(n*sizeof(edges));
   if(!E) return NULL;
   for(i=0; i < n; i++){
      scanf(" %d", &(E[i].num));
      E[i].edges = malloc(sizeof(int) * E[i].num);
      for(j=0; j < E[i].num; j++){
         scanf(" %d", E[i].edges + j);
      }
   }

   return E;
}

int main(){
   int n;
   edges *E = NULL;
   scanf(" %d", &n);
   E = read(n);
   int *colors = bfs(0, E, n);
   int ans = is_bipartite(colors);
   printf("%d\n", ans);
   for(int i=0; i<n; i++){
      free(E[i].edges);
   }
   free(E);
   free(colors);
   return 0;
}
