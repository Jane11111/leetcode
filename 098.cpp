#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isValidBST(TreeNode* root);
bool RecValid(TreeNode* root,double& min,double& max);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
bool RecValid(TreeNode* root,double& min,double& max){
    if(!root)
        return true;


    double n1=INT_MIN-1,n2=INT_MIN-1;
    double n3=INT_MAX+1, n4=INT_MAX+1;
    bool f1=true;bool f2=true;
    if(root->left){
        f1=RecValid(root->left,n1,n2);

    }
    if(root->right){
        f2=RecValid(root->right,n3,n4);
    }
    if(f1&&f2&&root->val>n2&&root->val<n3){
        min=n1==INT_MIN-1?root->val:n1;
        max=n4==INT_MAX+1?root->val:n4;
        return true;
    }
    return false;

}
bool isValidBST(TreeNode* root) {

    double min;double max;
    return RecValid(root,min,max);

}