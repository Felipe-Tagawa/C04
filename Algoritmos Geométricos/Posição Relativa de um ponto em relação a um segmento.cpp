// Saber onde um ponto está em relação a um triângulo.
#include <iostream>
using namespace std;

typedef struct{
	int x, y;
}ponto;

// Se área nula, triângulo é um segmento.
float area_triangulo(ponto a, ponto b, ponto c){
	float area = a.x * b.y - a.y * b.x + a.y* c.x - a.x * c.y + b.x * c.y - b.y * c.x;
	return area / 2;
}

int posicao_relativa(ponto a, ponto b, ponto p){
	float area = area_triangulo(a,b,p);
	if(area > 0){
		return 1; // Esquerda do segmento.
	} else if(area < 0){ // Sentido horário
		return -1; // Direita do segmento.
	}else{
		return 0; // Colineares(área igual a 0).
	}
}

int main(){
	
	ponto p = {3,2}; // Ponto a ser procurado.
	ponto p1 = {1,2};
	ponto p2 = {4,4};
	ponto p3 = {4,1};
	ponto p4 = {5,5};
	ponto p5 = {6,6};
	
	float area = area_triangulo(p1,p2,p3);
	float l1 = area_triangulo(p,p2,p3) / area; //Lambda 1.
	float l2 = area_triangulo(p1,p,p3) / area; //Lambda 2.
	float l3 = area_triangulo(p1,p2,p) / area; // lambda 3.
	 
    // Se todos os lambdas forem maiores do que 0, está dentro do triângulo, caso contrário, está fora.
	cout << l1 << endl;
	cout << l2 << endl;
	cout << l3 << endl;
	
	int pos = posicao_relativa(p2,p4,p5);
	
	if(pos == 1){
		cout << "A esquerda" << endl;
	}
	else if(pos == -1){
		cout << "A direita" << endl;
	}
	else{
		cout << "Pontos colineares." << endl;
	}
	
	
	return 0;
}