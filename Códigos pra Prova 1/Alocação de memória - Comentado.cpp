#include <iostream>
#include <iomanip>
using namespace std;

// Defini��o da estrutura "pessoa", que cont�m as notas e a m�dia de uma pessoa,
// bem como um ponteiro para o pr�ximo elemento da lista.
struct pessoa {
    int n1, n2, n3, n4; // Notas de uma pessoa
    double media; // M�dia das notas
    pessoa* prox; // Ponteiro para o pr�ximo elemento da lista
};

int main() {
    int n; // Vari�vel para armazenar o n�mero de pessoas
    cin >> n; // Leitura do n�mero de pessoas

    // Aloca��o din�mica de um array de "pessoa" com tamanho n
    pessoa* p = new pessoa[n];

    // Loop para ler as notas de cada pessoa e calcular sua m�dia
    for (int i = 0; i < n; i++) {
        cin >> p[i].n1 >> p[i].n2 >> p[i].n3 >> p[i].n4; // Leitura das notas
        // C�lculo da m�dia das notas
        p[i].media = (p[i].n1 + p[i].n2 + p[i].n3 + p[i].n4) / 4.0;
    }

    double media_geral = 0; // Vari�vel para armazenar a m�dia geral

    // Loop para calcular a m�dia geral
    for (int i = 0; i < n; i++) {
        media_geral += p[i].media / n; // Adiciona a m�dia da pessoa � m�dia geral
    }

    // Aloca��o din�mica de um novo elemento "pessoa" e atribui��o de seu endere�o ao ponteiro prox do primeiro elemento do array.
    (*p).prox = new pessoa;

    cout << fixed << setprecision(2); // Configura a sa�da para exibir duas casas decimais ap�s o ponto
    cout << media_geral << endl; // Imprime a m�dia geral

    // Libera��o da mem�ria alocada dinamicamente para o novo elemento "pessoa"
    delete (*p).prox;
    // Libera��o da mem�ria alocada dinamicamente para o array de "pessoa"
    delete p;

    return 0;
}
