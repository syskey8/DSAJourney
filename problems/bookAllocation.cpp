/*
Problem Statement
There are N books, and each book has A[i] number of pages.

You need to allocate these books to M students. The goal is to allocate the books such that the maximum number of pages allocated to any single student is minimized.

The following conditions must be met:
- Each book must be allocated to a student.
- Each student must be allocated at least one book.
- The allocation of books must be in a contiguous order.

You need to calculate and return this minimum possible number of maximum pages. If a valid assignment is not possible, return -1.
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValid(int mid, int n, int m, vector<int> arr)
{
    // Initialize student count and pages allocated to current student
    int student = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        // If a single book has more pages than mid, allocation is not possible
        if (arr[i] > mid)
        {
            return false;
        }
        // If current student can take this book without exceeding mid
        if (pages + arr[i] <= mid)
        {
            pages += arr[i];
        }
        else
        {
            // Allocate to next student
            student++;
            pages = arr[i];
        }
    }

    // If students required exceed m, allocation is not possible
    if (student > m)
    {
        return false;
    }
    // Allocation is possible
    if (student <= m)
    {
        return true;
    }
}

int allocateBooks(vector<int> arr, int n, int m)
{
    // Calculate total pages (sum of all books)
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    // Binary search range: 0 to total pages
    int start = 0, end = sum, ans = -1;

    // Binary search to find minimum possible maximum pages
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        // Check if allocation is possible with max pages = mid
        if (isValid(mid, n, m, arr))
        {
            ans = mid;     // Update answer
            end = mid - 1; // Try for a better (smaller) answer
        }
        else
        {
            start = mid + 1; // Increase max pages
        }
    }
    return ans;
}

int main()
{
    // Example usage
    vector<int> arr = {2, 1, 3, 4};
    int n = 4, m = 2; // n is the no. of books, m is the number of students

    cout << allocateBooks(arr, n, m) << endl;
    return 0;
}