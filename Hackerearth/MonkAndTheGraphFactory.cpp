#include <bits/stdc++.h>
using namespace std;

#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define INF 1e9
typedef long long LL;

void solve()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        sum+=x;
    }
    if(sum/2==n-1)
        cout<<"Yes"<<'\n';
    else
        cout<<"No"<<'\n';
}
int main()
{
    fast;
        solve();
}
