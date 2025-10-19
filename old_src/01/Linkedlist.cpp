#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct node {
    int val;
    node* next;
};

struct mylist {
    node* sb;

    mylist () {
        sb = new node();
    }

    void pushFront(int val) {
        node* newnode = new node();
        newnode -> val = val;
        newnode -> next = sb -> next;
        sb -> next = newnode;
    }

    void pushBack(int val) {
        node* newnode = new node();
        newnode ->val = val;
        node* p = sb -> next;
        node* prev = sb;
        while(p) {
            p = p -> next;
            prev = prev -> next;
        }
        prev -> next = newnode;
    }

    void search(int t) {
        node* p = sb -> next;
        while(p) {
            if(p -> val == t) {
                cout << "1\n";
                return;
            }
            p = p -> next;
        }
        cout << "0\n";
        return;
    }

    void remove(int t) {
        node* p = sb -> next;
        node* prev = sb;
        while(p) {
            bool check = false;
            if(p -> val == t) {
                //
                prev -> next = p -> next;
                check = true;
            }
            p = p -> next;
           if(!check) prev = prev -> next;
        }
    }

    void print() {
        node* p = sb -> next;
        while(p) {
            cout << p -> val <<' ';
            p = p -> next;
        }
        cout << '\n';
    }

};


void solve() {
    mylist ls;
    string cmd;
    int val;
    while(cin >> cmd) {
        if(cmd == "pushFront") {
            cin >> val;
            ls.pushFront(val);
        }else if(cmd == "pushBack") {
            cin >> val;
            ls.pushBack(val);
        }else if(cmd == "search") {
            cin >> val;
            ls.search(val);
        }else if(cmd == "remove") {
            cin >> val;
            ls.remove(val);
        }else {
            ls.print();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
