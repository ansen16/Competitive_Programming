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
#define unique(c) (c).resize(unique(ALL(c)) - (c).begin())
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
typedef vector<vector<int>> graph;


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
void solve(int n)
{
    unordered_map<string,int> mp;
    vector<string> v;
    REP(i,n)
    {
        string s;
        cin>>s;
        v.pb(s);
        mp[s]=i;
    }
    vector<int> a;
    vector<int> b;
    a.assign(n,0);
    b.assign(n,0);
    REP(i,n)
    {
        string s;
        cin>>s;
        int x,y;
        cin>>x>>y;
        if(y==0)
        {
            continue;
        }
        int give=x/y;
        REP(j,y)
        {
            string k;
            cin>>k;
            a[mp[k]]+=give;
            b[mp[s]]-=give;
        }
    }
    REP(i,n)
        cout<<v[i]<<" "<<a[mp[v[i]]]+b[mp[v[i]]]<<nl;

}
int main()
{
    fast;
    bool p=1;
    int n;
    while(cin>>n)
    {
        if(p==1)
            p=0;
        else
            cout<<nl;
        solve(n);
    }
        
}
