#include <bits/stdc++.h>
using namespace std;

#define mod         1000000007
#define pi          acos(-1.0)
#define eps         1e-9


#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define nl          '\n'

#define REP(i,start,end) for (int i = start; i <=end; i++)
#define RREP(i,end,start) for (int i=end; i>=start ;i--)

typedef long long LL;
typedef long double LD;
LL INF=1e9;

const LL maxn=55;
LD C[maxn + 1][maxn + 1]={0};

void precompute()
{
    C[0][0] = 1;
    for (LL n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (LL k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }
}
void solve()
{
    LL n;
    cin>>n;
    LL arr[n+1];
    arr[0]=-1000000;
    REP(i,1,n)
        cin>>arr[i];
    sort(arr,arr+n+1);
    LD ans=0;
    REP(i,1,n)
    {
        int r=i;
        while(arr[r]==arr[i])
            r--;
        int greater=n-r-1;
        smaller=r;
        REP(p,1,n)
        {
            REP(k,0,min(smaller,p-1))
            {
                if(k==p-1)
                    ans+= (k+1)*C[smaller][k]/(n*C[n-1][k]);
                else
                    ans+= (k+1)*C[smaller][k]*greater/(n*(n-1)*c[n-2][k]);
            }
        }
    }
    cout<<setprecision(2)<<fixed<<ans<<nl;
}
int main()
{
    fast;
    precompte();
    int t;
    cin>>t;
    while(t--)
        solve();
}
