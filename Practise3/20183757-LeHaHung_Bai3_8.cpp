#include <iostream>
#include <stack>
#define MAX 1000
using namespace std;

int n, M, m[MAX];
int sum = 0, x[MAX];
struct frame {
    int i;
    int j;
};

void input() {
    cin >> n >> M;
    for (int i = 1; i <= n; ++i) cin >> m[i];
}

void go() {
    stack<frame> S;
    S.push({ 1, -1 });
    while (!S.empty()) {
        frame& top = S.top();
        if (top.i > n) {
            if (sum == M) {
                for (int i = 1; i <= n; ++i) {
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << "=" << M;
                exit(0);
            }
            S.pop();
            continue;
        }

        if (top.j > -1) sum -= m[top.i] * x[top.i];
        if (top.j > 1) {
            S.pop();
            continue;
        }
        x[top.i] = top.j;
        sum += m[top.i] * x[top.i];
        S.push({ top.i + 1, -1 });
        top.j++;

    }
    cout << -1;
}

int main() {
    cout << "Ho va ten: Le Ha Hung" << endl;
    cout << "MSSV: 20183757" << endl;

    input();
    go();
    return 0;
}
