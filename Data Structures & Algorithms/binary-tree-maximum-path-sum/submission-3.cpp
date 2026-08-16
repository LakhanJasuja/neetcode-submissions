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
    int calculate(TreeNode* root, int& ans) {
        if (root == NULL) return 0;
        //cout << root->val << "\n";
        if (root->left == NULL && root->right == NULL) {
            ans = max(ans, root->val);
            return max(0, root->val);
        }

        int l = calculate(root->left, ans);
        int r = calculate(root->right, ans);
        ans = max(ans, max(l, 0) + max(r, 0) + root->val);
        return max(0, max(l, r) + root->val);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        calculate(root, ans);
        return ans;
    }
};
