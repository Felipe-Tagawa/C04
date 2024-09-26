#include <iostream>
#include <list>
using namespace std;

struct no {
    int v; // vértice adjacente
    int peso; // peso da aresta
};

void cria_aresta(list<no> *adj, int u, int v, int p, int orientado) {
    no vertice;
    vertice.v = v; // destino.
    vertice.peso = p;
    adj[u].push_back(vertice); // Relação do orientado, apenas uma referência.

    if (orientado == 0) { // se não orientado.
        vertice.v = u; // Origem.
        vertice.peso = p;
        adj[v].push_back(vertice);
    }
}

int main() {
    int n, orientado, origem, destino, peso;
    list<no>::iterator it;
    cin >> n >> orientado;

    list<no> adj[n];

    while (cin >> origem >> destino >> peso && origem != -1 && destino != -1 && peso != -1) {
        cria_aresta(adj, origem, destino, peso, orientado);
    }

    for (int i = 0; i < n; i++) {
   		for (it = adj[i].begin(); it != adj[i].end(); it++)
		{
            cout << i << " " << it->v << " " << it->peso << endl;
        }
    }

    return 0;
}
