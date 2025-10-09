#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

bool query(ull a,ull b) {
    cout<<"?"<<"\n";
    cout<<a<<' '<<b<<'\n';
    cout.flush();
    string ans;
    cin>>ans;
    return (ans=="<"||ans=="=");
}

struct cmp {
    bool operator()(ull a,ull b) {
        cout<<"?"<<"\n";
        cout<<a<<' '<<b<<'\n';
        cout.flush();
        string ans;
        cin>>ans;
        return (ans=="<"||ans=="=");
    }
};
vector<ull> merge(vector<ull>a1,vector<ull>a2) {
    vector<ull> ans;
    int i=0,j=0;
    int l1=a1.size();
    int l2=a2.size();
    while(i<l1 && j<l2) {
        if(query(a1[i],a2[j])) {
            ans.push_back(a1[i]);
            i++;
        }
        else {
            ans.push_back(a2[j]);
            j++;
        }
    }
    if(i==l1) {
        while(j<l2) {
            ans.push_back(a2[j]);
            j++;
        }
    }else {
        while(i<l1) {
            ans.push_back(a1[i]);
            i++;
        }
    }
    return ans;
}

vector<ull> mergesort(vector<ull> arr) {
    if(arr.size()==1||arr.empty())return arr;
    int n=arr.size();
    int mid=(n-1)/2;
    vector<ull> a1;
    vector<ull> a2;
    for(int i=0;i<=mid;++i)a1.push_back(arr[i]);
    for(int i=mid+1;i<n;++i)a2.push_back(arr[i]);
    vector<ull> ans=merge(mergesort(a1),mergesort(a2));
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<ull> arr(n);
    for (int i=0;i<n;++i) {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end(),cmp());
    cout<<"!"<<'\n';
    for(ull x:arr)cout<<x<<' ';
    cout<<'\n';
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
