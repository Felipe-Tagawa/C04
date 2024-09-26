#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct {
    int x, y;
} ponto;

// Função para calcular a área do triângulo formado pelos pontos a, b, c.
float area_triangulo(ponto a, ponto b, ponto c) {
    return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0;
}

// Função para determinar a posição relativa do ponto p em relação ao segmento de reta ab.
int posicao_relativa(ponto a, ponto b, ponto p) {
    float area = area_triangulo(a, b, p);
    if (area > 0) {
        return 1; // Ponto está à esquerda do segmento ab
    } else if (area < 0) {
        return -1; // Ponto está à direita do segmento ab
    } else {
        return 0; // Ponto é colinear com o segmento ab
    }
}

// Função para determinar se um ponto está dentro de um triângulo formado por a, b, c.
bool ponto_dentro_triangulo(ponto a, ponto b, ponto c, ponto p) {
    float area_total = area_triangulo(a, b, c);
    float l1 = area_triangulo(p, b, c) / area_total;
    float l2 = area_triangulo(a, p, c) / area_total;
    float l3 = area_triangulo(a, b, p) / area_total;

    return (l1 >= 0 && l2 >= 0 && l3 >= 0 && l1 <= 1 && l2 <= 1 && l3 <= 1);
}

// Função para determinar se um ponto está dentro de um polígono convexo ou não convexo.
bool ponto_dentro_poligono(ponto* vertices, int num_vertices, ponto p) {
    int intersect_count = 0;

    for (int i = 0; i < num_vertices; ++i) {
        ponto v1 = vertices[i];
        ponto v2 = vertices[(i + 1) % num_vertices];

        // Verifica se o ponto está sobre uma aresta do polígono
        if (posicao_relativa(v1, v2, p) == 0 && ponto_dentro_triangulo(v1, v2, p, vertices[(i + 2) % num_vertices])) {
            return true; // Ponto está sobre uma aresta do polígono
        }

        // Verifica a interseção do raio com a aresta do polígono
        if ((v1.y > p.y) != (v2.y > p.y) && p.x < ((v2.x - v1.x) * (p.y - v1.y) / (float)(v2.y - v1.y) + v1.x)) {
            intersect_count++;
        }
    }

    // Retorna true se o número de interseções for ímpar (ponto dentro do polígono), false caso contrário.
    return (intersect_count % 2 == 1);
}

int main() {
    ponto p = {8, 8}; // Ponto a ser verificado
    ponto poligono[] = {{1, 1}, {5, 1}, {5, 5}, {3, 6}, {1, 5}}; // Exemplo de polígono
    int num_vertices = sizeof(poligono) / sizeof(poligono[0]);

    bool dentro_poligono = ponto_dentro_poligono(poligono, num_vertices, p);

    if (dentro_poligono) {
        cout << "O ponto está dentro do polígono." << endl;
    } else {
        cout << "O ponto está fora do polígono." << endl;
    }

    return 0;
}
