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
//
// mod inverse
LL inv(LL x, LL m)
{
    return powm(x,m-2,m);
}
//
void solve()
{
    int A[20][2],B[20][2];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i][0]>>A[i][1];
    for(int i=0;i<n;i++)
        cin>>B[i][0]>>B[i][1];
    int dp[1<<n];
    for(int i=0;i<(1<<n);i++)
        dp[i]=1e9;
    dp[0]=0;
    for(int mask=0;mask<(1<<n);mask++)
    {
        int pos=__builtin_popcount(mask);
        for(int j=0;j<n;j++)
        {
            if((mask>>j)&1)
                continue;
            dp[mask|(1<<j)]=min(dp[mask|(1<<j)],dp[mask]+abs(B[j][0]-A[pos][0])+abs(B[j][1]-A[pos][1]));
        }
    }
    cout<<dp[(1<<n)-1]<<'\n';
}
int main()
{
    fast;
        solve();
}
