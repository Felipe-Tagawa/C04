#include <iostream>
#include <list>
using namespace std;

// Defini��o da estrutura para representar um n� de um grafo
struct no {
    int v; // V�rtice adjacente
    int peso; // Peso da aresta
};

// Fun��o para criar uma aresta entre dois v�rtices
void cria_aresta(list<no> *adj, int u, int v, int p, int orientado) {
    no vertice;
    vertice.v = v; // Define o v�rtice de destino da aresta
    vertice.peso = p; // Define o peso da aresta
    adj[u].push_back(vertice); // Adiciona a aresta � lista de adjac�ncias do n� 'u'

    if (orientado == 0) { // Verifica se o grafo � n�o orientado
        vertice.v = u; // Define o v�rtice de origem da aresta
        vertice.peso = p; // Define o peso da aresta
        adj[v].push_back(vertice); // Adiciona a aresta � lista de adjac�ncias do n� 'v' (para grafos n�o orientados)
    }
}

int main() {
    // Declara��o de vari�veis
    int n, orientado, origem, destino, peso;
    list<no>::iterator it; // Iterador para percorrer a lista de adjac�ncias
    cin >> n >> orientado; // Leitura do n�mero de v�rtices e se o grafo � orientado ou n�o

    // Inicializa��o da lista de adjac�ncias
    list<no> adj[n];

    // Leitura e cria��o das arestas do grafo
    while (cin >> origem >> destino >> peso && origem != -1 && destino != -1 && peso != -1) {
        cria_aresta(adj, origem, destino, peso, orientado); // Cria��o da aresta no grafo
    }

    // Impress�o das arestas do grafo
    for (int i = 0; i < n; i++) {
        for (it = adj[i].begin(); it != adj[i].end(); it++) {
            cout << i << " " << it->v << " " << it->peso << endl; // Imprime o v�rtice de origem, o v�rtice de destino e o peso da aresta
        }
    }

    return 0;
}
