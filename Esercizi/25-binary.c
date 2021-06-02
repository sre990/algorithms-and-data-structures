#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 101
//ricerca binaria string, input array ordinato
//complessita O(log n)
int my_strcmp(char *a, char *b){
   
   while(*a!='\0'){
      if(*b=='\0') return 1;
      if(*a<*b) return -1;
      if(*a>*b) return 1;
      a++, b++;
   }
   if(*b!='\0')return -1;
   return 0;
}

//ausiliaria per stampare array
void print(char **a, int n){
   int i;
   for(i=0; i<n; i++){
      printf("%s \n", a[i]);
   }
}

int binsearch(char **arr, char *str, int l, int r) {
   int pos, cmp;
   pos = floor((l+r)/2);
   
   if (l > r) {
      return -1;
   }
   cmp = my_strcmp(str, arr[pos]);
   if (cmp == 0) return pos;
   if (cmp < 0) {
      return binsearch(arr, str, l, pos-1);
   } else {
      return binsearch(arr, str, pos+1, r);
   }

}

int main(){
   char **a;
   char *str;
   int i, n, res, t;
 
   scanf("%d", &n);
   a = malloc(n*sizeof(char*));
   for(i=0; i<n; i++){
      a[i] = malloc(MAX*sizeof(char));
      scanf("%s", *(a+i));
   }
   scanf("%d", &t);
   while(t==1){
      str = malloc(MAX*sizeof(char));
      scanf("%s", str);
      res = binsearch(a, str, 0, n-1);
      printf("%d\n", res);
      scanf("%d", &t);
   }

   return 0;
}
