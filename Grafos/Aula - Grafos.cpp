// Estruturas de dados não lineares(sem ordenação possível), compostas por vértices interconectados por arestas.
// Lista de adjacência(consome menos espaço) ou matriz de adjacência(consome muito espaço).
// Um grado G é um par (V, E).
// Grafo direcionado ou não direcionado, quando direcionado, ele só tem uma direção a ser seguida.
// Grafo conexo ou desconexo, quando há conexão ou quando não há dentro de um grafo, nós desconectados.
// Grafo cíclico(pode retornar a um que já foi acessado) e acíclico que não há fechamento de ciclo.
// Grafo simples (só existe um tipo de conexão de um nó com outro) ou multigrafo(mais de um tipo de conexão entre dois nós, ex.: pessoas e comunidade).
// Grafo completo(Partindo de um nó, ele tem ligação com todos os outros nós) ou incompleto(maioria).
// Grafo Bipartido(nós de diferentes tipos, nunca de pessoa pra pessoa ou filme pra filme).
// Grafo Planar(sem cruzamento de arestas), euleriano(apenas 2 nós pode ter número de arestas ímpares, o restante com números pares).
// Grafo hamiltoniano(partindo de um nó, varre todos os outros vértices, passando apenas uma vez por cada um).

#include <iostream>
using namespace std;

struct v{ // Referente aos vértices.
	int vertice;
	v *proximo;
	list<int> *adj;
};

int main(){
	
	
	return 0;
}