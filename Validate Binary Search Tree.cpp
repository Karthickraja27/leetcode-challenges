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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* t=root;
        TreeNode* temp,*prev=NULL;
        vector<int> vec;
        while(t||!stk.empty()){
            if(t){
                stk.push(t);
                t=t->left;
            }
            else{
                temp=stk.top();
                stk.pop();
                if(prev&&prev->val>=temp->val){return false;}
                prev=temp;
                t=temp->right;
            }
        }

        return true;
    }
};
