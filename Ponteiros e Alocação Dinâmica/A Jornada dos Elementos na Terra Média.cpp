#include <iostream>
using namespace std;

int main(){
    
    int *p = NULL;
    int *v = NULL;
    int soma = 0;
    
    v = new int[5];
    p = v;
    for(int i = 0; i < 5; i++){
        cin >> *(p);
        cout << "Artefato coletado na terra " << i << " " << *(p) << endl;
        soma+= *(p);
        p++;
    }
    
    cout << "Fim da jornada! Soma total dos artefatos: " << soma << endl;
    
    delete []v;
    
    return 0;
}