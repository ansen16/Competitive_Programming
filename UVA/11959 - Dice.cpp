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

string a,b;
string ans;
void z()
{
    string bx=b;
    b[0]=bx[2];
    b[1]=bx[4];
    b[2]=bx[1];
    b[4]=bx[0];
}
void x()
{
    string bx=b;
    b[2]=bx[3];
    b[3]=bx[4];
    b[4]=bx[5];
    b[5]=bx[2];
}
void y()
{
    string bx=b;
    b[0]=bx[3];
    b[3]=bx[1];
    b[1]=bx[5];
    b[5]=bx[0];
}
void fx()
{
    REP(j,1,4)
    {
        bool f1=1;
        REP(k,0,5)
            f1&=(a[k]==b[k]);
        if(f1)
            ans="Equal";
        x();
    }
}
void solve()
{
    
    cin>>a>>b;
    ans= "Not Equal";
    REP(i,1,4)
    {
        fx();
        z();
    }
    y();
    fx();
    y();
    y();
    fx();
    cout<<ans<<nl;
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
