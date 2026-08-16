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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) return NULL;
        if (p->val > q->val) swap(p, q);

        int pval = p->val;
        int qval = q->val;

       // cout << pval << " " 

        if (pval > root->val && qval > root->val)  {
            return lowestCommonAncestor(root->right, p, q);
        } else if (pval < root->val && qval < root->val)  {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return root;
        }
        return NULL;
    }
};
