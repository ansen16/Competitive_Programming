#include <bits/stdc++.h>
using namespace std;

#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define INF 1e9
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++)
typedef long long LL;


void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    bool dp[55][55];
    memset(dp,0,sizeof(dp));
    int ans=n;
    for(int i=0;i<n;i++)
        dp[i][i]=1;
    for(int i=1;i<n;i++)
        if(s[i]==s[i-1])
        {
            ans++;
            dp[i-1][i]=1;
        }
    for(int k=2;k<n;k++)
        for(int i=0;i+k<n;i++)
        {
            dp[i][i+k]=((s[i]==s[i+k])&&(dp[i+1][i+k-1]));
            ans+=dp[i][i+k];
        }
    cout<<ans<<'\n';
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=i;j<n;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
}
int main()
{
    fast;
        solve();
}
