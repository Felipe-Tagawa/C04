#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct gladiador {

	string nome;
	int forca;
	int habilidade;
	int idade;
	int vida;
	int dano;
};

bool combate (gladiador & g1, gladiador & g2) {
	while(g1.vida > 0 && g2.vida > 0) { // 5*n
		int dano_g1 = g1.forca + pow(2 , g1.habilidade); // 5*n
		g2.vida -= dano_g1; // Gladiador 1 dando dano. // 3*n
		if (g2.vida <= 0) { // 2*n
			return true; // Gladiador 1 vitorioso
		}
		int dano_g2 = g2.forca + pow(2, g2.habilidade); // 5 unidade de tempo.
		g1.vida -= dano_g2; // Gladiador 2 dando dano. // 3 unidade de tempo.
	}
	return g2.vida <= 0; // Gladiador 2 vitorioso.
}


int main() {

	gladiador gladiadores[5];

	for(int i = 0; i < 5; i++) {
		cin.ignore();
		cin >> gladiadores[i].nome;
		cin >> gladiadores[i].forca;
		cin >> gladiadores[i].habilidade;
		cin >> gladiadores[i].idade;
		gladiadores[i].vida = 100;
	}

	cout << "Escolha dois numeros[0 a 5] que designa os gladiadores que irao se enfrentar: ";
	int g1, g2;

	while(g1 != -1 || g2 != -1) {
		cin >> g1 >> g2;


		bool vitoria = combate(gladiadores[g1], gladiadores[g2]);
		if(vitoria) {
			cout << gladiadores[g1].nome << " ganhou a batalha contra " << gladiadores[g2].nome << endl;
		} else {
			cout << gladiadores[g2].nome << " ganhou a batalha contra " << gladiadores[g1].nome << endl;
		}
	}
	return 0;
}

//A complexidade na análise assintótica é de O(n).
//A complecidade no modelo RAM da função "combate" é : 15n + 8.