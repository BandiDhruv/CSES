#include <bits/stdc++.h>
using namespace std;
void tests() {
    int n,m;
    cin >> n >> m;
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    queue<pair<int,vector<int>>> q;
    vector<bool>vis(n+1,false);
    q.push({1,{}});
    bool f=false;
    vector<int> temp;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int node=q.front().first;
            temp=q.front().second;
            q.pop();
            if(node==n){
                f=true;
                break;
            }
            for(auto it:mp[node]){
                if(!vis[it]){
                    vis[it]=true;
                    temp.push_back(it);
                    q.push({it,temp});
                    temp.pop_back();
                }
            }
        }
        if(f)break;
    }
    if(!f){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<temp.size()+1<<endl;
        cout<<1<<" ";
        for(auto it:temp)cout<<it<<' ';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}