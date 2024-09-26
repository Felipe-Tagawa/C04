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

void dijkstra(list<no> adj[], int nVertices, int start, int end){
    int distancia[nVertices], pai[nVertices];                                  // Vetores para armazenar as dist�ncias m�nimas e os pais dos v�rtices
    int u, v, i;
    int destino, dist, weight;
    bool inTree[nVertices];                                                    // Vetor para marcar se um v�rtice est� na �rvore de menor caminho
    list <no> :: iterator p;                                                   // Iterador para percorrer os n�s da lista de adjac�ncia
    list <int> pilha_aux;                                                      // Lista auxiliar para armazenar o caminho m�nimo

    // Inicializa��o dos vetores
    for(u = 0; u < nVertices; u++){
        inTree[u] = false;
        distancia[u] = INT_MAX;                                                // Dist�ncias iniciam com valor m�ximo
        pai[u] = -1;                                                           // Pais iniciam com valor inv�lido
    }

    distancia[start] = 0;                                                      // Dist�ncia do v�rtice de partida � 0
    v = start;

    // Algoritmo de Dijkstra
    while(inTree[v] == false){
        inTree[v] = true;

        // Percorre os v�rtices adjacentes ao v�rtice atual
        for(p = adj[v].begin(); p != adj[v].end(); p++){
            destino = p->v;
            weight = p->peso;
            if(intree[dest] == true){ // Para n�o verificar uma aresta j� visitada.
				continue;
			}

            // Atualiza as dist�ncias m�nimas e os pais dos v�rtices adjacentes se necess�rio
            if(distancia[destino] > distancia[v] + weight){
                distancia[destino] = distancia[v] + weight;
                pai[destino] = v;
            }
        }

        v = 0;
        dist = INT_MAX;

        // Encontra o v�rtice com a menor dist�ncia m�nima que ainda n�o est� na �rvore de menor caminho
        for(u = 0; u < nVertices; u++){
            if(inTree[u] == false && dist > distancia[u]){
                dist = distancia[u];
                v = u;
            }
        }
    }

    // Constru��o do caminho m�nimo
    for(i = end; i >= start; i = pai[i]){
        pilha_aux.push_front(i);
    }

    // Impress�o do caminho m�nimo e do custo total
    cout << "Menor caminho: ";
    while(!pilha_aux.empty()){
        cout << *pilha_aux.begin() << " ";
        pilha_aux.pop_front();
    }

    cout << "Custo: " << distancia[end] << endl;
}

int main(){
    int u, v, peso, start, end, i;
    int nVertices, orientado;
    list <no> adj[10];                                  // Declara��o da lista de adjac�ncia

    cin >> nVertices >> orientado >> start >> end;      // Leitura do n�mero de v�rtices, orienta��o do grafo, v�rtice de partida e v�rtice de destino

    cin >> u >> v >> peso;
    while(u != -1 && v != -1 && peso != -1){
        cria_aresta(adj, u, v, peso,  orientado);       // Cria��o das arestas do grafo
        cin >> u >> v >> peso;
    }

    dijkstra(adj, nVertices, start, end);               // Chamada da fun��o dijkstra para encontrar o menor caminho

    i = 0;
    while(!adj[i].empty()){
        adj[i].pop_front();                             // Limpeza da lista de adjac�ncia
        i++;
    }

    return 0;                                           // Retorna 0 para indicar que o programa foi executado com sucesso
}