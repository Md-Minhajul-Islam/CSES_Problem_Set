// Q: https://cses.fi/problemset/task/1675/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef pair<int, int> pii;
vector<pii> adj[N];
long long cost = 0;
bool visited[N];
void primsAlgo(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty())
    {
        int v = q.top().second;
        int w = q.top().first;
        q.pop();
        if(visited[v]) continue;
        cost += w;
        visited[v] = 1;
        for (pii vpair : adj[v])
        {
            int vp = vpair.first;
            int wp = vpair.second;
            if (visited[vp]) continue;
            q.push({wp, vp});
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    primsAlgo(1);
    bool flag = 1;
    for(int i = 1; i <= n; i++)
        if(!visited[i]){flag = 0; break;}
    if(flag) cout << cost;
    else cout << "IMPOSSIBLE";
    return 0;
}