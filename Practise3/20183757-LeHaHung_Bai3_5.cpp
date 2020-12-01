#include <iostream>
using namespace std;

int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n - 1, k) + binom(n - 1, k - 1);
}

int binom2(int n, int k) {
    if (k < 0 || k > n) return 0;
    int C[100][100];
    for (int i = 1; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    return C[n][k];
}

int main() {
    cout << "Ho va ten: Le Ha Hung" << endl;
    cout << "MSSV: 20183757" << endl;

    for (int n = 1; n <= 10; ++n) {
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= 10; ++n) {
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}
