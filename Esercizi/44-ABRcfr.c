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
   curr = *t;
   while(curr){
      parent = curr;
      if(curr->key<k) curr = curr->right;
      else curr = curr->left;
   }
   if(parent->key<k) parent->right = create(k);
   else parent->left = create(k);

}
//Al programma viene data una chiave intera K. Si puo'
//assumere che l’intero K sia presente in entrambe le 
//sequenze.  Il programma deve verificare che le seque-
//nze di chiavi incontrate nel cammino che dalla radice
//porta al nodo con chiave K nei due alberi coincidano.
//Funziona similmente al lookup, aggiungiamo un altro
//albero.
int confronta(int k, Node **t1, Node **t2){
   Node *p1, *p2;
   p1 = *t1, p2 = *t2;
   while(p1->key!=k){
      if(p1->key<k){
         if(p1->key!=p2->key) return 0;
         p1 = p1->right;
         p2 = p2->right;
      }else{
         if(p1->key!=p2->key) return 0;
         p1 = p1->left;
         p2 = p2->left; 
      }
   }
   if(p1->key != p2->key){
      return 0;
   }
   return 1;
}
//Utility per test. Usando il pre-order
//vediamo meglio se i percorsi sono uguali
void pre_print(Node *t){
   if(t){
      printf("%d ", t->key);
      pre_print(t->left);
      pre_print(t->right);
   }
}

int main(){
   Node *t1, *t2;
   int n, len, k, i;
   t1 = NULL, t2 = NULL;
   scanf("%d %d", &len, &n);
   for(i=0; i<len; i++){
      scanf("%d", &k);
      insert(k, &t1);
   }
   for(i=0;i<len; i++){
      scanf("%d", &k);
      insert(k, &t2);
   }
/*   
   pre_print(t1);
   printf("\n");
   pre_print(t2);
   printf("\n");
*/
   i = confronta(n, &t1, &t2);
   printf("%d\n", i);

   return 0;
}
