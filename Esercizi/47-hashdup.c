#include <stdio.h>
#include <stdlib.h>
#define p 999149
typedef struct _item{
   int val;
   struct _item *next;
}item;

item *create(int v){
   item *new = malloc(sizeof(item));
   if(new){
      new->next = NULL;
      new->val = v;
   }
   return new;
}

void append(int v, item **list){
   if(!*list){
      *list = create(v);
      return;
   }
   item *curr = *list;
   if(curr->val==v) return;
   while(curr->next){
      curr = curr->next;
   }
   curr->next = create(v);
}

int length(item *head){
   if(!head) return 0;
   else return 1+length(head->next);
}

void dist(int n, item **T){
   int i, count;
   count = 0;
   for(i=0; i<n; i++) count+=length(T[i]);
   printf("%d\n", count);
}

int hash(int a, int b, int x, int n){
   return ((a*x + b) % p) % (n*2);
}

void confl(int n, item **T){
   int max, confl, i;
   max = confl = 0;
   for(i=0; i<n; i++){
      if(length(T[i])>max) max = length(T[i]);
      if(length(T[i])>1) confl += length(T[i]->next);
   }
   printf("%d\n", confl);
   printf("%d\n", max);
  
}

void print(int n, item **T){
   int i;
   item *curr;
   for(i=0; i<n; i++){
      curr = T[i];
      printf("%d->", i);
      while(curr){
         printf(" %d", curr->val);
         curr = curr->next;
      }
      printf("\n");
   }

}

int main(){
   item **T = NULL;
   int i, n, x, a, b, h;
   scanf("%d%d%d", &n, &a, &b);
   T = malloc(n*2*sizeof(item *));
   for(i=0; i<n; i++){
      scanf("%d", &x);
      h = hash(a, b, x, n);
      append(x, &T[h]);
   }
   //print(n*2, T);
   confl(n*2, T);
   dist(n*2, T);

   return 0;
}
