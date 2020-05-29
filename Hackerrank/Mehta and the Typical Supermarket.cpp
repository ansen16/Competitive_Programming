#include <bits/stdc++.h>
using namespace std;


#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define nl          '\n'

#define REP(i,start,end) for (int i = start; i <=end; i++)
#define RREP(i,end,start) for (int i=end; i>=start ;i--)

typedef long long LL;
LL INF=2e18;

const int N=17;
LL dp1[(1<<N)+5];
int dp2[(1<<N)+5];

LL trunc_mul(LL a, LL b)
{
    return ( (a>INF/b)? INF: a*b);
}
void solve()
{
    LL n;
    cin>>n;
    LL arr[n];
    REP(i,0,n-1)
        cin>>arr[i];
    for(int mask=1;mask<(1<<n);mask++)
    {
        LL lcm=1;
        int k=__builtin_popcount(mask);
        REP(j,0,n)
            if((1<<j)&mask)
                lcm=trunc_mul(lcm/__gcd(lcm,arr[j]),arr[j]);
                
        dp1[mask]=lcm;
        dp2[mask]= ((k&1)? 1: -1);
    }
    int d;
    cin>>d;
    while(d--)
    {
        LL l,r;
        cin>>l>>r;
        l--;
        LL ans1=0;
        LL ans2=0;
        REP(i,1,(1<<n)-1)
        {
            ans1+= (r/dp1[i])*dp2[i];
            ans2+= (l/dp1[i])*dp2[i];
        }
        cout<<ans1-ans2<<nl;
    }
}
int main()
{
    fast;
        solve();
}
