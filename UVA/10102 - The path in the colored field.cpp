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

int dist(int x1, int y1, int x2, int y2)
{
    return abs(x1-x2) + abs(y1-y2);
}
void solve(int n)
{
    vi x1,y1,x3,y3;
    REP(i,1,n)
    {
        string s;
        cin>>s;
        REP(j,0,n-1)
        {
            if(s[j]=='1')
            {
                x1.pb(i);
                y1.pb(j+1);
            }    
            else if(s[j]=='3')
            {
                x3.pb(i);
                y3.pb(j+1);
            }
        }
    }
    int ans=0;
    int i=0;
    while(i<x1.size())
    {
        int temp=INF;
        int j=0;
        while(j<x3.size())
        {
            temp=min(temp,dist(x1[i],y1[i],x3[j],y3[j]));
            j++;
        }
        ans=max(ans,temp);
        i++;
    }
    cout<<ans<<nl;

}
int main()
{
    fast;
    int t;
    while(cin>>t)
        solve(t);
}
