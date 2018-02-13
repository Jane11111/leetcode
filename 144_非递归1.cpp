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
    stack<TreeNode*> myStack;
    while(root||!myStack.empty()){
        while(root){
            res.push_back(root->val);
            myStack.push(root);
            root=root->left;
        }
        root=myStack.top();
        root=root->right;
        myStack.pop();
    }
    return res;

}