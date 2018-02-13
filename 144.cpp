#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode{

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
vector<int> preorderTraversal(TreeNode* root);
void RecPre(TreeNode* root,vector<int>& res);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


vector<int> preorderTraversal(TreeNode* root) {

    vector<int> res;
    RecPre(root,res);
    return res;
}

void RecPre(TreeNode* root,vector<int>& res){
    if(root==NULL)
        return ;
    res.push_back(root->val);
    RecPre(root->left,res);
    RecPre(root->right,res);
}