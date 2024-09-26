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
            return p; // N� encontrado.
        }
        else if(pf < p->dados.pf){
            return tSearch(p->left, pf); // Busca na sub�rvore esquerda.
        }
        else{
            return tSearch(p->right, pf); // Busca na sub�rvore direita.
        }
    }
}*/

void inOrder(treenodeptr p, int pm, int pM){
    
    if(p != NULL){
        
        if(p->dados.pf >= pm && p->dados.pf <= pM){
        inOrder(p->left, pm, pM); // Visita recursivamente a sub�rvore esquerda.
        cout << p->dados.i << ":" << (int)p->dados.pf << endl;
        inOrder(p->right, pm, pM); // Visita recursivamente a sub�rvore direita.
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
        return t; // Retorna o menor n�.
    }
    else{
        return tMenor(p->left);
    }
}

bool tRemove(treenodeptr &p, float pf)
{
    treenodeptr aux;

    if (p == NULL)
        return false; // Se o n� for NULL, n�o h� nada para remover, ent�o retorna falso.

    if (pf == p->dados.pf) // Se o nome do aluno for igual ao nome no n� atual.
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
        if (pf < p->dados.pf)
            return tRemove(p->left, pf); // Se o nome for menor, busca na sub�rvore esquerda.
        else
            return tRemove(p->right, pf); // Se o nome for maior, busca na sub�rvore direita.
    }
}*/

void tDestruir(treenodeptr &p){
    if(p != NULL){
        tDestruir(p->left); // Deleta recursivamente a sub�rvore esquerda.
        tDestruir(p->right); // Deleta recursivamente a sub�rvore direita.
        delete p; // Deleta o n� atual.
    }
    p = NULL; // Define o ponteiro da raiz como NULL.
}

int main(){
	
	int t, pfMin, pfMax;
	treenodeptr p = NULL;
	
	cin >> t; // N�mero de tortas.
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