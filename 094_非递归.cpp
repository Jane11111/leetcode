#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
vector<int> inorderTraversal(TreeNode* root);
int main() {
    TreeNode * p1=new TreeNode(1);
    TreeNode* p2=new TreeNode(2);
    TreeNode* p3=new TreeNode(3);
    p1->right=p2;
    p2->left=p3;
    vector<int> res=inorderTraversal(p1);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
}

vector<int> inorderTraversal(TreeNode* root) {

    vector<int> res;
    if(root==NULL)
        return res;
    stack<TreeNode*> S;
    S.push(root);
    while(root->left!=NULL) {
        S.push(root->left);
        root=root->left;
    }
    while(!S.empty()){
        TreeNode*p=S.top();
        res.push_back(p->val);
        S.pop();
        if(p->right!=NULL) {
            S.push(p->right);
            TreeNode* p2=p->right;
            while(p2->left!=NULL) {
                S.push(p2->left);
                p2=p2->left;
            }
        }
    }
    return res;
}