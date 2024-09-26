#include <iostream>

using namespace std;

struct torta{
	float espessura, peso, altura, diametro, pf;
	int i;
};

struct treenode{
    torta dados;
    treenode *left;
    treenode *right;       
};

typedef treenode *treenodeptr;

void tInsert(treenodeptr &p, torta Torta){
    if(p == NULL){
        p = new treenode;
        p->dados = Torta;
        p->left = NULL;
        p->right = NULL;
    }
    else{ // Inserir na esquerda ou direita.
        if(Torta.pf < p->dados.pf){
            tInsert(p->left, Torta);
        }
        else{
            tInsert(p->right, Torta);
        }
	}
}

void inOrder(treenodeptr p){
    
    if(p != NULL){
        inOrder(p->left); // Visita recursivamente a subárvore esquerda.
        cout << p->dados.i << ":" << (int)p->dados.pf << endl;
        inOrder(p->right); // Visita recursivamente a subárvore direita.
    }
}

void tDestruir(treenodeptr &p){
    if(p != NULL){
        tDestruir(p->left); // Deleta recursivamente a subárvore esquerda.
        tDestruir(p->right); // Deleta recursivamente a subárvore direita.
        delete p; // Deleta o nó atual.
    }
    p = NULL; // Define o ponteiro da raiz como NULL.
}

int main(){
	
	int t;
	treenodeptr p = NULL;
	torta tortas;
	
	cin >> t; // Número de tortas.
	
	for(int i = 0; i < t; i++){
		cin >> tortas.espessura >> tortas.peso >> tortas.altura >> tortas.diametro;
		tortas.pf = (tortas.espessura * tortas.peso * tortas.altura) + tortas.diametro + tortas.altura;
		tortas.i = i;
		tInsert(p, tortas);
	}
	
    inOrder(p);
	
	
	tDestruir(p);
	
	
	return 0;
}