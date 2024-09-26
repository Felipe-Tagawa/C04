#include <iostream>
using namespace std;

struct rocha
{
	string nome, tipo;
};

struct treenode
{
	rocha dados;
	treenode *left;
	treenode *right;
};

typedef treenode *treenodeptr;

void tInsert(treenodeptr &p, rocha r) {
    if (p == NULL) { 
        p = new treenode;
        p->dados = r;
        p->left = NULL;
        p->right = NULL;
    } else if (r.nome < p->dados.nome) {
        tInsert(p->left, r);
    } else {
        tInsert(p->right, r);
    }
}

treenodeptr tSearch(treenodeptr p, string filme_buscado)
{
	if (p == NULL)
	{
		return NULL;
	}
	else if (filme_buscado == p->dados.nome)     // Elemento encontrado.
	{
		return p;
	}
	else if (filme_buscado < p->dados.nome)     // Procura na subárvore esquerda.
	{
		return tSearch(p->left, filme_buscado);
	}
	else     // Procura na subárvore direita.
	{
		return tSearch(p->right, filme_buscado);
	}
}

treenodeptr tpointSmaller(treenodeptr &p)
{
	treenodeptr t = p;
	if (t->left == NULL)
	{
		// Encontrar o menor valor da árvore.
		p = p->right;
		return t;
	}
	else
	{
		// Continua a busca na subárvore esquerda até encontrar o NULL.
		return tpointSmaller(p->left);
	}
}

bool tRemove(treenodeptr &p, rocha r)
{
	treenodeptr t;

	if (p == NULL)
	{
		return false;
	}
	if (r.nome == p->dados.nome && r.tipo == p->dados.tipo)
	{
		t = p; // t vai apontar para o nó que queremos remover.
		if (p->left == NULL)
		{
			// folha.
			p = p->right;
		}
		else if (p->right == NULL)
		{
			// Um filho a esquerda ou a direita.
			p = p->left;
		}
		else
		{
			// Caso em que tem dois filhos.
			t = tpointSmaller(p->right);
			p->dados.nome = t->dados.nome; // Trocar o valor do nó com o menor valor da subárvore da direita.
			p->dados.tipo = t->dados.tipo;
		}
		delete t; // Não pode deletar o p, pois perde a referência para futuras remoções.
		return true;
	}
	else if (r.nome < p->dados.nome)
	{
		return tRemove(p->left, r); // Procura e remove na subárvore esquerda.
	}
	else
	{
		return tRemove(p->right, r); // Procura e remove na subárvore direita.
	}
}

int main()
{

	int menu = 1;
	rocha nova_rocha;
	treenodeptr arvore = NULL;

	while(menu != 0)
	{

		cin >> menu;
		switch (menu)
		{
		case 0:
			break;
		case 1:
			getline(cin >> ws, nova_rocha.nome);
			getline(cin >> ws, nova_rocha.tipo);
			tInsert(arvore, nova_rocha);
			break;
		case 2:
			// Pesquisa passa apenas o nome.
			getline(cin >> ws, nova_rocha.nome);
			if(tSearch(arvore, nova_rocha.nome) != NULL)
			{
				cout << "Nome: " << tSearch(arvore, nova_rocha.nome)->dados.nome << endl;
                cout << "Tipo: " << tSearch(arvore, nova_rocha.nome)->dados.tipo << endl;
			}
			else{
				cout << "Rocha nao encontrada" << endl;
			}
			break;
		case 3:
			getline(cin >> ws, nova_rocha.nome);
			getline(cin >> ws, nova_rocha.tipo);	
			if(tRemove(arvore, nova_rocha)){
				cout << "Rocha removida com sucesso" << endl;
			}
			else{
				cout << "Rocha nao encontrada para remocao" << endl;
			}
			break;
		
		default:
			menu = 0;
		}
	}

	return 0;
}
