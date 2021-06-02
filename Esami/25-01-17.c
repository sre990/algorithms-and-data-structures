#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100
typedef struct _node{
   char u[MAXLEN];
   struct _node *left;
   struct _node *right;
}node;

node *create(const char *u){
   node *root = malloc(sizeof(node));
   if(root){
      strcpy(root->u, u);
      root->left = NULL; 
      root->right = NULL;
   }
    
   return root;
}

//inserimento in ordine lessicografico
void insert(node **T, const char *u){
   if(!*T){ 
      *T = create(u);
      return;
   }
   node *curr = *T;
   if(strcmp(curr->u, u)==0){
      return;
   }else if(strcmp(u, curr->u)<0){
      if(!curr->left) curr->left = create(u);
      else insert(&curr->left, u);
   }else{ 
      if(!curr->right) curr->right = create(u);
      else insert(&curr->right, u);
   }

}
//aux
int is_prefix(const char *u, const char *v){ 
   if(strlen(u)>strlen(v)) return 0;
   for(int i=0; i<strlen(u); i++){
      if(u[i]!=v[i]) return 0;
   }
   return 1;
}
char* prefix(node *root){
   if(root){
      char *min;
      //il minimo del sottoalbero radicato in root e' il nodo
      // piu' a sx
      min = prefix(root->left);
      //se siamo su una foglia, stampiamo la chiave e basta
      if(!min){
         printf("%s\n", root->u);
      }else{
      //altrimenti verifichiamo che il min e' un prefisso del nodo
      //corrente e nel caso stampiamo
         if(is_prefix(min, root->u)) printf("%s\n", root->u);
      }
      //visitiamo il sottoalbero a dx
      prefix(root->right);
      //se siamo arrivati a una foglia, root e' il minimo e lo resti-
      //tuiamo
      if(!root->left) return root->u;
      //altrimenti restituiamo min alle chiamate ricorsive.
      return min;
      
   }
   return NULL;
}
//test in-order print
void print(const node *root){
   if(root){
      print(root->left);
      printf("%s\n", root->u); 
      print(root->right);
   }
}
void clean(node *root){
   if(root){
      clean(root->left);
      clean(root->right);
      free(root);
   }
}

int main(){
   size_t n = 0;
   node **T = NULL;
   char u[MAXLEN];
   scanf("%lu", &n);
   if(n==0) return 0;
   T = malloc(n*sizeof(node));
   for(size_t i=0; i<n; i++){
      scanf("%s", u);
      T[i] = NULL;
      insert(T, u);
   }
   prefix(*T);
   //printf("\n");
   //print(*T);//test
   node *curr = *T;
   clean(curr);
   free(T);

   return 0;
}
