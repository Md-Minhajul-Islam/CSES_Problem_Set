// Q: https://cses.fi/problemset/task/1675/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> pii;
const int N = 1e5 + 5;
vector<pii> edges;
int parent[N], Size[N];
long long cost = 0;
void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
}
int find(int v)
{
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}
void Union(int a, int b)
{
    a = find(a), b = find(b);
    if (a != b)
    {
        if (Size[a] < Size[b]) swap(a, b);
        parent[b] = a;
        Size[a] += b;
    }
}
void kruskalsAlgo()
{
    sort(edges.begin(), edges.end());
    for (pii &e : edges)
    {
        int u = e.second.first, v = e.second.second, w = e.first;
        if (find(u) == find(v)) continue;
        cost += w;
        Union(u, v);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) make(i);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    kruskalsAlgo();
    int flag = 0;
    for(int i = 1; i <= n; i++)
        if(parent[i] == i)
        {
            flag++;
            if(flag > 1) break;
        }
    if (flag > 1) cout << "IMPOSSIBLE";
    else cout << cost;
    return 0;
}