#include <bits/stdc++.h>
using namespace std;

#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define INF 1e9
typedef long long LL;
#define pb push_back

int ans=0;
vector<bool> visited;
int dfs(int i, vector<vector<int>> & adj)
{
    int f=0;
    int s=0;
    for(auto x: adj[i])
    {
        if(!visited[x])
        {
            visited[x]=true;
            int a=dfs(x,adj);
            if(a>f)
            {
                s=f;
                f=a;
            }
            else if(a>s)
                s=a;
        }
    }
    ans=max(ans,1+f+s);
    return 1+max(f,s);

}
void solve()
{
    int n;
    cin>>n;
    ans=0;
    vector<vector<int>> adj;
    visited.assign(n,false);
    adj.resize(n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    visited[0]=1;
    dfs(0,adj);
    cout<<(ans/2)<<'\n';
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
