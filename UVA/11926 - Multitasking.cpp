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

#define REP(i,n) for (int i = 0; i < n; i++)
#define REP1(i,n) for (int i = 1; i <= n; i++)
#define RREP(i,n) for (int i=n-1; i>=0 ;i--)

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


bitset<1000001> schedule;

bool hasConflict(int n, int m, vi &s, vi &e, vi &r)
{
    REP(i,n)
    {
        int st=s[i]+1;
        int en=e[i];
        for(int t=st;t<=en;t++)
        {
            if(schedule.test(t))
                return 1;
            schedule.set(t);
        }
    }
    REP(i,m)
    {
        int st=s[i+n]+1;
        int en=e[i+n];
        int rep=r[i];
        while(st<=1000000)
        {
            for(int t=st;t<=en;t++)
            {
                if(schedule.test(t))
                    return true;
                schedule.set(t);
            }
            st+=rep;
            en=min(en+rep,1000000);
        }
    }
    return 0;
}
void solve(int n, int m)
{
    vi s(n+m), e(n+m), r(n+m);
    REP(i,n)
        cin>>s[i]>>e[i];
    REP(i,m)
        cin>>s[i+n]>>e[i+n]>>r[i];

    schedule.reset();
    if(hasConflict(n,m,s,e,r))
        cout<<"CONFLICT"<<nl;
    else
        cout<<"NO CONFLICT"<<nl;
}
int main()
{
    fast;
    int n,m;
    while(cin>>n>>m , n or m)
        solve(n,m);
}
