#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t=1;
    int seieve[2000005];
    for(int i=0;i<=2000000;i++)
        seieve[i]=i;
    for(int i=2;i*i<=2000000;i++)
    {
        if(seieve[i]!=i)
            continue;
        for(int j=i*i;j<=2000000;j+=i)
            seieve[j]=min(seieve[j],i);
    }
    while(t--)
    {
        LL n;
        cin>>n;
        bool ch[2000005];
        set0(ch);
        for(int i=n;i>1;i--)
        {
            if(ch[i])
                continue;
            ch[i]=true;
            cout<<i<<" ";
            vector<LL> tx,temp;
            int x=i;
            int lpd=seieve[x];
            while(x!=1)
            { 
                for(int j=i-lpd;j>1;j-=lpd)
                {
                    if(!ch[j])
                    {
                        temp.pb(j);
                        ch[j]=true;
                    }      
                }
                tx.pb(lpd);
                while(x%lpd==0)
                    x/=lpd;
                lpd=seieve[x];
            }
            
            sort(all(temp),greater<int>());
            for(auto z:temp)
                cout<<z<<" ";
        }
        cout<<1<<nl;

    }


    #ifdef rd
    cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif

}
