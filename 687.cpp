#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
int longestUnivaluePath(TreeNode* root);
int RecFind(TreeNode* root);
int mymax=0;
int main() {
    TreeNode* p1=new TreeNode(1);
    TreeNode* p2=new TreeNode(4);
    TreeNode* p3=new TreeNode(4);
    TreeNode* p4=new TreeNode(4);
    TreeNode* p5=new TreeNode(5);
    TreeNode* p6=new TreeNode(5);
    p2->left=p3;
    p2->right=p4;
    p5->left=p6;
    p1->left=p2;
    p1->right=p3;
    int res=longestUnivaluePath(p1);
    cout<<res<<endl;
}

int longestUnivaluePath(TreeNode* root) {

    RecFind(root);
    return mymax;
}

int RecFind(TreeNode* root){
    if(root==NULL)
        return 0;
    int left=RecFind(root->left);
    int right=RecFind(root->right);
    int res_left=0;
    int res_right=0;
    int res=0;
    if(root->left!=NULL&&root->left->val==root->val) {
        res_left = left + 1;
        res=res+res_left;
    }
    if(root->right!=NULL&&root->right->val==root->val) {
        res_right = right + 1;
        res=res+res_right;
    }
    if(res>mymax)
        mymax=res;
    return res_left>res_right?res_left:res_right;

}