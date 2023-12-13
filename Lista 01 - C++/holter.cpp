#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
     int a[n];
    int qtd = 0, soma = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        soma += a[i];
    }

    int media = soma / n;

    for (int i : a) {
        if (i < int(0.9 * media) or i > int(1.1 * media)){
            qtd++;
        }
    }

    cout << media << endl;
    cout << qtd << endl;

    return 0;
}
