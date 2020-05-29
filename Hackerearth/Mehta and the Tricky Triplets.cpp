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

int get_mask(LL x)
{
    int mask=0;
    while(x)
    {
        int r=x%10;
        x/=10;
        if(r==2)
            mask|=1;
        if(r==3)
            mask|=(1<<1);
        if(r==5)
            mask|=(1<<2);
        if(r==7)
            mask|=(1<<3);
    }
    return mask;
}
int n;
LL arr[100005];
LL mask[100005]={0};
LL dp[100005][4][16];
solve(int i, int o, int m)
{
    if(o>3)
        return 0;
    if(i==n)
    {
        if(o==3&&m)
            return 1;
        return 0;
    }
    if(dp[i][o][m]!=-1)
        return dp[i][o][m];
    return dp[i][o][m]=solve(i+1,o,m)+solve(i+1,o+1, m&mask[i]);
           
}
int main()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mask[i]=get_mask(arr[i]);
    }
    solve(0,0,15);
}
