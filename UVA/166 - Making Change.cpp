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


int coins[6]={1,2,4,10,20,40};
int freq[6];
int dp1[205];
int dp2[205][6];
int func1(int x)
{
    if(x==0)
        return 0;
    int &r=dp1[x];
    if(r!=-1)
        return r;
    r=INF;
    REP(i,0,5)
        if(coins[i]<=x)
            r=min(r,1+func1(x-coins[i]));
    return r;
}
int func2(int x, int i)
{
    if(i==6)
    {
        if(x==0)
            return 0;
        else
            return INF;
    }
    int &r=dp2[x][i];
    if(r!=-1)
        return r;
    r=INF;
    REP(j,0,freq[i])
        if(x>=j*coins[i])
            r=min(r,j+func2(x-j*coins[i],i+1));
    return r;
}
void solve(int sum)
{
    double x;
    cin>>x;
    x+=1e-9;
    x*=100;
    int n=x;
    n/=5;
    setneg(dp2);
    int ans=INF;
    REP(i,n,min(sum,200))
        ans=min(ans,func2(i,0)+func1(i-n));
    cout<<setw(3)<<ans<<nl;
}
int main()
{
    fast;
    setneg(dp1);
    while(1)
    {
        cin>>freq[0]>>freq[1]>>freq[2]>>freq[3]>>freq[4]>>freq[5];
        int sum=0;
        REP(i,0,5)
            sum+=coins[i]*freq[i];
        if(sum==0)
            break;
        solve(sum);
    }
        
}
