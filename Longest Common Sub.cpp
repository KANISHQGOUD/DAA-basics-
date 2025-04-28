#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string X, Y;
    cin >> X >> Y;
    int m = X.size(), n = Y.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
        if (X[i-1] == Y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    cout << dp[m][n] << endl;
    return 0;
}
