#include <iostream>
#include <list> // Para usar na busca em n�vel.
using namespace std;

// �rvore - Estrutura de dados n�o linear e din�mica, grafo ac�clico e DIRECIONADO


// �rvore bin�ria: apresenta uma raiz e duas sub�rvores(uma esquerda e outra direita) -- dois filhos iniciais.
// Ramos : N�s intermedi�rios.
// Folha : N�s sem filhos(�ltimos n�s).
// 
// Altura != N�vel::
// Altura -- altura de n�s vertical.
// N�vel = altura - 1 = profundidade(n�mero de arestas da raiz at� a folha mais longe).
// 
// Tipos de �rvore bin�ria:
// 
// 1) �rvore bin�ria incompleta(n�s ramos sem 2 filhos(apenas 1)).
// 2) �rvore bin�ria quase completa(todos os n�s, exceto o �ltimo, est�o totalmente preenchidos e todos os n�s do 
// �ltimo n�vel est�o o mais � esquerda poss�vel).
// 3) �rvore bin�ria completa(todos os n�s que n�o est�o no �ltimo n�vel t�m dois filhos).
// 4) �rvore estritamente bin�ria : todos os n�s tem 0 ou 2 filhos, nunca 1.
// **** IMPORTANTE: Complexidade da busca(O(h), onde h � a altura da �rvore, completa --> log n).
// Em uma �rvore de busca bin�ria balanceada, a altura h � O(log n), sendo n o n�mero de elementos da �rvore.
// No entanto, em uma �rvore n�o balanceada, a altura pode ser O(n), o que resultaria em uma complexidade de O(n).

struct aluno{
    string nome, curso;
    int matricula;
};

struct treenode{
    aluno dados;
    treenode *left;
    treenode *right;       
};

// -------------------------- CRIA��O DA AVL -------------------------- //

struct Node { // Cria��o da AVL.
    aluno dados;
    Node* left;
    Node* right;
    int height; // Altura do n� para AVL.
};

int height(Node* n) {
    return n ? n->height : 0; // Retorna a altura do n�, ou 0 se o n� for NULL.
}

int max(int a, int b) {
    return (a > b) ? a : b; // Retorna o maior valor entre a e b.
}

Node* newNode(aluno Aluno) {
    Node* node = new Node();
    node->dados = Aluno;
    node->left = node->right = NULL; // Inicializa os filhos como NULL.
    node->height = 1; // Novo n� � inicialmente adicionado como folha.
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
    return n ? height(n->left) - height(n->right) : 0; // Calcula o fator de balanceamento do n�.
}

// Inser��o em �rvore bin�ria comum
void tInsere(Node*& root, aluno Aluno) {
    if (root == NULL) {
        root = newNode(Aluno); // Se a raiz for NULL, cria um novo n�.
        return;
    }
    if (Aluno.matricula < root->dados.matricula) {
        tInsere(root->left, Aluno); // Insere na sub�rvore esquerda.
    } else {
        tInsere(root->right, Aluno); // Insere na sub�rvore direita.
    }
}

// Inser��o em �rvore AVL
Node* tInsereAVL(Node* node, aluno Aluno) {
    if (node == NULL)
        return newNode(Aluno); // Se o n� for NULL, cria um novo n�.

    if (Aluno.matricula < node->dados.matricula)
        node->left = tInsereAVL(node->left, Aluno); // Insere na sub�rvore esquerda.
    else if (Aluno.matricula > node->dados.matricula)
        node->right = tInsereAVL(node->right, Aluno); // Insere na sub�rvore direita.
    else
        return node; // N�o permite duplicatas.

    node->height = 1 + max(height(node->left), height(node->right)); // Atualiza a altura do n� pai.

    int balance = getBalance(node); // Obt�m o fator de balanceamento do n�.

    // Caso 1: Desbalanceado � esquerda
    if (balance > 1 && Aluno.matricula < node->left->dados.matricula)
        return rightRotate(node);

    // Caso 2: Desbalanceado � direita
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

    return node; // Retorna o n� (sem altera��es se balanceado).
}

