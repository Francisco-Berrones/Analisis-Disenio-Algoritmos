//Sudoku con Backtracking
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include <cstring>
using namespace std;

vector<vector<int> > Sudoku(9,vector<int>(9)); //Vector que almacena el sudoku sin resolver
vector<vector<int> > SudokuSolucion(9,vector<int>(9)); //Vector con el sudoku resuelto
int contador;

bool valido(int i, int f, int c){
    for(int cc=0; cc<9; cc++) //buscar en toda la fila
        if(Sudoku[f][cc]==i)
            return false;
    for(int ff=0; ff<9; ff++)
        if(Sudoku[ff][c]==i) //buscar en toda la columna 
            return false;
    f=(f/3)*3;
    c=(c/3)*3;
    for(int x=f; x<f+3;x++)
        for(int y=c; y<c+3; y++)
            if(Sudoku[x][y]==i)
                return false;

    return true;
}

void Solucion(){
    bool find=false;
    int f,c;
    for(f=0; f<9 && !find; f++)
        for(c=0; c<9 && !find; c++)
            if(Sudoku[f][c]==0)
                    find=true;       
    f--, c--;
    if(!find){
        contador++; //es una solucion y lo contamos
        SudokuSolucion=Sudoku;
        return;
    }
    for(int i=1; i<=9; i++){
        if(valido(i,f,c)){
            Sudoku[f][c]=i;
            Solucion();
        }
    }
    Sudoku[f][c]=0;

}


int main(){
    int k;
    char d;
    cin>>k;
    for(int i=0;i<k;i++){
        contador=0;
        for(int f=0; f<9;f++)
            for(int c=0;c<9;c++){
                cin>>d;
                Sudoku[f][c]=d-'0';
            }
        Solucion();
        cout<<contador<<endl;
        for(int f=0; f<9;f++){
            for(int c=0;c<9;c++)
                cout<<SudokuSolucion[f][c]<<" ";
            cout<<endl;
        }
    }
    
    return 0;
}