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
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
vector<int> preorderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*>  myStack;
    if(!root)
        return res;
    myStack.push(root);
    while(!myStack.empty()){
        TreeNode* p=myStack.top();
        res.push_back(p->val);
        myStack.pop();
        if(p->right)
            myStack.push(p->right);
        if(p->left)
            myStack.push(p->left);
    }
    return res;

}