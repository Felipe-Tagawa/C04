#include <iostream>
#include <cstring>
using namespace std;

int memo[50][100];

int solucao(int n, int i, int peso[], int poder[], int resist, int carga){
	if(i == n || carga == 0){
		return 0;
	}
	
	if(memo[i][carga] != -1){
		return memo[i][carga];
	}
	
	if(peso[i] > carga){
		return memo[i][carga] = solucao(n, i + 1, peso, poder, resist, carga);
	}
	
	int atirar = solucao(n, i + 1, peso, poder, resist - poder[i], carga - peso[i]) + poder[i];
	int nao_atirar = solucao(n, i + 1, peso, poder, resist, carga);
	return memo[i][carga] = max(atirar, nao_atirar);
	
}

int main(){
	
	int num_teste, n, poder[100], peso[100], carga, resist;
	
	cin >> num_teste;
	
	while(num_teste--){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> poder[i];
			cin >> peso[i];
		}
		cin >> carga >> resist;
		
		memset(memo, -1, sizeof(memo));
		int result = solucao(n, 0, peso, poder, resist, carga);
		
		if(result >= resist){
			cout << "Missao completada com sucesso" << endl;
		}
		else{
			cout << "Falha na missao" << endl;
		}
	}
	
	return 0;
}