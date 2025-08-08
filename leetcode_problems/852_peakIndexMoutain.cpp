#include <iostream>
#include <vector>
using namespace std;

int peak(vector<int> arr)
{
    int start = 1, end = arr.size() - 2;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        { // means the mid element was the peak element
            return arr[mid];
        }
        else if (arr[mid - 1] < arr[mid])
        { // means peak element lies in the right half (right search)
            start = mid + 1;
        }
        else
        { // means the peak element lies in the left half (left search)
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {0, 3, 8, 9, 5, 2};

    cout << "Peak Value:" << peak(arr) << endl;
}