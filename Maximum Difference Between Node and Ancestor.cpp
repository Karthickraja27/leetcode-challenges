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
    int findDiff(TreeNode* root,int max){
        stack<TreeNode*> stk;
        vector<int> vec;
        TreeNode* t=root->left;
        int x=root->val;
        while(t||!stk.empty()){
            if(t){
                vec.push_back(t->val);
                stk.push(t);
                t=t->left;
            }
            else{
                t=stk.top();
                stk.pop();
                t=t->right;
            }
        }

        for(int i=0;i<vec.size();i++){
           // cout<<vec[i]<<endl;
            if(abs(x-vec[i])>max){
                max=abs(x-vec[i]);
            }
        }
        t=root->right;

        vec.clear();
        while(!stk.empty()){
            stk.pop();
        }
        while(t||!stk.empty()){
            if(t){
                vec.push_back(t->val);
                stk.push(t);
                t=t->left;
            }
            else{
                t=stk.top();
                stk.pop();
                t=t->right;
            }
        }
        for(int i=0;i<vec.size();i++){
           // cout<<vec[i]<<endl;
            if(abs(x-vec[i])>max){
                max=abs(x-vec[i]);
            }
        }
        return max;

    }
    int maxAncestorDiff(TreeNode* root) {
        int max=-99999;
        stack<TreeNode*> stk;
        TreeNode* t=root;
        while(t||!stk.empty()){
            if(t){
                max=(findDiff(t,max)>max)?findDiff(t,max):max;
                stk.push(t);
                t=t->left;
            }
            else{
                t=stk.top();
                stk.pop();
                t=t->right;
            }
        }
       return max;

    }
};
