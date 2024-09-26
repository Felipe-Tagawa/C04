#include <iostream>
#include <list>
#include <climits>
using namespace std;

struct edge{
    int v; // Destino.
};

void cria_aresta(list<edge> adj[], int u, int v){
    edge aux;
    
    aux.v = v;
    adj[u].push_back(aux);
    /*if(orientado == 0){
        aux.v = u;
        aux.peso = peso;
        adj[v].push_back(aux);
    }*/
}

void tempo_minimo(list<edge>adj[], int vertices, int start, int end){
	bool intree[vertices];
	int distance[vertices], parent[vertices];
	list<edge>:: iterator p;
	int caminho = -1;
	
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
			/*if(intree[dest] == true){ // Para não verificar uma aresta já visitada.
				continue;
			}*/
			if(distance[dest] > distance[v]){
				distance[dest] = distance[v];
				parent[dest] = v;
				caminho++;
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
	
	if(caminho > 0)
	cout << caminho << endl;
	else{
		cout << "IMPOSSIVEL" << endl;
	}
}

int main(){
	
	int n, m; // Número de salas e de corredores.
	int s, d; // Origem e destino.
	int u, v;
	
	cin >> n >> m;
	list<edge> adj[n];
	
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		
		cria_aresta(adj, u-1, v-1);
	}
	
	cin >> s >> d;
	
	tempo_minimo(adj, n, s-1, d-1);
	
	return 0;
}