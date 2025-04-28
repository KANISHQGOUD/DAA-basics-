#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<Item> items(n);
    for (int i = 0; i < n; i++) cin >> items[i].value >> items[i].weight;
    sort(items.begin(), items.end(), cmp);
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (W >= items[i].weight) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }
    cout << totalValue << endl;
    return 0;
}
