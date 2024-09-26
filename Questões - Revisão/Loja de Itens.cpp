#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Item {
	int cod;
	string nome;
	int preco;
	int status;
};

int h1(int k, int m) {
	int result = k % m;
	if(result < 0) {
		result += m;
	}
	return result;
}

int hash_linear(int k, int m, int i) {
	int result2 = ((h1(k, m) + i) % m);
	if(result2 < 0) {
		result2 += m;
	}
	return result2;
}

int item_insert(Item t[], Item item, int m) {
	int j = 0, i = 0;
	while(i < m){
		j = hash_linear(item.cod, m, i);
		if(t[j].status != 1){
			t[j] = item;
			t[j].status = 1;
			return j;
		}
		i++;
	}
	return -1;
}

int item_search(Item t[], int cod, int m) {
	int j;
	int i = 0, status = 1;
	while(i < m){
		j = hash_linear(cod, m, i);
		t[j].status = status;

		if(t[j].cod == cod and t[j].status == 1){
			return j;
		}
		i++;
	}
	return -1;	
}

int main() {

	const int m = 43;
	int v, c, cod, pos_item, Lucro = 0;

	Item t[m];
	queue<int> vendas;
	stack<int> compras;

	Item item;

	int n; // Quantidade de itens.

	cout << "Leia a quantidade de itens: ";
	cin >> n; // Lendo a quantidade de itens.

	cout << "Digite agora o codigo, o nome e o preco do item, para todos: " << endl;
	for(int i = 0; i < n; i++) {

		cin >> item.cod;
		cin >> item.nome;
		cin >> item.preco;
		item_insert(t, item, m);
	}

	int vi; // cod de item a ser vendido.

	cout << "Escreva agora os codigos dos itens a serem vendidos: " << endl;
	cin >> vi;
	while(vi != -1) {

		// Inserindo os itens na lista de vendas:
		vendas.push(vi);
		cin >> vi;
	}

	int ci; // cod de item a ser comprado.

	cout << "Escreva agora os codigos dos itens a serem comprados: " << endl;
	cin >> ci;
	while(ci != -1) {
		compras.push(ci);
		cin >> ci;
	}

	cin >> v >> c;

	while(v) {
		cod = vendas.front();
		vendas.pop();
		pos_item = item_search(t, cod, m);
		item = t[pos_item];
		Lucro += item.preco;
		v--;
	}



	while(c) {
		cod = compras.top();
		compras.pop();
		pos_item = item_search(t, cod, m);
		item = t[pos_item];
		Lucro -= item.preco;
		c--;
	}

	cout << Lucro << " moeda(s)." << endl;

	return 0;
}
