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

#define INF 1e9

void solve()
{
    int e,f;
    cin>>e>>f;
    int cap=f-e;
    int n;
    cin>>n;
    int val[n];
    int wt[n];
    for(int i=0;i<n;i++)
        cin>>val[i]>>wt[i];
    int dp[cap+1];
    for(int j=0;j<=cap;j++)
            dp[j]=INF;
    dp[0]=0;
    for(int i=0;i<n;i++)
        for(int j=cap;j>=0;j--)
            for(int k=0;j+k*wt[i]<=cap;k++)
                if(dp[j]!=INF)
                    dp[j+k*wt[i]]=min(dp[j+k*wt[i]],k*val[i]+dp[j]);
    if(dp[cap]==INF)
        cout<<"This is impossible.\n";
    else
        cout<<"The minimum amount of money in the piggy-bank is "<<dp[cap]<<".\n";

}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
