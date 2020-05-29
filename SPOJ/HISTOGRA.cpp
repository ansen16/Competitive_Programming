#include <bits/stdc++.h>

using namespace std;

#define fs          first
#define sc          second
#define nl          '\n'

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;



int main()
{
    LL n;
    while(cin>>n)
    {
        if(n==0)
            return 0;
        LL ans=0;
        stack<pll> s;
        s.push({0,0});
        for(LL i=1;i<=n;i++)
        {
            LL x;
            cin>>x;
            while(1)
            {
                LL y=s.top().fs;
                LL z=s.top().sc;
                if(x>y)
                    break;
                s.pop();
                ans=max(ans,(i-(s.top().sc)-1)*y);
            }
            s.push({x,i});
        }
        while(1)
        {
            LL y=s.top().fs;
            LL z=s.top().sc;
            if(z==0)
                break;
            s.pop();
            ans=max(ans,(n-s.top().sc)*y);
            
        }
        cout<<ans<<nl;
    }
}

