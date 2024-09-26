#include <iostream>
#include <string>
using namespace std;

// Fun��o de busca bin�ria para encontrar uma pista em um array de ilhas
int busca_binaria(string ilhas[], int inicio, int fim, string pista) {
    // Calcula o �ndice do meio do array
    int meio = (inicio + fim) / 2;

    // Verifica se a pista est� no meio do array
    if (ilhas[meio] == pista) {
        return meio; // Retorna o �ndice se a pista for encontrada no meio
    } else {
        // Se a pista n�o estiver no meio, verifica se est� na metade superior ou inferior do array
        if (ilhas[meio] < pista) {
            return busca_binaria(ilhas, meio + 1, fim, pista); // Busca na metade superior
        } else {
            return busca_binaria(ilhas, inicio, meio - 1, pista); // Busca na metade inferior
        }
    }
    return -1; // Retorna -1 se a pista n�o for encontrada
}

int main() {
    // Declara��o de vari�veis
    string ilhas[7]; // Array de ilhas
    int n = 0; // Vari�vel para armazenar o n�mero de ilhas inseridas
    string buscado; // Pista a ser buscada

    // Loop para inserir os nomes das ilhas no array
    for(int i = 0; i < 7; i++) {
        getline(cin >> ws, ilhas[i]); // Leitura do nome da ilha
        n = i; // Atualiza o n�mero de ilhas inseridas
    }

    getline(cin >> ws, buscado); // Leitura da pista a ser buscada

    // Chamada da fun��o de busca bin�ria para encontrar a pista
    int indice = busca_binaria(ilhas, 0, n - 1, buscado);

    // Verifica se a pista foi encontrada e imprime o �ndice correspondente
    if (indice != -1) {
        cout << "Indice da pista encontrada: " << indice << endl;
    } else {
        cout << "Indice da pista encontrada: -1" << endl; // Se a pista n�o for encontrada, imprime -1
    }

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
