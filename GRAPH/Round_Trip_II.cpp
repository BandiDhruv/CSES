#include <bits/stdc++.h>
using namespace std;
#define int long long
bool dfs(int node,vector<int> mp[],vector<bool>&vis,vector<bool>&pathvis,stack<int>&st){
    vis[node]=true;
    st.push(node);
    pathvis[node]=true;
    for(auto it:mp[node]){
        if(!vis[it])
            if(dfs(it,mp,vis,pathvis,st))
                return true;
        if(pathvis[it])
        {
            st.push(it);
            return true;
        }
    }
    st.pop();
    pathvis[node]=false;
    return false;
}

void tests(){
    int n,m;
    cin>>n>>m;
    vector<int> mp[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
    }
    stack<int> s;
    vector<bool>vis(n+1,false),pathvis(n+1,false);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,mp,vis,pathvis,s))
                break;
        }
    }
    if(s.empty()){
        cout<<"IMPOSSIBLE";
        return;
    }
    vector<int> ans;
    ans.push_back(s.top()); 
    s.pop();
    while(s.top()!=ans[0]){
        // cout<<ans.back();
        ans.push_back(s.top());
        s.pop();
    }
    ans.push_back(s.top());
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto it:ans)
        cout<<it<<" ";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}