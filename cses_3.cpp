#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;

    int maxCount = 1, count = 1;

    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1]) {
            count++;
        } else {
            count = 1;
        }
        maxCount = max(maxCount, count);
    }

    cout << maxCount << '\n';
    return 0;
}
