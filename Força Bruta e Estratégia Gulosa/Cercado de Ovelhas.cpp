#include <iostream>
using namespace std;

int main(){
	
	int m; // número de metros de cerca.
	int x = 2;
	int area_maxima = 0;
	int a = 0;
	int xa = 0;
	int ya = 0;
	
	cin >> m;
	int y = m - x;
	
	for(int i = 0; i < m; i++){
		a = x/2*y;
		if(a > area_maxima){
			area_maxima = a;
			xa = x /2;
			ya = y;
		}
		
		x += 2;
		y = m - x;
	}
	
	cout << xa << " X " << ya << endl;
	
	return 0;
}