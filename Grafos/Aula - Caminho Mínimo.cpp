// Algoritmo de Dijkstra
// Acessa apenas uma vez cada caminho para encontrar o menor caminho.
// I � o v�rtice inicial, S representa o conjunto de menores caminhos.

#include <iostream>
#include <climits>
#include <list>
using namespace std;

struct edge{
	 int orim, dest, weight;	
};

int shortest_path_dijkstra(list<edge>adj[], int vertices, int start, int end){
	bool intree[vertices];
	int distance[vertices], parent[vertices];
	
	for(int u = 0; u < vertices; u++){
		intree[u] = false;
		distance[u] = INT_MAX; // Todas as dist�ncias iniciam infinitas.
		parent[u] = -1;
	}
	distance[start] = 0; // No nosso caso, � a posi��o 0.
	int v = start;
	while(intree[v] == false){
		intree[v] = true;
		list<edge>:: iterator p;
		for(p = adj[v].begin(); p != adj[v].end(); p++){
			int dest = p->dest;
			int weight = p ->weight;
			if(intree[dest] == true){ // Para n�o verificar uma aresta j� visitada.
				continue;
			}
			if(distance[dest] > distance[v] + weight){
				distance[dest] = distance[v] + weight;
				parent[dest] = v;
			}
		}
		v = 0;
		int dist = INT_MAX;
		// Procurar a menor aresta at� ent�o.
		for(int u = 0; u < vertices; u++){
			if(intree[u] == false and dist > distance[u]){
				dist = distance[u]; // Dist recebe a menor dist�ncia poss�vel dentre as arestas.
				v = u;
			}
		}
	}
	return distance[end];
}

int main(){
	
	   	int vertices, directed;
	   	
	   	cin >> vertices >> directed;
	   	
	   	list<edge> adj[vertices];
	   	
	   	int v1, v2, w; // w � peso da aresta.
	   	
	   	while(cin >> v1 >> v2 >> w and v1 != -1 and v2 != -1 and w != -1){
			   adj[v1].push_back({v1,v2,w});
			   if(directed == 0){
				   adj[v2].push_back({v2,v1,w});
			   }
		   }
		  // Para verificar o caminho, usa-se o parent de forma inversa(end at� o start), Exemplo: se o end for 4 e o start 0,
		  // pega-se o parent na posi��o 4, que seria 5, por exemplo, depois o parent de 5 que � o 2 e depois o parent de 2 que
		  // � o 0 e assim acaba, usando um for. 
		cout << shortest_path_dijkstra(adj, vertices, 0, 4) << endl;
	
	return 0;
}