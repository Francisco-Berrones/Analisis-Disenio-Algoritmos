#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> arista;
vector<pair<int, arista> > G;
vector<pair<int, arista> > MST;
vector<int> padre;

int buscaPadre(int v){
    if(padre[v]==v){
        return v;
    }
    return buscaPadre(padre[v]);
}

void kruskal(){
    sort(G.begin(),G.end());
    for(int i=0;i<G.size();i++){
        int pu=buscaPadre(G[i].second.first);
        int pv=buscaPadre(G[i].second.second);
        if(pu!=pv){
            MST.push_back(G[i]);
            padre[pu]=padre[pv];
        }
    }
}

int main(){
    int nVertices, nAristas, u, v, w;
    cin>>nVertices>>nAristas;
    for(int i=0;i<nVertices;i++){
        padre.push_back(1);
    }
    for(int i=0;i<nAristas;i++){
        cin>>u>>v>>w;
        arista a=make_pair(u,v);
        G.push_back(make_pair(w, a));
    }
    kruskal();
    for(int i=0;i<MST.size();i++){
        cout<<MST[i].second.first<<"-"<<MST[i].second.second<<": "<<MST[i].first<<endl;
    }
    return 0;
}