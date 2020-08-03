'''
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.
'''

class Solution:
    def isPalindrome(self, s):
        beg, end = 0, len(s) - 1
        while beg <= end:
            while not s[beg].isalnum() and beg < end: beg += 1
            while not s[end].isalnum() and beg < end: end -= 1
            if s[beg] == s[end] or s[beg].upper() == s[end].upper():
                beg, end = beg + 1, end - 1
            else:
                return False
        return True
