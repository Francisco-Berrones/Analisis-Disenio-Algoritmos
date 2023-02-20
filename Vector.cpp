#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> VI; //Arreglo dinamico, nos permite ir agregandole datos
    //VI.resize(100,-1); //Le estoy dando tamanio 10 a mi vector, cuando originalmente no habia nada.
    // VI[9]=19;
    // //VI.resize(5); //Al hacer resize, modificamos a 5 el vector
    // cout <<VI[50]<<endl; //Esto no es siempre seguro
    // VI

    //Agrega numeros con la funcion push
    // VI.push_back(1);
    // VI.push_back(20);
    // VI.push_back(15);

    // cout<<VI.size()<<endl; //Devuelve el numero de elemntos de mi vector

    //Generar 100 numeros aleatorios
    // for(int i=0; i<100;i++)
    //     VI.push_back(rand()%100);
    // for(int i=0; i<VI.size();i++)
    //     cout << VI[i] << endl;

    //Generador de numeros del 0-9
    for(int i=0; i<10;i++)
        VI.push_back(i);
    VI.erase(VI.begin()+5);
    VI.erase(VI.end()-1);
    for(int i=0; i<VI.size();i++)
        cout << VI[i] << endl;
    // cout << VI.size();
    return 0;
}