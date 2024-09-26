// Bem parecido com o das pedras(em rela��o � prog. din�mica)
#include <iostream>
#include <cstring>
using namespace std;

int memo[50][1000]; // Matriz para memoiza��o.

int solucao(int res, int peso[], int danos[], int capacity, int n, int i) {
    // Verifica se o estado j� foi calculado anteriormente
    if (i == n || capacity == 0)
        return 0;

    // Se o resultado j� foi memorizado, retorna o valor armazenado.
    if (memo[i][capacity] != -1)
        return memo[i][capacity];

    // Passando para o pr�ximo, caso acabe o anterior:
    if (peso[i] > capacity)
        return memo[i][capacity] = solucao(res, peso, danos, capacity, n, i + 1);

    // Calculando o m�ximo entre atirar com o proj�til e n�o atirar:
    int atirar = danos[i] + solucao(res - danos[i], peso, danos, capacity - peso[i], n, i + 1);
    int nao_atirar = solucao(res, peso, danos, capacity, n, i + 1);
    return memo[i][capacity] = max(atirar, nao_atirar);
}

int main() {
    int num_testes;
    int n; // N�mero de proj�teis.
    int danos[50]; // Poder de destrui��o do proj�til.
    int capacity, res; // Capacidade de carga do canh�o e resist�ncia do castelo.
    int peso[50]; // Pesos dos proj�teis.

    cin >> num_testes;

    while (num_testes--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> danos[i];
            cin >> peso[i];
        }
        cin >> capacity;
        cin >> res;

        // Inicializa a memoiza��o com valores infinitos
        memset(memo, -1, sizeof(memo));

        int result = solucao(res, peso, danos, capacity, n, 0);
      
        if (result >= res) {
            cout << "Missao completada com sucesso" << endl;
        } else {
            cout << "Falha na missao" << endl;
        }
    }

    return 0;
}
