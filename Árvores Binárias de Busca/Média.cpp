#include <iostream>
#include <iomanip>
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

void somaTotal(treenodeptr arvore, float &soma, int &n) {
    if (arvore != NULL) {
        somaTotal(arvore->left, soma, n);
        soma += arvore->info;
        n++;
        somaTotal(arvore->right, soma, n);
    }
}

float media(treenodeptr arvore) {
    float soma = 0;
    int n = 0;
    somaTotal(arvore, soma, n);
    
    if (n != 0)
        return soma / n;
    else
        return 0;
}

int main(){
    treenodeptr arvore = NULL;
    int x = 0;

    while(cin >> x && x != -1){
        tInsert(arvore, x);
    }

    float result = media(arvore);
    
    cout << fixed << setprecision(2) << "Media: " << result << endl;
    
    return 0;
}
