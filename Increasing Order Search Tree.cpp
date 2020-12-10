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
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> vec;
        stack<TreeNode*> stk;
        TreeNode* t=root;
        while(t||!stk.empty()){
            if(t){
                stk.push(t);
                t=t->left;
            }
            else{
                t=stk.top();
                stk.pop();
                vec.push_back(t);
                t=t->right;
            }

        }
        int i;
        root=vec[0];
        for(i=0;i<vec.size()-1;i++){
            vec[i]->right=vec[i+1];
            vec[i]->left=NULL;
        }
        vec[i]->right=NULL;
        vec[i]->left=NULL;
        return root;
    }
};
