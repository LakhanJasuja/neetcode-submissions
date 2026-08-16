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
    // [1, 2, 4, 1, 2]
    // dp[i] = max(dp[i-1], dp[i-2] + )
    int max(int a, int b) {
        if (a > b) return a;
        return b;
    }
    pair <int, int> calculate(TreeNode* root) {
        // excl , incl
        if (root == NULL) return make_pair(0, 0);
        if (root->left== NULL && root-> right == NULL) return make_pair(0, root->val);

        pair <int, int> p1 = calculate(root->left);
        pair <int, int> p2 = calculate(root->right);


        int excl = max(p1.first, p1.second) + max(p2.first , p2.second);
        int incl = root->val + p1.first + p2.first;

        return make_pair(excl, incl);
    }
    int rob(TreeNode* root) {
        pair <int, int> p = calculate(root);
        return max(p.first, p.second);
    }
};