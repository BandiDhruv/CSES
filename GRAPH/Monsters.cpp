#include <bits/stdc++.h>
using namespace std;
void tests() {
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    for(auto &i:s)cin>>i;
    queue<pair<int,int>> q;
    pair<int,int> start;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='M')q.push({i,j});
            if(s[i][j]=='A')start={i,j};
        }
    }
    q.push(start);
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x-1>=0 && s[x-1][y]=='.'){
            s[x-1][y]=(s[x][y]=='M')?'M':'U';
            q.push({x-1,y});
        }
        if(x+1<n && s[x+1][y]=='.'){
            s[x+1][y]=(s[x][y]=='M')?'M':'D';
            q.push({x+1,y});
        }
        if(y+1<m && s[x][y+1]=='.'){
            s[x][y+1]=(s[x][y]=='M')?'M':'R';
            q.push({x,y+1});
        }
        if(y-1>=0 && s[x][y-1]=='.'){
            s[x][y-1]=(s[x][y]=='M')?'M':'L';
            q.push({x,y-1});
        }
    }
    pair<int,int> finish={-1,-1};
    for(int i=0;i<n;i++){
        if(s[i][0]!='#' && s[i][0]!='.' && s[i][0]!='M'){
            finish.first=i;finish.second=0;
        }
        if(s[i][m-1]!='#' && s[i][m-1]!='.' && s[i][m-1]!='M'){
            finish.first=i;finish.second=m-1;
        }
    }

    for(int i=0;i<m;i++){
        if(s[0][i]!='#' && s[0][i]!='.' && s[0][i]!='M'){
            finish.first=0;finish.second=i;
        }
        if(s[n-1][i]!='#' && s[n-1][i]!='.' && s[n-1][i]!='M'){
            finish.first=n-1;finish.second=i;
        }
    }

    if(finish.first==-1){
        cout<<"NO";
        return;
    }
    string ans;
    while(finish.first!=start.first || finish.second!=start.second){
        if(s[finish.first][finish.second]=='U'){
            ans.push_back('U');
            finish.first++;
        }
        else if(s[finish.first][finish.second]=='D'){
            ans.push_back('D');
            finish.first--;
        }
        else if(s[finish.first][finish.second]=='L'){
            ans.push_back('L');
            finish.second++;
        }
        else if(s[finish.first][finish.second]=='R'){
            ans.push_back('R');
            finish.second--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    for(auto it:ans)cout<<it;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}