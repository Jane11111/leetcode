#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};
int findTilt(TreeNode* root);
int RecFindTilt(TreeNode* root);
int main() {
    TreeNode *p1=new TreeNode(1);
    TreeNode *p2=new TreeNode(2);
    TreeNode *p3=new TreeNode(3);
    TreeNode *p4=new TreeNode(4);
    TreeNode *p5=new TreeNode(5);
    p1->left=p2;
    p2->left=p3;
    p3->left=p4;
    p4->left=p5;
    int res=findTilt(p1);
    cout<<res<<endl;
}
int RecFindTile(TreeNode* root){
    if(!root)
        return 0;

    int t1=RecFindTile(root->left);
    int t2=RecFindTile(root->right);

    int n1=0;int n2=0;
    if(root->left)
    n1=root->left->val;
    if(root->right)
    n2=root->right->val;

    root->val=n1+n2+root->val;

    return abs(n1-n2)+t1+t2;


}
int findTilt(TreeNode* root) {
    if(root==NULL)
        return 0;
    int res=RecFindTile(root);
    return res;



}