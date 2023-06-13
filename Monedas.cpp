#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> //Devuelve en palabras reservadas el numero mas grande.
using namespace std;

int monedas[6]={1,2,5,10,16,20};
vector<int> minimos(1000000, -1); //Inicio vector con tamanio de 1000000, empezando en -1.

int Cambio(int cantidad)
{
    if(cantidad==0) //Si la cantidad es 0, se regresa el 0.
        return 0;
    if(minimos[cantidad]!=-1)
        return minimos[cantidad];
    int minima=INT_MAX;
    for(int i=0; i<6;i++)
    {
        if(monedas[i]<=cantidad)
        {
            int solucion=Cambio(cantidad-monedas[i])+1;
            minima=min(minima,solucion);
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