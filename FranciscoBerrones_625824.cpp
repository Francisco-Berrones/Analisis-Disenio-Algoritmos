#include <iostream>
#include <vector>
#include <string>

using namespace std;
//Variables: N(programadores), I(SegundosInformar), T(SegundosTerminar)
// 2 5 3 2 2 1
// - - x x x x x
//     - - - x x x
//           - - x

// - - - - - x x x x x
//           - - - - x x x x
//                   - - - x x x
int main(){
    int n,i,t;

    while(cin >> n){
        vector<int> tiempoExplicar(n);
        vector<int> tiempoResolver(n);
        if(n==0){
            break;
        }
        int sumatoriatiempos=0;
        for(int i=0; i<n;i++){
           cin >> tiempoExplicar[i]>>tiempoExplicar[i];
        }
        sort(tiempoExplicar.begin(),tiempoExplicar.end());
        sort(tiempoResolver.begin(),tiempoResolver.end());

        int tiempoAcum=0;
        int TiempoTotal=0;

        TiempoTotal=tiempoExplicar+tiempoResolver/n;
        cout << sumatoriatiempos;

    }



    return 0;
}