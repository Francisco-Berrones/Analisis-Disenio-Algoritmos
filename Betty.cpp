#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//Variables: n(filas), m(columnas), k(NumOP)
//Instrucciones: Up(1), Down(2), Left(3), Right(4)
//Condiciones: 0<n<100, 0<m<100, 0<k<1000000

const int MAX = 1005;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int operaciones[MAX];
    int tablero[MAX][MAX];
    memset(tablero, 0, sizeof(tablero));
    for (int i = 0; i < k; i++) {
        cin >> operaciones[i];
    }
    int inicioN = 0, inicioM = 0;
    for (int j = 0; j < n; j++) {
        for (int l = 0; l < n; l++) {
            cin >> tablero[j][l];
        }
    }
    for (int i = 0; i < k; i++) {
        if (operaciones[i] == 1) {
            inicioN = (inicioN + 1) % n;
        } else if (operaciones[i] == 2) {
            inicioN = (inicioN - 1 + n) % n;
        } else if (operaciones[i] == 3) {
            inicioM = (inicioM + 1) % m;
        } else if (operaciones[i] == 4) {
            inicioM = (inicioM - 1 + m) % m;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << tablero[(i + inicioN) % n][(j + inicioM) % m] << " ";
        }
        cout << endl;
    }

    return 0;
}

    