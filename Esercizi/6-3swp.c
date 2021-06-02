#include <stdio.h>
#include <math.h>

void tswap(int *x, int *y, int *z){
   int tmp; 

   tmp = *x;
   *x = *z;
   *z = *y;
   *y = tmp;

}

int main(){
   int x, y, z;
   scanf("%d %d %d", &x, &y, &z);
   //printf("x=%d, y=%d, z=%d\n", x, y, z);
   tswap(&x, &y, &z);
   //printf("x=%d, y=%d, z=%d\n", x, y, z);
   printf("%d\n%d\n%d\n", x, y, z);

   return 0;
}
