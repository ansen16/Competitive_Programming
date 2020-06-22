#include <bits/stdc++.h>

using namespace std;

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


void solve()
{
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    int dp[n+1][m+1]={0};
    REP(i,1,n) REP(j,1,m)
        cin>>a[i][j];
    REP(i,1,m)
        if(a[1][i]>=5)
            dp[1][i]=a[1][i];
    REP(i,2,n) RREP(j,m,1) REP(k,1,j)
        if(a[i][k]>=5 and dp[i-1][j-k]!=0)
            dp[i][j]=max(dp[i][j], dp[i-1][j-k]+a[i][k]);

    double ans=dp[n][m];
    ans/=n;

    ans+=1e-9; // if this line isnt there then its WA

    if(dp[n][m]==0)
        cout<<"Peter, you shouldn't have played billiard that much."<<nl;
    else
        cout<<"Maximal possible average mark - "<<setprecision(2)<<fixed<<ans<<"."<<nl;

}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
