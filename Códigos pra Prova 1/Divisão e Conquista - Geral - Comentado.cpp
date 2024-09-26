#include <iostream>
using namespace std;

// Função de divisão e conquista para encontrar o máximo em um array
int encontrar_maximo(int array[], int inicio, int fim) {
    // Caso base: quando há apenas um elemento no array
    if (inicio == fim) {
        return array[inicio];
    }

    // Calcula o índice do meio do array
    int meio = (inicio + fim) / 2;

    // Encontra o máximo na metade esquerda do array
    int max_esquerda = encontrar_maximo(array, inicio, meio);

    // Encontra o máximo na metade direita do array
    int max_direita = encontrar_maximo(array, meio + 1, fim);

    // Retorna o máximo entre os máximos da metade esquerda e da metade direita
    return max(max_esquerda, max_direita);
}

int main() {
    int tamanho;
    cout << "Digite o tamanho do array: ";
    cin >> tamanho;

    // Exemplo de array de inteiros
    int array[tamanho];
    cout << "Digite os elementos do array:" << endl;
    for (int i = 0; i < tamanho; ++i) {
        cin >> array[i];
    }

    // Encontra o máximo no array usando a função de divisão e conquista
    int maximo = encontrar_maximo(array, 0, tamanho - 1);

    // Imprime o máximo encontrado
    cout << "O elemento máximo no array é: " << maximo << endl;

    return 0;
}
