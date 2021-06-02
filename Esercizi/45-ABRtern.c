#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
   int key;
   struct _Node *left;
   struct _Node *center;
   struct _Node *right;
}Node;

Node *create(int k){
   Node *root = malloc(sizeof(Node));
   root->key = k; 
   root->left = NULL; 
   root->center = NULL;
   root->right = NULL;
   
   return root;
}
//Assumendo che k!=0, se no
//dividiamo per 0
void insert(int k, Node **t){
   if(!*t){
   *t = create(k);
   return;
   }
   Node *curr, *parent;
   curr = *t;
   while(curr){
      parent = curr;
      if(k<curr->key) curr = curr->left;
      else if(k%curr->key==0) curr = curr->center;
      else curr = curr->right;
   }
   if(k<parent->key) parent->left = create(k);
   else if(k%parent->key==0) parent->center = create(k);
   else parent->right = create(k);
}

void insertRec(int k, Node **t){
   if(!*t){ 
      *t = create(k);
      return;
   }
   Node *curr = *t;
   if(k<curr->key) insertRec(k, &curr->left);
   else if(k%curr->key==0) insertRec(k, &curr->center);
   else insertRec(k, &curr->right);

}
//stampa il numero di nodi che hanno tre figli
int countTern(Node *node){
   if(!node) return 0;
   int l, c, r, curr;
   l = c = r = curr = 0;
   if(node->left){
      l = countTern(node->left); 
      curr++;
   }
   if(node->center){
      c = countTern(node->center); 
      curr++;
   } 
   if(node->right){
      r = countTern(node->right); 
      curr++;
   }

   if(curr==3) return l+c+r+1;
   else return l+c+r;
}

//fa il pre-order
//da rivedere in-order
void pre_print(Node *t){
   if(t){
      printf("%d ", t->key);
      pre_print(t->left);
      pre_print(t->center);
      pre_print(t->right);
   }
}

int main(){
   Node *root = NULL;
   int len, k, i;
   scanf("%d", &len);
   for(i=0; i<len; i++){
      scanf("%d", &k);
      insert(k, &root);
   }
   //pre_print(root);
   printf("%d\n", countTern(root));
   return 0;
}
