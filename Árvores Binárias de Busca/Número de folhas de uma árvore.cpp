#include <iostream>
using namespace std;

struct treenode{
    int info;
    struct treenode *left;
    struct treenode *right;
};

typedef treenode *treenodeptr;

void tInsert(treenodeptr &p, int valores){
    if(p == NULL){ //Se a raiz for nula.
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

int countLeaves(treenodeptr arvore) {
    if (arvore == NULL) {
        return 0; // Se a árvore está vazia, então não há folhas.
    } else if (arvore->left == NULL && arvore->right == NULL) {
        return 1; // Se o nó não tem filhos, é uma folha.
    } else {
        // Recursivamente contar folhas nas subárvores esquerda e direita
        return countLeaves(arvore->left) + countLeaves(arvore->right);
    }
}

int main(){

    treenode *arvore = NULL;
    arvore = new treenode;
    arvore->left = NULL;
    arvore->right = NULL;

    int valores = 0;

    while(cin >> valores && valores != -1){
        if(valores != -1){
            tInsert(arvore, valores);
        }
    }

    int num_folhas = countLeaves(arvore);

    cout << num_folhas << endl;

    delete arvore;


    return 0;
}
