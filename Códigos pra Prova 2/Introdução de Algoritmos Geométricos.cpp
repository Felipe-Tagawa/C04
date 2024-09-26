#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

struct Retangulo {
    Point s1, s2, s3, s4;
};

// Fun��o para calcular o vetor AB
Point calcularVetorAB(Point A, Point B) {
    Point vetorAB;
    vetorAB.x = B.x - A.x;
    vetorAB.y = B.y - A.y;
    return vetorAB;
}

// Fun��o para calcular vetores AB para os lados de um ret�ngulo
void calcularVetoresRetangulo(Retangulo ret) {
    Point vetorAB1 = calcularVetorAB(ret.s1, ret.s2);
    Point vetorAB2 = calcularVetorAB(ret.s2, ret.s3);
    Point vetorAB3 = calcularVetorAB(ret.s3, ret.s4);
    Point vetorAB4 = calcularVetorAB(ret.s4, ret.s1);

    // Exibindo os vetores AB para os lados do ret�ngulo
    cout << "Vetor AB1: (" << vetorAB1.x << ", " << vetorAB1.y << ")" << endl;
    cout << "Vetor AB2: (" << vetorAB2.x << ", " << vetorAB2.y << ")" << endl;
    cout << "Vetor AB3: (" << vetorAB3.x << ", " << vetorAB3.y << ")" << endl;
    cout << "Vetor AB4: (" << vetorAB4.x << ", " << vetorAB4.y << ")" << endl;
}

int main() {
    // Criando um ret�ngulo com quatro pontos
    Point A = {1, 2};
    Point B = {5, 2};
    Point C = {5, 6};
    Point D = {1, 6};

    // Criando o ret�ngulo com esses pontos
    Retangulo retangulo = {A, B, C, D};

    // Chamando a fun��o para calcular os vetores AB para os lados do ret�ngulo
    calcularVetoresRetangulo(retangulo);

    return 0;
}