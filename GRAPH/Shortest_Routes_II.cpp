#include <bits/stdc++.h>
using namespace std;
#define int long long
void tests() {
    int n,m,q;
    cin>>n>>m>>q;
    // unordered_map<int,vector<pair<int,int>>> mp;
    vector<vector<int>> dist(n+1,vector<int>(n+1,LLONG_MAX));
    for(int i=0;i<m;i++){
        int u,v,t;
        cin>>u>>v>>t;
        dist[u][v]=min(t,dist[u][v]);
        dist[v][u]=min(t,dist[v][u]);
    }
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j] && dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(dist[a][b]==LLONG_MAX)cout<<-1<<endl;
        else cout<<dist[a][b]<<endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}