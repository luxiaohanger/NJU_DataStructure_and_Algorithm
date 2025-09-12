#include<bits/stdc++.h>
#include <iostream>

using namespace std;
void func1(queue<string>& plane,const string num,int max) {
    if(plane.size()==max) {
        cout<<"full"<<"\n";
    }else {
        plane.push(num);
    }
    return;
}

void func2(queue<string>& plane) {
    if(plane.empty()) {
        cout<<"empty"<<"\n";
    }else {
        cout<<plane.front()<<endl;
        plane.pop();
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    // 解除 cin 与 cout 的绑定
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    queue<string> plane;
    string cmd;
    string num;
    while(n--) {
        cin>>cmd;
        if(cmd=="1") {
            cin>>num;
            func1(plane,num,m);
        }else if(cmd=="2") {
            func2(plane);
        }else {
            cout<<plane.size()<<"\n";
        }
    }
    return 0;
}