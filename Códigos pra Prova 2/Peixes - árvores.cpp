#include <iostream>
#include <queue>
#include <list>

using namespace std;

struct peixe{
	float viscosidade, espessura, diametro, t; // t = int(V*E*N*E*N*O) // Sendo V a viscosidade, E a espessura e N é 7 e O o diâmetro.
	int i; // Indíces dos peixes.
};

struct treenode{
    peixe dados;
    treenode *left;
    treenode *right;       
};

typedef treenode *treenodeptr;

void tInsert(treenodeptr &p, peixe Peixe){
    if(p == NULL){
        p = new treenode;
        p->dados = Peixe;
        p->left = NULL;
        p->right = NULL;
    }
    else{ // Inserir na esquerda ou direita.
        if(Peixe.t < p->dados.t){
            tInsert(p->left, Peixe);
        }
        else{
            tInsert(p->right, Peixe);
        }
	}
}

void show_levels(treenodeptr p, int Tmin, int Tmax){
	
	if(p == NULL){
		return;
	}
	
	queue<treenodeptr> nodes;
	
	nodes.push(p);
	
	while(! nodes.empty()){
		
		treenodeptr aux = nodes.front();
		
		if(aux->dados.t <= Tmax && aux->dados.t >= Tmin){
		cout << aux->dados.i << ":" << (int)aux->dados.t << endl;
		}
		
		if(aux->left != NULL)
			nodes.push(aux->left);
		
		if(aux->right != NULL)
			nodes.push(aux->right);

		nodes.pop();
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
	
	int n;
	treenodeptr p = NULL;
	peixe peixes;
	
	cin >> n; // Número de peixes.
	
	for(int i = 0; i < n; i++){
		cin >> peixes.viscosidade >> peixes.espessura >> peixes.diametro;
		peixes.t = (int)(peixes.viscosidade * peixes.espessura * 7 * peixes.espessura * 7 * peixes.diametro);
		peixes.i = i;
		tInsert(p, peixes);
	}
	
	int Tmin, Tmax;
	
	cin >> Tmin >> Tmax;
	
    show_levels(p, Tmin, Tmax);
	
	
	tDestruir(p);
	
	
	return 0;
}