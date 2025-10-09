#include <bits/stdc++.h>
using namespace std;
struct cmp {
    bool operator()(int a,int b) {
        return a > b;
    }
};

int main()
{   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n;
    cin>>m>>n;

    vector<int> ist(m);
    vector<int> q(n);
    for(int i=0;i<m;++i)cin>>ist[i];
    for(int i=0;i<n;++i)cin>>q[i];
    int j=0;
    int cnt=0;
    //对顶堆
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,cmp> minheap;
    while(j<n) {
        minheap.push(ist[cnt++]);
        //维护最大堆里面是最小的x个元素
        maxheap.push(minheap.top());
        minheap.pop();
        minheap.push(maxheap.top());
        maxheap.pop();
        while(cnt==q[j]) {
            maxheap.push(minheap.top());
            cout<<maxheap.top()<<"\n";
            minheap.pop();
           j++;
        }
    }
    return 0;
}

