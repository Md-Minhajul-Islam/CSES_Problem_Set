// Q: https://cses.fi/problemset/task/1193
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<string> grid;
bool visited[N][N];
int level[N][N];
pair<int, int> parent[N][N];
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;

bool isValid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
    {
        if (grid[i][j] == '#' || visited[i][j]) return false;
        else return true;
    }
    else return false;
}
void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    level[i][j] = 0;
    visited[i][j] = 1;
    parent[i][j] = {-1, -1};
    while(!q.empty())
    {
        int ui, uj;
        ui = q.front().first;
        uj = q.front().second;
        q.pop();
        for(pair<int, int> p: direction)
        {
            int vi, vj;
            vi = ui+p.first;
            vj = uj+p.second;
            if(isValid(vi, vj))
            {
                visited[vi][vj] = 1;
                level[vi][vj] = level[ui][uj]+1;
                parent[vi][vj] = {ui, uj};
                q.push({vi, vj});
            }
        }
    }
}
int main()
{
    int si, sj, di, dj;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            if(s[j] == 'A') si = i, sj = j;
            if(s[j] == 'B') di = i, dj = j;
        }
        grid.push_back(s);
    }
    bfs(si, sj);
    if(level[di][dj] == 0) cout <<"NO";
    else
    {
        cout << "YES\n" << level[di][dj] << "\n";
        vector<char> path;
        int curri = di, currj = dj;
        while(parent[curri][currj].first > -1 && parent[curri][currj].second > -1)
        {
            int pi = parent[curri][currj].first;
            int pj = parent[curri][currj].second;
            if (pi < curri) path.push_back('D');
            else if (pi > curri) path.push_back('U');
            else if (pj < currj) path.push_back('R');
            else if (pj > currj) path.push_back('L');
            curri = pi, currj = pj;
        }
        for(int i = path.size()-1; i >= 0; i--)
            cout << path[i];
    }
    
    return 0;
}