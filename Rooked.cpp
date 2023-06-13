#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
char T[4][4];
int n,contador,MAX;

bool valido(int f, int c)  //Verifica si se puede poner la torre
{
	//verificar hacia la izquierda
	for(int x=c-1;x>=0 && T[f][x]!='X';x--)
		if(T[f][x]=='T')
			return false;
	//verificar hacia la derecha
	for(int x=c+1;x<n && T[f][x]!='X';x++)
		if(T[f][x]=='T')
			return false;
	//verificar hacia  arriba
	for(int y=f-1;y>=0 && T[y][c]!='X';y--)
		if(T[y][c]=='T')
			return false;
	//verificar hacia abajo
	for(int y=f+1;y<n && T[y][c]!='X';y++)
		if(T[y][c]=='T')
			return false;
	return true;
	
}

void soluciona()
{
	bool found=false;
	int f,c;
	//Buscar una celda vacía
	for(f=0;f<n && !found;f++)
		for(c=0;c<n && !found;c++)
			if(T[f][c]=='.')
				found=true;
	f--;c--;
	if(!found) //Tablero lleno, tenemos una sol.
	{
		if(contador>MAX)
			MAX=contador;
		return;
		//contar cuantas torres y comparar con el maximo
	}
	if(valido(f,c)) //Si se puede poner torre?
	{
		T[f][c]='T';
		contador++;
		soluciona();
		T[f][c]='.';
		contador--;
	}
	T[f][c]='-';
	soluciona();
	T[f][c]='.';
}

int main() {
	cin>>n;
	while(n>0) //Por cada caso
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>T[i][j];
		contador=0;
		MAX=-1;
		soluciona();
		cout<<MAX<<endl;
		/*for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<T[i][j];
			cout<<endl;
		}*/
		cin>>n;
	}
    return 0;
}