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
#define unique(c) (c).resize(unique(all(c)) - (c).begin())
#define itn int

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

#define REP(i,n) for (int i = 0; i < n; i++)
#define REP1(i,n) for (int i = 1; i <= n; i++)
#define RREP(i,n) for (int i=n-1; i>=0 ;i--)

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


//modular exponentiation
LL powm(LL x, LL y,LL m)
{
    if(y==0)
        return 1;
    if(y==1)
        return x%m;
    if(y&1)
        return (x*(powm((x*x)%m,y/2,m)))%m;
    return powm((x*x)%m,y/2,m)%m;
}
//
// mod inverse
LL inv(LL x, LL m)
{
    return powm(x,m-2,m);
}
//
void solve()
{
    int n;
    cin>>n;
    int mp[270]={0};
    REP(i,n)
    {
        char x;
        int y;
        cin>>x>>y;
        mp[x]=y;
    }
    double sum=0;
    int m;
    cin>>m;
    string s;
    getline(cin,s);
    REP(i,m)
    {
        getline(cin,s);
        REP(j,s.size())
            sum+=mp[(char)s[j]];
    }
    sum/=100;
    cout<<setprecision(2)<<fixed<<sum<<"$"<<nl;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
