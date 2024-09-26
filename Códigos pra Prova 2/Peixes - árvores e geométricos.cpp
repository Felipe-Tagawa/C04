#include <iostream>
#include <queue>
#include <list>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct
{
	int x;
	int y;
} Ponto;

struct peixe
{
	int i; // Indíces dos peixes.
	Ponto A;
	Ponto B;
	Ponto C;
	float comprimento;
};
struct treenode
{
	peixe dados;
	treenode *left;
	treenode *right;
};

typedef treenode *treenodeptr;

void tInsert(treenodeptr &p, peixe Peixe)
{
	if(p == NULL)
	{
		p = new treenode;
		p->dados = Peixe;
		p->left = NULL;
		p->right = NULL;
	}
	else  // Inserir na esquerda ou direita.
	{
		if(Peixe.comprimento < p->dados.comprimento)
		{
			tInsert(p->left, Peixe);
		}
		else
		{
			tInsert(p->right, Peixe);
		}
	}
}

double distancia(Ponto p1, Ponto p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
				(p1.y - p2.y) * (p1.y - p2.y));
}


void tDestruir(treenodeptr &p)
{
	if(p != NULL)
	{
		tDestruir(p->left); // Deleta recursivamente a subárvore esquerda.
		tDestruir(p->right); // Deleta recursivamente a subárvore direita.
		delete p; // Deleta o nó atual.
	}
	p = NULL; // Define o ponteiro da raiz como NULL.
}

void inOrder_contrario(treenodeptr p){
    
    if(p != NULL){
        inOrder_contrario(p->right); // Visita recursivamente a subárvore esquerda.
        cout << p->dados.i << ":" << p->dados.comprimento << endl;
        inOrder_contrario(p->left); // Visita recursivamente a subárvore direita.
    }
}

int main()
{

	int n;
	treenodeptr p = NULL;

	cin >> n; // Número de peixes.
	peixe peixes;

	for(int i = 0; i < n; i++)
	{
		cin >> peixes.A.x >> peixes.A.y >> peixes.B.x >> peixes.B.y >> peixes.C.x >> peixes.C.y;
		peixes.i = i;
		peixes.comprimento = max(distancia(peixes.A, peixes.B),distancia(peixes.A, peixes.C));
		tInsert(p, peixes);
	}
	
	inOrder_contrario(p);

	tDestruir(p);


	return 0;
}
