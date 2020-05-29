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

graph garments;
int m,c;
int dp[205][25];
int func(int i, int j)
{
    if(j==c)
        return m-i;
    int &r =dp[i][j];
    if(r!=-1)
        return r;
    int ans=-2;
    for(auto x: garments[j])
    {
        if(i-x>=0)
            ans=max(ans,func(i-x,j+1));
    }
    return r=ans;
}
void solve()
{
    setneg(dp);
    cin>>m>>c;
    garments.clear();
    garments.resize(c);
    REP(i,0,c-1)
    {
        int k;
        cin>>k;
        REP(j,0,k-1)
        {
            int x;
            cin>>x;
            garments[i].pb(x);
        }
    }
    func(m,0);
    if(dp[m][0]==-2)
        cout<<"no solution"<<nl;
    else
        cout<<dp[m][0]<<nl;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
