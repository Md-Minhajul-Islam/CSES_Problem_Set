// Q: https://cses.fi/problemset/task/1192
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+7;
vector<string> g;
int visited[N][N];
int n, m;
bool isValid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
    {
        if (g[i][j] == '#' || visited[i][j]) return false;
        else return true;
    }
    else return false;
}
void dfs(int i, int j)
{
    if(!isValid(i, j)) return;
    visited[i][j] = true;
    dfs(i-1, j);
    dfs(i+1, j);
    dfs(i, j-1);
    dfs(i, j+1);
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        g.push_back(s);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(g[i][j] == '#' || visited[i][j]) continue;
            dfs(i, j);
            cnt++;
        }
    cout << cnt << "\n";
    
    return 0;
}