#include <iostream>
#define MAX 17
using namespace std;

int m, n[MAX], h[MAX];
int x[MAX], num[MAX];

void print(int j) {
    for (int i = 1; i <= n[j]; i++) cout << x[i];
    cout << '\n';
}

void process(int i, int j) {
    for (int v = 0; v <= 1; v++) {
        x[i] = v;
        num[i] = num[i - 1] + v;
        if (num[i] > h[j]) return;
        if (i == n[j]) {
            if (num[i] == h[j]) print(j);
        }
        else process(i + 1, j);
    }
}

int main() {
    cout << "Ho va ten: Le Ha Hung" << endl;
    cout << "MSSV: 20183757" << endl;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> n[i] >> h[i];
    }
    for (int j = 0; j < m; j++) {
        process(1, j);
        cout << endl;
    }
}
