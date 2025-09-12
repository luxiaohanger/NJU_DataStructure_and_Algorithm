#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    // 解除 cin 与 cout 的绑定
    cin.tie(nullptr);
   int T,n,high;
    cin>>T;
    while(T--) {
        cin>>n;
        vector<int> build;
        while(n--){
            cin>>high;
            build.push_back(high);
        }
        int ans=0;
        for(int i=0;i<build.size()-1;i++) {
            int highest=0;
            int lowhigh;
            for(int j=i+1;j<build.size();j++) {
                lowhigh=min(build[i],build[j]);
                if(lowhigh>=highest)ans++;
                else {
                    if(lowhigh==build[i])break;
                }
                if(build[j]>highest)highest=build[j];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}