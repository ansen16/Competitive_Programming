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
typedef vector<vector<LL> > matrix;
typedef vector<vector<int> > graph;
typedef  pair <LD,LD>  vd;
LL INF=1e9;

bool custom(vd a,vd b)
{
    if(fabs(a.fs-b.fs)< 1e-9)
        return a.sc>b.sc;
    return a.fs<b.fs;
}
void solve(LL n, LD l, LD w)
{
    vector<vd > v;
    LD dw=w/2;
    REP(i,1,n)
    {
        LD x,y;
        cin>>x>>y;
        if(y<=dw)
            continue;
        LD dx=sqrt(y*y-dw*dw);
        v.pb({x-dx,x+dx});
        //cerr<<x<<" xy "<<y<<" "<<x-dx<<" "<<x+dx<<nl;
    }
    sort(all(v),custom);
    LD cur=0;
    int cnt=0;
    int m=v.size();
    int i=0;
    while(i<m)
    {
        if(cur>=l)
            break;
        int j=i;
        while(j<n and v[j].sc<=cur)
            j++;
        if(j==n or v[j].fs>cur)
        {
            cout<<-1<<nl;
            return;
        }
        LD temp=v[j].sc;
        while(j+1<n and v[j+1].fs<=cur)
        {
            j++;
            temp=max(temp,v[j].sc);
        }
        i=j+1;
        cur=temp;   
        cnt++;
        
    }
    if(cur>=l)
        cout<<cnt;
    else
        cout<<-1;
    cout<<nl;

}
int main()
{
    fast;
    LL n,l,w;
    while(cin>>n>>l>>w)
        solve(n,l,w);
}
