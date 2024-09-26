#include <iostream>
using namespace std;

struct treenode{
  int info;
  struct treenode *left;
  struct treenode *right;
    
};

typedef treenode *treenodeptr;

void tInsert(treenodeptr &p, int x){
    if(p == NULL){ //Se a raiz for nula.
    p = new treenode;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    } 
    else if(x < p->info){
        tInsert(p->left, x);
    }
    else{
        tInsert(p->right, x);
    }
}

int tSearch(treenodeptr p, int x){
    if(p == NULL){
        return 0;
    }
    else
        if(x == p->info) // Elemento encontrado.
            return p->info;
        
    else
        if(x < p-> info) // Procura na subárvore esquerda.
            return tSearch(p->left, x);
    else                 // Procura na subárvore direita.
        return tSearch(p->right, x);   
}

int main(){
    
    int x = 0, buscado;
    treenode *raiz = NULL;
    raiz = new treenode;
    
    raiz->left = NULL;
    raiz->right = NULL;
    
    int n;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> x;
    }
    
    cin >> buscado;
    
    for(int i = 0; i < n; i++){
        if(tSearch(raiz, x) == 0){
            tInsert(raiz, x);
        }
    }
    
    if(tSearch(raiz, x) == buscado){
        cout << "Encontrado" << endl;
    }
    else{
        cout << "Nao encontrado" << endl;
    }
    
    delete raiz;
    
    return 0;
}