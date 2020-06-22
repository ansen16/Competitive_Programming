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

//https://cp-algorithms.com/graph/bipartite-check.html
bool bipartite(vector<vector<int>> &adj)
{
    int n=adj.size();
    vector<int> side(n,-1);
    queue<int> q;
    for(int st=0;st<n;st++)
    {
        if(side[st]==-1)
        {
            q.push(st);
            side[st]=0;
            while(!q.empty())
            {
                int v=q.front();
                q.pop();
                for(int u:adj[v])
                {
                    if(side[u]==-1)
                    {
                        side[u]=side[v]^1;
                        q.push(u);
                    }
                    else if(side[u]==side[v])
                        return 0;
                }
            }
        }
    }
    return 1;
}
void solve(int n)
{
    graph adj(n);
    int m;
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bool flag=bipartite(adj);
    if(flag)
        cout<<"BICOLORABLE."<<nl;
    else
        cout<<"NOT BICOLORABLE."<<nl;
}
int main()
{
    fast;
    int t;
    while(cin>>t,t)
        solve(t);
}
