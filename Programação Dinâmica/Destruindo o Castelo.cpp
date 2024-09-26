// Bem parecido com o das pedras(em relação à prog. dinâmica)
#include <iostream>
#include <cstring>
using namespace std;

int memo[50][1000]; // Matriz para memoização.

int solucao(int res, int peso[], int danos[], int capacity, int n, int i) {
    // Verifica se o estado já foi calculado anteriormente
    if (i == n || capacity == 0)
        return 0;

    // Se o resultado já foi memorizado, retorna o valor armazenado.
    if (memo[i][capacity] != -1)
        return memo[i][capacity];

    // Passando para o próximo, caso acabe o anterior:
    if (peso[i] > capacity)
        return memo[i][capacity] = solucao(res, peso, danos, capacity, n, i + 1);

    // Calculando o máximo entre atirar com o projétil e não atirar:
    int atirar = danos[i] + solucao(res - danos[i], peso, danos, capacity - peso[i], n, i + 1);
    int nao_atirar = solucao(res, peso, danos, capacity, n, i + 1);
    return memo[i][capacity] = max(atirar, nao_atirar);
}

int main() {
    int num_testes;
    int n; // Número de projéteis.
    int danos[50]; // Poder de destruição do projétil.
    int capacity, res; // Capacidade de carga do canhão e resistência do castelo.
    int peso[50]; // Pesos dos projéteis.

    cin >> num_testes;

    while (num_testes--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> danos[i];
            cin >> peso[i];
        }
        cin >> capacity;
        cin >> res;

        // Inicializa a memoização com valores infinitos
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
