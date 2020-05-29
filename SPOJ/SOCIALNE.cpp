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

vector<vector<int>> adj,adj1;
vector<int> deg;
vector<int> fr;

void solve()
{
    deg.assign(55,0);
    fr.assign(55,0);
    adj.assign(55,vector<int>(55,0));
    string s;
    cin>>s;
    int n=s.size();
    REP(j,n)
    {
        adj[0][j]=(s[j]=='Y');
        deg[0]+=adj[0][j];
    }
        
    for(int i=1;i<n;i++)
    {
        cin>>s;
        REP(j,n)
        {
            adj[i][j]=(s[j]=='Y');
            deg[i]+=adj[i][j];
        }
    }
    adj1=adj;
    REP(k,n) REP(i,n) REP(j,n)
        adj1[i][j]|=(adj[i][k] & adj[k][j]);
    REP(i,n)
    {
        REP(j,n)
        {
            if(i==j)
                continue;
            fr[i]+=adj1[i][j];
        }

        cerr<<i<<" "<<fr[i]<<" "<<deg[i]<<nl; 
        fr[i]-=deg[i];
    } 
    int ans=-1;
    int id=-1;
    REP(i,n)
    {
        if(fr[i]>ans)
        {
            ans=fr[i];
            id=i;
        }
    }
    cout<<id<<" "<<ans<<nl;
    
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
