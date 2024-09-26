// Fazer a lógica das retas serem paralelas(nunca se intersectam).
// Procurar o maior intervalo de x e o maior de y, formando um quadrado.

// Código base da UFOP.

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct point {
    int x, y;
};

struct line {
    double a, b, c;
};

struct segment {
    point p1, p2;
};

void points_to_line(point p1, point p2, line &l) {
    if (abs(p1.x - p2.x) < 1e-9) { // vertical line
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

bool same_lineQ(line l1, line l2) {
    return (abs(l1.a - l2.a) < 1e-9 && abs(l1.b - l2.b) < 1e-9 && abs(l1.c - l2.c) < 1e-9);
}

bool parallelQ(line l1, line l2) {
    return (abs(l1.a - l2.a) < 1e-9 && abs(l1.b - l2.b) < 1e-9);
}

bool intersection_point(line l1, line l2, point &p) {
    if (parallelQ(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (abs(l1.b) > 1e-9) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true;
}

bool point_in_box(point p, point b1, point b2) {
    return (p.x >= min(b1.x, b2.x) && p.x <= max(b1.x, b2.x) &&
            p.y >= min(b1.y, b2.y) && p.y <= max(b1.y, b2.y));
}

bool segments_intersect(segment s1, segment s2) {
    line l1, l2; // retas (linhas) contendo os segmentos s1,s2
    point p; // ponto de interseção
    points_to_line(s1.p1, s1.p2, l1);
    points_to_line(s2.p1, s2.p2, l2);

    if (same_lineQ(l1, l2)) {
        return (point_in_box(s1.p1, s2.p1, s2.p2) ||
                point_in_box(s1.p2, s2.p1, s2.p2) ||
                point_in_box(s2.p1, s1.p1, s1.p2) ||
                point_in_box(s2.p2, s1.p1, s1.p2));
    }
    
    if (parallelQ(l1, l2)) return false;

    if (intersection_point(l1, l2, p)) {
        return (point_in_box(p, s1.p1, s1.p2) &&
                point_in_box(p, s2.p1, s2.p2));
    }

    return false;
}

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        segment s1 = {{x1, y1}, {x2, y2}};
        segment s2 = {{x3, y3}, {x4, y4}};

        if (segments_intersect(s1, s2)) {
            cout << "SIM" << endl;
        } else {
            cout << "NAO" << endl;
        }
    }
    return 0;
}
