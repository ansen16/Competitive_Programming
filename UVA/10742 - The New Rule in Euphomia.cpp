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

int tc=0;
vi primes;
void precompute()
{
    bool seieve[1000005];
    for(int i=0;i<1000001;i++)
        seieve[i]=true;
    seieve[0]=false;
    seieve[1]=false;
    for(int i=2;i*i<=1000001;i++)
    {
        if(seieve[i]==false)
            continue;
        for(int j=i*i;j<1000001;j+=i)
            seieve[j]=false;
    }
    REP(i,2,1000000)
        if(seieve[i])
            primes.pb(i);
}
void solve(int n)
{
    LL ans=0;
    int p1=0;
    int p2=primes.size()-1;
    while(p1<p2)
    {
        while(p2>p1 and (primes[p1]+primes[p2]>n))
            p2--;
        ans+=(p2-p1);
        p1++;
    }
    cout<<"Case "<<++tc<<": "<<ans<<nl;
}
int main()
{
    fast;
    precompute();
    int t;
    while(cin>>t,t)
        solve(t);
}
