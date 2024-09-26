#include <iostream>
#include <list>
using namespace std;

void bfs(bool mat_adj[100][100], int n, int origem){
    list<int> fila_espera;
    bool visitado[n] = {false};
    
    for(int i = 0; i < n; i++){
		visitado[i] = false;
	} 
    
    fila_espera.push_back(origem);
    int atual;
    while(!fila_espera.empty()) {
		atual = fila_espera.front();
		visitado[atual] = true;
		
		for(int i = 0; i < n; i++) {
			if(mat_adj[atual][i] == true and !visitado[i]) {
				fila_espera.push_back(i);
				//cout << atual << " ";
			}
		}
		fila_espera.pop_front(); //Não queremos que apague todos.
		
	}
	
	for(int i = 0; i < n; i++){
		if(!visitado[i]){
			cout << i + 1<< " "; // Mostrando as cidades inacessíveis a X, se X e Y forem destruídas.
		    
		}
	}
	
	
}


int main(){
    
    int n, m, a, b;
    int x, y; // Ponte a ser destruída.
    
    cin >> n >> m;
    bool mat_adj[100][100] = {false};
    
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        mat_adj[a-1][b-1] = true; // Começa no 1.
        mat_adj[b-1][a-1] = true; // Começa no 1.
    }
    cin >> x >> y;
    mat_adj[x-1][y-1] = false;
    mat_adj[y-1][x-1] = false;
    
    bfs(mat_adj, n, 0);
    
    
    return 0;
}