#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define mod         3
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

//modular exponentiation
LL powm(LL x, LL y,LL m)
{
    if(y==0)
        return 1;
    if(y==1)
        return x%m;
    if(y&1)
        return (x*(powm((x*x)%m,y/2,m)))%m;
    return powm((x*x)%m,y/2,m)%m;
}
//
int n;
const int N=1e5+5;
int t[4*N];
string s;

int combine(int a, int b, int c)
{
    int two=powm(2,c,mod);
    return (b+two*a)%mod;
}
void build(int v, int tl, int tr)
{
    if(tl==tr)
    {
        t[v]=s[tl-1]-'0';
        return;
    }
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    t[v]=combine(t[2*v],t[2*v+1],tr-tm);
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l==tl&&r==tr)
        return t[v];
    int tm=(tl+tr)/2;
    int a1=0;
    int a2=0;
    int c=0;
    if(l<=tm)
    {
        a1=query(v*2,tl,tm,l,min(tm,r));
    }
    if(r>tm)
    {
        a2=query(v*2+1,tm+1,tr,max(l,tm+1),r);
        c=r-max(tm+1,l)+1;
    }
    return combine(a1,a2,c);

}

void update(int v, int tl, int tr, int pos)
{
    if(tl==tr)
    {
        t[v]=1;
        return;
    }
    int tm=(tl+tr)/2;
    if(pos<=tm)
        update(v*2,tl,tm,pos);
    else
        update(v*2+1,tm+1,tr,pos);
    t[v]=combine(t[2*v],t[2*v+1],tr-tm);
    
}
void solve()
{
    cin>>n;
    cin>>s;
    build(1,1,n);
    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==0)
        {
            int l,r;
            cin>>l>>r;
            l++;
            r++;
            cout<<query(1,1,n,l,r)<<nl;
        }
        else{
            int x;
            cin>>x;
            x++;
            update(1,1,n,x);
        }
    }

}
int main()
{
    fast;
        solve();
}
