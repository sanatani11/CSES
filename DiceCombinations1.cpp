#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int mod = 1000000007;
    int n, x;
    cin >> n >> x;
    vector<int>coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    vector<int>dp(x+1);
    for(int i = 1; i <= x; i++){
      for(int j = 0; j < n; j++){
        if(i==coins[j]){
          dp[i]++;
          dp[i] %= mod;
        }
        if(coins[j]>i) continue;
        dp[i] += dp[i-coins[j]];
        dp[i] %= mod;
      }
    }
    cout<<dp[x];
    return 0;
}
