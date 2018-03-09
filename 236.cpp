#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if(!root)
        return NULL;

    if(root==p)
        return p;
    if(root==q)
        return q;

    TreeNode *p1=lowestCommonAncestor(root->left,p,q);
    TreeNode *p2=lowestCommonAncestor(root->right,p,q);

    if(p1&&p2)
        return root;
    else if(!p1&&!p2)
        return NULL;
    else
        return p1?p1:p2;


}