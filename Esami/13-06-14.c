#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXC 100
typedef struct _elem{
   char *code;
   int cfu;
   int diff;
   struct _elem *next;
}elem;
//ordine lessicografico dei codici d'esame
int cmp_str(const void *a, const void *b){
   elem a1 = *(elem *)a;
   elem b1 = *(elem *)b;
   return strcmp(a1.code, b1.code);
}
//a parita' di crediti diamo priorita' a quelli con
//difficolta' minore. altrimenti si scelgono quelli con piu'
//crediti
int cmp(const void *a, const void *b){
   elem *a1 = (elem *)a;
   elem *b1 = (elem *)b;
   if(a1->cfu > b1->cfu) return 1;
   if(a1->cfu < b1->cfu) return -1;
   else{
      if(a1->diff < b1->diff) return 1;
      if(a1->diff > b1->diff) return -1;
      else{
         //ordine lessicografico
         return -strcmp(a1->code, b1->code);
      }
   }
}

elem *create(const char *code, const int cfu, const int diff){
   elem *new = malloc(sizeof(elem));
   if(new){
      new->code = malloc(sizeof(char)*MAXC);
      strcpy(new->code, code);
      new->cfu = cfu;
      new->diff = diff;
      new->next = NULL;
   }
   return new;
}

void insert(elem **list, const char *code, 
            const int cfu, const int diff){
   if(!*list){
      *list = create(code, cfu, diff);
      return;
   }
   elem *new = create(code, cfu, diff);
   elem *prev,  *curr;
   curr = *list;
   prev = NULL;
   while(curr && cmp(curr, new) > 0){
      prev = curr;
      curr = curr->next;
   }
   if(!prev){
      new->next = curr;
      *list = new;
   }else{
      prev->next = new;
      new->next = curr;
   }
}
//array da ordinare con qsort
elem *build_arr(const elem *root, size_t *n, const int k){
   size_t i;
   int max_sum, sum;
   elem *arr = NULL;
   arr = calloc(*n, sizeof(elem));
   i = 0;
   sum = 0;
   max_sum = 0;
   while(root){
      sum += root->cfu;
      //se superiamo il numero massimo di cfu andiamo avanti
      if(sum > k){
         sum = max_sum;
         root = root->next;
      }else{
      //altrimenti riempiamo l'array
         arr[i].code = malloc(MAXC*sizeof(char));
         strcpy(arr[i].code, root->code);
         arr[i].cfu = root->cfu;
         arr[i].diff = root->diff;
         arr[i].next = NULL;
         i++;
         max_sum = sum;
         root = root->next;
      }
   }
   *n = i;

   return arr;
}
void clean(elem *e){
   if(e){
      clean(e->next);
      free(e->code);
      free(e);
   }
}
int main(){
   elem *root = NULL;
   size_t i, n;
   int k, cfu, diff;
   char *code;
   elem *arr = NULL;
   //k numero massimo crediti
   scanf("%d", &k);
   if(k<=0) return 1;
   //numero esami sostenibili
   scanf("%lu", &n);
   if(n<=0) return 1;
   code = calloc(MAXC, sizeof(char));
   for(i=0; i<n; i++){     
      scanf(" %s", code);
      scanf(" %d", &cfu);
      scanf(" %d", &diff);
      insert(&root, code, cfu, diff);

   }
   arr = build_arr(root, &n, k);
   qsort(arr, n, sizeof(elem), cmp_str);
   /*
   while(root->next){
      //test
      printf("%s (cfu:%d, diff:%d)\n", 
            root->code, root->cfu, root->diff);
      root = root->next;
   }*/
   for(i=0; i<n; i++){
      printf("%s\n", arr[i].code);
   }
   for(i=0; i<n; i++){
      free(arr[i].code);
   }
   clean(root);
   free(code);
   free(arr);
   
   return 0;
}
