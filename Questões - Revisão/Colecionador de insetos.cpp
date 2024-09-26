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

