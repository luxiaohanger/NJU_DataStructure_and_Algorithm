#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


struct myqueue {
    vector<int> queue;
    int capacity;
    int size;
    int head;
    int tail;
    myqueue(int N):queue(N,0),capacity(N),tail(N - 1) {
        size = 0;
        head = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int num) {
        if(isFull()) {
            cout<<"Overflow\n";
            return;
        }
        if(tail == capacity - 1)tail = 0;
        else tail++;
        queue[tail] = num;
        size++;
    }

    void dequeue() {
        if(isEmpty()) {
            cout<<"Underflow\n";
            return;
        }
        if(head != capacity - 1) {
            head++;
        }else {
            head = 0;
        }
        size--;
    }

    int front() {
        if(isEmpty()) {
            return -1;
        }
        return queue[head];
    }

    int rear() {
        if(isEmpty()) {
            return  -1;
        }
        return queue[tail];
    }



};
void solve() {
    int N;
    cin >> N;
    myqueue mq(N);
    string cmd;
    while(cin >> cmd) {
        if(cmd == "enqueue") {
            int num;
            cin >> num;
            mq.enqueue(num);
        }else if(cmd == "dequeue") {
            mq.dequeue();
        }else if(cmd == "front") {
            cout<<mq.front()<<'\n';
        }else if(cmd == "rear") {
            cout << mq.rear() <<'\n';
        }else if(cmd == "isEmpty") {
            if(mq.isEmpty())cout<<"True"<<'\n';
            else cout << "False" << '\n';
        }else {
            if(mq.isFull())cout<<"True"<<'\n';
            else cout << "False" << '\n';
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
