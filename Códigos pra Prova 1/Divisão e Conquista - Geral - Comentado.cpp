#include <iostream>
using namespace std;

// Fun��o de divis�o e conquista para encontrar o m�ximo em um array
int encontrar_maximo(int array[], int inicio, int fim) {
    // Caso base: quando h� apenas um elemento no array
    if (inicio == fim) {
        return array[inicio];
    }

    // Calcula o �ndice do meio do array
    int meio = (inicio + fim) / 2;

    // Encontra o m�ximo na metade esquerda do array
    int max_esquerda = encontrar_maximo(array, inicio, meio);

    // Encontra o m�ximo na metade direita do array
    int max_direita = encontrar_maximo(array, meio + 1, fim);

    // Retorna o m�ximo entre os m�ximos da metade esquerda e da metade direita
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

    // Encontra o m�ximo no array usando a fun��o de divis�o e conquista
    int maximo = encontrar_maximo(array, 0, tamanho - 1);

    // Imprime o m�ximo encontrado
    cout << "O elemento m�ximo no array �: " << maximo << endl;

    return 0;
}
