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

bool custom(pii a, pii b)
{
    if(a.fs==b.fs)
        return a.sc>b.sc;
    return a.fs<b.fs;
}
void solve()
{
    int n;
    cin>>n;
    vector<pii > v(n);
    REP(i,0,n-1)
        cin>>v[i].fs>>v[i].sc;
    sort(all(v),custom);
    
    vi v1;
    REP(i,0,n-1)
        v1.pb(v[i].sc);
    reverse(all(v1));
    vi dp;
    REP(i,0,n-1)
    {
        int x=upper_bound(all(dp),v1[i])-dp.begin();
        if(x==dp.size())
            dp.pb(v1[i]);
        else
            dp[x]=v1[i];
    }
    cout<<dp.size()<<nl;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
