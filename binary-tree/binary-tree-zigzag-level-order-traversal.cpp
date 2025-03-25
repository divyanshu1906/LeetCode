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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*>st;
        st.push(root);
        vector<vector<int>>ans;
        bool rightToLeft = false;
        while(!st.empty()){
            stack<TreeNode*>currSt;
            vector<int>currElement;
            while(!st.empty()){
                TreeNode* node = st.top();
                st.pop();
                currElement.push_back(node->val);
                if(rightToLeft){
                    if(node->right) currSt.push(node->right);
                    if(node->left) currSt.push(node->left);
                }
                else{
                    if(node->left) currSt.push(node->left);
                    if(node->right) currSt.push(node->right);
                }
            }
            ans.push_back(currElement);
            rightToLeft = !rightToLeft;
            st = move(currSt);
        }
        return ans;
    }
};