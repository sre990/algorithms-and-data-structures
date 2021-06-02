#include <stdio.h>
#include <stdlib.h>
//ogni nodo della lista e' formato da un valore k e il puntatore
//al prossimo nodo
typedef struct _elem{
   int key;
   struct _elem *next;
}elem;

//per creare una nuova lista lo usiamo con next = NULL
elem *create(int key){
   elem *new = malloc(sizeof(elem));
   if(new){
      new->next = NULL;
      new->key = key;
   }
   return new;
}

//crea lista
void append(int key, elem **list){
   if(!*list){ 
      *list = create(key); 
      return;
   }
   elem *listPtr = *list;
   while(listPtr->next){
      listPtr = listPtr->next;
   }
   listPtr->next = create(key);
}

elem *mtf(int k, elem **list){
   elem *curr = *list;

   if(!curr||curr->key==k) return curr;
   while(curr->next && curr->next->key != k){
      curr = curr->next;
   }
   if(!curr->next) return NULL;
   elem *tmp = *list;
   *list = curr->next;
   curr->next = curr->next->next;
   (*list)->next = tmp;

   return *list;

}

//trova la posizione della chiave, -1 se assente
int find(int key, elem *head){
   int i;
   for(i=0; head; i++){
      if(head->key==key) return i;
      head = head->next;
   }
   return -1;
}

void print(elem *list){
   while(list){
      printf("%d\n", list->key);
      list = list->next;
   }
}

int main(){
   elem *head = NULL;
   int n, len, i;
   scanf("%d", &len);
   for(i=0;i<len; i++){
      scanf("%d", &n);
      append(n, &head);
   }
   scanf("%d", &n);
   i = find(n, head);
   while(i!=-1){
      head = mtf(n, &head);
      printf("%d\n", i);
      scanf("%d", &n);
      i = find(n, head);
   }
   printf("%d\n", i);
   //print(head); 
   return 0;
}
