#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//lowest common ancestor (puo' anche essere uno dei due stessi nodi).
typedef struct _node{
   int val;
   struct _node *left;
   struct _node *right;
}Node;
Node *create(const int val){
   Node *root = malloc(sizeof(Node));
   root->val = val;
   root->left = NULL; root->right = NULL;
   return root;   
}
void insert(Node **T, const int val){
   if(!(*T)){ 
      *T = create(val);
      return;
   }
   Node *curr, *parent;
   curr = *T;
   while(curr){
      parent = curr;
      if(curr->val > val){
         curr = curr->left;
      }else curr = curr->right;
   }
   if(parent->val > val){
      parent->left = create(val);
   }else parent->right = create(val);
}
int find_lca(const Node *root, const int l, const int r){
   if(root){
      if(root->left){
         if(root->val > l && root->val > r){
            return find_lca(root->left, l, r);
         }
         if(root->val < l && root->val < r){
            return find_lca(root->right, l, r);
         }
      }
   }
   return root->val;
}
void print(const Node *root){
   if(root){
      printf("%d\n", root->val);
      print(root->left);
      print(root->right);
   }
}
void clean(Node *root){
   if(root){
      clean(root->left);
      clean(root->right);
      free(root);
   }
}
int main(){
   size_t n;
   int l, r;
   int val;

   scanf("%lu", &n); 
   Node *T = NULL;
   for(size_t i=0; i<n; i++){
      scanf("%d", &val);
      insert(&T, val);
   }
   scanf("%d %d", &l, &r);
   //print(T);//test
   printf("%d\n", find_lca(T, l, r));
   clean(T);
     
   return 0;
}
