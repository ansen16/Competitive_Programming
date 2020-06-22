// C++ 11
#include <bits/stdc++.h>
using namespace std;

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

char grid[105][105];
bool visited[105][105];

int dfs(int x, int y)
{
    if(x<0 or y<0 or grid[x][y]==0)
        return 0;
    if(visited[x][y]==1 or grid[x][y]!='W')
        return 0;
    visited[x][y]=1;
    int ans=1;
    REP(i,-1,1) REP(j,-1,1)
        ans+=dfs(x+i,y+j);
    return ans;
}
void solve()
{
    int n=0;
    char str[105];
    int i,j;
    set0(grid);
    
    while(gets(str))
    {
        if(str[0]=='\0')
            break;
        if((str[0]!='W') and (str[0]!='L'))
        {
            sscanf(str,"%d %d",&i,&j);
            set0(visited);
            cout<<dfs(i-1,j-1)<<nl;
        }
        else
        {
            sscanf(str,"%s",grid[n]);
            n++;
        }
    }
}
int main()
{
    int t;
    scanf("%d ", &t);
    while(t--)
    {
        solve();
        if(t)
            cout<<nl;
    }
        
}
