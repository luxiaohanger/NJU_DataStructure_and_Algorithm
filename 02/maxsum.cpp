#include <bits/stdc++.h>
using namespace std;
using ll =long long;
 ll maxsum(const vector<ll>& arr,int left,int right) {
    if(left==right)return arr[left];
    if(left+1==right) {
        return max(arr[left],max(arr[right],arr[left]+arr[right]));
    }
    int mid=(left+right+1)/2;
    //include mid
    ll max1=arr[mid];
    ll tempsum=max1;
    for(int i=mid+1;i<=right;i++) {
        tempsum+=arr[i];
        if(tempsum>max1)max1=tempsum;
    }
     tempsum=max1;
    for(int i=mid-1;i>=left;i--) {
        tempsum+=arr[i];
        if(tempsum>max1)max1=tempsum;
    }
    //no mid
     if(mid==right||mid==left)return max1;
    ll max2=maxsum(arr,left,mid-1);
    ll max3=maxsum(arr,mid+1,right);
    ll ans=max(max1,max(max2,max3));
    return ans;
}

ll maxsum_plus(vector<ll> arr) {
     int n=arr.size();
     ll temp=0;
     ll sum=arr[0];
     ll index=0;
     for(int i=0;i<n;++i) {
         temp+=arr[i];
         if(temp>sum){
             sum=temp;
             index=i;
         }
     }
     temp=sum;
     for(int i=0;i<index;i++) {
         temp-=arr[i];
         if(temp>sum)sum=temp;
     }
     return sum;
 }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    int n;
    while(T--) {
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;++i) {
            cin>>arr[i];
        }
        //ll ans=maxsum(arr,0,n-1);
        ll ans=maxsum_plus(arr);
        cout<<ans<<"\n";
    }
}