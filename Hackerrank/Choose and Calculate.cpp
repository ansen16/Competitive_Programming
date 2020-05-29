#include <bits/stdc++.h>
using namespace std;

#define mod         1000000007


#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define nl          '\n'

#define REP(i,start,end) for (int i = start; i <=end; i++)
#define RREP(i,end,start) for (int i=end; i>=start ;i--)

typedef long long LL;

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
    LL n,k;
    cin>>n>>k;
    LL arr[n];
    REP(i,0,n-1)
        cin>>arr[i];
    sort(arr,arr+n);
    LL ans1=0;
    LL ans2=0;
    REP(i,0,n-1)
    {
        LL mx=ncr(i,k-1);
        LL mn=ncr(n-1-i,k-1);
        ans1+=mx*arr[i];
        ans1%=mod;
        ans2+=mn*arr[i];
        ans2%=mod;
    }
    ans1-=ans2;
    ans1%=mod;
    ans1+=mod;
    ans1%=mod;
    cout<<ans1<<nl;


}
int main()
{
    fast;
    precompute();
    solve();
}
