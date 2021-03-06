#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
vector<vector<int>> levelOrder(TreeNode* root);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<vector<int>> levelOrder(TreeNode* root) {

    vector<vector<int>> res;
    if(root==NULL)
        return res;
    queue<TreeNode*> Q;
    vector<int> level;
    level.push_back(root->val);
    res.push_back(level);
    root->val=0;
    Q.push(root);
    while(!Q.empty()){
        TreeNode* p=Q.front();
        Q.pop();
        int num=p->val+1;
        if(p->left!=NULL){
            while(res.size()<=num){
                vector<int> t;
                res.push_back(t);
            }
            res[num].push_back(p->left->val);
            p->left->val=num;
            Q.push(p->left);
        }
        if(p->right!=NULL){
            while(res.size()<=num){
                vector<int> t;
                res.push_back(t);
            }
            res[num].push_back(p->right->val);
            p->right->val=num;
            Q.push(p->right);
        }
    }
    return res;
}