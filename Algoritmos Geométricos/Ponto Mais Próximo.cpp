#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

struct Point {
    int x, y;
};

// Função para calcular a distância entre dois pontos:
double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    int n;
    cin >> n;

    Point points[n];
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    Point usuario;
    cin >> usuario.x >> usuario.y;

    int dist_min = INT_MAX;
    Point ponto_mais_proximo;

    for (int i = 0; i < n; i++) {
        double d = dist(points[i], usuario);
        if (d < dist_min) {
            dist_min = d; // Temos que atualizar o dist_min.
            ponto_mais_proximo = points[i];
        }
    }

    cout << ponto_mais_proximo.x << " " << ponto_mais_proximo.y << endl;

    return 0;
}
