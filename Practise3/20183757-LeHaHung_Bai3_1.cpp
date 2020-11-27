#include <iostream>

using namespace std;

int lucas(int n) {

    if (n == 0) return 2;
    else if (n == 1) return 1;
    else return lucas(n - 1) + lucas(n - 2);
}

int main() {
    int n;
    cout << "Ho va ten: Le Ha Hung" << endl;
    cout << "MSSV:20183757" << endl;
    cout << "nhap n:" << endl;
    cin >> n;
    cout << lucas(n);
    return 0;
}