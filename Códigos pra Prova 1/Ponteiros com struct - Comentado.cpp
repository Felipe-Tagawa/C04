// Inclui a biblioteca iostream para entrada e saída de dados.
#include <iostream>
using namespace std;

// Define a estrutura "implante" para representar informações sobre os implantes.
struct implante{
    string nome; // Nome do implante
    string fabricante; // Fabricante do implante
    int tier; // Nível do implante
    float psicose; // Taxa de psicose do implante
};

// Função principal
int main(){
    // Declaração de variáveis
    float m = 0; // Variável para armazenar a soma das taxas de psicose
    int n; // Variável para armazenar a quantidade de implantes a serem registrados
    cin >> n; // Leitura da quantidade de implantes

    // Alocação dinâmica de um array de "implante" com tamanho n
    implante *vetor = new implante[n];
    implante *aux = vetor; // Ponteiro auxiliar para percorrer o array

    // Loop para registrar os dados de cada implante
    for(int i = 0; i < n; i++){
        // Leitura do nome e fabricante do implante
        getline(cin >> ws, aux->nome);
        getline(cin >> ws, aux->fabricante);
        // Leitura do nível e taxa de psicose do implante
        cin >> aux->tier >> aux->psicose;
        aux++; // Move o ponteiro auxiliar para o próximo elemento do array
    }

    // Loop para calcular a soma das taxas de psicose
    for(int i = 0; i < n; i++){
        m += vetor[i].psicose; // Adiciona a taxa de psicose do implante à soma
    }

    // Verifica se a soma das taxas de psicose ultrapassa 60%
    if(m > 60.0){
        // Imprime mensagem de alerta caso ultrapasse 60%
        cout << "Alerta! Uma recompensa de 50.000 edinhos foi colocada pela sua cabeça. Você se tornou um Ciberpsicopata." << endl;
    }
    else{
        // Imprime mensagem de sucesso caso não ultrapasse 60%
        cout << "Vamos tchum! Temos uma cidade pra conquistar!" << endl;
    }

    // Libera a memória alocada dinamicamente para o array de implantes
    delete []vetor;

    // Retorna 0 para indicar que o programa foi executado com sucesso
    return 0;
}
