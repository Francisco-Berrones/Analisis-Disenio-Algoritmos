//Vanesa Anahi Elizondo Rocha #578591
//Francisco Ariel Berrones Gomez #625824
#include <iostream>
#include <string>
using namespace std;

int main() {
    int rows, min=9999999, empty=0,auxiliar = 0; //Variables: rows(Para el total de filas a escribir), min(Num minimo de espacios en blanco), empty(Total de espacios vacios) y auxiliar(Ayuda para la suma de espacios auxiliar)
    string lines; //Variable que nos permite ingresar las lineas X junto con sus espacios
    cin>>rows; //Recibimos el total de lineas que vamos a escribir
    while (rows!=0){   //Condicion while, la cual entras mientras que el total de lineas sea diferente de 0
        cin.ignore();   //Funcion que nos permite ignorar o descartar el número de caracteres hasta el delimitador dado.
        for(int i=0;i<rows;i++){    //Ciclo for, para repetir el ingreso de filas que el usuario pidio.
            getline(cin, lines); //Agarramos todas las lineas de la fila
            for(int j=0;j<25;j++){   //Ciclo for que recorre las filas, las cuales tienen un maximo de 25 caracyeres
                if(lines[j]!='X'){   //Si dentro del recorrido, se encuentra una "X"
                    auxiliar++;  //Se le suma uno a la variable
                }
            }
            if(auxiliar<min){    //Comprueba sila  variable auxiliar es menor que el mínimo actual.
                min=auxiliar;  //Si se cumple, el min pasa ser igual al auxiliar
            }
            empty += auxiliar; //suma el número de espacios vacíos encontrados al total acumulado de espacios vacíos.
        }
        empty -= min*rows;  // resta la cantidad mínima de espacios vacíos que se encuentran  y la cantidad de filas totales del acumulado de espacios vacíos 
        cout<<empty<<endl;  //imprime el número restante de espacios vacíos
        cin>>rows;       //Recibe el total de filas para el siguiente caso    
    }
    return 0;
}