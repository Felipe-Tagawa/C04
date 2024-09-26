#include <iostream>
#include <cstring> // Para a fun��o memset
using namespace std;

// Defini��o do tamanho m�ximo da matriz de memoiza��o
const int MAX_SIZE = 100;

// Matriz de memoiza��o global
int memo[MAX_SIZE][MAX_SIZE];

// Fun��o de memoiza��o para resolver um problema espec�fico
int memoization(int i, int j, int values[], int n) {
    // Verifica se o valor j� foi calculado
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // Caso base: quando n�o h� mais escolhas
    if (i == 0 || j == 0) {
        return 0;
    }

    // Caso a escolha atual seja maior que o limite dispon�vel
    if (values[i] > j) {
        // N�o escolhe o item atual
        return memo[i][j] = memoization(i - 1, j, values, n);
    }

    // Calcula o m�ximo entre escolher ou n�o escolher o item atual
    int choose = values[i] + memoization(i - 1, j - values[i], values, n); // Escolhe o item atual
    int notChoose = memoization(i - 1, j, values, n); // N�o escolhe o item atual

    // Armazena o resultado na matriz de memoiza��o
    return memo[i][j] = max(choose, notChoose);
}

int main() {
    int n; // N�mero total de itens
    cout << "Digite o n�mero total de itens: ";
    cin >> n;

    int values[n + 1]; // Valores dos itens (�ndice 0 � ignorado)
    cout << "Digite os valores dos itens: ";
    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
    }

    int capacity; // Capacidade da mochila
    cout << "Digite a capacidade da mochila: ";
    cin >> capacity;

    // Inicializa a matriz de memoiza��o com -1
    memset(memo, -1, sizeof(memo));

    int maxValue = memoization(n, capacity, values, n);

    cout << "M�ximo valor obtido: " << maxValue << endl;

    return 0;
}
