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
    unordered_map<int,int> mp;
    mp[0]++;
    LL ans=0;
    int n,k;
    cin>>n>>k;
    int arr[n];
    int sum=0;
    REP(i,0,n-1)
    {
        cin>>arr[i];
        sum+=arr[i];
        sum%=k;
        ans+=mp[sum];
        mp[sum]++;
    }
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
