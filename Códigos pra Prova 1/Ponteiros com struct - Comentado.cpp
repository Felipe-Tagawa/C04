// Inclui a biblioteca iostream para entrada e sa�da de dados.
#include <iostream>
using namespace std;

// Define a estrutura "implante" para representar informa��es sobre os implantes.
struct implante{
    string nome; // Nome do implante
    string fabricante; // Fabricante do implante
    int tier; // N�vel do implante
    float psicose; // Taxa de psicose do implante
};

// Fun��o principal
int main(){
    // Declara��o de vari�veis
    float m = 0; // Vari�vel para armazenar a soma das taxas de psicose
    int n; // Vari�vel para armazenar a quantidade de implantes a serem registrados
    cin >> n; // Leitura da quantidade de implantes

    // Aloca��o din�mica de um array de "implante" com tamanho n
    implante *vetor = new implante[n];
    implante *aux = vetor; // Ponteiro auxiliar para percorrer o array

    // Loop para registrar os dados de cada implante
    for(int i = 0; i < n; i++){
        // Leitura do nome e fabricante do implante
        getline(cin >> ws, aux->nome);
        getline(cin >> ws, aux->fabricante);
        // Leitura do n�vel e taxa de psicose do implante
        cin >> aux->tier >> aux->psicose;
        aux++; // Move o ponteiro auxiliar para o pr�ximo elemento do array
    }

    // Loop para calcular a soma das taxas de psicose
    for(int i = 0; i < n; i++){
        m += vetor[i].psicose; // Adiciona a taxa de psicose do implante � soma
    }

    // Verifica se a soma das taxas de psicose ultrapassa 60%
    if(m > 60.0){
        // Imprime mensagem de alerta caso ultrapasse 60%
        cout << "Alerta! Uma recompensa de 50.000 edinhos foi colocada pela sua cabe�a. Voc� se tornou um Ciberpsicopata." << endl;
    }
    else{
        // Imprime mensagem de sucesso caso n�o ultrapasse 60%
        cout << "Vamos tchum! Temos uma cidade pra conquistar!" << endl;
    }

    // Libera a mem�ria alocada dinamicamente para o array de implantes
    delete []vetor;

    // Retorna 0 para indicar que o programa foi executado com sucesso
    return 0;
}
