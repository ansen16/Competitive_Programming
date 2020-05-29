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
LL n,q;
int BIT[200005]={0};
void update(int i, int x)
{
    while(i<=n)
    {
        BIT[i]+=x;
        i+=(i&(-i));
    }
}
int query(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=BIT[i];
        i-=(i&(-i));
    }
    return sum;
}
void solve()
{
    cin>>n>>q;
    int arr[n+1];
    arr[0]=0;
    for(int i=1;i<=n;i++)
    {
        string x;
        cin>>x;
        int val=(x[0]==x[x.size()-1]);
        arr[i]=val;
        update(i,val);
    }
    while(q--)
    {
        LL a;
        cin>>a;
        if(a==1)
        {
            LL b,c;
            cin>>b>>c;
            cout<<query(c)-query(b-1)<<nl;
        }
        else{
            LL b;
            string x;
            int val=(x[0]==x[x.size()-1]);
            update(b,val-arr[b]);
            arr[b]=val;
        }
    }
}
int main()
{
    fast;
        solve();
}
