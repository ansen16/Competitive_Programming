#include <bits/stdc++.h>
using namespace std;

#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define INF 1e9
typedef long long LL;

bool adj[1005][1005]={0};
void solve()
{
    int n,m;
    cin>>n>>m;
    while
    (m--)
    {
        int x,y;
        cin>>x>>y;
        adj[x][y]=1;
        adj[y][x]=1;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        adj[x][y]? cout<<"YES":cout<<"NO";
        cout<<'\n';
    }
}
int main()
{
    fast;
        solve();
}
