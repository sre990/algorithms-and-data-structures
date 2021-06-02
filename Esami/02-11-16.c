#include <stdio.h>
#include <stdlib.h>
typedef struct _elem{
   int val;
   int counter;
   struct _elem *next;
}elem;
//inutile
int hash(int val, size_t n){
   return val % n;
}
elem *create(int val){
   elem *head = malloc(sizeof(elem));
   head->val = val;
   head->counter = 1;
   head->next = NULL;
   return head;
}
void append(elem **list, int val){
   if(!*list){
      *list = create(val);
      //printf("lista vuota, inserito %d, count:%d\n", 
      //      (*list)->val, (*list)->counter);
      return;
   }
   elem *curr = *list;
   elem *prev;
   while(curr){
      prev = curr;
      if(curr->val == val){
         curr->counter++;
         //printf("aggiornato val:%d count:%d\n", 
         //      curr->val, curr->counter);
         return;       
      }else{
         //printf("non ancora inserito %d, avanti...\n", val);
         curr=curr->next;
      }
   }
   prev->next = create(val);
   //printf("inserito alla fine val:%d count:%d\n", 
   //      prev->next->val, prev->next->counter);
}
void print(const elem *root, const int k){
   while(root){
      if(root->counter>=k) printf("%d ", root->val);
      root = root->next;
   }
   
}
void clean(elem *root){
   if(root){
      clean(root->next);
      free(root);
   }
}
int main(){
   size_t n, i;
   int k, h, val;
   int *arr = NULL;
   elem **T = NULL;
   scanf("%lu", &n);
   scanf("%d", &k);
   arr = malloc(sizeof(size_t)*n);
   T = calloc(n, sizeof(elem *));
   for(i=0; i<n; i++){
      scanf("%d", &val);
      h = hash(val, n);
      append(&T[h], val);
      arr[i] = val;
      //printf("val%d (%d) at pos %d\n",
      //         T[h]->val, T[h]->counter, h);
   }
   for(i=0; i<n; i++){
      h = hash(arr[i], n);  
      print(T[h], k);
   }
   printf("\n");
   for(i=0; i<n; i++){
      if(T[i]) clean(T[i]);
   }
   free(arr);
   free(T);

   return 0;
}
