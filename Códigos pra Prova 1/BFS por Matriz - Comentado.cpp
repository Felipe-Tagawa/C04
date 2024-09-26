// Comentário sobre a função bfs:
// A função bfs implementa o algoritmo de busca em largura (BFS) em um grafo representado por uma matriz de adjacência.
// O BFS visita todos os nós vizinhos de um nó de origem primeiro e depois avança para os próximos níveis (profundidade) 
// visitando os nós vizinhos dos vizinhos.

#include <iostream>
#include <list>
using namespace std;

// Função bfs para realizar a busca em largura em um grafo representado por uma matriz de adjacência
bool bfs(bool adj[10][10], int vertices, int origem) {
    list<int> fila_espera; // Lista para armazenar os nós a serem visitados
    bool visitado[vertices]; // Array para armazenar os nós visitados

    // Inicialização do array de nós visitados
    for(int i = 0; i < vertices; i++) {
        visitado[i] = false;
    }

    fila_espera.push_back(origem); // Adiciona o nó de origem à fila de espera
    int atual;

    // Loop principal do BFS
    while(!fila_espera.empty()) {
        atual = fila_espera.front(); // Obtém o primeiro nó da fila de espera
        visitado[atual] = true; // Marca o nó como visitado
        for(int i = 0; i < vertices; i++) {
            // Verifica se há uma aresta entre o nó atual e o nó i e se o nó i ainda não foi visitado
            if(adj[atual][i] == true and visitado[i] == false) {
                fila_espera.push_back(i); // Adiciona o nó i à fila de espera
            }
        }
        fila_espera.pop_front(); // Remove o nó atual da fila de espera
        cout << atual << endl; // Imprime o nó atual (ordem de visita)
    }

    // Verificação de conexidade do grafo
    for(int i = 0; i < vertices; i++) {
        if(visitado[i] == false) {
            return false; // Se algum nó não foi visitado, o grafo é desconexo
        }
    }
    return true; // Se todos os nós foram visitados, o grafo é conexo
}

int main() {
    // Declaração de variáveis
    int n, origem;
    cin >> n >> origem; // Leitura do número de vértices e vértice de origem

    bool matriz_adj[10][10]; // Matriz de adjacência para representar o grafo
    // Inicialização da matriz de adjacência como totalmente desconexa
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matriz_adj[i][j] = false;
        }
    }

    // Leitura e criação das arestas do grafo
    int i = 0, j = 0;
    while(i != -1 and j != -1) {
        cin >> i >> j; // Leitura dos vértices da aresta
        matriz_adj[i][j] = true; // Marca a aresta na matriz de adjacência (bidirecional)
        matriz_adj[j][i] = true; // Marca a aresta na matriz de adjacência (bidirecional)
    }

    // Chamada da função bfs para realizar a busca em largura no grafo
    bfs(matriz_adj, n, origem);

    // Verificação da conexidade do grafo e impressão do resultado
    if(bfs(matriz_adj, n, origem)) {
        cout << "Conexo" << endl;
    } else {
        cout << "Desconexo" << endl;
    }
    
    return 0;
}
