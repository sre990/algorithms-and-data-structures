#include <stdio.h>
#include <stdlib.h>
#define OK "CONNESSO\n"
#define NO "NON CONNESSO\n"
//un grafo e' connesso se possiamo colorarne tutti i vertici
typedef struct _edges{
   int num;
   int *edges;
}edges;

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
//restituisce il numero di nodi che abbiamo visitato
int dfs_visited(int src, edges *E, int n){
   int *visited = malloc(sizeof(int)*n);
   int *stack = malloc(sizeof(int)*n);
   int stack_size, dest, i;
   for(i=0; i<n; i++){
      visited[i] = 0;
   }
   visited[src] = 1;
   stack[0] = src;
   int num_visited_nodes = 1;
   stack_size = 1;
   while(stack_size){
      src = stack[stack_size--];
      for(i=0; i< E[src].num; i++){
         dest = E[src].edges[i];
         if(!visited[dest]){
            num_visited_nodes++;
            visited[dest] = 1;
            stack[stack_size++] = dest;
         }
      }
   }
   free(stack);
   free(visited);
   return num_visited_nodes;
   
}

int main(){
   int n, i;
   edges *E = NULL;
   scanf(" %d", &n);
   if(n==0) return 1;
   E = read(n);
   int res = dfs_visited(0, E, n);

   (res<n) ? printf("%s", NO) : printf("%s", OK);
   //libero la memoria
   for(i=0; i<n; i++){
      free(E[i].edges);
   }
   free(E);

   return 0;
}
