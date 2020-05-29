#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multi_set;

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
#define unique(c) (c).resize(unique(all(c)) - (c).begin())
#define itn int

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

#define REP(i,n) for (int i = 0; i < n; i++)
#define REP1(i,n) for (int i = 1; i <= n; i++)
#define RREP(i,n) for (int i=n-1; i>=0 ;i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<double> vd;
typedef vector<vector<LL> > matrix;
typedef vector<vector<int> > graph;

class FenwickTree {
private:
    graph BIT;

public:
    FenwickTree() {}
    FenwickTree(int n) {
        BIT.assign(n + 1, vector<int>(3,0)); 
    }
    int LSOne(int S){
        return (S & (-S)); 
    }
    void add (vi &sum, vi a)
    {
        REP(i,3)
            sum[i]+=a[i];
    }
    void sub (vi &sum, vi a)
    {
        REP(i,3)
            sum[i]-=a[i];
    }
    vi query(int b) { 
        vector<int> sum (3,0); 
        for (; b; b -= LSOne(b)) 
            add(sum,BIT[b]);
        return sum;
    }
    vi query(int a, int b) {
        vi ans=query(b);
        if(a>1)
            sub(ans,query(a-1)); 
        return ans;
    }
    void update1(int k, int v) {           
        for (; k < (int)BIT.size(); k += LSOne(k))
        {
            if(v==0)
                BIT[k][0]++;
            else if(v>0)
                BIT[k][1]++;
            else
                BIT[k][2]++;
        }        
    }
    void update2(int k, int v) {           
        for (; k < (int)BIT.size(); k += LSOne(k))
        {
            if(v==0)
                BIT[k][0]--;
            else if(v>0)
                BIT[k][1]--;
            else
                BIT[k][2]--;
        }        
    }
};
void solve(int n, int k)
{
    FenwickTree ft(n+1);
    int arr[n+1];
    REP1(i,n)
    {
        cin>>arr[i];
        ft.update1(i,arr[i]);
    }
    while(k--)
    {
        char a;
        int b, c;
        cin>>a>>b>>c;
        if(a=='C')
        {
            ft.update2(b,arr[b]);
            arr[b]=c;
            ft.update1(b,arr[b]);
        }
        else{
            vi v=ft.query(b,c);
            if(v[0])
                cout<<0;
            else if(v[2]&1)
                cout<<'-';
            else
                cout<<'+';
        }
    }
    cout<<nl;
        
    
}
int main()
{
    fast;
    int n,k;
    while(cin>>n>>k)
        solve(n,k);
}
