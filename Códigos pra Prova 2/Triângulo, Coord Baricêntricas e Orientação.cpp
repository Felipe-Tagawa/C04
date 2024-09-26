#include <iostream>
using namespace std;

typedef struct {
    int x, y;
} ponto;

// Fun��o para calcular a �rea do tri�ngulo formado pelos pontos a, b, c.
float area_triangulo(ponto a, ponto b, ponto c) {
    float area = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    return area / 2.0;
}

// Fun��o para determinar a posi��o relativa do ponto p em rela��o ao segmento de reta ab.
int posicao_relativa(ponto a, ponto b, ponto p) {
    float area = area_triangulo(a, b, p);
    if (area > 0) {
        return 1; // Ponto est� � esquerda do segmento ab
    } else if (area < 0) {
        return -1; // Ponto est� � direita do segmento ab
    } else {
        return 0; // Ponto � colinear com o segmento ab
    }
}

// Fun��o para determinar se um ponto est� dentro de um tri�ngulo formado por a, b, c.
int ponto_dentro_triangulo(ponto a, ponto b, ponto c, ponto p) {
    float area_total = area_triangulo(a, b, c);
    float l1 = area_triangulo(p, b, c) / area_total;
    float l2 = area_triangulo(a, p, c) / area_total;
    float l3 = area_triangulo(a, b, p) / area_total;

    if (l1 >= 0 && l2 >= 0 && l3 >= 0 && l1 <= 1 && l2 <= 1 && l3 <= 1) {
        return 1; // Ponto est� dentro do tri�ngulo
    } else {
        return 0; // Ponto est� fora do tri�ngulo
    }
}

int main() {
    ponto p = {3, 1}; // Ponto a ser verificado
    ponto p1 = {1, 2};
    ponto p2 = {4, 4};
    ponto p3 = {4, 1};
    ponto p4 = {5, 5};
    ponto p5 = {6, 6};

    float l1 = area_triangulo(p, p2, p3) / area_triangulo(p1, p2, p3); // Lambda 1.
    float l2 = area_triangulo(p1, p, p3) / area_triangulo(p1, p2, p3); // Lambda 2.
    float l3 = area_triangulo(p1, p2, p) / area_triangulo(p1, p2, p3); // Lambda 3.

    cout << "Lambda 1: " << l1 << endl;
    cout << "Lambda 2: " << l2 << endl;
    cout << "Lambda 3: " << l3 << endl;

    int pos = posicao_relativa(p2, p4, p5);

    if (pos == 1) {
        cout << "O ponto est� � esquerda do segmento." << endl;
    } else if (pos == -1) {
        cout << "O ponto est� � direita do segmento." << endl;
    } else {
        cout << "Os pontos s�o colineares." << endl;
    }

    int dentro_triangulo = ponto_dentro_triangulo(p1, p2, p3, p);

    if (dentro_triangulo == 1) {
        cout << "O ponto est� dentro do tri�ngulo." << endl;
    } else {
        cout << "O ponto est� fora do tri�ngulo." << endl;
    }

    return 0;
}
