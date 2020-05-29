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

#define REP(i,n) for (int i = 0; i < n; i++)

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

const int N=1e5+5;
LL t[4*N];
LL lazy[4*N];

void push(int v, int  tl, int tr)
{
    int tm=(tl+tr)/2;
    t[v*2]+=lazy[v]*(tm-tl+1);
    lazy[v*2]+=lazy[v];
    t[v*2+1]+=lazy[v]*(tr-tm);
    lazy[v*2+1]+=lazy[v];
    lazy[v]=0;

}
void build(int v, int tl, int tr)
{
    if(tl==tr)
    {
        t[v]=0;
        return;
    }
    int tm=(tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
    t[v]=0;
}
void update(int v, int tl, int tr, int l, int r, LL val)
{
    if(l>r)
        return;
    if(l==tl&&r==tr)
    {
        t[v]+=val*(r-l+1);
        lazy[v]+=val;
        return;
    }
    push(v, tl,tr);
    int tm=(tl+tr)/2;
    update(v*2,tl,tm,l,min(r,tm),val);
    update(v*2+1,tm+1,tr,max(l,tm+1),r,val);
    t[v]=t[v*2]+t[v*2+1];
}
LL query(int v, int tl, int tr, int l, int r)
{
    if(l>r)
        return 0;
    if(l==tl&&r==tr)
        return t[v];
    push(v,tl,tr);
    int tm=(tl+tr)/2;
    return query(v*2,tl,tm,l,min(r,tm))+
            query(v*2+1,tm+1,tr,max(l,tm+1),r);
}
void solve()
{
    int n,c;
    cin>>n>>c;
    for(int i=0;i<=4*n+5;i++)
        lazy[i]=0;

    build(1,1,n);
    while(c--)
    {
        int t;
        cin>>t;
        int p,q;
        if(t==0)
        {
            LL v;
            cin>>p>>q>>v;
            update(1,1,n,p,q,v);
        }
        else{
            cin>>p>>q;
            cout<<query(1,1,n,p,q)<<nl;
        }
    }
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
