#include <iostream>
#include <list>
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

void tLevels(treenodeptr p){
    treenodeptr n;
    list<treenodeptr> q;
    if(p != NULL){
        q.push_back(p);
        while(!q.empty()){
            n = q.front();
            q.pop_front();
            if(n->left != NULL){
                q.push_back(n->left);
            }
            if(n->right != NULL){
                q.push_back(n->right);
            }
            cout << n->info << " ";
        }
    }
}

int main(){
    
    int valores;
    treenodeptr arvore = NULL;
    
    while(cin >> valores && valores != -1){
        tInsert(arvore, valores);
    }
    
    tLevels(arvore);
    
    delete arvore;
    
    return 0;

}


