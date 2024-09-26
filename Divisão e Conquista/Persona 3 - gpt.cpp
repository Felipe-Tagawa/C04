#include <iostream>
using namespace std;

struct Persona {
    int poder;
    string nome;
};

int busca_bin_persona(Persona persona[], int inicio, int fim, int poder_desejado) {
        int meio = (inicio + fim) / 2;
        if (persona[meio].poder == poder_desejado) {
            return meio;
        }
        else {
		if (persona[meio].poder < poder_desejado) {
			return busca_bin_persona(persona, meio + 1, fim, poder_desejado);
		} else {
			return busca_bin_persona(persona, inicio, meio - 1, poder_desejado);
		}
	}
	return -1;
}

int main() {
    int n; // Número de personagens jogáveis.
    cout << "Digite o numero de personagens jogaveis: ";
    cin >> n;

    Persona persona[n];

    for (int i = 0; i < n; i++) {
        cout << "Digite o nome e o poder do personagem " << i + 1 << ": ";
        cin >> persona[i].nome >> persona[i].poder;
    }

    int poder_desejado;
    cout << "Digite o poder desejado: ";
    cin >> poder_desejado;

    int pers = busca_bin_persona(persona, 0, n - 1, poder_desejado);

    if (pers != -1) {
        cout << "O personagem com este nível de poder é: " << persona[pers].nome << endl;
    } else {
        cout << "Personagem não encontrado." << endl;
    }

    return 0;
}
