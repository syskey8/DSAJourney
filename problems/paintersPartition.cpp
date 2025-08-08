/*
Painter's Partition Problem

Given are N boards of length of each given in the form of array, and M painters, such that each painter takes 1 unit of time to paint 1 unit of the board.

The task is to find the minimum time to paint all boards under the constraints that any painter will only paint continuous sections of boards.
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isValid(vector<int> arr, int n, int m, int mid) // mid is maxALlowedTime
{
    // Initialize painter count and blocks painted by current painter
    int painter = 1, blocks = 0;

    for (int i = 0; i < n; i++)
    {
        // If a single block is larger than allowed time, not possible
        if (arr[i] > mid)
        {
            return false;
        }
        // If current painter can paint this block within allowed time
        if (blocks + arr[i] <= mid)
        {
            blocks += arr[i];
        }
        else
        {
            // Assign block to next painter
            painter++;
            blocks = arr[i];
        }
    }
    // Return true if painters used do not exceed m
    return painter <= m;
}

int paintersPartition(vector<int> arr, int n, int m)
{
    // Calculate total units and max block size
    int sum = 0, maxValue = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxValue = max(maxValue, arr[i]);
    }

    // Binary search range: max block size to total units
    int start = maxValue, end = sum, ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        // Check if allocation is possible with max time = mid
        if (isValid(arr, n, m, mid))
        {
            ans = mid;     // Update answer
            end = mid - 1; // Try for a better (smaller) answer
        }
        else
        {
            start = mid + 1; // Increase max allowed time
        }
    }
    return ans;
}

int main()
{
    // Example usage
    vector<int> arr = {40, 30, 10, 20};
    int n = 4, m = 2;

    cout << paintersPartition(arr, n, m) << endl;
}