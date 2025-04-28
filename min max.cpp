#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;
    int mn = arr[0], mx = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < mn) mn = arr[i];
        if (arr[i] > mx) mx = arr[i];
    }
    cout << "Min: " << mn << endl;
    cout << "Max: " << mx << endl;
    return 0;
}
