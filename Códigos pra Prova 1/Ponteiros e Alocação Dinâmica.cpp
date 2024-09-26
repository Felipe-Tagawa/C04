// Estruturas Estáticas --> Tamanho constante, não variam o tamanho (uso ineficiente de memória), mas melhor busca(precisão);
// Estruturas Dinâmicas --> Tamanho variável, variam o tamanho de acordo com a inserção ou remoção de dados.
// Ponteiros só apontam para variáveis de mesmo tipo que eles.

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
	p = &a; // Passando o endereço de a na memória para o ponteiro.
	char *c; // Ponteiro de caracteres.
	c = &b; // Mesmo tipo, c não poderia receber o endereço de a, pois char != int.
	a = 10;
	*p = 12; // O asterisco representa o conteúdo do ponteiro e não mais o endereço de memória, mudando o valor de a de 10 para 12.
	int x[5]; // 20 bytes.
	x[3] = 18;
	*(x + 1) = 12; // Valor para o segundo elemento do vetor.
	p = a; // Problema, já que p é um ponteiro e a uma variável do tipo inteiro.
	p = x; // vetor não necessita do asterisco, pois se aproxima de um ponteiro.
	cout << x[3] << endl;  // Mostra o 18.
	cout << x << endl; // Primeiro endereço de memória, como se fosse x[0] --> x + 0.
	
	return 0;
}