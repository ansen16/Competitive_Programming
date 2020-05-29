#include <bits/stdc++.h>
using namespace std;

#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define INF 1e9
typedef long long LL;
#define pb push_back
vector<vector<int>> adj;
vector<vector<pair<LL,LL>>>  adj1;
//https://cp-algorithms.com/graph/lca.html

struct LCA {
    vector<int> height,euler,first,segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> & adj, int root=0)
    {
        n=adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n*2);
        visited.assign(n,false);
        dfs(adj,root);
        int m=euler.size();
        segtree.resize(m*4);
        build(1,0,m-1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h=0)
    {
        visited[node]=true;
        height[node]=h;
        first[node]=euler.size();
        euler.push_back(node);
        for(auto to: adj[node])
        {
            if(!visited[to])
            {
                dfs(adj,to,h+1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e)
    {
        if(b==e)
            segtree[node]=euler[b];
        else
        {
            int mid=(b+e)/2;
            build(node<<1,b,mid);
            build(node<<1|1,mid+1,e);
            int l=segtree[node<<1];
            int r=segtree[node<<1|1];
            segtree[node]= (height[l]<height[r])?l:r;
        }
    }

    int query(int node, int b, int e, int l , int r)
    {
        if(b>r||e<l)
            return -1;
        if(b>=l&&e<=r)
            return segtree[node];
        int mid=(b+e)>>1;
        int left=query(node<<1,b,mid,l,r);
        int right=query(node<<1|1,mid+1,e,l,r);
        if(left==-1) return right;
        if(right==-1) return left;

        return height[left]<height[right]? left:right;
    }

    int lca (int u,int v)
    {
        int left=first[u],right=first[v];
        if(left>right)
            swap(left,right);
        return query(1,0,euler.size()-1,left,right);
    }
};

//https://cp-algorithms.com/graph/dijkstra_sparse.html
vector<LL>  d; vector<LL>  p;

void dijkstra(int s, vector<vector<pair<LL,LL>>> & adj) {
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

void solve()
{
    int n;
    cin>>n;
    adj.resize(n);
    adj1.resize(n);
    for(int i=0;i<n-1;i++){
        int x,y,z;
        cin>>x>>y>>z;
        x--,y--;
        adj[x].pb(y);
        adj[y].pb(x);
        adj1[x].pb({y,z});
        adj1[y].pb({x,z});
    }
    LCA lca(adj,0);
    dijkstra(0,adj1);
    int q;
    cin>>q;

    while(q--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        LL x=max(d[u]-d[lca.lca(u,v)],d[v]-d[lca.lca(u,v)]);
        LL y=min(d[u]-d[lca.lca(u,v)],d[v]-d[lca.lca(u,v)]);
        if(w+y<x)
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';

    }

}
int main()
{
    fast;
        solve();
}
