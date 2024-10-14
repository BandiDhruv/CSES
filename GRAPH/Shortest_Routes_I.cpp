#include <bits/stdc++.h>
using namespace std;
#define int long long
void tests() {
    int n,m;
    cin >> n>>m;
    unordered_map<int,vector<pair<int,int>>> mp;
    for(int i=0;i<m;i++){
        int u,v,t;
        cin>>u>>v>>t;
        mp[u].push_back({v,t});
    }
    vector<bool> vis(n+1,false);
    vector<int> dist(n+1,LLONG_MAX);
    dist[1]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    while(!pq.empty()) {
        int city=pq.top().second;
        int distance=pq.top().first;
        pq.pop();
        if(!vis[city])vis[city]=true;
        else  continue;
        for(auto it:mp[city]){
            int ncity=it.first;
            int ndistance=it.second;
            if(distance+ndistance < dist[ncity]){
                dist[ncity]=distance+ndistance;
                pq.push({dist[ncity],ncity});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}