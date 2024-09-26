#include <iostream>
using namespace std;
int main(){
    
    int n;
    cin >> n;
    
    int valores[n];
    int *p;
    p = valores;
    // int *vetor = new int[n];
    
    for(int i = 0; i < n; i++){
        cin >> valores[i];
    }
    
    for(int i = 0; i < n; i++){
        cout << *p++ << " ";
    }
    
    return 0;
}