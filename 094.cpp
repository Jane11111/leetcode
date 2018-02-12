#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
vector<int> inorderTraversal(TreeNode* root);
void RecTravel(TreeNode* root,vector<int> &res);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void RecTravel(TreeNode* root,vector<int> &res){
    if(root==NULL)
        return;
    RecTravel(root->left,res);
    res.push_back(root->val);
    RecTravel(root->right,res);
}
vector<int> inorderTraversal(TreeNode* root) {

    vector<int> res;
    RecTravel(root,res);
    return res;
}