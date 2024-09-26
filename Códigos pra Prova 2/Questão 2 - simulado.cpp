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

/*treenodeptr tSearch(treenodeptr p, float pf){
    if(p == NULL){
        return NULL;
    }
    else{
        if(pf == p->dados.pf){
            return p; // Nó encontrado.
        }
        else if(pf < p->dados.pf){
            return tSearch(p->left, pf); // Busca na subárvore esquerda.
        }
        else{
            return tSearch(p->right, pf); // Busca na subárvore direita.
        }
    }
}*/

void inOrder(treenodeptr p, int pm, int pM){
    
    if(p != NULL){
        
        if(p->dados.pf >= pm && p->dados.pf <= pM){
        inOrder(p->left, pm, pM); // Visita recursivamente a subárvore esquerda.
        cout << p->dados.i << ":" << (int)p->dados.pf << endl;
        inOrder(p->right, pm, pM); // Visita recursivamente a subárvore direita.
        }
    }
}

/*void show_ordered(Node * curr){
	if(curr->left != NULL)
		show_ordered(curr->left);
	cout << curr->data.key << ":" << curr->data.value << endl;
	if(curr->right != NULL)
		show_ordered(curr->right);
}

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

bool tRemove(treenodeptr &p, float pf)
{
    treenodeptr aux;

    if (p == NULL)
        return false; // Se o nó for NULL, não há nada para remover, então retorna falso.

    if (pf == p->dados.pf) // Se o nome do aluno for igual ao nome no nó atual.
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
        if (pf < p->dados.pf)
            return tRemove(p->left, pf); // Se o nome for menor, busca na subárvore esquerda.
        else
            return tRemove(p->right, pf); // Se o nome for maior, busca na subárvore direita.
    }
}*/

void tDestruir(treenodeptr &p){
    if(p != NULL){
        tDestruir(p->left); // Deleta recursivamente a subárvore esquerda.
        tDestruir(p->right); // Deleta recursivamente a subárvore direita.
        delete p; // Deleta o nó atual.
    }
    p = NULL; // Define o ponteiro da raiz como NULL.
}

int main(){
	
	int t, pfMin, pfMax;
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
		tInsert(p, tortas[i]);
	}
	
	cin >> pfMin >> pfMax;
	
    inOrder(p, pfMin, pfMax);
	
	
	tDestruir(p);
	
	
	return 0;
}