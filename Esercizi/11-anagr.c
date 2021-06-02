#include <stdio.h>
#include <stdlib.h>
#define MAX 256 // 0-255 range di unsigne char

// Programma che legga da input s1 e s2 e utilizza la fn anagramma per stabilire se
// una e' l'anagramma dell'altra.
// hint: data una stringa S, costruire un array aS[256] t.c. aS[i] memorizzi il numero
// di occorrenze del carattere i in S. Come sono gli array aS e aZ di due stringhe Se Z che sono anagrammi?
int length(char *s){
   int i;
   for(i=0; *s!='\0'; s++) i++;
   return i;
}

int anagramma(unsigned char *s1, unsigned char *s2){
   int aS [MAX];
   int aZ [MAX];
   int i, l1, l2;
   l1 = length(s1);
   l2 = length(s2);
   
   //se hanno lunghezze diverse non serve continuare
   if(l1 != l2) return 0;
   //inizializziamo array a 0
   for(i=0; i<MAX; i++) aS[i] = aZ[i] = 0;
   for(i=0; i<l1; i++){
      //IMPORTANTE: vettori di puntatori
      aS[*(s1+i)]++;
      aZ[*(s2+i)]++;
   }
   
   for(i=0; i<MAX; i++){
      if(aS[i] != aZ[i]) return 0;
   }

   return 1;
   
}

int main (){
   unsigned char *s, *z;
   int i, l1, l2, res;

   s = malloc(MAX*sizeof(unsigned char));
   z = malloc(MAX*sizeof(unsigned char));
   scanf("%s %s", s, z);
   l1 = length(s);
   l2 = length(z);
   //realloc per riallocare quantita' giusta di memoria
   s = realloc(s, l1);
   z = realloc(z, l2);
   res = anagramma(s, z);
   printf("%d\n", res);

   return 0;
}
