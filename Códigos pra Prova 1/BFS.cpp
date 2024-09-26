#include <iostream>
#include <list>
using namespace std;

// Defini��o da estrutura para representar um n� de um grafo
struct no {
	int v;     // V�rtice de destino da aresta
	int peso;  // Peso da aresta
};

// Fun��o para criar uma aresta entre dois v�rtices
void cria_aresta(list<no> *adj, int u, int v, int peso, int orientado) {
    no aux;                       // Cria uma vari�vel auxiliar do tipo 'no' para representar a aresta
    aux.v = v;                    // Define o v�rtice de destino da aresta na vari�vel auxiliar
    aux.peso = peso;              // Define o peso da aresta na vari�vel auxiliar
    adj[u].push_back(aux);        // Adiciona a aresta � lista de adjac�ncias do n� 'u'

    if (orientado == 0) {         // Verifica se o grafo � n�o orientado
        aux.v = u;                // Define o v�rtice de origem da aresta na vari�vel auxiliar
        adj[v].push_back(aux);    // Adiciona a aresta � lista de adjac�ncias do n� 'v' (para grafos n�o orientados)
    }
}

// Fun��o para realizar a busca em largura (BFS)
void bfs(list<no> adj[], int nVertices, int s) {
	string state[nVertices]; // estado de cada v�rtice ('u', 'd' ou 'p')
	list<no>::iterator p;   // Iterador para percorrer a lista de adjac�ncias de cada v�rtice
	int pai[nVertices];     // pai de cada v�rtice
	list<int> q;            // Fila para armazenar os v�rtices a serem visitados

	// Inicializa��o dos estados e pais de cada v�rtice
	for (int u = 0; u < nVertices; u++) {
		if (u != s) {
			state[u] = "u"; // undiscovered (n�o descoberto).
			pai[u] = -1;    // Define o pai de cada v�rtice como -1 (ainda n�o foi descoberto)
		}
	}

	state[s] = "d"; // discovered (descoberto).
	pai[s] = -1;
	q.push_back(s); // Adiciona o v�rtice inicial � fila de visita��o

	// Processamento da busca em largura
	while (!q.empty()) {
		int u = q.front(); // Obt�m o primeiro v�rtice da fila
		q.pop_front();     // Remove o primeiro v�rtice da fila
		cout << u << endl; // Imprime o v�rtice atual

		// Percorrendo todos os v�rtices adjacentes ao v�rtice atual:
		for (p = adj[u].begin(); p != adj[u].end(); p++) {
			int v = p->v;  // V�rtice adjacente
			cout << u << " " << v << endl;

			// Se o v�rtice adjacente n�o foi descoberto
			if (state[v] == "u") {
				state[v] = "d"; // Define o estado do v�rtice como descoberto
				pai[v] = u;     // Define o pai do v�rtice adjacente como o v�rtice atual
				q.push_back(v); // Adiciona o v�rtice adjacente � fila de visita��o
			}
		}
		state[u] = "p"; // Define o estado do v�rtice atual como processado
	}
}

int main() {
	// Declara��o de vari�veis
	int nVertices, s; // N�mero de v�rtices e v�rtice inicial para a busca em largura
	cin >> nVertices >> s; // Leitura do n�mero de v�rtices e v�rtice inicial

	// Inicializa��o da lista de adjac�ncias
	list<no> adj[nVertices];

	
	/*
	IMPORTANTE: Se o v�rtice inicial for 1 e n�o 0, devemos subtrair 1 das entradas origem e destino.
	*/
	
	// Leitura e cria��o das arestas do grafo
	int origem, destino, peso;
	while (cin >> origem >> destino >> peso && origem != -1 && destino != -1 && peso != -1) {
		cria_aresta(adj, origem, destino, peso, 0); // Cria��o da aresta no grafo n�o orientado
	}

	// Realiza��o da busca em largura a partir do v�rtice inicial
	bfs(adj, nVertices, s);

	return 0;
}
