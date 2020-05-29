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


const LL mxn=1e6;
LL N=1e6+1;
LL n, k;
LL arr[mxn+5];
LL brr[mxn+5];
LL inv[mxn+5];
LL BIT[mxn+5]={0};
unordered_map<int,int> cmp;

void update(int i, int x)
{
    while(i<=N)
    {
        BIT[i]+=x;
        i+=(i&(-i));
    }
}
LL query(int i)
{
    int sum=0;
    while(i)
    {
        sum+=BIT[i];
        i-=(i&(-i));
    }
    return sum;
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        brr[i]=arr[i];
    }    
    sort(brr+1,brr+n+1);
    for(int i=1;i<=n;i++)
        cmp[brr[i]]=i;
    for(int i=n;i>0;i--)
    {
        LL a1=query(N);
        LL a2=query(cmp[arr[i]]);
        inv[i]=a1-a2;
        update(cmp[arr[i]],1);
    }
    sort(inv+1,inv+n+1);
    LL ans=0;
    int p1=1;
    int p2=n;
    while(p1<p2)
    {
        if(inv[p1]+inv[p2]>=k)
        {
            ans+=(p2-p1);
            p2--;
            continue;
        }
        p1++;
    }
    cout<<ans<<nl;
    
}
int main()
{
    fast;
        solve();
}
