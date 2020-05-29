#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
#define itn int

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
unordered_map<int,bool> visited;

//modular exponentiation
LL powm(LL x, LL y)
{
    if(y==0)
        return 1;
    if(y==1)
        return x%mod;
    if(y&1)
        return (x*(powm((x*x)%mod,y/2)))%mod;
    return powm((x*x)%mod,y/2);
}
//
// dfs
void dfs(int x)
{
    visited[x]=true;
    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]])
            dfs(adj[x][i]);
    }
}
//
int seieve[1000005];
int dp[11][1000001];
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    set0(seieve);
    seieve[0]=0;
    seieve[1]=0;
    for(int i=2;i<=500000;i++)
    {
        if(seieve[i]!=0)
            continue;
        for(int j=i;j<=1000000;j+=i)
            seieve[j]++;
    }
    for(int i=2;i<=1000000;i++)
    {
        seieve[i]+=seieve[i]==0;
    }
    for(int i=1;i<=10;i++)
    {
        dp[i][0]=0;
        for(int j=1;j<=1000000;j++)
        {
            dp[i][j]=dp[i][j-1]+(seieve[j]==i);
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        LL a,b,n;
        cin>>a>>b>>n;
        if(n==0)
        {
            cout<<(a==1)<<nl;
            continue;
        } 
        cout<<dp[n][b]-dp[n][a-1]<<nl;
    }


    #ifdef rd
    cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif

}
