// Q: https://cses.fi/problemset/task/1634
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int main()
{
    int n, x;
    cin >> n >> x;
    int coins[n];
    for(int i = 0; i < n; i++) cin >> coins[i];
    int dp[n+1][x+1];
    dp[0][0] = 0;
    for(int i = 1; i <= x; i++) dp[0][i] = INF;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= x; j++)
        {
            if(j >= coins[i-1])
                dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    if(dp[n][x] == INF) cout << -1;
    else cout << dp[n][x];
    return 0;
}