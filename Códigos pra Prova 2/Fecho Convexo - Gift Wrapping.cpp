// Algoritmo de Gift Wrapping(Jarvis march) O(nh, n -- pontos, h -- pontos que fazem parte do fecho) ->
// Escolher um ponto bom(extremidades),
// Tra�ar um segmento para todos os outros pontos poss�veis e escolher o segmento que tem o menor �ngulo,
// com o ponto inicial, em rela��o ao eixo x, depois, a partir desse ponto fazer o mesmo.
// Repetir o processo para todos os outros pontos at� chegar no maior �ngulo.
// Se n = h, O(n^2), caso em que todos os pontos fazem parte do fecho convexo.

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define INF 10000

struct Point
{
    int x;
    int y;
};

int orientacao(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

void gift_wraping(Point points[], int n, Point ans[], int &cont)
{
    if (n < 3) // Se menor do que 3 � uma reta ou mesmo um ponto.
        return;

    int next[n];
    for (int i = 0; i < n; i++)
        next[i] = -1;

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x) // Mais � esquerda.
            l = i;

    // until reach the start point again
    int p = l, q;
    do
    {
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
            if (orientacao(points[p], points[i], points[q]) == 2)
                q = i;

        next[p] = q;
        p = q;
    } while (p != l);

    for (int i = 0; i < n; i++)
    {
        if (next[i] != -1)
        {
            ans[cont] = points[i];
            cont++;
        }
    }
}

double dist(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double perimeter(Point ans[], int cont)
{
    double perimeter = 0.0;

    // Find the distance between adjacent points
    for (int i = 0; i < cont - 1; i++)
    {
        perimeter += dist(ans[i], ans[i + 1]);
    }

    // Add the distance between first and last point
    if (cont > 1)
    {
        perimeter += dist(ans[0], ans[cont-1]);
    }

    return perimeter;
}

// Driver program to test above functions
int main()
{
    int n, cont = 0;
    cin >> n;
    Point ponto[n];
    Point ans[20];

    for (int i = 0; i < n; i++)
    {
        cin >> ponto[i].x >> ponto[i].y;
    }

    gift_wraping(ponto, n, ans, cont);

    cout << fixed << setprecision(2) << perimeter(ans, cont) << endl;
    return 0;
}