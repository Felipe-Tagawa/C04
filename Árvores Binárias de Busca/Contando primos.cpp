#include <iostream>
using namespace std;

struct treenode{
    int info;
    treenode *left;
    treenode *right;
};

typedef treenode *treenodeptr;

void tInsert(treenodeptr &p, int x){
    if(p == NULL){
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

bool ehPrimo(int valor) {
    
    int divisores = 0;
    for (int i = 1; i <= valor; i++) {
        if (valor % i == 0) {
            divisores++;
        }
    }
    if (divisores <= 2) {
        return true;
    }
    
    return false;
}


int contaPrimos(treenodeptr p) {
    if (p == NULL) return 0;
    
    int primos = 0;
    if (ehPrimo(p->info)) {
        primos++;
    }
    
    primos += contaPrimos(p->left);
    primos += contaPrimos(p->right);
    
    return primos;
}

int main(){
    int valores;
    treenodeptr arvore = NULL;
    
    while(cin >> valores && valores != -1){
        tInsert(arvore, valores);
    }
    
    cout << contaPrimos(arvore) << " numeros primos" << endl;
    
    return 0;
}
