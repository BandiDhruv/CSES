#include <bits/stdc++.h>
using namespace std;
int n,m;
void dfs(int i,int j,vector<string>&a,vector<vector<bool>>&vis){
    if (i>=n||j>=m || i<0 || j<0) return ;
    vis[i][j]=true;
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    for(auto it:dir){
        int nx=i+it.first,ny=j+it.second;
        if(nx<n && ny<m && nx>=0 && ny>=0){
            if(a[nx][ny]=='.' && !vis[nx][ny])dfs(nx,ny,a,vis);
        }
    }
    return ;
}
void tests() {
        cin>>n>>m;
        vector<string> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int ans=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='.'){
                    if(!vis[i][j]){
                        ans++;
                        dfs(i,j,a,vis);
                    }
                }
            }
        }
        cout<<ans;

    }
int main() {
    tests();
    return 0;
}