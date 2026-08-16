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
    void inorder(TreeNode* root, int& k, int& ans) {
        if (ans != INT_MIN) return;
        if (root == NULL) return;
        if (root->left == NULL && root->right==NULL) {
            k--;
            //cout << k << " " << root-> val << "\n";
            if (k == 0) ans = root->val;
            return;
        }
        inorder(root-> left, k, ans);
        k--;
        if (ans != INT_MIN) return;
        if (k == 0) ans = root->val;
        inorder(root->right, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = INT_MIN;
        inorder(root, k, ans);
        return ans;
    }
};
