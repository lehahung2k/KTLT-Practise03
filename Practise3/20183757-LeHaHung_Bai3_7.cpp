#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, k;
int x[1000];

struct frame {
    int i;
    int num; // số bit 1
    int where; //0, 1, 2
};

void go() {
    stack<frame> S;
    S.push({ 0, 0, 0 });
    while (!S.empty()) {
        frame& top = S.top();
        if (top.i >= n) {
            for (int j = 0; j < n; ++j) cout << x[j];
            cout << endl;
            S.pop();
            continue;
        }
        if (top.where == 2) {
            S.pop();
            continue;
        }
        else if (top.where == 1) {
            if (top.num + 1 < k) {
                x[top.i] = 1;
                S.push({ top.i + 1, top.num + 1, 0 });
            }
        }
        else {
            // where == 0
            x[top.i] = 0;
            S.push({ top.i + 1, 0, 0 });
        }
        top.where++;
    }
}

int main() {
    cout << "Ho va ten: Le Ha Hung" << endl;
    cout << "MSSV: 20183757" << endl;

    cin >> n >> k;
    go();
}
