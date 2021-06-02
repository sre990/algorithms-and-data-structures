#include <stdio.h>
#include <stdlib.h>
#define P 941
//TESTO: acquisire un numero N di matricole e riempire una tabella
// Hash di dimensione 2N secondo la funzione h=(matricola*941)%2N,
//successivamente si acquisiscono sue sequenze di matricole 
//rispettivamente di lunghezza m1 e m2 che corrispondono ai bocciati
// di prima prova e seconda prova. Eliminare dalla tabella hash le
// matricole presenti in sia in m1 che in m2 e stampare il numero di
// studenti che possono sostenere la prova finale (che sono stati
// bocciati max 1 volta).
typedef struct _elem{
   int mat;
   int fail;
   struct _elem *next;
}elem;
int hash(int mat, size_t n){
   return (mat*P) % (2*n);
}
elem *create(int mat){
   elem *head = malloc(sizeof(elem));
   head->mat = mat;
   head->fail = 0;
   head->next = NULL;
   return head;
}
void append(elem **list, int mat){
   if(!*list){
      *list = create(mat);
      //printf("lista vuota, inserito %d, failed:%d\n", 
      //      (*list)->mat, (*list)->fail);
      return;
   }
   elem *curr = *list;
   elem *prev;
   while(curr){
      prev = curr;
      if(curr->mat == mat){
         curr->fail++;
         //printf("aggiornato mat:%d failed:%d\n", 
         //      curr->mat, curr->fail);
         return;       
      }else{
         //printf("non ancora inserito %d, avanti...\n", mat);
         curr=curr->next;
      }
   }
   prev->next = create(mat);
   //printf("inserito alla fine mat:%d failed:%d\n", 
   //      prev->next->mat, prev->next->fail);
}
int count(const elem *root){
   int c = 0;
   while(root){
      if(root->fail<=1) c++;
      root = root->next;
   }
   return c;
}
void clean(elem *root){
   if(root){
      clean(root->next);
      free(root);
   }
}
int main(){
   size_t n, m1, m2, i;
   int h, mat, c;
   elem **T = NULL;
   scanf("%lu", &n);
   T = malloc(n*2*sizeof(elem *));
   //devo inizializzare a NULL altrimenti mi da errore.
   for(i=0; i<n*2; i++){
      T[i] = NULL;
   }
   for(i=0; i<n; i++){
      scanf("%d", &mat);
      h = hash(mat, n);
      append(&T[h], mat);
   }
   scanf("%lu %lu", &m1, &m2);
   for(i=0; i<m1; i++){
      scanf("%d", &mat);
      h = hash(mat, n);
      append(&T[h], mat);
   }
   for(i=0; i<m2; i++){
      scanf("%d", &mat);
      h = hash(mat, n);
      append(&T[h], mat);
   }
   c = 0;
   for(i=0; i<n*2; i++){
      if(T[i]) c += count(T[i]);
   }
   printf("%d studenti possono sostenere la prova finale.\n", c);
   for(i=0; i<n*2; i++){
      if(T[i]) clean(T[i]);
   }
   free(T);

   return 0;
}
