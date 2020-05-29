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


void solve(int n,int m)
{
    vector<int> p(n);
    iota(all(p),0);
    vi a,b,c;
    REP(i,1,m)
    {
        int x,y,z;
        cin>>x>>y>>z;
        a.pb(x);
        b.pb(y);
        c.pb(z);
    }
    int ans=0;
    do
    {
        int mp[10];
        REP(i,0,n-1)
        {
            mp[p[i]]=i;
        }
        bool flag=1;
        REP(i,0,m-1)
        {
            //cerr<<mp[a[i]]<<" "<<mp[b[i]]<<" "<<c[i]<<nl;
            if(c[i]>0)
                flag&=(abs(mp[a[i]]-mp[b[i]]) <=( c[i]));
            else
                flag&=(abs(mp[a[i]]-mp[b[i]]) >= (c[i]*(-1)));
        }
        ans+=flag;
       
    } while (next_permutation(all(p)));
    cout<<ans<<nl;
    
}

int main()
{
    fast;
    int n,m;
    while(cin>>n>>m,n)
        solve(n,m);
}
