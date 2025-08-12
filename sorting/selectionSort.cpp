#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr) // O(n^2)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int smallestIndex = i;

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[smallestIndex])
            {
                smallestIndex = j;
            }
        }

        swap(arr[i], arr[smallestIndex]);
    }
}

int main()
{
    vector<int> arr = {4, 1, 5, 2, 3};

    selectionSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}