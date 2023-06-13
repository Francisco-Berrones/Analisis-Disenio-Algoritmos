#include <iostream>
using namespace std;

const int maxS = 1000000;
int S[maxS];

int main() {
    int casos,cant, sneakers,num;
    cin >> casos;

    for(int v=0; v<casos;v++) {
        cin >> cant;
        for (int i = 0; i < cant; i++) {
            int sneakers;
            cin >> sneakers;
            S[sneakers]++;
        }
        num=0;
        for (int i = 0; i < maxS; i++) {
            num += S[i]/2*2;
            S[i] %= 2;
        }
        bool si = true;
        for(int i = 0; i < maxS; i++) {
            if(S[i] == 1) {
                if(!si){
                cout << " ";
                }
                cout<<i;
                si = false;
            }
        }
        if(si==true)
            cout << ":)";
        for(int i = 0; i < maxS; i++)
            S[i] = 0;
        cout <<endl<<num << endl;

    }
    return 0;
}