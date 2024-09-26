#include <iostream>
#include <list> // Para usar na busca em nível.
using namespace std;

// Árvore - Estrutura de dados não linear e dinâmica, grafo acíclico e DIRECIONADO


// Árvore binária: apresenta uma raiz e duas subárvores(uma esquerda e outra direita) -- dois filhos iniciais.
// Ramos : Nós intermediários.
// Folha : Nós sem filhos(últimos nós).
// 
// Altura != Nível::
// Altura -- altura de nós vertical.
// Nível = altura - 1 = profundidade(número de arestas da raiz até a folha mais longe).
// 
// Tipos de árvore binária:
// 
// 1) Árvore binária incompleta(nós ramos sem 2 filhos(apenas 1)).
// 2) Árvore binária quase completa(todos os nós, exceto o último, estão totalmente preenchidos e todos os nós do 
// último nível estão o mais à esquerda possível).
// 3) Árvore binária completa(todos os nós que não estão no último nível têm dois filhos).
// 4) Árvore estritamente binária : todos os nós tem 0 ou 2 filhos, nunca 1.
// **** IMPORTANTE: Complexidade da busca(O(h), onde h é a altura da árvore, completa --> log n).
// Em uma árvore de busca binária balanceada, a altura h é O(log n), sendo n o número de elementos da árvore.
// No entanto, em uma árvore não balanceada, a altura pode ser O(n), o que resultaria em uma complexidade de O(n).

struct aluno{
    string nome, curso;
    int matricula;
};

struct treenode{
    aluno dados;
    treenode *left;
    treenode *right;       
};

// -------------------------- CRIAÇÃO DA AVL -------------------------- //

struct Node { // Criação da AVL.
    aluno dados;
    Node* left;
    Node* right;
    int height; // Altura do nó para AVL.
};

int height(Node* n) {
    return n ? n->height : 0; // Retorna a altura do nó, ou 0 se o nó for NULL.
}

int max(int a, int b) {
    return (a > b) ? a : b; // Retorna o maior valor entre a e b.
}

Node* newNode(aluno Aluno) {
    Node* node = new Node();
    node->dados = Aluno;
    node->left = node->right = NULL; // Inicializa os filhos como NULL.
    node->height = 1; // Novo nó é inicialmente adicionado como folha.
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left; // y's left child
    Node* T2 = x->right; // x's right child

    x->right = y; // Perform rotation
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1; // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // Return new root
}

Node* leftRotate(Node* x) {
    Node* y = x->right; // x's right child
    Node* T2 = y->left; // y's left child

    y->left = x; // Perform rotation
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1; // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // Return new root
}

int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0; // Calcula o fator de balanceamento do nó.
}

// Inserção em árvore binária comum
void tInsere(Node*& root, aluno Aluno) {
    if (root == NULL) {
        root = newNode(Aluno); // Se a raiz for NULL, cria um novo nó.
        return;
    }
    if (Aluno.matricula < root->dados.matricula) {
        tInsere(root->left, Aluno); // Insere na subárvore esquerda.
    } else {
        tInsere(root->right, Aluno); // Insere na subárvore direita.
    }
}

// Inserção em árvore AVL
Node* tInsereAVL(Node* node, aluno Aluno) {
    if (node == NULL)
        return newNode(Aluno); // Se o nó for NULL, cria um novo nó.

    if (Aluno.matricula < node->dados.matricula)
        node->left = tInsereAVL(node->left, Aluno); // Insere na subárvore esquerda.
    else if (Aluno.matricula > node->dados.matricula)
        node->right = tInsereAVL(node->right, Aluno); // Insere na subárvore direita.
    else
        return node; // Não permite duplicatas.

    node->height = 1 + max(height(node->left), height(node->right)); // Atualiza a altura do nó pai.

    int balance = getBalance(node); // Obtém o fator de balanceamento do nó.

    // Caso 1: Desbalanceado à esquerda
    if (balance > 1 && Aluno.matricula < node->left->dados.matricula)
        return rightRotate(node);

    // Caso 2: Desbalanceado à direita
    if (balance < -1 && Aluno.matricula > node->right->dados.matricula)
        return leftRotate(node);

    // Caso 3: Esquerda-Direita
    if (balance > 1 && Aluno.matricula > node->left->dados.matricula) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso 4: Direita-Esquerda
    if (balance < -1 && Aluno.matricula < node->right->dados.matricula) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // Retorna o nó (sem alterações se balanceado).
}

