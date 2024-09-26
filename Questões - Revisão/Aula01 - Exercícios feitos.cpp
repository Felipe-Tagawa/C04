//Batalha de Gladiadores: 

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

// Colecionador de Insetos: 
#include <iostream>
#include <string>

using namespace std;

struct inseto{

	double tamanho;
	string nome;
};

void bubblesort(inseto insetos[] , int n)
{
	int i, j;
	inseto aux;
	for(j = 0; j < n-1; j++)
	{
		for(i = 0; i < n-j-1; i++)
		{
			if(insetos[i].tamanho > insetos[i+1].tamanho) 
			{
				aux = insetos[i];
				insetos[i] = insetos[i+1];
				insetos[i+1] = aux;
			}
		}
	}
}

int main(){
	
	int n;
	
	cin >> n;
	
	inseto insetos[n];
	
	for(int i = 0; i < n; i++){
		cin.ignore();
		getline(cin,insetos[i].nome);
		cin >> insetos[i].tamanho;
	}
	
	bubblesort(insetos,n);
	
	
	for(int i = 0; i < n; i++){
		cout << insetos[i].nome << endl;
	}
	
	return 0;
}

//Pastelaria do Dudu(Sequencial):

#include <iostream>
#include <string>
using namespace std;

struct produto{
	   string nome;
	   int quantidade;	
	
};

int busca_sequencial(produto produtos[], int n, string nome_buscado) 
{
	for(int i = 0; i < n; i++)
	{
		if (produtos[i].nome == nome_buscado){
			return 1;	
		}
	}
	return -1;
}

int main(){
	
	int n;
	
	cin >> n;
	
	produto produtos[n];
	
	for(int i = 0; i < n; i++){
		cin.ignore();
		cin >> produtos[i].nome;
		cin >> produtos[i].quantidade;
	}
	
	
	string nome_buscado;
	cin.ignore();
	cin >> nome_buscado;
	
	int produto_buscado = busca_sequencial(produtos, n, nome_buscado);
	
	if(produto_buscado != -1){
		cout << nome_buscado << " em estoque!" << endl;
	}
	else{
		cout << "Nao existe " << nome_buscado << " em estoque!" << endl;
	}
	
	return 0;
}

// Pastelaria do Dudu(Binária):

#include <iostream>
#include <string>
using namespace std;

struct produto{
	int cod;
	string nome;
	int quantidade;	
};

produto busca(produto produtos[], int n, int cod_buscado)
{
	int inicio = 0;
	int metade;
	int fim = n-1;
	for(int i = 0; i < n; i++)
	{
		metade = (inicio + fim)/2;
		if (cod_buscado < produtos[metade].cod)
		{
			fim = metade - 1;
		}
		else if (cod_buscado > produtos[metade].cod)
		{
			inicio = metade + 1;
		}
	}
	return produtos[metade];
}

int main(){
	
	
	int cod_buscado; // código do produto buscado.
	int n; // Quantidade de produtos cadastrados.
	cin >> n;
	
	produto produtos[n];
	
	for(int i = 0; i < n; i++){
		cin >> produtos[i].cod;
		cin.ignore();
		cin >> produtos[i].nome;
		cin >> produtos[i].quantidade;
	}
	
	cin >> cod_buscado;
	
	produto produto_procurado = busca(produtos, n, cod_buscado);
	
	if(produto_procurado.cod == cod_buscado){
		cout << produto_procurado.nome << " em estoque!" << endl;
	}
	
	else{
		cout << "Nao existem produtos com esse codigo em estoque!" << endl;
	}
	
	return 0;
}

// Pilha e Hashing:

#include <iostream>
#include <list>
using namespace std;

struct dado {
	int k;
	int status;
};

int hash1(int k, int m){
    int result = k % m;
    if(result < 0){
        result += m;
    }
    return result;
}

int hash2(int k, int m)
{
    int result2 = 1 + (k % (m - 1));
     if(result2 < 0)
    {
        result2 += m;
    }
    return result2;
}

// Evita colisões.
int double_hash(int k, int i, int m){
    return ((hash1(k,m) + i * hash2(k,m)) % m);
}

int hash_insert(dado t[], int k, int m) {
	int i = 0;
	do {
		int j = double_hash(k , i, m);
		if (t[j].status != 1) {
			t[j].k = k;
			t[j].status = 1;
			return j;
		} else {
			i++;
		}
	} while (i != m);

	return -1;
}



int main() {

	list<int> pilha;
	int m; // Tamanho da tabela hash.
	int i, n, valor;

	cin >> m;

	dado t[m];

	for(i = 0; i < m; i++) {
		t[i].status = 0;
		t[i].k = -1;
	}

	i = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
        cin >> valor;
        pilha.push_back(valor);
    }

    while (!pilha.empty()) {
        int k = pilha.back();
        pilha.pop_back();
        hash_insert(t, k, m);
    }
	
	for(i = 0; i < m; i++){
			cout << t[i].k << " ";
	}

	return 0;
}

// Loja de Itens:

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





