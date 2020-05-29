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

#define REP(i,start,end) for (int i = start; i <=end; i++)
#define RREP(i,end,start) for (int i=end; i>=start ;i--)

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


class UnionFind { 
	public:
    vi p,setSize;                     
    int numSets;
    
    UnionFind(int N) 
	{
    	setSize.assign(N, 1); 
		numSets = N; 
    	p.assign(N, 0); 
		for (int i = 0; i < N; i++) p[i] = i; 
	}
  	int findSet(int i) 
	{
		return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
	}
  	bool isSameSet(int i, int j) 
	{ 	
		return findSet(i) == findSet(j); 
	}
    void unionSet(int i, int j) 
	{ 
    	if (!isSameSet(i, j)) 
		{ 
			numSets--; 
    		int x = findSet(i), y = findSet(j);
    		
            if(x<y)
            {
                p[y] = x; 
			    setSize[x] += setSize[y]; 
            }
            else{
                p[x] = y; 
			    setSize[y] += setSize[x];
            }
    		
		} 
	}
  	int numDisjointSets() 
	{ 
		return numSets; 
	}
};

void solve()
{
    string a,b,c;
    cin>>a>>b>>c;
    UnionFind uf(26);
    REP(i,0,a.size()-1)
    {
        int x=a[i]-'a';
        int y=b[i]-'a';
        uf.unionSet(x,y);
    }
    REP(i,0,c.size()-1)
    {
        int y=uf.findSet((int)c[i]-'a');
        char ans=y+'a';
        cout<<ans;
    }
    cout<<nl;

}
int main()
{
    fast;
        solve();
}
