#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multi_set;

#define mod         1000000007
#define pi          acos(-1.0)
#define eps         1e-9


#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define fs          first
#define sc          second
#define pb         push_back
#define sp          printf(" ")
#define nl          '\n'
#define all(a) a.begin(),a.end()
#define unique(c) (c).resize(unique(all(c)) - (c).begin())
#define itn int

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

#define REP(i,start,end) for (int i = start; i <=end; i++)
#define RREP(i,end,start) for (int i=end; i>=start ;i--)

typedef long long LL;
LL INF=1e18;
LL dp[21][21][21];

LL query(int x2,int y2, int x1,int y1, int k)
{
    return dp[x2][y2][k]-dp[x2][y1][k]-dp[x1][y2][k]+dp[x1][y1][k];
}

LL kadane(LL *arr,int k)
{
    LL sum=-INF;
    LL ans=-INF;
    REP(i,0,k-1)
    {
        sum=max(arr[i],sum+arr[i]);
        ans=max(ans,sum);
    }
    return ans;
}
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    LL ans=0;
    set0(dp);
    REP(i,1,a) REP(j,1,b) REP(k,1,c)
    {
        cin>>dp[i][j][k];
        ans+=dp[i][j][k];
    }
    REP(k,1,c) REP(i,1,a) REP(j,1,b)
    {
        dp[i][j][k]+=dp[i-1][j][k];
        dp[i][j][k]+=dp[i][j-1][k];
        dp[i][j][k]-=dp[i-1][j-1][k];
    }
    REP(si,1,a) REP(ei,si,a) REP(sj,1,b) REP(ej,sj,b)
    {
        LL arr[c];
        REP(i,0,c-1)
            arr[i]=query(ei,ej,si-1,sj-1,i+1);
        ans=max(ans,kadane(arr,c));
    }
    cout<<ans<<nl;
}
int main()
{
    fast;
    int t;
    int f=0;
    cin>>t;
    while(t--)
    {
        if(f==0)
            f=1;
        else
            cout<<nl;
        solve();
    }
        
}
