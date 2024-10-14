#include <bits/stdc++.h>
using namespace std;
int sv,ev;
bool dfs(int node,unordered_map<int,vector<int>> &mp,int par,vector<int>&parent,vector<bool>&vis){
    vis[node]=true;     
    parent[node]=par;
    // cout<<node<<" "<<par<<endl;
    for(auto it:mp[node]){
        if(it==par)continue;
        if(vis[it]){
            sv=it;
            ev=node;
            return true;
        }
        if(!vis[it] && dfs(it,mp,node,parent,vis))
            return true;
    }
    return false;
}

void tests() {
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<int>> mp;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    bool found=false;
    vector<int> parent(n+1);
    vector<bool>vis(n+1,false);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,mp,-1,parent,vis)){
                found=true;
                break;
            }
        } 
    }
    if(found){
        vector<int> ans;
        int tv=ev;
        ans.push_back(tv);
        while(tv!=sv){
            ans.push_back(parent[tv]);
            tv=parent[tv];
        }
        ans.push_back(ev);
        cout<<ans.size()<<endl;
        for(auto it:ans)cout<<it<<" ";
    }
    else cout<<"IMPOSSIBLE\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}