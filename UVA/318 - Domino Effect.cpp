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
typedef vector<vector<pair<int,int> > > graph1;

vector<int>  d; vector<int>  p;
const int INF = 1000000000;
int tc=0;

void dijkstra(int s, vector<vector<pair<int,int>>> & adj) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    set<pair<LL, LL>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}
int n,m;

void solve()
{
    graph1 adj(n+1);
    REP(i,1,m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
        adj[b].pb({a,c});
    }  
    dijkstra(1,adj);
    int maxd=-1;
    REP(i,1,n)
        maxd=max(maxd,d[i]);
    vi cand;
    REP(i,1,n)
        if(d[i]==maxd)
            cand.pb(i);
    bool f=0;
    float dist=maxd;
    int a1=0,a2=0;
    for(auto x: cand)
        for(auto y:adj[x])
        {
            int to=y.fs;
            int len=y.sc;

            float temp=d[x]+(d[to]+len-d[x])*1.0/2;
            if(temp>dist)
            {
                f=1;
                dist=temp;
                a1=x;
                a2=to;
            }
        }
    if(a1>a2)
        swap(a1,a2);
    cout<<"System #"<<++tc<<nl;
    cout<<setprecision(1)<<fixed;
    if(f==0)
        cout<<"The last domino falls after "<<dist<<" seconds, at key domino "<<cand[0]<<"."<<nl;
    else
        cout<<"The last domino falls after "<<dist<<" seconds, between key dominoes "<<a1<<" and "<<a2<<"."<<nl;
    cout<<nl;


}
int main()
{
    fast;
    while(cin>>n>>m,n)
        solve();
}
