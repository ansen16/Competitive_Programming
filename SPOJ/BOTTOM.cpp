#include <bits/stdc++.h>
using namespace std;
#define mod         1000000007
#define pi          acos(-1.0)
#define eps         1e-9
 
#define fs          first
#define sc          second
#define pb         push_back
#define mp(a,b)     make_pair(a,b)
#define sp          printf(" ")
#define nl          '\n'
#define all(a) a.begin(),a.end()
 
#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))
 
 
#define pr1(x)      cout<<x<<"\n"
#define pr2(x,y)    cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<"\n"
 
 
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<double> vd;
 
// clock
typedef long double f80;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
//
 
const long long int mx=100000;
 
int n,m;
vector<vector<int>> adj,adjt;
vector<vector<int>> ssc;
vector<int> vect;
unordered_map<int,bool> visited;
stack<int> s;
 
void dfs1(int x)
{
    
    visited[x]=true;
    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]])
            dfs1(adj[x][i]);
    }
    s.push(x);
}
void dfs2(int x)
{
    visited[x]=true;
    vect.pb(x);
    for(int i=0;i<adjt[x].size();i++)
    {
        if(!visited[adjt[x][i]])
            dfs2(adjt[x][i]);
    }
    
}
void get_ssc()
{
    visited.clear();
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs1(i);
        } 
    }
    visited.clear();
    while(!s.empty())
    {
        int x=s.top();
        s.pop();
        if(visited[x])
            continue;
        vect.clear();
        dfs2(x);
        ssc.pb(vect);
    }
}
 
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    while(cin>>n)
    {
        if(n==0)
            break;
        cin>>m;
        adj.clear();
        adjt.clear();
        adj.resize(n+1);
        adjt.resize(n+1);
        ssc.clear();
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].pb(b);
            adjt[b].pb(a);
        }
        get_ssc();
        unordered_map<int,int> comp;
        vector<int> ans;
        for(int i=0;i<ssc.size();i++)
        {
            for(int j=0;j<ssc[i].size();j++)
            {
                comp[ssc[i][j]]=i+1;
            }
        }
        for(int i=0;i<ssc.size();i++)
        {
            bool flag=true;
            for(int j=0;j<ssc[i].size();j++)
            {
                int x=ssc[i][j];
                for(int k=0;k<adj[x].size();k++)
                {
                    if(comp[adj[x][k]]!=comp[x])
                    {
                        flag=false;
                        break;
                    }
                }
            }
            if(flag)
            {
                for(int j=0;j<ssc[i].size();j++)
                {
                    ans.pb(ssc[i][j]);
                }
            }
        }
        sort(all(ans));
        for(auto q: ans)
            cout<<q<<" ";
        cout<<nl; 
    }
}
