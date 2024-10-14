#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int n,m;
void dijkstra(vector<int> &dist,unordered_map<int,vector<P>> mp,int src){
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,src});
    vector<bool> vis(n+1,false);
    dist[src]=0;
    while(!pq.empty()){
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(!vis[node])vis[node]=true;
        else continue;
        for(auto it:mp[node]){
            int neighbornode=it.first;
            int neighbordist=it.second;
            if(dist[node]+neighbordist<dist[neighbornode]){
                dist[neighbornode]=dist[node]+neighbordist;
                pq.push({dist[neighbornode],neighbornode});
            }
        }
    }
}

void tests() {
    cin>>n>>m;
    unordered_map<int,vector<P>> mp1,mp2;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
        mp1[u].push_back({v,w});
        mp2[v].push_back({u,w});
    }
    vector<int> arr1(n+1,1e15),arr2(n+1,1e15);
    dijkstra(arr1,mp1,1);
    dijkstra(arr2,mp2,n);
    int ans=1e15;
    for(auto it:edges){
        ans=min(ans,arr1[it[0]]+arr2[it[1]]+it[2]/2);
    }
    cout<<ans<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}