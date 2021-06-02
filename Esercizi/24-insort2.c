#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
//insertion sort su stringhe
//in-place, tempo dipende da dimesione input
//piu' efficiente per input quasi-ordinati
//complessita O(n^2)
int my_strcmp(char *a, char *b){

   while(*a!='\0'){
      if(*b=='\0')return 1;
      if(*a<*b) return -1;
      if(*a>*b) return 1;
      a++, b++;
   }
   if(*b!='\0') return -1;
   return 0;
}
char **sort(char **a, int n){
   int i, j; 
   char *x;
   
   for(i=0; i<n; i++){
      j = i-1;
      x = a[i];
     // maggiore di invece per stringhe      
      while(j>=0 && strcmp(a[j], x)>0){
         a[j+1] = a[j];
         j--;
      }
      a[j+1] = x;
   }

   return a;
}

int main(){
   int i, n;
   char **a;
   scanf("%d", &n);
   a = malloc(sizeof(char*)*n);
   for(i=0; i<n; i++){
      *(a+i) = malloc(sizeof(char)*MAX);
      //100 max lunghezza stringhe
      scanf("%s", *(a+i));

   }
   a = sort(a, n);
   for(i=0; i<n; i++) printf("%s\n", a[i]);
   return 0;
}
