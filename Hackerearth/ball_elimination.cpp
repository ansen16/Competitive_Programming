#include <bits/stdc++.h>
using namespace std;

#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define INF 1e9
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++)
typedef long long LL;


void solve()
{
    int n;
    cin>>n;
    int arr[505];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int dp[505][505];
    for(int i=0;i<n;i++)
    {
        dp[i][i]=1;
        dp[i+1][i]=0;
    }
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1])
            dp[i-1][i]=0;
        else
            dp[i-1][i]=2;
    }
    for(int k=2;k<n;k++)
    {
        for(int i=0;i+k<n;i++)
        {
            dp[i][i+k]=1+dp[i+1][i+k];
            for(int j=i+1;j<=i+k;j++)
                if(arr[i]==arr[j])
                    dp[i][i+k]=min(dp[i][i+k],dp[i+1][j-1]+dp[j+1][i+k]);
        }
    }
    cout<<dp[0][n-1]<<'\n';
}
int main()
{
    fast;
        solve();
}
