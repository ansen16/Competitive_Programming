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

int dx[]={0,-1,-1,-1,0,1,1,1};
int dy[]={1,1,0,-1,-1,-1,0,1};
void solve(string s)
{
    stringstream ss(s);
    int x,y,d;
    ss>>x>>y>>d;
    unordered_map<int,unordered_map<int,int> > mp;
    REP(i,1,8)
    {
        string s1;
        getline(cin,s1);
        stringstream ss1(s1);
        int a,b,c;
        ss1>>a>>b>>c;
        mp[a][b]=c;
    }
    int p=d-3;
    int cnt=0;
    while(cnt<8)
    {
        p+=8;
        p%=8;
        int x1=x+dx[p];
        int y1=y+dy[p];
        if(mp[x1][y1])
        {
            cout<<p<<nl;
            return;
        }
        cnt++;
        p++;    
    }
}
int main()
{
    fast;
    string s;
    while(getline(cin,s))
    {
        if(s[0]=='-')
            break;
        solve(s);
    }
        
}
