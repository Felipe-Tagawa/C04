// Usada para problemas combinatórios(otimização).
// Não pode ser usada para qualquer tipo de problema.
#include <iostream>
using namespace std;

int matriz_solucao[n][capp][capv]; // 3 dimensões, n sendo o número de pedras, por exemplo.
int solucao (int i, int peso[i], int volume[i], int valor[i], int capp, int capv, int n){ //capp sendo a capacidade de peso atual 
	if( i >= n || capp <= 0 || capv <= 0) {
		return 0;
	}
	if(matriz_solucao[i][capp][capv] != -1){ // -1 são todos os valores que ainda não foram calculados no programa.
		return matriz_solucao[i][capp][capv]; // Evita repetir os caminhos já calculados.
	}
	
	sol_2 = 0;
	// Solução da esquerda(não pegar as pedras):
	sol_1 = solucao(i++, capp, capv, n);
	// Solução da direita (pegar as pedras, somar com o valor da pedra):
	if(capp >= peso[i] and capv >= volume[i]) {
		sol_2 = solucao(i++, capp - peso[i], capv - volume[i], n) + valor[i];
	}
	a = max(sol_1, sol_2);
	matriz_solucao[i][capp][capv] = a; // Armazenando o resultado máximo em uma matriz para evitar repetições.
	return a;
}

int main() {


	return 0;
}
