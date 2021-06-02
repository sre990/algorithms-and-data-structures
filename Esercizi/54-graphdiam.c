#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
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

void dfs(int src, edges *E, int *visited){
   int dest, i;
   for(i=0; i < E[src].num; i++){
      dest = E[src].edges[i];
      if(!visited[dest]){
         visited[dest] = 1;
         dfs(dest, E, visited);
      }
   }
}

int is_connected(int *visited, int n){
   for(int i=0; i<n; i++){
      //printf("%d\n", visited[i]);
      if(visited[i]==0) return 0;
   }
   return 1;
}

int bfs(int src, int dest, edges *E, int n, int *pred, int *dist){
   int i;
   if(src == dest) return 0;
   int *visited = malloc(sizeof(int) * n);
   for(i=0; i < n; i++){
      visited[i] = 0;
      dist[i] = MAX;
      pred[i] = -1;
   }
   dist[src] = 0;
   visited[src] = 1;
   queue *q = init(n);
   enqueue(q, src);
   // loop fino a terminazione della coda
   while(q->size){
      src = dequeue(q);
      //printf("%d\n", src);//test
      for(i=0; i < E[src].num; i++){
         if(visited[E[src].edges[i]]==0){
            visited[E[src].edges[i]] = 1;
            dist[E[src].edges[i]] = dist[src]+1;
            pred[E[src].edges[i]] = src;
            enqueue(q, E[src].edges[i]);
            if(E[src].edges[i] == dest){
               deinit(q);
               free(visited);
               return dist[E[src].edges[i]];
            }
         }   
      }
   }
   // libero la memoria
   free(visited);
   deinit(q);
   return -1;
}

int is_adjacent(int *E, int n, int i){
   for(int j=0; j<n; j++){
      if(i==E[j]) return 1;
   }

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
   int n, i, j, src, dest, max, path;
   edges *E = NULL;
   max = -1;
   scanf(" %d", &n);
   E = read(n);
   int *visited = calloc(n, sizeof(int));
   dfs(0, E, visited);
   if(is_connected(visited, n)){
      int pred[n], dist[n];
      for(i=0; i<n; i++){
         src = i;
         for(j=0; j<n; j++){
            dest = j;
            path = bfs(src, dest, E, n, pred, dist);
            //if(is_adjacent(E[i].edges, E[i].num, dest)){        
               //printf("from %d to %d:%d\n", src, dest, path);
               if(path>max){
                  max = path;      
               } 
            //}
         }
      }
   }
   printf("%d\n", max);
   for(i=0; i<n; i++){
      free(E[i].edges);
   }
   free(E);
   free(visited);

   return 0;
}
