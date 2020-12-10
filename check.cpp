#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void traverse(TreeNode* root){
    if(root!=0){
        cout<<root->val<<endl;
        traverse(root->left);
        traverse(root->right);
    }
}
int main(){

    queue<TreeNode*> q;

    int left,right;
    cout<<"Enter the root:";
    int Root;
    cin>>Root;
    TreeNode *root=new TreeNode(Root);
    q.push(root);
    while(!q.empty()){
        TreeNode *temp=q.front();
        q.pop();
        cout<<"Enter the left child of "<<temp->val<<":";
        cin>>left;
        cout<<"Enter the right child of "<<temp->val<<":";
        cin>>right;
        if(left!=-1){
            TreeNode* x=new TreeNode(left);
            cout<<"**Node Created**"<<"   val:"<<x->val<<"   Left:"<<x->left<<"   Right:"<<x->right<<endl;
            temp->left=x;
            q.push(x);
        }
        if(right!=-1){
            TreeNode* y=new TreeNode(right);
            cout<<"**Node Created**"<<"   val:"<<y->val<<"   Left:"<<y->left<<"   Right:"<<y->right<<endl;
            temp->left=y;
            q.push(y);
        }
    }
    traverse(root);
}
