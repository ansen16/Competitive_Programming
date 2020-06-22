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

LL t,w,n;
LL d[35],v[35];
LL dp[1005][35];
bool dp2[1005][35];
LL func(LL tx, int i)
{
    if(i==n)
        return 0;
    LL &r=dp[tx][i];
    if(r!=-1)
        return r;
    dp2[tx][i]=0;
    r=func(tx,i+1);
    if(tx>=3*d[i])
    {
        LL rx=v[i]+func(tx-3*d[i],i+1);
        if(rx>=r)
        {
            r=rx;
            dp2[tx][i]=1;
        }
    }  
    return r;
}
void solve()
{
    setneg(dp);
    set0(dp2);
    cin>>w>>n;
    REP(i,0,n-1)
    {
        cin>>d[i]>>v[i];
        d[i]*=w;
    }
    cout<<func(t,0)<<nl;
    int i=t,j=0;
    vector< pii > ans;
    while(j<n)
    {
        if(dp2[i][j])
        {
            ans.pb({d[j]/w,v[j]});
            i-=3*d[j];
        }
        j++;
    }
    cout<<ans.size()<<nl;
    for(auto x: ans)
        cout<<x.fs<<" "<<x.sc<<nl;

}
int main()
{
    fast;
    int f=1;
    while(cin>>t)
    {
        if(f)
            f=0;
        else
            cout<<nl;
        solve();
    }
        
}
