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

LL dp[205][15][25];
int a[205];
int n,q;
int st=1;
int m,d;

LL func(int i, int j, int k)
{
    if(j==m)
        return (k==0);
    if(i==n)
        return 0;
    LL &r= dp[i][j][k];
    if(r!=-1)
        return r;
    r=func(i+1,j,k);
    int rem=a[i]%d;
    rem=k-rem;
    rem%=d;
    rem+=d;
    rem%=d;
    r+=func(i+1,j+1,rem);
    return r;
}
void solve()
{
    REP(i,0,n-1)
        cin>>a[i];
    cout<<"SET "<<st++<<":"<<nl;
    REP(i,1,q)
    {
        cin>>d>>m;
        setneg(dp);
        cout<<"QUERY "<<i<<": "<<func(0,0,0)<<nl;
    }
}
int main()
{
    fast;
    while(cin>>n>>q,n)
        solve();
}
