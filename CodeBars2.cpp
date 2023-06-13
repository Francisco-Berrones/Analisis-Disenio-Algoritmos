#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include <cstring>
using namespace std;

int memo[51][51];
int m; //Global para toda la recursion

int BC(int n, int k)
{
	if(n==0 && k==0)  //Soy una solucion para que la cuentes
		return 1;
	if(n<0)    //código lleno y aún faltaron variaciones
		return 0;
	if(k==0 && n>0)  //ya no hay variaciones y faltan barras.
		return 0;
	if(memo[n][k]!=-1)
		return memo[n][k];
	int cont=0;
	for(int i=1;i<=m;i++)
	{
		cont+=BC(n-i,k-1);//Contar todas las posibles soluciones desde la llamada orignal
	}
	memo[n][k]=cont;
	return cont;
}


int main()
{
	int n,k; //Variables
	while(cin>>n>>k>>m)
	{
		memset(memo,-1,sizeof(memo));
		cout<<BC(n,k)<<endl;
	}
	return 0;
}