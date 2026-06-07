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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int,TreeNode*> mpp;
        unordered_map<int,int> root;
        for(int i=0;i<d.size();i++){

            //create entry in map if not exist
            if(mpp[d[i][0]]==0){
                TreeNode* temp = new TreeNode(d[i][0]);
                mpp[d[i][0]]=temp;
            }

            if(mpp[d[i][1]]==0){
                TreeNode* tt = new TreeNode(d[i][1]);
                mpp[d[i][1]]=tt;
            }

            if(d[i][2]==1){
                mpp[d[i][0]]->left=mpp[d[i][1]];
            }
            else{
                 mpp[d[i][0]]->right=mpp[d[i][1]];
            }

            //root[node] = 0, node is not yet stored
            //root[node] = -1, node has a parent
            //root[node] = 1, node does not have any parent

            if(root[d[i][0]]!=-1) root[d[i][0]]=1;
            root[d[i][1]]=-1;

        }

        int value=0;
        for(auto &it:root){
            if((it).second==1) {
                value=(it).first;
                break;
            }
        }
        return mpp[value];

    }
};