// Q: 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
vector<int> adj[N];
vector<int> visited(N);
vector<int> level(N, 0);
vector<int> parent(N, -1);
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int v: adj[p])
        {
            if(visited[v]) continue;
            level[v] = level[p]+1;
            parent[v] = p;
            visited[v] = true;
            q.push(v);
        }
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
    bfs(1);
    if(level[n] == 0) cout << "IMPOSSIBLE";
    else
    {
        cout << level[n]+1 << "\n";
        int curr = n;
        vector<int> paths;
        while(curr != -1)
        {
            paths.push_back(curr);
            curr = parent[curr];
        }
        for(int i = paths.size()-1; i >= 0; i--)
            cout << paths[i] << " ";
    }
    return 0;
}