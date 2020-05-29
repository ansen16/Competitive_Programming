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
vector<vector<int>> adj;


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

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,m;
        cin>>n>>m;
        adj.clear();
        adj.resize(n);
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        bool ans=bipartite(adj);
        cout<<"Scenario #"<<z<<":\n";
        if(ans)
            cout<<"No suspicious bugs found!"<<nl;
        else
            cout<<"Suspicious bugs found!"<<nl;

    }


    #ifdef rd
    cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif

}
