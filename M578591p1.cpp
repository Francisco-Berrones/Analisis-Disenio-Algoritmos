//Vanesa Anahi Elizondo Rocha #578591
//Francisco Ariel Berrones Gomez #625824

#include <iostream>
//#include <time.h>
#include <string>

using namespace std;

int main(){
    int n, mov, j=0, p=0, num; //Variables tipo entero, n(Num_Casos), mov(Total_Movimientos), j(Limitador_Instrucciones), p(Posicion_Robot en 0) y num(Ayuda en el SAME AS para saber el numero al cual nos referimos en la instruccion)
    int recorrido[j]; //Variable para pasar las instrucciones a enteros
    string movimientos; //Variable donde se guardara la instruccion del Movimiento del Robot

    cin >> n; //Numero de casos
    for(int i=0; i<n; i++){ //Ciclo para realizar N cantidad de casos deseados
        cin >> mov; //Numero de Movimientos del robot a realizar
        for(int j=0; j<mov; j++){ //Ciclo para realiazr N cantidad de Movimientos
            cin.sync();
            getline(cin,movimientos); //Getline me permite agarrar la linea completa de la variable movimientos
            if(movimientos=="RIGHT"){ //Condicion: Si, movimientos es igual a RIGHT
                p++;    //La posicion se actualizara a +1
                recorrido[j+1]=1;
            }else if(movimientos=="LEFT"){ //Condicion: Si, movimientos es igual a LEFT
                    p--; //La posicion se actualizara a -1
                    recorrido[j+1]=0;
            }else if(movimientos.find("SAME AS")==0){ //Utilizamos la funcion FIND para buscar el elemento el cual queremos replicar con el SAME AS
                string numero_string = movimientos.substr(8); //Asignamos el valor obtenido extraido de movimientos, hacemos que llegue hasta el 8 caracter por los espacios del SAME AS
                num = stoi(numero_string); //Convertimos el num_string a int

                if(recorrido[num]==1){ //Condicion: Verificamos si recorrido es igual 1, si cumple dicha condicion
                    p++; //Se incrementa uno
                    recorrido[j+1]=1; //Establecemos indice en 1
                }
                else if(recorrido[num]==0){ //Condicion: Verificamos si recorrido es igual 0, si cumple dicha condicion
                    p--; //Se decrementa uno
                    recorrido[j+1]=0; //Establecemos el indice en 0
                }
            }
        }
    cout << p << endl; //Devolvemos la position final
    p=0; //Volvemos a regresar en 0 la posicion para el siguiente caso
    }
    return 0;
}

//Damos nuestra palabra de que hemos realizado esta actividad con integridad academica.