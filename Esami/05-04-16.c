#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
//chiama search su stringa e restituisce il nodo con key uguale.
//poi chiama findmax su nodo corrente e trova il maggiore tra i val 
//del sottoalbero radicato nel nodo corrente
typedef struct _node{
   int val;
   char *key;
   struct _node *left;
   struct _node *right;
}Node;
Node *create(const int val, const char *key){
   Node *root = malloc(sizeof(Node));
   root->val = val; 
   root->key = malloc(MAX*sizeof(char));
   strcpy(root->key, key);
   root->left = NULL; root->right = NULL;
   return root;   
}
int findmax(const Node *root){
   if(root){
      if(!root->left && !root->right){
         return root->val;
      }else if(!root->left){
         findmax(root->right);
      }else{
         findmax(root->left);
      }
   }
   return -1;
}
Node *search(Node *T, const char *s){
   if(T){
      if(strcmp(T->key, s)==0){
         //printf("%s found\n", s);//test
         return T;
      }else if(strcmp(T->key, s)<0){
         search(T->right, s);
      }else if(strcmp(T->key, s)>0){
         search(T->left, s);
      }
   }
   return NULL;
}

void insert(Node **T, const int val, const char *key){
   if(!*T){ 
      *T = create(val, key);
      return;
   }
   Node *curr = *T;
   if(strcmp(curr->key, key)==0){
      return;
   }else if(strcmp(key, curr->key)<0){
      if(!curr->left) curr->left = create(val, key);
      else insert(&curr->left, val, key);
   }else{ 
      if(!curr->right) curr->right = create(val, key);
      else insert(&curr->right, val, key);
   }
}
void print(const Node *root){
   if(root){
      printf("(%s, %d)\n", root->key, root->val);
      print(root->left);
      print(root->right);
   }
}

void clean(Node *root){
   if(root){
      clean(root->left);
      clean(root->right);
      free(root->key);
      free(root);
   }
}
int main(){
   size_t n = 0;
   int val;
   char *key = calloc(MAX, sizeof(char));
   scanf("%lu", &n); 
   Node *T = NULL;
   for(size_t i=0; i<n; i++){
      scanf(" %s", key);
      scanf("%d", &val);
      insert(&T, val, key);
   }
   //print(T);//test
   char *s = calloc(MAX, sizeof(char));
   scanf(" %s", s);
   Node *curr = search(T,s);
   int max = findmax(curr);
   //printf("found %s\n", curr->key);//test
   printf("%d\n", max);
   free(key);
   free(s);
   clean(T);
     
   return 0;
}
