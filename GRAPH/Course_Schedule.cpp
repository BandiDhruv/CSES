#include <bits/stdc++.h>
using namespace std;
void tests() {
    int n,m;
    cin>>n>>m;
    map<int,vector<int>> mp;    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        mp[u].push_back(v);
    }
    vector<int> topo;
    vector<int> indegree(n,0);

    for(auto it:mp){
        for(auto i:it.second){
            indegree[i]++;
        }
    }
    queue<int> q;
    vector<int> vis(n,false);
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
            vis[i]=true;
        }
    }
    
    while(!q.empty()){
        int node=q.front();
        topo.push_back(node);
        q.pop();
        for(auto it:mp[node]){
            indegree[it]--;
            if(indegree[it]==0 && !vis[it]){
                vis[it]=true;
                q.push(it);
            }
        }
    }
    // for(auto it:topo)cout<<it+1<<" ";
    // cout<<topo.size();
    if(topo.size()!=n)cout<<"IMPOSSIBLE";
    else{
        for(auto it:topo)cout<<it+1<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}