#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
   int key;
   struct _Node *left;
   struct _Node *right;
}Node;
Node *create(const int k){
   Node *root = malloc(sizeof(Node));
   root->key = k;
   root->left = NULL, root->right = NULL;

   return root;
}
//insert iterativo+ricorsivo
void insert(const int k, Node **t){
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
void insertRec(const int k, Node **t){
   if(!*t){
      *t = create(k);
      return;
   }
   Node *curr = *t;
   if(curr->key<k) insertRec(k, &curr->right);
   else insertRec(k, &curr->left);
}
//stampare tutti i nodi a livello k, ordinatamente
void k_level(const Node *t, int k){
    if(!t){
        return;
    }
    //la parte ricorsiva va dalla radice verso il livello giusto,
    //mentre il k si decrementa. Quando k diventa 0, significa che
    //siamo arrivati al livello che ci interessa. E stampiamo
    if(k == 0){
        printf("%d\n", t->key);
        return;
    }else{
        k_level(t->left, k-1);
        k_level(t->right, k-1); 
    } 

}
void clean(Node *t){
   if(t){
      clean(t->left);
      clean(t->right);
      free(t);
   }
}
//test
void print(const Node *t){
   if(t){
      print(t->left);
      printf("%d ", t->key);
      print(t->right);
   }
}
int main(){
   Node *root = NULL;
   size_t len, i;
   int n, k;
   //read tree
   scanf("%lu", &len);
   for(i=0; i<len; i++){
      scanf("%d", &n);
      insert(n, &root);
   }   
   //test
   //print(root);
   //printf("\n");
   
   //leggo il livello k
   scanf("%d", &k);
   k_level(root, k);
   clean(root);
   
   
   return 0;
}
