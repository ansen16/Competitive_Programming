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
//
vector<LL> factorize(LL k)
{
    vector<LL> ans;
    int cnt=0;
    while(k%2==0)
    {
        cnt++;
        k/=2;
    }
    if(cnt)
        ans.pb(2);
    cnt=0;
    while(k%3==0)
    {
        cnt++;
        k/=3;
    }
    if(cnt)
        ans.pb(3);
    for(int i=1;(6*i-1)*(6*i-1)<=k;i++)
    {
        cnt=0;
        while(k%(6*i-1)==0)
        {
            cnt++;
            k/=(6*i-1);
        }
        if(cnt)
            ans.pb(6*i-1);
        cnt=0;
        while(k%(6*i+1)==0)
        {
            cnt++;
            k/=(6*i+1);
        }
        if(cnt)
            ans.pb(6*i+1);
    }
    if(k!=1)
        ans.pb(k);
    return ans;
}
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t=1;
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
            vector<LL> temp;
            vector<LL> x=factorize(i);
            for(int j=0;j<x.size();j++)
            {
                LL f=x[j];
                LL num=i-f;
                while(num>1)
                {
                    if(!ch[num])
                    {
                        temp.pb(num);
                        ch[num]=true;
                    }
                    num-=f;
                }
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
