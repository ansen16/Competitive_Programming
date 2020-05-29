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
    LL n,u;
    cin>>n>>u;
    LL arr[n+1]={0};
    cerr<<u<<nl;
    while(u--)
    {
        LL l,r,val;
        cin>>l>>r>>val;
        arr[l]+=val;
        arr[r+1]-=val;
    }
    for(int i=1;i<=n;i++)
        arr[i]+=arr[i-1];
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        cout<<arr[x]<<nl;
    }
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
