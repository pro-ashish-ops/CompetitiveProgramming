#include <bits/stdc++.h>
using namespace std;

int GCD(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int num = abs(a * d - b * c);
    int den = max(a * d, b * c);
    int g = GCD(num, den);
    cout << num / g << "/" << den / g << "\n";
    return 0;
}
