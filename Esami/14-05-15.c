#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100
//simulazione laboratorio (Maggio 2015). Gestione coda
//ospedale. 
typedef struct _paziente{
   char *nome;
   struct _paziente *next;
}paziente;

int cmp(const void *a, const void *b){
   paziente *p1 = *(paziente **)a;
   paziente *p2 = *(paziente **)b;
   return strcmp(p1->nome, p2->nome);
}

paziente *create(const char *n){
   paziente *p = malloc(sizeof(paziente));
   if(p){
      p->nome = malloc(sizeof(char)*MAXLEN);
      strcpy(p->nome, n);
      p->next = NULL;
   }
   return p;
}

void append(paziente **q, const char *n){
   if(!*q){
      *q = create(n);
      return;
   }
   paziente *curr = *q;
   while(curr->next) curr = curr->next;
   curr->next = create(n); 
}

void delete(paziente **q){
   if(!*q) return;
   paziente *tmp = *q;
   paziente *curr = (*q)->next;
   free(tmp->nome);
   free(tmp);
   *q = curr;
}
//print linked list
void print(paziente **q){
   if(*q){
      paziente *curr = *q;
      printf("%s\n", curr->nome);
      print(&curr->next);
   }else{
      printf("$\n");
   }
}
//print array
void print_array(paziente **q, const size_t n){
   for(size_t i=0; i<n; i++){
      printf("%s\n", q[i]->nome);
   }
   printf("$\n");
}

void clean(paziente *p){
   paziente *tmp = p;
   if(!p) return;
   while(tmp){
      tmp = p->next;
      free(p->nome);
      free(p);
      p = tmp;
   }
}

int main(){
   paziente *coda = NULL;
   int e;
   size_t t;
   char *nome = malloc(sizeof(char)*MAXLEN);
   t=0;//dimensione coda
   scanf("%d", &e);
   while(e!=0){
      if(e==1){
         scanf("%s", nome);
         append(&coda, nome);
         t++;
      }else if(e==2){
         delete(&coda);
         t--;
      }
      scanf("%d", &e);
   }
   free(nome);
   //printf("%d\n", t);//test
   paziente *curr = coda; 
   //for(t=0; curr; curr=curr->next, t++);//test
   paziente **q = malloc(t*sizeof(paziente *));
   curr = coda;
   for(t=0; curr; curr=curr->next, t++){
      q[t] = create(curr->nome);
      //printf("%s\n", q[t]->nome);//test
   }
   //ordino la coda dei pazienti in ordine alfabetico
   qsort(q, t, sizeof(paziente *), cmp);
   print_array(q, t);
   for(int i=0; i<t; i++){
      free(q[i]->nome);
      free(q[i]);
   }
   clean(coda);
   free(q);

   return 0;
}
