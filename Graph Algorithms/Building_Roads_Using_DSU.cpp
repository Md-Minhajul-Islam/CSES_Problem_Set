// Q: https://cses.fi/problemset/task/1666
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int parent[N];
int Size[N];
void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
}
int find(int v)
{
    if(parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}
void Union(int a, int b)
{
    a = find(a), b = find(b);
    if(a != b)
    {
        if(Size[a] < Size[b]) swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) make(i);
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    vector<int> v;
    for(int i = 1; i <= n; i++)
        if(parent[i] == i) v.push_back(i);
    cout << v.size()-1 << "\n";
    if(v.size() > 1)
    {
        for(int i = 1; i < v.size(); i++)
            cout << v[i] << " " << v[i-1] << "\n";
    }
    return 0;
}