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

const int mxn=500005;
int px[mxn];
multiset<pii> range;
int dp[mxn];

void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    px[0]=0;

    for(int i=0;i<s.size();i++)
    {
        px[i+1]=px[i];
        px[i+1]+=(s[i]=='A');
        px[i+1]-=(s[i]=='B');
    }
    range.insert({0,0});
    dp[0]=0;

    for(int i=1;i<=n;i++)
    {
        if(i>k)
            range.erase(range.find({dp[i-k-1],px[i-k-1]}));
        auto x=*dp.begin();
        dp[i]=x.fs+(px[i]<=x.sc);
        range.insert({dp[i],px[i]});
    }
    cout<<dp[n]<<nl;

}
int main()
{
    fast;
        solve();
}
