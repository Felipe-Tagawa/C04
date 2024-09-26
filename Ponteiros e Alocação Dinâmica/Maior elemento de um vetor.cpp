#include <iostream>
using namespace std;

int main(){
    
    int n;
    
    cin >> n;
    
    int valores[n];
    int *p = valores;
    int maior_elemento = -500;
    
    for(int i = 0; i < n; i++){
        cin >> *(p + i);
        if(*(p + i) > maior_elemento){
            maior_elemento = *(p + i);
        }
    }
    
    cout << maior_elemento << endl;
    
    
    return 0;
}