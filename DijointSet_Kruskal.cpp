#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class DisjointSet{
    int n;
    vector<int> p, Rank;
public:
    DisjointSet (int n): n(n){
       p = vector<int> (n);
       Rank = vector<int> (n);

    }
  void makeSet (int x){
      p[x] = x;
      Rank[x] = 0;
  }
 int Find(int x){

    if ( x != p[x] )
     p[x] = Find (p[x]);
    else return p[x];
 }
  void Union (int a, int b){
   int x = Find (a);
   int y = Find (b);

   if ( x == y ){

    return;
   }
   if( Rank [x] > Rank [y] ){
       p[y] = x;
   }else{
       p[x] = y;
       if(Rank [x] == Rank[y])  Rank[y]++;
}
  }
};
class Graph  {
     int n;
     vector<vector<int> > edges;
public:
    Graph(int n): n(n){
    }
    void addEdge(int u, int v, int w){
      edges.push_back({w,u,v});
    }
    void Kruskal(){
        DisjointSet ds(n);
        for(int i = 0; i<n; i++)
            ds.makeSet(i);
        sort(edges.begin(), edges.end());

        vector<vector<int>> T;
        for(int i = 0; i<edges.size(); i++){
            int w = edges [i][0];
             int u = edges [i][1];
              int v = edges [i][2];

             if (ds.Find(u) != ds.Find(v)){
                T.push_back ({u,v,w});
                ds.Union(u,v);
             }
        }
        int cost = 0;
        cout<<"Chosen for MST:"<<endl;
        for(int i = 0; i < T.size(); i++){
            int u = T[i][0];
            int v = T[i][1];
            int w = T[i][2];
            cout<<"("<<u<<", "<<v<<", "<<w<<")"<<endl;
            cost +=w;

        }
        cout<<"Cost of MST:"<<endl;
    }

};


int main(){

   Graph g(5);

   g.addEdge(0, 2, 10);
     g.addEdge(2, 3, 6);
       g.addEdge(1, 2, 7);
         g.addEdge(1, 3, 5);
           g.addEdge(0, 1, 9);
             g.addEdge(3, 4, 3);
               g.addEdge(1, 4, 2);

  g.Kruskal()   ;



}
