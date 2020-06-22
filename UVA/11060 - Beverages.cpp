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

graph adj;
vi indeg,visited;
int tc;
unordered_map<string,int> mp;
string arr[105];

void solve(int n)
{
    mp.clear();
    indeg.assign(n,0);
    visited.assign(n,0);
    REP(i,0,n-1)
    {
        cin>>arr[i];
        mp[arr[i]]=i;
    }
    adj.clear();
    adj.resize(n);
    int m;
    cin>>m;
    while(m--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int x=mp[s1];
        int y=mp[s2];
        adj[x].pb(y);
        indeg[y]++;
    }
    cout<<"Case #"<<++tc<<": Dilbert should drink beverages in this order:";
    REP(j,0,n-1)
    {
        REP(i,0,n-1)
        {
            if(!visited[i] and indeg[i]==0)
            {
                cout<<" "<<arr[i];
                visited[i]=1;
                for(auto x: adj[i])
                    if(!visited[x]) 
                        indeg[x]--;
                break;
            }
        }
    }
    cout<<"."<<nl<<nl;
}
int main()
{
    fast;
    int t;
    tc=0;
    while(cin>>t)
        solve(t);
}
