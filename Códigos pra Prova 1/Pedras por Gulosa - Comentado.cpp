#include <iostream>
using namespace std;

// Definição da estrutura "PedraPreciosa" para representar uma pedra preciosa
struct PedraPreciosa {
	int quantidade; // Quantidade disponível da pedra
	int volume; // Volume da pedra
	int preco; // Preço da pedra
	int peso; // Peso da pedra
	string nome; // Nome da pedra
};

// Função para calcular as pedras preciosas a serem selecionadas
void calcular_pedras(PedraPreciosa pedras[], int volume_max, int peso_max, int n, string & pedras_selecionadas) {
	pedras_selecionadas = ""; // Inicializa a string de pedras selecionadas

	int atual_vol = 0; // Inicializa o volume total atual
	int atual_peso = 0; // Inicializa o peso total atual

	// Encontra a pedra preciosa com o maior preço enquanto houver espaço no volume e no peso máximo
	while (atual_vol < volume_max and atual_peso < peso_max) {
		int pos = -1; // Inicializa a posição da pedra selecionada como -1 (nenhuma pedra selecionada ainda)
		int max_preco = 0; // Inicializa o maior preço como 0

		// Itera sobre todas as pedras para encontrar a pedra com o maior preço
		for (int i = 0; i < n; i++) {
			// Verifica se há pedras disponíveis, se o preço é maior que o máximo até agora
			// e se adicionar essa pedra não ultrapassa o peso máximo
			if (pedras[i].quantidade > 0 and pedras[i].preco > max_preco and (atual_peso + pedras[i].peso) <= peso_max) {
				pos = i; // Atualiza a posição da pedra selecionada
				max_preco = pedras[i].preco; // Atualiza o maior preço
			}
		}

		// Verifica se nenhuma pedra foi selecionada
		if (pos == -1) {
			break; // Sai do loop, pois não há mais pedras disponíveis
		}

		// Adiciona o nome da pedra selecionada à lista de pedras selecionadas
		pedras_selecionadas += pedras[pos].nome + " ";

		// Atualiza o volume e o peso total
		atual_vol += pedras[pos].volume;
		atual_peso += pedras[pos].peso;

		// Atualiza a quantidade restante da pedra selecionada
		pedras[pos].quantidade--;
	}
}

int main() {
	PedraPreciosa pedras[5]; // Declaração de um array de pedras preciosas
	const int volume_max = 1000; // Volume máximo permitido
	const int peso_max = 400; // Peso máximo permitido
	string pedras_selecionadas; // String para armazenar os nomes das pedras selecionadas

	// Entradas fornecidas: quantidade, volume, preço, peso e nome de cada pedra preciosa
	pedras[0] = {10, 455, 500, 263, "Diamante"};
	pedras[1] = {20, 521, 410, 127, "Esmeralda"};
	pedras[2] = {25, 857, 320, 134, "Topázio"};
	pedras[3] = {20, 65, 315, 134, "Rubi"};
	pedras[4] = {30, 12, 280, 111, "Jade"};

	// Chamada da função para calcular as pedras preciosas a serem selecionadas
	calcular_pedras(pedras, volume_max, peso_max, 5, pedras_selecionadas);

	// Impressão das pedras preciosas selecionadas
	cout << "Pedras preciosas selecionadas: " << pedras_selecionadas << endl;

	return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
