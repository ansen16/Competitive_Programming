#include <bits/stdc++.h>
using namespace std;

vector<int> solve( vector<int> &A, int B) {
    vector<int> ans;
    deque<int> dq;
    for(int i=0;i<B-1;i++)
    {
        while(!dq.empty()&&A[dq.back()]<=A[i])
            dq.pop_back();
        dq.push_back(i);
    }
    for(int i=B-1;i<A.size();i++)
    {
        while(!dq.empty()&&A[dq.back()]<=A[i])
            dq.pop_back();
        dq.push_back(i);
        if(dq.front()<i-B+1)
            dq.pop_front();
        ans.push_back(A[dq.front()]);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> A;
    A.resize(n);
    for(int i=0;i<n;i++)
        cin>>A[i];
    int B;
    cin>>B;
    vector<int> ans =solve(A,B);
    for(auto x:ans)
        cout<<x<<" ";

}