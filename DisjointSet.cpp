#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DisjointSet{
    int n;
    vector<int> p, Rank;
public:
    DisjointSet(int n):n(n){
        p = vector<int>(n);
        Rank = vector<int>(n);
    }
    void make_set(int x){
        p[x] = x;
        Rank[x] = 0;
    }
    int Find(int x){
        //returns the representative of the set containing x
        if( x != p[x] )
            p[x] = Find(p[x]); //path compression
        return p[x];
    }

    void Union(int a, int b){
        //merge the sets containing a and b
        int x = Find(a);
        int y = Find(b);
        if(x == y){
            //both have the same representative
            //they are already in the same set
            //no need to union
            return;
        }
        //union by rank
        if(Rank[x] > Rank[y]){
            p[y] = x;
        }else{
            p[x] = y;
            if(Rank[x] == Rank[y])
                Rank[y]++;
        }

    }
};

class Island{
    int n;
    vector<vector<int>> edge;
public:
    Island(int n): n(n){}
    void addEdge(int u, int v){
        edge.push_back({u, v});
    }

    bool isConnect(int x, int y) {
        DisjointSet  ds(n);
        for (int i=0; i<n; i++){
            ds.make_set(i);
        }
        for(auto e:edge) {
            int a = e[0];
            int b = e[1];

            ds.Union(a,b);

            if (ds.Find(x) == ds.Find(y)) {
                return true;
            }
        }
        return false;
    }

};
int main(){
    //write code here
    Island i(7);
    i.addEdge(0,2);
    i.addEdge(0,3);
    i.addEdge(0,4);
    i.addEdge(3,4);
    i.addEdge(5,6);

    bool flag = true;
    for(int j=1; j<7;  j++){
        if(!(i.isConnect(j-1, j))){
            flag = false;
            break;
        }
    }
    if(flag) cout<< "All Island connected.."<<endl;
    else cout<< "All Island Not Connected"<<endl;


 return 0;
}
