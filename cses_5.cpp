#include <iostream>
#include <vector>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    vector<vector<int>> mat(row, vector<int>(col, 0));
    int x =0;
    int y =0;
    while(x< row && y < col){
        for (int i =0; i< row; i++){
            mat[x][y] = 1;
        }
    }
    // int n;
    // cin >> n;

    // if (n == 2 || n == 3) {
    //     cout << "NO SOLUTION\n";
    //     return 0;
    // }

    // for (int i = 2; i <= n; i += 2) {
    //     cout << i << " ";
    // }

    // for (int i = 1; i <= n; i += 2) {
    //     cout << i << " ";
    // }
    
    // cout << '\n';
    return 0;
}
