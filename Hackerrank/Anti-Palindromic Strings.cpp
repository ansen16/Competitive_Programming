#include <bits/stdc++.h>

using namespace std;
#define mod         1000000007

#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define nl          '\n'

#define REP(i,start,end) for (int i = start; i <=end; i++)
#define RREP(i,end,start) for (int i=end; i>=start ;i--)

typedef long long LL;

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

void solve()
{
    LL n,m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<m<<nl;
        return;
    }
    if(m==1)
    {
        cout<<0<<nl;
        return;
    }
    LL ans=m-1;
    ans*=m;
    ans%=mod;
    ans*=powm(m-2,n-2,mod);
    ans%=mod;
    cout<<ans<<nl;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
