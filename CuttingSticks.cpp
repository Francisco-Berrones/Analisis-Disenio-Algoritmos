#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

vector<int> cortes;
int minimos[10001][10001];

//resolver cm()
int CM(int CI,int CF){
    if(CI+1==CF){
        minimos[CI][CF]=0;
        return 0;
    }
    if(minimos[CI][CF]!=-1){
        return minimos[CI][CF];
    }
    //por cada corte intermedio probar todos y quedarme con el minimo
    int minimo=INT_MAX;
    for(int i=CI+1;i<CF;i++){
        int costo=CM(CI,i)+CM(i,CF);
        minimo=min(costo,minimo); //Comparo los costos
    }
    minimo+=cortes[CF]-cortes[CI];
    minimos[CI][CF]=minimo;
    return minimo;
}


int main(){
    int l,n;
    cin>>l;
    while(l>0){
        memset(minimos,-1, sizeof(minimos));
        cin>>n;
        cortes.resize(n+2);
        cortes[0]=0;
        cortes[n+1]=l;
        for(int i=1;i<n+1;i++){
            cin>>cortes[i];
        }
        for(int i=0;i<cortes.size();i++){
            cout<<cortes[i]<<" ";
        }
        cout<<endl;
        cout<<"The minimum cutting is: "<<CM(0,n+1)<<"."<<endl;
        cin>>l;

    }
    
    return 0;
}