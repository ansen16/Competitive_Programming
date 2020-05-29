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

const int mxn = 5e5+5;
int t[4*mxn]={0};

void update(int v,int tl, int tr,int pos,int val)
{
    if(tl==tr)
    {
        t[v]+=val;
        return;
    }
    int tm=(tl+tr)/2;
    if(pos<=tm)
        update(v*2,tl,tm,pos,val);
    else
        update(v*2+1,tm+1,tr,pos,val);
    t[v]=t[v*2]+t[v*2+1];
}
int query(int v, int tl, int tr, int l, int r)
{
    if(l>r)
        return 0;
    if(l==tl&&r==tr)
        return t[v];
    int tm=(tl+tr)/2;
    return query(v*2,tl,tm,l,min(r,tm))
        +query(v*2+1,tm+1,tr,max(l,tm+1),r);
}
void solve()
{
    int n,q;
    cin>>n>>q;
    while(q--)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int x;
            cin>>x;
            update(1,1,n,x,1);
        }
        else if(a==2)
        {
            int x;
            cin>>x;
            int y=query(1,1,n,x,x);
            if(y>0)
                update(1,1,n,x,-1);
        }
        else{
            int x,y;
            cin>>x>>y;
            cout<<query(1,1,n,x,y)<<nl;
        }
    }
}
int main()
{
    fast;
        solve();
}
