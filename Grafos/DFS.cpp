// O algoritmo de DFS(Busca em profundidade, varre o grafo em profundidade e backtracking(retorna))
// Pode ser feito por lista de adjasc�ncia ou matriz de adjasc�ncia.

#include <iostream>
using namespace std;

void dfs(int adj[][], bool visited[], int vertices, int curr){
	visited[vertices];
	visited[curr] = true;
	for(int i = 0; i < vertices; i++){
		if(adj[curr][i] != -1 && visited[i] == false){ // Se existir uma conex�o(peso existente) e apenas para v�rtices n�o visitados.
			dfs(adj, visited, vertices, i);
		}
	}
}

int main(){
	
	int o, d, p, vertices, directed; // Origem, destino, n�mero de v�rtices, direcionado.
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

// Fun��o DFS para realizar a busca em profundidade em um grafo representado por uma lista de adjac�ncia
void dfs(list<int> adj[], bool visited[], int curr) {
    visited[curr] = true; // Marca o n� atual como visitado
    cout << curr << endl; // Imprime o n� atual (ordem de visita)

    // Percorre todos os n�s adjacentes ao n� atual
    for (int i : adj[curr]) {
        // Se o n� adjacente ainda n�o foi visitado, chama recursivamente a fun��o dfs para visit�-lo
        if (!visited[i]) {
            dfs(adj, visited, i);
        }
    }
}

int main() {
    int o, d, p, vertices, directed; // Origem, destino, peso, n�mero de v�rtices, direcionado
    cin >> vertices >> directed;

    // Inicializa��o da lista de adjac�ncia
    list<int> adj[vertices];

    // Leitura das arestas e constru��o da lista de adjac�ncia
    while (cin >> o >> d >> p && o != -1 && d != -1 && p != -1) {
        adj[o].push_back(d); // Adiciona a aresta do n� o para o n� d
        if (!directed) {
            adj[d].push_back(o); // Adiciona a aresta do n� d para o (para grafos n�o direcionados)
        }
    }

    // Inicializa��o do array de n�s visitados
    bool visited[vertices] = {false};

    // Chamada da fun��o dfs para realizar a busca em profundidade no grafo
    dfs(adj, visited, 0); // Come�a a busca a partir do n� 0

    return 0;
}

	*/
}