int tPesq(Node* root, int matricula, int& count) {
    count++;
    if (root == NULL || root->dados.matricula == matricula)
        return root != NULL; // Retorna se o nó é encontrado.

    if (matricula < root->dados.matricula)
        return tPesq(root->left, matricula, count); // Busca na subárvore esquerda.
    else
        return tPesq(root->right, matricula, count); // Busca na subárvore direita.
}

typedef treenode *treenodeptr;

// -------------------------- INSERÇÃO DE ELEMENTOS NA ÁRVORE -------------------------- //
void tInsert(treenodeptr &p, aluno Aluno){
    if(p == NULL){
        p = new treenode;
        p->dados = Aluno;
        p->left = NULL;
        p->right = NULL;
    }
    else{ // Inserir na esquerda ou direita.
        if(Aluno.matricula < p->dados.matricula){
            tInsert(p->left, Aluno);
        }
        else{
            tInsert(p->right, Aluno);
        }
    }
}

// -------------------------- BUSCA DE ELEMENTOS NA ÁRVORE -------------------------- //

treenodeptr tSearch(treenodeptr p, string nome){
    if(p == NULL){
        return NULL;
    }
    else{
        if(nome == p->dados.nome){
            return p; // Nó encontrado.
        }
        else if(nome < p->dados.nome){
            return tSearch(p->left, nome); // Busca na subárvore esquerda.
        }
        else{
            return tSearch(p->right, nome); // Busca na subárvore direita.
        }
    }
}

// -------------------------- REMOÇÃO DE ELEMENTOS NA ÁRVORE -------------------------- //

// Essa função vai sempre procurando na esquerda, até chegar no leftest deles.
treenodeptr tMenor(treenodeptr &p){
    treenodeptr t;
    
    t = p;
    if(t->left == NULL){
        p = p->right;
        return t; // Retorna o menor nó.
    }
    else{
        return tMenor(p->left);
    }
}

bool tRemove(treenodeptr &p, string nome)
{
    treenodeptr aux;

    if (p == NULL)
        return false; // Se o nó for NULL, não há nada para remover, então retorna falso.

    if (nome == p->dados.nome) // Se o nome do aluno for igual ao nome no nó atual.
    {
        aux = p; // Armazena o nó atual em um nó auxiliar.

        if (p->left == NULL)
            p = p->right; // Se o filho esquerdo for NULL, move o filho direito para o lugar do nó atual.

        else
        {
            if (p->right == NULL)
                p = p->left; // Se o filho direito for NULL, move o filho esquerdo para o lugar do nó atual.

            else
            {
                aux = tMenor(p->right); // Encontra o menor nó da subárvore direita.
                p->dados = aux->dados; // Copia os dados do nó menor para o nó atual.
            }
        }

        delete aux; // Deleta o nó auxiliar.
        return true; // Retorna verdadeiro, indicando que a remoção foi bem-sucedida.
    }

    else
    {
        if (nome < p->dados.nome)
            return tRemove(p->left, nome); // Se o nome for menor, busca na subárvore esquerda.
        else
            return tRemove(p->right, nome); // Se o nome for maior, busca na subárvore direita.
    }
}

// -------------------------- VARREDURAS NA ÁRVORE -------------------------- //

void preOrder(treenodeptr p){
    
    if(p != NULL){
        cout << p->dados.nome << endl; // Imprime o nome do aluno.
        cout << p->dados.matricula << endl; // Imprime a matrícula do aluno.
        cout << p->dados.curso << endl; // Imprime o curso do aluno.
        preOrder(p->left); // Visita recursivamente a subárvore esquerda.
        preOrder(p->right); // Visita recursivamente a subárvore direita.
    }
}

