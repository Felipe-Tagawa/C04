#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Ponto_ {
    int x, y;
} Ponto;

typedef struct Retangulo_ {
    Ponto a, b, c, d;
} Retangulo;

bool dentro_do_retangulo(Retangulo R, Ponto X) {
    return (X.x <= max(max(max(R.a.x, R.b.x), R.c.x), R.d.x) &&
            X.x >= min(min(min(R.a.x, R.b.x), R.c.x), R.d.x) &&
            X.y <= max(max(max(R.a.y, R.b.y), R.c.y), R.d.y) &&
            X.y >= min(min(min(R.a.y, R.b.y), R.c.y), R.d.y));
}

int main() {
    int n, x, y;
    cin >> n;

    Retangulo ret;

    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (i == 0){
            ret.a = {x, y};
        }
        else if (i == 1){ 
            ret.b = {x, y};
        }
        else if (i == 2){ 
            ret.c = {x, y};
        }
        else {
            ret.d = {x, y};
        }
    }

    Ponto ponto_buscado;
    cin >> ponto_buscado.x >> ponto_buscado.y;

    if (dentro_do_retangulo(ret, ponto_buscado)) {
        cout << "DENTRO" << endl;
    } else {
        cout << "!(DENTRO)" << endl;
    }

    return 0;
}