int tPesq(Node* root, int matricula, int& count) {
    count++;
    if (root == NULL || root->dados.matricula == matricula)
        return root != NULL; // Retorna se o n� � encontrado.

    if (matricula < root->dados.matricula)
        return tPesq(root->left, matricula, count); // Busca na sub�rvore esquerda.
    else
        return tPesq(root->right, matricula, count); // Busca na sub�rvore direita.
}

typedef treenode *treenodeptr;

// -------------------------- INSER��O DE ELEMENTOS NA �RVORE -------------------------- //
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

// -------------------------- BUSCA DE ELEMENTOS NA �RVORE -------------------------- //

treenodeptr tSearch(treenodeptr p, string nome){
    if(p == NULL){
        return NULL;
    }
    else{
        if(nome == p->dados.nome){
            return p; // N� encontrado.
        }
        else if(nome < p->dados.nome){
            return tSearch(p->left, nome); // Busca na sub�rvore esquerda.
        }
        else{
            return tSearch(p->right, nome); // Busca na sub�rvore direita.
        }
    }
}

// -------------------------- REMO��O DE ELEMENTOS NA �RVORE -------------------------- //

// Essa fun��o vai sempre procurando na esquerda, at� chegar no leftest deles.
treenodeptr tMenor(treenodeptr &p){
    treenodeptr t;
    
    t = p;
    if(t->left == NULL){
        p = p->right;
        return t; // Retorna o menor n�.
    }
    else{
        return tMenor(p->left);
    }
}

bool tRemove(treenodeptr &p, string nome)
{
    treenodeptr aux;

    if (p == NULL)
        return false; // Se o n� for NULL, n�o h� nada para remover, ent�o retorna falso.

    if (nome == p->dados.nome) // Se o nome do aluno for igual ao nome no n� atual.
    {
        aux = p; // Armazena o n� atual em um n� auxiliar.

        if (p->left == NULL)
            p = p->right; // Se o filho esquerdo for NULL, move o filho direito para o lugar do n� atual.

        else
        {
            if (p->right == NULL)
                p = p->left; // Se o filho direito for NULL, move o filho esquerdo para o lugar do n� atual.

            else
            {
                aux = tMenor(p->right); // Encontra o menor n� da sub�rvore direita.
                p->dados = aux->dados; // Copia os dados do n� menor para o n� atual.
            }
        }

        delete aux; // Deleta o n� auxiliar.
        return true; // Retorna verdadeiro, indicando que a remo��o foi bem-sucedida.
    }

    else
    {
        if (nome < p->dados.nome)
            return tRemove(p->left, nome); // Se o nome for menor, busca na sub�rvore esquerda.
        else
            return tRemove(p->right, nome); // Se o nome for maior, busca na sub�rvore direita.
    }
}

// -------------------------- VARREDURAS NA �RVORE -------------------------- //

void preOrder(treenodeptr p){
    
    if(p != NULL){
        cout << p->dados.nome << endl; // Imprime o nome do aluno.
        cout << p->dados.matricula << endl; // Imprime a matr�cula do aluno.
        cout << p->dados.curso << endl; // Imprime o curso do aluno.
        preOrder(p->left); // Visita recursivamente a sub�rvore esquerda.
        preOrder(p->right); // Visita recursivamente a sub�rvore direita.
    }
}

void inOrder(treenodeptr p){
    
    if(p != NULL){
        inOrder(p->left); // Visita recursivamente a sub�rvore esquerda.
        cout << p->dados.nome << endl; // Imprime o nome do aluno.
        cout << p->dados.matricula << endl; // Imprime a matr�cula do aluno.
        cout << p->dados.curso << endl; // Imprime o curso do aluno.
        inOrder(p->right); // Visita recursivamente a sub�rvore direita.
    }
}

