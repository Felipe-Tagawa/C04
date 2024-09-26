#include <iostream>
#include <list>
using namespace std;

struct no {
	int v;
	int peso;
};

// Fun��o para realizar a busca em largura (BFS)
void bfs(list<no> adj[], int nVertices, int s) {
	string state[nVertices]; // estado de cada v�rtice ('u', 'd' ou 'p')
	int pai[nVertices]; // pai de cada v�rtice

	list<int> q;

	for (int u = 0; u < nVertices; u++) {
		if (u != s) {
			state[u] = "u"; // undiscovered.
			pai[u] = -1;
		}
	}

	state[s] = "d"; // discovered.
	pai[s] = -1;
	q.push_back(s);

	while (!q.empty()) {
		int u = q.front();
		q.pop_front();
		cout << u << endl; // Imprime o v�rtice atual

		// Percorrendo todos os v�rtices adjacentes ao v�rtice atual:
		for (list<no>::iterator p = adj[u].begin(); p != adj[u].end(); p++) {
			int v = p->v;
			cout << u << " " << v << endl;

			// Se o v�rtice adjacente n�o foi descoberto
			if (state[v] == "u") {
				state[v] = "d";
				pai[v] = u;
				q.push_back(v);
			}
		}
		state[u] = "p";
	}
}

int main() {
		int nVertices, s;
		cin >> nVertices >> s;

		list<no> adj[nVertices];


		int origem, destino, peso;
		while (cin >> origem >> destino >> peso && origem != -1 && destino != -1 && peso != -1) {

			// Fazendo a l�gica da n�o-orienta��o:
			no aresta_destino;
			aresta_destino.v = destino;
			aresta_destino.peso = peso;
			adj[origem].push_back(aresta_destino);

			no aresta_origem;
			aresta_origem.v = origem;
			aresta_origem.peso = peso;
			adj[destino].push_back(aresta_origem);
		}

		bfs(adj, nVertices, s);

		return 0;
	}

