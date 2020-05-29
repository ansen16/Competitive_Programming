#include <bits/stdc++.h>
using namespace std;

#define mod         1000000007


#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define nl          '\n'

#define REP(i,start,end) for (int i = start; i <=end; i++)
#define RREP(i,end,start) for (int i=end; i>=start ;i--)

typedef long long LL;


void solve()
{
    int n;
    cin>>n;
    LL ans=0;
    LL arr[1000005]={0};
    REP(i,1,n)
    {
        int x;
        cin>>x;
        arr[x]++;
    }
    REP(i,1,1000000)
        ans+=(arr[i]*(arr[i]-1));
    cout<<ans<<nl;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
        solve();
}
