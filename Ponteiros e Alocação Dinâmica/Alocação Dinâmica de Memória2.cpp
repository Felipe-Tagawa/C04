#include <iostream>
#include <iomanip>
using namespace std;

struct pessoa {
    int n1, n2, n3, n4;
    double media;
    pessoa* prox;
};

int main() {
    int n;
    cin >> n;

    pessoa* p = new pessoa[n];

    for (int i = 0; i < n; i++) {
        cin >> p[i].n1 >> p[i].n2 >> p[i].n3 >> p[i].n4;
        p[i].media = (p[i].n1 + p[i].n2 + p[i].n3 + p[i].n4) / 4.0;
    }

    double media_geral = 0;
    for (int i = 0; i < n; i++) {
        media_geral += p[i].media / n;
    }


    (*p).prox = new pessoa;
    cout << fixed << setprecision(2);
    cout << media_geral << endl;

    delete (*p).prox;
    delete p;

    return 0;
}
