#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL,"");
    const int n = 6; // Número de estações
    int a[2][6] = {{7, 9, 3, 4, 8, 4}, {8, 5, 6, 4, 5, 7}}; // Tempo por estação
    int t[2][5] = {{2, 3, 1, 3, 4}, {2, 1, 2, 2, 1}}; // Tempo de troca de linha
    int e[2] = {2, 4}; // Tempos de entrada
    int x[2] = {3, 2}; // Tempos de saída

    int f1[n], f2[n];

    f1[0] = e[0] + a[0][0];
    f2[0] = e[1] + a[1][0];

    for (int j = 1; j < n; j++) {
        if ((f1[j - 1] + a[0][j]) <= (f2[j - 1] + t[1][j - 1] + a[0][j])) {
            f1[j] = f1[j - 1] + a[0][j];
        } else {
            f1[j] = f2[j - 1] + t[1][j - 1] + a[0][j];
        }

        if ((f2[j - 1] + a[1][j]) <= (f1[j - 1] + t[0][j - 1] + a[1][j])) {
            f2[j] = f2[j - 1] + a[1][j];
        } else {
            f2[j] = f1[j - 1] + t[0][j - 1] + a[1][j];
        }
    }

    int fastest_time = min(f1[n - 1] + x[0], f2[n - 1] + x[1]);
    cout << "O tempo mais rápido é: " << fastest_time << endl;

    return 0;
}

/*
Usando a memoização:

#include <iostream>
#include <cstring> // Para usar memset

using namespace std;

const int n = 6; // Número de estações
int a[2][6] = {{7, 9, 3, 4, 8, 4}, {8, 5, 6, 4, 5, 7}}; // Tempo por estação (valores fictícios)
int t[2][5] = {{2, 3, 1, 3, 4}, {2, 1, 2, 2, 1}}; // Tempo de troca de linha (valores fictícios)
int e[2] = {2, 4}; // Tempos de entrada (valores fictícios)
int x[2] = {3, 2}; // Tempos de saída (valores fictícios)
int f1[n], f2[n]; // Matrizes para memorização

int montagem(int linha, int j) {
    if (j == 0) {
        return e[linha] + a[linha][0];
    }

    if (linha == 0) {
        if (f1[j] != -1) {
            return f1[j];
        }
        f1[j] = min(montagem(0, j - 1) + a[0][j], montagem(1, j - 1) + t[1][j - 1] + a[0][j]);
        return f1[j];
    } else {
        if (f2[j] != -1) {
            return f2[j];
        }
        f2[j] = min(montagem(1, j - 1) + a[1][j], montagem(0, j - 1) + t[0][j - 1] + a[1][j]);
        return f2[j];
    }
}

int main() {
    memset(f1, -1, sizeof(f1));
    memset(f2, -1, sizeof(f2));

    int fastest_time = min(montagem(0, n - 1) + x[0], montagem(1, n - 1) + x[1]);
    cout << "O tempo mais rápido é: " << fastest_time << endl;

    return 0;
}

OU

#include <iostream>
#include <cstring> // Para usar memset

using namespace std;

const int num_estacoes = 6; // Número de estações
int tempo_estacao[2][6] = {{7, 9, 3, 4, 8, 4}, {8, 5, 6, 4, 5, 7}}; // Tempo por estação (valores fictícios)
int tempo_troca[2][5] = {{2, 3, 1, 3, 4}, {2, 1, 2, 2, 1}}; // Tempo de troca de linha (valores fictícios)
int tempo_entrada[2] = {2, 4}; // Tempos de entrada (valores fictícios)
int tempo_saida[2] = {3, 2}; // Tempos de saída (valores fictícios)
int tempo_minimo_linha1[num_estacoes], tempo_minimo_linha2[num_estacoes]; // Matrizes para memorização

int montagem(int linha, int j) {
    if (j == 0) {
        return tempo_entrada[linha] + tempo_estacao[linha][0];
    }

    if (linha == 0) {
        if (tempo_minimo_linha1[j] != -1) {
            return tempo_minimo_linha1[j];
        }
        tempo_minimo_linha1[j] = min(montagem(0, j - 1) + tempo_estacao[0][j], montagem(1, j - 1) + tempo_troca[1][j - 1] + tempo_estacao[0][j]);
        return tempo_minimo_linha1[j];
    } else {
        if (tempo_minimo_linha2[j] != -1) {
            return tempo_minimo_linha2[j];
        }
        tempo_minimo_linha2[j] = min(montagem(1, j - 1) + tempo_estacao[1][j], montagem(0, j - 1) + tempo_troca[0][j - 1] + tempo_estacao[1][j]);
        return tempo_minimo_linha2[j];
    }
}

int main() {
    memset(tempo_minimo_linha1, -1, sizeof(tempo_minimo_linha1));
    memset(tempo_minimo_linha2, -1, sizeof(tempo_minimo_linha2));

    int tempo_minimo_total = min(montagem(0, num_estacoes - 1) + tempo_saida[0], montagem(1, num_estacoes - 1) + tempo_saida[1]);
    cout << "O tempo mais rápido é: " << tempo_minimo_total << endl;

    return 0;
}

*/
