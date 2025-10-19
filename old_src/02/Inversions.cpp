#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using ld = long double;

vector<int> merge(const vector<int>& arr1,const vector<int>& arr2,int& ans) {
    int l1 = arr1.size();
    int l2 = arr2.size();
    vector<int> re;
    int i = 0,j = 0;
    while(i != l1 && j != l2) {
        if(arr1[i] <= arr2[j]) {
            re.push_back(arr1[i]);
            i++;
        }else {
            re.push_back(arr2[j]);
            j++;
            ans += l1 - i;
        }
    }
    if(i == l1) {
        while(j != l2) {
            re.push_back(arr2[j]);
            j++;
        }
    }else {
        while(i != l1) {
            re.push_back(arr1[i]);
            i++;
        }
    }
    return re;
}

vector<int> mergesort(vector<int>& arr,int& ans) {
    if(arr.size() == 1||arr.empty())return arr;

    int mid = arr.size() / 2;

    vector<int> arr1;
    vector<int> arr2;

    for(int i=0;i<mid;++i) {
        arr1.push_back(arr[i]);
    }

    for(int i=mid;i<arr.size();++i) {
        arr2.push_back(arr[i]);
    }

     return  merge(mergesort(arr1,ans),mergesort(arr2,ans),ans);
}

void solve() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0;i < N;++i) {
        cin >> arr[i];
    }
    int ans = 0;
    vector<int> s = mergesort(arr,ans);
    cout << ans ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
