#include <iostream>
using namespace std;

int main(){
    
    int n;
    
    cin >> n;
    int valores[n];
    int *p = valores;
    int par_pos = 0;
    
    for(int i = 0; i < n; i++){
        
        cin >> *(p + i);
        if((*(p + i) % 2) == 0 and (*(p + i) > 0)){
            par_pos++;
        }
    }
    
    cout << par_pos << endl;
    
    
    
    
    return 0;
}