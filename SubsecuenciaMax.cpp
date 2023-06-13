#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int suma_maxima(vector <int> &V, int min, int max)
{
   //Caso base, 1 elemento
   if(max<=min)
      return V[min];
   int mitad=(min+max)/2;
   //Lado izquierdo, hacia atrás
   int maximoIzq = -99999;
   int sum = 0;
   for(int i=mitad; i >=min; i--)
   {
      sum+=V[i];
      //Cada iteración se revisa si es mayor
      if(sum > maximoIzq)
         maximoIzq = sum;
   }
   //Lado derecho hacia adelante
   int maximoDer = -99999;
   sum = 0;
   for(int i=mitad+1; i<=max; i++)
   {
      sum+=V[i];
      //Cada iteración se revisa si es mayor
      if(sum > maximoDer)
         maximoDer = sum;
   }
   //Suma central
   int sumaCentral=maximoIzq+maximoDer;
   //Recursión
   int izq=suma_maxima(V,min,mitad);
   int der=suma_maxima(V,mitad+1,max);
   int M = std::max(izq,der);
   return std::max(M,sumaCentral);
}

int main()
{
   vector <int>V = {2, -4, 1, 9, -6, 7, -3, 5};
   cout<<"La suma máxima es:"<<suma_maxima(V,0,V.size()-1)<<endl;
   return 0;
}