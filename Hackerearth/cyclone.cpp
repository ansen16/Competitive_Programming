#include <bits/stdc++.h>
using namespace std;

#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define INF 1e9
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++)
typedef long long LL;


void solve()
{
    LL n,k;
    cin>>n,k;
    LL arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    map<LL,LL> mp1,mp2;
    int size1=n/2;
    int size2=n-n/2;
    for(int i=0;i<(1<<size1);i++)
    {
        LL xo=0;
        for(int j=0;j<size1;j++)
        {
            if((i>>j)&1)
                xo^=(arr[j]);
        }
        
        mp1[xo]++;
    }
    for(int i=0;i<(1<<size2);i++)
    {
        LL xo=0;
        for(int j=0;j<size2;j++)
        {
            if((i>>j)&1)
                xo^=(arr[size1+j]);
        }
        mp2[xo]++;
    }
    LL ans=0;
    for(auto x: mp1)
    {
        LL x1=x.first;
        LL x2=x.second;
        LL x3=k^x1;
        LL x4=0;
        if(mp2.find(x3)!=mp2.end())
            x4=mp2[x3];
        
        ans+=x2*x4;
    }
    cout<<ans<<'\n';
}
int main()
{
    fast;
        solve();
}
