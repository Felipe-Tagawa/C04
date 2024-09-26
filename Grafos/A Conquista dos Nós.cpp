#include <iostream>
using namespace std;

int main(){
    int n, m, a, b;
    cin >> n >> m;
    
    //Inicializando a matriz de adjacência.
    int mat_adj[n][n] = {0};
    
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        mat_adj[i][j] = 0;
    }
}
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        // Marca a conexão entre as cidades a e b como bidirecional
        mat_adj[a - 1][b - 1] = 1;
        mat_adj[b - 1][a - 1] = 1;
    }
    
    // Imprimindo a matriz de adjacência
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << mat_adj[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
