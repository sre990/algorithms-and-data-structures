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
//Utility per visit
int myMax(int l, int r){
   if(l<r) return r;
   else return l;
}

//max depth
int visit(Node **t){
   if(!*t) return 0;
   Node *curr = *t;
   return 1+myMax(visit(&curr->left), 
                  visit(&curr->right));
}

void print(Node *t){
   if(t){
   print(t->left);
   printf("%d ", t->key);
   print(t->right);
   }
}

int main(){
   Node *root = NULL;
   int len, k, i, d;
   //read tree
   scanf("%d", &len);
   for(i=0; i<len; i++){
      scanf("%d", &k);
      insert(k, &root);
   }   
   //print(root);
   //printf("\n");
   d = visit(&root);
   printf("%d\n", d);

   return 0;
}
