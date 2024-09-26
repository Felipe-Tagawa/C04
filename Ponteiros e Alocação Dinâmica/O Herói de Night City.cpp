// A taxa de psicose não pode ultrapassar os 60%.
#include <iostream>
using namespace std;
struct implante{
  string nome;
  string fabricante;
  int tier;
  float psicose;
};

int main(){
    
    float m = 0;
    int n; // Quantidade de implantes a serem registrados.
    cin >> n;

	implante *vetor = new implante[n];
	implante *aux = vetor;
    
    for(int i = 0; i < n; i++){
        getline(cin >> ws, aux->nome);
        getline(cin >> ws, aux->fabricante);
		cin >> aux->tier >> aux->psicose;
		aux++;
    }
    
    for(int i = 0; i < n; i++){
		m += vetor[i].psicose;
	}
	
	if(m > 60.0){
		cout << "Alerta! Uma recompensa de 50.000 edinhos foi colocada pela sua cabeça. Você se tornou um Ciberpsicopata." << endl;
	}
	else{
		cout << "Vamos tchum! Temos uma cidade pra conquistar!" << endl;
	}
	
    delete []vetor;
    
    return 0;
}