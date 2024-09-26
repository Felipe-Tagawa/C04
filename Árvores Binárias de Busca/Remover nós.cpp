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
{ // N�o precisa ser por refer�ncia, pois n�o vai alterar como na inser��o, apenas buscar.
    if (p == NULL)
    {
        return NULL;
    }
    else if (x == p->info) // Elemento encontrado.
        return p;

    else if (x < p->info) // Procura na sub�rvore esquerda.
        return tSearch(p->left, x);
    else // Procura na sub�rvore direita.
        return tSearch(p->right, x);
}

// Remo��o: Mesmo ap�s tirar um elemento, ainda tem que respeitar o conceito de arvores bin�rias.
// Se o n� for folha, podemos simplesmente apag�-lo, porque nada depende dele.
// Se o n� tiver um filho � esquerda OU � direita, remove-se o n� e aponta a refer�ncia para o n� atual para seu filho.
// Se o n� tiver DOIS filhos, encontra-se o n� M com menor valor da sub�rvore da direita, aponta a direita do pai de M para a direita
// de M, modifica o valor do n� atual para o valor de M e remove-se M.

treenodeptr tpointSmaller(treenodeptr &p)
{
    treenodeptr t = p;
    if (t->left == NULL)
    { // Encontrar o menor valor da �rvore.
        p = p->right;
        return t;
    }
    else
    { // Continua a busca na sub�rvore esquerda at� encontrar o NULL.
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
        t = p; // t vai apontar para o n� que queremos remover.
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
            p->info = t->info; // Trocar o valor do n� com o menor valor da sub�rvore da direita.
        }
        delete t; // N�o pode deletar o p, pois perde a refer�ncia para futuras remo��es.
        return true;
    }
    else if (x < p->info)
    {
        return tRemove(p->left, x); // Procura e remove na sub�rvore esquerda.
    }
    else
    {
        return tRemove(p->right, x); // Procura e remove na sub�rvore direita.
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