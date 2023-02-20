#include <iostream>
using namespace std;

int main(){
    int numero[6] = {0,1,2,3,4,5};
    int opcion;
    bool existe;

    cout << "Digita un numero: " << endl;
    cin >> opcion;

    for(int i=0; i<6; i++){
        if(numero[i]==opcion){
            existe = true;
            cout << "El numero si se encuentra";
        }
    }
    if(existe==false){
        cout << "No se encontro " << endl;
    }  
    

};
