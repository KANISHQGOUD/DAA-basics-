#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> add(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) C[i][j] = A[i][j] + B[i][j];
    return C;
}

vector<vector<int>> subtract(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) C[i][j] = A[i][j] - B[i][j];
    return C;
}

vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int newSize = n / 2;
    vector<int> inner(newSize);
    vector<vector<int>> A11(newSize, inner), A12(newSize, inner), A21(newSize, inner), A22(newSize, inner),
                        B11(newSize, inner), B12(newSize, inner), B21(newSize, inner), B22(newSize, inner),
                        C11(newSize, inner), C12(newSize, inner), C21(newSize, inner), C22(newSize, inner),
                        P1(newSize, inner), P2(newSize, inner), P3(newSize, inner), P4(newSize, inner),
                        P5(newSize, inner), P6(newSize, inner), P7(newSize, inner);
    for (int i = 0; i < newSize; i++) for (int j = 0; j < newSize; j++) {
        A11[i][j] = A[i][j]; A12[i][j] = A[i][j+newSize];
        A21[i][j] = A[i+newSize][j]; A22[i][j] = A[i+newSize][j+newSize];
        B11[i][j] = B[i][j]; B12[i][j] = B[i][j+newSize];
        B21[i][j] = B[i+newSize][j]; B22[i][j] = B[i+newSize][j+newSize];
    }
    P1 = strassen(add(A11, A22), add(B11, B22));
    P2 = strassen(add(A21, A22), B11);
    P3 = strassen(A11, subtract(B12, B22));
    P4 = strassen(A22, subtract(B21, B11));
    P5 = strassen(add(A11, A12), B22);
    P6 = strassen(subtract(A21, A11), add(B11, B12));
    P7 = strassen(subtract(A12, A22), add(B21, B22));
    C11 = add(subtract(add(P1, P4), P5), P7);
    C12 = add(P3, P5);
    C21 = add(P2, P4);
    C22 = add(subtract(add(P1, P3), P2), P6);
    for (int i = 0; i < newSize; i++) for (int j = 0; j < newSize; j++) {
        C[i][j] = C11[i][j]; C[i][j+newSize] = C12[i][j];
        C[i+newSize][j] = C21[i][j]; C[i+newSize][j+newSize] = C22[i][j];
    }
    return C;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n)), B(n, vector<int>(n));
    for (auto& row : A) for (int& val : row) cin >> val;
    for (auto& row : B) for (int& val : row) cin >> val;
    vector<vector<int>> C = strassen(A, B);
    printMatrix(C);
    return 0;
}
