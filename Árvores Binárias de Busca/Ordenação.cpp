#include <iostream>
using namespace std;

struct treenode{
  int info;
  treenode *left;
  treenode *right;
};

typedef treenode *treenodeptr;

void tInsert(treenodeptr &p, int valores){
    if(p == NULL){
        p = new treenode;
        p->info = valores;
        p->left = NULL;
        p->right = NULL;
    } 
    else if(valores < p->info){
        tInsert(p->left, valores);
    }
    else{
        tInsert(p->right, valores);
    }
}

void inOrder(treenodeptr p){ //Ordem crescente ou decrescente.

    if(p != NULL){
        inOrder(p->right);
        cout << p->info << " ";
        inOrder(p->left);
    }
}


int main(){
  
  int valores, i = 0, n;
  treenodeptr arvore = NULL;
  
  while(cin >> valores && valores != -1){
      tInsert(arvore, valores);
      i++;
  }
  
  n = i;
  
  inOrder(arvore);
  
    return 0;
}