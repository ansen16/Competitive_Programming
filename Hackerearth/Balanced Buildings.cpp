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
#define RREP(i,end,start) for (int i=end; i>=start ;i--)

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



void solve()
{
    LL n,s,m,p;
    cin>>n>>s>>m>>p;
    LL arr[n];
    REP(i,0,n-1)
        cin>>arr[i];
    LL dp[2505][2505];
    LL opt=-1e18;
    LL opt1=-1e18;
    REP(j,0,n-1)
    {
        LL ht=arr[j];
        if(arr[0]<=ht)
            dp[0][j]=-(p*(ht-arr[0]));
        else
            dp[0][j]=-(m*(arr[0]-ht));
        opt=max(opt,dp[0][j]);
    }
    REP(i,1,n-1)
    {
        REP(j,0,n-1)
        {
            LL cost;
            LL ht=arr[j];
            if(arr[i]<=ht)
                cost=(p*(ht-arr[i]));
            else
                cost=(m*(arr[i]-ht));
            dp[i][j]=max(dp[i-1][j]-cost+s,opt-cost);
            opt1=max(opt1,dp[i][j]);
        }
        opt=opt1;
        opt1=-1e18;
    }
    cout<<opt<<nl;
}
int main()
{
    fast;
        solve();
}
