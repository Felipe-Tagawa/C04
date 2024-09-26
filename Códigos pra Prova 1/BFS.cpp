#include <iostream>
#include <list>
using namespace std;

// Definição da estrutura para representar um nó de um grafo
struct no {
	int v;     // Vértice de destino da aresta
	int peso;  // Peso da aresta
};

// Função para criar uma aresta entre dois vértices
void cria_aresta(list<no> *adj, int u, int v, int peso, int orientado) {
    no aux;                       // Cria uma variável auxiliar do tipo 'no' para representar a aresta
    aux.v = v;                    // Define o vértice de destino da aresta na variável auxiliar
    aux.peso = peso;              // Define o peso da aresta na variável auxiliar
    adj[u].push_back(aux);        // Adiciona a aresta à lista de adjacências do nó 'u'

    if (orientado == 0) {         // Verifica se o grafo é não orientado
        aux.v = u;                // Define o vértice de origem da aresta na variável auxiliar
        adj[v].push_back(aux);    // Adiciona a aresta à lista de adjacências do nó 'v' (para grafos não orientados)
    }
}

// Função para realizar a busca em largura (BFS)
void bfs(list<no> adj[], int nVertices, int s) {
	string state[nVertices]; // estado de cada vértice ('u', 'd' ou 'p')
	list<no>::iterator p;   // Iterador para percorrer a lista de adjacências de cada vértice
	int pai[nVertices];     // pai de cada vértice
	list<int> q;            // Fila para armazenar os vértices a serem visitados

	// Inicialização dos estados e pais de cada vértice
	for (int u = 0; u < nVertices; u++) {
		if (u != s) {
			state[u] = "u"; // undiscovered (não descoberto).
			pai[u] = -1;    // Define o pai de cada vértice como -1 (ainda não foi descoberto)
		}
	}

	state[s] = "d"; // discovered (descoberto).
	pai[s] = -1;
	q.push_back(s); // Adiciona o vértice inicial à fila de visitação

	// Processamento da busca em largura
	while (!q.empty()) {
		int u = q.front(); // Obtém o primeiro vértice da fila
		q.pop_front();     // Remove o primeiro vértice da fila
		cout << u << endl; // Imprime o vértice atual

		// Percorrendo todos os vértices adjacentes ao vértice atual:
		for (p = adj[u].begin(); p != adj[u].end(); p++) {
			int v = p->v;  // Vértice adjacente
			cout << u << " " << v << endl;

			// Se o vértice adjacente não foi descoberto
			if (state[v] == "u") {
				state[v] = "d"; // Define o estado do vértice como descoberto
				pai[v] = u;     // Define o pai do vértice adjacente como o vértice atual
				q.push_back(v); // Adiciona o vértice adjacente à fila de visitação
			}
		}
		state[u] = "p"; // Define o estado do vértice atual como processado
	}
}

int main() {
	// Declaração de variáveis
	int nVertices, s; // Número de vértices e vértice inicial para a busca em largura
	cin >> nVertices >> s; // Leitura do número de vértices e vértice inicial

	// Inicialização da lista de adjacências
	list<no> adj[nVertices];

	
	/*
	IMPORTANTE: Se o vértice inicial for 1 e não 0, devemos subtrair 1 das entradas origem e destino.
	*/
	
	// Leitura e criação das arestas do grafo
	int origem, destino, peso;
	while (cin >> origem >> destino >> peso && origem != -1 && destino != -1 && peso != -1) {
		cria_aresta(adj, origem, destino, peso, 0); // Criação da aresta no grafo não orientado
	}

	// Realização da busca em largura a partir do vértice inicial
	bfs(adj, nVertices, s);

	return 0;
}
