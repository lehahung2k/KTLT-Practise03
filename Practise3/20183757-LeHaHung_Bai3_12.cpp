#include <iostream>
#include <vector>
#define MAX 50

using namespace std;

int n, k, m;
vector<int> edge[MAX];
int cnt = 0;
bool mark[MAX];
int x[MAX];

void input() {
    cin >> n >> k;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
}

void process(int i) {
    for (int v : edge[x[i - 1]]) {
        if (mark[v] == false) {
            mark[v] = true;
            x[i] = v;
            if (i == k + 1) {
                cnt++;
            }
            else process(i + 1);
            mark[v] = false;
        }
    }
}

int main() {
    cout << "Ho va ten: Le Ha Hung" << endl;
    cout << "MSSV: 20183757" << endl;

    input();
    for (int i = 1; i <= n; i++) {
        memset(mark, false, sizeof(mark));
        mark[i] = true;
        x[1] = i;
        process(2);
    }

    cout << cnt / 2;
}
