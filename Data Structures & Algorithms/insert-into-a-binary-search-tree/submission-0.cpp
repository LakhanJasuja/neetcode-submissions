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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if (root == NULL) return newNode;
        TreeNode* prev = root;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->val > val) {
                prev = curr;
                curr = curr->left;
            } else {
                prev = curr; 
                curr = curr->right;
            }
        }
        if (prev->val > val) prev->left = newNode;
        else prev->right = newNode;

        return root;
    }
};