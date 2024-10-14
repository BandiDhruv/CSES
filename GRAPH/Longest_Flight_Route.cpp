#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs(map<int,vector<int>>&mp,vector<int>&dp,vector<int>&nextnode,int node,vector<bool>&vis){
    vis[node]=true;
    for(auto it:mp[node]){
        if(!vis[it])dfs(mp,dp,nextnode,it,vis);
        if(dp[it]!=-1 && dp[node]<dp[it]+1){
            dp[node]=dp[it]+1;
            nextnode[node]=it;
        }
    }
}
void tests() {
    int n,m;
    cin>>n>>m;
    map<int,vector<int>> mp;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        mp[u-1].push_back(v-1);

    }
    vector<int>dp(n,-1),nextnode(n,-1);
    dp[n-1]=1;
    vector<bool>vis(n,false);
    dfs(mp,dp,nextnode,0,vis);
    if(dp[0]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    else {
        int i=0;
        cout<<dp[0]<<endl;
        while(dp[0]--){
            cout<<1+i<<" ";
            i=nextnode[i];
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}