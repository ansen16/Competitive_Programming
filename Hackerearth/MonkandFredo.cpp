#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define mod         1000000007
#define pi          acos(-1.0)
#define eps         1e-9

#define fs          first
#define sc          second
#define pb         push_back
#define mp(a,b)     make_pair(a,b)
#define sp          printf(" ")
#define nl          '\n'
#define all(a) a.begin(),a.end()
#define itn int

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))


#define pr1(x)      cout<<x<<"\n"
#define pr2(x,y)    cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<"\n"


typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<double> vd;

// clock
typedef long double f80;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
//

const long long int mx=100000;
vector<vector<int>> adj;
unordered_map<int,bool> visited;

//modular exponentiation
LL powm(LL x, LL y)
{
    if(y==0)
        return 1;
    if(y==1)
        return x%mod;
    if(y&1)
        return (x*(powm((x*x)%mod,y/2)))%mod;
    return powm((x*x)%mod,y/2);
}
//

class triplet{
    public:
    LL a;
    LL b;
    LL gcd;
};
triplet extended_euclid(LL a,LL b)
{
    if(b==0)
    {
        triplet x;
        x.a=1;
        x.b=0;
        x.gcd=a;
        return x;
    }
    triplet x1=extended_euclid(b,a%b);
    triplet x;
    x.a=x1.b;
    x.b=x1.a-(a/b)*(x1.b);
    x.gcd=x1.gcd;
    return x;
}
LL mod_inverse(LL a, LL m)
{
    LL ans=extended_euclid(a,m).a;
    return (ans%m +m )%m;
}

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t;
    cin>>t;
    while(t--)
    {
        LL a,b,d;
        cin>>a>>b>>d;
        LL g=__gcd(a,b);
        if(d%g!=0)
        {
            cout<<0<<nl;
            continue;
        }
        a/=g;
        b/=g;
        d/=g;
        triplet x=extended_euclid(a,b);
        LL x1=x.a;
        LL y1=x.b;
        x1*=d;
        y1*=d;
        LL l,r;
        r=floor(1.0*x1/b);
        l=ceil(-1.0*y1/a);
        LL ans=(abs(r-l)+1)*(l<=r);
        // cerr<<x1<<" "<<y1<<nl;
        // cerr<<l<<" "<<r<<nl;
        cout<<ans<<nl;

    }


    #ifdef rd
    cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif

}