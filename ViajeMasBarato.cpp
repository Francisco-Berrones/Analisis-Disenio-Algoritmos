#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector< vector<int> > embarcaciones;
int Costos[1001][1001];

//int CaminoMasBarato(){}


int main(){

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        vector<int> temporal(n);
        embarcaciones.push_back(temporal);
    }

    return 0;
}
