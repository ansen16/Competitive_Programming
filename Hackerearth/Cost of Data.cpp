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

int cnt=1;

class TrieNode{
    public:
    int prio;
    TrieNode**child;
    TrieNode()
    {
        prio=0;
        child=new TrieNode*[26];
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
};
 
void insert(string & s,int x,TrieNode* head)
{
    TrieNode *temp=head;
    for(int i=0;i<s.size();i++)
    {
        int b=s[i]-'a';
        if(temp->child[b]==NULL)
        {
            temp->child[b]=new TrieNode();
            cnt++;
        }
        temp=temp->child[b];
        temp->prio=max(temp->prio,x);
    }
}
int query(string & s, TrieNode *head)
{
    TrieNode*temp=head;
    for(int i=0;i<s.size();i++)
    {
        int b=s[i]-'a';
        if(temp->child[b]==NULL)
            return -1;
        temp=temp->child[b];
    }
    return temp->prio;
}

void solve()
{
    int n;
    cin>>n;
    TrieNode * head= new TrieNode();
    while(n--)
    {
        string s;
        cin>>s;
        insert(s,1,head);
    }
    cout<<cnt<<nl;

}
int main()
{
    fast;
        solve();
}