void inOrder(treenodeptr p){
    
    if(p != NULL){
        inOrder(p->left); // Visita recursivamente a subárvore esquerda.
        cout << p->dados.nome << endl; // Imprime o nome do aluno.
        cout << p->dados.matricula << endl; // Imprime a matrícula do aluno.
        cout << p->dados.curso << endl; // Imprime o curso do aluno.
        inOrder(p->right); // Visita recursivamente a subárvore direita.
    }
}

void posOrder(treenodeptr p){
    posOrder(p->left); // Visita recursivamente a subárvore esquerda.
    posOrder(p->right); // Visita recursivamente a subárvore direita.
    cout << p->dados.nome << endl; // Imprime o nome do aluno.
    cout << p->dados.matricula << endl; // Imprime a matrícula do aluno.
    cout << p->dados.curso << endl; // Imprime o curso do aluno.
}

// -------------------------- VARREDURA EM NÍVEL(LARGURA) -------------------------- //

void tLevels(treenodeptr p) { // Como a inserção foi por matrícula, ele vai mostrar por nível de matrícula.
    treenodeptr n;
    list<treenodeptr> q;
    if (p != NULL) {
        q.push_back(p); // Adiciona o nó raiz à fila.
        while (!q.empty()) { // Enquanto a fila não estiver vazia.
            n = q.front(); // Obtém o primeiro nó da fila.
            q.pop_front(); // Remove o primeiro nó da fila.
            cout << n->dados.nome << " "; // Imprime o nome do aluno.
            cout << n->dados.matricula << " "; // Imprime a matrícula do aluno.
            cout << n->dados.curso << endl; // Imprime o curso do aluno.
            if (n->left != NULL) { // Se houver um filho à esquerda.
                q.push_back(n->left); // Adiciona o filho à fila.
            }
            if (n->right != NULL) { // Se houver um filho à direita.
                q.push_back(n->right); // Adiciona o filho à fila.
            }
        }
    }
}

// -------------------------- DELETAR A ÁRVORE -------------------------- //

void tDestruir(treenodeptr &p){
    if(p != NULL){
        tDestruir(p->left); // Deleta recursivamente a subárvore esquerda.
        tDestruir(p->right); // Deleta recursivamente a subárvore direita.
        delete p; // Deleta o nó atual.
    }
    p = NULL; // Define o ponteiro da raiz como NULL.
}

// -------------------------- MENOR VALOR DA ÁRVORE -------------------------- //

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

// -------------------------- MAIOR VALOR DA ÁRVORE -------------------------- //

treenodeptr tpointLarger(treenodeptr &p)
{
    treenodeptr t = p;
    if (t->right == NULL)
    { // Encontrar o maior valor da árvore.
        p = p->left; // Ajusta o ponteiro para a subárvore esquerda, se existir.
        return t; // Retorna o nó que contém o maior valor.
    }
    else
    { // Continua a busca na subárvore direita até encontrar o NULL.
        return tpointLarger(p->right);
    }
}


int main(){
    
    treenodeptr p = NULL; // Inicializa ponteiro para árvore binária normal.
    Node* arvore = NULL; // Inicializa ponteiro para árvore binária balanceada.
    Node* arvoreAVL = NULL; // Inicializa ponteiro para árvore AVL.
    aluno Aluno;
    int matricula, x;
    
    // Lê os dados dos alunos até que a matrícula seja 0
    while (cin >> Aluno.nome >> Aluno.matricula >> Aluno.curso && Aluno.matricula != 0) {
        tInsere(arvore, Aluno); // Insere na árvore binária comum.
        arvoreAVL = tInsereAVL(arvoreAVL, Aluno); // Insere na árvore AVL.
    }
    
    cin >> x; // Lê a matrícula a ser pesquisada.
    
    int countNormal = 0; // Contador de passos para árvore binária comum.
    int countAVL = 0; // Contador de passos para árvore AVL.
    
    tPesq(arvore, x, countNormal); // Pesquisa na árvore binária comum.
    tPesq(arvoreAVL, x, countAVL); // Pesquisa na árvore AVL.
    
    cout << "Arvore normal: " << countNormal << endl;
    cout << "AVL: " << countAVL << endl;
    
    tDestruir(p); // Destrói a árvore binária normal.
}
