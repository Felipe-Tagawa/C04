#include <iostream>
using namespace std;

struct treenode {
    int info;
    treenode *left;
    treenode *right;
};

typedef treenode *treenodeptr;

void tInsert(treenodeptr &p, int x) {
    if (p == NULL) { //Se a raiz for nula.
        p = new treenode;
        p->info = x;
        p->left = NULL;
        p->right = NULL;
    }
    else if (x < p->info) {
        tInsert(p->left, x);
    }
    else {
        tInsert(p->right, x);
    }
}

int inOrder(treenodeptr p, int &cont1, int buscado, int &pos) {
    if (p != NULL) {
        pos = inOrder(p->left, cont1, buscado, pos);
        if (cont1 == -1 && p->info == buscado) {
            cont1 = pos;
        }
        pos++;
        if (cont1 == -1) {
            pos = inOrder(p->right, cont1, buscado, pos);
        }
    }
    return pos;
}

int preOrder(treenodeptr p, int &cont2, int buscado, int &pos) {
    if (p != NULL) {
        if (cont2 == -1 && p->info == buscado) {
            cont2 = pos;
        }
        pos++;
        pos = preOrder(p->left, cont2, buscado, pos);
        if (cont2 == -1) {
            pos = preOrder(p->right, cont2, buscado, pos);
        }
    }
    return pos;
}

int posOrder(treenodeptr p, int &cont3, int buscado, int &pos) {
    if (p != NULL) {
        pos = posOrder(p->left, cont3, buscado, pos);
        if (cont3 == -1 && p->info == buscado) {
            cont3 = pos;
        }
        pos = posOrder(p->right, cont3, buscado, pos);
        if (cont3 == -1) {
            pos++;
        }
    }
    return pos;
}

int main() {

    int valores, buscado, cont1 = -1, cont2 = -1, cont3 = -1;
    int i = 0, n;
    treenodeptr arvore = NULL;

    while (cin >> valores && valores != -1) {
        tInsert(arvore, valores);
        i++;
    }

    cin >> buscado;

    n = i;

    int pos = 0;
    inOrder(arvore, cont1, buscado, pos);
    pos = 0;
    preOrder(arvore, cont2, buscado, pos);
    pos = 0;
    posOrder(arvore, cont3, buscado, pos);

    if (cont1 != -1 && cont1 < cont2 && cont1 < cont3) {
        cout << "Em" << endl;
    }
    else if (cont2 != -1 && cont2 < cont1 && cont2 < cont3) {
        cout << "Pre" << endl;
    }
    else if (cont3 != -1 && cont3 < cont1 && cont3 < cont2) {
        cout << "Pos" << endl;
    }

    return 0;
}
