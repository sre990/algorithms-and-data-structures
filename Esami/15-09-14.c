#include <stdio.h>
#include <stdlib.h>
#define MAX 10
//definiamo “visita sinistra” dell’albero la visita che,
//partendo dalla radice, opera ricorsivamente come segue: sono
//visitati tutti e soli i nodi presenti nel cammino che, partendo
// dalla radice, sceglie sempre e soltanto i figli sinistri,
//finché ce ne sono.
//definiamo “visita destra” dell’albero la visita che, partendo
//dalla radice, opera ricorsivamente come segue: se un nodo ha
//un figlio destro d, tale figlio è visitato e la visita prosegue da
//d; altrimenti termina.
//L(u): il numero di nodi visitati dalla “visita sinistra” del
// sottoalbero, escluso u.
//R(u): il numero di nodi visitati dalla “visita destra” del
// sottoalbero, escluso u.
typedef struct _Node{
   int key;
   int l, r;
   struct _Node *left;
   struct _Node *right;
}Node;
Node *create(const int k){
   Node *root = malloc(sizeof(Node));
   root->key = k;
   root->left = NULL, root->right = NULL;

   return root;
}
//insert (iterativo+ricorsivo)
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
//funzione che ricorsivamente mi calcola i valori di L(u) e R(u).
//dove u e' ciascun nodo dell'albero.
void unbalanced_helper(Node *root, int *sx, int *dx){
   if(!root){
      *sx = 0;
      *dx = 0;
      return;
   }
   int lvisit_sx, lvisit_dx, rvisit_sx, rvisit_dx;
   unbalanced_helper(root->left, &lvisit_sx, &lvisit_dx);
   unbalanced_helper(root->right, &rvisit_sx, &rvisit_dx);
   root->l = (root->left) ? lvisit_sx+1 : lvisit_sx;
   root->r = (root->right) ? rvisit_dx+1 : rvisit_dx;
   *sx = root->l;
   *dx = root->r;
}
//aggiorno i valori della visita dx e sx per ciascun nodo
void unbalanced_nodes(Node **T){
   if(*T){
      int visit;
      Node *curr = *T;
      unbalanced_helper(curr, &visit, &visit);
   }
}
//stampo tutti i nodi per cui L(root)>R(root). In ordine.
void printLR(const Node *root){
   if(root){
      printLR(root->left);
      if(root->l > root->r) printf("%d\n", root->key);
      printLR(root->right);
   }
}
void clean(Node *root){
   if(root){
      clean(root->left);
      clean(root->right);
      free(root);
   }
}
//per testing:
void print(const Node *root){
   if(root){
      print(root->left);
      printf("%d\n", root->key);
      print(root->right);
   }
}
int main(){
   Node *root = NULL;
   size_t len, i;
   int k;
   //read tree
   scanf("%lu", &len);
   for(i=0; i<len; i++){
      scanf("%d", &k);
      insert(k, &root);
   }   
   //print(root);
   //printf("\n");
   unbalanced_nodes(&root);
   printLR(root);
   clean(root);

   return 0;
}
