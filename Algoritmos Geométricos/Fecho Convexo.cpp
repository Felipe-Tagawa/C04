// Fecho convexo -- Dist�ncia menor do que para pol�gono c�ncavo.
// Algoritmo de Gift Wrapping(Jarvis march) O(nh, n -- pontos, h -- pontos que fazem parte do fecho) ->
// Escolher um ponto bom(extremidades),
// Tra�ar um segmento para todos os outros pontos poss�veis e escolher o segmento que tem o menor �ngulo,
// com o ponto inicial, em rela��o ao eixo x, depois, a partir desse ponto fazer o mesmo.
// Repetir o processo para todos os outros pontos at� chegar no maior �ngulo.
// Se n = h, O(n^2), caso em que todos os pontos fazem parte do fecho convexo.

// Algoritmos de Graham scan(n log n)
// Escolher o ponto P como sendo o mais baixo(menor y). Em caso de empate, escolher o mais � esquerda(menor x).
// Ordenar os pontos restantes em ordem crescente do �ngulo formado do segmento desse ponto e o ponto P com o eixo x.
// Para cada ponto, � determinado, se ao mover-se dos dois pontos anteriores para este ponto se forma uma curva hor�rio.
// Se for, n�o faz parte do fecho e deve ser removido.

#include <iostream>
#include <stack>
using namespace std;

typedef struct{
    int x, y;
}Point;

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
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
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
       while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0)
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
 
   while (!S.empty())
   {
       Point p = S.top();
       cout << p.x << " " << p.y << endl;
       S.pop();
   }
}


int main(){
    
    int n;
    cin >> n;
    
    Point vertice[n];
    
    for(int i = 0; i < n; i++){
        cin >> vertice[i].x >> vertice[i].y;
    }
    
    grahan_scan(vertice, n);
    
    
    return 0;
}