// Estruturas Est�ticas --> Tamanho constante, n�o variam o tamanho (uso ineficiente de mem�ria), mas melhor busca(precis�o);
// Estruturas Din�micas --> Tamanho vari�vel, variam o tamanho de acordo com a inser��o ou remo��o de dados.
// Ponteiros s� apontam para vari�veis de mesmo tipo que eles.

#include <iostream>
using namespace std;

struct node{
	   int dado;
	   node* proximo;	
};

int main(){
	
	int a; // 4 bytes.
	int *p; // Criando o ponteiro.
	char b; // 1 byte.
	p = &a; // Passando o endere�o de a na mem�ria para o ponteiro.
	char *c; // Ponteiro de caracteres.
	c = &b; // Mesmo tipo, c n�o poderia receber o endere�o de a, pois char != int.
	a = 10;
	*p = 12; // O asterisco representa o conte�do do ponteiro e n�o mais o endere�o de mem�ria, mudando o valor de a de 10 para 12.
	int x[5]; // 20 bytes.
	x[3] = 18;
	*(x + 1) = 12; // Valor para o segundo elemento do vetor.
	p = a; // Problema, j� que p � um ponteiro e a uma vari�vel do tipo inteiro.
	p = x; // vetor n�o necessita do asterisco, pois se aproxima de um ponteiro.
	cout << x[3] << endl;  // Mostra o 18.
	cout << x << endl; // Primeiro endere�o de mem�ria, como se fosse x[0] --> x + 0.
	
	return 0;
}