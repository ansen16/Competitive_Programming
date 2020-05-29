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
LL INF=1e9;
#define int long long 

void solve()
{
    int d,n;
    cin>>d>>n;
    int grid[1025][1025]={0};
    int x[n],y[n],s[n];
    REP(i,0,n-1)
        cin>>x[i]>>y[i]>>s[i];
    REP(i,0,n-1)
    {
        int ld=max(1LL,x[i]-d);
        int rd=min(1024LL,x[i]+d);
        int lh=max(0LL,y[i]-d-1);
        int rh=min(1024LL,y[i]+d);
        REP(j,ld,rd)
        {
            grid[j][rh]+=s[i];
            grid[j][lh]-=s[i];
        }
    }
    LL a=-1,b,c;
    REP(i,1,1024)
    {
        int sz=0;
        RREP(j,1024,1)
        {
            sz+=grid[i][j];
            grid[i][j]=sz;  
        }
    }
    REP(i,1,1024)
        REP(j,1,1024)
            if(grid[i][j]>a)
            {
                a=grid[i][j];
                b=i;
                c=j;
            }

    cout<<b<<" "<<c<<" "<<a<<nl;
    

}
signed main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
