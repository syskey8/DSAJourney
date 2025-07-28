// in this you have to find a pair of numbers that match the target value
// there is a better approach to solve this question

#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target)
{ // this function return the vector with the paisum which hits the required target
  vector<int> ans;
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (nums[i] + nums[j] == target)
      {
        ans.push_back(i);
        ans.push_back(j);
        return ans;
      }
    }
  }

  return ans; // this wont be executed as a pair will be always returned given that the vector and target is valid
}

int main()
{
  vector<int> nums = {2, 7, 11, 13}; // vector initialization
  int target = 9;                    // target value

  vector<int> ans = pairSum(nums, target);

  cout << ans[0] << ", " << ans[1] << endl;

  return 0;
}
