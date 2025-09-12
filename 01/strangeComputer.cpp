#include<bits/stdc++.h>

using namespace std;

void paste(vector<string>& cmds,int m,int k) {
    int i=0;
    while(cmds.size()<k&&i<m) {
        //当size==k-1时最后一次进入循环！！！
        cmds.push_back(cmds[i]);
        i++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    // 解除 cin 与 cout 的绑定
    cin.tie(nullptr);
     int n,k;
    cin>>n>>k;
    string cmd;
    int ptr=0;
    vector<string> cmds;
    cin.ignore(1, '\n');
    while(n--) {
      getline(cin,cmd);//会读取残留换行符
        cmds.push_back(cmd);
    }
    while(ptr<cmds.size()) {
          if(cmds[ptr][0]=='e') {
              cout<<cmds[ptr][5];
          }else {
              string sub=cmds[ptr].substr(3);//string 不以\0结尾，不能用C风格处理
              int m=stoi(sub);
              paste(cmds,m,k);
          }
        ptr++;
    }
    return 0;
}