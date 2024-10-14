
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
    // vector<vector<int>>edges;
    DisjointSet ds(n);
    int ans=n,cnt=0;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(ds.findUpar(u)==ds.findUpar(v)){
            cout<<ans<<" "<<cnt<<endl;
            continue;
        }
        ds.unionBySize(u,v);
        cnt=max(ds.size[ds.findUpar(u)],cnt);
        ans--;
        cout<<ans<<" "<<cnt<<endl;
    }
    
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}
