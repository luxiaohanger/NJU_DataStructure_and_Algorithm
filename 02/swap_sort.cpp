#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int> merge(vector<int> arr1,vector<int> arr2,ll& cnt) {
    vector<int> ans;
    int i=0,j=0;
    int l1=arr1.size(),l2=arr2.size();
    while(i!=l1&&j!=l2) {
        if(arr1[i]<=arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
        }else {
            ans.push_back(arr2[j]);
            j++;
            cnt+=l1-i;
        }
    }
    if(i==l1) {
        for(int k=j;k<l2;++k) {
            ans.push_back(arr2[k]);
        }
    }else {
        for(int k=i;k<l1;++k) {
            ans.push_back(arr1[k]);
        }
    }
    return ans;
}

vector<int> merge_sort(vector<int> arr,ll& cnt) {
    if(arr.size()==1)return arr;
    vector<int> arr1;
    vector<int> arr2;
    int len=arr.size();
    int mid=(len-1)/2;
    for(int i=0;i<=mid;i++) {
        arr1.push_back(arr[i]);
    }
    for(int i=mid+1;i<len;++i) {
        arr2.push_back(arr[i]);
    }
    vector<int> left=merge_sort(arr1,cnt);
    vector<int> right=merge_sort(arr2,cnt);
    vector<int> ans=merge(left,right,cnt);
    return ans;
}

int main()
{   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    int n;
    while(T--) {
        cin>>n;
        ll cnt=0;
        vector<int> arr(n);
        for(int i=0;i<n;++i) {
            cin>>arr[i];
        }
        merge_sort(arr,cnt);
        cout<<cnt<<"\n";
    }
    return 0;
}

