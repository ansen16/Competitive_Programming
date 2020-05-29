#include <bits/stdc++.h>
using namespace std;

#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define INF 1e9
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++)
typedef long long LL;
#define mod 720720






void solve()
{
    int n;
    cin>>n;
    bool a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int k;
    cin>>k;
    LL dp[n+1][k+1];
    for(int i=0;i<n;i++)
        dp[i][0]=1;
    dp[n-1][1]=(a[n-1]!=0);
    for(int i=2;i<=k;i++)
        dp[n-1][i]=0;
    for(int i=n-2;i>=0;i--)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(a[i]!=0)
                dp[i][j]+=dp[i-1][j-1];
            dp[i][j]%=mod;
        }
    }
    cout<<dp[0][k]<<'\n';

    


}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
