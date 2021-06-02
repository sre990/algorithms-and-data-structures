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

void insert(int k, Node **t){
   if(!*t){ 
      *t = create(k); 
      return;
   }
   Node *curr, *parent;
   curr = *t; //curr punta al primo nodo di t
   //attraversiamo t
   while(curr){
      parent = curr;
      if(curr->key<k) curr = curr->right;
      else curr = curr->left;
   }
   //dopo il loop arriviamo all'ultima foglia
   //con curr=NULL. Dobbiamo inserire qui
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

int lookup(int k, Node **t){
   int i = 0;
   Node *curr = *t;
   while(curr){
      if(curr->key==k) return i;
      if(curr->key<k) curr=curr->right;
      else curr=curr->left;
      i++;
   }

   return -1;
}

int lookupRec(int k, Node **t){
   if(!*t) return -1;
   Node *curr = *t;
   if(curr->key==k) return 0;
   int found = -1;
   if(curr->key<k) found = lookupRec(k, &curr->right);
   else found = lookupRec(k, &curr->left);
   if(found>=0) return 1+found;
   else return -1;
   //funziona ma capire meglio
}

//in-order display
void print(Node *t){
   if(t){
      print(t->left);
      printf("%d ", t->key);
      print(t->right);
   }

}

int main(){
   Node *root = NULL;
   int k, len, i;
   //costruisco BST
   scanf("%d", &len);
   for(i=0; i<len; i++){
      scanf("%d", &k);
      insert(k, &root);
   }
   //print(root);//test
   //printf("\n");
   scanf("%d", &k);
   i = lookupRec(k, &root);
   while(k!=-1){
      if(i>=0){ 
         printf("%d\n", i);
         scanf("%d", &k);
         i = lookupRec(k, &root);
      }else{
         printf("NO\n");
         scanf("%d", &k);
         i = lookupRec(k, &root);
      }
   }
 
   return 0;
}
