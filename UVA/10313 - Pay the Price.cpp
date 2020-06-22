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

ULL dp[305][305]={0};

void precompute()
{
    REP(j,0,300)
        dp[0][j]=1;
    
    REP(i,1,300) REP(j,1,300)
        dp[i][j]=dp[i][j-1] + ( (i>=j)? dp[i-j][j] : 0);
}
vector<int> N;

void solve()
{
    int L1, L2;
    switch(N.size())
    {
        case 1:
            L1 = 0;
            L2 = N[0];
            break;
        case 2:
            L1 = 0;
            L2 = N[1];
            break;
        default:
            L1 = N[1];
            L2 = N[2];
    }
    if (N[0] == 0)
        cout<<1<<nl;
    else
        cout<<dp[N[0]][min(300,L2)]-dp[N[0]][min(300,max(0,L1-1))]<<nl;
        
}
int main()
{
    precompute();
    string s;
    while(getline(cin,s))
    {
        N.clear();
        stringstream ss(s);
        int x;
        while(ss>>x)
            N.pb(x);
        solve();
    }
        
}
