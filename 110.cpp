#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
bool isBalanced(TreeNode* root);
int CalHeight(TreeNode* root);
int main() {
    TreeNode*p1=new TreeNode(3);
    TreeNode*p2=new TreeNode(9);
    TreeNode*p3=new TreeNode(20);
    TreeNode*p4=new TreeNode(15);
    TreeNode*p5=new TreeNode(7);
    p1->left=p2;
    p1->right=p3;
    p1->left=p4;
    p1->right=p5;
    bool res=isBalanced(p1);
    if(res)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}

int CalHeight(TreeNode* root){
    if(root==NULL)
        return 0;
    int left=CalHeight(root->left);
    int right=CalHeight(root->right);
    root->val=(left>right?left:right)+1;
    return root->val;
}


bool isBalanced(TreeNode* root) {
    if(root==NULL)
        return true;
    queue<TreeNode*> Q;
    CalHeight(root);
    Q.push(root);
    while(!Q.empty()){
        TreeNode* p=Q.front();
        Q.pop();
        int left=0;
        int right=0;
        if(p->left!=NULL) {
            left = p->left->val;
            Q.push(p->left);
        }
        if(p->right!=NULL){
            right=p->right->val;
            Q.push(p->right);
        }
        if(abs(left-right)>1)
            return false;



    }
    return true;

}