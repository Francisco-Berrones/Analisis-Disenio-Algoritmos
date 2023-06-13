#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Variables a pedir: N(int), Cactus(vector int), P(int), Qs(Vector int), Ps(int)
//N (Mayor o igual a 1), P(Menor o igual a 1,000,000) 
//Cactus(Puede número entero que está entre 1 y 1,000,000,000)
//Q(número entero que está entre 1 y N, ambos inclusive)

int main(){

    //Variables:
    int N,P,Ps;
    vector<int>Cactus;vector<int>Qs;

    cin >> N;
    for(int i=1;i<=N;i++){
        int nCactus;
        cin >> nCactus;
        Cactus.push_back(nCactus);
    }
    sort(Cactus.begin(), Cactus.end());
    cin >> P;
    for(int j=0; j<P; j++){
        cin>> Ps;
        Qs.push_back(Ps);
    }
    for (int i = 0; i < P; i++) {
        cout << Cactus[Cactus.size()-Qs[i]] << " ";
    }
    return 0;
}