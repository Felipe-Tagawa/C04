#include <iostream>
#include <list>
using namespace std;

// Definição da estrutura para representar um nó de um grafo
struct no {
    int v; // Vértice adjacente
    int peso; // Peso da aresta
};

// Função para criar uma aresta entre dois vértices
void cria_aresta(list<no> *adj, int u, int v, int p, int orientado) {
    no vertice;
    vertice.v = v; // Define o vértice de destino da aresta
    vertice.peso = p; // Define o peso da aresta
    adj[u].push_back(vertice); // Adiciona a aresta à lista de adjacências do nó 'u'

    if (orientado == 0) { // Verifica se o grafo é não orientado
        vertice.v = u; // Define o vértice de origem da aresta
        vertice.peso = p; // Define o peso da aresta
        adj[v].push_back(vertice); // Adiciona a aresta à lista de adjacências do nó 'v' (para grafos não orientados)
    }
}

int main() {
    // Declaração de variáveis
    int n, orientado, origem, destino, peso;
    list<no>::iterator it; // Iterador para percorrer a lista de adjacências
    cin >> n >> orientado; // Leitura do número de vértices e se o grafo é orientado ou não

    // Inicialização da lista de adjacências
    list<no> adj[n];

    // Leitura e criação das arestas do grafo
    while (cin >> origem >> destino >> peso && origem != -1 && destino != -1 && peso != -1) {
        cria_aresta(adj, origem, destino, peso, orientado); // Criação da aresta no grafo
    }

    // Impressão das arestas do grafo
    for (int i = 0; i < n; i++) {
        for (it = adj[i].begin(); it != adj[i].end(); it++) {
            cout << i << " " << it->v << " " << it->peso << endl; // Imprime o vértice de origem, o vértice de destino e o peso da aresta
        }
    }

    return 0;
}
