// Q: https://cses.fi/problemset/task/1636
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main()
{
    int n, x;
    cin >> n >> x;
    int coin[n];
    for(int i = 0; i < n; i++) cin >> coin[i];
    int dp[n+1][x+1];
    dp[0][0] = 1;
    for(int i = 1; i <= x; i++) dp[0][i] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= x; j++)
            if(j >= coin[i-1]) dp[i][j] = (dp[i][j-coin[i-1]] + dp[i-1][j])%mod;
            else dp[i][j] = dp[i-1][j];
    cout << dp[n][x];
    return 0;
}