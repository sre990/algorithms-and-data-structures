#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
#define p 999149
//usiamo una lista monodirezionale
typedef struct _item{
   struct _item *next;
   int val;
}item;

int hash(int a, int b, int x, int n){
   return ((a*x + b) % p) % (n*2);
}

item *create(int v){
   item *head = malloc(sizeof(item));
   if(head){
      head->next = NULL;
      head->val = v;
   }
   return head;
}

void append(int v, item **list){
   if(!*list){
      *list = create(v);
      return;
   }
   item *curr = *list;
   while(curr->next){
      curr = curr->next;
   }

   curr->next = create(v);
}

int length(item *head){
   if(!head) return 0;
   else return 1+length(head->next);
}

void print(int n, item **T){
   int i, h;
   item *curr;
   for(i = 0; i<n; i++){
      curr = T[i];
      printf("%d->", i);
      while(curr){
         printf(" %d", curr->val);
         curr = curr->next;
      }
      printf("\n");

   }
}

void confl(int n, item **T){
   int max,conf, i;
   max = conf = 0;
   for(i=0; i<n; i++){
      item *curr = T[i];
      if(curr){
         if(length(curr)>1) conf += (length(curr)-1);
         if(length(curr)>max) max = length(curr);
      }
   }

   printf("%d\n%d\n", max, conf);
}

int main(){
   item **T = NULL;
   int n, i, x, h, a, b;
   scanf("%d", &n);
   scanf("%d%d", &a, &b);
   //creiamo una tabella hash di liste
   //monodirezionali di dimensione 2n.
   T = malloc(n*2*sizeof(item*));
   for(i=0;i<n;i++){
      scanf("%d", &x);
      h = hash(a, b, x, n);
      append(x, &T[h]);
   }
   //print(n*2, T);
   confl(n*2, T);

   return 0;
}
