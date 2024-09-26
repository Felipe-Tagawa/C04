#include <iostream>
#include <string>
using namespace std;

int matriz_solucao[5][400][1000];
int caminho[5][400][1000] = {0};

int solucao(int i, int peso[], int volume[], int valor[], int capp, int capv, int n, string nome[], int caminho[][400][1000]) {
	if (i >= n || capp <= 0 || capv <= 0) {
		return 0;
	}

	if (matriz_solucao[i][capp][capv] != -1) { // -1 s�o todos os valores que ainda n�o foram calculados no programa.
		return matriz_solucao[i][capp][capv]; // Evita repetir os caminhos j� calculados.
	}

	// L�gica - Mostrar se vale ou n�o a pena pegar uma pedra: Pegar a pedra --> Caminho = 1 e n�o pegar a pedra --> Caminho = 0;
	int sol_2 = 0;
	int sol_1;
	sol_1 = solucao(i + 1, peso, volume, valor, capp, capv, n, nome, caminho);

	if (capp >= peso[i] and capv >= volume[i]) {
		sol_2 = solucao(i + 1, peso, volume, valor, capp - peso[i], capv - volume[i], n, nome, caminho) + valor[i];
		caminho[i][capp][capv] = 1; // Quando decidir pegar a pedra.
	} else {
		caminho[i][capp][capv] = 0; // Quando n�o for pegar a pedra.
	};
	return matriz_solucao[i][capp][capv] = max(sol_1, sol_2); // Armazenando o resultado m�ximo em uma matriz para evitar repeti��es.
}

int main() {
	int i = 0;
	int peso[5] = {263, 127, 254, 134, 111};
	int volume[5] = {455, 521, 857, 65, 12};
	int valor[5] = {500, 410, 320, 315, 280};
	string nome[5] = {"Diamante", "Esmeralda", "Topazio", "Rubi", "Jade"};
	int capp = 400;
	int capv = 1000;
	const int n = 5;
	
	// Inicializa��o da matriz com -1:
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= capp; j++) {
			for (int k = 0; k <= capv; k++) {
				matriz_solucao[i][j][k] = -1;
			}
		}
	}

	int resultado = solucao(0, peso, volume, valor, capp, capv, n, nome, caminho);

	cout << "Pedras selecionadas:" << endl;
	for (int i = 0; i < n; i++) {
		if (caminho[i][capp][capv] == 1) {
			cout << nome[i] << endl;
		}
	}

	return 0;
}
