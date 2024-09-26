#include <iostream>
#include <string>
using namespace std;

// Declaração de matriz global para armazenar soluções parciais
int matriz_solucao[5][400][1000]; // 3D array para armazenar as soluções parciais
int caminho[5][400][1000] = {0}; // 3D array para armazenar os caminhos escolhidos

// Função recursiva para encontrar a solução ótima
int solucao(int i, int peso[], int volume[], int valor[], int capp, int capv, int n, string nome[], int caminho[][400][1000]) {
	// Caso base: Quando atingir o final da lista ou quando a capacidade for zero
	if (i >= n || capp <= 0 || capv <= 0) {
		return 0;
	}

	// Verifica se a solução já foi calculada para evitar repetições
	if (matriz_solucao[i][capp][capv] != -1) {
		return matriz_solucao[i][capp][capv];
	}

	// Calcula a solução para não pegar a pedra atual (não escolher o item)
	int sol_1 = solucao(i + 1, peso, volume, valor, capp, capv, n, nome, caminho);

	// Inicializa a solução para pegar a pedra atual (escolher o item)
	int sol_2 = 0;

	// Verifica se é possível pegar a pedra atual
	if (capp >= peso[i] and capv >= volume[i]) {
		// Calcula a solução para pegar a pedra atual e adiciona seu valor à solução
		sol_2 = solucao(i + 1, peso, volume, valor, capp - peso[i], capv - volume[i], n, nome, caminho) + valor[i];
		// Marca o caminho como escolhido
		caminho[i][capp][capv] = 1; // 1 para indicar que o item foi escolhido
	} else {
		// Marca o caminho como não escolhido
		caminho[i][capp][capv] = 0; // 0 para indicar que o item não foi escolhido
	}

	// Armazena o resultado máximo na matriz de solução para evitar repetições
	return matriz_solucao[i][capp][capv] = max(sol_1, sol_2);
}

int main() {
	// Inicialização dos dados
	int peso[5] = {263, 127, 254, 134, 111}; // Peso das pedras
	int volume[5] = {455, 521, 857, 65, 12}; // Volume das pedras
	int valor[5] = {500, 410, 320, 315, 280}; // Valor das pedras
	string nome[5] = {"Diamante", "Esmeralda", "Topazio", "Rubi", "Jade"}; // Nomes das pedras
	int capp = 400; // Capacidade máxima de peso
	int capv = 1000; // Capacidade máxima de volume
	const int n = 5; // Número total de pedras

	// Inicialização da matriz de solução com -1 para indicar que os valores ainda não foram calculados
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= capp; j++) {
			for (int k = 0; k <= capv; k++) {
				matriz_solucao[i][j][k] = -1;
			}
		}
	}

	// Chamada da função para encontrar a solução ótima
	int resultado = solucao(0, peso, volume, valor, capp, capv, n, nome, caminho);

	// Impressão das pedras selecionadas
	cout << "Pedras selecionadas:" << endl;
	for (int i = 0; i < n; i++) {
		if (caminho[i][capp][capv] == 1) {
			cout << nome[i] << endl;
		}
	}

	return 0;
}
