// Estruturas de dados n�o lineares(sem ordena��o poss�vel), compostas por v�rtices interconectados por arestas.
// Lista de adjac�ncia(consome menos espa�o) ou matriz de adjac�ncia(consome muito espa�o).
// Um grado G � um par (V, E).
// Grafo direcionado ou n�o direcionado, quando direcionado, ele s� tem uma dire��o a ser seguida.
// Grafo conexo ou desconexo, quando h� conex�o ou quando n�o h� dentro de um grafo, n�s desconectados.
// Grafo c�clico(pode retornar a um que j� foi acessado) e ac�clico que n�o h� fechamento de ciclo.
// Grafo simples (s� existe um tipo de conex�o de um n� com outro) ou multigrafo(mais de um tipo de conex�o entre dois n�s, ex.: pessoas e comunidade).
// Grafo completo(Partindo de um n�, ele tem liga��o com todos os outros n�s) ou incompleto(maioria).
// Grafo Bipartido(n�s de diferentes tipos, nunca de pessoa pra pessoa ou filme pra filme).
// Grafo Planar(sem cruzamento de arestas), euleriano(apenas 2 n�s pode ter n�mero de arestas �mpares, o restante com n�meros pares).
// Grafo hamiltoniano(partindo de um n�, varre todos os outros v�rtices, passando apenas uma vez por cada um).

#include <iostream>
using namespace std;

struct v{ // Referente aos v�rtices.
	int vertice;
	v *proximo;
	list<int> *adj;
};

int main(){
	
	
	return 0;
}