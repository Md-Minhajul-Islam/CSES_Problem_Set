// Q: https://cses.fi/problemset/task/1676
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+4;
int parent[N], Size[N];
int largest_cmp = 0, num_of_cmp;
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
        --num_of_cmp;
        if(Size[a] < Size[b]) swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
    largest_cmp = max(largest_cmp, Size[a]);
}
int main()
{
    int n, m;
    cin >> n >> m;
    num_of_cmp = n;
    for(int i = 1; i <= n; i++) make(i);
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
        cout << num_of_cmp << " " << largest_cmp << "\n";
    }
    return 0;
}