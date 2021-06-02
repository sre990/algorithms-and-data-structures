/* BERTOSSI-MONTRESOR ES. 5.7 - Dato un ABR aggiungere ad ogni nodo foglia, un figlio sinistro con chiave 0 */
#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
   int key;
   struct _node *left;
   struct _node *right;
} node;
node *insert (node *root, int k){
   if (!root) {
      node *new = malloc(sizeof(node));
      new->key = k;
      new->left = NULL;
      new->right = NULL;
      return new;
   }
   if (k <= root->key) { //in caso di duplicati inserisco a sinistra
      root->left = insert(root->left, k);
   } else {
      root->right = insert(root->right, k);
   }

   return root;
}
//helper
int is_leaf(node *root){
   int res;
   (!root->left && !root->right) ? (res=1) : (res=0);
   return res;
}
//FIX:non funziona per la foglia piu' a sinistra (usare stack)
//controllo se la radice e' vuota, se e' vuota esco.
//controllo se ha figli, se non li ha aggiungo nodo 0 a sx.
//se li ha controllo se ha figli sinistro e se lo ha chiamo la 
//ricorsivamente sul figlio sinistro. discorso analogo per il figlio
//destro.
void add_zero_leaf(node **t){
   if (!(*t)) return;
   node *curr = *t;
   if(!is_leaf(curr)){
      add_zero_leaf(&curr->right);
      add_zero_leaf(&curr->left);
   }else{
      //printf("nodo foglia %d trovato!\n", curr->key);//test
      node *zero= malloc(sizeof(node));
      zero->key=0;
      zero->left=NULL;
      zero->right=NULL;
      curr->left=zero;
   }
}
//stampa in-order
void print(node *root){
   if (root){
      print(root->left);
      printf("%d\n",root->key);
      print(root->right);
   }
}
void free_mem(node **root){
   if(*root){
      node *curr = *root;
      free_mem(&curr->left);
      free_mem(&curr->right);
      free(curr);
   }
}
int main(){
   size_t n, i;
   int el;
   node *root=NULL;
   scanf("%lu",&n);
   for (i=0;i<n;i++){
      scanf("%d",&el);
      root = insert(root,el);
   }
   printf("l'albero originale e':\n");
   print(root);
   add_zero_leaf(&root);
   printf("il nuovo albero e':\n");
   print(root);
   free_mem(&root);
   
   return 0;
}
