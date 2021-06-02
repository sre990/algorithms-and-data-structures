#include <stdio.h>
#include <stdlib.h>
#define OK "E' UN ALBERO\n"
#define NO "NON E' UN ALBERO\n"
//Stabilire se un grafo indiretto (non orientato) è un albero.
//Un albero è un grafo indiretto aciclico e connesso.
//un grafo e' connesso se possiamo colorarne tutti i vertici
//un grafo e' aciclico se il numero dei suoi archi
//e' uguale a n-1, dove n e' il numero dei vertici
typedef struct _edges{
   int num;
   int *edges;
}edges;
typedef struct result {
   int is_connected;
   int is_acyclic;
}result;

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
//ci dice se un grafo e' connesso e se e' aciclico
result dfs_visited(int from, edges *E, int n){
   result res;
   int edges_num = 0;
   int *visited = malloc(sizeof(int)*n);
   int *stack = malloc(sizeof(int)*n);
   int stack_size, src, dest, i;
   for(i=0; i<n; i++){
      visited[i] = 0;
   }
   visited[from] = 1;
   stack[0] = from;
   int num_visited_nodes = 1;
   stack_size = 1;
   while(stack_size){
      stack_size--;
      src = stack[stack_size];
      for(i=0; i< E[src].num; i++){
         dest = E[src].edges[i];
         edges_num++;
         if(!visited[dest]){
            num_visited_nodes++;
            visited[dest] = 1;
            stack[stack_size++] = dest;
         }
      }
   }
   free(stack);
   free(visited);
   res.is_connected = (num_visited_nodes<n) ? 0 : 1;
   //abbiamo attraversato ogni arco due volte, dividiamo per 2 
   edges_num = (edges_num%2) ? edges_num/2+1 : edges_num/2;
   //printf("edges %d\n", edges_num);//test
   res.is_acyclic = (edges_num!=n-1) ? 0 : 1;
   return res;
}
int main(){
   int n, i;
   edges *E = NULL;
   scanf(" %d", &n);
   if(n==0) return 1;
   E = read(n);
   result res = dfs_visited(0, E, n);
   (res.is_connected && res.is_acyclic) ? printf("%s", OK) : 
                                          printf("%s", NO);
   //libero la memoria
   for(i=0; i<n; i++){
      free(E[i].edges);
   }
   free(E);

   return 0;
}
