#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//uguale a strcat ma con malloc
char *my_strcat(char *x, char *y){
   int i, j;
   int lenx = strlen(x);
   int leny = strlen(y);
   char *cat = malloc(sizeof(char)*(lenx+leny+1));
   if(cat == NULL) exit(1);
   for(i=0; i<lenx; i++) cat[i] = x[i];
   for(j=0; j<leny; j++) cat[i+j] = y[j];
   cat[i+j] = '\0';

   return cat;
}

int main(){
   int lenx, leny;
   char *cat, *x, *y;
   scanf("%d", &lenx);
   x = malloc(sizeof(char)*lenx);
   scanf("%s", x);
   
   scanf("%d", &leny);
   y = malloc(sizeof(char)*leny);
   scanf("%s", y);
   cat = my_strcat(x, y);
   printf("%s\n", cat);

   return 0;
}
