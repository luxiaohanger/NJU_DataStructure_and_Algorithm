#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    // 解除 cin 与 cout 的绑定
    cin.tie(nullptr);
    int T,n,q;
    cin>>T;
    while(T--) {
      cin>>n>>q;
        list<int> arr;
        int num;
        while(n--) {
            cin>>num;
            arr.push_back(num);
        }
        while(q--) {
        int k;
            cin>>k;
            int i=1;
        for(auto it=arr.begin();i<=k;i++) {
            if(i%2==1)it = arr.erase(it);
            else it++;
        }
            //k/2
            k/=2;
            list<int> temp;
            // 移除前n个元素到临时链表
            auto it = arr.begin();
            for (int i = 0; i < k; ++i) {
                temp.splice(temp.end(), arr, it++);
            }
            // 反转临时链表
            temp.reverse();
            // 将反转后的元素插回原位置
            arr.splice(arr.begin(), temp);
        }
     for(auto it:arr) {
         //for-each循环
         cout<<it<<' ';
     }
        cout<<'\n';

    }
    return 0;
}
