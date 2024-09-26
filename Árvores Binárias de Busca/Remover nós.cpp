#include <iostream>
using namespace std;

struct treenode
{
    int info;
    struct treenode *left;
    struct treenode *right;
};

typedef treenode *treenodeptr;

void tInsert(treenodeptr &p, int x)
{
    if (p == NULL)
    { // Se a raiz for nula.
        p = new treenode;
        p->info = x;
        p->left = NULL;
        p->right = NULL;
    }
    else if (x < p->info)
    {
        tInsert(p->left, x);
    }
    else
    {
        tInsert(p->right, x);
    }
}

treenodeptr tSearch(treenodeptr p, int x)
{ // Não precisa ser por referência, pois não vai alterar como na inserção, apenas buscar.
    if (p == NULL)
    {
        return NULL;
    }
    else if (x == p->info) // Elemento encontrado.
        return p;

    else if (x < p->info) // Procura na subárvore esquerda.
        return tSearch(p->left, x);
    else // Procura na subárvore direita.
        return tSearch(p->right, x);
}

// Remoção: Mesmo após tirar um elemento, ainda tem que respeitar o conceito de arvores binárias.
// Se o nó for folha, podemos simplesmente apagá-lo, porque nada depende dele.
// Se o nó tiver um filho à esquerda OU à direita, remove-se o nó e aponta a referência para o nó atual para seu filho.
// Se o nó tiver DOIS filhos, encontra-se o nó M com menor valor da subárvore da direita, aponta a direita do pai de M para a direita
// de M, modifica o valor do nó atual para o valor de M e remove-se M.

treenodeptr tpointSmaller(treenodeptr &p)
{
    treenodeptr t = p;
    if (t->left == NULL)
    { // Encontrar o menor valor da árvore.
        p = p->right;
        return t;
    }
    else
    { // Continua a busca na subárvore esquerda até encontrar o NULL.
        return tpointSmaller(p->left);
    }
}

bool tRemove(treenodeptr &p, int x)
{
    treenodeptr t;

    if (p == NULL)
    {
        return false;
    }
    if (x == p->info)
    {
        t = p; // t vai apontar para o nó que queremos remover.
        if (p->left == NULL)
        { // folha.
            p = p->right;
        }
        else if (p->right == NULL)
        { // Um filho a esquerda ou a direita.
            p = p->left;
        }
        else
        { // Caso em que tem dois filhos.
            t = tpointSmaller(p->right);
            p->info = t->info; // Trocar o valor do nó com o menor valor da subárvore da direita.
        }
        delete t; // Não pode deletar o p, pois perde a referência para futuras remoções.
        return true;
    }
    else if (x < p->info)
    {
        return tRemove(p->left, x); // Procura e remove na subárvore esquerda.
    }
    else
    {
        return tRemove(p->right, x); // Procura e remove na subárvore direita.
    }
}

void emOrdem(treenodeptr arvore){
    if(arvore != NULL){
        emOrdem(arvore->left);
        cout << arvore->info << " ";
        emOrdem(arvore->right);
    }
}

int main()
{

    treenodeptr raiz = NULL;

    int valores = 0, x;

    while (cin >> valores && valores != 0)
    {
        if (valores != 0)
        {
            tInsert(raiz, valores);
        }
    }
    
    cin >> x;
    
    while(tRemove(raiz,x)){
         tRemove(raiz, x);  
    }
    
    
    emOrdem(raiz);
    
    

    return 0;
}