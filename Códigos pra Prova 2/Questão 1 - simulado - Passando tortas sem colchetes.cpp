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

void tInsert(treenodeptr &p, torta Torta[], int i){
    if(p == NULL){
        p = new treenode;
        p->dados = Torta[i];
        p->left = NULL;
        p->right = NULL;
    }
    else{ // Inserir na esquerda ou direita.
        if(Torta[i].pf < p->dados.pf){
            tInsert(p->left, Torta, i);
        }
        else{
            tInsert(p->right, Torta, i);
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
	
	cin >> t; // Número de tortas.
	torta tortas[t];
	int pos[t];
	
	for(int i = 0; i < t; i++){
		cin >> tortas[i].espessura >> tortas[i].peso >> tortas[i].altura >> tortas[i].diametro;
		tortas[i].pf = (tortas[i].espessura * tortas[i].peso * tortas[i].altura) + tortas[i].diametro + tortas[i].altura;
		tortas[i].i = i;
	}
	
	
	for(int i = 0; i < t; i++){
		tInsert(p, tortas, i);
	}
	
    inOrder(p);
	
	
	tDestruir(p);
	
	
	return 0;
}