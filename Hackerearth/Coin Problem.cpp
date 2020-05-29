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
#define RREP(i,start,end) for (int i=end; i>=start ;i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<double> vd;
typedef vector<vector<LL> > matrix;
typedef vector<vector<int> > graph;

LL dp[1000005][3];

void precompute()
{
    dp[1][0]=1;
    dp[1][1]=1;
    dp[1][2]=0;
    REP(i,2,1000000)
    {
        dp[i][0]=dp[i-1][1]+dp[i-1][2]+dp[i-1][0];
        dp[i][0]%=mod;
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][1];
    }
}
void solve()
{
    int n;
    cin>>n;
    LL ans=dp[n][0]+dp[n][1]+dp[n][2];
    ans%=mod;
    cout<<ans<<nl;
}
int main()
{
    fast;
    precompute();
    int t;
    cin>>t;
    while(t--)
        solve();
}
