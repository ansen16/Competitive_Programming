#include <bits/stdc++.h>
using namespace std;

#define LL long long 
#define mod 1000000007

LL A[2][2]={{1,1},{1,0}};

void multiply2()
{
    LL a=(A[0][0])%mod+(A[0][1])%mod;
    LL b=(A[0][0])%mod;
    LL c=(A[1][0])%mod+(A[1][1])%mod;
    LL d=(A[1][0])%mod;
    A[0][0]=a%mod;
    A[0][1]=b%mod;
    A[1][0]=c%mod;
    A[1][1]=d%mod;
    
}
void multiply1()
{
    LL a=(A[0][0]*A[0][0])%mod+(A[0][1]*A[1][0])%mod;
    LL b=(A[0][0]*A[0][1])%mod+(A[0][1]*A[1][1])%mod;
    LL c=(A[1][0]*A[0][0])%mod+(A[1][1]*A[1][0])%mod;
    LL d=(A[1][0]*A[0][1])%mod+(A[1][1]*A[1][1])%mod;
    A[0][0]=a%mod;
    A[0][1]=b%mod;
    A[1][0]=c%mod;
    A[1][1]=d%mod;
}
void pow(LL x)
{
    if(x==0||x==1)
        return;
    pow(x/2);
    multiply1();
    if(x&1)
        multiply2();
}
LL fibo(LL x)
{
    if(x==0||x==1)
        return x;
    A[0][0]=1;
    A[0][1]=1;
    A[1][0]=1;
    A[1][1]=0;
    pow(x-1);
    return A[0][0];
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        LL m,n;
        cin>>m>>n;
	    cout<<(((fibo(n+2)-fibo(m+1))%mod)+mod)%mod<<'\n';
    }
    
}

