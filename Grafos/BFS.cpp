// Varredura em largura(BFS) --> Visita todos os nós vizinhos primeiro, depois vai para o próximo
// nível(profundidade - ligados aos vizinhos(vizinho dos vizinhos)).

#include <iostream>
#include <list>
using namespace std;

#define VERTICES 5

bool bfs(bool adj[VERTICES][VERTICES], int vertices, int origem){
	list<int> fila_espera;
	bool visitado[vertices];
	
	for(int i = 0; i < vertices; i++){
		visitado[i] = false;
	} 
	
	fila_espera.push_back(origem); // Primeiro valor é a própria origem.
	int atual;

	while(!fila_espera.empty()) {
		atual = fila_espera.front();
		visitado[atual] = true;
		for(int i = 0; i < vertices; i++) {
			if(adj[atual][i] == true and visitado[i] == false) { // Vai verificar se em uma linha, quantas conexões são verdadeiras.
				fila_espera.push_back(i); // Acrescenta apenas aqueles vizinhos.
			}
		}
		fila_espera.pop_front(); // Elimina a origem e os próximos valores para que o atual não seja sempre a origem.
		cout << atual << endl;
	}
	
	
	// Para verificar se é conexo ou não.
	for(int i = 0; i < vertices; i++){
		if(visitado[i] == false){
			return false;
		}
	}
	
	return true;
	
}

int main() {

	bool matriz_adj[VERTICES][VERTICES]; // Com peso teria que ser inteiro.
	for(int i = 0; i < VERTICES; i++) {
		for(int j = 0; j < VERTICES; j++) {
			matriz_adj[i][j] = false; // Totalmente desconexo no início.
		}
	}

	/* Leitura :
	int i = 0, j = 0;
	while(i!= -1 and j != -1)
		cin >> i >> j;
		matriz_adj[i][j] = true; // Se começar no vértice 1, i - 1 e j - 1.
		matriz_adj[j][i] = true; // Se começar no vértice 1, i - 1 e j - 1.
	*/

	matriz_adj[0][1] = true;
	matriz_adj[1][0] = true;
	matriz_adj[2][3] = true;
	matriz_adj[3][2] = true;
	matriz_adj[1][2] = true;
	matriz_adj[2][1] = true;

	bfs(matriz_adj, 5, 0);
	if(bfs(matriz_adj, 5, 0)){
		cout << "Conexo" << endl;
	}
	else{
		cout << "Desconexo" << endl;
	}
	
	return 0;

}
