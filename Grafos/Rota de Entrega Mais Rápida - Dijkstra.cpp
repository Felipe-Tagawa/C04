#include <iostream>
#include <list>
#include <climits>
using namespace std;

struct edge{
    int v, tempo; // Destino e tempo da estrutura.
};

void cria_aresta(list<edge> adj[], int u, int v, int tempo) /*, int orientado)*/{
    edge aux;
    
    aux.v = v;
    aux.tempo = tempo;
    adj[u].push_back(aux);
    /*if(orientado == 0){
        aux.v = u;
        adj[v].push_back(aux);
    }*/
}

void tempo_minimo(list<edge>adj[], int vertices, int start, int end){
	bool intree[vertices];
	int distance[vertices], parent[vertices];
	list<edge>:: iterator p;
	
	for(int u = 0; u < vertices; u++){
		intree[u] = false;
		distance[u] = INT_MAX; // Todas as distâncias iniciam infinitas.
		parent[u] = -1;
	}
	distance[start] = 0; // No nosso caso, é a posição 0.
	int v = start;
	while(intree[v] == false){
		intree[v] = true;
		for(p = adj[v].begin(); p != adj[v].end(); p++){
			int dest = p->v;
			int tempo = p ->tempo;
			/*if(intree[dest] == true){ // Para não verificar uma aresta já visitada.
				continue;
			}*/
			if(distance[dest] > distance[v] + tempo){
				distance[dest] = distance[v] + tempo;
				parent[dest] = v;
			}
		}
		v = 0;
		int dist = INT_MAX;
		// Procurar a menor aresta até então.
		for(int u = 0; u < vertices; u++){
			if(intree[u] == false && dist > distance[u]){
				dist = distance[u]; // Dist recebe a menor distância possível dentre as arestas.
				v = u;
			}
		}
	}
	
	cout << distance[end] << endl;
}

int main(){
    
    int n, m; // Número de cidades e o número de estradas.
    int u, v, t; // Estrada entre u e v e t representa o tempo.
    int origem, destino;
    
    cin >> n >> m;
    
    list<edge>adj[n];
    
    for(int i = 0; i < m; i++){
        cin >> u >> v >> t;
        
        cria_aresta(adj,u-1,v-1,t);
    }
    
    cin >> origem >> destino; // origem e destino.
    
    tempo_minimo(adj, n, origem - 1 , destino - 1);
    
    /*int i = 0;
    while(!adj[i].empty()){
        adj[i].pop_front();      // Limpeza da lista de adjacência
        i++;
    }*/
    
    return 0;
}