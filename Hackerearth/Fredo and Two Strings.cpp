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



void solve()
{
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    int dp1[n+1],dp2[n+1];
    int p1=0;
    int cnt=0;
    dp1[1]=0;
    REP(i,2,n)
    {
        if(p1<m and s[i-2]==t[p1])
        {
            p1++;
            cnt++;
        }
        dp1[i]=cnt;
    }
    p1=m-1;
    dp2[n]=0;
    cnt=0;
    RREP(i,n-1,1)
    {
        if(p1>=0 and s[i]==t[p1])
        {
            p1--;
            cnt++;
        }
        dp2[i]=cnt;
    }
    int q,trash;
    cin>>q>>trash;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int x=dp1[l]+dp2[r];
        if(x>=m)
            cout<<"Yes"<<nl;
        else
            cout<<"No"<<nl;
    }
}
int main()
{
    fast;
        solve();
}
