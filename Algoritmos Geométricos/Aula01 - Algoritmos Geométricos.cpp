#include <iostream>
using namespace std;

typedef struct{
	int x, y;
}ponto;

/* Segmento
typedef struct{
	ponto a, b;
}segmento;
*/

float area_triangulo(ponto a, ponto b, ponto c){
	float area = a.x * b.y - a.y * b.x + a.y* c.x - a.x * c.y + b.x * c.y - b.y * c.x;
	return area / 2;
}

int main(){
	
	ponto a, b, c;
	a.x = 1;
	a.y = 2;
	b.x = 4;
	b.y = 4;
	c.x = 4;
	c.y = 1;
	
	// Área negativa : sentido horário dos pontos.
	// Área positiva : sentido anti_horário dos pontos.
	cout << area_triangulo(a,b,c) << endl;
	
	return 0;
}