'''
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
'''

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> v(digits);
        if(digits[n-1]!=9)
        { 
            v[n-1]++;
            return v;
        }
        int i = n-1;
        while(i>=0 && v[i]==9)
        {
            v[i] = 0;
            i--;
        }
        if(i<0)
        {
            v.push_back(1);
            reverse(v.begin(),v.end());
            /*vector<int> z(n+1,0);
            z[0] = 1;
            return z;  */ 
        }
        else
        {
            v[i]++;
        }
        return v;
        
    }
};
