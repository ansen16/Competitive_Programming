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

int adj[105][105];
int c=0;
void solve(int a, int b)
{
    REP1(i,100) REP1(j,100)
        (i==j) ? adj[i][j]=0 : adj[i][j]=1e9;
    while(a!=0)
    {
        adj[a][b]=1;
        cin>>a>>b;
    }
    REP1(k,100) REP1(i,100) REP1(j,100)
        adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
    
    float sum=0;
    int cnt=0;
    REP1(i,100) REP1(j,100)
    {
        if(i!=j&&adj[i][j]!=1e9)
        {
            sum+=adj[i][j];
            cnt++;
        }
    }
    float ans=sum/cnt;
    cout<<"Case "<<c<<": average length between pages = "<<setprecision(3)<<fixed<<ans<<" clicks"<<nl;
}
int main()
{
    fast;
    int a,b;
    cin>>a>>b;
    while(a!=0)
    {
        c++;
        solve(a,b);
        cin>>a>>b;
    }
        
}
