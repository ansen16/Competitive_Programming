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
#define nl          '\n'

int dp[1005][22][80];
int ox,nit;
int n;
int cyl[1005][3];
int func(int n, int ox, int nit)
{
    if(n==0)
    {
        if(ox<=0&&nit<=0)
            return 0;
        else return 1e9;
    }
    int & x= dp[n][ox][nit];
    if(x!=-1)
        return x;
    return x= min(func(n-1, ox, nit), cyl[n][2]+func(n-1, max(0,ox-cyl[n][0]),max(0,nit-cyl[n][1])));
}
void solve()
{
    memset(dp,-1,sizeof(dp));
    cin>>ox>>nit;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>cyl[i][0]>>cyl[i][1]>>cyl[i][2];
    cout<<func(n,ox,nit)<<endl;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
