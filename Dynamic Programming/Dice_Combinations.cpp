// Q: https://cses.fi/problemset/task/1633
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int dp[1000002];
int fn(int n)
{
   if(n == 0) return 1;
   if(n < 0) return 0; 
   if(dp[n] != -1) return dp[n];
   int ans = 0;
   for(int i = 1; i <= 6; i++)
    ans = (ans + fn(n-i))%mod;
    return dp[n] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << fn(n) << "\n";
    return 0;
}