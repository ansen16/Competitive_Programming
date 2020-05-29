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

int n;
const LL mxn=500005;
LL phi[mxn+1];
LL dp[mxn+1]={0};
LL BIT[1000005]={0};

void update(int i, LL x)
{
    while(i<=n)
    {
        BIT[i]+=x;
        BIT[i]%=mod;
        i+=(i&(-i));
    }
}
LL query(int i)
{
    LL sum=0;
    while(i>0)
    {
        sum+=BIT[i];
        sum%=mod;
        i-=(i&(-i));
    }
    return sum;
}
void precompute()
{
    for(LL i=0;i<mxn;i++)
        phi[i]=i;
    phi[1]=1;
    for(LL i=2;i<mxn;i++)
    {
        if(phi[i]==i)
        {   
            phi[i]--;
            for(LL j=i*2;j<mxn;j+=i)
                phi[j]-=(phi[j]/i);
        }
    }
    dp[0]=0;
    for(LL i=1;i<mxn;i++)
        for(LL j=i;j<mxn;j+=i)
            dp[j]+=(i*phi[j/i]);
    for(LL i=1;i<mxn;i++)
        dp[i]%=mod;

}
void solve()
{
    LL q,x,y;
    char c;
    cin>>n;
    LL arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        dp[arr[i]]%=mod;
        update(i,dp[arr[i]]);
    }
    cin>>q;
    while(q--)
    {
        cin>>c>>x>>y;
        if(c=='C')
        {
            LL r=query(y);
            LL l=0;
            if(x>1)
                l=query(x-1);
            LL ans=r-l;
            ans%=mod;
            ans+=mod;
            ans%=mod;
            cout<<ans<<nl;
        }
        else{
            LL upd=dp[y]-dp[arr[x]];
            upd%=mod;
            upd+=mod;
            upd%=mod;
            update(x,upd);
            arr[x]=y;
        }
    }
    
    
}
int main()
{
    fast;
    precompute();
        solve();
}
