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
#define RREP(i,start,end) for (int i=end; i>=start ;i--)

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



void solve()
{
    int n,q;
    cin>>n>>q;
    LL a[2][n+1];
    a[0][0]=0;
    a[1][0]=0;
    REP(i,1,n)
        cin>>a[0][i];
    REP(i,1,n)
        cin>>a[1][i];
    for(int i=2;i<=n;i+=2)
        swap(a[0][i],a[1][i]);
    REP(i,1,n)
    {
        a[0][i]+=a[0][i-1];
        a[1][i]+=a[1][i-1];
    }
    while(q--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        x^=(1-(y&1));
        cout<<(a[x][z]-a[x][y-1])<<nl;
    }



}
int main()
{
    fast;
        solve();
}
