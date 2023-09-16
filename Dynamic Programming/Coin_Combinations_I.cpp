// Q: https://cses.fi/problemset/task/1635
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int dp[1000002], coin[102];
int n;
int coinComb(int s)
{
    if(s == 0) return 1;
    if(s < 0) return 0;
    if(dp[s] != -1) return dp[s];
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = (ans + coinComb(s-coin[i]))%mod;
    return dp[s] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> coin[i];
    cout << coinComb(x);
    return 0;
}