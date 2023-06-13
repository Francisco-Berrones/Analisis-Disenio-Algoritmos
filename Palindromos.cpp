#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

int PS(int l,int n,int ant)
{
   if(n%2==1) //es impar
   {
      if(l==(n/2)+1) //Caso base
         if(ant==1)
            return 2;
         else
            return 1;
   }
   else //par
      if(l==n/2) //Caso base
         return 1;
   if(ant==1) //Tengo 2 opciones
      return PS(l+1,n,1)+PS(l+1,n,0);
   else
      return PS(l+1,n,1);

}

int main() {
  int n;
  cin>>n;
  cout<<PS(1,n,1)<<endl;
}