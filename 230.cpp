#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
int kthSmallest(TreeNode* root, int k);
int RecNodeNum(TreeNode* root,int k,int & res);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
int RecNodeNum(TreeNode* root,int k,int & res){
    if(root==NULL)
        return 0;
    int left=RecNodeNum(root->left,k,res);
    int right=RecNodeNum(root->right,k,res);
    if(left==k-1)
        res=root->val;
    return left+right+1;

}
int kthSmallest(TreeNode* root, int k) {
    int res;
    RecNodeNum(root,k,res);
    return res;

}