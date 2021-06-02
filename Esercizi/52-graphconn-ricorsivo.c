#include <stdio.h>
#include <stdlib.h>

typedef struct _edges{
   int num;
   int *edges;
}edges;

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
   int n, i;
   edges *E = NULL;
   scanf(" %d", &n);
   E = read(n);
   int *visited = calloc(n, sizeof(int));
   dfs(0, E, visited);
   printf("%d\n", is_connected(visited, n));
   free(visited);
   for(i=0; i<n; i++){
      free(E[i].edges);
   }
   free(E);

   return 0;
}
