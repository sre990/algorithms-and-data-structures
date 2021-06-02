#include <stdio.h>
#include <stdlib.h>
typedef struct _elem{
   int key;
   int counter;
   struct _elem *prev;
   struct _elem *next;
}elem;

elem *create(int k){
   elem *new = malloc(sizeof(elem));
   if(new){
      new->key = k;
      new->next = NULL;
      new->prev = NULL;
   }
   return new;
}

void append(int k, elem **list){
   if(!*list){
      *list = create(k);
      return;
   }
   elem *listPtr = *list;
   elem *node = create(k);
   while(listPtr->next){
      listPtr = listPtr->next;
   }
   listPtr->next = node;
   node->prev = listPtr;
}

//pensare a lista con soli tre elementi: curr,
//prev e next
void insertAfter(elem **list, elem *e, elem *new){
   new->prev = e;
   //non e' l'ultimo
   if(!e->next){
      new->next = NULL;//non scordare
      //trovo ultimo elemento
      elem *last = *list;
      while(last->next) last = last->next;
      last = new;
   }else{
      new->next = e->next;
      e->next->prev = new;
   }
   e->next = new;
}
//vedi sopra
void insertBefore(elem **list, elem *e, elem *new){
   new->next = e;
   //il primo elemento
   if(!e->prev){
      new->prev = NULL;//non scordare
      *list = new;
   }else{
      new->prev = e->prev;
      e->prev->next = new;
   }
   e->prev = new;
}

void insertStart(elem **list, elem *new){
   if(!(*list)) *list = create(new->key);
   else insertBefore(list, *list, new);
}
//vedi sopra
elem *delete(elem **list, elem *e){
   // e e' il primo elemento
   if(!e->prev) *list = e->next;
   else e->prev->next = e->next;
   //se non e' all'ultimo posto
   if(!e->next){
      //trovo l'ultimo elemento
      elem *last = *list;
      while(last->next) last = last->next;
      last = e->prev;
   }else e->next->prev = e->prev;

   return e;
}

void init(elem **list){
   elem *listPtr = *list;
   while(listPtr){
      listPtr->counter = 0;
      listPtr = listPtr->next;
   }
}

int find(int k, elem *head){
   int i;
   for(i=0; head; i++){
      if(head->key==k){
         return i;
      }
      head = head->next;
   }
   return -1;
}

//test
void print(elem *list){
   while(list){
      printf("%d(%d) ", list->key, list->counter);
      list = list->next;
   }
}

//scambia contenuto due nodi(non necessario)
void swap(elem **x, elem **y){
   int k = (*x)->key;
   int c = (*x)->counter;
   (*x)->key = (*y)->key;
   (*x)->counter = (*y)->counter;
   (*y)->key = k;
   (*y)->counter = c;
}

//Dopo ogni ricerca si deve garantire che gli elementi
//della lista siano ordinati in ordine non-crescente di 
//contatore.  Se il contatore di un elemento viene incre-
//mentato e risulta uguale a quello dell’elemento
//precedente, i due elementi vanno lasciati dove sono.
void freq(int k, elem **list){
   int i = 0;
   elem *curr = *list;
   if(!curr) return;//caso lista vuota
   if(curr->key==k){//caso primo elemento
      curr->counter++;
      return;
   }
   //continuo a cercare
   while(curr->next && curr->next->key!=k){
      curr = curr->next;
   }
   
   if(!curr->next) return;//not found
   curr->next->counter++;//trovato a curr->next
   
   //se il contatore incrementato e' uguale a quello
   //adiacente non faccio nulla
   if(curr->counter==curr->next->counter) return;
   //salvo elemento trovato in una var
   //e lo stacco
   elem *found = delete(list, curr->next);
   
   //cerco posizione in cui aggiungere 
   while(curr&&(curr->counter<found->counter)){
      curr = curr->prev;
   }
   //se ho finito la lista aggiungo al primo elemento
   if(!curr){
      insertStart(list, found);
      return;
   }
   //altrimenti aggiungo prima di curr>=found
   insertAfter(list, curr, found);

}

int main(){
   int n, len, i;
   elem *head = NULL; // non scordare null

   //leggo una lista di interi ordinati e li inserisco
   //in una lista bidirezionale
   scanf("%d", &len);
   for(i=0;i<len;i++){
      scanf("%d", &n);
      append(n, &head);
   }
   //inizializzo contatori a 0
   init(&head);
   //Il programma entra poi in un ciclo nel quale legge un 
   //intero da tastiera e lo cerca nella lista. Se si trova
   //nella lista, stampa la sua posizione (contando da 0), 
   //altrimenti stampa -1
   scanf("%d", &n);
   i = find(n, head);
   while(i!=-1){
      freq(n, &head);//ordino per frequenza
      //print(head);//test
      //printf("\tidx:%d\n", i);
      printf("%d\n",i);
      scanf("%d", &n);
      i = find(n, head);
   } 
   //print(head);
   //printf("\tidx:%d\n", i);//fine -1
   printf("%d\n", i);
   
   return 0;
}
