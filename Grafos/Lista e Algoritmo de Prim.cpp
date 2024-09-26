/*
Se um grafo for acíclico e conexo, é chamado de ÁRVORE.
Se um grafo for acíclico e desconexo, é chamado de floresta.
Árvore geradora : Subconjunto de arestas de um grafo conexo que formam uma árvore.
MST : Árvore geradora mínima : Conjunto de arestas que formam uma árvore e que os pesos são os menores possíveis.
Algoritmo de Prim : grafos ponderados, conexos e não direcionados. Encontra a MST de forma gulosa, a partir da escolha de um nó inicial,
depois escolhe a aresta mais apetitosa e insere esta aresta e seu vértice no subgrafo.
Algoritmo de Kruskal - mais complexo, usa o conceito de florestas e árvores, também guloso e apenas ponderados, conexos e não direcionados.
*/

#include <iostream>
#include <list>
using namespace std;

struct Aresta {
	int peso;
	int origem;
	int destino;
};

int menor_peso_nao_visitado(list<Aresta> *adj, bool * visitado, int n) {
	int min_peso = 9999;
	int min_indice = -1;

	for(int i = 0; i < n; i++) {
		if(!visitado[i]) {
			for(list<Aresta>::iterator it = adj[i].begin(); it != adj[i].end(); it++) {
				Aresta aresta = * (it); // Pega o valor númerico da aresta(peso).
				if (!visitado[aresta.destino] and aresta.peso < min_peso) {
					min_peso = aresta.peso;
					min_indice = i;
				}
			}
		}
	}

	return min_indice;

}

void prim(list<Aresta> *adj/*ou []*/, int n) {
	bool visitado[n];
	for(int i = 0; i < n; i++) {
		visitado[i] = false;
	}

	// Começando o algoritmo de prim:
	//Para construir a MST:
	for(int i = 0; i < n - 1; i++) {

		int u = menor_peso_nao_visitado(adj, visitado, n);

		list<Aresta>::iterator it;
		for(it = adj[u].begin(); it != adj[u].end(); it++) {
			Aresta aresta = * (it);
			if(!visitado[aresta.destino]) {
				cout << u << " - " << aresta.destino << " (" << aresta.peso << ") " << endl;
				break;
			}
		}
		visitado[u] = true;
	}
}


int main() {

	int n, a, origem, destino;

	cin >> n >> a; //nós e arestas.

	list<Aresta> adj[n]; // Com peso, precisa de struct pois são duas informações(destino e peso).
	// Quando é não ponderado, apenas o destino importa e a lista pode ser de inteiros.

	for(int i = 0; i < a; i++) {
		int peso;
		cin >> origem >> destino >> peso;

		if(peso != 0) {
			adj[origem].push_back ({origem, destino, peso});
			adj[destino].push_back ({destino, origem, peso});
		}
	}

	prim(adj, n);

	return 0;


}
