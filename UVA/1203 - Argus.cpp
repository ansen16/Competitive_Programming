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



void solve()
{
    string s;
    unordered_map<int,int> p;
    priority_queue<pii > pq;
    while(cin>>s, s!="#")
    {
        int x,y;
        cin>>x>>y;
        p[x]=y;
        pq.push({-y,-x});
    }
    int k;
    cin>>k;
    while(k--)
    {
        pii x=pq.top();
        pq.pop();
        cout<<(-x.sc)<<nl;
        x.fs-=p[-x.sc];
        pq.push(x);
    }
}
int main()
{
    fast;
        solve();
}
