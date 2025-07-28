// this is a better approach to parisum due to the fact that the data is sorted we are going to use the two pointer approach for this

#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target)
{
    int n = nums.size();
    int i = 0;
    int j = n - 1;
    int pairsum = 0;
    vector<int> ans;

    while (i < j)
    {
        pairsum = nums[i] + nums[j];
        if (pairsum > target) // if the target value is smaller than the sum then the last pointer decreases
        {
            j--;
        }
        else if (pairsum < target) // if the target value is larger than the sume the first pointer increases
        {
            i++;
        }
        else // this exectues when the paisum is equal to target
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 26;

    vector<int> ans = pairSum(nums, target);

    cout << ans[0] << ", " << ans[1] << endl;
    return 0;
}