#include <iostream>
#include <list>
using namespace std;

int main() {
    int n; // Número de cidades (vértices).
    int m; // Número de arestas.
    int A, B;
    list<int> adj[100];

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> A >> B;
        adj[A-1].push_back(B);
        adj[B-1].push_back(A);
    }
    
    for (int i = 0; i < n; i++) {
        cout << adj[i].size() << " ";
        adj[i].sort();
        for (list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
        cout << endl;
    }

    return 0;
}
