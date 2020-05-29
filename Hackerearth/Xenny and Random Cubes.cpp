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


void solve()
{
    int n,k;
    cin>>n>>k;
    char arr[n][6];
    for(int i=0;i<n;i++)
        for(int j=0;j<6;j++)
            cin>>arr[i][j];
    string s;
    cin>>s;
    int dp[1<<n];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int mask=0;mask<(1<<n);mask++)
    {
        int x=__builtin_popcount(mask);
        if(x>=k)
            continue;
        for(int j=0;j<n;j++)
        {
            if(mask&(1<<j))
                continue;
            for(int k=0;k<6;k++)
                if(arr[j][k]==s[x])
                    dp[mask|(1<<j)]+=dp[mask];
        }
    }
    LL ans=0;
    for(int mask=0;mask<(1<<n);mask++)
    {
        int x=__builtin_popcount(mask);
        if(x==k)
            ans+=dp[mask];
    }
    cout<<ans<<nl;
}
int main()
{
    fast;
        solve();
}
