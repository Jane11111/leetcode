#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root==NULL)
        return res;
    vector<TreeNode*> Q;
    vector<int> tmp;
    tmp.push_back(root->val);
    res.push_back(tmp);
    root->val=0;
    Q.push_back(root);
    while(!Q.empty()){
        TreeNode* p=Q[0];
        Q.erase(Q.begin());
        if(p->left==NULL&&p->right==NULL)
            continue;
        int num=p->val+1;
        while(res.size()<=num){
            vector<int> t;
            res.push_back(t);
        }
        if(p->left!=NULL){
            if(num%2)
                res[num].insert(res[num].begin(),p->left->val);
            else
                res[num].push_back(p->left->val);
            p->left->val=num;
            Q.push_back(p->left);
        }
        if(p->right!=NULL){
            if(num%2)
                res[num].insert(res[num].begin(),p->right->val);
            else
                res[num].push_back(p->right->val);
            p->right->val=num;
            Q.push_back(p->right);
        }
    }
    return res;

}