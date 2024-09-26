#include <iostream>
using namespace std;

struct treenode{
    int info;
    treenode *left;
    treenode *right;
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

int maior(treenodeptr arvore){
    while(arvore->right != NULL){
        arvore = arvore->right;
    }
    return arvore->info;
}

int menor(treenodeptr arvore){
    while(arvore->left != NULL){
        arvore = arvore->left;
    }
    return arvore->info;
}

int main(){
    
    int valores;
    treenodeptr arvore = NULL;
    
    while(cin >> valores && valores != -1){
        tInsert(arvore, valores);
    }
    
    cout << menor(arvore) << " e " << maior(arvore) << endl;
    
    
    
    return 0;
}