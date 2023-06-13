#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector< vector<int> > M;

int Camino(int a, int b){
    if(M[a][b]!=0){ //Es una ciudad vecina
        return M[a][b]; 
    }
    //Revisar cada vecino de a
    int minimo=9999999;
    for(int i=1;i<=M[a].size();i++){
        if(M[a][i]!=0){
            int c=M[a][i]+Camino(i,b);
            if(c<minimo){
                minimo=c;
            }
        }
    }
    M[a][b]=minimo;
    return minimo;

}

int main(){

    int n,i,j,v;
    cin>>n;
    vector<int> temp(n+1);
    for(int i=0;i<=n;i++){
        M.push_back(temp);
    }
    for(int x=0; x<n;x++){
        cin>>i>>j>>v;
        M[i][j]=v;

    }
    cout << Camino(6,10);

    return 0;
}