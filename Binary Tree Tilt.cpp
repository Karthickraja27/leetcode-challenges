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
    int sum(TreeNode* root){
        if(root){
            int x=sum(root->left);
            int y=sum(root->right);
            return x+y+root->val;
        }
        return 0;
    }
    int findTilt(TreeNode* root) {
        stack<TreeNode*> st;
        int ans=0,left,right;
        TreeNode *t=root;
        while(t || !st.empty()){
            if(t){
               left=sum(t->left);
               right=sum(t->right);
               ans+=abs(left-right);
               st.push(t);
               t=t->left;
            }
            else{
                t=st.top();
                st.pop();
                t=t->right;
            }
        }
        return ans;
    }
};
