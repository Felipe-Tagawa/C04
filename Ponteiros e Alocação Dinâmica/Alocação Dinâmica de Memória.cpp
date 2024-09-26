#include <iostream>
#include <iomanip>
using namespace std;

struct pessoa {
    int n1, n2, n3, n4;
    double media;
    pessoa* prox;
};

int main() {

    pessoa* p = new pessoa;
    
    cin >> (*p).n1 >> (*p).n2 >> (*p).n3 >> (*p).n4;
    (*p).media = ((*p).n1 + (*p).n2 + (*p).n3 + (*p).n4) / 4.0;
    
    (*p).prox = new pessoa;
    
    cout << fixed << setprecision(2);
    cout << (*p).media << endl;
    
    
    delete (*p).prox;
    delete p;

    return 0;
}
