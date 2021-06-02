#include <stdio.h>

int main(){
   int x;
   int *p, *q, **w;
   x = 25;
   p = &x;
   q = p;
   *q = 11;
// q = 11; dà dare errore perché q ha tipo int * e non int	
   w = &p;
   *w = q;

   printf("w = %p;\nw* = %p;\nw** = %d;\nq = %p;\n*q = %d;\np = %p;\n*p =%d;\nx = %d\n", 
      w, *w, **w, q, *q, p, *p, x);


}
