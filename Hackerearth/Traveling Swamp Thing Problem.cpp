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
int INF=1e9;

int dist[15][15];
int ene[15][15];
int dp[(1<<15)][15][105];
int n,m,e;

int func(int mask,int x, int e)
{
    if(e<0)
        return INF;
    int k=__builtin_popcount(mask);
    if(k==n)
        return 0;
    int &r=dp[mask][x][e];
    if(r!=-1)
        return r;
    int ans=INF;
    REP(j,0,n-1)
    {
        if(mask&(1<<j))
            continue;
        ans=min(ans, func(mask|(1<<j),j,e-ene[x][j]) +dist[x][j]);
    }
    return r=ans;
}

void solve()
{
    
    cin>>n>>m>>e;
    REP(i,0,n-1)
        REP(j,0,n-1)
        {
            dist[i][j]=1e9;
            ene[i][j]=1e9;
        }
    setneg(dp);
    while(m--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;
        b--;
        dist[a][b]=c;
        dist[b][a]=c;
        ene[a][b]=d;
        ene[b][a]=d;
    }
    int ans= func(1,0,e);
    if(ans==INF)
        ans=-1;
    cout<<ans<<nl;
}
int main()
{
    fast;
        solve();
}
