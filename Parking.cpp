#include <iostream>
#include <vector>
using namespace std;

int main(){
    int casos,tiendas,store;
    cin >> casos;
    for(int i=0; i<casos; i++){ //por cada caso
        
        cin >> tiendas;
        int mayor=-1, menor=100; //Poner uno menor que el mayor y uno mayor que el menor
        for(int i =0; i<tiendas; i++){//por cada tienda
            cin >> store;
            if(store<menor)
                menor=store;
            if(store>mayor)
                mayor=store;

        }
        int salida=(mayor-menor)*2;
        cout << salida;
    }
   

    return 0;
};


//Entubamiento, pasar datos a un archivo
//gedit borrar.txt
//borrar.exe ./a.out < borrar.txt