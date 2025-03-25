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
    void levelOrderTraversal(TreeNode* root, vector<vector<int>>&ans){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>vec;
            for(int i=0; i<n; i++){
                TreeNode* ele = q.front();
                q.pop();
                vec.push_back(ele->val);
                if(ele->left != NULL) q.push(ele->left);
                if(ele->right != NULL) q.push(ele->right);
            }
            ans.push_back(vec);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        levelOrderTraversal(root, ans);
        return ans;
    }
};