#include <iostream>
#include <string>
using namespace std;

int busca_binaria(string ilhas[], int inicio, int fim, string pista) {

	int meio = (inicio + fim) / 2;

	if (ilhas[meio] == pista) {
		return meio;
	} else {
		if (ilhas[meio] < pista) {
			return busca_binaria(ilhas, meio + 1, fim, pista);
		} else {
			return busca_binaria(ilhas, inicio, meio - 1, pista);
		}
	}
	return -1;
}

int main() {

	string ilhas[7];
	int i = 0;
	int n = 0;
	string buscado;
	for(int i = 0; i < 7; i++) {
		getline(cin >> ws, ilhas[i]);
		n = i;
	}

	getline(cin >> ws, buscado);

	int indice = busca_binaria(ilhas, 0, n - 1, buscado);

	if (indice != -1) {
		cout << "Indice da pista encontrada: " << indice << endl;
	} else {
		cout << "Indice da pista encontrada: -1" << endl;
	}

	return 0;
}
