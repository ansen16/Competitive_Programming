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
// mod inverse
LL inv(LL x, LL m)
{
    return powm(x,m-2,m);
}
//
void solve()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    int mask1=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mask1|=(1<<x);
    }
    LL ans=0;
    int p2=0;
    int mask2=0;
    for(int p1=0;p1<s.size();p1++)
    {
        while(((mask1&mask2)!=mask1)&&(p2<s.size()))
        {
            int x=s[p2]-'0';
            mask2=(mask2|(1<<x));
            p2++;
        }
        if((mask1&mask2)==mask1)
            ans+=s.size()-p2+1;
        
        int x=s[p1]-'0';
        mask2=(mask2&(~(1<<x));
    }
    cout<<ans<<nl;

}
int main()
{
    fast;
        solve();
}
