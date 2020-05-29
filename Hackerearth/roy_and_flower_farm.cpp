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
    int x[105];
    x[0]=0;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    int y[105];
    for(int i=1;i<=n;i++)
    {
        cin>>y[i];
        x[i]-=y[i];
    }
    int w;
    cin>>w;
    int dp[n+1][w+1]={0};
    for(int j=1;j<=w;j++)
        for(int i=1;i<=n;i++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-y[i]>=0)
                dp[i][j]=max(dp[i][j],x[i]+dp[i-1][j-y[i]]);
        }
    LL ans=dp[n]][w];
    ans+=w;
    cout<<ans<<'\n';

        
    
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
