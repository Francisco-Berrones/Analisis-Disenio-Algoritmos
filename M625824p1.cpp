//Francisco Ariel Berrones Gomez #625824
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long int casos;
    while(cin >> casos){
        if(casos == 0)
            break;
        vector<pair<long long int, long long int> > eventos;
        for(long long int i=0; i<casos; i++){
            long long int inicio, fin;
            cin >> inicio >> fin;
            pair<long long int, long long int> evento = make_pair(fin, inicio);  
            eventos.push_back(evento);
        }
        sort(eventos.begin(), eventos.end());
        long long int maximos = 1, finActual = eventos[0].first;
        for(long long int i = 1; i < eventos.size(); i++){
            if(eventos[i].second >= finActual){
                finActual = eventos[i].first;
                 maximos++;
            }
        }
        cout << maximos << endl;
    }
    return 0;
}
