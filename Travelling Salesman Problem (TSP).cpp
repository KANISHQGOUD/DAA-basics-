#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tsp(vector<vector<int>>& graph, vector<bool>& visited, int currPos, int n, int count, int cost, int ans) {
    if (count == n && graph[currPos][0]) return min(ans, cost + graph[currPos][0]);
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i]) {
            visited[i] = true;
            ans = tsp(graph, visited, i, n, count+1, cost + graph[currPos][i], ans);
            visited[i] = false;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (auto& row : graph) for (auto& val : row) cin >> val;
    vector<bool> visited(n, false);
    visited[0] = true;
    int ans = tsp(graph, visited, 0, n, 1, 0, INT_MAX);
    cout << ans << endl;
    return 0;
}
