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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root==NULL){
            return ans;
        }

        if(root->left==NULL && root->right==NULL){
            ans.push_back(to_string(root->val));
            return ans;
        }
        if (root->left) {
            for (string s : binaryTreePaths(root->left)) {
                ans.push_back(to_string(root->val) + "->" + s);
            }
        }
        
        if (root->right) {
            for (string s : binaryTreePaths(root->right)) {
                ans.push_back(to_string(root->val) + "->" + s);
            }
        }
        
        return ans;

    }
};