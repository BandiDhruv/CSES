#include <bits/stdc++.h>
using namespace std;
#define int long long
int M=1e9+7;
void tests() {
    int n,m;
    cin>>n>>m;
    vector<int> indegree(n+1,0);
    map<int,vector<int>> mp;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        indegree[b]++;
    }    
    queue<int>q;
    for(int i=2;i<=n;i++){
        if(indegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:mp[node]){
            if(it==1)continue;
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }
    q.push(1);
    vector<int> cnt(n+1,0);
    cnt[1]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:mp[node]){
            if(cnt[it]==0)cnt[it]=cnt[node];
            else cnt[it]+=cnt[node];
            cnt[it]%=M;
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }
    cout<<cnt[n]%M;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}