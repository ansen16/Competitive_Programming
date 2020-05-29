#include <bits/stdc++.h>
using namespace std;

#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define INF 1e9
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++)
typedef long long LL;


void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    LL cost[2005]={0};
    LL dp[2005]={0};
    for(int i=0;i<m;i++)
    {
        LL l,r,c;
        cin>>l>>r>>c;
        l--;
        r--;
        cost[l]+=c;
        cost[r+1]-=c;
    }
    dp[0]=cost[0];
    for(int i=1;i<n;i++)
        dp[i]=dp[i-1]+cost[i];
    vector<LL> vect;
    for(int i=0;i<n;i++)
    {
        vect.push_back(dp[i]);
    }
    sort(vect.begin()vect.end());
    LL ans=0;
    for(int i=0;i<k;i++)
        ans+=vect[i];
    cout<<ans<<'\n';

}
int main()
{
    fast;
        solve();
}
