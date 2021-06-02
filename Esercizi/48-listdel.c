#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

//inserisci alla fine. Crea lista
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

int cmp(const void *a, const void *b){
   elem a1 = *(elem *)a;
   elem b1 = *(elem *)b;
   return a1.key - b1.key;
}

elem *removeLessEq(int avg, elem *head){
   while(head && (head->key<=avg)){
      free(head);
      head = head->next;
   } 
   if(!head) return NULL;
   elem *curr = head;
   elem *prev = head;
   curr = curr->next;
   while(curr){
      if(curr->key<=avg){
         free(curr);
         prev->next = curr->next;
      }else{
         prev = curr;
      }
      curr = curr->next;
   }
   return head;

}

int average(int n, elem **list){
   int sum = 0;
   elem *curr = *list;  
   while(curr){
      sum += curr->key;
      curr = curr->next;
   }
   return floor(sum/n);
}

void print(elem *list){
   if(!list) return;
   while(list){
      printf("%d ", list->key);
      list = list->next;
   }
   printf("\n");
}

void clean(elem *head){
   if(!head) return;
   while(head){
      free(head);
      head = head->next;
   }
}

int main(){
   elem *head = NULL;
   int avg, n, len, i;
   scanf("%d", &len);
   //head = malloc(len*(sizeof(elem)));
   for(i=0;i<len; i++){
      scanf("%d", &n);
      append(n, &head);
   }
   //qsort(head, len, sizeof(elem), cmp);
   avg = average(len, &head);
   printf("%d\n", avg);
   print(head);
   head = removeLessEq(avg, head);   
   print(head);
   clean(head);

   return 0;
}
