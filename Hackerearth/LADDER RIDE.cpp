#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multi_set;

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
#define unique(c) (c).resize(unique(all(c)) - (c).begin())
#define itn int

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

#define REP(i,start,end) for (int i = start; i <=end; i++)
#define RREP(i,start,end) for (int i=end; i>=start ;i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<double> vd;
typedef vector<vector<LL> > matrix;
typedef vector<vector<int> > graph;

LL dp1[1000005]={0};

void precompute()
{
    dp1[0]=1;
    REP(i,1,1000000)
    {
        if(i-2>=0)
        {
            dp1[i]+=dp1[i-2];
            dp1[i]%=mod;
        }
        if(i-5>=0)
        {
            dp1[i]+=dp1[i-5];
            dp1[i]%=mod;
        }
    }
}

void solve(int n)
{
    LL c,k;
    cin>>c>>k;
    if(k>c)
    {
        cout<<dp1[c]<<nl;
        return;
    }
    if(k==5)
        k=1e15;
    LL dp[c+1]={0};
    dp[0]=1;
    REP(i,1,c)
    {
        if(i-2>=0)
        {
            dp[i]+=dp[i-2];
            dp[i]%=mod;
        }
        if(i-5>=0)
        {
            dp[i]+=dp[i-5];
            dp[i]%=mod;
        }
        if(i-k>=0)
        {
            dp[i]+=dp[i-k];
            dp[i]%=mod;
        }
    }
    cout<<dp[c]<<nl;
}   
int main()
{
    fast;
    precompute();
    int t,n;
    cin>>t>>n;
    while(t--)
        solve(n);
}
