#include <iostream>
#include <vector>
using namespace std;

int peak(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            return arr[i];
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {0, 3, 8, 9, 5, 2};
    int size = 6;

    cout << "Peak Value: " << peak(arr, size) << endl;
}