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

LL a,b;
LL tc;

LL func( LL x)
{
    LL ans=0;
    LL c=min(x,100LL);
    ans+=c*2;
    x-=c;
    c=min(x,9900LL);
    ans+=c*3;
    x-=c;
    c=min(x,990000LL);
    ans+=c*5;
    x-=c;
    ans+=x*7;

    return ans;
}
bool func1(LL x)
{
    LL a1=func(x);
    LL a2=func(tc-x);
    LL a3=a2-a1;
    return a3>=b;
}
void solve()
{
    LL low=0;
    LL high=0;
    
    if(a>=200)
    {
        high+=100;
        a-=200;
    }
    else
    {
        high+=a/2;
        a=0;
    }
    if(a>=9900*3)
    {
        high+=9900;
        a-=9900*3;
    }
    else{
        high+=a/3;
        a=0;
    }
    if(a>=990000*5)
    {
        high+=990000;
        a-=990000*5;
    }
    else{
        high+=a/5;
        a=0;
    }
    high+=a/7;
    tc=high;

    int ans=0;
    int jump=tc;
    while(jump)
    {
        while(ans+jump<=tc and func1(ans+jump))
            ans+=jump;
        jump/=2;
    }
    cout<<func(ans)<<nl;
    
}
int main()
{
    fast;
    while(cin>>a>>b,a)
        solve();
}
