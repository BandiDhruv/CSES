#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;

void tests() {
    cin>>n>>m;
    vector<vector<int>> mp;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mp.push_back({u,v,w});
    }
    vector<int> dist(n+1,1e18);
    vector<int> parent(n+1,-1);
    dist[1]=0;
    int x;
    for(int i=0;i<n;i++){
        x=-1;
        for(auto it:mp){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            if(dist[u]+w < dist[v]){
                dist[v]=dist[u]+w;
                parent[v]=u;
                x=u;
            }
        }
    }
    if(x==-1)cout<<"NO\n";
    else{
        cout<<"YES\n";
        for(int i=1;i<=n;i++)x=parent[x];//x becomes a node part of negative cycle by tracing back n times
        vector<int> ans;
        int y=x;
        ans.push_back(x);
        for(;y=parent[y];){
            ans.push_back(y);
            if(y==x && ans.size()>1)break;
        }
        reverse(ans.begin(),ans.end());
        for(auto it:ans)cout<<it<<" ";
    }

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}