#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main(){
	int n, p, pedido, vendas = 0; //5
	cin >> n; //1
	int tamanhos[n]; //1
	for (int i = 1; i <= n; i++){ //N
		cin >> tamanhos[i];//1
	}
	cin >> p; //1
	for (int i = 0; i < p; i++){ //N
		cin >> pedido; //1
		if (tamanhos[pedido] > 0){ //2
			tamanhos[pedido] -= 1; //2
			vendas += 1; //2
		}
	}
	
	cout << vendas; //1
	return 0;
}