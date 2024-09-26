// O algoritmo de DFS(Busca em profundidade, varre o grafo em profundidade e backtracking(retorna))
// Pode ser feito por lista de adjascência ou matriz de adjascência.

#include <iostream>
using namespace std;

void dfs(int adj[][], bool visited[], int vertices, int curr){
	visited[vertices];
	visited[curr] = true;
	for(int i = 0; i < vertices; i++){
		if(adj[curr][i] != -1 && visited[i] == false){ // Se existir uma conexão(peso existente) e apenas para vértices não visitados.
			dfs(adj, visited, vertices, i);
		}
	}
}

int main(){
	
	int o, d, p, vertices, directed; // Origem, destino, número de vértices, direcionado.
	bool visited[vertices];
	
	cin >> vertices >> directed;
	int adj[vertices][vertices];
	
	for(int i = 0; i < vertices; i++){
		
		for(int j = 0; j < vertices; j++)
			adj[i][j] = -1;
	}
	
	while(cin >> o >> d >> p && o!= -1 && d!= -1 && p!= -1){
		adj[o][p] = p;
		if(!directed)
			adj[d][o] = p;
	}
	
	dfs(adj, visited, vertices, 0);
	
	return 0;
	
	/* COM LISTA:
	
	#include <iostream>
#include <list>
using namespace std;

// Função DFS para realizar a busca em profundidade em um grafo representado por uma lista de adjacência
void dfs(list<int> adj[], bool visited[], int curr) {
    visited[curr] = true; // Marca o nó atual como visitado
    cout << curr << endl; // Imprime o nó atual (ordem de visita)

    // Percorre todos os nós adjacentes ao nó atual
    for (int i : adj[curr]) {
        // Se o nó adjacente ainda não foi visitado, chama recursivamente a função dfs para visitá-lo
        if (!visited[i]) {
            dfs(adj, visited, i);
        }
    }
}

int main() {
    int o, d, p, vertices, directed; // Origem, destino, peso, número de vértices, direcionado
    cin >> vertices >> directed;

    // Inicialização da lista de adjacência
    list<int> adj[vertices];

    // Leitura das arestas e construção da lista de adjacência
    while (cin >> o >> d >> p && o != -1 && d != -1 && p != -1) {
        adj[o].push_back(d); // Adiciona a aresta do nó o para o nó d
        if (!directed) {
            adj[d].push_back(o); // Adiciona a aresta do nó d para o (para grafos não direcionados)
        }
    }

    // Inicialização do array de nós visitados
    bool visited[vertices] = {false};

    // Chamada da função dfs para realizar a busca em profundidade no grafo
    dfs(adj, visited, 0); // Começa a busca a partir do nó 0

    return 0;
}

	*/
}