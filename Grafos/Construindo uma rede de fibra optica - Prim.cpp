#include <iostream>
#include <climits>
#include <list>
using namespace std;

struct no {
    int v, peso;
};

void cria_aresta(list<no> adj[], int u, int v, int peso, int orientado){
    no aux;
    
    aux.v = v;
    aux.peso = peso;
    adj[u].push_back(aux);
    if(orientado == 0){
        aux.v = u;
        aux.peso = peso;
        adj[v].push_back(aux);
    }
    
}

void custo_minimo(list<no> adj[], int n, int start) {
    bool intree[n];
    int distance[n], parent[n], custo = 0;
    list<no>::iterator p;
    for (int u = 0; u < n; u++) {
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
    }
    distance[start] = 0;
    int v = start;
    
    while (!intree[v]) {
        intree[v] = true;
        
        for (p = adj[v].begin(); p != adj[v].end(); p++) {
            int destino = p->v;
            int peso = p->peso;
            
            if (distance[destino] > peso && !intree[destino]) {
                distance[destino] = peso;
                parent[destino] = v;
            }
        }
        v = 0;
        int dist = INT_MAX;
        for (int u = 0; u < n; u++) {
            if (!intree[u] && dist > distance[u]) {
                dist = distance[u];
                v = u;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        custo += distance[i];
    }
    
    cout << custo << endl;
}

int main() {
    int n, m; // Número de cidades e conexões.
    int orientado = 0;
    cin >> n >> m;
    int u, v, c; // Origem, destino e custo.
    list<no> adj[n];
    
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        /*
        adj[u].push_back({u, v, c});
        adj[v].push_back({v, u, c});
        */
        cria_aresta(adj,u-1,v-1,c, orientado);
    }
    
    custo_minimo(adj, n , 0);
    
    return 0;
}
