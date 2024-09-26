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