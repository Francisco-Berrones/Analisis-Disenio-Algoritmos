//Vanesa Anahi Elizondo Rocha #578591
//Francisco Ariel Berrones Gomez #625824
//"Damos nuestra palabra que hemos realizado esta actividad con integridad academica"
#include <iostream>
#include <string>
using namespace std;

int sumaNum(long long int num) { //Funcion de SumarNumeros, la cual tiene como variable un long long int ya que es el tipo de dato grande para ints
    int suma = 0; //Declaramos la variable suma en 0
    while (num > 0) { //Ciclo while, mientras que numero sea mayor a 0
        suma = suma + num % 10; //se suma la misma variable mas el numero divisible entre 10
        num /= 10; //divide a num entre 10
    }
    if (suma > 9) { //Condicion if, mientras que suma sea mayor a 9 para los numeros con mas de dos digitos
        suma = sumaNum(suma); //Recursion de la funcion
    }
    return suma; //Regresamos el valor de suma
}
int main() {
    string digitos; //Variable String para los digitos
    long long int n = 1; //Variable long long int n igual a 1
    while (n) { //Condicion Mientras n sea un int
        n = 0;//Se inicializa nuevamente a n como 0
        getline(cin, digitos); //Detecta linea por linea, ingresando las cifras y las va leyendo
        for (int i = 0; i < digitos.length(); i++) { //se crea un ciclo para ir posicion por posicion dentro de las cifras
            n = n + digitos[i] - 48;  //se autosuma lo acumulado en n y su posicion de cada cifra nueva
        }
        if (n == 0) { //si el cin es 0 termina el codigo
            break;
        }
        n = sumaNum(n);//Genera la funcion de sumar y verificar el resultado final no sea mas de dos digitos
        cout << n << endl;//Da el resultado de cada cifra.
    }
    return 0;
}

