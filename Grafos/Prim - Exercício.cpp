#include <iostream>
#include <list>
using namespace std;

struct no {
	int peso, v, origem; // V é destino.
};

void prim(list<no> *adj , int nVertices, int start) {
	bool intree[nVertices];
	int distance[nVertices];
	int parent[nVertices];
	int INT_MAX, custo_total = 0;

	for(int u = 0; u < nVertices; u++) {
		distance[u] = INT_MAX;
		parent[u] = -1;
	}

	distance[start] = 0;
	int v = start;

	while(!intree[v]) {
		intree[v] = true;

		for (list<no>::iterator p = adj[v].begin(); p != adj[v].end(); p++) {
			int destiny = p->v;
			int weight = p->peso;
			if (!intree[destiny] and distance[destiny] > weight) {
				distance[destiny] = weight;
				parent[destiny] = v;
			}
		}
		v = 0;
		int dist = INT_MAX;
		for(int u = 0; u < nVertices; u++) {
			if(!intree[u] and dist > distance[u]) {
				dist = distance[u];
				v = u;
			}
		}

		cout << "Arvore Geradora Minima:" << endl;
		for(int u = 0; u < nVertices; u++) {
			if(parent[u] != -1) {
				cout << parent[u] << " " << u << endl;
				custo_total += distance[u];
			}
		}
		cout << "Custo: " << custo_total << endl;
	}
}

	int main() {

		int n, destino, v_origem, origem, orientado, peso;

		cin >> n >> orientado >> origem;
		list<no> adj[n];

		while(cin >> origem >> destino >> peso and origem != -1 and destino != -1 and peso != -1) {
			if (orientado == 0) {
				adj[origem].push_back( {origem, destino, peso});
				adj[destino].push_back( {destino, origem, peso});
			} else if(orientado == 1) {
				adj[origem].push_back( {origem, destino, peso});
			}
		}

		prim(adj, n , v_origem);

		return 0;
	}
