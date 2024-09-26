#include <iostream>
using namespace std;

struct treenode {
    int info;
    struct treenode *left;
    struct treenode *right;
};

typedef treenode *treenodeptr;

void tInsert(treenodeptr &p, int x) {
    if (p == NULL) {
        p = new treenode;
        p->info = x;
        p->left = NULL;
        p->right = NULL;
    } else if (x < p->info) {
        tInsert(p->left, x);
    } else {
        tInsert(p->right, x);
    }
}

treenodeptr tSearch(treenodeptr p, int x) {
    if (p == NULL) {
        return NULL; // Manuscrito n�o encontrado.
    } else if (x == p->info) {
        return p; // Manuscrito encontrado.
    } else if (x < p->info) {
        return tSearch(p->left, x); // Procura na sub�rvore esquerda.
    } else {
        return tSearch(p->right, x); // Procura na sub�rvore direita.
    }
}

int main() {
    int op, valores;
    string operacao;
    treenode *arvore = new treenode;
    arvore = NULL;

    cin >> op;
    for (int i = 0; i < op; i++) {
        cin >> operacao >> valores;
        if (operacao == "i") {
            tInsert(arvore, valores); // Insere o n�mero do manuscrito na �rvore.
        } else if (operacao == "b") {
            if (tSearch(arvore, valores) != NULL) {
                cout << "Sim" << endl; // Manuscrito encontrado.
            } else {
                cout << "N�o" << endl; // Manuscrito n�o encontrado.
            }
        }
    }

    delete arvore;

    return 0;
}
