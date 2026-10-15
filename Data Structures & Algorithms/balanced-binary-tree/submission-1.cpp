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
    int traverse(TreeNode* root, bool &balance){
        if(!root) return 0;

        int lh = traverse(root->left, balance);
        int rh = traverse(root->right, balance);
        if(abs(lh-rh)>1) balance = false;

        return 1 + max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        bool balance = true;
        traverse(root, balance);
        return balance;
    }
};
