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
    multiset<int> sizes; // delete 
    
    UnionFind(int N) 
	{
    	setSize.assign(N, 1); 
		numSets = N; 
    	p.assign(N, 0); 
		for (int i = 0; i < N; i++) p[i] = i; 
		for (int i = 0; i < N; i++) sizes.insert(1); //delete
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
    		sizes.erase(sizes.find(setSize[x])); //delete
    		sizes.erase(sizes.find(setSize[y])); //delete
    		
    		p[y] = x; 
			setSize[x] += setSize[y]; 
			sizes.insert(setSize[x]); //delete
		} 
	}
  	int numDisjointSets() 
	{ 
		return numSets; 
	}
};

void solve()
{
    int n;
    cin>>n;
    UnionFind uf(n);
    int m1;
    cin>>m1;
    while(m1--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        uf.unionSet(x,y);
    }
    set<int> s;
    REP(i,0,n-1)
        s.insert(uf.findSet(i));
    int m2;
    cin>>m2;
    int ans=0;
    while(m2--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(uf.findSet(x)==uf.findSet(y))
            s.erase(uf.findSet(x));
    }
    for(auto x: s)
        ans=max(ans,uf.setSize[x]);
    cout<<ans<<nl;
}
int main()
{
    fast;
        solve();
}
