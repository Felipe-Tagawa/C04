/*

Aula 01:

Força Bruta:

Avalia (quase) todas as possibilidades, retornando a melhor.
Busca Sequencial(S/ ordenação do conjunto de dados);
Demanda muito tempo, nem sempre sendo a melhor.

Estratégia Gulosa:

Escolhe o objeto mais valioso visto.
Esquece aquilo que já foi analisado.
Bem eficiente no tempo.
Nem sempre retorna o melhor resultado.


Resolver o problema das pedras preciosas pelos dois métodos.
*/


#include <iostream>
using namespace std;

struct PedraPreciosa {
	string nome;
	int volume;
	int peso;
	int preco;
};

void combinacao_otima(PedraPreciosa pedras[], int n, int volume_max, int peso_max) {
	int melhor_lucro = 0;
	int combinacao_otima[5];

	// Gerando todas as combinações possíveis de pedras preciosas(Bem parecido com o do caminhão, mas com quantidade = 1)
	for (int diamante = 0; diamante <= 1; diamante++) {
		for (int esmeralda = 0; esmeralda <= 1; esmeralda++) {
			for (int topazio = 0; topazio <= 1; topazio++) {
				for (int rubi = 0; rubi <= 1; rubi++) {
					for (int jade = 0; jade <= 1; jade++) {
						int volume_total = diamante * pedras[0].volume + esmeralda * pedras[1].volume +
										   topazio * pedras[2].volume + rubi * pedras[3].volume +
										   jade * pedras[4].volume;
						int peso_total = diamante * pedras[0].peso + esmeralda * pedras[1].peso +
										 topazio * pedras[2].peso + rubi * pedras[3].peso +
										 jade * pedras[4].peso;

						if (volume_total <= volume_max and peso_total <= peso_max) {
							int lucro_total = diamante * pedras[0].preco + esmeralda * pedras[1].preco +
											  topazio * pedras[2].preco + rubi * pedras[3].preco +
											  jade * pedras[4].preco;
							// Verificar se é a melhor combinação até agora
							if (lucro_total > melhor_lucro) {
								melhor_lucro = lucro_total;
								combinacao_otima[0] = diamante;
								combinacao_otima[1] = esmeralda;
								combinacao_otima[2] = topazio;
								combinacao_otima[3] = rubi;
								combinacao_otima[4] = jade;
							}
						}
					}
				}
			}
		}
	}

	cout << "A melhor combinação de pedras preciosas para lucro máximo: " << endl;
	string nomes_pedras[] = {"Diamante", "Esmeralda", "Topazio", "Rubi", "Jade"};
	for (int i = 0; i < n; i++) {
		if (combinacao_otima[i] == 1) {
			cout << nomes_pedras[i] << ": Escolhida" << endl;
		} else {
			cout << nomes_pedras[i] << ": Nao escolhida" << endl;
		}
	}
	cout << "Lucro maximo: " << melhor_lucro << endl;
	// n fatorial( 5 nesse caso, pois 5 pedras diferentes), dependendo das escolhas das pedras, fazendo as combinações.
	// Muito mais lenta.
	/*
	
	int solucao (int i, int vetores(3 vetores -> peso, volume e preço), int capp, int capv, int n) capp sendo a capacidade de peso atual{
		if( i >= n || capp <= 0 || capv <= 0){
			return 0;
		}
		sol_2 = 0;
		// Solução da esquerda(não pegar as pedras):
		sol_1 = solucao(i++, capp, capv, n);
		// Solução da direita (pegar as pedras, somar com o valor da pedra):
		if(capp >= peso[i] and capv >= volume[i]){
		sol_2 = solucao(i++, capp - peso[i], capv - volume[i], n) + valor[i];
		}	
		return max(sol_1, sol_2);
	}
	
	
	
	*/
}

