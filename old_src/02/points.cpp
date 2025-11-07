#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct point {
    ll x = 0;
    ll y = 0;
};

double dist(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

struct cmpbyx {
    bool operator()(const point a, const point b) {
        return a.x <= b.x;
    }
};

struct cmpbyy {
    bool operator()(const point a, const point b) {
        return a.y <= b.y;
    }
};

double mindist(const vector<point> &points, int left, int right) {
    //left and right is the idx of point
    if (left == right) {
        return 1e15;
    }

    if (left + 1 == right) {
        return dist(points[left], points[right]);
    }

    int mid = (left + right) / 2;
    double minleft = mindist(points, left, mid);
    double minright = mindist(points, mid, right);
    double tempmin = min(minleft, minright);
    int midl = mid;
    int midr = mid;
    while (points[mid].x - points[midl].x <= tempmin && midl > left) {
        midl-- ;
    }
    while (points[midr].x - points[mid].x <= tempmin && midr < right) {
        midr++ ;
    }
    double ans = tempmin;
    vector<point> newpoints (points.begin()+midl,points.begin()+midr+1);
    sort(newpoints.begin(),newpoints.end(),cmpbyy());
    for(int i=0;i<newpoints.size();++i) {
        for(int j = i+1;j<newpoints.size();++j) {
            if(abs(newpoints[i].x - newpoints[j].x)>ans)continue;
            double dis = dist(newpoints[i],newpoints[j]);
            ans = min(ans,dis);
        }
    }
    return ans;
    //
}

void solve() {
    int n;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x;
        cin >> points[i].y;
    }
    sort(points.begin(), points.end(), cmpbyx());
    double ans = mindist(points,0,n-1);
    cout << fixed << setprecision(4) << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
