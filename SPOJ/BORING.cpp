#include <bits/stdc++.h>
using namespace std;

#define nl '\n' 
 
typedef unsigned long long LL;

LL mod;
 
//modular exponentiation
LL powm(LL x, LL y)
{
    if(y==0)
        return 1;
    if(y==1)
        return x%mod;
    if(y&1)
        return (x*(powm((x*x)%mod,y/2)))%mod;
    return powm((x*x)%mod,y/2);
}
 
 
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t;
    cin>>t;
    while(t--)
    {
        LL n,p;
        cin>>n>>p;
        mod=p;
        if(n>=p){
            cout<<0<<nl;
            continue;
        }
        LL ans=p-1;
        ans%=mod;
        for(LL i=n+1;i<p;i++)
        {
            ans*=i;
            ans%=mod;
        }
        cout<<powm(ans,p-2)<<nl;
        
    }
 
 
 
}