#include <bits/stdc++.h>
using namespace std;
int n, m;


void tests()
{
    cin >> n >> m;
    unordered_map<int, vector<int>> g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> ans(n + 1, -1);
    queue<pair<int, int>> q;
    bool f = true;
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == -1)
        {
            q.push({i, 1});
            ans[i] = 1;
            while (!q.empty())
            {
                int node = q.front().first;
                int color = q.front().second;
                q.pop();
                for (auto it : g[node])
                {
                    if (ans[it] == color)
                    {
                        f = false;
                        break;
                    }
                    if (ans[it] == -1)
                    {
                        ans[it] = (color == 1) ? 2 : 1;
                        q.push({it, ans[it]});
                    }
                }
            }
            if (!f)
                break;
        }
    }
    if (!f)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}