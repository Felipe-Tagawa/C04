// Algoritmos de Graham scan(n log n)
// Escolher o ponto P como sendo o mais baixo(menor y). Em caso de empate, escolher o mais à esquerda(menor x).
// Ordenar os pontos restantes em ordem crescente do ângulo formado do segmento desse ponto e o ponto P com o eixo x.
// Para cada ponto, é determinado, se ao mover-se dos dois pontos anteriores para este ponto se forma uma curva horário.
// Se for, não faz parte do fecho e deve ser removido.

#include <iostream>
#include <stack>
#include <algorithm> // para usar a função sort
#include <cmath> // para usar a função sqrt
using namespace std;
 
struct Point
{
    int x, y;
};
 
Point p0;
 
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
 
void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
 
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
 
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  
    return (val > 0)? 1: 2; 
}
 
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
 
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}
 
double perimeter(Point points[], int n)
{
    double perimeter = 0.0;
    for (int i = 0; i < n - 1; i++)
    {
        perimeter += sqrt(distSq(points[i], points[i + 1]));
    }
    perimeter += sqrt(distSq(points[0], points[n - 1]));
    return perimeter;
}
 
void grahan_scan(Point points[], int n)
{
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;
 
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
 
   swap(points[0], points[min]);
 
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);
 
   int m = 1; 
   for (int i=1; i<n; i++)
   {
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;
 
       points[m] = points[i];
       m++;
   }
 
   if (m < 3) return;
 
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
 
   for (int i = 3; i < m; i++)
   {
      while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }

   // Convertendo os pontos na pilha para um array para cálculo do perímetro
   int cont = 0;
   while (!S.empty())
   {
       points[cont++] = S.top();
       S.pop();
   }
   
   // Calculando o perímetro e imprimindo
   cout << "Pontos do Convex Hull (em ordem):" << endl;
   for (int i = 0; i < cont; i++)
   {
       cout << "(" << points[i].x << ", " << points[i].y << ")" << endl;
   }
   cout << "Perímetro do Convex Hull: " << fixed << perimeter(points, cont) << endl;
}
 
int main()
{
    int n;
    cout << "Entre com o numero de pontos: ";
    cin >> n;
    
    Point *points = new Point[n];
    
    cout << "Entre com os pontos (x y):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    grahan_scan(points, n);

    delete[] points;
    
    return 0;
}
