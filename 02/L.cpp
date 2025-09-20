#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void drawL(vector<vector<int>>& map,pair<ll,ll>a,pair<ll,ll>b,pair<ll,ll>c,int& num,int position) {
    if(abs(a.first-c.first)==1) {
        map[a.first][a.second]=num;
        map[b.first][b.second]=num;
        map[c.first][c.second]=num;
        num++;
        //不要忘了返回
        return;
    }
    ll len=abs(a.first-c.first)+1;
    if(position==2) {
        drawL(map,{b.first-len/2,a.second},a,{a.first,c.second-len/2},num,4);
        drawL(map,{a.first+len/2,a.second},b,{c.first,c.second-len/2},num,2);
        drawL(map,{a.first+len/4,a.second+len/4},{b.first-len/4,b.second+len/4},{c.first-len/4,c.second-len/4},num,2);
        drawL(map,{a.first+len/2,c.second},c,{c.first,b.second+len/2},num,1);
    }else if(position==1) {
        drawL(map,{b.first-len/2,a.second},a,{a.first,c.second+len/2},num,3);
        drawL(map,{a.first+len/2,a.second},b,{c.first,c.second+len/2},num,1);
        drawL(map,{a.first+len/4,a.second-len/4},{b.first-len/4,b.second-len/4},{c.first-len/4,c.second+len/4},num,1);
        drawL(map,{a.first+len/2,c.second},c,{c.first,b.second-len/2},num,2);
    }else if(position==4) {
        drawL(map,{b.first+len/2,a.second},a,{a.first,c.second-len/2},num,2);
        drawL(map,{a.first-len/2,a.second},b,{c.first,c.second-len/2},num,4);
        drawL(map,{a.first-len/4,a.second+len/4},{b.first+len/4,b.second+len/4},{c.first+len/4,c.second-len/4},num,4);
        drawL(map,{a.first-len/2,c.second},c,{c.first,b.second+len/2},num,3);
    }else {//3
        drawL(map,{b.first+len/2,a.second},a,{a.first,c.second+len/2},num,1);
        drawL(map,{a.first-len/2,a.second},b,{c.first,c.second+len/2},num,3);
        drawL(map,{a.first-len/4,a.second-len/4},{b.first+len/4,b.second-len/4},{c.first+len/4,c.second+len/4},num,3);
        drawL(map,{a.first-len/2,c.second},c,{c.first,b.second-len/2},num,4);
    }
    return;
}
int main()
{   ios::sync_with_stdio(false);
    cin.tie(nullptr);
int T;
    int k;
    ll x,y;
    cin>>T;
    while(T--) {
        cin>>k>>x>>y;
      ll len=pow(2,k);
        vector<vector<int>> map(len+1,vector<int>(len+1));
        map[x][y]=0;
        //1 2
        //3 4 --->the position of leak
        int position=0;
        int num=1;
        pair<ll,ll> A={1,1},B={1,len},C={len,1},D={len,len};
        pair<ll,ll> a,b,c;
        for(int i=0;i<k;i++) {
            ll l=abs(A.first-D.first)+1;
            if(x<A.first+l/2&&y<A.second+l/2)position=1;
            else if(x<A.first+l/2&&y>=A.second+l/2)position=2;
            else if(x>A.first+l/2&&y<A.second+l/2)position=3;
            else position=4;
            if(position==1) {
                a=B;
                b=D;
                c=C;
               B.second-=l/2;
                C.first-=l/2;
                D.first-=l/2;
                D.second-=l/2;
            }else if(position==2) {
                a=A;b=C;c=D;
                A.second+=l/2;
                D.first-=l/2;
                C.first-=l/2;
                C.second+=l/2;
            }else if(position==3) {
                a=D;
                b=B;
                c=A;
                A.first+=l/2;
                B.first+=l/2;
                B.second-=l/2;
                D.second-=l/2;
            }else {
                a=C;b=A;c=B;
                A.first+=l/2;
                A.second+=l/2;
                B.first+=l/2;
                C.second+=l/2;
            }
            drawL(map,a,b,c,num,position);
        }
for(ll i=1;i<=len;++i) {
    for(ll j=1;j<=len;++j) {
        cout<<map[i][j]<<' ';
    }
    cout<<"\n";
}
    }
    return 0;
}