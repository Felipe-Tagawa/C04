#include <iostream>
#include <iomanip>
using namespace std;

// Definição da estrutura "pessoa", que contém as notas e a média de uma pessoa,
// bem como um ponteiro para o próximo elemento da lista.
struct pessoa {
    int n1, n2, n3, n4; // Notas de uma pessoa
    double media; // Média das notas
    pessoa* prox; // Ponteiro para o próximo elemento da lista
};

int main() {
    int n; // Variável para armazenar o número de pessoas
    cin >> n; // Leitura do número de pessoas

    // Alocação dinâmica de um array de "pessoa" com tamanho n
    pessoa* p = new pessoa[n];

    // Loop para ler as notas de cada pessoa e calcular sua média
    for (int i = 0; i < n; i++) {
        cin >> p[i].n1 >> p[i].n2 >> p[i].n3 >> p[i].n4; // Leitura das notas
        // Cálculo da média das notas
        p[i].media = (p[i].n1 + p[i].n2 + p[i].n3 + p[i].n4) / 4.0;
    }

    double media_geral = 0; // Variável para armazenar a média geral

    // Loop para calcular a média geral
    for (int i = 0; i < n; i++) {
        media_geral += p[i].media / n; // Adiciona a média da pessoa à média geral
    }

    // Alocação dinâmica de um novo elemento "pessoa" e atribuição de seu endereço ao ponteiro prox do primeiro elemento do array.
    (*p).prox = new pessoa;

    cout << fixed << setprecision(2); // Configura a saída para exibir duas casas decimais após o ponto
    cout << media_geral << endl; // Imprime a média geral

    // Liberação da memória alocada dinamicamente para o novo elemento "pessoa"
    delete (*p).prox;
    // Liberação da memória alocada dinamicamente para o array de "pessoa"
    delete p;

    return 0;
}
