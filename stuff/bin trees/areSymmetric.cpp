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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return areSymmetric(root->left, root->right);
    }
    
    bool areSymmetric(TreeNode * p, TreeNode * q)
    {
        if (!p && !q) return true;
        if ((!p && q) || (p && !q)) return false;
        if (p->val != q->val) return false;
        return areSymmetric(p->left, q->right) &&
               areSymmetric(p->right, q->left);
    }
};
