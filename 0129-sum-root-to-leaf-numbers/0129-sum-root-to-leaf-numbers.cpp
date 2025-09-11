/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int output = 0;
        dfs(root, 0 , output);
        return output;
    }

    void dfs(TreeNode* root, int currentsum, int& output)
    {
        currentsum = currentsum*10 +  root->val;
        if(root->left == nullptr && root->right == nullptr)
        {
            output+= currentsum;
            return;
        }

        if(root->left)  dfs(root -> left, currentsum , output);
        if(root->right)  dfs(root -> right, currentsum , output);
    }
};