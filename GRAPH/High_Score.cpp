#include <bits/stdc++.h>
using namespace std;
#define int long long
void tests() {
    int n ,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> grid(n+1,vector<pair<int,int>>());
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        grid[u].push_back({v,w});
    }
    vector<int> dist(n+1,-1e10);
    dist[1]=0;
    for(int i=0;i<n-1;i++){
        for(int j=1;j<n+1;j++){
            if(dist[j]!=-1e10){
                for(auto it:grid[j]){
                    int u=it.first, w=it.second;
                    if(dist[j]+w>dist[u]){
                        dist[u]=dist[j]+w;
                    }
                }
            }
        }
    }
    bool f=true;
    for(int i=1;i<=n;i++){
        if(dist[i]!=-1e10){
            for(auto it:grid[i]){
                int u=it.first, w=it.second;
                if(dist[i]+w>dist[u]){
                    queue<int>q ;
                    q.push(i);
                    vector<bool>vis(n+1,false); 
                    while(!q.empty()){
                        int a=q.front();
                        q.pop();
                        vis[a]=true;
                        if(a==n){
                            f=false;
                            break;
                        }
                        for(auto it:grid[a]){
                            if(!vis[it.first])q.push(it.first);
                        }
                        if(!f)break;
                    }
                    if(!f)break;
                }
                if(!f)break;
            }
            if(!f)break;
        }
        if(!f)break;
    }
    if(f)cout<<dist[n];
    else cout<<-1;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}