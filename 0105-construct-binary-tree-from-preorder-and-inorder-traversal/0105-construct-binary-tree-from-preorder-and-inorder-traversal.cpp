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
    unordered_map<int,int> mp;
    int preorderIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i =0; i < inorder.size() ; i++)
        {
            mp[inorder[i]] = i;
        }

       return  helper(preorder, 0, inorder.size()-1);
    }

    TreeNode* helper(vector<int>& preorder , int left, int right)
    {
        if( left > right ) return nullptr;

        int rootval = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootval);

        int inorderIndex = mp[rootval];

        root->left = helper(preorder, left, inorderIndex -1);
        root->right = helper(preorder, inorderIndex +1, right);
        return root;

    }
};