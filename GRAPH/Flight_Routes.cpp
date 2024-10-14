#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
void tests() {
    int n,m,k;
    cin>>n>>m>>k;
    unordered_map<int,vector<P>> mp;
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        mp[u].push_back({v,w});
    }
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,1});
    vector<vector<int>> dist(n+1,vector<int>(k,1e15));
    dist[1][0]=0;
    vector<bool> vis(n+1,false);
    while(!pq.empty()){
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        if(dist[node][k-1]<dis)continue;
        for(auto it:mp[node]){
            int nnode=it.first,ndis=it.second;
            if(dis+ndis<dist[nnode][k-1]){
                dist[nnode][k-1]=dis+ndis;
                pq.push({dist[nnode][k-1],nnode});
                sort(dist[nnode].begin(),dist[nnode].end());
            }
        }
    }
    for(auto it:dist[n])cout<<it<<" ";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}