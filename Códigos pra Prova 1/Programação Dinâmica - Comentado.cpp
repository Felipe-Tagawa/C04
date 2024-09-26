#include <iostream>
#include <cstring> // Para a função memset
using namespace std;

// Definição do tamanho máximo da matriz de memoização
const int MAX_SIZE = 100;

// Matriz de memoização global
int memo[MAX_SIZE][MAX_SIZE];

// Função de memoização para resolver um problema específico
int memoization(int i, int j, int values[], int n) {
    // Verifica se o valor já foi calculado
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // Caso base: quando não há mais escolhas
    if (i == 0 || j == 0) {
        return 0;
    }

    // Caso a escolha atual seja maior que o limite disponível
    if (values[i] > j) {
        // Não escolhe o item atual
        return memo[i][j] = memoization(i - 1, j, values, n);
    }

    // Calcula o máximo entre escolher ou não escolher o item atual
    int choose = values[i] + memoization(i - 1, j - values[i], values, n); // Escolhe o item atual
    int notChoose = memoization(i - 1, j, values, n); // Não escolhe o item atual

    // Armazena o resultado na matriz de memoização
    return memo[i][j] = max(choose, notChoose);
}

int main() {
    int n; // Número total de itens
    cout << "Digite o número total de itens: ";
    cin >> n;

    int values[n + 1]; // Valores dos itens (índice 0 é ignorado)
    cout << "Digite os valores dos itens: ";
    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
    }

    int capacity; // Capacidade da mochila
    cout << "Digite a capacidade da mochila: ";
    cin >> capacity;

    // Inicializa a matriz de memoização com -1
    memset(memo, -1, sizeof(memo));

    int maxValue = memoization(n, capacity, values, n);

    cout << "Máximo valor obtido: " << maxValue << endl;

    return 0;
}
