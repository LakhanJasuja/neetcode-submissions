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
    bool check(TreeNode* root, unordered_map<int, int>&mp) {
        if (root == NULL) return true;
        if (mp.find(root->val) != mp.end()) return false;

        mp[root->val]++;
        if (root->left == NULL && root->right == NULL) {
            return true;
        }


        int l = INT_MIN;
        if (root->left) l = root->left->val;

        int r = INT_MAX;
        if (root->right) r = root->right->val;

      //  cout << l << " " << r << " " << root->val << "\n";



        if (!(root->val > l && root->val < r)) {
            return false;
        }

        bool ans1 = check(root->left, mp);
        bool ans2 = check(root->right, mp);

        return ans1 && ans2;
    }

    void inorder(TreeNode* root, vector <int>& arr) {
        if (root == NULL) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    bool isValidBST(TreeNode* root) {
        vector <int> arr;
        inorder(root, arr);
        for (int i=1;i<arr.size();i++) {
            if (arr[i] <= arr[i-1]) return false;
        }
        return true;
        
    }
};
