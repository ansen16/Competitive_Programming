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

int grid[101][101];
void solve(int n)
{
    REP(i,1,n) REP(j,1,n)
        cin>>grid[i][j];
    vector<pair<int,pair<int,int> > > ans;
    REP(i,1,n) REP(j,i+1,n) REP(k,j+1,n)
    {
        int f12=grid[i][j];
        int f21=grid[j][i];
        int f23=grid[j][k];
        int f32=grid[k][j];
        int f13=grid[i][k];
        int f31=grid[k][i];

        stringstream ss;
        if(!(f12 or f21 or f31 or f13 or f23 or f32))
            ans.pb({i,{j,k}});
        else if(f12 and f23 and f31 and (!f21) and (!f32) and (!f13))
            ans.pb({i,{j,k}});
        else if(f13 and f32 and f21 and (!f31) and (!f23) and !(f12))
            ans.pb({k,{j,i}});
    }
    sort(all(ans));
    cout<<ans.size()<<nl;
    for(auto x: ans)
        cout<<x.fs<<" "<<x.sc.fs<<" "<<x.sc.sc<<nl;

}
int main()
{
    fast;
    int t;
    while(cin>>t)
        solve(t);
}
