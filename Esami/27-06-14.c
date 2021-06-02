#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXC 100
#define MAXO 15

typedef struct _elem{
   char *name;
   char *num;
   struct _elem *next;
}elem;

int cmp(const void *a, const void *b){
   elem a1 = *(elem *)a;
   elem b1 = *(elem *)b;
   return strcmp(a1.name, b1.name);
}

int hash(const char *name, const int n){
   unsigned int sum = 0;
   unsigned int x;
   unsigned char c;
   for(int i=0; name[i]!='\0'; i++){
      c = (unsigned char)name[i];
      x = (unsigned int)c;
      sum += x;
   }
   
   return (sum % (2*n));
}

elem *create(const char *name, const char *num){
   elem *new = malloc(sizeof(elem));
   if(new){
      new->name = malloc(sizeof(char)*MAXC);
      new->num = malloc(sizeof(char)*MAXC);
      strcpy(new->name, name);
      strcpy(new->num, num);
      new->next = NULL;
   }
   return new;
}

void insert(elem **T, const char *nm, const char *val){
   if(!*T){
      *T = create(nm, val);
      return;
   }
   elem *new = create(nm, val);
   elem *prev, *curr;
   curr = *T;
   prev = NULL;
   while(curr && cmp(new, curr)>0){
      prev = curr;
      curr = curr->next;
   }
   if(!prev){
      new->next = curr;
      *T = new;
   }else{
      prev->next = new;
      new->next = curr;
   }
}

void clean(elem *e){
   if(e){
      clean(e->next);
      free(e->name);
      free(e->num);
      free(e);
   }
}

int main(){
   elem **T = NULL;
   size_t i, n;
   int h, k;
   char *name;
   char *num;
   scanf("%lu", &n);
   if(n==0) return 0;
   T = calloc(n*2,(sizeof(elem *)));
   name = calloc(MAXC, sizeof(char));
   num = calloc(MAXC, sizeof(char));
   for(i=0; i<n; i++){     
      scanf(" %s", name);
      scanf(" %s", num);
      h = hash(name, n);
      insert(&T[h], name, num);
      //test
      //printf("%s (%s) at pos %d\n", 
      //      name, num, h);
   }
   scanf(" %d", &k);
   elem *curr = T[k];
   while(curr){
      printf("%s %s\n", curr->name, curr->num);
      curr = curr->next;
   }
   
   for(i=0; i<n*2; i++){
      clean(T[i]);
   }
   free(name);
   free(num);
   free(T);
   

   return 0;
}
