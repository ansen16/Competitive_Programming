#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
#define itn int

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

#define REP(i,n) for (int i = 0; i < n; i++)
#define REP1(i,n) for (int i = 1; i <= n; i++)

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


bool adj[11][11]={0};
void solve()
{
    int n,m;
    cin>>n>>m;
    REP(i,m)
    {
        int x,y;
        cin>>x>>y;
        adj[x][y]=1;
        adj[y][x]=1;
    }
    bool dp[1<<n][n]={0};
    for(int j=0;j<n;j++)
    {
        dp[(1<<j)][j]=1;
    }
    for(int mask=1;mask<1<<n;mask++)
    {
        for(int j=0;j<n;j++)
        {
            if(dp[mask][j]==0)
                continue;
            for(int k=0;k<n;k++)
            {
                if((mask>>k)&1)
                    continue;
                dp[mask|(1<<k)][k]=adj[j][k];
            }
        }
    }
    string ans="NO";
    for(int i=0;i<n;i++)
    {
        if(dp[(1<<n)-1][i]==1)
        {
            ans="YES";
            break;
        }
    }
    cout<<ans<<nl;
}
int main()
{
    fast;
        solve();
}
