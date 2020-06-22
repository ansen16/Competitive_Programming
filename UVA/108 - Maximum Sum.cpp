#include <bits/stdc++.h>
using namespace std;


#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)


#define REP(i,start,end) for (int i = start; i <=end; i++)
#define RREP(i,end,start) for (int i=end; i>=start ;i--)
#define set0(a)     memset(a,0,sizeof(a))
typedef long long LL;


void solve()
{
    int n;
    cin>>n;
    int grid[101][101];
    REP(i,1,n)
        REP(j,1,n)
            cin>>grid[i][j];
    int dp[101][101];
    set0(dp);
    int ans=-200;
    RREP(k,n,1)
    {
        REP(i,1,k)
        {
            REP(j,1,n)
                dp[i][j]+=grid[n-k+i][j];
        }
        
        REP(i,1,k)
        {
            int sum=-200;
            REP(j,1,n)
            {
                sum=max(sum+dp[i][j],dp[i][j]);
                ans=max(ans,sum);
            }
        }
    }
    cout<<ans<<endl;

}
int main()
{
    fast;
        solve();
}
