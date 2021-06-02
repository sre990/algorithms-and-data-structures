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
   if(!new) return NULL;
   new->next = NULL;
   new->key = key;

   return new;
}

//inserisce in testa alla lista(push)
void push(int key, elem **list){
   if(!list){
      *list = create(key);
      return;
   }
   elem *new = create(key);
   new->next = *list;
   *list = new;
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

//trova la posizione della chiave, -1 se assente
//(non necessario)
int find(int key, elem *head){
   int i = 0;
   while(head){
      if(head->key==key) return i;
      i++;
      head = head->next;
   }
   return -1;
}

//trova lunghezza lista
//(non necessario)
int length(elem *head){
   if(!head) return 0;
   return 1+length(head->next);
}

void clean(elem *list){
   elem *tmp = list;
   if(!list) return;
   while(tmp){
      tmp = list->next;
      free(list);
      list = tmp;
   }
}

void printRev(elem **list){
   if(!(*list)) return;
   elem *curr = *list;
   printf("%d\n", curr->key);
   printRev(&curr->next);
}

//next puntatore al prossimo elemento; head all'inizio e'
//la testa ma poi le viene assegnato il puntatore al prossimo
//elemento in lista finche' non incontra NULL; ptr fa il con-
//trario di head e viene restituito al chiamante
elem *reverse(elem *head){
   elem *prev = NULL;
   elem *next;      
   while(head){
      next = head->next;
      head->next = prev;
      prev = head;      
      head = next;
   }
   return prev;
}

//metodo ricorsivo
void recRev(elem **head){
   elem *first, *rest;
   if(!*head) return;//controlliamo che non sia vuota
   first = *head; //first punta al primo elemento
   rest = first->next; //rest alla coda
   if(!rest) return; //controlliamo che non abbia solo un elem
   recRev(&rest);//parte ricorsiva sulla coda
   first->next->next = first;//linkiamo la coda alla testa
   first->next = NULL;//la testa non punta a niente
   *head = rest; //il primo elemento puntato della lista e'
                 // la coda.
}

int main(){
   elem *head = NULL;
   int n, len, i;
   scanf("%d", &len);
   for(i=0;i<len; i++){
      scanf("%d", &n);
      push(n, &head);
   }
   //head = reverse(head);
   //recRev(&head);
   printRev(&head);
   clean(head);

   return 0;
}
