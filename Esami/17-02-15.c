#include <stdio.h>
#include <stdlib.h>
//stampa il piu' piccolo nodo nel cammino di somma massima
typedef struct _node{
   int key;
   struct _node *left, *right;
}node;
node *create(const int k){
   node *root = malloc(sizeof(node));
   root->key = k;
   root->left = NULL;
   root->right = NULL;
   
   return root;
}
void append(node **T, const int k){
   if(!(*T)){ 
      *T = create(k);
      return;
   }
   node *curr, *parent;
   curr = *T;
   while(curr){
      parent = curr;
      if(curr->key > k){
         curr = curr->left;
      }else curr = curr->right;
   }
   if(parent->key > k){
      parent->left = create(k);
   }else parent->right = create(k);
}
int cmp(const void *a, const void *b){
   const int *a1 = (const int *)a;
   const int *b1 = (const int *)b;
   return *a1-*b1;
}
//helper che prende in input il nodo radice, la somma massima di
//un cammino di somma massima e il piu' piccolo nodo di questo cammino
//(caso base: NULL, 0, 0). Questa funzione trova la somma massima del
//cammino di somma massima e il valore del piu' piccolo nodo apparte-
//nente a questo cammino
void max_path_helper(const node *root, int *max_sum, int *min){
   if(!root){
      *max_sum = 0;
      *min = 0;
      return;
   }
   int max_sum_sx, max_sum_dx, min_sx, min_dx;
   //passo ricorsivo: eseguo per sottoalbero sx e dx
   max_path_helper(root->left, &max_sum_sx, &min_sx);
   max_path_helper(root->right, &max_sum_dx, &min_dx);
   //se il cammino di somma massima sx e' maggiore di quello dx
   //significa che non abbiamo un sottoalbero destro
   if(max_sum_dx<max_sum_sx){
      //la somma del cammino di somma massima e' il nodo corrente
      //piu' la somma del cammino di somma massima del sottoalbero sx
      *max_sum = max_sum_sx + root->key;
      //se non abbiamo nemmeno nodo sx, allora il piu' piccolo nodo
      //e' il nodo corrente, altrimenti e' il figlio sinistro del
      //nodo corrente.
      *min = (max_sum_sx==0) ? root->key : min_sx;
   }else{
      //la somma del cammino di somma massima e' il nodo corrente
      //piu' la somma del cammino di somma massima del sottoalber dx
      *max_sum = max_sum_dx + root->key;
      //sappiamo che un nodo e' sempre piu' piccolo del suo figlio dx
      //quindi aggiorniamo min con il nodo corrente.
      *min = root->key; 
   }
}
//restituisce il piu' piccolo nodo.
int max_path(const node *root){
   int max_sum;
   int min;
   max_path_helper(root, &max_sum, &min);
   
   return min;
}
void print(const node *root){
   if(root){
      printf("%d ", root->key);
      print(root->left);
      print(root->right);
   }
   printf("\n");
}
void clean(node *root){
   if(root){
      clean(root->left);
      clean(root->right);
      free(root);
   }
}
int main(){
   size_t n, i;
   int k, min;
   node *root = NULL;
   scanf("%ld", &n);
   if(n==0) return 1;
   for(i=0; i<n; i++){
      scanf("%d", &k);
      append(&root, k);
   }
   //print(T);//test
   min = max_path(root);
   printf("%d\n", min);
   clean(root);

   return 0;
}
