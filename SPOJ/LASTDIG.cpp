#include <bits/stdc++.h>
using namespace std;

#define nl          '\n'
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

void solve()
{
    LL a,b;
    cin>>a>>b;
    cout<<powm(a,b,10)<<nl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
