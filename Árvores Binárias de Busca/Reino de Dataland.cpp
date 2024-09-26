#include <iostream>
using namespace std;

struct filme{
	string nome, genero;
	int duracao, idade, ano;
};

struct treenode {
    filme dados;
    struct treenode *left;
    struct treenode *right;
};

typedef treenode *treenodeptr;

void tInsert(treenodeptr &p, filme filmes) {
    if (p == NULL) { 
        p = new treenode;
        p->dados = filmes;
        p->left = NULL;
        p->right = NULL;
    } else if (filmes.nome < p->dados.nome) {
        tInsert(p->left, filmes);
    } else {
        tInsert(p->right, filmes);
    }
}

treenodeptr tSearch(treenodeptr p, string filme_buscado) {
    if (p == NULL) {
        return NULL;
    } else if (filme_buscado == p->dados.nome) { // Elemento encontrado.
        return p;
    } else if (filme_buscado < p->dados.nome) { // Procura na subárvore esquerda.
        return tSearch(p->left, filme_buscado);
    } else { // Procura na subárvore direita.
        return tSearch(p->right, filme_buscado);
    }
}

int main() {

    string nome_buscado;
    filme novo_filme;
    int menu = 1;
    treenode *arvore = NULL;
    arvore = new treenode;

    arvore->left = NULL;
    arvore->right = NULL;

    while (menu != 0) {

        cin >> menu;

        switch (menu) {

            case 0:
                break;

            case 1:
                getline(cin >> ws, novo_filme.nome);
                getline(cin >> ws, novo_filme.genero);
                cin >> novo_filme.duracao >> novo_filme.idade >> novo_filme.ano;
                tInsert(arvore, novo_filme);
                break;

            case 2:
                getline(cin >> ws, nome_buscado);
                {
                    treenodeptr encontrado = tSearch(arvore, nome_buscado);
                    if (encontrado != NULL) {
                        cout << "Nome: " << encontrado->dados.nome << endl;
                        cout << "Genero: " << encontrado->dados.genero << endl;
                        cout << "Duracao: " << encontrado->dados.duracao << " mins" << endl;
                        cout << "Classificacao: " << encontrado->dados.idade << endl;
                        cout << "Ano: " << encontrado->dados.ano << endl;
                    } else {
                        cout << "Filme nao encontrado" << endl;
                    }
                }
                break;
                
             default:
                 cout << "Operacao invalida" << endl;
        }
    }
    
    delete arvore;

    return 0;
}
