#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


void flatten(TreeNode* root);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


void flatten(TreeNode* root) {

    if(root==NULL)
        return;
    flatten(root->left);
    flatten(root->right);
    if(root->left) {
        TreeNode *p = root->left;
        while (p->right) {
            p = p->right;
        }
        p->right=root->right;
        root->right=root->left;
        root->left=NULL;
    }


}