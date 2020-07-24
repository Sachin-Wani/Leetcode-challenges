/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_result = 0;
      for (int i=0;i < nums.size(); i++) {
         xor_result = xor_result ^ nums[i];
      }
      int pos = 0;
      while ((xor_result & (1 << pos)) == 0) {
         pos++;
      }
      int num1 = 0;
      for (int i=0;i < nums.size(); i++) {
         if ((nums[i] & (1 << pos)) != 0) {
            num1 = num1 ^ nums[i];
         }
      }
      int num2 = xor_result ^ num1;
      vector<int> result = {num1, num2};
      return result;
    }
};
