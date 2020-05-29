#include <bits/stdc++.h>
using namespace std;

#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define INF 1e9
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++)
typedef long long LL;
#define mod 1000000007


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
LL fact[5005];
void precompute()
{
	fact[0]=1;
	for(LL i=1;i<=5000;i++)
	{
		fact[i]=i*fact[i-1];
		fact[i]%=mod;
	}	
}
LL ncr(LL n, LL r)
{
	if(r==0)
		return 1;
	if(n<r)
		return 0;
	return (((fact[n]*inv(fact[r],mod))%mod)*inv(fact[n-r],mod))%mod;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    LL ans=0;
    for(int i=0;i<=k;i++)
    {
        ans+=ncr(n,i);
        ans%=mod;
    }
    cout<<ans<<'\n';

   
}
int main()
{
    fast;
    precompute();
    int t;
    cin>>t;
    while(t--)
        solve();
}
