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

int m,s;
int dp[305][305];
int x[45],y[45];
int func(int i,int j)
{
    if(s*s==i*i+j*j)
        return 0;
    if(s*s<i*i+j*j)
        return INF;
    int &r=dp[i][j];
    if(r!=-1)
        return r;
    r=INF;
    REP(k,0,m-1)
    {
        if(i+x[k]<=s and j+y[k]<=s)
            r=min(r,1+func(i+x[k],j+y[k]));
    }
    return r;
}
void solve()
{
    cin>>m>>s;
    setneg(dp);
    REP(i,0,m-1)
        cin>>x[i]>>y[i];
    int ans=func(0,0);
    if(ans==INF)
        cout<<"not possible"<<nl;
    else
        cout<<ans<<nl;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
