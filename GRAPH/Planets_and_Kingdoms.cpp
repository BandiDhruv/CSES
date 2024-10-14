#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int node,unordered_map<int,vector<int>>&mp1,vector<bool>&vis,stack<int>&st){
    vis[node]=true;
    for(auto it:mp1[node]){
        if(!vis[it])
            dfs(it,mp1,vis,st);
    }
    st.push(node);
}
void dfs2(int node,unordered_map<int,vector<int>>&mp1,vector<bool>&vis,vector<int>&scc,int cnt){
    vis[node]=true;
    scc[node]=cnt;
    for(auto it:mp1[node]){
        if(!vis[it])
            dfs2(it,mp1,vis,scc,cnt);
    }
}
void tests() {
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<int>> mp1,mp2;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        mp1[u].push_back(v);
        mp2[v].push_back(u);
    }
      vector<bool> vis(n+1,false);
    stack<int> st;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,mp1,vis,st);
        }
    }
    vector<int> scc(n+1,0);
    vector<bool>vis2(n+1,false);
    int cnt=1;
   while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis2[node]){
            dfs2(node,mp2,vis2,scc,cnt);
            cnt++;
        }
    }
    cout<<cnt-1<<endl;
    // int n=scc.size();
    for(int i=1;i<=n;i++)cout<<scc[i]<<" ";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}