#include <iostream>
#include <iomanip>
using namespace std;

typedef struct{
    int x, y;
}ponto;

float area_triangulo(ponto a, ponto b, ponto c){
	float area = a.x * b.y - a.y * b.x + a.y* c.x - a.x * c.y + b.x * c.y - b.y * c.x;
	return area / 2;
}

int main(){
    
    ponto a,b,c;
    
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    
    cout << fixed << setprecision(1) << area_triangulo(a,b,c) << endl;
    
    return 0;
}