#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int Hombres, Mujeres;
    while (cin >> Hombres >> Mujeres) {
        if (Hombres == 0 && Mujeres == 0)
            break;

        vector<int> EdadesHombres(Hombres);
        vector<int> EdadesMujeres(Mujeres);
        for (int i = 0; i < Hombres; i++) {
            cin >> EdadesHombres[i];
        }
        for (int i = 0; i < Mujeres; i++) {
            cin >> EdadesMujeres[i];
        }

        sort(EdadesHombres.begin(), EdadesHombres.end());
        sort(EdadesMujeres.begin(), EdadesMujeres.end());

        int i = 0, j = 0;
        int solteros = 0;
        int edadSoltero = -1;

        while (EdadesHombres.size() > 0 && EdadesMujeres.size() > 0) {
            int HombreActual = EdadesHombres.back(); 
            EdadesHombres.pop_back();
            int edadmax = 61, indiceMujer = -1;
            
            for (int i = 0; i < EdadesMujeres.size(); i++) {
                int diferencia = abs(EdadesMujeres[i] - HombreActual); 
                if (diferencia < edadmax) {
                    edadmax = diferencia;
                    indiceMujer = i;
                }
            }
            if (indiceMujer != -1) {
                EdadesMujeres.erase(EdadesMujeres.begin() + indiceMujer);
            }
        }
        cout << EdadesHombres.size();
        if (EdadesHombres.size() > 0) {
            cout << " " << EdadesHombres[0];
        }
        cout << "\n";
    }
    return 0;
}




