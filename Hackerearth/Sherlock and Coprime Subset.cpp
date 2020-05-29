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

int prim[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int p=15;
int mask[50];
int n;
unordered_map<int,int> mp;

int dp[55][(1<<15)+5];

int func(int i, int m)
{
    if(i==n)
        return 0;
    
    int &r=dp[i][m];
    if(r!=-1)
        return r;
    
    int ans=0;
    ans=max(ans,func(i+1,m));
    if(!(mask[i]&m))
        ans=max(ans,1+func(i+1, m|mask[i]));
    return r=ans;
}
void solve()
{
    setneg(dp);
    cin>>n;
    REP(i,0,n-1)
    {
        int m=0;
        int x;
        cin>>x;
        REP(j,0,14)
        {
            if((x%prim[j])==0)
                m|=(1<<mp[prim[j]]);
        }
        mask[i]=m;
    }
    cout<<func(0,0)<<nl;
}
int main()
{
    fast;
    int t;
    cin>>t;
    REP(i,0,14)
        mp[prim[i]]=i;
    while(t--)
        solve();
}
