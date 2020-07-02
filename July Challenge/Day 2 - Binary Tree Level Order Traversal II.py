'''
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
'''

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> ans;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> levelElem;
            int size = q.size();
            while(size--)
            {
                TreeNode* curr = q.front();
                q.pop();
                levelElem.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            ans.push_back(levelElem);
        }
        reverse(ans.begin(), ans.end());
        return ans;
            
    }
};
