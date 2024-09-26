#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point {
    int x;
    int y;
};

// Função para determinar a orientação do ponto 'r' em relação ao segmento 'pq'
int orientacao(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

// Função para encontrar a envoltória convexa usando o algoritmo Gift Wrapping
void gift_wrapping(Point points[], int n, Point ans[], int &cont) {
    if (n < 3)
        return;

    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    int p = l, q;
    do {
        ans[cont++] = points[p];
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
            if (orientacao(points[p], points[i], points[q]) == 2)
                q = i;
        p = q;
    } while (p != l);
}

// Função para calcular a distância entre dois pontos
double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Função para calcular o perímetro da envoltória convexa
double perimeter(Point ans[], int cont) {
    double perimeter = 0.0;
    for (int i = 0; i < cont; i++)
        perimeter += dist(ans[i], ans[(i + 1) % cont]);
    return perimeter;
}

int main() {
    int n, cont = 0;
    cin >> n;
    Point ponto[n];
    Point ans[n]; // Garantimos que o tamanho de ans é igual ao de ponto

    for (int i = 0; i < n; i++)
        cin >> ponto[i].x >> ponto[i].y;

    gift_wrapping(ponto, n, ans, cont);

    cout << fixed << setprecision(2) << perimeter(ans, cont) << endl;

    return 0;
}
