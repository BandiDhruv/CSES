#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> P;
int n, m, k;
int M = 1e9 + 7;
vector<int> routes, minr, maxr;
void dijk(int src, unordered_map<int, vector<pair<int, int>>> &mp, vector<int> &dist)
{
    dist[src] = 0;
    routes[src] = 1;
    vector<bool> vis(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[node])
            continue;

        for (auto it : mp[node])
        {
            int nnode = it.first;
            int ndis = it.second;
            if (dist[node] + ndis > dist[nnode])
                continue;
            if (dist[node] + ndis == dist[nnode])
            {
                routes[nnode] += routes[node];
                routes[nnode] %= M;
                minr[nnode] = min(minr[node] + 1, minr[nnode]);
                maxr[nnode] = max(maxr[node] + 1, maxr[nnode]);
            }
            else if (dist[node] + ndis < dist[nnode])
            {
                dist[nnode] = dist[node] + ndis;
                routes[nnode] = routes[node];
                minr[nnode] = minr[node] + 1;
                maxr[nnode] = maxr[node] + 1;
                pq.push({dist[nnode], nnode});
            }
        }
    }
}

void tests()
{
    cin >> n >> m;
    unordered_map<int, vector<P>> mp, mp2;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mp[u].push_back({v, w});
    }
    routes.resize(n + 1);
    minr.resize(n + 1);
    maxr.resize(n + 1);
    vector<int> d1(n + 1, 1e15);
    dijk(1, mp, d1);
    cout << d1[n] << " " << routes[n] << " " << minr[n] << " " << maxr[n];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tests();
    return 0;
}