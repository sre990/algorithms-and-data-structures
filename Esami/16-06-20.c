#include <stdlib.h>
#include <stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
typedef struct _node {
   int key;
   struct _node *left;
   struct _node *right;
} node;
// Inserimento in un albero binario non bilanciato.
// In caso di duplicati, l'inserimento va fatto a sinistra.
node *insert(node *root, int k) {
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
// Liberiamo la memoria una volta finito
void free_mem(node **root){
   if(*root){
      node *curr = *root;
      free_mem(&curr->left);
      free_mem(&curr->right);
      free(curr);
   }
}
// Ad ogni passo, questa funzione calcola il numero di nodi che 
// abbiamo visitato e che vengono passati come parametro della
// funzione. Il terzo parametro ci dice il fattore di bilanciamento. 
void unbalanced_helper(const node *root, int *nodes_num, int *fact) {
   if (!root) {
      *nodes_num = 0;
      return;
   }
   int nodes_sx, nodes_dx;
   unbalanced_helper(root->left, &nodes_sx, fact);
   unbalanced_helper(root->right, &nodes_dx, fact); 
   *nodes_num = nodes_sx + nodes_dx + 1;
   //printf("nodi a sx %d e a dx %d\n", nodes_sx, nodes_dx);//test
   //voglio il massimo degli sbilanciamenti per ogni sottoalbero
   int max_fact = max(abs(nodes_sx - nodes_dx), *fact);
   *fact = max_fact;
}
// Funzione di supporto che restituisce lo sbilanciamento massimo. 
// Alla prima chiamata il fattore di sbilanciamento e' 0. 
int unbalanced_by(const node *root) {
   int nodes_num;
   int fact = 0;//fattore di sbilanciamento
   unbalanced_helper(root, &nodes_num, &fact);
   
   return fact;
}
// Funzione che stampa chiave di ogni nodo (per testing)
void print(node *root){
   if(root){
      print(root->left);
      printf("Nodo %d\n", root->key);
      print(root->right);
   }  
}
int main() {
   int k;
   size_t n;
   node *root = NULL;
   scanf("%ld", &n);
   for (size_t i = 0; i < n; i++) {
      scanf("%d", &k);
      root = insert(root, k);
   }
   //print(root);//test
   printf("%d\n", unbalanced_by(root));
   free_mem(&root);
   
   return 0;
}
