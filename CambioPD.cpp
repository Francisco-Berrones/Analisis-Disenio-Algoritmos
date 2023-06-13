#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> //Devuelve en palabras reservadas el numero mas grande.
using namespace std;

int monedas[6]={1,2,5,10,16,20};
vector<int> minimos(1000000, -1); //Inicio vector con tamanio de 1000000, empezando en -1.

int Cambio(int cantidad)
{
    if(cantidad==0) //Si la cantidad es 0, hay 0 monedas que regresar.
        return 0;
    if(minimos[cantidad]!=-1)
        return minimos[cantidad];
    int minima=INT_MAX;
    for(int i=0; i<6;i++) //Se explora cada moneda
    {
        if(monedas[i]<=cantidad) //Se valida que no pase de la canitdad
        {
            int solucion=Cambio(cantidad-monedas[i])+1; //Usamos 1 moneda y calculamos el resto recursivamente
            minima=min(minima,solucion); //Me quedo siempre con la minima cantidad
        }

    }
    minimos[cantidad]=minima;
    return minima;
    
}

int main()
{
    int n;
    cin>>n;
    minimos[0]=0;
    cout <<Cambio(n)<<endl;
}