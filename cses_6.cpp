#include <iostream>
#include <vector>

using namespace std;

void spiralMat()
{
    int row, col;
    cin >> row >> col;

    int size = max(row, col);
    vector<vector<int>> mat(size, vector<int>(size, 0));

    int i = 0, j = 0;
    mat[i][j] = 1;
    int prev = 1;

    while (i < size or j < size)
    {

        // right
        if (j + 1 < size)
        {
            mat[i][++j] = ++prev;
            // cout<< prev<< " "<< endl;
        }
        else
        {
            break;
        }

        // down
        for (int r = 1; r <= j; r++, i++)
        {
            mat[r][j] = ++prev;
        }

        // left
        for (int c = i - 1; c >= 0; c--, j--)
        {
            mat[i][c] = ++prev;
            // cout<< prev<< " ";
        }

        // down
        if (i + 1 < size)
        {
            mat[++i][j] = ++prev;
        }
        else
        {
            break;
        }

        // right
        for (int c = 1; c <= i; c++, j++)
        {
            mat[i][c] = ++prev;
            // cout<< prev<< " ";
        }

        // up
        for (int r = j - 1; r >= 0; r--, i--)
        {
            mat[r][j] = ++prev;
            // cout<< prev<< " ";
        }
    }
    cout << mat[row-1][col-1]<<"\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        spiralMat();
    }
    return 0;
}