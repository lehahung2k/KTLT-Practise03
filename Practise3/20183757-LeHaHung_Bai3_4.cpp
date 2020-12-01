#include <iostream>
using namespace std;
int a[1000], n;
int mem[1000];

void init() {
    memset(mem, -1, sizeof(mem));
}

//#Quy hoạch động
void lis(int i) {
    if (mem[i] != -1) return;
    int f = 1;
    for (int j = 1; j < i; j++) {
        if (a[j] < a[i]) {
            f = max(f, mem[j] + 1);
        }
    }
    mem[i] = f;
}

//#Truy vết lời giải
void trace(int i) {
    if (mem[i] > 1) {
        for (int j = 1; j < i; j++)
            if (mem[j] + 1 == mem[i]) {
                trace(j);
                break;
            }
    }
    cout << a[i] << ' ';
}

int main() {
    cout << "Ho va ten: Le Ha Hung" << endl;
    cout << "MSSV: 20183757" << endl;

    init();
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) lis(i);
    int res = 1, pos = 0;
    for (int i = 1; i <= n; i++) {
        if (res < mem[i]) {
            res = mem[i];
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}
