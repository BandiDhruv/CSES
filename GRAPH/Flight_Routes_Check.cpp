#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int node,map<int,vector<int>>&mp1,vector<bool>&vis,stack<int>&st){
    vis[node]=true;
    for(auto it:mp1[node]){
        if(!vis[it])
            dfs(it,mp1,vis,st);
    }
    st.push(node);
}
void dfs2(int node,map<int,vector<int>>&mp1,vector<bool>&vis){
    vis[node]=true;
    for(auto it:mp1[node]){
        if(!vis[it])
            dfs2(it,mp1,vis);
    }
}
void tests() {
    int n,m;
    cin>>n>>m;
    map<int,vector<int>> mp1,mp2;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        mp1[x].push_back(y);
        mp2[y].push_back(x);
    }
    vector<bool> vis(n+1,false);
    stack<int> st;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,mp1,vis,st);
        }
    }
    vector<int> scc;
    vector<bool>vis2(n+1,false);

   while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis2[node]){
            scc.push_back(node);
            dfs2(node,mp2,vis2);
        }
    }

    if(scc.size()<=1)
        cout<<"YES";
    else{
        cout<<"NO\n";
        reverse(scc.begin(),scc.end());
        // for(auto it:scc){
            cout<<scc[0]<<" "<<scc[1];
        // }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}