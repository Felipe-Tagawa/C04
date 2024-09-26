#include <iostream>
#include <list>
using namespace std;

struct dado {
	int k;
	int status;
};

int hash1(int k, int m){
    int result = k % m;
    if(result < 0){
        result += m;
    }
    return result;
}

int hash2(int k, int m)
{
    int result2 = 1 + (k % (m - 1));
     if(result2 < 0)
    {
        result2 += m;
    }
    return result2;
}

// Evita colisões.
int double_hash(int k, int i, int m){
    return ((hash1(k,m) + i * hash2(k,m)) % m);
}

int hash_insert(dado t[], int k, int m) {
	int i = 0;
	do {
		int j = double_hash(k , i, m);
		if (t[j].status != 1) {
			t[j].k = k;
			t[j].status = 1;
			return j;
		} else {
			i++;
		}
	} while (i != m);

	return -1;
}



int main() {

	list<int> pilha;
	int m; // Tamanho da tabela hash.
	int i, n, valor;

	cin >> m;

	dado t[m];

	for(i = 0; i < m; i++) {
		t[i].status = 0;
		t[i].k = -1;
	}

	i = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
        cin >> valor;
        pilha.push_back(valor);
    }

    while (!pilha.empty()) {
        int k = pilha.back();
        pilha.pop_back();
        hash_insert(t, k, m);
    }
	
	for(i = 0; i < m; i++){
			cout << t[i].k << " ";
	}

	return 0;
}
