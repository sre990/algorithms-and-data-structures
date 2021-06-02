#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
   int key;
   struct _Node *left;
   struct _Node *right;
}Node;

Node *create(int k){
   Node *root = malloc(sizeof(Node));
   root->key = k;
   root->left = NULL, root->right = NULL;

   return root;
}

//insert iterativo+ricorsivo
void insert(int k, Node **t){
   if(!*t){ 
      *t = create(k);
      return;
   }
   Node *curr, *parent;
   curr = *t;
   while(curr){
      parent = curr;
      if(curr->key<k) curr = curr->right;
      else curr = curr->left;
   }
   if(parent->key<k) parent->right = create(k);
   else parent->left = create(k);
}
void insertRec(int k, Node **t){
   if(!*t){
      *t = create(k);
      return;
   }
   Node *curr = *t;
   if(curr->key<k) insertRec(k, &curr->right);
   else insertRec(k, &curr->left);
}

//in-order traversal
void print(Node *t){
   if(t){
   print(t->left);
   printf("%d\n", t->key);
   print(t->right);
   }
}
//pre-order traversal
void pre_print(Node *t){
   if(t){
      printf("%d\n", t->key);
      pre_print(t->left);
      pre_print(t->right);
   }
}
//post-order traversal
void post_print(Node *t){
   if(t){
      post_print(t->left);
      post_print(t->right);
      printf("%d\n", t->key);
   }
}

int main(){
   Node *root = NULL;
   int len, k, i;
   //read tree
   scanf("%d", &len);
   for(i=0; i<len; i++){
      scanf("%d", &k);
      insert(k, &root);
   }   
   print(root);
   //printf("\n");
   //pre_print(root);
   //printf("\n");
   //post_print(root);
   //printf("\n");

   return 0;
}
