#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
public:
    vector<int> size,parent;
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize( n + 1);
        for(int i=0;i<=n;i++){
            size[i] = 1;
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void UnionBySize(int u, int v){
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);
        if(ult_u == ult_v){
            return;
        }
        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
    
};
void tests() {
    int n,m;
    cin >> n>>m;
    DisjointSet ds(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        ds.UnionBySize(u-1,v-1);
    }
    int cnt=0;
    vector<pair<int,int>>ans;
    for(int i=2;i<=n;i++) {
        if(ds.findUPar(i-1) != ds.findUPar(0)) {
            ds.UnionBySize(0,i-1);
            cnt++;
            ans.push_back({1,i});
        }
    }
    cout<<cnt<<endl;
    for(auto it:ans)cout <<it.first<<" "<<it.second<<endl;

}
int main() {
    tests();
    return 0;
}