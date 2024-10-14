#include <bits/stdc++.h>
using namespace std;
int n, m;
bool isValid(int x,int y)
{
    return (x<n && y<m && x>=0 && y>=0);
}
 
void tests()
{
    cin >> n >> m;
    vector<string> a(n);
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int,char>>> dist(n,vector<pair<int,char>>(m));
    queue<pair<pair<int,int>,int>> q;
    bool ok = false;
    for (auto &it : a)
        cin >> it;
    bool T=false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'A')
            {
                T=true;
                q.push({{i,j},0});
                break;
            }
            if(T)break;
        }
        if(T)break;
    }
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,-1,1};
    vector<char> w={'D','U','L','R'};
    string ans;
    bool f=false;
    int lx,ly;
    while (!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int cnt=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(isValid(nx,ny) && a[nx][ny]=='B'){
                    ok=true;
                    lx=nx;
                    ly=ny;
                    dist[nx][ny]={cnt+1,w[k]};
                    break;
                }
                if(isValid(nx,ny) && a[nx][ny]=='.' && !vis[nx][ny]){
                    dist[nx][ny]={cnt,w[k]};
                    vis[nx][ny]=true;
                    q.push({{nx,ny},cnt+1});
                }
            }
            if(ok)break;
        }
        if(ok)break;
    }
    
    if (!ok)
        cout << "NO";
    else
    {
        int temp=dist[lx][ly].first;
        while(temp--){
            char ch=dist[lx][ly].second;
            ans.push_back(ch);
            if(ch=='U'){
                lx++;
            }
            else if(ch=='D'){
                lx--;
            }
            else if(ch=='L'){
                ly++;
            }
            else if(ch=='R'){
                ly--;
            }
        }
        cout << "YES\n";
        cout<<ans.size()<<endl;
        reverse(ans.begin(),ans.end());
        for(auto it:ans)cout<<it;
        
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}