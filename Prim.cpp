#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pesos;
vector< vector < pair< int,int> > > G;
int nV;

void prim(){
    vector<bool> visitados(nV, false);
    priority_queue<pesos,vector<pesos>,greater<pesos> > pq;
    int inicio=0;
    pq.push(make_pair(0, inicio));
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(visitados[u]){
            continue;
        }
        else{
            visitados[u]=true;
        }
        for(int i=0;i<G[u].size();i++){
            int w=G[u][i].first;
            int v=G[u][i].second;
            if(!visitados[v]){
                pq.push(make_pair(w, v));
            }
        }
    }
    
}

int main(){
    int nA, u, v, w;
    cin>>nV>>nA;
    G.resize(nV);
    for(int i=0;i<nA;i++){
        cin>>u>>v>>w;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
    prim();
    return 0;
}