#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
#define itn int

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<double> vd;

const int maxn =1e6+5;
int t[4*maxn];

void build(int v, int tl,int tr)
{
    if(tl==tr)
    {
        t[v]=1;
        return;
    }    
    int tm=(tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
    t[v]=t[2*v]+t[2*v+1];
}
void update(int v, int tl, int tr,int pos)
{
    if(tl==tr)
    {
        t[v]=0;
        return;
    }
    int tm=(tl+tr)/2;
    if(pos<=tm)
        update(v*2,tl,tm,pos);
    else
        update(v*2+1,tm+1,tr,pos);
    t[v]=t[2*v]+t[2*v+1];
}
int query(int v, int tl, int tr, int k)
{
    if(k>t[v])
        return -1;
    if(tl==tr)
        return tl;
    int tm=(tl+tr)/2;
    if(t[v*2]>=k)
        return query(v*2,tl,tm,k);
    else
        return query(v*2+1,tm+1,tr,k-t[v*2]);
}
void solve()
{
    int n;
    cin>>n;
    int q;
    cin>>q;
    build(1,1,n);
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(x==0)
            update(1,1,n,y);
        else
            cout<<query(1,1,n,y)<<nl;
    }
}
int main()
{
    fast;
        solve();
}
