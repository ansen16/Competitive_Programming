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
LL INF=1e18;

LL city[5][5];

pii conv(int r)
{
    return {r/5,r%5};
}
LL dist(int x1, int y1, int x2, int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}
LL func(int i1,int i2,int i3,int i4,int i5)
{
    vector<pii> v;
    v.pb(conv(i1));
    v.pb(conv(i2));
    v.pb(conv(i3));
    v.pb(conv(i4));
    v.pb(conv(i5));
    LL cost=0;
    REP(i,0,4) REP(j,0,4){
        LL cx=INF;
        REP(k,0,4)
            cx=min(cx,dist(i,j,v[k].fs,v[k].sc));
        cost+=cx*city[i][j];
    }
    return cost;
}
void solve()
{
    set0(city);
    int n;
    cin>>n;
    REP(i,1,n)
    {
        int x,y,z;
        cin>>x>>y>>z;
        city[x][y]=z;
    }
    int a1,a2,a3,a4,a5;
    LL cost=INF;
    REP(i1,0,24) REP(i2,i1+1,24) REP(i3,i2+1,24)
    REP(i4,i3+1,24) REP(i5,i4+1,24)
    {
        LL cx=func(i1,i2,i3,i4,i5);
        if(cx<cost)
        {
            cost=cx;
            a1=i1;
            a2=i2;
            a3=i3;
            a4=i4;
            a5=i5;
        }
    }
    cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<nl;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
