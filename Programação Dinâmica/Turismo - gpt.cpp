#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 100; // Número máximo de destinos
const int MAX_BUDGET = 1000; // Orçamento máximo para a viagem
const int MAX_TEMPO = 1000; // Tempo máximo disponível para a viagem

int memo[MAX_N][MAX_BUDGET][MAX_TEMPO];

int maxSatisfacao(int n, int budget, int tempo_max, int custo[], int tempo[], int satisfacao[][MAX_N], int i){
	if(i == n || budget == 0){
		return 0;
	}
	if(memo[i][budget][tempo_max] != -1){
		return memo[i][budget][tempo_max];
	}
	
	int nao_destino = maxSatisfacao(n, budget, tempo_max, custo, tempo, satisfacao, i + 1);
	int destino = 0;
	if(custo[i] <= budget and tempo[i] <= tempo_max){
		int satisfacao_atual = satisfacao[i][0]; // Supondo que a pontuação de satisfação para a primeira pessoa seja a relevante
		destino = satisfacao_atual + maxSatisfacao(n, budget - custo[i], tempo_max - tempo[i],
		 custo, tempo, satisfacao , i + 1);
	}
	return memo[i][budget][tempo_max] = max(nao_destino, destino);
}


int main(){
	
	int n; // destinos.
	int m; // número de pessoas.
	
	cin >> n >> m;
	
	int budget; // orçamento máximo para a viagem.
	int tempo_max;
	int custo[100], tempo[100], satisfacao[100][100];
	
	cin >> budget >> tempo_max;
	
	for(int i = 0; i < n; i++){
		
		cin >> custo[i] >> tempo[i];
		for(int j = 0; j < m; j++){
			cin >> satisfacao[i][j];
		}
	}
	
	memset(memo, -1, sizeof(memo));
	cout << "Maxima satisfacao : " << maxSatisfacao(n, budget, tempo_max, custo, tempo, satisfacao, 0);
	
	return 0;
}