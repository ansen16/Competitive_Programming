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
LL INF=1e9;

void solve(int t)
{
    int n;
    cin>>n;
    int a[n],dp1[n],dp2[n],l[n];
    REP(i,0,n-1)
        cin>>a[i];
    REP(i,0,n-1)
        cin>>l[i];
    int a1=0,a2=0;
    REP(i,0,n-1)
    {
        dp1[i]=l[i];
        REP(j,0,i-1)
            if(a[j]<a[i])
                dp1[i]=max(dp1[i],l[i]+dp1[j]);
        dp2[i]=l[i];
        REP(j,0,i-1)
            if(a[j]>a[i])
                dp2[i]=max(dp2[i],l[i]+dp2[j]);
        a1=max(a1,dp1[i]);
        a2=max(a2,dp2[i]);
    }
    cout<<"Case "<<t<<". ";
    if(a1>=a2)
        cout<<"Increasing ("<<a1<<"). Decreasing ("<<a2<<")."<<nl;
    else
        cout<<"Decreasing ("<<a2<<"). Increasing ("<<a1<<")."<<nl;

}
int main()
{
    fast;
    int t;
    cin>>t;
    REP(i,1,t)
        solve(i);
}
