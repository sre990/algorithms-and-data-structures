#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
   int key;
   struct _node *left;
   struct _node *right;
}Node;
Node *create(const int k){
   Node *T = malloc(sizeof(Node));
   T->key = k;
   T->left = NULL;
   T->right = NULL;
   return T;
}
void insert(Node **T, const int k){
   if(!*T){
      *T = create(k);
      return;
   }
   Node *curr = *T;
   Node *parent;
   while(curr){
      parent = curr;
      if(curr->key<k) curr = curr->right;
      else curr = curr->left;
   }
   if(parent->key<k) parent->right = create(k);
   else parent->left = create(k);
}
//metodo iterativo per restituire il secondo nodo piu' grande
Node *visit(Node *root){
   Node *curr = root;
   Node *parent = root;
   Node *second;
   while(curr->right){
      parent = curr;
      curr = curr->right;
   }
   if(curr->left){
      curr = curr->left;
      while(curr->right){
         curr = curr->right;
      }
      second = curr;
   }else{
      second = parent;
   }
   return second;

}
void clean(Node *root){
   if(root){
      clean(root->right);
      clean(root->left);
      free(root);
   }
}
int main(){
   size_t n;
   int k;
   scanf("%lu", &n);
   //devo inserire almeno due nodi nell'albero
   if(n<2) return 0;
   Node *T = NULL;
   for(size_t i=0; i<n; i++){
      scanf("%d", &k);
      insert(&T, k);
   }
   Node *second = visit(T);
   printf("%d\n", second->key);
   clean(T);

   return 0;
}
