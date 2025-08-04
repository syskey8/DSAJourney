#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;       // Track the maximum profit seen so far
        int bestBuy = prices[0]; // Track the lowest price seen so far (best buy price)

        for (int i = 1; i < prices.size(); i++)
        {
            // If current price is higher than our best buy price,
            // calculate potential profit
            if (prices[i] > bestBuy)
            {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
            // Update the best buy price if we find a lower price
            bestBuy = min(bestBuy, prices[i]);
        }

        return maxProfit;
    }
};

// Example usage:

int main()
{
    Solution solution;

    // Test case 1: [7,1,5,3,6,4] -> Expected output: 5 (buy at 1, sell at 6)
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Test 1 - Max profit: " << solution.maxProfit(prices1) << endl;

    // Test case 2: [7,6,4,3,1] -> Expected output: 0 (no profit possible)
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Test 2 - Max profit: " << solution.maxProfit(prices2) << endl;

    // Test case 3: [1,2,3,4,5] -> Expected output: 4 (buy at 1, sell at 5)
    vector<int> prices3 = {1, 2, 3, 4, 5};
    cout << "Test 3 - Max profit: " << solution.maxProfit(prices3) << endl;

    return 0;
}