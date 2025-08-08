#include <iostream>
#include <vector>
using namespace std;

/* recursive approach
int recBinarySearch(vector<int> arr, int tar, int st, int end) {
    if (st <= end) {
        int mid = st + (end—st)/2;

        if (tar > arr[mid]) { // 2nd half
            return recBinarySearch(arr, tar, mid+l, end);
        } else if (tar < arr[mid]) { // 1st half
            return recBinarySearch(arr, tar, st, mid—l) ;
        else { //mid => ans
            return mid;
        }
    }

    return -1;
}
*/

int binarySearch(vector<int> arr, int tar)
{
    int st = 0, end = arr.size() - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2; // we dont use (st + end) / 2 because if anyone of the st or end is INT_MAX then i will cause overflow

        if (tar > arr[mid])
        {
            st = mid + 1;
        }
        else if (tar < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // odd
    int tar = 12;

    cout << binarySearch(arr1, tar) << endl;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // even
    tar = 0;

    cout << binarySearch(arr2, tar) << endl;
}