#include <iostream>
#include <vector>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
int rob(TreeNode* root);
int RecRob(TreeNode* root,bool can);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int rob(TreeNode* root) {

    if(!root)
        return 0;
    int n1=root->val;
    if(root->left)
        n1+=rob(root->left->left)+rob(root->left->right);
    if(root->right)
        n1+=rob(root->right->left)+rob(root->right->right);

    int n2=rob(root->left)+rob(root->right);
    return max(n1,n2);


}