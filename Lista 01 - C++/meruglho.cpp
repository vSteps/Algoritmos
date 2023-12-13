#include <iostream>

using namespace std;

int main() {
    int N, R;
    cin >> N >> R;

    bool retornaram[10000] = {false}; 

    for (int i = 0; i < R; i++) {
        int voluntario;
        cin >> voluntario;
        retornaram[voluntario - 1] = true;
    }

    bool todosRetornaram = true;

    for (int i = 0; i < N; i++) {
        if (!retornaram[i]) {
            cout << i + 1 << " ";
            todosRetornaram = false;
        }
    }

    if (todosRetornaram) {
        cout << "*";
    }

    cout << endl;

    return 0;
}
