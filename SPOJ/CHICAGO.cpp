#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
#define itn int

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

#define REP(i,n) for (int i = 0; i < n; i++)
#define REP1(i,n) for (int i = 1; i <= n; i++)

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


double adj[105][105]={0};

void solve(int n)
{
    int m;
    cin>>m;
    REP1(i,n) REP1(j,n)
        adj[i][j]= (i==j) ? 1 : 0;
    REP(i,m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        double p=c*1.0/100;
        adj[a][b]=p;
        adj[b][a]=p;
    }
    REP1(k,n) REP1(i,n) REP1(j,n)
        adj[i][j]=max(adj[i][j], adj[i][k]*adj[k][j]);

    double ans=adj[1][n];
    ans*=100;
    cout<<setprecision(6)<<fixed<<ans<<" percent"<<nl;


}
int main()
{
    fast;
    int n;
    cin>>n;
    while(n)
    {
        solve(n);
        cin>>n;
    }
        
}
