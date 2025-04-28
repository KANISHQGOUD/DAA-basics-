#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

int cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convexHull(vector<Point>& P) {
    int n = P.size(), k = 0;
    if (n <= 3) return P;
    sort(P.begin(), P.end());
    vector<Point> H(2*n);
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    for (int i = n-2, t = k+1; i >= 0; --i) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k-1);
    return H;
}

int main() {
    int n;
    cin >> n;
    vector<Point> P(n);
    for (int i = 0; i < n; ++i) cin >> P[i].x >> P[i].y;
    vector<Point> hull = convexHull(P);
    for (auto& p : hull) cout << p.x << " " << p.y << endl;
    return 0;
}
