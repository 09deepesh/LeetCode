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
    int postorderIndex = 0;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         for(int i =0; i < inorder.size() ; i++)
        {
            mp[inorder[i]] = i;
        }
       postorderIndex = postorder.size() -1;
       return  helper(postorder, 0, inorder.size()-1);
    }
    
  

    TreeNode* helper(vector<int>& postorder , int left, int right)
    {
        if( left > right ) return nullptr;

        int rootval = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootval);

        int inorderIndex = mp[rootval];
        root->right = helper(postorder, inorderIndex +1, right);

        root->left = helper(postorder, left, inorderIndex -1);
        return root;

    }
};