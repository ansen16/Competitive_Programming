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
LL INF=1e18;

LL grid[101][101]={0};

LL query(int x1, int y1, int x2, int y2)
{
    return grid[x2][y2]-grid[x1-1][y2]-grid[x2][y1-1]+grid[x1-1][y1-1];
}
void solve(int t)
{
    int n,m,k;
    cin>>n>>m>>k;
    REP(i,1,n) REP(j,1,m)
        cin>>grid[i][j];
    LL area=0;
    LL ans=0;
    REP(i,1,n)  REP(j,1,m)
        grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
    REP(i,1,n) REP(j,1,m) REP(ix,i,n) REP(jx,j,m)
    {
        LL ax= (ix-i+1)*(jx-j+1);
        LL cost= query(i,j,ix,jx);
        if(cost<=k)
        {
            if(ax>area)
            {
                area=ax;
                ans=cost;
            }
            else if(area==ax)
            {
                ans=min(ans,cost);
            }
        }
    }
    cout<<"Case #"<<t<<": "<<area<<" "<<ans<<nl;
}
int main()
{
    fast;
    int t;
    cin>>t;
    REP(i,1,t)
        solve(i);
}
