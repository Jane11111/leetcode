#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumNumbers(TreeNode* root);
void Rec(TreeNode * root,int& count);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
void Rec(TreeNode * root,int &count){
    if(root==NULL) {
        count=0;
        return;
    }
    if(!root->left&&!root->right){
        count+=root->val;
    }

    if(root->left){
        int num=root->left->val;
        int base=10;
        while(num/base)
            base*=10;
        root->left->val=root->val*base+root->left->val;
        Rec(root->left,count);
    }
    if(root->right){
        int num=root->right->val;
        int base=10;
        while(num/base)
            base*=10;
        root->right->val=root->val*base+root->right->val;
        Rec(root->right,count);
    }
}
int sumNumbers(TreeNode* root) {

    int count=0;
    Rec(root,count);
    return count;

}