int main() {
	const int volume_max = 1000;
	const int peso_max = 400;
	PedraPreciosa pedras[] = {
		{"Diamante", 455, 263, 500},
		{"Esmeralda", 521, 127, 410},
		{"Topázio", 857, 134, 320},
		{"Rubi", 65, 134, 315},
		{"Jade", 12, 111, 280}
	};

	combinacao_otima(pedras, 5, volume_max, peso_max);

	return 0;
}

// Abordagem gulosa:

#include <iostream>
using namespace std;

struct PedraPreciosa {
	int quantidade, volume, preco, peso;
	string nome;
};

void calcular_pedras(PedraPreciosa pedras[], int volume_max, int peso_max, int n, string & pedras_selecionadas) {
	pedras_selecionadas = "";

	int atual_vol = 0;
	int atual_peso = 0;

	// Encontrar a pedra preciosa com o maior preço
	while (atual_vol < volume_max and atual_peso < peso_max) {
		int pos = 0;
		int max_preco = 0;

		for (int i = 0; i < n; i++) {
			if (pedras[i].quantidade > 0 and pedras[i].preco > max_preco and (atual_peso + pedras[i].peso) <= peso_max) {
				pos = i;
				max_preco = pedras[i].preco;
			}
		}

		if (pos == -1) {
			break; // Nenhuma pedra preciosa restante
		}

		// Adicionar o nome da pedra preciosa selecionada
		pedras_selecionadas += pedras[pos].nome + " ";

		// Atualizar o volume e peso total
		atual_vol += pedras[pos].volume;
		atual_peso += pedras[pos].peso;

		// Atualizar a quantidade restante da pedra preciosa selecionada
		pedras[pos].quantidade--;
	}
}

int main() {
	PedraPreciosa pedras[5];
	const int volume_max = 1000;
	const int peso_max = 400;
	string pedras_selecionadas;

	// Entradas fornecidas
	pedras[0] = {10, 455, 500, 263, "Diamante"};
	pedras[1] = {20, 521, 410, 127, "Esmeralda"};
	pedras[2] = {25, 857, 320, 134, "Topázio"};
	pedras[3] = {20, 65, 315, 134, "Rubi"};
	pedras[4] = {30, 12, 280, 111, "Jade"};

	calcular_pedras(pedras, volume_max, peso_max, 5, pedras_selecionadas);

	cout << "Pedras preciosas selecionadas: " << pedras_selecionadas << endl;

	return 0;
	// Abordagem : n unidades de tempo, pois vai ter que ler pelo menos uma vez, parando com uma condição(ex. : capacidade).
}

/* OU 
#include <iostream>
using namespace std;

struct Pedra {
    string nome;
    int volume;
    int peso;
    int valor;
};

Pedra* solucao(int n, Pedra pedras[], int cap_peso, int cap_volume, int& num_pedras_selecionadas) {
    Pedra* pedras_selecionadas = new Pedra[n]; 
    int valor_total = 0;
    num_pedras_selecionadas = 0;

    for (int i = 0; i < n; i++) {
        if (cap_peso >= pedras[i].peso && cap_volume >= pedras[i].volume) {
            cap_peso -= pedras[i].peso;
            cap_volume -= pedras[i].volume;
            valor_total += pedras[i].valor;
            pedras_selecionadas[num_pedras_selecionadas] = pedras[i];
            num_pedras_selecionadas++;
        }
    }
    return pedras_selecionadas;
}

int main() {
    const int n = 5;
    const int cap_peso = 400;
    const int cap_volume = 1000;
    Pedra pedras[] = {
        {"Diamante", 455, 263, 500},
        {"Esmeralda", 521, 127, 410},
        {"Topázio", 857, 134, 320},
        {"Rubi", 65, 134, 315},
        {"Jade", 12, 111, 280}
    };

    int num_pedras_selecionadas = 0;
    Pedra* escolha = solucao(n, pedras, cap_peso, cap_volume, num_pedras_selecionadas);

    for (int i = 0; i < num_pedras_selecionadas; i++) {
        cout << escolha[i].nome << endl;
    }

    return 0;
}
*/

