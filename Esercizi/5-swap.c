#include <stdio.h>
#include <math.h>
void swap(int *a, int *b){
   int tmp;
   tmp = *a;
   *a = *b;
   *b = tmp;

}

int main(){
   int a, b;
   scanf("%d %d", &a, &b); 
   swap(&a, &b);
   //printf("a= %d, b= %d\n", a, b);
   printf("%d\n%d\n", a, b);
   printf("\n");
   return 0;
}
