#include <iostream>
#include <string>
using namespace std;

// Declara��o de matriz global para armazenar solu��es parciais
int matriz_solucao[5][400][1000]; // 3D array para armazenar as solu��es parciais
int caminho[5][400][1000] = {0}; // 3D array para armazenar os caminhos escolhidos

// Fun��o recursiva para encontrar a solu��o �tima
int solucao(int i, int peso[], int volume[], int valor[], int capp, int capv, int n, string nome[], int caminho[][400][1000]) {
	// Caso base: Quando atingir o final da lista ou quando a capacidade for zero
	if (i >= n || capp <= 0 || capv <= 0) {
		return 0;
	}

	// Verifica se a solu��o j� foi calculada para evitar repeti��es
	if (matriz_solucao[i][capp][capv] != -1) {
		return matriz_solucao[i][capp][capv];
	}

	// Calcula a solu��o para n�o pegar a pedra atual (n�o escolher o item)
	int sol_1 = solucao(i + 1, peso, volume, valor, capp, capv, n, nome, caminho);

	// Inicializa a solu��o para pegar a pedra atual (escolher o item)
	int sol_2 = 0;

	// Verifica se � poss�vel pegar a pedra atual
	if (capp >= peso[i] and capv >= volume[i]) {
		// Calcula a solu��o para pegar a pedra atual e adiciona seu valor � solu��o
		sol_2 = solucao(i + 1, peso, volume, valor, capp - peso[i], capv - volume[i], n, nome, caminho) + valor[i];
		// Marca o caminho como escolhido
		caminho[i][capp][capv] = 1; // 1 para indicar que o item foi escolhido
	} else {
		// Marca o caminho como n�o escolhido
		caminho[i][capp][capv] = 0; // 0 para indicar que o item n�o foi escolhido
	}

	// Armazena o resultado m�ximo na matriz de solu��o para evitar repeti��es
	return matriz_solucao[i][capp][capv] = max(sol_1, sol_2);
}

int main() {
	// Inicializa��o dos dados
	int peso[5] = {263, 127, 254, 134, 111}; // Peso das pedras
	int volume[5] = {455, 521, 857, 65, 12}; // Volume das pedras
	int valor[5] = {500, 410, 320, 315, 280}; // Valor das pedras
	string nome[5] = {"Diamante", "Esmeralda", "Topazio", "Rubi", "Jade"}; // Nomes das pedras
	int capp = 400; // Capacidade m�xima de peso
	int capv = 1000; // Capacidade m�xima de volume
	const int n = 5; // N�mero total de pedras

	// Inicializa��o da matriz de solu��o com -1 para indicar que os valores ainda n�o foram calculados
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= capp; j++) {
			for (int k = 0; k <= capv; k++) {
				matriz_solucao[i][j][k] = -1;
			}
		}
	}

	// Chamada da fun��o para encontrar a solu��o �tima
	int resultado = solucao(0, peso, volume, valor, capp, capv, n, nome, caminho);

	// Impress�o das pedras selecionadas
	cout << "Pedras selecionadas:" << endl;
	for (int i = 0; i < n; i++) {
		if (caminho[i][capp][capv] == 1) {
			cout << nome[i] << endl;
		}
	}

	return 0;
}