void posOrder(treenodeptr p){
    posOrder(p->left); // Visita recursivamente a sub�rvore esquerda.
    posOrder(p->right); // Visita recursivamente a sub�rvore direita.
    cout << p->dados.nome << endl; // Imprime o nome do aluno.
    cout << p->dados.matricula << endl; // Imprime a matr�cula do aluno.
    cout << p->dados.curso << endl; // Imprime o curso do aluno.
}

// -------------------------- VARREDURA EM N�VEL(LARGURA) -------------------------- //

void tLevels(treenodeptr p) { // Como a inser��o foi por matr�cula, ele vai mostrar por n�vel de matr�cula.
    treenodeptr n;
    list<treenodeptr> q;
    if (p != NULL) {
        q.push_back(p); // Adiciona o n� raiz � fila.
        while (!q.empty()) { // Enquanto a fila n�o estiver vazia.
            n = q.front(); // Obt�m o primeiro n� da fila.
            q.pop_front(); // Remove o primeiro n� da fila.
            cout << n->dados.nome << " "; // Imprime o nome do aluno.
            cout << n->dados.matricula << " "; // Imprime a matr�cula do aluno.
            cout << n->dados.curso << endl; // Imprime o curso do aluno.
            if (n->left != NULL) { // Se houver um filho � esquerda.
                q.push_back(n->left); // Adiciona o filho � fila.
            }
            if (n->right != NULL) { // Se houver um filho � direita.
                q.push_back(n->right); // Adiciona o filho � fila.
            }
        }
    }
}

// -------------------------- DELETAR A �RVORE -------------------------- //

void tDestruir(treenodeptr &p){
    if(p != NULL){
        tDestruir(p->left); // Deleta recursivamente a sub�rvore esquerda.
        tDestruir(p->right); // Deleta recursivamente a sub�rvore direita.
        delete p; // Deleta o n� atual.
    }
    p = NULL; // Define o ponteiro da raiz como NULL.
}

// -------------------------- MENOR VALOR DA �RVORE -------------------------- //

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

// -------------------------- MAIOR VALOR DA �RVORE -------------------------- //

treenodeptr tpointLarger(treenodeptr &p)
{
    treenodeptr t = p;
    if (t->right == NULL)
    { // Encontrar o maior valor da �rvore.
        p = p->left; // Ajusta o ponteiro para a sub�rvore esquerda, se existir.
        return t; // Retorna o n� que cont�m o maior valor.
    }
    else
    { // Continua a busca na sub�rvore direita at� encontrar o NULL.
        return tpointLarger(p->right);
    }
}


int main(){
    
    treenodeptr p = NULL; // Inicializa ponteiro para �rvore bin�ria normal.
    Node* arvore = NULL; // Inicializa ponteiro para �rvore bin�ria balanceada.
    Node* arvoreAVL = NULL; // Inicializa ponteiro para �rvore AVL.
    aluno Aluno;
    int matricula, x;
    
    // L� os dados dos alunos at� que a matr�cula seja 0
    while (cin >> Aluno.nome >> Aluno.matricula >> Aluno.curso && Aluno.matricula != 0) {
        tInsere(arvore, Aluno); // Insere na �rvore bin�ria comum.
        arvoreAVL = tInsereAVL(arvoreAVL, Aluno); // Insere na �rvore AVL.
    }
    
    cin >> x; // L� a matr�cula a ser pesquisada.
    
    int countNormal = 0; // Contador de passos para �rvore bin�ria comum.
    int countAVL = 0; // Contador de passos para �rvore AVL.
    
    tPesq(arvore, x, countNormal); // Pesquisa na �rvore bin�ria comum.
    tPesq(arvoreAVL, x, countAVL); // Pesquisa na �rvore AVL.
    
    cout << "Arvore normal: " << countNormal << endl;
    cout << "AVL: " << countAVL << endl;
    
    tDestruir(p); // Destr�i a �rvore bin�ria normal.
}
