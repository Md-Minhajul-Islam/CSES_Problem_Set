// Q: https://cses.fi/problemset/task/1666
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
vector<int> adj[N];
vector<int> visited(N);

void  dfs(int u)
{
    visited[u] = true;
    for(int v: adj[u])
    {
        if(visited[v]) continue;
        dfs(v);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> leaders;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        leaders.push_back(i);
        dfs(i);
    }
    cout << leaders.size()-1 << endl;
    for(int i = 1; i < leaders.size(); i++)
       cout << leaders[i-1] << " " << leaders[i] << endl;
    return 0;
}