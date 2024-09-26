#include <iostream>
#include <list>
#include <climits>

using namespace std;

// Estrutura de dados para representar uma aresta
struct no{
    int v;         // Identificador do v�rtice adjacente
    int peso;      // Peso da aresta
};

// Fun��o para criar uma aresta entre dois v�rtices
void cria_aresta(list<no> adj[], int u, int v, int peso, int orientado) {
    no aux;                       // Cria uma vari�vel auxiliar do tipo 'no' para representar a aresta

    aux.v = v;                    // Define o v�rtice de destino da aresta na vari�vel auxiliar
    aux.peso = peso;              // Define o peso da aresta na vari�vel auxiliar
    adj[u].push_back(aux);        // Adiciona a aresta � lista de adjac�ncias do n� 'u'

    if (orientado == 0) {         // Verifica se o grafo � n�o orientado
        aux.v = u;                // Define o v�rtice de origem da aresta na vari�vel auxiliar
        adj[v].push_back(aux);    // Adiciona a aresta � lista de adjac�ncias do n� 'v' (para grafos n�o orientados)
    }
}

void prim(list<no> adj[], int nVertices, int start) {
    int distancia[nVertices];                             // Vetor para armazenar as dist�ncias m�nimas de cada v�rtice at� a �rvore geradora m�nima
    int pai[nVertices];                                   // Vetor para armazenar o pai de cada v�rtice na �rvore geradora m�nima
    int u, v, i;
    int destino, dist, weight;
    int custo = 0;                                        // Vari�vel para armazenar o custo total da �rvore geradora m�nima
    bool inTree[nVertices];                               // Vetor para marcar se um v�rtice j� est� na �rvore geradora m�nima
    list<no>::iterator p;                                 // Iterador para percorrer as arestas adjacentes de um v�rtice

    // Inicializa��o dos vetores
    for (u = 0; u < nVertices; u++) {
        inTree[u] = false;                                // Marca todos os v�rtices como n�o pertencentes � �rvore geradora m�nima
        distancia[u] = INT_MAX;                           // Define a dist�ncia m�nima inicialmente como infinito para todos os v�rtices
        pai[u] = -1;                                      // Define o pai de todos os v�rtices como -1 (ainda n�o definido)
    }

    distancia[start] = 0;                                 // Define a dist�ncia do v�rtice de partida como 0
    v = start;                                            // Define o v�rtice de partida como o v�rtice atual

    while (inTree[v] == false) {
        inTree[v] = true;                                 // Marca o v�rtice atual como pertencente � �rvore geradora m�nima

        // Percorre as arestas adjacentes ao v�rtice atual
        for (p = adj[v].begin(); p != adj[v].end(); p++) {
            destino = p->v;                                    // Obt�m o v�rtice destino da aresta
            weight = p->peso;                                  // Obt�m o peso da aresta

            // Se a dist�ncia m�nima at� o v�rtice destino � maior que o peso da aresta e o v�rtice destino ainda n�o pertence � �rvore geradora m�nima
            if (distancia[destino] > weight && inTree[destino] == false) {
                distancia[destino] = weight;                                   // Atualiza a dist�ncia m�nima at� o v�rtice destino
                pai[destino] = v;                                              // Define o v�rtice atual como o pai do v�rtice destino
            }
        }

        v = 0;
        dist = INT_MAX;

        // Encontra o v�rtice com a menor dist�ncia m�nima que ainda n�o pertence � �rvore geradora m�nima
        for (u = 0; u < nVertices; u++) {
            if (inTree[u] == false && dist > distancia[u]) {
                dist = distancia[u];
                v = u;
            }
        }
    }

    cout << "Arvore Geradora Minima: \n";

    // Imprime as arestas da �rvore geradora m�nima e calcula o custo total
    for (i = 0; i < nVertices; i++) {
        custo += distancia[i];

        if (i != start) {
            cout << pai[i] << " " << i << endl;
        }
    }

    cout << "Custo: " << custo << endl;
}

int main(){
    int u, v, peso, s, i;
    int nVertices, orientado;
    list <no> adj[10];                               // Lista de adjac�ncia para armazenar o grafo
    list <no> :: iterator q;                         // Iterador para percorrer os n�s da lista de adjac�ncia

    cin >> nVertices >> orientado >> s;              // Entrada do n�mero de v�rtices, se o grafo � orientado e o v�rtice de partida

    // Entrada das arestas (v�rtices de origem, destino e peso) at� que valores -1 sejam inseridos
    cin >> u >> v >> peso;
    while(u != -1 && v != -1 && peso != -1){
        cria_aresta(adj, u, v, peso, orientado);     // Cria��o das arestas no grafo
        cin >> u >> v >> peso;
    }

    prim(adj, nVertices, s);                         // Chama a fun��o prim para encontrar a �rvore geradora m�nima

    i = 0;
    while(!adj[i].empty()){
        adj[i].pop_front();                          // Limpa a lista de adjac�ncia
        i++;
    }

    return 0;
}