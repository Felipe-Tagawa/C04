// O grafo � orientado/direcionado.
#include<iostream>
#include<list>
#include<string>
using namespace std;

#define INT_MAX 99999

struct Upgrade
{
	int orig;
	int dest;
	int custo;
};

struct Habilidade
{
	string nome;
	int codigo;
	float poder;
	list<Upgrade> upgrades;
};

void bfs_poder_acumulado(Habilidade habilidades[], int vertices, int start, float poder_acumulado[])
{

	bool visited[vertices];
	list<int> to_visit_queue;

	for(int i = 0; i < vertices; i++)
	{
		visited[i] = false;
	}

	visited[start] = true;
	to_visit_queue.push_back(start);

	while(!to_visit_queue.empty())
	{
		int u = to_visit_queue.front(); // O current � o nosso v�rtice atual(u).
		to_visit_queue.pop_front();
		list<Upgrade>::iterator p;
		for(p = habilidades[u].upgrades.begin(); p != habilidades[u].upgrades.end(); p++)
		{
			int dest = p->dest;
			if(!visited[dest])
			{
				visited[dest] = true;
				to_visit_queue.push_back(dest);
				poder_acumulado[dest] += poder_acumulado[u];
			}
		}

	}
}


int shortest_path_dijkstra(Habilidade habilidades[], float poder_acumulado[], int vertices, int start, float poder_desejado)
{
	bool intree[vertices];
	int distance[vertices], parent[vertices];

	for(int u = 0; u < vertices; u++)
	{
		intree[u] = false;
		distance[u] = INT_MAX;
		parent[u] = -1;
	}
	distance[start] = 0;
	int v = start;
	while(intree[v] == false)
	{
		intree[v] = true;
		list<Upgrade>::iterator p;
		for(p = habilidades[v].upgrades.begin(); p != habilidades[v].upgrades.end(); p++)
		{
			int dest = p->dest;
			int weight = p->custo;
			if(distance[dest] > distance[v] + weight)
			{
				distance[dest] = distance[v] + weight;
				parent[dest] = v;
			}
		}
		v = 0;
		int dist = INT_MAX, poder = 0;
		for(int u = 0; u < vertices; u++)
		{
			if(intree[u] == false && distance[u] < dist)
			{
				dist = distance[u];
				v = u;
			}
		}
	}
	int dist = INT_MAX;
	for(int u = 0; u < vertices; u++)
	{
		if(intree[u] == true && distance[u] < dist && poder_acumulado[u] >= poder_desejado)
		{
			dist = distance[u];
		}
	}
	return dist == INT_MAX ? -1 : dist;
}

int main()
{

	int num_habilidades;
	cin >> num_habilidades;

	Habilidade habilidades[num_habilidades];
	float poder_acumulado[num_habilidades];

	for(int i = 0; i < num_habilidades; i++)
	{
		habilidades[i].codigo = i;
		cin >> habilidades[i].nome;
		cin >> habilidades[i].poder;
		poder_acumulado[i] = habilidades[i].poder;
	}

	int num_upgrades, origem, destino, custo;
	cin >> num_upgrades;

	for(int j = 0; j < num_upgrades; j++)
	{
		cin >> origem;
		cin >> destino;
		cin >> custo;
		habilidades[origem].upgrades.push_back( {origem, destino, custo});
	}

	bfs_poder_acumulado(habilidades, num_habilidades, 0, poder_acumulado);

	float poder_desejado;
	cin >> poder_desejado;
	int resultado = shortest_path_dijkstra(habilidades, poder_acumulado, num_habilidades, 0, poder_desejado);
	if (resultado == -1)
	{
		cout << "Impossivel" << endl;
	}
	else
	{
		cout << resultado << endl;
	}

	return 0;
}
/*
10
0 0
1 1
2 3
3 3
4 4
5 5
6 7
7 2
8 4
9 5
9
0 1 1
1 2 2
1 3 2
3 4 3
3 5 3
3 6 4
0 7 2
7 8 3
7 9 3
7

5
---------


Poles est� desenvolvendo uma �rvore de habilidades para o seu jogo de RPG. Ele quer que os personagens possam escolher, partindo de uma habilidade principal, algumas ramifica��es poss�veis.
Para cada upgrade de habilidade, o personagem deve gastar alguns pontos de experi�ncia e pode adquirir alguma pontua��o de poder.
<imagem>
Ele quer saber, dada um determinada �rvore de habilidadades, qual � o custo m�nimo de experi�ncia para ter um determinado valor de poder.

Entrada
A entrada come�a com um n�mero inteiro indicando a quantidade H de habilidades. As H linhas seguintes cont�m o nome (palavra) e o poder (n�mero real) de cada habilidade (cada habilidade tem um c�digo autom�tico de 0 a H de acordo com a entrada de dados).
Em seguida � informado um valor inteiro indicando a quantidade U de upgrades poss�veis. As U linhas seguintes cont�m tr�s inteiros indicando o c�digo da habilidade origem, o c�digo da habilidade destino e o custo de cada upgrade.
Por fim, � informado um n�mero real que � o valor de poder desejado.

Sa�da
A sa�da � um n�mero inteiro indicando o custo m�nimo para se conseguir o n�vel de poder desejado.

*/
