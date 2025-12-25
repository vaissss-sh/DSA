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
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> tree;
        TreeTraversal(root, tree);

        int max_freq = 0;

        for(const auto& p : tree){
            if(p.second > max_freq) max_freq = p.second;
        }

        for(const auto& p : tree){
            if(p.second == max_freq) ans.push_back(p.first);
        }

        return ans;
    }
    void TreeTraversal(TreeNode* root, unordered_map<int, int>& tree){
        if(root == nullptr) return;

        TreeTraversal(root->left, tree);
        tree[root->val]++;
        TreeTraversal(root->right, tree);
    }
};