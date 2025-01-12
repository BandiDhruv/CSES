#include <bits/stdc++.h>
using namespace std;
#define int long long
void tests() {
    int n,q;
    cin>>n>>q;
    int m=30;
    vector<vector<int>> sparseTable(m+1,vector<int>(n+1,-1));
    for(int i=1;i<=n;i++) {
        cin>>sparseTable[0][i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            sparseTable[i][j]=sparseTable[i-1][sparseTable[i-1][j]];
        }
    }

    while(q--){
        int x,k;
        cin>>x>>k;
        int ans=x;
        for(int i=0;i<=m;i++){
            if(k&(1<<i)){
                ans=sparseTable[i][ans];
            }
        }
        cout<<ans<<endl;
    }

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}