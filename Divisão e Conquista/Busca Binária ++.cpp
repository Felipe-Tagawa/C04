#include <iostream>
using namespace std;

int busca_bin_pp(int valores[], int buscado, int inicio, int fim) {
	int metade;
	while(inicio <= fim) {
		metade = (inicio + fim) / 2;
		if(buscado == valores[metade]) {
			return metade;
		} else {
			if(buscado > valores[metade]) {
				inicio = metade + 1;
			} else {
				fim = metade - 1;
			}
		}
	}
	return -1;
}


int main() {

	int n; // Tamanho do Vetor.
	int buscado; // Valor a ser buscado na busca binária.

	cin >> n;

	int valores[n];

	for(int i = 0; i < n; i++) {
		cin >> valores[i];
	}

	cin >> buscado;

	int result = busca_bin_pp(valores, buscado, 0, n - 1);

	if(result != -1) {
		cout << result << endl;
	} else {
		cout << "-1" << endl;
	}

	return 0;
}
