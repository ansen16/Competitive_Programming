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
LL inv(LL x, LL m)
{
    return powm(x,m-2,m);
}
LL fact[200005];
void precompute()
{
    fact[0]=1;
    for(LL i=1;i<=200005;i++)
    {
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
    }    
}
LL ncr(LL n, LL r)
{
	if(n<r)
        return 0;
    if(r==0)
        return 1;
    return (((fact[n]*inv(fact[r],mod))%mod)*inv(fact[n-r],mod))%mod;
}
void solve()
{
    string s;
    cin>>s;
    unordered_map<char,LL> mp;
    int n=s.size();
    for(char x: s)
        mp[x]++;
    vector<LL> v[2];
    for(char i='a';i<='z';i++)
        v[mp[i]&1].pb(mp[i]);
    if(v[1].size()>1)
    {
        cout<<0<<nl;
        return;
    }
    LL num=0;
    for(auto x: v[0])
        num+=x/2;
    if(!v[1].empty())
        num+=v[1][0]/2;
    LL ans=fact[num];
    for(LL x:v[0])
    {
        ans*=inv(fact[x/2]);
        ans%=mod;
    }
    if(!v[1].empty())
        ans*=inv(fact[v[1][0]/2]);
    ans%mod;
    cout<<ans<<nl;
}
int main()
{
    fast;
    precompute();
        solve();
}
