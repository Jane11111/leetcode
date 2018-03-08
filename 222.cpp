#include <iostream>
#include <vector>
#include <cmath>
 using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int countNodes(TreeNode* root);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


int countNodes(TreeNode* root) {
    if(root==NULL)
        return 0;
    int h1=0;
    TreeNode *p=root;
    while(p){
        h1++;
        p=p->left;
    }
    int h2=0;
    p=root;
    while(p){
        h2++;
        p=p->right;
    }
    if(h1==h2)
        return pow(2,h1)-1;

    int n1=countNodes(root->left);
    int n2=countNodes(root->right);
    return 1+n1+n2;
}