#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool myfunction (pair<int,int> i,pair<int,int> j) { 
   if(i.second==j.second)
      return i.first<j.first;
   else 
      return i.second<j.second;
}

void mochila(int W,vector<pair<int,int> > &O,vector<float> &S)
{
   sort(O.begin(),O.end(),myfunction);
   int i=O.size()-1;
   while(i>=0 && W>0)
   {
      if(O[i].first<W) //Si cabe el objeto
      {
         //cout<<i<<endl;
         S[i]=1;
         W-=O[i].first;
      }
      else  //Fraccionamos
      {
         S[i] = (float) W/ O[i].first;
         W=0;
      }
      i--;
   }
}

int main()
{
   pair<int,int> Obj;
   vector<pair<int,int> > O; //peso,valor
   vector<float> S;
   Obj=make_pair(10,20); O.push_back(Obj);
   Obj=make_pair(20,30); O.push_back(Obj);
   Obj=make_pair(30,66); O.push_back(Obj);
   Obj=make_pair(40,40); O.push_back(Obj);
   Obj=make_pair(50,60); O.push_back(Obj);
   int W=100;
   S.resize(5,0);
   mochila(W,O,S);
   int suma=0;
   for(int i=S.size()-1;i>0;i--)
   {
      if(S[i]>0){
         cout<<"objeto "<<i<<"elegido proporcion"<<S[i]<<endl;
         suma+=O[i].second*S[i];
      }
   }
   cout<<"Ganancia "<<suma<<endl;
   return 0;
}