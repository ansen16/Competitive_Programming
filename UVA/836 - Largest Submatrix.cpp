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
LL INF=1e5;

int dp[26][26];

int query(int x2,int y2, int x1, int y1)
{
    return dp[x2][y2]-dp[x2][y1]-dp[x1][y2]+dp[x1][y1];
}
void solve()
{
    string s;
    cin>>s;
    set0(dp);    
    int n=s.size();
    REP(j,0,n-1)
    {
        if(s[j]=='0')
            dp[1][j+1]=-INF;
        else
            dp[1][j+1]=1;
    }
    REP(i,2,n)
    {
        cin>>s;
        REP(j,0,n-1)
        {
            if(s[j]=='0')
                dp[i][j+1]=-INF;
            else
                dp[i][j+1]=1;
        }
    }
    
    REP(i,1,n)  REP(j,1,n)
    {
        dp[i][j]+=dp[i-1][j];
        dp[i][j]+=dp[i][j-1];
        dp[i][j]-=dp[i-1][j-1];
    }
    int ans=0;
    REP(si,1,n) REP(ei,si,n) REP(sj,1,n) REP(ej,sj,n)
        ans=max(ans,query(ei,ej,si-1,sj-1));
    cout<<ans<<nl;
}
int main()
{
    fast;
    int t;
    cin>>t;
    
    int f=1;
    while(t--)
    {
        if(f==1)
            f=0;
        else
            cout<<nl;
        solve();
    }
        
}
