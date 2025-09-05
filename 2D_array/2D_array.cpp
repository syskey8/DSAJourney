#include <iostream>
using namespace std;

int main()
{
    int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int rows = 4;
    int cols = 3;

    cout << matrix[2][1] << endl;

    matrix[2][1] = 50;
    cout << matrix[2][1] << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // linear search
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 5)
                cout << "Found 5 at [" << i << "]" << "[" << j << "]" << endl;
        }
        cout << endl;
    }
    return 0;
}