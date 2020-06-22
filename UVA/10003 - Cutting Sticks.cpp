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
vector<int> v;
int n;

int dp[55][55];

int func(int i,int j)
{
    if(i+1==j)
        return 0;
    int &r=dp[i][j];
    if(r!=-1)
        return r;
    r=INF;
    REP(k,i+1,j-1)
        r=min(r,func(i,k)+func(k,j)+v[j]-v[i]);
    return r;
}
void solve(int l)
{
    cin>>n;
    v.clear();
    setneg(dp);
    v.pb(0);
    REP(i,0,n-1)
    {
        int x;
        cin>>x;
        v.pb(x);
    }
    v.pb(l);
    cout<<"The minimum cutting is "<<func(0,n+1)<<"."<<nl;

}
int main()
{
    fast;
    int t;
    while(cin>>t,t)
        solve(t);
}
