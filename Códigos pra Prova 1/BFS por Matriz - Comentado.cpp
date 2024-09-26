// Coment�rio sobre a fun��o bfs:
// A fun��o bfs implementa o algoritmo de busca em largura (BFS) em um grafo representado por uma matriz de adjac�ncia.
// O BFS visita todos os n�s vizinhos de um n� de origem primeiro e depois avan�a para os pr�ximos n�veis (profundidade) 
// visitando os n�s vizinhos dos vizinhos.

#include <iostream>
#include <list>
using namespace std;

// Fun��o bfs para realizar a busca em largura em um grafo representado por uma matriz de adjac�ncia
bool bfs(bool adj[10][10], int vertices, int origem) {
    list<int> fila_espera; // Lista para armazenar os n�s a serem visitados
    bool visitado[vertices]; // Array para armazenar os n�s visitados

    // Inicializa��o do array de n�s visitados
    for(int i = 0; i < vertices; i++) {
        visitado[i] = false;
    }

    fila_espera.push_back(origem); // Adiciona o n� de origem � fila de espera
    int atual;

    // Loop principal do BFS
    while(!fila_espera.empty()) {
        atual = fila_espera.front(); // Obt�m o primeiro n� da fila de espera
        visitado[atual] = true; // Marca o n� como visitado
        for(int i = 0; i < vertices; i++) {
            // Verifica se h� uma aresta entre o n� atual e o n� i e se o n� i ainda n�o foi visitado
            if(adj[atual][i] == true and visitado[i] == false) {
                fila_espera.push_back(i); // Adiciona o n� i � fila de espera
            }
        }
        fila_espera.pop_front(); // Remove o n� atual da fila de espera
        cout << atual << endl; // Imprime o n� atual (ordem de visita)
    }

    // Verifica��o de conexidade do grafo
    for(int i = 0; i < vertices; i++) {
        if(visitado[i] == false) {
            return false; // Se algum n� n�o foi visitado, o grafo � desconexo
        }
    }
    return true; // Se todos os n�s foram visitados, o grafo � conexo
}

int main() {
    // Declara��o de vari�veis
    int n, origem;
    cin >> n >> origem; // Leitura do n�mero de v�rtices e v�rtice de origem

    bool matriz_adj[10][10]; // Matriz de adjac�ncia para representar o grafo
    // Inicializa��o da matriz de adjac�ncia como totalmente desconexa
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matriz_adj[i][j] = false;
        }
    }

    // Leitura e cria��o das arestas do grafo
    int i = 0, j = 0;
    while(i != -1 and j != -1) {
        cin >> i >> j; // Leitura dos v�rtices da aresta
        matriz_adj[i][j] = true; // Marca a aresta na matriz de adjac�ncia (bidirecional)
        matriz_adj[j][i] = true; // Marca a aresta na matriz de adjac�ncia (bidirecional)
    }

    // Chamada da fun��o bfs para realizar a busca em largura no grafo
    bfs(matriz_adj, n, origem);

    // Verifica��o da conexidade do grafo e impress�o do resultado
    if(bfs(matriz_adj, n, origem)) {
        cout << "Conexo" << endl;
    } else {
        cout << "Desconexo" << endl;
    }
    
    return 0;
}
