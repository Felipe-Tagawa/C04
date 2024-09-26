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