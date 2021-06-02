#include <stdio.h>
#include <stdlib.h>
// last recently used
typedef struct _item{
   int key;
   struct _item *next;
}item;
item *create(const int k){
   item *new = malloc(sizeof(item));
   if(new){
      new->key = k;
      new->next = NULL;
   }

   return new;
}
int search(const item *curr, const int k){
   int i;
   for(i=0; curr->next; i++){
      if(curr->key == k) return i;
      curr = curr->next;
   }
   return -1;
}
void push(item **queue, const int k){
      if(!*queue){
         *queue = create(k);
         return;
      }
      item *curr = *queue;
      int found = search(curr, k);

      if(found == -1){
            item *new = create(k);
            new->next = curr;
            *queue = new;
      }else if(found == 0){
         return;
      }else{
         while(curr->next && curr->next->key != k){
            curr = curr->next;
         }
         if(!curr->next) return;
         item *tmp = *queue;
         *queue = curr->next;
         curr->next = curr->next->next;
         (*queue)->next = tmp;

      }
}
//n e' la dimensione della coda
void print(const item *curr, const size_t n){
   for(size_t i=0; i<n && curr->next; i++){
      printf("%d ", curr->key);
      curr = curr->next;
   }
   printf("$\n");
}
void clean(item *curr){
   if(curr){
      clean(curr->next);
      free(curr);
   }
}
int main(){
   size_t n;//dimensione della coda
   int k, e;
   scanf(" %lu", &n);
   if(n==0) return 0;
   item *queue = NULL;
   queue = calloc(n, sizeof(item));
   scanf(" %d", &e);
   while(e != 0){
      if(e==1){
         scanf(" %d", &k);
         push(&queue, k);
      }else if(e==2){
         print(queue, n);
      }
      scanf(" %d", &e);
   }
   clean(queue);

   return 0;
}
