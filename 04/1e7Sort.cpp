#include <bits/stdc++.h>
#include<random>
using namespace std;
using ll = long long;
using ui = unsigned int;
int N = 100000;
int myhash = 998244353;
void solve() {
    int n,seed;
    cin>>n>>seed;
    mt19937 mt(seed);
    vector<int> arr(N);
     ui num;
    for(int i=0;i<n;i++) {
        num =mt();
        num%=N;
        arr[num]++;
    }
   ll ans = 0;
    int i=1;
    ll temp = 1;
    for(int j=0;j<N;j++) {
        if(arr[j]==0)continue;
       else{
            while(arr[j]) {
                temp*=N;
                temp%=myhash;
                ans+=temp*j;
                ans%=myhash;
                arr[j]--;
                i++;
            }
        }
    }
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while (t--) {
        solve();
    }
    return 0;
}
