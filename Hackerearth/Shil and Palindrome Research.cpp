#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define mod         1000000007
#define pi          acos(-1.0)
#define eps         1e-9

#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define fs          first
#define sc          second
#define pb         push_back
#define sp          printf(" ")
#define nl          '\n'
#define all(a) a.begin(),a.end()
#define itn int

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<double> vd;

int n,q;
int BIT[100005]={0};

void update(int i, int val)
{
    while(i<=n)
    {
        BIT[i]^=val;
        i+=(i&(-i));
    }
}
int query(int i)
{
    int sum=0;
    while(i)
    {
        sum^=BIT[i];
        i-=(i&(-i));
    }
    return sum;
}
void solve()
{
    cin>>n>>q;
    string s;
    cin>>s;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        int j=s[i-1]-'a';
        arr[i]=(1<<j);
        update(i,arr[i]);
    }
    while(q--)
    {
        string a,l,r;
        cin>>a>>l>>r;
        if(a=="1")
        {   
            int l1=stoi(l);
            char r1=r[0];
            int j=r1-'a';
            int x=(1<<j);
            update(l1,x^arr[l1]);
            arr[l1]=x;
            
            
        }
        else{
            int l1=stoi(l);
            int r1=stoi(r);
            int j=query(r1);
            if(l1>1)
                j^=query(l1-1);
            j=__builtin_popcount(j);
            if(j>1)
                cout<<"no\n";
            else
                cout<<"yes\n";
        }
    }

}
int main()
{
    fast;
        solve();
}
