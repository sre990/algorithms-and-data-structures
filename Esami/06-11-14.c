#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXC 100
#define MAXO 15

typedef struct _obj{
   char *nm;
   int val;
   struct _obj *next;
}Obj;
//ordine per valore affettivo; a parita' di valore affettivo, ordine
//lessicografico
int cmp(const void *a, const void *b){
   Obj a1 = *(Obj *)a;
   Obj b1 = *(Obj *)b;
  
   if(a1.val - b1.val == 0){
      return strcmp(a1.nm,b1.nm);
   }else if(a1.val - b1.val < 0){
      return 1;
   }else return -1;
}
int hash(const char *nm, const size_t n){
   unsigned int sum = 0;
   unsigned int x;
   unsigned char c;
   for(int i=0; nm[i]!='\0'; i++){
      c = (unsigned char)nm[i];
      x = (unsigned int)c;
      sum += x;
   }
   
   return (sum % (2*n));
}
Obj *create(const char *nm, const int val){
   Obj *o = malloc(sizeof(Obj));
   if(o){
      o->nm = malloc(sizeof(char)*MAXC);
      strcpy(o->nm, nm);
      o->val = val;
      o->next = NULL;
   }
   return o;
}
//inserimento in tabella
void insert(Obj **T, const char *nm, const int val){
   if(!*T){
      *T = create(nm, val);
      return;
   }
   Obj *curr = *T;
   if(strcmp(curr->nm, nm)==0 && curr->val>=val) return;
   else if(strcmp(curr->nm, nm)==0){
      curr->val = val;
      return;
   }else{
      while(curr&&strcmp(curr->nm, nm)!=0){
         curr = curr->next;
      }
      if(!curr){
      //inserimento in cima alla lista di trabocco
         Obj *new = create(nm, val);
         new->next = *T;
         *T = new;
      }else{
         insert(&curr, nm, val);
      }
   }

}
//array di oggetti su cui chiamare qsort
Obj *build_arr(Obj **T, size_t *n){
   size_t i, j;
   Obj *curr;
   Obj *arr = NULL;
   arr = calloc(*n, sizeof(Obj));
   j = 0;
   for(i=0; i<*n; i++){
      //se non e' presente alcuna lista passo avanti
      if(!T[i]){
         continue;
      }
      curr = T[i];
      while(curr){
         arr[j].val = curr->val;
         arr[j].nm = malloc(sizeof(char)*MAXC);
         strcpy(arr[j].nm, curr->nm);
         arr[j].next = NULL;
         j++;//aggiorno lunghezza stringa
         curr = curr->next;
      }
   }
   *n = j;//aggiorno lunghezza stringa

   return arr;
}
void clean(Obj *o){
   if(o){
      clean(o->next);
      free(o->nm);
      free(o);
   }
}
int main(){
   Obj **T = NULL;
   size_t i, n, size;
   int val, h;
   Obj *arr = NULL;
   char *nm;
   scanf("%lu", &n);
   if(n==0) return 0;
   nm = malloc(MAXC*sizeof(char));
   T = calloc(n*2,(sizeof(Obj *)));
   for(i=0; i<n; i++){
      scanf("%s %d", nm, &val);
      h = hash(nm, n);
      insert(&T[h], nm, val);
   }
   size = n*2;
   arr = build_arr(T, &size); 
   //ordino gli elementi (senza duplicati) per valore affettivo
   qsort(arr, size, sizeof(Obj), cmp);
   //e ne stampo 15.
   for(i=0; i<MAXO; i++){
      //printf("%d: %s(%d)\n", i, arr[i].nm, arr[i].val);
      printf("%s\n", arr[i].nm);
   }
   for(i=0; i<n*2; i++){
      free(arr[i].nm);
      clean(T[i]);
   }
   free(nm);
   free(arr);
   free(T);

   return 0;
}
