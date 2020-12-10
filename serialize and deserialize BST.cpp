/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    struct TreeNode *root;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* t=root;
        string s="";
        while(t||!stk.empty()){
            if(t!=NULL){
                s+=to_string(t->val);
                s+=',';
                stk.push(t);
                t=t->left;
            }
            else{
                t=stk.top();
                stk.pop();
                t=t->right;
            }
        }
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    void insert(int i){
        TreeNode* t=root;
        TreeNode *r=NULL,*p;

        if(root==NULL){
            p=(struct TreeNode*)malloc(sizeof(struct TreeNode));
           p->val=i;
            p->left=p->right=NULL;
             root=p;
             return;
        }

            while(t){
                r=t;
                if(i<t->val){
                    t=t->left;
                }
                else if(i>t->val){
                    t=t->right;
                }
                else{
                    return;
                }
            }
        p=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        p->val=i;
        p->left=p->right=NULL;
        if(i<r->val){
            r->left=p;
        }
        else{
            r->right=p;
        }
    }
    int stringTointeger(string str)
    {
     int temp = 0;
     for (int i = 0; i < str.length(); i++) {


        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
    }
    TreeNode* deserialize(string data) {
        root=NULL;
        string s="";
        for(int i=0;i<data.length();i++){
            if(data[i]!=','){
                s+=data[i];
            }else{
                insert(stringTointeger(s));
            s="";
            }

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
