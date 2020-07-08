/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
   Hide Hint #1  
So, we essentially need to find three numbers x, y, and z such that they add up to the given value. If we fix one of the numbers say x, we are left with the two-sum problem at hand!
   Hide Hint #2  
For the two-sum problem, if we fix one of the numbers, say
x
, we have to scan the entire array to find the next number
y
which is
value - x
where value is the input parameter. Can we change our array somehow so that this search becomes faster?
   Hide Hint #3  
The second train of thought for two-sum is, without changing the array, can we use additional space somehow? Like maybe a hash map to speed up the search?

*/

class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> output;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); ++i) {
        // Never let i refer to the same value twice to avoid duplicates.
        if (i != 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
          if (nums[i] + nums[j] + nums[k] == 0) {
            output.push_back({nums[i], nums[j], nums[k]});
            ++j;
            // Never let j refer to the same value twice (in an output) to avoid duplicates
            while (j < k && nums[j] == nums[j-1]) ++j;
          } else if (nums[i] + nums[j] + nums[k] < 0) {
            ++j;
          } else {
            --k;
          }
        }
      }
      return output;
    }
};

/*
Solution that doesnt remove duplicates

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> trio;
        set<int> s;
        for(int i=0;i<nums.size()-1;i++)
        {
            s.clear();
            for(int j=i+1;j<nums.size();j++)
            {
                if(s.find(nums[j])!=s.end())
                {
                    trio = {nums[i], nums[j], -(nums[i]+nums[j])};
                    result.push_back(trio);
                }
                else
                {
                    s.insert(-(nums[i]+nums[j]));
                }
            }
        }
        return result;
    }
};
*/
