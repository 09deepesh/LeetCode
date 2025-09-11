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
    void flatten(TreeNode* root) {
         if (!root) return;
        vector<TreeNode *> preorder_list;

        preorder(root,preorder_list);

        for(int i= 0; i < preorder_list.size()-1 ; i++)
        {
            preorder_list[i] -> left = nullptr;
            preorder_list[i] -> right = preorder_list[i+1];
        }
    }

   void preorder(TreeNode* root,vector<TreeNode *>& preorder_list)
    {
        if(!root) return ;

        preorder_list.push_back(root);
        preorder(root->left,preorder_list);
        preorder(root->right,preorder_list);

    }
};