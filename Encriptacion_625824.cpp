//Francisco Atiel Berrones Gomez 625824

#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

int main(){

    //Variables: Casos(int), MnsEncr(String), MnsDesEncr(String)
    int Casos;

    cin>>Casos;
    cin.ignore();
    for(int i=0;i<Casos;i++){
        string MnsEncr;
        getline(cin,MnsEncr); //Leer toda la linea de string
        //Para poder generar la matriz tenemos que sacarle lo contrario de cuadrado: RAIZ
        int genCuad=sqrt(MnsEncr.length()); //Sacamos la raiz del largo del mensaje

        if(genCuad*genCuad != MnsEncr.length()) //Si la multiplicacion de la raiz es diferente del tamanio del mensaje
        {
            cout << "NULL" << endl; //Si es diferente regresamos el "NULL"
        }else{
            //Creamos la matriz donde vamos a almacenar el mensaje
            vector<vector<string> > MatrizBi(genCuad, vector<string>(genCuad));

            //Ciclo for anidado que ira almacenando en la matriz de tamanio genCuad los caracteres del texto
            for(int j=0; j<genCuad;j++)
            {
                for(int k=0; k<genCuad; k++)
                {
                    MatrizBi[j][k] = MnsEncr[j*genCuad + k]; //Almacenamos en la Matriz el mensaje
                }
            }

            string MnsDesEncr = ""; //Variable para pasar el mensaje desencrp
            for(int j=0; j<genCuad; j++){ //Ciclo anidado para imprimir la matriz
                for(int k=0; k<genCuad; k++){
                    MnsDesEncr += MatrizBi[k][j]; 
                }
            }

            cout << MnsDesEncr << endl; //Imprimir el mensaje
        }
    }
    return 0;
}
