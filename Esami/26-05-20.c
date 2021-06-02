#include <stdlib.h>
#include <stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define TRUE "TRUE\n"
#define FALSE "FALSE\n"
typedef struct _node {
   int key;
   int col;
   struct _node *left;
   struct _node *right;
} node;
// Inserimento in un albero binario non bilanciato.
// In caso di duplicati, l'inserimento va fatto a sinistra.
node *insert(node *root, int k, int c) {
   if (!root) {
      node *new = malloc(sizeof(node));
      new->key = k;
      new->col = c;
      new->left = NULL;
      new->right = NULL;
      return new;
   }
   if (k <= root->key) { //in caso di duplicati inserisco a sinistra
      root->left = insert(root->left, k, c);
   } else {
      root->right = insert(root->right, k, c);
   }

   return root;
}
// Liberiamo la memoria una volta finito
void free_mem(node **root){
   if(*root){
      node *curr = *root;
      free_mem(&curr->left);
      free_mem(&curr->right);
      free(curr);
   }
}
// Ad ogni passo, questa funzione calcola il numero di nodi rossi che
// abbiamo trovato e che vengono passati come parametro della
// funzione. Il terzo parametro ci dice se a ogni chiamata ricorsiva 
// e' verificata la condizione (abs(altezza rossa sx - altezza rossa
// destra) <= 1). 
void _one_balanced(const node *root, int *red_nodes, int *cond) {
   if (!root || !(*cond)) {
      *red_nodes = 0;
      return;
   }
   int red_nodes_sx, red_nodes_dx;
   _one_balanced(root->left, &red_nodes_sx, cond);
   _one_balanced(root->right, &red_nodes_dx, cond);
   //aggiorno l'altezza rossa  del nodo corrente con il massimo 
   //tra le altezze rosse dei due sottoalberi
   *red_nodes = max(red_nodes_sx, red_nodes_dx);
   //se il colore e' rosso incremento l'altezza del nodo corrente
   if(!root->col){*red_nodes = *red_nodes+1;}
   //se la differenza l'altezza sinistra e destra e' piu' di 1 la
   //condizione non e' verificata.
   if(abs(red_nodes_sx - red_nodes_dx) > 1){*cond = 0;}
}
// Funzione di supporto che dice se la condizione richiesta e' 
// verificata. La prima chiamata richiede di passare cond = 1. 
int one_balanced(const node *root) {
   int reds;
   int cond = 1;
   _one_balanced(root, &reds, &cond);
   
   return cond;
}
// Funzione che stampa chiave e colore di un nodo (per testing)
void print(node *root){
   if(root){
      print(root->left);
      if(root->col==0){
         printf("Nodo %d di colore BIANCO\n", root->key);
      } else {
         printf("Nodo %d di colore ROSSO\n", root->key);
      }
      print(root->right);
   }  
}
int main() {
   int k, c;
   size_t n;
   node *root = NULL;
   scanf("%ld", &n);
   for (size_t i = 0; i < n; i++) {
      scanf("%d %d", &k, &c);
      root = insert(root, k, c);
   }
   //print(root);//test
   (one_balanced(root)) ? printf(TRUE) : printf(FALSE);
   free_mem(&root);
   
   return 0;
}
