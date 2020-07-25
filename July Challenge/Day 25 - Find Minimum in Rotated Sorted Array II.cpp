/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/

class Solution {
public:
int search(vector <int>& arr, int low, int high){
      if(low == high){
         return arr[low];
      }
      int mid = low + (high - low) / 2;
      int ans = INT_MAX;
      if(arr[low] < arr[mid]){
         ans = min(arr[low], search(arr, mid, high));
      }
      else if (arr[high] > arr[mid]){
         ans = min(arr[mid], search(arr, low, mid));
      }
      else if(arr[low] == arr[mid]){
         ans = min(arr[low], search(arr, low + 1, high));
      }
      else if(arr[high] == arr[mid]){
         ans = min(arr[high], search(arr, low, high - 1));
      }
      return ans;
   }
   int findMin(vector<int>& nums) {
      return search(nums, 0, nums.size() - 1);
   }
};
