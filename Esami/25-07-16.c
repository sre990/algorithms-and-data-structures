#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
//--- MORRIS TRAVERSAL ---//
typedef struct _node{
   int val;
   struct _node *left;
   struct _node *right;
}Node;

Node *create(int val){
   Node *root = malloc(sizeof(Node));
   root->val = val;
   root->left = NULL; root->right = NULL;
   return root;   
}

int count(Node* root){
   if(root == NULL) return 0;
	return 1 + count(root->right) + count(root->left);
}

//inorder (morris) per riempire array ordinato
//algoritmo morris: inizializzo curr = root.
//while curr non e' NULL controlla se curr ha figlio sx.
//1.se curr non ce l'ha aggiungo curr in array e curr punta l suo
//figlio dx.
//altrimenti ha figlio sx, curr e' il figlio destro del predecessore.
//adesso abbiamo due casi: 
//1.1: il figio dx e' NULL. gli assegnamo curr e ci spostistiamo sul
//     figlio sx di curr.
//1.2: il figlio dx del predecessore punta gia' al nodo corrente. 
//     Aggiungiuamo in array e ci postiamo al figlio destro di curr.
//2.curr e' il figlio sx.
int *get_arr(Node* root, int n){
   if(!root) return NULL;
   int *arr = calloc(n,sizeof(int));
   int i = 0; 
   Node *curr, *pre;
   curr = root;
   while(curr){
      if(!curr->left){
         arr[i++] = curr->val;
         //printf("%d\n", arr[i]);
         curr = curr->right;
      }else{
         //trova il predecessore di curr
         pre = curr->left;
         while(pre->right && pre->right!=curr){
            pre = pre->right;
         }
         //curr e' il figlio destro del suo predecessore
         if(!pre->right){
            pre->right = curr;
            curr = curr->left;
         }else{
            //risistema figlio destro del predecessore
            pre->right = NULL;
            arr[i++] = curr->val;
            //printf("%d\n", arr[i]);
            curr = curr->right;
         }
      }
   }
   return arr;
}

int find_med(Node* root){
	int l = count(root);
   int res = 0;
   int *arr = get_arr(root, l);
	if(l%2==0){
		res = (arr[(l+1)/2]);
      free(arr);
      return res;
   }
   res = arr[l/2];
   free(arr);
	return res;
}

void insert(Node **T, int val){
   if(!(*T)){ 
      *T = create(val);
      return;
   }
   Node *curr, *parent;
   curr = *T;
   while(curr){
      parent = curr;
      if(curr->val > val){
         curr = curr->left;
      }else curr = curr->right;
   }
   if(parent->val > val){
      parent->left = create(val);
   }else parent->right = create(val);
}

void print(Node *root){
   if(root){
      printf("%d\n", root->val);
      print(root->left);
      print(root->right);
   }
}

void clean(Node *root){
   if(root){
      clean(root->left);
      clean(root->right);
      free(root);
   }
}

int main(){
   int n;
   int val;

   scanf("%d", &n); 
   Node *T = NULL;
   for(int i=0; i<n; i++){
      scanf("%d", &val);
      insert(&T, val);
   }
   //print(T);//test
   printf("%d\n", find_med(T));
   clean(T);
     
   return 0;
}
