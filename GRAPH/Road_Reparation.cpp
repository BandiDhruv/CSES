
#include <bits/stdc++.h>
using namespace std;
#define int long long

class DisjointSet{
    public:
    vector<int>parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int findUpar(int node){
        if(node==parent[node])return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionBySize(int u,int v){
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv)return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

void tests() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    int ans=0;
    DisjointSet ds(n);
    for(auto it:edges){
        int w=it[0],u=it[1],v=it[2];
        if(ds.findUpar(u)==ds.findUpar(v))continue;
        ans+=w;
        ds.unionBySize(u,v);
    }
    for(int i=1;i<=n-1;i++){
        if(ds.findUpar(i)!=ds.findUpar(i+1))
        {
            cout<<"IMPOSSIBLE";
            return;
        }
    }
    cout<<ans<<endl;
    
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}
