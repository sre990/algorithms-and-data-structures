#include <stdio.h>
#include <stdlib.h>
typedef struct _elem{
   int key;
   struct _elem *prev;
   struct _elem *next;
}elem;

//create node
elem *create(int k){
   elem *new = malloc(sizeof(elem));
   if(new){
      new->key = k;
      new->next = NULL;
      new->prev = NULL;
   }
   return new;
}

//push
void push(int k, elem **list){
   elem *new = create(k);
   new->next = *list;
   new->prev = NULL;
   if(*list) (*list)->prev = new;
   *list = new;

}

//create list
void append(int k, elem **list){
   if(!*list){
      *list = create(k);
      return;
   }
   elem *node = create(k);
   elem *listPtr = *list;
   while(listPtr->next){
      listPtr = listPtr->next;
   }
   listPtr->next = node;
   node->prev = listPtr;

}

//metodo iterativo
void reverse(elem **head){
   elem *tmp = NULL;
   elem *curr = *head;
   if(!*head || !(*head)->next) return;//se e' <=1 usciamo
   while(curr){//iterazione+swap   
      curr->prev = curr->next;
      curr->next = tmp;
      tmp = curr;
      curr = curr->prev;
   }
   *head = tmp; //head ora punta all'ultimo      
}

void clean(elem *list){
   if(!list) return;
   elem *curr = list;
   elem *next = NULL;
   while(curr){
      next = curr->next;
      free(curr);
      curr = next;
   }
}

//print list
void revPrint(elem **list){
   if(!list) return;
   elem *curr = *list;
   while(curr){
      printf("%d\n", curr->key);
      curr = curr->next;
   }
   
}

int main(){
   elem *head = NULL;//non scordare null
   int k, len, i;
   scanf("%d", &len);
   for(i=0; i<len; i++){
      scanf("%d", &k);
      push(k, &head);
   }
   //reverse(&head);
   revPrint(&head);
   clean(head);

   return 0;
}
