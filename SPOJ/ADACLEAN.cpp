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

#define REP(i,n) for (int i = 0; i < n; i++)
#define REP1(i,n) for (int i = 1; i <= n; i++)
#define RREP(i,n) for (int i=n-1; i>=0 ;i--)

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


LL p=31;
LL mod1=1e9+9;
LL mod2=1e9+7;
LL pk1[100005],pk2[100005];
LL hash1[100005],hash2[100005];

LL get_hash1(int l, int r)
{
    int len=r-l+1;
    LL ans=hash1[r];
    if(l>0)
        ans-=(pk1[len]*hash1[l-1]);
    ans%=mod1;
    ans+=mod1;
    ans%=mod1;
    return ans;
}
LL get_hash2(int l, int r)
{
    int len=r-l+1;
    LL ans=hash2[r];
    if(l>0)
        ans-=(pk2[len]*hash2[l-1]);
    ans%=mod2;
    ans+=mod2;
    ans%=mod2;
    return ans;
}
void precompute()
{
    pk1[0]=pk2[0]=1;
    REP1(i,100000)
    {
        pk1[i]=(pk1[i-1]*p)%mod1;
        pk2[i]=(pk2[i-1]*p)%mod2;
    }
}
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    
    hash1[0]=(s[0]-'a'+1);
    hash2[0]=hash1[0];
    REP1(i,n-1)
    {
        hash1[i]=(p*hash1[i-1])%mod1;
        hash1[i]+=(s[i]-'a'+1);
        hash1[i]%=mod1;

        hash2[i]=(p*hash2[i-1])%mod2;
        hash2[i]+=(s[i]-'a'+1);
        hash2[i]%=mod2;
    }
    set<pll> st;
    for(int i=0;i+k-1<n;i++)
    {
        LL v1=get_hash1(i,i+k-1);
        LL v2=get_hash2(i,i+k-1);
        st.insert({v1,v2});
    }
    cout<<st.size()<<nl;

}
int main()
{
    fast;
    precompute();
    int t;
    cin>>t;
    while(t--)
        solve();
}
