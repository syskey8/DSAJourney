#include <iostream>
#include <climits>
using namespace std;

int getMaxSum(int mat[][3], int rows, int cols)
{ // while defining a fucntion it is okay if you do not add the value of rows but you compulsorily add the vale of columns
    int maxRowSum = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < cols; j++)
        {
            rowSum += mat[i][j];
        }

        maxRowSum = max(maxRowSum, rowSum);
    }

    return maxRowSum;
}

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3;
    int cols = 3;

    cout << getMaxSum(matrix, rows, cols) << endl;

    return 0;
}