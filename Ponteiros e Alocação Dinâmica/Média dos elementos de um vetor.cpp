#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    double media = 0;
    cin >> n;
    
    int valores[n];
    int *p = valores; 

    for (int i = 0; i < n; i++) {
        cin >> *(p + i);
        media += *(p + i); 
    }

    media /= n; 

    cout << fixed << setprecision(2);
    cout << media << endl; 

    return 0;
}
