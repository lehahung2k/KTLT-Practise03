#include <iostream>
#define MAX 1000
using namespace std;

int n, c[MAX][MAX];
int X[MAX], X_best[MAX], mark[MAX];
int sum, sum_best, c_min;

void init() {
    sum = 0;
    sum_best = 1000000;
    X[1] = 1;
    mark[1] = 1;
    c_min = 1e9;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j && c[i][j] < c_min) c_min = c[i][j];
}

void print() {
    cout << sum_best + c[X_best[n]][X_best[1]] << endl;
}

void TRY(int i, int x) {
    for (int v = 2; v <= n; v++) {
        if (mark[v] == 0) {
            mark[v] = 1;
            X[i] = v;
            sum += c[x][v];
            if (i == n) {
                if (sum < sum_best) {
                    sum_best = sum;
                    for (int j = 1; j <= n; j++) X_best[j] = X[j];
                }
            }
            else {
                if (sum + c_min * (n - i + 1) < sum_best) TRY(i + 1, v);
            }
            mark[v] = 0;
            sum -= c[x][v];
        }
    }
}

int main() {
    cout << "Ho va ten: Le Ha Hung" << endl;
    cout << "MSSV: 20183757" << endl;

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];
    init();
    TRY(2, 1);
    print();
    return 0;
}
