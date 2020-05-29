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

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<double> vd;



LL A[2][2]={{1,1},{1,0}};
int n,q;
LL arr[100005];
LL t[4*100005];
void multiply2()
{
    LL a=(A[0][0])%mod+(A[0][1])%mod;
    LL b=(A[0][0])%mod;
    LL c=(A[1][0])%mod+(A[1][1])%mod;
    LL d=(A[1][0])%mod;
    A[0][0]=a%mod;
    A[0][1]=b%mod;
    A[1][0]=c%mod;
    A[1][1]=d%mod;
    
}
void multiply1()
{
    LL a=(A[0][0]*A[0][0])%mod+(A[0][1]*A[1][0])%mod;
    LL b=(A[0][0]*A[0][1])%mod+(A[0][1]*A[1][1])%mod;
    LL c=(A[1][0]*A[0][0])%mod+(A[1][1]*A[1][0])%mod;
    LL d=(A[1][0]*A[0][1])%mod+(A[1][1]*A[1][1])%mod;
    A[0][0]=a%mod;
    A[0][1]=b%mod;
    A[1][0]=c%mod;
    A[1][1]=d%mod;
}
void pow(LL x)
{
    if(x==0||x==1)
        return;
    pow(x/2);
    multiply1();
    if(x&1)
        multiply2();
}
LL fibo(LL x)
{
    if(x==0||x==1)
        return x;
    A[0][0]=1;
    A[0][1]=1;
    A[1][0]=1;
    A[1][1]=0;
    pow(x-1);
    A[0][0]%=mod;
    return A[0][0];
    
}

void build(int v, int tl, int tr)
{
    if(tl==tr)
    {
        t[v]=arr[tl];
        return;
    }
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    t[v]=__gcd(t[2*v],t[2*v+1]);
}
LL query(int v, int tl, int tr, int l, int r)
{
    if(l>r)
        return 0;
    if(tl==tr)
        return t[v];
    int tm=(tl+tr)/2;
    return __gcd(query(v*2,tl,tm,l,min(tm,r))
                ,query(v*2+1,tm+1,tr,max(tm+1,l),tr));
}
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    build(1,1,n);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        LL x=query(1,1,n,l,r);
        cout<<fibo(x)<<nl;
    }
    
}
int main()
{
    fast;
        solve();
}
